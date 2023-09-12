#include <iostream>
#include "PatientPriorityQueue.h"
using namespace std;

int main() {
PatientPriorityQueue q;

PatientType p1("Ola","Ahmad",50,3);
PatientType p2("Omar","Abd-Alaziz",48,1);
PatientType p3("Obada","Khalid",45,2);
PatientType p4("Razan","Jamal",35,3);
PatientType p5("Samar","Mousa",23,5);
PatientType p6("Noor","Omar",20,4);
  
q.addPatient(p1);
q.addPatient(p2);
q.addPatient(p3);
q.addPatient(p4);
q.addPatient(p5);
q.addPatient(p6);

q.printPriorityQueue();
cout<<endl;


cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();
 
q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl; 

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

cout<<"******the patient in the front is: ******"<<endl;
q.frontPatient();

q.deletePatient();
cout<<endl;
q.printPriorityQueue();
cout<<endl;

 }