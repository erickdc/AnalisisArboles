#include "Node.h"
#include  <iostream> ;
#include <stdlib.h>
float Node::radius = 50.0f;
static int screenWidth= 1360;
 static int screenHeight = 768 ;
Node::Node(int data,float posX,float posY)
{

    initNode(posX,posY,data);
    initCircle();
    setFont("Marlboro.ttf");
    this->eIzquierdo=new Edge(0,0,0,0);
    this->eDerecho=new Edge(0,0,0,0);
    initTextNumber();
    this->posicionX =300;
    this->altura = 0;
}


void Node::initNode( float posX,float posY,int data)
{
    this->color="ROJO";
    this->posX=posX;
    this->posY=posY;
    this->padre=NULL;
    this->derecho= NULL;
    this->izquierdo=NULL;
    this->value = data;
}
 void Node::initCircle()
 {
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(radius);
    circle.setPosition(this->posX,this->posY);
 }


void Node::initTextNumber()
{
     char chString[32];
     itoa(this->value, chString, 10); //stdlib.h

     valueText = sf::Text(chString,font);
     valueText.setPosition(this->posX+40,this->posY+25);
     valueText.setColor(sf::Color::White);

}
Node::~Node()
{

}

void Node::setFont(std::string name)
{
    font.loadFromFile(name);
}

void Node::drawEdges()
{
    if(this->izquierdo!=NULL)
        this->eIzquierdo->setLine(this->posX+10,this->posY+80,this->izquierdo->posX+50,this->izquierdo->posY);
    if(this->derecho!=NULL)
        this->eDerecho->setLine(this->posX+90,this->posY+80,this->derecho->posX+50,this->derecho->posY);

}

void Node::setColor (sf::Color color){
    circle.setFillColor(color);
}

void Node::setColorValue(sf::Color color){
    valueText.setColor(color);
}

void Node::setColorNode()
{
    if(this->color=="NEGRO")
        this->setColor(sf::Color::Black);
    else
        this->setColor(sf::Color::Red);
}

void Node::actualizarGrafico()
{
       circle.setPosition(this->posX,this->posY);
       valueText.setPosition(this->posX+40,this->posY+25);
       drawEdges();

}

void Node::actualizarPosXAltura()
{
    if(padre!=NULL)
        this->altura=this->padre->altura+1;
    else{
        this->altura =0;
         this->posY=10;
         this->posX=600;
    }




    if(this->altura==1)
        this->posicionX=400;
    if(this->altura==2)
        this->posicionX=200;
    if(this->altura==3)
        this->posicionX=100;
    if(this->altura==4)
        this->posicionX=100;
     if(this->altura==5)
        this->posicionX=100;

}
void Node::StayActualPosition()
{

   std::string tipoHijo = getTipoHijo();
    std::cout<<"TIPO:" <<tipoHijo;
    actualizarPosXAltura();
    if(tipoHijo.compare("derecho")==0)
    {
        if(this->posX <this->padre->posX+posicionX)
            this->posX += 2.0f;
    }

    else if(tipoHijo.compare("izquierdo")==0)
    {
        if(  this->posX < this->padre->posX-posicionX)
                this->posX += 2.0f;
        else if(this->posX >this->padre->posX-posicionX)
               this->posX -= 2.0f;
    }


    if(this->padre!=NULL)
        this->posY=this->padre->posY+100;

}
void Node::render( sf::RenderWindow *w)
{
    sf::RenderWindow *window = w;
     setColorNode();
     StayActualPosition();
     actualizarGrafico();

     window->draw(circle);
     window->draw(valueText);


        eIzquierdo->render(w);

        eDerecho->render(w);
}

std::string Node::getTipoHijo()
{
    if(this->padre!=NULL)
    {
        return this->padre->derecho ==this?"derecho":"izquierdo";
    }
    return "raiz";
}

 bool Node::estaClick(sf::RenderWindow* w)
 {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
            sf::Vector2i position = sf::Mouse::getPosition(*w);


            if(this->circle.getGlobalBounds().contains(position.x,position.y))
                return true;
    }


    return false;
 }

 void Node::removeLeftChild()
 {
     this->izquierdo= NULL;

 }

void Node::removeRightChild()
{
    this->derecho=NULL;
}


