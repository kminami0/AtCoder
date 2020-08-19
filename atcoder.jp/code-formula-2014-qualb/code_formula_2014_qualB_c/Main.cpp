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
    string A, B;
    cin >> A >> B;
    ll diff = 0;
    vector<ll> diffp(0);
    rep(i, sz(A)){
        if(A.at(i) != B.at(i)){
            diff++;
            diffp.push_back(i);
        }
    }
    if(diff > 6){
        cout << "NO" << endl;
        return 0;
    }
    set<ll> chs;
    rep(i, sz(A)){
        chs.insert(A.at(i));
    }
    if(A == B){
        if(sz(chs) == sz(A)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        return 0;
    }
    if(diff == 1){
        cout << "NO" << endl;
        return 0;
    }
    map<char, ll> ac;
    map<char, ll> bc;
    rep(i, sz(A)){
        ac[A.at(i)]++;
        bc[B.at(i)]++;
    }
    if(ac != bc){
        cout << "NO" << endl;
        return 0;
    }
    if(diff == 2){
        cout << "YES" << endl;
        return 0;
    }
    string C = A;
    bool two = false;
    rep(i, diff){
        rep2(j, i+1, diff){
            rep(k, diff){
                rep2(l, k+1, diff){
                    C = A;
                    swap(C.at(diffp.at(i)), C.at(diffp.at(j)));
                    swap(C.at(diffp.at(k)), C.at(diffp.at(l)));
                    if(C == B){
                        two = true;
                    }
                }
            }
        }
    }
    if(two){
        if(sz(chs) == sz(A)){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        return 0;
    }
    bool three = false;
    rep(i, diff){
        rep2(j, i+1, diff){
            rep(k, diff){
                rep2(l, k+1, diff){
                    rep(m, diff){
                        rep2(n, m+1, diff){
                            C = A;
                            swap(C.at(diffp.at(i)), C.at(diffp.at(j)));
                            swap(C.at(diffp.at(k)), C.at(diffp.at(l)));
                            swap(C.at(diffp.at(m)), C.at(diffp.at(n)));
                            if(C == B){
                                three = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(three){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}