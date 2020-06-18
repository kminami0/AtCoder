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
    string S;
    cin >> S;
    if(S == "{}"){
        cout << "dict" << endl;
        return 0;
    }
    rep(i, sz(S)){
        if(S.at(i) == '{' && i != 0){
            ll c = 1;
            ll k = 0;
            rep2(j, i+1, sz(S)){
                if(S.at(j) == '{'){
                    c++;
                }
                if(S.at(j) == '}'){
                    c--;
                    if(c == 0){
                        k = j;
                        break;
                    }
                }
            }
            i = k;
        }
        if(S.at(i) == ':'){
            cout << "dict" << endl;
            return 0;
        }
    }
    cout << "set" << endl;
}