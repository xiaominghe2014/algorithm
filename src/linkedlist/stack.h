#ifndef stack_h_
#define stack_h_
#include <iostream>
#include <assert.h>
namespace stack
{
    template <class T>
    struct node
    {
        node(T x) : key(x), top(0), bottom(0) {}
        ~node()
        {
            if(top) delete top;
            top = nullptr;
            bottom = nullptr;
        }
        node<T> *top;
        node<T> *bottom;
        T key;
    };

    template <class T>
    class Stack
    {
    public:
        Stack()
        {
            this->top = nullptr;
            this->len = 0;
        };
        ~Stack()
        {
            while (len) {
                pop();
            }
            if (top)
                delete top;
            top = nullptr;
        };

    public:
        //压栈
        void push(T x)
        {
            if (top)
            {
                node<T> *e = new node<T>(x);
                top->top = e;
                e->bottom = top;
                top = e;
            }
            else top = new node<T>(x);
            len ++;
        };
        //出栈
        T pop()
        {
            if (top)
            {
                T v = top->key;
                node<T> *t = top->bottom;
                if (t)
                {
                    t->top = nullptr;
                }
                delete top;
                top = t;
                len--;
                return v;
            }
            return 0;
        };
        
        bool empty(){
            return nullptr==top;
        };
        
        int length() const{
            return len;
        }
        
        //获取栈顶元素
        T seek() const{
            static_assert(top, "top is nullptr");
            if(top) return top->key;
        }
        
        //获取指定深度的元素
        T seek(int depth) const{
            assert(depth>-1&&depth<len);
            node<T>* tmp = top;
            int start = 0;
            while(tmp){
                if(start==depth){
                    return tmp->key;
                }
                tmp = tmp->bottom;
                start++;
            }
            return 0;
        }
        
        //获取所有元素
        template <size_t N>
        void seekAll(T (&all)[N]){
            node<T>* tmp = top;
            int start = 0;
            while(tmp){
                all[start++] = tmp->key;
                tmp = tmp->bottom;
            }
        }
    private:
        int len;
        node<T> *top;
    };
    
    void test(){
        std::cout<<"stack------test--------"<<std::endl;
        auto mStack = new stack::Stack<int>();
        for(int i = 10; i< 100 ; i++){
            std::cout<<i<<",";
            mStack->push(i);
        }
        std::cout<<std::endl;
        const int len = mStack->length();
        int pArr[100] = {0};
        mStack->seekAll(pArr);
        for(int k = 0 ; k < len ; k++){
            std::cout<<"["<<k<<"]="<<pArr[k]<<",";
        }
        std::cout<<std::endl;
        for(int j = 80 ; j > 10 ; j -= 3){
            //std::cout<<mStack->empty()<<std::endl;
            int num = mStack->seek(j);
            std::cout<<j<<"="<<num<<",";
        }
        std::cout<<std::endl;
        while (mStack->length()-10) {
            mStack->pop();
            std::cout<<mStack->length()<<",";
        }
        std::cout<<std::endl;
        delete mStack;
        mStack = nullptr;
    };
}

#endif
