#pragma once

class Player
{
    private:
        float thirst;
        float hunger;
        float tired;
        
    public:
        Player();
        float getThirst();
        void setThirst(float thirst);
        float getHunger();
        void setHunger(float hunger);
        float getTired();
        void setTired(float tired);
};
