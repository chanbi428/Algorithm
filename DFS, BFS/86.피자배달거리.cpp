#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdlib.h>
using namespace std;

int n, m, mmin=2147000000;
vector<pair<int,int> > home;
vector<pair<int,int> > pizza;
vector<int> ch;

void DFS(int p, int s){
	int i, j, d, sum=0;
	if(p==m){
		vector<int> dis(home.size(),2147000000);
		for(i=0;i<m;i++){
			for(j=0;j<home.size();j++){
				d=abs(home[j].first-pizza[ch[i]].first)+abs(home[j].second-pizza[ch[i]].second);
				if(d<dis[j]) dis[j]=d;
			}
		}
		for(i=0;i<home.size();i++){
			sum+=dis[i];
		}
		if(sum<mmin) mmin=sum;
	}
	else{
		for(i=s;i<pizza.size();i++){
			ch.push_back(i);
			DFS(p+1, i+1);
			ch.pop_back();
		}
	}
}

int main(int argc, char** argv) {
	
//	freopen("input.txt", "rt", stdin);
	int j, i, a;
	
	scanf("%d %d",&n, &m);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a);
			if(a==1) home.push_back(make_pair(i+1,j+1));
			else if(a==2) pizza.push_back(make_pair(i+1,j+1));
		}
	}

	DFS(0, 0);
	
	printf("%d",mmin);

	return 0;
}

