#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
template <typename T>
class Stack:public Vector<T>
{
public:
    void push(const T& X)
    {
        this->push_back(X);
    }
    T pop(void)
    {
        return this->pop_back();
    }
    T& top(void)const
    {
        return (*this)[this->size()-1];
    }
    T& second(void)const
    {
        return (*this)[this->size()-2];
    }
};


#endif // STACK_H_INCLUDED
