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
    vector<pair<ll, ll>> circs(0);
    ll i = 0;
    ll x = 1;
    ll y = 1;
    while(i < 100){
        x *= 11;
        x %= 1500;
        y += 1;
        y %= 1500;
        bool good = true;
        rep(j, sz(circs)){
            if(pow((x-circs.at(j).first), 2) + pow((y-circs.at(j).second), 2) < pow((i+j+2), 2)){
                good = false;
                break;
            }
            if(x-i-1 < 0 || x+i+1 > 1500){
                good = false;
                break;
            }
            if(y-i-1 < 0 || y+i+1 > 1500){
                good = false;
                break;
            }
        }
        if(good){
            circs.push_back({x, y});
            cout << circs.at(i).first << " " << circs.at(i).second << endl;
            i++;
        }
    }
}