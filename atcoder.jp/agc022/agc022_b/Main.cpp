#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(N == 4){
        cout << "2 5 20 63" << endl;
        return 0;
    }
    if(N == 5){
        cout << "2 5 20 30 63" << endl;
        return 0;
    }
    set<ll> ans;
    ll k = 0;
    rep(i, N){
        if(i % 4 == 0){
            ans.insert(6*k + 2);
        }
        else if(i % 4 == 1){
            ans.insert(6*k + 3);
        }
        else if(i % 4 == 2){
            ans.insert(6*k + 4);
        }
        else{
            k++;
            ans.insert(6*k);
        }
    }
    ll sum = 0;
    for(auto p : ans){
        sum += p;
    }
    ll cnt = 0;
    if(sum % 6 == 2){
        ans.erase(8);
        if(ans.count(6*k)){
            ans.insert(6*k+6);
        }
        else{
            ans.insert(6*k); 
        }       
    }
    else if(sum % 6 == 3){
        ans.erase(9);
        if(ans.count(6*k)){
            ans.insert(6*k+6);
        }
        else{
            ans.insert(6*k); 
        }       
    }
    else if(sum % 6 == 5){
        ans.erase(9);
        if(ans.count(6*k+2)){
            ans.insert(6*k+4);
        }
        else{
            ans.insert(6*k+12); 
        }       
    }
    for(auto p : ans){
        if(cnt != N-1){
            cout << p << " ";
            cnt++;
        }
        else{
            cout << p << endl;
        }
    }
}