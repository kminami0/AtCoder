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
    ll N, M;
    cin >> N >> M;
    vector<ll> x(N), y(N), z(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i) >> z.at(i);
    }
    ll ans = 0;
    rep(t, 1 << 3){
        bitset<3> s(t);
        vector<ll> X(N), Y(N), Z(N);
        if(s.test(0)){
            rep(i, N){
                X.at(i) = -1 * x.at(i);
            }
        }
        else{
            rep(i, N){
                X.at(i) = x.at(i);
            }
        }
        if(s.test(1)){
            rep(i, N){
                Y.at(i) = -1 * y.at(i);
            }
        }
        else{
            rep(i, N){
                Y.at(i) = y.at(i);
            }
        }
        if(s.test(2)){
            rep(i, N){
                Z.at(i) = -1 * z.at(i);
            }
        }
        else{
            rep(i, N){
                Z.at(i) = z.at(i);
            }
        }
        vector<vector<tuple<ll, ll, ll>>> cake(N+1, vector<tuple<ll, ll, ll>>(N+1));
        rep(i, N+1){
            cake.at(i).at(0) = make_tuple(0, 0, 0);
        }
        rep(i, N){
            rep(j, i+1){
                if(j == i){
                    cake.at(i+1).at(j+1) = make_tuple(get<0>(cake.at(i).at(j)) + X.at(i), get<1>(cake.at(i).at(j)) + Y.at(i), get<2>(cake.at(i).at(j)) + Z.at(i));
                    continue;
                }
                ll old = get<0>(cake.at(i).at(j+1)) + get<1>(cake.at(i).at(j+1)) + get<2>(cake.at(i).at(j+1));
                ll ate = get<0>(cake.at(i).at(j)) + X.at(i) + get<1>(cake.at(i).at(j)) + Y.at(i) + get<2>(cake.at(i).at(j)) + Z.at(i);
                if(ate > old){
                    cake.at(i+1).at(j+1) = make_tuple(get<0>(cake.at(i).at(j)) + X.at(i), get<1>(cake.at(i).at(j)) + Y.at(i), get<2>(cake.at(i).at(j)) + Z.at(i));
                }
                else{
                    cake.at(i+1).at(j+1) = cake.at(i).at(j+1);
                }
            }
        }
        chmax(ans, get<0>(cake.at(N).at(M))+get<1>(cake.at(N).at(M))+get<2>(cake.at(N).at(M)));
    }
    cout << ans << endl;
}