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


map<int, int> ans;
map<int, vector<int>> m;
void update(int i, pair<int,int> k){
	if(k.ff == -1){
		return;
	}
	ans[i] += k.ss;
	k.ff--;
	vector<int> q = m[i];
	for(int ii = 0 ; ii < q.size() ; ii++){
		update(q[ii], k);
	}	
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	map<int, map<int,int>> m1;
	vector<pair<int,int>> a(n-1);
	for(int i = 0 ; i < n-1; i++){
		int q,w;
		cin>>q>>w;
		m1[q][w] = 1;
		m1[w][q] = 1;
	}
	vector<int> todo;
	todo.pb(1);
	for(int i = 0 ; i < todo.size() ; i++){
		for(auto ii = m1[todo[i]].begin() ; ii!= m1[todo[i]].end() ; ii++){
			if(ii->ss == 1){
				m[todo[i]].pb(ii->ff);
				ii->ss = 0;
				m1[ii->ff][todo[i]] = 0;
				todo.pb(ii->ff);
			}
		}

	}
	// for(auto i = m.begin() ; i!=m.end() ; i++){
	// 	cout<<i->ff<<" : ";
	// 	for(int j = 0 ; j < (i->ss).size() ; j++){
	// 		cout<<i->ss[j]<<' ';
	// 	}
	// 	cout<<'\n';
	// }
	int k;
	cin>>k;
	for(int i = 1 ; i < n+1 ; i++){
		ans[i] = 0;
	}
	for(int i = 0 ; i < k ; i++){
		int p,o,y;
		cin>>p>>o>>y;
		pair<int,int> qq = mp(o,y);
		update(p, qq);
	}

	// for(auto i = m.begin() ; i!= m.end() ; i++){
	// 	if(mark.find(i->ff) != mark.end()){
	// 		ans[i->ff] += mark[i->ff].ss;
	// 		for(int j = 0 ; j < (i->ss).size() ; j++){
	// 			update(i->ss[j], mark[i->ff]);
	// 		}
	// 	}
	// }
	for(auto i = ans.begin() ; i!=ans.end() ; i++){
		cout<<i->ss<<' ';
	}
	

	return 0;
}