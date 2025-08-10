#include "game.hpp"

/*
namespace fs = std::filesystem;

struct TextureHolder    // holds textures, along with the paths of their original images
{
    std::string imagePath;
    sf::Texture texture;
};

std::vector<TextureHolder> initTextures();      // stores all textures in a vector of texture holders
sf::Texture* getTexture(std::string path, std::vector<TextureHolder> &textureList);      // searches for and returns a pointer to a texture, or returns nullptr
                                                                                             // IMPORTANT!! always type directories in this format: "d1/d2/d3", NOT "d1\\d2\\d3\\" when using this function
*/

int main()
{
    // Init game engine
    Game game;

    while (game.running())
    {
        // Update
        game.update();

        // Render
        game.render();

    }

    // End of application
    return 0;
}

/*
std::vector<TextureHolder> initTextures()   // NOTE: some images fail to load, "Image not of any known type, or corrupt"
{
    std::vector<TextureHolder> THVector;     // vector to store all textures
    const fs::path dir_path{"..\\..\\images"};      // path to all images used for textures
    for (auto const& entry: fs::directory_iterator{dir_path})
    {
        std::string imagePath = entry.path().generic_string();    // converts path to string
        sf::Texture newTexture;
        if (!newTexture.loadFromFile(imagePath))
        {
            std::cout << imagePath << " Failed to load!" << std::endl;
            continue;
        }
        TextureHolder newTH;
        newTH.texture = newTexture;
        newTH.imagePath = imagePath;
        THVector.push_back(newTH);
    }
    return THVector;
}

sf::Texture* getTexture(std::string path, std::vector<TextureHolder> &textureList)
{
    for (int i = 0; i < textureList.size(); i++)    // searches for texture
    {
        if (textureList[i].imagePath == path)
        {
            sf::Texture* TexturePtr = &textureList[i].texture;
            return TexturePtr;
        }
    }
    std::cout << std::endl << textureList[9].imagePath << std::endl;
    std::cout << std::endl << "Texture not found" << std::endl;
    return nullptr;     // texture not found
}

*/