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
void tracev(vector<T> &a){
	for(auto &i:a){
		cout<<i<<' ';
	}
	cout<<'\n';
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<lli> a(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	vector<pair<lli,lli>> r(m);
	for(int i = 0 ; i < m ; i++){
		cin>>r[i].ff>>r[i].ss;
	}
	vector<lli> mm(n+1, 0);
	for(int i = 0 ; i < m ; i++){
		mm[r[i].ff-1] += 1;
		mm[r[i].ss] += -1;
	}
	int cum = 0;
	vector<lli> q(n);
	for(int i = 0 ; i < n ; i++){
		cum += mm[i];
		mm[i] = cum;
		q[i] = a[i]-mm[i];
	}
	set<int> ans;
	for(int i = 1 ; i <= m ; i++){
		ans.insert(i);
	}
	set<lli> mi, ma;
	lli mii = *min_element(q.begin(), q.end());
	lli maa = *max_element(q.begin(), q.end());
	// trace2(maa, mii);
	// tracev(a);
	// tracev(mm);
	// tracev(q);
	for(int i = 0 ; i < n ; i++){
		if(q[i] == mii){
			mi.insert(i);
		}
		if(q[i] == maa){
			ma.insert(i);
		}
	}
	// for(auto i:ma){
	// 	trace1(i);
	// }
	// for(auto i:mi){
	// 	trace1(i);
	// }
	for(int i = 0 ; i < m ; i++){
		bool ff = false;
		trace3(i, r[i].ff-1, r[i].ss-1);
		for(int j = r[i].ff-1 ; j<r[i].ss ; j++){
			if(mi.find(j) != mi.end()){
				ff = true;
			}
		}
		if(!ff){
			for(int j = r[i].ff-1 ; j<r[i].ss ; j++){
				if(ma.find(j) != ma.end()){
					ff = false;
				}
			}
		}
		trace1(ff);
		if(!ff){
			ans.erase(ans.find(i+1));
			// trace3(i, r[i].ff-1, r[i].ss-1);
			for(int j = r[i].ff-1 ; j<r[i].ss ; j++){
				q[j]++;
				if(q[j] > maa){
					// ma.clear();
					// maa = q[j];
					ma.insert(j);
				}
				else if(q[j] == maa){
					ma.insert(j);
				}
			}
		}
	}
	cout<<maa-mii<<'\n';
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		cout<<i<<' ';
	}

	return 0;
}