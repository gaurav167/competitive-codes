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

	lli n;
	cin>>n;
	set<pair<pair<pair<lli,lli>, lli>, lli>> a;
	for(lli i = 0 ; i < n ; i++){
		lli q,w,e;
		cin>>q>>w>>e;
		a.insert(mp(mp(mp(q,w),e), i+1));
		// cin>>a[i].ff.ff.ff>>a[i].ff.ff.ss>>a[i].ff.ss;
		// a[i].ss = i+1;
	}
	// sort(a.begin(), a.end());
	// for(auto &i : a){
	// 	trace3(i.ff.ff, i.ff.ss, i.ss);
	// }
	// for(auto &i:a){
	// 	trace4(i.ff.ff.ff, i.ff.ff.ss, i.ff.ss, i.ss);
	// }
	// cout<<'\n';
	vpii ans;
	auto ii = a.begin();
	while(a.size() > 0 && ii != a.end()){
		auto jj = ii;
		jj++;
		if(jj == a.end()) break;
		if((*ii).ff.ff.ff == (*jj).ff.ff.ff){
			if((*ii).ff.ff.ss == (*jj).ff.ff.ss){
				ans.pb(mp((*ii).ss, (*jj).ss));
				auto ij = ii;
				ii = jj;
				ii++;
				a.erase(ij);
				a.erase(jj);
			}
			else{
				ii++;
			}
		}
		else{
			ii++;
		}
	}
	// for(auto &i:a){
	// 	trace4(i.ff.ff.ff, i.ff.ff.ss, i.ff.ss, i.ss);
	// }
	// cout<<'\n';
	ii = a.begin();
	while(a.size() > 0 && ii != a.end()){
		auto jj = ii;
		jj++;
		if(jj == a.end()) break;
		if((*ii).ff.ff.ff == (*jj).ff.ff.ff){
			ans.pb(mp((*ii).ss, (*jj).ss));
			auto ij = ii;
			ii = jj;
			ii++;
			a.erase(ij);
			a.erase(jj);
		}
		else{
			ii++;
		}
	}
	// for(auto &i:a){
	// 	trace4(i.ff.ff.ff, i.ff.ff.ss, i.ff.ss, i.ss);
	// }
	if(a.size() > 0){
		ii = a.begin();
		while(ii != a.end()){
			auto jj = ii;
			jj++;
			if(jj == a.end()) break;
			ans.pb(mp((*ii).ss, (*jj).ss));
			auto ij = ii;
			ii = jj;
			ii++;
			a.erase(ij);
			a.erase(jj);
		}
	}
	for(auto &i:ans){
		cout<<i.ff<<' '<<i.ss<<'\n';
	}
	// for(lli i = 0 ; i < n - 1 ; i++){
	// 	if(a[i].ff.ff.ff == a[i+1].ff.ff.ff){
	// 		if(a[i].ff.ff.ss == a[i+1].ff.ff.ss){
	// 			ans.pb(mp(a[i].ss, a[i+1].ss));
	// 		}

	// 	}
	// }

	return 0;
}