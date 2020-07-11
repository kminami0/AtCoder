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
    vector<ll> f(N, 0);
    rep2(i, 1, N+1){
        rep2(j, 1, min(100, (int)(sqrt(i)+1))){
            rep2(k, j, min(100, (int)(sqrt(i)+1))){
                rep2(l, k, min(100, (int)(sqrt(i)+1))){
                    if(j*j + k*k + l*l + j*k + k*l + l*j == i){
                        if(j == k && k == l){
                            f.at(i-1)++;
                        }
                        else if(j == k && k < l){
                            f.at(i-1) += 3;
                        }
                        else if(j < k && k == l){
                            f.at(i-1) += 3;
                        }
                        else{
                            f.at(i-1) += 6;
                        }
                    }
                }
            }
        }
    }
    rep(i, N){
        cout << f.at(i) << endl;
    }
}