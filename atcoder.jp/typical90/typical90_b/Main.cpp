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

vector<string> par(ll N){
    if(N == 0 || N % 2 == 1){
        return {};
    }
    if(N == 2){
        return {"()"};
    }
    vector<string> S = par(N-2);
    vector<string> v(0);
    for(string p : S){
        v.push_back("(" + p + ")");
    }
    rep2(i, 1, N){
        vector<string> T = par(i);
        vector<string> U = par(N-i);
        for(string p : T){
            for(string q : U){
                v.push_back(p+q);
            }
        }
    }
    return v;
}

int main()
{
    ll N;
    cin >> N;
    vector<string> ans = par(N);
    sort(all(ans));
    ans.erase(unique(all(ans)), end(ans));
    for(string p : ans){
        cout << p << '\n';
    }
}