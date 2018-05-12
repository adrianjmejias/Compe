#include <stdio.h>
#include <functional>
#include <queue>
#include <vector>
#define nl printf("\n")
using namespace std;

int main(){
    //sfreopen("entrada.in","r", stdin);
    priority_queue < greater<int>, vector<int> > friends;

    int N;
    int iN=1;
    int goal, nfriends;
    int aux;

    scanf("%d", &N);

    while(iN<=N){
        printf("Scenario #%d:\n", iN);
        scanf("%d %d\n", &goal, &nfriends);

        while(nfriends--){
            scanf("%d", &aux);
            friends.push(aux);
        }

        int re=0;
        while(!friends.empty() && goal > 0){
            //printf("%d ", friends.top()); 
            goal-= friends.top();
            friends.pop();
            re++;
        }

        if(goal>0){
            printf("impossible");
        }else{
            printf("%d", re);
        }
        nl;nl;

        while(!friends.empty()) friends.pop();
        iN++;
    }

    return 0;
}