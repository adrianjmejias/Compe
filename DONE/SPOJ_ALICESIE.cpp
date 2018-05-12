#include <stdio.h>
using namespace std;
int main(){
    //freopen("entrada.in", "r", stdin);
    int T;
    unsigned int N;

    scanf("%d\n", &T);
    while(T--){
        scanf("%u\n", &N);
        //printf("%u---->",N);
        if (N % 2 ==0)
            printf("%u\n", N/2);
        else
            printf("%u\n", N/2 +1);
    }
    return 0;
}