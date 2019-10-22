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

typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
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

bool comp(pii &a, pii &b){
	return a.ff<b.ff;
}
bool compp(pii &a, int b){
	return a.ff<b;
}
int main(){
	int n;
	cin>>n;
	map<int,vpii> m;
	for(int i = 0 ; i < n-1 ; i++){
		int t1,t2;
		cin>>t1>>t2;
		m[t1].pb(mp(t2,0));
		m[t2].pb(mp(t1,0));
	}
	for(auto i = m.begin() ; i != m.end() ; i++){
		sort((i->ss).begin(), (i->ss).end(), comp);
	}
	vi b(n);
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	queue<int> q;
	q.push(b[0]);
	int i = 1;
	int j = 1;
	while(i<n){
		vpii ne = m[q.front()];
		vpii::iterator o = lower_bound(ne.begin(), ne.end(), b[i], compp);
		if((*o).ff == b[i] && (*o).ss == 0){
			// q.push(b[i]);
			(*o).ss = 1;
			vpii::iterator z = lower_bound(m[b[i]].begin(), m[b[i]].end(), q.front(), compp);
			(*z).ss = 1;
		}
		else{
			cout<<"No";
			return 0;
		}
		int k=0;
		while(j<n&&k<m[q.front()].size()){
			q.push(b[j++]);
		}
		q.pop();
		i++;
	}

	cout<<"Yes";

	// vector<vector<int>> ans;
	// queue<int> q;
	// vi p(1,b[0]);
	// ans.pb(p);


	return 0;
}