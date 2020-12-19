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
    ll ans = 0;
    rep(i, N){
        bool flag = false;
        string s = to_string(i+1);
        rep(j, sz(s)){
            if(s.at(j) == '7'){
                flag = true;
                break;
            }
        }
        stringstream ss;
        ss << oct << i+1;
        s = ss.str();
        rep(j, sz(s)){
            if(s.at(j) == '7'){
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        ans++;
    }
    cout << ans << endl;
}