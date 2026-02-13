#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

class Student{
    public:
        int id;
        string name;

};

int main(){
    
    vector<Student> roster; // roster vector
    //int student_count = 0;
    
    // original menu options
    cout<<" Enter a number from the options below: \n"
        " 1. Add a student \n"
        " 2. Find a student by ID \n"
        " 3. Delete a student by ID \n"
        " 4. Print all students \n"
        " 5. Load from a text file \n"
        " 6. Save to a text file \n"
        " 7. Exit \n";
    
    string user_choice;
    cin >> user_choice;
    cout<<"You've selected option: "<< user_choice<<endl;
    cout<<"Loading... \n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // wait 2 sec


        while(user_choice != "7"){
            if(user_choice == "1"){ // Option 1 - Add student 
                if (roster.size() >= 3){
                    cout<<"Error - Roster is full, cannot add more students"<<endl;
                }
                else{
                    int id;
                    string name;
                    
                    cout<<"Enter student ID: ";
                    cin >> id;        
                    std::this_thread::sleep_for(std::chrono::seconds(1)); // wait 1 sec
                    
                    cout<<"Enter student name: ";
                    cin >> name;
                    cout<<"Loading... \n";
                    std::this_thread::sleep_for(std::chrono::seconds(2)); // wait 2 sec
                    
                    //roster[student_count].id = id;
                    //roster[student_count].name = name;
                    //student_count++;
                    roster.push_back(Student{ id, name });
                    cout<<"Student added. \n";
                }
            }
            else if(user_choice == "2"){ // option 2 - find student by id
                int student_id;
                cout<< "Enter student ID: ";
                cin>> student_id;
                
                cout<<"Loading... \n";
                std::this_thread::sleep_for(std::chrono::seconds(2)); // wait 2 sec
                bool found = false; //set found to false
                
                for(int i = 0; i < roster.size(); i++){
                    if(roster[i].id == student_id){ // compares user input to id in array
                    cout << "Found: " << roster[i].name << endl;
                    found = true; //updates found to true when comparison matches
                    break;
                    }
                }
               
                if(!found){
                    cout<<"Student not found \n";
                }
            }
            else if(user_choice == "3"){ // option 3 - delete student by id
                 if (roster.size() <= 0){
                    cout<<"Error - Roster is empty, cannot delete anymore students"<<endl;
                }
                else{
                    int id;
                    string name;
                    
                    cout<<"Enter student ID: ";
                    cin >> id;        
                    std::this_thread::sleep_for(std::chrono::seconds(1)); // wait 1 sec
                  
                    bool deleted = false; // set deleted to false
                    for(int i = 0; i < roster.size(); i++){
                        if(roster[i].id == id){ // compares user input to id in vector
                        roster.erase(roster.begin() + i); //deletes id from anywhere in the vector
                        cout<<"Student deleted. \n";
                        break;
                        }
                    }
                }
            }
            else if(user_choice == "4"){ //option 4 - print all students
                cout<<"Loading... \n";
                std::this_thread::sleep_for(std::chrono::seconds(3)); // wait 2 sec
                for(int i = 0; i < roster.size(); i++){
                    cout<<roster[i].id<<" "<<roster[i].name<<"\n";
                }
            }
            else if(user_choice == "5"){ //option 5 - load from txt file
                string mytext;
                
                ifstream read_file("file.txt");
                    while (getline (read_file, mytext)){
                    cout<<mytext;
                    }
                    read_file.close();
            }
            else if(user_choice == "6"){ //option 6 - Save to a txt file
                cout<<"Saving to text file...";
                std::this_thread::sleep_for(std::chrono::seconds(2)); // wait 2 sec
                 
                ofstream myfile("check_students.txt");
                if (!myfile){
                    cout<<"Error - could not open text file \n";
                }
                else{
                    for(Student s : roster){
                        myfile<<s.id<<" "<<s.name<<"\n";
                    }
                }
                myfile.close();
                std::this_thread::sleep_for(std::chrono::seconds(2)); // wait 2 sec
                cout<<"\n""Roster has been saved to check_students.txt";
            }
            // reprompting options menu
            cout << "\nEnter a number from the options below:\n"
                " 1. Add a student\n"
                " 2. Find a student by ID\n"
                " 3. Delete a student by ID\n"
                " 4. Print all students\n"
                " 5. Load from a text file\n"
                " 6. Save to a text file\n"
                " 7. Exit\n";
            cin >> user_choice;
            cout << "You've selected option: " << user_choice << endl;
        }
}