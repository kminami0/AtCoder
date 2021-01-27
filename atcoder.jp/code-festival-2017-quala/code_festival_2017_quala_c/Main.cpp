#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll H, W;
    cin >> H >> W;
    vector<ll> a(26, 0);
    rep(i, H){
        string x;
        cin >> x;
        rep(j, W){
            a.at(x.at(j)-'a')++;
        }
    }
    if(H % 2 == 0 && W % 2 == 0){
        rep(i, 26){
            if(a.at(i) % 4 != 0){
                cout << "No" << '\n';
                return 0;
            }
        }
        cout << "Yes" << '\n';
        return 0;
    }
    if(H % 2 == 0){
        ll cnt = 0;
        rep(i, 26){
            if(a.at(i) % 4 == 2){
                cnt++;
            }
            else if(a.at(i) % 4 != 0){
                cout << "No" << '\n';
                return 0;
            }
        }
        if(cnt <= H/2){
            cout << "Yes" << '\n';
            return 0;
        }
        else{
            cout << "No" << '\n';
            return 0;
        }
    }
    if(W % 2 == 0){
        ll cnt = 0;
        rep(i, 26){
            if(a.at(i) % 4 == 2){
                cnt++;
            }
            else if(a.at(i) % 4 != 0){
                cout << "No" << '\n';
                return 0;
            }
        }
        if(cnt <= W/2){
            cout << "Yes" << '\n';
            return 0;
        }
        else{
            cout << "No" << '\n';
            return 0;
        }
    }
    ll cnt1 = 0;
    ll cnt2 = 0;
    rep(i, 26){
        if(a.at(i) % 4 == 1){
            cnt1++;
        }
        else if(a.at(i) % 4 == 2){
            cnt2++;
        }
        else if(a.at(i) % 4 == 3){
            cout << "No" << '\n';
            return 0;
        }
    }
    if(cnt1 != 1){
        cout << "No" << '\n';
        return 0;
    }
    if(cnt2 > (H-1)/2+(W-1)/2){
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
}