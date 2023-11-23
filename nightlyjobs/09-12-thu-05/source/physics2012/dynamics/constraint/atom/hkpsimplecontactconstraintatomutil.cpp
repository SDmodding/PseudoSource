// File Line: 16
// RVA: 0xD97920
__int64 __fastcall atomSizeRoundUp(int size)
{
  if ( size <= 16 )
    return 16i64;
  if ( size <= 32 )
    return 32i64;
  if ( size <= 48 )
    return 48i64;
  if ( size <= 64 )
    return 64i64;
  if ( size <= 96 )
    return 96i64;
  if ( size <= 128 )
    return 128i64;
  if ( size <= 160 )
    return 160i64;
  if ( size <= 192 )
    return 192i64;
  if ( size <= 256 )
    return 256i64;
  if ( size <= 320 )
    return 320i64;
  if ( size <= 512 )
    return 512i64;
  if ( size <= 640 )
    return 640i64;
  if ( size <= 1024 )
    return 1024i64;
  if ( size <= 2048 )
    return 2048i64;
  if ( size <= 4096 )
    return 4096i64;
  if ( size <= 0x2000 )
    return 0x2000;
  return (unsigned int)size;
}

// File Line: 55
// RVA: 0xD97720
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::allocateAtom(
        int numReservedContactPoints,
        int numExtraUserDatasA,
        int numExtraUserDatasB,
        unsigned __int16 maxNumContactPoints)
{
  unsigned __int16 v4; // bp
  char v6; // r12
  char v7; // r15
  unsigned int v8; // r14d
  unsigned int v9; // esi
  __int64 *v10; // rbx
  __int64 v11; // rdi
  unsigned int v12; // eax
  hkpSimpleContactConstraintAtom *result; // rax

  v4 = numReservedContactPoints;
  v6 = numExtraUserDatasB;
  v7 = numExtraUserDatasA;
  v8 = (4 * (numExtraUserDatasA + numExtraUserDatasB) + 35) & 0xFFFFFFFC;
  v9 = (numReservedContactPoints * (v8 + 32) + 63) & 0xFFFFFFF0;
  v10 = (__int64 *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  v11 = *v10;
  v12 = atomSizeRoundUp(v9);
  result = (hkpSimpleContactConstraintAtom *)(*(__int64 (__fastcall **)(__int64 *, _QWORD))(v11 + 8))(v10, v12);
  result->m_sizeOfAllAtoms = v9;
  result->m_numReservedContactPoints = v4;
  result->m_numUserDatasForBodyA = v7;
  result->m_numUserDatasForBodyB = v6;
  result->m_maxNumContactPoints = maxNumContactPoints;
  result->m_contactPointPropertiesStriding = v8;
  *(_DWORD *)&result->m_info.m_flags = 196608;
  result->m_info.m_contactRadius = 0.0;
  *(_DWORD *)&result->m_info.m_internalData1.m_value = 0;
  result->m_info.m_rhsRolling[1].m_value = 0;
  result->m_info.m_rollingFrictionMultiplier.m_value = 0;
  *(_QWORD *)result->m_info.m_data = 0i64;
  *(_QWORD *)&result->m_info.m_data[2] = 0i64;
  result->m_numContactPoints = 0;
  result->m_type.m_storage = 29;
  return result;
}

// File Line: 130
// RVA: 0xD977F0
void __fastcall hkpSimpleContactConstraintAtomUtil::copyContents(
        hkpSimpleContactConstraintAtom *dst,
        hkpSimpleContactConstraintAtom *src)
{
  unsigned __int16 *p_m_numContactPoints; // r15
  int v3; // r11d
  hkpSimpleContactConstraintAtom *v4; // rbx
  char *v5; // rdi
  char *v6; // r10
  int v7; // esi
  hkpSimpleContactConstraintAtom *v8; // r9
  signed __int64 v9; // rbp
  __int64 m_contactPointPropertiesStriding; // r14
  __int128 v11; // xmm0
  int *v12; // rcx
  __int64 v13; // rdx
  int v14; // eax

  p_m_numContactPoints = &src->m_numContactPoints;
  dst->m_info = src->m_info;
  v3 = 0;
  v4 = src + 1;
  dst->m_numContactPoints = src->m_numContactPoints;
  v5 = (char *)&dst[1] + 32 * dst->m_numReservedContactPoints;
  v6 = (char *)&src[1] + 32 * src->m_numReservedContactPoints;
  if ( src->m_numContactPoints )
  {
    v7 = (int)(unsigned __int8)src->m_contactPointPropertiesStriding >> 2;
    v8 = dst + 1;
    v9 = (char *)src - (char *)dst;
    m_contactPointPropertiesStriding = (unsigned __int8)src->m_contactPointPropertiesStriding;
    do
    {
      v11 = *(_OWORD *)&v4->m_type.m_storage;
      v8 = (hkpSimpleContactConstraintAtom *)((char *)v8 + 32);
      v4 = (hkpSimpleContactConstraintAtom *)((char *)v4 + 32);
      *(_OWORD *)&v8[-1].m_info.m_flags = v11;
      v12 = (int *)v6;
      *(_OWORD *)v8[-1].m_info.m_data = *(_OWORD *)((char *)v8 + v9 - 16);
      if ( v7 > 0 )
      {
        v13 = (unsigned int)v7;
        do
        {
          v14 = *v12++;
          *(int *)((char *)v12 + v5 - v6 - 4) = v14;
          --v13;
        }
        while ( v13 );
      }
      ++v3;
      v5 += m_contactPointPropertiesStriding;
      v6 += m_contactPointPropertiesStriding;
    }
    while ( v3 < *p_m_numContactPoints );
  }
}

// File Line: 157
// RVA: 0xD97570
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::expandOne(
        hkpSimpleContactConstraintAtom *oldAtom_mightGetDeallocated,
        hkPadSpu<bool> *atomReallocated)
{
  int m_numContactPoints; // ebp
  hkpSimpleContactConstraintAtom *Atom; // r14
  hkpSimpleContactConstraintAtom *v5; // rsi
  int m_maxNumContactPoints; // r9d
  int m_numUserDatasForBodyB; // r8d
  int m_numUserDatasForBodyA; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ebx
  __int64 v13; // rcx
  int m_contactPointPropertiesStriding; // edx
  _DWORD *v15; // rdi
  int v16; // edx
  __int64 i; // rcx

  m_numContactPoints = oldAtom_mightGetDeallocated->m_numContactPoints;
  Atom = oldAtom_mightGetDeallocated;
  v5 = oldAtom_mightGetDeallocated;
  if ( m_numContactPoints >= oldAtom_mightGetDeallocated->m_numReservedContactPoints )
  {
    m_maxNumContactPoints = oldAtom_mightGetDeallocated->m_maxNumContactPoints;
    m_numUserDatasForBodyB = (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyB;
    m_numUserDatasForBodyA = (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyA;
    v9 = 2;
    v10 = m_maxNumContactPoints;
    if ( m_numContactPoints > 2 )
      v9 = m_numContactPoints;
    v11 = 2 * v9;
    if ( v11 < m_maxNumContactPoints )
      v10 = v11;
    Atom = hkpSimpleContactConstraintAtomUtil::allocateAtom(
             v10,
             m_numUserDatasForBodyA,
             m_numUserDatasForBodyB,
             m_maxNumContactPoints);
    hkpSimpleContactConstraintAtomUtil::copyContents(Atom, v5);
    v12 = atomSizeRoundUp(v5->m_sizeOfAllAtoms);
    v13 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
    (*(void (__fastcall **)(__int64, hkpSimpleContactConstraintAtom *, _QWORD))(*(_QWORD *)v13 + 16i64))(v13, v5, v12);
    v5 = Atom;
    atomReallocated->m_storage = 1;
  }
  m_contactPointPropertiesStriding = (unsigned __int8)v5->m_contactPointPropertiesStriding;
  v5->m_numContactPoints = m_numContactPoints + 1;
  v15 = (_DWORD *)((char *)&v5[1].m_type.m_storage
                 + 32 * v5->m_numReservedContactPoints
                 + (__int16)m_numContactPoints * m_contactPointPropertiesStriding);
  v16 = (m_contactPointPropertiesStriding >> 2) - 1;
  if ( v16 >= 0 )
  {
    for ( i = (unsigned int)(v16 + 1); i; --i )
      *v15++ = 0;
  }
  return Atom;
}

// File Line: 205
// RVA: 0xD97670
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::optimizeCapacity(
        hkpSimpleContactConstraintAtom *oldAtom_mightGetDeallocated,
        int numFreeElemsLeft,
        hkPadSpu<bool> *atomReallocated)
{
  int m_numReservedContactPoints; // ecx
  hkpSimpleContactConstraintAtom *Atom; // rdi
  unsigned int v7; // ebx
  _QWORD **Value; // rax
  hkpSimpleContactConstraintAtom *result; // rax

  m_numReservedContactPoints = oldAtom_mightGetDeallocated->m_numReservedContactPoints;
  if ( 2 * (numFreeElemsLeft + oldAtom_mightGetDeallocated->m_numContactPoints) > m_numReservedContactPoints )
    return oldAtom_mightGetDeallocated;
  Atom = hkpSimpleContactConstraintAtomUtil::allocateAtom(
           (unsigned int)m_numReservedContactPoints >> 1,
           (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyA,
           (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyB,
           oldAtom_mightGetDeallocated->m_maxNumContactPoints);
  hkpSimpleContactConstraintAtomUtil::copyContents(Atom, oldAtom_mightGetDeallocated);
  v7 = atomSizeRoundUp(oldAtom_mightGetDeallocated->m_sizeOfAllAtoms);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpSimpleContactConstraintAtom *, _QWORD))(*Value[11] + 16i64))(
    Value[11],
    oldAtom_mightGetDeallocated,
    v7);
  result = Atom;
  atomReallocated->m_storage = 1;
  return result;
}

