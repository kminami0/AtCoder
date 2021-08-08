#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> A(N), B(N);
    vector<ll> tate(N), yoko(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        tate.at(i) = A.at(i);
        yoko.at(i) = B.at(i);
    }
    sort(all(tate));
    sort(all(yoko));
    tate.erase(unique(begin(tate), end(tate)), end(tate));
    yoko.erase(unique(begin(yoko), end(yoko)), end(yoko));
    rep(i, N){
        auto iter = lower_bound(all(tate), A.at(i));
        auto iter2 = lower_bound(all(yoko), B.at(i));
        cout << iter - begin(tate) + 1 << " " << iter2 - begin(yoko) + 1 << endl;
    }
}