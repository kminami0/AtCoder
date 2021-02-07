#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> a(N), b(N);
    rep(i, N){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;
        b.at(i)--;
    }
    map<pair<ll, ll>, ll> box;
    rep(i, N){
        rep(j, 3){
            rep(k, 3){
                if(a.at(i)+j >= H || b.at(i)+k >= W || a.at(i)+j < 2 || b.at(i)+k < 2){
                    continue;
                }
                box[{a.at(i)+j, b.at(i)+k}]++;
            }
        }
    }
    vector<ll> paint(10, 0);
    ll m = H * W - 2*H - 2*W + 2*2;
    paint.at(0) = m - sz(box);
    for(auto p : box){
        paint.at(p.second)++;
    }
    rep(i, 10){
        cout << paint.at(i) << '\n';
    }
}