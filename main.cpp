#include <iostream>
#include <string>
#include "ItemQueue.h"
using namespace std;

//********************************************
// Function getOption ask user what he wants *
// to do with the Queue and returns integer  *
//             								 *
//********************************************
int getOption()
{
	int option;	
	cout << " 1. Put an item in the queue\n" 
	     << " 2. Remove an item from the queue\n"
	     << " 3. Display the items in the queue\n"
	     << " 4. Quit\n";
	cout << "\nEnter option: ";
	cin >> option;
	
	return option;
}
//***********************************************
// Function QueueFun() ask a user size of Queue,*
// what he wants to do and display the outcome  *
//             									*
//***********************************************
template <class Type>
void QueueFun(){
	Type item;
	int maxNumItems;
	cout<<"Determine size of your queue: ";
	cin>>maxNumItems;
	cout<<endl;
	ItemQueue <Type>queue(maxNumItems);
	int option;
	option = getOption();
	while(option != 4){
	
	switch(option){
		case 1:			
			if (queue.isFull()) {
				cout <<"\nQueue is Full."<<endl;
				break;
			}else
			cout << "Insert Item: ";
			cin >> item;
			queue.enqueue(item);
			break;
		case 2:
			if (queue.isEmpty()) {
				cout << "Queue is Empty."<<endl;
				break;
			}else
			queue.dequeue(item);
			cout <<"Removing Item: " << item << endl;
			break;
		case 3:
			cout<<"Diplaying items in queue: "<<endl;
			queue.display();
			cout<<endl;
			break;
		default:
			cout <<"Invalid entry, please try again "<<endl;
		}
		option = getOption();
		cin.clear(); 	// clear the entry if it's string or double 
        cin.ignore(INT_MAX, '\n');		
	}	
	cout<<" Program Ending..."<<endl;
	cout<<" Goodbye!"<<endl;	
}

int main()
{
	int dataType;
	cout <<" 1. Integers"<< endl;
	cout <<" 2. Floats"<< endl;
	cout <<" 3. Strings"<< endl;
	cout <<"which data type would you like to use?: ";
	cin >> dataType;
	if (dataType == 1) {
		QueueFun<int>();
	}
	else if (dataType == 2) {
		QueueFun<float>();	}

	else if (dataType == 3) {
		QueueFun<string>();
	}
	return 0;
}









































	

