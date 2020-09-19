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
    ll N, K;
    cin >> N >> K;
    if(2*K > (N-1)*(N-2)){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll, ll>> edges(0);
    rep(i, N-1){
        edges.push_back({N, i+1});
    }
    ll d = (N-1)*(N-2)/2 - K;
    ll c = 0;
    bool flag = false;
    rep(i, N-1){
        rep2(j, i+1, N-1){
            if(c == d){
                flag = true;
                break;
            }
            edges.push_back({i+1, j+1});
            c++;
        }
        if(flag){
            break;
        }
    }
    cout << N-1+d << endl;
    rep(i, N-1+d){
        cout << edges.at(i).first << " " << edges.at(i).second << endl;
    }
}