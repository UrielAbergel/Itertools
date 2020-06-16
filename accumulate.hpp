//
// Created by yair on 10/06/2020.
//

#ifndef ITERATORSTRUCT_ACCUMULATE_HPP
#define ITERATORSTRUCT_ACCUMULATE_HPP

#include <iterator>
#include <vector>
using namespace std;

typedef struct _defult {
    int x;
    int y;

    _defult operator[](_defult a) {
     return a;
    }

} defult;

namespace itertools
{
    template<typename T , typename Functio>
    class accumulate
    {
    private:
        T & numbers_container;
//        FUNCTION func;
    public:
        accumulate(range t) {}
        accumulate(T& containter) :  numbers_container(containter){}
//        accumulate(T& containter , FUNCTION f = defult()) :  numbers_container(containter), func (f){}

        class iterator
        {
        private:
            typename T::iterator iter;
            decltype(*(numbers_container.begin())) cur_sum;

        public:
            iterator(typename T::iterator temp): iter(temp),cur_sum(*iter){}

            iterator &operator++()
            {
                cur_sum += *(++iter);
                return *this;
            }

            bool operator==(const iterator &temp_iter) const
            {
                return iter == temp_iter.iter;
            }
            iterator(const iterator& iter) = default;

            iterator& operator=(const iterator &temp_iter)
            {
                return *this;
            }

            bool operator!=(const iterator &temp_iter) const
            {
                return !(iter==temp_iter.iter);
            }

            iterator operator++(int)
            {
                iterator prev = *this;
                cur_sum += iter++;
                return prev;
            }

            auto operator*() const
            {
                return this->cur_sum;
            }



        };


        iterator begin() const
        {
            return iterator(numbers_container.begin());
        }

        iterator end() const
        {
            return iterator(numbers_container.end());
        }
    };
}



#endif //ITERATORSTRUCT_ACCUMULATE_HPP
