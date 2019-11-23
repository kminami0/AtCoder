#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<char>> s(H, vector<char>(W));
  rep(i, H){
    rep(j, W){
      cin >> s.at(i).at(j);
    }
  }
  int str = 0;
  bool fst = true;
  bool flg = false;
  rep(i, H){
    rep(j, W){
      if(s.at(i).at(j) == '#'){
        str = i;
        flg = true;
        break;
      }
    }
    if(flg){
      break;
    }
  }
  vector<vector<int>> ans(H, vector<int>(W, 0));
  int cut = 1;
  rep(i, str+1){
    cut = 1;
    rep(j, W){
      if(s.at(str).at(j) == '#'){
        if(!fst){
          cut++;
        }
        else{
          fst = false;
        }
      }
      ans.at(i).at(j) = cut;
    }
    fst = true;
  }
  fst = true;
  bool emp = false;
  rep2(i, str+1, H){
    rep(j, W){
      if(s.at(i).at(j) == '#'){
        break;
      }
      if(j == W-1){
        emp = true;
      }
    }
    if(emp){
      rep(j, W){
        ans.at(i).at(j) = ans.at(i-1).at(j);
      }
      emp = false;
    }
    else{
      cut++;
      rep(j, W){
        ans.at(i).at(j) = cut;
        if(s.at(i).at(j) == '#'){
          if(!fst){
            cut++;
            ans.at(i).at(j) = cut;
          }
          else{
            fst = false;
          }
        }
      }
      fst = true;
    }
  }
  rep(i, H){
    rep(j, W){
      if(j != W-1){
        cout << ans.at(i).at(j) << " ";
      }
      else{
        cout << ans.at(i).at(j) << endl;
      }
    }
  }
}
