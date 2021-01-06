#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll N;
    cin >> N;
    set<string> kaikin;
    rep(i, N){
        if(i == 0){
            ll k;
            cin >> k;
            rep(j, k){
                string mem;
                cin >> mem;
                kaikin.insert(mem);
            }
            continue;
        }
        ll k;
        cin >> k;
        set<string> S;
        rep(j, k){
            string mem;
            cin >> mem;
            S.insert(mem);
        }
        set<string> kesseki;
        for(auto p : kaikin){
            if(!S.count(p)){
                kesseki.insert(p);
            }
        }
        for(auto p : kesseki){
            if(kaikin.count(p)){
                kaikin.erase(p);
            }
        }
    }
    cout << sz(kaikin) << endl;
}