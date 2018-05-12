#include <stdio.h>
#include <map>
#include <utility>
#include <string>
#include <cstring>
#include <functional>
#define SIZE 35
#define ARGINVENTO(z) z, z + 2, z + 10, z + 14, z + 18, z + 22
#define FORMATINVENTOIN  "%2s %8s %4s %4s %4s %s\n"
#define FORMATINVENTOOUT "%.2s %.8s %.4s %.4s %.4s %s"
using namespace std;

int main()
{
    //freopen("entrada.in", "r", stdin);
    map<string, int, less<string>> acc;
    char in[SIZE];
    int N, Nacc;
    map<string, int>::iterator it;

    scanf("%d\n", &N);
    while (N--)
    {
        scanf("%d\n", &Nacc);
        while (Nacc--)
        {

            scanf(FORMATINVENTOIN, ARGINVENTO(in));
           // printf(FORMATINVENTOOUT, ARGINVENTO(in));
            //printf("\n");

            it = acc.find(in);
            if (it != acc.end())
            {
                it->second++;
            }
            else
            {
                acc[in] = 1;
            }
        }
        scanf("\n");

        char b[SIZE];
        for (pair<string, int> a : acc)
        {
            memcpy(b, a.first.c_str(), SIZE);
            //cout<<b<<" "<<a.first<<endl;
            printf(FORMATINVENTOOUT, ARGINVENTO(b));
            printf(" %d\n", a.second);
        }
        printf("\n");
        acc.clear();
    }

    return 0;
}