#include <iostream>

class Word {
private:
	int static N, cnt;
	int n;
	char S;
	uint16_t A;
public:
	Word& operator &= (const Word& B) {
		A &= B.A;
		return *this;
	}
	Word operator & (const Word& B) const {
		Word C(*this);
		return std::move(C &= B);
	}
	Word& operator |= (const Word& B) {
		A |= B.A;
		return *this;
	}
	Word operator | (const Word& B) const {
		Word C(*this);
		return std::move(C |= B);
	}
	Word operator ~ () const {
		Word C;
		C.A = (~A % N-1);//���������
		return std::move(C);
	};
	Word(const Word& B) : S('A' + cnt++), n(B.n), A(B.A){}
	Word& operator = (const Word& B) {
		if (this != &B) {
			n = B.n;
			A = B.A;
			S = 'A' + cnt++;
		}
		return *this;
	}
	Word(Word&& B) : S('A' + cnt++), n(B.n), A(B.A) { B.A = 0; }

	void Show() { // Убрал вывод символа, т.к при повторных запусках шли другие буквы
		//std::cout << S << '=';
		//for (int i = 0; i < N; i++) if (A & 1LL<<i) std::cout << '0' + i;
		for(int i = N-1; i >= 0; i--){ 
			if((A>>i)&1) std::cout << char('9'-i);
    	}
		std::cout << std::endl;
	}
	int power() { return n; }

	Word() : n(0), S('A' + cnt++), A(0) {}
	Word(char) : n(0), S('A' + cnt++), A(rand() % 0x3FF) {}
	~Word() {}

};