// File Line: 31
// RVA: 0xD8D4C0
void __fastcall hkpWorldConstraintUtil::addConstraint(hkpWorld *world, hkpConstraintInstance *constraint)
{
  hkpConstraintData *m_data; // rcx
  hkpModifierConstraintAtom *m_constraintModifiers; // rdx
  hkpModifierConstraintAtom *v5; // rax
  hkpEntity *v6; // rcx
  hkpEntity *v7; // r8
  unsigned __int16 m_modifierAtomSize; // ax
  bool v9; // zf
  unsigned __int64 v10; // rsi
  hkpSimulationIsland *v11; // rax
  hkpConstraintAtom *m_atoms; // rcx
  int m_storage; // edx
  hkpConstraintData *v14; // rcx
  char v15; // al
  hkpModifierConstraintAtom *v16; // rax
  unsigned __int8 m_enum; // r8
  char v18; // al
  unsigned __int8 v19; // dl
  hkpConstraintOwner *m_owner; // r9
  int m_maxSizeOfSchema; // ecx
  hkSmallArray<hkConstraintInternal> *v22; // rbx
  int v23; // r13d
  __int64 v24; // r10
  int m_sizeOfSchemas; // eax
  hkConstraintInternal *m_internal; // r8
  unsigned __int16 v27; // cx
  unsigned __int16 v28; // dx
  int v29; // ecx
  __int64 v30; // r11
  hkConstraintInternal *v31; // r8
  unsigned __int8 v32; // cl
  unsigned int m_uid; // edx
  unsigned int v34; // r9d
  int v35; // edi
  __int64 v36; // rdx
  __int64 v37; // rcx
  hkConstraintInternal *v38; // r12
  unsigned int v39; // ecx
  __int64 v40; // r10
  int v41; // edi
  char *v42; // rsi
  unsigned int v43; // eax
  int v44; // edi
  char *v45; // r15
  __int64 v46; // r8
  __int64 v47; // r15
  __int64 v48; // rdx
  hkConstraintInternal *v49; // rcx
  struct hkpConstraintRuntime *m_runtime; // rax
  struct hkpConstraintRuntime *v51; // rax
  int v52; // edi
  __int64 v53; // r15
  __int64 v54; // rcx
  struct hkpConstraintRuntime *v55; // rax
  __int64 v56; // r8
  __int64 v57; // rbx
  char *v58; // [rsp+30h] [rbp-49h]
  hkpConstraintInfo cinfo; // [rsp+38h] [rbp-41h] BYREF
  hkpModifierConstraintAtom *v60; // [rsp+48h] [rbp-31h]
  unsigned __int16 v61; // [rsp+50h] [rbp-29h]
  int v62; // [rsp+54h] [rbp-25h]
  hkConstraintInternal t; // [rsp+60h] [rbp-19h] BYREF
  hkResult usedFlagsOut; // [rsp+E8h] [rbp+6Fh] BYREF
  unsigned int v65; // [rsp+F0h] [rbp+77h] BYREF
  hkArray<unsigned char,hkContainerHeapAllocator> *v66; // [rsp+F8h] [rbp+7Fh]

  hkReferencedObject::addReference(constraint);
  m_data = constraint->m_data;
  v62 = 0;
  m_data->vfptr[2].__vecDelDtor(m_data, (unsigned int)&cinfo);
  m_constraintModifiers = constraint->m_constraintModifiers;
  v5 = v60;
  v6 = constraint->m_entities[0];
  v7 = constraint->m_entities[1];
  if ( m_constraintModifiers )
    v5 = constraint->m_constraintModifiers;
  t.m_constraint = constraint;
  t.m_entities[0] = v6;
  t.m_atoms = v5;
  t.m_entities[1] = v7;
  if ( m_constraintModifiers )
    m_modifierAtomSize = m_constraintModifiers->m_modifierAtomSize;
  else
    m_modifierAtomSize = v61;
  t.m_atomsSize = m_modifierAtomSize;
  t.m_priority.m_storage = constraint->m_priority.m_storage;
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
  constraint->m_owner = v11;
  ++v11->m_numConstraints;
  m_atoms = t.m_atoms;
  m_storage = t.m_atoms->m_type.m_storage;
  t.m_constraintType.m_storage = 0;
  t.m_callbackRequest = 0;
  switch ( m_storage )
  {
    case 2:
      m_storage = t.m_atoms[72].m_type.m_storage;
      break;
    case 3:
      m_storage = t.m_atoms[24].m_type.m_storage;
      break;
    case 4:
      m_storage = t.m_atoms[56].m_type.m_storage;
      break;
  }
  if ( (unsigned int)(m_storage - 30) <= 5 )
    m_storage = **(unsigned __int16 **)&t.m_atoms[12].m_type.m_storage;
  if ( m_storage == 1 )
  {
    v14 = constraint->m_data;
    t.m_callbackRequest = 2;
    if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConstraintData *, unsigned int *))v14->vfptr[10].__first_virtual_table_function__)(
                     v14,
                     &v65) )
      t.m_callbackRequest |= 4u;
    v15 = ((__int64 (__fastcall *)(hkpConstraintInstance *))constraint->vfptr[3].__vecDelDtor)(constraint);
    m_atoms = t.m_atoms;
    t.m_constraintType.m_storage = v15;
  }
  else
  {
    if ( m_storage != 20 )
    {
      if ( m_storage != 28 )
        goto LABEL_27;
      t.m_constraintType.m_storage = 2;
    }
    t.m_callbackRequest = 2;
  }
LABEL_27:
  v16 = constraint->m_constraintModifiers;
  m_enum = 0;
  LOBYTE(usedFlagsOut.m_enum) = 0;
  if ( v16 )
  {
    v18 = hkpModifierConstraintAtom::addAllModifierDataToConstraintInfo(v16, &cinfo, (char *)&usedFlagsOut);
    m_atoms = t.m_atoms;
    m_enum = usedFlagsOut.m_enum;
    t.m_callbackRequest |= v18;
  }
  for ( ; m_atoms->m_type.m_storage >= 0x1Eu; m_atoms = *(hkpConstraintAtom **)&m_atoms[12].m_type.m_storage )
    ;
  if ( m_atoms->m_type.m_storage == 29 )
  {
    v19 = constraint->m_entities[0]->m_responseModifierFlags | constraint->m_entities[1]->m_responseModifierFlags;
    cinfo.m_sizeOfSchemas += hkpResponseModifier::tableOfAdditionalSchemaSizes[(v19 - (m_enum & v19)) & 7];
  }
  m_owner = constraint->m_owner;
  m_maxSizeOfSchema = cinfo.m_maxSizeOfSchema;
  *(_DWORD *)&t.m_numSolverResults = 0;
  t.m_sizeOfSchemas = 0;
  v22 = (hkSmallArray<hkConstraintInternal> *)(v10 + 248);
  constraint->m_internal = &t;
  v23 = 0;
  if ( m_owner->m_constraintInfo.m_maxSizeOfSchema > m_maxSizeOfSchema )
    m_maxSizeOfSchema = m_owner->m_constraintInfo.m_maxSizeOfSchema;
  v24 = 0i64;
  m_owner->m_constraintInfo.m_maxSizeOfSchema = m_maxSizeOfSchema;
  m_sizeOfSchemas = cinfo.m_sizeOfSchemas;
  if ( m_maxSizeOfSchema > cinfo.m_sizeOfSchemas )
    m_sizeOfSchemas = m_maxSizeOfSchema;
  m_owner->m_constraintInfo.m_maxSizeOfSchema = m_sizeOfSchemas;
  m_owner->m_constraintInfo.m_sizeOfSchemas += cinfo.m_sizeOfSchemas;
  m_owner->m_constraintInfo.m_numSolverResults += cinfo.m_numSolverResults;
  m_owner->m_constraintInfo.m_numSolverElemTemps += cinfo.m_numSolverElemTemps;
  m_internal = constraint->m_internal;
  v27 = LOWORD(cinfo.m_sizeOfSchemas) + m_internal->m_sizeOfSchemas;
  v28 = LOWORD(cinfo.m_numSolverElemTemps) + m_internal->m_numSolverElemTemps;
  m_internal->m_numSolverResults += LOWORD(cinfo.m_numSolverResults);
  m_internal->m_sizeOfSchemas = v27;
  m_internal->m_numSolverElemTemps = v28;
  v29 = constraint->m_internal->m_sizeOfSchemas;
  if ( m_owner->m_constraintInfo.m_maxSizeOfSchema > v29 )
    v29 = m_owner->m_constraintInfo.m_maxSizeOfSchema;
  m_owner->m_constraintInfo.m_maxSizeOfSchema = v29;
  v30 = *(unsigned __int16 *)(v10 + 256);
  if ( *(_WORD *)(v10 + 256) )
  {
    v31 = v22->m_data;
    do
    {
      v32 = v31->m_priority.m_storage;
      if ( (unsigned int)t.m_priority.m_storage < v32 )
        break;
      if ( (unsigned int)t.m_priority.m_storage <= v32 )
      {
        m_uid = t.m_constraint->m_uid;
        v34 = v31->m_constraint->m_uid;
        if ( m_uid < v34
          || m_uid <= v34
          && *(_DWORD *)((v10 ^ (__int64)t.m_entities[0] ^ (__int64)t.m_entities[1]) + 0x134) < *(_DWORD *)((v10 ^ (__int64)v31->m_entities[0] ^ (__int64)v31->m_entities[1]) + 0x134) )
        {
          break;
        }
      }
      ++v24;
      ++v23;
      ++v31;
    }
    while ( v24 < v30 );
  }
  v35 = 0;
  if ( (unsigned __int16)v30 < (unsigned __int16)(*(_WORD *)(v10 + 258) & 0x3FFF) )
    v35 = v23;
  hkSmallArray<hkConstraintInternal>::insertAt((hkSmallArray<hkConstraintInternal> *)(v10 + 248), v23, &t);
  if ( v35 < *(unsigned __int16 *)(v10 + 256) )
  {
    v36 = (__int64)v35 << 6;
    do
    {
      ++v35;
      v37 = (__int64)v22->m_data + v36;
      v36 += 64i64;
      *(_QWORD *)(*(_QWORD *)v37 + 96i64) = v37;
    }
    while ( v35 < *(unsigned __int16 *)(v10 + 256) );
  }
  v38 = constraint->m_internal;
  ((void (__fastcall *)(hkpConstraintData *, _QWORD, unsigned int *))v38->m_constraint->m_data->vfptr[8].__first_virtual_table_function__)(
    v38->m_constraint->m_data,
    (unsigned __int8)constraint->m_wantRuntime.m_bool,
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
    if ( (*(_DWORD *)(v10 + 292) & 0x3FFFFFFF) < (int)(v41 + v39) )
    {
      hkArrayUtil::_reserve(&usedFlagsOut, &hkContainerHeapAllocator::s_alloc, (const void **)(v10 + 280), v41 + v39, 1);
      v39 = v65;
      v40 = (__int64)v66;
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
        v49 = v22->m_data;
        m_runtime = v22->m_data[v48].m_runtime;
        if ( m_runtime )
        {
          v51 = (struct hkpConstraintRuntime *)((char *)m_runtime + v47);
          v42 = (char *)v51 + v49[v48].m_runtimeSize;
          v49[v48].m_runtime = v51;
        }
        ++v48;
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
    if ( v52 < v22->m_size )
    {
      v54 = (__int64)v52 << 6;
      do
      {
        v55 = *(struct hkpConstraintRuntime **)((char *)&v22->m_data->m_runtime + v54);
        if ( v55 )
          v55 = (struct hkpConstraintRuntime *)((char *)v55 + v53);
        *(struct hkpConstraintRuntime **)((char *)&v22->m_data->m_runtime + v54) = v55;
        ++v52;
        v54 += 64i64;
      }
      while ( v52 < v22->m_size );
    }
  }
  ((void (__fastcall *)(hkpConstraintData *, struct hkpConstraintRuntime *, _QWORD))v38->m_constraint->m_data->vfptr[9].__first_virtual_table_function__)(
    v38->m_constraint->m_data,
    v38->m_runtime,
    v38->m_runtimeSize);
  v56 = *((_QWORD *)&v38->m_constraint + 2i64 - (unsigned __int8)v38->m_whoIsMaster);
  v57 = v56 + 264;
  v38->m_slaveIndex = *(_WORD *)(v56 + 272);
  if ( *(_DWORD *)(v56 + 272) == (*(_DWORD *)(v56 + 276) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v57, 8);
  *(_QWORD *)(*(_QWORD *)v57 + 8i64 * (int)(*(_DWORD *)(v57 + 8))++) = constraint;
}

// File Line: 295
// RVA: 0xD8D9C0
void __fastcall hkpWorldConstraintUtil::removeConstraint(hkpConstraintInstance *constraint)
{
  hkConstraintInternal *m_internal; // rbx
  hkpConstraintOwner *m_owner; // rdx
  int m_numSolverResults; // r8d
  int m_numSolverElemTemps; // r9d
  hkpConstraintOwner *v6; // rax
  hkConstraintInternal *v7; // rcx
  __int64 m_slaveIndex; // r9
  __int64 v9; // rbp
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rdx
  struct hkpConstraintRuntime *m_runtime; // rcx
  hkpEntity *v14; // rsi
  unsigned __int64 i; // rcx
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  struct hkpConstraintRuntime *v19; // rax
  unsigned __int16 m_sizeOfSchemas; // [rsp+24h] [rbp-14h]

  m_internal = constraint->m_internal;
  m_owner = constraint->m_owner;
  BYTE1(m_owner[1].m_constraintInfo.m_maxSizeOfSchema) &= ~2u;
  BYTE1(m_owner[1].m_constraintInfo.m_maxSizeOfSchema) |= 1u;
  m_numSolverResults = m_internal->m_numSolverResults;
  m_numSolverElemTemps = m_internal->m_numSolverElemTemps;
  m_sizeOfSchemas = m_internal->m_sizeOfSchemas;
  if ( constraint->m_internal )
  {
    v6 = constraint->m_owner;
    v6->m_constraintInfo.m_sizeOfSchemas -= m_internal->m_sizeOfSchemas;
    v6->m_constraintInfo.m_numSolverResults -= m_numSolverResults;
    v6->m_constraintInfo.m_numSolverElemTemps -= m_numSolverElemTemps;
    v7 = constraint->m_internal;
    v7->m_numSolverResults -= m_numSolverResults;
    v7->m_numSolverElemTemps -= m_numSolverElemTemps;
    v7->m_sizeOfSchemas -= m_sizeOfSchemas;
  }
  --*(_DWORD *)&m_owner[1].m_memSizeAndFlags;
  constraint->m_owner = 0i64;
  m_slaveIndex = m_internal->m_slaveIndex;
  v9 = 0i64;
  v10 = *((_QWORD *)&m_internal->m_constraint + 2i64 - (unsigned __int8)m_internal->m_whoIsMaster);
  v11 = *(_QWORD *)(v10 + 264);
  v12 = *(_QWORD *)(v11 + 8i64 * *(int *)(v10 + 272) - 8);
  *(_QWORD *)(v11 + 8 * m_slaveIndex) = v12;
  --*(_DWORD *)(v10 + 272);
  *(_WORD *)(*(_QWORD *)(v12 + 96) + 58i64) = m_slaveIndex;
  m_runtime = m_internal->m_runtime;
  v14 = m_internal->m_entities[(unsigned __int8)m_internal->m_whoIsMaster];
  if ( m_runtime )
  {
    v9 = -m_internal->m_runtimeSize;
    hkString::memMove(
      m_runtime,
      (char *)m_runtime + m_internal->m_runtimeSize,
      LODWORD(v14->m_constraintRuntime.m_data)
    + v14->m_constraintRuntime.m_size
    - ((_DWORD)m_runtime
     + m_internal->m_runtimeSize));
    v14->m_constraintRuntime.m_size -= m_internal->m_runtimeSize;
    m_internal->m_runtime = 0i64;
  }
  constraint->m_internal = 0i64;
  for ( i = (unsigned __int64)&v14->m_constraintsMaster.m_data[(__int64)(v14->m_constraintsMaster.m_size - 1)];
        (unsigned __int64)m_internal < i;
        ++m_internal )
  {
    v16 = *(_OWORD *)&m_internal[1].m_entities[1];
    *(_OWORD *)&m_internal->m_constraint = *(_OWORD *)&m_internal[1].m_constraint;
    v17 = *(_OWORD *)&m_internal[1].m_atomsSize;
    *(_OWORD *)&m_internal->m_entities[1] = v16;
    v18 = *(_OWORD *)&m_internal[1].m_runtime;
    *(_OWORD *)&m_internal->m_atomsSize = v17;
    *(_OWORD *)&m_internal->m_runtime = v18;
    m_internal->m_constraint->m_internal = m_internal;
    v19 = m_internal->m_runtime;
    if ( v19 )
      v19 = (struct hkpConstraintRuntime *)((char *)v19 + v9);
    m_internal->m_runtime = v19;
  }
  --v14->m_constraintsMaster.m_size;
  hkReferencedObject::removeReference(constraint);
}

// File Line: 380
// RVA: 0xD8DB60
hkpConstraintInstance *__fastcall hkpWorldConstraintUtil::getConstraint(hkpEntity *entityA, hkpEntity *entityB)
{
  __int64 v2; // r9
  hkpEntity **i; // rbx
  __int64 v4; // r11
  int v5; // r8d
  __int64 v6; // rdx
  _QWORD *v7; // rax
  hkpEntity *v9; // [rsp+0h] [rbp-18h]
  hkpEntity *v10; // [rsp+8h] [rbp-10h] BYREF

  v9 = entityA;
  v10 = entityB;
  v2 = 0i64;
  for ( i = &v10; ; --i )
  {
    v4 = (__int64)*(&v9 + v2);
    v5 = 0;
    v6 = 0i64;
    if ( *(_WORD *)(v4 + 256) )
      break;
LABEL_6:
    if ( ++v2 >= 2 )
      return 0i64;
  }
  v7 = (_QWORD *)(*(_QWORD *)(v4 + 248) + 8i64);
  while ( (hkpEntity *)(v4 ^ *v7 ^ v7[1]) != *i )
  {
    ++v6;
    ++v5;
    v7 += 8;
    if ( v6 >= *(unsigned __int16 *)(v4 + 256) )
      goto LABEL_6;
  }
  return *(hkpConstraintInstance **)(((__int64)v5 << 6) + *(_QWORD *)(v4 + 248));
}

// File Line: 407
// RVA: 0xD8DC10
void __fastcall hkpWorldConstraintUtil::addModifier(
        hkpConstraintInstance *instance,
        hkpConstraintOwner *constraintOwner,
        hkpModifierConstraintAtom *newModifier)
{
  hkpModifierConstraintAtom *LastModifier; // rax
  hkConstraintInternal *m_internal; // r8
  hkpModifierConstraintAtom *v8; // r9
  hkpModifierConstraintAtom *m_constraintModifiers; // rax
  char v10; // r10
  int m_sizeOfSchemas; // r9d
  int m_maxSizeOfSchema; // edx
  int v13; // ecx
  int m_numSolverElemTemps; // eax
  hkConstraintInternal *v15; // r8
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // cx
  int v18; // ecx
  int v19; // edx
  hkConstraintInternal *v20; // rax
  hkpConstraintData *m_data; // rcx
  hkpConstraintInfo cinfo; // [rsp+20h] [rbp-28h] BYREF
  hkpConstraintAtom *v23; // [rsp+30h] [rbp-18h]
  unsigned __int16 v24; // [rsp+38h] [rbp-10h]
  int v25; // [rsp+3Ch] [rbp-Ch]
  char usedFlagsOut; // [rsp+50h] [rbp+8h] BYREF

  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  LastModifier = hkpWorldConstraintUtil::findLastModifier(instance);
  m_internal = instance->m_internal;
  v8 = LastModifier;
  if ( newModifier->m_type.m_storage == 33 && LastModifier )
  {
    newModifier->m_child = LastModifier->m_child;
    newModifier->m_childSize = LastModifier->m_childSize;
    LastModifier->m_child = newModifier;
    LastModifier->m_childSize = newModifier->m_modifierAtomSize;
  }
  else
  {
    m_constraintModifiers = instance->m_constraintModifiers;
    if ( m_constraintModifiers && m_constraintModifiers->m_type.m_storage == 34 )
    {
      newModifier->m_child = m_constraintModifiers->m_child;
      newModifier->m_childSize = instance->m_constraintModifiers->m_childSize;
      instance->m_constraintModifiers->m_child = newModifier;
      instance->m_constraintModifiers->m_childSize = newModifier->m_modifierAtomSize;
    }
    else
    {
      instance->m_constraintModifiers = newModifier;
      if ( !m_internal )
      {
        m_data = instance->m_data;
        v25 = 0;
        ((void (__fastcall *)(hkpConstraintData *, hkpConstraintInfo *, _QWORD, hkpModifierConstraintAtom *))m_data->vfptr[2].__vecDelDtor)(
          m_data,
          &cinfo,
          0i64,
          v8);
        newModifier->m_child = v23;
        newModifier->m_childSize = v24;
        return;
      }
      newModifier->m_child = m_internal->m_atoms;
      newModifier->m_childSize = m_internal->m_atomsSize;
      m_internal->m_atoms = newModifier;
      m_internal->m_atomsSize = newModifier->m_modifierAtomSize;
    }
  }
  if ( m_internal )
  {
    *(_QWORD *)&cinfo.m_maxSizeOfSchema = 0i64;
    *(_QWORD *)&cinfo.m_numSolverResults = 0i64;
    usedFlagsOut = 0;
    v10 = hkpModifierConstraintAtom::addModifierDataToConstraintInfo(newModifier, &cinfo, &usedFlagsOut);
    if ( instance->m_internal )
    {
      m_sizeOfSchemas = cinfo.m_sizeOfSchemas;
      m_maxSizeOfSchema = cinfo.m_maxSizeOfSchema;
      v13 = cinfo.m_sizeOfSchemas;
      if ( constraintOwner->m_constraintInfo.m_maxSizeOfSchema > cinfo.m_maxSizeOfSchema )
        m_maxSizeOfSchema = constraintOwner->m_constraintInfo.m_maxSizeOfSchema;
      if ( m_maxSizeOfSchema > cinfo.m_sizeOfSchemas )
        v13 = m_maxSizeOfSchema;
      constraintOwner->m_constraintInfo.m_numSolverResults += cinfo.m_numSolverResults;
      constraintOwner->m_constraintInfo.m_sizeOfSchemas += m_sizeOfSchemas;
      m_numSolverElemTemps = cinfo.m_numSolverElemTemps;
      constraintOwner->m_constraintInfo.m_maxSizeOfSchema = v13;
      constraintOwner->m_constraintInfo.m_numSolverElemTemps += m_numSolverElemTemps;
      v15 = instance->m_internal;
      v16 = m_numSolverElemTemps + v15->m_numSolverElemTemps;
      v17 = m_sizeOfSchemas + v15->m_sizeOfSchemas;
      v15->m_numSolverResults += LOWORD(cinfo.m_numSolverResults);
      v15->m_numSolverElemTemps = v16;
      v15->m_sizeOfSchemas = v17;
      v18 = instance->m_internal->m_sizeOfSchemas;
      if ( constraintOwner->m_constraintInfo.m_maxSizeOfSchema > v18 )
        v18 = constraintOwner->m_constraintInfo.m_maxSizeOfSchema;
      constraintOwner->m_constraintInfo.m_maxSizeOfSchema = v18;
    }
    usedFlagsOut &= instance->m_entities[0]->m_responseModifierFlags | instance->m_entities[1]->m_responseModifierFlags;
    v19 = hkpResponseModifier::tableOfAdditionalSchemaSizes[usedFlagsOut & 7];
    constraintOwner->m_constraintInfo.m_sizeOfSchemas -= v19;
    instance->m_internal->m_sizeOfSchemas -= v19;
    v20 = instance->m_internal;
    if ( v20 )
      v20->m_callbackRequest |= v10;
  }
}

// File Line: 491
// RVA: 0xD8DE00
void __fastcall hkpWorldConstraintUtil::removeAndDeleteModifier(
        hkpConstraintInstance *instance,
        hkpConstraintOwner *constraintOwner,
        hkpConstraintAtom::AtomType type)
{
  hkpModifierConstraintAtom *m_constraintModifiers; // rbx
  hkConstraintInternal *m_internal; // r14
  hkpModifierConstraintAtom *m_child; // rcx
  hkpModifierConstraintAtom *v9; // rax
  hkpModifierConstraintAtom *v10; // rcx
  unsigned __int16 m_storage; // ax
  int v12; // edx
  hkpConstraintInstance *m_constraint; // r8
  int m_sizeOfSchemas; // r9d
  int m_numSolverElemTemps; // eax
  hkConstraintInternal *v16; // r8
  unsigned __int16 v17; // dx
  unsigned __int16 v18; // cx
  unsigned int m_modifierAtomSize; // edi
  _QWORD **Value; // rax
  hkpConstraintInfo cinfo; // [rsp+20h] [rbp-28h] BYREF
  char usedFlagsOut; // [rsp+50h] [rbp+8h] BYREF

  ((void (__fastcall *)(hkpConstraintOwner *))constraintOwner->vfptr[3].__vecDelDtor)(constraintOwner);
  m_constraintModifiers = instance->m_constraintModifiers;
  if ( m_constraintModifiers )
  {
    m_internal = instance->m_internal;
    if ( m_constraintModifiers->m_type.m_storage == type )
    {
      m_child = (hkpModifierConstraintAtom *)m_constraintModifiers->m_child;
      if ( m_internal )
      {
        m_internal->m_atoms = m_child;
        m_internal->m_atomsSize = m_constraintModifiers->m_childSize;
      }
      v9 = 0i64;
      if ( m_child->m_type.m_storage >= 0x1Eu )
        v9 = m_child;
      instance->m_constraintModifiers = v9;
    }
    else
    {
      v10 = instance->m_constraintModifiers;
      m_constraintModifiers = (hkpModifierConstraintAtom *)m_constraintModifiers->m_child;
      m_storage = m_constraintModifiers->m_type.m_storage;
      if ( m_constraintModifiers->m_type.m_storage < 0x1Eu )
        return;
      while ( m_storage != type )
      {
        v10 = m_constraintModifiers;
        m_constraintModifiers = (hkpModifierConstraintAtom *)m_constraintModifiers->m_child;
        m_storage = m_constraintModifiers->m_type.m_storage;
        if ( m_constraintModifiers->m_type.m_storage < 0x1Eu )
          return;
      }
      v10->m_child = m_constraintModifiers->m_child;
      v10->m_childSize = m_constraintModifiers->m_childSize;
    }
    if ( m_internal )
    {
      *(_QWORD *)&cinfo.m_maxSizeOfSchema = 0i64;
      *(_QWORD *)&cinfo.m_numSolverResults = 0i64;
      usedFlagsOut = 0;
      hkpModifierConstraintAtom::addModifierDataToConstraintInfo(m_constraintModifiers, &cinfo, &usedFlagsOut);
      usedFlagsOut &= instance->m_entities[0]->m_responseModifierFlags | instance->m_entities[1]->m_responseModifierFlags;
      v12 = hkpResponseModifier::tableOfAdditionalSchemaSizes[usedFlagsOut & 7];
      constraintOwner->m_constraintInfo.m_sizeOfSchemas += v12;
      instance->m_internal->m_sizeOfSchemas += v12;
      m_constraint = m_internal->m_constraint;
      if ( m_internal->m_constraint->m_internal )
      {
        m_sizeOfSchemas = cinfo.m_sizeOfSchemas;
        constraintOwner->m_constraintInfo.m_numSolverResults -= cinfo.m_numSolverResults;
        m_numSolverElemTemps = cinfo.m_numSolverElemTemps;
        constraintOwner->m_constraintInfo.m_sizeOfSchemas -= m_sizeOfSchemas;
        constraintOwner->m_constraintInfo.m_numSolverElemTemps -= m_numSolverElemTemps;
        v16 = m_constraint->m_internal;
        v17 = v16->m_numSolverElemTemps - m_numSolverElemTemps;
        v18 = v16->m_sizeOfSchemas - m_sizeOfSchemas;
        v16->m_numSolverResults -= LOWORD(cinfo.m_numSolverResults);
        v16->m_numSolverElemTemps = v17;
        v16->m_sizeOfSchemas = v18;
      }
    }
    m_modifierAtomSize = m_constraintModifiers->m_modifierAtomSize;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpModifierConstraintAtom *, _QWORD))(*Value[11] + 16i64))(
      Value[11],
      m_constraintModifiers,
      m_modifierAtomSize);
  }
}

// File Line: 583
// RVA: 0xD8DF90
hkpModifierConstraintAtom *__fastcall hkpWorldConstraintUtil::findModifier(
        hkpConstraintInstance *instance,
        hkpConstraintAtom::AtomType type)
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
void __fastcall hkpWorldConstraintUtil::updateFatherOfMovedAtom(
        hkpConstraintInstance *instance,
        hkpModifierConstraintAtom *oldAtom,
        hkpModifierConstraintAtom *updatedAtom,
        unsigned __int16 updatedSizeOfAtom)
{
  hkpModifierConstraintAtom *m_constraintModifiers; // r10
  hkConstraintInternal *m_internal; // rax
  hkpModifierConstraintAtom *i; // rax

  m_constraintModifiers = instance->m_constraintModifiers;
  m_internal = instance->m_internal;
  if ( !m_constraintModifiers )
    goto LABEL_4;
  if ( m_constraintModifiers == oldAtom )
  {
    instance->m_constraintModifiers = updatedAtom;
LABEL_4:
    if ( m_internal )
    {
      m_internal->m_atoms = updatedAtom;
      m_internal->m_atomsSize = updatedSizeOfAtom;
    }
    return;
  }
  for ( i = (hkpModifierConstraintAtom *)m_constraintModifiers->m_child;
        i != oldAtom;
        i = (hkpModifierConstraintAtom *)i->m_child )
  {
    m_constraintModifiers = i;
  }
  m_constraintModifiers->m_child = updatedAtom;
  m_constraintModifiers->m_childSize = updatedSizeOfAtom;
}

