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
#define mod (lli)(1000*1000*1000+7)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }
template<typename T> void tracev(vector<T> &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }

lli n, h;
set<int> a;
vi aa;
// vi dp;
map<int, int> dp;
int solve(int st){
	if(st >= h) return 0;
	if(st >= (h-2)) return 0;
	if(dp.find(st) == dp.end()){
		dp[st] = INT_MAX;

		auto ii = a.lower_bound(st+1);

		if(ii == a.end()){
			dp[st] = 0;
		}
	
		else if(*ii == st+1){
			dp[st] = min(dp[st], 1 + solve(st+1));
			dp[st] = min(dp[st], solve(st+2) + int(a.find(st+2)==a.end()));
		}

		else if(*ii == st+2){
			dp[st] = min(dp[st], 1 + solve(st+2));
			dp[st] = min(dp[st], solve(st+1));
		}

		else{
			dp[st] = min(dp[st], solve(*ii-1));
			dp[st] = min(dp[st], 1 + solve(*ii));
		}
	}
	// trace2(st, dp[st]);
	return dp[st];
}
int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>h>>n;
		a.clear();
		dp.clear();
		for(int i = 0 ; i < n ; i++){
			int k;
			cin>>k;
			a.insert(h-k);
		}
		cout<<solve(0)<<'\n';
	}


	return 0;
}