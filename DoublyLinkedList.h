#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
    }

    void push_front(T value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        count++;
    }

    void push_back(T value) {
        Node* node = new Node(value);
        if (empty()) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        count++;
    }

    T pop_front() {
        if (empty()) return T();
        Node* temp = head;
        T value = temp->data;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        count--;
        return value;
    }

    T pop_back() {
        if (empty()) return T();
        Node* temp = tail;
        T value = temp->data;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
        return value;
    }

    void insert(T value, int pos) {
        if (pos <= 0) {
            push_front(value);
            return;
        }
        if (pos >= count) {
            push_back(value);
            return;
        }
        Node* node = new Node(value);
        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
        count++;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= count) return;
        if (pos == 0) {
            pop_front();
            return;
        }
        if (pos == count - 1) {
            pop_back();
            return;
        }
        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }

    T operator[](int pos) {
        Node* curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }
};

#endif
