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
	while(q--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n<=3){
			if(n==2){
				if(s[0]<s[1]){
					cout<<"YES\n2\n"<<s[0]<<' '<<s[1]<<'\n';
				}
				else{
					cout<<"NO\n";
				}
			}
			else{
				if(int(s[0])-48 < (int(s[1])-48)*10+(int(s[2])-48)){
					cout<<"YES\n2\n"<<s[0]<<' '<<s[1]<<s[2]<<'\n';
				}
				else if(s[0] < s[1] && s[1] < s[2]){
					cout<<"YES\n3\n"<<s[0]<<' '<<s[1]<<' '<<s[2]<<'\n';
				}
				else{
					cout<<"NO\n";
				}
			}

		}
		else{
			cout<<"YES\n2\n";
			cout<<s[0]<<' ';
			cout<<s.substr(1)<<'\n';
		}

	}


	return 0;
}