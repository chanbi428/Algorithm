#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	string a,b;
	stack<int> res;
	int i, al, bl, carry=0;
	
	cin>>a>>b;
	al=a.length();
	bl=b.length();
	//big=max(a.length(), b.length());
	while(al!=0 &&bl!=0){
		res.push((a[al-1]+b[bl-1]+carry-96)%10);
		carry=(a[al-1]+b[bl-1]+carry-96)/10;
		al--;
		bl--;
	}
	if(al!=0){
		while(al!=0){
			res.push((a[al-1]+carry-48)%10);
			carry=(a[al-1]+carry-48)/10;
			al--;
		}
	}
	else if(bl!=0){
		while(bl!=0){
			res.push((b[bl-1]+carry-48)%10);
			carry=(b[bl-1]+carry-48)/10;
			bl--;
		}
	}
	if(carry!=0) res.push(carry);
	while(!res.empty()){
		cout<<res.top();
		res.pop();
	}
		
	return 0;
}
