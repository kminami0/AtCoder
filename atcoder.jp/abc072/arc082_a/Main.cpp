#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N;
  cin >> N;
  int btm = 100000;
  int top = -1;
  vector<int> a(N);
  rep(i, N){
    cin >> a.at(i);
    chmin(btm, a.at(i));
    chmax(top, a.at(i));
  }
  sort(all(a));
  int cnt = 0;
  int ans = 0;
  int p = 0;
  int q = 0;
  rep2(i, btm, top+1){
    p = q;
    rep2(j, p, N){
      if(a.at(j) < i-1){
        q++;
      }
      if(i-1 <= a.at(j) && a.at(j) <= i+1){
        cnt++;
      }
      if(a.at(j) > i+1){
        break;
      }
    }
    chmax(ans, cnt);
    cnt = 0;
  }
  cout << ans << endl;
}