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
int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    if(A == B){
        if(N % (A+1) == 0){
            cout << "Aoki" << endl;
        }
        else{
            cout << "Takahashi" << endl;
        }
    }
    else if(A >= N){
        cout << "Takahashi" << endl;
    }
    else if(B >= A+1){
        cout << "Aoki" << endl;
    }
    else{
        cout << "Takahashi" << endl;
    }
}