#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

ll wp(ll d){
  if(100*d < 25*60){
    return 0;
  }
  if(100*d  < 155*60){
    return 1;
  }
  if(100*d  < 335*60){
    return 2;
  }
  if(100*d  < 545*60){
    return 3;
  }
  if(100*d  < 795*60){
    return 4;
  }
  if(100*d  < 1075*60){
    return 5;
  }
  if(100*d  < 1385*60){
    return 6;
  }
  if(100*d  < 1715*60){
    return 7;
  }
  if(100*d  < 2075*60){
    return 8;
  }
  if(100*d  < 2445*60){
    return 9;
  }
  if(100*d < 2845*60){
    return 10;
  }
  if(100*d < 3265*60){
    return 11;
  }
  return 12;
}

string wd(ll d){
  ll x = (10*d + 1125) / 2250;
  if(x == 1){
    return "NNE";
  }
  if(x == 2){
    return "NE";
  }
  if(x == 3){
    return "ENE";
  }
  if(x == 4){
    return "E";
  }
  if(x == 5){
    return "ESE";
  }
  if(x == 6){
    return "SE";
  }
  if(x == 7){
    return "SSE";
  }
  if(x == 8){
    return "S";
  }
  if(x == 9){
    return "SSW";
  }
  if(x == 10){
    return "SW";
  }
  if(x == 11){
    return "WSW";
  }
  if(x == 12){
    return "W";
  }
  if(x == 13){
    return "WNW";
  }
  if(x == 14){
    return "NW";
  }
  if(x == 15){
    return "NNW";
  }
  return "N";
}

int main(){
  ll Deg;
  ll Dis;
  cin >> Deg >> Dis;
  if(wp(Dis) == 0){
    cout << "C" << " " << 0 << endl;
  }
  else{
    cout << wd(Deg) << " " << wp(Dis) << endl;
  }
}