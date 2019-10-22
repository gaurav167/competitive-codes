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

bool comp(pair<int,int> &a, pair<int,int> &b){
	return a.ss>b.ss;
}
bool compp(pair<int,int> &a, pair<int,int> &b){
	return a.ff>b.ff;
}
bool comppp(pair<int,int> &a, pair<int,int> &b){
	return a.ff<b.ff;
}
int main(){

	int n,k;
	cin>>n>>k;
	map<int,int> m;
	multimap<int,int> mm;
	for(int i = 0 ; i < n ; i++){
		int k;
		cin>>k;
		if(m.find(k) == m.end()){
			m[k] = 1;
		}
		else{
			m[k]++;
		}
	}
	for(auto i = m.begin() ; i!= m.end() ; i++){
		mm.insert(mp(i->ss,i->ff));
	}
	// sort(m.begin(), m.end(), comp);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_q;
	priority_queue<pair<int,int>, vector<pair<int,int>> , less<pair<int,int>>> max_q;
	int ans = -1;
	int j=0;
	for(auto i = mm.begin() ; j < k ; i++, j++){
		min_q.push(mp(i->ff, i->ss));
		max_q.push(mp(i->ff,i->ss));
		ans = i->ss;
	}
	while(!max_q.empty() && !min_q.empty()){
		pair<int,int> max_tp = max_q.top();
		pair<int,int> min_tp = min_q.top();
		if(ans > max_tp.ff/2){
			break;
		}
		max_q.pop();
		min_q.pop();
		max_q.push(mp(max_tp.ff/2, max_tp.ss));
		max_q.push(mp(max_tp.ff-max_tp.ff/2, max_tp.ss));
		min_q.push(mp(max_tp.ff/2, max_tp.ss));
		min_q.push(mp(max_tp.ff-max_tp.ff/2, max_tp.ss));
		if(ans < min_q.top().ff){
			ans = min_q.top().ff;
		}
	}
	int i = 0;
	while(i<k){
		i++;
		cout<<max_q.top().ss<<' ';
		max_q.pop();
	}

	return 0;
}