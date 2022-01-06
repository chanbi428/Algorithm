#include <bits/stdc++.h>
using namespace std;

struct compare{
	bool operator()(pair<int,int>a, pair<int,int>b){
		return a.second>b.second;
	}
};

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int V, E, K, v, u, w, i;
	cin>>V>>E>>K;
	vector<pair<int, int> >gragh[V+1];
	vector<int> dis(V+1,2147000000);
	vector<int> ch(V+1);
	for(i=0;i<E;i++){
		cin>>v>>u>>w;
		gragh[v].push_back({u,w});
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare>Q;
	Q.push({K,0});
	dis[K]=0;
	while(!Q.empty()){
		v=Q.top().first;
		w=Q.top().second;
		Q.pop();
		for(i=0;i<gragh[v].size();i++){
			if(dis[gragh[v][i].first]>w+gragh[v][i].second){
				dis[gragh[v][i].first]=w+gragh[v][i].second;
				Q.push({gragh[v][i].first, dis[gragh[v][i].first]});
			}
		}
	}
	for(i=1;i<=V;i++){
		if(dis[i]==2147000000) cout<<"INF\n";
		else cout<<dis[i]<<"\n";
	}
	
	return 0;
}
