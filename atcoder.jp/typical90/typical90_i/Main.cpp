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
    ll N;
    cin >> N;
    vector<long double> X(N), Y(N);
    rep(i, N){
        cin >> X.at(i) >> Y.at(i);
    }
    long double ans = 0;
    rep(i, N){
        vector<long double> angle(0);
        rep(j, N){
            if(j == i){
                continue;
            }
            long double x = X.at(j) - X.at(i);
            long double y = Y.at(j) - Y.at(i);
            long double alpha = atan2(y, x);
            if(alpha < 0){
                alpha += 2 * M_PI;
            }
            angle.push_back(alpha);

        }
        sort(all(angle));
        rep(j, N-1){
            long double t = angle.at(j);
            long double u = t + M_PI;
            if(u > 2 * M_PI){
                u -= 2 * M_PI;
            }
            auto iter = lower_bound(all(angle), u);
            ll index = iter - begin(angle);
            if(index == N-1){
                long double theta = angle.at(index-1);
                long double cand = min(abs(theta-t), 2*M_PI-abs(theta-t));
                chmax(ans, cand);
            }
            else{
                long double theta1 = angle.at(index);
                long double theta2;
                if(index == 0){
                    theta2 = angle.at(N-2);
                }
                else{
                    theta2 = angle.at(index-1);
                }
                long double cand = min(abs(theta1-t), 2*M_PI-abs(theta1-t));
                chmax(cand, min(abs(theta2-t), 2*M_PI-abs(theta2-t)));
                chmax(ans, cand);
            }
        }
    }
    ans *= 180 / M_PI;
    cout << fixed << setprecision(12);
    cout << ans << '\n';
}