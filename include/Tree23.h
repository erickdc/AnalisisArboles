#ifndef TREE23_H
#define TREE23_H

#include "Node.h"
#include <SFML/Graphics.hpp>

class Tree23{
public:
    int altura;
    int auxLineaImprime[9];

    Node23 raiz;
    Node23 *aux;

    Tree23();
    Node23 *creaNodo();
    Node23 *buscar(int valor);
    void insertar(int n);
    void crearRama(Node23 *adoptivo);
    void colocarRama(Node23 *ramaI, Node23 *ramaD);
    void actEtiqs(Node23 *inicial);
    void imprime(Node23 *x, int espacio, int hF);
    void eliminar(Node23 *nd);
    void dibujarArbol(sf::RenderWindow *window, Node23 *raiz);
    int valMaxSubarb(Node23 *x);

    virtual ~Tree23();
};

#endif // TREE23_H
