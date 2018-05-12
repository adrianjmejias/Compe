#include <array>
#include <vector>
#define  nPins 10
#define nFrames 10
#define lastFrame 9

using std::vector;
using std::array;

void printFrame(vector<int> c, int a){
	printf("Frame %d |", a);
	for(int b: c){
		printf("%d ", b);
	}
	printf("\n");
}


int main(){

    //guarda la cantidad de pines restantes, de esa manera si reviso
    //frame[i][0]==0 es strike, o si hago frame[i][1]==0 es spare
    //freopen("entrada.in.cpp", "r", stdin);
    vector<int> frame[10];

    int T, lanz, nlanz, score;
    scanf("%d", &T);

    while(T--){
        scanf("\n");
        score =0;
        nlanz=2;
        for(int i=0; i<lastFrame; i++){
            int pinRestantes=nPins;
            
            for(int k=0; k<nlanz && pinRestantes; k++){

                scanf("%d", &lanz);
                frame[i].push_back(lanz);
                pinRestantes-= lanz;
                
            }
        }

        //trato el ultimo lanzamiento
        int pinRestantes=nPins;
        for(int k=0; k<nlanz; k++){
        	
            scanf("%d", &lanz);
            frame[lastFrame].push_back(lanz);
            pinRestantes-=lanz;
            
            if(pinRestantes == 0 && (k == 0 || k == 1)){//strike, strike doble O spare
                nlanz= (nlanz + 1 > 3)? nlanz: nlanz + 1;
                pinRestantes=nPins;
            }

        }
		
		//for(int i=0; i< nFrames; i++) printFrame(frame[i], i);
		//-------------------------------------------------------
        for(int i=0; i <lastFrame; i++){
            int lim=2, scoreFrame=0;
            //puedo hacer esto por short circuit evaluation, sino la segunda da segfault
            if(frame[i][0] == nPins || (frame[i][1]+frame[i][0]) == nPins) lim=3;//strike o spare

            int k = i;
            
            for (int j = 1; j <= lim; j++){
               
                if(j > frame[k].size()){
                    lim-= j-1;
                    k++;
                    j = 1; // 0 para que ++ lo ponga en1
                }
                
                scoreFrame += frame[k][j-1];
                //printf("sume %d ", frame[k][j-1]);
                
            }
            score+=scoreFrame;
            //printf("|%d scoreFrame %d\n", i,scoreFrame);
        }

        //Caso de frame final
		
		for(int aux : frame[lastFrame]){
			//printf("last %d ",aux);
			score+= aux;
		}
		//printf("\n");

        printf("%d\n",score);
        for(vector<int> &a : frame) a.clear();
    }

    return 0;
}
