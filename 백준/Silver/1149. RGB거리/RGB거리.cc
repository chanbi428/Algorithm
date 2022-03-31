#include <bits/stdc++.h>
using namespace std;

struct House{
	int r, g, b;
};
int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int t, r, g, b;
	House house[2]={0,0,0};
	
	cin>>t;
	while(t--){
		cin>>r>>g>>b;
		house[1].r=min(house[0].g, house[0].b)+r;
		house[1].g=min(house[0].r, house[0].b)+g;
		house[1].b=min(house[0].g, house[0].r)+b;
		house[0]=house[1];
	}
	cout<<min(min(house[1].r, house[1].g),house[1].b);
		
	return 0;
}
