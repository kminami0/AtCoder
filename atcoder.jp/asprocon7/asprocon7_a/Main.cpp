#include <bits/stdc++.h>
using namespace std;
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

int M, S, L, T;
vector<int> n(40);
vector<int> x(81, 0);
vector<vector<int>> t(40, vector<int>(80));

int scoring(int K, vector<int> p){
    if((int)(sz(p)) != K){
        return -1;
    }
    vector<int> cnt(M, 0);
    rep(i, K){
        cnt.at(p.at(i)-1)++;
    }
    rep(i, M){
        if(cnt.at(i) > n.at(i)){
            return -1;
        }
    }
    vector<int> m(M, 0);
    bool b;
    vector<int> y(K);
    rep(i, K){
        y.at(i) = -i * T;
    }
    vector<vector<int>> r(K, vector<int>(S, 0));
    int time = 0;
    rep(i, L){
        b = false;
        rep(k, K){
            rep(j, S){
                if(x.at(j+1) == y.at(k) && r.at(k).at(j) != t.at(p.at(k)-1).at(j)){
                    b = true;
                    break;
                }
            }
            if(b){
                break;
            }
        }
        rep(j, S){
            rep(k, K){
                if(x.at(j)+1 <= y.at(k) && y.at(k) <= x.at(j+1) && r.at(k).at(j) != t.at(p.at(k)-1).at(j)){
                    r.at(k).at(j)++;
                    break;
                }
            }
        }
        if(!b){
            rep(k, K){
                y.at(k)++;
            }
        }
        if(r.at(K-1).at(S-1) == t.at(p.at(K-1)-1).at(S-1)){
            time = i+1;
            break;
        }
    }
    rep(k, K){
        if(r.at(k).at(S-1) == t.at(p.at(k)-1).at(S-1)){
            m.at(p.at(k)-1)++;
        }
    }
    rep(i, M){
        if(m.at(i) != n.at(i)){
            break;
        }
        if(i == M-1){
            return round(1000000 * (2 - (double)(time) / (double)(L)));
        }
    }
    double sum = 0;
    rep(i, M){
        sum += pow((double)(m.at(i)) / (double)(n.at(i)), 0.5);
    }
    return round(1000000 / (double)(M) * sum);
}

chrono::system_clock::time_point start_time;

void annealing(int K, vector<int>& p){
    uniform_int_distribution<> randint(0, K-1);
    uniform_real_distribution<> dist(0.0, 1.0);
    int old_score = scoring(K, p);
    double start_temp = 200000;
    double end_temp = 1;
    double temp;
    double limit = 2000 - 100 * 10;
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        cout << elapsed_time << '\n';
        if(elapsed_time >= limit){
            break;
        }
        temp = start_temp + (end_temp - start_temp) * elapsed_time / limit;
        int idx = randint(mt);
        int idy = randint(mt);
        swap(p.at(idx), p.at(idy));
        int d = scoring(K, p) - old_score;
        if(d > 0 || exp(d / temp) > dist(mt)){
            old_score += d;
        }
        else{
            swap(p.at(idx), p.at(idy));
        }
    }
}

int main()
{
    start_time = chrono::system_clock::now();
    cin.tie(nullptr), ios::sync_with_stdio(false);
    cin >> M >> S >> T >> L;
    rep(i, M){
        rep(j, S){
            cin >> t.at(i).at(j);
        }
    }
    rep(i, S) cin >> x.at(i+1);
    rep(i, M) cin >> n.at(i);
    int K = 0;
    rep(i, M){
        K += n.at(i);
    }
    vector<int> p(K);
    int c = 0;
    rep(i, M){
        rep(j, n.at(i)){
            p.at(c+j) = i+1;
        }
        c += n.at(i);
    }
    shuffle(all(p), mt);
    //annealing(K, p);
    cout << K << '\n';
    rep(i, K-1){
        cout << p.at(i) << " ";
    }
    cout << p.at(K-1) << endl;
}