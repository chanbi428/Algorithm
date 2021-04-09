#include <bits/stdc++.h>
using namespace std;
	
vector<vector<int> > pre(10, vector<int>(10));

void cal(){
	vector<vector<int> > next(10, vector<int>(10));	
	for(int j=1;j<10;j++){
		for(int k=0;k<10;k++){
			if(pre[j][k]!=0){
				if(k==0) next[j][1]=(next[j][1]+pre[j][0])%1000000000;
				else if(k==9) next[j][8]=(next[j][8]+pre[j][9])%1000000000;
				else{
					next[j][k-1]=(next[j][k-1]+pre[j][k])%1000000000;
					next[j][k+1]=(next[j][k+1]+pre[j][k])%1000000000;
				}
			}
		}
	}
	pre=next;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, k, res=0;
	cin>>n;
	if(n==1) cout<<9;
	else{
		for(i=1;i<10;i++) pre[i][i]=1;
		for(i=1;i<n;i++){
			cal();
		}
		for(i=1;i<10;i++){
			for(j=0;j<10;j++){
 				res=(res+pre[i][j])%1000000000;
			}
		}
		cout<<res;
	}

		
	return 0;
}
