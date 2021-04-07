#include <bits/stdc++.h>
using namespace std;

int num[1000001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int i, j, n, m, flag=0;
	num[1]=1;
	cin>>m>>n;
	for(i=2;i<=n;i++){
		if(num[i]==0){
			for(j=1;j*i<=n;j++){
				num[j*i]++;
			}
			if(i>=m) cout<<i<<"\n";
		}
	}
		
	return 0;
}
