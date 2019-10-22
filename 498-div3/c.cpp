#include <iostream>
#include<vector>

using namespace std;

void solve2(vector<long long int> a, long long int s, long long int l){
	long long int i = s-1 , j = l+1, sl=0, sr=0, max = 0;
	while(i<j){
		i++; j--;
		if(i>=j) break;
		sl+=a[i];
		sr+=a[j];
		if(sl==sr){
			max+=sl;
			sl=0;
			sr=0;
		}
		while(i<j && sl<sr){
			if(++i>=j) break;
			sl+=a[i];
			if(sl==sr){
				max+=sl;
				sl=0; sr=0;
			}
		}
		while(i<j && sl>sr){
			if(--j<=i) break;
			sr+=a[j];
			if(sl==sr){
				max+=sl;
				sl=0; sr=0;
			}
		}
	}
	cout<<max;
}
int main(){
	long long int n;
	cin>>n;
	vector<long long int> a(n);
	for (long long int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	solve2(a,0,n-1);
	return 0;
}