#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	long long n, m, i, res=0, res1=0;
	cin>>n>>m;
	for(i=5;i<=n;i*=5) res=res+n/i;
	for(i=5;i<=m;i*=5) res=res-m/i;
	for(i=5;i<=n-m;i*=5) res=res-(n-m)/i;
    for(i=2;i<=n;i*=2) res1=res1+n/i;
	for(i=2;i<=m;i*=2) res1=res1-m/i;
	for(i=2;i<=n-m;i*=2) res1=res1-(n-m)/i;
	cout<<min(res,res1);
	
	return 0;
}
