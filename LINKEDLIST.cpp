//sem 2: topic 1: linked lists
//an array of nodes; where each node contains one data and one pointer to the next node
#include<iostream>
using namespace std;
//first create a node
class Node
{
	//make it public
	public:
		//first part of the node:data
	int data;
	//second part of the node: pointer to next node
	Node *next;	
	//for only one node, by default the address stored need to be nullified
	//by using constructor
	Node(){
	 next = NULL;
	}
};

class Linkedlist
{
	public:
		// now make the head and tail nodes for the chain
		Node *head;
		Node *tail;
		
		//assgning the head and tail as null by default constructor
		
		Linkedlist(){
			head = NULL;
			tail= NULL;
		}
		
		//now we have to make funcions to insert, insertat, delete, and deletear the nodes from the chain
		
	void insert(int value){
		Node *temp = new Node;
		//now this new node's data has to contain the value
		temp->data = value;
		//now conditions
		if(head==NULL){
			head = temp;
			//the first node is created thereby
		}
		else{
			tail->next=temp;
			}
		tail=temp;
	}
	
	// now the insert at function
	void insertat(int pos, int value){
		//start from the head position and reach till the pos position
		Node *current=head;
		//now we want to proceed till pos
		int i=1;
		while(i<pos-1){
			i++;
			current=current->next;
		}
		//now since we are at pos-1, we will create a new node here
		Node *temp=new Node;
		//assign the new node, the intented value
		temp->data=value;
		//and now we will link the next of this new node to the actual next node whose address is currently stored in the pos-1's(i.e.current's) next location
		temp->next=current->next;
		//and link the new node to pos-1(i.e. current) by feeding temp into pos-1's next(i.e. current's next)
		current->next=temp;
	}
	//now let's delete a node
	void dlt(){
		//first let's store the address of last node(i.e. the value of tail) to a temp pointer
		Node * temp=tail;
		//make a new pointer pointing towards head 
		Node * current=head;
		//now till current becomes the address of the second last node, keep on assigning the address of the next node to current
		while(current->next !=tail){
			current=current->next;
		}
		//now make the next section of current node(i.e. the second last node so far) as NULL. so as to break off the last node so as to discard it ahead
		current->next=NULL;
		//now we make this new last node sit with the address of the discarded node (i.e. make current = tail)
		current=tail;
		//now remove the discarded tail node from memory locations by deleting it
		delete temp;
	}
	
	//next let's see how to delete the node from in between the linked list
	void dltat(int pos){
		Node * current = head;
		
		int i=1;
	//first let's obtain the address of the next node from the "to be deleted" node. by reaching till pos and copying the value in next section to a new pointer temp.
		while(i<pos){
			current=current->next;
			i++;
		}	
	
		Node * temp= current->next;
	//restore i to 1.
		i=1;
		//now send current back to head position		
		current=head;
	//now graze the current pointer till pos - 1 
		while(i<pos-1){
			current=current->next;	
			i++;		
		}
		//now copy the current's next value to a new temporary pointer temp1, so as to delete the garbage node after bypassing
		Node * temp1 = current->next;
		
		//and now bypass the "to be deleted"node by feeding in the value of the next node into the previous node's next column//here next and previous are used w.r.t the pos node 

		current->next=temp;	
		delete temp1;
				
	}
	

// now the display function
void display(){
	//let us launch a pointer towards the head and move it gradually through the list taking the output of each node's data as we proceed through 
	Node * current = head;
	//add an integer that will keep on counting the number of rounds the loop runs.
	int i=0;
	//the loop to keep on moving over the list while taking output from each  data in each browser node,untill the current hit's null(i.e. the address stored in tail)
	while(current != NULL){
		cout<<current->data<<"->NULL";
		i++;
		current=current->next;
	}
	cout<<endl;
	//output the  number of rounds the loop runs
	cout<<"TOTAL ENTRIES = "<<i<<endl;
	cout<<endl;
	
}
			
};


int main(){
	
	Linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	
	l1.display();
	
	l1.insertat(3,1);
	
	l1.display();
	
	l1.dlt();
	
	l1.display();
	
	l1.dltat(3);
	
	l1.display();
	
 
	return 0;
}
