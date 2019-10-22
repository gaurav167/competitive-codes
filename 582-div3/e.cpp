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


	// Disjoint Set DataStructure
	map< ll,ll > parent; 		// reserve space for map if n > 10000
	map<ll, ll> sz;

	ll find(ll x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}

	ll merge(ll x, ll y)
	{
		ll xroot = find(x);
		ll yroot = find(y);

			parent[xroot] = yroot ;
			ll ans = sz[xroot]*sz[yroot];
		sz[yroot] = sz[xroot] + sz[yroot];

		return ans;

	}

int main(){

	lli n,m;
	cin>>n>>m;
	for(lli i = 0 ; i < n ; i++){
		parent[i] = i;
		sz[i] = 1;
	}

	vector<pair<lli , pii>> e;
	for(lli i = 0 ; i < n-1 ; i++){
		lli u,v,w;
		cin>>u>>v>>w;
		e.pb(mp(w, mp(u-1, v-1)));
	}
	sort(e.begin(), e.end());
	vector<lli> mm(m);
	for(lli i = 0 ; i < m ; i++) cin>>mm[i];

	lli j = 0;
	vector<lli> w(*max_element(mm.begin(), mm.end()) + 10, 0);
	ll cc = 0;
	for(lli i = 1 ; i < w.size() ; i++){
		while(j < e.size() && e[j].ff == i){
			// trace3(e[j].ss.ff, e[j].ss.ss, e[j].ff);
			cc += merge(e[j].ss.ff, e[j].ss.ss);
			// trace1(cc);
			j++;
		}
		w[i] = cc;
		// trace2(i, w[i]);
	}
	for(lli i = 0 ; i < m ; i++){
		// trace3(i, mm[i], w[mm[i]]);
		cout<<w[mm[i]]<<' ';
	}



	return 0;
}