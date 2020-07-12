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

ll f(ll z1, ll z2, ll w1, ll w2, ll x, ll y){
    return (z2-z1)*(y-w1) - (w2-w1)*(x-z1);
}

int main()
{
    ll Ax, Ay, Bx, By, N;
    cin >> Ax >> Ay >> Bx >> By >> N;
    vector<ll> X(N+1), Y(N+1);
    rep(i, N){
        cin >> X.at(i) >> Y.at(i);
    }
    X.at(N) = X.at(0);
    Y.at(N) = Y.at(0);
    ll cross = 0;
    rep(i, N){
        if(f(Ax, Bx, Ay, By, X.at(i), Y.at(i)) * f(Ax, Bx, Ay, By, X.at(i+1), Y.at(i+1)) < 0 && f(X.at(i), X.at(i+1), Y.at(i), Y.at(i+1), Ax, Ay) * f(X.at(i), X.at(i+1), Y.at(i), Y.at(i+1), Bx, By) < 0){
            cross++;
        }
    }
    cout << cross/2 + 1 << endl;
}