#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
           if(i*i != n){
               ret.push_back(n/i);
           }
       }
   }
   return ret;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    rep(i, N){
        cin >> A.at(i);
        sum += A.at(i);
    }
    vector<ll> v = enum_div(sum);
    sort(rbegin(v), rend(v));
    rep(i, sz(v)){
        vector<ll> B(N);
        rep(j, N){
            B.at(j) = A.at(j) % v.at(i);
        }
        sort(all(B));
        rep2(j, 1, N){
            ll cntm = 0;
            ll cntp = 0;
            rep(k, j){
                cntm += B.at(k);
            }
            rep2(k, j, N){
                cntp += (v.at(i) - B.at(k)) % v.at(i);
            }
            if(max(cntm, cntp) <= K){
                cout << v.at(i) << '\n';
                return 0;
            }
        }
    }
}