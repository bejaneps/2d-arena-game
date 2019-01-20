#include "../headers/header.hpp"

int main()
{   
    std::pair<short, short> s = screen_size();
    
    sf::RenderWindow window(sf::VideoMode(s.first, s.second), "Arena Game", sf::Style::Default);

    /* Application will run at the same frequency as the monitor's refresh rate */
    window.setVerticalSyncEnabled(true);

    std::thread *tt = new(std::nothrow) std::thread[4];
    if(tt == nullptr)
    {
        std::cerr << "threads bad alloc" << std::endl;
        window.close();
    }
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

    }

    return 0;
}