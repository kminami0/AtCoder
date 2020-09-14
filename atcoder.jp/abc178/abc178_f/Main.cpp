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
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    reverse(all(B));
    ll cnt = 0;
    vector<ll> freq(N+1, 0);
    rep(i, N){
      freq.at(A.at(i))++;
      freq.at(B.at(i))++;
    }
    rep(i, N+1){
      if(freq.at(i) > N){
        cout << "No" << endl;
        return 0;
      }
    }
    ll p = 0;
    rep(i, N){
      if(A.at(i) == B.at(i)){
        rep2(j, p, N){
          if(A.at(j) != B.at(i) && B.at(j) != B.at(i)){
            swap(B.at(i), B.at(j));
            p = j+1;
            break;
          }
        }
      }
    }
    cout << "Yes" << endl;
    rep(i, N-1){
      cout << B.at(i) << " ";
    }
    cout << B.at(N-1) << endl;
}