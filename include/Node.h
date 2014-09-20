#ifndef NODE_H
#define NODE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
#include "Edge.h"
class Node
{

    public:
        static float radius ;
        float posX,posY;
        sf::CircleShape circle;
        sf::Font font;
        sf::Text valueText;
        Edge *eIzquierdo, *eDerecho;

        int value;
        Node* izquierdo;
        Node* derecho;
        Node* padre;
        std::string color;
        int altura, posicionX;
        Node(int data, float posX,float posY);


        void initCircle();
        void initNode( float posX,float posY,int data);
        void initTextNumber();
        void setColorNode();
        void drawEdges();
        void setFont(std::string name);
        void render( sf::RenderWindow* w);
        void setColor (sf::Color color);
        void setColorValue(sf::Color color); //Color del Texto
        void StayActualPosition();
        void actualizarGrafico();
        void actualizarPosXAltura();
        std::string getTipoHijo();

        virtual ~Node();
    protected:
    private:

};

#endif // NODE_H
