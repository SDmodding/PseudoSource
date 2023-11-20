// File Line: 133
// RVA: 0xDC7460
void __fastcall hkpStaticCompoundShape_Internals::AabbCastQuery::AabbCastCollectorWrapper::addHit(hkpStaticCompoundShape_Internals::AabbCastQuery::AabbCastCollectorWrapper *this, unsigned int key)
{
  hkpStaticCompoundShape_Internals *v2; // r9
  hkpStaticCompoundShape_Internals::AabbCastQuery::AabbCastCollectorWrapper *v3; // rbx
  unsigned int v4; // eax
  hkpStaticCompoundShape::Instance *v5; // r8
  unsigned int v6; // edi
  char v7; // cl
  signed int v8; // edx
  int v9; // ecx
  bool v10; // zf
  bool v11; // al

  v2 = this->m_compound;
  v3 = this;
  v4 = this->m_instanceFlags;
  v5 = this->m_instance;
  v6 = key | (this->m_instanceId << v2->m_numBitsForChildShapeKey);
  if ( !(v4 & 0x10) )
  {
    if ( key >= 0x25 )
    {
      if ( v4 & 0x40 )
      {
        v11 = hkpShapeKeyTable::exists(&v2->m_disabledLargeShapeKeyTable, v6);
        v9 = 0;
        v10 = v11 == 0;
        goto LABEL_10;
      }
    }
    else if ( v4 & 0x20 )
    {
      if ( key >= 0xD )
      {
        v5 = (hkpStaticCompoundShape::Instance *)((char *)v5 + 32);
        v7 = key - 13;
      }
      else
      {
        v7 = key + 11;
      }
      v8 = 1 << v7;
      v9 = 0;
      v10 = (v8 & v5->m_transform.m_translation.m_quad.m128_i32[3] & 0xC0FFFFFF) == 0;
LABEL_10:
      LOBYTE(v9) = v10;
      if ( !v9 )
        return;
      goto LABEL_11;
    }
LABEL_11:
    ((void (__fastcall *)(hkpAabbCastCollector *, _QWORD, hkpStaticCompoundShape::Instance *))v3->m_collector->vfptr->addHit)(
      v3->m_collector,
      v6,
      v5);
    v3->m_earlyOutFraction = v3->m_collector->m_earlyOutFraction;
  }
}

