#include <iostream>
#include <string>
using namespace std;
//Binary Search Tree Node

struct Node{
    int data;
    Node* left;
    Node* right;
};
int main(){
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    
    //Store data 
    node1->data =50;
    node2->data =30;
    node3->data =70;
    node4->data =20;
    
    //Connect with left and right poiters
    node1->left = node2;
    node1->right = node3;
    
    node2->left = node4;
    node2->right = NULL;
    
    node3->left = NULL;
    node3->right = NULL;
    
    node4->left = NULL;
    node4->right = NULL;
    
    //Display the tree 
    cout<<"Binary Tree"<<endl;
    
    cout<<"Root Node: "<<node1->data<<endl;
    
    cout<<"Left Child: "<<node1->left->data<<endl;
    cout<<"Right Child: "<<node1->right->data<<endl;
   
   cout<<"Left Child of "<<node2->data<<" : "<<node2->left->data<<endl;
   return 0;
}
