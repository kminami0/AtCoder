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
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> pawn(M);
    rep(i, M){
        cin >> pawn.at(i).first >> pawn.at(i).second;
    }
    sort(all(pawn));
    set<ll> movable;
    movable.insert(N);
    ll row = 0;
    rep(i, M){
        set<ll> A, B;
        row = pawn.at(i).first;
        while(i < M && row == pawn.at(i).first){
            if(movable.count(pawn.at(i).second-1) || movable.count(pawn.at(i).second+1)){
                A.insert(pawn.at(i).second);
            }
            if(movable.count(pawn.at(i).second)){
                B.insert(pawn.at(i).second);
            }
            i++;
        }
        i--;
        for(ll x : B){
            movable.erase(x);
        }
        for(ll x : A){
            movable.insert(x);
        }
    }
    cout << sz(movable) << '\n';
}