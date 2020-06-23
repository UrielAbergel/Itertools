//
// Created by yair on 10/06/2020.
//

#ifndef ITERATORSTRUCT_ACCUMULATE_HPP
#define ITERATORSTRUCT_ACCUMULATE_HPP

#include <iterator>
#include <vector>
using namespace std;

 struct _defult {
     template<typename T>
     auto operator()(T& a ,T& b) {
     return a+b;
    }

} ;

namespace itertools
{
    template<typename T , typename Function=_defult>
    class accumulate
    {
    private:
      const  T & numbers_container;
      const Function& func;
    public:
        accumulate(const T& containter , const Function& f = _defult()) :  numbers_container(containter), func (f){}

        class iterator
        {
        private:
            decltype(numbers_container.begin()) iter;
            typename std::decay<decltype(*(numbers_container.begin()))>:: type cur_sum;
            const accumulate& my_obj;

        public:
            iterator( decltype(numbers_container.begin()) it , const accumulate& c): iter(it),my_obj(c){
                if(iter!= my_obj.numbers_container.end()) cur_sum = *iter;
            }

            iterator &operator++()
            {
                cur_sum += *(++iter);
                return *this;
            }

            bool operator==(const iterator &temp_iter) const
            {
                return iter == temp_iter.iter;
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
            return iterator(numbers_container.begin(),*this);
        }

        iterator end() const
        {
            return iterator(numbers_container.end(),*this);
        }
    };
}



#endif //ITERATORSTRUCT_ACCUMULATE_HPP
