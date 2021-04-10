#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long n, i, mmin=2147000000, km;
	long long res=0;
	cin>>n;
	vector<long long>dis(n-1);
	for(i=0;i<n-1;i++){
		cin>>dis[i];
	}
	for(i=0;i<n-1;i++){
		cin>>km;
		mmin=min(mmin, km);
		res+=mmin*dis[i];
	}
	cout<<res;
		
	return 0;
}
