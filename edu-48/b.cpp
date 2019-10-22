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

// bool match(string a , string b , i){

// }
int main(){

	int n,m,q;
	cin>>n>>m>>q;
	string a,b;
	cin>>a>>b;
	int lb = b.length(), la = a.length();
	vi dp;
		// vi l(n);
	for(int i = 0 ; i < n ; i++){
		dp.pb(0);
	}
	// for(int i = 0 ; i < n ; i++){
	// 	dp.pb(l);
	// }
	for(int i =lb-1 ; i < n ; i++){
		// for(int j = 0 ; j < n ; j++){
		// 	if(i-j>=lb){

		// 	}
		// }
		int is = a.compare(i-lb+1, lb, b);
		if(is==0){
			dp[i] = 1;
		}
	}
	// for(int i = 0 ; i < n ; i++){
	// 	cout<<dp[i]<<' ';
	// }
	// cout<<'\n';
	for(int i = 0 ; i < q  ; i++){
		int l ,r;
		cin>>l>>r;
		// cout<<"test "<<l-r<<'\n';
		if(r-l<lb-1){
			cout<<"0\n";
		}
		else{
			int cnt=0;
			// cout<<"test "<<lb+l-2<<'\n';
			for(int j = lb+l-2 ; j < r ; j++){
				cnt+=dp[j];
			}
			cout<<cnt<<'\n';
		}
	}

	return 0;
}