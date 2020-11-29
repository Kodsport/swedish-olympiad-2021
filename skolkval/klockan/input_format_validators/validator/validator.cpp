#include "validator.h"
#include <vector>

vector<int> e {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int energy(int time){
    assert(time >= 0 && time < 24*60*60);
    int secs = time%60;
    int mins = time/60%60;
    int hours = time/3600%24;
    return e[secs%10] + e[secs/10] +
           e[mins%10] + e[mins/10] +
           e[hours%10] + e[hours/10];
}

int solve(int n){
    int ans = 0;
    int a = 0;
    int b = 0;
    int sum = energy(0);
    while(1){
        if(sum == n) ans++;
        if(sum <= n){
            b++;
            if(b >= 24*60*60) break;
            sum += energy(b);
        }
        else{
            sum -= energy(a);
            a++;
        }
    }
    return ans;
}

void run() {
    int max_n  = Arg("max_n");
    if(max_n == -1) max_n = 1e9;
    int n = Int(1, max_n);
    assert(solve(n) != 0);
    Endl();
    Eof();
}
