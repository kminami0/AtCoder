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

struct Circle{
    pair<long double, long double> center;
    long double radius;

    Circle(pair<long double, long double> c, long double r)
        : center({c.first, c.second}), radius(r)
    {}
};

long double distance(pair<long double, long double> P, pair<long double, long double> Q){
    long double x1 = P.first;
    long double y1 = P.second;
    long double x2 = Q.first;
    long double y2 = Q.second;
    return pow((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1), 0.5);
}

bool on_line(pair<long double, long double> A, pair<long double, long double> B, pair<long double, long double> C){
    return distance(A, B) + distance(A, C) == distance(B, C) || distance(A, B) + distance(B, C) == distance(A, C) || distance(A, C) + distance(B, C) == distance(A, B);
}

pair<long double, long double> middle_point(pair<long double, long double> P, pair<long double, long double> Q){
    return {(P.first+Q.first)/2, (P.second+Q.second)/2};
}

pair<long double, long double> center_of_3points_circle(pair<long double, long double> P, pair<long double, long double> Q, pair<long double, long double> R){
    long double x1 = P.first;
    long double y1 = P.second;
    long double x2 = Q.first;
    long double y2 = Q.second;
    long double x3 = R.first;
    long double y3 = R.second;
    long double xp = ((y1-y2)*(x3*x3-x1*x1+y3*y3-y1*y1) - (y1-y3)*(x2*x2-x1*x1+y2*y2-y1*y1)) / (2*(x1-x2)*(y1-y3) - 2*(x1-x3)*(y1-y2));
    long double yp = ((x1-x3)*(x2*x2-x1*x1+y2*y2-y1*y1) - (x1-x2)*(x3*x3-x1*x1+y3*y3-y1*y1)) / (2*(x1-x2)*(y1-y3) - 2*(x1-x3)*(y1-y2));
    return {xp, yp};
}

//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<pair<long double, long double>> p(N);
    rep(i, N){
        cin >> p.at(i).first >> p.at(i).second;
    }
    Circle C({0, 0}, INF);
    rep(i, N-2){
        rep2(j, i+1, N-1){
            rep2(k, j+1, N){
                pair<long double, long double> c;
                long double r = 0;
                if(on_line(p.at(i), p.at(j), p.at(k))){
                    r = distance(p.at(i), p.at(j));
                    c = middle_point(p.at(i), p.at(j));
                    if(chmax(r, distance(p.at(j), p.at(k)))){
                        c = middle_point(p.at(j), p.at(k));
                    }
                    if(chmax(r, distance(p.at(k), p.at(i)))){
                        c = middle_point(p.at(k), p.at(i));
                    }
                }
                else{
                    c = center_of_3points_circle(p.at(i), p.at(j), p.at(k));
                    r = distance(p.at(i), c);
                }
                if(r < C.radius){
                    bool check = false;
                    rep(l, N){
                        if(l == i || l == j || l == k){
                            continue;
                        }
                        if(distance(c, p.at(l)) > r){
                            check = true;
                            break;
                        }
                    }
                    if(!check){
                        C = Circle(c, r);
                    }
                }
            }
        }
    }
    rep(i, N-1){
        rep2(j, i+1, N){
            pair<long double, long double> c = middle_point(p.at(i), p.at(j));
            long double r = distance(p.at(i), p.at(j)) / 2;
            if(r < C.radius){
                bool check = false;
                rep(k, N){
                    if(k == i || k == j){
                        continue;
                    }
                    if(distance(c, p.at(k)) > r){
                        check = true;
                        break;
                    }
                }
                if(!check){
                   C = Circle(c, r);
                }
            }
        }
    }
    cout << fixed << setprecision(18);
    cout << C.radius << '\n';
}