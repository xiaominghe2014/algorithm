#ifndef hashtable_h_
#define hashtable_h_
#include <iostream>
#include <assert.h>
namespace hash {
    template<class K,class V>
    class HashTable {
    public:
        HashTable():keys(nullptr),values(nullptr),size(0),length(0){
            //resetSize(10);
        };
        ~HashTable(){};
        void push(K k,V v){
            if(size<=length)
                resetSize(length<=0?10:length*2);
            keys[length-1] = k;
            values[length-1] = v;
            length++;
        };
        V get(K k){
            for(int i = 0 ; i < size ; i++){
                if(keys[i]==k)
                    return values[i];
            }
            return 0;
        };
        void resetSize(int len){
            if(size){
                K* keys_tmp = new K[len];
                V* values_tmp = new V[len];
                for(int i = 0 ; i < len ; i++){
                    if(i<length){
                        keys_tmp[i] = keys[i];
                        values_tmp[i] = values[i];
                    }else{
                       
                        keys_tmp[i] = K();
                        values_tmp[i] = V();
                    }
                }
                delete keys;
                delete values;
                keys = keys_tmp;
                values = values_tmp;
            }else{
                keys = new K[len];
                values = new V[len];
                for(int i = 0 ; i< len ; i++){
                    keys[i] = K();
                    values[i] = V();
                }
            }
            size = len;
        };
        
    private:
        //key 数组
        K* keys;
        //value 数组
        V* values;
        //当前容量
        int size;
        //数据长度
        int length;
    };
#include <string>
    void test(){
        hash::HashTable<std::string,int> hash;
        hash.push("one",1);
        hash.push("two",2);
        hash.push("three",3);
        std::cout<<hash.get("two")<<std::endl;
        std::cout<<hash.get("one")<<std::endl;
        std::cout<<hash.get("three")<<std::endl;
    }
}
#endif
