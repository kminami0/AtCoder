#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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
    vector<tuple<ll, ll, ll>> seg(N);
    rep(i, N){
        cin >> get<2>(seg.at(i)) >> get<0>(seg.at(i)) >> get<1>(seg.at(i));
    }
    ll ans = 0;
    rep(i, N){
        rep2(j, i+1, N){
            if(get<0>(seg.at(i)) <= get<1>(seg.at(j)) && get<0>(seg.at(j)) <= get<1>(seg.at(i))){
                if(get<0>(seg.at(i)) == get<1>(seg.at(j))){
                    if(get<2>(seg.at(i)) == 3 || get<2>(seg.at(i)) == 4){
                        continue;
                    }
                    if(get<2>(seg.at(j)) == 2 || get<2>(seg.at(j)) == 4){
                        continue;
                    }
                    ans++;
                }
                else if(get<0>(seg.at(j)) == get<1>(seg.at(i))){
                    if(get<2>(seg.at(j)) == 3 || get<2>(seg.at(j)) == 4){
                        continue;
                    }
                    if(get<2>(seg.at(i)) == 2 || get<2>(seg.at(i)) == 4){
                        continue;
                    }
                    ans++;
                }
                else{
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}