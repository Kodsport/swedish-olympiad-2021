#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi e {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int energy(int time){
    assert(time >= 0 && time < 24*60*60);
    int secs = time%60;
    int mins = time/60%60;
    int hours = time/3600%24;
    return e[secs%10] + e[secs/10] +
           e[mins%10] + e[mins/10] +
           e[hours%10] + e[hours/10];
}

int main(){
    int n;
    cin >> n;

    int ans = 0;
    for(int a = 0; a < 24*60*60; a++){
        int sum = 0;
        for(int b = a; b < 24*60*60; b++){
            sum += energy(b);
            if(sum == n) ans++;
            if(sum > n) break;
        }
    }

    cout << ans << "\n";
}
