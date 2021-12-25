#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	int n, m, i, a, b, c, x=1, min=2147000000;
	vector<pair<int,int> > v[21];
	
	scanf("%d %d",&n, &m);
	vector<int> dis(n+1,2147000000);
	vector<int> ch(n+1);
	
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a, &b, &c);
		v[a].push_back(make_pair(b,c));
	}
	ch[1]=1;
	dis[1]=0;
	
	for(int j=0;j<n-1;j++){
		for(i=0;i<v[x].size();i++){
			if(dis[x]+v[x][i].second<dis[v[x][i].first]) dis[v[x][i].first]=dis[x]+v[x][i].second;
		}
		for(i=1;i<=n;i++){
			if(ch[i]==0){
				if(min>dis[i]){
					min=dis[i];
					x=i;
				}
			}
		}
		ch[x]=1;
		min=2147000000;
	}
	
	for(i=2;i<=n;i++){
		printf("%d : ",i);
		if(dis[i]!=2147000000) printf("%d\n", dis[i]);
		else printf("imposible\n");
	}


	return 0;
}

