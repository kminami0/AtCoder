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
  vector<string> S(N);
  rep(i, N){
    cin >> S.at(i);
  }
  ll a = 0;
  ll w = 0;
  ll t = 0;
  ll r = 0;
  rep(i, N){
    if(S.at(i) == "AC"){
      a++;
    }
    if(S.at(i) == "WA"){
      w++;
    }
    if(S.at(i) == "TLE"){
      t++;
    }
    if(S.at(i) == "RE"){
      r++;
    }
  }
  cout << "AC x " << a << endl;
  cout << "WA x " << w << endl;
  cout << "TLE x " << t << endl;
  cout << "RE x " << r << endl;
}