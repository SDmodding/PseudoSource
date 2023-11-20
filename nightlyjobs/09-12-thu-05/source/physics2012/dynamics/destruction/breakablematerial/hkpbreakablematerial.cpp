// File Line: 16
// RVA: 0xD97400
void __fastcall hkpBreakableMaterial::ShapeKeyCollector::addShapeKeyBatch(hkpBreakableMaterial::ShapeKeyCollector *this, const unsigned int *shapeKeys, int numShapeKeys)
{
  const unsigned int *v3; // r14
  hkpBreakableMaterial::ShapeKeyCollector *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rsi

  if ( numShapeKeys > 0 )
  {
    v3 = shapeKeys;
    v4 = this;
    v5 = 0i64;
    v6 = numShapeKeys;
    do
      v4->vfptr->addShapeKey(v4, v3[v5++]);
    while ( v5 < v6 );
  }
}

// File Line: 27
// RVA: 0xD97470
void __fastcall hkpBreakableMaterial::ShapeKeyCollector::addContiguousShapeKeyRange(hkpBreakableMaterial::ShapeKeyCollector *this, unsigned int baseShapeKey, int numShapeKeys)
{
  int v3; // esi
  unsigned int v4; // ebp
  hkpBreakableMaterial::ShapeKeyCollector *v5; // rdi
  int v6; // ebx

  if ( numShapeKeys > 0 )
  {
    v3 = numShapeKeys;
    v4 = baseShapeKey;
    v5 = this;
    v6 = 0;
    do
      v5->vfptr->addShapeKey(v5, v4 | v6++);
    while ( v6 < v3 );
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
  hkRefCountedProperties *v1; // rdi
  hkpBreakableMaterial *v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_properties;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMaterial::`vftable;
  if ( v1 && this->m_memSizeAndFlags )
  {
    hkRefCountedProperties::~hkRefCountedProperties(v1);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkRefCountedProperties *, signed __int64))(*v3[11] + 16i64))(v3[11], v1, 16i64);
  }
  v2->m_properties = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

