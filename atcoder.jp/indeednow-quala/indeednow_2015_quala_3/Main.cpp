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
	ll N;
	cin >> N;
	map<ll, ll> students;
	rep(i, N){
		ll s;
		cin >> s;
		students[s]++;
	}
	ll Q;
	cin >> Q;
	vector<ll> k(Q);
	rep(i, Q) cin >> k.at(i);
	vector<ll> acc(1000002, 0);
	// acc.at(i)はi点未満の学生の数
	rep(i, 1000001){
		acc.at(i+1) = acc.at(i) + students[i];
	}
	rep(i, Q){
		if(k.at(i) >= N){
			cout << 0 << '\n';
			continue;
		}
		ll l = 0;
		ll r = 1000001;
		// N - acc.at(r) <= k.at(i) < N - acc.at(l)
		while(r-l > 1){
			ll c = (l+r) / 2;
			if(N - acc.at(c) <= k.at(i)){
				r = c;
			}
			else{
				l = c;
			}
		}
		if(r == 1){
			cout << 0 << '\n';
		}
		else{
			cout << r << '\n';
		}
	}
}