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
    int a = 0;
    int b = -1;
    int sum = 0;
    while(true){
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

    cout << ans << "\n";
}
