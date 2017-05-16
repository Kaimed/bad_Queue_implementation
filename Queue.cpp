#include "Queue.h"

Queue::Queue(int population,Node *beginning,Node *end){
  size = population;
  Head = beginning;
  Tail = end;
}

Queue::~Queue(){
  while(Head != nullptr)
  {
    pop();
  }
  delete Head;
  delete Tail;
}

bool Queue::isEmpty() const{
  if(size == 0)
    return true;
  else
    return false;
}

void Queue::showAllCars(){
    Node *p = Head;
    while(p != nullptr){
      cout<<p->data.firstName<<'\t'<<p->data.model<<'\t'<<p->data.plateNumber<<'\t'<<p->position<<endl;
      p = p->next;

    }
    delete p;
}

void Queue::addCarAtBottom(car item){
  if(isEmpty()){
    Head = new Node(item,size,nullptr);
    Tail = Head;
  }
  else if(size<101){
    Tail->next = new Node(item,size,nullptr);
    Tail = Tail->next;
  }
  else{
    cout<<"There are too many cars in the current queue...\n";
    return;
  }
  size++;
}

car Queue::pop(){
  if(isEmpty()){
    return car();
  }
  else{
    Node *p = Head;
    car returnVal;

    Head = Head->next;
    if(Head == nullptr)
    {
      Tail = Head;
    }
    returnVal = p->data;
    delete p;
    p = nullptr;
    size--;
    return returnVal;
  }
}

car Queue::top(){
  if(!isEmpty())
    return Head->data;
  else{
    return car();
  }
}

Queue::Queue(const Queue &Q){
  *this = Q;
}

void Queue::addVipCar(car item){
  Queue Q;
  if(top().type == 'N'){
    Q.addCarAtBottom(item);
    while(!isEmpty()){
      Q.addCarAtBottom(pop());
    }
  }
  else{
    while(top().type == 'V'){
      Q.addCarAtBottom(pop());
    }
    Q.addCarAtBottom(item);
    while(!isEmpty()){
      Q.addCarAtBottom(pop());
    }
  }
  while(!Q.isEmpty()){
    addCarAtBottom(Q.pop());
  }
}

//ASK MAY //ASK MAY //ASK MAY //ASK MAY //ASK MAY //ASK MAY //ASK MAY //ASK MAY //ASK MAY
void Queue::removeCar(car item){
  Queue Q;
  bool found = false;
  while(!isEmpty()){
    if(top() == item){
      car throwaray = pop();
      found = true;
    }
    if(!isEmpty())
      Q.addCarAtBottom(pop());
  }
  while(!Q.isEmpty()){
    addCarAtBottom(Q.pop());
  }
  if(found){
    cout<<"Removed "<<item.firstName<<" from the queue"<<endl;
  }
  else{
    cout<<item.firstName<<" was not found in the queue"<<endl;
  }
}
