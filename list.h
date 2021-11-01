#include <iostream>
#include <string>

const int UniSize = 10;

class list {
    private:
        char Element;
        list* next;
    public:
        list(){
            Element = 0;
            next = nullptr;
        }
        list(char El){
            Element = El;
            next = nullptr;
        }
        list(std::string El){
            Element = 0;
            next = nullptr;
            for(int i = 0; i < El.size(); ++i){ this->append(El[i]); }
        }
        list(unsigned short word)
        {
            int i, k;
            Element = 0;
            next = nullptr;
            for (i = 0, k = 0; i < UniSize; i++){  
                if ((word >> i) & 1) this->append(i + '0');
            }
        }
        ~list(){ delete next; }

        list& operator &(const list& B) const;
        list& operator |(const list& B);

        void append(char El);
        void show();
};

list& list::operator &(const list& B) const
{
    list* result = new list();
    const list* tmp_el = this;
    while(tmp_el){
        const list* tmp_B = &B;
        while(tmp_B){
            if(tmp_el->Element == tmp_B->Element){ result->append(tmp_B->Element); }
            tmp_B = tmp_B->next;
        }
        tmp_el = tmp_el->next;
    }
    return *result;
}

list& list::operator |(const list& B)
{
    list* result = new list();
    list* tmp_A = this;
    while(tmp_A){
        result->append(tmp_A->Element);
        tmp_A = tmp_A->next;
    }
    const list* tmp_B = &B;
    bool duplicate;

	while(tmp_B){
		duplicate = true;
		list* tmp_el = result;
		for(; tmp_el && duplicate; tmp_el = tmp_el->next){ if(tmp_B->Element == tmp_el->Element) duplicate = false; }
		if(duplicate) result->append(tmp_B->Element);
		tmp_B = tmp_B->next;
	}

    return *result;
}

inline void list::append(char El)
{
    if(Element){ // Если первый не пустой
        list *tmp_el = this;
        while(tmp_el->next){ tmp_el = tmp_el->next; }
        tmp_el->next = new list(El);
    }
    else{
        Element = El;
    }
}

inline void list::show()
{
    list* tmp_el = this;
    while(tmp_el){
        std::cout << tmp_el->Element;
        tmp_el = tmp_el->next;
    }
}

