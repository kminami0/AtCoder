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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H+1, "");
    rep(i, H){
        cin >> S.at(i);
        S.at(i) += "#";
    }
    rep(i, W+1){
        S.at(H) += "#";
    }
    rep(i, H){
        rep(j, W){
            if(S.at(H-i-1).at(W-j-1) == '#'){
                continue;
            }
            if(S.at(H-i).at(W-j) == 'S' || S.at(H-i).at(W-j-1) == 'S' || S.at(H-i-1).at(W-j) == 'S'){
                S.at(H-i-1).at(W-j-1) = 'F';
            }
            else{
                S.at(H-i-1).at(W-j-1) = 'S';
            }
        }
    }
    if(S.at(0).at(0) == 'F'){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
}