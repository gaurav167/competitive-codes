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
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<lli, lli> > vplli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define PI 3.141592653589793
#define mod (lli)(998244353)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
template<typename T> void tracev(vector<T> &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }

int main(){

	int n;
	cin>>n;
	vector<int> fact(n+10, 1);
	for(int i = 2 ; i < n+10 ; i++){
		fact[i] = ((fact[i-1])%mod*i)%mod;
	}
	map<int, int> a,b;
	map<pii, int> c;
	for(int i = 0 ; i < n ; i++){
		int u,v;
		cin>>u>>v;
		if(a.find(u) == a.end()) a[u] = 1;
		else a[u] ++;
		if(b.find(v) == b.end()) b[v] = 1;
		else b[v] ++;
		if(c.find(mp(u, v)) == c.end()) c[mp(u, v)] = 1;
		else c[mp(u, v)] ++;
	}
	lli ans = fact[n];
	lli ans1 = 1, ans2 = 1, ans3  =1; 
	for(auto &i: a){
		ans1 = (ans1%mod * (fact[i.ss]))%mod;
	}
	ans = (ans - ans1 + mod)%mod;
	for(auto &i: b){
		ans2 = (ans2%mod * (fact[i.ss]))%mod;
	}
	ans = (ans - ans2 + mod)%mod;
	int prev = -1;
	bool f = true;
	for(auto &i: c){
		if (i.ff.ss < prev){
			f = false;
			break;
		}
		prev = i.ff.ss;
	}
	if(f){
		for(auto &i: c){
			ans3 = (ans3%mod * (fact[i.ss]))%mod;
		}
		ans = (ans + ans3)%mod;
	}

	cout<<ans;


	return 0;
}