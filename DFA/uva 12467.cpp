#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test,k=1;
    cin>>test;
    while(test--)
    {
    int i=1,j=0,l,m,n,mx=0,p;
    //string pat,text;
    char pat[1000005],text[1000005];
    cin>>text;
    p=strlen(text);
    strcpy(pat,text);
    reverse(text,text+p);
    int lps[p];
    lps[0]=0;
    while(i<p)
    {
        if(pat[i]==pat[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }
    }

    j=0,mx=0;
    for(i=0;i<p;)
    {
        if(text[i]==pat[j])
        {
            j++;
            i++;
            if(j>mx)
            {
                mx=j;
            }
        }
        else
        {
            if(j !=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    for(l=mx-1;l>=0;l--)
    {
    {
        printf("%c",pat[l]);
    }


    }
    printf("\n");

}
}
