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

	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		// vi a(n);
		// for(lli i = 0 ; i < n ; i++){
		// 	cin>>a[i];
		// }
		// sort(a.begin(), a.end());
		map<int,int> m1,m2;
		for(lli i = 0 ; i < n ; i++){
			int p;
			cin>>p;
			if(m1.find(p)==m1.end()){
				m1[p] = 1;
			}
			else{
				auto it = m1.find(p);
				m1.erase(it);
				m2[p] += 1;
			}
		}
		vi r;
		// lli k = 0;
		// while(k<n-1){
		// 	if(a[k] == a[k+1]){
		// 		r.pb(a[k]);
		// 		k+=2;
		// 	}
		// 	else{
		// 		k+=1;
		// 	}
		// }
		for(auto i = m2.begin() ; i!=m2.end() ; i++){
			while((i->ss)--){
				r.pb(i->ff);
			}
		}
		// vector<double> d(r.size()-1);
		double min = (double(r[1])/double(r[0])) + (double(r[0])/double(r[1]));
		int ind = 0;
		for(lli i = 1 ; i < r.size()-1 ; i++){
			double l = (double(r[i+1])/double(r[i])) + (double(r[i])/double(r[i+1]));
			if(l<min){
				min = l;
				ind = i;
			}
		}
		// for(lli i = 1 ; i < d.size() ; i++){
		// 	if(d[i]<min){
		// 		min = d[i];
		// 		ind = i;
		// 	}
		// }
		cout<<r[ind]<<' '<<r[ind]<<' '<<r[ind+1]<<' '<<r[ind+1]<<'\n';

	}


	return 0;
}