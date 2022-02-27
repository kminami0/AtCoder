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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    vector<ll> C(N), D(N);
    rep(i, N){
        C.at(i) = A.at(i);
        D.at(i) = B.at(i);
    }
    sort(all(C));
    sort(all(D));
    if(C != D){
        cout << "No" << '\n';
        return 0;
    }
    ll cnt = 0;
    rep(i, N){
        if(A.at(i) == B.at(i)){
            continue;
        }
        rep2(j, i+1, N){
            if(B.at(i) == A.at(j)){
                swap(A.at(i), A.at(j));
                cnt++;
                break;
            }
        }
    }
    if(cnt % 2 == 0){
        cout << "Yes" << '\n';
        return 0;
    }
    set<ll> S;
    rep(i, N){
        S.insert(A.at(i));
    }
    if(sz(S) == N){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
    }
}