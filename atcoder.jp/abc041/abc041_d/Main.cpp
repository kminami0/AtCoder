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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> x(M), y(M);
	map<ll, set<ll>> to;
	rep(i, M){
		cin >> x.at(i) >> y.at(i);
		x.at(i)--;
		y.at(i)--;
		to[x.at(i)].insert(y.at(i));
	}
	vector<ll> dp(1 << N, 0);
	dp.at(0) = 1;
	rep2(i, 1, 1 << N){
		bitset<16> s(i);
		set<ll> X;
		rep(j, N){
			if(!s.test(j)){
				continue;
			}
			bool flag = false;
			rep(k, N){
				if(k == j){
					continue;
				}
				if(s.test(k) && to[j].count(k)){
					flag = true;
					break;
				}
			}
			if(flag){
				continue;
			}
			X.insert(j);
		}
		for(ll j : X){
			dp.at(i) += dp.at(i - (1 << j));
		}
	}
	cout << dp.at((1 << N) - 1) << '\n';
}