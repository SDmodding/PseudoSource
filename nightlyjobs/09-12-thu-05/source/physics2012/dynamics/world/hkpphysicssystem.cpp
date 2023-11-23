// File Line: 38
// RVA: 0xD65530
void __fastcall hkpPhysicsSystem::hkpPhysicsSystem(hkpPhysicsSystem *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystem::`vftable;
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_rigidBodies.m_capacityAndFlags = 0x80000000;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 0x80000000;
  this->m_actions.m_data = 0i64;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacityAndFlags = 0x80000000;
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_size = 0;
  this->m_phantoms.m_capacityAndFlags = 0x80000000;
  hkStringPtr::hkStringPtr(&this->m_name, 0i64);
  this->m_userData = 0i64;
  this->m_active.m_bool = 1;
}

// File Line: 42
// RVA: 0xD65C90
void __fastcall hkpPhysicsSystem::removeAll(hkpPhysicsSystem *this)
{
  __int64 m_size; // rsi
  __int64 i; // rbx
  hkpRigidBody *v4; // rcx
  __int64 v5; // rsi
  __int64 j; // rbx
  hkpPhantom *v7; // rcx
  __int64 v8; // rsi
  __int64 k; // rbx
  hkpConstraintInstance *v10; // rcx
  __int64 v11; // rsi
  __int64 m; // rbx
  hkpAction *v13; // rcx

  m_size = this->m_rigidBodies.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    v4 = this->m_rigidBodies.m_data[i];
    if ( v4 )
      hkReferencedObject::removeReference(v4);
  }
  v5 = this->m_phantoms.m_size;
  this->m_rigidBodies.m_size = 0;
  for ( j = 0i64; j < v5; ++j )
  {
    v7 = this->m_phantoms.m_data[j];
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = this->m_constraints.m_size;
  this->m_phantoms.m_size = 0;
  for ( k = 0i64; k < v8; ++k )
  {
    v10 = this->m_constraints.m_data[k];
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = this->m_actions.m_size;
  this->m_constraints.m_size = 0;
  for ( m = 0i64; m < v11; ++m )
  {
    v13 = this->m_actions.m_data[m];
    if ( v13 )
      hkReferencedObject::removeReference(v13);
  }
  this->m_actions.m_size = 0;
}

// File Line: 85
// RVA: 0xD655B0
void __fastcall hkpPhysicsSystem::~hkpPhysicsSystem(hkpPhysicsSystem *this)
{
  int m_capacityAndFlags; // r8d
  int v3; // r8d
  int v4; // r8d
  int v5; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystem::`vftable;
  hkpPhysicsSystem::removeAll(this);
  hkStringPtr::~hkStringPtr(&this->m_name);
  m_capacityAndFlags = this->m_phantoms.m_capacityAndFlags;
  this->m_phantoms.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_phantoms.m_data,
      8 * m_capacityAndFlags);
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_capacityAndFlags = 0x80000000;
  v3 = this->m_actions.m_capacityAndFlags;
  this->m_actions.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_actions.m_data, 8 * v3);
  this->m_actions.m_data = 0i64;
  this->m_actions.m_capacityAndFlags = 0x80000000;
  v4 = this->m_constraints.m_capacityAndFlags;
  this->m_constraints.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_constraints.m_data,
      8 * v4);
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_capacityAndFlags = 0x80000000;
  v5 = this->m_rigidBodies.m_capacityAndFlags;
  this->m_rigidBodies.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_rigidBodies.m_data,
      8 * v5);
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 90
// RVA: 0xD65D90
void __fastcall hkpPhysicsSystem::copy(hkpPhysicsSystem *this, hkpPhysicsSystem *toCopy)
{
  __int64 m_size; // rax
  hkpRigidBody **m_data; // rcx
  __int64 v6; // rdx
  char *v7; // r8
  hkpRigidBody *v8; // rax
  __int64 v9; // rax
  hkpPhantom **v10; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkpPhantom *v13; // rax
  __int64 v14; // rax
  hkpConstraintInstance **v15; // rcx
  __int64 v16; // rdx
  char *v17; // r8
  hkpConstraintInstance *v18; // rax
  __int64 v19; // rax
  hkpAction **v20; // rcx
  __int64 v21; // rdx
  char *v22; // r8
  hkpAction *v23; // rax
  int v24; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_rigidBodies.m_size )
  {
    if ( this->m_rigidBodies.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_rigidBodies.m_data,
        8 * this->m_rigidBodies.m_capacityAndFlags);
    v24 = 8 * toCopy->m_rigidBodies.m_size;
    this->m_rigidBodies.m_data = (hkpRigidBody **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v24);
    this->m_rigidBodies.m_capacityAndFlags = v24 / 8;
  }
  m_size = toCopy->m_rigidBodies.m_size;
  m_data = this->m_rigidBodies.m_data;
  this->m_rigidBodies.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)toCopy->m_rigidBodies.m_data - (char *)m_data);
    do
    {
      v8 = *(hkpRigidBody **)((char *)m_data++ + (_QWORD)v7);
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
  if ( (this->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_phantoms.m_size )
  {
    if ( this->m_phantoms.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_phantoms.m_data,
        8 * this->m_phantoms.m_capacityAndFlags);
    v24 = 8 * toCopy->m_phantoms.m_size;
    this->m_phantoms.m_data = (hkpPhantom **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                               &hkContainerHeapAllocator::s_alloc,
                                               &v24);
    this->m_phantoms.m_capacityAndFlags = v24 / 8;
  }
  v9 = toCopy->m_phantoms.m_size;
  v10 = this->m_phantoms.m_data;
  this->m_phantoms.m_size = v9;
  v11 = v9;
  if ( (int)v9 > 0 )
  {
    v12 = (char *)((char *)toCopy->m_phantoms.m_data - (char *)v10);
    do
    {
      v13 = *(hkpPhantom **)((char *)v10++ + (_QWORD)v12);
      *(v10 - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
  if ( (this->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_constraints.m_size )
  {
    if ( this->m_constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_constraints.m_data,
        8 * this->m_constraints.m_capacityAndFlags);
    v24 = 8 * toCopy->m_constraints.m_size;
    this->m_constraints.m_data = (hkpConstraintInstance **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                             &hkContainerHeapAllocator::s_alloc,
                                                             &v24);
    this->m_constraints.m_capacityAndFlags = v24 / 8;
  }
  v14 = toCopy->m_constraints.m_size;
  v15 = this->m_constraints.m_data;
  this->m_constraints.m_size = v14;
  v16 = v14;
  if ( (int)v14 > 0 )
  {
    v17 = (char *)((char *)toCopy->m_constraints.m_data - (char *)v15);
    do
    {
      v18 = *(hkpConstraintInstance **)((char *)v15++ + (_QWORD)v17);
      *(v15 - 1) = v18;
      --v16;
    }
    while ( v16 );
  }
  if ( (this->m_actions.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_actions.m_size )
  {
    if ( this->m_actions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_actions.m_data,
        8 * this->m_actions.m_capacityAndFlags);
    v24 = 8 * toCopy->m_actions.m_size;
    this->m_actions.m_data = (hkpAction **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                             &hkContainerHeapAllocator::s_alloc,
                                             &v24);
    this->m_actions.m_capacityAndFlags = v24 / 8;
  }
  v19 = toCopy->m_actions.m_size;
  v20 = this->m_actions.m_data;
  this->m_actions.m_size = v19;
  v21 = v19;
  if ( (int)v19 > 0 )
  {
    v22 = (char *)((char *)toCopy->m_actions.m_data - (char *)v20);
    do
    {
      v23 = *(hkpAction **)((char *)v20++ + (_QWORD)v22);
      *(v20 - 1) = v23;
      --v21;
    }
    while ( v21 );
  }
  hkStringPtr::operator=(&this->m_name, &toCopy->m_name);
  this->m_userData = toCopy->m_userData;
  this->m_active.m_bool = toCopy->m_active.m_bool;
}

// File Line: 102
// RVA: 0xD656D0
hkpPhysicsSystem *__fastcall hkpPhysicsSystem::clone(
        hkpPhysicsSystem *this,
        hkpPhysicsSystem::CloneConstraintMode cloneMode)
{
  hkpPhysicsSystem *v2; // r14
  _QWORD **Value; // rax
  hkpPhysicsSystem *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rsi
  __int64 *v8; // r15
  int m_size; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // r9d
  int v17; // ebx
  __int64 *v18; // r13
  int v19; // eax
  int v20; // eax
  int v21; // r9d
  int v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  __int64 v26; // rcx
  int v27; // esi
  __int64 v28; // rdi
  __int64 v29; // rbx
  __int64 v30; // rax
  int v31; // esi
  __int64 v32; // r15
  __int64 v33; // rdi
  __int64 v34; // rbx
  __int64 v35; // rax
  int v36; // r15d
  __int64 v37; // rsi
  hkpPhysicsSystem *v38; // rbx
  hkpConstraintInstance *v39; // r14
  __int64 v40; // rdx
  hkpRigidBody **m_data; // rax
  hkpEntity *v42; // rdi
  hkpEntity *v43; // r8
  __int64 v44; // rdx
  __int64 v45; // rcx
  hkpRigidBody **v46; // rax
  hkpConstraintInstance::CloningMode v47; // r9d
  __int64 v48; // rbx
  int v49; // r15d
  __int64 *v50; // r12
  __int64 v51; // rsi
  hkpAction *v52; // rdi
  hkpRigidBody *v53; // r8
  __int64 v54; // rbx
  __int64 v55; // r9
  __int64 v56; // r13
  __int64 v57; // rdx
  __int64 v58; // rcx
  hkpRigidBody **v59; // rax
  __int64 v60; // rbx
  __int64 v61; // r9
  __int64 v62; // rdx
  __int64 v63; // rax
  hkpPhantom **v64; // rcx
  __int64 v65; // rbx
  __int64 *v67; // [rsp+30h] [rbp-50h]
  _QWORD *v68; // [rsp+38h] [rbp-48h] BYREF
  int v69; // [rsp+40h] [rbp-40h]
  int v70; // [rsp+44h] [rbp-3Ch]
  _QWORD *array; // [rsp+48h] [rbp-38h] BYREF
  int v72; // [rsp+50h] [rbp-30h]
  int v73; // [rsp+54h] [rbp-2Ch]
  _QWORD *v74; // [rsp+58h] [rbp-28h] BYREF
  int v75; // [rsp+60h] [rbp-20h]
  int v76; // [rsp+64h] [rbp-1Ch]
  _QWORD *v77; // [rsp+68h] [rbp-18h] BYREF
  int v78; // [rsp+70h] [rbp-10h]
  int v79; // [rsp+74h] [rbp-Ch]
  hkpPhysicsSystem *v80; // [rsp+C0h] [rbp+40h] BYREF
  hkResult result; // [rsp+D0h] [rbp+50h] BYREF
  __int64 v82; // [rsp+D8h] [rbp+58h]

  v80 = this;
  v2 = this;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 104i64);
  if ( v5 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v82 = v7;
  hkStringPtr::operator=((hkStringPtr *)(v7 + 80), &v2->m_name);
  v8 = (__int64 *)(v7 + 16);
  *(_QWORD *)(v7 + 88) = v2->m_userData;
  *(_BYTE *)(v7 + 96) = v2->m_active.m_bool;
  m_size = v2->m_rigidBodies.m_size;
  v10 = *(_DWORD *)(v7 + 28) & 0x3FFFFFFF;
  if ( v10 < m_size )
  {
    v11 = 2 * v10;
    v12 = v2->m_rigidBodies.m_size;
    if ( m_size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v7 + 16), v12, 8);
  }
  *(_DWORD *)(v7 + 24) = m_size;
  v13 = v2->m_phantoms.m_size;
  v14 = *(_DWORD *)(v7 + 76) & 0x3FFFFFFF;
  if ( v14 < v13 )
  {
    v15 = 2 * v14;
    v16 = v2->m_phantoms.m_size;
    if ( v13 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v7 + 64), v16, 8);
  }
  *(_DWORD *)(v7 + 72) = v13;
  v17 = v2->m_constraints.m_size;
  v18 = (__int64 *)(v7 + 32);
  v19 = *(_DWORD *)(v7 + 44) & 0x3FFFFFFF;
  if ( v19 < v17 )
  {
    v20 = 2 * v19;
    v21 = v2->m_constraints.m_size;
    if ( v17 < v20 )
      v21 = v20;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v7 + 32), v21, 8);
  }
  *(_DWORD *)(v7 + 40) = v17;
  v22 = v2->m_actions.m_size;
  v67 = (__int64 *)(v7 + 48);
  v23 = *(_DWORD *)(v7 + 60) & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    v25 = v2->m_actions.m_size;
    if ( v22 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v7 + 48), v25, 8);
  }
  v26 = 0i64;
  *(_DWORD *)(v7 + 56) = v22;
  v27 = 0;
  if ( v2->m_rigidBodies.m_size > 0 )
  {
    v28 = 0i64;
    do
    {
      v29 = *v8;
      v30 = ((__int64 (__fastcall *)(hkpRigidBody *))v2->m_rigidBodies.m_data[v28]->vfptr[3].__first_virtual_table_function__)(v2->m_rigidBodies.m_data[v28]);
      ++v27;
      *(_QWORD *)(v29 + ++v28 * 8 - 8) = v30;
    }
    while ( v27 < v2->m_rigidBodies.m_size );
    v26 = 0i64;
  }
  v31 = 0;
  if ( v2->m_phantoms.m_size > 0 )
  {
    v32 = v82;
    v33 = 0i64;
    do
    {
      v34 = *(_QWORD *)(v32 + 64);
      v35 = ((__int64 (__fastcall *)(hkpPhantom *))v2->m_phantoms.m_data[v33]->vfptr[6].__vecDelDtor)(v2->m_phantoms.m_data[v33]);
      ++v31;
      *(_QWORD *)(v34 + ++v33 * 8 - 8) = v35;
    }
    while ( v31 < v2->m_phantoms.m_size );
    v26 = 0i64;
  }
  v36 = 0;
  if ( v2->m_constraints.m_size > 0 )
  {
    v37 = 0i64;
    while ( 1 )
    {
      v38 = v80;
      v39 = v2->m_constraints.m_data[v37];
      v40 = v80->m_rigidBodies.m_size;
      if ( v40 <= 0 )
      {
LABEL_34:
        v26 = -1i64;
      }
      else
      {
        m_data = v80->m_rigidBodies.m_data;
        while ( *m_data != v39->m_entities[0] )
        {
          ++v26;
          ++m_data;
          if ( v26 >= v40 )
            goto LABEL_34;
        }
      }
      v42 = *(hkpEntity **)(*(_QWORD *)(v82 + 16) + 8 * v26);
      if ( hkpConstraintInstance::isConstrainedToWorld(v39, (hkBool *)&result)->m_bool )
      {
        v43 = 0i64;
      }
      else
      {
        v44 = v38->m_rigidBodies.m_size;
        v45 = 0i64;
        if ( v44 <= 0 )
        {
LABEL_41:
          v45 = -1i64;
        }
        else
        {
          v46 = v38->m_rigidBodies.m_data;
          while ( *v46 != v39->m_entities[1] )
          {
            ++v45;
            ++v46;
            if ( v45 >= v44 )
              goto LABEL_41;
          }
        }
        v43 = *(hkpEntity **)(*(_QWORD *)(v82 + 16) + 8 * v45);
      }
      if ( cloneMode == CLONE_SHALLOW_IF_NOT_CONSTRAINED_TO_WORLD )
        break;
      if ( cloneMode == CLONE_DATAS_WITH_MOTORS )
      {
        v47 = CLONE_DATAS_WITH_MOTORS;
        goto LABEL_49;
      }
      if ( cloneMode == CLONE_FORCE_SHALLOW )
      {
        v47 = CLONE_FORCE_SHALLOW;
        goto LABEL_49;
      }
LABEL_50:
      v2 = v80;
      ++v36;
      ++v37;
      v26 = 0i64;
      if ( v36 >= v80->m_constraints.m_size )
        goto LABEL_51;
    }
    v47 = CLONE_SHALLOW_IF_NOT_CONSTRAINED_TO_WORLD;
LABEL_49:
    v48 = *v18;
    *(_QWORD *)(v48 + v37 * 8) = hkpConstraintInstance::clone(v39, v42, v43, v47);
    goto LABEL_50;
  }
LABEL_51:
  v49 = 0;
  if ( v2->m_actions.m_size > 0 )
  {
    v50 = v67;
    v51 = 0i64;
    do
    {
      v52 = v2->m_actions.m_data[v51];
      if ( v52 )
      {
        v77 = 0i64;
        v78 = 0;
        v79 = 0x80000000;
        v52->vfptr[2].__vecDelDtor(v52, (unsigned int)&v77);
        v54 = v78;
        array = 0i64;
        v72 = 0;
        v73 = 0x80000000;
        if ( v78 <= 0 )
          LODWORD(v80) = 0;
        else
          hkArrayUtil::_reserve((hkResult *)&v80, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v78, 8);
        v55 = 0i64;
        v56 = v82;
        v72 = v54;
        if ( (int)v54 > 0 )
        {
          do
          {
            v57 = v2->m_rigidBodies.m_size;
            v58 = 0i64;
            v53 = (hkpRigidBody *)v77[v55];
            if ( v57 <= 0 )
            {
LABEL_63:
              v58 = -1i64;
            }
            else
            {
              v59 = v2->m_rigidBodies.m_data;
              while ( *v59 != v53 )
              {
                ++v58;
                ++v59;
                if ( v58 >= v57 )
                  goto LABEL_63;
              }
            }
            array[v55++] = *(_QWORD *)(*(_QWORD *)(v56 + 16) + 8 * v58);
          }
          while ( v55 < v54 );
        }
        v74 = 0i64;
        v75 = 0;
        v76 = 0x80000000;
        ((void (__fastcall *)(hkpAction *, _QWORD **, hkpRigidBody *, __int64))v52->vfptr[2].__first_virtual_table_function__)(
          v52,
          &v74,
          v53,
          v55);
        v60 = v75;
        v68 = 0i64;
        v69 = 0;
        v70 = 0x80000000;
        if ( v75 <= 0 )
          result.m_enum = HK_SUCCESS;
        else
          hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v68, v75, 8);
        v69 = v60;
        v61 = 0i64;
        if ( (int)v60 > 0 )
        {
          do
          {
            v62 = v2->m_phantoms.m_size;
            v63 = 0i64;
            if ( v62 <= 0 )
            {
LABEL_73:
              v63 = -1i64;
            }
            else
            {
              v64 = v2->m_phantoms.m_data;
              while ( *v64 != (hkpPhantom *)v74[v61] )
              {
                ++v63;
                ++v64;
                if ( v63 >= v62 )
                  goto LABEL_73;
              }
            }
            v68[v61++] = *(_QWORD *)(*(_QWORD *)(v56 + 64) + 8 * v63);
          }
          while ( v61 < v60 );
          v50 = v67;
        }
        v65 = *v50;
        *(_QWORD *)(v65 + v51 * 8) = ((__int64 (__fastcall *)(hkpAction *, _QWORD **, _QWORD **, __int64))v52->vfptr[3].__first_virtual_table_function__)(
                                       v52,
                                       &array,
                                       &v68,
                                       v61);
        v69 = 0;
        if ( v70 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v68, 8 * v70);
        v68 = 0i64;
        v70 = 0x80000000;
        v75 = 0;
        if ( v76 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v74, 8 * v76);
        v74 = 0i64;
        v76 = 0x80000000;
        v72 = 0;
        if ( v73 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v73);
        array = 0i64;
        v73 = 0x80000000;
        v78 = 0;
        if ( v79 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v77, 8 * v79);
        v77 = 0i64;
        v79 = 0x80000000;
      }
      else
      {
        *(_QWORD *)(v51 * 8 + *v50) = 0i64;
      }
      ++v49;
      ++v51;
    }
    while ( v49 < v2->m_actions.m_size );
  }
  return (hkpPhysicsSystem *)v82;
}

// File Line: 210
// RVA: 0xD66040
void __fastcall hkpPhysicsSystem::addRigidBody(hkpPhysicsSystem *this, hkpRigidBody *rb)
{
  if ( rb )
  {
    hkReferencedObject::addReference(rb);
    if ( this->m_rigidBodies.m_size == (this->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_rigidBodies.m_data, 8);
    this->m_rigidBodies.m_data[this->m_rigidBodies.m_size++] = rb;
  }
}

// File Line: 219
// RVA: 0xD660B0
void __fastcall hkpPhysicsSystem::addPhantom(hkpPhysicsSystem *this, hkpPhantom *p)
{
  if ( p )
  {
    hkReferencedObject::addReference(p);
    if ( this->m_phantoms.m_size == (this->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_phantoms.m_data, 8);
    this->m_phantoms.m_data[this->m_phantoms.m_size++] = p;
  }
}

// File Line: 228
// RVA: 0xD66120
void __fastcall hkpPhysicsSystem::addConstraint(hkpPhysicsSystem *this, hkpConstraintInstance *c)
{
  if ( c )
  {
    hkReferencedObject::addReference(c);
    if ( this->m_constraints.m_size == (this->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_constraints.m_data, 8);
    this->m_constraints.m_data[this->m_constraints.m_size++] = c;
  }
}

// File Line: 237
// RVA: 0xD66190
void __fastcall hkpPhysicsSystem::addAction(hkpPhysicsSystem *this, hkpAction *a)
{
  if ( a )
  {
    hkReferencedObject::addReference(a);
    if ( this->m_actions.m_size == (this->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_actions.m_data, 8);
    this->m_actions.m_data[this->m_actions.m_size++] = a;
  }
}

// File Line: 246
// RVA: 0xD66200
void __fastcall hkpPhysicsSystem::removeRigidBody(hkpPhysicsSystem *this, int i)
{
  __int64 v4; // rsi
  __int64 v5; // rax

  v4 = i;
  hkReferencedObject::removeReference(this->m_rigidBodies.m_data[v4]);
  v5 = --this->m_rigidBodies.m_size;
  if ( (_DWORD)v5 != i )
    this->m_rigidBodies.m_data[v4] = this->m_rigidBodies.m_data[v5];
}

// File Line: 252
// RVA: 0xD66260
void __fastcall hkpPhysicsSystem::removePhantom(hkpPhysicsSystem *this, int i)
{
  __int64 v4; // rsi
  __int64 v5; // rax

  v4 = i;
  hkReferencedObject::removeReference(this->m_phantoms.m_data[v4]);
  v5 = --this->m_phantoms.m_size;
  if ( (_DWORD)v5 != i )
    this->m_phantoms.m_data[v4] = this->m_phantoms.m_data[v5];
}

// File Line: 258
// RVA: 0xD662C0
void __fastcall hkpPhysicsSystem::removeConstraint(hkpPhysicsSystem *this, int i)
{
  __int64 v4; // rsi
  __int64 v5; // rax

  v4 = i;
  hkReferencedObject::removeReference(this->m_constraints.m_data[v4]);
  v5 = --this->m_constraints.m_size;
  if ( (_DWORD)v5 != i )
    this->m_constraints.m_data[v4] = this->m_constraints.m_data[v5];
}

// File Line: 264
// RVA: 0xD66320
void __fastcall hkpPhysicsSystem::removeAction(hkpPhysicsSystem *this, int i)
{
  __int64 v4; // rsi
  __int64 v5; // rax

  v4 = i;
  hkReferencedObject::removeReference(this->m_actions.m_data[v4]);
  v5 = --this->m_actions.m_size;
  if ( (_DWORD)v5 != i )
    this->m_actions.m_data[v4] = this->m_actions.m_data[v5];
}

// File Line: 270
// RVA: 0xD66380
void __fastcall hkpPhysicsSystem::removeNullPhantoms(hkpPhysicsSystem *this)
{
  int v2; // r10d
  __int64 i; // r9
  hkpPhantom **m_data; // rax
  hkpPhantom **v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  hkpPhantom *v8; // rcx

  v2 = this->m_phantoms.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    m_data = this->m_phantoms.m_data;
    if ( !m_data[i] )
    {
      --this->m_phantoms.m_size;
      v5 = &m_data[i];
      v6 = 8 * (this->m_phantoms.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = v5[1];
          *v5++ = v8;
          --v7;
        }
        while ( v7 );
      }
    }
    --v2;
  }
}

// File Line: 282
// RVA: 0xD66500
void __fastcall tranformPhantom(hkpShapePhantom *phantom, hkTransformf *transformation)
{
  int v4; // eax
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm2
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  v4 = ((__int64 (__fastcall *)(hkpShapePhantom *))phantom->vfptr[3].__vecDelDtor)(phantom);
  if ( v4 )
  {
    if ( (unsigned int)(v4 - 1) <= 1 )
    {
      v5.m_quad = (__m128)phantom->m_motionState.m_transform.m_rotation.m_col1;
      transform.m_rotation.m_col0 = phantom->m_motionState.m_transform.m_rotation.m_col0;
      v6.m_quad = (__m128)phantom->m_motionState.m_transform.m_rotation.m_col2;
      transform.m_rotation.m_col1 = (hkVector4f)v5.m_quad;
      v7.m_quad = (__m128)phantom->m_motionState.m_transform.m_translation;
      transform.m_rotation.m_col2 = (hkVector4f)v6.m_quad;
      transform.m_translation = (hkVector4f)v7.m_quad;
      hkTransformf::setMulEq(&transform, transformation);
      hkpShapePhantom::setTransform(phantom, &transform);
    }
  }
  else
  {
    v8.m_quad = _mm_add_ps(
                  phantom->m_motionState.m_transform.m_rotation.m_col1.m_quad,
                  transformation->m_translation.m_quad);
    transform.m_rotation.m_col0.m_quad = _mm_add_ps(
                                           phantom->m_motionState.m_transform.m_rotation.m_col0.m_quad,
                                           transformation->m_translation.m_quad);
    transform.m_rotation.m_col1 = (hkVector4f)v8.m_quad;
    hkpAabbPhantom::setAabb((hkpAabbPhantom *)phantom, (hkAabb *)&transform);
  }
}

// File Line: 327
// RVA: 0xD663F0
void __fastcall hkpPhysicsSystem::transform(hkpPhysicsSystem *this, hkTransformf *transformation)
{
  int v2; // edi
  int v5; // r14d
  __int64 v6; // rsi
  hkVector4f v7; // xmm1
  hkpRigidBody **m_data; // rax
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  int v11; // esi
  __int64 v12; // r14
  __int64 v13; // rsi
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  v2 = 0;
  v5 = 0;
  if ( this->m_rigidBodies.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7.m_quad = (__m128)transformation->m_rotation.m_col1;
      m_data = this->m_rigidBodies.m_data;
      transform.m_rotation.m_col0 = transformation->m_rotation.m_col0;
      v9.m_quad = (__m128)transformation->m_rotation.m_col2;
      transform.m_rotation.m_col1 = (hkVector4f)v7.m_quad;
      v10.m_quad = (__m128)transformation->m_translation;
      transform.m_rotation.m_col2 = (hkVector4f)v9.m_quad;
      transform.m_translation = (hkVector4f)v10.m_quad;
      hkTransformf::setMulEq(&transform, &m_data[v6]->m_motion.m_motionState.m_transform);
      hkpRigidBody::setTransform(this->m_rigidBodies.m_data[v6], &transform);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_rigidBodies.m_size );
  }
  v11 = 0;
  if ( this->m_constraints.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkpConstraintInstance::transform(this->m_constraints.m_data[v12], transformation);
      ++v11;
      ++v12;
    }
    while ( v11 < this->m_constraints.m_size );
  }
  if ( this->m_phantoms.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      tranformPhantom(this->m_phantoms.m_data[v13], transformation);
      ++v2;
      ++v13;
    }
    while ( v2 < this->m_phantoms.m_size );
  }
}

