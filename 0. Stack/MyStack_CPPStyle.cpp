#include <iostream>
using namespace std;

/* 소멸자
복사 생성자
복사 대입 연산자
이동 생성자
이동 대입 연산자
*/
typedef int element;

class Stack
{
private:
    element *data;
    int capacity;
    int top;

private:
    void resize()
    {
        capacity *= 2;

        element *newData = new element[capacity];
        for (int i = 0; i <= top; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    Stack() : data(new element[1]), capacity(1), top(-1) {}
    ~Stack()
    {
        delete[] data;
    }

    int get_size() { return top + 1; }
    int get_capacity() { return capacity; }

    bool is_full() { return (top == (capacity - 1)); }
    bool is_empty() { return (top == -1); }
    void push(element _item)
    {
        if (is_full())
            resize();

        data[++top] = _item;
    }
    element pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty\n";
            exit(1);
        }

        return data[top--];
    }
    element peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty\n";
            exit(1);
        }

        return data[top];
    }
    void print()
    {
        if (is_empty())
        {
            cout << "Stack is empty\n";
            exit(1);
        }

        for (int i = 0; i <= top; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }
    void print_info(class Stack *_stack)
    {
        cout << "Size: " << _stack->get_size() << '\n';
        cout << "Capacity: " << _stack->get_capacity() << '\n';
        cout << "Peek: " << _stack->peek() << '\n';
    }
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.print();

    stack.print_info(&stack);

    cout << "Pop: " << stack.pop() << '\n';
    cout << "Pop: " << stack.pop() << '\n';
    cout << "Pop: " << stack.pop() << '\n';
    stack.print();

    return 0;
}