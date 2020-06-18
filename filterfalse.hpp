//
// Created by yair on 10/06/2020.
//

#ifndef ITERATORSTRUCT_FILTERFALSE_HPP
#define ITERATORSTRUCT_FILTERFALSE_HPP

template <typename Function, typename T>
class filterfalse {
    const T& numbers_container;
    const Function& func;
public:
    filterfalse(const Function& f, const T& container): numbers_container(container) , func(f){}
    class iterator{
        decltype(numbers_container.begin()) iter;
        const filterfalse& my_obj;
    public:
        iterator(decltype(numbers_container.begin()) it, const filterfalse& obj): iter(it),my_obj(obj){
            // move on the iterator till false from the function.
        }

        iterator& operator++(){
            ++iter;
            while(iter!=my_obj.numbers_container.end() && my_obj.func(*iter))++iter ;
            return *this;
        }

        const iterator operator++(int){
            iterator temp = *this;
            ++iter;
            return temp;
        }

        bool operator==(const iterator& it) const{
            return iter==it.iter;
        }

        bool operator!=(const iterator& it) const{
            return iter!=it.iter;
        }

        auto operator*(){
            return *iter;
        }
    };
    iterator begin() const{
        return iterator(numbers_container.begin(),*this);
    }
    iterator end() const{
        return iterator(numbers_container.end(),*this);
    }

};


#endif //ITERATORSTRUCT_FILTERFALSE_HPP
