#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace pokemania {
    class AssetManager {
    public:
        void LoadTexture(const std::string& name, const std::string& fileName);

        sf::Texture &GetTexture(const std::string& name);

        void LoadFont(const std::string& name, const std::string& fileName);

        sf::Font &GetFont(const std::string& name);

        void LoadSoundBuffer(const std::string& name, const std::string& fileName);

        sf::SoundBuffer &GetSoundBuffer(const std::string& name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
        std::map<std::string, sf::SoundBuffer> _sounds;
    };
}
