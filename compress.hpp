//
// Created by uriel on 18/06/2020.
//

#ifndef ITERATORSTRUCT_COMPRESS_HPP
#define ITERATORSTRUCT_COMPRESS_HPP

#pragma once
#include <iostream>


namespace itertools{
    template <class T1 , class T2>
    class compress{

        const T1& the_first_container_to_compress;

        const T2& the_second_container_to_compress;


    public:
        compress(const T1& first , const T2& second) : the_first_container_to_compress(first) , the_second_container_to_compress(second){}

        class iterator{
            decltype(the_first_container_to_compress.begin()) iterator_of_the_first_conatainer;

            decltype(the_second_container_to_compress.begin()) iterator_of_the_second_container;

            const compress& the_compress;
        public:

            iterator(decltype(the_first_container_to_compress.begin()) iter_num1 , decltype(the_second_container_to_compress.begin()) iter_num_2 , const compress& compress_func)
                    : iterator_of_the_first_conatainer(iter_num1) ,the_compress(compress_func){
                if(iterator_of_the_second_container != compress_func.the_second_container_to_compress.end()) iterator_of_the_second_container=iter_num_2;
                while(iterator_of_the_second_container!=the_compress.the_second_container_to_compress.end() && *iterator_of_the_second_container==false) {
                    iterator_of_the_first_conatainer++;
                    iterator_of_the_second_container++;
                }
            }

            iterator& operator++(){
                ++iterator_of_the_first_conatainer;
                ++iterator_of_the_second_container;
                while(iterator_of_the_second_container!=the_compress.the_second_container_to_compress.end() && !(*iterator_of_the_second_container)) {
                    iterator_of_the_first_conatainer++;

                    iterator_of_the_second_container++;
                }
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                while(iterator_of_the_second_container!=the_compress.the_second_container_to_compress.end() && !(*iterator_of_the_second_container)) {
                    ++iterator_of_the_first_conatainer;
                    ++iterator_of_the_second_container;
                }
                return temp;
            }

            bool operator==(const iterator& it) const{
                return iterator_of_the_first_conatainer==it.iterator_of_the_first_conatainer;
            }

            bool operator!=(const iterator& it) const{
                return iterator_of_the_first_conatainer!=it.iterator_of_the_first_conatainer;
            }

            auto operator*(){
                return *iterator_of_the_first_conatainer;
            }

        };

        iterator begin() const{
            return iterator(the_first_container_to_compress.begin(),the_second_container_to_compress.begin(),*this);
        }

        iterator end() const {
            return iterator(the_first_container_to_compress.end(),the_second_container_to_compress.end(),*this);
        };


    };
}
#endif //ITERATORSTRUCT_COMPRESS_HPP
