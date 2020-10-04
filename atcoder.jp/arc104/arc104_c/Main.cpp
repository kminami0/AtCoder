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
    vector<ll> A(N), B(N);
    vector<ll> type(2*N+1, 0);
    // type.at(i)の値が-1ならi階が始点であること、0なら未確定であること、1なら終点であることを表す
    vector<vector<ll>> p(2*N+1, vector<ll>(2*N+1, 0));
    // p.at(i).at(j)の値が-1ならi階からj階への移動が不可能であること、
    // 0なら可能であること、1なら確定していることを表す
    set<ll> source; // 終点が不明な始点の集合
    set<ll> target; // 始点が不明な終点の集合
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        if(A.at(i) != -1){
            if(type.at(A.at(i)) != 0){
                cout << "No" << endl;
                return 0;
            }
            type.at(A.at(i)) = -1;
        }
        if(B.at(i) != -1){
            if(type.at(B.at(i)) != 0){
                cout << "No" << endl;
                return 0;
            }
            type.at(B.at(i)) = 1;
        }
        if(A.at(i) != -1 && B.at(i) != -1 && A.at(i) >= B.at(i)){
            cout << "No" << endl;
            return 0;
        }
        if(A.at(i) != -1 && B.at(i) != -1){
            p.at(A.at(i)).at(B.at(i)) = 1;
        }
        if(A.at(i) != -1 && B.at(i) == -1){
            source.insert(A.at(i));
        }
        if(A.at(i) == -1 && B.at(i) != -1){
            target.insert(B.at(i));
        }
    }
    rep2(i, 1, 2*N+1){
        rep2(j, 1, i+1){
            p.at(i).at(j) = -1;
        }
    }
    for(auto i : source){
        for(auto j : target){
            p.at(i).at(j) = -1;
        }
    }
    rep(i, 2*N+1){
        if(type.at(i) == -1){
            rep(j, 2*N+1){
                p.at(j).at(i) = -1;
            }
        }
        if(type.at(i) == 1){
            rep(j, 2*N+1){
                p.at(i).at(j) == -1;
            }
        }
    }
    rep(i, N){
        if(A.at(i) != -1 && B.at(i) != -1){
            rep(k, 2*N+1){
                if(k == B.at(i)){
                    continue;
                }
                p.at(A.at(i)).at(k) = -1;
            }
            rep(k, 2*N+1){
                if(k == A.at(i)){
                    continue;
                }
                p.at(k).at(B.at(i)) = -1;
            }
        }
    }
    vector<bool> dp(N+1, false);
    // dp.at(i)は最後に区切ったのが2*i階であるということが可能かどうかを表す
    dp.at(0) = true;
    bool failure = false;
    rep(i, N){
        rep(j, i+1){
            if(!dp.at(j)){
                continue;
            }
            // i+1-j階分移動することは可能か
            rep(k, i+1-j){
                if(p.at(2*j+1+k).at(j+2+i+k) == -1){
                    failure = true;
                    break;
                }
            }
            if(failure){
                failure = false;
                continue;
            }
            dp.at(i+1) = true;
            break;
        }
    }
    if(dp.at(N)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}