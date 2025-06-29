#include <iostream>
#include "Fila.hpp"   // ajuste o caminho se necessário

using namespace std;
using namespace DataStructures;

int main() {
    try {
        Fila<int> fila;

        // 1) enqueue
        cout << "Enfileirando: ";
        for (int i = 1; i <= 5; ++i) {
            cout << i << " ";
            fila.enqueue(i);
        }
        cout << "\n";

        // 2) front (peek)
        if (!fila.empty()) {
            cout << "Frente da fila (front): " << fila.front() << "\n";
        }

        // 3) size
        cout << "Tamanho atual: " << fila.size() << "\n";

        // 4) dequeue de forma segura
        cout << "Desenfileirando: ";
        while (!fila.empty()) {
            int v = fila.dequeue();
            cout << v << " ";
        }
        cout << "\n";

        // 5) deve estar vazia
        cout << "Está vazia? " << (fila.empty() ? "sim" : "não") << "\n";
        cout << "Tamanho após esvaziar: " << fila.size() << "\n";

        // 6) destroy (limpa de novo, não muda nada)
        fila.destroy();
        cout << "Depois de destroy(): está vazia? "
             << (fila.empty() ? "sim" : "não") << "\n";

    } catch (const exception& e) {
        cerr << "Exceção: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
