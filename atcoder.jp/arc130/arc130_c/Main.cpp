#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
    string a, b;
    cin >> a >> b;
    vector<ll> anum(10, 0), bnum(10, 0);
    vector<ll> ac(10, 0), bc(10, 0);
    rep(i, sz(a)){
        anum.at(a.at(i)-'0')++;
    }
    rep(i, sz(b)){
        bnum.at(b.at(i)-'0')++;
    }
    rep(i, 10){
        ac.at(i) = anum.at(i);
        bc.at(i) = bnum.at(i);
    }
    ll K = 0;
    rep2(i, 1, 10){
        ll cnt = 0;
        rep(j, 10){
            anum.at(j) = ac.at(j);
            bnum.at(j) = bc.at(j);
        }
        if(anum.at(i) == 0){
            continue;
        }
        anum.at(i)--;
        string tmpa = "";
        tmpa += i + '0';
        string tmpb = "";
        bool flag = false;
        rep2(j, 10-i, 10){
            if(bnum.at(j) > 0){
                tmpb += j + '0';
                bnum.at(j)--;
                cnt += 1;
                break;
            }
            if(j == 9){
                flag = true;
            }
        }
        if(flag){
            continue;
        }
        rep2(j, 1, 10){
            rep2(k, 9-j, 10){
                if(bnum.at(k) >= anum.at(j)){
                    rep(l, anum.at(j)){
                        tmpb += k + '0';
                        tmpa += j + '0';
                    }
                    cnt += anum.at(j);
                    bnum.at(k) -= anum.at(j);
                    anum.at(j) = 0;
                    break;
                }
                else{
                    rep(l, bnum.at(k)){
                        tmpb += k + '0';
                        tmpa += j + '0';
                    }
                    cnt += bnum.at(k);
                    anum.at(j) -= bnum.at(k);
                    bnum.at(k) = 0;
                }
            }
        }
        if(anum.at(9) > 0){
            rep(j, anum.at(9)){
                tmpa += 9 + '0';
            }
            cnt += anum.at(9);
            anum.at(9) = 0;
        }
        rep2(j, 1, 10){
            rep(k, anum.at(j)){
                tmpa += j + '0';
            }
            anum.at(j) = 0;
        }
        if(bnum.at(9) > 0){
            rep(j, bnum.at(9)){
                tmpb += 9 + '0';
            }
            cnt += bnum.at(9);
            bnum.at(9) = 0;
        }
        rep2(j, 1, 10){
            rep(k, bnum.at(j)){
                tmpb += j + '0';
            }
            bnum.at(j) = 0;
        }
        //cerr << "a:" << tmpa << endl;
        //cerr << "b:" << tmpb << endl;
        if(chmax(K, cnt)){
            a = tmpa;
            b = tmpb;
            reverse(all(a));
            reverse(all(b));
        }
    }
    cout << a << '\n';
    cout << b << '\n';
}