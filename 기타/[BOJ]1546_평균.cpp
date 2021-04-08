#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, g_max=0, g;
	double sum=0;
	cin>>n;
	vector<int>grade(n);
	for(int i=0;i<n;i++){
		cin>>g;
		grade[i]=g;
		g_max=max(g_max, g);
	}
	for(int i=0;i<n;i++){
		sum=sum+(double)grade[i]/g_max*100;
	}
	cout<<sum/n;
	return 0;
}
