#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N, L;
    cin >> N >> L;
    set<string> S;
    vector<vector<ll>> cnt(L, vector<ll>(3, 0));
    rep(i, N){
        string s = "";
        ll n = i;
        rep(j, L-1){
            s += '0' + (n % 3);
            n /= 3;
        }
        reverse(all(s));
        string t = '2' + s;
        S.insert(t);
        rep(j, L){
            cnt.at(j).at(t.at(j)-'0')++;
        }
    }
    set<string> T;
    for(string s : S){
        string t = "";
        string u = "";
        rep(i, L){
            if(s.at(i) == '0'){
                t += '1';
                u += '2';
            }
            else if(s.at(i) == '1'){
                t += '2';
                u += '0';
            }
            else{
                t += '0';
                u += '1';
            }
        }
        T.insert(t);
        T.insert(u);
    }
    for(string t : T){
        cout << t << '\n';
    }
    for(string s : S){
        cout << s << '\n';
    }
}