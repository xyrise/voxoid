/* state/controlstate.h */
#include "state/controlstate.h"


ControlState newControlState(void) {
    ControlState result = { 0 };
    return result;
}

bool getMouseButtonLeft(MouseButtons const mb) {
    return mb & 0x01u;
}

bool getMouseButtonRight(MouseButtons const mb) {
    return (mb >> 1) & 0x01u;
}

bool getMouseButtonMiddle(MouseButtons const mb) {
    return (mb >> 2) & 0x01u;
}

bool getMouseButtonSide(MouseButtons const mb) {
    return (mb >> 3) & 0x01u;
}

bool getMouseButtonExtra(MouseButtons const mb) {
    return (mb >> 4) & 0x01u;
}

bool getMouseButtonForward(MouseButtons const mb) {
    return (mb >> 5) & 0x01u;
}

bool getMouseButtonBack(MouseButtons const mb) {
    return (mb >> 6) & 0x01u;
}

void clearMouseButtons(MouseButtons *const mb) {
    *mb = 0x00u;
}

void setMouseButtonLeft(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x01u;
    else *mb &= 0xFEu;
}

void setMouseButtonRight(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x02u;
    else *mb &= 0xFDu;
}

void setMouseButtonMiddle(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x04u;
    else *mb &= 0xFBu;
}

void setMouseButtonSide(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x08u;
    else *mb &= 0xF7u;
}

void setMouseButtonExtra(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x10u;
    else *mb &= 0xEFu;
}
void setMouseButtonForward(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x20u;
    else *mb &= 0xDFu;
}

void setMouseButtonBack(MouseButtons *const mb, bool const active) {
    if (active) *mb |= 0x40u;
    else *mb &= 0xBFu;
}
