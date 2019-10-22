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


bool check(vector<int> &a, int ii, int jj){
	unordered_set<int> s;
	for(int i = 0 ; i < ii ; i++){
		if(s.find(a[i]) == s.end()) s.insert(a[i]);
		else return false;
	}
	for(int i = jj+1 ; i < a.size() ; i++){
		if(s.find(a[i]) == s.end()) s.insert(a[i]);
		else return false;
	}
	return true;
}

int solve(vector<int> &a){
	int n = a.size();
	set<int> s;
	int mm = -1;
	for(int i = 0 ; i < n ; i++){
		if(s.find(a[i]) == s.end()) s.insert(a[i]);
		else{
			mm = i;
			break;
		}
	}

	if(mm==-1) return 0;
	set<int> s2;
	int l = mm;
	for(int i = mm+1 ; i<n ; i++){
		if(s.find(a[i]) != s.end()) l = i;
		else{
			if(s2.find(a[i]) != s2.end()){
				l = i - 1;
			}
			else{
				s2.insert(a[i]);
			}
		}
	}
	return l-mm+1;

}

int main(){
	fio;
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}

	int ans = solve(a);
	reverse(a.begin(), a.end());
	cout<<min(ans, solve(a));

	// int ans = INT_MAX;
	// unordered_set<int> s;
	// bool f = true;
	// for(int i = 0 ; i < n ; i++){
	// 	if(s.find(a[i]) == s.end()) s.insert(a[i]);
	// 	else{
	// 		f = false;
	// 		break;
	// 	}
	// }
	// if(f) {cout<<0; return 0;}
	// for(int i = 0 ; i < n ; i++){
	// 	for(int j = i ; j  < n ; j++){
	// 		if(check(a, i , j)){
	// 			// trace2(i, j)
	// 			ans = min(ans, j-i+1);
	// 		}
	// 	}
	// }
	// cout<<ans;

	// int a1 = solve(a);
	// reverse(a.begin(), a.end());
	// cout<<min(a1, solve(a));


	return 0;
}