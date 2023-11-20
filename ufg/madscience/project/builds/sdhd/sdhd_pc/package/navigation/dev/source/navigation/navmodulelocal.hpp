// File Line: 33
// RVA: 0xE62F0
void __fastcall UFG::NavModuleLocal::~NavModuleLocal(UFG::NavModuleLocal *this)
{
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable';
  _((AMD_HD3D *)&this->m_adjustedWaypoint);
}

// File Line: 46
// RVA: 0xECF80
float __fastcall UFG::NavModuleLocal::GetTurningRadius(UFG::NavModuleLocal *this, float fSpeed)
{
  return fSpeed;
}

// File Line: 53
// RVA: 0xF0E60
void __fastcall UFG::NavModuleLocal::SetCollisionAvoidanceType(UFG::NavModuleLocal *this, UFG::eCollisionAvoidanceType type)
{
  this->m_avoidanceType = type;
}

// File Line: 54
// RVA: 0xECF70
__int64 __fastcall UFG::NavModuleLocal::GetCollisionAvoidanceType(UFG::NavModuleLocal *this)
{
  return (unsigned int)this->m_avoidanceType;
}

