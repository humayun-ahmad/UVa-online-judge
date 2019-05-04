// Author: Humayun Ahmad Rajib
// University of Rajshahi


#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int tc,len;
    cin >> tc;
    while(tc--){
        cin >> s;
        len = s.size();
        if(s=="1"){
            cout << "+"<<endl;
        }
        else if(s=="4"){
            cout << "+" <<endl;
        }
        else if(s=="78"){
            cout << "+" <<endl;
        }
        else if(s[0]=='9' && s[len-1]=='4'){
            cout << "*" <<endl;
        }
        else if(s[len-1]=='5' && s[len-2]=='3'){
            cout << "-" <<endl;
        }
        else {
            cout << "?" <<endl;
        }
    }


    return 0;
}
