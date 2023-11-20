// File Line: 34
// RVA: 0x12FEB80
void __fastcall hkRefVariant::hkRefVariant(hkRefVariant *this, void *o, hkClass *k)
{
  hkReferencedObject *v3; // rdi
  hkRefVariant *v4; // rbx

  v3 = (hkReferencedObject *)o;
  v4 = this;
  if ( o )
  {
    hkReferencedObject::addReference((hkReferencedObject *)o);
    v4->m_pntr = v3;
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
  hkReferencedObject *v2; // rdi
  hkRefVariant *v3; // rbx

  v2 = (hkReferencedObject *)v->m_object;
  v3 = this;
  if ( v->m_object )
  {
    hkReferencedObject::addReference((hkReferencedObject *)v->m_object);
    v3->m_pntr = v2;
  }
  else
  {
    this->m_pntr = 0i64;
  }
}

// File Line: 45
// RVA: 0x12FEBD0
void __fastcall hkRefVariant::set(hkRefVariant *this, void *o, hkClass *k)
{
  hkReferencedObject *v3; // rbx
  hkRefVariant *v4; // rdi

  v3 = (hkReferencedObject *)o;
  v4 = this;
  if ( o )
    hkReferencedObject::addReference((hkReferencedObject *)o);
  if ( v4->m_pntr )
    hkReferencedObject::removeReference(v4->m_pntr);
  v4->m_pntr = v3;
}

// File Line: 51
// RVA: 0x12FEC10
hkClass *__fastcall hkRefVariant::getClass(hkRefVariant *this)
{
  hkClass *result; // rax

  if ( this->m_pntr )
    result = (hkClass *)((__int64 (*)(void))hkSingleton<hkVtableClassRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  else
    result = 0i64;
  return result;
}

