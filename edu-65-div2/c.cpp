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
	unordered_map< ll,ll > parent; 		// reserve space for map if n > 10000
	unordered_map< ll,ll > urank;

	void create(ll x)
	{
		parent[x] = x ;
		urank[x] = 1 ; 		// rank = no. of nodes in its subtree
	}

	ll find(ll x)
	{
		if( parent[x] != x )	//path compression
		{
			parent[x] = find(parent[x]) ;
		}
		return parent[x];
	}

	void merge(ll x, ll y)
	{
		ll xroot = find(x);
		ll yroot = find(y);
		if(xroot != yroot){
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
	}

int main(){
	fio;
	lli n,m;
	cin>>n>>m;
	for(lli i = 0 ; i < n ; i++){
		create(i);
	}
	for(lli i = 0 ; i < m ; i++){
		lli k;
		cin>>k;
		if(k>0){
			lli s;
			cin>>s;
			s--;
			for(lli j = 0 ; j < k-1 ; j++){
				lli q;
				cin>>q;
				q--;
				merge(s,q);
			}
		}
	}
	for(lli i = 0 ; i < n ; i++){
		// trace2(i, parent[i]);
		cout<<urank[find(i)]<<' ';
	}


	return 0;
}