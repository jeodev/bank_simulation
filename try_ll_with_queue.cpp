
#include <iostream>
using namespace std;

class Node{
    public:
        int key, data;
        Node* next;

        Node(){
            key = data = 0;
            next = NULL;
        }

        Node (int ke_y, int dat_a){
            key = ke_y;
            data = dat_a;
        }
};

class Queue{
    public:
        Node *front, *rear;
        Queue(){
            front = rear = NULL;
        }

        Queue(Node* nod_e){
            front = rear = nod_e;
        }

        bool isEmpty(){
            if(front == NULL && rear == NULL){
                return true;
            }
            return false;
        }

        bool nodeExists(int ke_y){
            bool exists = false;
            if(!isEmpty()){
                Node* ptr = front;
                while(ptr){
                    if(ptr->key == ke_y){
                        exists = true;
                        break;
                    }

                    ptr = ptr->next;
                }
            }

            return exists;
        }

        void Enqueue(Node* nod_e){
            if(isEmpty()){
                front = rear = nod_e;
                cout << endl << "Node enqueued at the front" << endl << endl;
            }else{
                if(nodeExists(nod_e->key)){
                    cout << endl << "Node key already existed" << endl << endl;
                }else{
                    rear->next = nod_e;
                    rear = nod_e;
                    cout << endl << "Node enqueued" << endl << endl;
                }
            }
        }

        void Dequeue(){
            if(isEmpty()){
                cout << endl << "Queue is already empty" << endl << endl;
            }else{
                Node* temp = front;
                if(front == rear){
                    front = rear = NULL;
                    cout << endl << "Dequeued: &The queue is empty now" << endl << endl;
                }else{
                    front=front->next;
                    cout << endl << "Dequeued" << endl << endl;
                }

                delete temp;
            }
        }

        void display(){
            if(isEmpty()){
                cout << endl << "The queue is empty" << endl << endl;
            }else{
                Node* ptr = front;
                cout << endl;
                while(ptr){
                    cout << "[" << ptr->key << ", " << ptr->data << "]";
                    if(ptr->next){
                        cout << "-->";
                    }else{
                        cout << endl;
                    }
                    ptr = ptr->next;
                }
                cout << endl << endl;
            }
        }

};


int main(){

    Queue queue;
    int ke_y, dat_a, option;
    do{
        Node* node = new Node();
        cout << "0. Exit" << endl
             << "1. Enqueue" << endl
             << "2. Dequeue" << endl
             << "3. isEmpty" << endl
             << "4. Display" << endl
             << "Select: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "Enter the key: ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                node->key = ke_y;
                node->data = dat_a;
                queue.Enqueue(node);
                break;
            case 2:
                queue.Dequeue();
                break;
            case 3:
                if(queue.isEmpty()){
                    cout << endl << "Queue is empty" << endl << endl;
                }else{
                    cout << endl << "Qeuue isn't empty" << endl << endl;
                }
                break;
            case 4:
                queue.display();
                break;
            default:
                break;
        }
    }while(option != 0);


    return 0;
}