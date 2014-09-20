#ifndef SCREENMESSAGE_H
#define SCREENMESSAGE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

class ScreenMessage
{
    public:
        ScreenMessage(std::string message,float posX, float posY);
        sf::Font font;
        sf::Text Message;


        void setText(std::string message);
        void setFont(std::string name);
        void updateRenderPosition();
        void setPosX(float posX);
        void setPosY(float posY);
        float getPosX();
        float getPosY();

        void render(sf::RenderWindow * window);

        virtual ~ScreenMessage();
    protected:
    private:
        float posX;
        float posY;
};

#endif // SCREENMESSAGE_H
