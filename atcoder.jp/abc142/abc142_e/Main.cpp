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

vector<vector<ll>> dp(4096, vector<ll>(1001, INF));

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<vector<ll>> c(M, vector<ll>(0));
    rep(i, M){
        cin >> a.at(i) >> b.at(i);
        rep(j, b.at(i)){
            ll x;
            cin >> x;
            x--;
            c.at(i).push_back(x);
        }
    }
    rep(i, M){
        dp.at(0).at(i) = 0;
    }
    rep2(i, 1, 1<<N){
        bitset<12> s(i);
        rep(j, M){
            bitset<12> t = s;
            rep(k, b.at(j)){
                t.set(c.at(j).at(k), 0);
            }
            ll x = 0;
            rep(k, 12){
                if(t.test(k)){
                    x += pow(2, k);
                }
            }
            dp.at(i).at(j+1) = min(dp.at(x).at(j)+a.at(j), dp.at(i).at(j));
        }
    }
    if(dp.at(pow(2, N)-1).at(M) >= 100000*1000+1){
        cout << -1 << endl;
    }
    else{
        cout << dp.at(pow(2, N)-1).at(M) << endl;   
    }
}