#include <stdio.h>
#include <vector>
#include <utility>
#include <cmath>
#define as "entrada.in"
#define MEMOSIZE 1000000000
#ifdef as
   #define b freopen(as, "r", stdin)
#endif
using namespace std;

/*Solución de python de alvie
import math

i = 5
x = 11000000000
sum = 0

while x >= i:
  sum += math.floor(x / i)
  i *= 5
	
	
print(int(sum))
*/

int main(){

    /*
    no es necesario scar memo[2] porque la cantidad de trailing zeros siempre 
    va a ser el minimo, y el minimo siempre será memo[5]
    */
    
    long long N;
    long long  re;
    long long num;
    scanf("%lld", &N);


while(N--){
        scanf("%lld", &num);
        int i=5; long long sum=0;

        while(num >= i){
            sum+=floor(num/i);
            i*=5;
        }

        printf("%lld\n",sum);
    }
}