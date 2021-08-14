#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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

ll f(ll x){
    ll a = 1;
    while(x > 0){
        a *= x % 10;
        x /= 10;
    }
    return a;
}

ll N, B;
ll ans = 0;

void dfs(string str, ll nex){
    if(sz(str) == 11){
        ll m = stoll(str);
        ll T = f(m) + B;
        if(T > N){
            return;
        }
        string t = to_string(T);
        sort(all(t));
        string u = to_string(m);
        if(u == t){
            ans++;
        }
        return;
    }
    rep2(i, nex, 10){
        string str2 = str;
        char d = '0'+i;
        str2 += d;
        dfs(str2, i);
    }
}

int main()
{
    cin >> N >> B;
    dfs("", 0);
    string b = to_string(B);
    sort(all(b));
    if(b.at(0) == '0' && B <= N){
        ans++;
    }
    cout << ans << '\n';
}