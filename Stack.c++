#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    //constructor
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top > 1){  //to check agar atleast ek bhi khaali space hai ki nahi
        top++;
        arr[top] = element; element daal deta hu
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop(){
        if (top>=0) { //to check agar atleast ek element to present ho tab hi to pop kar paunga
            top--;

        } else{
                cout << "Stack Underflow" << endl;
        }
    }

    int peek(){   //peek method is to check the top of the stack
        if(top>=0 && top<size)
        return arr[top];
    else{
        cout << "Stack is empty" << endl;
        return -1;
    }
    }
    bool isEmpty() {
        if(top == -1){
            return true;
        } else{
            return false;
        }
    }
};

int main(){
  Stack st(5);   //stack ka naam maine st rakh diya aur iska size hai 5
  st.push(22);
  st.push(43);
  st.push(44);

  cout << st.peek() << endl;

}