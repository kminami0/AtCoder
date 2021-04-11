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
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    map<char, ll> wariate;
    rep(i, sz(S1)){
        wariate[S1.at(i)] = -1;
    }
    rep(i, sz(S2)){
        wariate[S2.at(i)] = -1;
    }
    rep(i, sz(S3)){
        wariate[S3.at(i)] = -1;
    }
    if(sz(wariate) > 10){
        cout << "UNSOLVABLE" << '\n';
        return 0;
    }
    vector<ll> digit = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do{
        ll p = 0;
        for(auto x : wariate){
            wariate.at(x.first) = digit.at(p);
            p++;
        }
        ll T1 = 0;
        ll T2 = 0;
        ll T3 = 0;
        ll d = 1;
        rep(i, sz(S1)){
            T1 += d * wariate.at(S1.at(sz(S1)-1-i));
            d *= 10;
        }
        d = 1;
        rep(i, sz(S2)){
            T2 += d * wariate.at(S2.at(sz(S2)-1-i));
            d *= 10;
        }
        d = 1;
        rep(i, sz(S3)){
            T3 += d * wariate.at(S3.at(sz(S3)-1-i));
            d *= 10;
        }
        string U1 = to_string(T1);
        string U2 = to_string(T2);
        string U3 = to_string(T3);
        if(sz(S1) != sz(U1) || sz(S2) != sz(U2) || sz(S3) != sz(U3)){
            continue;
        }
        if(T1 == 0 || T2 == 0 || T3 == 0){
            continue;
        }
        if(T1 + T2 == T3){
            cout << T1 << '\n';
            cout << T2 << '\n';
            cout << T3 << '\n';
            return 0;
        }
    } while(next_permutation(all(digit)));
    cout << "UNSOLVABLE" << '\n';
}