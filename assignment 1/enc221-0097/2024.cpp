#include <iostream>
#include <string>

using namespace std;

class Neighbour{
    public:
    string name;
    string gender;
    int age;

    void work(){
        cout<<"She works."<<endl;
    }
    void study(){
        cout<<"she also goes to school."<<endl;
    }
    void display(){
        cout<<"My neighbour is,"<<name<<",she is"<<gender<<"and is"<<age<<"years of age."<<endl;

    }
};
 int main(){
    Neighbour neighbour1;
    neighbour1.name="Sheila";
    neighbour1.gender="female";
    neighbour1.age=26;

    neighbour1.display();
    neighbour1.work();
    neighbour1.study();

    return 0;
}