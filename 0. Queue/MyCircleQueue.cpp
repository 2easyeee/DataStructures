#include <iostream>
using namespace std;

typedef int element;

class MyCircleQueue
{
private:
    element *data;
    int capacity;
    int size;
    int front;
    int rear;

    void resize()
    {

    }
    
public:
    MyCircleQueue() : data(new element[1]), capacity(1), size(0), front(-1), rear(-1) {}
    ~MyCircleQueue()
    {
        delete[] data;
    }

    const int get_size() { return size; }
    const int get_capacity() { return capacity; }
    const int get_front() { return front; }
    const int get_back() { return rear; }

    const bool is_full() { return (size >= capacity); }
    const bool is_empty() { return (size <= 0); }

    void push(element _item) 
    {

    }
    void pop() 
    {
        if (is_empty())
        {
            cout << "Queue is Empty\n";
        }
    }

    element get_item(int _index)
    {
        if (_index < 0 || _index >= size)
        {
            cout << "Out of Range\n";
        }

        return data[_index];
    }

    void set_item(int _index, element _item)
    {
        if (_index < 0 || _index >= size)
        {
            cout << "Out of Range\n";
        }

        data[_index] = _item;
    }

    void print()
    {
        if (is_empty())
        {
            cout << "Queue is empty\n";
        }

        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }

    void print_info(MyCircleQueue *_queue)
    {
        cout << "Size: " << _queue->get_size() << '\n';
        cout << "Capacity: " << _queue->get_capacity() << '\n';
        cout << "Front: " << _queue->get_front() << '\n';
        cout << "Rear: " << _queue->get_back() << '\n';
    }
};

int main()
{
    MyCircleQueue queue;
    
    return 0;
}