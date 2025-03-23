#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    public:
    string name;
    int age;
        
    virtual void getData() = 0; // PURE VIRTUAL FUNCTION
    virtual void putData() = 0; // PURE VIRUTAL FUNCTION
    
    virtual ~Person() {} // VIRTUAL DESTRUCTOR FOR PROPER CLEANUP
};

class Professor : public Person {
    private:
    int publications;
    static int id_counter;
    int cur_id;
    
    public: 
    Professor() {
        cur_id = ++id_counter; // ASSIGN UNIQUE ID
    }
    void getData() override {
        cin >> name >> age >> publications;
    }
    void putData() override {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id_counter = 0; // Initialize static variable

class Student : public Person {
    private:
    int marks[6];
    static int id_counter;
    int cur_id;
    
    public:
    Student() {
        cur_id = ++id_counter;
    }
    
    void getData() override {
        cin >> name >> age;
        for(int i=0; i<6; i++) {
            cin >> marks[i];
        }
    }
    
    void putData() override {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        cout << name << " " << age << " " << sum << " " << cur_id << "\n";
    }
};

int Student::id_counter = 0;  // Initialize static variable

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<Person*> persons;
    
    for(int i=0; i<n; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            persons.push_back(new Professor());
        } else {
            persons.push_back(new Student());
        }
        persons.back()->getData();
    }
    
    for(Person* p : persons) {
        p->putData();
        delete p; // Free dynamically allocated memory
    }
    
    return 0;
}


/*
    This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

    The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.

    The class Student should have two data members: marks, which is an array of size  and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.

    For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .

    Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.

    Note: Expand the main function to look at how the input is being handled.

    Input Format

    The first line of input contains the number of objects that are being created. If the first line of input for each object is , it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.

    If the first line of input for each object is , it means that the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.


    Output Format

    There are two types of output depending on the object.

    If the object is of type Professor, print the space separated name, age, publications and id on a new line.

    If the object is of the Student class, print the space separated name, age, the sum of the marks in  subjects and id on a new line.

    Sample Input

    4
    1
    Walter 56 99
    2
    Jesse 18 50 48 97 76 34 98
    2
    Pinkman 22 10 12 0 18 45 50
    1
    White 58 87
    Sample Output

    Walter 56 99 1
    Jesse 18 403 1
    Pinkman 22 135 2
    White 58 87 2
*/