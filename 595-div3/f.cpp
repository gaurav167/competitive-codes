#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cout<<#x<<": "<<x<<endl;
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
typedef lli ll;
typedef long double ld;
typedef pair<lli, lli> pii;
typedef pair<lli, lli> plli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef vector<pair<lli, lli> > vpii;
typedef vector<pair<lli, lli> > vplli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define mod (lli)(1000*1000*1000+7)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
template<typename T> void tracev(vector<T> &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }

vvi g;
vi a;
	lli n,k;
vector<vector<vector<lli>>> dp;
lli dfs(lli st, lli par, lli depth){
	lli res = 0;
	if(depth == 0) res += a[st];
	for(lli i = 0 ; i < g[st].size() ; i++){
		if(g[st][i] != par){
			res += dp[st][g[st][i]][(depth+1)%k];
			// if((depth+1)%k == 0) res += a[g[st][i]];
		}
	}
	return res;
}
lli create(lli st, lli par, lli depth){
	lli res = 0;
	if(depth == 0) res += a[st];
	// trace4(par, st, depth, res);
	for(lli i = 0 ; i < g[st].size() ; i++){
		if(g[st][i] != par && dp[st][g[st][i]][(depth+1)%k] == -1){
			lli aa = create(g[st][i], st, (depth+1)%k);
			lli bb = -1;
			if(depth == 0) bb = create(g[st][i], st, 0) - a[st];
			if(aa <= -1) aa = 0;
			dp[st][g[st][i]][(depth+1)%k] = max(aa, bb);
			// dp[g[st][i]][st][(depth+1)%k] = aa;
			// trace5(st, g[st][i], (depth+1)%k, aa, bb);
		}
		if(g[st][i] != par) res += dp[st][g[st][i]][(depth+1)%k];
		// trace6(par, st, depth, res, g[st][i], dp[st][g[st][i]][(depth+1)%k]);
	}
	return res;
}

int main(){

	cin>>n>>k;
	k++;
	a.resize(n);
	g.resize(n);
	dp.resize(n, vector<vector<lli>>(n, vlli(k, -1)));
	for(lli i = 0 ; i < n ; i++) cin>>a[i];
	for(lli i = 0 ; i < n-1; i++){
		lli u,v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	for(int i = 0 ; i < n ; i++){
		lli aa = create(i, -1, 0);
	}
	// for(auto &i:dp){
	// 	for(auto &j:i){
	// 		tracev(j);
	// 	}
	// 	cout<<'\n';
	// }
	lli ans = 0;
	for(lli i = 0 ; i < n ; i++){
		ans = max(ans, dfs(i, -1, 0));
	}
	cout<<ans;


	return 0;
}