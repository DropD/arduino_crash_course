// Author:  Mario S. Könz <mskoenz@gmx.net>
// Date:    20.07.2013 11:27:01 EDT
// File:    mean_module.hpp

#ifndef __MEAN_MODULE_HEADER
#define __MEAN_MODULE_HEADER

#include "module.hpp"
#include "../../util/mean_trait.hpp"

namespace ustd {
    namespace detail {
        template<>
        struct requirement<tag::mean> {
            typedef typename make_list<tag::count>::type type;
        };
    }//end namespace detail
    
    template<typename T, typename _base>
    class module<T, tag::mean, _base>: public _base {
        typedef _base base;
        typedef typename mean_trait<T>::type mean_type;
    public:
        //------------------- ctor -------------------
        module(): base(), sum_() {
        }
        //------------------- ops -------------------
        void operator<<(T const & in) {
            base::operator<<(in);
            sum_ += in;
        }
        //------------------- fct -------------------
        mean_type mean() const {
            return sum_ / base::count();
        }
        void clear() {
            base::clear();
            sum_ = mean_type();
        }
    private:
        mean_type sum_;
    };
}//end namespace ustd 

#endif //__MEAN_MODULE_HEADER
