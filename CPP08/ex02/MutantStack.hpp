#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

    typedef std::stack<T> base;

    MutantStack(){

    }

    MutantStack(const MutantStack& orig) : base(orig){
        
    }

    MutantStack& operator=(const MutantStack& orig) {
        if (this != &orig)
            base::operator=(orig); // public
        return (*this);
    }

    // protected c's functions

    typedef typename base::container_type::iterator iterator;
    iterator begin(void){
        return this->c.begin(); // c is a member of base class(std::stack)
    }

    typedef typename base::stack::container_type::const_iterator const_iterator;
    const_iterator begin(void) const{
        return this->c.begin();
    }

    // typedef typename base::container_type::iterator iterator;
    iterator end(void){
        return this->c.end();
    }

    // typedef typename base::stack::container_type::const_iterator const_iterator;
    const_iterator end(void) const{
        return this->c.end();
    }

    typedef typename base::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin(void) {
        return this->c.rbegin();
    }

    typedef typename base::stack::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin(void) const{
        return this->c.rbegin();
    }

    // typedef typename base::stack::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rend(void){
        return this->c.rend();
    }

    // typedef typename base::stack::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rend(void) const{
        return this->c.rend();
    }

    virtual~MutantStack(){
        // actually virtual depends on the parent so hmm maybe no need
    }

};

#endif


//  template<typename _Tp, typename _Sequence = deque<_Tp> >
//     class stack
// container_type == std::deque<T>

// 이 말인즉 c 는 deque 다

// protected:
//       //  See queue::c for notes on this name.
//       _Sequence c;
//->
//  template<typename _Tp, typename _Sequence = deque<_Tp> >
    // class stack
    // {

// std::deque iterator https://en.cppreference.com/cpp/container/deque
//  begin 
// cbegin (C++11)
// 	returns an iterator to the beginning
// (public member function)
// end
// cend (C++11)
// 	returns an iterator to the end
// (public member function)
// rbegin
// crbegin (C++11)
// 	returns a reverse iterator to the beginning
// (public member function)
// rend
// crend (C++11)
// 	returns a reverse iterator to the end
// (public member function)

// iterator
//       begin() _GLIBCXX_NOEXCEPT
//       { return this->_M_impl._M_start; }

//       /**
//        *  Returns a read-only (constant) iterator that points to the first
//        *  element in the %deque.  Iteration is done in ordinary element order.
//        */
//       _GLIBCXX_NODISCARD
//       const_iterator
//       begin() const _GLIBCXX_NOEXCEPT
//       { return this->_M_impl._M_start; }
// _GLIBCXX_NODISCARD
//   const_iterator
//   end() const _GLIBCXX_NOEXCEPT
//   { return this->_M_impl._M_finish; }

//   /**
//    *  Returns a read/write reverse iterator that points to the
//    *  last element in the %deque.  Iteration is done in reverse
//    *  element order.
//    */
//   _GLIBCXX_NODISCARD
//   reverse_iterator
//   rbegin() _GLIBCXX_NOEXCEPT
//   { return reverse_iterator(this->_M_impl._M_finish); }

// : macron return value reverse_iterator rbegin() macron {}

//   /**
//    *  Returns a read-only (constant) reverse iterator that points
//    *  to the last element in the %deque.  Iteration is done in
//    *  reverse element order.
//    */
//   _GLIBCXX_NODISCARD
//   const_reverse_iterator
//   rbegin() const _GLIBCXX_NOEXCEPT
//   { return const_reverse_iterator(this->_M_impl._M_finish); }
//etc....