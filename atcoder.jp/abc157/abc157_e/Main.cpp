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

ll N;
vector<vector<ll>> seg(26);

// 要求区間 [a, b) 中の要素の和を答える
// k := 自分がいるノードのインデックス
// 対象区間は [l, r) にあたる
ll getsum(ll a, ll b, ll i, ll k = 0, ll l = 0, ll r = -1){
    
    // 最初に呼び出されたときの対象区間は [0, N)
    if(r < 0){
        r = N;
    }
    
    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l){
        return 0;
    }
    
    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b){
        return seg.at(i).at(k);
    }

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    ll vl = getsum(a, b, i, 2*k+1, l, (l+r)/2);
    ll vr = getsum(a, b, i, 2*k+2, (l+r)/2, r);
    return vl + vr;
}

int main()
{
    ll n, Q;
    string S;
    cin >> n >> S >> Q;
    ll c = 0;
    while(true){
        if(pow(2, c) >= n){
            N = pow(2, c);   
            break;
        }
        else{
            c++;
        }
    }
    rep(i, 26){
        seg.at(i).resize(2*N-1, 0);
    }
    rep(i, 26){
        rep(j, n){
            if(S.at(j) == 'a' + i){
                seg.at(i).at(j+N-1) = 1;
            }
        }
    }
    rep(i, 26){
        for(ll j = N - 2; j >= 0; j--){
            seg.at(i).at(j) = seg.at(i).at(2*j+1) + seg.at(i).at(2*j+2);
        }
    }
    rep(i, Q){
        ll type;
        cin >> type;
        if(type == 1){
            ll iq;
            char cq;
            cin >> iq >> cq;
            iq--;
            ll x = iq;
            x += N - 1;
            seg.at(S.at(iq)-'a').at(x) = 0;
            while(x > 0){
                x = (x - 1) / 2;
                seg.at(S.at(iq)-'a').at(x) = seg.at(S.at(iq)-'a').at(2*x+1) + seg.at(S.at(iq)-'a').at(2*x+2);
            }
            S.at(iq) = cq;
            x = iq + N - 1;
            seg.at(cq-'a').at(x) = 1;
            while(x > 0){
                x = (x - 1) / 2;
                seg.at(cq-'a').at(x) = seg.at(cq-'a').at(2*x+1) + seg.at(cq-'a').at(2*x+2);
            }
        }
        else{
            ll lq, rq;
            cin >> lq >> rq;
            lq--;
            rq--;
            ll cnt = 0;
            rep(j, 26){
                if(getsum(lq, rq+1, j) >= 1){
                    cnt++;
                }
//                cout << getsum(lq, rq+1, j) << endl;
            }
            cout << cnt << endl;
        }
    }
}