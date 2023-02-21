#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <numeric>
#include <random>
#include <time.h>
#include <stack>
#include <chrono>

using namespace std;

#define ll long long
#define p2 pair<ll, ll>
#define p3 tuple<ll, ll, ll>
#define vi vector<ll>
#define inf 1e9

#define read(a) cin >> a
#define write(a) cout << (a) << endl

#define readpush(type,a) type temp; read(temp); a.push_back(temp)
#define readinsert(type,a) type temp; read(temp); a.insert(temp)
#define setcontains(set, x) (set.find(x) != set.end())
#define all(a) begin(a),end(a)

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (ll i = high; i >= 0; i--)

#define ceildiv(x,y) ((x + y - 1) / y)


inline void fast()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void subtract()
{

}

int main()
{
    fast();

    ll n;
    ll m;
    read(n);
    read(m);

    vector<string> lock;

    rep(i, n)
    {
        string row;
        read(row);
        lock.push_back(row);
    }

    vector<vector<set<ll>>> opening(m, vector<set<ll>>(n, set<ll>()));

    rep(i, m)
    {
        rep(j, n)
        {
            string s = lock[j];

            rep(k, m)
            {
                if (s[i] == '.')
                {
                    opening[i][j].insert(k);
                }
                std::rotate(s.begin(), s.begin() + 1, s.end());
            }

        }
    }

    ll unionSum = 0;


    vector<vector<vector<ll>>> unions;
    rep(firstHole, m)
    {
        for (ll secondHole = firstHole + 1; secondHole < m; secondHole++)
        {
            ll holeProduct = 1;
            vector<vector<ll>> unionSet;
            rep(row, n)
            {
                vector<ll> rowUnion;
                set_intersection(opening[firstHole][row].begin(), opening[firstHole][row].end(), opening[secondHole][row].begin(), opening[secondHole][row].end(), back_inserter(rowUnion));
                holeProduct *= rowUnion.size();
                unionSet.push_back(rowUnion);
            }
            unions.push_back(unionSet);
            unionSum += holeProduct;
        }
    }

    ll unionIntersectionSum = 0;
    vector<vector<vector<ll>>> unionUnions;

    rep(firstHole, unions.size())
    {
        for (ll secondHole = firstHole + 1; secondHole < unions.size(); secondHole++)
        {
            ll holeProduct = 1;
            vector<vector<ll>> unionSet;
            rep(row, n)
            {
                vector<ll> rowUnion;
                set_intersection(unions[firstHole][row].begin(), unions[firstHole][row].end(), unions[secondHole][row].begin(), unions[secondHole][row].end(), back_inserter(rowUnion));
                holeProduct *= rowUnion.size();
                unionSet.push_back(rowUnion);
            }
            unionUnions.push_back(unionSet);
            unionIntersectionSum += holeProduct;
        }
    }


    ll nSum = 0;
    rep(i, m)
    {
        ll prod = 1;
        rep(j, n)
        {
            prod *= opening[i][j].size();
        }
        nSum += prod;
    }

    ll ans = nSum - (unionSum - unionIntersectionSum);
    if (unionIntersectionSum > 0)
    {
        auto Start = std::chrono::high_resolution_clock::now();
        ll sub = 0;

        while (true)
        {
            vector<vector<vector<ll>>> temp;
            rep(firstHole, unionUnions.size())
            {
                for (ll secondHole = firstHole + 1; secondHole < unions.size(); secondHole++)
                {
                    ll holeProduct = 1;
                    vector<vector<ll>> unionSet;
                    rep(row, n)
                    {
                        vector<ll> rowUnion;
                        set_intersection(unionUnions[firstHole][row].begin(), unionUnions[firstHole][row].end(), unionUnions[secondHole][row].begin(), unionUnions[secondHole][row].end(), back_inserter(rowUnion));
                        holeProduct *= rowUnion.size();
                        unionSet.push_back(rowUnion);
                    }
                    temp.push_back(unionSet);
                    sub += holeProduct;
                }
            }

            unionUnions = temp;
            auto End = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> Elapsed = End - Start;
            if (Elapsed.count() >= 900.0)
                break;
        }
        ans -= sub;
    }
    write(ans);

    return 0;
}