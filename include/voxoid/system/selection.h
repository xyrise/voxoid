/* system/selection.h */
#ifndef VOXOID_SYSTEM_SELECTION_H
#define VOXOID_SYSTEM_SELECTION_H

/* Local States */
#include "state/controlstate.h"
#include "state/gamestate.h"
#include "state/renderstate.h"


void updateSelection(
    RenderState *const,
    GameState const *const,
    ControlState const *const
);


#endif /* VOXOID_SYSTEM_SELECTION_H */
