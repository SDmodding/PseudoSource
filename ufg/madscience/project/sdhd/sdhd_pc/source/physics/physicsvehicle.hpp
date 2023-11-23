// File Line: 175
// RVA: 0x4521A0
void __fastcall UFG::VehicleCollisionListener::operator delete(void *p, unsigned __int64 nbytes)
{
  _QWORD **Value; // rax

  if ( p )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, __int64))(*Value[11] + 16i64))(Value[11], p, 48i64);
  }
}

// File Line: 281
// RVA: 0x466830
float __fastcall UFG::PhysicsVehicle::GetHalfSteeringRange(UFG::PhysicsVehicle *this)
{
  return FLOAT_0_78539819;
}

// File Line: 466
// RVA: 0x46AF40
bool __fastcall UFG::PhysicsWheeledVehicle::IsInAir(UFG::HumanDriverComponent *this)
{
  return (*(_DWORD *)&this[2].mBreakOnUpdate & 8) != 0;
}

