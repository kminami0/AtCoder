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
    vector<ll> A(4);
    ll sum = 0;
    rep(i, 4){
        cin >> A.at(i);
        sum += A.at(i);
    }
    rep(i, 16){
        bitset<4> s(i);
        ll eat = 0;
        rep(j, 4){
            if(s.test(j)){
                eat += A.at(j);
            }
        }
        if(eat == sum - eat){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}