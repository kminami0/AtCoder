#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int mex(set<int> S){
    int c = 0;
    while(true){
        if(!S.count(c)){
            return c;
        }
        c++;
    }
}

vector<vector<int>> Gr(51, vector<int>(1326, -1));

int grundy(int w, int b){
    if(Gr[w][b] != -1){
        return Gr[w][b];
    }
    set<int> S;
    if(w >= 1){
        if(Gr[w-1][b+w] != -1){
            S.insert(Gr[w-1][b+w]);
        }
        else{
            S.insert(grundy(w-1, b+w));
        }
    }
    if(b >= 2){
        rep2(k, 1, b/2+1){
            if(Gr[w][b-k] != -1){
                S.insert(Gr[w][b-k]);
            }
            else{
                S.insert(grundy(w, b-k));
            }
        }
    }
    Gr[w][b] = mex(S);
    return Gr[w][b];
}

int main()
{
    int N;
    cin >> N;
    vector<int> W(N), B(N);
    rep(i, N){
        cin >> W[i];
    }
    rep(i, N){
        cin >> B[i];
    }
    int G = 0;
    rep(i, N){
        G ^= grundy(W[i], B[i]);
    }
    if(G != 0){
        cout << "First" << '\n';
    }
    else{
        cout << "Second" << '\n';
    }
}