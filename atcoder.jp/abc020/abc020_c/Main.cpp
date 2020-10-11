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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

int main()
{
    ll H, W, T;
    cin >> H >> W >> T;
    graph.resize(H*W);
    vector<string> s(H);
    rep(i, H){
        cin >> s.at(i);
    }
    ll start;
    ll goal;
    rep(i, H){
        rep(j, W){
            if(s.at(i).at(j) == 'S'){
                start = i*W+j;
            }
            if(s.at(i).at(j) == 'G'){
                goal = i*W+j;
            }
        }
    }
    ll l = 1;
    ll r = T;
    // x<=lのときT秒以内にゴール可能、x>=rのときT秒以内にゴール不可能
    // 境界を二分探索で見つける
    while(r-l > 1){
        ll c = (l+r) / 2;
        vector<vector<ll>> d(H*W, vector<ll>(H*W, INF));
        // ワーシャルフロイド法でx=cのときのゴールへの移動時間を調べる
        rep(i, H*W){
            d.at(i).at(i) = 0;
        }
        rep(i, H){
            rep(j, W-1){
                if(s.at(i).at(j+1) == '#'){
                    d.at(i*W+j).at(i*W+j+1) = c;
                }
                else{
                    d.at(i*W+j).at(i*W+j+1) = 1;
                }
            }
        }
        rep(i, H){
            rep2(j, 1, W){
                if(s.at(i).at(j-1) == '#'){
                    d.at(i*W+j).at(i*W+j-1) = c;
                }
                else{
                    d.at(i*W+j).at(i*W+j-1) = 1;
                }
            }
        }
        rep(i, H-1){
            rep(j, W){
                if(s.at(i+1).at(j) == '#'){
                    d.at(i*W+j).at((i+1)*W+j) = c;
                }
                else{
                    d.at(i*W+j).at((i+1)*W+j) = 1;
                }
            }
        }
        rep2(i, 1, H){
            rep(j, W){
                if(s.at(i-1).at(j) == '#'){
                    d.at(i*W+j).at((i-1)*W+j) = c;
                }
                else{
                    d.at(i*W+j).at((i-1)*W+j) = 1;
                }
            }
        }
        rep(k, H*W){
            rep(i, H*W){
                rep(j, H*W){
                    chmin(d.at(i).at(j), d.at(i).at(k)+d.at(k).at(j));
                }
            }
        }
        if(d.at(start).at(goal) <= T){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << l << endl;
}