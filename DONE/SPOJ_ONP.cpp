#include <vector>
#include <stdio.h>
#define c continue;
#define e exp[i]
#define SIZE_OP 5
using namespace std;

char OP[]={'+','-','*','^','/'};

bool isOp(char a){
    for(int i=0; i< SIZE_OP; i++){
        if(a == OP[i]) return true;
    }
    return false;
}

bool isNum(char a){
    return a<='z' && a>='a'; 
}


int main(){
    vector<char> num, op;
    char exp[410];
    int N;
    //freopen("entrada.in", "r",stdin);
    scanf("%d", &N);
    while(N--){
        scanf("%s", exp);
        for(int i=0; e!='\0'; i++){
            if(e =='(')c

            if(isOp(e)){
                //printf("op %c\n", e);
                op.push_back(e);
                c
            }
            if(isNum(e)){
                //printf("num %c\n", e);
                num.push_back(e);
                c
            }
            
            if(e ==')'){
                num.push_back(op.back());
                op.pop_back();
            }
        }
        for(int i=0; i<num.size(); i++)
            printf("%c", num[i]);
        printf("\n");
        num.clear();
    }

}