#include "combat_medic.hpp"

CombatMedic::CombatMedic(int health, int damage) : Soldier(health, damage)
{}

void CombatMedic::heal(Unit &target)
{
    target.set_health(target.get_health() + 10);
}