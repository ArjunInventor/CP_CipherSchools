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

    LinkedList<T> operator+(LinkedList<T> l) {
        LinkedList<T> res;

        while(getSize() && l.getSize()) {
            T t1 = get(0)->value;
            T t2 = l.get(0)->value;
            if(t1<t2) {
                res.insertAtEnd(t1);
                deleteAtBegin();
            } else {
                res.insertAtEnd(t2);
                l.deleteAtBegin();
            }
        }

        while(getSize()) {
            T t1 = get(0)->value;
            res.insertAtEnd(t1);
            deleteAtBegin();
        }

        while (l.getSize()) {
            T t2 = l.get(0)->value;
            res.insertAtEnd(t2);
            l.deleteAtBegin();
        }

        return res;
    }
};

LinkedList<int> merge(vector<LinkedList<int>> lists) {
    LinkedList<int> res;
    for(auto l:lists) {
        res = res + l;
    }
    return res;
}

int main() {
    LinkedList<int> l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(3);
    l1.insertAtEnd(6);

    LinkedList<int> l2;
    l2.insertAtEnd(2);
    l2.insertAtEnd(3);
    l2.insertAtEnd(10);

    LinkedList<int> l3;
    l3.insertAtEnd(4);
    l3.insertAtEnd(5);

    vector<LinkedList<int>> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    LinkedList<int> l = merge(lists);

    l.print();
    return 0;
}