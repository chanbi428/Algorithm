#include <bits/stdc++.h>
using namespace std;

int people[1001];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, sum=0, m;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>people[i];
	}
	sort(people,people+n);
	m=n;
	for(i=0;i<n;i++){
		sum+=people[i]*m;
		m--;
	}
	cout<<sum;
		
	return 0;
}
