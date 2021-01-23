#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
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
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
	ll ans = 0;
	rep(i, N){
		ll p = i;
		rep2(j, i, N){
			if(A.at(j) >= A.at(p)){
				if(j == N-1){
					chmax(ans, (N-i)*A.at(p));
				}
				continue;
			}
			chmax(ans, (j-i)*A.at(p));
			p = j;
		}
	}
	cout << ans << '\n';
}