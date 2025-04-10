#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* stack;
    int capacity;
    int topIndex;

public:
    myStack(int max_size) : capacity(max_size), topIndex(-1) {
        stack = new T[capacity];
    }

    ~myStack() {
        delete[] stack;
    }

    void push(T value) {
        if (!isFull()) {
            stack[++topIndex] = value;
        }
        else {
            cout << "Stack is full.\n";
        }
    }

    T pop() {
        if (!isEmpty()) {
            return stack[topIndex--];
        }
        else {
            cout << "Stack is empty.\n";
            return T();
        }
    }

    T top() {
        if (!isEmpty()) {
            return stack[topIndex];
        }
        else {
            cout << "Stack is empty.\n";
            return T();
        }
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        }
        else {
            for (int i = topIndex; i >= 0; --i) {
                cout << stack[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    myStack<int> s(capacity);

    int choice, value;
    do {
        cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            cout << "Popped value: " << s.pop() << "\n";
            break;
        case 3:
            cout << "Top element: " << s.top() << "\n";
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 6:
            cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
