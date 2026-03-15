#pragma once
#include "Enemy.hpp"

class DyEnemy : public Enemy {
    private: 
        float angle = 135;
        float aimAngle = 225;
        bool loop = false;
        Rectangle spriteRec = Rectangle{2, 128, 13, 14};

    public: DyEnemy(float x, float y) : Enemy(x, y) { 
    this->cooldown = GetRandomValue(90, 300);
    this->health = 1;

    if (GetRandomValue(0, 1) == 0) {
        this->spriteRec = Rectangle{2, 128, 13, 14};
    } else {
        this->spriteRec = Rectangle{2, 147, 13, 13};
    }
}

        DyEnemy(float x, float y) : Enemy(x, y) { 
            this->cooldown = GetRandomValue(90, 300);
            this->health = 1; 
            this->points = 100;
        }

        void draw() override;
        void update(std::pair<float, float> pos, HitBox target) override;
        void attack(HitBox target) override;
};