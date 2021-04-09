#include <bits/stdc++.h>
using namespace std;

int num[1000001];
queue<pair<int, int> > Q; 

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, x, cnt;	
	cin>>n;

	Q.push(make_pair(n, 0));
	while(!Q.empty()){
		x = Q.front().first;
		cnt= Q.front().second;
		Q.pop();
		num[x]=1;
		if(x==1) break;
		if(x%3==0 && num[x/3]==0) Q.push(make_pair(x/3, cnt+1));
		if(x%2==0 && num[x/2]==0) Q.push(make_pair(x/2, cnt+1));
		if(num[x-1]==0) Q.push(make_pair(x-1, cnt+1));
	}
	cout<<cnt;

		
	return 0;
}
