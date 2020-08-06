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
    string s;
    cin >> N >> s;
    ll p = 0;
    rep(i, N){
        if(s.at(i) == 'x'){
            p = i;
            break;
        }
        if(i == N-1){
            rep(j, N){
                cout << 'S';
            }
            cout << endl;
            return 0;
        }
    }
    s = s + s + s;
    string t = "";
    rep(i, 3*N){
        t += 'a';
    }
    bool ok1 = false;
    bool ok2 = false;
    //1:羊羊狼
    t.at(p+N-1) = 'S';
    t.at(p+N) = 'S';
    t.at(p+N+1) = 'W';
    rep(i, N-3){
        if(t.at(p+N+1+i) == 'S'){
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
        }
        else{
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
        }
    }
    if(s.at(p+2*N-2) == 'o'){
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    else{
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    if(s.at(p+2*N-1) == 'o'){
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
    }
    else{
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
    }
    if(ok1 && ok2){
        string ans = "";
        rep(i, N){
            rep(j, 3){
                if(t.at(j*N+i) != 'a'){
                    ans += t.at(j*N+i);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    ok1 = false;
    ok2 = false;
    //2:狼羊羊
    t.at(p+N-1) = 'W';
    t.at(p+N) = 'S';
    t.at(p+N+1) = 'S';
    rep(i, N-3){
        if(t.at(p+N+1+i) == 'S'){
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
        }
        else{
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
        }
    }
    if(s.at(p+2*N-2) == 'o'){
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    else{
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    if(s.at(p+2*N-1) == 'o'){
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
    }
    else{
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
    }
    if(ok1 && ok2){
        string ans = "";
        rep(i, N){
            rep(j, 3){
                if(t.at(j*N+i) != 'a'){
                    ans += t.at(j*N+i);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    ok1 = false;
    ok2 = false;
    //3:羊狼羊
    t.at(p+N-1) = 'S';
    t.at(p+N) = 'W';
    t.at(p+N+1) = 'S';
    rep(i, N-3){
        if(t.at(p+N+1+i) == 'S'){
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
        }
        else{
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
        }
    }
    if(s.at(p+2*N-2) == 'o'){
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    else{
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    if(s.at(p+2*N-1) == 'o'){
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
    }
    else{
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
    }
    if(ok1 && ok2){
        string ans = "";
        rep(i, N){
            rep(j, 3){
                if(t.at(j*N+i) != 'a'){
                    ans += t.at(j*N+i);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    ok1 = false;
    ok2 = false;
    //4:狼狼狼
    t.at(p+N-1) = 'W';
    t.at(p+N) = 'W';
    t.at(p+N+1) = 'W';
    rep(i, N-3){
        if(t.at(p+N+1+i) == 'S'){
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
        }
        else{
            if(s.at(p+N+1+i) == 'o'){
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'W';
                }
                else{
                    t.at(p+N+i+2) = 'S';
                }
            }
            else{
                if(t.at(p+N+i) == 'S'){
                    t.at(p+N+i+2) = 'S';
                }
                else{
                    t.at(p+N+i+2) = 'W';
                }
            }
        }
    }
    if(s.at(p+2*N-2) == 'o'){
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    else{
        if(t.at(p+2*N-2) == 'S'){
            if(t.at(p+2*N-3) != t.at(p+N-1)){
                ok1 = true;
            }
        }
        else{
            if(t.at(p+2*N-3) == t.at(p+N-1)){
                ok1 = true;
            }
        }
    }
    if(s.at(p+2*N-1) == 'o'){
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
    }
    else{
        if(t.at(p+N-1) == 'S'){
            if(t.at(p+2*N-2) != t.at(p+N)){
                ok2 = true;
            }
        }
        else{
            if(t.at(p+2*N-2) == t.at(p+N)){
                ok2 = true;
            }
        }
    }
    if(ok1 && ok2){
        string ans = "";
        rep(i, N){
            rep(j, 3){
                if(t.at(j*N+i) != 'a'){
                    ans += t.at(j*N+i);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
}