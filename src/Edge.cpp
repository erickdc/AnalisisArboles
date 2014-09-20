#include "Edge.h"

Edge::Edge(float posXI,float posYI,float posXF,float posYF )
{
    line[0]=sf::Vertex(sf::Vector2f(posXI, posYI));
    line[1]=sf::Vertex(sf::Vector2f(posXF,posYF));

    line[0].color=sf::Color::Black;
    line[1].color=sf::Color::Black;
}


Edge::~Edge()
{

}

void Edge::setLine(float posXI,float posYI,float posXF,float posYF)
{
    line[0]=sf::Vertex(sf::Vector2f(posXI, posYI));
    line[1]=sf::Vertex(sf::Vector2f(posXF,posYF));
     line[0].color=sf::Color::Black;
    line[1].color=sf::Color::Black;

}
void Edge::render( sf::RenderWindow *w)
  {
    sf::RenderWindow *window = w;

     window->draw(line,2,sf::Lines);
  }
