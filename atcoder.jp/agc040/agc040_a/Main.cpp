#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  string S;
  cin >> S;
  if(S.at(0) == '>'){
    reverse(all(S));
    S += "<";
    reverse(all(S));
  }
  if(S.at(S.size()-1) == '<'){
    S += ">";
  }
  vector<int64_t> ans(0);
  int cnt = 1;
  rep(i, S.size()-1){
    if(S.at(i) == S.at(i+1)){
      cnt++;
    }
    else{
      ans.push_back(cnt);
      cnt = 1;
    }
  }
  ans.push_back(cnt);
  int64_t answer = 0;
  rep(i, ans.size() / 2){
    if(ans.at(2*i) >= ans.at(2*i+1)){
      answer += ans.at(2*i) * (ans.at(2*i)+1) / 2;
      answer += (ans.at(2*i+1)-1) * ans.at(2*i+1) / 2;
    }
    else{
      answer += ans.at(2*i+1) * (ans.at(2*i+1)+1) / 2;
      answer += (ans.at(2*i)-1) * ans.at(2*i) / 2;
    }
  }
  cout << answer << endl;
}