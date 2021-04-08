#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	
	int c, n, g, sum, cnt;
	double avg, res;
	cin>>c;
	for(int i=0;i<c;i++){
		cin>>n;
		vector<int>stu(n);
		sum=0;
		for(int j=0;j<n;j++){
			cin>>g;
			stu[j]=g;
			sum+=g;
		}
		avg=(double)sum/n;
		cnt=0;
		for(int j=0;j<n;j++){
			if(avg<stu[j]) cnt++;
		}
		res=(double)cnt/n*100;
		cout << fixed;
		cout.precision(3);
		cout<<res<<"%\n";
	}
		
	return 0;
}
