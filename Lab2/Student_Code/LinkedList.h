//Austin Tebbs
#pragma once
#include "LinkedListInterface.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>


template <class T>
class LinkedList : public LinkedListInterface <T> {


    public:
        
        Node<T>* head;
        Node<T>* tail;
        int num_items;

        LinkedList() //when we initialize list, nothing in it so head and tail are pointing to nothing
        {
            head = NULL;
            num_items = 0;
        }
        ~LinkedList()
        {
            clear();
        }

	bool isDuplicate(T value)
	{
	    Node<T>* temp = head;
	    while (temp != NULL)
            {
		if (temp->data == value)
		{
			return true;
		}
		temp = temp->next;
	    }        
		
	    return false;	
	}        
        virtual void insertHead(T value)
        {
            Node<T>* temp = head;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    return;
                }
                temp = temp->next;
            }
            if (head == NULL) //if there are no nodes in list, simply have head point to value
            {
                head = new Node<T>(value);
            }
            else
            {
                //head needs to point to value, value->next points to old head, old head
                head = new Node<T>(value, head);
                
            }
            num_items++;
        }
        
        virtual void insertTail(T value)
        {
            Node<T>* temp = head;
            while (temp != NULL)
            {
                if (temp->data == value)
                {
                    return;
                }
                temp = temp->next;
            }
            if (head == NULL) // if no nodes, value is head
            {
                head = new Node<T>(value);
                tail = head;
            }
            else
            {
                Node<T>* temp = head;
                while(temp->next != NULL) //interate through list until we find last item
                {
                    temp = temp->next;
                }
                tail = new Node<T>(value); // tail points to value
                temp->next = tail;      // 2nd to last item now points to tail
                tail->next = NULL;      // tail->next points to NULL
            }
            num_items++;
        }
        
        
        
        virtual void insertAfter(T value, T insertionNode)
        {
            
            Node<T>* temp = head;
            
            if (isDuplicate(value))
	    {
   	     	return;
	    }
         
            
            
            while(temp != NULL) //iterate through list
            {
                if(temp->data == insertionNode) //for each iteration check to see if we should insert value
                {
		    Node<T>* to_add = new Node<T>(value);
                    to_add->next = temp->next; //if we do, point our value->next to same as temp->next
                    temp->next = to_add;        // now point temp->next to our new value
                    num_items++;
                    return;
                }
                temp = temp->next;
            }
            
        }
        
        virtual void remove(T value)
        {
            Node<T>* to_remove = head;
            Node<T>* temp = head;
            
            if (head->data == value)
            {
                head = temp->next;
                delete temp;
                num_items--;
                return;
            }
    
            while (temp->next != NULL)
            {
                if (temp->next->data == value)
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
            
            
        }
        
        virtual void clear()
        {
            while (head != NULL)
            {
                Node<T>* temp = head->next;
                delete head;
                head = temp;
            }
            num_items = 0;
        }
        virtual T at(int index)
        {
            int pos =0;
            T value;
            Node<T>* temp = head;
	    if (head == NULL)
	    {
		throw out_of_range("The given value of index is out of range of the list");
	    }

            while (temp != NULL)
            {
                if (index == pos)
                {
                    value = temp->data;
                }
                temp = temp->next;
                
                pos++;
            }
            if (index < 0 || index >= size())
            {
                throw out_of_range("The given value of index is out of range of the list");
            }
            return value;
        }
        virtual int size()
        {
            return num_items;
        }
        
        void print()
        {
            Node<T>* i = head;
            while (i != NULL)
            {
                cout << i->data << ", ";
                i = i->next;
            }
            cout << endl << "#Nodes: " << size() << endl << endl;
        }
        
   
     
        
        
        
    };

