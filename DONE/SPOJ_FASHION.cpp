 #include <stdio.h>
#include <queue>
#include <functional>

using namespace std;

 int main(){
    //freopen("entrada.in","r", stdin);
    int T,N;
    priority_queue <int> men, women;

    scanf("%d", &N);
    while(N--){
        scanf("%d", &T);
        int aux,n;

        n= T;
        //printf("lero lero \n");
        while(n--){
            scanf("%d", &aux);
            //printf("men %d\n", aux);
            men.push(aux);
        }

        n=T;
        //printf("lero lero \n");
        while (n--)
        {
            scanf("%d", &aux);
            //printf("women %d\n", aux);
            women.push(aux);
        }
        unsigned long int sum=0;
        //printf("lero lero \n");
        while(T--){
            //printf("%d ------ %d \n", women.top(), men.top());
            sum += women.top() * men.top();
            women.pop(); men.pop();
        }
        printf("%lu\n", sum);
    }
    return 0;
 }