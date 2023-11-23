// File Line: 20
// RVA: 0xCF0A10
__int64 __fastcall getMoppInstruction(unsigned __int8 removeInfo)
{
  return removeInfo;
}

// File Line: 25
// RVA: 0xCF0A20
__int64 __fastcall getMoppOffset(const unsigned int removeInfo)
{
  return removeInfo >> 8;
}

// File Line: 30
// RVA: 0xCF0A30
void __fastcall setMoppInstruction(unsigned int *removeInfo, unsigned __int8 instruction)
{
  *(_BYTE *)removeInfo = 0;
  *removeInfo |= instruction;
}

// File Line: 36
// RVA: 0xCF0A40
void __fastcall setMoppOffset(unsigned int *removeInfo, const unsigned int offset)
{
  *removeInfo = (unsigned __int8)*removeInfo;
  *removeInfo |= offset << 8;
}

// File Line: 43
// RVA: 0xCF05A0
void __fastcall hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
        hkpRemoveTerminalsMoppModifier *this,
        hkpMoppCode *moppCode,
        hkpShapeContainer *shapeContainer,
        hkArray<unsigned int,hkContainerHeapAllocator> *shapesToRemove)
{
  int v8; // esi
  hkpShape *v9; // rax
  __int64 v10; // r14
  hkpShape *v11; // rax
  hkAabb aabb; // [rsp+20h] [rbp-258h] BYREF
  __m128 v13[2]; // [rsp+40h] [rbp-238h] BYREF
  char v14[512]; // [rsp+60h] [rbp-218h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkReferencedObject};
  this->hkpMoppModifier::vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkpMoppModifier};
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_removeInfo.m_capacityAndFlags = 0x80000000;
  v8 = 1;
  if ( shapesToRemove->m_size )
  {
    v9 = shapeContainer->vfptr->getChildShape(shapeContainer, *shapesToRemove->m_data, v14);
    ((void (__fastcall *)(hkpShape *, hkVector4f *, hkBaseObjectVtbl *, hkAabb *))v9->vfptr[2].__vecDelDtor)(
      v9,
      &transform,
      v9->vfptr,
      &aabb);
    if ( shapesToRemove->m_size > 1 )
    {
      v10 = 1i64;
      do
      {
        v11 = shapeContainer->vfptr->getChildShape(shapeContainer, shapesToRemove->m_data[v10], v14);
        ((void (__fastcall *)(hkpShape *, hkVector4f *, hkBaseObjectVtbl *, __m128 *))v11->vfptr[2].__vecDelDtor)(
          v11,
          &transform,
          v11->vfptr,
          v13);
        ++v8;
        ++v10;
        aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v13[0]);
        aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v13[1]);
      }
      while ( v8 < shapesToRemove->m_size );
    }
    this->m_tempShapesToRemove = shapesToRemove;
    hkMoppModifyVirtualMachine_queryAabb(moppCode, &aabb, &this->hkpMoppModifier);
    this->m_tempShapesToRemove = 0i64;
  }
}

// File Line: 81
// RVA: 0xCF0700
void __fastcall hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
        hkpRemoveTerminalsMoppModifier *this,
        hkpMoppCode *moppCode,
        hkAabb *aabb,
        hkArray<unsigned int,hkContainerHeapAllocator> *shapesToRemove)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkReferencedObject};
  this->hkpMoppModifier::vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkpMoppModifier};
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_removeInfo.m_capacityAndFlags = 0x80000000;
  this->m_tempShapesToRemove = shapesToRemove;
  hkMoppModifyVirtualMachine_queryAabb(moppCode, aabb, &this->hkpMoppModifier);
  this->m_tempShapesToRemove = 0i64;
}

// File Line: 88
// RVA: 0xCF0770
void __fastcall hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(hkpRemoveTerminalsMoppModifier *this)
{
  int m_capacityAndFlags; // r8d

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkReferencedObject};
  this->hkpMoppModifier::vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable{for `hkpMoppModifier};
  m_capacityAndFlags = this->m_removeInfo.m_capacityAndFlags;
  this->m_removeInfo.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_removeInfo.m_data,
      4 * m_capacityAndFlags);
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_capacityAndFlags = 0x80000000;
  this->hkpMoppModifier::vfptr = (hkpMoppModifierVtbl *)&hkpMoppModifier::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 93
// RVA: 0xCF07F0
void __fastcall hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(
        hkpRemoveTerminalsMoppModifier *this,
        hkpMoppCode *moppCode)
{
  int v2; // r8d
  __int64 v5; // r9
  unsigned int *v6; // rdx
  char *v7; // rcx
  int v8; // eax

  v2 = 0;
  if ( this->m_removeInfo.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      v6 = &this->m_removeInfo.m_data[v5++];
      v7 = &moppCode->m_data.m_data[(unsigned __int64)*v6 >> 8];
      v8 = (unsigned __int8)*v7;
      *(_BYTE *)v6 = 0;
      *v6 |= v8;
      *v7 = 0;
    }
    while ( v2 < this->m_removeInfo.m_size );
  }
}

// File Line: 103
// RVA: 0xCF0850
void __fastcall hkpRemoveTerminalsMoppModifier::undoRemoveTerminals(
        hkpRemoveTerminalsMoppModifier *this,
        hkpMoppCode *moppCode)
{
  int v2; // r8d
  __int64 v4; // r9
  unsigned __int64 v5; // rdx

  v2 = 0;
  if ( this->m_removeInfo.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v2;
      v5 = this->m_removeInfo.m_data[v4++];
      moppCode->m_data.m_data[v5 >> 8] = v5;
    }
    while ( v2 < this->m_removeInfo.m_size );
  }
}

// File Line: 114
// RVA: 0xCF08A0
hkBool *__fastcall hkpRemoveTerminalsMoppModifier::shouldTerminalBeRemoved(
        hkpRemoveTerminalsMoppModifier *this,
        hkBool *result,
        unsigned int id,
        const unsigned int *properties)
{
  unsigned int *m_data; // rax
  int v5; // r9d
  __int64 v6; // r10
  __int64 v7; // rcx
  _DWORD *v8; // rax

  m_data = this->m_removeInfo.m_data;
  v5 = 0;
  v6 = (int)m_data[2];
  v7 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_5:
    v5 = -1;
  }
  else
  {
    v8 = *(_DWORD **)m_data;
    while ( *v8 != id )
    {
      ++v7;
      ++v5;
      ++v8;
      if ( v7 >= v6 )
        goto LABEL_5;
    }
  }
  result->m_bool = v5 >= 0;
  return result;
}

// File Line: 121
// RVA: 0xCF08E0
void __fastcall hkpRemoveTerminalsMoppModifier::addTerminalRemoveInfo(
        hkpRemoveTerminalsMoppModifier *this,
        int relativeMoppAddress)
{
  unsigned __int16 *p_m_memSizeAndFlags; // rbx
  __int64 v4; // rdx
  _BYTE *v5; // r8

  p_m_memSizeAndFlags = &this->m_memSizeAndFlags;
  if ( LODWORD(this->hkpMoppModifier::vfptr) == (HIDWORD(this->hkpMoppModifier::vfptr) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)p_m_memSizeAndFlags, 4);
  v4 = *((int *)p_m_memSizeAndFlags + 2);
  v5 = (_BYTE *)(*(_QWORD *)p_m_memSizeAndFlags + 4 * v4);
  *((_DWORD *)p_m_memSizeAndFlags + 2) = v4 + 1;
  *v5 = 0;
  *(_DWORD *)v5 = (unsigned __int8)*(_DWORD *)v5;
  *(_DWORD *)v5 |= relativeMoppAddress << 8;
}

// File Line: 130
// RVA: 0xCF09E0
hkBool *__fastcall hkpRemoveTerminalsMoppModifier2::shouldTerminalBeRemoved(
        hkpRemoveTerminalsMoppModifier2 *this,
        hkBool *result,
        int id,
        const unsigned int *properties)
{
  result->m_bool = ((*(_DWORD *)(**(_QWORD **)&this->m_removeInfo.m_size + 4 * ((__int64)id >> 5)) >> (id & 0x1F)) & 1) == 0;
  return result;
}

// File Line: 137
// RVA: 0xCF0950
void __fastcall hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2(
        hkpRemoveTerminalsMoppModifier2 *this,
        hkpMoppCode *moppCode,
        hkBitField *enabledKeys)
{
  hkAabb aabb; // [rsp+20h] [rbp-28h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_removeInfo.m_capacityAndFlags = 0x80000000;
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_tempShapesToRemove = 0i64;
  aabb.m_max = (hkVector4f)_xmm;
  aabb.m_min = (hkVector4f)_xmm_d01502f9d01502f9d01502f9d01502f9;
  this->m_enabledKeys = enabledKeys;
  this->hkpRemoveTerminalsMoppModifier::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier2::`vftable{for `hkReferencedObject};
  this->hkpRemoveTerminalsMoppModifier::hkpMoppModifier::vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier2::`vftable{for `hkpMoppModifier};
  hkMoppModifyVirtualMachine_queryAabb(moppCode, &aabb, &this->hkpMoppModifier);
  this->m_enabledKeys = 0i64;
}

