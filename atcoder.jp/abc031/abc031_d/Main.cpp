#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll K, N;
    cin >> K >> N;
    vector<string> v(N);
    vector<string> w(N);
    rep(i, N){
        cin >> v.at(i) >> w.at(i);
    }
    rep(i, pow(3, K)){
        ll p = i;
        vector<ll> l(K);
        map<char, string> s;
        rep(j, K){
            l.at(j) = p % 3 + 1;
            p /= 3;
        }
        rep(j, N){
            ll q = 0;
            bool flag = false;
            rep(k, sz(v.at(j))){
                if(q >= sz(w.at(j))){
                    flag = true;
                    break;
                }
                if(!s.count(v.at(j).at(k))){
                    s[v.at(j).at(k)] = w.at(j).substr(q, l.at(v.at(j).at(k) - '0' - 1));
                }
                else if(s.at(v.at(j).at(k)) != w.at(j).substr(q, l.at(v.at(j).at(k) - '0' - 1))){
                    flag = true;
                    break;
                }
                q += l.at(v.at(j).at(k) - '0' - 1);
            }
            if(flag){
                break;
            }
            if(q != sz(w.at(j))){
                break;
            }
            if(j == N-1){
                rep(k, K){
                    cout << s.at(k+'1') << '\n';
                }
                return 0;
            }
        }
    }
}