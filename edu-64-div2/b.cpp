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
template<typename T> void tracevp(T &a) { for(auto &i:a) { trace2(i.ff, i.ss); } cout<<'\n'; }

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		map<char, int> m;
		for(int i = 0 ; i < s.length() ; i++){
			if(m.find(s[i]) == m.end()) m[s[i]] = 1;
			else m[s[i]]++;
		}
		vector<char> ans;
		ans.pb(m.begin()->ff);
		bool f = true;
		for(auto i = m.rbegin() ; i != m.rend() ; i++){
			auto q = i;
			q++;
			if(q == m.rend()) break;
			if(f){
				ans.pb(i->ff);
			}
			else ans.insert(ans.begin(), i->ff);
			f = !f;
		}
		bool ff = true;
		for(int i = 0 ; i < ans.size()-1 ; i++){
			if(abs(ans[i] - ans[i+1]) == 1){
				ff = false;
				break;
			}
		}
		if(ff){
			for(int i = 0 ; i < ans.size() ; i++){
				for(int j = 0 ; j < m[ans[i]] ; j++){
					cout<<ans[i];
				}
			}
			cout<<'\n';
		}
		else{
			if(m.size() == 3){
				vvi b = {{0, 1, 2}, {1, 0 ,2}, {2, 0, 1}};
				for(int ii = 0 ; ii < 3 ; ii++){
					if(abs(ans[b[ii][0]]-ans[b[ii][1]])!=1 && abs(ans[b[ii][0]]-ans[b[ii][2]])!=1){
						for(int i = 0 ; i < m[ans[b[ii][1]]] ; i++) cout<<ans[b[ii][1]];
						for(int i = 0 ; i < m[ans[b[ii][0]]] ; i++) cout<<ans[b[ii][0]];
						for(int i = 0 ; i < m[ans[b[ii][2]]] ; i++) cout<<ans[b[ii][2]];
						cout<<'\n';
						ff = true;
						break;
					}
				}
			}
			if(!ff) cout<<"No answer\n";
		}
	}
	


	return 0;
}