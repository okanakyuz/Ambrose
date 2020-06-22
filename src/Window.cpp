#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
#endif
#include "Window.hpp"
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

Window::Window()
{

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    window = new sf::Window(sf::VideoMode(800, 600), "OpenGL",
                            sf::Style::Default, settings);
    window->setVerticalSyncEnabled(true);
    window->setActive(true);

    running = true;
    gameLoop();
}

void Window::gameLoop()
{
    while (running)
    {
        collectInputs();
    }
}

void Window::collectInputs()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            running = false;
        }
        else if (event.type == sf::Event::Resized)
        {
            glViewport(0, 0, event.size.width, event.size.height);
        }
    }
}

void Window::update()
{

}


void Window::display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    window->display();
}

Window::~Window()
{
}