// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

template <class F>
long double score(istream& is, int N,int T, vi t,vi v,vector<vi> a, F fail) {
	int L;
    vi ans;
	if(!(is >> L)) fail("Could not read answer.\n");
    if(L>N || L<0) fail("invalid answer size\n");
    ans.resize(L);
    rep(i,0,L) if(!(is >> ans[i])) fail("Could not read answer.\n");

	assert_done(is, fail);

    vector<bool> proven(N);
    ll timesum = 0;
    ll score = 0;
    rep(i,0,L) {
        if(ans[i]<0 || ans[i]>=N)
		    fail("Invalid theorem index\n");
        if(proven[ans[i]])
		    fail("Trying to prove same theorem twice\n");
        trav(ai,a[ans[i]])
            if(!proven[ai]){
                fail("Theorem proven without prerequisites\n");
            }
         
        timesum += t[ans[i]];
        score += v[ans[i]];
        proven[ans[i]] = true;
    }
	if(timesum>T){
		fail("Spent more than T time proving\n");
	}
	return score;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int C;
    fin >> C;

    int N,T;
    fin >> N>>T;

    vi t(N);
    vi v(N);
    vector<vi> a(N);

	rep(i,0,N){
        int k;
        fin >> t[i]>>v[i]>>k;
        a[i].resize(k);
        rep(j,0,k) fin>>a[i][j];
    }

    assert_done(fin, die);
    fin.close();

	ifstream fans(answer_file);

    try {
		long double sc = score(cin, N,T,t,v,a, die);
		long double bestsc = score(fans, N,T,t,v,a, judge_error);
		long double ratio = sc / bestsc;
		if (C == 0) accept(0);
		else accept(10.0 * ratio*ratio*ratio);
    } catch(...) {
        die("IO failure");
    }
}
