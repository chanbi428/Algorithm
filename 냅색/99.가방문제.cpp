#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, i, j, weight, worth;
	cin>>n>>m;
	vector<int> bag(m+1);

	for(i=0;i<n;i++){
		cin>>weight>>worth;
		for(j=weight;j<=m;j++){
			if(bag[j-weight]+worth>bag[j]) bag[j]=bag[j-weight]+worth;
		}
	}
	cout<<bag[m];
	 
	return 0;
}

