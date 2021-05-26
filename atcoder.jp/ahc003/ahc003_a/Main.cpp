#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
#define EPSILON 1e-14
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
    rep(i, 1000){
        ll si, sj, ti, tj;
        cin >> si >> sj >> ti >> tj;
        string path = "";
        if(ti > si){
            rep(j, ti-si){
                path += "D";
            }
        }
        else{
            rep(j, si-ti){
                path += "U";
            }
        }
        if(tj > sj){
            rep(j, tj-sj){
                path += "R";
            }
        }
        else{
            rep(j, sj-tj){
                path += "L";
            }
        }
        cout << path << endl;
        ll time;
        cin >> time;
    }
}