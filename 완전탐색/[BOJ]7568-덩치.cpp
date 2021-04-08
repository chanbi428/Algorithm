#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int i, j, n, k, h, grade;
	
	cin>>n;
	vector<pair<int, int> > people(n);
	for(i=0;i<n;i++){
		cin>>k>>h;
		people[i]=make_pair(k,h);
	}
	for(i=0;i<n;i++){
		grade=0;
		for(j=0;j<n;j++){
			if(i==j) continue;
			if(people[i].first<people[j].first && people[i].second<people[j].second) grade++;
		}
		cout<<grade+1<<" ";
	}
		
	return 0;
}
