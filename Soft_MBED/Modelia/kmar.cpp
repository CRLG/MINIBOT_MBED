#include "kmar.h"
#include "CGlobale.h"
#include "ConfigSpecifiqueCoupe.h"

// PAS DE KMAR COUPE 2022
// BOUCHON UNIQUEMENT POUR COMPATIBILITE AVEC GROSBOT et SIMULIA

CKmar::CKmar()
{
}

// __________________________________________________
void CKmar::start(int mouvement)
{
    (void)mouvement;
}

// __________________________________________________
bool CKmar::setAxisPosition(int axis, int pos, int speed)
{
    if (axis >=AXIS_NUMBER) return false;
    if (speed == -1) speed = m_servo_default_speed[axis];
    Application.m_servos_ax.setPositionSpeed(m_servo_ax_id[axis], pos, speed*m_speed_factor);
    return true;
}

// __________________________________________________
bool CKmar::setAxisSpeed(int axis, int speed)
{
    if (axis >=AXIS_NUMBER) return false;
    m_servo_default_speed[axis] = speed;
    return true;
}

// __________________________________________________
int CKmar::getAxisCount()
{
   return AXIS_NUMBER;
}

// __________________________________________________
bool CKmar::isMoving(int axis)
{
    if (axis >=AXIS_NUMBER) return false;
    int index= Application.m_servos_ax.servo_id_to_index_present(m_servo_ax_id[axis]);
    return Application.m_servos_ax.m_moving[index];
}

// __________________________________________________
int CKmar::getPosition(int axis)
{
    if (axis >=AXIS_NUMBER) return -1;
    int index= Application.m_servos_ax.servo_id_to_index_present(m_servo_ax_id[axis]);
    return Application.m_servos_ax.m_positions[index];
}

// __________________________________________________
void CKmar::arm(int axis)
{
    if (axis >=AXIS_NUMBER) return ;
    Application.m_servos_ax.enableTorque(m_servo_ax_id[axis], true);
}

// __________________________________________________
void CKmar::disarm(int axis)
{
    if (axis >=AXIS_NUMBER) return;
    Application.m_servos_ax.enableTorque(m_servo_ax_id[axis], false);
}

// __________________________________________________
int CKmar::getTime()
{
    return 0; //_Global_Timer.read_ms();
}

// __________________________________________________
void CKmar::delay_ms(int delay)
{
    // TODO
}

// __________________________________________________
void CKmar::catchObject()
{
    // TODO : voir quels actionneurs activer/désactiver pour prendre l'objet
    //Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE_AV, true);
}

// __________________________________________________
void CKmar::releaseObject()
{
    // TODO : voir quels actionneurs activer/désactiver pour relâcher l'objet
    //Application.m_power_electrobot.setOutput((dsPicPowerElectrobotBase::tSwitchOutput)POMPE_AV, false);
}

// __________________________________________________
bool CKmar::isObjectCatched()
{
    // TODO : faire le lien avec le capteur de pression
    return false; // bouchon pour renvoyer quelque chose
}
