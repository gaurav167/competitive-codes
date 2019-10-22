#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <string>
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

int n;
string s = "";
// vector<vector<int>> dp(500+1, vector<int> (500+1,-1)); 
vector<vector<bool>> a(26, vector<bool> (501, false));
vector<unordered_map<string, int>> dp(501);
// lli id = 0;
// map<string,int> m;
int min(int aa, int b){
	return (aa<b)?aa:b;
}
int solve(int st, string ss){
	// trace1(st);
	if(st>=n) return ss.size();
	// if(m.find(ss) == m.end()){
	// 	m[ss] = ++id;
	// }
	// lli sss = m[ss];
	if(dp[st].find(ss) == dp[st].end()){
		while(ss.length()>0 && ss[ss.length()-1] == s[st]) ss.pop_back();
		int q = solve(st+1, ss)+1;
		int q2 = INT_MAX;
		if(a[s[st]-'a'][st]){
			ss.push_back(s[st]);
			q2 = solve(st+1, ss);
		}
		dp[st][ss] = min(q, q2);
	}
	return dp[st][ss];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	string ss;
	cin>>ss;
	char prev = ss[0];
	// bool f = false;
	s += ss[0];
	for(int i = 1 ; i < n ; i++){
		if(ss[i] != prev){
			prev = ss[i];
			s+=ss[i];
		}
	}
	n = s.length();
	vector<bool> seen(26, false);
	for(int i = n-1 ; i >= 0 ; i--){
		a[s[i]-'a'][i] = a[s[i]-'a'][i+1];
		if(seen[s[i]-'a']) a[s[i]-'a'][i] = true;
		seen[s[i]-'a'] = true;
	}
	
	string sss;
	cout<<solve(0, sss);


	return 0;
}