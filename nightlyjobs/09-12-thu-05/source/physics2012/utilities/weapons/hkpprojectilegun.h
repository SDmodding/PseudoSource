// File Line: 80
// RVA: 0xE19E00
void __fastcall hkpGunProjectile::onHit(hkpGunProjectile *this, hkpContactPointEvent *event)
{
  this->m_flags.m_storage |= 2u;
}

// File Line: 88
// RVA: 0xE19DF0
void __fastcall hkpGunProjectile::contactPointCallback(hkpGunProjectile *this, hkpContactPointEvent *event)
{
  (*(void (__fastcall **)(float *, hkpContactPointEvent *))(*(_QWORD *)&this[-1].m_existanceTime + 32i64))(
    &this[-1].m_existanceTime,
    event);
}

