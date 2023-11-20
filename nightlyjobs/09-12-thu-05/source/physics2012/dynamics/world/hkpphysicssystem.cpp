// File Line: 38
// RVA: 0xD65530
void __fastcall hkpPhysicsSystem::hkpPhysicsSystem(hkpPhysicsSystem *this)
{
  hkpPhysicsSystem *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystem::`vftable;
  this->m_rigidBodies.m_data = 0i64;
  this->m_rigidBodies.m_size = 0;
  this->m_rigidBodies.m_capacityAndFlags = 2147483648;
  this->m_constraints.m_data = 0i64;
  this->m_constraints.m_size = 0;
  this->m_constraints.m_capacityAndFlags = 2147483648;
  this->m_actions.m_data = 0i64;
  this->m_actions.m_size = 0;
  this->m_actions.m_capacityAndFlags = 2147483648;
  v1 = this;
  this->m_phantoms.m_data = 0i64;
  this->m_phantoms.m_size = 0;
  this->m_phantoms.m_capacityAndFlags = 2147483648;
  hkStringPtr::hkStringPtr(&this->m_name, 0i64);
  v1->m_userData = 0i64;
  v1->m_active.m_bool = 1;
}

// File Line: 42
// RVA: 0xD65C90
void __fastcall hkpPhysicsSystem::removeAll(hkpPhysicsSystem *this)
{
  __int64 v1; // rsi
  hkpPhysicsSystem *v2; // rdi
  __int64 i; // rbx
  hkReferencedObject *v4; // rcx
  __int64 v5; // rsi
  __int64 j; // rbx
  hkReferencedObject *v7; // rcx
  __int64 v8; // rsi
  __int64 k; // rbx
  hkReferencedObject *v10; // rcx
  __int64 v11; // rsi
  __int64 l; // rbx
  hkReferencedObject *v13; // rcx

  v1 = this->m_rigidBodies.m_size;
  v2 = this;
  for ( i = 0i64; i < v1; ++i )
  {
    v4 = (hkReferencedObject *)&v2->m_rigidBodies.m_data[i]->vfptr;
    if ( v4 )
      hkReferencedObject::removeReference(v4);
  }
  v5 = v2->m_phantoms.m_size;
  v2->m_rigidBodies.m_size = 0;
  for ( j = 0i64; j < v5; ++j )
  {
    v7 = (hkReferencedObject *)&v2->m_phantoms.m_data[j]->vfptr;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  v8 = v2->m_constraints.m_size;
  v2->m_phantoms.m_size = 0;
  for ( k = 0i64; k < v8; ++k )
  {
    v10 = (hkReferencedObject *)&v2->m_constraints.m_data[k]->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v2->m_actions.m_size;
  v2->m_constraints.m_size = 0;
  for ( l = 0i64; l < v11; ++l )
  {
    v13 = (hkReferencedObject *)&v2->m_actions.m_data[l]->vfptr;
    if ( v13 )
      hkReferencedObject::removeReference(v13);
  }
  v2->m_actions.m_size = 0;
}

// File Line: 85
// RVA: 0xD655B0
void __fastcall hkpPhysicsSystem::~hkpPhysicsSystem(hkpPhysicsSystem *this)
{
  hkpPhysicsSystem *v1; // rbx
  int v2; // er8
  int v3; // er8
  int v4; // er8
  int v5; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPhysicsSystem::`vftable;
  hkpPhysicsSystem::removeAll(this);
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v2 = v1->m_phantoms.m_capacityAndFlags;
  v1->m_phantoms.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_phantoms.m_data,
      8 * v2);
  v1->m_phantoms.m_data = 0i64;
  v1->m_phantoms.m_capacityAndFlags = 2147483648;
  v3 = v1->m_actions.m_capacityAndFlags;
  v1->m_actions.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_actions.m_data,
      8 * v3);
  v1->m_actions.m_data = 0i64;
  v1->m_actions.m_capacityAndFlags = 2147483648;
  v4 = v1->m_constraints.m_capacityAndFlags;
  v1->m_constraints.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_constraints.m_data,
      8 * v4);
  v1->m_constraints.m_data = 0i64;
  v1->m_constraints.m_capacityAndFlags = 2147483648;
  v5 = v1->m_rigidBodies.m_capacityAndFlags;
  v1->m_rigidBodies.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_rigidBodies.m_data,
      8 * v5);
  v1->m_rigidBodies.m_data = 0i64;
  v1->m_rigidBodies.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 90
// RVA: 0xD65D90
void __fastcall hkpPhysicsSystem::copy(hkpPhysicsSystem *this, hkpPhysicsSystem *toCopy)
{
  hkpPhysicsSystem *v2; // rdi
  hkpPhysicsSystem *v3; // rbx
  __int64 v4; // rax
  hkpRigidBody **v5; // rcx
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
  int v24; // [rsp+30h] [rbp+8h]

  v2 = toCopy;
  v3 = this;
  if ( (this->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) < toCopy->m_rigidBodies.m_size )
  {
    if ( this->m_rigidBodies.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_rigidBodies.m_data,
        8 * this->m_rigidBodies.m_capacityAndFlags);
    v24 = 8 * v2->m_rigidBodies.m_size;
    v3->m_rigidBodies.m_data = (hkpRigidBody **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v24);
    v3->m_rigidBodies.m_capacityAndFlags = v24 / 8;
  }
  v4 = v2->m_rigidBodies.m_size;
  v5 = v3->m_rigidBodies.m_data;
  v3->m_rigidBodies.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_rigidBodies.m_data - (char *)v5);
    do
    {
      v8 = *(hkpRigidBody **)((char *)v5 + (_QWORD)v7);
      ++v5;
      *(v5 - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
  if ( (v3->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_phantoms.m_size )
  {
    if ( v3->m_phantoms.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_phantoms.m_data,
        8 * v3->m_phantoms.m_capacityAndFlags);
    v24 = 8 * v2->m_phantoms.m_size;
    v3->m_phantoms.m_data = (hkpPhantom **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                             (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                             &v24);
    v3->m_phantoms.m_capacityAndFlags = v24 / 8;
  }
  v9 = v2->m_phantoms.m_size;
  v10 = v3->m_phantoms.m_data;
  v3->m_phantoms.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v2->m_phantoms.m_data - (char *)v10);
    do
    {
      v13 = *(hkpPhantom **)((char *)v10 + (_QWORD)v12);
      ++v10;
      *(v10 - 1) = v13;
      --v11;
    }
    while ( v11 );
  }
  if ( (v3->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_constraints.m_size )
  {
    if ( v3->m_constraints.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_constraints.m_data,
        8 * v3->m_constraints.m_capacityAndFlags);
    v24 = 8 * v2->m_constraints.m_size;
    v3->m_constraints.m_data = (hkpConstraintInstance **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                           &v24);
    v3->m_constraints.m_capacityAndFlags = v24 / 8;
  }
  v14 = v2->m_constraints.m_size;
  v15 = v3->m_constraints.m_data;
  v3->m_constraints.m_size = v14;
  v16 = v14;
  if ( (signed int)v14 > 0 )
  {
    v17 = (char *)((char *)v2->m_constraints.m_data - (char *)v15);
    do
    {
      v18 = *(hkpConstraintInstance **)((char *)v15 + (_QWORD)v17);
      ++v15;
      *(v15 - 1) = v18;
      --v16;
    }
    while ( v16 );
  }
  if ( (v3->m_actions.m_capacityAndFlags & 0x3FFFFFFF) < v2->m_actions.m_size )
  {
    if ( v3->m_actions.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v3->m_actions.m_data,
        8 * v3->m_actions.m_capacityAndFlags);
    v24 = 8 * v2->m_actions.m_size;
    v3->m_actions.m_data = (hkpAction **)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                           (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                           &v24);
    v3->m_actions.m_capacityAndFlags = v24 / 8;
  }
  v19 = v2->m_actions.m_size;
  v20 = v3->m_actions.m_data;
  v3->m_actions.m_size = v19;
  v21 = v19;
  if ( (signed int)v19 > 0 )
  {
    v22 = (char *)((char *)v2->m_actions.m_data - (char *)v20);
    do
    {
      v23 = *(hkpAction **)((char *)v20 + (_QWORD)v22);
      ++v20;
      *(v20 - 1) = v23;
      --v21;
    }
    while ( v21 );
  }
  hkStringPtr::operator=(&v3->m_name, &v2->m_name);
  v3->m_userData = v2->m_userData;
  v3->m_active.m_bool = v2->m_active.m_bool;
}

// File Line: 102
// RVA: 0xD656D0
hkpPhysicsSystem *__fastcall hkpPhysicsSystem::clone(hkpPhysicsSystem *this, hkpPhysicsSystem::CloneConstraintMode cloneMode)
{
  hkpPhysicsSystem *v2; // r14
  hkpPhysicsSystem::CloneConstraintMode v3; // er12
  _QWORD **v4; // rax
  hkpPhysicsSystem *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rsi
  __int64 *v8; // r15
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // er9
  int v17; // ebx
  __int64 *v18; // r13
  int v19; // eax
  int v20; // eax
  int v21; // er9
  int v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // er9
  signed __int64 v26; // rcx
  int v27; // esi
  __int64 v28; // rdi
  __int64 v29; // rbx
  __int64 v30; // rax
  int v31; // esi
  __int64 v32; // r15
  __int64 v33; // rdi
  __int64 v34; // rbx
  __int64 v35; // rax
  int v36; // er15
  __int64 v37; // rsi
  hkpPhysicsSystem *v38; // rbx
  hkpConstraintInstance *v39; // r14
  signed __int64 v40; // rdx
  hkpRigidBody **v41; // rax
  hkpEntity *v42; // rdi
  hkpEntity *v43; // r8
  signed __int64 v44; // rdx
  signed __int64 v45; // rcx
  hkpRigidBody **v46; // rax
  hkpConstraintInstance::CloningMode v47; // er9
  __int64 v48; // rbx
  int v49; // er15
  __int64 *v50; // r12
  __int64 v51; // rsi
  hkpAction *v52; // rdi
  hkpRigidBody *v53; // r8
  __int64 v54; // rbx
  int v55; // er9
  __int64 v56; // r9
  __int64 v57; // r13
  signed __int64 v58; // rdx
  signed __int64 v59; // rcx
  hkpRigidBody **v60; // rax
  __int64 v61; // rbx
  int v62; // er9
  __int64 v63; // r9
  signed __int64 v64; // rdx
  signed __int64 v65; // rax
  hkpPhantom **v66; // rcx
  __int64 v67; // rbx
  signed __int64 v69; // [rsp+30h] [rbp-50h]
  _QWORD *v70; // [rsp+38h] [rbp-48h]
  int v71; // [rsp+40h] [rbp-40h]
  int v72; // [rsp+44h] [rbp-3Ch]
  _QWORD *array; // [rsp+48h] [rbp-38h]
  int v74; // [rsp+50h] [rbp-30h]
  int v75; // [rsp+54h] [rbp-2Ch]
  _QWORD *v76; // [rsp+58h] [rbp-28h]
  int v77; // [rsp+60h] [rbp-20h]
  int v78; // [rsp+64h] [rbp-1Ch]
  _QWORD *v79; // [rsp+68h] [rbp-18h]
  int v80; // [rsp+70h] [rbp-10h]
  int v81; // [rsp+74h] [rbp-Ch]
  hkpPhysicsSystem *v82; // [rsp+C0h] [rbp+40h]
  hkResult result; // [rsp+D0h] [rbp+50h]
  __int64 v84; // [rsp+D8h] [rbp+58h]

  v82 = this;
  v2 = this;
  v3 = cloneMode;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpPhysicsSystem *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 104i64);
  if ( v5 )
  {
    hkpPhysicsSystem::hkpPhysicsSystem(v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v84 = v7;
  hkStringPtr::operator=((hkStringPtr *)(v7 + 80), &v2->m_name);
  v8 = (__int64 *)(v7 + 16);
  *(_QWORD *)(v7 + 88) = v2->m_userData;
  *(_BYTE *)(v7 + 96) = v2->m_active.m_bool;
  v9 = v2->m_rigidBodies.m_size;
  v10 = *(_DWORD *)(v7 + 28) & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    v12 = v2->m_rigidBodies.m_size;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v7 + 16),
      v12,
      8);
  }
  *(_DWORD *)(v7 + 24) = v9;
  v13 = v2->m_phantoms.m_size;
  v14 = *(_DWORD *)(v7 + 76) & 0x3FFFFFFF;
  if ( v14 < v13 )
  {
    v15 = 2 * v14;
    v16 = v2->m_phantoms.m_size;
    if ( v13 < v15 )
      v16 = v15;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v7 + 64),
      v16,
      8);
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
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v7 + 32),
      v21,
      8);
  }
  *(_DWORD *)(v7 + 40) = v17;
  v22 = v2->m_actions.m_size;
  v69 = v7 + 48;
  v23 = *(_DWORD *)(v7 + 60) & 0x3FFFFFFF;
  if ( v23 < v22 )
  {
    v24 = 2 * v23;
    v25 = v2->m_actions.m_size;
    if ( v22 < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v7 + 48),
      v25,
      8);
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
      v30 = ((__int64 (*)(void))v2->m_rigidBodies.m_data[v28]->vfptr[3].__first_virtual_table_function__)();
      ++v27;
      ++v28;
      *(_QWORD *)(v29 + v28 * 8 - 8) = v30;
    }
    while ( v27 < v2->m_rigidBodies.m_size );
    v26 = 0i64;
  }
  v31 = 0;
  if ( v2->m_phantoms.m_size > 0 )
  {
    v32 = v84;
    v33 = 0i64;
    do
    {
      v34 = *(_QWORD *)(v32 + 64);
      v35 = ((__int64 (*)(void))v2->m_phantoms.m_data[v33]->vfptr[6].__vecDelDtor)();
      ++v31;
      ++v33;
      *(_QWORD *)(v34 + v33 * 8 - 8) = v35;
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
      v38 = v82;
      v39 = v2->m_constraints.m_data[v37];
      v40 = v82->m_rigidBodies.m_size;
      if ( v40 <= 0 )
      {
LABEL_34:
        v26 = -1i64;
      }
      else
      {
        v41 = v82->m_rigidBodies.m_data;
        while ( *v41 != (hkpRigidBody *)v39->m_entities[0] )
        {
          ++v26;
          ++v41;
          if ( v26 >= v40 )
            goto LABEL_34;
        }
      }
      v42 = *(hkpEntity **)(*(_QWORD *)(v84 + 16) + 8 * v26);
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
          while ( *v46 != (hkpRigidBody *)v39->m_entities[1] )
          {
            ++v45;
            ++v46;
            if ( v45 >= v44 )
              goto LABEL_41;
          }
        }
        v43 = *(hkpEntity **)(*(_QWORD *)(v84 + 16) + 8 * v45);
      }
      if ( v3 == CLONE_SHALLOW_IF_NOT_CONSTRAINED_TO_WORLD )
        break;
      if ( v3 == 1 )
      {
        v47 = 1;
        goto LABEL_49;
      }
      if ( v3 == 2 )
      {
        v47 = 2;
        goto LABEL_49;
      }
LABEL_50:
      v2 = v82;
      ++v36;
      ++v37;
      v26 = 0i64;
      if ( v36 >= v82->m_constraints.m_size )
        goto LABEL_51;
    }
    v47 = 0;
LABEL_49:
    v48 = *v18;
    *(_QWORD *)(v48 + v37 * 8) = hkpConstraintInstance::clone(v39, v42, v43, v47);
    goto LABEL_50;
  }
LABEL_51:
  v49 = 0;
  if ( v2->m_actions.m_size > 0 )
  {
    v50 = (__int64 *)v69;
    v51 = 0i64;
    do
    {
      v52 = v2->m_actions.m_data[v51];
      if ( v52 )
      {
        v79 = 0i64;
        v80 = 0;
        v81 = 2147483648;
        v52->vfptr[2].__vecDelDtor((hkBaseObject *)&v52->vfptr, (unsigned int)&v79);
        v54 = v80;
        array = 0i64;
        v74 = 0;
        v75 = 2147483648;
        if ( v80 <= 0 )
        {
          LODWORD(v82) = 0;
        }
        else
        {
          v55 = v80;
          if ( v80 < 0 )
            v55 = 0;
          hkArrayUtil::_reserve(
            (hkResult *)&v82,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &array,
            v55,
            8);
        }
        v56 = 0i64;
        v57 = v84;
        v74 = v54;
        if ( (signed int)v54 > 0 )
        {
          do
          {
            v58 = v2->m_rigidBodies.m_size;
            v59 = 0i64;
            v53 = (hkpRigidBody *)v79[v56];
            if ( v58 <= 0 )
            {
LABEL_65:
              v59 = -1i64;
            }
            else
            {
              v60 = v2->m_rigidBodies.m_data;
              while ( *v60 != v53 )
              {
                ++v59;
                ++v60;
                if ( v59 >= v58 )
                  goto LABEL_65;
              }
            }
            array[++v56 - 1] = *(_QWORD *)(*(_QWORD *)(v57 + 16) + 8 * v59);
          }
          while ( v56 < v54 );
        }
        v76 = 0i64;
        v77 = 0;
        v78 = 2147483648;
        ((void (__fastcall *)(hkpAction *, _QWORD **, hkpRigidBody *, __int64))v52->vfptr[2].__first_virtual_table_function__)(
          v52,
          &v76,
          v53,
          v56);
        v61 = v77;
        v70 = 0i64;
        v71 = 0;
        v72 = 2147483648;
        if ( v77 <= 0 )
        {
          result.m_enum = 0;
        }
        else
        {
          v62 = v77;
          if ( v77 < 0 )
            v62 = 0;
          hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v70, v62, 8);
        }
        v71 = v61;
        v63 = 0i64;
        if ( (signed int)v61 > 0 )
        {
          do
          {
            v64 = v2->m_phantoms.m_size;
            v65 = 0i64;
            if ( v64 <= 0 )
            {
LABEL_77:
              v65 = -1i64;
            }
            else
            {
              v66 = v2->m_phantoms.m_data;
              while ( *v66 != (hkpPhantom *)v76[v63] )
              {
                ++v65;
                ++v66;
                if ( v65 >= v64 )
                  goto LABEL_77;
              }
            }
            v70[++v63 - 1] = *(_QWORD *)(*(_QWORD *)(v57 + 64) + 8 * v65);
          }
          while ( v63 < v61 );
          v50 = (__int64 *)v69;
        }
        v67 = *v50;
        *(_QWORD *)(v67 + v51 * 8) = ((__int64 (__fastcall *)(hkpAction *, _QWORD **, _QWORD **, __int64))v52->vfptr[3].__first_virtual_table_function__)(
                                       v52,
                                       &array,
                                       &v70,
                                       v63);
        v71 = 0;
        if ( v72 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v70,
            8 * v72);
        v70 = 0i64;
        v72 = 2147483648;
        v77 = 0;
        if ( v78 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v76,
            8 * v78);
        v76 = 0i64;
        v78 = 2147483648;
        v74 = 0;
        if ( v75 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            8 * v75);
        array = 0i64;
        v75 = 2147483648;
        v80 = 0;
        if ( v81 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v79,
            8 * v81);
        v79 = 0i64;
        v81 = 2147483648;
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
  return (hkpPhysicsSystem *)v84;
}

// File Line: 210
// RVA: 0xD66040
void __fastcall hkpPhysicsSystem::addRigidBody(hkpPhysicsSystem *this, hkpRigidBody *rb)
{
  hkpPhysicsSystem *v2; // rbx
  hkpRigidBody *v3; // rdi

  if ( rb )
  {
    v2 = this;
    v3 = rb;
    hkReferencedObject::addReference((hkReferencedObject *)&rb->vfptr);
    if ( v2->m_rigidBodies.m_size == (v2->m_rigidBodies.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_rigidBodies, 8);
    v2->m_rigidBodies.m_data[v2->m_rigidBodies.m_size++] = v3;
  }
}

// File Line: 219
// RVA: 0xD660B0
void __fastcall hkpPhysicsSystem::addPhantom(hkpPhysicsSystem *this, hkpPhantom *p)
{
  hkpPhysicsSystem *v2; // rbx
  hkpPhantom *v3; // rdi

  if ( p )
  {
    v2 = this;
    v3 = p;
    hkReferencedObject::addReference((hkReferencedObject *)&p->vfptr);
    if ( v2->m_phantoms.m_size == (v2->m_phantoms.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_phantoms, 8);
    v2->m_phantoms.m_data[v2->m_phantoms.m_size++] = v3;
  }
}

// File Line: 228
// RVA: 0xD66120
void __fastcall hkpPhysicsSystem::addConstraint(hkpPhysicsSystem *this, hkpConstraintInstance *c)
{
  hkpPhysicsSystem *v2; // rbx
  hkpConstraintInstance *v3; // rdi

  if ( c )
  {
    v2 = this;
    v3 = c;
    hkReferencedObject::addReference((hkReferencedObject *)&c->vfptr);
    if ( v2->m_constraints.m_size == (v2->m_constraints.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_constraints, 8);
    v2->m_constraints.m_data[v2->m_constraints.m_size++] = v3;
  }
}

// File Line: 237
// RVA: 0xD66190
void __fastcall hkpPhysicsSystem::addAction(hkpPhysicsSystem *this, hkpAction *a)
{
  hkpPhysicsSystem *v2; // rbx
  hkpAction *v3; // rdi

  if ( a )
  {
    v2 = this;
    v3 = a;
    hkReferencedObject::addReference((hkReferencedObject *)&a->vfptr);
    if ( v2->m_actions.m_size == (v2->m_actions.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_actions, 8);
    v2->m_actions.m_data[v2->m_actions.m_size++] = v3;
  }
}

// File Line: 246
// RVA: 0xD66200
void __fastcall hkpPhysicsSystem::removeRigidBody(hkpPhysicsSystem *this, int i)
{
  hkpPhysicsSystem *v2; // rdi
  int v3; // ebx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = this;
  v3 = i;
  v4 = i;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_rigidBodies.m_data[i]->vfptr);
  v5 = --v2->m_rigidBodies.m_size;
  if ( (_DWORD)v5 != v3 )
    v2->m_rigidBodies.m_data[v4] = v2->m_rigidBodies.m_data[v5];
}

// File Line: 252
// RVA: 0xD66260
void __fastcall hkpPhysicsSystem::removePhantom(hkpPhysicsSystem *this, int i)
{
  hkpPhysicsSystem *v2; // rdi
  int v3; // ebx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = this;
  v3 = i;
  v4 = i;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_phantoms.m_data[i]->vfptr);
  v5 = --v2->m_phantoms.m_size;
  if ( (_DWORD)v5 != v3 )
    v2->m_phantoms.m_data[v4] = v2->m_phantoms.m_data[v5];
}

// File Line: 258
// RVA: 0xD662C0
void __fastcall hkpPhysicsSystem::removeConstraint(hkpPhysicsSystem *this, int i)
{
  hkpPhysicsSystem *v2; // rdi
  int v3; // ebx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = this;
  v3 = i;
  v4 = i;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_constraints.m_data[i]->vfptr);
  v5 = --v2->m_constraints.m_size;
  if ( (_DWORD)v5 != v3 )
    v2->m_constraints.m_data[v4] = v2->m_constraints.m_data[v5];
}

// File Line: 264
// RVA: 0xD66320
void __fastcall hkpPhysicsSystem::removeAction(hkpPhysicsSystem *this, int i)
{
  hkpPhysicsSystem *v2; // rdi
  int v3; // ebx
  signed __int64 v4; // rsi
  __int64 v5; // rax

  v2 = this;
  v3 = i;
  v4 = i;
  hkReferencedObject::removeReference((hkReferencedObject *)&this->m_actions.m_data[i]->vfptr);
  v5 = --v2->m_actions.m_size;
  if ( (_DWORD)v5 != v3 )
    v2->m_actions.m_data[v4] = v2->m_actions.m_data[v5];
}

// File Line: 270
// RVA: 0xD66380
void __fastcall hkpPhysicsSystem::removeNullPhantoms(hkpPhysicsSystem *this)
{
  hkpPhysicsSystem *v1; // r11
  int v2; // er10
  __int64 i; // r9
  hkpPhantom **v4; // rax
  signed __int64 v5; // rax
  int v6; // ecx
  __int64 v7; // rdx
  __int64 v8; // rcx

  v1 = this;
  v2 = this->m_phantoms.m_size - 1;
  for ( i = v2; i >= 0; --i )
  {
    v4 = v1->m_phantoms.m_data;
    if ( !v4[i] )
    {
      --v1->m_phantoms.m_size;
      v5 = (signed __int64)&v4[i];
      v6 = 8 * (v1->m_phantoms.m_size - v2);
      if ( v6 > 0 )
      {
        v7 = ((unsigned int)(v6 - 1) >> 3) + 1;
        do
        {
          v8 = *(_QWORD *)(v5 + 8);
          v5 += 8i64;
          *(_QWORD *)(v5 - 8) = v8;
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
void __fastcall tranformPhantom(hkpPhantom *phantom, hkTransformf *transformation)
{
  hkTransformf *v2; // rdi
  hkpPhantom *v3; // rbx
  int v4; // eax
  hkVector4f v5; // xmm1
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm2
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v2 = transformation;
  v3 = phantom;
  v4 = ((__int64 (*)(void))phantom->vfptr[3].__vecDelDtor)();
  if ( v4 )
  {
    if ( (unsigned int)(v4 - 1) <= 1 )
    {
      v5.m_quad = *(__m128 *)&v3[1].m_userData;
      transform.m_rotation.m_col0 = *(hkVector4f *)&v3[1].m_memSizeAndFlags;
      v6.m_quad = *(__m128 *)&v3[1].m_collidable.m_shapeKey;
      transform.m_rotation.m_col1 = (hkVector4f)v5.m_quad;
      v7.m_quad = *(__m128 *)&v3[1].m_collidable.m_parent;
      transform.m_rotation.m_col2 = (hkVector4f)v6.m_quad;
      transform.m_translation = (hkVector4f)v7.m_quad;
      hkTransformf::setMulEq(&transform, v2);
      hkpShapePhantom::setTransform((hkpShapePhantom *)v3, &transform);
    }
  }
  else
  {
    v8.m_quad = _mm_add_ps(*(__m128 *)&v3[1].m_userData, v2->m_translation.m_quad);
    transform.m_rotation.m_col0.m_quad = _mm_add_ps(*(__m128 *)&v3[1].m_memSizeAndFlags, v2->m_translation.m_quad);
    transform.m_rotation.m_col1 = (hkVector4f)v8.m_quad;
    hkpAabbPhantom::setAabb((hkpAabbPhantom *)v3, (hkAabb *)&transform);
  }
}

// File Line: 327
// RVA: 0xD663F0
void __fastcall hkpPhysicsSystem::transform(hkpPhysicsSystem *this, hkTransformf *transformation)
{
  int v2; // edi
  hkTransformf *v3; // rbp
  hkpPhysicsSystem *v4; // rbx
  int v5; // er14
  __int64 v6; // rsi
  hkVector4f v7; // xmm1
  hkpRigidBody **v8; // rax
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  int v11; // esi
  __int64 v12; // r14
  __int64 v13; // rsi
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v2 = 0;
  v3 = transformation;
  v4 = this;
  v5 = 0;
  if ( this->m_rigidBodies.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7.m_quad = (__m128)v3->m_rotation.m_col1;
      v8 = v4->m_rigidBodies.m_data;
      transform.m_rotation.m_col0 = v3->m_rotation.m_col0;
      v9.m_quad = (__m128)v3->m_rotation.m_col2;
      transform.m_rotation.m_col1 = (hkVector4f)v7.m_quad;
      v10.m_quad = (__m128)v3->m_translation;
      transform.m_rotation.m_col2 = (hkVector4f)v9.m_quad;
      transform.m_translation = (hkVector4f)v10.m_quad;
      hkTransformf::setMulEq(&transform, &v8[v6]->m_motion.m_motionState.m_transform);
      hkpRigidBody::setTransform(v4->m_rigidBodies.m_data[v6], &transform);
      ++v5;
      ++v6;
    }
    while ( v5 < v4->m_rigidBodies.m_size );
  }
  v11 = 0;
  if ( v4->m_constraints.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      hkpConstraintInstance::transform(v4->m_constraints.m_data[v12], v3);
      ++v11;
      ++v12;
    }
    while ( v11 < v4->m_constraints.m_size );
  }
  if ( v4->m_phantoms.m_size > 0 )
  {
    v13 = 0i64;
    do
    {
      tranformPhantom(v4->m_phantoms.m_data[v13], v3);
      ++v2;
      ++v13;
    }
    while ( v2 < v4->m_phantoms.m_size );
  }
}

