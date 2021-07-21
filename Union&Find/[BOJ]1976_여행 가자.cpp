#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[201];

int find(int v){
	if(root[v]==v) return v;
	else return root[v]=find(root[v]);
}

void unio(int x, int y){
	x=find(x);
	y=find(y);
	root[x]=y;
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, m, i, j, num, a, b;
	
	cin>>n>>m;
	
	for(i=1; i<n+1; i++) root[i]=i;
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			cin>>num;
			if(j<=i) continue;
			if(num==1){
				unio(i+1, j+1);
			}
		}
	}
	
	cin>>a;
	for(i=1; i<m; i++){
		cin>>b;
		if(find(a)==find(b)) a=b;
		else{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	
	return 0;
}
