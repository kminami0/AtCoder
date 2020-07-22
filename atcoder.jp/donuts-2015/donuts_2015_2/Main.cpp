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

vector<ll> A, B;
ll ans = 0;
ll M;
vector<set<ll>> I;

int main()
{
    ll N;
    cin >> N >> M;
    A.resize(N);
    I.resize(M);
    B.resize(M);
    rep(i, N){
        cin >> A.at(i);
    }
    vector<ll> C(M);
    rep(i, M){
        cin >> B.at(i) >> C.at(i);
        rep(j, C.at(i)){
            ll x;
            cin >> x;
            x--;
            I.at(i).insert(x);
        }
    }
    foreach_comb(N, 9, [](ll *indexes){
        ll tmp = 0;
        rep(i, 9){
            tmp += A.at(indexes[i]);
        }
        rep(i, M){
            ll c = 0;
            rep(j, 9){
                if(I.at(i).count(indexes[j])){
                    c++;
                }
                if(c >= 3){
                    tmp += B.at(i);
                    break;
                }
            }
        }
        chmax(ans, tmp);
    });
    cout << ans << endl;
}