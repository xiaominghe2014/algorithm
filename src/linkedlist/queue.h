
#ifndef queue_h_
#define queue_h_
#include <iostream>
#include <assert.h>

namespace queue {
    template<class T>
    struct Node {
        Node(T x):key(x),next(0){};
        Node()=default;
        ~Node(){}
        T key;
        Node<T>* next;
    };
    template <class T>
    class Queue {
    public:
        Queue():head(0),end(0),len(0){
            head = new Node<T>();
            end = head;
        };
        ~Queue(){
            while(len){
                pop();
            }
            if(head) delete head;
            head = nullptr;
        };
        bool empty(){return 0==len;};
        int length()const{return len;};
        void push(T x){
            Node<T>* tmp = new Node<T>(x);
            end->next = tmp;
            end = tmp;
            len ++;
        };
        bool pop(){
            if(head){
                Node<T>* tmp = head;
                head = tmp->next;
                delete tmp;
                len --;
                return true;
            }
            return false;
        };
        T front()const{
            if(head->next) return head->next->key;
            return 0;
        };
    private:
        Node<T>* head;
        Node<T>* end;
        int len;
    };
    
    void test(){
        std::cout<<"queue------test--------"<<std::endl;
        auto mQueue = new queue::Queue<int>();
        for(int i = 10; i< 100 ; i++){
            std::cout<<i<<",";
            mQueue->push(i);
        }
        std::cout<<std::endl;
        while (mQueue->length()) {
            std::cout<<mQueue->front()<<",";
            mQueue->pop();
        }
        std::cout<<std::endl;
        delete mQueue;
    }
}
#endif
