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
    vector<tuple<ll, ll, ll>> data(N);
    rep(i, N){
        cin >> get<1>(data.at(i)) >> get<2>(data.at(i)) >> get<0>(data.at(i));
    }
    sort(all(data));
    reverse(all(data));
    rep(CX, 101){
        rep(CY, 101){
            ll H = get<0>(data.at(0)) + abs(get<1>(data.at(0))-CX) + abs(get<2>(data.at(0))-CY);
            bool ok = true;
            for(auto d : data){
                if(get<0>(d) == 0){
                    if(H-abs(get<1>(d)-CX)-abs(get<2>(d)-CY) > 0){
                        ok = false;
                        break;
                    }
                }
                else{
                    if(H-abs(get<1>(d)-CX)-abs(get<2>(d)-CY) != get<0>(d)){
                        ok =false;
                        break;
                    }
                }
            }
            if(ok){
                cout << CX << " " << CY << " " << H << '\n';
                return 0;
            }
        }
    }
}