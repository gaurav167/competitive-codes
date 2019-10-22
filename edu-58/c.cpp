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


bool cmp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){
	return a.ss.ff<b.ss.ff;
}
bool comp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){
	return a.ss.ss<b.ss.ss;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int, pair<int,int>>> a(n);
		for(int i = 0 ; i < n ; i++){
			a[i].ff = i;
			cin>>a[i].ss.ff>>a[i].ss.ss;
		}
		vector<bool> ans(n, false);
		// sort(a.begin(), a.end(), comp);
		sort(a.begin(), a.end(), cmp);
		// vector<set<int>> s(1);
		// s[0].insert(a[0].ff);
		int end = a[0].ss.ss;
		int end2 = -1;
		// set<int> ans1, ans2;
		// ans1.insert(a[0].ff);
		bool side = true;
		// ans[a[0].ff] = true;
		// int dend = a[0].ss.ss;
		bool f = false, ff = true;
		for(int i = 1 ; i < n ; i++){
			if(a[i].ss.ff <= end){
				if(a[i].ss.ss == a[i].ss.ff && a[i].ss.ff == end){
					ff = false;
					break;
				}
				if(a[i].ss.ff <= end2){
					ff = false;
					break;
				}
				if(side) ans[a[i].ff] = true;
				// if(f) ans1.insert(a[i].ff);
				// else ans2.insert(a[i].ff);
				// s[s.size()-1].insert(a[i].ff);
				if(end <= a[i].ss.ss){
					side = !side;
					end2 = end;
					end = a[i].ss.ss;
				}
				else{
					end2 = max(end2, a[i].ss.ss);
				}
				// end2 = min(end2, a[i].ss.ss);
				// end = max(end, a[i].ss.ss);
				// if(a[i].ss.ff <= a[i-1].ss.ss)
				// 	if(!f) f = true;
				// 	else{
				// 		ff = false;
				// 		break;
				// 	}
				if(a[i].ss.ss == a[i].ss.ff){
					end2 = a[i].ss.ss;
				}
			}
			else{
				end = a[i].ss.ss;
				end2=-1;
				// side = !side;
				// f = false;
				if(side) ans[a[i].ff] = true;
				side = !side;

				// if(f) ans1.insert(a[i].ff);
				// else ans2.insert(a[i].ff);
				// set<int> ss;
				// ss.insert(a[i].ff);
				// s.pb(ss);
			}
		}
		if(!ff) cout<<"-1\n";
		else{
			for(int i = 0 ; i < n ; i++){
				if(ans[i]) cout<<"1 ";
				else{
					cout<<"2 ";
				}
			}
			cout<<'\n';
			
		}
		// vector<int> a(N, 0);
		// for(int i = 0 ; i < n ; i++){
		// 	int l,r;
		// 	cin>>l>>r;
		// 	a[l] += 1;
		// 	a[r] -= 1;
		// }
		// bool f = false;
		// int cnt=0;
		// for(int i = 0 ; i < N ; i++){
		// 	cnt+=a[i];
		// 	a[i] = cnt;
		// 	if(a[i] > 2){
		// 		f = false;
		// 		break;
		// 	}
		// }
		// if(!f){
		// 	cout<<"-1\n";
		// }
		// bool s = true;
		// vector<int> ans
		// else{
		// 	for(int i = 0 ; i < N ; i++){
		// 		if(a[i]!=0){
		// 			if(a[i]==1){

		// 			}
		// 		}
		// 	}
		// }



	}



	return 0;
}