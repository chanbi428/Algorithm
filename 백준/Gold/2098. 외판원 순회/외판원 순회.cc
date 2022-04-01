#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, answer;
int arr[16][16];
int cost[16][1<<16];

int dfs(int node, int cur_cost){
	if(cur_cost==answer){
		if(arr[node][0]==0) return 20000000;
		return arr[node][0];
	}
	if (cost[node][cur_cost]!=-1) return cost[node][cur_cost];
    cost[node][cur_cost] = 20000000;
	
	for(int i=0; i<n; i++){
		if(arr[node][i]==0) continue;
		if((cur_cost&(1<<i))==(1<<i)) continue;
		
		cost[node][cur_cost]=min(cost[node][cur_cost], arr[node][i]+dfs(i,cur_cost|(1<<i)));
	}
	return cost[node][cur_cost];
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   cin>>n;
   answer=(1<<n)-1;
   memset(cost, -1, sizeof(cost));

   for(int i=0; i<n; i++){
   	for(int j=0; j<n; j++){
   		cin>>arr[i][j];
	   }
   }
   cout<<dfs(0,1);
   
   return 0;
}