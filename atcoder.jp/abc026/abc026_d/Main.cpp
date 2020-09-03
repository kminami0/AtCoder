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

long double A, B, C;
long double f(long double t){
    return A * t + B * sin(C * t * M_PI);
}

int main()
{
    cin >> A >> B >> C;
    long double s = 0;
    while(true){
        if(f(s) < 100){
            s += 1;
        }
        else{
            break;
        }
    }
    long double l = 0;
    long double r = s;
    while(abs(f(l)-100) > 0.0000001 && abs(f(r)-100) > 0.0000001){
        long double c = (l + r) / 2;
        if(f(c) < 100){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << fixed << setprecision(14);
    if(abs(f(l)-100) <= 0.0000001){
        cout << l << endl;
//        cout << f(l) << endl;
    }
    else{
        cout << r << endl;
//        cout << f(r) << endl;
    }
}