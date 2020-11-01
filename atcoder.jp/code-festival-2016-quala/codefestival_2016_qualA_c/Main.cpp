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
    ll K;
    cin >> s >> K;
    rep(i, sz(s)){
        if(i == sz(s)-1){
            rep(j, K % 26){
                if(s.at(i) == 'z'){
                    s.at(i) = 'a';
                }
                else{
                    s.at(i)++;
                }
            }
        }
        else if(s.at(i) == 'a'){
            continue;
        }
        else if(K >= 'z' - s.at(i) + 1){
            K -= 'z' - s.at(i) + 1;
            s.at(i) = 'a';
        }
    }
    cout << s << endl;
}