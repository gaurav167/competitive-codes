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

	string s;
	cin>>s;
	int q;
	cin>>q;
	int n = s.length();
	int x = sqrt(s.length());
	int blocks = x + int(n != x*x);
	vector<vector<int>> a(blocks, vector<int> (26, 0));
	for(int i = 0 ; i < n ; i++){
		a[min(i/x, blocks-1)][s[i]-'a']++;
	}
	while(q--){
		int p;
		cin>>p;
		if(p==1){
			int pos;
			char c;
			cin>>pos>>c;
			pos--;
			a[min(pos/x, blocks-1)][s[pos]-'a']--;
			s[pos] = c;
			a[min(pos/x, blocks-1)][s[pos]-'a']++;
		}
		else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			int sl=min(l/x, blocks-1), sr=min(r/x, blocks-1);
			vector<int> ans(26, 0);
			if(sl != sr){
				for(int i = l ; i < sl*x+x ; i++){
					ans[s[i]-'a']++;
				}
				sl++;
				while(sl<sr){
					for(int i = 0; i < 26 ;i++){
						ans[i] += a[sl][i];
					}
					sl++;
				}
			}
			int sst;
			if(sl*x < l){
				sst = l;
			}
			else{
				sst = sl*x;
			}
			for(int i = sst ; i <= r ; i++){
				ans[s[i]-'a']++;
			}
			int ak = 0;
			for(int i = 0 ; i < 26 ; i++){
				if(ans[i]!=0) ak++;
			}
			cout<<ak<<'\n';
		}
		// tracevv(a);
		// cout<<'\n';
	}



	return 0;
}