#pragma once

class SmartPtr{
private:
    int* _ptr;

public:
    explicit SmartPtr(int* p): _ptr(p){}
    
    ~SmartPtr()
    {
        if(_ptr!=nullptr)
            delete _ptr;
        _ptr=nullptr;
    }

    int& operator*()
    {
        return *_ptr;
    }

    int* operator->()
    {
        return _ptr;
    }
};