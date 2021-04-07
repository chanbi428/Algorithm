#include <bits/stdc++.h>
using namespace std;

bool compare(string str1, string str2) { 
    if (str1.length()==str2.length()) { 
        return str1<str2;
    }
    return str1.length()<str2.length();
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, x, y;
	string str;
	cin>>n;
	vector<string> word(n);
	
	for(i=0;i<n;i++){
		cin>>str;
		word[i]=str;
	}
	sort(word.begin(), word.end(),compare);
	for(i=0;i<n-1;i++){
		if(word[i]==word[i+1]) continue;
		cout<<word[i]<<"\n";
	}
	cout<<word[n-1]<<"\n";
		
	return 0;
}
