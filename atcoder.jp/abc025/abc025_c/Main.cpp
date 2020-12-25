#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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

vector<vector<ll>> b(2, vector<ll>(3));
vector<vector<ll>> c(3, vector<ll>(2));

ll ox_game(vector<vector<ll>> board){
    set<pair<ll, ll>> pos;
    rep(i, 3){
        rep(j, 3){
            if(board.at(i).at(j) == -1){
                pos.insert({i, j});
            }
        }
    }
    ll score = 0;
    if(pos.empty()){
        rep(i, 2){
            rep(j, 3){
                if(board.at(i).at(j) == board.at(i+1).at(j)){
                    score += b.at(i).at(j);
                }
                else{
                    score -= b.at(i).at(j);
                }
            }
        }
        rep(i, 3){
            rep(j, 2){
                if(board.at(i).at(j) == board.at(i).at(j+1)){
                    score += c.at(i).at(j);
                }
                else{
                    score -= c.at(i).at(j);
                }
            }
        }
        return score;
    }
    if(sz(pos) % 2 == 1){
        ll tmp = -INF;
        for(auto p : pos){
            vector<vector<ll>> next = board;
            next.at(p.first).at(p.second) = 0;
            chmax(tmp, ox_game(next));
        }
        return tmp;
    }
    ll tmp = INF;
    for(auto p : pos){
        vector<vector<ll>> next = board;
        next.at(p.first).at(p.second) = 1;
        chmin(tmp, ox_game(next));
    }
    return tmp;
}

int main()
{
    ll sum = 0;
    rep(i, 2){
        rep(j, 3){
            cin >> b.at(i).at(j);
            sum += b.at(i).at(j);
        }
    }
    rep(i, 3){
        rep(j, 2){
            cin >> c.at(i).at(j);
            sum += c.at(i).at(j);
        }
    }
    vector<vector<ll>> board(3, vector<ll>(3, -1));
    ll score = ox_game(board);
    cout << (sum+score) / 2 << endl;
    cout << (sum-score) / 2 << endl;
}