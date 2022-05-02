#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
charastr[100];
char lhs[9]={"E","e","T","t","F","F"};
char rhs[8][4]={"Te","+Te","N","Ft","*Ft","N","(E)","i"};
char afirst[11][15];
char set[12]={'e','E','T','t','F','i','+','*','('*')','$'};

charafollow[5][15];
int prod[5][6];

int indexof(char a){
    int i;
    for(i=0;i<11;i++){
        if(set[i]==a){
            return i;
        }
    }
}
int isterminal(char a){
    int i;
    for(i=5;i<9;i++){
        if (set[i]=='a'){
            return 1;
        }
        if(a=='N'){
            return 1
        }
    }
    return 0;
}
int count[11];
int focount[5];

void first(intabc){
    int j,i;
    if(abc>=5){
        afirst[abc][0]=set[abc];
        count[abc]=1;
    }
    else{
        for(i=0;i<8;i++){
            if (lhs[i]==set[abc]){
                if (isterminal(rhs[i][0])){
                    afirst[abc][count[abc]++]=rhs[i][0];
                }
                else{
                    first(indexof(rhs[i][0]));
                    for(j=0;j<count[indexof(rhs[i][0])];j++){
                        afirst[abc][count[abc]++]=afirst[indexof(rhs[i][0])][j];
                    }
                }
            }
        }
    }
}
void rem_rep{
    int i,j,k;


}

void follow(int abc){
    int i,j,k;
    for(i=0;i<8;i++){
        for(j=0;j<strlen(rhs[i]);j++){
            if (rhs[i][j]==set[abc]){
                if((j+1)!=strlen(rhs[i])){
                    for(k=0;k<count[indexof(rhs[i])];k++){
                        afollow[abc][focount[abc]++]=afirst[indexof(rhs[i][j+1])][k];
                    }

                }
                else if (set[abc]!=lhs[i]){
                    if(!focount[indexof(lhs[i])]){
                        follow(indexof(lhs[i]));
                        for(k=0;k<focount[indexof(lhs[i])];k++){
                            afollow[abc][focount[abc]++]=afollow[indexof(lhs[i])][k];
                        }
                    }
                }
                if (afollow[abc][focount[abc]-1]=='N'){
                    focount[abc]--;
                    if (!focount[indexof(lhs[i])]){
                        follow(indexof(lhs[i]));
                        for(k=0;k<focount[indexof(lhs[i])];k++){
                            afollow[abc][focount[abc]++]=afollow[indexof(lhs[i])][k];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
