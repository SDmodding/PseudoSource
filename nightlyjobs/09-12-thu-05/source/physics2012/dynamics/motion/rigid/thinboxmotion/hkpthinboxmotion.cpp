// File Line: 18
// RVA: 0xD8E240
void __fastcall hkpThinBoxMotion::hkpThinBoxMotion(
        hkpThinBoxMotion *this,
        hkVector4f *position,
        hkQuaternionf *rotation)
{
  hkpBoxMotion::hkpBoxMotion(this, position, rotation);
  this->vfptr = (hkBaseObjectVtbl *)&hkpThinBoxMotion::`vftable;
  this->m_type.m_storage = 6;
}

