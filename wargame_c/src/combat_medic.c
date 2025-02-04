#include "combat_medic.h"

void combat_medic_heal(Unit *self, Unit *target)
{
    if (unit_get_health(target) < 0)
    {
        printf("He is gone...");
    }
    else
    {
        printf("Hang in there!");
        unit_set_health(target, unit_get_health(target) + 10);
    }
}

// The test file does not use combat_medic_heal, but uses unit_heal_target.
// Therefore we have added some code in unit.c, to make the medic unable to ressurect.

void make_combat_medic(CombatMedic *self, int health, int damage)
{
    make_soldier(&self->inherited, health, damage);
    self->inherited.inherited.vt->heal_target = combat_medic_heal;
}
