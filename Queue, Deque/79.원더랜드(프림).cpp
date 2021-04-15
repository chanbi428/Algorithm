#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int sum=0, ch[101];

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int n, m, i, a, b, c, x;
	vector<pair<int,int> > Ed[101];
	priority_queue<pair<int,int> > pQ;
	
	scanf("%d %d",&n, &m);
	for(i=0;i<m;i++){
		scanf("%d %d %d",&a, &b, &c);
		Ed[a].push_back(make_pair(c, b));
		Ed[b].push_back(make_pair(c, a));
	}
	ch[1]=1;
	x=1;
	while(n>1){
		for(i=0;i<Ed[x].size();i++){
			if(ch[Ed[x][i].second]==0) pQ.push(make_pair(-Ed[x][i].first,Ed[x][i].second));
		}
		while(ch[pQ.top().second]==1){
			pQ.pop();
		}
		x=pQ.top().second;
		sum-=pQ.top().first;
		pQ.pop();
		ch[x]=1;
		n--;	
	}
	
	printf("%d", sum);


	return 0;
}

