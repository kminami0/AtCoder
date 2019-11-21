#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> x(M);
  vector<int> y(M);
  rep(i, M){
    cin >> x.at(i) >> y.at(i);
  }
  int ans = 0;
  vector<int> grp(0);
  bool chk = false;
  for(int tmp = 0; tmp < (1 << N); tmp++){
    bitset<12> s(tmp);
    rep(i, N){
      if(s.test(i)){
        grp.push_back(i);
      }
    }
    chk = false;
    if(grp.size() == 1){
      chk = true;
    }
    rep(i, grp.size()){
      rep2(j, i+1, grp.size()){
        chk = false;
        rep(k, M){
          if(x.at(k)-1 == grp.at(i) && y.at(k)-1 == grp.at(j)){
            chk = true;
            break;
          }
        }
        if(!chk){
          break;
        }
      }
      if(!chk){
        break;
      }
    }
    if(chk){
      int t = grp.size();
      chmax(ans, t);
    }
    grp.clear();
  }
  cout << ans << endl;
}