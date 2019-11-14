#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  double A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  double con = 0;
  double sw = 0;
  double sug = 0;
  rep(i, F/(100*A) +1){
    rep(j, F/(100*B) +1){
      rep(k, F/C +1){
        rep(l, F/D +1){
          if(100*A*i + 100*B*j + C*k + D*l <= F){
            if((C*k + D*l)/(100*A*i + 100*B*j + C*k + D*l) >= con &&
              (A*i + B*j)*E >= (C*k + D*l)){
              sw = 100*A*i + 100*B*j + C*k + D*l;
              sug = C*k + D*l;
              con = (C*k + D*l)/(100*A*i + 100*B*j + C*k + D*l);
            }
          }
        }
      }
    }
  }
  cout << sw << " " << sug << endl;
}