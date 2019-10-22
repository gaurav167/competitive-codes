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

int main(){
	int n;
	cin>>n;
	string p,s;
	bool f = false;
	std::vector<string> a(2*n-2);
	for(int i = 0 ; i < 2*n-2; i++){
		cin>>a[i];

		if(a[i].length() == n-1){
			if(f) p = a[i];
			if(!f){
				s = a[i];
				f = true;
			}
		}
	}
	// bool ff = true;
	// for(int i = 1 ; i < n-1 ; i++){
	// 	if(p[i] != s[i-1]){
	// 		ff = false;
	// 		break;
	// 	}
	// }
	// if(!ff){
	// 	string q = p;
	// 	p = s;
	// 	s = q;
	// }
	vector<char> a1(2*n-2),a2(2*n-2);
	string ss2 = p+s[s.length()-1];
	string ss1 = s+p[p.length()-1];
	// trace2(ss1, ss2);
	vector<char> b1(n-1, 'a'), b2(n-1, 'a');
	bool fffff = true;
	for(int i = 0 ; i < a.size() ; i++){
		bool fff = true;
		for(int j = 0 ; j < a[i].length() ; j++){
			// trace3(a[i][j], ss[j], (a[i][j] != ss[j]));
			if(a[i][j] != ss1[j]){
				fff = false;
				break;
			}
		}
		if(fff){
			if(b1[a[i].length()-1] != 'a'){
				if(b1[a[i].length()-1] == 'P') a1[i] = 'S';
				else a1[i] = 'P';
			}

			else{
				a1[i] = 'P';
				b1[a[i].length()-1] = 'P';
			}
		}
		else{
			// trace1(a[i]);
			for(int j = 0 ; j < a[i].length() ; j++){
				// trace4(a[i][j], n+j-a[i].length(), ss1[n+j-a[i].length()], (a[i][j] != ss1[n+j-a[i].length()]));
				if(a[i][j] != ss1[n+j-a[i].length()]){
					fffff = false;
					break;
				}
			}
			if(!fffff) break;

			if(b1[a[i].length()-1] != 'a'){
				if(b1[a[i].length()-1] == 'P') a1[i] = 'S';
				else a1[i] = 'P';

			}

			else{
				a1[i] = 'S';
				b1[a[i].length()-1] = 'S';
			}
		}
		// trace1(a1[i]);
	}
	for(int i = 0 ; i < a.size() ; i++){
		bool fff = true;
		for(int j = 0 ; j < a[i].length() ; j++){
			// trace3(a[i][j], ss[j], (a[i][j] != ss[j]));
			if(a[i][j] != ss2[n+j-a[i].length()]){
				fff = false;
				break;
			}
		}
		// trace4(a[i], fff, b2[a[i].length()-1], a[i].length()-1);
		if(fff){
			if(b2[a[i].length()-1] != 'a'){
				if(b2[a[i].length()-1] == 'P') a2[i] = 'S';
				else a2[i] = 'P';
			}

			else{
				a2[i] = 'S';
				b2[a[i].length()-1] = 'S';
			}
		}
		else{
			if(b2[a[i].length()-1] != 'a'){
				if(b2[a[i].length()-1] == 'P') a2[i] = 'S';
				else a2[i] = 'P';

			}

			else{
				a2[i] = 'P';
				b2[a[i].length()-1] = 'P';
			}
		}
		// trace1(a2[i]);
	}
	// for(int i = 0 ; i < 2*n-2 ; i++){
	// 	cout<<a1[i];
	// }
	// cout<<'\n';
	// for(int i = 0 ; i < 2*n-2 ; i++){
	// 	cout<<a2[i];
	// }
	// cout<<'\n';
	if(fffff){

	}
	// int cnt = 0;
	// bool ffff = false;
	// for(int i = 0 ;i < 2*n-2 ; i++){
	// 	if(a1[i] == 'P') cnt++;
	// }
	// if(cnt == 2*n-2){
	// 	ffff = true;
	// }
	if(fffff){
		for(int i = 0 ; i < 2*n-2; i++){
			cout<<a1[i];
		}
	}
	else{
		for(int i = 0 ; i < 2*n-2; i++){
			cout<<a2[i];
		}	
	}
	return 0;
}