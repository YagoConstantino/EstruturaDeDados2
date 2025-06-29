#include <iostream>
#include "AVL.hpp"
#include <vector>

template<typename T>
void testAVL(const std::vector<T>& valores, T buscar1, T buscar2, T remover) {
    DataStructures::AVL<T> avl;
    auto* root = static_cast<typename DataStructures::AVL<T>::Elem*>(nullptr);

    std::cout << "\n=== Teste AVL<" << typeid(T).name() << "> ===\n";
    std::cout << "Inserindo: ";
    for (auto v : valores) {
        std::cout << v << " ";
        root = avl.inserir(root, v);
    }
    std::cout << "\n\n";

    std::cout << "In-order (ordenada): ";
    avl.inOrder(root);  std::cout << "\n";
    std::cout << "Pre-order: ";
    avl.preOrder(root); std::cout << "\n";
    std::cout << "Des-order (decrescente): ";
    avl.desOrder(root); std::cout << "\n\n";

    std::cout << "Buscar " << buscar1 << ": "
              << (avl.buscar(root, buscar1) ? "encontrado\n" : "nao encontrado\n");
    std::cout << "BuscarIte " << buscar2 << ": "
              << (avl.buscarIte(root, buscar2) ? "encontrado\n" : "nao encontrado\n\n");

    std::cout << "Removendo " << remover << "...\n";
    root = avl.remover(root, remover);

    std::cout << "In-order apos remocao: ";
    avl.inOrder(root); std::cout << "\n";
}

int main() {
    // 1) Teste com int
    testAVL<int>({30,20,40,10,25,35,50,5,15}, 25, 100, 20);

    // 2) Teste com float
    testAVL<float>({3.5f, 1.2f, 4.8f, 0.9f, 2.3f, 6.7f}, 2.3f, 9.9f, 1.2f);

    // 3) Teste com char
    testAVL<char>({'m','a','z','e','c','h','t'}, 'e', 'x', 'a');

    return 0;
}
