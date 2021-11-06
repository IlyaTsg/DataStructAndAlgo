#include <iostream>

class Set {
	private:
		int static N, cnt;
		int n;
		char S, *A;
	public:
		Set& operator &= (const Set& B) {
			Set C(*this);
			n = 0;
			for (int i = 0; i < C.n; i++) {
				for (int j = 0; j < B.n; j++) if (C.A[i] == B.A[j]) A[n++] = C.A[i];
			}
			A[n] = 0;
			return *this;
		}
		Set operator & (const Set& B) const {
			Set C(*this);
			return std::move(C &= B);
		}
		Set& operator |= (const Set& B) {
			for (int i = 0; i < B.n; i++) {
				bool flag = 1;
				for (int j = 0; j < n && flag; j++) if (A[j] == B.A[i]) flag = 0;
				if (flag) A[n++] = B.A[i];
			}
			A[n] = 0;
			return *this;
		}
		Set operator | (const Set& B) const { // Тут не было return, я добавил и убрал set&
			Set C(*this);
			return std::move(C |= B);
		}
		Set operator ~ () const {
			Set C;
			for (char c = '0'; c <= '9'; c++) {
				bool flag = true;
				for (int i = 0; i < n && flag; i++)
					if (c == A[i]) flag = false;
				if (flag) C.A[C.n++] = c;
			}
			C.A[C.n] = 0;
			return std::move(C);
		};
		Set(const Set& B) : S('A' + cnt++), n(B.n), A(new char[N + 1]) {
			char* dst(A), * src(B.A);
			while (*dst++ = *src++);
		}
		Set& operator = (const Set& B) {
			if (this != &B) {
				char *dst(A), *src(B.A);
				n = B.n;
				while (*dst++ = *src++);
				S = 'A' + cnt++;
			}
			return *this;
		}
		Set(Set &&B) : S('A' + cnt++), n(B.n), A(B.A) { B.A = nullptr; }

		void Show() { std::cout << A << std::endl; } // Убрал вывод символа, т.к при повторных запусках шли другие буквы
		int power() { return n; }

		Set() : n(0), S('A' + cnt++), A(new char[N + 1]) { A[0] = 0; }
		Set(char) : n(0), S('A' + cnt++), A(new char[N + 1]) {
			uint16_t random = rand() % 0x3FF;
			int i;
			for (i = 0; i < ((rand() + 1) % (N + 1)); i++) if ((random >> i) & 1) A[n++] = i + '0';
			A[n] = 0;		
		}
		~Set() { delete[] A; }

};