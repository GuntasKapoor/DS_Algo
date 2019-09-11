// Guntas Singh
// Thapar University
#include <bits/stdc++.h>
using namespace std;



// If the constructors are called in an order, the destructors are called in a reverse order..!

class Test{

public:
	Test(){
		cout<<"Constructor Called "<<this<<endl;
	}
	~Test(){
		cout<<"Destructor Called "<<this<<endl;
	}
};


class Student{
static int totalStudents;
public:
	char *name;
	int age;
	Student(char name[]){
		// strcpy(this->name, name);
		age = 0;
		this->name = new char[strlen(name) + 1];
		totalStudents++;
		strcpy(this->name, name);
	}

	void print(){
		cout<<name<<endl;
	}

	Student(const Student &s){
		this->name = s.name;
		totalStudents++;
	}
	static int gettotalStudnets(){
		return age;
	}

};

int Student::totalStudents = 0;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Test t1, t2;
char name[] = "Guntas";
Student s1(name);
s1.print();
name[0] = 'Q';
Student s2(name);
s2.print();
s1.print();

Student s3(s1);
s1.name[2] = 'm';
s3.print();

// cout<<Student::totalStudents<<endl;
cout<<s1.gettotalStudnets();

}