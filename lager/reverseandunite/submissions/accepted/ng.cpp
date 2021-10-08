#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<int> X, ANS;

int mod(int a, int m){
    return (a + 10000*m)%m;
}

void make_move(int L){
    for(int c1 = 0; c1 < n; c1++){
        if(X[c1] >= L && X[c1] <= L + d - 1){
            X[c1] = 2*L + d - 1 - X[c1];
        }
    }
    ANS.push_back(L);
}

void move_to(int i, int to, int mi){
    if(mod(X[i],d-1) != mod(to,d-1)){
        if(mod(to + 1 + X[i] - d,2) == 1){
            make_move(X[i]);
        }
        int goal = (to + 1 + X[i] - d) / 2;
        while(goal+d-1 < X[i] || goal < mi){
            goal += 2*(d-1);
        }
        while(goal > X[i]){
            make_move(X[i]);
        }
        make_move(goal);
    }
    while(X[i] != to){
        make_move(X[i]-d+1);
    }
}

int main(){
    cin >> n >> d;
    int parity[2] = {0};
    for(int c1 = 0; c1 < n; c1++){
        int x;
        cin >> x;
        X.push_back(x);
        parity[x%2]++;
    }
    int start = -(n + n%2);
    if(d%2 == 1 && abs(parity[0] - parity[1]) > 1){
        cout << "-1\n";
        return 0;
    }
    if(n%2 == 1 && parity[1] > parity[0]){
        start--;
    }
    for(int c1 = 0; c1 < n; c1++){
        int chosen = -1;
        for(int c2 = 0; c2 < n; c2++){
            if((mod(start, 2) == mod(X[c2], 2) || d%2 == 0) && X[c2] >= start){
                chosen = c2;
                break;
            }
        }
        assert(chosen != -1);
        move_to(chosen, start, start);
        start++;
    }

    cout << ANS.size() << "\n";
    for(int c1 = 0; c1 < ANS.size(); c1++){
        cout << ANS[c1] << "\n";
    }

    return 0;
}
