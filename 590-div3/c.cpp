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

	int q;
	cin>>q;
	while(q--){


		int n;
		cin>>n;
		string s[2];
		cin>>s[0]>>s[1];
		int st = 0;
		int cur = 0;
		int l = true;
		int ans = true;
		if(s[cur][0] <= '2'){
			st = 1;
		}
		else{
			cur = 1;
			l = false;
		}

		for(int i=st ; i < n ; i++){
			if(l){
				if(s[cur][i] > '2'){
					l = false;
					cur = (cur+1)%2;
					i--;
				}
			}
			else{
				if(s[cur][i] <= '2'){
					ans = false;
					break;
				}
				l = true;
			}
		}
		if(l && ans && cur == 1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}












		// int n;
		// cin>>n;
		// string s1,s2;
		// cin>>s1>>s2;
		// int st;
		// string cur = s1;
		// bool inl = true, ol = (cur[0] <= '2');
		// bool ans = true;
		// if(cur[0] <= '2'){
		// 	cur = s1;
		// 	st = 1;
		// }
		// else{
		// 	cur = s2;
		// 	st = 0;
		// }
		// for(int i = st ; i < n ; i++){
		// 	if(ol){
		// 		if(cur[i] > '2'){
		// 			ol = false;
		// 			if(cur == s1) cur = s2;
		// 			else cur = s1;
		// 			i--;
		// 		}
		// 	}
		// 	else{
		// 		if(cur[i] <= '2'){
		// 			ans=  false;
		// 			break;
		// 		}
		// 		ol = true;
		// 	}
		// }
		// if(ol && ans && cur == s2){
		// 	cout<<"YES\n";
		// }
		// else{
		// 	cout<<"NO\n";
		// }

	}

	return 0;
}