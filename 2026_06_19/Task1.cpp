#include <iostream>
#include <string>
using namespace std;
//Double Linked List

struct Node{
    string name;
    Node* next;
    Node* prev;
};
int main(){
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    
    //Store data 
    node1->name ="Aimar";
    node2->name ="Ahmad";
    node3->name ="Anjana";
    node4->name ="Jessy";
    
    //Connect with next poiters
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    //Connect with prev pointers
    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    
    //Display foward 
    cout<<"Foward Traversal: "<<endl;
    Node* display_node = node1;
    
    while(display_node != NULL){
        cout<<display_node->name<<endl;
        display_node = display_node->next;
    }
    
    //Display backward
    cout<<"\nBackward Traversal: "<<endl;
    display_node = node4;
    
    while(display_node != NULL){
        cout<<display_node->name<<endl;
        display_node = display_node->prev;
    }
    return 0;
}
