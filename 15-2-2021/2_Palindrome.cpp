#include<iostream>
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

    void reverse()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node<T> *curr = head, *next = NULL, *prev = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    bool operator == (LinkedList<T> &l)  {
        while(getSize() && l.getSize()) {
            if(get(0)->value != l.get(0)->value) {
                return false;
            }
            deleteAtBegin();
            l.deleteAtBegin();
        }
        return true;
    }
};

bool isPalindrome(LinkedList<char> l) {
    LinkedList<char> lrev;
    for(int i=0; i<l.getSize(); i++) {
        lrev.insertAtBegin(l.get(i)->value);
    }
    return (l==lrev);
}

int main() {
    LinkedList<char> l1;
    l1.insertAtEnd('a');
    l1.insertAtEnd('b');
    l1.insertAtEnd('a');

    cout<<(isPalindrome(l1)?"TRUE":"FALSE");
    return 0;
}