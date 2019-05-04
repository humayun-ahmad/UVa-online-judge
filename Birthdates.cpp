#include <bits/stdc++.h>

using namespace std;



struct person{
    int day,month,year;
    char name[30];

}a[156];

int main()
{
    int n,i,j,temp,cnt=0,ara[150],str[150],Max=0,Min,k=1,s1,s2;
    cin >> n;

    for( i=0; i<n; i++){
        cin >>a[i].name>>a[i].day>>a[i].month>>a[i].year;
        ara[i] = a[i].year*360 + a[i].month*30 + a[i].day;
        str[i] = ara[i];

    }

    for( i=0; i<n; i++){
        if(Max<ara[i]){
            Max = ara[i];
            s1=i;
            if(k==1){
                k=0;
                Min = ara[i];
            }
        }
        if(Min>ara[i]){
            Min = ara[i];
            s2=i;
        }

    }

    cout << a[s1].name <<endl;
    cout<< a[s2].name <<endl;





    return 0;
}
