#include "ExpressionManager.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

ExpressionManager::ExpressionManager(){}
ExpressionManager::~ExpressionManager(){}


bool ExpressionManager::isOpen(char parenth)
{
    if (parenth == '{' || parenth == '[' || parenth == '(')
    {
        return true;
    }
    return false;
}

bool ExpressionManager::isClose(char parenth)
{
    if (parenth == '}' || parenth == ']' || parenth == ')')
    {
        return true;
    }
    return false;
}

bool ExpressionManager::isParenth(char parenth)
{
    if (!isOpen(parenth) && !isClose(parenth))
    {
        //cout << "not a parenth, bracket, or curly brace\n\n";
        return false;
    }
        return true;
}

bool ExpressionManager::isCorresponding(char first, char second)
{
    //first = top
    if (first == '{' && second == '}')
    {
        return true;
    }
    else if (first == '[' && second == ']')
    {
        return true;
    }
    else if (first == '(' && second == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ExpressionManager::isBalanced(string expression)
{
    stack <char> mystack;
    
    for (int i=0; i < expression.size(); i++)
    {
        if (isOpen(expression[i]))
        {
            mystack.push(expression[i]);
        }
        else if (isClose(expression[i]))
        {
            if (mystack.empty())
            {
                cout << "invalid - close parenth before open\n\n";
                return false;
            }
            else
            {
                char top = mystack.top();
                if (isCorresponding(top, expression[i]))
                {
                    mystack.pop();
                }
                else
                {
                    cout << "invalid - not corresponding\n\n";
                    return false;
                }
            }
        }
    }
    
    if (!mystack.empty())
    {
        return false;
    }
    
    return true;
}
bool ExpressionManager::isValidOperator(char op)
{
    if (op == '-' || op == '+' || op == '*' || op == '/' || op == '%' || op == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ExpressionManager::isInfix(string expression)
{
    string temp;
    
    for (int i=0; i < expression.size(); i++)
    {
        if (!isParenth(expression[i]) && expression[i] != ' ')
        {
            temp += expression[i];
        }
    }
    
    for (int i=0; i < temp.size(); i++)
    {
        if (isValidOperator(temp[i]) && isValidOperator(temp[i+1]))
        {
            return false;
        }
    }
    
    return true;
}
bool ExpressionManager::isPostfix(string expression)
{
    int counter=0;
    if (!isdigit(expression[0]))
    {
        return false;
    }
    
    for (int i=0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]) && !isdigit(expression[i+1]))
        {
            counter++;
        }
        else if (isValidOperator(expression[i]) && expression[i] != ' ')
        {
            counter--;
        }
        //cout << i << ":" << counter << endl;
    }
   // cout << "counter: " << counter << endl;
    
    if (counter == 1)
    {
        return true;
    }
    
    return false;
}
bool ExpressionManager::isValid(string expression)
{
    bool anyNum = false;
    if (!isBalanced(expression))
    {
        cout << "not balanced\n";
        return false;
    }
    for (int i=0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]))
        {
            anyNum = true;
        }
    }
    
    if (!anyNum)
    {
        return false;
    }
    
    for (int i=0; i < expression.size(); i++)
    { // if the char is not a number &&it is not an approved operand & not a parenth, return false
        if (!isdigit(expression[i]) && !isValidOperator(expression[i]) && !isParenth(expression[i]))
        {
            cout << "not a number, parenth, or valid operator\n\n";
            return false;
        }
    }
    
    return true;
}

int ExpressionManager::precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
    string infix;
    stack <string> mystack;
    string left;
    string right;
    
    if(!isValid(postfixExpression))
    {
        return "invalid";
    }
    if(!isPostfix(postfixExpression))
    {
        return "invalid";
    }
    
    for (int i=0; i < postfixExpression.size(); i++)
    {
        cout << "index: " << i << " stacksize: " << mystack.size() << endl;
        if (mystack.empty())
        {
            // do nothing
        }
        
        if (isdigit(postfixExpression[i]) && !isdigit(postfixExpression[i+1]))
        {
            if (isdigit(postfixExpression[i-1]))
            {
		if (i == 0)
		{
		   string temp;
		   temp += postfixExpression[i];
	   	   mystack.push(temp);
		}

                //cout << "in loop on index: " << i << endl;
		//cout << "where char: " << postfixExpression[i] << endl << endl;
            }
            else
            {
                string temp;
                temp += postfixExpression[i];
                //cout << "TEMP: " << temp << endl;
                mystack.push(temp);
            }
        }
        else if (isdigit(postfixExpression[i]) && isdigit(postfixExpression[i+1]))
        {
            string temp;
            temp += postfixExpression[i];
            temp += postfixExpression[i+1];
            //cout << "TEMP: " << temp << endl;
            mystack.push(temp);
        }
        else if (isValidOperator(postfixExpression[i]) && postfixExpression[i] != ' ')
        {
            if (mystack.empty())
            {
                return "invalid";
            }
            else
            {
                string op;
                op += postfixExpression[i];
                right = mystack.top();
		cout << "top: " << mystack.top() << endl;
                mystack.pop();
		
                if (mystack.empty())
                {
		    cout << "empty\n";
                    return "invalid";
                }
                left = mystack.top();
                mystack.pop();
                infix = "( " + left + " " + op + " " + right + " )";
                cout << "inFix: " << infix << endl;
                mystack.push(infix);
            }
        }

    }
    
    if (mystack.empty())
    {
        return "invalid";
    }
    return mystack.top();
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
    string pfix;
    stack <char> mystack;
    
    if (!isValid(infixExpression))
    {
        return "invalid";
    }
    
    if(!isInfix(infixExpression))
    {
        return "invalid";
    }
    
    for (int i=0; i < infixExpression.size(); i++)
    {
        if (isdigit(infixExpression[i]))
        {
            if (isdigit(infixExpression[i+1]))
            {
                pfix += infixExpression[i];
            }
            else
            {
                pfix += infixExpression[i];
                pfix += " ";
            }
        }
        else if (isValidOperator(infixExpression[i]))
        {
            if (infixExpression[i] == ' ')
            {
                // do nothing
            }
            else if (mystack.empty())
            {
                mystack.push(infixExpression[i]);
            }
            else if (isParenth(mystack.top()))
            {
                mystack.push(infixExpression[i]);
            }
            else if (precedence(infixExpression[i]) > precedence(mystack.top()))
            {
                mystack.push(infixExpression[i]);
            }
            else
            {
                while (!mystack.empty() && precedence(infixExpression[i]) <= precedence(mystack.top()))
                {
                    pfix += mystack.top();
                    pfix += " ";
                    mystack.pop();
                }
                mystack.push(infixExpression[i]);
            }
        }
        else if (isParenth(infixExpression[i]))
        {
            if (isOpen(infixExpression[i]))
            {
                mystack.push(infixExpression[i]);
            }
            else if (isClose(infixExpression[i]))
            {
                while (!isCorresponding(mystack.top(), infixExpression[i]))
                {
                    pfix += mystack.top();
                    pfix += " ";
                    mystack.pop();
                }
                //error here, calling function on an empty stack.
                mystack.pop();
            }
        }

    }
    
    while (!mystack.empty())
    {
        pfix += mystack.top();
        pfix += " ";
        mystack.pop();
    }
    
    size_t last = 0;
    last = pfix.size() - 1;
    if (pfix[last] == ' ')
    {
        pfix.pop_back();
    }
    
    return pfix;
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
    stack <string> mystack;
    string right;
    string left;
    
    int answer = 0;
    
    if (!isValid(postfixExpression))
    {
        
        return "invalid";
    }
    
    if (!isPostfix(postfixExpression))
    {
        
        return "invalid";
    }
    
    for (int i=0; i < postfixExpression.size(); i++)
    {
	if (isdigit(postfixExpression[i]) && isdigit(postfixExpression[i+1]) && isdigit(postfixExpression[i+2]))
	{
	    string temp;
            temp += postfixExpression[i];
            temp += postfixExpression[i+1];
	    temp += postfixExpression[i+2];
            cout << "TEMP: " << temp << endl;
            mystack.push(temp);
	}
        else if (isdigit(postfixExpression[i]) && !isdigit(postfixExpression[i+1]))
        {
            if (isdigit(postfixExpression[i-1]))
            {
                // do nothing
            }
            else
            {
                string temp;
                temp += postfixExpression[i];
                //cout << "TEMP: " << temp << endl;
                mystack.push(temp);
            }
        }
        else if (isdigit(postfixExpression[i]) && isdigit(postfixExpression[i+1]))
        {
	    if (isdigit(postfixExpression[i-1]))
	    {
		//do nothing
	    }
	    else
	    {
            	string temp;
            	temp += postfixExpression[i];
            	temp += postfixExpression[i+1];
            	//cout << "TEMP: " << temp << endl;
            	mystack.push(temp);
	    }
        }
        else if (isValidOperator(postfixExpression[i]) && postfixExpression[i] != ' ')
        {
            //cout << postfixExpression[i] << endl;
         
            if (mystack.empty())
            {
                return "invalid";
            }
            right = mystack.top();
            mystack.pop();
            if (mystack.empty())
            {
                
                return "invalid";
            }
            left = mystack.top();
            mystack.pop();
            
            int ri, li;
            
            ri = atoi(right.c_str());
            li = atoi(left.c_str());
            
            //cout << "ri: " << ri << " li: " << li << endl;
            
            if (postfixExpression[i] == '-')
            {
                answer = li - ri;
            }
            if (postfixExpression[i] == '+')
            {
                answer = li + ri;
            }
            if (postfixExpression[i] == '*')
            {
                answer = li * ri;
            }
            if (postfixExpression[i] == '%')
            {
                answer = li % ri;
            }
            if (postfixExpression[i] == '/')
            {
                if (ri == 0)
                {
                    return "invalid";
                }
                else
                {
                    answer = li / ri;
                }
            }
            
            stringstream ss;
            
            //cout << "answer: " << answer << endl;
            ss << answer;
            
            mystack.push(ss.str());
            cout << "pushed onto stack: " << mystack.top() << endl;
        }
        

        

    }
    return mystack.top();
}
