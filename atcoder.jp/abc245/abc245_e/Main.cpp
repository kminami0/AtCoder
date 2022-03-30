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
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    vector<ll> C(M);
    rep(i, M) cin >> C.at(i);
    vector<ll> D(M);
    rep(i, M) cin >> D.at(i);
    vector<tuple<ll, ll, ll>> P(N+M);
    rep(i, N){
        P.at(i) = {A.at(i), B.at(i), 0};
    }
    rep(i, M){
        P.at(N+i) = {C.at(i), D.at(i), 1};
    }
    sort(all(P));
    reverse(all(P));
    multiset<ll> box;
    rep(i, N+M){
        if(get<2>(P.at(i)) == 0){
            auto it = box.lower_bound(get<1>(P.at(i)));
            if(it == end(box)){
                cout << "No" << '\n';
                return 0;
            }
            box.erase(it);
        }
        else{
            box.insert(get<1>(P.at(i)));
        }
    }
    cout << "Yes" << '\n';
}