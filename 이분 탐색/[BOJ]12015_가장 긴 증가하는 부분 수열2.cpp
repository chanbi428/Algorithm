#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, j, num;
	vector<int>A;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num;
		if(A.empty() || A[A.size()-1]<num) A.push_back(num);
		else{
			for(j=0; j<A.size(); j++){
				if(A[j]>=num){
					A[j]=num;
					break;
				}
			}
		}
	}
	cout<<A.size();

	
	return 0;
}
