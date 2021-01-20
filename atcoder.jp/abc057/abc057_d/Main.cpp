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

ll combinations(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

pair<long double, ll> calc(ll A, ll B, vector<ll> v, long double sum, ll n){
    long double avg = sum;
    ll cnt = 0;
    map<ll, ll> bucket;
    rep(i, sz(v)){
        bucket[v.at(i)]++;
    }
    if(A <= bucket.at(v.at(0))){
        if(n == 0){
            rep2(i, A, B+1){
                cnt += combinations(bucket.at(v.at(0)), i);
            }
            avg = v.at(0);
        }
        else{
            avg += v.at(0) * A;
            avg /= n + A;
            cnt += combinations(bucket.at(v.at(0)), A);
        }
        return {avg, cnt};
    }
    avg += bucket.at(v.at(0)) * v.at(0);
    vector<ll> w(sz(v)-bucket.at(v.at(0)));
    copy(v.begin()+bucket.at(v.at(0)), v.end(), w.begin());
    return calc(A-bucket.at(v.at(0)), B-bucket.at(v.at(0)), w, avg, n+bucket.at(v.at(0)));
}

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    map<ll, ll> bucket;
    rep(i, N){
        cin >> v.at(i);
        bucket[v.at(i)]++;
    }
    sort(all(v));
    reverse(all(v));
    pair<long double, ll> p = calc(A, B, v, 0, 0);
    cout << fixed << setprecision(6);
    cout << p.first << '\n';
    cout << p.second << '\n';
}