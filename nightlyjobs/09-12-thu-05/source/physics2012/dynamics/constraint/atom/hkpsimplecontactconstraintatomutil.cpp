// File Line: 16
// RVA: 0xD97920
signed __int64 __fastcall atomSizeRoundUp(int size)
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
    size = 0x2000;
  return (unsigned int)size;
}

// File Line: 55
// RVA: 0xD97720
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::allocateAtom(int numReservedContactPoints, int numExtraUserDatasA, int numExtraUserDatasB, int maxNumContactPoints)
{
  unsigned __int16 v4; // bp
  unsigned __int16 v5; // r13
  char v6; // r12
  char v7; // r15
  unsigned int v8; // er14
  unsigned int v9; // esi
  __int64 *v10; // rbx
  __int64 v11; // rdi
  unsigned int v12; // eax
  hkpSimpleContactConstraintAtom *result; // rax

  v4 = numReservedContactPoints;
  v5 = maxNumContactPoints;
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
  result->m_maxNumContactPoints = v5;
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
void __fastcall hkpSimpleContactConstraintAtomUtil::copyContents(hkpSimpleContactConstraintAtom *dst, hkpSimpleContactConstraintAtom *src)
{
  unsigned __int16 *v2; // r15
  signed int v3; // er11
  hkpSimpleContactConstraintAtom *v4; // rbx
  char *v5; // rdi
  char *v6; // r10
  signed int v7; // esi
  hkpSimpleContactConstraintAtom *v8; // r9
  signed __int64 v9; // rbp
  __int64 v10; // r14
  __int128 v11; // xmm0
  int *v12; // rcx
  __int64 v13; // rdx
  int v14; // eax

  v2 = &src->m_numContactPoints;
  dst->m_info.m_flags = src->m_info.m_flags;
  dst->m_info.m_biNormalAxis = src->m_info.m_biNormalAxis;
  v3 = 0;
  dst->m_info.m_rollingFrictionMultiplier.m_value = src->m_info.m_rollingFrictionMultiplier.m_value;
  dst->m_info.m_internalData1.m_value = src->m_info.m_internalData1.m_value;
  v4 = src + 1;
  dst->m_info.m_rhsRolling[0].m_value = src->m_info.m_rhsRolling[0].m_value;
  dst->m_info.m_rhsRolling[1].m_value = src->m_info.m_rhsRolling[1].m_value;
  dst->m_info.m_contactRadius = src->m_info.m_contactRadius;
  dst->m_info.m_data[0] = src->m_info.m_data[0];
  dst->m_info.m_data[1] = src->m_info.m_data[1];
  dst->m_info.m_data[2] = src->m_info.m_data[2];
  dst->m_info.m_data[3] = src->m_info.m_data[3];
  dst->m_numContactPoints = src->m_numContactPoints;
  v5 = (char *)&dst[1] + 32 * dst->m_numReservedContactPoints;
  v6 = (char *)&src[1] + 32 * src->m_numReservedContactPoints;
  if ( src->m_numContactPoints > 0u )
  {
    v7 = (signed int)(unsigned __int8)src->m_contactPointPropertiesStriding >> 2;
    v8 = dst + 1;
    v9 = (char *)src - (char *)dst;
    v10 = (unsigned __int8)src->m_contactPointPropertiesStriding;
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
          v14 = *v12;
          ++v12;
          *(int *)((char *)v12 + v5 - v6 - 4) = v14;
          --v13;
        }
        while ( v13 );
      }
      ++v3;
      v5 += v10;
      v6 += v10;
    }
    while ( v3 < *v2 );
  }
}

// File Line: 157
// RVA: 0xD97570
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::expandOne(hkpSimpleContactConstraintAtom *oldAtom_mightGetDeallocated, hkPadSpu<bool> *atomReallocated)
{
  signed int v2; // ebp
  hkpSimpleContactConstraintAtom *v3; // r14
  hkPadSpu<bool> *v4; // r15
  hkpSimpleContactConstraintAtom *v5; // rsi
  int v6; // er9
  int v7; // er8
  int v8; // edx
  signed int v9; // eax
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ebx
  __int64 v13; // rcx
  int v14; // edx
  int v15; // ecx
  _DWORD *v16; // rdi
  int v17; // edx
  __int64 i; // rcx

  v2 = oldAtom_mightGetDeallocated->m_numContactPoints;
  v3 = oldAtom_mightGetDeallocated;
  v4 = atomReallocated;
  v5 = oldAtom_mightGetDeallocated;
  if ( v2 >= oldAtom_mightGetDeallocated->m_numReservedContactPoints )
  {
    v6 = oldAtom_mightGetDeallocated->m_maxNumContactPoints;
    v7 = (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyB;
    v8 = (unsigned __int8)oldAtom_mightGetDeallocated->m_numUserDatasForBodyA;
    v9 = 2;
    v10 = oldAtom_mightGetDeallocated->m_maxNumContactPoints;
    if ( v2 > 2 )
      v9 = v2;
    v11 = 2 * v9;
    if ( v11 < v6 )
      v10 = v11;
    v3 = hkpSimpleContactConstraintAtomUtil::allocateAtom(v10, v8, v7, v6);
    hkpSimpleContactConstraintAtomUtil::copyContents(v3, v5);
    v12 = atomSizeRoundUp(v5->m_sizeOfAllAtoms);
    v13 = *((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
    (*(void (__fastcall **)(__int64, hkpSimpleContactConstraintAtom *, _QWORD))(*(_QWORD *)v13 + 16i64))(v13, v5, v12);
    v5 = v3;
    v4->m_storage = 1;
  }
  v14 = (unsigned __int8)v5->m_contactPointPropertiesStriding;
  v15 = (unsigned __int8)v5->m_contactPointPropertiesStriding;
  v5->m_numContactPoints = v2 + 1;
  v16 = (_DWORD *)((char *)&v5[1].m_type.m_storage + 32 * v5->m_numReservedContactPoints + (signed __int16)v2 * v15);
  v17 = (v14 >> 2) - 1;
  if ( v17 >= 0 )
  {
    for ( i = (unsigned int)(v17 + 1); i; --i )
    {
      *v16 = 0;
      ++v16;
    }
  }
  return v3;
}

// File Line: 205
// RVA: 0xD97670
hkpSimpleContactConstraintAtom *__fastcall hkpSimpleContactConstraintAtomUtil::optimizeCapacity(hkpSimpleContactConstraintAtom *oldAtom_mightGetDeallocated, int numFreeElemsLeft, hkPadSpu<bool> *atomReallocated)
{
  hkpSimpleContactConstraintAtom *v3; // rsi
  int v4; // ecx
  hkPadSpu<bool> *v5; // r14
  hkpSimpleContactConstraintAtom *v6; // rdi
  unsigned int v7; // ebx
  _QWORD **v8; // rax
  hkpSimpleContactConstraintAtom *result; // rax

  v3 = oldAtom_mightGetDeallocated;
  v4 = oldAtom_mightGetDeallocated->m_numReservedContactPoints;
  v5 = atomReallocated;
  if ( 2 * (numFreeElemsLeft + v3->m_numContactPoints) > v4 )
    return v3;
  v6 = hkpSimpleContactConstraintAtomUtil::allocateAtom(
         (unsigned int)v4 >> 1,
         (unsigned __int8)v3->m_numUserDatasForBodyA,
         (unsigned __int8)v3->m_numUserDatasForBodyB,
         v3->m_maxNumContactPoints);
  hkpSimpleContactConstraintAtomUtil::copyContents(v6, v3);
  v7 = atomSizeRoundUp(v3->m_sizeOfAllAtoms);
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpSimpleContactConstraintAtom *, _QWORD))(*v8[11] + 16i64))(v8[11], v3, v7);
  result = v6;
  v5->m_storage = 1;
  return result;
}

