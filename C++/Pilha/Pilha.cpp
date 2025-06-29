#include <iostream>
#include "Pilha.hpp"  
using namespace std;
using namespace DataStructures;

int main() {
    try {
        Pilha<int> pilha;

        cout << "Empilhando: ";
        for (int i = 1; i <= 5; ++i) {
            cout << i << " ";
            pilha.push(i);
        }
        cout << "\n";

        cout << "Tamanho atual: " << pilha.size() << "\n";
        cout << "Topo da pilha (peak): " << pilha.peak() << "\n";

        cout << "Desempilhando: ";
        while (!pilha.empty()) {
            int v = pilha.pop();
            cout << v << " ";
        }
        cout << "\n";

        cout << "Está vazia? " << (pilha.empty() ? "sim" : "não") << "\n";
        cout << "Tamanho após esvaziar: " << pilha.size() << "\n";

        // Reutilizando destroy (não faz diferença nesse caso)
        pilha.destroy();
        cout << "Após destroy(), está vazia? "
             << (pilha.empty() ? "sim" : "não") << "\n";

    } catch (const exception& e) {
        cerr << "Exceção: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
