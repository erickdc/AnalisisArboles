#include "Button.h"

Button::Button(float posX, float posY,sf::Texture texture)
{
    this->posX = posX;
    this->posY = posY;
    this->texture = texture;
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(posX,posY);
    this->width= 184.0f;
    this->height= 78.0f;
}

Button::~Button()
{
    //dtor
}

 void Button::render(sf::RenderWindow *w)
 {
    w->draw(this->sprite);

 }
  void Button::setWidth(float width)
  {
      this->width= width;
  }

  void Button::setHeight(float height)
  {

      this->height = height;
  }
