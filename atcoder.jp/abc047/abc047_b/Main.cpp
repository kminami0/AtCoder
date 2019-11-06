#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> x(N), y(N), a(N);
  rep(i, N){
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }
  vector<vector<bool>> color(W, vector<bool>(H, true));
  rep(i, N){
    if(a.at(i) == 1){
      rep(j, x.at(i)){
        rep(k, H){
          color.at(j).at(k) = false;
        }
      }
    }
    else if(a.at(i) == 2){
      rep2(j, x.at(i), W){
        rep(k, H){
          color.at(j).at(k) = false;
        }
      }
    }
    else if(a.at(i) == 3){
      rep(j, W){
        rep(k, y.at(i)){
          color.at(j).at(k) = false;
        }
      }
    }
    else{
      rep(j, W){
        rep2(k, y.at(i), H){
          color.at(j).at(k) = false;
        }
      }
    }
  }
  int cnt = 0;
  rep(i, W){
    rep(j, H){
      if(color.at(i).at(j)){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}