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

int check(int a){
	int m = -1;
	for(int i = 1 ; i < a ; i++){
		if(gcd(a^i, a&i) > m){
			m = gcd(a^i, a&i);
		}
	}
	return m;
	// cout<<"check "<<m<<' ';
}
int main(){
	int q;
	cin>>q;
	// for(int a = 1 ; a < 33554432 ; a++){
	while(q--){
		int a;
		cin>>a;
		// int m2;
		// int m1 =check(a);
		// trace1(m1);
		int szz = (sizeof(int)*8 - __builtin_clz(a));
		int w = (1<<szz) - 1;
		if(w == a){
			bool f = false;
			int sqr = sqrt(a);
			int m = 1;
			for(int i = 2 ; i < sqr+1 ; i++){
				if(a%i == 0){
					int ii = a/i;
					int gc1 = gcd(a^i, a&i);
					int gc2 = gcd(a^ii, a&ii);
					// trace3(i, gc1, gc2);
					if(max(gc1, gc2) > m){
						m = max(gc1, gc2);
					}
				}
			}
			// int sq = sqrt(szz);
			// for(int i = 2 ; i < sq+1 ; i++){
			// 	if(szz%i == 0){
			// 		pad = i;
			// 		f = true;
			// 		break;
			// 	}
			// }
			// if(szz%2 == 0){
			// 	int sum = 0;
			// 	for(int i = 0 ; i < szz ; i+=2){
			// 		sum += 1<<i;
			// 	}
			// 	m2 = sum;
			// 	cout<<sum<<'\n';
			// }
			cout<<m<<'\n';
			// if(f){
			// 	cout<<m<<
			// }
			// else{
			// 	m2 = 1;
			// 	cout<<"1\n";
			// }
		}
		else{
			// m2 = w;
			cout<<w<<'\n';
			// int ww = w-a;
			// cout<<gcd(ww^a, ww&a)<<'\n';
		}
	}



	return 0;
}