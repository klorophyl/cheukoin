#include "Application.h"
#include "Bot.h"
#include "Team.h"
#include "Lobby.h"
#include "Player.h"

using namespace std;

Application& Application::getInstance()
{
    static Application instance;
    return instance;
}

void Application::handleClick()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*_window);
    sf::IntRect rect;

    rect = _game->getHuman()->getGlobalBounds();
    if (rect.contains(mousePosition)) {
        if (_game->getCurrentPlayer() == _game->getHuman()) {
            _game->play(true);
            return;
        }
    }
    _game->play();
}

void Application::startGame(Lobby& lobby, GameMode const& mode)
{
    _game = make_shared<Game>(lobby, mode);
    _game->startGame();
}

shared_ptr<sf::RenderWindow> Application::getWindow()
{
    return _window;
}

void Application::initWindow()
{
    _window = make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768), "Cheukoin !");
}

std::shared_ptr<Game> Application::getGame()
{
    return _game;
}