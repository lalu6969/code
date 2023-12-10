/* 
Assignment No.2
Title:- Stack

Problem Statement:- Implement stack as an abstract data type
using singly linked list and use this ADT for conversion of infix
expression to postfix, prefix and evaluation of postfix and prefix
expression.

*/

//CODE


/***********************Infix to Postfix ******************************/ 

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


bool isOperator(char c){
 if (c =='+' || c == '-' || c == '*' || c == '/' || c == '^') 
 return true;
 else
 return false;
}


int precedence(char c){
 if (c == '^' || c == '$')
 return 3;
 if (c == '*' || c == '/')
 return 2;
 if(c =='+' || c == '-')
 return 1;
 else
 return -1;
}

// INFIX TO POSTFIX CONVERSION FUNCTION
string InfixToPostfix(stack<char> s, string infix ){
 string postfix;
 
 for (int i = 0; i < infix.length(); i++)
 {
 	if ((infix[i] >= 'a' && infix[i] <= 'z') ||(infix[i] >= 'A' && infix[i] <='Z'))
 	{
 		
 		postfix += infix[i];
 	}
 	
 	else if(infix[i] == '(')
 	s.push(infix[i]);
 	
 	else if(infix[i] == ')')
	{
 		while ((s.top() != '(') && (!s.empty()))
 		{
 		postfix += s.top();
 		s.pop();
 		}
 		
 		if(s.top() == '(')
 		s.pop();
 	}
 	
 	else if(isOperator(infix[i]))
	{
 		if(s.empty())
 		{
 			
 			s.push(infix[i]);
 		}
 		else
 		{
 			if (precedence(infix[i]) == precedence(s.top()) && infix[i] =='^')
 			{ 
			 	s.push(infix[i]);
			}
 			else
 			{
 				while ((!s.empty()) && (precedence(infix[i]) <=
				precedence(s.top())))
 				{
					
				    postfix+=s.top();
				    s.pop();
 				}
 			s.push(infix[i]);
 			}
 		}
 	}
}
 while (!s.empty())
 {
	 // cout << s.top() << endl;
	 postfix += s.top();
	 s.pop();
 }

 return postfix;
 
}


int main()
{
 string infix, postfix;
 cout << "Enter a Infix EXPRESSION :";
 cin >> infix;
 stack <char> stack; 
 postfix = InfixToPostfix(stack, infix);
 cout << "\nPOSTFIX EXPRESSION :" << postfix << endl;
 return 0;
}

//OUTPUT

/*

Enter a Infix EXPRESSION :A+B

POSTFIX EXPRESSION :AB+

--------------------------------
Process exited after 2.097 seconds with return value 0
Press any key to continue . . .


Enter a Infix EXPRESSION :A+B

PREFIX EXPRESSION :+AB

--------------------------------
Process exited after 3.252 seconds with return value 0
Press any key to continue . . .


Enter a POSTFIX Expression : 56+

Your Evaluated POSTFIX EXPRESSION is : 11

--------------------------------
Process exited after 4.477 seconds with return value 0
Press any key to continue . . .


Enter a PREFIX Expression : +56
Your Evaluated PREFIX EXPRESSION is : 11

--------------------------------
Process exited after 4.396 seconds with return value 0
Press any key to continue . . .

*/
