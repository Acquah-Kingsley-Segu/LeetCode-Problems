#include <iostream>
 
/* Class to define the node */
class Node{
	int data; //data variable of node
	Node* next; //next variable to hold memory address of the next node
	
	public: 
		/* method to set the data attribute of the node class */
		void setData(int number){
			this->data = number;
		}
		
		/* method to set the next attribute of the node class */
		void setNext(Node* next){
			this->next = next;
		}
		
		/* method to get the data attribute of the node class */ 
		int getData(){
			return this->data;
		}
		
		/* method to get the next attribute of the node class */
		Node* getNext(){
			return this->next;
		}
		
};
/* End of node definition */

class LinkedList{
	Node* head, *trav; /* the head and traverse variable of a linked list */
	
	public:
		/* constructor method of the linked list, sets head and trav to NULL */
		LinkedList(){
			this->head = NULL;
			this->trav = NULL;
		}
		
		/* method to display the contents in a linked list */
		void displayElement(){
			std::cout << "Numbers stored in the linked list are: ";

			Node* current = getHead();

			while (current != NULL){
				std::cout << current->getData() << " ";
				current = current->getNext();
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		
		/* method to get the head of the linked list */
		Node* getHead(){
			return this->head;
		}
		
		/* method to get the trav attribute of a linked list */
		Node* getTrav(){
			return this->trav;
		}
		
		/* method to get the memory location of the next node in a linked list */
		Node* getTravNext(){
			return this->trav->getNext();
		}
		
		/* method to join two sorted lists together */
		void mergeList(LinkedList& list){
			/*g++ mergeTwoSortedList.cpp*/
			
			/* Node variables to hold the new node to be added to the list(addNode)
			and hold the prev node in the list(this) being added to(prev) */
			Node* addNode,* prev;  
			
			// count variable to help add to the head node
			int count = 1;
			
			/* the loop used for the addition of the nodes to the this list */
			while(list.getTrav() != NULL){
				std::cout << "Inside the while" << std::endl;
				
				/* condition that checks whether the foreign list(list) is less
				or equal to the this list */
				if(list.getTrav()->getData() <= this->getTrav()->getData()){
					std::cout << "	Inside the if" << std::endl;
					
					if(count == 1){
						std::cout << "		Inside the inner if" << std::endl;
						
						addNode = list.getHead();
						list.setTrav(list.getTravNext());
						addNode->setNext(this->getHead());
						this->setHead(addNode);
						count++;
						
						prev = this->getHead();
						
						std::cout << prev->getData() << " " << this->getTrav()->getData() 
								  << " " << list.getTrav()->getData() <<  std::endl;
					}
					else{
						std::cout << "		Inside the inner else" << std::endl;
						addNode = list.getTrav();
						list.setTrav(list.getTravNext());
						
						std::cout << "			Prev: " << prev->getData() << " " << "Current: " << this->getTrav()->getData() 
								  << " " << "AddNode: " << addNode->getData() << " List: " << list.getTrav() << std::endl;
						
						addNode->setNext(this->getTrav());
						prev->setNext(addNode);
						
						
						prev = prev->getNext();
						
						std::cout << "			Prev: " << prev->getData() << " " << "Current: " << this->getTrav()->getData() 
								  << " " << "AddNode: " << addNode->getData() << " List: " << list.getTrav() << std::endl;
						break;
					}
				}
				else{
					count++;
					std::cout << "	Inside the outer else" << std::endl;
					
					prev = this->getTrav();
					this->setTrav(this->getTrav()->getNext());
				}
			}
		}
		
		/* method to allow user input values of the linked list */
		void setElements(){
			int number; Node* node;
			
			std::cout << "Enter number and \"0\" to stop input: ";
			std::cin >> number;
			
			node = new Node;
			node->setData(number);
			node->setNext(NULL);
			
			setHead(node);
			setTrav(node);
			
			while(number != 0){                
				std::cout << "Enter number: ";
				std::cin >> number;
				
				if(number == 0){
					break;
				}
				node = new Node;
				node->setData(number);
				node->setNext(NULL);
				
				setTravNext(node);
				setTrav(getTravNext());
			}
			setTrav(getHead());	
		}
		
		/* method to set the head attribute of a linked list */
		void setHead(Node* start){
			this->head = start;
		}
		
		/* method to set the trav attribute of the linked list */
		void setTrav(Node* start){
			this->trav = start;
		}
		
		/* method to set the trav next of a node in a linked list */
		void setTravNext(Node* next){
			trav->setNext(next);
		}
};

int main(){
	
	/* List 1 definition and display*/
	LinkedList L1;
	L1.setElements();
	L1.displayElement();
	/*End of List1 definition and display */
	
	/* List2 definition and display*/
	LinkedList L2;
	L2.setElements();
	L2.displayElement();
	/*End of List2 definition and display */
	
	L1.mergeList(L2);
	
	L1.displayElement();
	
	
	return 0;
}