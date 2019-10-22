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

bool comp(vector<lli> &a1, vector<lli> &a2){
	return a1.size() > a2.size();
}
int main(){
	fio;
	int n;
	cin>>n;
	vector<lli> a(n);
	for(int i =0 ; i  < n ; i++) cin>>a[i];
	if(n == 1){
		cout<<"0\n";
		return 0;
	}
	vector<vector<lli>> ans(1);
	ans[0].pb(a[0]);
	for(int i = 1 ; i < n ; i++){
		bool f = false;
		for(int j = 0 ; j < ans.size() ; j++){
			lli g = gcd(a[i], ans[j][0]);
			if(!((a[i]/g)%2==0 || (ans[j][0]/g)%2 == 0)){
				ans[j].pb(a[i]);
				f = true;
			}
		}
		if(!f){
			ans.pb({a[i]});
		}
	}
	sort(ans.begin(), ans.end(), comp);

	cout<<n - ans[0].size()<<'\n';
	for(int i = 1 ; i < ans.size() ; i++){
		for(int j = 0 ; j < ans[i].size() ; j++){
			cout<<ans[i][j]<<'\n';
		}
	}

	return 0;
}