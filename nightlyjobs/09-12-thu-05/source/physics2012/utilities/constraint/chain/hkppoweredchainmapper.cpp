// File Line: 32
// RVA: 0xE18970
hkpPoweredChainMapper *__fastcall hkpPoweredChainMapper::buildChainMapper(hkpPoweredChainMapper::Config config, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints, hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *pairs, hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *unusedConstraints)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v4; // r13
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v5; // r14
  _QWORD **v6; // rax
  __int64 v7; // rax
  signed int *v8; // r15
  __int64 v9; // rsi
  _DWORD *v10; // rdi
  int v11; // er9
  __int64 i; // rcx
  bool v13; // zf
  bool v14; // sf
  int v15; // edi
  __int64 v16; // rsi
  signed int v17; // edi
  _QWORD *v18; // r12
  int v19; // eax
  int v20; // eax
  int v21; // er9
  __int64 v22; // rcx
  int v23; // eax
  signed __int64 v24; // rdx
  __int64 v25; // rcx
  signed __int64 v26; // rdx
  _DWORD *v27; // rdi
  __int64 j; // rcx
  hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *v29; // rax
  hkResultEnum v30; // er14
  __int64 v31; // r12
  hkpPoweredChainMapper::ChainEndpoints *v32; // rax
  hkpConstraintChainInstance *v33; // r13
  int v34; // esi
  __int64 v35; // r14
  int v36; // eax
  int v37; // edx
  __int64 v38; // r12
  signed __int64 v39; // rdi
  __int64 v40; // r15
  hkpConstraintData *v41; // rax
  signed int v42; // edi
  signed int v43; // edx
  __int64 v44; // rcx
  __int64 v45; // r8
  int v46; // eax
  int v47; // eax
  int v48; // er9
  int v49; // er9
  __int64 v50; // r8
  char *v51; // rdx
  signed int *v52; // rdi
  _QWORD *v53; // rcx
  signed int v54; // esi
  __int64 v55; // r14
  __int64 v56; // rdi
  hkpConstraintInstance **v57; // r12
  hkpConstraintInstance *v58; // rax
  int v60; // er9
  int v61; // ecx
  hkReferencedObject *v62; // rcx
  int v63; // er9
  int v64; // ecx
  hkResult result; // [rsp+30h] [rbp-D0h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> constraints; // [rsp+38h] [rbp-C8h]
  char *v67; // [rsp+48h] [rbp-B8h]
  int v68; // [rsp+50h] [rbp-B0h]
  int v69; // [rsp+54h] [rbp-ACh]
  _DWORD *array; // [rsp+58h] [rbp-A8h]
  int v71; // [rsp+60h] [rbp-A0h]
  int v72; // [rsp+64h] [rbp-9Ch]
  hkArray<hkpEntity *,hkContainerHeapAllocator> entitiesOut; // [rsp+68h] [rbp-98h]
  signed int *v74; // [rsp+78h] [rbp-88h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v75; // [rsp+80h] [rbp-80h]
  hkErrStream v76; // [rsp+90h] [rbp-70h]
  __int64 v77; // [rsp+A8h] [rbp-58h]
  hkReferencedObject *v78; // [rsp+B0h] [rbp-50h]
  hkResult v79; // [rsp+B8h] [rbp-48h]
  _QWORD *v80; // [rsp+C0h] [rbp-40h]
  char buf; // [rsp+D0h] [rbp-30h]
  hkpPoweredChainMapper::Config v82; // [rsp+320h] [rbp+220h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraintsa; // [rsp+328h] [rbp+228h]
  hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *v84; // [rsp+330h] [rbp+230h]
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v85; // [rsp+338h] [rbp+238h]

  v85 = unusedConstraints;
  v84 = pairs;
  allConstraintsa = allConstraints;
  v82 = config;
  v4 = unusedConstraints;
  v5 = allConstraints;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 64i64);
  v8 = (signed int *)v7;
  v74 = (signed int *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpPoweredChainMapper::`vftable';
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 2147483648;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 2147483648;
    *(_QWORD *)(v7 + 48) = 0i64;
    *(_DWORD *)(v7 + 56) = 0;
    *(_DWORD *)(v7 + 60) = 2147483648;
  }
  else
  {
    v8 = 0i64;
    v74 = 0i64;
  }
  v9 = v5->m_size;
  v67 = 0i64;
  v68 = 0;
  v69 = 2147483648;
  v10 = 0i64;
  array = 0i64;
  v71 = 0;
  v72 = 2147483648;
  if ( (signed int)v9 > 0 )
  {
    v11 = v9;
    if ( (signed int)v9 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 4);
    v10 = array;
  }
  v71 = v9;
  if ( (signed int)(((unsigned __int64)(4 * v9) >> 2) - 1) >= 0 )
  {
    for ( i = (unsigned int)((unsigned __int64)(4 * v9) >> 2); i; --i )
    {
      *v10 = 0;
      ++v10;
    }
  }
  v13 = v5->m_size == 0;
  v14 = v5->m_size < 0;
  v75.m_elem = 0i64;
  v75.m_numElems = 0;
  v75.m_hashMod = -1;
  v15 = 0;
  if ( !v14 && !v13 )
  {
    v16 = 0i64;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v75,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v5->m_data[v16],
        v15++);
      ++v16;
    }
    while ( v15 < v5->m_size );
  }
  v17 = v5->m_size;
  v18 = v8 + 4;
  v19 = v8[7] & 0x3FFFFFFF;
  v80 = v8 + 4;
  if ( v19 < v17 )
  {
    v20 = 2 * v19;
    v21 = v17;
    if ( v17 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 4, v21, 16);
  }
  v22 = v8[6];
  v23 = v17 - v22;
  v24 = 16 * v22;
  v25 = v17 - (signed int)v22;
  v26 = *v18 + v24;
  if ( v23 > 0 )
  {
    do
    {
      if ( v26 )
      {
        *(_DWORD *)v26 = -1;
        *(_DWORD *)(v26 + 4) = 0;
        *(_QWORD *)(v26 + 8) = 0i64;
      }
      v26 += 16i64;
      --v25;
    }
    while ( v25 );
  }
  v8[6] = v17;
  if ( (signed int)(((unsigned __int64)(16i64 * v8[6]) >> 2) - 1) >= 0 )
  {
    v27 = (_DWORD *)*v18;
    for ( j = (unsigned int)((unsigned __int64)(16i64 * v8[6]) >> 2); j; --j )
    {
      *v27 = 0;
      ++v27;
    }
  }
  v29 = v84;
  v30 = 0;
  result.m_enum = 0;
  if ( v84->m_size <= 0 )
  {
LABEL_50:
    v42 = 0;
    v43 = 0;
    if ( v8[6] > 0 )
    {
      v44 = 0i64;
      v45 = 0i64;
      do
      {
        ++v43;
        ++v45;
        *(_DWORD *)(v44 + *v18) = v42;
        v44 += 16i64;
        v42 += array[v45 - 1];
        *(_DWORD *)(v44 + *v18 - 12) = 0;
      }
      while ( v43 < v8[6] );
    }
    v46 = v8[11] & 0x3FFFFFFF;
    if ( v46 < v42 )
    {
      v47 = 2 * v46;
      v48 = v42;
      if ( v42 < v47 )
        v48 = v47;
      hkArrayUtil::_reserve(
        (hkResult *)&v84,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v8 + 8,
        v48,
        16);
    }
    v8[10] = v42;
    v49 = 0;
    if ( v68 > 0 )
    {
      v50 = 0i64;
      do
      {
        v51 = v67;
        ++v49;
        v50 += 24i64;
        v52 = (signed int *)(*v18 + 16i64 * *(signed int *)&v67[v50 - 8]);
        v53 = (_QWORD *)(*((_QWORD *)v8 + 4) + 16 * (*v52 + (signed __int64)v52[1]));
        *v53 = *(_QWORD *)&v67[v50 - 24];
        v53[1] = *(_QWORD *)&v51[v50 - 16];
        ++v52[1];
      }
      while ( v49 < v68 );
    }
    if ( v4 )
    {
      v54 = 0;
      if ( v8[6] > 0 )
      {
        v55 = 0i64;
        v56 = 0i64;
        do
        {
          if ( !*(_DWORD *)(v56 + *v18 + 4) )
          {
            v57 = allConstraintsa->m_data;
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
            v58 = v57[v55];
            v18 = v8 + 4;
            v4->m_data[v4->m_size++] = v58;
          }
          ++v54;
          v56 += 16i64;
          ++v55;
        }
        while ( v54 < v8[6] );
      }
    }
    goto LABEL_68;
  }
  v31 = 0i64;
  v77 = 0i64;
  while ( 1 )
  {
    v32 = v29->m_data;
    entitiesOut.m_data = 0i64;
    entitiesOut.m_size = 0;
    entitiesOut.m_capacityAndFlags = 2147483648;
    constraints.m_data = 0i64;
    constraints.m_size = 0;
    constraints.m_capacityAndFlags = 2147483648;
    if ( hkpConstraintChainUtil::findConstraintLinkBetweenEntities(
           &v79,
           allConstraintsa,
           *(hkpEntity **)((char *)&v32->m_start + v31),
           *(hkpEntity **)((char *)&v32->m_end + v31),
           &entitiesOut,
           &constraints)->m_enum == 1 )
    {
      hkErrStream::hkErrStream(&v76, &buf, 512);
      hkOstream::operator<<(
        (hkOstream *)&v76.vfptr,
        "Cannot find a chain of constraints linking one of the entity pairs.");
      v63 = 68;
      v64 = -1413830008;
      goto LABEL_78;
    }
    v33 = hkpConstraintChainUtil::buildPoweredChain(&constraints, v82.m_cloneMotors);
    v78 = (hkReferencedObject *)&v33->vfptr;
    if ( !v33 )
    {
      hkErrStream::hkErrStream(&v76, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v76.vfptr, "Failed to build a chain.");
      v63 = 78;
      v64 = -1413816918;
LABEL_78:
      hkError::messageWarning(v64, &buf, "Constraint\\Chain\\hkpPoweredChainMapper.cpp", v63);
      hkOstream::~hkOstream((hkOstream *)&v76.vfptr);
      v62 = (hkReferencedObject *)v8;
      goto LABEL_79;
    }
    if ( v8[14] == (v8[15] & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8 + 12, 8);
    v34 = 0;
    *(_QWORD *)(*((_QWORD *)v8 + 6) + 8i64 * v8[14]++) = v33;
    if ( constraints.m_size > 0 )
      break;
LABEL_44:
    constraints.m_size = 0;
    if ( constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        constraints.m_data,
        8 * constraints.m_capacityAndFlags);
    constraints.m_data = 0i64;
    constraints.m_capacityAndFlags = 2147483648;
    entitiesOut.m_size = 0;
    if ( entitiesOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        entitiesOut.m_data,
        8 * entitiesOut.m_capacityAndFlags);
    v29 = v84;
    ++v30;
    v31 += 16i64;
    entitiesOut.m_data = 0i64;
    entitiesOut.m_capacityAndFlags = 2147483648;
    result.m_enum = v30;
    v77 = v31;
    if ( v30 >= v84->m_size )
    {
      v4 = v85;
      v18 = v8 + 4;
      goto LABEL_50;
    }
  }
  v35 = 0i64;
  while ( 1 )
  {
    v36 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              &v75,
                              (unsigned __int64)constraints.m_data[v35]);
    if ( v36 > v75.m_hashMod )
      break;
    v37 = v68;
    v38 = SLODWORD(v75.m_elem[v36].val);
    v39 = *v80 + 16 * v38;
    if ( v68 == (v69 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v67, 24);
      v37 = v68;
    }
    v33 = (hkpConstraintChainInstance *)v78;
    v68 = v37 + 1;
    v40 = (__int64)&v67[24 * v37];
    *(_DWORD *)(v40 + 16) = v38;
    ++array[v38];
    if ( ((unsigned int (*)(void))v33->m_data->vfptr[1].__first_virtual_table_function__)() != 102 )
    {
      hkErrStream::hkErrStream(&v76, &buf, 512);
      hkOstream::operator<<((hkOstream *)&v76.vfptr, "Internal error; invalid chain type.");
      v60 = 108;
      v61 = -1413833363;
      goto LABEL_74;
    }
    v41 = v33->m_data;
    *(_DWORD *)(v40 + 8) = v34;
    *(_QWORD *)v40 = v41;
    if ( v82.m_createLimitConstraints.m_bool && !*(_QWORD *)(v39 + 8) )
      *(_QWORD *)(v39 + 8) = hkpConstraintUtils::convertToLimits(constraints.m_data[v35]);
    ++v34;
    ++v35;
    if ( v34 >= constraints.m_size )
    {
      v8 = v74;
      v30 = result.m_enum;
      v31 = v77;
      goto LABEL_44;
    }
  }
  hkErrStream::hkErrStream(&v76, &buf, 512);
  hkOstream::operator<<((hkOstream *)&v76.vfptr, "Internal error.");
  v60 = 93;
  v61 = -1413834275;
LABEL_74:
  hkError::messageWarning(v61, &buf, "Constraint\\Chain\\hkpPoweredChainMapper.cpp", v60);
  hkOstream::~hkOstream((hkOstream *)&v76.vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v33->vfptr);
  v62 = (hkReferencedObject *)v74;
LABEL_79:
  hkReferencedObject::removeReference(v62);
  constraints.m_size = 0;
  if ( constraints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      constraints.m_data,
      8 * constraints.m_capacityAndFlags);
  constraints.m_data = 0i64;
  constraints.m_capacityAndFlags = 2147483648;
  entitiesOut.m_size = 0;
  if ( entitiesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      entitiesOut.m_data,
      8 * entitiesOut.m_capacityAndFlags);
  v8 = 0i64;
LABEL_68:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v75,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v75);
  v71 = 0;
  if ( v72 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v72);
  array = 0i64;
  v72 = 2147483648;
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v67,
      24 * (v69 & 0x3FFFFFFF));
  return (hkpPoweredChainMapper *)v8;
}

// File Line: 179
// RVA: 0xE18820
void __fastcall hkpPoweredChainMapper::~hkpPoweredChainMapper(hkpPoweredChainMapper *this)
{
  hkpPoweredChainMapper *v1; // rbx
  int v2; // edi
  __int64 v3; // rsi
  hkReferencedObject *v4; // rcx
  int v5; // edi
  __int64 v6; // rsi
  int v7; // er8
  int v8; // er8
  int v9; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainMapper::`vftable';
  v2 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = (hkReferencedObject *)&v1->m_links.m_data[v3].m_limitConstraint->vfptr;
      if ( v4 )
        hkReferencedObject::removeReference(v4);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_links.m_size );
  }
  v5 = 0;
  if ( v1->m_chains.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v1->m_chains.m_data[v6]->vfptr);
      ++v5;
      ++v6;
    }
    while ( v5 < v1->m_chains.m_size );
  }
  v7 = v1->m_chains.m_capacityAndFlags;
  v1->m_chains.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_chains.m_data,
      8 * v7);
  v1->m_chains.m_data = 0i64;
  v1->m_chains.m_capacityAndFlags = 2147483648;
  v8 = v1->m_targets.m_capacityAndFlags;
  v1->m_targets.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_targets.m_data,
      16 * v8);
  v1->m_targets.m_data = 0i64;
  v1->m_targets.m_capacityAndFlags = 2147483648;
  v9 = v1->m_links.m_capacityAndFlags;
  v1->m_links.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_links.m_data,
      16 * v9);
  v1->m_links.m_data = 0i64;
  v1->m_links.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 199
// RVA: 0xE19150
void __fastcall hkpPoweredChainMapper::setForceLimits(hkpPoweredChainMapper *this, int linkIndex, int coordinageIndex, float minForce, float maxForce)
{
  int v5; // er8
  float v6; // xmm1_4
  __int64 v7; // rdx
  hkpConstraintMotor *v8; // rcx
  hkArray<hkpConstraintMotor *,hkContainerHeapAllocator> motorsOut; // [rsp+20h] [rbp-28h]

  motorsOut.m_data = 0i64;
  motorsOut.m_size = 0;
  motorsOut.m_capacityAndFlags = 2147483648;
  hkpPoweredChainMapper::getMotors(this, linkIndex, coordinageIndex, &motorsOut);
  if ( motorsOut.m_size )
  {
    v5 = 0;
    v6 = 1.0 / (float)motorsOut.m_size;
    if ( motorsOut.m_size > 0 )
    {
      v7 = 0i64;
      do
      {
        ++v5;
        ++v7;
        v8 = motorsOut.m_data[v7 - 1];
        *(float *)&v8[1].vfptr = minForce * v6;
        *((float *)&v8[1].vfptr + 1) = maxForce * v6;
      }
      while ( v5 < motorsOut.m_size );
    }
  }
  motorsOut.m_size = 0;
  if ( motorsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      motorsOut.m_data,
      8 * motorsOut.m_capacityAndFlags);
}

// File Line: 222
// RVA: 0xE19220
void __fastcall hkpPoweredChainMapper::getMotors(hkpPoweredChainMapper *this, int linkIndex, int coordinateIndex, hkArray<hkpConstraintMotor *,hkContainerHeapAllocator> *motorsOut)
{
  int v4; // edi
  hkArray<hkpConstraintMotor *,hkContainerHeapAllocator> *v5; // rbx
  hkpPoweredChainMapper *v6; // r14
  hkpPoweredChainMapper::LinkInfo *v7; // rsi
  __int64 v8; // r15
  signed int *v9; // r8
  hkpConstraintMotor *v10; // rbp

  v4 = 0;
  v5 = motorsOut;
  v6 = this;
  v7 = &this->m_links.m_data[linkIndex];
  if ( v7->m_numTargets > 0 )
  {
    v8 = coordinateIndex;
    do
    {
      v9 = (signed int *)&v6->m_targets.m_data[v4 + v7->m_firstTargetIdx];
      v10 = *(hkpConstraintMotor **)(*(_QWORD *)(*(_QWORD *)v9 + 64i64) + 8 * (v8 + 12i64 * v9[2]) + 64);
      if ( v10 )
      {
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
        v5->m_data[v5->m_size++] = v10;
      }
      ++v4;
    }
    while ( v4 < v7->m_numTargets );
  }
}

// File Line: 246
// RVA: 0xE192F0
void __fastcall hkpPoweredChainMapper::setMotors(hkpPoweredChainMapper *this, int linkIndex, int coordinateIndex, hkpConstraintMotor *newMotor)
{
  int v4; // ebx
  hkpConstraintMotor *v5; // rsi
  hkpPoweredChainMapper *v6; // r12
  hkpPoweredChainMapper::LinkInfo *v7; // r14
  __int64 v8; // r15
  signed int *v9; // rdi
  __int64 v10; // rbp
  hkReferencedObject *v11; // rcx

  v4 = 0;
  v5 = newMotor;
  v6 = this;
  v7 = &this->m_links.m_data[linkIndex];
  if ( v7->m_numTargets > 0 )
  {
    v8 = coordinateIndex;
    do
    {
      v9 = (signed int *)&v6->m_targets.m_data[v4 + v7->m_firstTargetIdx];
      v10 = *(_QWORD *)v9;
      v11 = *(hkReferencedObject **)(*(_QWORD *)(*(_QWORD *)v9 + 64i64) + 8 * (v8 + 12i64 * v9[2]) + 64);
      if ( v11 )
        hkReferencedObject::removeReference(v11);
      *(_QWORD *)(*(_QWORD *)(v10 + 64) + 8 * (v8 + 12i64 * v9[2]) + 64) = v5;
      if ( v5 )
        hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
      ++v4;
    }
    while ( v4 < v7->m_numTargets );
  }
}

// File Line: 272
// RVA: 0xE193C0
void __fastcall hkpPoweredChainMapper::setTargetOrientation(hkpPoweredChainMapper *this, int linkIndex, hkQuaternionf *newTarget_aTb)
{
  int v3; // er10
  hkpPoweredChainMapper *v4; // r9
  hkpPoweredChainMapper::LinkInfo *v5; // rax
  __int64 v6; // rdx
  signed int *v7; // rdx
  __m128 v8; // xmm4
  __int64 v9; // rcx
  signed __int64 v10; // rdx
  __m128 v11; // xmm6
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm3
  __m128 v16; // xmm3

  v3 = 0;
  v4 = this;
  v5 = &this->m_links.m_data[linkIndex];
  if ( v5->m_numTargets > 0 )
  {
    do
    {
      v6 = v3++ + v5->m_firstTargetIdx;
      v7 = (signed int *)&v4->m_targets.m_data[v6];
      v8 = _mm_shuffle_ps(newTarget_aTb->m_vec.m_quad, newTarget_aTb->m_vec.m_quad, 255);
      v9 = *(_QWORD *)(*(_QWORD *)v7 + 64i64);
      v10 = 96i64 * v7[2];
      v11 = *(__m128 *)(v10 + v9 + 48);
      v12 = v11;
      v13 = _mm_shuffle_ps(v11, v11, 255);
      v14 = _mm_mul_ps(newTarget_aTb->m_vec.m_quad, v12);
      v15 = _mm_sub_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)(v10 + v9 + 48), *(__m128 *)(v10 + v9 + 48), 201),
                newTarget_aTb->m_vec.m_quad),
              _mm_mul_ps(
                _mm_shuffle_ps(newTarget_aTb->m_vec.m_quad, newTarget_aTb->m_vec.m_quad, 201),
                *(__m128 *)(v10 + v9 + 48)));
      v16 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), _mm_mul_ps(v8, v12)),
              _mm_mul_ps(v13, newTarget_aTb->m_vec.m_quad));
      *(__m128 *)(v10 + v9 + 32) = _mm_shuffle_ps(
                                     v16,
                                     _mm_unpackhi_ps(
                                       v16,
                                       _mm_sub_ps(
                                         _mm_mul_ps(v13, v8),
                                         _mm_add_ps(
                                           _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                                           _mm_shuffle_ps(v14, v14, 170)))),
                                     196);
    }
    while ( v3 < v5->m_numTargets );
  }
}

