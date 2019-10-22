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

bool comp(pair<lli,lli> &a, pair<lli,lli> &b){
	return a.ff<b.ff;
}
int main(){

	lli n,m;
	cin>>n>>m;
	vector<vector<pair<lli,lli>>> g(n); 
	for(lli i = 0 ; i < m ; i++){
		lli q,w,e;
		cin>>q>>w>>e;
		g[q-1].pb(mp(e,w-1));
		g[w-1].pb(mp(e,q-1));
	}
	int ans=0;
	// for(int i = 0 ; i < n ; i++){
	// 	sort(g[i].begin(), g[i].end());
	// }
	umordered_map<int, unordered_map<int,bool>>> mm;
	for(int i = 0 ; i < n ; i++){
		pair<lli,lli> mi = mp(INT_MAX, -1);
		int cnt = 0;
		trace1(i);
		for(int j = 0 ; j < g[i].size() ; j++){
			trace2(g[i][j].ff, g[i][j].ss);
			if(g[i][j].ff == mi.ff) cnt++;
			if(g[i][j].ff < mi.ff){
				cnt = 1;
				mi.ff = g[i][j].ff;
			}
			trace2(cnt, mi.ff);
		}
		ans+=(cnt-1);
	}
	cout<<ans;
	return 0;
}