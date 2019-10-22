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


bool comp(pair<int, pair<int,int>> &a, pair<int,pair<int, int>> &b){
	return a.ss.ff<b.ss.ff;
}

bool compp(pair<int, pair<int,int>> &a, pair<int,pair<int, int>> &b){
	return a.ss.ss<b.ss.ss;
}
int main(){

	int n,k;
	cin>>n>>k;
	vector<pair<int, pair<int,int>>> a(n);
	for(int i = 0 ; i < n ;i++){
		int q;
		cin>>q;
		a[i].ss.ff = q;
		a[i].ss.ss = i;
	}
	bool f = true;
	int max = 1;
	if(k > n) f=false;
	else{
		int cnt = 1;
		sort(a.begin(), a.end(), comp);
		a[0].ff=1;
		for(int i = 1 ; i < n ; i++){
			a[i].ff = i%k+1;
			// trace4(i,a[i].ff, a[i].ss.ff, a[i].ss.ss);
			if(a[i].ss.ff == a[i-1].ss.ff){
				cnt++;
			}
			else{
				cnt=1;
			}
			if(cnt>k){
				f=false;
			}
			if(a[i].ff>max) max = a[i].ff;
		}
		// a[0].ff = 1;
		// for(int i = 1 ; i < n ; i++){
		// 	if(a[i].ss.ff == a[i-1].ss.ff){
		// 		a[i].ff = a[i-1].ff+1;
		// 		if(a[i].ff > max){
		// 			max = a[i].ff;
		// 		}
		// 		if(a[i].ff > k){
		// 			f = false;
		// 			break;
		// 		}
		// 	}
		// 	else{
		// 		a[i].ff = 1;
		// 	}
		// }		
	}

	if(f&&max==k){
		cout<<"YES\n";
		sort(a.begin(), a.end(), compp);
		// if(max < k){
		// 	for(int i = 0 ; i < k-max ; i++){
		// 		a[i].ff = max+i+1;
		// 	}
		// }
		for(int i = 0 ; i < n ; i++){
			cout<<a[i].ff<<' ';
		}
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}