//
// Created by Sebastiaan on 14/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_DATA_H
#define GBA_SPRITE_ENGINE_PROJECT_DATA_H


class Data
{
private:
    int amountOfDeaths;
protected:
public:
    Data();
    void setAmountOfDeaths (int amountOfDeaths) { this->amountOfDeaths = amountOfDeaths; }
    int getAmountOfDeaths () { return amountOfDeaths; }
    void increaseAmountOfDeaths() { amountOfDeaths++; }

};


#endif //GBA_SPRITE_ENGINE_PROJECT_DATA_H
