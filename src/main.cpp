#include "main.h"
#include "Node.h"
#include <SFML/Graphics.hpp>
#include "Edge.h"
#include "RedBlackTree.h"
#include "Button.h"
#include "Tree23.h"
#include <iostream>

using namespace std;

 static int screenWidth= 1360;
 static int screenHeight = 768 ;

void arbolRN();
void arbol23();

int main()
{
    int opcion;

    do{
        cout << "Seleccione el tipo de arbol: (1. Rojo-Negro, 2. Dos-Tres, 3. Salir)" << endl;
        cin >> opcion;

        switch(opcion){
        case 1:
            arbolRN();
            break;
        case 2:
            arbol23();
            break;
        case 3:
            break;
        default:
            cout << "Opcion no existe" << endl;
        }
    }while(opcion != 3);

    return 0;
}

void arbolRN(){
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arboles");
    sf::Texture tInsertar;
    sf::View view;

    ScreenMessage numberEntered("Number Entered: 0",screenWidth-400,0);

    view.reset(sf::FloatRect(0,0,screenWidth,screenHeight));
    view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));

    tInsertar.loadFromFile("insertar.png");

    sf::String userInput;

    RedBlackTree tree;

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
       /* if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i position = sf::Mouse::getPosition(window);


            if(bInsertar.sprite.getGlobalBounds().contains(position.x,position.y))
                std::cout <<"Hit";
        }*/
        tree.render(&window);
        numberEntered.render(&window);
        window.display();
    }
}

void arbol23(){
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Arboles");
    sf::Texture tInsertar;
    sf::View view;

    ScreenMessage numberEntered("Number Entered: 0",screenWidth-400,0);

    view.reset(sf::FloatRect(0,0,screenWidth,screenHeight));
    view.setViewport(sf::FloatRect(0,0,1.0f,1.0f));

    tInsertar.loadFromFile("insertar.png");

    sf::String userInput;
    Tree23 arbol;

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){
           if(event.type == sf::Event::TextEntered){
                  userInput.insert(userInput.getSize(), event.text.unicode);

           }else if(event.type == sf::Event::KeyPressed){

                if(event.key.code == sf::Keyboard::BackSpace)// delete the last character
                    userInput.erase(userInput.getSize() - 1);

                if(event.key.code == sf::Keyboard::Return){
                    std::string data = userInput;
                    arbol.insertar(atoi(data.c_str()));
                    userInput.clear();
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        numberEntered.setText("Number Entered: "+ userInput);

        window.setView(view);
        window.clear(sf::Color::White);

        arbol.dibujarArbol(&window, &arbol.raiz);
        numberEntered.render(&window);
        window.display();
    }
}
