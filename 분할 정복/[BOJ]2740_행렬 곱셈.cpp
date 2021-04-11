#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, k, i, j, tmp, a, b;
	cin>>n>>m;
	vector<vector<int> >arr1(n,vector<int>(m));
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin>>arr1[i][j];
		}
	}
	cin>>m>>k;
	vector<vector<int> >arr2(m,vector<int>(k));
	for(i=0; i<m; i++){
		for(j=0; j<k; j++){
			cin>>arr2[i][j];
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<k; j++){
			tmp=0;
			for(a=0; a<m; a++){
				tmp+=arr1[i][a]*arr2[a][j];
			}
			cout<<tmp<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}
