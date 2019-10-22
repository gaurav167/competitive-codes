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

	int n;
	cin>>n;
	vi a(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	vi dis;
	for(int i = 1 ; i < n-1 ; i++){
		if(a[i] == 0 && a[i-1] == 1 && a[i+1] == 1){
			dis.pb(i);
		}
	}
	int ans = 0;
	// trace1(0-1);
	// trace1(dis.size());
	// trace1(int(dis.size())-1);
	// trace1((0<dis.size()-1));
	// for(int i = 0 ; i < (int(dis.size())-1) ; i++){
	// 	trace1(i);
	// 	if(dis[i+1] - dis[i] == 2){
	// 		trace3(i+1, i, ans);
	// 		ans++;
	// 		i++;
	// 	}
	// 	else{
	// 		trace2(i, ans);
	// 		ans++;
	// 	}
	// 	trace3(i, int(dis.size()) - 1, (i < int(dis.size()) - 1));
	// }
	// if(dis.size() % 2 == 1 && dis.size() > 1){
	// 	if(dis[int(dis.size())-1] - dis[int(dis.size()) - 2] != 2){
	// 		ans++;
	// 	}
	// }
	// if(dis.size()  > 1){
		for(auto i = dis.begin() ; dis.size() > 1 ;){
			// trace2(*(i+1), *i);
			if(*(i+1) - *i == 2){
				dis.erase(i);
				dis.erase(i);
			}
			else{
				dis.erase(i);
			}
			ans++;
			// trace1(ans);
		}
		
	// }
	if(dis.size() > 0){
		ans++;
	}
	cout<<ans;

	return 0;
}