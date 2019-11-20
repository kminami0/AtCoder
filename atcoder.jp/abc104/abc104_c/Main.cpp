#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t D, G;
  cin >> D >> G;
  vector<int64_t> p(D);
  vector<int64_t> c(D);
  rep(i, D){
    cin >> p.at(i) >> c.at(i);
  }
  int64_t cnt = 0;
  int64_t ans = 1001001001;
  int64_t pnt = 0;
  int64_t sav = 0;
  for (int tmp = 0; tmp < (1 << D); tmp++) {
    bitset<10> s(tmp);
    rep(i, D){
      if(s.test(i)){
        cnt += p.at(i);
        pnt += 100*(i+1)*p.at(i)+c.at(i);
      }
    }
    if(pnt >= G){
      chmin(ans, cnt);
      cnt = 0;
      pnt = 0;
    }
    else{
      rep(i, D){
        sav = p.at(D-1-i);
        if(!(s.test(D-1-i))){
          while(p.at(D-1-i) > 1){
            p.at(D-1-i)--;
            cnt++;
            pnt += 100*(D-i);
            if(pnt >= G){
              p.at(D-1-i) = sav;
              chmin(ans, cnt);
              cnt = 0;
              pnt = 0;
              break;
            }
          }
          p.at(D-1-i) = sav;
          if(pnt >=G){
            break;
          }
        }
        if(i == D-1 && pnt < G){
          p.at(0) = sav;
          cnt = 0;
          pnt = 0;
        }
      }
    }
  }
  cout << ans << endl;
}