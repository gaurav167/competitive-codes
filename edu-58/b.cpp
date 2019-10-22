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
	string s;
	cin>>s;
	int st1 = -1, st2=-2, st3=-3, st4=-4;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] == '['){
			st1 = i;
			break;
		}
	}
	for(int i = s.length() - 1; i>=0 ; i--){
		if(s[i]==']'){
			st2 = i;
			break;
		}
	}

	for(int i = st1 ; i < s.length() ; i++){
		if(s[i] == ':'){
			st3 = i;
			break;
		}
	}
	for(int i = st2; i>=0 ; i--){
		if(s[i]==':'){
			st4 = i;
			break;
		}
	}
	if(st1>=0 && st2>=0 && st3>=0 && st4>=0 && st1<st3 && st3<st4 && st4<st2){
		int ans = 4;
		for(int i = st3+1 ; i < st4 ; i++){
			if(s[i]=='|'){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		cout<<"-1";
	}
	return 0;
}