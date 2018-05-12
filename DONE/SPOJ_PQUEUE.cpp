#include <stdio.h>
#include <utility>
#include <queue>
#include <array>
using std::pair;
using std::array;
using std::queue;
using std::priority_queue;

class nodo{
public:
    int data, pri;
    nodo *next;

    nodo(int d){
        this->data=d;
        this->next=NULL;
    }
};

class pqueue{
    nodo *first, *last;
    public:
    array <int, 10> pri;
    void insert(nodo *nuevo){
        if(nuevo != NULL){

            if(first==NULL){
                last= first = nuevo;
            }else{
                last = last->next= nuevo;
            }
            pri[nuevo->data]++;
        }
    }
    bool print(const nodo *elbicho, int &count){
        if(first!=NULL){
            nodo *aux= first;

            bool puedoImprimir= true;
            for(int i =9;puedoImprimir && i>first->data; i--)
                if(pri[i]!=0) puedoImprimir=false;

            if(puedoImprimir) {
                pri[aux->data]--;
                first= first->next; 
                count++;
                bool re= aux==elbicho;
                delete aux;
                return re;
            }
            else{
                first= first->next;
                last= last->next = aux;
                last->next=NULL;
                return false;
            }
        }
    }

    void printValues(){
        nodo *aux= first;
        printf("cola ");
        while(aux!=NULL){
            printf("%d ", aux->data);
            aux=aux->next;
        }
        printf("\n");
    }
    void vaciar(){
        while(first!=NULL){
            nodo *aux =first;
            first=first->next;
            delete aux;
        }
        last= first;
    }
};

int main(){
    freopen("entrada.in", "r", stdin);

    int T;
    pqueue work;
    scanf("%d\n", &T);

    while(T--){
        int n,m, count=0;
        work.pri.fill(0);
        nodo *elbicho;
        scanf("%d %d\n", &n, &m);

        while(n--){
            int aux;
            scanf("%d", &aux);
            nodo *creator = new nodo(aux);
            work.insert(creator);
            if( count== m) {elbicho= creator;}
            count++;
            //work.printValues();
            
        }
        //work.printValues();
        //printf("---\n");
        count=0;
        while(!work.print(elbicho, count));
        printf("%d\n", count);
        work.vaciar();
    }
    return 0;
}