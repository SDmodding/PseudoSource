// File Line: 36
// RVA: 0xD89310
void __fastcall hkpWorldOperationQueue::hkpWorldOperationQueue(hkpWorldOperationQueue *this, hkpWorld *world)
{
  this->m_pending.m_capacityAndFlags = 0x80000000;
  this->m_pending.m_data = 0i64;
  this->m_pending.m_size = 0;
  this->m_islandMerges.m_data = 0i64;
  this->m_islandMerges.m_size = 0;
  this->m_islandMerges.m_capacityAndFlags = 0x80000000;
  this->m_pendingBodyOperations.m_data = 0i64;
  this->m_pendingBodyOperations.m_size = 0;
  this->m_pendingBodyOperations.m_capacityAndFlags = 0x80000000;
  this->m_world = world;
}

// File Line: 41
// RVA: 0xD89350
void __fastcall hkpWorldOperationQueue::~hkpWorldOperationQueue(hkpWorldOperationQueue *this)
{
  int m_capacityAndFlags; // eax
  int v3; // r8d
  int v4; // r8d

  m_capacityAndFlags = this->m_pendingBodyOperations.m_capacityAndFlags;
  this->m_pendingBodyOperations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pendingBodyOperations.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_pendingBodyOperations.m_data = 0i64;
  this->m_pendingBodyOperations.m_capacityAndFlags = 0x80000000;
  v3 = this->m_islandMerges.m_capacityAndFlags;
  this->m_islandMerges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_islandMerges.m_data,
      v3 << 6);
  this->m_islandMerges.m_data = 0i64;
  this->m_islandMerges.m_capacityAndFlags = 0x80000000;
  v4 = this->m_pending.m_capacityAndFlags;
  this->m_pending.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pending.m_data,
      v4 << 6);
  this->m_pending.m_capacityAndFlags = 0x80000000;
  this->m_pending.m_data = 0i64;
}

// File Line: 44
// RVA: 0xD8A3A0
// attributes: thunk
void __fastcall addReferenceTo(hkReferencedObject *obj)
{
  hkReferencedObject::addReference(obj);
}

// File Line: 45
// RVA: 0xD8A3B0
// attributes: thunk
void __fastcall removeReferenceFrom(hkReferencedObject *obj)
{
  hkReferencedObject::removeReference(obj);
}

// File Line: 48
// RVA: 0xD89420
void __fastcall hkpWorldOperationQueue::queueOperation(
        hkpWorldOperationQueue *this,
        hkWorldOperation::BaseOperation *operation)
{
  hkWorldOperation::BiggestOperation *v4; // rax
  hkWorldOperation::BaseOperation *v5; // rcx
  __int64 v6; // rdx
  hkWorldOperation::BiggestOperation *v7; // rdi
  int v8; // eax
  hkReferencedObject *v9; // rcx
  int v10; // ebx
  _QWORD **Value; // rax
  void *v12; // rax
  hkReferencedObject **v13; // rbx
  hkReferencedObject **v14; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // ebx
  _QWORD **v17; // rax
  void *v18; // rax
  hkReferencedObject **v19; // rbx
  hkReferencedObject **v20; // rdi
  hkReferencedObject *v21; // rcx
  hkWorldOperation::BiggestOperation *v22; // rcx
  int v23; // ebx
  _QWORD **v24; // rax
  void *v25; // rax
  hkReferencedObject **v26; // rbx
  hkReferencedObject **v27; // rdi
  hkReferencedObject *v28; // rcx
  int v29; // ebx
  _QWORD **v30; // rax
  void *v31; // rax
  hkReferencedObject **v32; // rbx
  hkReferencedObject **v33; // rdi
  hkReferencedObject *v34; // rcx
  _QWORD **v35; // rax
  _OWORD *v36; // rax
  _OWORD *v37; // rcx
  int v38; // ebx
  _QWORD **v39; // rax
  void *v40; // rax
  hkReferencedObject **v41; // rbx
  hkReferencedObject **v42; // rdi
  hkReferencedObject *v43; // rcx

  hkReferencedObject::lockAll();
  if ( this->m_pending.m_size == (this->m_pending.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_pending.m_data, 64);
  v4 = &this->m_pending.m_data[(__int64)this->m_pending.m_size];
  if ( v4 )
    v4->m_type.m_storage = 0;
  v5 = operation;
  v6 = 16i64;
  v7 = &this->m_pending.m_data[(__int64)this->m_pending.m_size++];
  ++this->m_world->m_pendingOperationsCount;
  do
  {
    v8 = *(_DWORD *)&v5->m_type.m_storage;
    v5 += 4;
    *(_DWORD *)&v5[(char *)v7 - (char *)operation - 4].m_type.m_storage = v8;
    --v6;
  }
  while ( v6 );
  switch ( v7->m_type.m_storage )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x13:
    case 0x15:
    case 0x17:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x26:
      v9 = (hkReferencedObject *)v7->dummy[0];
      goto LABEL_33;
    case 5:
    case 0x14:
    case 0x25:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      v9 = (hkReferencedObject *)v7->dummy[1];
LABEL_33:
      hkReferencedObject::addReference(v9);
      break;
    case 7:
      v10 = LOWORD(v7->dummy[1]);
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                      Value[11],
                      (unsigned int)(8 * v10));
      v7->dummy[0] = (unsigned __int64)v12;
      hkString::memCpy(
        v12,
        *(const void **)&operation[8].m_type.m_storage,
        8 * *(unsigned __int16 *)&operation[16].m_type.m_storage);
      v13 = (hkReferencedObject **)v7->dummy[0];
      v14 = &v13[LOWORD(v7->dummy[1])];
      while ( v13 < v14 )
      {
        v15 = *v13++;
        hkReferencedObject::addReference(v15);
      }
      break;
    case 8:
      v16 = LOWORD(v7->dummy[1]);
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v17[11] + 8i64))(v17[11], (unsigned int)(8 * v16));
      v7->dummy[0] = (unsigned __int64)v18;
      hkString::memCpy(
        v18,
        *(const void **)&operation[8].m_type.m_storage,
        8 * *(unsigned __int16 *)&operation[16].m_type.m_storage);
      v19 = (hkReferencedObject **)v7->dummy[0];
      v20 = &v19[LOWORD(v7->dummy[1])];
      while ( v19 < v20 )
      {
        v21 = *v19++;
        hkReferencedObject::addReference(v21);
      }
      break;
    case 0xD:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[1]);
      if ( this->m_islandMerges.m_size == (this->m_islandMerges.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_islandMerges.m_data, 64);
      v22 = &this->m_islandMerges.m_data[(__int64)this->m_islandMerges.m_size];
      if ( v22 )
      {
        *(_QWORD *)&v22->m_type.m_storage = *(_QWORD *)&v7->m_type.m_storage;
        v22->dummy[0] = v7->dummy[0];
        v22->dummy[1] = v7->dummy[1];
        v22->dummy[2] = v7->dummy[2];
        v22->dummy[3] = v7->dummy[3];
        v22->dummy[4] = v7->dummy[4];
        v22->dummy[5] = v7->dummy[5];
        v22->dummy[6] = v7->dummy[6];
      }
      ++this->m_islandMerges.m_size;
      --this->m_pending.m_size;
      break;
    case 0x10:
      v23 = LOWORD(v7->dummy[1]);
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v24[11] + 8i64))(v24[11], (unsigned int)(8 * v23));
      v7->dummy[0] = (unsigned __int64)v25;
      hkString::memCpy(
        v25,
        *(const void **)&operation[8].m_type.m_storage,
        8 * *(unsigned __int16 *)&operation[16].m_type.m_storage);
      v26 = (hkReferencedObject **)v7->dummy[0];
      v27 = &v26[LOWORD(v7->dummy[1])];
      while ( v26 < v27 )
      {
        v28 = *v26++;
        hkReferencedObject::addReference(v28);
      }
      break;
    case 0x11:
      v29 = LOWORD(v7->dummy[1]);
      v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v31 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v30[11] + 8i64))(v30[11], (unsigned int)(8 * v29));
      v7->dummy[0] = (unsigned __int64)v31;
      hkString::memCpy(
        v31,
        *(const void **)&operation[8].m_type.m_storage,
        8 * *(unsigned __int16 *)&operation[16].m_type.m_storage);
      v32 = (hkReferencedObject **)v7->dummy[0];
      v33 = &v32[LOWORD(v7->dummy[1])];
      while ( v32 < v33 )
      {
        v34 = *v32++;
        hkReferencedObject::addReference(v34);
      }
      break;
    case 0x12:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v36 = (_OWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v35[11] + 8i64))(v35[11], 32i64);
      v7->dummy[1] = (unsigned __int64)v36;
      v37 = *(_OWORD **)&operation[16].m_type.m_storage;
      *v36 = *v37;
      v36[1] = v37[1];
      break;
    case 0x18:
      v38 = LOWORD(v7->dummy[1]);
      v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v40 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v39[11] + 8i64))(v39[11], (unsigned int)(8 * v38));
      v7->dummy[0] = (unsigned __int64)v40;
      hkString::memCpy(
        v40,
        *(const void **)&operation[8].m_type.m_storage,
        8 * *(unsigned __int16 *)&operation[16].m_type.m_storage);
      v41 = (hkReferencedObject **)v7->dummy[0];
      v42 = &v41[LOWORD(v7->dummy[1])];
      while ( v41 < v42 )
      {
        v43 = *v41++;
        hkReferencedObject::addReference(v43);
      }
      break;
    case 0x1F:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      --this->m_pending.m_size;
      --this->m_world->m_pendingOperationsCount;
      break;
    case 0x20:
      hkReferencedObject::removeReference((hkReferencedObject *)v7->dummy[0]);
      --this->m_pending.m_size;
      --this->m_world->m_pendingOperationsCount;
      break;
    default:
      break;
  }
  hkReferencedObject::unlockAll();
}

// File Line: 394
// RVA: 0xD8A150
void __fastcall hkpWorldOperationQueue::queueBodyOperation(
        hkpWorldOperationQueue *this,
        hkpEntity *entity,
        hkpBodyOperation *operation,
        int priority,
        hkpBodyOperation::ExecutionState hint)
{
  __int64 m_size; // rdx
  hkpBodyOperationEntry *v10; // r8

  hkReferencedObject::lockAll();
  ++this->m_world->m_pendingBodyOperationsCount;
  if ( this->m_pendingBodyOperations.m_size == (this->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_pendingBodyOperations.m_data,
      24);
  m_size = this->m_pendingBodyOperations.m_size;
  v10 = &this->m_pendingBodyOperations.m_data[m_size];
  this->m_pendingBodyOperations.m_size = m_size + 1;
  v10->m_entity = entity;
  v10->m_operation = operation;
  v10->m_priority = priority;
  v10->m_hint = hint;
  hkReferencedObject::addReference(entity);
  hkReferencedObject::addReference(operation);
  hkReferencedObject::unlockAll();
}

// File Line: 413
// RVA: 0xD8A3C0
bool __fastcall hkpWorldBodyOperationQueueSortCmp(hkpBodyOperationEntry *a, hkpBodyOperationEntry *b)
{
  if ( a->m_entity == b->m_entity )
    return a->m_priority > (unsigned __int64)b->m_priority;
  else
    return a->m_entity->m_uid < b->m_entity->m_uid;
}

// File Line: 425
// RVA: 0xD8A200
void __fastcall hkpWorldOperationQueue::executeAllPendingBodyOperations(hkpWorldOperationQueue *this)
{
  int v2; // r9d
  __int64 m_size; // rdi
  hkRelocationInfo::Import *m_data; // rbp
  hkRelocationInfo::Import *v5; // rbx
  __int64 v6; // rsi
  hkReferencedObject **v7; // rbx
  __int64 v8; // rsi
  hkReferencedObject *v9; // rdi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v10; // [rsp+30h] [rbp-38h] BYREF
  __int16 v11; // [rsp+70h] [rbp+8h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  for ( ; this->m_pendingBodyOperations.m_size; v10.m_capacityAndFlags = 0x80000000 )
  {
    v10.m_data = 0i64;
    v10.m_size = 0;
    v10.m_capacityAndFlags = 0x80000000;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      &v10,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_pendingBodyOperations);
    this->m_world->m_pendingBodyOperationsCount = 0;
    if ( (this->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFFu) >= 0x10 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v2 = 16;
      if ( 2 * (this->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFF) > 16 )
        v2 = 2 * (this->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_pendingBodyOperations.m_data,
        v2,
        24);
    }
    m_size = (unsigned int)v10.m_size;
    m_data = v10.m_data;
    if ( v10.m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpBodyOperationEntry,bool (*)(hkpBodyOperationEntry const &,hkpBodyOperationEntry const &)>(
        (hkpBodyOperationEntry *)v10.m_data,
        0,
        v10.m_size - 1,
        hkpWorldBodyOperationQueueSortCmp);
    if ( (int)m_size > 0 )
    {
      v5 = m_data;
      v6 = m_size;
      do
      {
        v11 = 256;
        (*(void (__fastcall **)(const char *, _QWORD, __int16 *))(*(_QWORD *)v5->m_identifier + 24i64))(
          v5->m_identifier,
          *(_QWORD *)&v5->m_fromOffset,
          &v11);
        v5 = (hkRelocationInfo::Import *)((char *)v5 + 24);
        --v6;
      }
      while ( v6 );
    }
    hkReferencedObject::lockAll();
    if ( (int)m_size > 0 )
    {
      v7 = (hkReferencedObject **)m_data;
      v8 = m_size;
      do
      {
        v9 = v7[1];
        hkReferencedObject::removeReferenceLockUnchecked(*v7);
        hkReferencedObject::removeReferenceLockUnchecked(v9);
        v7 += 3;
        --v8;
      }
      while ( v8 );
    }
    hkReferencedObject::unlockAll();
    v10.m_size = 0;
    if ( v10.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_data,
        24 * (v10.m_capacityAndFlags & 0x3FFFFFFF));
    v10.m_data = 0i64;
  }
}

// File Line: 466
// RVA: 0xD8A400
hkBool *__fastcall islandLess(
        hkBool *result,
        hkWorldOperation::BiggestOperation *a,
        hkWorldOperation::BiggestOperation *b)
{
  unsigned int v4; // ecx
  unsigned int v5; // eax

  v4 = *(unsigned __int16 *)(*(_QWORD *)(a->dummy[0] + 296) + 44i64);
  v5 = *(unsigned __int16 *)(*(_QWORD *)(b->dummy[0] + 296) + 44i64);
  if ( v4 < v5
    || v4 == v5
    && *(_WORD *)(*(_QWORD *)(a->dummy[1] + 296) + 44i64) < *(_WORD *)(*(_QWORD *)(b->dummy[1] + 296) + 44i64) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 494
// RVA: 0xD898A0
void __fastcall hkpWorldOperationQueue::executeAllPending(hkpWorldOperationQueue *this)
{
  hkpWorldOperationQueue *v2; // r10
  int m_size; // r8d
  hkWorldOperation::BiggestOperation *m_data; // rax
  int v5; // edx
  __int64 v6; // rcx
  __m128i v7; // xmm2
  __int128 v8; // xmm1
  hkpEntity *v9; // rbx
  __int128 v10; // xmm0
  hkpEntity *v11; // xmm2_8
  hkpWorld *m_world; // rax
  hkpWorld *v13; // rcx
  __int64 v14; // rsi
  const char **p_m_identifier; // rbx
  hkpWorld *v16; // rcx
  hkpEntity *v17; // rcx
  int v18; // edi
  hkpEntity *v19; // rsi
  _QWORD **Value; // rax
  hkpConstraintInstance *v21; // rdx
  hkpWorld *v22; // rcx
  hkpEntity *v23; // rax
  hkpEntity *v24; // rcx
  int v25; // edx
  void *v26; // r10
  __int64 v27; // rcx
  hkpWorld *v28; // rcx
  hkpWorld *v29; // rcx
  hkpEntity *v30; // rdi
  _QWORD **v31; // rax
  hkpWorld *v32; // rcx
  hkpWorld *v33; // rcx
  hkpEntity *v34; // r8
  hkpWorld *v35; // rcx
  const char *v36; // rdi
  _QWORD **v37; // rax
  hkpEntity *v38; // rdi
  hkpEntity *v39; // rcx
  hkpEntity *v40; // rdi
  hkpEntity *v41; // rcx
  hkpEntity *v42; // rdi
  hkpEntity *v43; // rcx
  const char *v44; // rdi
  _QWORD **v45; // rax
  hkpEntity *v46; // rdi
  hkpEntity *v47; // rcx
  __int64 v48; // r11
  const char *v49; // rdx
  char *v50; // rcx
  __int64 v51; // r8
  __int64 v52; // rax
  hkpEntity *v53; // rdi
  unsigned __int64 v54; // rsi
  hkReferencedObject *vfptr; // rcx
  void *v56; // [rsp+28h] [rbp-69h] BYREF
  int v57; // [rsp+30h] [rbp-61h]
  int v58; // [rsp+34h] [rbp-5Dh]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v59; // [rsp+38h] [rbp-59h] BYREF
  __m128 v60; // [rsp+48h] [rbp-49h] BYREF
  __m128 v61; // [rsp+58h] [rbp-39h] BYREF
  __m128 v62; // [rsp+68h] [rbp-29h] BYREF
  __m128 v63[2]; // [rsp+78h] [rbp-19h] BYREF
  hkpEntity *entityB[2]; // [rsp+98h] [rbp+7h]
  __int128 v65; // [rsp+A8h] [rbp+17h]
  __int128 v66; // [rsp+B8h] [rbp+27h]
  hkpWorldOperationQueue *retaddr; // [rsp+F8h] [rbp+67h]
  hkpWorldOperationQueue *result; // [rsp+100h] [rbp+6Fh] BYREF
  hkBool v69; // [rsp+108h] [rbp+77h] BYREF
  __int64 v70; // [rsp+110h] [rbp+7Fh]

  result = this;
  hkReferencedObject::lockAll();
  v59.m_data = 0i64;
  v59.m_size = 0;
  v59.m_capacityAndFlags = 0x80000000;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v59,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)this);
  v2 = retaddr;
  ++retaddr->m_world->m_pendingOperationQueueCount;
  m_size = retaddr->m_islandMerges.m_size;
  if ( m_size )
  {
    if ( m_size > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkWorldOperation::BiggestOperation,hkBool (*)(hkWorldOperation::BiggestOperation const &,hkWorldOperation::BiggestOperation const &)>(
        retaddr->m_islandMerges.m_data,
        0,
        m_size - 1,
        islandLess);
      v2 = retaddr;
    }
    if ( v2->m_islandMerges.m_size )
    {
      do
      {
        m_data = v2->m_islandMerges.m_data;
        v5 = v2->m_islandMerges.m_size;
        v6 = (__int64)v5 << 6;
        v7 = *(__m128i *)(&m_data[-1].m_type.m_storage + v6);
        v8 = *(_OWORD *)((char *)m_data + v6 - 32);
        *(_OWORD *)entityB = *(_OWORD *)((char *)m_data + v6 - 48);
        v9 = entityB[0];
        v65 = v8;
        v10 = *(_OWORD *)((char *)m_data + v6 - 16);
        v11 = (hkpEntity *)_mm_srli_si128(v7, 8).m128i_u64[0];
        v2->m_islandMerges.m_size = v5 - 1;
        m_world = v2->m_world;
        v66 = v10;
        v13 = v11->m_world;
        if ( v13 == m_world
          && v9->m_world == m_world
          && v11->m_motion.m_type.m_storage != 5
          && v9->m_motion.m_type.m_storage != 5
          && v11->m_simulationIsland != v9->m_simulationIsland )
        {
          hkpWorldOperationUtil::mergeIslands(v13, v11, v9);
        }
        hkReferencedObject::removeReference(v11);
        hkReferencedObject::removeReference(v9);
        v2 = retaddr;
      }
      while ( retaddr->m_islandMerges.m_size );
    }
  }
  if ( v59.m_size > 0 )
  {
    v70 = (unsigned int)v59.m_size;
    v14 = (unsigned int)v59.m_size;
    p_m_identifier = &v59.m_data->m_identifier;
    do
    {
      switch ( *((_BYTE *)p_m_identifier - 8) )
      {
        case 1:
          if ( !*((_QWORD *)*p_m_identifier + 2) )
            hkpWorld::addEntity(v2->m_world, (hkpEntity *)*p_m_identifier, *((hkpEntityActivation *)p_m_identifier + 2));
          goto LABEL_89;
        case 2:
          v16 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v16 )
            hkpWorld::removeEntity(v16, (hkBool *)&result, (hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 3:
          v29 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v29 )
            hkpWorldOperationUtil::updateEntityBP(v29, (hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 4:
          hkpRigidBody::setMotionType(
            (hkpRigidBody *)*p_m_identifier,
            (hkpMotion::MotionType)*((unsigned __int8 *)p_m_identifier + 8),
            (hkpEntityActivation)*((unsigned __int8 *)p_m_identifier + 9),
            (hkpUpdateCollisionFilterOnEntityMode)*((unsigned __int8 *)p_m_identifier + 10));
          goto LABEL_89;
        case 5:
          (*(void (__fastcall **)(const char *, const char *))(*(_QWORD *)*p_m_identifier + 24i64))(
            *p_m_identifier,
            p_m_identifier[1]);
          goto LABEL_21;
        case 6:
          (*(void (__fastcall **)(const char *, const char *))(*(_QWORD *)*p_m_identifier + 32i64))(
            *p_m_identifier,
            p_m_identifier[1]);
          goto LABEL_89;
        case 7:
          hkpWorld::addEntityBatch(
            v2->m_world,
            (hkpEntity *const *)*p_m_identifier,
            *((unsigned __int16 *)p_m_identifier + 4),
            (hkpEntityActivation)*((unsigned __int8 *)p_m_identifier + 10));
          goto LABEL_24;
        case 8:
          hkpWorld::removeEntityBatch(
            v2->m_world,
            (hkpEntity **)*p_m_identifier,
            *((unsigned __int16 *)p_m_identifier + 4));
          goto LABEL_24;
        case 9:
          v21 = (hkpConstraintInstance *)*p_m_identifier;
          if ( !*((_QWORD *)*p_m_identifier + 2) )
          {
            v22 = v2->m_world;
            if ( v21->m_entities[0]->m_world == v22 )
            {
              v23 = v21->m_entities[1];
              if ( !v23 || v23->m_world == v22 )
                hkpWorld::addConstraint(v22, v21);
            }
          }
          goto LABEL_89;
        case 0xA:
          if ( *((_QWORD *)*p_m_identifier + 2) )
            hkpWorld::removeConstraint(v2->m_world, &v69, (hkpConstraintInstance *)*p_m_identifier);
          goto LABEL_89;
        case 0xB:
          v24 = (hkpEntity *)*p_m_identifier;
          if ( *((_QWORD *)*p_m_identifier + 2) )
            goto LABEL_89;
          v58 = 0x80000000;
          v56 = 0i64;
          v57 = 0;
          v24->vfptr[2].__vecDelDtor(v24, (unsigned int)&v56);
          v25 = 0;
          if ( v57 <= 0 )
            goto LABEL_39;
          v26 = v56;
          v27 = (__int64)v56;
          break;
        case 0xC:
          if ( *((_QWORD *)*p_m_identifier + 3) )
            hkpWorld::removeAction(v2->m_world, (hkpAction *)*p_m_identifier);
          goto LABEL_89;
        case 0xE:
          if ( !*((_QWORD *)*p_m_identifier + 2) )
            hkpWorld::addPhantom(v2->m_world, (hkpPhantom *)*p_m_identifier);
          goto LABEL_89;
        case 0xF:
          v28 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v28 )
            hkpWorld::removePhantom(v28, (hkpPhantom *)*p_m_identifier);
          goto LABEL_89;
        case 0x10:
          hkpWorld::addPhantomBatch(
            v2->m_world,
            (hkpPhantom *const *)*p_m_identifier,
            *((unsigned __int16 *)p_m_identifier + 4));
          goto LABEL_24;
        case 0x11:
          hkpWorld::removePhantomBatch(
            v2->m_world,
            (hkpPhantom *const *)*p_m_identifier,
            *((unsigned __int16 *)p_m_identifier + 4));
LABEL_24:
          hkReferencedObject::removeReferences(
            (hkReferencedObject **)*p_m_identifier,
            *((unsigned __int16 *)p_m_identifier + 4),
            8);
          goto LABEL_25;
        case 0x12:
          if ( (hkpWorld *)*((_QWORD *)*p_m_identifier + 2) == v2->m_world )
            hkpPhantom::updateBroadPhase((hkpPhantom *)*p_m_identifier, (hkAabb *)p_m_identifier[1]);
          hkReferencedObject::removeReference((hkReferencedObject *)*p_m_identifier);
          v30 = (hkpEntity *)p_m_identifier[1];
          if ( v30 )
            goto LABEL_56;
          goto LABEL_91;
        case 0x13:
          v32 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v32 )
            hkpWorld::updateCollisionFilterOnEntity(
              v32,
              (hkpEntity *)*p_m_identifier,
              (hkpUpdateCollisionFilterOnEntityMode)*((unsigned __int8 *)p_m_identifier + 8),
              (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)p_m_identifier + 9));
          goto LABEL_89;
        case 0x14:
          v33 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v33 && (v34 = (hkpEntity *)p_m_identifier[1], v34->m_world == v33) )
          {
            hkpWorld::reenableCollisionBetweenEntityPair(v33, (hkpEntity *)*p_m_identifier, v34);
            hkReferencedObject::removeReference((hkReferencedObject *)*p_m_identifier);
            v17 = (hkpEntity *)p_m_identifier[1];
          }
          else
          {
LABEL_21:
            hkReferencedObject::removeReference((hkReferencedObject *)*p_m_identifier);
            v17 = (hkpEntity *)p_m_identifier[1];
          }
          goto LABEL_90;
        case 0x15:
          v35 = v2->m_world;
          if ( *((hkpWorld **)*p_m_identifier + 2) == v35 )
            hkpWorld::updateCollisionFilterOnPhantom(
              v35,
              (hkpPhantom *)*p_m_identifier,
              (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)p_m_identifier + 8));
          goto LABEL_89;
        case 0x16:
          hkpWorld::updateCollisionFilterOnWorld(
            v2->m_world,
            (hkpUpdateCollisionFilterOnWorldMode)*((unsigned __int8 *)p_m_identifier - 7),
            (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)p_m_identifier - 6));
          goto LABEL_91;
        case 0x17:
          hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody((hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 0x18:
          v48 = *((unsigned __int16 *)p_m_identifier + 4);
          v49 = &(*p_m_identifier)[8 * v48 - 8];
          v50 = (char *)v49;
          if ( v49 >= *p_m_identifier )
          {
            do
            {
              v51 = *(_QWORD *)v50;
              if ( *(hkpWorld **)(*(_QWORD *)v50 + 16i64) != v2->m_world )
              {
                v52 = *(_QWORD *)v49;
                v49 -= 8;
                LODWORD(v48) = v48 - 1;
                *(_QWORD *)v50 = v52;
                *((_QWORD *)v49 + 1) = v51;
              }
              v50 -= 8;
            }
            while ( v50 >= *p_m_identifier );
          }
          if ( (_DWORD)v48 )
            ((void (__fastcall *)(hkpSimulation *, const char *, _QWORD))v2->m_world->m_simulation->vfptr[8].__vecDelDtor)(
              v2->m_world->m_simulation,
              *p_m_identifier,
              (unsigned int)v48);
          v53 = (hkpEntity *)*p_m_identifier;
          v54 = (unsigned __int64)&(*p_m_identifier)[8 * *((unsigned __int16 *)p_m_identifier + 4)];
          if ( (unsigned __int64)*p_m_identifier < v54 )
          {
            do
            {
              vfptr = (hkReferencedObject *)v53->vfptr;
              v53 = (hkpEntity *)((char *)v53 + 8);
              hkReferencedObject::removeReference(vfptr);
            }
            while ( (unsigned __int64)v53 < v54 );
          }
LABEL_25:
          v18 = *((unsigned __int16 *)p_m_identifier + 4);
          v19 = (hkpEntity *)*p_m_identifier;
          Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpEntity *, _QWORD))(*Value[11] + 16i64))(
            Value[11],
            v19,
            (unsigned int)(8 * v18));
          v14 = v70;
          goto LABEL_91;
        case 0x19:
          hkpRigidBody::setPositionAndRotation(
            (hkpRigidBody *)*p_m_identifier,
            (hkVector4f *)p_m_identifier[1],
            (hkQuaternionf *)p_m_identifier[1] + 1);
          v36 = p_m_identifier[1];
          v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, const char *, __int64))(*v37[11] + 16i64))(v37[11], v36, 32i64);
          goto LABEL_89;
        case 0x1A:
          v38 = (hkpEntity *)*p_m_identifier;
          v39 = (hkpEntity *)*p_m_identifier;
          v63[0] = _mm_movelh_ps(
                     (__m128)(unsigned __int64)p_m_identifier[1],
                     (__m128)*((unsigned int *)p_m_identifier + 4));
          hkpEntity::activate(v39);
          v38->m_motion.vfptr[9].__vecDelDtor(&v38->m_motion, (unsigned int)v63);
          goto LABEL_89;
        case 0x1B:
          v40 = (hkpEntity *)*p_m_identifier;
          v41 = (hkpEntity *)*p_m_identifier;
          v60 = _mm_movelh_ps(
                  (__m128)(unsigned __int64)p_m_identifier[1],
                  (__m128)*((unsigned int *)p_m_identifier + 4));
          hkpEntity::activate(v41);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v40->m_motion.vfptr[9].__first_virtual_table_function__)(
            &v40->m_motion,
            &v60);
          goto LABEL_89;
        case 0x1C:
          v42 = (hkpEntity *)*p_m_identifier;
          v43 = (hkpEntity *)*p_m_identifier;
          v61 = _mm_movelh_ps(
                  (__m128)(unsigned __int64)p_m_identifier[1],
                  (__m128)*((unsigned int *)p_m_identifier + 4));
          hkpEntity::activate(v43);
          v42->m_motion.vfptr[11].__vecDelDtor(&v42->m_motion, (unsigned int)&v61);
          goto LABEL_89;
        case 0x1D:
          hkpRigidBody::applyPointImpulse(
            (hkpRigidBody *)*p_m_identifier,
            (hkVector4f *)p_m_identifier[1] + 1,
            (hkVector4f *)p_m_identifier[1]);
          v44 = p_m_identifier[1];
          v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, const char *, __int64))(*v45[11] + 16i64))(v45[11], v44, 32i64);
          goto LABEL_89;
        case 0x1E:
          v46 = (hkpEntity *)*p_m_identifier;
          v47 = (hkpEntity *)*p_m_identifier;
          v62 = _mm_movelh_ps(
                  (__m128)(unsigned __int64)p_m_identifier[1],
                  (__m128)*((unsigned int *)p_m_identifier + 4));
          hkpEntity::activate(v47);
          v46->m_motion.vfptr[12].__vecDelDtor(&v46->m_motion, (unsigned int)&v62);
          goto LABEL_89;
        case 0x21:
          hkpWorld::activateRegion(v2->m_world, (hkAabb *)*p_m_identifier);
          v30 = (hkpEntity *)*p_m_identifier;
LABEL_56:
          v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpEntity *, __int64))(*v31[11] + 16i64))(v31[11], v30, 32i64);
          goto LABEL_91;
        case 0x22:
          hkpEntity::activate((hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 0x23:
          if ( (hkpWorld *)*((_QWORD *)*p_m_identifier + 2) == v2->m_world )
            hkpEntity::requestDeactivation((hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 0x24:
          if ( (hkpWorld *)*((_QWORD *)*p_m_identifier + 2) == v2->m_world )
            hkpEntity::deactivate((hkpEntity *)*p_m_identifier);
          goto LABEL_89;
        case 0x25:
          hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
            (hkpConstraintCollisionFilter *)*p_m_identifier,
            (hkpConstraintInstance *)p_m_identifier[1],
            (hkBool)p_m_identifier[2]);
          hkReferencedObject::removeReference((hkReferencedObject *)*p_m_identifier);
          v17 = (hkpEntity *)p_m_identifier[1];
          goto LABEL_90;
        case 0x26:
          (*(void (__fastcall **)(const char *, const char *))(*(_QWORD *)*p_m_identifier + 24i64))(
            *p_m_identifier,
            p_m_identifier[1]);
          goto LABEL_89;
        default:
          goto LABEL_92;
      }
      while ( *(hkpWorld **)(*(_QWORD *)v27 + 16i64) == retaddr->m_world )
      {
        ++v25;
        v27 += 8i64;
        if ( v25 >= v57 )
        {
LABEL_39:
          hkpWorld::addAction(retaddr->m_world, (hkpAction *)*p_m_identifier);
          v26 = v56;
          break;
        }
      }
      v57 = 0;
      if ( v58 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v26, 8 * v58);
      v56 = 0i64;
      v58 = 0x80000000;
LABEL_89:
      v17 = (hkpEntity *)*p_m_identifier;
LABEL_90:
      hkReferencedObject::removeReference(v17);
LABEL_91:
      v2 = retaddr;
LABEL_92:
      if ( v2->m_pending.m_size )
      {
        hkpWorldOperationQueue::executeAllPending(v2);
        v2 = retaddr;
      }
      p_m_identifier += 8;
      v70 = --v14;
    }
    while ( v14 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v59,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v2);
  retaddr->m_pending.m_size = 0;
  --retaddr->m_world->m_pendingOperationQueueCount;
  hkReferencedObject::unlockAll();
  if ( v59.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v59.m_data,
      v59.m_capacityAndFlags << 6);
}

