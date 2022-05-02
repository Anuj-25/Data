#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

char str[100];

char lhs[9] = {'E','e','e','T','t','t','F','F'};
char rhs[8][4] = {"Te","+Te","N","Ft","*Ft","N","(E)","i"};
char afirst[11][15];
char set[12] = {'E','e','T','t','F','i','+','*','(',')','$'};

char afollow[5][15];
int prod[5][6];

int indexof(char a){
    int i;
    for(i=0;i<11;i++){
        if(set[i] == a){
            return i;
        }
    }
}

int isterminal(char a){
    int i;
    for(i =5;i<9;i++){
        if(set[i] == a){
            return 1;
        }
    }
    if(a == 'N'){
        return 1;
    }
    return 0;
}


int count[11];
int focount[5];


void first(int abc){
    int i,j;
    if(abc >= 5){
        afirst[abc][0] = set[abc];
        count[abc] = 1;
    }

    else{
        for(i=0;i<8;i++){
            if(lhs[i] == set[abc]){
                if(isterminal(rhs[i][0])){
                    afirst[abc][count[abc]++]= rhs[i][0];
                }
                else{
                    first(indexof(rhs[i][0]));
                    for(j=0;j<count[indexof(rhs[i][0])];j++){
                        afirst[abc][count[abc]++] = afirst[indexof(rhs[i][0])][j];
                    }
                }
            }
        }
    }
}

void rem_rep(char a[15]){
    int i,j,k;
    for(i=0;i<strlen(a);i++){
        for(j = i+1 ;j<strlen(a);j++){
            if(a[i] == a[j]){
                for(k = j;k<strlen(a);k++){
                    a[k] = a[k+1];
                }
            }
        }
    }
}

void follow(int abc){
    int i,j,k;
    for(i=0;i<8;i++){
        for(j=0;j<strlen(rhs[i]);j++){
            if (rhs[i][j]==set[abc]){
                if((j+1)!=strlen(rhs[i])){
                    for(k=0;k<count[indexof(rhs[i][j+1])];k++){
                        afollow[abc][focount[abc]++]=afirst[indexof(rhs[i][j+1])][k];
                    }

                }
                else if (set[abc]!=lhs[i]){
                    if(!focount[indexof(lhs[i])])
                        follow(indexof(lhs[i]));
                        for(k=0;k<focount[indexof(lhs[i])];k++){
                            afollow[abc][focount[abc]++]=afollow[indexof(lhs[i])][k];
                        }
                }
                if (afollow[abc][focount[abc]-1]=='N'){
                    focount[abc]--;
                    if (!focount[indexof(lhs[i])])
                        follow(indexof(lhs[i]));
                        for(k=0;k<focount[indexof(lhs[i])];k++){
                            afollow[abc][focount[abc]++]=afollow[indexof(lhs[i])][k];
                        }
                }
            }
        }
    }
}


int main(){
    char ch,str[100];
    int i,val,ind,k,l;
    char stack[100];
    int top = 1;
    int current = 0;

    for(int i = 0;i<11;i++){
        if(!count[i]){
            first(i);
        }
    }
    for(i = 0;i<11;i++){
        printf("\nFirst of %c is given by %s",set[i],afirst[i]);
    }

    for(i =0;i<5;i++){
        if(!focount[i]){
            follow(i);
            if(i==0){
                focount[0]++;
                afollow[0][focount[0] - 1] = '$';
            }
            rem_rep(afollow[i]);
        }
    }

    for(i=0;i<5;i++){
        rem_rep(afollow[i]);
    }
    for(i=0;i<5;i++){
        printf("\nFollow of %c is given by %s",set[i],afollow[i]);
    }

    for(i=0;i<8;i++){
        ch = rhs[i][0];
        if(ch !='N'){
            ind = indexof(ch);
            for(k=0;k<count[ind];k++){
                if(afirst[ind][k]!= 'N'){
                    prod[indexof(lhs[i])][indexof(afirst[ind][k]) - 5] = i+1;
                }
                else{
                    for(l=0;i<focount[indexof(lhs[i])];l++){
                       prod[indexof(lhs[i])][indexof(afollow[indexof(lhs[i])][l]) - 5] = i+1;
                    }
                }
            }
        }
    }
    for(i =0;i<100;i++){
        str[i] = stack[i] = '\0';
        printf("\nEnter the strings (Use i for an identifier)");
        gets(str);
        str[strlen(str)] = '$';
        str[strlen(str)+1] = '\0';
        current = 0;
        stack[0] = '$';
        stack[1] = 'E';
        while(strcmp(stack,"$") != 0 || str[current] != '$'){
            printf("\n%s  \t\t",stack);
            for(i = current;i<strlen(str);i++){
                printf("%c",str[i]);
            }
            if(isterminal(stack[top])){
                val = prod[indexof(stack[top])][indexof(str[current])-5];
                if(val == 0){
                    printf("\n Not Accepted");
                    exit(0);
                }
                top-- ;
                stack[top+1] = '\0';
                for(k=strlen(rhs[val-1])-1;k>=0;k--){
                    if(rhs[val-1][k] != 'N'){
                        stack[++top] = rhs[val-1][k];
                    }
                }
            }
            else{
                if(stack[top] == str[current]){
                    top--;
                    stack[top+1] = '\0';
                    current++;
                }
                else{
                    printf("\nNot Accepted");
                    exit(0);
                }
            }
        }
    }
    printf("\nAccepted");
    return 0;
}
