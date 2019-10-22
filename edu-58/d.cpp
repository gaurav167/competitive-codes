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

vector<vector<int>> a;
vector<int> b;
vector<bool> visited;

void dfs(int st, int &a1, int &a2){
	int max1 = -1, max2 = -1;
	if(a[st].size() == 2){
		a2 = 1;
		if(!visited[a[st][0]]){
			if(gcd(b[st], b[a[st][0]]) == 1) a1=-1;
			else a1 = 2;
		}
		else{
			if(gcd(b[st], b[a[st][1]]) == 1) a1=-1;
			else a1 = 2;
		}
		return;
	}
	for(int i = 0 ; i < a[st].size() ; i++){
		if(!visited[a[st][i]]){
			// bool ff = false;
			int aa1 = -1, aa2 = -1;
			dfs(a[st][i], aa1, aa2);
			if(aa1 == -1){
				if(gcd(b[st], b[a[st][i]]) == 1) a1 = -1;
				else a1 = 2;
			}
			else{
				if(gcd(b[st], b[a[st][i]])!=1) aa1++;
				else aa1 = -1;
				
			}
			if(aa1 > max1) max1 = aa1;
			if(aa2 > max2) max2 = aa2;
		}
	}
	a1 = max1;
	a2 = max2;
}
int main(){

	int n;
	cin>>n;
	visited.resize(n);
	a.resize(n);
	b.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(int i = 0 ; i < n-1; i++){
		int q,w;
		cin>>q>>w;
		q--;
		w--;
		a[q].pb(w);
		a[w].pb(q);
	}
	int aa=-1,bb=-1;
	dfs(0, aa,bb);
	cout<<max(aa,bb);


	return 0;
}