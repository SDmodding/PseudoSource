// File Line: 17
// RVA: 0xD7A360
void __fastcall hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(hkpSimpleBreakableMaterial *this, float strength)
{
  this->m_strength = strength;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleBreakableMaterial::`vftable;
  this->m_typeAndFlags = 17;
  this->m_properties = 0i64;
}

// File Line: 23
// RVA: 0xD7A3F0
hkClass *__fastcall hkpSimpleBreakableMaterial::getClassType(hkpSimpleBreakableMaterial *this)
{
  return &hkpSimpleBreakableMaterialClass;
}

// File Line: 32
// RVA: 0xD7A390
void __fastcall hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(hkpSimpleBreakableMaterial *this, hkFinishLoadedObjectFlag flag)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleBreakableMaterial::`vftable;
  if ( flag.m_finishing )
    this->m_typeAndFlags = 17;
}

// File Line: 44
// RVA: 0xD7A3B0
void __fastcall hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(hkpSimpleBreakableMaterial *this, hkpSimpleBreakableMaterial *other)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBreakableMaterial::`vftable;
  this->m_strength = other->m_strength;
  this->m_typeAndFlags = other->m_typeAndFlags;
  this->m_properties = other->m_properties;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSimpleBreakableMaterial::`vftable;
}

// File Line: 50
// RVA: 0xD7A400
void __fastcall hkpSimpleBreakableMaterial::duplicate(hkpSimpleBreakableMaterial *this)
{
  hkpSimpleBreakableMaterial *v1; // rbx
  _QWORD **v2; // rax
  hkpSimpleBreakableMaterial *v3; // rax

  v1 = this;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpSimpleBreakableMaterial *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                       v2[11],
                                       32i64);
  if ( v3 )
    hkpSimpleBreakableMaterial::hkpSimpleBreakableMaterial(v3, v1);
}

// File Line: 58
// RVA: 0xD7A450
void __fastcall hkpSimpleBreakableMaterial::setDefaultMapping(hkpSimpleBreakableMaterial *this)
{
  this->m_typeAndFlags &= 0xFFFFFF1F;
  this->m_typeAndFlags |= 0x10u;
}

// File Line: 66
// RVA: 0xD7A470
hkpSimpleBreakableMaterial *__fastcall hkpSimpleBreakableMaterial::getShapeKeyMaterial(hkpSimpleBreakableMaterial *this, hkcdShape *shapePpu, unsigned int shapeKey)
{
  return this;
}

