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
#define mod (lli)(998244353)

template<typename T> T gcd(T a, T b) { if (a == 0) return b; return gcd(b % a, a); }
template<typename T> T pow(T a, T b, lli m) {T ans = 1; while (b > 0) { if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m; b /= 2; a = ((a % m) * (a % m)) % m; } return ans % m; }

int main(){

	lli n;
	cin>>n;
	map<lli, pair<lli,lli>> m;
	for(lli i = 0 ; i < n ; i++){
		lli k;
		cin>>k;
		if(m.find(k)==m.end()){
			m[k] = mp(i,-1);
		}
		else{
			m[k].ss = i;
		}
	}
	vector<lli> a(n,-1);
	for(auto i = m.begin() ; i!=m.end() ; i++){
		// trace3(i->ff, i->ss.ff, i->ss.ss);
		a[i->ss.ff] = i->ff;
		if(i->ss.ss!=-1){
			a[i->ss.ss] = i->ff;
		}
	}
	set<lli> s1;
	lli cnt=0;
	for(lli i = 0 ; i < n ; i++){
		if(a[i]!=-1){
			if(m.find(a[i])->ss.ss == -1){
				if(s1.size()==0) cnt++;
			}
			else{
				auto q = s1.find(a[i]);
				if(q==s1.end()){
					s1.insert(a[i]);
				}
				else{
					s1.erase(q);
					if(s1.size()==0){
						cnt++;
					}
				}
				
			}
		}
	}
	cout<<pow(lli(2),cnt-1,mod);


	return 0;
}