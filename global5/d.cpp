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

int main(){

	int n;
	cin>>n;
	vector<double> a(n);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	vlli ans(n, -1);

	double gmax;
	int ii = 0;
	int st;
	while(ii < n){
		// trace1(ii);
		int jj = ii+1;
		double mx = a[ii];
		int end = -1;
		for( ; jj < n ; jj++){
			if(a[jj] < mx/2){
				end = jj;
				break;
			}
			mx= max(mx, a[jj]);
		}
		// trace1(end);
		if(end != -1){
			for(int p = ii ; p < end ; p++){
				ans[p] = (end - p);
			}
		}
		else{
			st = ii;
			gmax = mx;
			break;
		}
		ii = end;
	}
	if(st == 0){
		auto mx = max_element(a.begin(), a.end());
		auto mn = min_element(a.begin(), a.end());
		int sl = -1;
		for(int i = 0 ; i < n ;i++){
			if(a[i] < *mx/2){
				sl = i;
				break;
			}
		}
		if(sl != -1){
			for(int i = 0 ; i  < n ; i++){
				ans[i] = ((mx-a.begin())-i+n)%n + (sl-(mx - a.begin())+n)%n;
				// if(a[i] == *mx) ans[i] -= n;
			}
		}
	}
	else{
		// trace1(st);
		int sl  =-1;
		for(int j = 0 ; j<= st ; j++){
			if(a[j] < gmax/2){
				sl = j;
				break;
			}
			gmax = max(a[j], gmax);
		}
		if(sl != -1){
			for(int i = st ; i < n ; i++){
				ans[i] = (n-i) + sl;
			}
		}
	}


	tracev(ans);









	// double mxx;
	// int cont;
	// 	int end;
	// 	bool f = true;
	// for(int i = 0 ; i < n ;){
	// 	double mx = a[i];
	// 	for(end = i+1 ; end < n ; end++){
	// 		// trace2(a[end], mx/2);
	// 		if(a[end] < mx/2){
	// 			break;
	// 		}
	// 		mx = max(mx, a[end]);
	// 	}
	// 	// trace3(i, a[i], end);
	// 	if(end != n){
	// 		f = false;
	// 		for(int k = i ; k < end ; k++){
	// 			ans[k] = (end-k);
	// 		}
	// 	}
	// 	else{
	// 		cont = i;
	// 		mxx = mx;
	// 		break;
	// 	}
	// 	i = end;
	// }
	// // trace3(cont, end, mxx)
	// if(!f){
	// 	end = -1;
	// 	for(int i = 0 ; i <= cont ; i++){
	// 		if(a[i] < mxx/2){
	// 			end = i;
	// 			break;
	// 		}
	// 		mxx = max(mxx, a[i]);
	// 	}
	// 	if(end != -1){
	// 		for(int i = cont ; i < n ; i++){
	// 			ans[i] = (n-i) + (end);
	// 			// ans[i] = (end - cont + n)%n + 1;
	// 			// ans[i] = (n-cont)+end - (i-cont);
	// 		}
	// 	}
	// }
	// else{
	// 	auto mx = max_element(a.begin(), a.end());
	// 	auto mn = min_element(a.begin(), a.end());
	// 	if(*mn < (*mx)/2){
	// 		for(int i = 0 ; i < n ; i++){
	// 			ans[i] = ((mx-a.begin())-i + n)%n + 1 + (((mn-a.begin())-(mx-a.begin())) + n)%n - 1;
	// 		}
	// 	}
	// }
	// tracev(ans);

	return 0;
}