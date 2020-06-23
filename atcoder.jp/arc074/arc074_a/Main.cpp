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

ll choco(ll H, ll W){
    ll ans = INF;
    vector<ll> pieces(0);
    if(H % 3 == 0){
        ans = 0;
    }
    else if(H % 3 == 1){
        pieces.push_back((H / 3 + 1) * W);
        pieces.push_back(2 * H / 3 * (W / 2));
        pieces.push_back(2 * H / 3 * W - 2 * H / 3 * (W / 2));
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
        pieces.clear();
        pieces.push_back(H / 3 * W);
        pieces.push_back((2 * H / 3 + 1) * (W / 2));
        pieces.push_back((2 * H / 3 + 1) * W - (2 * H / 3 + 1) * (W / 2));
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
        chmin(ans, W);
    }
    else if(H == 2){
        pieces.push_back(W);
        pieces.push_back(W / 2);
        pieces.push_back(W - W / 2);
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
    }
    else{
        pieces.push_back((H / 3 + 2) * W);
        pieces.push_back(2 * (H / 3) * (W / 2));
        pieces.push_back(2 * (H / 3) * W - 2 * (H / 3) * (W / 2));
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
        pieces.clear();
        pieces.push_back((H / 3 + 1) * W);
        pieces.push_back((2 * (H / 3) + 1) * (W / 2));
        pieces.push_back((2 * (H / 3) + 1) * W - (2 * (H / 3) + 1) * (W / 2));
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
        pieces.clear();
        pieces.push_back((H / 3) * W);
        pieces.push_back((2 * (H / 3) + 2) * (W / 2));
        pieces.push_back((2 * (H / 3) + 2) * W - (2 * (H / 3) + 2) * (W / 2));
        sort(all(pieces));
        chmin(ans, pieces.at(2) - pieces.at(0));
        chmin(ans, W);
    }
    return ans;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    ll ans = INF;
    chmin(ans, choco(H, W));
    chmin(ans, choco(W, H));
    cout << ans << endl;
}