#include <bits/stdc++.h>
using namespace std;

int n, power[21][21], ch[21], dif=100;

void DFS(int p, int s){
	if(p==n/2){
		int sta=0, lin=0;
		vector<int> sp;
		vector<int> lp;
		for(int i=1; i<=n; i++){
			if(ch[i]==1) sp.push_back(i);
			else lp.push_back(i);
		}
		for(int i=0; i<n/2-1; i++){
			for(int j=i+1; j<n/2; j++){
				sta+=power[sp[i]][sp[j]]+power[sp[j]][sp[i]];
				lin+=power[lp[i]][lp[j]]+power[lp[j]][lp[i]];
			}
		}
		dif=min(dif, abs(sta-lin));
		if(dif==0){
			cout<<dif;
			exit(0);
		}
	}
	else{
		for(int i=s; i<=n; i++){
			ch[i]=1;
			DFS(p+1, i+1);
			ch[i]=0;
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int i, j;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>power[i][j];
		}
	}
	DFS(0, 1);
	cout<<dif;
	
	 
	return 0;
}
