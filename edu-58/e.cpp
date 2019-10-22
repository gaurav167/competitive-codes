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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int h,w;
	string s1;
	cin>>s1;
	int a1,b1;
	cin>>a1>>b1;
	h = min(a1,b1);
	w = max(a1,b1);
	for(int i = 1 ; i < n ; i++){
		string s;
		cin>>s;
		int a,b;
		cin>>a>>b;
		if(s[0]=='+'){
			int ma = max(a,b);
			int mi = min(a,b);
			w = max(ma, w);
			h = max(mi, h);
			// if(ma > h && ma>w){
			// 	w = ma;
			// 	if(mi > h) h = mi;
			// }
			// if(mi > w){
			// 	if(mi>w){
			// 		w = ma;
			// 		h = mi;
			// 	}
			// 	else{

			// 	}
			// }
		}
		else{
			if((a>=h && b>=w) || (b>=h && a>=w)){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
		}
	}



	return 0;
}