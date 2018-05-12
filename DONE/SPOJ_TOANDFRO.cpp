#include <stdio.h>

int main(){
    //freopen("entrada.in", "r", stdin);
    int col;
    char out[205];
    while(1){

        scanf("%d\n", &col);
        if(!col) break;
        int count =0;
        for(char c='a'; (c= getchar())!= '\n'; count++){
            out[count]= c;
            //printf("%c", c);
        }
        //printf("\n");
    
        /*for(int i=0; i<count; i++) {
            printf("%c", out[count]);
        }*/

        int nfilas= count/col;

        //printf("count = %d\n", count);
       // printf("nfilas = %d\n", nfilas);
        
        bool jump=true;
        for(int i=0, j=0,pos=j, stepsize=1,jumpsize= col*2 -stepsize;count>0 ;count--,i++){
            if(i >= nfilas){
                i=0;
                jump=true;
                j++;
                pos= j;
                stepsize+=2;
                jumpsize-=2;
            }
            printf("%c", out[pos]);

            if(jump){
                jump=false;
                pos+= jumpsize;
            }else{
                jump=true;
                pos+= stepsize;
            }
        } 
        printf("\n"); 

    }
    return 0;
}