#include <bits/stdc++.h>
using namespace std;

int l, c, m_cnt=0, j_cnt=0;
vector<char> alpha;
vector<int> ch;
vector<char> res;

void Pass(int s, int n){
	if(s==l){
		if(m_cnt>=1 && j_cnt>=2){
			for(int i=0;i<l;i++){
				cout<<res[i];
			}
			cout<<"\n";
		}
	}
	else{
		for(int i=n;i<c;i++){
			if(ch[i]==0){
				if(alpha[i]=='a'||alpha[i]=='e'||alpha[i]=='i'||alpha[i]=='o'||alpha[i]=='u') m_cnt++;
				else j_cnt++;
				res.push_back(alpha[i]); 
				ch[i]=1;
				Pass(s+1, i+1);
				if(alpha[i]=='a'||alpha[i]=='e'||alpha[i]=='i'||alpha[i]=='o'||alpha[i]=='u') m_cnt--;
				else j_cnt--;
				ch[i]=0;
				res.pop_back();
			}
		}
	}
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	char a;
	cin>>l>>c;
	for(int i=0;i<c;i++){
		cin>>a;
		alpha.push_back(a);
		ch.push_back(0);
	}
	sort(alpha.begin(), alpha.end());
	Pass(0, 0);
	 
	return 0;
}
