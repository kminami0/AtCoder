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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll nlcm(vector<ll> numbers) {
    ll res;
    res = numbers.at(0);
    rep2(i, 1, sz(numbers)){
        res = lcm(res, numbers.at(i));
    }
    return res;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> T(N);
    rep(i, N) cin >> T.at(i);
    cout << nlcm(T) << endl;
}