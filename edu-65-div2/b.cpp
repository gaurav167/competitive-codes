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

int ask(int a, int b){
	cout<<"? "<<a<<' '<<b<<'\n';
	cout.flush();
	int y;
	cin>>y;
	if(y==-1) exit(0);
	return y;
}

vector<int> solve(int y){
	vector<int> a(2);
	if(y%128 == 0){
		a[0] = 16;
		a[1] = 8;
	}
	else if(y%64==0){
		a[0] = 4;
		a[1] = 16;
	}
	else if(y%32 ==0){
		if(y%3==0){
			a[0] = 42;
			a[1] = 16;
		}
		else{
			a[0] = 4;
			a[1] = 8;
		}
	}
	else if(y%16==0){
		if(y%7==0){
			a[0] = 42;
			a[1] = 8;
		}
		else if(y%5==0){
			a[0] = 15;
			a[1] = 16;
		}
		else{
			a[0] = 23;
			a[1] = 16;
		}
	}
	else if(y%8==0){
		if(y%5==0){
			a[0] = 8;
			a[1] = 15;
		}
		else if(y%23==0){
			a[0] = 23;
			a[1] = 8;
		}
		else{
			a[0] = 4;
			a[1] = 42;
		}
	}
	else if(y%4==0){
		if(y%23==0){
			a[0] = 23;
			a[1] = 4;
		}
		else{
			a[0] = 4;
			a[1] = 15;
		}
	}
	else if(y%2 == 0){
		if(y%23 ==0){
			a[0] = 23;
			a[1] = 42;
		}
		else{
			a[0] = 42;
			a[1] = 15;
		}
	}
	else{
		a[0] = 15;
		a[1] = 23;
	}
	return a;
}
int main(){
	vector<int> res(6);
	int y1 = ask(1,2);
	int y2 = ask(2,3);
	vector<int> a1 = solve(y1);
	vector<int> a2 = solve(y2);
	if(a1[0] == a2[0] || a1[0] == a2[1]){
		res[1] = a1[0];
		res[0] = y1/res[1];
		res[2] = y2/res[1];
	}
	else{
		res[1] = a1[1];
		res[0] = y1/res[1];
		res[2] = y2/res[1];
	}

	int y3 = ask(4,5);
	int y4 = ask(5,6);
	vector<int> a3 = solve(y3);
	vector<int> a4 = solve(y4);
	
	if(a3[0] == a4[0] || a3[0] == a4[1]){
		res[4] = a3[0];
		res[3] = y3/res[4];
		res[5] = y4/res[4];
	}
	else{
		res[4] = a3[1];
		res[3] = y3/res[4];
		res[5] = y4/res[4];
	}
	cout<<"! ";
	for(auto &i:res) cout<<i<<' ';
	cout<<'\n';
	cout.flush();


	return 0;
}