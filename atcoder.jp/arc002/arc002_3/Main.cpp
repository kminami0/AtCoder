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
    string c;
    cin >> N >> c;
    string buttons = "ABXY";
    ll ad = 0;
    rep(i, 4){
        rep(j, 4){
            rep(k, 4){
                rep(l, 4){
                    string L = "";
                    string R = "";
                    L.push_back(buttons.at(i));
                    L.push_back(buttons.at(j));
                    R.push_back(buttons.at(k));
                    R.push_back(buttons.at(l));
                    ll sh = 0;
                    rep(m, sz(c)-1){
                        if(c.substr(m, 2) == L || c.substr(m, 2) == R){
                            sh++;
                            m++;
                        }
                    }
                    chmax(ad, sh);
                }
            }
        }
    }
    cout << sz(c)-ad << endl;
}