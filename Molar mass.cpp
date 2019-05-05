#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int tc;
    cin >> tc;
    while(tc--){
        cin >> s;
        int result = 0,j=0;
        double sum = 0;
        for(int i=s.size()-1; i>=0;i--){
            if(s[i] == 'C'){
                    if(result == 0){
                        sum += 12.01;
                    }
                sum += 12.01 * result;
                result = 0;
                j = 0;
            }
            else if(s[i] == 'H'){
                    if(result == 0){
                        sum += 1.008;
                    }
                sum += 1.008 * result;
                result = 0;
                j = 0;
            }
            else if(s[i] == 'N'){
                    if(result == 0){
                        sum += 14.01;
                    }
                sum += 14.01 * result;
                result = 0;
                j = 0;
            }
            else if(s[i] == 'O'){
                    if(result == 0){
                        sum += 16.00;
                    }
                sum += 16.00 * result;
                result = 0;
                j = 0;
            }
            else{
                int x = s[i] - '0';
                result = result + x*pow(10,j);
                j++;
            }
        }

        printf("%.3lf\n", sum);
    }

    return 0;
}