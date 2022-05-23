#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct node
{
    char lhs[10];
    char rhs[10];
};
struct node n[5];

void initialise()
{
    int i;
    strcpy(n[0].lhs,"S");strcpy(n[0].rhs,"aS");
    strcpy(n[1].lhs,"S");strcpy(n[1].rhs,"aT");
    strcpy(n[2].lhs,"T");strcpy(n[2].rhs,"bW");
    strcpy(n[3].lhs,"W");strcpy(n[3].rhs,"c");
    printf("\nGrammar is");
    for(i=0;i<4;i++)
    {
        printf("\n%s->%s",n[i].lhs,n[i].rhs);
    }
}
char stack[25];
int top=-1;
char str[30];
void push(char s)
{
    stack[++top]=s;
}
char pop()
{
    return(stack[top--]);
}

void display()
{
    int k;
    for(k=0;k<=top;k++)
        printf("%c",stack[k]);
}

void main()
{
    char temp[10],temp1,temp3[5];
    int i=0,j,k,t,flag,tflag=0;
//    clrscr();
    initialise();
    printf("\nEnter Input String:\n");
    scanf("%s",str);
    printf("\nStack\t\tAction\n");
    while(i<strlen(str))
    {
        push(str[i]);
        printf("\n");
        display();
        printf("\t\tShift%c",str[i++]);
    }
    j=top;flag=1;
    while(top!=0)
    {
        tflag=0;
        if(flag==1)
        {
            temp3[0]=pop();
            temp3[1]='\0';
            flag=0;
        }
        else
        {
            temp3[0]=pop();temp3[1]=pop();temp3[2]='\0';strrev(temp3);
        }
        for(i=0;i<4;i++)
        {
            if(strcmp(temp3,n[i].rhs)==0)
            {
                k=0;t=strlen(n[i].lhs);
                while(k<t)
                    {
                        push(n[i].lhs[k]);
                        k++;printf("\n");
                        display();
                        printf("\t\tReduce %s->%s",n[i].lhs,n[i].rhs);
                        tflag=1;
                    }
                    break;
            }
        }
            if(tflag==0)
                break;
    }
        if(stack[0]=='S')
            printf("\nString is accepted");
        else
            printf("\nString is not accepted");
        getch();
}
