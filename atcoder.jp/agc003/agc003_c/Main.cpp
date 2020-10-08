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
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> pos; //数列に含まれる各数字が現れる位置を記録する
    rep(i, N){
        cin >> A.at(i);
        pos[A.at(i)] = i;
    }
    ll ans = 0;
    ll c = 0; //ループを何周したか記録する
    for(auto p : pos){
        if(c % 2 != p.second % 2){ //ソート後にあるべき位置と、今の位置の偶奇が一致していなければ、操作1を行う必要がある
            ans++;
        }
        c++;
    }
    cout << ans / 2 << endl; //ansは操作1の対象となる数字の個数を表すので、回数はその半分
}