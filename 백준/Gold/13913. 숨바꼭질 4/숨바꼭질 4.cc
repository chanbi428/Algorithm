#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k;
	cin>>n>>k;
	vector<int>path(100001, -1);
	queue<pair<int, int> >Q;
	vector<int>result;
	Q.push({n, 0});
	path[n]=-2;
	
	while(!Q.empty()){
		int num=Q.front().first;
		int cnt=Q.front().second;
		Q.pop();
		if(num==k){
			cout<<cnt<<"\n";
			int m=num;
			while(m!=-2){
				result.push_back(m);
				m=path[m];
			}
			break;
		}
		if(num!=0 && path[num-1]==-1){
			path[num-1]=num;
			Q.push({num-1, cnt+1});
		}
		if(num!=100000 && path[num+1]==-1){
			path[num+1]=num;
			Q.push({num+1, cnt+1});
		}
		if(num*2<=100000 && path[num*2]==-1){
			path[num*2]=num;
			Q.push({num*2, cnt+1});
		}
	}
	for(int i=result.size()-1; i>=0; i--) cout<<result[i]<<" ";
	
	return 0;
}
