#ifndef ARBOLESROJOSNEGROS_H
#define ARBOLESROJOSNEGROS_H


class ArbolesRojosNegros
{
    public:
        ArbolesRojosNegros();
        void rotar_izda(struct node *p);
        void rotar_dcha(struct node *p);
        struct node *abuelo(struct node *n);
        void insercion_caso1(struct node *n);
        void insercion_caso2(struct node *n);
        void insercion_caso3(struct node *n);
        void insercion_caso4(struct node *n);
        void insercion_caso5(struct node *n);
        struct node *hermano(struct node *n);
        void elimina_un_hijo(struct node *n);
        void eliminar_caso1(struct node *n);
        void eliminar_caso2(struct node *n);
        void eliminar_caso3(struct node *n);
        void eliminar_caso4(struct node *n);
        void eliminar_caso5(struct node *n);
        void eliminar_caso6(struct node *n);
        virtual ~ArbolesRojosNegros();
    protected:
    private:
};

#endif // ARBOLESROJOSNEGROS_H
