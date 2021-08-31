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

vector<ll> A(1598, -1);
vector<ll> fib = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        ll N;
        cin >> N;
        A.at(0) = -2;
        rep2(j, 1, N+1){
            A.at(j) = -1;
        }
        rep2(j, N+1, 1598){
            A.at(j) = -j+N-2;
        }
        ll l = 0;
        ll r = 1597;
        ll L = 610;
        ll R = 987;
        if(A.at(L) == -1){
            cout << "? " << L << endl;
            cin >> A.at(L);
        }
        if(A.at(R) == -1){
            cout << "? " << R << endl;
            cin >> A.at(R);
        }
        ll ans = max(0LL, max(A.at(L), A.at(R)));
        if(A.at(L) < A.at(R)){
            l = L;
            L = R;
            R = -1;
        }
        else{
            r = R;
            R = L;
            L = -1;
        }
        for(ll i = 12; i >= 0; i--){
            if(L == -1){
                L = l + fib.at(i);
                if(A.at(L) == -1){
                    cout << "? " << L << endl;
                    cin >> A.at(L);
                }
                chmax(ans, A.at(L));
                chmax(ans, A.at(R));
            }
            else{
                R = r - fib.at(i);
                if(A.at(R) == -1){
                    cout << "? " << R << endl;
                    cin >> A.at(R);
                }
                chmax(ans, A.at(L));
                chmax(ans, A.at(R));
            }
            //cerr << l << " " << L << " " << R << " " << r << endl;
            if(A.at(L) < A.at(R)){
                l = L;
                L = R;
                R = -1;
            }
            else{
                r = R;
                R = L;
                L = -1;
            }
        }
        rep(i, N){
            chmax(ans, A.at(i+1));
        }
        cout << "! " << ans << '\n';
    }
}