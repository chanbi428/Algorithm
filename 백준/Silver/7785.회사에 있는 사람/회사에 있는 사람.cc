#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(int argc, char** argv) {
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   //freopen("input.txt", "rt", stdin);
   
   int n;
   string name, state;
   map<string, bool, greater<string> > record;
   cin>>n;
   
   for(int i=0; i<n; i++){
   	cin>>name>>state;
   	if(state=="enter") record[name]=true;
   	else record[name]=false;
   }
   for(auto i=record.begin(); i!=record.end(); i++){
   	if(i->second==true) cout<<i->first<<"\n";
   }
   
   return 0;
}