#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define trace1(x)                cout<<#x<<": "<<x<<endl;
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl;
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl;
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long int lli;
typedef lli ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int, int> > vpii;
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
template<typename T> void tracev(vector<T> &a) { for(auto &i:a) { cout<<i<<' '; } cout<<'\n'; }
template<typename T> void tracevv(vector<T> &a) { for(auto &i:a) { tracev(i); } }
template<typename T> void tracevp(vector<T> &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }


// int reachable(int sti, int stj, vector<vector<int>> &v, vector<string> &s){
// 	if(sti >= v.size()-1 || stj >= v[0].size()-1 || s[sti][stj] == '#'){
// 		v[sti][stj] = -1;
// 		return -1;
// 	}
// 	if(sti == v.size()-2 && stj == v[0].size()-2){
// 		v[sti][stj] = 1;
// 		return 1;
// 	}
// 	int a = reachable(sti+1, stj, v, s);
// 	int b = reachable(sti, stj+1, v, s);
// 	if(a== 1 || b == 1){
// 		v[sti][stj] = 1;
// 	}
// 	else v[sti][stj] = -1;
// }
	vector<string> s;
	vector<vector<int>> v, vv;
	int n,m;

int reachable(int ii, int jj){
	// trace2(ii, jj)
	if(v[ii][jj] != 0) return v[ii][jj];
	if(s[ii][jj] == '#'){
		vv[ii][jj] = 0;
		v[ii][jj] = -1;
		return -1;
	}
	int a = reachable(ii+1, jj);
		int b = reachable(ii, jj+1);
	if(a == 1 || b == 1) v[ii][jj] =1;
	else v[ii][jj] = -1;
	return v[ii][jj];

}
int main(){

	cin>>n>>m;
	s.resize(n);
	v.resize(n+1, vector<int>(m+1, 0));
	vv.resize(n+1, vector<int>(m+1, 0));
	for(int i = 0 ; i < n ; i++) cin>>s[i];
	v[n-1][m-1] = 1;
	for(int i = 0 ; i<m+1 ;i++){
		v[n][i] = -1;
		vv[n][i] = 0;
		// v[i][n] = -1;
	}
	for(int i = 0 ; i<n+1 ;i++){
		v[i][m] = -1;
		vv[i][m] = 0;
		// v[i][n] = -1;
	}

	int x = reachable(0, 0);
	tracevv(v);
	if(x == 0) {
		cout<<0;
		return 0;
	}
	for(int i = 0 ; i  < n-1; i++){
		int c = 0;
		for(int j = 0 ; j < m ; j++){
			if(v[i][j] == 1) c++;
		}
		if(c==1){
			cout<<1;
			return 0;
		}
	}
	for(int i = 0 ; i  < m-1; i++){
		int c = 0;
		for(int j = 0 ; j < n ; j++){
			if(v[j][i] == 1) c++;
		}
		if(c==1){
			cout<<1;
			return 0;
		}
	}
	cout<<2;

	return 0;
}