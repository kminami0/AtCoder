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
    ll N, Q;
    cin >> N >> Q;
    vector<long double> X(N), R(N), H(N);
    rep(i, N){
        cin >> X.at(i) >> R.at(i) >> H.at(i);
    }
    vector<long double> V(20005, 0);
    vector<long double> C(20005, 0);
    rep(i, N){
        long double a = R.at(i) * R.at(i) * M_PI * H.at(i) / 3;
        long double b = a;
        rep(j, H.at(i)){
            long double c = a * pow((H.at(i)-j-1)/H.at(i), 3);
            C.at(X.at(i)+j) += b - c;
            b = c;
        }
    }
    rep(i, 20000){
        V.at(i+1) = V.at(i) + C.at(i);
    }
    rep(i, Q){
        ll A, B;
        cin >> A >> B;
        cout << fixed << setprecision(6);
        cout << V.at(B) - V.at(A) << endl;
    }
}