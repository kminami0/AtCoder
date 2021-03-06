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
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    deque<ll> d;
    rep(i, N){
        ll p = lower_bound(all(d), A.at(i)) - d.begin();
        if(p == 0){
            d.push_front(A.at(i));
        }
        else{
            d.at(p-1) = A.at(i);
        }
    }
    cout << sz(d) << endl;    
}