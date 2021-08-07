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

map<char, pair<ll, ll>> dir;
ll N, si, sj;
vector<vector<bool>> visible(69, vector<bool>(69, false));
vector<string> c(69);
ll r = 0;
bool pat;
ll gx, gy;

void watch(ll x, ll y){
    if(!visible.at(x).at(y)){
        pat = true;
    }
    visible.at(x).at(y) = true;
    rep(i, x){
        if(c.at(x-i-1).at(y) != '#' && c.at(x-i-1).at(y) != '$'){
            if(!visible.at(x-i-1).at(y)){
                pat = true;
            }
            visible.at(x-i-1).at(y) = true;
        }
        else{
            break;
        }
    }
    rep2(i, x+1, N){
        if(c.at(i).at(y) != '#' && c.at(i).at(y) != '$'){
            if(!visible.at(i).at(y)){
                pat = true;
            }
            visible.at(i).at(y) = true;
        }
        else{
            break;
        }
    }
    rep(i, y){
        if(c.at(x).at(y-i-1) != '#' && c.at(x).at(y-i-1) != '$'){
            if(!visible.at(x).at(y-i-1)){
                pat = true;
            }
            visible.at(x).at(y-i-1) = true;
        }
        else{
            break;
        }
    }
    rep2(i, y+1, N){
        if(c.at(x).at(i) != '#' && c.at(x).at(i) != '$'){
            if(!visible.at(x).at(i)){
                pat = true;
            }
            visible.at(x).at(i) = true;
        }
        else{
            break;
        }
    }
}

ll scoring(string s){
    rep(i, N){
        rep(j, N){
            visible.at(i).at(j) = false;
        }
    }
    ll n = sz(s);
    ll time = 0;
    ll px = si;
    ll py = sj;
    watch(px, py);
    rep(i, n){
        if(!dir.count(s.at(i))){
            return -1;
        }
        px += dir.at(s.at(i)).first;
        py += dir.at(s.at(i)).second;
        if(px < 0 || px >= N || py < 0 || py >= N){
            return -1;
        }
        if(c.at(px).at(py) == '#' || c.at(px).at(py) == '$'){
            return -1;
        }
        time += c.at(px).at(py) - '0';
        watch(px, py);
    }
    //cout << time << endl;
    if(px != si || py != sj){
        return -1;
    }
    ll v = 0;
    rep(i, N){
        rep(j, N){
            if(visible.at(i).at(j)){
                v++;
            }
        }
    }
    if(v < r){
        return round(10000 * (long double)(v) / (long double)(r));
    }
    return round(10000 + 10000000 *  (long double)(N) / (long double)(time));
}

vector<vector<bool>> vst(69, vector<bool>(69, false));
string ans = "";

void dfs(ll x, ll y, char d){
    if(x < 0 || x >= N || y < 0 || y >= N){
        return;
    }
    if(c.at(x).at(y) == '#' || c.at(x).at(y) == '$'){
        return;
    }
    if(vst.at(x).at(y)){
        return;
    }
    vst.at(x).at(y) = true;
    pat = false;
    watch(x, y);
    if(pat){
        gx = x;
        gy = y;
        //cout << gx << " " << gy << endl;
    }
    ans += d;
    for(auto k : dir){
        dfs(x+k.second.first, y+k.second.second, k.first);
    }
    if(d == 'U'){
        ans += 'D';
    }
    else if(d == 'D'){
        ans += 'U';
    }
    else if(d == 'L'){
        ans += 'R';
    }
    else{
        ans += 'L';
    }
}

void crash(){
    rep(i, N){
        rep(j, N){
            if(c.at(i).at(j) == '#' || c.at(i).at(j) == '$'){
                continue;
            }
            ll cnt = 0;
            for(auto k : dir){
                ll nx = i + k.second.first;
                ll ny = j + k.second.second;
                if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                    continue;
                }
                if(c.at(nx).at(ny) != '#' && c.at(nx).at(ny) != '$'){
                    cnt++;
                }
            }
            if(cnt == 1){
                bool adm = true;
                for(auto k : dir){
                    ll nx = i + k.second.first;
                    ll ny = j + k.second.second;
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N){
                        continue;
                    }
                    if(c.at(nx).at(ny) == '$'){
                        ll ox = i - k.second.first;
                        ll oy = j - k.second.second;
                        if(ox < 0 || ox >= N || oy < 0 || oy >= N){
                            adm = false;
                        }
                        else if(c.at(ox).at(oy) == '#' || c.at(ox).at(oy) == '$'){
                            adm = false;
                        }
                    }
                }
                if(adm){
                    c.at(i).at(j) = '$';
                }
            }
        }
    }
}

int main()
{
    cin >> N >> si >> sj;
    rep(i, N){
        cin >> c.at(i);
    }
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    dir['R'] = {0, 1};
    rep(i, N){
        rep(j, N){
            if(isdigit(c.at(i).at(j))){
                r++;
            }
        }
    }
    vector<string> e(N);
    rep(i, N){
        e.at(i) = c.at(i);
    }
    rep(i, N){
        crash();
    }
    pat = false;
    watch(si, sj);
    gx = si;
    gy = sj;
    for(auto k : dir){
        dfs(si+k.second.first, sj+k.second.second, k.first);
    }
    rep(i, N){
        c.at(i) = e.at(i);
    }
    string ans2 = ans;
    rep(i, sz(ans2)-1){
        if(ans2.substr(i, 2) == "UD" || ans2.substr(i, 2) == "DU" || ans2.substr(i, 2) == "LR" || ans2.substr(i, 2) == "RL"){
            ans2.erase(i, 2);
            i--;
        }
    }
    //cout << ans << '\n';
    //cout << scoring(ans) << '\n';
    string ans3 = ans;
    ll nowx = si;
    ll nowy = sj;
    char pred = 'X';
    rep(i, sz(ans)){
        nowx += dir.at(ans.at(i)).first;
        nowy += dir.at(ans.at(i)).second;
        if(pred == 'U' && ans.at(i) == 'D'){
            if(nowy == 0){
                if(c.at(nowx-1).at(nowy+1) == '#' || c.at(nowx-1).at(nowy+1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else if(nowy == N-1){
                if(c.at(nowx-1).at(nowy-1) == '#' || c.at(nowx-1).at(nowy-1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else{
                if((c.at(nowx-1).at(nowy+1) == '#' || c.at(nowx-1).at(nowy+1) == '$') && (c.at(nowx-1).at(nowy-1) == '#' || c.at(nowx-1).at(nowy-1) == '$')){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
        }
        else if(pred == 'D' && ans.at(i) == 'U'){
            //cout << nowx << " " << nowy << '\n';
            if(nowy == 0){
                if(c.at(nowx+1).at(nowy+1) == '#' || c.at(nowx+1).at(nowy+1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else if(nowy == N-1){
                if(c.at(nowx+1).at(nowy-1) == '#' || c.at(nowx+1).at(nowy-1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else{
                if((c.at(nowx+1).at(nowy+1) == '#' || c.at(nowx+1).at(nowy+1) == '$') && (c.at(nowx+1).at(nowy-1) == '#' || c.at(nowx+1).at(nowy-1) == '$')){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                    //cout << "Erase" << endl;
                }
            }
        }
        else if(pred == 'L' && ans.at(i) == 'R'){
            if(nowx == 0){
                if(c.at(nowx+1).at(nowy-1) == '#' || c.at(nowx+1).at(nowy-1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else if(nowx == N-1){
                if(c.at(nowx-1).at(nowy-1) == '#' || c.at(nowx-1).at(nowy-1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else{
                if((c.at(nowx+1).at(nowy-1) == '#' || c.at(nowx+1).at(nowy-1) == '$') && (c.at(nowx-1).at(nowy-1) == '#' || c.at(nowx-1).at(nowy-1) == '$')){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
        }
        else if(pred == 'R' && ans.at(i) == 'L'){
            if(nowx == 0){
                if(c.at(nowx+1).at(nowy+1) == '#' || c.at(nowx+1).at(nowy+1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else if(nowx == N-1){
                if(c.at(nowx-1).at(nowy+1) == '#' || c.at(nowx-1).at(nowy+1) == '$'){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
            else{
                if((c.at(nowx+1).at(nowy+1) == '#' || c.at(nowx+1).at(nowy+1) == '$') && (c.at(nowx-1).at(nowy+1) == '#' || c.at(nowx-1).at(nowy+1) == '$')){
                    pred = 'X';
                    ans.erase(i-1, 2);
                    i -= 2;
                }
            }
        }
        else{
            pred = ans.at(i);
        }
    }
    //cout << ans << '\n';
    //cout << scoring(ans) << '\n';
    if(scoring(ans) < 10000){
        ans = "";
        rep(i, N){
            rep(j, N){
                vst.at(i).at(j) = false;
            }
        }
        for(auto k : dir){
            dfs(si+k.second.first, sj+k.second.second, k.first);
        }
    }
    if(scoring(ans2) > scoring(ans)){
        ans = ans2;
    }
    if(scoring(ans3) > scoring(ans)){
        ans = ans3;
    }
    cout << ans << endl;
    //cout << scoring(ans) << '\n';
}