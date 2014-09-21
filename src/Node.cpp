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

    actualizarPosXAltura();
    if(tipoHijo.compare("derecho")==0)
        this->posX = this->padre->posX+posicionX;
    else if(tipoHijo.compare("izquierdo")==0)
        this->posX = this->padre->posX-posicionX;
    else{
         if(this->posX<(screenWidth/2)-Node::radius)
            this->posX+=0.9f;


         if(this->posY>50.0f)
            this->posY-=1.0f;
         else
            this->posY+=1.0f;
    }
    if(this->padre!=NULL)
        this->posY=this->padre->posY+150;

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

void Node23::dibujarNodo23(sf::RenderWindow *window, int etiquetaI, int etiquetaD){
    //Inicializa la figura
    rectangulo.setFillColor(sf::Color::Blue);
    rectangulo.setSize(sf::Vector2f(100, 100));
    rectangulo.setPosition(((screenWidth / 2)), 10);

    //Inicializa la fuente
    fuente.loadFromFile("Marlboro.ttf");

    //Inicializa el texto del nodo
    char chString[32];
    itoa(etiquetaI, chString, 10); //stdlib.h
    texto = sf::Text(chString,fuente);
    //texto = sf::Text(":",fuente);
    texto.setPosition(((screenWidth / 2)-10) + 40,10 + 25);
    texto.setColor(sf::Color::White);

    window->draw(rectangulo);
    window->draw(texto);
}

std::string Node::getTipoHijo()
{
    if(this->padre!=NULL)
    {
        if(this->padre->derecho ==this)
            return "derecho";
        else
            return "izquierdo";
    }
    return "raiz";
}


