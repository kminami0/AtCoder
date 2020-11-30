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
    deque<ll> A;
    rep(i, N){
        ll x;
        cin >> x;
        A.push_back(x);
    }
    ll ans = 0;
    //黒コマを置いたあと、白コマを置ける場所は1箇所しかない
    //2回の操作をひとまとめにして、ひっくり返す数が少ないほうに置き続ける貪欲法
    rep(i, (N-1)/2){
        ll s = sz(A);
        ll left = 2*A.at(0)+A.at(1)+1;
        ll right = 2*A.at(s-1)+A.at(s-2)+1;
        if(left < right){
            ans += left;
            ll y = A.at(0)+A.at(1)+A.at(2)+2;
            A.pop_front();
            A.pop_front();
            A.pop_front();
            A.push_front(y);
        }
        else{
            ans += right;
            ll y = A.at(s-1)+A.at(s-2)+A.at(s-3)+2;
            A.pop_back();
            A.pop_back();
            A.pop_back();
            A.push_back(y);
        }
    }
    cout << ans << endl;
}