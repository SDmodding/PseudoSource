// File Line: 36
// RVA: 0xD89310
void __fastcall hkpWorldOperationQueue::hkpWorldOperationQueue(hkpWorldOperationQueue *this, hkpWorld *world)
{
  this->m_pending.m_capacityAndFlags = 2147483648;
  this->m_pending.m_data = 0i64;
  this->m_pending.m_size = 0;
  this->m_islandMerges.m_data = 0i64;
  this->m_islandMerges.m_size = 0;
  this->m_islandMerges.m_capacityAndFlags = 2147483648;
  this->m_pendingBodyOperations.m_data = 0i64;
  this->m_pendingBodyOperations.m_size = 0;
  this->m_pendingBodyOperations.m_capacityAndFlags = 2147483648;
  this->m_world = world;
}

// File Line: 41
// RVA: 0xD89350
void __fastcall hkpWorldOperationQueue::~hkpWorldOperationQueue(hkpWorldOperationQueue *this)
{
  int v1; // eax
  hkpWorldOperationQueue *v2; // rbx
  int v3; // er8
  int v4; // er8

  v1 = this->m_pendingBodyOperations.m_capacityAndFlags;
  v2 = this;
  this->m_pendingBodyOperations.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_pendingBodyOperations.m_data,
      24 * (v1 & 0x3FFFFFFF));
  v2->m_pendingBodyOperations.m_data = 0i64;
  v2->m_pendingBodyOperations.m_capacityAndFlags = 2147483648;
  v3 = v2->m_islandMerges.m_capacityAndFlags;
  v2->m_islandMerges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_islandMerges.m_data,
      v3 << 6);
  v2->m_islandMerges.m_data = 0i64;
  v2->m_islandMerges.m_capacityAndFlags = 2147483648;
  v4 = v2->m_pending.m_capacityAndFlags;
  v2->m_pending.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_pending.m_data,
      v4 << 6);
  v2->m_pending.m_capacityAndFlags = 2147483648;
  v2->m_pending.m_data = 0i64;
}

// File Line: 44
// RVA: 0xD8A3A0
void __fastcall addReferenceTo(hkReferencedObject *obj)
{
  hkReferencedObject::addReference(obj);
}

// File Line: 45
// RVA: 0xD8A3B0
void __fastcall removeReferenceFrom(hkReferencedObject *obj)
{
  hkReferencedObject::removeReference(obj);
}

// File Line: 48
// RVA: 0xD89420
void __fastcall hkpWorldOperationQueue::queueOperation(hkpWorldOperationQueue *this, hkWorldOperation::BaseOperation *operation)
{
  hkWorldOperation::BaseOperation *v2; // rsi
  hkpWorldOperationQueue *v3; // rbx
  hkWorldOperation::BiggestOperation *v4; // rax
  hkWorldOperation::BaseOperation *v5; // rcx
  signed __int64 v6; // rdx
  hkWorldOperation::BiggestOperation *v7; // rdi
  int v8; // eax
  hkReferencedObject *v9; // rcx
  int v10; // ebx
  _QWORD **v11; // rax
  void *v12; // rax
  hkReferencedObject **v13; // rbx
  unsigned __int64 v14; // rdi
  hkReferencedObject *v15; // rcx
  int v16; // ebx
  _QWORD **v17; // rax
  void *v18; // rax
  hkReferencedObject **v19; // rbx
  unsigned __int64 v20; // rdi
  hkReferencedObject *v21; // rcx
  hkWorldOperation::BiggestOperation *v22; // rcx
  int v23; // ebx
  _QWORD **v24; // rax
  void *v25; // rax
  hkReferencedObject **v26; // rbx
  unsigned __int64 v27; // rdi
  hkReferencedObject *v28; // rcx
  int v29; // ebx
  _QWORD **v30; // rax
  void *v31; // rax
  hkReferencedObject **v32; // rbx
  unsigned __int64 v33; // rdi
  hkReferencedObject *v34; // rcx
  _QWORD **v35; // rax
  _OWORD *v36; // rax
  _OWORD *v37; // rcx
  int v38; // ebx
  _QWORD **v39; // rax
  void *v40; // rax
  hkReferencedObject **v41; // rbx
  unsigned __int64 v42; // rdi
  hkReferencedObject *v43; // rcx

  v2 = operation;
  v3 = this;
  hkReferencedObject::lockAll();
  if ( v3->m_pending.m_size == (v3->m_pending.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 64);
  v4 = &v3->m_pending.m_data[(signed __int64)v3->m_pending.m_size];
  if ( v4 )
    v4->m_type.m_storage = 0;
  v5 = v2;
  v6 = 16i64;
  v7 = &v3->m_pending.m_data[(signed __int64)v3->m_pending.m_size++];
  ++v3->m_world->m_pendingOperationsCount;
  do
  {
    v8 = *(_DWORD *)&v5->m_type.m_storage;
    v5 += 4;
    *(_DWORD *)&v5[(char *)v7 - (char *)v2 - 4].m_type.m_storage = v8;
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
      v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v12 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v11[11] + 8i64))(v11[11], (unsigned int)(8 * v10));
      v7->dummy[0] = (unsigned __int64)v12;
      hkString::memCpy(v12, *(const void **)&v2[8].m_type.m_storage, 8 * *(unsigned __int16 *)&v2[16].m_type.m_storage);
      v13 = (hkReferencedObject **)v7->dummy[0];
      v14 = (unsigned __int64)&v13[LOWORD(v7->dummy[1])];
      while ( (unsigned __int64)v13 < v14 )
      {
        v15 = *v13;
        ++v13;
        hkReferencedObject::addReference(v15);
      }
      break;
    case 8:
      v16 = LOWORD(v7->dummy[1]);
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v17[11] + 8i64))(v17[11], (unsigned int)(8 * v16));
      v7->dummy[0] = (unsigned __int64)v18;
      hkString::memCpy(v18, *(const void **)&v2[8].m_type.m_storage, 8 * *(unsigned __int16 *)&v2[16].m_type.m_storage);
      v19 = (hkReferencedObject **)v7->dummy[0];
      v20 = (unsigned __int64)&v19[LOWORD(v7->dummy[1])];
      while ( (unsigned __int64)v19 < v20 )
      {
        v21 = *v19;
        ++v19;
        hkReferencedObject::addReference(v21);
      }
      break;
    case 0xD:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[1]);
      if ( v3->m_islandMerges.m_size == (v3->m_islandMerges.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v3->m_islandMerges,
          64);
      v22 = &v3->m_islandMerges.m_data[(signed __int64)v3->m_islandMerges.m_size];
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
      ++v3->m_islandMerges.m_size;
      --v3->m_pending.m_size;
      break;
    case 0x10:
      v23 = LOWORD(v7->dummy[1]);
      v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v25 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v24[11] + 8i64))(v24[11], (unsigned int)(8 * v23));
      v7->dummy[0] = (unsigned __int64)v25;
      hkString::memCpy(v25, *(const void **)&v2[8].m_type.m_storage, 8 * *(unsigned __int16 *)&v2[16].m_type.m_storage);
      v26 = (hkReferencedObject **)v7->dummy[0];
      v27 = (unsigned __int64)&v26[LOWORD(v7->dummy[1])];
      while ( (unsigned __int64)v26 < v27 )
      {
        v28 = *v26;
        ++v26;
        hkReferencedObject::addReference(v28);
      }
      break;
    case 0x11:
      v29 = LOWORD(v7->dummy[1]);
      v30 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v31 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v30[11] + 8i64))(v30[11], (unsigned int)(8 * v29));
      v7->dummy[0] = (unsigned __int64)v31;
      hkString::memCpy(v31, *(const void **)&v2[8].m_type.m_storage, 8 * *(unsigned __int16 *)&v2[16].m_type.m_storage);
      v32 = (hkReferencedObject **)v7->dummy[0];
      v33 = (unsigned __int64)&v32[LOWORD(v7->dummy[1])];
      while ( (unsigned __int64)v32 < v33 )
      {
        v34 = *v32;
        ++v32;
        hkReferencedObject::addReference(v34);
      }
      break;
    case 0x12:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      v35 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v36 = (_OWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v35[11] + 8i64))(v35[11], 32i64);
      v7->dummy[1] = (unsigned __int64)v36;
      v37 = *(_OWORD **)&v2[16].m_type.m_storage;
      *v36 = *v37;
      v36[1] = v37[1];
      break;
    case 0x18:
      v38 = LOWORD(v7->dummy[1]);
      v39 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v40 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v39[11] + 8i64))(v39[11], (unsigned int)(8 * v38));
      v7->dummy[0] = (unsigned __int64)v40;
      hkString::memCpy(v40, *(const void **)&v2[8].m_type.m_storage, 8 * *(unsigned __int16 *)&v2[16].m_type.m_storage);
      v41 = (hkReferencedObject **)v7->dummy[0];
      v42 = (unsigned __int64)&v41[LOWORD(v7->dummy[1])];
      while ( (unsigned __int64)v41 < v42 )
      {
        v43 = *v41;
        ++v41;
        hkReferencedObject::addReference(v43);
      }
      break;
    case 0x1F:
      hkReferencedObject::addReference((hkReferencedObject *)v7->dummy[0]);
      --v3->m_pending.m_size;
      --v3->m_world->m_pendingOperationsCount;
      break;
    case 0x20:
      hkReferencedObject::removeReference((hkReferencedObject *)v7->dummy[0]);
      --v3->m_pending.m_size;
      --v3->m_world->m_pendingOperationsCount;
      break;
    default:
      break;
  }
  hkReferencedObject::unlockAll();
}nsCount;
      break;
    default:
      break;
  }
  hkReferencedObject::unlockAll();
}

// File Line: 394
// RVA: 0xD8A150
void __fastcall hkpWorldOperationQueue::queueBodyOperation(hkpWorldOperationQueue *this, hkpEntity *entity, hkpBodyOperation *operation, int priority, hkpBodyOperation::ExecutionState hint)
{
  int v5; // ebp
  hkpBodyOperation *v6; // rdi
  hkpEntity *v7; // rsi
  hkpWorldOperationQueue *v8; // rbx
  __int64 v9; // rdx
  signed __int64 v10; // r8

  v5 = priority;
  v6 = operation;
  v7 = entity;
  v8 = this;
  hkReferencedObject::lockAll();
  ++v8->m_world->m_pendingBodyOperationsCount;
  if ( v8->m_pendingBodyOperations.m_size == (v8->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_pendingBodyOperations,
      24);
  v9 = v8->m_pendingBodyOperations.m_size;
  v10 = (signed __int64)&v8->m_pendingBodyOperations.m_data[v9];
  v8->m_pendingBodyOperations.m_size = v9 + 1;
  *(_QWORD *)v10 = v7;
  *(_QWORD *)(v10 + 8) = v6;
  *(_DWORD *)(v10 + 16) = v5;
  *(_DWORD *)(v10 + 20) = hint;
  hkReferencedObject::addReference((hkReferencedObject *)&v7->vfptr);
  hkReferencedObject::addReference((hkReferencedObject *)&v6->vfptr);
  hkReferencedObject::unlockAll();
}

// File Line: 413
// RVA: 0xD8A3C0
bool __fastcall hkpWorldBodyOperationQueueSortCmp(hkpBodyOperationEntry *a, hkpBodyOperationEntry *b)
{
  bool result; // al

  if ( a->m_entity == b->m_entity )
    result = a->m_priority > (unsigned __int64)b->m_priority;
  else
    result = a->m_entity->m_uid < b->m_entity->m_uid;
  return result;
}

// File Line: 425
// RVA: 0xD8A200
void __fastcall hkpWorldOperationQueue::executeAllPendingBodyOperations(hkpWorldOperationQueue *this)
{
  hkpWorldOperationQueue *i; // r14
  int v2; // eax
  int v3; // eax
  int v4; // er9
  __int64 v5; // rdi
  hkRelocationInfo::Import *v6; // rbp
  hkRelocationInfo::Import *v7; // rbx
  __int64 v8; // rsi
  hkReferencedObject **v9; // rbx
  __int64 v10; // rsi
  hkReferencedObject *v11; // rdi
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v12; // [rsp+30h] [rbp-38h]
  __int16 v13; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]

  for ( i = this; i->m_pendingBodyOperations.m_size; v12.m_capacityAndFlags = 2147483648 )
  {
    v12.m_data = 0i64;
    v12.m_size = 0;
    v12.m_capacityAndFlags = 2147483648;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      &v12,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&i->m_pendingBodyOperations);
    i->m_world->m_pendingBodyOperationsCount = 0;
    v2 = i->m_pendingBodyOperations.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v2 >= 16 )
    {
      result.m_enum = 0;
    }
    else
    {
      v3 = 2 * v2;
      v4 = 16;
      if ( v3 > 16 )
        v4 = v3;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &i->m_pendingBodyOperations,
        v4,
        24);
    }
    v5 = (unsigned int)v12.m_size;
    v6 = v12.m_data;
    if ( v12.m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpBodyOperationEntry,bool (*)(hkpBodyOperationEntry const &,hkpBodyOperationEntry const &)>(
        (hkpBodyOperationEntry *)v12.m_data,
        0,
        v12.m_size - 1,
        hkpWorldBodyOperationQueueSortCmp);
    if ( (signed int)v5 > 0 )
    {
      v7 = v6;
      v8 = v5;
      do
      {
        v13 = 256;
        (*(void (__fastcall **)(const char *, _QWORD, __int16 *))(*(_QWORD *)v7->m_identifier + 24i64))(
          v7->m_identifier,
          *(_QWORD *)&v7->m_fromOffset,
          &v13);
        v7 = (hkRelocationInfo::Import *)((char *)v7 + 24);
        --v8;
      }
      while ( v8 );
    }
    hkReferencedObject::lockAll();
    if ( (signed int)v5 > 0 )
    {
      v9 = (hkReferencedObject **)v6;
      v10 = v5;
      do
      {
        v11 = v9[1];
        hkReferencedObject::removeReferenceLockUnchecked(*v9);
        hkReferencedObject::removeReferenceLockUnchecked(v11);
        v9 += 3;
        --v10;
      }
      while ( v10 );
    }
    hkReferencedObject::unlockAll();
    v12.m_size = 0;
    if ( v12.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v6,
        24 * (v12.m_capacityAndFlags & 0x3FFFFFFF));
    v12.m_data = 0i64;
  }
}

// File Line: 466
// RVA: 0xD8A400
hkBool *__fastcall islandLess(hkBool *result, hkWorldOperation::BiggestOperation *a, hkWorldOperation::BiggestOperation *b)
{
  hkBool *v3; // r10
  unsigned int v4; // ecx
  unsigned int v5; // eax
  hkBool *v6; // rax

  v3 = result;
  v4 = *(unsigned __int16 *)(*(_QWORD *)(a->dummy[0] + 296) + 44i64);
  v5 = *(unsigned __int16 *)(*(_QWORD *)(b->dummy[0] + 296) + 44i64);
  if ( v4 < v5
    || v4 == v5
    && *(_WORD *)(*(_QWORD *)(a->dummy[1] + 296) + 44i64) < *(_WORD *)(*(_QWORD *)(b->dummy[1] + 296) + 44i64) )
  {
    v3->m_bool = 1;
    v6 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v6 = v3;
  }
  return v6;
}

// File Line: 494
// RVA: 0xD898A0
void __fastcall hkpWorldOperationQueue::executeAllPending(hkpWorldOperationQueue *this)
{
  hkpWorldOperationQueue *v1; // rdi
  hkpWorldOperationQueue *v2; // r10
  signed int v3; // er8
  hkWorldOperation::BiggestOperation *v4; // rax
  int v5; // edx
  signed __int64 v6; // rcx
  __m128i v7; // xmm2
  __int128 v8; // xmm1
  hkpEntity *v9; // rbx
  __int128 v10; // xmm0
  hkpEntity *v11; // xmm2_8
  hkpWorld *v12; // rax
  hkpWorld *v13; // rcx
  __int64 v14; // rsi
  hkpEntityActivation *v15; // rbx
  hkpWorld *v16; // rcx
  hkpEntity *v17; // rcx
  int v18; // edi
  hkpEntity *v19; // rsi
  _QWORD **v20; // rax
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
  __int64 v36; // rdi
  _QWORD **v37; // rax
  hkpEntity *v38; // rdi
  hkpEntity *v39; // rcx
  hkpEntity *v40; // rdi
  hkpEntity *v41; // rcx
  hkpEntity *v42; // rdi
  hkpEntity *v43; // rcx
  __int64 v44; // rdi
  _QWORD **v45; // rax
  hkpEntity *v46; // rdi
  hkpEntity *v47; // rcx
  __int64 v48; // r11
  _QWORD *v49; // rdx
  _QWORD *i; // rcx
  __int64 v51; // r8
  __int64 v52; // rax
  int v53; // ST20_4
  hkpEntity *v54; // rdi
  unsigned __int64 v55; // rsi
  hkReferencedObject *v56; // rcx
  void *v57; // [rsp+28h] [rbp-69h]
  int v58; // [rsp+30h] [rbp-61h]
  int v59; // [rsp+34h] [rbp-5Dh]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> v60; // [rsp+38h] [rbp-59h]
  __m128 v61; // [rsp+48h] [rbp-49h]
  __m128 v62; // [rsp+58h] [rbp-39h]
  __m128 v63; // [rsp+68h] [rbp-29h]
  __m128 v64; // [rsp+78h] [rbp-19h]
  hkpEntity *entityB[2]; // [rsp+98h] [rbp+7h]
  __int128 v66; // [rsp+A8h] [rbp+17h]
  __int128 v67; // [rsp+B8h] [rbp+27h]
  hkpWorldOperationQueue *retaddr; // [rsp+F8h] [rbp+67h]
  hkpWorldOperationQueue *result; // [rsp+100h] [rbp+6Fh]
  hkBool v70; // [rsp+108h] [rbp+77h]
  __int64 v71; // [rsp+110h] [rbp+7Fh]

  result = this;
  v1 = this;
  hkReferencedObject::lockAll();
  v60.m_data = 0i64;
  v60.m_size = 0;
  v60.m_capacityAndFlags = 2147483648;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v60,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v1);
  v2 = retaddr;
  ++retaddr->m_world->m_pendingOperationQueueCount;
  v3 = retaddr->m_islandMerges.m_size;
  if ( v3 )
  {
    if ( v3 > 1 )
    {
      hkAlgorithm::quickSortRecursive<hkWorldOperation::BiggestOperation,hkBool (*)(hkWorldOperation::BiggestOperation const &,hkWorldOperation::BiggestOperation const &)>(
        retaddr->m_islandMerges.m_data,
        0,
        v3 - 1,
        islandLess);
      v2 = retaddr;
    }
    if ( v2->m_islandMerges.m_size )
    {
      do
      {
        v4 = v2->m_islandMerges.m_data;
        v5 = v2->m_islandMerges.m_size;
        v6 = (signed __int64)v2->m_islandMerges.m_size << 6;
        v7 = *(__m128i *)(&v4[-1].m_type.m_storage + v6);
        v8 = *(_OWORD *)((char *)v4 + v6 - 32);
        *(_OWORD *)entityB = *(_OWORD *)((char *)v4 + v6 - 48);
        v9 = entityB[0];
        v66 = v8;
        v10 = *(_OWORD *)((char *)v4 + v6 - 16);
        v11 = (hkpEntity *)*(_OWORD *)&_mm_srli_si128(v7, 8);
        v2->m_islandMerges.m_size = v5 - 1;
        v12 = v2->m_world;
        v67 = v10;
        v13 = v11->m_world;
        if ( v13 == v12
          && v9->m_world == v12
          && v11->m_motion.m_type.m_storage != 5
          && v9->m_motion.m_type.m_storage != 5
          && v11->m_simulationIsland != v9->m_simulationIsland )
        {
          hkpWorldOperationUtil::mergeIslands(v13, v11, v9);
        }
        hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
        hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
        v2 = retaddr;
      }
      while ( retaddr->m_islandMerges.m_size );
    }
  }
  if ( v60.m_size > 0 )
  {
    v71 = (unsigned int)v60.m_size;
    v14 = (unsigned int)v60.m_size;
    v15 = (hkpEntityActivation *)&v60.m_data->m_identifier;
    do
    {
      switch ( *((unsigned __int8 *)v15 - 8) )
      {
        case 1u:
          if ( !*(_QWORD *)(*(_QWORD *)v15 + 16i64) )
            hkpWorld::addEntity(v2->m_world, *(hkpEntity **)v15, v15[2]);
          goto LABEL_90;
        case 2u:
          v16 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v16 )
            hkpWorld::removeEntity(v16, (hkBool *)&result, *(hkpEntity **)v15);
          goto LABEL_90;
        case 3u:
          v29 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v29 )
            hkpWorldOperationUtil::updateEntityBP(v29, *(hkpEntity **)v15);
          goto LABEL_90;
        case 4u:
          hkpRigidBody::setMotionType(
            *(hkpRigidBody **)v15,
            (hkpMotion::MotionType)*((unsigned __int8 *)v15 + 8),
            (hkpEntityActivation)*((unsigned __int8 *)v15 + 9),
            (hkpUpdateCollisionFilterOnEntityMode)*((unsigned __int8 *)v15 + 10));
          goto LABEL_90;
        case 5u:
          (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v15 + 24i64))(*(_QWORD *)v15, *((_QWORD *)v15 + 1));
          goto LABEL_21;
        case 6u:
          (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v15 + 32i64))(*(_QWORD *)v15, *((_QWORD *)v15 + 1));
          goto LABEL_90;
        case 7u:
          hkpWorld::addEntityBatch(
            v2->m_world,
            *(hkpEntity *const **)v15,
            *((unsigned __int16 *)v15 + 4),
            (hkpEntityActivation)*((unsigned __int8 *)v15 + 10));
          goto LABEL_24;
        case 8u:
          hkpWorld::removeEntityBatch(v2->m_world, *(hkpEntity *const **)v15, *((unsigned __int16 *)v15 + 4));
          goto LABEL_24;
        case 9u:
          v21 = *(hkpConstraintInstance **)v15;
          if ( !*(_QWORD *)(*(_QWORD *)v15 + 16i64) )
          {
            v22 = v2->m_world;
            if ( v21->m_entities[0]->m_world == v22 )
            {
              v23 = v21->m_entities[1];
              if ( !v23 || v23->m_world == v22 || !v23 )
                hkpWorld::addConstraint(v22, v21);
            }
          }
          goto LABEL_90;
        case 0xAu:
          if ( *(_QWORD *)(*(_QWORD *)v15 + 16i64) )
            hkpWorld::removeConstraint(v2->m_world, &v70, *(hkpConstraintInstance **)v15);
          goto LABEL_90;
        case 0xBu:
          v24 = *(hkpEntity **)v15;
          if ( *(_QWORD *)(*(_QWORD *)v15 + 16i64) )
            goto LABEL_90;
          v59 = 2147483648;
          v57 = 0i64;
          v58 = 0;
          v24->vfptr[2].__vecDelDtor((hkBaseObject *)&v24->vfptr, (unsigned int)&v57);
          v25 = 0;
          if ( v58 <= 0 )
            goto LABEL_40;
          v26 = v57;
          v27 = (__int64)v57;
          break;
        case 0xCu:
          if ( *(_QWORD *)(*(_QWORD *)v15 + 24i64) )
            hkpWorld::removeAction(v2->m_world, *(hkpAction **)v15);
          goto LABEL_90;
        case 0xEu:
          if ( !*(_QWORD *)(*(_QWORD *)v15 + 16i64) )
            hkpWorld::addPhantom(v2->m_world, *(hkpPhantom **)v15);
          goto LABEL_90;
        case 0xFu:
          v28 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v28 )
            hkpWorld::removePhantom(v28, *(hkpPhantom **)v15);
          goto LABEL_90;
        case 0x10u:
          hkpWorld::addPhantomBatch(v2->m_world, *(hkpPhantom *const **)v15, *((unsigned __int16 *)v15 + 4));
          goto LABEL_24;
        case 0x11u:
          hkpWorld::removePhantomBatch(v2->m_world, *(hkpPhantom *const **)v15, *((unsigned __int16 *)v15 + 4));
LABEL_24:
          hkReferencedObject::removeReferences(*(hkReferencedObject *const **)v15, *((unsigned __int16 *)v15 + 4), 8);
          goto LABEL_25;
        case 0x12u:
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v2->m_world )
            hkpPhantom::updateBroadPhase(*(hkpPhantom **)v15, *((hkAabb **)v15 + 1));
          hkReferencedObject::removeReference(*(hkReferencedObject **)v15);
          v30 = (hkpEntity *)*((_QWORD *)v15 + 1);
          if ( v30 )
            goto LABEL_57;
          goto LABEL_92;
        case 0x13u:
          v32 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v32 )
            hkpWorld::updateCollisionFilterOnEntity(
              v32,
              *(hkpEntity **)v15,
              (hkpUpdateCollisionFilterOnEntityMode)*((unsigned __int8 *)v15 + 8),
              (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)v15 + 9));
          goto LABEL_90;
        case 0x14u:
          v33 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) != v33
            || (v34 = (hkpEntity *)*((_QWORD *)v15 + 1), v34->m_world != v33) )
          {
LABEL_21:
            hkReferencedObject::removeReference(*(hkReferencedObject **)v15);
            v17 = (hkpEntity *)*((_QWORD *)v15 + 1);
          }
          else
          {
            hkpWorld::reenableCollisionBetweenEntityPair(v33, *(hkpEntity **)v15, v34);
            hkReferencedObject::removeReference(*(hkReferencedObject **)v15);
            v17 = (hkpEntity *)*((_QWORD *)v15 + 1);
          }
          goto LABEL_91;
        case 0x15u:
          v35 = v2->m_world;
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v35 )
            hkpWorld::updateCollisionFilterOnPhantom(
              v35,
              *(hkpPhantom **)v15,
              (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)v15 + 8));
          goto LABEL_90;
        case 0x16u:
          hkpWorld::updateCollisionFilterOnWorld(
            v2->m_world,
            (hkpUpdateCollisionFilterOnWorldMode)*((unsigned __int8 *)v15 - 7),
            (hkpUpdateCollectionFilterMode)*((unsigned __int8 *)v15 - 6));
          goto LABEL_92;
        case 0x17u:
          hkpRigidBody::updateBroadphaseAndResetCollisionInformationOfWarpedBody(*(hkpEntity **)v15);
          goto LABEL_90;
        case 0x18u:
          v48 = *((unsigned __int16 *)v15 + 4);
          v49 = (_QWORD *)(*(_QWORD *)v15 + 8 * (v48 - 1));
          for ( i = v49; (unsigned __int64)i >= *(_QWORD *)v15; --i )
          {
            v51 = *i;
            if ( *(hkpWorld **)(*i + 16i64) != v2->m_world )
            {
              v52 = *v49;
              --v49;
              LODWORD(v48) = v48 - 1;
              *i = v52;
              v49[1] = v51;
            }
          }
          if ( (_DWORD)v48 )
          {
            v53 = *((unsigned __int8 *)v15 + 10);
            ((void (__fastcall *)(hkpSimulation *, _QWORD, _QWORD))v2->m_world->m_simulation->vfptr[8].__vecDelDtor)(
              v2->m_world->m_simulation,
              *(_QWORD *)v15,
              (unsigned int)v48);
          }
          v54 = *(hkpEntity **)v15;
          v55 = *(_QWORD *)v15 + 8i64 * *((unsigned __int16 *)v15 + 4);
          if ( *(_QWORD *)v15 < v55 )
          {
            do
            {
              v56 = (hkReferencedObject *)v54->vfptr;
              v54 = (hkpEntity *)((char *)v54 + 8);
              hkReferencedObject::removeReference(v56);
            }
            while ( (unsigned __int64)v54 < v55 );
          }
LABEL_25:
          v18 = *((unsigned __int16 *)v15 + 4);
          v19 = *(hkpEntity **)v15;
          v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpEntity *, _QWORD))(*v20[11] + 16i64))(
            v20[11],
            v19,
            (unsigned int)(8 * v18));
          v14 = v71;
          goto LABEL_92;
        case 0x19u:
          hkpRigidBody::setPositionAndRotation(
            *(hkpRigidBody **)v15,
            *((hkVector4f **)v15 + 1),
            (hkQuaternionf *)(*((_QWORD *)v15 + 1) + 16i64));
          v36 = *((_QWORD *)v15 + 1);
          v37 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v37[11] + 16i64))(v37[11], v36, 32i64);
          goto LABEL_90;
        case 0x1Au:
          v38 = *(hkpEntity **)v15;
          v39 = *(hkpEntity **)v15;
          v64 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v15 + 1), (__m128)*((unsigned int *)v15 + 4));
          hkpEntity::activate(v39);
          v38->m_motion.vfptr[9].__vecDelDtor((hkBaseObject *)&v38->m_motion.vfptr, (unsigned int)&v64);
          goto LABEL_90;
        case 0x1Bu:
          v40 = *(hkpEntity **)v15;
          v41 = *(hkpEntity **)v15;
          v61 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v15 + 1), (__m128)*((unsigned int *)v15 + 4));
          hkpEntity::activate(v41);
          ((void (__fastcall *)(hkpMaxSizeMotion *, __m128 *))v40->m_motion.vfptr[9].__first_virtual_table_function__)(
            &v40->m_motion,
            &v61);
          goto LABEL_90;
        case 0x1Cu:
          v42 = *(hkpEntity **)v15;
          v43 = *(hkpEntity **)v15;
          v62 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v15 + 1), (__m128)*((unsigned int *)v15 + 4));
          hkpEntity::activate(v43);
          v42->m_motion.vfptr[11].__vecDelDtor((hkBaseObject *)&v42->m_motion.vfptr, (unsigned int)&v62);
          goto LABEL_90;
        case 0x1Du:
          hkpRigidBody::applyPointImpulse(
            *(hkpRigidBody **)v15,
            (hkVector4f *)(*((_QWORD *)v15 + 1) + 16i64),
            *((hkVector4f **)v15 + 1));
          v44 = *((_QWORD *)v15 + 1);
          v45 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, __int64, signed __int64))(*v45[11] + 16i64))(v45[11], v44, 32i64);
          goto LABEL_90;
        case 0x1Eu:
          v46 = *(hkpEntity **)v15;
          v47 = *(hkpEntity **)v15;
          v63 = _mm_movelh_ps((__m128)*((unsigned __int64 *)v15 + 1), (__m128)*((unsigned int *)v15 + 4));
          hkpEntity::activate(v47);
          v46->m_motion.vfptr[12].__vecDelDtor((hkBaseObject *)&v46->m_motion.vfptr, (unsigned int)&v63);
          goto LABEL_90;
        case 0x21u:
          hkpWorld::activateRegion(v2->m_world, *(hkAabb **)v15);
          v30 = *(hkpEntity **)v15;
LABEL_57:
          v31 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          (*(void (__fastcall **)(_QWORD *, hkpEntity *, signed __int64))(*v31[11] + 16i64))(v31[11], v30, 32i64);
          goto LABEL_92;
        case 0x22u:
          hkpEntity::activate(*(hkpEntity **)v15);
          goto LABEL_90;
        case 0x23u:
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v2->m_world )
            hkpEntity::requestDeactivation(*(hkpEntity **)v15);
          goto LABEL_90;
        case 0x24u:
          if ( *(hkpWorld **)(*(_QWORD *)v15 + 16i64) == v2->m_world )
            hkpEntity::deactivate(*(hkpEntity **)v15);
          goto LABEL_90;
        case 0x25u:
          hkpConstraintCollisionFilter::_constraintBreakingCallbackImmediate(
            *(hkpConstraintCollisionFilter **)v15,
            *((hkpConstraintInstance **)v15 + 1),
            (hkBool)*((char *)v15 + 16));
          hkReferencedObject::removeReference(*(hkReferencedObject **)v15);
          v17 = (hkpEntity *)*((_QWORD *)v15 + 1);
          goto LABEL_91;
        case 0x26u:
          (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)v15 + 24i64))(*(_QWORD *)v15, *((_QWORD *)v15 + 1));
          goto LABEL_90;
        default:
          goto LABEL_93;
      }
      while ( *(hkpWorld **)(*(_QWORD *)v27 + 16i64) == retaddr->m_world )
      {
        ++v25;
        v27 += 8i64;
        if ( v25 >= v58 )
        {
LABEL_40:
          hkpWorld::addAction(retaddr->m_world, *(hkpAction **)v15);
          v26 = v57;
          break;
        }
      }
      v58 = 0;
      if ( v59 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v26,
          8 * v59);
      v57 = 0i64;
      v59 = 2147483648;
LABEL_90:
      v17 = *(hkpEntity **)v15;
LABEL_91:
      hkReferencedObject::removeReference((hkReferencedObject *)&v17->vfptr);
LABEL_92:
      v2 = retaddr;
LABEL_93:
      if ( v2->m_pending.m_size )
      {
        hkpWorldOperationQueue::executeAllPending(v2);
        v2 = retaddr;
      }
      v15 += 16;
      v71 = --v14;
    }
    while ( v14 );
  }
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    &v60,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v2);
  retaddr->m_pending.m_size = 0;
  --retaddr->m_world->m_pendingOperationQueueCount;
  hkReferencedObject::unlockAll();
  if ( v60.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v60.m_data,
      v60.m_capacityAndFlags << 6);
}

