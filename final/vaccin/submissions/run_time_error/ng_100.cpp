#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int k,n;
vl done;

int solve(int x){
    int l = 0;
    int r = k;
    while(l < r-1){
        int mid = (l+r)/2;
        if(x < done[mid]){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    assert(x < done.back());
    return r;
}

int main() {
    cin >> k >> n;
    done.push_back(0);
    rep(c1,0,k){
        int a;
        cin >> a;
        done.push_back(a+done.back());
    }
    rep(c1,0,n){
        int a;
        cin >> a;
        cout << solve(a) << "\n";
    }
    return 0;
}
