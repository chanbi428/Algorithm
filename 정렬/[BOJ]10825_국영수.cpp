#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Student{
	string name;
	int kor, eng, mat;
	Student(string n, int k, int e, int m){
		name=n;
		kor=k;
		eng=e;
		mat=m;
	}
};

bool comp(Student a, Student b){
	if(a.kor==b.kor){
		if(a.eng==b.eng){
			if(a.mat==b.mat) return a.name<b.name;
			return a.mat>b.mat;
		}
		return a.eng<b.eng;
	}
	return a.kor>b.kor;
}

int main(int argc, char** argv) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "rt", stdin);

	int n, kor, eng, mat, i;
	string name;
	vector<Student> student;
	cin>>n;
	
	for(i=0; i<n; i++){
		cin>>name>>kor>>eng>>mat;
		student.push_back(Student(name, kor, eng, mat));
	}
	sort(student.begin(), student.end(), comp);
	for(int i=0; i<n; i++){
		cout<<student[i].name<<"\n";
	}
	
	return 0;
}