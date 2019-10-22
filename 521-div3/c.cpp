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

bool comp(const pair<int,int> &a, const pair<int,int> &b){
	return a.ff<b.ff;
}
int main(){

	int n;
	cin>>n;
	lli sum = 0;
	vector<pair<int,int>> b(n);
	for(int i = 0 ; i < n ; i++){
		cin>>b[i].ff;
		b[i].ss = i;
		sum += b[i].ff;
	}
	sort(b.begin(), b.end(), greater<pair<int,int>>());
	int m = b[0].ff;
	int mm = b[1].ff;
	vector<int> ans;
	sum -= m;
	if((sum - mm) == mm){
		ans.pb(b[0].ss+1);
	}
	for(int i = 1 ; i < n ; i++){
		if(sum - b[i].ff == m){
			ans.pb(b[i].ss+1);
		}
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		cout<<i<<' ';
	}

	return 0;
}