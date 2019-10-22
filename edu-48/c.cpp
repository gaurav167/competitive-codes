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

lli maxx(lli a, lli b ,lli c){
	if(a>b){
		if(a>c) return a;
		return c;
	}
	if(b>c) return b;
	return c;

}

lli solve(vlli a, vlli b, lli q, lli ck, lli n){
	lli clk = ck, c1=0,c2=0,c3=0;
	for(lli i = q; i < n ; i++,clk++){
		c1+=clk*a[i];
	}
	for(lli i =  n -1; i>=q ; i--, clk++){
		c1+=clk*b[i];
	}
	// cout<<c1;

	clk=ck+1;
	for(lli i = q ; i < n ; i++,clk++){
		c2+=b[i]*clk;
	}
	for(lli i = n-1 ; i>q ; i--, clk++){
		c2+=a[i]*clk;
	}
	clk=ck;

	c3+=a[q]*clk;
	clk++;
	c3+=b[q]*clk;
	clk++;
	c3+=b[q+1]*clk;
	clk++;
	c3+=a[q+1]*clk;
	clk++;
	if(q+2==n-1){
		c3+=a[q+2]*clk;
		clk++;
		c3+=b[q+2]*clk;
		clk++;
	}
	else if(q+2!=n){
		c3+= solve(a,b,q+2,clk, n);
	}
	// cout<<"c3 "<<c3<<'\n';
	// lli s=0;
	// for(lli i = q ; i < n;i++){
	// 	if(s==0){
	// 		c3+=a[i]*clk;
	// 		clk++;
	// 		c3+=b[i]*clk;
	// 		clk++;
	// 		s=1;
	// 	}
	// 	else{
	// 		c3+=b[i]*clk;
	// 		clk++;
	// 		c3+=a[i]*clk;
	// 		clk++;
	// 		s=0;
	// 	}
	// }
	cout<<"test "<<c1<<' '<<c2<<' '<<c3<<'\n';
	return maxx(c1,c2,c3);
}
int main(){
	int n;
	cin>>n;
	vlli a(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	vlli b(n);
	for(int i = 0 ; i < n ;i++){
		cin>>b[i];
	}
	if(n==1){
		cout<< b[0];
		return 0;
	}
	lli res = solve(a,b,0,0,n);
	cout<<res;
	// cout<<'\n'<<c2;
	return 0;
}