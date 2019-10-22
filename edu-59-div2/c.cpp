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
const int N = 2e5+10;
int n, k;
// int t[2*N];
vector<pair<int,int>> t(2*N);
void build(){
	for(int i = n - 1; i > 0; --i){
		t[i].ff = max(t[i<<1].ff, t[i<<1|1].ff);
		t[i].ss = (t[i<<1].ff>t[i<<1|1].ff)?t[i<<1].ss:t[i<<1|1].ss;
	}
}
void modify(int p, int value){
	for(t[p+=n].ff = value ; p>1 ; p>>=1){
		t[p>>1].ff = max(t[p].ff, t[p^1].ff);
		t[p>>1].ss = (t[p].ff>t[p^1].ff)?t[p].ss:t[p^1].ss;
	}
}
pair<int,int> query(int l, int r){
	pair<int,int> res = mp(INT_MIN, -1);
  	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
    	if (l&1){
    		if(t[l].ff>res.ff){
    			res.ff = t[l].ff;
    			res.ss = t[l].ss;
    		}
    		l++;
    	}
    	if (r&1){
    		if(t[--r].ff>res.ff){
	    		res.ff = t[r].ff;
	    		res.ss = t[r].ss;
    		}
    	}
  }
  return res;
}

lli add(int len , int en){
	lli ans = 0;
	int st = en - len + 1;
	for(int i = 0 ; i < k ; i++){
		pair<int,int> q = query(st, en+1);
		// trace2(q.ff, q.ss);
		ans += q.ff;
		modify(q.ss, INT_MIN);
	}
	return ans;
}
int main(){
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>t[i+n].ff;
		t[i+n].ss=i;
	}
	string s;
	cin>>s;
	s+='Z';
	build();
	lli ans = 0;
	char prev = s[0];
	int len = 1;
	lli sum = t[n].ff;
	for(int i = 1 ; i < s.length() ; i++){
		if(s[i] == prev){
			len++;
			sum += t[i+n].ff;
		}
		else{
			if(len <= k){
				ans += sum;
				// trace2(ans, sum);
			}
			else{
				// trace2(len, i-1);
				ans += add(len, i-1);
				// trace1(ans);
			}
			len = 1;
			prev = s[i];
			sum = t[i+n].ff;
		}
	}
	cout<<ans;
	return 0;
}