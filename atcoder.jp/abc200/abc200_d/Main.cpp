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
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    A.at(0) = 0;
    rep(i, N){
        cin >> A.at(i+1);
        A.at(i+1) %= 200;
    }
    vector<vector<pair<ll, ll>>> diff(200, vector<pair<ll, ll>>(0));
    rep(i, N+1){
        rep2(j, i+1, N+1){
            ll r = A.at(j) + A.at(i);
            r %= 200;
            diff.at(r).push_back({i, j});
        }
    }
    rep(i, 200){
        if(sz(diff.at(i)) >= 2){
            cout << "Yes" << '\n';
            if(diff.at(i).at(0).first == 0){
                cout << 1 << " " << diff.at(i).at(0).second  << '\n';
            }
            else{
                cout << 2 << " " << diff.at(i).at(0).first << " " << diff.at(i).at(0).second << '\n';
            }
            if(diff.at(i).at(1).first == 0){
                cout << 1 << " " << diff.at(i).at(1).second  << '\n';
            }
            else{
                cout << 2 << " " <<  diff.at(i).at(1).first << " " << diff.at(i).at(1).second << '\n';
            }
            return 0;
        }
    }
    vector<ll> rem(200, 0);
    rep2(i, 1, 1 << N){
        bitset<23> s(i);
        ll tmp = 0;
        rep(j, N){
            if(s.test(j)){
                tmp += A.at(j+1);
            }
        }
        tmp %= 200;
        if(rem.at(tmp) != 0){
            ll k = rem.at(tmp);
            bitset<23> t(k);
            vector<ll> B(0), C(0);
            rep(j, N){
                if(s.test(j)){
                    B.push_back(j+1);
                }
            }
            rep(j, N){
                if(t.test(j)){
                    C.push_back(j+1);
                }
            }
            cout << "Yes" << '\n';
            cout << sz(B) << " ";
            rep(j, sz(B)-1){
                cout << B.at(j) << " ";
            }
            cout << B.at(sz(B)-1) << '\n';
            cout << sz(C) << " ";
            rep(j, sz(C)-1){
                cout << C.at(j) << " ";
            }
            cout << C.at(sz(C)-1) << '\n';
            return 0;
        }
        else{
            rem.at(tmp) = i;
        }
    }
    cout << "No" << '\n';
}