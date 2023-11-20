// File Line: 175
// RVA: 0x4521A0
void __fastcall UFG::VehicleCollisionListener::operator delete(void *p, unsigned __int64 nbytes)
{
  void *v2; // rbx
  _QWORD **v3; // rax

  if ( p )
  {
    v2 = p;
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, void *, signed __int64))(*v3[11] + 16i64))(v3[11], v2, 48i64);
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
  return (*(_DWORD *)&this[2].mBreakOnUpdate >> 3) & 1;
}

