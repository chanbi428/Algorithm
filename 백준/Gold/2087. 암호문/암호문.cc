#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int a[40];
map<int, int>map1;
map<int, int, greater<int> >map2;

void find(int n, int st){
	bitset<20> bit;
	int s=1<<n;
	for(int i=0; i<s; i++){
   	bit=bitset<20>(i);
   	
   	int tmp=0;
	for(int j=0; j<n; j++){
   		tmp+=a[st+j]*bit[j];
	}
	//string str=bit.to_string();
	if(st==0) map1[tmp]=(int)(bit.to_ulong());//str.substr(20-n);
	else map2[tmp]=(int)(bit.to_ulong());//str.substr(20-n);
   }
}

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int n, k, an, bn;
   cin>>n;
   
   for(int i=0; i<n; i++) cin>>a[i];
   cin>>k;
   
   an=n/2;
   if(n%2==0) bn=n/2;
   else bn=n/2+1;
   
   find(an, 0);
   find(bn, n/2);
   
   auto s=map1.begin();
   auto e=map2.begin();
   while(s!=map1.end() && e!=map2.end()){
   	int aa=s->first, bb=e->first;
   	if(aa+bb==k){
   		int num1=s->second;
   		int num2=e->second;
   		bitset<20>bit1(num1);
   		bitset<20>bit2(num2);
   		
		string str1=bit1.to_string();
   		string str2=bit2.to_string();
   		str1=str1.substr(20-an);
   		str2=str2.substr(20-bn);
   		reverse(str1.begin(), str1.end());
   		reverse(str2.begin(), str2.end());
   		
   		cout<<str1+str2;
   		break;
	   }
	else if(aa+bb>k){
		e++;
	}
	else{
		s++;
	}
   }
   
   return 0;
}