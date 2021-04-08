#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int a, n, mmax=-2147000000, mmin=2147000000;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		mmax=max(mmax,a);
		mmin=min(mmin,a);
	}
	cout<<mmin<<" "<<mmax;
	return 0;
}
