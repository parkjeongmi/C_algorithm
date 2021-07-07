#include <iostream>
using namespace std;

void error(const char* message){
    printf("Error: %s \n", message);
    exit(1);
}

const int MAX_STACK_SIZE = 20;
class Stack{
    private :
        int top;
        int data[MAX_STACK_SIZE];
    public :
        Stack(){
            top = 1;
        }
        void push(int e){
            if (isFull()) error("Full");
            data[++top] = e;
        }
        int pop(){
            if (isEmpty()){
                error("Empty");
            }
            return data[top--];
        }
        void display(){
            printf("[Size=%d]", top+1);
            for (int i=0; i<=top; i++){
                printf("%3d", data[i]);
            }
            printf("\n");
        }
        int peek(){
            if (isEmpty()){
                error("Empty");
            }
            return data[top];
        }
        int size() {return top;}
        bool isEmpty(){return top==1;}
        bool isFull() {return top==MAX_STACK_SIZE -1;}
};