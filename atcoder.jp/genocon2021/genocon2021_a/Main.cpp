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

char R(char a){
    if(a == 'A'){
        return 'T';
    }
    if(a == 'T'){
        return 'A';
    }
    if(a == 'C'){
        return 'G';
    }
    if(a == 'G'){
        return 'C';
    }
    return 'X';
}

int main()
{
    ll m;
    cin >> m;
    vector<string> s(m);
    rep(i, m){
        cin >> s.at(i);
    }
    rep(i, m){
        reverse(all(s.at(i)));
        rep(j, sz(s.at(i))){
            cout << R(s.at(i).at(j));
        }
        cout << endl;
    }
}