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


int main(){
	lli n,m;
	cin>>n>>m;
	vector<lli> x(m);
	for(lli i = 0 ; i < m ; i++) cin>>x[i];

	vector<lli> ans(n+2, 0);

	for(lli i = 0 ; i  <m-1; i ++){
		lli dist = abs(x[i] - x[i+1]);
		lli d1,d2;
		if(x[i+1] > x[i]){
			d1 = x[i+1]-1;
		}
		else if(x[i+1] < x[i]){
			d1 = x[i+1];
		}
		else{
			d1 = 0;
		}

		if(x[i] > x[i+1]){
			d2 = x[i]-1;
		}
		else if(x[i]<x[i+1]){
			d2 = x[i];
		}
		else{
			d2=0;
		}

		lli d3 = dist-1;

		// trace6(x[i], x[i+1], d1,d2,d3, dist);
		ans[x[i]] += d1;
		ans[x[i]+1] -= d1;
		// tracev(ans);
		ans[x[i+1]] += d2;
		ans[x[i+1]+1] -= d2;
		// tracev(ans);
		if(d3>0){
			ans[min(x[i], x[i+1])+1] += d3;
			ans[max(x[i], x[i+1])] -= d3;

		}
		// tracev(ans);
		if(x[i]!=1 && x[i+1]!=1){
			ans[1] += dist;
			ans[min(x[i], x[i+1])] -= dist;
		}

		if(x[i]!=n && x[i+1]!=n){
			ans[max(x[i], x[i+1])+1] += dist;
			ans[n+1] -= dist;
		}
		// tracev(ans);

	}
	for(lli i = 1 ; i < ans.size()-1 ; i++){
		ans[i] += ans[i-1];
		cout<<ans[i]<<' ';
	}
	// tracev(ans);
	// query(0, n);
	// for(lli i = 0 ; i < n ; i++){
	// 	cout<<t[i+n]<<' ';
	// }

	return 0;
}