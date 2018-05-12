#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
using std:: queue;
using std:: min;
using std:: cout;

template <class T>
void printArr(T a[], int size){
	for(int i=0; i< size; i++)
		cout<<a[i]<<" ";
	printf("\n");
}

void printQueue(queue<int> a){
	while(!a.empty()){
		cout<<a.front()<<" ";
		a.pop();
	}
	printf("\n");
}

int main(){
	int T;
	//freopen("entrada.in.cpp", "r", stdin);
	int est[100005];
	queue<int> aux;
	
	scanf("%d\n", &T);
	while(T--){
		int Nest, Bt;
		int actH=0;
		
		scanf("%d %d\n", &Nest, &Bt);
		
		for(int i = 0; i< Nest; i++)
			scanf("%d", est + i);
		scanf("\n");
		
		
		//printArr(est, Nest);
		
		int maxE=0, minH=1<<30;
		for(int estV=0 ;estV< Nest; estV++){
			
				aux.push(est[estV]);
				actH+= est[estV];
			
			while(actH > Bt){
				int sacar = aux.front(); aux.pop();
				actH-= sacar;
			}
			//printf("aux.size()=%d || ", aux.size());
			
			
			//ESTUVE UN CO;AZO DE TIEMPO PEGADO ACA PORQUE ESTA COMPARACION ES UNSIGNED NOJODA
			if(maxE < aux.size()){
				maxE = aux.size();
				minH = actH;
			}
			else if(maxE== aux.size()){
				minH= min(minH, actH);
			}
			
			//printQueue(aux);
		}
		
		while(!aux.empty()) aux.pop();
		printf("%d %d\n", minH, maxE);

	}
	
	return 0;
}
