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
    ll A, B, C;
    cin >> A >> B >> C;
    if(A >= 0 && B >= 0){
        if(A < B){
            cout << "<" << '\n';
        }
        else if(A > B){
            cout << ">" << '\n';
        }
        else{
            cout << "=" << '\n';
        }
    }
    else if(A >= 0 && B < 0){
        if(C % 2 == 1){
            cout << ">" << '\n';
        }
        else{
            if(A < -B){
                cout << "<" << '\n';
            }
            else if(A > -B){
                cout << ">" << '\n';
            }
            else{
                cout << "=" << '\n';
            }
        }
    }
    else if(A < 0 && B >= 0){
        if(C % 2 == 1){
            cout << "<" << '\n';
        }
        else{
            if(-A < B){
                cout << "<" << '\n';
            }
            else if(-A > B){
                cout << ">" << '\n';
            }
            else{
                cout << "=" << '\n';
            }
        }
    }
    else{
        if(C % 2 == 1){
            if(A < B){
                cout << "<" << '\n';
            }
            else if(A > B){
                cout << ">" << '\n';
            }
            else{
                cout << "=" << '\n';
            }
        }
        else{
            if(-A < -B){
                cout << "<" << '\n';
            }
            else if(-A > -B){
                cout << ">" << '\n';
            }
            else{
                cout << "=" << '\n';
            }
        }
    }
}