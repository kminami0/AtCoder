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
int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    set<string> t;
    set<string> f;
    rep(i, N){
        cin >> S.at(i);
        if(S.at(i).at(0) == '!'){
            if(t.count(S.at(i).substr(1))){
                cout << S.at(i).substr(1) << endl;
                return 0;
            }
            else{
                f.insert(S.at(i).substr(1));
            }
        }
        else{
            if(f.count(S.at(i))){
                cout << S.at(i) << endl;
                return 0;
            }
            else{
                t.insert(S.at(i));
            }
        }
    }
    cout << "satisfiable" << endl;
}