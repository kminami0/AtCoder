#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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

bool collision_detection(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h){
    pair<long double, long double> center1 = {(a+c)/2.0, (b+d)/2.0};
    pair<long double, long double> center2 = {(e+g)/2.0, (f+h)/2.0};
    long double x_dist = abs(center1.first - center2.first);
    long double y_dist = abs(center1.second - center2.second);
    if(x_dist >= (c-a)/2.0 + (g-e)/2.0){
        return false;
    }
    if(y_dist >= (d-b)/2.0 + (h-f)/2.0){
        return false;
    }
    return true;
}

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
           if(i*i != n){
               ret.push_back(n/i);
           }
       }
   }
   sort(all(ret));
   return ret;
}

int main()
{
    random_device rd;
    seed_seq seed = {rd()};
    mt19937 engine(seed);
    uniform_int_distribution<> dist(0, 9999);
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), r(n);
    rep(i, n){
        cin >> x.at(i) >> y.at(i) >> r.at(i);
    }
    vector<tuple<ll, ll, ll, ll>> ads(n);
    rep(i, n){
        rep(j, r.at(i)){
            ll factor = pow(2,8);
            vector<ll> divisors = enum_div((r.at(i)-j)/factor);
            bool put = false;
            ll cnt = 0;
            for(ll div : divisors){
                if(cnt <= 8){
                    cnt++;
                    continue;
                }
                ll a = x.at(i);
                ll b = y.at(i);
                ll c = a + div;
                ll d = b + ((r.at(i)-j)/factor)/div;
                if(c > 10000 || d > 10000){
                    continue;
                }
                bool hit = false;
                rep(k, i){
                    if(collision_detection(a, b, c, d, get<0>(ads.at(k)), get<1>(ads.at(k)), get<2>(ads.at(k)), get<3>(ads.at(k)))){
                        hit = true;
                        break;
                    }
                }
                if(hit){
                    continue;
                }
                ads.at(i) = {a, b, c, d};
                put = true;
                break;
            }
            if(put){
                break;
            }
            if(j == r.at(i)-1){
                bool make = false;
                while(!make){
                    ll p = dist(engine);
                    ll q = dist(engine);
                    rep(k, i){
                        if(collision_detection(p, q, p+1, q+1, get<0>(ads.at(k)), get<1>(ads.at(k)), get<2>(ads.at(k)), get<3>(ads.at(k)))){
                            break;
                        }
                        if(k == i-1){
                            ads.at(i) = {p, q, p+1, q+1};
                            make = true;
                            break;
                        }
                    }
                }
            }
        }
        //cerr << i << endl;
    }
    rep(k, pow(2,3)){
        rep(i, n){
            ll height = get<3>(ads.at(i)) - get<1>(ads.at(i));
            ll width = get<2>(ads.at(i)) - get<0>(ads.at(i));
            if(height*width*2 > r.at(i)){
                continue;
            }
            if(get<3>(ads.at(i)) + height <= 10000){
                rep(j, n){
                    if(i == j){
                        continue;
                    }
                    if(collision_detection(get<0>(ads.at(i)), get<1>(ads.at(i)), get<2>(ads.at(i)), get<3>(ads.at(i))+height, get<0>(ads.at(j)), get<1>(ads.at(j)), get<2>(ads.at(j)), get<3>(ads.at(j)))){
                        break;
                    }
                    if(j == n-1 || (i == n-1 && j == n-2)){
                        get<3>(ads.at(i)) += height;
                    }
                }
            }
        }
    }
    rep(k, pow(2,3)){
        rep(i, n){
            ll height = get<3>(ads.at(i)) - get<1>(ads.at(i));
            ll width = get<2>(ads.at(i)) - get<0>(ads.at(i));
            if(height*width*2 > r.at(i)){
                continue;
            }
            if(get<2>(ads.at(i)) + width <= 10000){
                rep(j, n){
                    if(i == j){
                        continue;
                    }
                    if(collision_detection(get<0>(ads.at(i)), get<1>(ads.at(i)), get<2>(ads.at(i))+width, get<3>(ads.at(i)), get<0>(ads.at(j)), get<1>(ads.at(j)), get<2>(ads.at(j)), get<3>(ads.at(j)))){
                        break;
                    }
                    if(j == n-1 || (i == n-1 && j == n-2)){
                        get<2>(ads.at(i)) += width;
                    }
                }
            }
        }
    }
    rep(k, pow(2,3)){
        rep(i, n){
            ll height = get<3>(ads.at(i)) - get<1>(ads.at(i));
            ll width = get<2>(ads.at(i)) - get<0>(ads.at(i));
            if(height*width*2 > r.at(i)){
                continue;
            }
            if(get<1>(ads.at(i)) - height >= 0){
                rep(j, n){
                    if(i == j){
                        continue;
                    }
                    if(collision_detection(get<0>(ads.at(i)), get<1>(ads.at(i))-height, get<2>(ads.at(i)), get<3>(ads.at(i)), get<0>(ads.at(j)), get<1>(ads.at(j)), get<2>(ads.at(j)), get<3>(ads.at(j)))){
                        break;
                    }
                    if(j == n-1 || (i == n-1 && j == n-2)){
                        get<1>(ads.at(i)) -= height;
                    }
                }
            }
        }
    }
    rep(k, pow(2,3)){
        rep(i, n){
            ll height = get<3>(ads.at(i)) - get<1>(ads.at(i));
            ll width = get<2>(ads.at(i)) - get<0>(ads.at(i));
            if(height*width*2 > r.at(i)){
                continue;
            }
            if(get<0>(ads.at(i)) - width >= 0){
                rep(j, n){
                    if(i == j){
                        continue;
                    }
                    if(collision_detection(get<0>(ads.at(i))-width, get<1>(ads.at(i)), get<2>(ads.at(i)), get<3>(ads.at(i)), get<0>(ads.at(j)), get<1>(ads.at(j)), get<2>(ads.at(j)), get<3>(ads.at(j)))){
                        break;
                    }
                    if(j == n-1 || (i == n-1 && j == n-2)){
                        get<0>(ads.at(i)) -= width;
                    }
                }
            }
        }
    }
    rep(i, n){
        cout << get<0>(ads.at(i)) << " " << get<1>(ads.at(i)) << " " << get<2>(ads.at(i)) << " " << get<3>(ads.at(i)) << '\n';
    }
}