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

void recursive_comb(ll *indexes, ll s, ll rest, std::function<void(ll *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(ll n, ll k, function<void(ll *)> f) {
  ll indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main()
{
    string c;
    cin >> c;
    set<ll> watch;
    set<ll> pos;
    rep(i, sz(c)){
        if(c.at(i) == 'o'){
            pos.insert(i);
        }
    }
    ll ans = INF;
    rep(i, 1 << sz(c)){
        bitset<10> s(i);
        ll tmp = 0;
        rep(j, 10){
            if(s.test(j)){
                tmp++;
                for(auto x : pos){
                    if(x + j < sz(c)){
                        watch.insert(x + j);
                    }
                    else{
                        watch.insert(x + j - sz(c));
                    }
                }
            }
        }
        if(sz(watch) == sz(c)){
            chmin(ans, tmp);
        }
        watch.clear();
    }
    cout << ans << endl;
}