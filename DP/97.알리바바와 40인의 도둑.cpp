#include <bits/stdc++.h>
using namespace std;

int bridge[20][20];
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, c, res=0;
	cin>>n;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>bridge[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==0&&j==0) continue;
			else if(i==0) bridge[i][j]+=bridge[i][j-1];
			else if(j==0) bridge[i][j]+=bridge[i-1][j];
			else{
				if(bridge[i-1][j]>bridge[i][j-1]) bridge[i][j]+=bridge[i][j-1];
				else bridge[i][j]+=bridge[i-1][j];
			}
		}
	}
	cout<<bridge[n-1][n-1];
	 
	return 0;
}

