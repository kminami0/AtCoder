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
    ll A, B;
    cin >> A >> B;
    vector<string> s(100, "");
    rep(i, 100){
      if(i % 2 == 0){
        rep(j, 99){
          s.at(i) += ".";
        }
        s.at(i) += "#";
      }
      else{
        s.at(i) += ".";
        rep(j, 99){
          s.at(i) += "#";
        }
      }
    }
    ll c = 0;
    bool comp = false;
    if(A != 1){
      rep(i, 50){
        rep(j, 49){
          s.at(2*i).at(2*j+1) = '#';
          c++;
          if(c == A-1){
            comp = true;
            break;
          }
        }
        if(comp){
          break;
        }
      }
    }
    c = 0;
    comp = false;
    if(B != 1){
      rep(i, 50){
        rep(j, 49){
          s.at(99-2*i).at(2*j+2) = '.';
          c++;
          if(c == B-1){
            comp = true;
            break;
          }
        }
        if(comp){
          break;
        }
      }
    }
    cout << 100 << " " << 100 << endl;
    rep(i, 100){
      cout << s.at(i) << endl;
    }
}