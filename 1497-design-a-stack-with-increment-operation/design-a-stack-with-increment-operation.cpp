class CustomStack {
public:
    vector<int> stack;
    vector<int> increments;  // stores increment values for each position
    int currentSize = 0;
    int capacity = 0;

    CustomStack(int maxSize) : capacity(maxSize), increments(maxSize, 0) {}

    void push(int value) {
        if (currentSize == capacity)
            return;
        stack.push_back(value);
        currentSize++;
    }

    int pop() {
        if (currentSize == 0)
            return -1;

        int topIndex = currentSize - 1;
        int value = stack[topIndex] + increments[topIndex];
        if (topIndex > 0)
            increments[topIndex - 1] += increments[topIndex];

        increments[topIndex] = 0;
        stack.pop_back();
        currentSize--;
        return value;
    }

    void increment(int k, int value) {
        int limit = min(k, currentSize);
        if (limit > 0)
            increments[limit - 1] += value;
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */