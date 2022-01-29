
#include <iostream>
using namespace std;

class Node{
    public:
        int data, key;
        Node* next;
        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }
        Node(int ke_y, int dat_a){
            key = ke_y;
            data = dat_a;
        }
};

class Queue{
    public:
        Node *front, *rear;
        int counter;

        Queue(){
            counter = 0;
            front = rear = NULL;
        }

        bool isEmpty(){
            if(front == NULL && rear == NULL){
                return true;
            }
            return false;
        }

        int size(){
            return counter;
        }

        bool nodeExistes(int ke_y){
            bool status = false;            
            Node* ptr = front;
            while(ptr != NULL){
                if(ptr->key == ke_y){
                    status = true;
                    break;
                }

                ptr = ptr->next;
            }

            return status; 
        }

        void Enqueue(Node* nod_e){
            if(isEmpty()){
                front = rear = nod_e;
                counter ++;
                cout << endl << "Node enqueued at the front" << endl << endl;
            }else{
                if(nodeExistes(nod_e->key)){
                    cout << endl << "Node key already existed" << endl << endl;
                }else{
                    rear->next = nod_e;
                    rear = nod_e;
                    counter ++;
                    cout << endl << "Node enqueued" << endl << endl;
                }
                
            } 
        }

        bool Dequeue(){
            if(isEmpty()){
                return false;
            }else{
                if(front == rear){
                    front = rear = NULL;
                    counter = 0;
                    // cout << endl << "Node dequeued: last queue" << endl << endl;        
                }else{
                    front = front->next;
                    counter --;
                    // cout << endl << "Node dequeued" << endl << endl;
                }

            }
            return true;
        }

        void display(){
            if(isEmpty()){
                cout << endl << "Queue is empty" << endl << endl;
            }else{
                Node* ptr = front;
                cout << endl;
                while(ptr != NULL){
                    cout << "(" << ptr->key << ", " << ptr->data << ")";
                    if(ptr->next){
                        cout << "-->"; 
                    }else{
                        cout << endl;
                    }
                    ptr = ptr->next;
                }
                cout << endl;
                delete ptr;
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
             << "3. Size" << endl
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
                // bool result = queue.Dequeue();
                if(queue.Dequeue()){
                    cout << endl << "Dequeued !!" << endl << endl;
                }
                break;

            case 3: 
                cout << endl << "Size: " << queue.size() << endl << endl;
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