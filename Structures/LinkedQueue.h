//
// Created by Andrew on 21.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H
#define ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H


#include "Queue.h"

template<class T> class LinkedQueue : public Queue<T>{

    struct Node{
        T object;
        struct Node* next;
    };

    Node* head;
    Node* tail;

    public:
        LinkedQueue<T>(int max): Queue<T>(max) {
            head = nullptr;
            tail = nullptr;
        }

        int push(T t) override{
            Node* node = new Node();
            if(node == nullptr)
                return -1;

            node->object = t;
            node->next = nullptr;
            if(head == nullptr){
                head = node;
                tail = node;
            }else{
                tail->next = node;
                tail = node;
            }

            this->size++;

            return 0;
        }

        void pop() override{
            if(head != nullptr){
                Node* node = head;
                if(head == tail){
                    head = nullptr;
                    tail = nullptr;
                }else{
                    head = node->next;
                }
                
                delete node;
                this->size--;
            }
        }

        bool empty() override{
            return this->size == 0;
        }

        T* first() override{
            if(head == nullptr)
                return nullptr;
            
            return &head->object;
        }

        T* data() override{
            if(head != nullptr){
                if(head == tail)
                    return &head->object;
                
                T* data = new T[this->size];
                int j = 0;

                Node* node = head;
                while(node != nullptr){
                    data[j] = node->object;
                    j++;
                    node = node->next;
                }

                return data;
            }
        }

};


#endif //ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H
