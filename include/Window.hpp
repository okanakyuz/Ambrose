#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <SFML/Window.hpp>

class Window
{
private:

    sf::Window* window;
    bool running;
    void gameLoop();
public:
    Window();

   
    virtual void collectInputs();
    virtual void update();
    virtual void display();

    ~Window();
};





#endif // __WINDOW_H__