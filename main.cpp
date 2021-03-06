/*
main.cpp
*/

#include "LinkedList.h"



int main(){

	// create an empty linked list
	LinkedList drugSchedule = LinkedList();


	bool x = true;
	char userChoice;
    std::string drugNameInput;
    int scheduleInput;
	int indexInsert;
    
	while(x){

        
        std::cout << "Choose from the following options:\n";
        std::cout << "To add a node to the linked list enter '1'\n";
        std::cout << "To remove a node from the linked list enter '2'\n";
        std::cout << "To print the current linked list enter '3'\n";
        std::cout << "To exit the program enter '4'\n";
        std::cout << "Enter choice: ";
        std::cin  >> userChoice;
        
        switch (userChoice) {
            case '1':
            {
                
                std::cout <<"Enter the drug's name: ";
				std::cin.ignore();
                std::getline(std::cin, drugNameInput);
                
                std::cout <<"Enter the drug's schedule: ";
               
                std::cin >> scheduleInput;
                
                node* newNode = new node(drugNameInput, scheduleInput);
                
                std::cout << "Where do you want to insert the node?\n";
                std::cout << "To insert at the head of of the linked list enter '1'\n";
                std::cout << "To insert at the tail of the the linked list enter '2'\n";
				std::cout << "To insert at a custom position enter '3'\n";
                std::cin >> userChoice;
                
                    if(userChoice == '2'){
                        drugSchedule.tailInsert(newNode);
                       drugSchedule.print();
                    }
                        
                    else if(userChoice == '1'){
                        drugSchedule.headInsert(newNode); 
                        drugSchedule.print();
                    }
					
					else if(userChoice == '3'){
						if(drugSchedule.returnLength() == 0){
							std::cout <<"\nThe list is empty, inserting at head\n";
							drugSchedule.headInsert(newNode);
							drugSchedule.print(); 
						}
						else{
						std::cout <<"\nThe available position(s) are from 1 to ";					
						std::cout << drugSchedule.returnLength() + 1 << "\n";
						std::cout <<"Enter your selection: ";
						std::cin >> indexInsert;
						drugSchedule.insertAtPosition(newNode, indexInsert); 
						drugSchedule.print();
						}
					}
                    else{
                        std::cout << "Invalid input!\n";
                    }
                break;
            }
                
            case '2':{
				std::cout << "To remove the node at the head enter '1'\n";
				std::cout << "To remove the node at the tail enter '2'\n";
				std::cout << "To remove a node by drug name enter '3'\n";
				std::cin >> userChoice;

				if(userChoice == '1'){	
					drugSchedule.headRemove(); 
					drugSchedule.print(); 
				}
				
				if(userChoice == '2'){
                	drugSchedule.tailRemove();
					drugSchedule.print();
				}

				if(userChoice == '3'){
					std::cin.ignore();
					std::cout <<"Enter the drug name to be removed: ";
					std::getline(std::cin,drugNameInput); 
					drugSchedule.removeByName(drugNameInput);	
					drugSchedule.print();
				}
                break;
			}

            case '3':
                drugSchedule.print();
                break;
                
            case '4':
                x = false;
                break;
                
            default:
                break;
        }
    }
    
    drugSchedule.print();
    
	return 0;
}
