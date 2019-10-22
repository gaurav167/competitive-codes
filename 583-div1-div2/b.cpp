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
vector<map<pii, lli>> dp;
	lli b,g,n;


lli slv(lli bb, lli gg, lli st){
	trace3(bb ,gg, st);
	if(st > n){
		if( bb<=0&&gg<=0) return 0;
		else return INT_MAX;
	}

	if(dp[st].find(mp(bb, gg)) == dp[st].end()){
		lli ans = min(slv(bb, gg, st+1), 1+slv(bb-st, gg-(n-st), st+1));
		dp[st].insert(mp(mp(bb, gg), ans));
	}
	return dp[st].find(mp(bb, gg))->ss;
}


// lli solve(lli bb, lli gg, lli st){
// 	trace3(bb, gg, st);
// 	if(st > n){
// 		trace4(st, n, bb, gg);
// 		if(bb <=0 && gg<=0) return 0;
// 		else return INT_MAX;
// 	}
// 	if(dp[st].find(mp(bb, gg))!= dp[st].end()) return dp[st][mp(bb, gg)];
// 	// trace1(solve(bb, gg, st+1));
// 	// trace1((1+solve(bb-st, gg-(n-st), st+1)));
// 	lli ans = min(solve(bb, gg, st+1), 1+solve(bb - st, gg - (n-st), st+1));
// 	dp[st][mp(bb, gg)] = ans;
// 	trace2(st, dp[st][mp(bb, gg)]);
// 	return dp[st][mp(bb, gg)];
// }


int main(){

	cin>>b>>g>>n;
	dp.resize(n+2);
	cout<<slv(b, g, 0);


	return 0;
}