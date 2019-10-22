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

lli n,k;
std::vector<pair<lli,lli>> a;
bool cmp(lli nn, pair<lli, lli> const& p){
    return (p.ff > nn);
}
vector<lli> dp;
lli solve(lli st, lli kk){
	// trace1(st);
	if(st>=n) return 0;
	if(kk>=k) return 0;
	// trace1(dp[st]);
	if(dp[st] == -1){
		dp[st] = max(solve(st+1, kk), (a[st].ss-st) + solve(a[st].ss, kk+1));
	}
	// trace1(dp[st]);
	return dp[st];
}
int main(){

	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cin>>n>>k;
	dp.resize(n, -1);
	a.resize(n+1);
	for(lli i = 0 ; i < n ; i++){
		cin>>a[i].ff;
		a[i].ss = LLONG_MAX;
	}
	sort(a.begin(), a.end());
	a.pb(mp(LLONG_MAX, LLONG_MAX));
	for(lli i = 0 ; i < n ; i++){
		lli tf = a[i].ff+5;
		for(lli j = i+1 ; j < n+1 ; j++){
			if(a[j].ff > tf){
				a[i].ss = j;
				break;
			}
		}
	}
	// for(lli i = 0 ; i < n ; i++){
	// 	// trace1(a[i].ff);
	// 	auto j = upper_bound(a.begin(), a.end(), a[i].ff+5, cmp);
	// 	// trace3((*j).ff, (*j).ss,(j-a.begin()));
	// 	a[i].ss = (j-a.begin());
	// }
	// for(auto i:a){
	// 	trace2(i.ff, i.ss);
	// }
	cout<<solve(0, 0);
	return 0;
}