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

ll ngcd(vector<ll> a){
    ll res;
    res = a.at(0);
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a.at(i), res);
    }
    return res;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    sort(all(A));
    if(K <= A.at(N-1) && K % ngcd(A) == 0){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}