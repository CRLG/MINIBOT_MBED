#ifndef CKMAR_H
#define CKMAR_H

#include "CKmarBase.h"

class CKmar : public CKmarBase
{
public:
    CKmar();

    /*virtual*/bool setAxisPosition(int axis, int pos, int speed=-1);
    /*virtual*/bool setAxisSpeed(int axis, int speed);
    /*virtual*/int getAxisCount();
    /*virtual*/bool isMoving(int axis);
    /*virtual*/int getPosition(int axis);
    /*virtual*/void arm(int axis);
    /*virtual*/void disarm(int axis);
    /*virtual*/int getTime();
    /*virtual*/void delay_ms(int delay);
    /*virtual*/void start(int mouvement);

    /*virtual*/void catchObject();
    /*virtual*/void releaseObject();
    /*virtual*/bool isObjectCatched();

    typedef enum {
        MOUVEMENT_INIT = (NO_MOUVEMENT + 1),
    }tMouvements;

    //! ATTENTION : Dans les fonctions, le numéro d'axe commence à "0"
    //! Ex : isMoving(0) interroge le 1er axe du Kmar (équivaut à isMoving(AXIS_1))
    typedef enum {
        AXIS_1 = 0,
        AXIS_2,
        AXIS_3,
        AXIS_4,
        // _______________
        AXIS_NUMBER
    }tAxisNumber;

    unsigned char m_servo_ax_id[AXIS_NUMBER];
    unsigned int m_servo_default_speed[AXIS_NUMBER];
};

#endif // CKMAR_H
