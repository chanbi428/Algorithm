#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	vector<vector<int> >apart(15, vector<int>(15,1));
	int t, k, n, i, j;
	
	for(i=1;i<15;i++) apart[0][i]=i;
	for(i=1;i<15;i++){
		for(j=2;j<15;j++){
			apart[i][j]=apart[i][j-1]+apart[i-1][j];
		}
	}
	cin>>t;
	for(i=0;i<t;i++){
		cin>>k>>n;
		cout<<apart[k][n]<<"\n";
	}
		
	return 0;
}
