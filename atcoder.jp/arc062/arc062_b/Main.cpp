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
    string s;
    cin >> s;
    ll ans = 0;
    rep(i, sz(s)){
        if(i % 2 == 0){
            if(s.at(i) == 'p'){
                ans--;
            }
        }
        else{
            if(s.at(i) == 'g'){
                ans++;
            }
        }
    }
    cout << ans << endl;
}