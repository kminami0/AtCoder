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
//h.at(i)が極小値となるiを列挙し、最大の隣り合うiの差+1が答え
int main()
{
    ll N;
    cin >> N;
    vector<ll> h(N);
    rep(i, N){
        cin >> h.at(i);
    }
    bool up = true;
    vector<ll> ext(0);
    ext.push_back(0);
    rep(i, N-1){
        if(up){
            if(h.at(i) > h.at(i+1)){
                up = false;
                ext.push_back(i);
            }
        }
        else{
            if(h.at(i) < h.at(i+1)){
                up = true;
                ext.push_back(i);
            }
        }
    }
    ext.push_back(N-1);
    if(up){
        ext.push_back(N-1);
    }
    ll i = 0;
    ll ans = 0;
    while(i+2 < sz(ext)){
        chmax(ans, ext.at(i+2) - ext.at(i) + 1);
        i += 2;
    }
    cout << ans << endl;
}