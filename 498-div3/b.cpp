#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.first > b.first) return true;
	return false;
}
bool com(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<pair<int,int>> a(n);
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin>>t;
		pair<int,int> L;
		L.first = t;
		L.second = i;
		a[i] = L;
	}
	sort(a.begin(), a.end(), comp);
	sort(a.begin(), a.begin()+k, com);
	int s = 0,b=-1,s1=0;
	vector<int> m(k);
	for(int i =0 ; i < k-1 ; i++){
		s+=a[i].first;
		m[i] = a[i].second - b;
		b=a[i].second;
		s1+=m[i];
	}
	s+=a[k-1].first;
	m[k-1] = n-a[k-1].second;
	s1+=m[k-1];
	if(s1<n){
		m[k-1]+=n-s1;
	}
	cout<<s<<'\n';
	for (int i = 0; i < k; ++i)
	{
		cout<<m[i]<<' ';
	}
	return 0;
}