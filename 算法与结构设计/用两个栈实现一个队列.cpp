class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    
    // 队列是先进先出，因此需要保障stack2的栈顶元素始终是stack1的栈底元素
    int pop() {
        if(stack2.empty()){   // 为空，把栈1全部入栈2，弹出栈顶
            while(!stack1.empty()){
                int num = stack1.top();
                stack2.push(num);
                stack1.pop();
            }
        }

        // 直接弹出栈顶
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;   //用来表示入队操作
    stack<int> stack2;   //用来表示出队操作
};