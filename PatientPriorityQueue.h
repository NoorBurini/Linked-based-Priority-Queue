#ifndef H_PatientPriorityQueue
#define H_PatientPriorityQueue

#include <iostream>
using namespace std;

class PatientType{
public:
string firstname;
string lastname;
int age;
int priority;
PatientType(string,string,int,int=1);//O(1)
PatientType();//O(1)
void printPatientInfo();//O(1)
};

PatientType::PatientType(){
  firstname="";
  lastname="";
  age=40;
  priority=1;
}

PatientType::PatientType(string fn,string ln,int a,int p){
firstname=fn;
lastname=ln;
age=a;
if(p<1)
priority=1;
else
priority=p;
}

void PatientType::printPatientInfo(){
cout<<firstname<<" "<<lastname<<", "<<age<<" years, Priority = "<<priority<<endl;
}

class PatientNode{
public:
PatientType patient;
PatientNode * next;
};

class PatientPriorityQueue{
PatientNode *queuefront;
PatientNode *queuerear;
public:
PatientPriorityQueue();//O(1)
~PatientPriorityQueue();//O(n)
bool isempty();//O(1)
bool isfull();//O(1)
void initializeQueue();//O(n)
void printPriorityQueue();//O(n)
void addPatient(PatientType p);//O(1)
void deletePatient();//O(n)
void frontPatient();//O(n)
};

PatientPriorityQueue::PatientPriorityQueue(){
queuefront=NULL;
queuerear=NULL;
}

PatientPriorityQueue::~PatientPriorityQueue(){
initializeQueue();
}

bool PatientPriorityQueue::isempty(){
  return (queuefront==NULL);
}

bool PatientPriorityQueue::isfull(){
 return false;//the queue implemented by linked list so it will never be full
}

void PatientPriorityQueue::initializeQueue(){
PatientNode *temp;
while(queuefront != NULL){
temp = queuefront;
queuefront = queuefront->next;
delete temp;
}
queuerear = NULL;
}

void PatientPriorityQueue::printPriorityQueue(){
PatientNode *current;
current=queuefront;
while(current!=NULL){
current->patient.printPatientInfo();
current=current->next;}
}

void PatientPriorityQueue::addPatient(PatientType p){
PatientNode *newpatient;
newpatient= new PatientNode;
 
newpatient->patient.firstname=p.firstname;
newpatient->patient.lastname=p.lastname;
newpatient->patient.age=p.age;
newpatient->patient.priority=p.priority;
newpatient->next=NULL;

if (isempty()){
queuefront = newpatient;
queuerear = newpatient;}
else{
  queuerear->next=newpatient;
  queuerear=newpatient;}
}

void PatientPriorityQueue::deletePatient(){
PatientNode *current;
PatientNode *trailcurrent;
int min;
bool found=false;

if(queuefront==NULL)//delete from empty queue
cout<<"you can't delete from empty queue"<<endl;

else{
current=queuefront;
min=current->patient.priority;
while(current!=NULL)
  if(current->patient.priority < min)
   min=current->patient.priority;
  else{
   trailcurrent=current;
   current=current->next;
    }
}

current=queuefront;
while(current!=NULL && !found)
if(current->patient.priority == min){
 if(queuefront==current){//delete the first node;
   queuefront=queuefront->next;
   if(queuefront==NULL)
   queuerear=NULL;
   delete current;
    }
   
  else if(current->next==NULL){//delete the last node
   trailcurrent->next=NULL;
   delete current;
   }

  else if(queuefront==queuerear){//delete from queue has only one node
    delete queuefront; 
   }

  else if(current->next==NULL){//delete the last node
   trailcurrent->next=NULL;
   delete current;
   }

  else{//delete node in the middle
   trailcurrent->next=current->next;
   if(current==queuerear)
   queuerear=trailcurrent;
   delete current;
 }
 found=true;}

else{
  trailcurrent=current;
  current=current->next;
}
}


void PatientPriorityQueue::frontPatient(){
PatientNode *current;
PatientNode *trailcurrent;
int min;
bool found=false;

if(queuefront==NULL)
cout<<"the queue is empty"<<endl;
else{
current=queuefront;
min=current->patient.priority;
  while(current!=NULL)
    if(current->patient.priority < min)
     min=current->patient.priority;
    else{
     trailcurrent=current;
     current=current->next;
       }
}

current=queuefront;
while(current!=NULL && !found)
if(current->patient.priority == min){
current->patient.printPatientInfo();
found=true;}
else{
  trailcurrent=current;
  current=current->next;
}
}

#endif