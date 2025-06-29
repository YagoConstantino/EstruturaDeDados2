#ifndef _AVL_HPP_
#define _AVL_HPP_

#include <iostream>
#include <stdexcept>

int maior(int a, int b) { return a > b ? a : b; }

namespace DataStructures {
    //T deve suportar > e < para funcionar 
    template <typename T>
    class AVL {
    public:
        class Elem {
        private:
            T info;
            int altura;
            Elem* esq;
            Elem* dir;

        public:
            Elem(T inf, Elem* e = nullptr, Elem* d = nullptr)
                : info(inf), esq(e), dir(d), altura(0) {}
            T getInfo() const { return info; }
            void setInfo(T inf) { info = inf; }
            int getAltura() const { return altura; }
            void setAltura(int alt) { altura = alt; }
            Elem* getEsq() const { return esq; }
            Elem* getDir() const { return dir; }
            void setEsq(Elem* e) { esq = e; }
            void setDir(Elem* d) { dir = d; }
        };

        AVL() : raiz(nullptr) {}
        AVL(Elem* r) : raiz(r) {}
        ~AVL() { limpar(raiz); }

        Elem* inserir(Elem* el, T info);
        Elem* remover(Elem* el, T info);
        bool buscar(Elem* el, T v) const;
        bool buscarIte(Elem* el, T v) const;

        void inOrder(Elem* el) const;
        void preOrder(Elem* el) const;
        void posOrder(Elem* el) const;
        void desOrder(Elem* el) const;

        T minimo(Elem* el) const;
        T maximo(Elem* el) const;

        T maiorRamo(Elem* el) const;
        bool pertence_arv(Elem* el, T c) const;
        int conta_nos(Elem* el) const;
        int calcula_altura_Elem(Elem* el) const;
        int conta_nos_folha(Elem* el) const;
        bool verifica_Elem_cheia(Elem* el) const;
        T ancestral(Elem* el, T e1, T e2) const;

        Elem* espelha_AVl(Elem* el) const;
        Elem* copiaAVL(Elem* el) const;

        Elem* getRaiz() const { return raiz; }

    private:
        Elem* raiz;

        void limpar(Elem* el);
        int alturaElem(Elem* el) const;
        int atualizar_altura(Elem* el) const;
        int balanceamento(Elem* el) const;
        Elem* rotacao_simples_esq(Elem* el);
        Elem* rotacao_simples_dir(Elem* el);
        Elem* rotacao_dupla_esq(Elem* el);
        Elem* rotacao_dupla_dir(Elem* el);
        Elem* atualizar_fb_esq(Elem* el);
        Elem* atualizar_fb_dir(Elem* el);
    };

    // Implementations

    template <typename T>
    inline void AVL<T>::limpar(Elem* el) {
        if (!el) return;
        limpar(el->getEsq()); 
        limpar(el->getDir());
        delete el;
    }

    template <typename T>
    inline int AVL<T>::alturaElem(Elem* el) const {
        return el ? el->getAltura() : -1;
    }

    template <typename T>
    inline int AVL<T>::atualizar_altura(Elem* el) const {
        return maior(alturaElem(el->getEsq()), alturaElem(el->getDir())) + 1;
    }

    template <typename T>
    inline int AVL<T>::balanceamento(Elem* el) const {
        return alturaElem(el->getDir()) - alturaElem(el->getEsq());
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::rotacao_simples_esq(Elem* el) {
        Elem* tmp = el->getDir();
        el->setDir(tmp->getEsq()); 
        tmp->setEsq(el);
        el->setAltura(atualizar_altura(el)); 
        tmp->setAltura(atualizar_altura(tmp));
        return tmp;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::rotacao_simples_dir(Elem* el) {
        Elem* tmp = el->getEsq();
        el->setEsq(tmp->getDir()); 
        tmp->setDir(el);
        el->setAltura(atualizar_altura(el)); 
        tmp->setAltura(atualizar_altura(tmp));
        return tmp;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::rotacao_dupla_esq(Elem* el) {
        el->setDir(rotacao_simples_dir(el->getDir()));
        return rotacao_simples_esq(el);
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::rotacao_dupla_dir(Elem* el) {
        el->setEsq(rotacao_simples_esq(el->getEsq()));
        return rotacao_simples_dir(el);
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::atualizar_fb_esq(Elem* el) {
        el->setAltura(atualizar_altura(el));
        if (balanceamento(el) == -2) {
            if (balanceamento(el->getEsq()) <= 0)
                el = rotacao_simples_dir(el);
            else
                el = rotacao_dupla_dir(el);
        }
        return el;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::atualizar_fb_dir(Elem* el) {
        el->setAltura(atualizar_altura(el));
        if (balanceamento(el) == 2) {
            if (balanceamento(el->getDir()) >= 0)
                el = rotacao_simples_esq(el);
            else
                el = rotacao_dupla_esq(el);
        }
        return el;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::inserir(Elem* el, T info) {
        if (!el) return new Elem(info);
        if (info < el->getInfo()) el->setEsq(inserir(el->getEsq(), info)), el = atualizar_fb_esq(el);
        else                       el->setDir(inserir(el->getDir(), info)), el = atualizar_fb_dir(el);
        return el;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::remover(Elem* el, T info) {
        if (!el) return nullptr;
        if (info < el->getInfo())       el->setEsq(remover(el->getEsq(), info)), el = atualizar_fb_dir(el);
        else if (info > el->getInfo())  el->setDir(remover(el->getDir(), info)), el = atualizar_fb_esq(el);
        else {
            if (!el->getEsq() && !el->getDir()) { delete el; return nullptr; }
            if (!el->getEsq()) { 
                Elem* tmp = el->getDir(); 
                delete el; 
                return tmp; 
            }
            if (!el->getDir()) { 
                Elem* tmp = el->getEsq(); 
                delete el; 
                return tmp; 
            }
            Elem* pred = el->getEsq(); 
            while (pred->getDir()) 
            pred = pred->getDir();
            el->setInfo(pred->getInfo());
            el->setEsq(remover(el->getEsq(), pred->getInfo()));
            el = atualizar_fb_dir(el);
        }
        return el;
    }

    template <typename T>
    inline bool AVL<T>::buscar(Elem* el, T v) const {
        if (!el) return false;
        if (el->getInfo() == v) return true;
        return (v < el->getInfo()) ? buscar(el->getEsq(), v) : buscar(el->getDir(), v);
    }

    template <typename T>
    inline bool AVL<T>::buscarIte(Elem* el, T v) const {
        while (el) {
            if (el->getInfo() == v) return true;
            el = (v < el->getInfo()) ? el->getEsq() : el->getDir();
        }
        return false;
    }

    template <typename T>
    inline void AVL<T>::inOrder(Elem* el) const { 
        if (!el) return; 
        inOrder(el->getEsq()); 
        std::cout<<el->getInfo()<<" "; 
        inOrder(el->getDir()); 
    }

    template <typename T>
    inline void AVL<T>::preOrder(Elem* el) const { 
        if (!el) return; 
        std::cout<<el->getInfo()<<" "; 
        preOrder(el->getEsq()); 
        preOrder(el->getDir()); 
    }

    template <typename T>
    inline void AVL<T>::posOrder(Elem* el) const { 
        if (!el) return; 
        posOrder(el->getEsq()); 
        posOrder(el->getDir()); 
        std::cout<<el->getInfo()<<" "; 
    }

    template <typename T>
    inline void AVL<T>::desOrder(Elem* el) const { 
        if (!el) return; 
        desOrder(el->getDir()); 
        std::cout<<el->getInfo()<<" "; 
        desOrder(el->getEsq()); 
    }

    template <typename T>
    inline T AVL<T>::minimo(Elem* el) const {
        if (!el) throw std::runtime_error("Árvore vazia");
        while (el->getEsq()) el = el->getEsq();
        return el->getInfo();
    }

    template <typename T>
    inline T AVL<T>::maximo(Elem* el) const {
        if (!el) throw std::runtime_error("Árvore vazia");
        while (el->getDir()) el = el->getDir();
        return el->getInfo();
    }

    template <typename T>
    inline T AVL<T>::maiorRamo(Elem* el) const {
        if (!el) return 0;
        T somaEsq = maiorRamo(el->getEsq());
        T somaDir = maiorRamo(el->getDir());
        return el->getInfo() + maior(somaEsq, somaDir);
    }

    template <typename T>
    inline bool AVL<T>::pertence_arv(Elem* el, T c) const {
        if (!el) return false;
        if (el->getInfo() == c) return true;
        return pertence_arv(el->getEsq(), c) || pertence_arv(el->getDir(), c);
    }

    template <typename T>
    inline int AVL<T>::conta_nos(Elem* el) const {
        if (!el) return 0;
        return 1 + conta_nos(el->getEsq()) + conta_nos(el->getDir());
    }

    template <typename T>
    inline int AVL<T>::calcula_altura_Elem(Elem* el) const {
        if (!el) return -1;
        return 1 + maior(calcula_altura_Elem(el->getEsq()), calcula_altura_Elem(el->getDir()));
    }

    template <typename T>
    inline int AVL<T>::conta_nos_folha(Elem* el) const {
        if (!el) return 0;
        if (!el->getEsq() && !el->getDir()) return 1;
        return conta_nos_folha(el->getEsq()) + conta_nos_folha(el->getDir());
    }

    template <typename T>
    inline bool AVL<T>::verifica_Elem_cheia(Elem* el) const {
        if (!el) return true;
        if (!el->getEsq() && !el->getDir()) return true;
        if (el->getEsq() && el->getDir())
            return verifica_Elem_cheia(el->getEsq()) && verifica_Elem_cheia(el->getDir());
        return false;
    }

    template <typename T>
    inline T AVL<T>::ancestral(Elem* el, T e1, T e2) const {
        if (!el) throw std::runtime_error("Árvore vazia");
        if (e1 < el->getInfo() && e2 < el->getInfo())
            return ancestral(el->getEsq(), e1, e2);
        if (e1 > el->getInfo() && e2 > el->getInfo())
            return ancestral(el->getDir(), e1, e2);
        return el->getInfo();
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::espelha_AVl(Elem* el) const {
        if (!el) return nullptr;
        Elem* novo = new Elem(el->getInfo());
        novo->setEsq(espelha_AVl(el->getDir()));
        novo->setDir(espelha_AVl(el->getEsq()));
        novo->setAltura(atualizar_altura(novo));
        return novo;
    }

    template <typename T>
    inline typename AVL<T>::Elem* AVL<T>::copiaAVL(Elem* el) const {
        if (!el) return nullptr;
        Elem* novo = new Elem(el->getInfo());
        novo->setEsq(copiaAVL(el->getEsq()));
        novo->setDir(copiaAVL(el->getDir()));
        novo->setAltura(el->getAltura());
        return novo;
    }

} // namespace DataStructures

#endif // _AVL_HPP_
