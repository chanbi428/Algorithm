#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, m, i, j, k, a, b, c;
	
	cin>>n>>m;
	vector<vector<int> >cost(n, vector<int>(n));
	
	for(i=0; i<m; i++){
	    cin>>a>>b>>c;
	    if(cost[a-1][b-1]==0)  cost[a-1][b-1]=c;
	    else cost[a-1][b-1]=min(c, cost[a-1][b-1]);
	}
	
	for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	        if(j==i) continue;
	        for(k=0; k<n; k++){
	            if(i==k || j==k) continue;
	            if(cost[j][i]==0 || cost[i][k]==0) continue;
	            if(cost[j][k]==0) cost[j][k]=cost[j][i]+cost[i][k];
	            else cost[j][k]=min(cost[j][k], cost[j][i]+cost[i][k]);
	        }
	    }
	}
	
	for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
	        cout<<cost[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	
	return 0;
}