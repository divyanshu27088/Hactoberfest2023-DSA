#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){}
        Node(char d, Node *ptr){
            data = d;
            next = ptr;
        }
};
class Stack{
    Node *top;
    public:
        Stack(){
            top = NULL;
        }
    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else
            return false;
    }
    bool isFull(){
        Node *ptr = new Node();
        if(ptr==NULL){// system memory is exhausted
            return true;
        }
        else{
            return false;
        }
    }
    void push(int value){
        if(!isFull()){
        Node *ptr = new Node();
        ptr->data = value;
        ptr->next = top;
        top = ptr;
        //cout << top->data << " is pushed" << endl;
        }
        else{
            std :: cout << "Stack is full" << endl;
        }
    }
    int pop(){
        if(!isEmpty()){
            int val = top->data;
            top = top->next;
          //  cout << val << " is popped" << endl;
            return val;
        }
        else{
            std :: cout << "Stack underflow" << endl;
        }
    }
    int solvePostfix(string exp){
        int i = 0;
        while(exp[i]!='\0'){
            if(isdigit(exp[i])){
                push(exp[i]-'0');
            }
            else{
                char opt = exp[i];
                int n2 = pop();
                int n1 = pop();
                switch (opt){
                    case '+':
                        push(n1+n2);
                        break;
                    case '-':
                        push(n1-n2);
                        break;
                    case '*':
                        push(n1*n2);
                        break;
                    case '/':
                        push(n1/n2);
                        break;
                    default:
                        break;
                }

            }
            i++;
        }
        int res = pop();
        return res;
    }
};
int main(){
    Stack* stack = new Stack();
    int result = stack->solvePostfix("32*96-+");
    cout << "Result is " << result << endl;
    delete stack;
    return 0;
}