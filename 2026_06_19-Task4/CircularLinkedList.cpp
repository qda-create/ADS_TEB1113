#include <iostream>
#include <string>
using namespace std;
//Circular Linked List

struct Node{
    string name;
    Node* next;
};

int main(){
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    
    //Store data 
    node1->name = "Aimar";
    node2->name = "Ahmadr";
    node3->name = "Anjana";
    node4->name = "Jessy";
    
    //Connect with nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1; //point back at first node = circular
    
    //Display
    cout<<"Circular Linked List: "<<endl;
    Node* display_node = node1;
    
    do{
        cout<<display_node->name<<endl;
        display_node = display_node->next;
    }while(display_node != node1);
    
    return 0;
}
