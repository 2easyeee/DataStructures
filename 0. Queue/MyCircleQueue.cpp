#include <iostream>
using namespace std;

typedef int element;

class MyCircleQueue
{
private:
    element *data;
    int capacity;
    int size;
    int front;      // 배열의 인덱스
    int rear;       // 배열의 인덱스

    void resize()
    {
        int oldCapacity = capacity;
        capacity *= 2;

        element *newData = new element[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[(front + i) % oldCapacity];
        }

        delete[] data;
        data = newData;

        front = 0;
        rear = size - 1;
    }
    
public:
    MyCircleQueue() : data(new element[1]), capacity(1), size(0), front(0), rear(0) {}
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
        if (is_full())
            resize();

        // 데이터 추가
        if (size == 0)
        {
            data[rear] = _item;
            ++size;
            return;
        }
        
        // index 이동
        rear = (rear + 1) % capacity;
        data[rear] = _item;
        ++size;
    }

    void pop() 
    {
        if (is_empty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        // 없앨 인덱스 값 초기화
        data[front] = 0;

        // index 이동
        front = (front + 1) % capacity;

        // 크기 줄이기
        --size;
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

        cout << "[Queue] > ";
        for (int i = 0; i < size; ++i)
        {
            cout << data[(front + i) % capacity] << ' ';
        }
        cout << '\n';

        cout << "[Debuging Array] > ";
        for (int i = 0; i < capacity; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }

    void print_info(MyCircleQueue *_queue)
    {
        cout << "Size: " << _queue->get_size() << " | ";
        cout << "Capacity: " << _queue->get_capacity() << " | ";
        cout << "Front: " << _queue->get_front() << " | ";
        cout << "Rear: " << _queue->get_back() << " | ";
        cout << '\n';
    }
};

int main()
{
    MyCircleQueue queue;

    return 0;
}