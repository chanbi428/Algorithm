#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, num;
	
	cin>>n;
	vector<vector<int> >stair(n+2, vector<int>(2));
	
	for(i=2;i<n+2;i++){
		cin>>num;
		stair[i][0]=stair[i-1][1]+num;
		stair[i][1]=max(stair[i-2][0],stair[i-2][1])+num;
	}
	cout<<max(stair[n+1][0],stair[n+1][1]);
		
	return 0;
}
