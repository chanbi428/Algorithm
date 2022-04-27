#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	
	int h, w, answer=0;
	cin>>h>>w;
	vector<int> block(w);
	
	for(int i=0; i<w; i++){
		cin>>block[i];
	}
	for(int i=1; i<w-1; i++){
		int left=0, right=0;
		for(int j=0; j<i; j++) left=max(left, block[j]);
		for(int j=i+1; j<w; j++) right=max(right, block[j]);
		int rain = min(left, right);
		if(rain>block[i]) answer+=rain-block[i];
	}
	cout<<answer;
	
	return 0;
}