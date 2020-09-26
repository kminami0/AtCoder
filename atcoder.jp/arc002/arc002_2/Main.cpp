#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main()
{
    string s;
    cin >> s;
    ll Y = stoll(s.substr(0,4));
    ll M = stoll(s.substr(5,2));
    ll D = stoll(s.substr(8,2));
    while(true){
        if(Y % (M * D) == 0){
            break;
        }
        if(M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12){
            if(D != 31){
                D++;
            }
            else{
                if(M != 12){
                    M++;
                    D = 1;
                }
                else{
                    Y++;
                    M = 1;
                    D = 1;
                }
            }
        }
        else if(M != 2){
            if(D != 30){
                D++;
            }
            else{
                M++;
                D = 1;
            }
        }
        else{
            if(Y % 4 != 0){
                if(D != 28){
                    D++;
                }
                else{
                    M++;
                    D = 1;
                }
            }
            else if(Y % 100 != 0){
                if(D != 29){
                    D++;
                }
                else{
                    M++;
                    D = 1;
                }
            }
            else if(Y % 400 != 0){
                if(D != 28){
                    D++;
                }
                else{
                    M++;
                    D = 1;
                }
            }
            else{
                if(D != 29){
                    D++;
                }
                else{
                    M++;
                    D = 1;
                }
            }
        }
    }
    string ans = to_string(Y);
    ans += "/";
    if(M < 10){
        ans += "0" + to_string(M);
    }
    else{
        ans += to_string(M);
    }
    ans += "/";
    if(D < 10){
        ans += "0" + to_string(D);
    }
    else{
        ans += to_string(D);
    }
    cout << ans << endl;
}