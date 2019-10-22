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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	cin>>n>>k;
	vector<lli> d(n);
	for(lli i = 0 ; i < n ; cin>>d[i] , i++);
	map<lli,lli> m;
	for(lli i = 0 ; i< n ; i++){
		lli q = d[i]%k;
		if(m.find(q) == m.end()) m[q]=1;
		else m[q]++;
	}
	lli ans = 0;
	// for(auto i:m){
	// 	trace2(i.ff, i.ss);
	// }
	// vector<bool> done(k, false);
	for(int i = 0 ; i < k ; i++){
		auto j = m.find(i);
		if(j!=m.end()){
			auto jj = m.find((k-i)%k);
			if(jj!=m.end()){
				// if(done[i] != true){
					if(i == ((k-i)%k)){
						ans += 2*(min(j->ss, jj->ss)/2);
					}
					else ans += min(j->ss, jj->ss);
				// }
				// done[i] = true;
				// done[(k-i)%k] = true;
			}
		}
	}
	// if(m.find(0)!=m.end()){
	// 	auto j = m.find(0);
	// 	ans += 2*((j->ss)/2);
	// }
	cout<<ans;
	// for(auto &i :m){
	// 	if(i.ff!=0){
	// 		lli key = i.ff;
	// 		auto j = m.find((k-key)%k);
	// 		if(j!=m.end()){
	// 			// trace2(i.ss, j->ss);
	// 			ans += min(i.ss, j->ss);
	// 		}
	// 	}
	// }
	// cout<<ans;

	return 0;
}