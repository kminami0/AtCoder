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

ll H, W;
vector<string> S;
vector<vector<ll>> mv(1000, vector<ll>(1000, INF));
deque<pair<ll, ll>> det;

void bfs(ll x, ll y, ll d, bool w){
  if(x < 0 || x >= H || y < 0 || y >= W){
    return;
  }
  if(S.at(x).at(y) == '#'){
    return;
  }
  if(mv.at(x).at(y) <= d){
      return;
  }
  if(w){
      if(chmin(mv.at(x).at(y), d+1)){
        det.push_back(make_pair(x, y));
    }
  }
  else{
      if(chmin(mv.at(x).at(y), d)){
        det.push_front(make_pair(x, y));
    }
  }
}

int main()
{
    cin >> H >> W;
    ll Ch, Cw, Dh, Dw;
    cin >> Ch >> Cw >> Dh >> Dw;
    Ch--;
    Cw--;
    Dh--;
    Dw--;
    S.resize(H);
    rep(i, H){
        cin >> S.at(i);
    }
    bfs(Ch, Cw, 0, false);
    while(!det.empty()){
        pair<ll, ll> q = make_pair(det.front().first, det.front().second);
        det.pop_front();
        ll d = mv.at(q.first).at(q.second);
        bfs(q.first+1, q.second, d, false);
        bfs(q.first-1, q.second, d, false);
        bfs(q.first, q.second+1, d, false);
        bfs(q.first, q.second-1, d, false);
        if(q.first+1 < H){
            if(S.at(q.first+1).at(q.second) == '#'){
                rep2(i, 1, 3){
                    rep2(j, -2, 3){
                        bfs(q.first+i, q.second+j, d, true);
                    }
                }
            }
        }
        if(0 <= q.first-1){
            if(S.at(q.first-1).at(q.second) == '#'){
                rep2(i, -2, 0){
                    rep2(j, -2, 3){
                        bfs(q.first+i, q.second+j, d, true);
                    }
                }
            }
        }
        if(q.second+1 < W){
            if(S.at(q.first).at(q.second+1) == '#'){
                rep2(i, -2, 3){
                    rep2(j, 1, 3){
                        bfs(q.first+i, q.second+j, d, true);
                    }
                }
            }
        }
        if(0 <= q.second-1){
            if(S.at(q.first).at(q.second-1) == '#'){
                rep2(i, -2, 3){
                    rep2(j, -2, 0){
                        bfs(q.first+i, q.second+j, d, true);
                    }
                }
            }
        }
    }
    if(mv.at(Dh).at(Dw) == INF){
        cout << -1 << endl;
    }
    else{
        cout << mv.at(Dh).at(Dw) << endl;
    }
}