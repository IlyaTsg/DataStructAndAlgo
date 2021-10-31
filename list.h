#include <iostream>

class list {
    private:
        char Element;
        list *next;
    public:
        list(){
            Element = 0;
            next = nullptr;
        }
        list(char El){
            Element = El;
            next = nullptr;
        }
        ~list(){ delete next; } 

        void append(char El);
        void show();
};

inline void list::append(char El){
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
    list *tmp_el = this;
    while(tmp_el){
        std::cout << tmp_el->Element;
        tmp_el = tmp_el->next;
    }
}

