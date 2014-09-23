#include "RedBlackTree.h"
#include "SFML/Audio.hpp"
 static int screenWidth= 1360;
 static int screenHeight = 768 ;

RedBlackTree::RedBlackTree()
{
    this->raiz= NULL;

    this->message = new ScreenMessage("",0,0);

}

RedBlackTree::~RedBlackTree()
{
    //dtor
}

void RedBlackTree::deleteTreeNode(sf::RenderWindow *w)
{
     if(raiz!=NULL)
        deleteNode(w,raiz);

}

void RedBlackTree::deleteNode(sf::RenderWindow *w, Node*n)
{
      if(n->estaClick(w))
      {

         eliminarNodo(n);
          return;

      }

      if(n->izquierdo!=NULL)
      {

        deleteNode(w,n->izquierdo);


      }

     if(n->derecho!=NULL)
     {
         deleteNode(w,n->derecho);
     }

}
 void RedBlackTree::renderTree(sf::RenderWindow *w, Node*n)
 {
      if(n==NULL)
        return;
      n->render(w);

      if(n->izquierdo!=NULL)
      {

        renderTree(w,n->izquierdo);


      }

     if(n->derecho!=NULL)
     {
         renderTree(w,n->derecho);
     }



 }
 void RedBlackTree::render( sf::RenderWindow *w)
  {
     if(raiz!=NULL)
        renderTree(w,raiz);

      this->message->render(w);


  }
 void RedBlackTree::insertar(int valor)
 {
     if(raiz==NULL)
    {
         raiz = new Node(valor,((screenWidth/2)-Node::radius),450);
         insercion_caso1(raiz);
    }else
    {
        insertarNodo(valor, raiz);
    }

 }

 Node *RedBlackTree::abuelo(Node *n)
{
	if ((n != NULL) && (n->padre != NULL))
		return n->padre->padre;
	else
		return NULL;
}

Node *RedBlackTree::tio(Node *n)
{
	Node *a = abuelo(n);
	if (n->padre == a->izquierdo)
		return a->derecho;
	else
		return a->izquierdo;
}
Node *RedBlackTree::hermano(Node *n)
{
	if (n == n->padre->izquierdo)
		return n->padre->derecho;
	else
		return n->padre->izquierdo;
}

Node *RedBlackTree::hermano_menor(Node *n)
{
	if (n == n->padre->izquierdo)
		return n;
	return n;
}


 void RedBlackTree::rotar_izquierda(Node *p)
{
    this->message->setText("Rotar Izquierda");
    Node **aux=&raiz;
    if(p->padre!=NULL && p->padre->derecho==p)
        aux=&(p->padre->derecho);
    else if(p->padre!=NULL && p->padre->izquierdo==p)
        aux=&(p->padre->izquierdo);

    *aux=p->derecho;

    (*aux)->padre=p->padre;
     p->padre=*aux;
     p->derecho=(*aux)->izquierdo;
    (*aux)->izquierdo=p;

    if(p->derecho!=NULL) p->derecho->padre=p;
}
void RedBlackTree::rotar_derecha(Node *p)
{
      this->message->setText("Rotar Derecha");
    Node **aux=&raiz;
    if(p->padre!=NULL && p->padre->derecho==p)
        aux=&(p->padre->derecho);
    else if(p->padre!=NULL && p->padre->izquierdo==p)
        aux=&(p->padre->izquierdo);

    *aux=p->izquierdo;

    (*aux)->padre=p->padre;

    p->padre=*aux;
    p->izquierdo=(*aux)->derecho;
    (*aux)->derecho=p;

    if(p->izquierdo!=NULL) p->izquierdo->padre=p;
}

void RedBlackTree::insertarNodo(int valor ,Node *n)
{



    if(valor< n->value)
    {
        if(n->izquierdo!=NULL)
            insertarNodo(valor, n->izquierdo);
        else{
              n->izquierdo=new Node(valor,0,0);
              n->izquierdo->padre =n;

              insercion_caso2(n->izquierdo);
        }



    }
    else if(valor>=n->value)
    {
        if(n->derecho!=NULL)
            insertarNodo(valor, n->derecho);
        else{
            n->derecho=new Node(valor,0,0);
            n->derecho->padre =n;

            insercion_caso2(n->derecho);
        }


    }





}

 void RedBlackTree::insercion_caso1(Node *n)
 {

     	if (n->padre == NULL){
              n->color = "NEGRO";
             this->message->setText("The root is always black");

     	}

        else
            insercion_caso2(n);
 }
void RedBlackTree::insercion_caso2(Node *n)
{
    if(raiz->color=="ROJO")
        raiz->color="NEGRO";

       this->message->setText("Red Node has black Children ");
	if (n->padre->color == "NEGRO")
		return; /* Árbol válido. */
	else
		insercion_caso3(n);
}

void RedBlackTree::insercion_caso3(Node *n)
{
	Node *t = tio(n), *a;

      this->message->setText("Recolor red Uncle,Father and Grandpa");
	if ((t != NULL) && (t->color == "ROJO")) {
		n->padre->color = "NEGRO";
		t->color = "NEGRO";
		a = abuelo(n);
		a->color = "ROJO";
		insercion_caso1(a);
	} else {
		insercion_caso4(n);
    }
}
void RedBlackTree::insercion_caso4(Node *n)
{
	Node *a = abuelo(n);

	if ((n == n->padre->derecho) && (n->padre == a->izquierdo)) {
		rotar_izquierda(n->padre);
		n=n->izquierdo;
	} else if ((n == n->padre->izquierdo) && (n->padre == a->derecho)) {
		rotar_derecha(n->padre);
		n=n->derecho;
	}
	insercion_caso5(n);
}

void RedBlackTree::insercion_caso5(Node *n)
{
	Node *a = abuelo(n);

	n->padre->color = "NEGRO";
	a->color = "ROJO";
	if ((n == n->padre->izquierdo) && (n->padre == a->izquierdo)) {
		rotar_derecha(a);
	} else {
		/*
		 * En este caso, (n == n->padre->dcho) && (n->padre == a->dcho).
		 */
		rotar_izquierda(a);
	}
}
 bool RedBlackTree:: es_hoja(Node *n)
 {
     if(n!=NULL)
        return false;
     return true;
 }

void  RedBlackTree::reemplazar_nodo(Node *n, Node *hijo)
{
    hijo = n;



}

void RedBlackTree::eliminarNodo(Node* n)
{

   /* sf::SoundBuffer buffer;
        buffer.loadFromFile("bang.aiff");*/

    /*Node* actual=n;

    if(raiz==NULL)
    {
        return;

    }else if(n->padre==NULL && n->derecho==NULL && n->izquierdo==NULL)
    {
        raiz=NULL;
        free(n);
        return;
    }else if(raiz->izquierdo == NULL && raiz->derecho!=NULL)
    {




         raiz = raiz->derecho;
         actual->derecho =NULL;



        delete actual;


    }
*/
   /* if(n->derecho==NULL && n->izquierdo==NULL)
    {
        if(n->padre->izquierdo ==n)
        {
            n->padre->removeLeftChild();
        }else
        {
            n->padre->removeRightChild();
        }

        free(n);
        return;
    }*/



}
void RedBlackTree::elimina_un_hijo(Node *n)
{

    eliminarNodo(n);

	Node *hijo = es_hoja(n->derecho) ? n->izquierdo : n->derecho;

	reemplazar_nodo(n, hijo);
	if (n->color == "NEGRO") {
		if (hijo->color == "ROJO")
			hijo->color = "NEGRO";
		else
			eliminar_caso1(hijo);
	}
	free(n);
}
void RedBlackTree::eliminar_caso1(Node *n)
{
	if (n->padre!= NULL)
		eliminar_caso2(n);
}

void RedBlackTree::eliminar_caso2(Node *n)
{
	Node *hm = hermano(n);

	if (hm->color == "ROJO") {
		n->padre->color = "ROJO";
		hm->color = "NEGRO";
		if (n == n->padre->izquierdo)
			rotar_izquierda(n->padre);
		else
			rotar_derecha(n->padre);
	}
	eliminar_caso3(n);
}

void RedBlackTree::eliminar_caso3(Node *n)
{
	Node *hm = hermano_menor(n);

	if ((n->padre->color == "NEGRO") &&
	 (hm->color == "NEGRO") &&
	 (hm->izquierdo->color == "NEGRO") &&
	 (hm->derecho->color == "NEGRO")) {
		hm->color = "ROJO";
		eliminar_caso1(n->padre);
	} else
		eliminar_caso4(n);
}

void RedBlackTree::eliminar_caso4(Node *n)
{
	Node *hm = hermano_menor(n);

	if ((n->padre->color == "ROJO") &&
	 (hm->color == "NEGRO") &&
	 (hm->izquierdo->color == "NEGRO") &&
	 (hm->derecho->color == "NEGRO")) {
		hm->color = "ROJO";
		n->padre->color = "NEGRO";
	} else
		eliminar_caso5(n);
}

void RedBlackTree::eliminar_caso5(Node *n)
{
	Node *hm = hermano(n);

	if ((n == n->padre->izquierdo) &&
	 (hm->color == "NEGRO") &&
	 (hm->izquierdo->color == "ROJO") &&
	 (hm->derecho->color == "NEGRO")) {
		hm->color = "ROJO";
		hm->izquierdo->color = "NEGRO";
		rotar_derecha(hm);
	} else if ((n == n->padre->derecho) &&
	 (hm->color == "NEGRO") &&
	 (hm->derecho->color == "ROJO") &&
	 (hm->izquierdo->color == "NEGRO")) {
		hm->color = "ROJO";
		hm->derecho->color = "NEGRO";
		rotar_izquierda(hm);
	}
	eliminar_caso6(n);
}

void RedBlackTree::eliminar_caso6(Node *n)
{
	 Node *hm = hermano(n);

	hm->color = n->padre->color;
	n->padre->color = "NEGRO";
	if (n == n->padre->izquierdo) {

		hm->derecho->color = "NEGRO";
		rotar_izquierda(n->padre);
	} else {

		hm->izquierdo->color = "NEGRO";
		rotar_derecha(n->padre);
	}
}

