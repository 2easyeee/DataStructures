#include <iostream>
using namespace std;

typedef int element;
struct STACK
{
    element *data;
    int capacity;
    int top;
};

void create(STACK *_stack)
{
    _stack->capacity = 1;
    _stack->top = -1;
    _stack->data = (element *)malloc(_stack->capacity * sizeof(element));
}
int is_full(STACK *_stack)
{
    return (_stack->top == (_stack->capacity - 1));
}
int is_empty(STACK *_stack)
{
    return (_stack->top == -1);
}
void push(STACK *_stack, element _item)
{
    if (is_full(_stack))
    {
        _stack->capacity *= 2;
        _stack->data = (element *)realloc(_stack->data, _stack->capacity * sizeof(element));
    }
    _stack->data[++(_stack->top)] = _item;
}
element pop(STACK *_stack)
{
    if (::is_empty(_stack))
    {
        printf("\nStack is empty\n");
        exit(1);
    }
    else
    {
        return _stack->data[(_stack->top)--];
    }
}
element peek(STACK *_stack)
{
    if (::is_empty(_stack))
    {
        printf("\nStack is empty\n");
        exit(1);
    }
    else
    {
        return _stack->data[_stack->top];
    }
}

void print(int _num)
{
    printf("%d ", _num);
}

int main()
{
    STACK stack;
    create(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    print(pop(&stack));
    print(pop(&stack));
    print(pop(&stack));
    print(peek(&stack));
    print(peek(&stack));

    free(stack.data);
    return 0;
}