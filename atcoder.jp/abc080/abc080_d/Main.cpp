#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    int N, C;
    cin >> N >> C;
    vector<int> s(N), t(N), c(N);
    rep(i, N){
        cin >> s.at(i) >> t.at(i) >> c.at(i);
        c.at(i)--;
    }
    vector<vector<int>> imos(200001, vector<int>(C, 0));
    rep(i, N){
        imos.at(2*s.at(i)-1).at(c.at(i))++;
        imos.at(2*t.at(i)).at(c.at(i))--;
    }
    int ans = 0;
    int tmp = 0;
    rep(i, C){
        tmp += imos.at(0).at(i);
    }
    chmax(ans, tmp);
    rep(i, 200000){
        rep(j, C){
            imos.at(i+1).at(j) += imos.at(i).at(j);
        }
    }
    rep(i, 200000){
        tmp = 0;
        rep(j, C){
            if(imos.at(i+1).at(j) == 2){
                imos.at(i+1).at(j) = 1;
            }
            tmp += imos.at(i+1).at(j);
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
