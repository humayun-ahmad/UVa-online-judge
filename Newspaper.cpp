#include <bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll tc,initn,initstr;

    scanf("%lld", &tc);

    while(tc--){
        map<char,ll>mp;
        cin >> initn;
        while(initn--){
             char c;
            ll val;
            cin >> c >> val;
            mp[c] = val;
        }

        cin >> initstr;
        getchar();
        string st;
        ll sum =0;
        while(initstr--){
            //cin >> st;
            //ll length = st.size(st);
            getline(cin,st);

            for(int i=0; i<st.size(); i++){
                if(mp[st[i]]) sum += mp[st[i]];
            }
        }

        //cout << sum(double)/100.0 <<"$"<<endl;
		printf("%.2lf$\n",(double)sum/100.0);
    }


    return 0;
}
