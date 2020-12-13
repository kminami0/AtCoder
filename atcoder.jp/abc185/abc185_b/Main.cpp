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
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll> A(M), B(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i);
    }
    ll bat = N;
    rep(i, M+1){
        if(i == 0){
            bat -= A.at(i);
        }
        else if(i == M){
            bat -= T - B.at(M-1);
        }
        else{
            bat -= A.at(i) - B.at(i-1);
        }
        if(bat <= 0){
            cout << "No" << endl;
            return 0;
        }
        if(i < M){
            bat += B.at(i) - A.at(i);
        }
        if(bat > N){
            bat = N;
        }
    }
    cout << "Yes" << endl;
}