#include "ScreenMessage.h"

ScreenMessage::ScreenMessage(std::string message,float posX, float posY)
{
     setPosX(posX);
     setPosY(posY);
     setFont("Marlboro.ttf");
     setText(message);


}

ScreenMessage::~ScreenMessage()
{
    //dtor
}

void ScreenMessage::setText(std::string message)
{
      this->Message = sf::Text(message.c_str(),font);
      this->Message.setColor(sf::Color::Black);
      this->Message.setCharacterSize(50);

}
void ScreenMessage::setFont(std::string name)
{
    font.loadFromFile(name);
}

void ScreenMessage::setPosX(float posX)
{
         this->posX = posX;
}

void ScreenMessage::setPosY(float posY)
{
    this->posY=posY;
}

 float ScreenMessage::getPosX()
 {
    return this->posX;
 }

float ScreenMessage::getPosY()
{
    return this->posY;
}
 void ScreenMessage::updateRenderPosition()
 {
     this->Message.setPosition(this->getPosX(),this->getPosY());
 }
void ScreenMessage::render(sf::RenderWindow * window)
{
    updateRenderPosition();
    window->draw(this->Message);
}
