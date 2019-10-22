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

void heat(vector<pair<int,int>> &a, int i, int r, int n){
	for(int j = max(0,i-r+1) ; j < min(n,i+r) ; j++){
		a[j].ss+=1;
		// trace2(i, j);
	}
}
int turnoff(vector<pair<int,int>> a, int i , int r, int n){
	for(int j = max(0,i-r+1) ; j < min(n,i+r) ; j++){
		// if(a[j].ss == 0) return 2;
		if(a[j].ss == 1) return 0;
	}
	return 1;
}
void off(vector<pair<int,int>> &a, int i, int r, int n){
	for(int j = max(0, i-r+1); j < min(n, i+r); j++){
		a[j].ss--;
	}
}
int main(){

	int n,r;
	cin>>n>>r;
	vector<pair<int,int>> a(n);
	int heaters = 0;
	for(int i = 0 ; i < n ; i++){
		int k;
		cin>>k;
		if(k) heaters++;
		a[i] = mp(k,0);
	}
	if(heaters == 0){
		cout<<"-1";
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i].ff == 1){
			heat(a,i,r, n);
		}
	}
	// trace1(heaters);
	for(int i = 0 ; i < n ; i++){
		if(a[i].ss == 0){
				cout<<"-1";
				return 0;
		}
		// trace2(a[i].ff, a[i].ss);
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i].ff == 1){
			int j = turnoff(a, i, r, n);
			if(j == 1){
				a[i].ff = 0;
				off(a, i , r, n);
				heaters--;
			}
		}
	}
	cout<<heaters;
	return 0;
}