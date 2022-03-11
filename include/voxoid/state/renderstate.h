/* renderstate.h */
#ifndef VOXOID_STATE_RENDERSTATE_H
#define VOXOID_STATE_RENDERSTATE_H

/* Libraries */
#include "raylib.h"


typedef struct RenderState {
    Camera camera;
    Ray ray;
    RayCollision collision;
} RenderState;


#endif /* VOXOID_STATE_RENDERSTATE_H */
