#include "common.hpp"

class Person {
    friend ostream &operator<<(ostream &os,const Person &p);
    private:
        string name;
        int age;
    public:
        Person() = default;
        Person(string name, int age): name{name},age{age} {}
        bool operator<(const Person &rhs) const{
            return this->age < rhs.age;
        }

        string get_name(){
            return this->name;
        }
        
        int get_age(){
            return this->age;
        }

        bool operator==(const Person &rhs) const {
            return (this->name == rhs.name && this->age == rhs.age);
        }

}; 
 

ostream &operator<<(ostream &os,const Person &p){
    os << p.name << " : " << p.age ;
    return os;
}