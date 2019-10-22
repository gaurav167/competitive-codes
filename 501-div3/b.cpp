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


void m_str(string &a, int s, int in, vi &op){
	int temp = a[in];
	for(int i = in ; i > s ; i--){
		a[i] = a[i-1];
		op.pb(i-1);
	}
	a[s] = temp;
	// op.pb(s);
}
int find(string a, int s, char k){
	for(int i = s ; i < a.length() ; i++){
		if(a[i] == k) return i;
	}
	return -1;
}
void shif(string a, string b, int s, vi &op){
	// trace6(a,b,s,a[s],b[s],(a[s]==b[s]));
	if(s>=a.length()) return;
	if(a[s]==b[s]){
		shif(a,b,s+1,op);
		return;
	}
	int in = find(a,s+1,b[s]);
	// trace1(in);
	if(in==-1){
		cout<<"-1";
		exit(0);
	}
	else{
		m_str(a,s,in, op);
		// cout<<"op : ";
		// for(int i = 0 ; i < op.size() ; i++){
		// 	cout<<op[i]<<' ';
		// }
		// cout<<'\n';
		shif(a,b,s+1,op);
	}
}
int main(){

	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	vi op;
	shif(a,b,0, op);
	cout<<op.size()<<'\n';
	for(int i = 0 ; i < op.size() ; i++){
		cout<<op[i]+1<<' ';
	}
	return 0;
}