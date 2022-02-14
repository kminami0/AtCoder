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
    vector<ll> S(N);
    rep(i, N) cin >> S.at(i);
    // S.at(i) = A.at(i) + A.at(i+1) + A.at(i+2)
    // S.at(i+1) = A.at(i+1) + A.at(i+2) + A.at(i+3)
    // S.at(i+1) - S.at(i) = A.at(i+3) - A.at(i)
    // A.at(i+3) = A.at(i) + S.at(i+1) - S.at(i)
    // A.at(i+6) = A.at(i) + (S.at(i+4) - S.at(i+3)) + (S.at(i+1) - S.at(i))
    vector<ll> v(0), w(0), x(0);
    v.push_back(0);
    w.push_back(0);
    x.push_back(0);
    rep(i, N/3+1){
        if(3*i+1 < N){
            ll n = v.back();
            v.push_back(n + S.at(3*i) - S.at(3*i+1));
        }
        if(3*i+2 < N){
            ll n = w.back();
            w.push_back(n + S.at(3*i+1) - S.at(3*i+2));
        }
        if(3*i+3 < N){
            ll n = x.back();
            x.push_back(n + S.at(3*i+2) - S.at(3*i+3));
        }
    }
    sort(all(v));
    sort(all(w));
    sort(all(x));
    ll a0 = v.back();
    ll a1 = w.back();
    ll a2 = x.back();
    if(a0 + a1 + a2 > S.at(0)){
        cout << "No" << '\n';
        return 0;
    }
    vector<ll> A(N+2);
    A.at(0) = a0;
    A.at(1) = a1;
    A.at(2) = a2;
    A.at(0) += S.at(0) - (a0 + a1 + a2);
    rep2(i, 3, N+2){
        A.at(i) = S.at(i-2) - A.at(i-1) - A.at(i-2);
    }
    cout << "Yes" << '\n';
    rep(i, N+1){
        cout << A.at(i) << " ";
    }
    cout << A.at(N+1) << '\n';
}