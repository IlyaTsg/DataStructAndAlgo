#include <iostream>

class Set {
private:
	int static N, cnt;
	int n;
	char S;
	uint16_t A;
public:
	Set& operator &= (const Set& B) {
		A &= B.A;
		return *this;
	}
	Set operator & (const Set& B) const {
		Set C(*this);
		return std::move(C &= B);
	}
	Set& operator |= (const Set& B) {
		A |= B.A;
		return *this;
	}
	Set operator | (const Set& B) const {
		Set C(*this);
		return std::move(C |= B);
	}
	Set operator ~ () const {
		Set C;
		C.A = (~A % N-1);
		return std::move(C);
	};
	Set(const Set& B) : S('A' + cnt++), n(B.n), A(B.A){}
	Set& operator = (const Set& B) {
		if (this != &B) {
			n = B.n;
			A = B.A;
			S = 'A' + cnt++;
		}
		return *this;
	}
	Set(Set&& B) : S('A' + cnt++), n(B.n), A(B.A) { B.A = 0; }

	void Show() { // Убрал вывод символа, т.к при повторных запусках шли другие буквы

		for(int i = N-1; i >= 0; i--){ 
			if((A>>i)&1) std::cout << char('9'-i);
    	}
		std::cout << std::endl;
	}
	int power() { return n; }

	Set() : n(0), S('A' + cnt++), A(0) {}
	Set(int) : n(0), S('A' + cnt++), A(rand() % 0x3FF) {}
	~Set() {}

};