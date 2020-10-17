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
    vector<ll> x(N);
    rep(i, N) cin >> x.at(i);
    ll man = 0;
    rep(i, N){
        man += abs(x.at(i));
    }
    cout << man << endl;
    long double euq = 0;
    rep(i, N){
        euq += abs(x.at(i)) * abs(x.at(i));
    }
    euq = pow(euq, 0.5);
    cout << fixed << setprecision(15);
    cout << euq << endl;
    ll che = 0;
    rep(i, N){
        chmax(che, abs(x.at(i)));
    }
    cout << che << endl;
}