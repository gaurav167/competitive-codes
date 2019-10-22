#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> plli;
typedef vector<lli> vi;
typedef vector<vi> vvi;
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
vector<vector<int>> g;
vector<bool> visited;
vector<lli> a;
lli cnt = 0;
int bb=0, rr=0;

// vector<pair<lli,lli>> ans;
pair<int,int> dfs(int st){
	// trace1(st);
	if(visited[st]) return {0,0};
	visited[st] = true;
	pair<int,int> aa = {0,0};
	for(int i = 0 ; i < g[st].size() ; i++){
		// trace2(i, g[st][i]);
		pair<int,int> q = dfs(g[st][i]);
		aa.ff += q.ff;
		aa.ss += q.ss;
		if((q.ff == bb && q.ss == 0) || (q.ff == 0 && q.ss == rr)) cnt++;
		// trace1(cnt);
	}
	if(a[st] == 1) aa.ss++;
	else if(a[st] == 2) aa.ff++;
	// ans[st] = aa;
	return aa;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	a.resize(n);
	visited.resize(n, false);
	// ans.resize(n);
	g.resize(n);
	for(int i = 0 ; i < n ; cin>>a[i], i++);
	for(auto &i:a){
		if(i==2) bb++;
		if(i==1) rr++;
	}
	// trace2(bb,rr);
	for(int i = 0 ; i < n-1 ; i++){
		int u,v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	pair<int,int> q = dfs(0);
	// for(auto &q:ans){
	// 	// trace2(q.ff ,q.ss);
	// 	if((q.ff == bb && q.ss == 0) || (q.ff == 0 && q.ss == rr)) cnt++;
	// 	// trace1(cnt);
	// }
	cout<<cnt;
	return 0;
}