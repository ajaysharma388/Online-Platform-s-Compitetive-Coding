/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
        CurrentMin = INT_MAX;

    }

    void push(int x)
    {
        if( LastElementIndex > 0 )
        { CurrentMin = std::min(x, MinData[LastElementIndex-1]); }
        else
        { CurrentMin = x; }

        MinData[LastElementIndex] = CurrentMin;
        ValueData[LastElementIndex] = x;
        LastElementIndex++;
    }

    void pop()
    {
        LastElementIndex--;
    }

    int top()
    {
        return ValueData[LastElementIndex-1];
    }

    int getMin()
    {
        return MinData[LastElementIndex-1];
    }

private:
    int CurrentMin;
    int MinData[10000];
    int ValueData[10000];
    int LastElementIndex;

};

auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();