#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int main(){

    //freopen("entrada.in", "r", stdin);
    int N,P,L;
    string adn;
    unordered_map <string , int> data;
    unordered_map<string, int> ::iterator it;
do{
    scanf("%d", &P);
    scanf("%d\n", &L);
    //getchar();
    //printf("%d %d \n",P,L);
    if(!P && !L) break;
    int *re = (int*) malloc( (P+5) * sizeof(int));
    int P_copy=P;
    fill(re, re + P, 0);

    while(P--){
        getline(cin,adn);
        it = data.find(adn);
        //cout<<adn<<endl;
        if(it != data.end()){
            it->second++;
        }else{
            data[adn]=1;
        }
    }

    for(it= data.begin(); it!= data.end(); it++){
        re[it->second]++;
    }
    for(int i=1; i<= P_copy; i++){
        printf("%d\n", re[i]);
    }
    data.clear();
    free(re);
}while(1);
    return 0;
}