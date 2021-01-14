#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000000000000LL //10^18
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
  ll dist;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    vector<vector<ll>> cost(N, vector<ll>(N, INF));
    rep(i, M){
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        graph.at(A).push_back({B, C});
        graph.at(B).push_back({A, C});
        cost.at(A).at(B) = C;
        cost.at(B).at(A) = C;
    }
    rep(i, N){
        cost.at(i).at(i) = 0;
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(cost.at(i).at(j), cost.at(i).at(k)+cost.at(k).at(j));
            }
        }
    }
    ll K;
    cin >> K;
    rep(i, K){
        ll X, Y, Z;
        cin >> X >> Y >> Z;
        X--;
        Y--;
        rep(j, N){
            rep(k, N){
                chmin(cost.at(j).at(k), cost.at(j).at(X)+Z+cost.at(Y).at(k));
                chmin(cost.at(j).at(k), cost.at(j).at(Y)+Z+cost.at(X).at(k));
            }
        }
        ll S = 0;
        rep(j, N){
            rep2(k, j+1, N){
                S += cost.at(j).at(k);
            }
        }
        cout << S << endl;
    }
}