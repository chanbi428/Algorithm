#include <bits/stdc++.h>
using namespace std;

int ch[100001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, k, res;
	queue<pair<int, int> >Q;
	cin>>n>>k;
	
	Q.push({n, 0});
	ch[n]=1;
	while(!Q.empty()){
		int pos=Q.front().first;
		int l=Q.front().second;
		Q.pop();
		if(pos==k){
			cout<<l;
			break;
		}
		if(pos-1>=0 && ch[pos-1]==0){
			ch[pos-1]=1;
			Q.push({pos-1, l+1});
		}
		if(pos+1<=100000 && ch[pos+1]==0){
			ch[pos+1]=1;
			Q.push({pos+1, l+1});
		}
		if(pos*2<=100000 && ch[pos*2]==0){
			ch[pos*2]=1;
			Q.push({pos*2, l+1});
		}
	}
	
	return 0;
}
