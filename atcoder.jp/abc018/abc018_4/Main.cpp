#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    ll N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    vector<ll> x(R), y(R), z(R);
    rep(i, R){
        cin >> x.at(i) >> y.at(i) >> z.at(i);
        x.at(i)--;
        y.at(i)--;
    }
    ll ans = 0;
    rep(i, 1 << N){
        bitset<18> s(i);
        ll cnt = 0;
        set<ll> girls;
        rep(j, 18){
            if(s.test(j)){
                cnt++;
                girls.insert(j);
            }
        }
        if(cnt != P){
            continue;
        }
        vector<ll> happy(M, 0);
        rep(j, R){
            if(girls.count(x.at(j))){
                happy.at(y.at(j)) += z.at(j);
            }
        }
        sort(rbegin(happy), rend(happy));
        ll tmp = 0;
        rep(j, Q){
            tmp += happy.at(j);
        }
        chmax(ans, tmp);
    }
    cout << ans << '\n';
}