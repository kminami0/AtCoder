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
    ll x, y;
    cin >> s >> x >> y;
    set<ll> xpos; //到達可能なx座標
    set<ll> ypos; //到達可能なy座標
    xpos.insert(0);
    ypos.insert(0);
    bool x_axis = true; //今x軸方向を向いているか
    ll cnt = 0; //Fが何個連続して現れたか
    bool start = true; //最初のFの列か
    rep(i, sz(s)){
      if(s.at(i) == 'T'){
        if(x_axis){
          set<ll> tmp;
          for(auto p : xpos){
            tmp.insert(p+cnt);
            if(!start){
              tmp.insert(p-cnt);
            }
          }
          cnt = 0;
          start = false;
          //到達可能なx座標の集合を更新する
          xpos.clear();
          for(auto p : tmp){
            xpos.insert(p);
          }
        }
        else{
          set<ll> tmp;
          for(auto p : ypos){
            tmp.insert(p+cnt);
            tmp.insert(p-cnt);
          }
          cnt = 0;
          //到達可能なy座標の集合を更新する
          ypos.clear();
          for(auto p : tmp){
            ypos.insert(p);
          }
        }
        x_axis = !x_axis; //Tが現れたので向きが90度変わる
      }
      else{
        cnt++;
      }
    }
    //最後のFの列に対しても同様の処理を行う
    if(x_axis){
      set<ll> tmp;
      for(auto p : xpos){
        tmp.insert(p+cnt);
        if(!start){
          tmp.insert(p-cnt);
        }
      }
      xpos.clear();
      for(auto p : tmp){
        xpos.insert(p);
      }
    }
    else{
      set<ll> tmp;
      for(auto p : ypos){
        tmp.insert(p+cnt);
        tmp.insert(p-cnt);
      }
      ypos.clear();
      for(auto p : tmp){
        ypos.insert(p);
      }
    }
    if(xpos.count(x) && ypos.count(y)){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
}