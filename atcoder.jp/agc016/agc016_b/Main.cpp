#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    vector<ll> a(N);
    map<ll, ll> cats;
    rep(i, N){
        cin >> a.at(i);
        cats[a.at(i)]++;
    }
    sort(all(a));
    ll m = a.at(0);
    ll M = a.at(N-1);
    if(M - m >= 2){
        cout << "No" << endl;
    }
    else if(M - m == 1){
        ll p = cats.at(m);
        if(N >= p + 2 * (M-p) && M-p >= 1){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    else{
        if(M == N-1 || N >= 2 * M){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}