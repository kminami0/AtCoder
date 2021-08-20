#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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

long double signed_area_of_triangle(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    long double S = ((ax-cx)*(by-cy)+(bx-cx)*(cy-ay)) / 2.0;
    return S;
}

bool clockwise(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    return signed_area_of_triangle(ax, ay, bx, by, cx, cy) < 0;
}

bool counterclockwise(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    return signed_area_of_triangle(ax, ay, bx, by, cx, cy) > 0;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll num_of_lattice_points(ll x1, ll y1, ll x2, ll y2){
    return gcd(abs(x1-x2), abs(y1-y2)) + 1;
}

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> P(N);
    rep(i, N){
        cin >> P.at(i).first >> P.at(i).second;
    }
    sort(all(P));
    stack<ll> S;
    S.push(0);
    S.push(1);
    rep2(i, 2, N){
        while(true){
            ll i2 = S.top();
            S.pop();
            ll i1 = S.top();
            if(clockwise(P.at(i1).first, P.at(i1).second, P.at(i2).first, P.at(i2).second, P.at(i).first, P.at(i).second)){
                S.push(i2);
                break;
            }
            if(sz(S) == 1){
                break;
            }
        }
        S.push(i);
    }
    vector<ll> upper_convex(0);
    while(!S.empty()){
        upper_convex.push_back(S.top());
        S.pop();
    }
    S.push(0);
    S.push(1);
    rep2(i, 2, N){
        while(true){
            ll i2 = S.top();
            S.pop();
            ll i1 = S.top();
            if(counterclockwise(P.at(i1).first, P.at(i1).second, P.at(i2).first, P.at(i2).second, P.at(i).first, P.at(i).second)){
                S.push(i2);
                break;
            }
            if(sz(S) == 1){
                break;
            }
        }
        S.push(i);
    }
    vector<ll> lower_convex(0);
    while(!S.empty()){
        lower_convex.push_back(S.top());
        S.pop();
    }
    reverse(all(lower_convex));
    ll area = 0;
    vector<ll> polygon(0);
    for(ll x : lower_convex){
        polygon.push_back(x);
    }
    rep2(i, 1, sz(upper_convex)-1){
        polygon.push_back(upper_convex.at(i));
    }
    ll M = N;
    N = sz(polygon);
    rep(i, N){
        area += (P.at(polygon.at(i)).first*P.at(polygon.at((i+1)%N)).second - P.at(polygon.at((i+1)%N)).first*P.at(polygon.at(i)).second);
    }
    area /= 2;
    ll lp = 0;
    rep(i, N){
        lp += num_of_lattice_points(P.at(polygon.at(i)).first, P.at(polygon.at(i)).second, P.at(polygon.at((i+1)%N)).first, P.at(polygon.at((i+1)%N)).second);
    }
    lp -= N;
    ll il = area - lp/2 + 1;
    cout << il + lp - M << '\n';
}