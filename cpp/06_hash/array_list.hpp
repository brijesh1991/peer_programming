#include "hash.hpp"

class array_list {
    private:
        int *arr;
        int size;
    public:
        array_list();
        array_list(int sz);
        array_list(int arr[],int sz);
        int * get_array();
        int get_size();
        int get_value_at_index(int index);
        ~array_list();
        
};

array_list::array_list() {
    cout << "creating arr of size 1"  << endl;
    this->arr= new int(1);
    this->size =1;
}

array_list::array_list(int sz) {
    cout << "creating arr of size " << sz << endl;
    this->arr = new int[sz];
    this->size =  sz;
}

array_list::array_list(int arr[],int sz) {
    cout << "creating arr of size " << sz << endl;
    this->size = sz;
    this->arr = new int[sz];
    for(int i=0;i<sz;i++) {
        this->arr[i]= arr[i];
    }
}

array_list::~array_list() {
}


int * array_list::get_array() {
    return this->arr;
}

int array_list::get_size() {
    return this->size;
}

int array_list::get_value_at_index(int index) {
    if (index > this->size)
        return -1;
    return this->arr[index];
}