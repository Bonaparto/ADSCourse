#include <iostream>
// #include <fstream>
 
// ifstream cin("input.txt");
// ofstream cout("output.txt");

using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(head == NULL) {
        head = node;
        head->next = nullptr;
        return head;
    }
    if(p == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node* temp = head;
    Node* prev;
    bool f = 0;
    for(int i = 0; i < p; ++i) {
        prev = temp;
        temp = temp->next;
        if(temp->next == NULL) break;
    } 
    if(temp->next == NULL){
        node->next = nullptr;
        temp->next = node;
        return head;
    } else {
        node->next = temp;
        prev->next = node;
        return head;
    }
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    Node* temp = head;
    if(p == 0) return nullptr;
    for(int i = 0; i < p-1; ++i) head = head->next;
    if(head->next->next != nullptr) head->next = head->next->next;
    else head->next = nullptr;
    return temp;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    if(p1 == p2) return head;
    Node * temp = head;
    Node * n1 = nullptr;
    Node * n2 = nullptr;
    Node * prev1 = nullptr;
    Node * prev2 = nullptr;
    int val1, val2;
    for(int i = 0; i < p1; ++i) {
        prev1 = temp;
        temp = temp->next;
    }
    if(prev1 != nullptr) prev1->next = temp->next;
    n1 = temp;

    temp = head;
    for(int i = 0; i < p2; ++i) {
        prev2 = temp;
        temp = temp->next;
    }
    n2 = temp;
    if(prev2 != nullptr) prev2->next = n1;
    n1->next = n2;
    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* temp = head;
    Node* temp1 = head->next;
    if(temp1 != nullptr){
        temp->next = nullptr;
        Node* temp2 = temp1->next;
        if(temp2 == nullptr) {
            temp1->next = temp;
            head = temp1;
            return head;
        }
        temp->next = nullptr;
        while(temp2 != nullptr) {
            temp1->next = temp;
            temp = temp1;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp;
        return temp1;
    } else {
        return head;
    }
}
 
void print(Node* head){
    /* write your code here */
    if(head == nullptr) {
        cout << -1 << endl;
        return;
    }
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    Node * temp = head;
    Node * end = nullptr;
    while(temp != nullptr) {
        end = temp;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0; i < x; ++i) {
        end->next = head;
        head = head->next;
        end = head;
        end->next = nullptr;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    Node * end = nullptr;
    for(int i = 0; i < x; ++i) {
        Node * temp = head;
        Node * prev = nullptr;
        while(temp != nullptr) {
            prev = end;
            end = temp;
            temp = temp->next;
        }
        end->next = head;
        if(prev != nullptr) prev->next = nullptr;
        head = end;
    }
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}