//Austin Tebbs
#pragma once
#include "Node.h"
#include <stdexcept>
#include <iostream>
#include "Player.h"
#include <string>

using namespace std;


template <class T>
class LinkedList
{


public:
        
    Node<T>* head;
    Node<T>* tail;
    int num_items;

    LinkedList() //when we initialize list, nothing in it so head and tail are pointing to nothing
    {
        tail = NULL;
        head = NULL;
        num_items = 0;
    }
    
    ~LinkedList()
    {
        clear();
    }

	bool isDuplicate(string player_name)
	{
        Node<T>* temp = head;
	    while (temp != NULL)
        {
            if (temp->name == player_name)
            {
                return true;
            }
            temp = temp->next;
	    }        
		
	    return false;	
	}
    
    virtual void insertHead(PlayerInterface* player)
    {
        Node<T>* temp = head;
        while (temp != NULL)
        {
            if (temp->name == player->getName())
            {
                return;
            }
            temp = temp->next;
        }
        if (head == NULL) //if there are no nodes in list, simply have head point to value
        {
            head = new Node<T>(player);
        }
        else
        {
            
            //head needs to point to value, value->next points to old head,
            //old head->prev needs to point to new head
            head = new Node<T>(player, head);
            temp->prev = head; // old head prev points to head
            
        }
        num_items++;
    }
        
    virtual void insertTail(PlayerInterface* player)
    {
        //string value = player->getName();
  
        if (head == NULL) // if no nodes, value is head
        {
            head = new Node<T>(player);
            tail = head;
        }
        else
        {
            Node<T>* temp = head;
            while(temp->next != NULL) //interate through list until we find last item
            {
                temp = temp->next;
            }
            tail = new Node<T>(player); // tail points to value
            temp->next = tail;      // 2nd to last item now points to tail
            tail->next = NULL;      // tail->next points to NULL
            tail->prev = temp;      // tail-> prev points to old tail
        }
            num_items++;
    }
        
        
        
    virtual bool insertAfter(PlayerInterface* player, PlayerInterface* insertAfter)
    {
            
        Node<T>* temp = head;
            
        if (isDuplicate(player->getName()))
	    {
            cout << "DUPLICATE\n\n";
   	     	return false;
	    }
            
        while(temp != NULL) //iterate through list
        {
            if(temp->name == insertAfter->getName()) //for each iteration check to see if we should insert
            {
                if (temp->name == tail->name) // if we need to insert after the tail
                {
                    insertTail(player);
                    return true;
                }
                else
                {
                    Node<T>* to_add = new Node<T>(player);
                    to_add->next = temp->next; //if we do, point our value->next to same as temp->next
                    to_add->prev = temp;
                    temp->next = to_add;        // now point temp->next to our new value
                    to_add->next->prev = to_add;
                    num_items++;
                    return true;
                }
            }
            temp = temp->next;
        }
        cout << "END\n\n";
        return false;
    }
        
    virtual void remove(PlayerInterface* player)
    {
        Node<T>* to_remove = head;
        Node<T>* temp = head;

            
        if (head->name == player->getName())
        {
            head = temp->next;
            delete temp;
            
            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }
            num_items--;
            return;
        }
    
        if (tail->name == player->getName())
        {
            to_remove = tail;
            tail = to_remove->prev;
            tail->next = NULL;
            to_remove->prev = NULL;
            delete to_remove;
            num_items--;
            return;
        }
         
        while (temp->next != NULL)
        {
            if (temp->next->name == player->getName())
            {
                to_remove = temp->next;
                to_remove->next->prev = temp;
                temp->next = to_remove->next;
                to_remove->next = NULL;
                to_remove->prev = NULL;
                delete to_remove;
                num_items--;
                return;
            }
        
         temp = temp->next;
            
         }
        /*while (temp->next != NULL)
        {
            if (temp->next->name == player->getName())
            {
                to_remove = temp->next;
                temp->next = to_remove->next;
                to_remove->next = NULL;
                delete to_remove;
                num_items--;
                return;
            }
            temp = temp->next;
        }
          */
            
    }
        
    virtual void clear()
    {
        while (head != NULL)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        num_items = 0;
    }
    
    virtual PlayerInterface* at(int index)
    {
        int pos =0;
        PlayerInterface* player_ptr = nullptr;
        Node<T>* temp = head;
            
        if (head == NULL)
	    {
            return NULL;
	    }

        while (temp != NULL)
        {
            if (index == pos)
            {
                player_ptr = temp->player;
            }
            temp = temp->next;
                
            pos++;
        }
            if (index < 0 || index >= size())
            {
                return NULL;
            }
        return player_ptr;
        }
    
    virtual int size()
    {
        return num_items;
    }
    
    bool empty()
    {
        if (size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void print()
    {
        Node<T>* i = head;
        while (i != NULL)
        {
            cout << i->name << ": " << i->strength << ", " << i->speed << endl;
            i = i->next;
        }
        cout << "#Nodes: " << size() << endl;
    }
    
    void printFromTail()
    {
        Node<T>* i = tail;
        while (i != NULL)
        {
            cout << i->name << ": " << i->strength << ", " << i->speed << endl;
            i = i->prev;
        }
        cout << "#Nodes: " << size() << endl;
    }
    
   string rosterFormat()
    {
        string roster;
        Node<T>* i = head;
        if (empty())
        {
            return "empty";
        }
        while (i != NULL)
        {
            if (i->next != NULL)
            {
                roster += i->name + " ";
                i = i->next;
            }
            else
            {
                roster += i->name;
                i = i->next;
            }

        }
        
        return roster;
    }
    
    PlayerInterface* next_player(PlayerInterface* playerx)
    {
        Node<T>* temp = head;
        
        if (tail->name == playerx->getName())
        {
            return nullptr;
        }
        
        if (head->name == playerx->getName())
        {
            return head->next->player;
        }
        
        while (temp->next != NULL)
        {
            if (temp->next->name == playerx->getName())
            {
                return temp->next->next->player;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    
    PlayerInterface* prev_player(PlayerInterface* playerx)
    {
        Node<T>* temp = head;
        
        if (tail->name == playerx->getName())
        {
            return tail->prev->player;
        }
        if (head->name == playerx->getName())
        {
            return nullptr;
        }
        
        while (temp->next != NULL)
        {
            if (temp->next->name == playerx->getName())
            {
                return temp->player;
            }
            temp = temp->next;
        }
        return 0;
    }
    
        
        
        
};

