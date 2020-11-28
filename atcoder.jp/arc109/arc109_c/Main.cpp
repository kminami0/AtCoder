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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    rep(j, k){
        s = s + s;
        string t = "";
        rep(i, sz(s)/2){
            if(s.at(2*i) == 'R'){
                if(s.at(2*i+1) == 'P'){
                    t += "P";
                }
                else{
                    t += "R";
                }
            }
            if(s.at(2*i) == 'S'){
                if(s.at(2*i+1) == 'R'){
                    t += "R";
                }
                else{
                    t += "S";
                }
            }
            if(s.at(2*i) == 'P'){
                if(s.at(2*i+1) == 'S'){
                    t += "S";
                }
                else{
                    t += "P";
                }
            }
        }
        s = t;
    }
    cout << s.at(0) << endl;
}