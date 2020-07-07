#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
    map<char, ll> X1, X2, X3;
    rep(i, sz(S3)){
        X3[S3.at(i)]++;
        X1[S3.at(i)] = 0;
        X2[S3.at(i)] = 0;
    }
    rep(i, sz(S1)){
        X1[S1.at(i)]++;
    }
    rep(i, sz(S2)){
        X2[S2.at(i)]++;
    }
    map<char, pair<ll, ll>> toru1, toru2;
    rep(i, sz(S3)){
        if(toru1.count(S3.at(i))){
            continue;
        }
        toru1[S3.at(i)] = make_pair(max(0LL, X3.at(S3.at(i)) - X2.at(S3.at(i))), min(X1.at(S3.at(i)), X3.at(S3.at(i))));
    }
    rep(i, sz(S3)){
        if(toru2.count(S3.at(i))){
            continue;
        }
        toru2[S3.at(i)] = make_pair(max(0LL, X3.at(S3.at(i)) - X1.at(S3.at(i))), min(X2.at(S3.at(i)), X3.at(S3.at(i))));
    }
    ll Amin = 0;
    ll Amax = 0;
    for(auto p : toru1){
        Amin += p.second.first;
        Amax += p.second.second;
    }
    ll Bmin = 0;
    ll Bmax = 0;
    for(auto p : toru2){
        Bmin += p.second.first;
        Bmax += p.second.second;
    }
    if(Amin <= sz(S3)/2 && sz(S3)/2 <= Amax && Bmin <= sz(S3)/2 && sz(S3)/2 <= Bmax){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}