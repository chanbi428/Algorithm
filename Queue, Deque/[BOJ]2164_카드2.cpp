#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n, i;
	queue<int>card;
	cin>>n;
	for(i=1;i<=n;i++) card.push(i);
	while(card.size()!=1){
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout<<card.front();
	
	return 0;
}
