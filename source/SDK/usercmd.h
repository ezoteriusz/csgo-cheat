#pragma once
#include <cstdint>
#include "valve/CVector.h"

enum move_type {
    movetype_none = 0,
    movetype_isometric,
    movetype_walk,
    movetype_step,
    movetype_fly,
    movetype_flygravity,
    movetype_vphysics,
    movetype_push,
    movetype_noclip,
    movetype_ladder,
    movetype_observer,
    movetype_custom,
    movetype_last = movetype_custom,
    movetype_max_bits = 4,
    max_movetype
};

enum entity_flags {
    fl_onground = (1 << 0),
    fl_ducking = (1 << 1),
    fl_waterjump = (1 << 2),
    fl_ontrain = (1 << 3),
    fl_inrain = (1 << 4),
    fl_frozen = (1 << 5),
    fl_atcontrols = (1 << 6),
    fl_client = (1 << 7),
    fl_fakeclient = (1 << 8),
    fl_inwater = (1 << 9),
    fl_fly = (1 << 10),
    fl_swim = (1 << 11),
    fl_conveyor = (1 << 12),
    fl_npc = (1 << 13),
    fl_godmode = (1 << 14),
    fl_notarget = (1 << 15),
    fl_aimtarget = (1 << 16),
    fl_partialground = (1 << 17),
    fl_staticprop = (1 << 18),
    fl_graphed = (1 << 19),
    fl_grenade = (1 << 20),
    fl_stepmovement = (1 << 21),
    fl_donttouch = (1 << 22),
    fl_basevelocity = (1 << 23),
    fl_worldbrush = (1 << 24),
    fl_object = (1 << 25),
    fl_killme = (1 << 26),
    fl_onfire = (1 << 27),
    fl_dissolving = (1 << 28),
    fl_transragdoll = (1 << 29),
    fl_unblockable_by_player = (1 << 30)
};

enum CommandButtons : int
{
    IN_ATTACK = (1 << 0),
    IN_JUMP = (1 << 1),
    IN_DUCK = (1 << 2),
    IN_FORWARD = (1 << 3),
    IN_BACK = (1 << 4),
    IN_USE = (1 << 5),
    IN_CANCEL = (1 << 6),
    IN_LEFT = (1 << 7),
    IN_RIGHT = (1 << 8),
    IN_MOVELEFT = (1 << 9),
    IN_MOVERIGHT = (1 << 10),
    IN_SECOND_ATTACK = (1 << 11),
    IN_RUN = (1 << 12),
    IN_RELOAD = (1 << 13),
    IN_LEFT_ALT = (1 << 14),
    IN_RIGHT_ALT = (1 << 15),
    IN_SCORE = (1 << 16),
    IN_SPEED = (1 << 17),
    IN_WALK = (1 << 18),
    IN_ZOOM = (1 << 19),
    IN_FIRST_WEAPON = (1 << 20),
    IN_SECOND_WEAPON = (1 << 21),
    IN_BULLRUSH = (1 << 22),
    IN_FIRST_GRENADE = (1 << 23),
    IN_SECOND_GRENADE = (1 << 24),
    IN_MIDDLE_ATTACK = (1 << 25)
};
class CUserCmd
{
public:
    void* vmt;
    std::int32_t commandNumber;
    std::int32_t tickCount;
    CVector viewAngles;
    CVector aimDirection;
    float forwardMove;
    float sideMove;
    float upMove;
    std::int32_t buttons;
    char impulse;
    std::int32_t weaponSelect;
    std::int32_t weaponSubType;
    std::int32_t randomSeed;
    short mouseDeltaX;
    short mouseDeltaY;
    bool hasBeenPredicted;
    CVector headAngles;
    CVector headOffset;
};
