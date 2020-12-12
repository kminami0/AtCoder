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
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(k));
    rep(i, n){
        rep(j, k){
            cin >> a.at(i).at(j);
        }
    }
    set<ll> finalist;
    rep(i, n){
        set<ll> tmp;
        ll cnt = 0;
        ll x = k -sz(finalist);
        bool flag = false;
        rep(j, k){
            rep(l, n){
                if(cnt == x){
                    flag = true;
                    break;
                }
                if(l <= i){
                    if(!finalist.count(a.at(l).at(j))){
                        tmp.insert(a.at(l).at(j));
                        finalist.insert(a.at(l).at(j));
                        cnt++;
                    }
                }
                else{
                    cnt++;
                }
            }
            if(flag){
                break;
            }
        }
        for(auto p : tmp){
            cout << p << " ";
        }
        cout << endl;
    }
}