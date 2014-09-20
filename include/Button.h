#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{
    public:
        Button(float posX, float posY,sf::Texture texture);
        float posX,posY,width,height;
        sf::Sprite sprite;
        sf::Texture texture;
        void render(sf::RenderWindow *w);
        void setWidth(float width);
        void setHeight(float height);
        virtual ~Button();
    protected:
    private:
};

#endif // BUTTON_H
