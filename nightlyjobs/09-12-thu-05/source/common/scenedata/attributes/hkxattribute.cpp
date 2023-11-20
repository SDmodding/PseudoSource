// File Line: 12
// RVA: 0xE37040
void __fastcall hkxAttribute::hkxAttribute(hkxAttribute *this)
{
  hkxAttribute *v1; // rbx

  v1 = this;
  hkStringPtr::hkStringPtr(&this->m_name);
  v1->m_value.m_pntr = 0i64;
}

// File Line: 17
// RVA: 0xE37070
void __fastcall hkxAttribute::hkxAttribute(hkxAttribute *this, hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_name, f);
}

// File Line: 21
// RVA: 0xE37090
void __fastcall hkxAttribute::setValue(hkxAttribute *this, hkReferencedObject *obj, hkClass *klass)
{
  hkRefVariant::set(&this->m_value, obj, klass);
}

