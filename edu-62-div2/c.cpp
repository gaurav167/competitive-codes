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

	lli n,k;
	cin>>n>>k;
	vector<pair<lli,lli>> a(n);
	for(lli i = 0 ; i < n ; i++){
		cin>>a[i].ss>>a[i].ff;
	}
	sort(a.begin(), a.end(), greater<pair<lli,lli>>());
	vector<lli> cum(n+1, 0);
	lli mn = LLONG_MAX;
		priority_queue < ll, std::vector<ll>, std::greater<ll> > mnheap;	// mnheap.push(), mnheap.top(), mnheap.pop()
	for(lli i = 0 ; i < k ; i++){
		cum[i+1] = cum[i]+a[i].ss;
		mnheap.push(a[i].ss);
		// mn = min(lli(mn), lli(a[i].ss));
	}
	lli sum = cum[k];
	for(lli i = k ; i < n ; i++){
		cum [i+1] = sum - mnheap.top() + a[i].ss;
		// cum[i+1] = cum[k-1]+a[i].ss;
		if(cum[i+1] > sum){
			sum = cum[i+1];
			mnheap.pop();
			mnheap.push(a[i].ss);
		}
	}
	// tracev(cum);
	// tracevp(a);
	lli ans = 0;
	for(lli i = 0 ; i < n ; i++){
		ans = max(ans, a[i].ff*cum[i+1]);
	}
	cout<<ans;

	return 0;
}