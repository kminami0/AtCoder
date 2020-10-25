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
    ll N, M;
    cin >> N >> M;
    if(M < 0){ //高橋君のプログラムは最適解を与えるので、M<0なら不可
        cout << -1 << endl;
        return 0;
    }
    if(M == N){ //青木君のプログラムの少なくとも1個はとるので、M=Nなら不可
        cout << -1 << endl;
        return 0;
    }
    if(N == 1 && M == 0){ //N=1, M=0ならどんな区間1個でもよい
        cout << 1 << " " << 1000000000 << endl;
        return 0;
    }
    if(M == N-1){ //高橋君がN個とれるなら、どの2つの区間も交わってないので、青木君もN個とれるはず、よってM=N-1は不可
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << " " << 1000000000 << endl;
    rep(i, M){
        cout << 2*i+2 << " " << 2*i+3 << endl;
    }
    rep(i, N-M-1){
        cout << 2*M+2+i << " " << 999999999-i << endl;
    }
}