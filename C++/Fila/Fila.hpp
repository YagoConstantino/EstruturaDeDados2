#ifndef _FILA_HPP
#define _FILA_HPP

#include <iostream>
#include "../Lista/Lista.hpp"

namespace DataStructures {

    template <typename T>
    class Fila {
    private:
        Lista<T>* list;

    public:
        Fila(): list(new Lista<T>()) {}

        Fila(const Fila& other): list(new Lista<T>(*other.getList())){}
        ~Fila() { delete list;}

        const Lista<T>& getList() const {return *list;}

        bool empty() const {return list->getSize() == 0;}
        std::size_t size() const {return list->getSize();}

        void destroy() { list->limpar();}

        void enqueue(const T valor) {list->insert_back(valor);}

        T dequeue() {
            if (empty()) {
                throw std::runtime_error("dequeue() em fila vazia");
            }
            T ret = list->getHead()->getInfo();
            list->remove_front();
            return ret;
        }

        T front() {
            if (empty()) {
                throw std::runtime_error("front() em fila vazia");
            }
            return list->getHead()->getInfo();
        }

    };

} // namespace DataStructures

#endif // FILA_HPP
