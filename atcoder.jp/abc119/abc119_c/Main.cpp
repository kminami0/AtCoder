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

ll A, B, C;

ll kadomatsu(vector<ll> l, ll m){
    if(sz(l) < 3){
        return INF;
    }
    if(sz(l) == 3){
        return abs(l.at(0)-A) + abs(l.at(1)-B) + abs(l.at(2)-C) + 10 * m;
    }
    ll a = INF;
    vector<ll> p(sz(l)-1), q(sz(l)-1), r(sz(l)-1), s(sz(l)-1);
    rep(i, sz(l)-1){
        p.at(i) = l.at(i);
        q.at(i) = l.at(i);
        r.at(i) = l.at(i);
        s.at(i) = l.at(i);
    }
    p.at(0) += l.at(sz(l)-1);
    q.at(1) += l.at(sz(l)-1);
    r.at(2) += l.at(sz(l)-1);
    chmin(a, kadomatsu(p, m+1));
    chmin(a, kadomatsu(q, m+1));
    chmin(a, kadomatsu(r, m+1));
    chmin(a, kadomatsu(s, m));
    return a;
}

int main()
{
    ll N;
    cin >> N >> A >> B >> C;
    vector<ll> l(N);
    rep(i, N){
        cin >> l.at(i);
    }
    sort(all(l));
    ll mp = INF;
    do{
        chmin(mp, kadomatsu(l, 0));
    } while(next_permutation(all(l)));
    cout << mp << endl;
}