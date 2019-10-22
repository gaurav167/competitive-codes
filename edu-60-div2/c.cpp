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
template<typename T> 
void tracev(vector<T> &v){
	for(auto i:v){
		cout<<i<<' ';
	}
	cout<<'\n';
}
template<typename T> 
void tracevv(vector<T> &v){
	for(auto i:v){
		tracev(i);
	}
}
int main(){
	unordered_map<char, int> m = {{'U', 0}, {'D', 1}, {'R', 2}, {'L', 3}};
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<int>> a(n, vector<int> (4, 0));
	a[0][m[s[0]]]++;
	for(int i = 1 ; i < n ; i++){
		a[i] = a[i-1];
		a[i][m[s[i]]]++;
	}
	if(x1 == x2 && y1 == y2){
		cout<<0;
		return 0;
	}
	tracevv(a);
	int x = a[n-1][0] - a[n-1][1];
	int y = a[n-1][2] - a[n-1][3];
	int w = x2-x1;
	int h = y2-y1;
	int ans = INT_MAX;
	for(int i = 0 ; i < n ; i++){
		int xx = a[i][0] - a[i][1];
		int yy = a[i][2] - a[i][3];
		if(!((h*x < 0 && (h*xx < 0 || abs(h)>abs(xx))) || (w*y < 0 && (w*yy < 0 || abs(w)>abs(yy))))){
			int n1 = (((h+w+1)/2 - xx - yy)+x+y-1)/(x+y);
			trace5(xx,yy,h,w,n1);
			if(n1 >= 0){
				int an = n1*n + i + 1;
				trace2(i ,an);
				if(an < ans) ans = an;	
			}
		}
	}
	if(ans == INT_MAX){
		cout<<-1;
	}
	else cout<<ans;
	return 0;
	// tracevv(a);


	return 0;
}