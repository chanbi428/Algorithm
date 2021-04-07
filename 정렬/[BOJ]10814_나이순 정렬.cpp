#include <bits/stdc++.h>
using namespace std;

struct Person{
	int in, age;
	string name;
};
bool cmp(Person a, Person b){
	if(a.age==b.age) return a.in<b.in;
	return a.age<b.age;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("input.txt", "rt", stdin);
	
	int n, i, a;
	string b;
	cin>>n;
	vector<Person>llist(n);
	
	for(i=0;i<n;i++){
		cin>>llist[i].age>>llist[i].name;
		llist[i].in=i;
	}
	sort(llist.begin(), llist.end(),cmp);
	for(i=0;i<n;i++){
		cout<<llist[i].age<<" "<<llist[i].name<<"\n";
	}
		
	return 0;
}
