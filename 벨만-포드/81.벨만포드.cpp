#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main(int argc, char** argv) {
	
	freopen("input.txt", "rt", stdin);
	int n, m, i, a, b, c, s, e, j;
	int u,v,w;
	vector<Edge> Ed;
	
	scanf("%d %d",&n, &m);
	vector<int> dist(n+1,2147000000);
	vector<int> dist2(n+1,2147000000);
	
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a, &b, &c);
		Ed.push_back(Edge(a,b,c));
	}
	scanf("%d %d",&s, &e);
	dist2[s]=0;
	
	for(i=1;i<n;i++){
		for(j=0;j<Ed.size();j++){
			u=Ed[j].s;
			v=Ed[j].e;
			w=Ed[j].val;
			if(dist2[u]!=2147000000&&dist2[u]+w<dist2[v]){
				dist[v]=dist2[u]+w;
			}
		}
		dist[s]=0;
		dist2=dist;
	}
	for(j=0;j<Ed.size();j++){
		u=Ed[j].s;
		v=Ed[j].e;
		w=Ed[j].val;
		if(dist[u]!=2147000000&&dist[u]+w<dist[v]){
			printf("-1");
			exit(0);
		}
	}
	
	printf("%d",dist[e]);


	return 0;
}

