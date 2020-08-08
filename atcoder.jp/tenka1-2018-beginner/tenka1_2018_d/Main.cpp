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

vector<vector<ll>> crossing(ll k, ll s){
    vector<vector<ll>> ans(0);
    if(k == 1){
        ans.push_back({s});
        ans.push_back({s});
        return ans;
    }
    ans.push_back({});
    rep(i, k){
        ans.at(0).push_back(i+s);
    }
    rep(i, k){
        ans.push_back({});
    }
    rep(i, k){
        ans.at(i+1).push_back(i+s);
    }
    vector<vector<ll>> tmp = crossing(k-1, k+s);
    rep(i, k){
        ans.at(i+1).insert(ans.at(i+1).end(), tmp.at(i).begin(), tmp.at(i).end());
    }
    return ans;
}

int main()
{
    ll N;
    cin >> N;
    ll k = 0;
    ll p = 0;
    rep(i, N+1){
        k += i;
        if(k > N){
            cout << "No" << endl;
            return 0;
        }
        if(k == N){
            p = i;
            break;
        }
    }
    vector<vector<ll>> ans = crossing(p, 1);
    cout << "Yes" << endl;
    cout << p+1 << endl;
    rep(i, p+1){
        cout << sz(ans.at(i)) << " ";
        rep(j, sz(ans.at(i))-1){
            cout << ans.at(i).at(j) << " ";
        }
        cout << ans.at(i).at(sz(ans.at(i))-1) << endl;
    }
}