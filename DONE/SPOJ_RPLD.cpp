#include <stdio.h>
#include <set>
#include <stack>
using namespace std;

int main(){
    //freopen("entrada.in","r",stdin);
    int T, ND , NE,E, M;
    set<int> data[100010];
    stack <int> clearStack;
    scanf("%d\n", &T);

    for(int i=1; i<=T; i++){
        printf("Scenario #%d: ",i);

        bool possible=true;
        scanf("%d %d\n",&NE, &ND);

        while(ND--){
            scanf("%d %d\n", &E, &M);
            clearStack.push(E);
            //printf("combo %d, %d\n", E, M);
            if(data[E].find(M) == data[E].end()){
                data[E].insert(M);
            }else{
                //printf("PELASTE %d ---> %d\n", E,M);
                possible=false;
            }
        }

        while(!clearStack.empty()){
            data[clearStack.top()].clear();
            clearStack.pop();
        }

        if(!possible) printf("im");
        printf("possible\n");
    }

    return 0;
}