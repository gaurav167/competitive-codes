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

	int q;
	cin>>q;
	int left = 0, right = 0;
	int ctr = 0;
	map<int,pair<char,pair<int,int>>> a;
	while(q--){
		char c;
		int id;
		cin>>c>>id;
		if(c=='L'){
			// if(ctr==1){
			// 	if(a[0].ff=='L'){
			// 		a[id] = mp(c, mp(0,1));
			// 	}
			// }
			a[id] = mp(c, mp(left, right));
			ctr++;
			left++;
			// trace3(ctr, left, right);
		}
		else if(c=='R'){
			a[id] = mp(c, mp(left, right));
			ctr++;
			right++;
			// trace3(ctr, left, right);
		}
		else{
			int l,r;
			// trace2(left, right);
			// trace2(a[id].ss.ff, a[id].ss.ss);
			if(a[id].ff == 'L'){
				l = left - a[id].ss.ff - 1;
				r = ctr - 1 - l;
			}
			else{
				r = right - a[id].ss.ss - 1;
				l = ctr - 1 - r;
			}
			// trace2(l,r);
			cout<<min(l,r)<<'\n';
		}
	}


	return 0;
}