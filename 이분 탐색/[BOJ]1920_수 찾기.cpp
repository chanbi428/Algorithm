#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, m, j=0, a;
	cin>>n;
	vector<int>arr1(n);
	for(int i=0;i<n;i++) cin>>arr1[i];
	cin>>m;
	vector<pair<int, int> >arr2(m);
	vector<pair<int, int> >res(m);
	for(int i=0;i<m;i++){
		cin>>a;
		arr2[i]={a,i};
	}
	
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	
	for(int i=0;i<m;i++){
		while(arr1[j]<arr2[i].first && j<n) j++;
		if(arr1[j]==arr2[i].first) res[i]={arr2[i].second,1};
		else res[i]={arr2[i].second,0};
	}
	
	sort(res.begin(), res.end());
	for(int i=0;i<m;i++) cout<<res[i].second<<"\n";
	
	return 0;
}
