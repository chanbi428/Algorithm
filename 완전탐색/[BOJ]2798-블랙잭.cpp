#include <bits/stdc++.h>
using namespace std;

int n, m, res;
vector<int> card;

void game(int num, int sum, int index){
	if(num==3){
		if(sum<=m) res=max(res,sum);
		return;
	}
	if(index==n) return;
	for(int i=index;i<n;i++){
		game(num+1, sum+card[i], i+1);
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, a;
	
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a;
		card.push_back(a);
	}
	
	game(0,0,0);
	cout<<res;
		
	return 0;
}
