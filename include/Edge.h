#ifndef EDGE_H
#define EDGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Edge
{
    public:
        Edge(float posXI,float posYI,float posXF,float posYF);
        sf::Vertex line[2];
        void setLine(float posXI,float posYI,float posXF,float posYF);
        void render( sf::RenderWindow* w);
        virtual ~Edge();
    protected:
    private:
};

#endif // EDGE_H
