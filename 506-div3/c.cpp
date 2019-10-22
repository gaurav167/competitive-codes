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

bool comp(const pair<lli,lli> &a, const pair<lli,lli> &b){
	return a.ff<b.ff;
}

bool compp(const pair<lli,lli> &a, const pair<lli,lli> &b){
	return a.ss<b.ss;
}

int main(){
	lli n;
	cin>>n;
	vplli a(n);
	for(lli i = 0 ; i < n ; i++){
		int k,l;
		cin>>k>>l;
		a[i] = mp(k,l);
	}
	sort(a.begin(), a.end(), comp);
	vplli b = a;
	sort(a.begin(), a.end(), compp);
	vplli c = a;

	auto r = c.begin();
	auto l = b.end()-1;
	lli dom = (*r).ss - (*l).ff;
	if(dom<0){
		cout<<"0";
		return 0;
	}

	auto low = lower_bound(b.begin(), b.end(), (*l), comp);
	auto hig = lower_bound(c.begin(), c.end(), (*r), compp);
	// trace2((*low).ff, (*hig).ss);
	if((*low).ff==(*(low+1)).ff){
		if((*hig).ss==(*(hig+1)).ss){
		}
		else{
			if(hig+1!=c.end()){
				dom+=(*(hig+1)).ss-(*hig).ss;
				// trace2((*hig).ss,(*(hig+1)).ss);
			}
		}
	}
	else{
		if((*hig).ss==(*(hig+1)).ss){
			if(low != b.begin())
				dom+=(*low).ff-(*(low-1)).ff;
				// trace2((*low).ff,(*(low+1)).ff);
		}
		else{
			lli p = dom;
			if(hig+1!=c.end())
				p+=(*(hig+1)).ss-(*hig).ss;
			if(low != b.begin())
				dom+=(*low).ff-(*(low-1)).ff;
			if (p>dom) dom=p;
		}
	}
	cout<<dom;
	return 0;
}