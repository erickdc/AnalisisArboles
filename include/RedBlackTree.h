#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "Node.h"
#include "ScreenMessage.h"

class RedBlackTree
{
    public:
        Node *raiz;
        ScreenMessage *message;
        RedBlackTree();


        Node *abuelo(Node *n);
        Node *tio(Node *n);
        Node *hermano(Node *n);

        void rotar_izquierda(Node *p);
        void rotar_derecha(Node *p);

        void insertarNodo(int valor,Node *n);
        void insertar(int valor);

        void insercion_caso1(Node *n);
        void insercion_caso2(Node *n);
        void insercion_caso3(Node *n);
        void insercion_caso4(Node *n);
        void insercion_caso5(Node *n);

         void elimina_un_hijo(Node *n);
         void eliminar_caso1(Node *n);
         void eliminar_caso2(Node *n);
         void eliminar_caso3(Node *n);
         void eliminar_cas4(Node *n);
         void eliminar_caso5(Node *n);
         void eliminar_caso6(Node *n);

          bool es_hoja(Node *n);

          void render(sf::RenderWindow *w);
          void renderTree(sf::RenderWindow *w, Node*n);
        virtual ~RedBlackTree();
    protected:
    private:
};

#endif // REDBLACKTREE_H
