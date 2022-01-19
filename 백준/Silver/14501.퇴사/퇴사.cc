#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);

	int n, i;
	
	cin>>n;
	
	vector<pair<int, int> > work(n);
	vector<int> answer(n+1);
	
	for(i=0; i<n; i++) cin>>work[i].first>>work[i].second;
	
	for(i=n-1; i>=0; i--){
		if(work[i].first+i<n){
			answer[i]=work[i].second+answer[i+work[i].first];	
		}
		else if(work[i].first+i==n) answer[i]=work[i].second;
		answer[i]=max(answer[i], answer[i+1]);
	}

	cout<<answer[0];
	
	return 0;
}