#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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

ll si, sj;
vector<vector<ll>> p(50, vector<ll>(50));
vector<bool> vst(2500, false);
vector<vector<ll>> t(50, vector<ll>(50));

ll lx, ly;

ll scoring(string S){
    ll score = 0;
    score += p.at(si).at(sj);
    vst.at(t.at(si).at(sj)) = true;
    ll px = si;
    ll py = sj;
    rep(i, sz(S)){
        if(S.at(i) == 'U'){
            px--;
        }
        else if(S.at(i) == 'D'){
            px++;
        }
        else if(S.at(i) == 'L'){
            py--;
        }
        else if(S.at(i) == 'R'){
            py++;
        }
        if(vst.at(t.at(px).at(py))){
            cerr << t.at(px).at(py) << ": twice visited" << endl;
            return -1;
        }
        else{
            vst.at(t.at(px).at(py)) = true;
            score += p.at(px).at(py);
        }
    }
    lx = px;
    ly = py;
    return score;
}

string solve(ll si, ll sj){
    string ans = "";
    vector<ll> dx = {-1, 1, 0, 0};
    vector<ll> dy = {0, 0, -1, 1};
    string dir = "UDLR";
    ll px = si;
    ll py = sj;
    vst.at(t.at(si).at(sj)) = true;
    while(true){
        bool move = false;
        rep(i, 4){
            if(0 <= px+dx.at(i) && px+dx.at(i) <= 49 && 0 <= py+dy.at(i) && py+dy.at(i) <= 49 && !vst.at(t.at(px+dx.at(i)).at(py+dy.at(i)))){
                px += dx.at(i);
                py += dy.at(i);
                vst.at(t.at(px).at(py)) = true;
                ans += dir.at(i);
                move = true;
                break;
            }
        }
        if(!move){
            break;
        }
    }
    return ans;
}

string greed(ll si, ll sj){
    string ans = "";
    vector<ll> dx = {-1, 1, 0, 0};
    vector<ll> dy = {0, 0, -1, 1};
    string dir = "UDLR";
    ll px = si;
    ll py = sj;
    vst.at(t.at(si).at(sj)) = true;
    while(true){
        ll add = 0;
        pair<ll, ll> d = {-1, -1};
        rep(i, 4){
            rep(j, 4){
                if(0 <= px+dx.at(i) && px+dx.at(i) <= 49 && 0 <= py+dy.at(i) && py+dy.at(i) <= 49 && !vst.at(t.at(px+dx.at(i)).at(py+dy.at(i)))){
                    vst.at(t.at(px+dx.at(i)).at(py+dy.at(i))) = true;
                    if(0 <= px+dx.at(i)+dx.at(j) && px+dx.at(i)+dx.at(j) <= 49 && 0 <= py+dy.at(i)+dy.at(j) && py+dy.at(i)+dy.at(j) <= 49 && !vst.at(t.at(px+dx.at(i)+dx.at(j)).at(py+dy.at(i)+dy.at(j)))){
                        if(chmax(add, p.at(px+dx.at(i)).at(py+dy.at(i)) + p.at(px+dx.at(i)+dx.at(j)).at(py+dy.at(i)+dy.at(j)))){
                            d = {i, j};
                        }
                    }
                    vst.at(t.at(px+dx.at(i)).at(py+dy.at(i))) = false;
                }
            }
        }
        if(d.first == -1){
            break;
        }
        px += dx.at(d.first);
        py += dy.at(d.first);
        vst.at(t.at(px).at(py)) = true;
        ans += dir.at(d.first);
        px += dx.at(d.second);
        py += dy.at(d.second);
        vst.at(t.at(px).at(py)) = true;
        ans += dir.at(d.second);
    }
    while(true){
        ll add = 0;
        ll d = -1;
        rep(i, 4){
            if(0 <= px+dx.at(i) && px+dx.at(i) <= 49 && 0 <= py+dy.at(i) && py+dy.at(i) <= 49 && !vst.at(t.at(px+dx.at(i)).at(py+dy.at(i)))){
                if(chmax(add, p.at(px+dx.at(i)).at(py+dy.at(i)))){
                    d = i;
                }
            }
        }
        if(d == -1){
            break;
        }
        px += dx.at(d);
        py += dy.at(d);
        vst.at(t.at(px).at(py)) = true;
        ans += dir.at(d);
    }
    return ans;
}

int main()
{
    random_device rd;
    seed_seq seed = {rd()};
    mt19937 engine(seed);
    uniform_real_distribution<> distr(0.0, 1.0);
    cin >> si >> sj;
    rep(i, 50){
        rep(j, 50){
            cin >> t.at(i).at(j);
        }
    }
    rep(i, 50){
        rep(j, 50){
            cin >> p.at(i).at(j);
        }
    }
    string ans1 = solve(si, sj);
    rep(i, 2500){
        vst.at(i) = false;
    }
    string ans2 = greed(si, sj);
    rep(i, 2500){
        vst.at(i) = false;
    }
    ll score1 = scoring(ans1);
    rep(i, 2500){
        vst.at(i) = false;
    }
    ll score2 = scoring(ans2);
    string zantei;
    ll ts;
    if(score1 > score2){
        zantei = ans1;
        ts = score1;
    }
    else{
        zantei = ans2;
        ts = score2;
    }
    clock_t start = clock();
    long double time = 0;
    ll cnt = 0;
    while(time < 1.9){
        uniform_int_distribution<> dist(1, sz(zantei));
        ll q = dist(engine);
        rep(i, 2500){
            vst.at(i) = false;
        }
        string S = zantei.substr(0, q);
        scoring(S);
        string T = solve(lx, ly);
        rep(i, 2500){
            vst.at(i) = false;
        }
        ll delta = scoring(S+T) - ts;
        if(cnt % 100 == 0){
            time = (long double)(clock() - start) / CLOCKS_PER_SEC;
        }
        long double ran = distr(engine);
        if(delta >= 0 || ran <= exp(delta/time)){
            ts += delta;
            zantei = S+T;
        }
        cnt++;
    }
    cout << zantei << '\n';
}