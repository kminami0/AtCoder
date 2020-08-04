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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll pick(ll a, ll b, ll c, ll d){
    if(a == c){
        return abs(b - d) + 1;
    }
    ll g = gcd(c-a, d-b);
    ll p = (c-a) / g;
    ll q = (d-b) / g;
    return abs(c-a) / abs(p) + 1;
}

bool line(ll x1, ll y1, ll x2, ll y2, ll a, ll b){
    return (x2-x1)*(b-y1) == (y2-y1)*(a-x1);
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i);
    }
    ll ans = 0;
    rep(i, N){
        rep2(j, i+1, N){
            rep2(k, j+1, N){
                if(line(x.at(i), y.at(i), x.at(j), y.at(j), x.at(k), y.at(k))){
                    continue;
                }
                ll c = 0;
                c += pick(x.at(i), y.at(i), x.at(j), y.at(j));
                c += pick(x.at(j), y.at(j), x.at(k), y.at(k));
                c += pick(x.at(k), y.at(k), x.at(i), y.at(i));
                c -= 3;
                if(c % 2 == 0){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}