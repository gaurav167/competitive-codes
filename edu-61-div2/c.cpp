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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	lli n,q;
	cin>>n>>q;
	vector<lli> a(n+1, 0);
	vector<pair<lli, lli>> qq(q);
	for(lli i = 0 ; i < q ; i++){
		lli l,r;
		cin>>l>>r;
		a[l-1]++;
		a[r]--;
		qq[i] = mp(l,r);
	}
	sort(qq.begin(), qq.end());
	lli cc = int(a[0]>0);
	lli c = a[0];
	for(lli i = 1 ; i < n ; i++){
		c += a[i];
		a[i] = c;
		if(a[i] != 0){
			cc++;
		}
	}
	// for(auto i:a){
	// 	cout<<i<<' ';
	// }
	// cout<<'\n';
	// trace1(cc);
	vector<lli> aa(n+1, 0), bb(n+1, 0);
	for(lli i =  1 ; i < n+1 ; i++){
		aa[i] = aa[i-1]+lli(a[i-1]==1);
		bb[i] = bb[i-1]+lli(a[i-1]==2);
	}
	// for(lli i = 0 ; i < n+1 ; i++){
	// 	trace3(i, aa[i], bb[i]);
	// }
	lli ans = 0;
	for(lli i = 0 ; i < q ; i++){
		for(lli j = i+1 ; j < q ; j++){
			// trace4(qq[i].ff, qq[i].ss, qq[j].ff, qq[j].ss);
				lli q1 = aa[qq[i].ss] - aa[qq[i].ff-1];
				lli q2 = bb[qq[i].ss] - bb[qq[i].ff-1];
				lli w1 = aa[qq[j].ss] - aa[qq[j].ff-1];
				lli w2 = bb[qq[j].ss] - bb[qq[j].ff-1];
				lli g = q1+w1;
				// trace5(q1,q2,w1,w2,g);
				if(qq[i].ss >= qq[j].ff){
					lli e1 = 0;
					// lli e1 = aa[qq[i].ss] - aa[qq[j].ff-1];
					lli e2 = bb[min(qq[j].ss, qq[i].ss)] - bb[qq[j].ff-1];
					// trace2(e1,e2);
					g = g-e1+e2;
				}
				// trace1(g);
				ans = max(ans, cc-g);
		}
	}
	cout<<ans;



	return 0;
}