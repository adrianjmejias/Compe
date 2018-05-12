#include <stdio.h>

int main(){
    freopen("entrada.in", "r", stdin);
    int T;
    scanf("%d\n", &T);

    while(T--){
        int n,num,den;
        scanf("%d\n", &n);
        int count=1;
        int j=1, i=1;
            for(int movi=0, movj=1;count<n ;i+=movi, j+=movj,count++){

                printf("i=%d  || j=%d\n",i,j);
            }   
        printf("TERM %d IS %d/%d\n",n,i,j);
        
    }
    return 0;
}