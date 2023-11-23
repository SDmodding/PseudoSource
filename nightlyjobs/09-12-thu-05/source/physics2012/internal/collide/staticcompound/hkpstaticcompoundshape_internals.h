// File Line: 133
// RVA: 0xDC7460
void __fastcall hkpStaticCompoundShape_Internals::AabbCastQuery::AabbCastCollectorWrapper::addHit(
        hkpStaticCompoundShape_Internals::AabbCastQuery::AabbCastCollectorWrapper *this,
        unsigned int key)
{
  hkpStaticCompoundShape_Internals *m_compound; // r9
  unsigned int m_instanceFlags; // eax
  hkpStaticCompoundShape::Instance *m_instance; // r8
  unsigned int v6; // edi
  char v7; // cl
  int v8; // edx
  int v9; // ecx
  bool v10; // zf
  bool v11; // al

  m_compound = this->m_compound;
  m_instanceFlags = this->m_instanceFlags;
  m_instance = this->m_instance;
  v6 = key | (this->m_instanceId << m_compound->m_numBitsForChildShapeKey);
  if ( (m_instanceFlags & 0x10) == 0 )
  {
    if ( key >= 0x25 )
    {
      if ( (m_instanceFlags & 0x40) != 0 )
      {
        v11 = hkpShapeKeyTable::exists(&m_compound->m_disabledLargeShapeKeyTable, v6);
        v9 = 0;
        v10 = !v11;
        goto LABEL_10;
      }
    }
    else if ( (m_instanceFlags & 0x20) != 0 )
    {
      if ( key >= 0xD )
      {
        m_instance = (hkpStaticCompoundShape::Instance *)((char *)m_instance + 32);
        v7 = key - 13;
      }
      else
      {
        v7 = key + 11;
      }
      v8 = 1 << v7;
      v9 = 0;
      v10 = (v8 & m_instance->m_transform.m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) == 0;
LABEL_10:
      LOBYTE(v9) = v10;
      if ( !v9 )
        return;
    }
    ((void (__fastcall *)(hkpAabbCastCollector *, _QWORD, hkpStaticCompoundShape::Instance *))this->m_collector->vfptr->addHit)(
      this->m_collector,
      v6,
      m_instance);
    this->m_earlyOutFraction = this->m_collector->m_earlyOutFraction;
  }
}

