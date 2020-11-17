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
    vector<vector<ll>> dist(N, vector<ll>(N, INF)); //2点間の最短距離
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    vector<tuple<ll, ll, ll>> edge;
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist.at(a).at(b) = c;
        dist.at(b).at(a) = c;
        edge.push_back({a, b, c});
    }
    // ワーシャルフロイド法で2点間の最短距離を求める
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
            }
        }
    }
    ll ans = M;
    rep(i, M){
        rep(j, N){
            // i番目の辺がある最短経路に含まれるなら、あるjに対し「jからa_iまでの最短距離」+「i番目の辺の長さ」=「jからb_iまでの最短距離」が成り立つ
            if(dist.at(j).at(get<0>(edge.at(i))) + get<2>(edge.at(i)) == dist.at(j).at(get<1>(edge.at(i)))){
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
}