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


lli cc(lli a, lli b){
	lli ans = 0;
	while(a!=0 && b!=0){
		while(a>b){
			a>>=1;
			ans++;
		}
		while(a<b){
			b>>=1;
			ans++;
		}
		if(a==b) break;
	}
	return ans;
}
	map<int, vector<int>> m;

	void insert(int a){
		int c = 0;
		while(a){
			m[a].pb(c);
			a>>=1;
			c++;
		}
	}
int main(){
	lli n, k;
	cin>>n>>k;
	vector<lli> a(n);
	for(lli i = 0 ; i < n ; i++) cin>>a[i];

	for(int i = 0 ; i < n ; i++){
		insert(a[i]);
	}

	for(auto &i:m)
	{
		sort(i.ss.begin(), i.ss.end());
	}
	int ans = INT_MAX;
	for(auto &i:m){
		int aa = 0;
		// tracev(i.ss);
		if(i.ss.size() >= k){
			for(int j = 0 ; j < k ; j++){
				aa += i.ss[j];
			}
			ans= min(ans, aa);
		}
	}
	cout<<ans;
	// vector<vector<lli>> s(n, vector<lli> (n, 0));
	// for(lli i = 0 ; i < n ; i++){
	// 	for(lli j = i+1 ; j < n ; j++){
	// 		s[i][j] = cc(a[i], a[j]);
	// 	}
	// }
	// for(lli i = 0 ; i < n ; i++)
	// 	sort(s[i].begin(), s[i].end());

	// // tracevv(s);
	// lli ans = INT_MAX;
	// for(lli i = 0 ; i < n-k+1 ; i++){
	// 	lli aa = 0;
	// 	for(lli j = i+1; j < i+k ; j++){
	// 		aa += s[i][j];
	// 	}
	// 	ans = min(ans, aa);
	// }

	// cout<<ans;
	return 0;
}