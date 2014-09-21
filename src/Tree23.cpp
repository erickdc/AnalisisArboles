#include "Tree23.h"
#include <stdio.h>

using namespace std;

Tree23::Tree23(){
    altura = -1;
    raiz.nPadre = NULL;
    raiz.hijoIzq = NULL;
    raiz.hijoCen = NULL;
    raiz.hijoDer = NULL;
}

void Tree23::insertar(int n){
    Node23 *nuevo;
    int cnt;

    if(altura < 0){
        raiz.val = n;
        //strcpy(raiz.cadena,c);
        altura = 0;
        return;
    }

    nuevo = creaNodo();
    nuevo->val = n;
    //strcpy(nuevo->cadena,c);

    if(altura == 0){
        aux = creaNodo();
        aux->val = raiz.val;
        //strcpy(aux->cadena,raiz.cadena);
        raiz.val = 0;
        //strcpy(raiz.cadena,"");
        raiz.hijoIzq = (aux->val >= nuevo->val?nuevo:aux);
        raiz.hijoCen = (aux->val >= nuevo->val?aux:nuevo);
        raiz.hijoDer = NULL;
        nuevo->nPadre = &raiz;
        aux->nPadre = &raiz;
        actEtiqs(&raiz);
        altura = 1;
        return;
    }

    aux=&raiz; cnt=0;
    while(++cnt<altura){
        if(n <= aux->etiqIzq)
            aux = aux->hijoIzq;
        else if(n <= aux->etiqDer)
            aux = aux->hijoCen;
        else
            aux = (aux->hijoDer ? aux->hijoDer:aux->hijoCen);
    };

    if(!aux->hijoDer){
        if(n < aux->etiqIzq){
            aux->hijoDer = aux->hijoCen;
            aux->hijoCen = aux->hijoIzq;
            aux->hijoIzq = nuevo;
        }else if(n < aux->etiqDer){
            aux->hijoDer = aux->hijoCen;
            aux->hijoCen=nuevo;
        }else{
            aux->hijoDer = nuevo;
        }
        nuevo->nPadre = aux;
        actEtiqs(&raiz);
        return;
    }

    crearRama(nuevo), actEtiqs(&raiz);
}

Node23 *Tree23::creaNodo(){
    Node23 *tmp = new Node23;
    tmp->nPadre = NULL;
    tmp->hijoIzq = NULL;
    tmp->hijoCen = NULL;
    tmp->hijoDer = NULL;
    return tmp;
}

void Tree23::crearRama(Node23 *adoptivo){

    Node23 *aux2;
    Node23 *aux3;
    aux2 = creaNodo();

    if(adoptivo->val < aux->etiqDer){
        aux2->hijoIzq = aux->hijoCen;
        aux2->hijoCen = aux->hijoDer;
        aux3 = aux2->hijoIzq;
        aux3->nPadre = aux2;
        aux3 = aux2->hijoCen;
        aux3->nPadre = aux2;

        if(adoptivo->val < aux->etiqIzq){
            aux->hijoCen = aux->hijoIzq;
            aux->hijoIzq = adoptivo;
        }else{
            aux->hijoCen=adoptivo;
        }

        adoptivo->nPadre=aux;
    }else{
        aux3 = aux->hijoDer;
        aux3->nPadre = aux2;
        adoptivo->nPadre = aux2;
        aux2->hijoIzq = (adoptivo->val < aux3->val ? adoptivo:aux3);
        aux2->hijoCen = (adoptivo->val < aux3->val ? aux3:adoptivo);
    }
    aux->hijoDer=NULL; aux2->hijoDer=NULL;
    colocarRama(aux, aux2);
}

void Tree23::colocarRama(Node23 *ramaI, Node23 *ramaD){
    Node23 *aux2;
    Node23 *aux3;
    aux = ramaI->nPadre;

    if(aux){
        if(!aux->hijoDer){
            if(aux->hijoIzq == ramaI){
                aux->hijoDer = aux->hijoCen;
                aux->hijoCen = ramaD;
            }else{
                aux->hijoDer=ramaD;
            }
            ramaD->nPadre=aux;
            return;
        }

        aux2= creaNodo();

        if(aux->hijoIzq == ramaI){
            aux2->hijoIzq = aux->hijoCen;
            aux2->hijoCen = aux->hijoDer;
            aux->hijoCen = ramaD;
            ramaD->nPadre = aux;
        }else{
            aux2->hijoIzq = (aux->hijoCen == ramaI ? ramaD:aux->hijoDer);
            aux2->hijoCen = (aux->hijoCen == ramaI ? aux->hijoDer:ramaD);
        }
        aux3 = aux2->hijoIzq;
        aux3->nPadre = aux2;
        aux3 = aux2->hijoCen;
        aux3->nPadre = aux2;
        aux->hijoDer = NULL;
        aux2->hijoDer = NULL;
        colocarRama(aux, aux2);
    }else{
        aux2 = creaNodo();
        aux2->hijoIzq = ramaI->hijoIzq;
        aux2->hijoCen = ramaI->hijoCen;
        aux2->hijoDer = ramaI->hijoDer;
        aux3 = aux2->hijoIzq;
        aux3->nPadre = aux2;
        aux3 = aux2->hijoCen;
        aux3->nPadre = aux2;

        if(aux2->hijoDer){
            aux3=aux2->hijoDer;
            aux3->nPadre = aux2;
        }

        raiz.hijoIzq = aux2;
        raiz.hijoCen = ramaD;
        raiz.hijoDer = NULL;
        aux2->nPadre = &raiz;
        ramaD->nPadre = &raiz;
        altura++;
    }
}

void Tree23::actEtiqs(Node23 *inicial){
    if(inicial->hijoIzq){
        inicial->etiqIzq = valMaxSubarb(inicial->hijoIzq);
        inicial->etiqDer = valMaxSubarb(inicial->hijoCen);
        actEtiqs(inicial->hijoIzq);
        actEtiqs(inicial->hijoCen);
    }

    if(inicial->hijoDer){
        actEtiqs(inicial->hijoDer);
    }
}

int Tree23::valMaxSubarb(Node23 *x){
    if(x->hijoDer)
        return valMaxSubarb(x->hijoDer);
    else if(x->hijoCen)
        return valMaxSubarb(x->hijoCen);
    else
        return x->val;
}

void Tree23::imprime(Node23 *x, int espacio, int hF){
    int cnt = 0;
    cout << "\n";

    while(++cnt < espacio){
        cout << (char)(auxLineaImprime[cnt-1] == 1 ? 179:32) << " ";
    }

    if(x != &raiz){
        cout << (char)(hF == 1 ? 192:195) << " ";
    }

    if(espacio > 0){
        auxLineaImprime[espacio-1] = (hF == 1 ? 0:1);
    }

    if(x->hijoIzq){
        cout << "[" << x->etiqIzq << " : " << x->etiqDer << "]"/* Etiqueta"*/;
        imprime(x->hijoIzq, espacio + 1, 0);
        imprime(x->hijoCen, espacio + 1, (x->hijoDer ? 0:1));

        if(x->hijoDer){
            imprime(x->hijoDer, espacio + 1, 1);
        }
    }else{
        cout << " val=[" << x->val << "]"/* Cadena=[" << x->cadena << "]"*/;
    }
}

void Tree23::eliminar(Node23 *nd){
    if(nd->hijoIzq) eliminar(nd->hijoIzq);
    if(nd->hijoCen) eliminar(nd->hijoCen);
    if(nd->hijoDer) eliminar(nd->hijoDer);
    delete nd;
}

Node23 *Tree23::buscar(int valor){
    if(altura == -1)
        return NULL;

    aux = &raiz;

    while(aux->hijoIzq){ /*Solo hay que recorrer comparando con las etiquetas*/
        if(valor <= aux->etiqIzq)
            aux = aux->hijoIzq;
        else if(valor <= aux->etiqDer)
            aux = aux->hijoCen;
        else if(aux->hijoDer)
            aux = aux->hijoDer;
        else
            return NULL;
    }

    return (valor == aux->val ? aux:NULL);
}

void Tree23::dibujarArbol(sf::RenderWindow *window, Node23 *raiz){

    if(altura < 0)
        return;

    if(raiz->hijoIzq){
        raiz->dibujarNodo23(window, raiz->etiqIzq, raiz->etiqDer);
        dibujarArbol(window, raiz->hijoIzq);
        dibujarArbol(window, raiz->hijoCen);

        if(raiz->hijoDer)
            dibujarArbol(window, raiz->hijoDer);

    }else{
        raiz->dibujarNodo23(window, raiz->val, -1);
    }
}

Tree23::~Tree23(){
    //dtor
}
