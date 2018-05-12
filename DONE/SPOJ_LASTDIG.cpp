#include <stdio.h>
#include <math.h>
int main(){
    //freopen("entrada.in", "r", stdin);
    int T;
    scanf("%d", &T);
    int caso[10][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {6, 2, 4, 8},
        {1, 3, 9, 7},
        {6, 4, 6, 4},
        {5, 5, 5, 5},
        {6, 6, 6, 6},
        {1, 7, 9, 3},
        {6, 8, 4, 2},
        {1, 9, 1, 9}
    };
    
    while (T--)
    {
        int a,b;
        scanf("%d %d\n", &a, &b);
        if(b==0){
            printf("1\n");
            continue;
        }
        printf("%d\n", caso[a%10][b%4]);
    }    
    return 0;
}