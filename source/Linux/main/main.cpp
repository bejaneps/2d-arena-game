#include "../headers/main_header.hpp"

int main()
{	
	/* Get default screensize */
	std::pair<short, short> s {Game::screenSize()};

	try
	{
		Game game{s};
		game.run();
	}
	catch(std::exception &exception)
	{
		std::cerr << "Error: " << exception.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return 0;
}