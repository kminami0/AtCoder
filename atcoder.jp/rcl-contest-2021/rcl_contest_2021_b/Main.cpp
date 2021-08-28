#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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

random_device rd;
mt19937 mt(rd());

int N;
vector<vector<int>> E(40, vector<int>(40));
vector<vector<int>> P(40, vector<int>(40));

bool check(){
    rep(i, N){
        rep(j, N){
            if(P[i][j] != 0){
                rep2(k, i-P[i][j], i+P[i][j]+1){
                    rep2(l, j-P[i][j], j+P[i][j]+1){
                        if(k < 0 || k >= N || l < 0 || l >= N){
                            continue;
                        }
                        if(k == i && l == j){
                            continue;
                        }
                        if(abs(i-k)+abs(j-l) <= P[i][j]){
                            if(P[k][l] != 0){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

int scoring(){
    if(!check()){
        return -1;
    }
    int s = 0;
    rep(i, N){
        rep(j, N){
            s += E[i][j] * P[i][j];
        }
    }
    return s;
}

chrono::system_clock::time_point start_time;

void greed(){
    double limit = 1900;
    std::uniform_int_distribution<> randint(0, N - 1);
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        if(elapsed_time >= limit){
            break;
        }
        int idx = randint(mt);
        int idy = randint(mt);
        if(P[idx][idy] == N){
            continue;
        }
        P[idx][idy]++;
        if(!check()){
            P[idx][idy]--;
        }
    }
}

vector<tuple<int, int, int>> pfm(0);

void greed2(){
    double limit = 1900;
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        if(elapsed_time >= limit){
            break;
        }
    }
    for(auto x : pfm){
        int idx = get<1>(x);
        int idy = get<2>(x);
        if(P[idx][idy] == N){
            continue;
        }
        int pre = P[idx][idy];
        P[idx][idy] += get<0>(x);
        chmin(P[idx][idy], N); 
        if(!check()){
            P[idx][idy] = pre;
        }
        if(P[idx][idy] != N){
            P[idx][idy]++;
            if(!check()){
                P[idx][idy]--;
            }
        }
    }
}

void anneal(){
    double limit = 1900;
    uniform_int_distribution<> randint(0, N - 1);
    uniform_real_distribution<> dist(0.0, 1.0);
    double start_temp = 30;
    double end_temp = 1;
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        if(elapsed_time >= limit){
            break;
        }
        int idx = randint(mt);
        int idy = randint(mt);
        if(P[idx][idy] == N){
            continue;
        }
        P[idx][idy]++;
        double d = E[idx][idy];
        if(!check()){
            rep(i, N){
                rep(j, N){
                    if(i == idx && j == idy){
                        continue;
                    }
                    if(abs(idx-i)+abs(idy-j) <= P[idx][idy]){
                        d -= P[i][j] * E[i][j];
                    }
                }
            }
        }
        double temp = start_temp + (end_temp - start_temp) * elapsed_time / limit;
        if(d > 0 || exp(d / temp) > dist(mt)){
            if(!check()){
                rep(i, N){
                    rep(j, N){
                        if(i == idx && j == idy){
                            continue;
                        }
                        if(abs(idx-i)+abs(idy-j) <= P[idx][idy]){
                            P[i][j] = 0;
                        }
                    }
                }
            }
        }
        while(!check()){
            P[idx][idy]--;
        }
    }
}

int main()
{
    start_time = chrono::system_clock::now();
    cin >> N;
    rep(i, N){
        rep(j, N){
            cin >> E[i][j];
            pfm.push_back({E[i][j], i, j});
        }
    }
    sort(all(pfm));
    reverse(all(pfm));
    anneal();
    rep(i, N){
        rep(j, N-1){
            cout << P[i][j] << " ";
        }
        cout << P[i][N-1] << '\n';
    }
    //cout << "score: " << scoring() << '\n';
}