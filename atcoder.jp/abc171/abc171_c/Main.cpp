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
    ll a = 1;
    ll n = 0;
    while(true){
        if((a-1)/25 <= N && N < (a*26-1)/25){
            break;
        }
        n++;
        a *= 26;
    }
    ll b = N - (a-1)/25;
    string s = "";
    rep(i, n){
        ll c = b % 26;
        s += 'a' + c;
        b /= 26;
    }
    reverse(all(s));
    cout << s << endl;
}