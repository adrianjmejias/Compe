#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    //freopen("entrada.in", "r", stdin);
    int N;
    scanf("%d\n", &N);
    map<string, int> bet;
    map<string, int> ::iterator it;
    char a[5], b[5];
    int ag, bg;
    while(N--){
        for(int i= 0; i<16 ;i++){
            scanf("%s %s %d %d\n", a, b, &ag, &bg);
            if(ag < bg) strcpy(a,b);
            it= bet.find(a);
            if(it == bet.end())
                bet[a]=1;
            else
                it->second++;
        }
        
        for(it=bet.begin(); it != bet.end(); it++){
            if( it->second==4) break;
        }
        cout<<it->first<<endl;
        bet.clear();
    }
    return 0;
}