#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<int> X, ANS;

bool taken[2000] = {0};

int main(){
    cin >> n >> d;
    int mi = 12939;
    for(int c1 = 0; c1 < n; c1++){
        int x;
        cin >> x;
        X.push_back(x);
        taken[x] = 1;
        mi = min(mi, x);
    }

    while(1){
        bool ok = 1;
        for(int c1 = 0; c1 < n; c1++){
            if(X[c1] != mi && !taken[X[c1]-1]){
                ok = 0;
                ANS.push_back(X[c1]-1);
                taken[X[c1]] = 0;
                X[c1]--;
                taken[X[c1]] = 1;
            }
        }
        if(ok)break;
    }

    cout << ANS.size() << "\n";
    for(int c1 = 0; c1 < ANS.size(); c1++){
        cout << ANS[c1] << "\n";
    }

    return 0;
}
