#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i;
    long long a, b, res;
	cin>>n;
	vector<long long>factor(n);
	for(i=0;i<n;i++){
		cin>>factor[i];
	}
    sort(factor.begin(),factor.end());
    res=factor[0]*factor[n-1];
	cout<<res;
		
	return 0;
}
