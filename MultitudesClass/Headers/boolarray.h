#include <iostream>
#include <string>

// Если в bool array будет 0100110101, то множество имеет след вид 02458
//                         9876543210

class BoolArray {
    private:
        int static UniSize;
        bool *multitudes;
    public:
        BoolArray(){ multitudes = new bool[UniSize+1]{false}; }
        BoolArray(std::string S)
        {
            multitudes = new bool[UniSize+1]{false};
            for(int i = 0; i < S.size(); ++i){
                multitudes['9'-S[i]] = true;
            }
        }
        BoolArray(unsigned short word)
        {
            multitudes = new bool[UniSize+1]{false};
            for(int i = UniSize-1; i >= 0; i--) multitudes[i] = ((word >> (UniSize-i-1)) & 1);
        }
        void Generate(){
            unsigned short word = rand() % 0x3FF;
            multitudes = new bool[UniSize+1]{false};
            for(int i = UniSize-1; i >= 0; i--) multitudes[i] = ((word >> (UniSize-i-1)) & 1);
        }
        ~BoolArray(){ delete[] multitudes; }
        
        void operator &=(const BoolArray& B);
        void operator |=(const BoolArray& B);
        BoolArray& operator &(const BoolArray& B);
        BoolArray& operator |(const BoolArray& B);

        void show();
};

void BoolArray::operator &=(const BoolArray& B)
{
    for (int i = 0; i < UniSize; ++i){
        multitudes[i] &= B.multitudes[i];
    }
}

BoolArray& BoolArray::operator &(const BoolArray& B)
{
    BoolArray& tmp_el = *this;
    tmp_el &= B;
    return tmp_el;
}

void BoolArray::operator |=(const BoolArray& B)
{
    for (int i = 0; i < UniSize; ++i){
        multitudes[i] |= B.multitudes[i];
    }
}

BoolArray& BoolArray::operator |(const BoolArray& B)
{
    BoolArray& tmp_el = *this;
    tmp_el |= B;
    return tmp_el;
}

void BoolArray::show()
{
    for(int i = UniSize-1; i >= 0; i--){
        if(multitudes[i]) std::cout << char('9'-i);
    }
    std::cout << std::endl;
}