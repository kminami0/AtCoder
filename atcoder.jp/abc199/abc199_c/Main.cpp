#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;
    bool flip = false;
    rep(i, Q){
        ll T, A, B;
        cin >> T >> A >> B;
        A--;
        B--;
        if(T == 1){
            if(!flip){
                swap(S.at(A), S.at(B));
            }
            else{
                A += N;
                A %= 2*N;
                B += N;
                B %= 2*N;
                swap(S.at(A), S.at(B));
            }
        }
        else{
            flip = !flip;
        }
    }
    if(flip){
        cout << S.substr(N) << S.substr(0, N) << '\n';
    }
    else{
        cout << S << '\n';
    }
}