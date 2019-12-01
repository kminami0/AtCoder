#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'0'] = i;
    }
    return res;
}

int main(){
  int64_t N;
  string S;
  cin >> N >> S;
  vector<vector<int> > next = calcNext(S);
  vector<long long> dp0(sz(S)+1, 0);
  vector<long long> dp1(sz(S)+1, 0);
  vector<long long> dp2(sz(S)+1, 0);
  vector<long long> dp3(sz(S)+1, 0);
  dp0.at(0) = 1;
  dp1.at(0) = 0;
  dp2.at(0) = 0;
  dp3.at(0) = 0;
  rep(i, sz(S)){
    rep(j, 10){
      if (next[i][j] >= sz(S)) continue;
      dp1.at(next.at(i).at(j) + 1) += dp0.at(i);
      dp2.at(next.at(i).at(j) + 1) += dp1.at(i);
      dp3.at(next.at(i).at(j) + 1) += dp2.at(i);
    }
  }
  int64_t ans=0;
  rep(i, sz(S)+1){
    ans += dp3.at(i);
  }
  cout << ans << endl;
}