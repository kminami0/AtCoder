#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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

struct edge {
  ll to;
  ll cost;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    vector<ll> A(M), B(M), C(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i) >> C.at(i);
        A.at(i)--;
        B.at(i)--;
        graph.at(A.at(i)).push_back({B.at(i), C.at(i)});
        graph.at(B.at(i)).push_back({A.at(i), C.at(i)});
        dist.at(A.at(i)).at(B.at(i)) = C.at(i);
        dist.at(B.at(i)).at(A.at(i)) = C.at(i);
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
            }
        }
    }
    ll ans = 0;
    rep(i, M){
        rep(j, N){
            if(j == A.at(i) || j == B.at(i)){
                continue;
            }
            if(dist.at(A.at(i)).at(j)+dist.at(j).at(B.at(i)) <= C.at(i)){
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}