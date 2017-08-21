#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
template<typename T>
class Vector
{
protected:
    int _capacity,_size;
    T *_elem;
    void expand(void)
    {
        if(_size<_capacity)
            return ;//尚未满员，无需扩容
        if(_capacity<3)
            _capacity=3;
        T *oldElem=_elem;//backup
        _elem=new T[_capacity<<=1];
        for(int i=0;i<_size;i++)
            _elem[i]=oldElem[i];
        delete []oldElem;
    }
    void shrink(void)
    {
        if(_capacity<6)//不至于收缩到DEFAULT_CAPACITY以下
            return ;
        if(_size<<2 >_capacity)//当装填率小于25%时缩容
            return ;
        T *oldElem=_elem;//backup
        _elem=new T[_capacity>>=1];
        for(int i=0;i<_size;i++)
            _elem[i]=oldElem[i];
        delete []oldElem;
    }
public:
    //constructor
    Vector(void)
    {
        _capacity=3;//default capacity
        _size=0;
        _elem=new T[_capacity];
    }
    ~Vector()
    {
        delete []_elem;
    }
    T& operator [](int r)const
    {
        return _elem[r];
    }
    int size()const
    {
        return _size;
    }
    bool empty()const
    {
        return(!_size);
    }

    void push_back(const T& X)
    {
        expand();
        _elem[_size++]=X;
    }
    T pop_back(void)
    {
        T temp=_elem[--_size];
        shrink();
        return temp;
    }
};


#endif // VECTOR_H_INCLUDED
