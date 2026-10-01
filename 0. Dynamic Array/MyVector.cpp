#include <iostream>
using namespace std;

typedef int element;

class MyVector
{
private:
    element *data;
    int capacity;
    int size;

    void resize()
    {
        capacity *= 2;

        element *newData = new element[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

public:
    MyVector() : data(new element[1]), capacity(1), size(0) {}
    ~MyVector()
    {
        delete[] data;
    }

    int get_size() { return size; }
    int get_capacity() { return capacity; }

    bool is_full() { return (size >= capacity); }
    bool is_empty() { return (size <= 0); }

    void push_back(element _item)
    {
        if (is_full())
            resize();

        data[size++] = _item;
    }
    void pop_back()
    {
        if (is_empty())
        {
            cout << "Vector is empty\n";
        }
        --size;
        return;
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
            cout << "Vector is empty\n";
        }

        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << ' ';
        }
        cout << '\n';
    }
    void print_info(MyVector *_vector)
    {
        cout << "Size: " << _vector->get_size() << '\n';
        cout << "Capacity: " << _vector->get_capacity() << '\n';
    }
};

int main()
{
    MyVector vector;

    cout << "=== Initial State ===\n";
    vector.print();
    vector.print_info(&vector);

    cout << "\n=== Push Back ===\n";

    for (int i = 1; i <= 5; ++i)
    {
        vector.push_back(i * 10);

        cout << "push_back(" << i * 10 << "): ";
        vector.print();
        vector.print_info(&vector);
    }

    cout << "\n=== Get Item ===\n";
    cout << "vector[0]: " << vector.get_item(0) << '\n';
    cout << "vector[2]: " << vector.get_item(2) << '\n';
    cout << "vector[4]: " << vector.get_item(4) << '\n';

    cout << "\n=== Set Item ===\n";
    vector.set_item(2, 999);
    vector.print();

    cout << "\n=== Pop Back ===\n";

    while (!vector.is_empty())
    {
        vector.pop_back();
        vector.print();
    }

    cout << "\n=== Final State ===\n";
    vector.print_info(&vector);

    return 0;
}