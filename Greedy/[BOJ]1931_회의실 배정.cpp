#include <bits/stdc++.h>
using namespace std;

pair<int, int> conf[100001];
bool comp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, e=0, cnt=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>conf[i].first>>conf[i].second;
	}
	sort(conf,conf+n,comp);
	for(i=0;i<n;i++){
		if(conf[i].first>=e){
			e=conf[i].second;
			cnt++;
		}
	}
	cout<<cnt;
		
	return 0;
}
