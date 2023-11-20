// File Line: 31
// RVA: 0xD8D4C0
void __fastcall hkpWorldConstraintUtil::addConstraint(hkpWorld *world, hkpConstraintInstance *constraint)
{
  hkpConstraintInstance *v2; // r14
  hkpConstraintData *v3; // rcx
  hkpModifierConstraintAtom *v4; // rdx
  hkpConstraintAtom *v5; // rax
  hkpEntity *v6; // rcx
  hkpEntity *v7; // r8
  unsigned __int16 v8; // ax
  bool v9; // zf
  unsigned __int64 v10; // rsi
  hkpSimulationIsland *v11; // rax
  hkpConstraintAtom *v12; // rcx
  int v13; // edx
  hkpConstraintData *v14; // rcx
  char v15; // al
  hkpModifierConstraintAtom *v16; // rax
  char v17; // r8
  char v18; // al
  unsigned __int8 v19; // dl
  hkpConstraintOwner *v20; // r9
  int v21; // ecx
  signed __int64 v22; // rbx
  int v23; // er13
  __int64 v24; // r10
  int v25; // eax
  hkConstraintInternal *v26; // r8
  unsigned __int16 v27; // cx
  unsigned __int16 v28; // dx
  int v29; // ecx
  __int64 v30; // r11
  __int64 v31; // r8
  unsigned __int8 v32; // cl
  unsigned int v33; // edx
  unsigned int v34; // er9
  signed int v35; // edi
  signed __int64 v36; // rdx
  signed __int64 v37; // rcx
  hkConstraintInternal *v38; // r12
  unsigned int v39; // ecx
  signed __int64 v40; // r10
  int v41; // edi
  char *v42; // rsi
  int v43; // eax
  int v44; // edi
  char *v45; // r15
  __int64 v46; // r8
  signed __int64 v47; // r15
  __int64 v48; // rdx
  __int64 v49; // rcx
  __int64 v50; // rax
  signed __int64 v51; // rax
  int v52; // edi
  signed __int64 v53; // r15
  signed __int64 v54; // rcx
  __int64 v55; // rax
  __int64 v56; // r8
  _DWORD *v57; // rbx
  char *v58; // [rsp+30h] [rbp-49h]
  hkpConstraintInfo cinfo; // [rsp+38h] [rbp-41h]
  hkpConstraintAtom *v60; // [rsp+48h] [rbp-31h]
  unsigned __int16 v61; // [rsp+50h] [rbp-29h]
  int v62; // [rsp+54h] [rbp-25h]
  hkConstraintInternal t; // [rsp+60h] [rbp-19h]
  char usedFlagsOut; // [rsp+E8h] [rbp+6Fh]
  unsigned int v65; // [rsp+F0h] [rbp+77h]
  hkArray<unsigned char,hkContainerHeapAllocator> *v66; // [rsp+F8h] [rbp+7Fh]

  v2 = constraint;
  hkReferencedObject::addReference((hkReferencedObject *)&constraint->vfptr);
  v3 = v2->m_data;
  v62 = 0;
  v3->vfptr[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)&cinfo);
  v4 = v2->m_constraintModifiers;
  v5 = v60;
  v6 = v2->m_entities[0];
  v7 = v2->m_entities[1];
  if ( v4 )
    v5 = (hkpConstraintAtom *)&v2->m_constraintModifiers->m_type;
  t.m_constraint = v2;
  t.m_entities[0] = v6;
  t.m_atoms = v5;
  t.m_entities[1] = v7;
  if ( v4 )
    v8 = v4->m_modifierAtomSize;
  else
    v8 = v61;
  t.m_atomsSize = v8;
  t.m_priority.m_storage = v2->m_priority.m_storage;
  v9 = v6->m_motion.m_type.m_storage == 5;
  if ( v6->m_motion.m_type.m_storage != 5 )
  {
    if ( v7->m_motion.m_type.m_storage != 5 && v6->m_simulationIsland != v7->m_simulationIsland )
    {
      hkpWorldOperationUtil::mergeIslands(v6->m_world, v6, v7);
      v6 = t.m_entities[0];
    }
    v9 = v6->m_motion.m_type.m_storage == 5;
  }
  t.m_whoIsMaster = v9;
  v10 = (unsigned __int64)t.m_entities[v9];
  v11 = *(hkpSimulationIsland **)(v10 + 296);
  v2->m_owner = (hkpConstraintOwner *)&v11->vfptr;
  ++v11->m_numConstraints;
  v12 = t.m_atoms;
  v13 = t.m_atoms->m_type.m_storage;
  t.m_constraintType.m_storage = 0;
  t.m_callbackRequest = 0;
  switch ( v13 )
  {
    case 2:
      v13 = t.m_atoms[72].m_type.m_storage;
      break;
    case 3:
      v13 = t.m_atoms[24].m_type.m_storage;
      break;
    case 4:
      v13 = t.m_atoms[56].m_type.m_storage;
      break;
  }
  if ( (unsigned int)(v13 - 30) <= 5 )
    v13 = **(unsigned __int16 **)&t.m_atoms[12].m_type.m_storage;
  if ( v13 == 1 )
  {
    v14 = v2->m_data;
    t.m_callbackRequest = 2;
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConstraintData *, unsigned int *))v14->vfptr[10].__first_virtual_table_function__)(
                     v14,
                     &v65) )
      t.m_callbackRequest |= 4u;
    v15 = ((__int64 (__fastcall *)(hkpConstraintInstance *))v2->vfptr[3].__vecDelDtor)(v2);
    v12 = t.m_atoms;
    t.m_constraintType.m_storage = v15;
  }
  else
  {
    if ( v13 != 20 )
    {
      if ( v13 != 28 )
        goto LABEL_27;
      t.m_constraintType.m_storage = 2;
    }
    t.m_callbackRequest = 2;
  }
LABEL_27:
  v16 = v2->m_constraintModifiers;
  v17 = 0;
  usedFlagsOut = 0;
  if ( v16 )
  {
    v18 = hkpModifierConstraintAtom::addAllModifierDataToConstraintInfo(v16, &cinfo, &usedFlagsOut);
    v12 = t.m_atoms;
    v17 = usedFlagsOut;
    t.m_callbackRequest |= v18;
  }
  for ( ; v12->m_type.m_storage >= 0x1Eu; v12 = *(hkpConstraintAtom **)&v12[12].m_type.m_storage )
    ;
  if ( v12->m_type.m_storage == 29 )
  {
    v19 = v2->m_entities[0]->m_responseModifierFlags | v2->m_entities[1]->m_responseModifierFlags;
    cinfo.m_sizeOfSchemas += hkpResponseModifier::tableOfAdditionalSchemaSizes[(v19 - ((unsigned __int8)v17 & v19)) & 7];
  }
  v20 = v2->m_owner;
  v21 = cinfo.m_maxSizeOfSchema;
  *(_DWORD *)&t.m_numSolverResults = 0;
  t.m_sizeOfSchemas = 0;
  v22 = v10 + 248;
  v2->m_internal = &t;
  v23 = 0;
  if ( v20->m_constraintInfo.m_maxSizeOfSchema > v21 )
    v21 = v20->m_constraintInfo.m_maxSizeOfSchema;
  v24 = 0i64;
  v20->m_constraintInfo.m_maxSizeOfSchema = v21;
  v25 = cinfo.m_sizeOfSchemas;
  if ( v21 > cinfo.m_sizeOfSchemas )
    v25 = v21;
  v20->m_constraintInfo.m_maxSizeOfSchema = v25;
  v20->m_constraintInfo.m_sizeOfSchemas += cinfo.m_sizeOfSchemas;
  v20->m_constraintInfo.m_numSolverResults += cinfo.m_numSolverResults;
  v20->m_constraintInfo.m_numSolverElemTemps += cinfo.m_numSolverElemTemps;
  v26 = v2->m_internal;
  v27 = LOWORD(cinfo.m_sizeOfSchemas) + v26->m_sizeOfSchemas;
  v28 = LOWORD(cinfo.m_numSolverElemTemps) + v26->m_numSolverElemTemps;
  v26->m_numSolverResults += LOWORD(cinfo.m_numSolverResults);
  v26->m_sizeOfSchemas = v27;
  v26->m_numSolverElemTemps = v28;
  v29 = v2->m_internal->m_sizeOfSchemas;
  if ( v20->m_constraintInfo.m_maxSizeOfSchema > v29 )
    v29 = v20->m_constraintInfo.m_maxSizeOfSchema;
  v20->m_constraintInfo.m_maxSizeOfSchema = v29;
  v30 = *(unsigned __int16 *)(v10 + 256);
  if ( v30 > 0 )
  {
    v31 = *(_QWORD *)v22;
    do
    {
      v32 = *(_BYTE *)(v31 + 35);
      if ( t.m_priority.m_storage < v32 )
        break;
      if ( t.m_priority.m_storage <= v32 )
      {
        v33 = t.m_constraint->m_uid;
        v34 = *(_DWORD *)(*(_QWORD *)v31 + 104i64);
        if ( v33 < v34
          || v33 <= v34
          && *(_DWORD *)((v10 ^ (_QWORD)t.m_entities[0] ^ (_QWORD)t.m_entities[1]) + 0x134) < *(_DWORD *)((v10 ^ *(_QWORD *)(v31 + 8) ^ *(_QWORD *)(v31 + 16)) + 0x134) )
        {
          break;
        }
      }
      ++v24;
      ++v23;
      v31 += 64i64;
    }
    while ( v24 < v30 );
  }
  v35 = 0;
  if ( (unsigned __int16)v30 < (unsigned __int16)(*(_WORD *)(v10 + 258) & 0x3FFF) )
    v35 = v23;
  hkSmallArray<hkConstraintInternal>::insertAt((hkSmallArray<hkConstraintInternal> *)(v10 + 248), v23, &t);
  if ( v35 < *(unsigned __int16 *)(v10 + 256) )
  {
    v36 = (signed __int64)v35 << 6;
    do
    {
      ++v35;
      v37 = v36 + *(_QWORD *)v22;
      v36 += 64i64;
      *(_QWORD *)(*(_QWORD *)v37 + 96i64) = v37;
    }
    while ( v35 < *(unsigned __int16 *)(v10 + 256) );
  }
  v38 = v2->m_internal;
  ((void (__fastcall *)(hkpConstraintData *, _QWORD, unsigned int *))v38->m_constraint->m_data->vfptr[8].__first_virtual_table_function__)(
    v38->m_constraint->m_data,
    (unsigned __int8)v2->m_wantRuntime.m_bool,
    &v65);
  v9 = ((v65 + 15) & 0xFFFFFFF0) == 0;
  v39 = (v65 + 15) & 0xFFFFFFF0;
  v65 = v39;
  v38->m_runtimeSize = v39;
  if ( v9 )
  {
    v38->m_runtime = 0i64;
  }
  else
  {
    v40 = v10 + 280;
    v66 = (hkArray<unsigned char,hkContainerHeapAllocator> *)(v10 + 280);
    v41 = *(_DWORD *)(v10 + 288);
    v58 = *(char **)(v10 + 280);
    if ( (*(_DWORD *)(v10 + 292) & 0x3FFFFFFF) < (signed int)(v41 + v39) )
    {
      hkArrayUtil::_reserve(
        (hkResult *)&usedFlagsOut,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (void *)(v10 + 280),
        v41 + v39,
        1);
      v39 = v65;
      v40 = (signed __int64)v66;
    }
    v42 = *(char **)v40;
    v43 = v41 + v39;
    v44 = 0;
    v45 = *(char **)v40;
    *(_DWORD *)(v40 + 8) = v43;
    v46 = v23;
    v47 = v45 - v58;
    if ( v23 > 0 )
    {
      v48 = 0i64;
      v44 = v23;
      do
      {
        v49 = *(_QWORD *)v22;
        v50 = *(_QWORD *)(*(_QWORD *)v22 + v48 + 48);
        if ( v50 )
        {
          v51 = v47 + v50;
          v42 = (char *)(v51 + *(unsigned __int16 *)(v49 + v48 + 56));
          *(_QWORD *)(v49 + v48 + 48) = v51;
        }
        v48 += 64i64;
        --v46;
      }
      while ( v46 );
    }
    hkString::memMove(
      &v42[v38->m_runtimeSize],
      v42,
      *(_DWORD *)(v40 + 8) + *(_DWORD *)v40 - v38->m_runtimeSize - (_DWORD)v42);
    v52 = v44 + 1;
    v53 = v38->m_runtimeSize + v47;
    v38->m_runtime = (struct hkpConstraintRuntime *)v42;
    if ( v52 < *(unsigned __int16 *)(v22 + 8) )
    {
      v54 = (signed __int64)v52 << 6;
      do
      {
        v55 = *(_QWORD *)(*(_QWORD *)v22 + v54 + 48);
        if ( v55 )
          v55 += v53;
        *(_QWORD *)(*(_QWORD *)v22 + v54 + 48) = v55;
        ++v52;
        v54 += 64i64;
      }
      while ( v52 < *(unsigned __int16 *)(v22 + 8) );
    }
  }
  ((void (__fastcall *)(hkpConstraintData *, struct hkpConstraintRuntime *, _QWORD))v38->m_constraint->m_data->vfptr[9].__first_virtual_table_function__)(
    v38->m_constraint->m_data,
    v38->m_runtime,
    v38->m_runtimeSize);
  v56 = *((_QWORD *)&v38->m_constraint + 2i64 - (unsigned __int8)v38->m_whoIsMaster);
  v57 = (_DWORD *)(v56 + 264);
  v38->m_slaveIndex = *(_WORD *)(v56 + 272);
  if ( *(_DWORD *)(v56 + 272) == (*(_DWORD *)(v56 + 276) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v57, 8);
  *(_QWORD *)(*(_QWORD *)v57 + 8i64 * (signed int)v57[2]++) = v2;
}

// File Line: 295
// RVA: 0xD8D9C0
void __fastcall hkpWorldConstraintUtil::removeConstraint(hkpConstraintInstance *constraint)
{
  hkConstraintInternal *v1; // rbx
  hkpConstraintOwner *v2; // rdx
  hkpConstraintInstance *v3; // rdi
  int v4; // er8
  int v5; // er9
  hkpConstraintOwner *v6; // rax
  hkConstraintInternal *v7; // rcx
  __int64 v8; // r9
  __int64 v9; // rbp
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rdx
  struct hkpConstraintRuntime *v13; // rcx
  hkpEntity *v14; // rsi
  unsigned __int64 i; // rcx
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  struct hkpConstraintRuntime *v19; // rax
  unsigned __int16 v20; // [rsp+24h] [rbp-14h]

  v1 = constraint->m_internal;
  v2 = constraint->m_owner;
  v3 = constraint;
  BYTE1(v2[1].m_constraintInfo.m_maxSizeOfSchema) &= 0xFDu;
  BYTE1(v2[1].m_constraintInfo.m_maxSizeOfSchema) |= 1u;
  v4 = v1->m_numSolverResults;
  v5 = v1->m_numSolverElemTemps;
  v20 = v1->m_sizeOfSchemas;
  if ( constraint->m_internal )
  {
    v6 = constraint->m_owner;
    v6->m_constraintInfo.m_sizeOfSchemas -= v1->m_sizeOfSchemas;
    v6->m_constraintInfo.m_numSolverResults -= v4;
    v6->m_constraintInfo.m_numSolverElemTemps -= v5;
    v7 = constraint->m_internal;
    v7->m_numSolverResults -= v4;
    v7->m_numSolverElemTemps -= v5;
    v7->m_sizeOfSchemas -= v20;
  }
  --*(_DWORD *)&v2[1].m_memSizeAndFlags;
  v3->m_owner = 0i64;
  v8 = v1->m_slaveIndex;
  v9 = 0i64;
  v10 = *((_QWORD *)&v1->m_constraint + 2i64 - (unsigned __int8)v1->m_whoIsMaster);
  v11 = *(_QWORD *)(v10 + 264);
  v12 = *(_QWORD *)(v11 + 8i64 * *(signed int *)(v10 + 272) - 8);
  *(_QWORD *)(v11 + 8 * v8) = v12;
  --*(_DWORD *)(v10 + 272);
  *(_WORD *)(*(_QWORD *)(v12 + 96) + 58i64) = v8;
  v13 = v1->m_runtime;
  v14 = v1->m_entities[(unsigned __int8)v1->m_whoIsMaster];
  if ( v13 )
  {
    v9 = -v1->m_runtimeSize;
    hkString::memMove(
      (void *)v13,
      (char *)v13 + v1->m_runtimeSize,
      LODWORD(v14->m_constraintRuntime.m_data) + v14->m_constraintRuntime.m_size - ((_DWORD)v13 + v1->m_runtimeSize));
    v14->m_constraintRuntime.m_size -= v1->m_runtimeSize;
    v1->m_runtime = 0i64;
  }
  v3->m_internal = 0i64;
  for ( i = (unsigned __int64)&v14->m_constraintsMaster.m_data[(signed __int64)(v14->m_constraintsMaster.m_size - 1)];
        (unsigned __int64)v1 < i;
        ++v1 )
  {
    v16 = *(_OWORD *)&v1[1].m_entities[1];
    *(_OWORD *)&v1->m_constraint = *(_OWORD *)&v1[1].m_constraint;
    v17 = *(_OWORD *)&v1[1].m_atomsSize;
    *(_OWORD *)&v1->m_entities[1] = v16;
    v18 = *(_OWORD *)&v1[1].m_runtime;
    *(_OWORD *)&v1->m_atomsSize = v17;
    *(_OWORD *)&v1->m_runtime = v18;
    v1->m_constraint->m_internal = v1;
    v19 = v1->m_runtime;
    if ( v19 )
      v19 = (struct hkpConstraintRuntime *)((char *)v19 + v9);
    v1->m_runtime = v19;
  }
  --v14->m_constraintsMaster.m_size;
  hkReferencedObject::removeReference((hkReferencedObject *)&v3->vfptr);
}

// File Line: 380
// RVA: 0xD8DB60
hkpConstraintInstance *__fastcall hkpWorldConstraintUtil::getConstraint(hkpEntity *entityA, hkpEntity *entityB)
{
  signed __int64 v2; // r9
  hkpEntity **v3; // rbx
  __int64 v4; // r11
  int v5; // er8
  __int64 v6; // r10
  __int64 v7; // rdx
  _QWORD *v8; // rax
  hkpEntity *v10; // [rsp+0h] [rbp-18h]
  hkpEntity *v11; // [rsp+8h] [rbp-10h]

  v10 = entityA;
  v11 = entityB;
  v2 = 0i64;
  v3 = &v11;
  while ( 1 )
  {
    v4 = (__int64)*(&v10 + v2);
    v5 = 0;
    v6 = *(unsigned __int16 *)(v4 + 256);
    v7 = 0i64;
    if ( v6 > 0 )
      break;
LABEL_6:
    ++v2;
    --v3;
    if ( v2 >= 2 )
      return 0i64;
  }
  v8 = (_QWORD *)(*(_QWORD *)(v4 + 248) + 8i64);
  while ( (hkpEntity *)(v4 ^ *v8 ^ v8[1]) != *v3 )
  {
    ++v7;
    ++v5;
    v8 += 8;
    if ( v7 >= v6 )
      goto LABEL_6;
  }
  return *(hkpConstraintInstance **)(((signed __int64)v5 << 6) + *(_QWORD *)(v4 + 248));
}

// File Line: 407
// RVA: 0xD8DC10
void __fastcall hkpWorldConstraintUtil::addModifier(hkpConstraintInstance *instance, hkpConstraintOwner *constraintOwner, hkpModifierConstraintAtom *newModifier)
{
  hkpConstraintInstance *v3; // rdi
  hkpModifierConstraintAtom *v4; // rbx
  hkpConstraintOwner *v5; // rsi
  hkpModifierConstraintAtom *v6; // rax
  hkConstraintInternal *v7; // r8
  hkpModifierConstraintAtom *v8; // r9
  hkpModifierConstraintAtom *v9; // rax
  char v10; // r10
  int v11; // er9
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  hkConstraintInternal *v15; // r8
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // cx
  int v18; // ecx
  int v19; // edx
  hkConstraintInternal *v20; // rax
  hkpConstraintData *v21; // rcx
  hkpConstraintInfo cinfo; // [rsp+20h] [rbp-28h]
  hkpConstraintAtom *v23; // [rsp+30h] [rbp-18h]
  unsigned __int16 v24; // [rsp+38h] [rbp-10h]
  int v25; // [rsp+3Ch] [rbp-Ch]
  char usedFlagsOut; // [rsp+50h] [rbp+8h]

  v3 = instance;
  v4 = newModifier;
  v5 = constraintOwner;
  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  v6 = hkpWorldConstraintUtil::findLastModifier(v3);
  v7 = v3->m_internal;
  v8 = v6;
  if ( v4->m_type.m_storage == 33 && v6 )
  {
    v4->m_child = v6->m_child;
    v4->m_childSize = v6->m_childSize;
    v6->m_child = (hkpConstraintAtom *)&v4->m_type;
    v6->m_childSize = v4->m_modifierAtomSize;
  }
  else
  {
    v9 = v3->m_constraintModifiers;
    if ( v9 && v9->m_type.m_storage == 34 )
    {
      v4->m_child = v9->m_child;
      v4->m_childSize = v3->m_constraintModifiers->m_childSize;
      v3->m_constraintModifiers->m_child = (hkpConstraintAtom *)&v4->m_type;
      v3->m_constraintModifiers->m_childSize = v4->m_modifierAtomSize;
    }
    else
    {
      v3->m_constraintModifiers = v4;
      if ( !v7 )
      {
        v21 = v3->m_data;
        v25 = 0;
        ((void (__fastcall *)(hkpConstraintData *, hkpConstraintInfo *, _QWORD, hkpModifierConstraintAtom *))v21->vfptr[2].__vecDelDtor)(
          v21,
          &cinfo,
          0i64,
          v8);
        v4->m_child = v23;
        v4->m_childSize = v24;
        return;
      }
      v4->m_child = v7->m_atoms;
      v4->m_childSize = v7->m_atomsSize;
      v7->m_atoms = (hkpConstraintAtom *)&v4->m_type;
      v7->m_atomsSize = v4->m_modifierAtomSize;
    }
  }
  if ( v7 )
  {
    *(_QWORD *)&cinfo.m_maxSizeOfSchema = 0i64;
    *(_QWORD *)&cinfo.m_numSolverResults = 0i64;
    usedFlagsOut = 0;
    v10 = hkpModifierConstraintAtom::addModifierDataToConstraintInfo(v4, &cinfo, &usedFlagsOut);
    if ( v3->m_internal )
    {
      v11 = cinfo.m_sizeOfSchemas;
      v12 = cinfo.m_maxSizeOfSchema;
      v13 = cinfo.m_sizeOfSchemas;
      if ( v5->m_constraintInfo.m_maxSizeOfSchema > cinfo.m_maxSizeOfSchema )
        v12 = v5->m_constraintInfo.m_maxSizeOfSchema;
      if ( v12 > cinfo.m_sizeOfSchemas )
        v13 = v12;
      v5->m_constraintInfo.m_numSolverResults += cinfo.m_numSolverResults;
      v5->m_constraintInfo.m_sizeOfSchemas += v11;
      v14 = cinfo.m_numSolverElemTemps;
      v5->m_constraintInfo.m_maxSizeOfSchema = v13;
      v5->m_constraintInfo.m_numSolverElemTemps += v14;
      v15 = v3->m_internal;
      v16 = v14 + v15->m_numSolverElemTemps;
      v17 = v11 + v15->m_sizeOfSchemas;
      v15->m_numSolverResults += LOWORD(cinfo.m_numSolverResults);
      v15->m_numSolverElemTemps = v16;
      v15->m_sizeOfSchemas = v17;
      v18 = v3->m_internal->m_sizeOfSchemas;
      if ( v5->m_constraintInfo.m_maxSizeOfSchema > v18 )
        v18 = v5->m_constraintInfo.m_maxSizeOfSchema;
      v5->m_constraintInfo.m_maxSizeOfSchema = v18;
    }
    usedFlagsOut &= v3->m_entities[0]->m_responseModifierFlags | v3->m_entities[1]->m_responseModifierFlags;
    v19 = hkpResponseModifier::tableOfAdditionalSchemaSizes[usedFlagsOut & 7];
    v5->m_constraintInfo.m_sizeOfSchemas -= v19;
    v3->m_internal->m_sizeOfSchemas -= v19;
    v20 = v3->m_internal;
    if ( v20 )
      v20->m_callbackRequest |= v10;
  }
}m_sizeOfSchemas -= v19;
    v20 = v3->m_internal;
    if ( v20 )
      v20-

// File Line: 491
// RVA: 0xD8DE00
void __fastcall hkpWorldConstraintUtil::removeAndDeleteModifier(hkpConstraintInstance *instance, hkpConstraintOwner *constraintOwner, hkpConstraintAtom::AtomType type)
{
  hkpConstraintInstance *v3; // rbp
  hkpConstraintAtom::AtomType v4; // edi
  hkpConstraintOwner *v5; // rsi
  hkpModifierConstraintAtom *v6; // rbx
  hkConstraintInternal *v7; // r14
  hkpConstraintAtom *v8; // rcx
  hkpModifierConstraintAtom *v9; // rax
  hkpModifierConstraintAtom *v10; // rcx
  unsigned __int16 v11; // ax
  int v12; // edx
  hkpConstraintInstance *v13; // r8
  int v14; // er9
  int v15; // eax
  hkConstraintInternal *v16; // r8
  unsigned __int16 v17; // dx
  unsigned __int16 v18; // cx
  unsigned int v19; // edi
  _QWORD **v20; // rax
  hkpConstraintInfo cinfo; // [rsp+20h] [rbp-28h]
  char usedFlagsOut; // [rsp+50h] [rbp+8h]

  v3 = instance;
  v4 = type;
  v5 = constraintOwner;
  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  v6 = v3->m_constraintModifiers;
  if ( v6 )
  {
    v7 = v3->m_internal;
    if ( v6->m_type.m_storage == v4 )
    {
      v8 = v6->m_child;
      if ( v7 )
      {
        v7->m_atoms = v8;
        v7->m_atomsSize = v6->m_childSize;
      }
      v9 = 0i64;
      if ( v8->m_type.m_storage >= 0x1Eu )
        v9 = (hkpModifierConstraintAtom *)v8;
      v3->m_constraintModifiers = v9;
    }
    else
    {
      v10 = v3->m_constraintModifiers;
      v6 = (hkpModifierConstraintAtom *)v6->m_child;
      v11 = v6->m_type.m_storage;
      if ( v6->m_type.m_storage < 0x1Eu )
        return;
      while ( v11 != v4 )
      {
        v10 = v6;
        v6 = (hkpModifierConstraintAtom *)v6->m_child;
        v11 = v6->m_type.m_storage;
        if ( v6->m_type.m_storage < 0x1Eu )
          return;
      }
      v10->m_child = v6->m_child;
      v10->m_childSize = v6->m_childSize;
    }
    if ( v7 )
    {
      *(_QWORD *)&cinfo.m_maxSizeOfSchema = 0i64;
      *(_QWORD *)&cinfo.m_numSolverResults = 0i64;
      usedFlagsOut = 0;
      hkpModifierConstraintAtom::addModifierDataToConstraintInfo(v6, &cinfo, &usedFlagsOut);
      usedFlagsOut &= v3->m_entities[0]->m_responseModifierFlags | v3->m_entities[1]->m_responseModifierFlags;
      v12 = hkpResponseModifier::tableOfAdditionalSchemaSizes[usedFlagsOut & 7];
      v5->m_constraintInfo.m_sizeOfSchemas += v12;
      v3->m_internal->m_sizeOfSchemas += v12;
      v13 = v7->m_constraint;
      if ( v7->m_constraint->m_internal )
      {
        v14 = cinfo.m_sizeOfSchemas;
        v5->m_constraintInfo.m_numSolverResults -= cinfo.m_numSolverResults;
        v15 = cinfo.m_numSolverElemTemps;
        v5->m_constraintInfo.m_sizeOfSchemas -= v14;
        v5->m_constraintInfo.m_numSolverElemTemps -= v15;
        v16 = v13->m_internal;
        v17 = v16->m_numSolverElemTemps - v15;
        v18 = v16->m_sizeOfSchemas - v14;
        v16->m_numSolverResults -= LOWORD(cinfo.m_numSolverResults);
        v16->m_numSolverElemTemps = v17;
        v16->m_sizeOfSchemas = v18;
      }
    }
    v19 = v6->m_modifierAtomSize;
    v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpModifierConstraintAtom *, _QWORD))(*v20[11] + 16i64))(v20[11], v6, v19);
  }
}

// File Line: 583
// RVA: 0xD8DF90
hkpModifierConstraintAtom *__fastcall hkpWorldConstraintUtil::findModifier(hkpConstraintInstance *instance, hkpConstraintAtom::AtomType type)
{
  hkpModifierConstraintAtom *result; // rax

  result = instance->m_constraintModifiers;
  if ( result )
  {
    if ( result->m_type.m_storage == type )
      return result;
    while ( 1 )
    {
      result = (hkpModifierConstraintAtom *)result->m_child;
      if ( result->m_type.m_storage < 0x1Eu )
        break;
      if ( result->m_type.m_storage == type )
        return result;
    }
  }
  return 0i64;
}

// File Line: 615
// RVA: 0xD8DFC0
hkpModifierConstraintAtom *__fastcall hkpWorldConstraintUtil::findLastModifier(hkpConstraintInstance *instance)
{
  hkpModifierConstraintAtom *result; // rax
  hkpModifierConstraintAtom *i; // rcx

  result = instance->m_constraintModifiers;
  if ( result )
  {
    for ( i = (hkpModifierConstraintAtom *)result->m_child;
          i->m_type.m_storage >= 0x1Eu;
          i = (hkpModifierConstraintAtom *)i->m_child )
    {
      result = i;
    }
  }
  return result;
}

// File Line: 649
// RVA: 0xD8E000
void __fastcall hkpWorldConstraintUtil::updateFatherOfMovedAtom(hkpConstraintInstance *instance, hkpConstraintAtom *oldAtom, hkpConstraintAtom *updatedAtom, int updatedSizeOfAtom)
{
  hkpModifierConstraintAtom *v4; // r10
  hkConstraintInternal *v5; // rax
  hkpModifierConstraintAtom *i; // rax

  v4 = instance->m_constraintModifiers;
  v5 = instance->m_internal;
  if ( !v4 )
    goto LABEL_4;
  if ( v4 == (hkpModifierConstraintAtom *)oldAtom )
  {
    instance->m_constraintModifiers = (hkpModifierConstraintAtom *)updatedAtom;
LABEL_4:
    if ( v5 )
    {
      v5->m_atoms = updatedAtom;
      v5->m_atomsSize = updatedSizeOfAtom;
    }
    return;
  }
  for ( i = (hkpModifierConstraintAtom *)v4->m_child;
        i != (hkpModifierConstraintAtom *)oldAtom;
        i = (hkpModifierConstraintAtom *)i->m_child )
  {
    v4 = i;
  }
  v4->m_child = updatedAtom;
  v4->m_childSize = updatedSizeOfAtom;
}

