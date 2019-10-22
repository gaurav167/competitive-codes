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
typedef vector<int> vi;
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

	// Disjoint Set DataStructure
	map< lli,lli > parent; 		// reserve space for map if n > 10000
	map< lli,lli > urank;

	void create(lli x)
	{
		parent[x] = x ;
		urank[x] = 0 ; 		// rank = no. of nodes in its subtree
	}

	lli find(lli x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}

	void merge(lli x, lli y)
	{
		lli xroot = find(x);
		lli yroot = find(y);

		if( urank[xroot] <= urank[yroot] )	// Union by rank
		{
			parent[xroot] = yroot ;
			urank[yroot] = urank[yroot] + urank[xroot] ;
		}
		else
		{
			parent[yroot] = xroot;
			urank[xroot] = urank[xroot] + urank[yroot] ;
		}
	}


std::vector<vector<int>> g;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	g.resize(n);
	for(int i = 0 ; i < m ; i++){
		int u,v;
		cin>>u>>v;
		g[u-1].pb(v-1);
		g[v-1].pb(u-1);
	}
	int ii = 0;
	int jj = 0;
	for(int i = 0 ; i < n ; i++){
		if(g[i].size() > ii){
			ii = g[i].size();
			jj = i;
		}
	}
	for(int i = 0 ; i < n ; i++){
		create(i);
	}
	vector<pair<int,int>> ans;
	for(int i = 0 ; i < ii ; i++){
		ans.pb(mp(jj, g[jj][i]));
		merge(jj, g[jj][i]);
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < g[i].size() ; j++){
			int a = find(i);
			int b = find(g[i][j]);
			if(a!=b){
				ans.pb(mp(i, g[i][j]));
				merge(i,g[i][j]);
			}
		}
	}
	for(int i = 0 ; i < ans.size() ; i++){
		cout<<ans[i].ff+1<<' '<<ans[i].ss+1<<'\n';
	}


	return 0;
}