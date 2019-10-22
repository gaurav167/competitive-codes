#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	// vector<int> a(n);
	for(int i = 0 ; i < n ; i++){
		int k;
		cin>>k;
		if(k%2==0){
			k-=1;
		}
		cout<<k<<' ';
	}

	return 0;
}