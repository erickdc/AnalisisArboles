#include "ArbolesRojosNegros.h"

ArbolesRojosNegros::ArbolesRojosNegros()
{
    //ctor
}

ArbolesRojosNegros::~ArbolesRojosNegros()
{
    //dtor
}
struct node *abuelo(struct node *n)
{
	if ((n != 0) && (n->padre != 0))
		return n->padre->padre;
	else
		return 0;
}
struct node *tio(struct node *n)
{
	struct node *a = abuelo(n);
	if (n->padre == a->izdo)
		return a->dcho;
	else
		return a->izdo;
}

void insercion_caso1(struct node *n)
{
	if (n->padre == NULL)
		n->color = NEGRO;
	else
		insercion_caso2(n);
}
void insercion_caso2(struct node *n)
{
	if (n->padre->color == NEGRO)
		return; /* Árbol válido. */
	else
		insercion_caso3(n);
}

void insercion_caso3(struct node *n)
{
	struct node *t = tio(n), *a;

	if ((t != NULL) && (t->color == ROJO)) {
		n->padre->color = NEGRO;
		t->color = NEGRO;
		a = abuelo(n);
		a->color = ROJO;
		insercion_caso1(a);
	} else {
		insercion_caso4(n);
        }
}

void insercion_caso4(struct node *n)
{
	struct node *a = abuelo(n);

	if ((n == n->padre->dcho) && (n->padre == a->izdo)) {
		rotar_izda(n->padre);
		n=n->izdo;
	} else if ((n == n->padre->izdo) && (n->padre == a->dcho)) {
		rotar_dcha(n->padre);
		n=n->dcho;
	}
	insercion_caso5(n);
}
void insercion_caso5(struct node *n)
{
	struct node *a = abuelo(n);

	n->padre->color = NEGRO;
	a->color = ROJO;
	if ((n == n->padre->izdo) && (n->padre == a->izdo)) {
		rotar_dcha(a);
	} else {
		/*
		 * En este caso, (n == n->padre->dcho) && (n->padre == a->dcho).
		 */
		rotar_izda(a);
	}
}

struct node * hermano(struct node *n)
{
	if (n == n->padre->izdo)
		return n->padre->dcho;
	else
		return n->padre->izdo;
}

void elimina_un_hijo(struct node *n)
{
	/*
	 * Precondición: n tiene al menos un hijo no nulo.
	 */
	struct node *hijo = es_hoja(n->dcho) ? n->izdo : n->dcho;

	reemplazar_nodo(n, hijo);
	if (n->color == NEGRO) {
		if (hijo->color == ROJO)
			hijo->color = NEGRO;
		else
			eliminar_caso1(hijo);
	}
	free(n);
}

void eliminar_caso1(struct node *n)
{
	if (n->padre!= NULL)
		eliminar_caso2(n);
}

void eliminar_caso2(struct node *n)
{
	struct node *hm = hermano(n);

	if (hm->color == ROJO) {
		n->padre->color = ROJO;
		hm->color = NEGRO;
		if (n == n->padre->izdo)
			rotar_izda(n->padre);
		else
			rotar_dcha(n->padre);
	}
	eliminar_caso3(n);
}

void eliminar_caso3(struct node *n)
{
	struct node *hm = hermano_menor(n);

	if ((n->padre->color == NEGRO) &&
	 (hm->color == NEGRO) &&
	 (hm->izdo->color == NEGRO) &&
	 (hm->dcho->color == NEGRO)) {
		hm->color = ROJO;
		eliminar_caso1(n->padre);
	} else
		eliminar_caso4(n);
}

void eliminar_caso4(struct node *n)
{
	struct node *hm = hermano_menor(n);

	if ((n->padre->color == ROJO) &&
	 (hm->color == NEGRO) &&
	 (hm->izdo->color == NEGRO) &&
	 (hm->dcho->color == NEGRO)) {
		hm->color = ROJO;
		n->padre->color = NEGRO;
	} else
		eliminar_caso5(n);
}

void eliminar_caso5(struct node *n)
{
	struct node *hm = hermano(n);

	if ((n == n->padre->izdo) &&
	 (hm->color == NEGRO) &&
	 (hm->izdo->color == ROJO) &&
	 (hm->dcho->color == NEGRO)) {
		hm->color = ROJO;
		hm->izdo->color = NEGRO;
		rotar_dcha(hm);
	} else if ((n == n->padre->dcho) &&
	 (hm->color == NEGRO) &&
	 (hm->dcho->color == ROJO) &&
	 (hm->izdo->color == NEGRO)) {
		hm->color = ROJO;
		hm->dcho->color = NEGRO;
		rotar_izda(hm);
	}
	eliminar_caso6(n);
}

void eliminar_caso6(struct node *n)
{
	struct node *hm = hermano(n);

	hm->color = n->padre->color;
	n->padre->color = NEGRO;
	if (n == n->padre->izdo) {
		/*
		 * Aquí, hm->dcho->color == ROJO.
		 */
		hm->dcho->color = NEGRO;
		rotar_izda(n->padre);
	} else {
		/*
		 * Aquí, hm->izdo->color == ROJO.
		 */
		hm->izdo->color = NEGRO;
		rotar_dcha(n->padre);
	}
}
