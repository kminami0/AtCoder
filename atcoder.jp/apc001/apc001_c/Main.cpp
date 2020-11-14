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
    cin >> N;
    ll l = 0;
    ll r = N ;
    ll q = 0;
    cout << q << endl;
    string s;
    cin >> s;
    if(s == "Vacant"){
        return 0;
    }
    bool l_male;
    bool r_male;
    if(s == "Male"){
        l_male = true;
        r_male = true;
    }
    else{
        l_male = false;
        r_male = false;
    }
    q = N;
    rep(i, 19){
        q = (l+r) / 2;
        cout << q << endl;
        cin >> s;
        if(s == "Vacant"){
            return 0;
        }
        if((q-l) % 2 == 1 && s == "Male" && l_male){
            r = q;
            r_male = true;
        }
        else if((q-l) % 2 == 1 && s == "Female" && !l_male){
            r = q;
            r_male = false;
        }
        else if((q-l) % 2 == 0 && s == "Male" && !l_male){
            r = q;
            r_male = true;
        }
        else if((q-l) % 2 == 0 && s == "Female" && l_male){
            r = q;
            r_male = false;
        }
        else if((r-q) % 2 == 1 && s == "Male" && r_male){
            l = q;
            l_male = true;
        }
        else if((r-q) % 2 == 1 && s == "Female" && !r_male){
            l = q;
            l_male = false;
        }
        else if((r-q) % 2 == 0 && s == "Male" && !r_male){
            l = q;
            l_male = true;
        }
        else if((r-q) % 2 == 0 && s == "Female" && r_male){
            l = q;
            l_male = false;
        }
    }
}