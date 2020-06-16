//
// Created by yair on 10/06/2020.
//

#ifndef ITERATORSTRUCT_RANGE_HPP
#define ITERATORSTRUCT_RANGE_HPP
using namespace std;
namespace itertools
{
    class range {
        private:
            int start, last;

        public:
            range(int s, int l)
            {
                start = s;
                last = l;
            }



            class iterator
            {
                int current;
                public:
                    iterator(int start = 0)
                    {
                        current = start;
                    }


                    iterator &operator++()
                    {
                         current++;
                         return *this;
                    }

                    bool operator==(const iterator &iter) const
                    {
                        return this->current == iter.current;
                    }

                    bool operator!=(const iterator &iter) const
                    {
                            return !(*this==iter);
                    }

                    iterator operator++(int)
                    {
                        iterator prev = *this;
                        current++;
                        return prev;
                    }

                    int operator*() const
                    {
                        return this->current;
                    }



            };


         const iterator begin() const
        {
            return iterator(start);
        }

         const iterator end() const
        {
            return iterator(last);
        }
    };

}

#endif //ITERATORSTRUCT_RANGE_HPP
