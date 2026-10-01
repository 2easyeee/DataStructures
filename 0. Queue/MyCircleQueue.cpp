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
    // =========================================================
    // Test 1. 기본 Push
    // - 빈 큐에 데이터를 순서대로 추가
    // - FIFO 순서 확인
    // =========================================================
    cout << "========================================" << endl;
    cout << "Test 1. Basic Push" << endl;
    cout << "========================================" << endl;

    MyCircleQueue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 2. 기본 Pop
    // - 가장 먼저 들어온 데이터부터 제거되는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 2. Basic Pop (FIFO)" << endl;
    cout << "========================================" << endl;

    queue.pop();

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 3. Circular Queue
    // - 앞쪽 공간이 비어있는 상태에서 새로운 데이터 추가
    // - rear가 배열의 끝을 넘어 다시 처음으로 돌아가는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 3. Circular Behavior" << endl;
    cout << "========================================" << endl;

    queue.push(40);
    queue.push(50);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 4. Circular + Resize
    // - 원형으로 데이터가 배치된 상태에서 capacity 증가
    // - resize 후에도 논리적인 Queue 순서가 유지되는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 4. Circular + Resize" << endl;
    cout << "========================================" << endl;

    queue.push(60);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 5. 여러 번 Pop
    // - front가 계속 이동하는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 5. Multiple Pop" << endl;
    cout << "========================================" << endl;

    queue.pop();
    queue.pop();

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 6. Empty Queue
    // - 모든 데이터를 제거하여 Queue를 비운다.
    // - 빈 Queue에서 pop했을 때 예외적으로 동작하지 않는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 6. Empty Queue" << endl;
    cout << "========================================" << endl;

    while (!queue.is_empty())
    {
        queue.pop();
    }

    queue.print();
    queue.print_info(&queue);

    cout << "\n[Try Pop Empty Queue]" << endl;
    queue.pop();


    // =========================================================
    // Test 7. Empty -> Push
    // - Queue가 완전히 비워진 후 다시 데이터를 추가
    // - front / rear 상태가 정상적으로 동작하는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 7. Push After Empty" << endl;
    cout << "========================================" << endl;

    queue.push(100);
    queue.push(200);
    queue.push(300);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 8. Full Cycle
    // - Pop과 Push를 반복하면서 원형 구조를 지속적으로 사용하는 테스트
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 8. Full Circular Cycle" << endl;
    cout << "========================================" << endl;

    queue.pop();
    queue.pop();

    queue.push(400);
    queue.push(500);

    queue.pop();
    queue.push(600);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Test 9. Large Resize
    // - 여러 번 resize가 발생해도 데이터 순서가 유지되는지 확인
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "Test 9. Multiple Resize" << endl;
    cout << "========================================" << endl;

    queue.push(700);
    queue.push(800);
    queue.push(900);
    queue.push(1000);
    queue.push(1100);
    queue.push(1200);
    queue.push(1300);
    queue.push(1400);
    queue.push(1500);

    queue.print();
    queue.print_info(&queue);


    // =========================================================
    // Final
    // =========================================================
    cout << "\n========================================" << endl;
    cout << "All Tests Finished" << endl;
    cout << "========================================" << endl;

    return 0;
}