#ifndef _PILHA_HPP
#define _PILHA_HPP
#include <iostream>
#include "../Lista/Lista.hpp"

namespace DataStructures
{
    template <typename T>
    class Pilha
    {
        private:
            Lista<T> *list;

        public:
            Pilha():list(new Lista<T>()){};
            Pilha(const Pilha& other):list(new Lista<T>(*other.getList())){};
            ~Pilha(){delete list;}

            const Lista<T>& getList() const {return *list;};
            bool empty()const {return list->getSize()==0;};
            std::size_t size()const {return list->getSize();};

            void destroy(){list->limpar();}

            void push(const T valor){list->insert_back(valor);}
            T peak()const 
            {
                if (empty()) {
                    throw std::runtime_error("front() em fila vazia");
                }
                return list->getTail()->getInfo();
            }
            T pop()
            {
                T valor = peak();
                list->remove_back();

                return valor;
            }

    };
}

#endif