#include <iostream>
#include <string>

using namespace std;

class car{
public:
  //THIS WILL BE EITHER 'N' FOR NORMAL OR 'V' FOR VIP, DEFUALT TO N
  char type;
  string firstName, model;
  int plateNumber;
  car() {firstName = "Name",model = "Model",type = 'N',plateNumber = 123;}
  car(char typee,string name,string Model,int number){
    type = typee;
    firstName = name;
    model = Model;
    if(number>0)
      plateNumber = number;
    else
      //-1 is error code for invalid plate number
      plateNumber = -1;
  }
  bool operator==(car &rhs){
    if(firstName == rhs.firstName && model == rhs.model && plateNumber == rhs.plateNumber)
      return true;
    else
      return false;
  }
};

class Node{
public:
  //MAKE IT ALL COMPATIBLE WITH THE CAR STRUCT
  car data;
  int position;
  Node *next;
  Node() {data = car(); next = nullptr;}
  Node(car Datae,int pos,Node *link) {data = Datae;position = pos;next = link;}
};

class Queue{
  int size;
  Node *Head;
  Node *Tail;
public:
  Queue() {size = 0;Head = nullptr; Tail = nullptr;}
  Queue(int population,Node *beginning = nullptr, Node *end = nullptr);
  Queue(const Queue &Q);
  ~Queue();
  //adds an item at the TAIL of the queue
  void addCarAtBottom(car item);
  //ADDS CAR AT HEAD OF NON-VIP cars
  void addVipCar(car item);
  //PRINTS OUT ALL CARS IN THE CURRENT QUEUE
  int getSize(){return size;}
  void showAllCars();
  car pop();
  car top();
  void removeCar(car item);
  bool isEmpty() const;


};
