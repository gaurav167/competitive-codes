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

	lli t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		lli n = s.length();
		vector<lli> a(s.length()+1, 0);
		for(int i = 1 ; i < n+1 ; i++){
			if(s[i-1] == '1') a[i] = 0;
			else{
				a[i] = a[i-1] + 1;
			}
		}
		lli ans = 0;
		for(lli i = 0 ; i < n ; i++){
			if(s[i] == '1'){
				lli c = 0;
				for(lli j = i ; j < min(n, i+25) ; j++){
					c  = (c<<1) + (s[j]-'0');
					if(c!=0){
						if(c==(j-i+1)) ans++;
						else if(c > (j-i+1)){
							int req = c - (j-i+1);
							if(req <= a[i]) ans++;
						}
					}

					// if(c!=0){
					// 	if(c == (j-i+1)) { ans++;}
					// 	else{
					// 		if(a[i] > 15){
					// 			if(c <= a[i]+(j-i+1)) { ans++;}
					// 		}
					// 	}
					// }
					// if(c <= a[i]+(j-i+1) && c!=0) {trace3(i,j,a[i]) ans++;}
				}
			}
		}
		cout<<ans<<'\n';

	}
	


	return 0;
}