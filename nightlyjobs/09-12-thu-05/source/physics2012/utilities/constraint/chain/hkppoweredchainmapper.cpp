// File Line: 32
// RVA: 0xE18970
hkpPoweredChainMapper *__fastcall hkpPoweredChainMapper::buildChainMapper(
        hkpPoweredChainMapper::Config config,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *allConstraints,
        hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *pairs,
        hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *unusedConstraints)
{
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v4; // r13
  _QWORD **Value; // rax
  __int64 v7; // rax
  __int64 v8; // r15
  __int64 m_size; // rsi
  _DWORD *v10; // rdi
  __int64 i; // rcx
  bool v12; // cc
  int v13; // edi
  __int64 v14; // rsi
  int v15; // edi
  _QWORD *v16; // r12
  int v17; // eax
  int v18; // eax
  int v19; // r9d
  __int64 v20; // rdx
  int v21; // eax
  __int64 v22; // rcx
  __int64 v23; // rdx
  _DWORD *v24; // rdi
  __int64 j; // rcx
  hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *v26; // rax
  hkResultEnum m_enum; // r14d
  __int64 v28; // r12
  hkpPoweredChainMapper::ChainEndpoints *v29; // rax
  hkpConstraintChainInstance *v30; // r13
  int v31; // esi
  __int64 v32; // r14
  int Key; // eax
  int v34; // edx
  __int64 val_low; // r12
  __int64 v36; // rdi
  char *v37; // r15
  hkpConstraintData *v38; // rax
  int v39; // edi
  int v40; // edx
  __int64 v41; // rcx
  __int64 v42; // r8
  int v43; // eax
  int v44; // eax
  int v45; // r9d
  int v46; // r9d
  __int64 v47; // r8
  char *v48; // rdx
  int *v49; // rdi
  _QWORD *v50; // rcx
  int v51; // esi
  __int64 v52; // r14
  __int64 v53; // rdi
  hkpConstraintInstance **m_data; // r12
  hkpConstraintInstance *v55; // rax
  int v57; // r9d
  unsigned int v58; // ecx
  hkReferencedObject *v59; // rcx
  int v60; // r9d
  unsigned int v61; // ecx
  hkResult result; // [rsp+30h] [rbp-D0h] BYREF
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> constraints; // [rsp+38h] [rbp-C8h] BYREF
  char *v64; // [rsp+48h] [rbp-B8h] BYREF
  int v65; // [rsp+50h] [rbp-B0h]
  int v66; // [rsp+54h] [rbp-ACh]
  _DWORD *array; // [rsp+58h] [rbp-A8h] BYREF
  int v68; // [rsp+60h] [rbp-A0h]
  int v69; // [rsp+64h] [rbp-9Ch]
  hkArray<hkpEntity *,hkContainerHeapAllocator> entitiesOut; // [rsp+68h] [rbp-98h] BYREF
  hkReferencedObject *v71; // [rsp+78h] [rbp-88h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v72; // [rsp+80h] [rbp-80h] BYREF
  hkErrStream v73; // [rsp+90h] [rbp-70h] BYREF
  __int64 v74; // [rsp+A8h] [rbp-58h]
  hkReferencedObject *v75; // [rsp+B0h] [rbp-50h]
  hkResult v76; // [rsp+B8h] [rbp-48h] BYREF
  _QWORD *v77; // [rsp+C0h] [rbp-40h]
  char buf[576]; // [rsp+D0h] [rbp-30h] BYREF
  hkArray<hkpPoweredChainMapper::ChainEndpoints,hkContainerHeapAllocator> *v81; // [rsp+330h] [rbp+230h] BYREF
  hkArray<hkpConstraintInstance *,hkContainerHeapAllocator> *v82; // [rsp+338h] [rbp+238h]

  v82 = unusedConstraints;
  v81 = pairs;
  v4 = unusedConstraints;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  v8 = v7;
  v71 = (hkReferencedObject *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkpPoweredChainMapper::`vftable;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 0x80000000;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 0x80000000;
    *(_QWORD *)(v7 + 48) = 0i64;
    *(_DWORD *)(v7 + 56) = 0;
    *(_DWORD *)(v7 + 60) = 0x80000000;
  }
  else
  {
    v8 = 0i64;
    v71 = 0i64;
  }
  m_size = allConstraints->m_size;
  v64 = 0i64;
  v65 = 0;
  v66 = 0x80000000;
  v10 = 0i64;
  array = 0i64;
  v68 = 0;
  v69 = 0x80000000;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 4);
    v10 = array;
  }
  v68 = m_size;
  if ( (int)(((unsigned __int64)(4 * m_size) >> 2) - 1) >= 0 )
  {
    for ( i = (unsigned int)((unsigned __int64)(4 * m_size) >> 2); i; --i )
      *v10++ = 0;
  }
  v12 = allConstraints->m_size <= 0;
  v72.m_elem = 0i64;
  v72.m_numElems = 0;
  v72.m_hashMod = -1;
  v13 = 0;
  if ( !v12 )
  {
    v14 = 0i64;
    do
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v72,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)allConstraints->m_data[v14++],
        v13++);
    while ( v13 < allConstraints->m_size );
  }
  v15 = allConstraints->m_size;
  v16 = (_QWORD *)(v8 + 16);
  v17 = *(_DWORD *)(v8 + 28) & 0x3FFFFFFF;
  v77 = (_QWORD *)(v8 + 16);
  if ( v17 < v15 )
  {
    v18 = 2 * v17;
    v19 = v15;
    if ( v15 < v18 )
      v19 = v18;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v8 + 16), v19, 16);
  }
  v20 = *(int *)(v8 + 24);
  v21 = v15 - v20;
  v22 = v15 - (int)v20;
  v23 = *v16 + 16 * v20;
  if ( v21 > 0 )
  {
    do
    {
      if ( v23 )
      {
        *(_DWORD *)v23 = -1;
        *(_DWORD *)(v23 + 4) = 0;
        *(_QWORD *)(v23 + 8) = 0i64;
      }
      v23 += 16i64;
      --v22;
    }
    while ( v22 );
  }
  *(_DWORD *)(v8 + 24) = v15;
  if ( (int)(((unsigned __int64)(16i64 * *(int *)(v8 + 24)) >> 2) - 1) >= 0 )
  {
    v24 = (_DWORD *)*v16;
    for ( j = (unsigned int)((unsigned __int64)(16i64 * *(int *)(v8 + 24)) >> 2); j; --j )
      *v24++ = 0;
  }
  v26 = v81;
  m_enum = HK_SUCCESS;
  result.m_enum = HK_SUCCESS;
  if ( v81->m_size <= 0 )
  {
LABEL_48:
    v39 = 0;
    v40 = 0;
    if ( *(int *)(v8 + 24) > 0 )
    {
      v41 = 0i64;
      v42 = 0i64;
      do
      {
        ++v40;
        ++v42;
        *(_DWORD *)(v41 + *v16) = v39;
        v41 += 16i64;
        v39 += array[v42 - 1];
        *(_DWORD *)(v41 + *v16 - 12) = 0;
      }
      while ( v40 < *(_DWORD *)(v8 + 24) );
    }
    v43 = *(_DWORD *)(v8 + 44) & 0x3FFFFFFF;
    if ( v43 < v39 )
    {
      v44 = 2 * v43;
      v45 = v39;
      if ( v39 < v44 )
        v45 = v44;
      hkArrayUtil::_reserve((hkResult *)&v81, &hkContainerHeapAllocator::s_alloc, (const void **)(v8 + 32), v45, 16);
    }
    *(_DWORD *)(v8 + 40) = v39;
    v46 = 0;
    if ( v65 > 0 )
    {
      v47 = 0i64;
      do
      {
        v48 = v64;
        ++v46;
        v47 += 24i64;
        v49 = (int *)(*v16 + 16i64 * *(int *)&v64[v47 - 8]);
        v50 = (_QWORD *)(*(_QWORD *)(v8 + 32) + 16 * (*v49 + (__int64)v49[1]));
        *v50 = *(_QWORD *)&v64[v47 - 24];
        v50[1] = *(_QWORD *)&v48[v47 - 16];
        ++v49[1];
      }
      while ( v46 < v65 );
    }
    if ( v4 )
    {
      v51 = 0;
      if ( *(int *)(v8 + 24) > 0 )
      {
        v52 = 0i64;
        v53 = 0i64;
        do
        {
          if ( !*(_DWORD *)(v53 + *v16 + 4) )
          {
            m_data = allConstraints->m_data;
            if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 8);
            v55 = m_data[v52];
            v16 = (_QWORD *)(v8 + 16);
            v4->m_data[v4->m_size++] = v55;
          }
          ++v51;
          v53 += 16i64;
          ++v52;
        }
        while ( v51 < *(_DWORD *)(v8 + 24) );
      }
    }
    goto LABEL_66;
  }
  v28 = 0i64;
  v74 = 0i64;
  while ( 1 )
  {
    v29 = v26->m_data;
    entitiesOut.m_data = 0i64;
    entitiesOut.m_size = 0;
    entitiesOut.m_capacityAndFlags = 0x80000000;
    constraints.m_data = 0i64;
    constraints.m_size = 0;
    constraints.m_capacityAndFlags = 0x80000000;
    if ( hkpConstraintChainUtil::findConstraintLinkBetweenEntities(
           &v76,
           allConstraints,
           *(hkpEntity **)((char *)&v29->m_start + v28),
           *(hkpEntity **)((char *)&v29->m_end + v28),
           &entitiesOut,
           &constraints)->m_enum == HK_FAILURE )
    {
      hkErrStream::hkErrStream(&v73, buf, 512);
      hkOstream::operator<<(&v73, "Cannot find a chain of constraints linking one of the entity pairs.");
      v60 = 68;
      v61 = -1413830008;
      goto LABEL_76;
    }
    v30 = hkpConstraintChainUtil::buildPoweredChain(&constraints, config.m_cloneMotors);
    v75 = v30;
    if ( !v30 )
    {
      hkErrStream::hkErrStream(&v73, buf, 512);
      hkOstream::operator<<(&v73, "Failed to build a chain.");
      v60 = 78;
      v61 = -1413816918;
LABEL_76:
      hkError::messageWarning(v61, buf, "Constraint\\Chain\\hkpPoweredChainMapper.cpp", v60);
      hkOstream::~hkOstream(&v73);
      v59 = (hkReferencedObject *)v8;
      goto LABEL_77;
    }
    if ( *(_DWORD *)(v8 + 56) == (*(_DWORD *)(v8 + 60) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)(v8 + 48), 8);
    v31 = 0;
    *(_QWORD *)(*(_QWORD *)(v8 + 48) + 8i64 * (int)(*(_DWORD *)(v8 + 56))++) = v30;
    if ( constraints.m_size > 0 )
      break;
LABEL_42:
    constraints.m_size = 0;
    if ( constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        constraints.m_data,
        8 * constraints.m_capacityAndFlags);
    constraints.m_data = 0i64;
    constraints.m_capacityAndFlags = 0x80000000;
    entitiesOut.m_size = 0;
    if ( entitiesOut.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        entitiesOut.m_data,
        8 * entitiesOut.m_capacityAndFlags);
    v26 = v81;
    ++m_enum;
    v28 += 16i64;
    entitiesOut.m_data = 0i64;
    entitiesOut.m_capacityAndFlags = 0x80000000;
    result.m_enum = m_enum;
    v74 = v28;
    if ( m_enum >= v81->m_size )
    {
      v4 = v82;
      v16 = (_QWORD *)(v8 + 16);
      goto LABEL_48;
    }
  }
  v32 = 0i64;
  while ( 1 )
  {
    Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                          &v72,
                          (unsigned __int64)constraints.m_data[v32]);
    if ( Key > v72.m_hashMod )
      break;
    v34 = v65;
    val_low = SLODWORD(v72.m_elem[Key].val);
    v36 = *v77 + 16 * val_low;
    if ( v65 == (v66 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v64, 24);
      v34 = v65;
    }
    v30 = (hkpConstraintChainInstance *)v75;
    v65 = v34 + 1;
    v37 = &v64[24 * v34];
    *((_DWORD *)v37 + 4) = val_low;
    ++array[val_low];
    if ( ((unsigned int (__fastcall *)(hkpConstraintData *))v30->m_data->hkpConstraintInstance::vfptr[1].__first_virtual_table_function__)(v30->m_data) != 102 )
    {
      hkErrStream::hkErrStream(&v73, buf, 512);
      hkOstream::operator<<(&v73, "Internal error; invalid chain type.");
      v57 = 108;
      v58 = -1413833363;
      goto LABEL_72;
    }
    v38 = v30->m_data;
    *((_DWORD *)v37 + 2) = v31;
    *(_QWORD *)v37 = v38;
    if ( config.m_createLimitConstraints.m_bool && !*(_QWORD *)(v36 + 8) )
      *(_QWORD *)(v36 + 8) = hkpConstraintUtils::convertToLimits(constraints.m_data[v32]);
    ++v31;
    ++v32;
    if ( v31 >= constraints.m_size )
    {
      v8 = (__int64)v71;
      m_enum = result.m_enum;
      v28 = v74;
      goto LABEL_42;
    }
  }
  hkErrStream::hkErrStream(&v73, buf, 512);
  hkOstream::operator<<(&v73, "Internal error.");
  v57 = 93;
  v58 = -1413834275;
LABEL_72:
  hkError::messageWarning(v58, buf, "Constraint\\Chain\\hkpPoweredChainMapper.cpp", v57);
  hkOstream::~hkOstream(&v73);
  hkReferencedObject::removeReference(v30);
  v59 = v71;
LABEL_77:
  hkReferencedObject::removeReference(v59);
  constraints.m_size = 0;
  if ( constraints.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      constraints.m_data,
      8 * constraints.m_capacityAndFlags);
  constraints.m_data = 0i64;
  constraints.m_capacityAndFlags = 0x80000000;
  entitiesOut.m_size = 0;
  if ( entitiesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      entitiesOut.m_data,
      8 * entitiesOut.m_capacityAndFlags);
  v8 = 0i64;
LABEL_66:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v72,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v72);
  v68 = 0;
  if ( v69 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v69);
  array = 0i64;
  v69 = 0x80000000;
  v65 = 0;
  if ( v66 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v64, 24 * (v66 & 0x3FFFFFFF));
  return (hkpPoweredChainMapper *)v8;
}

// File Line: 179
// RVA: 0xE18820
void __fastcall hkpPoweredChainMapper::~hkpPoweredChainMapper(hkpPoweredChainMapper *this)
{
  int v2; // edi
  __int64 v3; // rsi
  hkpConstraintInstance *m_limitConstraint; // rcx
  int v5; // edi
  __int64 v6; // rsi
  int m_capacityAndFlags; // r8d
  int v8; // r8d
  int v9; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpPoweredChainMapper::`vftable;
  v2 = 0;
  if ( this->m_links.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_limitConstraint = this->m_links.m_data[v3].m_limitConstraint;
      if ( m_limitConstraint )
        hkReferencedObject::removeReference(m_limitConstraint);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_links.m_size );
  }
  v5 = 0;
  if ( this->m_chains.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      hkReferencedObject::removeReference(this->m_chains.m_data[v6]);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_chains.m_size );
  }
  m_capacityAndFlags = this->m_chains.m_capacityAndFlags;
  this->m_chains.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_chains.m_data,
      8 * m_capacityAndFlags);
  this->m_chains.m_data = 0i64;
  this->m_chains.m_capacityAndFlags = 0x80000000;
  v8 = this->m_targets.m_capacityAndFlags;
  this->m_targets.m_size = 0;
  if ( v8 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_targets.m_data,
      16 * v8);
  this->m_targets.m_data = 0i64;
  this->m_targets.m_capacityAndFlags = 0x80000000;
  v9 = this->m_links.m_capacityAndFlags;
  this->m_links.m_size = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_links.m_data, 16 * v9);
  this->m_links.m_data = 0i64;
  this->m_links.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 199
// RVA: 0xE19150
void __fastcall hkpPoweredChainMapper::setForceLimits(
        hkpPoweredChainMapper *this,
        int linkIndex,
        int coordinageIndex,
        float minForce,
        float maxForce)
{
  int v5; // r8d
  float v6; // xmm1_4
  __int64 v7; // rdx
  hkpConstraintMotor *v8; // rcx
  hkArray<hkpConstraintMotor *,hkContainerHeapAllocator> motorsOut; // [rsp+20h] [rbp-28h] BYREF

  motorsOut.m_data = 0i64;
  motorsOut.m_size = 0;
  motorsOut.m_capacityAndFlags = 0x80000000;
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
        v8 = motorsOut.m_data[v7++];
        *(float *)&v8[1].vfptr = minForce * v6;
        *((float *)&v8[1].vfptr + 1) = maxForce * v6;
      }
      while ( v5 < motorsOut.m_size );
    }
  }
  motorsOut.m_size = 0;
  if ( motorsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      motorsOut.m_data,
      8 * motorsOut.m_capacityAndFlags);
}

// File Line: 222
// RVA: 0xE19220
void __fastcall hkpPoweredChainMapper::getMotors(
        hkpPoweredChainMapper *this,
        int linkIndex,
        int coordinateIndex,
        hkArray<hkpConstraintMotor *,hkContainerHeapAllocator> *motorsOut)
{
  int v4; // edi
  hkpPoweredChainMapper::LinkInfo *v7; // rsi
  __int64 v8; // r15
  hkpPoweredChainMapper::Target *v9; // r8
  hkpConstraintMotor *v10; // rbp

  v4 = 0;
  v7 = &this->m_links.m_data[linkIndex];
  if ( v7->m_numTargets > 0 )
  {
    v8 = coordinateIndex;
    do
    {
      v9 = &this->m_targets.m_data[v4 + v7->m_firstTargetIdx];
      v10 = v9->m_chain->m_infos.m_data[v9->m_infoIndex].m_motors[v8];
      if ( v10 )
      {
        if ( motorsOut->m_size == (motorsOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&motorsOut->m_data, 8);
        motorsOut->m_data[motorsOut->m_size++] = v10;
      }
      ++v4;
    }
    while ( v4 < v7->m_numTargets );
  }
}

// File Line: 246
// RVA: 0xE192F0
void __fastcall hkpPoweredChainMapper::setMotors(
        hkpPoweredChainMapper *this,
        int linkIndex,
        int coordinateIndex,
        hkpConstraintMotor *newMotor)
{
  int v4; // ebx
  hkpPoweredChainMapper::LinkInfo *v7; // r14
  __int64 v8; // r15
  hkpPoweredChainMapper::Target *v9; // rdi
  hkpPoweredChainData *m_chain; // rbp
  hkReferencedObject *v11; // rcx

  v4 = 0;
  v7 = &this->m_links.m_data[linkIndex];
  if ( v7->m_numTargets > 0 )
  {
    v8 = coordinateIndex;
    do
    {
      v9 = &this->m_targets.m_data[v4 + v7->m_firstTargetIdx];
      m_chain = v9->m_chain;
      v11 = v9->m_chain->m_infos.m_data[v9->m_infoIndex].m_motors[v8];
      if ( v11 )
        hkReferencedObject::removeReference(v11);
      m_chain->m_infos.m_data[v9->m_infoIndex].m_motors[v8] = newMotor;
      if ( newMotor )
        hkReferencedObject::addReference(newMotor);
      ++v4;
    }
    while ( v4 < v7->m_numTargets );
  }
}

// File Line: 272
// RVA: 0xE193C0
void __fastcall hkpPoweredChainMapper::setTargetOrientation(
        hkpPoweredChainMapper *this,
        int linkIndex,
        hkQuaternionf *newTarget_aTb)
{
  int v3; // r10d
  hkpPoweredChainMapper::LinkInfo *v5; // rax
  __int64 v6; // rdx
  hkpPoweredChainMapper::Target *v7; // rdx
  __m128 v8; // xmm4
  hkpPoweredChainData::ConstraintInfo *m_data; // rcx
  __int64 m_infoIndex; // rdx
  __m128 m_quad; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm3

  v3 = 0;
  v5 = &this->m_links.m_data[linkIndex];
  if ( v5->m_numTargets > 0 )
  {
    do
    {
      v6 = v3 + v5->m_firstTargetIdx;
      ++v3;
      v7 = &this->m_targets.m_data[v6];
      v8 = _mm_shuffle_ps(newTarget_aTb->m_vec.m_quad, newTarget_aTb->m_vec.m_quad, 255);
      m_data = v7->m_chain->m_infos.m_data;
      m_infoIndex = v7->m_infoIndex;
      m_quad = m_data[m_infoIndex].m_bTc.m_vec.m_quad;
      v12 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v13 = _mm_mul_ps(newTarget_aTb->m_vec.m_quad, m_quad);
      v14 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), newTarget_aTb->m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(newTarget_aTb->m_vec.m_quad, newTarget_aTb->m_vec.m_quad, 201), m_quad));
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 201), _mm_mul_ps(v8, m_quad)),
              _mm_mul_ps(v12, newTarget_aTb->m_vec.m_quad));
      m_data[m_infoIndex].m_aTc.m_vec.m_quad = _mm_shuffle_ps(
                                                 v15,
                                                 _mm_unpackhi_ps(
                                                   v15,
                                                   _mm_sub_ps(
                                                     _mm_mul_ps(v12, v8),
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_shuffle_ps(v13, v13, 85),
                                                         _mm_shuffle_ps(v13, v13, 0)),
                                                       _mm_shuffle_ps(v13, v13, 170)))),
                                                 196);
    }
    while ( v3 < v5->m_numTargets );
  }
}

