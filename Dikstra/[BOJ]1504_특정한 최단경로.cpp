#include <bits/stdc++.h>
using namespace std;

struct compare{
	bool operator()(pair<int,int>a, pair<int,int>b){
		return a.second>b.second;
	}
};

vector<int> dikstra(int k, int n, vector<vector<pair<int, int> > >gragh){
	
	vector<int> dis(n+1,2147000000);
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare>Q;
	Q.push({k,0});
	dis[k]=0;
	
	while(!Q.empty()){
		int v=Q.top().first;
		int w=Q.top().second;
		Q.pop();
		for(int i=0;i<gragh[v].size();i++){
			if(dis[gragh[v][i].first]>w+gragh[v][i].second){
				dis[gragh[v][i].first]=w+gragh[v][i].second;
				Q.push({gragh[v][i].first, dis[gragh[v][i].first]});
			}
		}
	}
	
	return dis;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, e, a, b, c, i, v1, v2, road1, road2;
	cin>>n>>e;
	
	vector<vector<pair<int, int> > >gragh(n+1);
	vector<int> res(n+1);
	
	for(i=0;i<e;i++){
		cin>>a>>b>>c;
		gragh[a].push_back({b,c});
		gragh[b].push_back({a,c});
	}
	cin>>v1>>v2;
	res=dikstra(1, n, gragh);
	if(res[v1]!=2147000000 && res[v2]!=2147000000){
		road1=res[v1];
		road2=res[v2];
		res=dikstra(v1, n, gragh);
		if(res[v2]!=2147000000){
			road1+=res[v2];
			road2+=res[v2];
			res=dikstra(n, n, gragh);
			if(res[v1]!=2147000000 && res[v2]!=2147000000){
				road1+=res[v2];
				road2+=res[v1];
				cout<<min(road1, road2);
			}
			else if(res[v1]!=2147000000) cout<<road2+res[v1];
			else if(res[v2]!=2147000000) cout<<road1+res[v2];
			else cout<<"-1";
		}
		else cout<<"-1";
	}
	else if(res[v1]!=2147000000){
		road1=res[v1];
		res=dikstra(v1, n, gragh);
		if(res[v2]!=2147000000){
			road1+=res[v2];
			res=dikstra(n, n, gragh);
			if(res[v2]!=2147000000) cout<<road1+res[v2];
			else cout<<"-1";
		}
		else cout<<"-1";
	}
	else if(res[v2]!=2147000000){
		road2=res[v2];
		res=dikstra(v2, n, gragh);
		if(res[v1]!=2147000000){
			road2+=res[v1];
			res=dikstra(n, n, gragh);
			if(res[v1]!=2147000000) cout<<road2+res[v1];
			else cout<<"-1";
		}
		else cout<<"-1";
	}
	else cout<<"-1";
	
	return 0;
}
