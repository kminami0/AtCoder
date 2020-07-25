#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

vector<ll> dp(100, 0);

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A.at(i);
  bool up = true;
  ll money = 1000;
  ll stock = 0;
  rep(i, N-1){
    if(i == 0){
      if(A.at(0) < A.at(1)){
        stock += 1000/A.at(0);
        money -= A.at(0) * (1000/A.at(0));
      }
      else{
        up = false;
      }
    }
    else if(A.at(i) < A.at(i+1) && !up){
      stock += money / A.at(i);
      money -= A.at(i) * (money/A.at(i));
      up = true;
    }
    else if(A.at(i) > A.at(i+1) && up){
      money += A.at(i) * stock;
      stock = 0;
      up = false;
    }
  }
  money += A.at(N-1) * stock;
  cout << money << endl;  
}