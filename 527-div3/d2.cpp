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

std::vector<int> a;
int m=-1;
bool solve(int start, bool f){
	// trace2(start, f);
	if(start >= a.size()) return true;
	if(a.size() - start == 1){
		if(a[start] == m && !f) return true;
		else return false;
	}
	if(a[start] < a[start+1]) return false;
	if(a[start] == a[start+1]){
		if (!f) return solve(start+2, false);
		a[start+1] = a[start-1];
		return solve(start+1, false);
	}
	else{
		return solve(start+1, true);
	}

}
int main(){

	int n;
	cin>>n;
	for(int i = 0 ; i< n ; i++){
		int k;
		cin>>k;
		a.pb(k);
	}
	m = *max_element(a.begin(), a.end());
	int cnt = 0;
	vi mm;
	mm.pb(-1);
	for(int i = 0 ;i < n ; i++){
		if(a[i] == m) mm.pb(i);
	}
	mm.pb(n);
	for(int i = 0 ; i < mm.size()-1 ; i++){
		if((mm[i+1] - mm[i])%2 == 0){
			cout<<"NO\n";
			return 0;
		}
	}
	if((n-mm.size())%2 == 1) cout<<"NO\n";
	else{
		bool f = solve(0, false);
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}


	return 0;
}