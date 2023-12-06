#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:
    Car(float startX, float startY, float startSpeed);
    void draw();
    void update();
    void setSpeed(float newSpeed);

private:
    float x, y;
    float speed;
};

#endif // CAR_H
