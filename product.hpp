//
// Created by Dvir on 05/05/2019.
//

#ifndef CPP_PROJECT5_PRODUCT_HPP
#define CPP_PROJECT5_PRODUCT_HPP

#include "utility"
#include "ostream"

namespace itertools {
    template <typename T, typename Z>
    class itProduct {

    public:
        T a ;
        Z b;
        itProduct(T a , Z b)
                :a(a),b(b){}
        itProduct()
        {}

        // begin of class iterator

        class iterator {

        public:

            decltype(a.begin()) a_startPointer;
            decltype(a.end()) a_endPointer;
            decltype(b.begin()) b_startPointer;
            decltype(b.end()) b_endPointer;
            decltype(b.begin()) saveFirst;


            iterator(T& a, Z& b)
                    :a_startPointer (a.begin()),
                     saveFirst(b.begin()),
                     a_endPointer(a.end()),
                     b_startPointer (b.begin()),
                     b_endPointer(b.end())
            {}

            iterator(T& a, Z& b,bool F)
                    :a_startPointer(a.end()),
                     //saveFirst(b.end()),
                     a_endPointer(a.end()),
                     b_startPointer(b.end()),
                     b_endPointer(b.end())


            {}

            iterator()
            {}

            auto operator*() const {

                return std :: make_pair(*a_startPointer, *b_startPointer);

            }

            iterator& operator++() {
                if (a_startPointer != a_endPointer){
                    b_startPointer++;

                }

                    if (b_startPointer == b_endPointer){
                    b_startPointer = saveFirst;
                    a_startPointer++;
                }

                return *this;
            }


            const iterator operator++(int) {
                iterator tmp;
                tmp = make_pair(a_startPointer,b_startPointer);
                if (a_startPointer != a_endPointer){
                    b_startPointer++;

                }

                if (b_startPointer == b_endPointer){
                    b_startPointer = saveFirst;
                    a_startPointer++;
                }
                return tmp;

            }

            bool operator==(const iterator &it) const {
                return (a_startPointer == it.a_startPointer && b_startPointer == it.b_startPointer);
            }

            bool operator!=(const iterator& it) const {
                return (a_startPointer != it.a_startPointer && b_startPointer != it.b_startPointer);
            }

        };

        //end of class iterator

        iterator begin() {
            return iterator{ a,b };
        }
        iterator end() {
            return iterator{ a,b , false};

        }


    };

    template<typename T, typename Z>
    itProduct<T, Z> product(T a, Z b) {
        return itProduct<T,Z>(a, b);
    }



}

#endif //CPP_PROJECT5_PRODUCT_HPP
