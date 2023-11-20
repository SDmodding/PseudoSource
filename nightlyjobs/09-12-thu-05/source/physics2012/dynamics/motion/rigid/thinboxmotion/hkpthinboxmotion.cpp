// File Line: 18
// RVA: 0xD8E240
void __fastcall hkpThinBoxMotion::hkpThinBoxMotion(hkpThinBoxMotion *this, hkVector4f *position, hkQuaternionf *rotation)
{
  hkpThinBoxMotion *v3; // rbx

  v3 = this;
  hkpBoxMotion::hkpBoxMotion((hkpBoxMotion *)&this->vfptr, position, rotation);
  v3->vfptr = (hkBaseObjectVtbl *)&hkpThinBoxMotion::`vftable;
  v3->m_type.m_storage = 6;
}

