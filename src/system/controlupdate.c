/* system/controlupdate.c */
#include "system/controlupdate.h"

/* Standard Library */
#include <stdbool.h>

/* Libraries */
#include "raylib.h"


void updateControlState(ControlState *const cs) {
    cs->mouse_position = GetMousePosition();
    clearMouseButtons(&cs->mouse_buttons);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
      setMouseButtonLeft(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
      setMouseButtonRight(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
      setMouseButtonMiddle(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE))
      setMouseButtonSide(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA))
      setMouseButtonExtra(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD))
      setMouseButtonForward(&cs->mouse_buttons, true);
    if (IsMouseButtonPressed(MOUSE_BUTTON_BACK))
      setMouseButtonBack(&cs->mouse_buttons, true);
    cs->touch_position = GetTouchPosition(0);
    cs->gesture = GetGestureDetected();
}
