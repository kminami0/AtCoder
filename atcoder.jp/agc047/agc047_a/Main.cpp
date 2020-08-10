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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    ll N;
    cin >> N;
    vector<string>A(N);
    rep(i, N){
        cin >> A.at(i);
    }
    vector<pair<ll, ll>> B(N);
    rep(i, N){
        ll c = 0;
        ll p = 0;
        rep(j, sz(A.at(i))){
            if(A.at(i).at(j) == '.'){
                c = sz(A.at(i)) - j - 1;
                p = j;
                break;
            }
        }
        if(p != 0){
            ll x = stoll(A.at(i).substr(0, p)+A.at(i).substr(p+1));
            B.at(i) = make_pair(pow(10, c), x);
        }
        else{
            B.at(i) = make_pair(1, stoll(A.at(i)));
        }
    }
    vector<pair<ll, ll>> C(N);
    rep(i, N){
        ll g = gcd(B.at(i).first, B.at(i).second);
        C.at(i) = make_pair(B.at(i).first/g, B.at(i).second/g);
    }
    vector<pair<ll, ll>> D(N);
    rep(i, N){
        ll a = 0;
        ll b = 0;
        ll c = 0;
        ll d = 0;
        ll s = C.at(i).first;
        ll t = C.at(i).second;
        while(s % 2 == 0){
            a++;
            s /= 2;
        }
        while(s % 5 == 0){
            b++;
            s /= 5;
        }
        while(t % 2 == 0){
            c++;
            t /= 2;
        }
        while(t % 5 == 0){
            d++;
            t /= 5;
        }
        D.at(i) = make_pair(c-a, d-b);
    }
    sort(all(D));
    map<pair<ll, ll>, ll> cnt;
    rep(i, N){
        cnt[D.at(i)]++;
    }
    ll ans = 0;
    rep2(i, -9, 45){
        rep2(j, -9, 45){
            rep2(k, -9, 45){
                rep2(l, -9, 45){
                    if((i + k) < 0 || (j + l) < 0){
                        continue;
                    }
                    if(i == k && j > l){
                        continue;
                    }
                    if(i > k){
                        continue;
                    }
                    if(i == k && j == l){
                        ans += (cnt[make_pair(i, j)] * (cnt[make_pair(i, j)]-1)) / 2;
                    }
                    else{
                        ans += cnt[make_pair(i, j)] * cnt[make_pair(k, l)];
                    }
                }
            }
        }
    }
    cout << ans << endl;
}