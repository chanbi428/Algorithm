#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int n, m, i, answer=0;
	string s;
	unordered_map<string, bool> S;
	
	cin>>n>>m;
	
	for(i=0; i<n; i++){
		cin>>s;
		S[s]=true;
	}
	for(i=0; i<m; i++){
		cin>>s;
		if(S[s]==true) answer++;
	}
	cout<<answer;
	
	return 0;
}