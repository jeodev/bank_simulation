#include <iostream>
using namespace std;

class Node{
    public:
        int key, data;
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

class LinkedList{
    public:
        Node* head;

        LinkedList(){
            head = NULL;
        }

        LinkedList(Node* nod_e){
            head = nod_e;
        }

        Node* nodeExistes(int ke_y){
            Node* temp = NULL;
            Node* ptr = head;
            while(ptr != NULL){
                if(ptr->key == ke_y){
                    temp = ptr;
                    break;
                }

                ptr = ptr->next;
            }

            return temp;
        }

        void appendNode(Node* nod_e){
            if(head == NULL){
                head = nod_e;
                cout << endl << "Node appended to the head" << endl << endl;
            }else{
                if(nodeExistes(nod_e->key) != NULL){
                    cout << endl << "Node key already existed!!" << endl << endl;
                }else{
                    Node* ptr = head;
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = nod_e;
                    cout << endl << "Node appended" << endl << endl;
                }
            }
        }

        void prependNode(Node* nod_e){
            if(head == NULL){
                head = nod_e;
                cout << endl << "Node prepended at the head" << endl << endl;
            }else{
                if(nodeExistes(nod_e->key) != NULL){
                    cout << endl << "Node key dosen't existed" << endl;
                }else{
                    nod_e->next= head;
                    head = nod_e;
                    cout << endl << "Node prepended" << endl << endl;
                }
            }
        }

        void deleteNode(int ke_y){
            if(head == NULL){
                cout << endl << "The list is empty" << endl << endl;
            }else{
                // Node* temp = NULL;
                Node* prevNode = head;
                Node* currentNode = head->next;
                while(currentNode != NULL){
                    if(currentNode->key == ke_y){
                        prevNode->next = currentNode->next;
                        currentNode = NULL;
                    }else{
                        prevNode = prevNode->next;
                        currentNode = currentNode->next;
                    }
                }
            delete currentNode;
            }
        }

        void updateNode(int ke_y, int dat_a){
            if(head == NULL){
                cout << endl << "The list is empty" << endl << endl;
            }else{
                Node* ptr = nodeExistes(ke_y);
                if(ptr == NULL){
                    cout << endl << "Node key dosen't exist" << endl << endl;
                }else{
                    ptr->data = dat_a;
                    cout << endl << "Node updated!!" << endl << endl;
                }
            }
        }

        void display(){
            if(head == NULL){
                cout << endl << "The link is empty" << endl << endl;
            }else{
                Node* ptr = head;
                while(ptr != NULL){
                    cout << "(" << ptr->key << ", " << ptr->data << ")";
                    if(ptr->next != NULL){
                        cout << "-->";
                    }else{
                        cout << endl;
                    }

                    ptr = ptr->next;
                }
            }
        }


};

int main(){
    LinkedList ll;
    int ke_y, dat_a, option, ioption;
    do{
        Node* node = new Node();
        cout << "0. Exit" << endl
             << "1. Create" << endl
             << "2. Read" << endl
             << "3. Update" << endl
             << "4. Delete" << endl
             << "Select: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "1. Appended" << endl
                     << "2. Prepended" << endl
                     << "Select: ";
                cin >> ioption;
                
                cout << "Enter the key: ";
                cin >> ke_y;
                cout << "Enter the data: ";
                cin >> dat_a;

                
                if(ioption >= 1 && ioption <= 2){
                        node->key = ke_y;
                        node->data = dat_a;
                }
                
                switch(ioption){
                    case 1:
                        ll.appendNode(node);
                        break;
                    case 2:
                        ll.prependNode(node);
                        break;
                    default:
                        break;
                }

                break;
            case 2:
                ll.display();
                break;
            case 3:
                cout << "Enter the position(key): ";
                cin >> ke_y;
                if(ll.nodeExistes(ke_y)){
                    cout << "Enter the data: ";
                    cin >> dat_a;
                    ll.updateNode(ke_y, dat_a);
                }else{
                    cout << endl << "Node key dosen't exist" << endl << endl;
                }
                break;
            case 4:
                cout << "Enter the position(key): ";
                cin >> ke_y;
                ll.deleteNode(ke_y);
                break;
            default:
                break;
        }
    }while(option != 0);

    return 0;
}