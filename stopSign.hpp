#ifndef STOP_SIGN_H
#define STOP_SIGN_H

class StopSign {
public:
    StopSign(float x, float y, float z);
    void render();

private:
    float posX, posY, posZ;
    void drawCylinder();
    void drawOctagon();
};

#endif
