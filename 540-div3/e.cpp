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

int main(){

	int n,k;
	cin>>n>>k;
	if(k*(k-1) < n){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		vector<vector<int>> a(k);
		int c = 0;
		for(int i = 1 ; i < k+1 ; i++){
			// vector<int> q;
			// a.pb(q);
			for(int j = 1 ; j < k+1 ; j++){
				if(c == n) break;
				if(i!=j) a[i-1].pb(j-1);
			}
		}
		// for(auto i:a){
		// 	for(auto j:i){
		// 		cout<<j<<' ';
		// 	}
		// 	cout<<'\n';
		// }
		int cur = 0;
		int pos = 0;
		if(n==1){
			cout<<"1 1\n";
		}
		else{
			vector<pair<int,int>> ans, qq;
			int cc = 0;
			int kk = k;
			if(k&1) kk--;
			for(int i = 0 ; i < kk ;i+=2){
				for(int j = 0 ; j < k ; j++){
					if(cc == n) break;
					cc+=2;
					ans.pb(mp(i+1, a[i][j]+1));
					ans.pb(mp(i+2, a[i+1][j]+1));
					// cout<<i+1<<' '<<a[i][j]+1<<'\n';
					// cout<<i+2<<' '<<a[i+1][j]+1<<'\n';
				}
			}
			if(k&1){
				for(int j = 0 ; j < k ; j++){
					qq.pb(mp(k, j+1));
				}
			}
			int ccc = 0;
			for(int i = 0 ; i < ans.size() ; i+=4){
				cout<<ans[i]
			}
			// for(int i = 0 ; i < n ; i+=2){
			// 	cout<<cur+1<<' '<<a[cur][pos]+1<<'\n';
			// 	cout<<cur+2<<' '<<a[cur+1][pos]+1<<'\n';
			// 	pos++;
			// 	if(pos == k){
			// 		cur+=2;
			// 		pos=0;
			// 	}
			// }
			if(n&1){
				cout<<k<<' '<<k-1<<'\n';
			}
		}
	}


	return 0;
}