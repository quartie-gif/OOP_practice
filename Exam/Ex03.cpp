#include <iostream>

struct Int_t
{
    Int_t(int v): _v(v)
    {
        std::cout << "K_" << _v << ";";
    }
    ~Int_t()
    {
        std::cout << "D_" << _v << ";";
    }
private:
    int _v = 1;
};


class ptr
{
public:
    ptr(Int_t* p = nullptr)
    {
        _p = p;
    }
    ~ptr()
    {
        delete _p;
    }
private:
    Int_t * _p;
};


int main()
{
    { ptr p {new Int_t{1}}; }
      ptr p {new Int_t{2}};
}


/*
output:

K_1;D_1;K_2;D_2

*/