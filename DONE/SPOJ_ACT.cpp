#include <stdio.h>
#include <iostream>
#include <cstring>
int main(){
    //freopen("entrada.in","r", stdin);
    int N;
    scanf("%d\n", &N);
    char buff[50005];
    while(N--){
        scanf("%*d ");
        scanf("%s\n", buff);
        printf("%c\n", buff[strlen(buff)-1]);
    }

    return 0;
}