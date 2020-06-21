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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll Q;
    cin >> Q;
    vector<ll> B(Q), C(Q);
    rep(i, Q) cin >> B.at(i) >> C.at(i);
    map<ll, ll> V;
    ll S = 0;
    rep(i, N){
        V[A.at(i)]++;
        S += A.at(i);
    }
    rep(i, Q){
        if(V.count(B.at(i))){
            S += (C.at(i) - B.at(i)) * V[B.at(i)];
            if(B.at(i) != C.at(i)){
                V[C.at(i)] += V[B.at(i)];
                V.erase(B.at(i));
            }
        }
        cout << S << endl;
    }
}