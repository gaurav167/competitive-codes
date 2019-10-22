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
	lli n;
	cin>>n;
	vlli a(n);
	for(lli i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	lli m;
	cin>>m;
	vlli b(m);
	for(lli i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	lli ans=0;
	lli a1=0,b1=0, k = min(n,m);
	for( ; a1<a.size() && b1<b.size() ; a1++, b1++){
		if(a[a1]==b[b1]){
			// trace3(ans,a[a1],b[b1]);
			ans++;
		}
		else{
			// trace2(a[a1], b[b1]);

				lli sum1 = a[a1], sum2 = b[b1];
				while(a1<a.size() && b1<b.size() && sum1!=sum2){
					while(sum1 < sum2){
						a1++;
						sum1 += a[a1];
						// trace2(sum1, sum2);
					}
					while(sum1 > sum2){
						b1++;
						sum2+=b[b1];
						// trace2(sum2, sum1);
					}
				}
				if(sum1!=sum2){
					cout<<"-1";
					return 0;
				}
				else{
					ans++;
					// trace3(ans,sum1,sum2);
				}
		}
	}
	cout<<ans;

	return 0;
}