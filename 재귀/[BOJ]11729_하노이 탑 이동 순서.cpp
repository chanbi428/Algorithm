#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > res;
void hanoi(int num, int start, int end){
	int mid;
	if(num==1){
		res.push_back(make_pair(start, end));
		return;
	}
	mid=6-(start+end);
	hanoi(num-1, start, mid);
	hanoi(1, start, end);
	hanoi(num-1, mid, end);
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int n;
	cin>>n;
	hanoi(n,1,3);
	
	cout<<res.size()<<"\n";
	for(int i=0;i<res.size();i++) cout<<res[i].first<<" "<<res[i].second<<"\n";
		
	return 0;
}
