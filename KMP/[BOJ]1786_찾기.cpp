#include <bits/stdc++.h>
using namespace std;

vector<int> answer;

void getPI(vector<int> &pi, string &str2){
	int j=0;
	for(int i=1; i<str2.size(); i++){
		while(j>0 && str2[i]!=str2[j]) j=pi[j-1];
		if(str2[i]==str2[j]) pi[i]=++j;
	}
}
void KMP(string str1, string str2, vector<int> &pi){
	int j=0;
	for(int i=0; i<str1.size(); i++){
		while(j>0 && str1[i]!=str2[j]) j=pi[j-1];
		if(str1[i]==str2[j]){
			if(j==str2.size()-1){
				answer.push_back(i-j+1);
				j=pi[j];
			}
			else j++;
		}
	}
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	string str1, str2;
	
	getline(cin, str1);
	getline(cin, str2);
	
	vector<int> pi(str2.size());
	getPI(pi, str2);
	KMP(str1, str2, pi);
	
	cout<<answer.size()<<"\n";
	for(int i=0; i<answer.size(); i++) cout<<answer[i]<<" ";
	
	return 0;
}