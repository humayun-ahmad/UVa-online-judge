#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);

    char ch[300];

    while(scanf("%s",ch)!=EOF){

        printf("The string '%s' contains %d palindromes.\n",ch,strlen(ch));
    }

    return 0;
}
