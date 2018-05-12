#include <stdio.h>
#include <map>
#include <utility>
#define mp(a,b) make_pair(a,b)
#define leftp left->second
#define rightp right->second
using std::pair;
using std::map;
using std::make_pair;
//http://openframeworks.cc/ofBook/chapters/stl_map.html
int main(){
    //freopen("entrada.in","r",stdin);
    int Q;
    scanf("%d\n", &Q);
    map< int,pair<int,int>  > sha;
    map<int, pair<int,int> > :: iterator left;
    map<int, pair<int,int> > :: iterator right;
    
    int count=0;
    while(Q--){
        int num, auxl, auxr; 
        scanf("%d", &num);
        
        right = sha.find(num+1);
        left = sha.find(num-1);

        //printf("num %d\n", num);
        if(left == sha.end()){
            if(right == sha.end()){//nuevo
                sha[num]= make_pair(num,num);
                count++;
            }else{//completo a la izquierda

                if(rightp.first == rightp.second){
                    //si es un conjunto de un solo numero
                    rightp.first--;
					sha[rightp.first]= mp(rightp.first, rightp.second);
                }
                else{
                	rightp.first--;
            		sha[rightp.first] = mp(rightp.first, rightp.second);
            		sha.find(rightp.second)->second.first--;
            		sha.erase(right);
					
                }

            }
        }else{
            if(right == sha.end()){
			//completo a la derecha
				
	            if(leftp.first== leftp.second){
	            	leftp.second++;
	            	sha[leftp.second]=mp(leftp.first, leftp.second);
				}else{
					sha.erase(leftp.second);
					leftp.second++;
					sha[leftp.second]=mp(leftp.first, leftp.second);
					sha.find(leftp.first)->second.second++;				
				}
			
            }else{//uno conjuntos done
            
                if(leftp.second != leftp.first){
                	left= sha.find(leftp.first);
            		sha.erase(leftp.second);
            		
				}
				if(rightp.second!= rightp.first){
                	right= sha.find(rightp.second);
					sha.erase(rightp.first);
				}
                
                leftp.second= rightp.second;
                rightp.first= leftp.first;
                count--;

            }
        }
		//for(map<int, pair<int,int> > :: iterator it = sha.begin(); it!= sha.end(); it++)
         //   printf("%d <%d, %d> %d\n",it->first, it->second.first, it->second.second,sha.size());
        printf("%d\n", count);
        
    }
	sha.clear();
    printf("Justice\n");
    return 0;
}
