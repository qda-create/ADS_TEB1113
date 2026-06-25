#include <iostream>
using namespace std;

//creating structure
struct Student {
        int ID;
        string name;
        string course;
        int age;
    };
    
int main() {
    //record (array of 5)
    const int size = 5;
    Student student[size];
    
    cout<< "Enter details for 5 students:\n";
    
    for(int i = 0; i <size; i++){
        cout<<"\nStudent "<<i + 1<<endl;
        cout<<"ID: ";
        cin>>student[i].ID;
        
        cin.ignore();
        
        cout<<"Name: ";
        getline(cin, student[i].name);
        
        cout<<"Age: ";
        cin>>student[i].age;
        
        cin.ignore();
        
        cout<<"Course: ";
        getline(cin, student[i].course);
    }
    
    //display records
    cout<<"====STUDENT RECORDS====\n";
    
    for(int i = 0; i<5; i++){
        cout<<"\n*** Student "<< i+1<<" ***\n";
        cout<<"ID: "<<student[i].ID<<endl;
        cout<<"Name: "<<student[i].name<<endl;
        cout<<"Course: "<<student[i].course<<endl;
        cout<<"Age: "<<student[i].age<<endl;
    }
    
    //searching by ID
    int searchID;
    cout<<"\nSearch in database: ";
    cin>>searchID;
    
    bool found = false;
    
    for(int i = 0; i<5; i++){
        if(student[i].ID == searchID){
            cout<<"\nStudent Found!\n";
            cout<<"ID: "<<student[i].ID<<endl;
            cout<<"Name: "<<student[i].name<<endl;
            cout<<"Course: "<<student[i].course<<endl;
            cout<<"Age: "<<student[i].age<<endl;
            found = true;
            break;
        }
    }
    
    if(!found){
        cout<<"Student not found.\n";
    }
    
    //Update record
    int updateID;
    cout<<"\nUpdate one student record: ";
    cin>>updateID;
    
    for(int i=0; i<5; i++){
        if(student[i].ID == updateID) {
            cout<<"\nWhat do you want to change?\n";
            
            cout<<"New Name: ";
            cin>>student[i].name;
            
            cout<<"New Course: ";
            cin>>student[i].course;
            
            cout<<"New Age: ";
            cin>>student[i].age;
            
            cout<<"\nRecord Updated!\n";
            
            cout<<"ID: "<<student[i].ID<<endl;
            cout<<"Name: "<<student[i].name<<endl;
            cout<<"Course: "<<student[i].course<<endl;
            cout<<"Age: "<<student[i].age<<endl;
            
            break;
            
        }
    }

    return 0;
}
