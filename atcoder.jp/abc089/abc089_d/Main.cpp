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
    ll H, W, D;
    cin >> H >> W >> D;
    vector<vector<ll>> A(H, vector<ll>(W, 0));
    map<ll, pair<ll, ll>> P;
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
            A.at(i).at(j)--;
            P[A.at(i).at(j)] = make_pair(i, j);
        }
    }
    vector<vector<ll>> S(D, vector<ll>(H*W/D +3, 0));
    rep(i, D){
        ll j = 0;
        while(D*(j+1) + i < H*W){
            ll x = P.at(D*j+i).first;
            ll y = P.at(D*j+i).second;
            ll nx = P.at(D*(j+1)+i).first;
            ll ny = P.at(D*(j+1)+i).second;
            S.at(i).at(j+1) = S.at(i).at(j) + abs(nx-x) + abs(ny-y);
            j++;
        }
    }
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll L, R;
        cin >> L >> R;
        L--;
        R--;
        ll k = L % D;
        ll j1 = L / D;
        ll j2 = R / D;
        cout << S.at(k).at(j2) - S.at(k).at(j1) << endl;
    }
}