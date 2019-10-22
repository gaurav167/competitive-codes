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



lli solve(int n){
	if(n<2) return INT_MAX;
	if(n >= 2 && n<= 7) return 1;
	// trace1(n);
	// trace1(n-2);
	lli a7 = solve(n-7)+1;
	lli a6 = solve(n-6)+1;
	lli a5 = solve(n-5)+1;
	lli a4 = solve(n-4)+1;
	lli a3 = solve(n-3)+1;
	lli a2 = solve(n-2)+1;
	trace2(n-2, a2);
	// trace1(n-3);
	trace2(n-3, a3);
	// trace1(n-4);
	trace2(n-4, a4);
	// trace1(n-5);
	trace2(n-5, a5);
	// trace1(n-6);
	trace2(n-6, a6);
	// trace1(n-7);
	trace2(n-7, a7);
	return min({a2,a3,a4,a5,a6,a7});
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f = solve(n);
		cout<<f<<'\n';
	}


	return 0;
}