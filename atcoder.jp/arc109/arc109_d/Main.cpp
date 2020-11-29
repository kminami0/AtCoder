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

ll answer(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    map<ll, ll> x;
    map<ll, ll> y;
    x[ax]++;
    y[ay]++;
    x[bx]++;
    y[by]++;
    x[cx]++;
    y[cy]++;
    ll gx, gy, sx, sy;
    for(auto p : x){
        if(p.second == 2){
            gx = p.first;
        }
        else{
            sx = p.first;
        }
    }
    for(auto p : y){
        if(p.second == 2){
            gy = p.first;
        }
        else{
            sy = p.first;
        }
    }
    ll goalx = 0;
    ll goaly = 0;
    if(sx == gx+1 && sy == gy+1){
        goalx = 2 * gx;
        goaly = 2 * gy;
    }
    if(sx == gx+1 && sy == gy-1){
        goalx = 2 * gx;
        goaly = 2 * gy - 1;
    }
    if(sx == gx-1 && sy == gy+1){
        goalx = 2 * gx - 1;
        goaly = 2 * gy;
    }
    if(sx == gx-1 && sy == gy-1){
        goalx = 2 * gx - 1;
        goaly = 2 * gy - 1;
    }
    if(goalx == 0 && goaly == 0){
        return 0;
    }
    set<pair<ll, ll>> move1 = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {0, -1}, {1, -1}};
    if(move1.count({goalx, goaly})){
        return 1;
    }
    set<pair<ll, ll>> move2 = {{-2, 2}, {-1, 2}, {0, 2}, {1, 2}, {-2, 1}, {2, 1}, {-2, 0}, {2, 0}, {-2, -1}, {-1, -1}, {2, -1}, {-1, -2}, {0, -2}, {1, -2}, {2, -2}};
    if(move2.count({goalx, goaly})){
        return 2;
    }
    if((goalx > 0 && goalx == goaly) || (goalx < 0 && goalx == goaly)){
        return abs(goalx) + 1;
    }
    return max(abs(goalx), abs(goaly));
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        ll ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        cout << answer(ax, ay, bx, by, cx, cy) << endl;
    }
}