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

	int n;
	cin>>n;
	string l,r;
	cin>>l>>r;
	// map<char, vector<int>> m1, m2;
	vector<set<int>> a(27);
	for(int i = 0 ; i < n ; i++){
		// m1[l[i]].pb(i);
		// m2[r[i]].pb(i);
		if(r[i] == '?'){
			a[26].insert(i);
		}
		else{
			a[r[i]-'a'].insert(i);
		}
	}
	vector<pair<int,int>> ans;
	vector<pair<char, int>> extra1, extra2;
	for(int i = 0 ; i < n ; i++){
		if(l[i]!='?' && a[l[i]-'a'].size()!=0){
			ans.pb(mp(i, *a[l[i]-'a'].begin()));
			a[l[i]-'a'].erase(a[l[i]-'a'].begin());
		}
		else{
			if(l[i] == '?') extra1.pb(mp(l[i], i));
			else extra2.pb(mp(l[i], i));
		}
	}
	int ii = 0;
	while(ii < extra2.size() && a[26].size()>0){
		ans.pb(mp(extra2[ii++].ss, *a[26].begin()));
		a[26].erase(a[26].begin());
	}
	int jj = 0;
	for(int i = 0 ; i < 27 ; i++){
		// if(jj == extra1.size()) break;
		while(jj < extra1.size() && a[i].size()>0){
			ans.pb(mp(extra1[jj++].ss, *a[i].begin()));
			a[i].erase(a[i].begin());
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans){
		cout<<i.ff+1<<' '<<i.ss+1<<'\n';
	}



	return 0;
}