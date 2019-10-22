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
int main(){

	int n;
	cin>>n;
	vector<int> a(n*n);
	bool f = true;
	map<int,int> m;
	for(int i = 0 ; i < n*n ; i++){
		int k;
		cin>>k;
		if(m.find(k) == m.end()){
			m[k] = 1;
		}
		else m[k]++;
	}
	vector<pair<int, int>> v;
	for(auto &i :m){
		v.pb(mp(i.ff,i.ss));
	}
	vector<std::vector<int>> ans(n, vector<int>(n));
	int ii = 0;
	sort(v.begin(), v.end(), comp);
	for(int i = 0 ; i < n/2; i++){
		for(int j = 0 ; j < n/2; j++){
			if(ii < v.size() && v[ii].ss > 3){
				ans[i][j] = ans[i][n-j-1] = ans[n-i-1][j] = ans[n-i-1][n-j-1] = v[ii].ff;
				v[ii].ss -= 4;
				if(v[ii].ss < 4) ii++;
			}
			else{
				f = false;
				break;
			}
		}
	}
	if(n&1){
		ii = 0;
		sort(v.begin(), v.end(), comp);
		for(int i = 0 ; i < n/2 ; i++){
			if(ii < v.size() && v[ii].ss > 1){
				ans[i][n/2] = ans[n-i-1][n/2] = v[ii].ff;
				v[ii].ss-=2;
				if(v[ii].ss < 2){
					ii++;
				}
			}
			else{
				f = false;
				break;
			}
		}
		for(int i = 0 ; i < n/2 ; i++){
			if(ii < v.size() && v[ii].ss > 1){
				ans[n/2][i] = ans[n/2][n-i-1] = v[ii].ff;
				v[ii].ss-=2;
				if(v[ii].ss < 2){
					ii++;
				}
			}
			else{
				f = false;
				break;
			}
		}
		sort(v.begin(), v.end(), comp);
		if(v[0].ss != 0){
			ans[n/2][n/2] = v[0].ff;
		}
		else f = false;
	}

	// for(int i = 0 ; i < n*n ; cin>>a[i] , i++);
	// unordered_map<int,int> m1;
	// for(auto &i:a){
	// 	auto j = m1.find(i);
	// 	if(j == m1.end()){
	// 		m1[i] = 1;
	// 	}
	// 	else{
	// 		m1[i]++;
	// 	}
	// }
	// std::vector<int> u;
	// for(auto &i:m1){
	// 	if(i.ss > 3){
	// 		while(i.ss>3){
	// 			u.pb(i.ff);
	// 			i.ss -= 4;
	// 		}
	// 	}
	// }
	// int ii = 0;
	// vector<vector<int>> ans(n, vector<int>(n, -1));
	// for(int i = 0 ; i < n/2 ; i++){
	// 	for(int j = 0 ; j < n/2 ; j++){
	// 		if(ii < u.size()){
	// 			ans[i][j] = u[ii];
	// 			ans[n-i-1][j] = u[ii];
	// 			ans[i][n-j-1] = u[ii];
	// 			ans[n-i-1][n-j-1] = u[ii];
	// 			++ii;
	// 		}
	// 		else{
	// 			f = false;
	// 			break;
	// 		}
	// 	}
	// }
	// vector<pair<int,int>> uu;
	// for( ; ii<u.size() ; ii++){
	// 	uu.pb(mp(u[ii], 4));
	// }
	// for(auto &i:m1){
	// 	uu.pb(mp(i.ff, i.ss));
	// }
	// sort(uu.begin(), uu.end(), comp);
	// int jj = 0;
	// if(n&1){
	// 	for(int i = 0 ; i < n/2 ; i++){
	// 		if(jj < uu.size()){
	// 			if(uu[jj].ss > 1){
	// 				uu[jj].ss -= 2;
	// 				ans[i][n/2] = uu[jj].ff;
	// 				ans[n-i-1][n/2] = uu[jj].ff;
	// 			}
	// 			else{
	// 				f = false;
	// 				break;
	// 			}
	// 			if(uu[jj].ss == 0){
	// 				jj++;
	// 			}
	// 			else if(uu[jj].ss == 1){
	// 				ans[n/2][n/2] = uu[jj].ff;
	// 				jj++;
	// 			}
	// 		}
	// 	}
	// 	for(int i = 0 ; i < n/2 ; i++){
	// 		if(jj < uu.size()){
	// 			if(uu[jj].ss > 1){
	// 				uu[jj].ss -= 2;
	// 				ans[n/2][i] = uu[jj].ff;
	// 				ans[n/2][n-i-1] = uu[jj].ff;
	// 			}
	// 			else{
	// 				f = false;
	// 				break;
	// 			}
	// 			if(uu[jj].ss == 0){
	// 				jj++;
	// 			}
	// 			else if(uu[jj].ss == 1){
	// 				ans[n/2][n/2] = uu[jj].ff;
	// 				jj++;
	// 			}
	// 		}
	// 	}
	// 	if(jj<uu.size()){
	// 		ans[n/2][n/2] = uu[jj].ff;
	// 	}
	// }
	if(f){
		cout<<"YES\n";
		for(auto i:ans){
			for(auto j:i){
				cout<<j<<' ';
			}
			cout<<'\n';
		}
	}
	else{
		cout<<"NO\n";
	}


	return 0;
}