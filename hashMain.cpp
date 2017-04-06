#include<iostream>
#include "hashtable.h"
using namespace std;

class Person{
public:
		char name[100];
		int phoneNo;
		int id_no;
	
	Person(){
		name[0] = '\0';
		phoneNo = -1;
		id_no = -1;
	}

	Person(char *n,int phoneNo,int id){
		strcpy(name,n);
		this->phoneNo = phoneNo;
		id_no = id;
	}
	void print(){
		cout<<"Name : "<<name<<endl;
		cout<<"Phone : "<<phoneNo<<endl;
		cout<<"Id : "<<id_no<<endl;
		cout<<endl;
	}
	
	//friend void operator<<(ostream &os , Person &p){}
};

//Helpful for Cascading (Return type)
ostream& operator<<(ostream &os, Person &p){
	os << p.name <<endl;
	os << p.phoneNo<<endl;
	os << p.id_no<<endl;
	cout<<endl;
	return os;
}


int main(){

hashTable<Person> hp;

Person p1("Prateek",10,20);
Person p2("Prabhjot",20,30);
Person p3("Komal",30,40);
Person p4("Chitranshi",40,50);
Person p5("Ishan",50,56);

//cout<<p1<<p2<<p3<<p4<<p5;

hp.insert(p1.name,p1);
hp.insert(p2.name,p2);
hp.insert(p3.name,p3);
hp.insert(p4.name,p4);
hp.insert(p5.name,p5);
hp.print();
char search_name[100];
cout<<"Enter the name of person to search ";

cin>>search_name;
Person ans = hp.find(search_name);

//hp.print();

if(ans.phoneNo== -1){
		cout<<"Not Found";
}
else{
	//ans.print();
	cout<<ans;
}


/*
hashTable<int> h1;
h1.insert("Prateek",50);
h1.insert("Prabjot",49);
h1.insert("Ishan",51);
h1.insert("Komal",60);
h1.print();
cout<<"Enter the name of the student";
char name[100];
cin>>name;
cout<<endl;
cout<<"Marks of the "<<name<<" is "<<h1.find(name);
*/

return 0;
}
