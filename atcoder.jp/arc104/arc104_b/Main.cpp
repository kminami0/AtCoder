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
    string S;
    cin >> N >> S;
    vector<ll> As(N+1, 0);
    vector<ll> Ts(N+1, 0);
    vector<ll> Cs(N+1, 0);
    vector<ll> Gs(N+1, 0);
    rep(i, N){
        if(S.at(i) == 'A'){
            As.at(i+1) = As.at(i) + 1;
            Ts.at(i+1) = Ts.at(i);
            Cs.at(i+1) = Cs.at(i);
            Gs.at(i+1) = Gs.at(i);
        }
        if(S.at(i) == 'T'){
            As.at(i+1) = As.at(i);
            Ts.at(i+1) = Ts.at(i) + 1;
            Cs.at(i+1) = Cs.at(i);
            Gs.at(i+1) = Gs.at(i);
        }
        if(S.at(i) == 'C'){
            As.at(i+1) = As.at(i);
            Ts.at(i+1) = Ts.at(i);
            Cs.at(i+1) = Cs.at(i) + 1;
            Gs.at(i+1) = Gs.at(i);
        }
        if(S.at(i) == 'G'){
            As.at(i+1) = As.at(i);
            Ts.at(i+1) = Ts.at(i);
            Cs.at(i+1) = Cs.at(i);
            Gs.at(i+1) = Gs.at(i) + 1;
        }
    }
    ll ans = 0;
    // [i, j)が条件を満たすか
    rep(i, N){
        rep2(j, i+1, N+1){
            if(As.at(j)-As.at(i) == Ts.at(j)-Ts.at(i) && Cs.at(j)-Cs.at(i) == Gs.at(j)-Gs.at(i)){
                ans++;
            }
        }
    }
    cout << ans << endl;
}