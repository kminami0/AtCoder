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
    string c;
    cin >> c;
    bool lc = false; //すでに英小文字が出現したか
    bool camel = false; //キャメルケースかどうか 
    bool us = false; //アンダースコア区切りかどうか
    ll firstlc = -1; // 初めて英小文字が出現する位置
    ll lastchar = -1; // 最後にアンダースコア以外の文字が出現する位置
    rep(i, sz(c)){
        if(islower(c.at(i)) && firstlc == -1){
            firstlc = i;
        }
        if(c.at(i) != '_'){
            lastchar = i;
        }
    }
    rep(i, lastchar+1){
        if(c.at(i) == '_' && !lc){
            continue;
        }
        // 英小文字が現れる前に英大文字か数字が現れたらキャメルケースでもアンダースコア区切りでもない
        if(isupper(c.at(i)) && !lc){
            cout << c << endl;
            return 0;
        }
        if(isdigit(c.at(i)) && !lc){
            cout << c << endl;
            return 0;
        }
        if(islower(c.at(i))){
            lc = true;
        }
        if(c.at(i) == '_'){
            //英小文字が現れた後、末尾以外にアンダースコアが現れたならキャメルケースではないし、
            //アンダースコアが2連続で現れたらキャメルケースでもアンダースコア区切りでもない
            if(camel || c.at(i+1) == '_'){
                cout << c << endl;
                return 0;
            }
            us = true;
        }
        //数字の直前にアンダースコアが来たらキャメルケースでもアンダースコア区切りでもない
        if(isdigit(c.at(i)) && c.at(i-1)=='_'){
            cout << c << endl;
            return 0;
        }
        if(isupper(c.at(i))){
            //英大文字が現れたら、アンダースコア区切りではない
            if(us){
                cout << c << endl;
                return 0;
            }
            camel = true;
        }
    }
    string ans = "";
    if(us){
        bool nextup = false;
        rep(i, lastchar+1){
            if(c.at(i) == '_' && i > firstlc){ //英小文字が現れて以降の末尾以外のアンダースコアは削除し、次の文字を大文字にする
                nextup = true;
                continue;
            }
            else if(nextup){
                ans += toupper(c.at(i));
                nextup = false;
            }
            else{
                ans += c.at(i);
            }
        }
        rep2(i, lastchar+1, sz(c)){
            ans += '_';
        }
    }
    else{
        rep(i, sz(c)){
            if(isupper(c.at(i))){//大文字を小文字に変え、直前にアンダースコアを挿入する
                ans += '_';
                ans += tolower(c.at(i));
            }
            else{
                ans += c.at(i);
            }
        }
    }
    cout << ans << endl;
}