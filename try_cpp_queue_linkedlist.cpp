
#include <iostream>
using namespace std;

class Node{
    
    public:
        int key, data;
        Node *next;
        Node(){
            key = data = 0;
            next = NULL;
        }
        Node(int ke_y, int dat_a){
            key = ke_y;
            data = dat_a;
        }
};

class QueueList{
    private:
        Node *front, *rear;
        int counter, capacity;
    public:
        /*
            -1 - Enqueu Node key same
            0 - Enqeue/Dequeue failed
                *full queue
            1 - Enqueu/Dequeue Succesfully

        */
        QueueList(){
            front = rear = NULL;
            counter = 0;
            capacity = 3;
        }

        QueueList(int capacit_y){
            front = rear = NULL;
            counter = 0;
            capacity = capacit_y;
        }

        bool isEmpty(){
            if(front == NULL && rear == NULL){
                return true;
            }
            return false;
        }

        bool isFull(){
            if(size() == capacity){
                return true;
            }

            return false;
        }

        bool nodeExists(int ke_y){
            bool status = false;
            if(isEmpty()){
                return status;
            }
            Node* ptr = front;
            while(ptr){
                if(ptr->key == ke_y){
                    status = true;
                    break;
                }
                ptr = ptr->next;
            }

            return status;
        }
        
        int size(){
            return counter;
        }

        int Enqueue(Node* nod_e){
            int status = 0;
            if(isFull()){
                status = -1;
            }else{
                if(isEmpty()){
                    front = rear = nod_e;
                    counter = status = 1;
                }else{
                    if(nodeExists(nod_e->key)){
                        status = -1;
                    }
                    rear->next = nod_e;
                    rear = nod_e;
                    counter ++;
                    status = 1;
                }
            }
        }

        bool Dequeue(){
            bool success = false;
            if(isEmpty()){
                return success;
            }else{
                if(front == rear){
                    front = rear = NULL;
                    counter = 0;
                    success = true;
                }
                front = front->next;
                counter --;
                success = true;
            }

            return success;
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

    QueueList queue1, queue2;
    int ke_y, dat_a, option, ioption;
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
                cout << endl << "1. on queue1"
                     << endl << "2. on queue2"
                     << endl << "Select: ";
                cin >> ioption;
                switch(ioption){
                    case 1:
                        queue1.Enqueue(node);
                        break;
                    case 2:
                        queue2.Enqueue(node);
                        break;
                    default:
                        break;
                }

                break;

            case 2:
                // bool result = queue.Dequeue();
                cout << endl << "1. dequeue on queue1"
                     << endl << "2. dequeue on queue2"
                     << endl << "Select: ";
                cin >> ioption;
                switch (ioption)
                {
                case 1:
                    if(queue1.Dequeue()){
                        cout << endl << "Dequeued !!" << endl << endl;
                    }
                    break;
                case 2:
                    if(queue2.Dequeue()){
                        cout << endl << "Dequeued !!" << endl << endl;
                    }
                    break;
                
                default:
                    break;
                }
                break;

            case 3: 
                cout << endl << "Size of queue1: " << queue1.size() << endl 
                     << "Size of queue2: " << queue2.size() << endl << endl;
                break;            

            case 4:
                queue1.display();
                queue2.display();
                break;

            default:
                break;
        }
    }while(option != 0);

    return 0;
}