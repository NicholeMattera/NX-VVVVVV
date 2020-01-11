#pragma once

#include <string>
#include <vector>

namespace vvvvvv::levels
{
    class Tower
    {
        public:
            Tower();
            int backAt(int xP, int yP, int yOff);
            int at(int xP, int yP, int yOff);
            void loadMiniTower1();
            void loadMiniTower2();

            bool miniTowerMode;

        private:
            int miniAt(int xP, int yP, int yOff);
            void fillBackground(std::vector<std::string>& tmap);
            void fillMiniTower(std::vector<std::string>& tmap);
            void loadBackground();
            void fillContents(std::vector<std::string>& tmap);
            void loadMap();

            std::vector<int> back;
            std::vector<int> contents;
            std::vector<int> miniTower;
            std::vector<int> vmult;
    };
}
