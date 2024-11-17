#include <iostream>
using namespace std;

template <typename T>
struct StackNode {
    T data;
    StackNode* Next;

    StackNode(T value) : data(value), Next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* Head;
    int count;

public:
    // �����������
    Stack() : Head(nullptr), count(0) {}

    // ����������
    ~Stack() {
        clear();
    }

    // ���������� �������� � ����
    void push(T value) {
        StackNode<T>* newNode = new StackNode<T>(value);
        newNode->Next = Head;
        Head = newNode;
        count++;
    }

    // �������� �������� � ������� �����
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return;
        }
        StackNode<T>* temp = Head;
        Head = Head->Next;
        delete temp;
        count--;
    }

    // ��������� �������� � ������� ����� ��� ��������
    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek.\n";
        }
        return Head->data;
    }

    // ��������, ���� �� ����
    bool isEmpty() const {
        return Head == 0;
    }

    // ������� �����
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    // ��������� ���������� ��������� � �����
    int size() const {
        return count;
    }

    // ������ ��������� �����
    void print() const {
        StackNode<T>* temp = Head;
        while (temp != 0) {
            cout << temp->data << " ";
            temp = temp->Next;
        }
        cout << endl;
    }
};

int main() {
    Stack<char> stack;

    char s[] = "Hello, World!";
    cout << "Input string: " << s << endl;

    for (int i = 0; s[i] != '\0'; i++) {
        stack.push(s[i]);
    }

    cout << "Stack after pushing elements: ";
    stack.print();

    stack.pop();
    stack.pop();

    cout << "Stack after popping 2 elements: ";
    stack.print();

    cout << "Head element: " << stack.peek() << endl;

    stack.clear();
    cout << "Stack cleared.\n";

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}