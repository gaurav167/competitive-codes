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

	lli n;
	cin>>n;
	vector<lli> q(n-1);
	for(lli i = 0 ; i < n - 1 ; i++){
		cin>>q[i];
	}
	vector<lli> a(n);
	a[0] = 0;
	lli cum = 0;
	for(lli i = 1 ; i < n ; i++){
		a[i] = cum + q[i-1];
		cum = a[i];
	}
	lli m = *min_element(a.begin(), a.end());
	lli st = abs(m)+1;
	set<lli> p;
	p.insert(st);
	lli sum = st;
	for(lli i = 1 ; i < n ; i++){
		p.insert(q[i-1]+sum);
		sum += q[i-1];
	}
	bool f = true;
	if(p.size()==n){
		lli qq = 1;
		for(auto &i:p){
			if(i != qq){
				f = false;
				break;
			}
			qq++;
		}
	}
	else{
		f = false;
	}

	if(f){
		cout<<st<<' ';
		lli cum = 0;
		for(lli i = 1 ; i < n  ;i++){
			cum += q[i-1];
			cout<<st+cum<<' ';
		}
	}
	else{
		cout<<"-1";
	}



	return 0;
}