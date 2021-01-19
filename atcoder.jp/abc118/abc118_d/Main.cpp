#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
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

struct Match{
    string num;
    bool pos;

    bool operator< (const Match &other){
        if(!pos && other.pos){
            return true;
        }
        if(pos && !other.pos){
            return false;
        }
        if(sz(num) < sz(other.num)){
            return true;
        }
        if(sz(num) > sz(other.num)){
            return false;
        }
        return num < other.num;
    }

    Match operator+(ll x){
        Match ret;
        char y = x + '0';
        ret.num = num + y;
        ret.pos = pos;
        return ret;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M);
    rep(i, M) cin >> A.at(i);
    vector<ll> need = {INF,2,5,5,4,5,6,3,7,6};
    vector<Match> dp(N+1, {"", false});
    dp.at(0).pos = true;
    rep2(i, 1, N+1){
        rep(j, M){
            if(i - need.at(A.at(j)) < 0){
                continue;
            }
            chmax(dp.at(i), dp.at(i-need.at(A.at(j))) + A.at(j));
        }
    }
    cout << dp.at(N).num << '\n';
}