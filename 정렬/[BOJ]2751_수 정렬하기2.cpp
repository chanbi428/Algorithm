#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n, a, i, j, tmp;
	
	cin>>n;
	vector<int>num(n);
	
	for(i=0;i<n;i++){
		cin>>a;
		num[i]=a;
	}
    sort(num.begin(),num.end());
	for(i=0;i<n;i++){
		cout<<num[i]<<"\n";
	}
	

		
	return 0;
}
