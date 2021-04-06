#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(M);
    rep(i, M) cin >> A.at(i);
    vector<ll> amida(N);
    rep(i, N){
        amida.at(i) = i;
    }
    rep(i, M){
        swap(amida.at(A.at(i)-1), amida.at(A.at(i)));
    }
    //左からi番目の縦線にたどり着くのは、左からamida.at(i)番目の縦線から出発したとき
    vector<ll> tadoru(N);
    rep(i, N){
        tadoru.at(amida.at(i)) = i;
    }
    vector<vector<ll>> cycle(0);
    vector<bool> used(N, false);
    map<ll, pair<ll, ll>> pos;
    rep(i, N){
        if(used.at(i)){
            continue;
        }
        cycle.push_back({});
        ll p = i;
        ll cnt = 0;
        while(!used.at(p)){
            used.at(p) = true;
            cycle.at(sz(cycle)-1).push_back(p);
            pos[p] = {sz(cycle)-1, cnt};
            cnt++;
            p = tadoru.at(p);
        }
    }
    rep(i, N){
        ll a = pos.at(i).first;
        ll b = pos.at(i).second;
        ll len = sz(cycle.at(a));
        ll r = D % len;
        cout << cycle.at(a).at((b+r) % len)+1 << '\n';
    }
}