#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node {
    public:
    T value;
    Node * next = NULL;

    Node(T &_value) {
        value = _value;
    }
};

template <class T>
class LinkedList {
    int size = 0;
    Node<T> *head;
    public:
    int getSize() { return size; }
    
    void print() {
        Node<T> *t = head;
        while(t!=NULL) {
            cout<<t->value<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    int find(T key) {
        Node<T> *t = head;
        int i = 0;
        while(t!=NULL) {
            if(t->value == key) {
                return i;
            }
            i++;
            t=t->next;
        }
        return -1;
    }

    Node<T> *get(int index) {
        Node<T> *t = head;
        int i = 0;

        if(index > size-1) {
            cout<<"Index too large.";
            return NULL;
        }

        if(index == 0) {
            return t;
        }
        while(i!=index-1 && t!=NULL) {
            i++;
            t=t->next;
        }
        return t->next;
    }

    void insertAtIndex(T value, int index) {
        if(index > size) {
            cout<<"Index greater than size.";
            return;
        }

        Node<T> *temp = new Node<T>(value);

        size++;

        if(size == 1) {
            head = temp;
            return;
        }
        

        if(index == 0) {
            temp->next = head;
            head = temp;
            return;
        }

        int i = 0;
        Node<T> *t = head;

        while(i!=index-1) {
            t = t-> next;
            i++;
        }

        temp->next = t->next;
        t->next = temp;
    }

    void insertAtBegin(T value) {
        insertAtIndex(value, 0);
    }

    void insertAtEnd(T value) {
        insertAtIndex(value, size);
    }

    void deleteAtIndex(int index) {
        Node<T> *t = head;
        size--;
        if(index == 0) {
            head = head->next;
            delete t;
            return;
        } else {
            int i = 0;
            while(i != index-1) {
                t = t-> next;
                i++;
            }
            Node<T> *t1 = t->next;
            if(index == size-1) {
                t->next = NULL;
            } else {
                t->next = t->next->next;
            }
            delete t1;
        }
    }

    void deleteAtBegin() {
        deleteAtIndex(0);
    }

    void deleteAtEnd() {
        deleteAtIndex(size);
    }

    LinkedList<T> unionOf(LinkedList<T> l2) {
        unordered_map<T, bool> m;
        LinkedList<T> resl;
        for(int i = 0; i < getSize(); i++) {
            Node<T> *t  = get(i);
            m[t->value] = true;
            resl.insertAtEnd(t->value);
        }

        for(int i = 0; i < l2.getSize(); i++) {
            Node<T> *t  = l2.get(i);
            auto a = m.find(t->value);
            if(a == m.end()) {
                resl.insertAtEnd(t->value);
            }
        }
        return resl;
    }

    LinkedList<T> intersectionOf(LinkedList<T> l2) {
        unordered_map<T, int> m;
        
        
    }
};

int main() { 
    LinkedList<int> l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    LinkedList<int> l2;
    l2.insertAtEnd(2);
    l2.insertAtEnd(3);
    l2.insertAtEnd(7);

    LinkedList<int> l3 = l1.intersectionOf(l2);
    l3.print();
    return 0;
}