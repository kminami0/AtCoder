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
    string S;
    cin >> S;
    map<char, ll> given;
    rep(i, sz(S)){
        given[S.at(i)]++;
    }
    if(sz(S) == 1){
        if(S == "8"){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(sz(S) == 2){
        if(S == "16" || S == "61" || S == "24" || S == "42" || S == "32" || S == "23" || S == "48" || S == "84" || S == "56" || S == "65" || S == "64" || S == "46" || S == "72" || S == "27" || S == "88" || S == "96" || S == "69"){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    rep2(i, 13, 125){
        string t = to_string(8*i);
        map<char, ll> eight;
        rep(j, 3){
            eight[t.at(j)]++;
        }
        rep(j, 3){
            if(given[t.at(j)] < eight.at(t.at(j))){
                break;
            }
            if(j == 2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}