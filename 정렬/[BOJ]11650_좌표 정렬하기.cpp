#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n, i, x, y;
	cin>>n;
	vector<pair<int,int> > pos(n);
	
	for(i=0;i<n;i++){
		cin>>x>>y;
		pos[i]=make_pair(x,y);
	}
	sort(pos.begin(),pos.end());
	for(i=0;i<n;i++){
		cout<<pos[i].first<<" "<<pos[i].second<<"\n";
	}
		
	return 0;
}
