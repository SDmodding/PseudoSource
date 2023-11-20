// File Line: 20
// RVA: 0xCF0A10
__int64 __fastcall getMoppInstruction(const unsigned int removeInfo)
{
  return (unsigned __int8)removeInfo;
}

// File Line: 25
// RVA: 0xCF0A20
__int64 __fastcall getMoppOffset(const unsigned int removeInfo)
{
  return removeInfo >> 8;
}

// File Line: 30
// RVA: 0xCF0A30
void __fastcall setMoppInstruction(unsigned int *removeInfo, const char instruction)
{
  *(_BYTE *)removeInfo = 0;
  *removeInfo |= (unsigned __int8)instruction;
}

// File Line: 36
// RVA: 0xCF0A40
void __fastcall setMoppOffset(unsigned int *removeInfo, const unsigned int offset)
{
  *removeInfo &= 0xFFu;
  *removeInfo |= offset << 8;
}

// File Line: 43
// RVA: 0xCF05A0
void __fastcall hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(hkpRemoveTerminalsMoppModifier *this, hkpMoppCode *moppCode, hkpShapeContainer *shapeContainer, hkArray<unsigned int,hkContainerHeapAllocator> *shapesToRemove)
{
  hkArray<unsigned int,hkContainerHeapAllocator> *v4; // rdi
  hkpShapeContainer *v5; // r15
  hkpMoppCode *v6; // r12
  hkpRemoveTerminalsMoppModifier *v7; // rbx
  signed int v8; // esi
  hkpShape *v9; // rax
  signed __int64 v10; // r14
  _QWORD *v11; // rax
  hkAabb aabb; // [rsp+20h] [rbp-258h]
  __m128 v13; // [rsp+40h] [rbp-238h]
  __m128 v14; // [rsp+50h] [rbp-228h]
  char v15; // [rsp+60h] [rbp-218h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = shapesToRemove;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkReferencedObject'};
  v5 = shapeContainer;
  this->vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkpMoppModifier'};
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_removeInfo.m_capacityAndFlags = 2147483648;
  v6 = moppCode;
  v7 = this;
  v8 = 1;
  if ( shapesToRemove->m_size )
  {
    v9 = shapeContainer->vfptr->getChildShape(shapeContainer, *shapesToRemove->m_data, (char (*)[512])&v15);
    ((void (__fastcall *)(hkpShape *, hkVector4f *, hkBaseObjectVtbl *, hkAabb *))v9->vfptr[2].__vecDelDtor)(
      v9,
      &transform,
      v9->vfptr,
      &aabb);
    if ( v4->m_size > 1 )
    {
      v10 = 1i64;
      do
      {
        v11 = (_QWORD *)v5->vfptr->getChildShape(v5, v4->m_data[v10], (char (*)[512])&v15);
        (*(void (__fastcall **)(_QWORD *, hkVector4f *, _QWORD, __m128 *))(*v11 + 32i64))(v11, &transform, *v11, &v13);
        ++v8;
        ++v10;
        aabb.m_min.m_quad = _mm_min_ps(aabb.m_min.m_quad, v13);
        aabb.m_max.m_quad = _mm_max_ps(aabb.m_max.m_quad, v14);
      }
      while ( v8 < v4->m_size );
    }
    v7->m_tempShapesToRemove = v4;
    hkMoppModifyVirtualMachine_queryAabb(v6, &aabb, (hkpMoppModifier *)&v7->vfptr);
    v7->m_tempShapesToRemove = 0i64;
  }
}

// File Line: 81
// RVA: 0xCF0700
void __fastcall hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(hkpRemoveTerminalsMoppModifier *this, hkpMoppCode *moppCode, hkAabb *aabb, hkArray<unsigned int,hkContainerHeapAllocator> *shapesToRemove)
{
  hkpRemoveTerminalsMoppModifier *v4; // rbx

  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkpMoppModifier'};
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_removeInfo.m_capacityAndFlags = 2147483648;
  this->m_tempShapesToRemove = shapesToRemove;
  hkMoppModifyVirtualMachine_queryAabb(moppCode, aabb, (hkpMoppModifier *)&this->vfptr);
  v4->m_tempShapesToRemove = 0i64;
}

// File Line: 88
// RVA: 0xCF0770
void __fastcall hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier(hkpRemoveTerminalsMoppModifier *this)
{
  hkpRemoveTerminalsMoppModifier *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier::`vftable'{for `hkpMoppModifier'};
  v2 = this->m_removeInfo.m_capacityAndFlags;
  this->m_removeInfo.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_removeInfo.m_data,
      4 * v2);
  v1->m_removeInfo.m_data = 0i64;
  v1->m_removeInfo.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpMoppModifierVtbl *)&hkpMoppModifier::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 93
// RVA: 0xCF07F0
void __fastcall hkpRemoveTerminalsMoppModifier::applyRemoveTerminals(hkpRemoveTerminalsMoppModifier *this, hkpMoppCode *moppCode)
{
  int v2; // er8
  hkpMoppCode *v3; // r11
  hkpRemoveTerminalsMoppModifier *v4; // r10
  __int64 v5; // r9
  unsigned int *v6; // rdx
  char *v7; // rcx
  int v8; // eax

  v2 = 0;
  v3 = moppCode;
  v4 = this;
  if ( this->m_removeInfo.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v2;
      v6 = &v4->m_removeInfo.m_data[v5];
      ++v5;
      v7 = &v3->m_data.m_data[(unsigned __int64)*v6 >> 8];
      v8 = (unsigned __int8)*v7;
      *(_BYTE *)v6 = 0;
      *v6 |= v8;
      *v7 = 0;
    }
    while ( v2 < v4->m_removeInfo.m_size );
  }
}

// File Line: 103
// RVA: 0xCF0850
void __fastcall hkpRemoveTerminalsMoppModifier::undoRemoveTerminals(hkpRemoveTerminalsMoppModifier *this, hkpMoppCode *moppCode)
{
  int v2; // er8
  hkpMoppCode *v3; // r11
  __int64 v4; // r9
  unsigned int *v5; // rax
  unsigned __int64 v6; // rdx

  v2 = 0;
  v3 = moppCode;
  if ( this->m_removeInfo.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = this->m_removeInfo.m_data;
      ++v2;
      v6 = v5[v4];
      LOBYTE(v5) = v5[v4];
      ++v4;
      v3->m_data.m_data[v6 >> 8] = (char)v5;
    }
    while ( v2 < this->m_removeInfo.m_size );
  }
}

// File Line: 114
// RVA: 0xCF08A0
hkBool *__fastcall hkpRemoveTerminalsMoppModifier::shouldTerminalBeRemoved(hkpRemoveTerminalsMoppModifier *this, hkBool *result, unsigned int id, const unsigned int *properties)
{
  unsigned int *v4; // rax
  signed int v5; // er9
  __int64 v6; // r10
  __int64 v7; // rcx
  _DWORD *v8; // rax

  v4 = this->m_removeInfo.m_data;
  v5 = 0;
  v6 = (signed int)v4[2];
  v7 = 0i64;
  if ( v6 <= 0 )
  {
LABEL_5:
    v5 = -1;
  }
  else
  {
    v8 = *(_DWORD **)v4;
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
void __fastcall hkpRemoveTerminalsMoppModifier::addTerminalRemoveInfo(hkpRemoveTerminalsMoppModifier *this, int relativeMoppAddress)
{
  signed int *v2; // rbx
  int v3; // edi
  __int64 v4; // rdx
  _BYTE *v5; // r8

  v2 = (signed int *)&this->m_memSizeAndFlags;
  v3 = relativeMoppAddress;
  if ( LODWORD(this->vfptr) == (HIDWORD(this->vfptr) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 4);
  v4 = v2[2];
  v5 = (_BYTE *)(*(_QWORD *)v2 + 4 * v4);
  v2[2] = v4 + 1;
  *v5 = 0;
  *(_DWORD *)v5 &= 0xFFu;
  *(_DWORD *)v5 |= v3 << 8;
}

// File Line: 130
// RVA: 0xCF09E0
hkBool *__fastcall hkpRemoveTerminalsMoppModifier2::shouldTerminalBeRemoved(hkpRemoveTerminalsMoppModifier2 *this, hkBool *result, unsigned int id, const unsigned int *properties)
{
  result->m_bool = ~(unsigned __int8)(*(_DWORD *)(**(_QWORD **)&this->m_removeInfo.m_size
                                                + 4 * ((signed __int64)(signed int)id >> 5)) >> (id & 0x1F)) & 1;
  return result;
}

// File Line: 137
// RVA: 0xCF0950
void __fastcall hkpRemoveTerminalsMoppModifier2::hkpRemoveTerminalsMoppModifier2(hkpRemoveTerminalsMoppModifier2 *this, hkpMoppCode *moppCode, hkBitField *enabledKeys)
{
  hkpRemoveTerminalsMoppModifier2 *v3; // rbx
  hkAabb aabb; // [rsp+20h] [rbp-28h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_removeInfo.m_capacityAndFlags = 2147483648;
  v3 = this;
  this->m_removeInfo.m_data = 0i64;
  this->m_removeInfo.m_size = 0;
  this->m_tempShapesToRemove = 0i64;
  aabb.m_max = (hkVector4f)_xmm;
  aabb.m_min = (hkVector4f)_xmm_d01502f9d01502f9d01502f9d01502f9;
  this->m_enabledKeys = enabledKeys;
  this->vfptr = (hkBaseObjectVtbl *)&hkpRemoveTerminalsMoppModifier2::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkpMoppModifierVtbl *)&hkpRemoveTerminalsMoppModifier2::`vftable'{for `hkpMoppModifier'};
  hkMoppModifyVirtualMachine_queryAabb(moppCode, &aabb, (hkpMoppModifier *)&this->vfptr);
  v3->m_enabledKeys = 0i64;
}

