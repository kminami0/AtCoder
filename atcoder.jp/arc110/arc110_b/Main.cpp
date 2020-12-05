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
    ll N;
    string T;
    cin >> N >> T;
    if(N == 1){
        if(T == "0"){
            cout << 10000000000 << endl;
        }
        else{
            cout << 20000000000 << endl;
        }
        return 0;
    }
    string pre = "";
    string post = "";
    if(T.at(0) == '0'){
        pre = "0";
        T.erase(0, 1);
    }
    else if(T.substr(0, 2) == "10"){
        pre = "10";
        T.erase(0, 2);
    }
    if(sz(T) >= 2 && T.substr(sz(T)-2, 2) == "11"){
        post = "11";
        T.erase(sz(T)-2, 2);
    }
    else if(sz(T) >= 1 && T.at(sz(T)-1) == '1'){
        post = "1";
        T.erase(sz(T)-1, 1);
    }
    if(sz(T) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    while(!T.empty()){
        if(T.substr(0, 3) != "110"){
            cout << 0 << endl;
            return 0;
        }
        cnt++;
        T.erase(0, 3);
    }
    if(pre == "" && post == ""){
        cout << 10000000000-cnt+1 << endl;
    }
    else if(pre != "" && post != ""){
        cout << 10000000000-cnt-1 << endl;
    }
    else{
        cout << 10000000000-cnt << endl;
    }
}