#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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

struct vector2D{
    long double x;
    long double y;
};

vector2D nearest( vector2D A, vector2D B, vector2D P ){
	vector2D a, b;
	long double r;
	
	a.x = B.x - A.x;
	a.y = B.y - A.y;
	b.x = P.x - A.x;
	b.y = P.y - A.y;
	
	r = (a.x*b.x + a.y*b.y) / (a.x*a.x + a.y*a.y);
	
	if( r<= 0 ){
		return A;
	}else if( r>=1 ){
		return B;
	}else{
		vector2D result;
		result.x = A.x + r*a.x;
		result.y = A.y + r*a.y;
		return result;
	}
}

long double distance(vector2D P, vector2D Q){
    return pow((P.x-Q.x)*(P.x-Q.x) + (P.y-Q.y)*(P.y-Q.y), 0.5);
}

int main()
{
    long double X, Y;
    ll N;
    cin >> X >> Y >> N;
    vector2D ant = {X, Y};
    vector<vector2D> P(N);
    rep(i, N){
        long double x, y;
        cin >> x >> y;
        P.at(i) = {x, y};
    }
    P.push_back(P.at(0));
    long double ans = INF;
    rep(i, N){
        vector2D Q = nearest(P.at(i), P.at(i+1), ant);
        chmin(ans, distance(ant, Q));
    }
    cout << fixed << setprecision(10);
    cout << ans << '\n';
}