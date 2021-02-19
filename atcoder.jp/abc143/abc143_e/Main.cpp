#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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
    ll N, M, L;
    cin >> N >> M >> L;
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    rep(i, M){
        ll A, B, C;
        cin >> A >> B >> C;
        if(C > L){
            continue;
        }
        A--;
        B--;
        dist.at(A).at(B) = C;
        dist.at(B).at(A) = C;
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
            }
        }
    }
    vector<vector<ll>> cost(N, vector<ll>(N, INF));
    rep(i, N){
        cost.at(i).at(i) = 0;
    }
    rep(i, N){
        rep(j, N){
            if(i == j){
                continue;
            }
            if(dist.at(i).at(j) <= L){
                cost.at(i).at(j) = 1;
            }
        }
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(cost.at(i).at(j), cost.at(i).at(k) + cost.at(k).at(j));
            }
        }
    }
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        if(cost.at(s).at(t) == INF){
            cout << -1 << '\n';
        }
        else{
            cout << cost.at(s).at(t)-1 << '\n';
        }
    }
}