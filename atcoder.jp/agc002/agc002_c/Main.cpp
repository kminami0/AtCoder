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
    ll N, L;
    cin >> N >> L;
    vector<ll> a(N);
    ll sum = 0;
    ll max_length = 0;
    ll max_rope = 0;
    rep(i, N){
        cin >> a.at(i);
        sum += a.at(i);
        if(chmax(max_length, a.at(i))){
          max_rope = i;
        }
    }
    if(sum < L){ //全体の長さがL未満なら不可能
      cout << "Impossible" << endl;
      return 0;
    }
    if(max_length >= L){ //長さL以上のロープが存在すれば可能
      cout << "Possible" << endl;
      rep(i, max_rope){
        cout << i+1 << endl;
      }
      rep(i, N-1-max_rope){
        cout << N-1-i << endl;
      }
      return 0;
    }
    ll max_succ = 0;
    ll max_neighbor = 0;
    rep(i, N-1){
      if(chmax(max_succ, a.at(i)+a.at(i+1))){
        max_neighbor = i;
      }
    }
    if(max_succ < L){ //隣り合う2本の長さの和の最大値がL未満なら不可能
      cout << "Impossible" << endl;
      return 0;
    }
    cout << "Possible" << endl;
    rep(i, max_neighbor){
      cout << i+1 << endl;
    }
    rep(i, N-1-max_neighbor){
      cout << N-1-i << endl;
    }
}