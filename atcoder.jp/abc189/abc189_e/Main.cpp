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

struct A {
	vector<vector<ll>> a;
	vector<ll> b;
	A(const vector<vector<ll>> _a = {{1,0},{0,1}},
	  const vector<ll> _b = {0,0}):a(_a), b(_b) {}
	A operator*(const A& x) const {
		A res({{0,0},{0,0}});
		rep(i, 2){
			rep(j, 2){
				rep(k, 2){
					res.a.at(i).at(j) += x.a.at(i).at(k) * a.at(k).at(j);
				}
			}
		}
		rep(i, 2){
			res.b.at(i) += b.at(i);
			rep(j, 2){
				res.b.at(i) += a.at(j).at(i) * x.b.at(j);
			}
		}
		return res;
	}
};

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> P(N);
    rep(i, N){
        cin >> P.at(i).first >> P.at(i).second;
    }
    ll M;
    cin >> M;
	vector<A> d(1);
    rep(i, M){
        ll op;
        cin >> op;
		A x;
        if(op == 1){
			x = A({{0,-1},{1,0}});
        } 
        else if(op == 2){
			x = A({{0,1},{-1,0}});
        }
        else if(op == 3){
            ll p;
            cin >> p;
			x = A({{-1,0},{0,1}},{2*p,0});
        }
        else{
            ll p;
            cin >> p;
			x = A({{1,0},{0,-1}},{0,2*p});
        }
		A y = x*d.back();
		d.emplace_back(y);
    }
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll A, B;
        cin >> A >> B;
        B--;
		ll posx = 0;
		ll posy = 0;
		posx += d.at(A).a.at(0).at(0) * P.at(B).first;
		posx += d.at(A).a.at(1).at(0) * P.at(B).second;
		posy += d.at(A).a.at(0).at(1) * P.at(B).first;
		posy += d.at(A).a.at(1).at(1) * P.at(B).second;
		posx += d.at(A).b.at(0);
		posy += d.at(A).b.at(1);
		cout << posx << ' ' << posy << '\n';
    }
}