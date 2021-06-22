// Problem Link - https://www.codechef.com/problems/CAMC
/* By Milind Mishra */
#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              __emplace_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff              first
#define ss              second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;

void fio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[]) {
    fio();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< pair<ll, int> > v(n);
        loop(i, 0, n - 1) {
            cin >> v[i].ff;
            v[i].ss = i % m;
        }
        int count = m;
        int right = 0;
        ll ans = INT_MAX;
        sort(v.begin(), v.end());
        vector<int> cnt(n, 0);
        for (int left = 0; left < n; left++) {
            while (right < n && count > 0) {
                count -= cnt[v[right].ss] == 0;
                cnt[v[right].ss]++;
                right++;
            }
            if (count == 0) {
                ans = min(ans, v[right - 1].ff - v[left].ff);
            }
            if (cnt[v[left].ss] > 0)
                cnt[v[left].ss]--;
            count += cnt[v[left].ss] == 0;
        }
        cout << ans << "\n";
    }
    return 0;
}