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

int main(){

	lli h,n;
	cin>>h>>n;
	vector<lli> a(n);
	vector<lli> cum(n+1, 0);
	for(lli i = 0 ; i < n ; i++){
		cin>>a[i];
		cum[i+1] = cum[i]+a[i];
	}

	// for(auto i:cum){
	// 	cout<<i<<' ';
	// }
	// cout<<'\n';
	
	if(cum[n] == 0){
		for(int i = 1 ; i < n+1 ; i++){
			if(h+cum[i] <= 0){
				cout<<i;
				return 0;
			}
		}
		cout<<-1;
		return 0;
	}
	if(cum[n]>0){
		if(h+*min_element(cum.begin(), cum.end())>0){
			cout<<-1;
			return 0;
		}
	}
	lli ans = LLONG_MAX;
	for(lli i = 0 ; i < n ; i++){
		lli s = ceil(-1*((1.0*(h+cum[i+1]))/cum[n]));
		s = max(0LL, s);
		lli ss = s*n + i+1;
		// trace2(s, ss);
		ans = min(ans, ss);
	}
	if(ans <= 0){
		cout<<"-1";
	}
	else{
		cout<<ans;
	}


	return 0;
}