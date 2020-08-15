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
    ll N;
    cin >> N;
    vector<ll> L(N);
    rep(i, N) cin >> L.at(i);
    ll c = 0;
    rep(i, N){
        rep2(j, i+1, N){
            rep2(k, j+1, N){
                if(L.at(i) == L.at(j) || L.at(j) == L.at(k) || L.at(k) == L.at(i)){
                    continue;
                }
                if(L.at(i)+L.at(j) > L.at(k) && L.at(j)+L.at(k) > L.at(i) && L.at(k)+L.at(i) > L.at(j)){
                    //cout << i << " " << j << " " << k << endl;
                    c++;
                }
            }
        }
    }
    cout << c << endl;
}