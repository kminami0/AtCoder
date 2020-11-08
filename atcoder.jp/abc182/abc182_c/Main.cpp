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
    ll sum = 0;
    map<ll, ll> rem;
    ll digit = 0;
    while(N > 0){
        sum += N % 10;
        rem[(N%10) % 3]++;
        N /= 10;
        digit++;
    }
    if(sum % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    if(sum % 3 == 1){
        if(rem[1] >= 1 && digit > 1){
            cout << 1 << endl;
            return 0;
        }
        if(rem[2] >= 2 && digit > 2){
            cout << 2 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    if(rem[2] >= 1 && digit > 1){
        cout << 1 << endl;
        return 0;
    }
    if(rem[1] >= 2 && digit > 2){
        cout << 2 << endl;
        return 0;
    }
    cout << -1 << endl;
}