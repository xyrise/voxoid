/* state/controlstate.h */
#ifndef VOXOID_CONTROLSTATE_H
#define VOXOID_CONTROLSTATE_H

/* Standard Library */
#include <stdbool.h>
#include <stdint.h>

/* Libraries */
#include "raylib.h"


typedef uint8_t MouseButtons;

typedef struct ControlState {
    Vector2 touch_position;
    Vector2 mouse_position;
    MouseButtons mouse_buttons;
    int gesture;
} ControlState;

ControlState newControlState(void);

bool getMouseButtonLeft(MouseButtons const);
bool getMouseButtonRight(MouseButtons const);
bool getMouseButtonMiddle(MouseButtons const);
bool getMouseButtonSide(MouseButtons const);
bool getMouseButtonExtra(MouseButtons const);
bool getMouseButtonForward(MouseButtons const);
bool getMouseButtonBack(MouseButtons const);

void clearMouseButtons(MouseButtons *const);
void setMouseButtonLeft(MouseButtons *const, bool const);
void setMouseButtonRight(MouseButtons *const, bool const);
void setMouseButtonMiddle(MouseButtons *const, bool const);
void setMouseButtonSide(MouseButtons *const, bool const);
void setMouseButtonExtra(MouseButtons *const, bool const);
void setMouseButtonForward(MouseButtons *const, bool const);
void setMouseButtonBack(MouseButtons *const, bool const);


#endif /* VOXOID_CONTROLSTATE_H */
