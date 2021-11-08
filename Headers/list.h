#include <iostream>
#include <string>

class Set {
    private:
        int static N, cnt;
        char S, Element;
        Set* next;
    public:
        Set() : S('A' + cnt++) { // Базовый конструктор
            Element = 0;
            next = nullptr;
        }
        Set(char El) : S('A' + cnt++) { // Коструктор с элементом
            Element = El;
            next = nullptr;
        }
        Set(std::string El) : S('A' + cnt++) { // Коструктуор из строки
            Element = 0; // Заполняем первый элемент 0
            next = nullptr;
            for(int i = 0; i < El.size(); ++i){ this->append(El[i]); } // Дополняем остальные
        }
        Set(int) : S('A' + cnt++) // Конструктор из машинного слова
        {
			unsigned short word = rand() % 0x3FF;
			int i;
			Element = 0;
			next = nullptr;
			for (i = 0; i < N; i++) {
				if ((word >> i) & 1) this->append(i + '0');
			}
			S = 'A' + cnt++;
        }

        ~Set(){ delete next; }

        Set& operator &(const Set& B) const;
        Set& operator |(const Set& B) const;

        void append(char El);
        void Show();
};

Set& Set::operator &(const Set& B) const
{
    Set* result = new Set(); // Результирующий список
    const Set* tmp_el = this;
    while(tmp_el){ // Проход по всем парам элементов
        const Set* tmp_B = &B;
        while(tmp_B){
            if(tmp_el->Element == tmp_B->Element){ result->append(tmp_B->Element); } // Если элемент есть в обоих множествах, то добавляем в результат
            tmp_B = tmp_B->next;
        }
        tmp_el = tmp_el->next;
    }
    return *result;
}

Set& Set::operator |(const Set& B) const
{
    Set* result = new Set();
    const Set* tmp_A = this;
    while(tmp_A){
        result->append(tmp_A->Element); // Заполняем результирующий список 
        tmp_A = tmp_A->next;
    }
    const Set* tmp_B = &B;
    bool duplicate;

	while(tmp_B){
        if(tmp_B->Element){ // Если B не пустое
            duplicate = true;
            Set* tmp_el = result;
            for(; tmp_el && duplicate; tmp_el = tmp_el->next){ if(tmp_B->Element == tmp_el->Element) duplicate = false; } // Если в результате уже есть данный элемент, он не подходит
            if(duplicate) result->append(tmp_B->Element); // Если такого элемента нет, то добавляем
        }
		tmp_B = tmp_B->next;
	}

    return *result;
}

inline void Set::append(char El)
{
    if(Element){ // Если первый не пустой
        Set *tmp_el = this;
        while(tmp_el->next){ tmp_el = tmp_el->next; }
        tmp_el->next = new Set(El);
    }
    else{
        Element = El;
    }
}

inline void Set::Show()
{
    Set* tmp_el = this;
    while(tmp_el){
        std::cout << tmp_el->Element;
        tmp_el = tmp_el->next;
    }
    std::cout << std::endl;
}

