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

	lli n, m;
	cin>>n>>m;
	map<lli,vector<lli>> mm;
	for(lli i = 0 ; i < n ; i++){
		lli q,w;
		cin>>q>>w;
		mm[q].pb(w);
	}
	lli ss = 0;
	for(auto i = mm.begin() ; i!=mm.end() ; i++){
		sort((i->ss).begin(), (i->ss).end(), greater<lli>());
		if((i->ss).size() > ss){
			ss = (i->ss).size();
		}
	}

	vector<lli> a(ss,0);
	for(auto i = mm.begin() ; i!=mm.end() ; i++){
		lli cnt = 0, sum = 0;
		for(auto j = (i->ss).begin() ; j!=(i->ss).end() ; j++, cnt++){
			sum+=(*j);
			if(sum>0){
				a[cnt] += sum;
			}
			else{
				break;
			}
		}
	}
	// for(lli i = 0 ; i < a.size() ; i++){
	// 	cout<<a[i]<<' ';
	// }
	// cout<<'\n';
	lli ans = 0;
	for(lli i = 0; i < a.size() ; i++){
		if(a[i] > ans){
			ans = a[i];
		}
	}
	cout<<ans;


	return 0;
}