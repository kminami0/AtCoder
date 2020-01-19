#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
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

int main(){
  ll N;
  cin >> N;
  ll cnt = 0;
  ll n = N / pow(10, floor(log10(N)));
  ll ne = N % 10;
  ll nm = (N - n * pow(10, floor(log10(N)))) / 10;
  // Aがi+1桁Bがj+1桁
  rep(i, floor(log10(N))+1){
    rep(j, floor(log10(N))+1){
      // Aの先頭はa Bの先頭はb
      rep2(a, 1, 10){
        rep2(b, 1, 10){
          if(i == 0 && a != b){
            continue;
          }
          if(j == 0 && a != b){
            continue;
          }
          if(i < floor(log10(N))){
            if(j < floor(log10(N))){
              cnt += pow(10, max(i-1, 0)) * pow(10, max(j-1, 0));
            }
            else if(b < n){
              cnt += pow(10, max(i-1, 0)) * pow(10, max(j-1, 0));
            }
            else if(b == n){
              if(j == 0){
                cnt += pow(10, max(i-1, 0));
              }
              else if(j == 1 && 10 * b + a <= N){
                cnt += pow(10, max(i-1, 0));
              }
              else if(pow(10, j) * b + nm * 10 + a <= N){
                cnt += pow(10, max(i-1, 0)) * (nm + 1);
              }
              else{
                cnt += pow(10, max(i-1, 0)) * nm;
              }
            }
          }
          else if(j < floor(log10(N))){
            if(a < n){
              cnt += pow(10, max(i-1, 0)) * pow(10, max(j-1, 0));
            }
            else if(a == n){
              if(i == 0){
                cnt += pow(10, max(j-1, 0));
              }
              else if(i == 1 && 10 * a + b <= N){
                cnt += pow(10, max(j-1, 0));
              }
              else if(pow(10, i) * a + nm * 10 + b <= N){
                cnt += pow(10, max(j-1, 0)) * (nm + 1);
              }
              else{
                cnt += pow(10, max(j-1, 0)) * nm;
              }
            }
          }
          else{
            if(a < n && b < n){
              cnt += pow(10, max(i-1, 0)) * pow(10, max(j-1, 0));
            }
            else if(a < n && b == n){
              if(j == 0){
                cnt += pow(10, max(i-1, 0));
              }
              else if(j == 1 && 10 * b + a <= N){
                cnt += pow(10, max(i-1, 0));
              }
              else if(pow(10, j) * b + nm * 10 + a <= N){
                cnt += pow(10, max(i-1, 0)) * (nm + 1);
              }
              else{
                cnt += pow(10, max(i-1, 0)) * nm;
              }
            }
            else if(a == n && b < n){
              if(i == 0){
                cnt += pow(10, max(j-1, 0));
              }
              else if(i == 1 && 10 * a + b <= N){
                cnt += pow(10, max(j-1, 0));
              }
              else if(pow(10, i) * a + nm * 10 + b <= N){
                cnt += pow(10, max(j-1, 0)) * (nm + 1);
              }
              else{
                cnt += pow(10, max(j-1, 0)) * nm;
              }
            }
            else if(a == n && b == n){
              if(i == 0){
                cnt += 1;
              }
              else if(i == 1 && 10 * a + b <= N){
                cnt += 1;
              }
              else if(pow(10, i) * a + nm * 10 + b <= N){
                cnt += (nm + 1) * (nm + 1);
              }
              else{
                cnt += nm * nm;
              }
            }
          }
        }
      }
    }
  }
  cout << cnt << endl;
}