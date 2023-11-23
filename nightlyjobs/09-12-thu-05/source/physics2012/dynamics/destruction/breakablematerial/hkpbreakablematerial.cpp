// File Line: 16
// RVA: 0xD97400
void __fastcall hkpBreakableMaterial::ShapeKeyCollector::addShapeKeyBatch(
        hkpBreakableMaterial::ShapeKeyCollector *this,
        const unsigned int *shapeKeys,
        int numShapeKeys)
{
  __int64 v5; // rbx
  __int64 v6; // rsi

  if ( numShapeKeys > 0 )
  {
    v5 = 0i64;
    v6 = numShapeKeys;
    do
      this->vfptr->addShapeKey(this, shapeKeys[v5++]);
    while ( v5 < v6 );
  }
}

// File Line: 27
// RVA: 0xD97470
void __fastcall hkpBreakableMaterial::ShapeKeyCollector::addContiguousShapeKeyRange(
        hkpBreakableMaterial::ShapeKeyCollector *this,
        unsigned int baseShapeKey,
        int numShapeKeys)
{
  int i; // ebx

  if ( numShapeKeys > 0 )
  {
    for ( i = 0; i < numShapeKeys; ++i )
      this->vfptr->addShapeKey(this, baseShapeKey | i);
  }
}

// File Line: 38
// RVA: 0xD97550
void __fastcall hkpBreakableMaterial::setDefaultMapping(hkpBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF0F;
}

// File Line: 46
// RVA: 0xD974D0
void __fastcall hkpBreakableMaterial::~hkpBreakableMaterial(hkpBreakableMaterial *this)
{
  hkRefCountedProperties *m_properties; // rdi
  _QWORD **Value; // rax

  m_properties = this->m_properties;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMaterial::`vftable;
  if ( m_properties && this->m_memSizeAndFlags )
  {
    hkRefCountedProperties::~hkRefCountedProperties(m_properties);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkRefCountedProperties *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_properties,
      16i64);
  }
  this->m_properties = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

