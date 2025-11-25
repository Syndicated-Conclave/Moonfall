/*

FROM THE LABS:


#include <iostream>

//usings for our level creator, game parameters and game system
using LS = LevelSystem;
using param = Parameters;
using GS = GameSystem;

//shared pointers
std::shared_ptr<Scene> Scenes::menu;
std::shared_ptr<Scene> Scenes::level;

#pragma region MENU SCENE
void MenuScene::update(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        gs::set_active_scene(Scenes::level);
    }
    Scene::update(dt);
}

void MenuScene::render() {
    Renderer::queue(&_text);
    Scene::render();
}

void MenuScene::load() {
    //TODO Add in our font here
    //_font.loadFromFile("resources/fonts/RobotoMono-Regular.ttf");
    _text.setFont(_font);
    _text.setCharacterSize(60);
    _text.setString("Moonfall level 1 Test\n Press Space to start");
}

void MenuScene::unload(){}

#pragma endregion

#pragma region LEVEL SCENE
void LevelScene::load(){
    _load_level(param::level_1);
}

void LevelScene::_load_level(const std::string &file_path){
    ls::load_level(file_path,param::tile_size);


    _player = make_entity();
    _player->set_position(ls::get_start_position());

    std::shared_ptr<ShapeComponent> shape = _player->add_component<ShapeComponent>();
    shape->set_shape<sf::RectangleShape>(sf::Vector2f(param::player_size[0],param::player_size[1]));
    shape->get_shape().setFillColor(sf::Color::Yellow);
    shape->get_shape().setOrigin(sf::Vector2f(param::player_size[0]/2.f,param::player_size[1]/2.f));
    std::shared_ptr<PlayerPhysicsComponent> cmp = _player->add_component<PlayerPhysicsComponent>(sf::Vector2f(param::player_size[0],param::player_size[1]));
        cmp->create_capsule_shape(sf::Vector2f(param::player_size[0],param::player_size[1]),
        param::player_weight,param::player_friction,param::player_restitution);

    std::vector<std::vector<sf::Vector2i>> wall_groups = ls::get_groups(ls::WALL);
    for (const std::vector<sf::Vector2i> &walls : wall_groups) {
        _walls.push_back(make_entity());
        _walls.back()->add_component<PlatformComponent>(walls);
    }

}

void LevelScene::update(const float &dt){
    Scene::update(dt);
    _entities.update(dt);
    if(ls::get_tile_at(_player->get_position()) == ls::END){
        unload();
        _load_level(param::level_2);
    }

}

void LevelScene::render(){
    ls::render(Renderer::get_window());
    Scene::render();
    _entities.render();
}

void LevelScene::unload(){
    Scene::unload();
    _player.reset();
    _walls.clear();
}
#pragma endregion

*/