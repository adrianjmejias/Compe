#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define s2i(a) atoi(buff[a])

int main(){
    //freopen("entrada.in", "r", stdin);
    int T;
    char buff[3][30];
    scanf("%d", &T);
    
    while(T--){
        scanf("\n");
        scanf("%s + %s = %s", buff[0], buff[1], buff[2]);
       // printf("%s __ %s __ %s\n", buff[0], buff[1], buff[2]);
        int a, b, x, i;
        for(i=0; i<3; i++){
            if(strchr(buff[i],'m')!=NULL)break;
        }

        //printf("i= %d\n",i);
        if(i==2){
            printf("%s + %s = %d", buff[0], buff[1], s2i(0) + s2i(1));
        }if(i==1){
            printf("%s + %d = %s", buff[0], s2i(2) - s2i(0), buff[2]);
        }if(i==0){
            printf("%d + %s = %s", s2i(2) - s2i(1), buff[1], buff[2]);
        }
        printf("\n");
    }

    return 0;
}