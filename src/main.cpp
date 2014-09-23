#include "main.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Edge.h"
#include "RedBlackTree.h"
#include "Button.h"

 static int screenWidth= 1360;
 static int screenHeight = 768 ;
int main()
{
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arboles");
    sf::Texture tInsertar;
    sf::View view;
    ScreenMessage numberEntered("Number Entered: 0",screenWidth-400,0);
    view.reset(sf::FloatRect(0,0,screenWidth,screenHeight));
    view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));
    tInsertar.loadFromFile("insertar.png");

    sf::String userInput;

    RedBlackTree tree;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           if(event.type == sf::Event::TextEntered)
           {
                  userInput.insert(userInput.getSize(), event.text.unicode);

           }
           else if(event.type == sf::Event::KeyPressed)
           {
               if(event.key.code == sf::Keyboard::BackSpace) // delete the last character
               {
                    userInput.erase(userInput.getSize() - 1);
                }
                if(event.key.code == sf::Keyboard::Return)
                {
                    std::string data = userInput;
                    tree.insertar(atoi(data.c_str()));
                    userInput.clear();

                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        numberEntered.setText("Number Entered: "+ userInput);
//
        window.setView(view);
        window.clear(sf::Color::White);

        tree.render(&window);
        tree.deleteTreeNode(&window);
        numberEntered.render(&window);
        window.display();
    }

    return 0;
}
