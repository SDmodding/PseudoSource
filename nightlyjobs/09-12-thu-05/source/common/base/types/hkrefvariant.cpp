// File Line: 34
// RVA: 0x12FEB80
void __fastcall hkRefVariant::hkRefVariant(hkRefVariant *this, hkReferencedObject *o, hkClass *k)
{
  if ( o )
  {
    hkReferencedObject::addReference(o);
    this->m_pntr = o;
  }
  else
  {
    this->m_pntr = 0i64;
  }
}

// File Line: 40
// RVA: 0x12FEB30
void __fastcall hkRefVariant::hkRefVariant(hkRefVariant *this, hkVariant *v)
{
  hkReferencedObject *m_object; // rdi

  m_object = (hkReferencedObject *)v->m_object;
  if ( v->m_object )
  {
    hkReferencedObject::addReference((hkReferencedObject *)v->m_object);
    this->m_pntr = m_object;
  }
  else
  {
    this->m_pntr = 0i64;
  }
}

// File Line: 45
// RVA: 0x12FEBD0
void __fastcall hkRefVariant::set(hkRefVariant *this, hkReferencedObject *o, hkClass *k)
{
  if ( o )
    hkReferencedObject::addReference(o);
  if ( this->m_pntr )
    hkReferencedObject::removeReference(this->m_pntr);
  this->m_pntr = o;
}

// File Line: 51
// RVA: 0x12FEC10
hkClass *__fastcall hkRefVariant::getClass(hkRefVariant *this)
{
  if ( this->m_pntr )
    return (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *))hkSingleton<hkVtableClassRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkVtableClassRegistry>::s_instance);
  else
    return 0i64;
}

