//
// Created by Sebastiaan on 14/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_DATA_H
#define GBA_SPRITE_ENGINE_PROJECT_DATA_H


#include <string>

class Data
{
private:
    int amountOfDeaths;
    bool atEnd;
protected:
public:
    Data();
    void setAmountOfDeaths (int amountOfDeaths) { this->amountOfDeaths = amountOfDeaths; }
    int getAmountOfDeaths () { return amountOfDeaths; }
    std::string getAmountOfDeathsString() { return "Amount of deaths: " + std::to_string(amountOfDeaths); }
    void increaseAmountOfDeaths() { amountOfDeaths++; }

    bool getAtEnd() {return atEnd; }
    void setAtEnd(bool atEnd) { this->atEnd = atEnd; }

};


#endif //GBA_SPRITE_ENGINE_PROJECT_DATA_H
