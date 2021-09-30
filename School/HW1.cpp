#include <iostream>
using namespace std;

class Vector {
public:
    float* data;
    int size;
    int capacity;

    Vector(){
        size = 0;
        capacity = 8;
        data = new float[capacity];
    }

    ~Vector(){}
    
    void push_back(float num) {
      if (size == capacity) {
         capacity *= 2;
         float* temp = new float[capacity];
         for (register int i = 0; i < size; i++) {
            temp[i] = data[i];
         }
         data = temp;
      }
      data[size++] = num;
    }

    void modify(int index, float val){
        if(index < size && index >= 0){
            data[index] = val;
        } else{
            cout << "**index error**" << endl;
        }
    }

    void mutiply(float scalar){
        for(int i = 0; i < size; i++){
            data[i] *= scalar;
        }
    }

    void display(){
        cout << "element list\n(";
        for(int i = 0; i < size; i++){
            if(i == size-1){
                cout << data[i];
                break;
            }
            cout << data[i] << ", ";
        }
        cout << ")" << endl;
    }
};

int main() {
  Vector f_vec;
  f_vec.push_back(40);
  f_vec.push_back(10);
  f_vec.push_back(15);
  f_vec.push_back(20);
  f_vec.display();
  f_vec.modify(0, 5);
  f_vec.display();
  f_vec.mutiply(2);
  f_vec.display();

  return 0;
}

  