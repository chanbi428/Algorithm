#include <bits/stdc++.h>
using namespace std;

int tri[510][510];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, num, res=0;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			cin>>num;
			tri[i+1][j+1]=num+max(tri[i][j],tri[i][j+1]);
		}
	}
	for(i=1;i<=n;i++) res=max(res,tri[n][i]);
	cout<<res;
		
	return 0;
}
