/*conversion */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 100
char stack[size];
char str[size];
int top=-1;
int key;
char pop();
int isoperator(char symbol);
int precedence(char symbol);
char *infixtopostfix(char infix[]);
char *infixtoprefix(char infix[]);
char *postfixtoinfix(char str[]);
char *prefixtoinfix(char prefix[]);
void push(char symbol);
char pop();
int precedence(char symbol);
int main()
{
char infix[20];
char prefix[20];
int *ptr;
int choice;
while(1)
{
printf("The menu is:\n");
printf("1-Infix to postfix\n2-Infix to prefix\n3-Postfix to infix\n4-Postfix to prefix\n5-Prefix to infix\n6-Prefix to postfix\n7-exit\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the infix expression:\n");
scanf("%s",infix);
ptr=infixtopostfix(infix);
printf("The postfix expession is:\n");
            printf("%s\n",ptr);
break;
case 2:
printf("Enter the infix expression:\n");
scanf("%s",infix);
ptr=infixtoprefix(infix);
 printf("The prefix expression is:\n");
        printf("%s\n",ptr);

break;

case 3:
 printf("Enter the postfix expression:\n");
            scanf("%s",str);
ptr=postfixtoinfix(str);
  printf("The infix expression is:\n");
            printf("%s\n",ptr);
            
break;
case 4:
printf("Enter the postfix expression:\n");
            scanf("%s",str);
ptr=postfixtoinfix(str);
ptr=infixtoprefix(ptr);
printf("The prefix expression is:\n");
printf("%s\n",ptr);
break;

case 5:
printf("Enter the prefix expression:\n");
scanf("%s",prefix);
ptr=prefixtoinfix(prefix);
printf("The infix expression is:\n");
printf("%s",ptr);
printf("\n");
break;
case 6:
printf("Enter the prefix expression:\n");
scanf("%s",prefix);
ptr=prefixtoinfix(prefix);
ptr=infixtopostfix(ptr);
printf("The postfix expression is:\n");
printf("%s",ptr);
printf("\n");
break;
case 7:
exit(0);
break;
default:
printf("Invalid choice:\n");
}
}
}	


//    for convert infix to postfix 

            char *infixtopostfix(char infix[])
            {
             static char postfix[20];
            char item,x;
            int i=0,j=0;
            push('(');
            strcat(infix,")");
            while(infix[i] != '\0')
            {
            item=infix[i];
            if(item=='(')
            push(item);
            else if( isdigit(item) || isalpha(item) )
            {
            postfix[j]=item;
            j++;
            }
            else if(isoperator(item)==1)
            {
            x=pop();

            while(isoperator(x)==1 && precedence(x)>=precedence(item))
            {
            postfix[j]=x;
            j++;
            x=pop();
            }
            push(x);
            push(item);
            }
            else if(item==')')
            {   
            x=pop();
            while(x != '(')
            {
            postfix[j]=x;
            j++;
            x=pop();
            }
            }
            i++;
            }
            return postfix;
            }
// for push the value on the Stack
    void push(char symbol)
    {
    if(top==size-1)
    printf("Stack is Full");
    else
    {
    top++;
    stack[top]=symbol;
    }
    }
// for check given symbol is opeartor or not
    int isoperator(char symbol)
    {
    if(symbol=='^' || symbol=='*' || symbol=='/' || symbol=='+' || symbol=='-')
    return 1;
    else 
    return 0;
    }   
    
// for pop the value on the stack
    char pop()
    {   
    char x;
    if(top==-1)
    printf("Stack is Empty");
    else
    {
    x=stack[top];
    top--;
    return x;
    }
    }
// for check precedence of given operator
        int precedence(char symbol)
        {
        if(symbol=='^')
        return 3;
        else if (symbol=='*' || symbol=='/')
        return 2;
        else if(symbol=='+' || symbol=='-')
        return 1;
        else 
        return 0;
        }
// claculating to infix to prefix
void f2()
{
char infix[20];

}

//convert infix to prefix 
    char *infixtoprefix(char infix[])
    {
    int l,i=0,j=0;
    char x,item;
   static char prefix[20];
    l=strlen(infix);
    for(i=0;i<l;i++)
    {
    x=infix[i];
    push(x);
    }
    for(i=0;i<l;i++)
    {
    infix[i]=pop();
    }
    push(')');
    strcat(infix,"(");
    i=0;
    
            while(infix[i] != '\0')
            {
            item=infix[i];
            if(item==')')
            push(item);
            else if( isdigit(item) || isalpha(item) )
            {
            prefix[j]=item;
            j++;
            }
            else if(isoperator(item)==1)
            {
            x=pop();

            while(isoperator(x)==1 && precedence(x)>=precedence(item))
            {
            prefix[j]=x;
            j++;
            x=pop();
            }
            push(x);
            push(item);
            }
            else if(item=='(')
            {   
            x=pop();
            while(x != ')')
            {
            prefix[j]=x;
            j++;
            x=pop();
            }
            }
            i++;
            }
            l=strlen(prefix);
            for(i=0;i<l;i++)
            {
            x=prefix[i];
            push(x);
            }
            for(i=0;i<l;i++)
            {
            prefix[i]=pop();
            }
       return prefix;
    }

// convert postfix to infix 
            char *postfixtoinfix(char str[])
            {
            int i,l,j=0;
            char a,b,exe,temp,x[20],symbol;
           static char dup[20];
           
            l=strlen(str);
            for(i=0;i<l/2;i++)
            {
             temp=str[l-1-i];
             str[l-1-i]=str[i];
             str[i]=temp;
            }
            for(i=0;i<l-1;i++)
            {
            symbol=str[i];
            if(symbol=='*' || symbol=='-' || symbol=='/' || symbol=='+' || symbol=='^')
            push(symbol);
            else
            {
             
             x[j]=symbol;
             j++;
             
              x[j]=pop();
              j++;
            }
            x[j]=str[l-1];
            }
            for(i=0;i<l;i++)
            {
             dup[i]=x[l-1-i];
            }
             return dup;  
            }
// convert prefix to infix 
        char *prefixtoinfix(char prefix[])
        {
        int n,j,i=0;
        j=0;
        char x,y,item;
        static char dup[20];
        n=strlen(prefix);
        for(i=0;i<size;i++)
        stack[i]='\0';
        for(i=0;i<n-1;i++)
        {
        if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*'|| prefix=='/')
        {
        push(prefix[i]);
        }
        else
        {
        item=pop();
        x=prefix[i];
        dup[j]=x;j++;
        dup[j]=item;j++;
        }
        }
        dup[j]=prefix[i];
        return dup;
        }






