#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }

        ~Node(){
            if(this->next != NULL || this->prev != NULL){
                this->next = NULL;
                this->prev = NULL;
                delete next;
            }
            cout << "Node with value " << this->data << " will be deleted" << endl;
        }
};

class DoublyLinkedList {
    public:
        void print(Node *head){
            Node *ptr = head;
            cout << "NULL <-> ";
            while(ptr != NULL){
                cout << ptr->data << " <-> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }

        void insert_beginning(Node* &head, int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        void insert_end(Node* &head, int data){
            Node *newNode = new Node(data);
            if(head == NULL) {
                head = newNode;
                return;
            }

            Node *ptr = head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = newNode;
            newNode->prev = ptr;
        }

        void insert(Node* &head, int position, int data){
            if(position == 1){
                insert_beginning(head, data);
                return;
            }

            Node* ptr = head;
            for(int i = 1; i < position-1; i++){
                ptr = ptr->next;
                if(ptr == NULL) {
                    cout << "Cannot add" << endl;
                    return;
                }
            }

            if(ptr->next == NULL){
                insert_end(head, data);
                return;
            }

            Node* newNode = new Node(data);
            newNode->next = ptr->next;
            newNode->prev = ptr;
            ptr->next->prev = newNode;
            ptr->next = newNode;
        }

        void deleteNode(Node* &head, int position){
            if(position == 1){
                Node* ptr = head;
                head->next->prev = NULL;
                head = head->next;
                delete ptr;
                return;
            }

            Node* last = NULL;
            Node* curr = head;
            for(int i = 1; i < position; i++){
                last = curr;
                curr = curr->next;
                if(curr == NULL){
                    cout << "Cannot delete" << endl;
                    return;
                }
            }

            if(curr->next == NULL){
                last->next = NULL;
                delete curr;
                return;
            }

            curr->next->prev = last;
            last->next = curr->next;
            delete curr;
        }

        void search(Node* &head, int data){
            Node* ptr = head;
            if(ptr == NULL){
                cout << "Empty List" << endl;
                return;
            }
            int i = 0;
            while(ptr != NULL){
                if(ptr->data == data){
                    cout << data << " found in the Linked List at node " << (i+1) << endl;
                    return;
                }
                i++;
                ptr = ptr->next;
            }

            cout << data << " not found in the Linked List" << endl;
        }
};

// Main Function
int main(){
    Node *head = NULL;
    DoublyLinkedList *sll = new DoublyLinkedList();

    int choice;
    while(choice != 9){
        cout << "\n\n-- Select the correct option --\n";
        cout << "1. Insert at the Beginning\n";
        cout << "2. Insert at the End\n";
        cout << "3. Insert at the Specific Node\n";
        cout << "4. Delete\n";
        cout << "5. Searching\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice){
            int data, position;
            case 1:
                cout << "Enter the element : ";
                cin >> data;
                sll->insert_beginning(head, data);
                break;
            case 2:
                cout << "Enter the element : ";
                cin >> data;
                sll->insert_end(head, data);
                break;
            case 3:
                cout << "Enter the element : ";
                cin >> data;
                cout << "Enter the position : ";
                cin >> position;
                sll->insert(head, position, data);
                break;
            case 4:
                cout << "Enter the position : ";
                cin >> position;
                sll->deleteNode(head, position);
                break;
            case 5:
                cout << "Enter the element : ";
                cin >> data;
                sll->search(head, data);
                break;
            case 6:
                sll->print(head);
                break;
            case 7:
                cout << "Exiting ...\n";
                exit(0);
            default:
                printf("Please choose correct option\n");
                break;
        }
    }
    return 0;
}