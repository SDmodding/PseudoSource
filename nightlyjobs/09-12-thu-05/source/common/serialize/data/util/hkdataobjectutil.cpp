// File Line: 108
// RVA: 0xE49E50
void __fastcall Copier::~Copier(Copier *this)
{
  Copier *v1; // rbx
  hkPackfileData *v2; // rcx
  hkReferencedObject *v3; // rcx
  int v4; // er8
  int v5; // er8
  int v6; // eax
  int v7; // er8

  v1 = this;
  v2 = this->m_trackedData.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_trackedData.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_classReg.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_classReg.m_pntr = 0i64;
  v4 = v1->m_postFinishObjects.m_capacityAndFlags;
  v1->m_postFinishObjects.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_postFinishObjects.m_data,
      16 * v4);
  v1->m_postFinishObjects.m_data = 0i64;
  v1->m_postFinishObjects.m_capacityAndFlags = 2147483648;
  v5 = v1->m_copyStack.m_capacityAndFlags;
  v1->m_copyStack.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_copyStack.m_data,
      16 * v5);
  v1->m_copyStack.m_data = 0i64;
  v1->m_copyStack.m_capacityAndFlags = 2147483648;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *)&v1->m_liveInfoFromHandle.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v1->m_pointerPatchesFromHandle.m_indexMap,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  v6 = v1->m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags;
  v1->m_pointerPatchesFromHandle.m_valueChain.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_pointerPatchesFromHandle.m_valueChain.m_data,
      24 * (v6 & 0x3FFFFFFF));
  v1->m_pointerPatchesFromHandle.m_valueChain.m_data = 0i64;
  v1->m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 2147483648;
  v7 = v1->m_todos.m_capacityAndFlags;
  v1->m_todos.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_todos.m_data,
      16 * v7);
  v1->m_todos.m_capacityAndFlags = 2147483648;
  v1->m_todos.m_data = 0i64;
}

// File Line: 121
// RVA: 0xE4ACD0
void __fastcall Copier::markAsDone(Copier *this, hkDataObject_Handle *handle, hkVariant *v, int objectSize)
{
  hkDataObject_Handle *v4; // r15
  Copier *v5; // r13
  int v6; // er14
  int v7; // er12
  hkVariant *v8; // rbx
  int v9; // esi
  int i; // eax
  signed __int64 v11; // rcx
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx
  void **v15; // rdx
  hkClass *v16; // rbx
  bool v17; // zf
  signed int v18; // eax
  hkDataObject_Handle v19; // [rsp+20h] [rbp-40h]
  __int64 v20; // [rsp+30h] [rbp-30h]
  hkDataObject_Handle v21; // [rsp+40h] [rbp-20h]
  __int64 v22; // [rsp+50h] [rbp-10h]
  hkBool v23; // [rsp+A0h] [rbp+40h]
  hkBool result; // [rsp+B8h] [rbp+58h]

  v4 = handle;
  v5 = this;
  v6 = 0;
  v7 = objectSize;
  v8 = v;
  v9 = 0;
  v19 = *handle;
  for ( i = hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
              &this->m_pointerPatchesFromHandle,
              &v19); i != -1; i = *(int *)((char *)&v5->m_pointerPatchesFromHandle.m_valueChain.m_data->next + v13) )
  {
    v11 = 3i64 * i;
    v12 = v5->m_pointerPatchesFromHandle.m_valueChain.m_data;
    v13 = 8 * v11;
    v14 = *(_QWORD *)&v12[(unsigned __int64)v11 / 3].value.m_isVariant.m_bool;
    v15 = *(void ***)((char *)&v12->value.m_addr + v13);
    *v15 = v8->m_object;
    if ( (_BYTE)v14 )
      v15[1] = v8->m_class;
    v9 += BYTE1(v14) != 0;
  }
  v19 = *v4;
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::removeKey(
    &v5->m_pointerPatchesFromHandle,
    &v19);
  v19 = (hkDataObject_Handle)*v8;
  v16 = (hkClass *)v19.p1;
  if ( !hkClass::hasVtable((hkClass *)v19.p1, &result)->m_bool
    || (v17 = hkClass::isSuperClass(&hkReferencedObjectClass, &v23, v16)->m_bool == 0, v18 = 1, v17) )
  {
    v18 = 0;
  }
  HIDWORD(v20) = v7;
  if ( v18 )
    v6 = v9;
  LODWORD(v20) = v6;
  v21 = v19;
  v19 = *v4;
  v22 = v20;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *)&v5->m_liveInfoFromHandle.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    &v19,
    (Copier::LiveObjectInfo *)&v21);
}

// File Line: 153
// RVA: 0xE4B400
hkResult *__fastcall Copier::resolvePointer(Copier *this, hkResult *result, Copier::PointerPatch *patch, hkDataObject_Handle *handle)
{
  hkDataObject_Handle *v4; // rdi
  Copier::PointerPatch *v5; // rsi
  hkResult *v6; // r15
  Copier *v7; // rbx
  __int64 v8; // r8
  int v9; // er10
  __int64 v10; // r9
  hkDataObject_Handle *v11; // rcx
  int v12; // eax
  bool v13; // zf
  signed __int64 v14; // rcx
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v15; // rax
  void *v16; // rdx
  hkClass *v17; // r8
  _QWORD *v18; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v19; // rax
  signed __int64 v20; // rcx
  __int64 v21; // rax
  hkDataObject_Handle *v22; // rcx
  int v23; // eax
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *v24; // r8
  hkDataObject_Handle *v25; // rdx
  hkDataObject_Handle v27; // [rsp+20h] [rbp-28h]
  __int64 v28; // [rsp+30h] [rbp-18h]

  v4 = handle;
  v5 = patch;
  v6 = result;
  v7 = this;
  if ( !this->m_allocatedOnHeap )
    goto LABEL_8;
  if ( !patch->m_isOwning.m_bool )
    goto LABEL_8;
  v8 = this->m_copyStack.m_size;
  v9 = 0;
  v10 = 0i64;
  if ( v8 <= 0 )
    goto LABEL_8;
  v11 = this->m_copyStack.m_data;
  while ( v11->p0 != v4->p0 || v11->p1 != v4->p1 )
  {
    ++v10;
    ++v9;
    ++v11;
    if ( v10 >= v8 )
      goto LABEL_8;
  }
  if ( v9 == -1 )
  {
LABEL_8:
    v27 = *v4;
    v12 = (unsigned __int64)hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::findKey(
                              (hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *)&v7->m_liveInfoFromHandle.m_elem,
                              &v27);
    if ( v12 <= v7->m_liveInfoFromHandle.m_hashMod )
    {
      v13 = v5->m_isVariant.m_bool == 0;
      v14 = v12;
      v15 = v7->m_liveInfoFromHandle.m_elem;
      v16 = v15[v14].val.m_variant.m_object;
      v17 = v15[v14].val.m_variant.m_class;
      v28 = *(_QWORD *)&v15[v14].val.m_refCount;
      v18 = v5->m_addr;
      *(_QWORD *)v5->m_addr = v16;
      if ( !v13 )
        v18[1] = v17;
      LODWORD(v28) = (v5->m_isOwning.m_bool != 0) + (_DWORD)v28;
      v19 = v7->m_liveInfoFromHandle.m_elem;
      v19[v14].val.m_variant.m_object = v16;
      v20 = (signed __int64)&v19[v14];
      v21 = v28;
      *(_QWORD *)(v20 + 24) = v17;
      *(_QWORD *)(v20 + 32) = v21;
      goto LABEL_33;
    }
    v27 = *v4;
    if ( hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
           &v7->m_pointerPatchesFromHandle,
           &v27) == -1 )
    {
      if ( !v5->m_isOwning.m_bool )
      {
LABEL_32:
        v27 = *v4;
        hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::insert(
          &v7->m_pointerPatchesFromHandle,
          &v27,
          v5);
LABEL_33:
        v6->m_enum = 0;
        return v6;
      }
      if ( v7->m_todos.m_size == (v7->m_todos.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
      v22 = &v7->m_todos.m_data[v7->m_todos.m_size];
      if ( v22 )
      {
        v22->p0 = v4->p0;
        v22->p1 = v4->p1;
      }
    }
    else
    {
      if ( !v5->m_isOwning.m_bool )
        goto LABEL_32;
      v27 = *v4;
      v23 = hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
              &v7->m_pointerPatchesFromHandle,
              &v27);
      if ( v23 != -1 )
      {
        v24 = v7->m_pointerPatchesFromHandle.m_valueChain.m_data;
        while ( !v24[v23].value.m_isOwning.m_bool )
        {
          v23 = v24[v23].next;
          if ( v23 == -1 )
            goto LABEL_27;
        }
        if ( v23 != -1 )
          goto LABEL_32;
      }
LABEL_27:
      if ( v7->m_todos.m_size == (v7->m_todos.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
      v25 = &v7->m_todos.m_data[v7->m_todos.m_size];
      if ( v25 )
      {
        v25->p0 = v4->p0;
        v25->p1 = v4->p1;
      }
    }
    ++v7->m_todos.m_size;
    goto LABEL_32;
  }
  result->m_enum = 1;
  return v6;
}

// File Line: 215
// RVA: 0xE4A740
void __fastcall Copier::finishAndTrackObjectsInPackfile(Copier *this, hkPackfileData *trackedData)
{
  int v2; // er9
  Copier *v3; // rsi
  __int64 v4; // rcx
  hkPackfileData *v5; // r15
  __int64 v6; // r8
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v7; // rax
  int v8; // edi
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v9; // rax
  hkClass *v10; // rbp
  unsigned __int64 v11; // r14
  __int64 v12; // ST30_8
  const char *v13; // rax
  _QWORD *v14; // rax
  __int64 v15; // r10
  int v16; // er9
  __int64 v17; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v18; // r8

  v2 = 0;
  v3 = this;
  v4 = this->m_liveInfoFromHandle.m_hashMod;
  v5 = trackedData;
  v6 = 0i64;
  if ( v4 >= 0 )
  {
    v7 = v3->m_liveInfoFromHandle.m_elem;
    do
    {
      if ( v7->key.p0 != (void *)-1i64 )
        break;
      ++v6;
      ++v2;
      ++v7;
    }
    while ( v6 <= v4 );
  }
  v8 = v2;
  if ( v2 <= v3->m_liveInfoFromHandle.m_hashMod )
  {
    do
    {
      v9 = v3->m_liveInfoFromHandle.m_elem;
      v10 = v9[v8].val.m_variant.m_class;
      v11 = (unsigned __int64)v9[v8].val.m_variant.m_object;
      v12 = *(_QWORD *)&v9[v8].val.m_refCount;
      v13 = hkClass::getName(v10);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v5->m_trackedObjects.m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v11,
        (unsigned __int64)v13);
      if ( hkClass::getAttribute(v10, "hk.PostFinish") )
      {
        if ( v5->m_postFinishObjects.m_size == (v5->m_postFinishObjects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v5->m_postFinishObjects,
            16);
        v14 = &v5->m_postFinishObjects.m_data[v5->m_postFinishObjects.m_size].m_object;
        if ( v14 )
        {
          *v14 = v11;
          v14[1] = v10;
        }
        ++v5->m_postFinishObjects.m_size;
      }
      v15 = v3->m_liveInfoFromHandle.m_hashMod;
      v16 = v8 + 1;
      v17 = v8 + 1;
      if ( v17 <= v15 )
      {
        v18 = &v3->m_liveInfoFromHandle.m_elem[v16];
        do
        {
          if ( v18->key.p0 != (void *)-1i64 )
            break;
          ++v17;
          ++v16;
          ++v18;
        }
        while ( v17 <= v15 );
      }
      v8 = v16;
    }
    while ( v16 <= v3->m_liveInfoFromHandle.m_hashMod );
  }
}

// File Line: 233
// RVA: 0xE4A5C0
void __fastcall Copier::finishAndRefcountLiveObjects(Copier *this, hkTypeInfoRegistry *typeReg)
{
  int v2; // er9
  Copier *v3; // rsi
  __int64 v4; // rcx
  hkTypeInfoRegistry *v5; // r12
  __int64 v6; // r8
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v7; // rax
  int v8; // ebp
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v9; // rax
  __int64 v10; // r15
  hkClass *v11; // r14
  _WORD *v12; // rdi
  hkVariant *v13; // rax
  __int16 v14; // ax
  hkBaseObjectVtbl *v15; // rbx
  const char *v16; // rax
  __int64 v17; // r10
  int v18; // er9
  __int64 v19; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v20; // r8
  __int64 v21; // [rsp+30h] [rbp-38h]
  hkBool result; // [rsp+70h] [rbp+8h]

  v2 = 0;
  v3 = this;
  v4 = this->m_liveInfoFromHandle.m_hashMod;
  v5 = typeReg;
  v6 = 0i64;
  if ( v4 >= 0 )
  {
    v7 = v3->m_liveInfoFromHandle.m_elem;
    do
    {
      if ( v7->key.p0 != (void *)-1i64 )
        break;
      ++v6;
      ++v2;
      ++v7;
    }
    while ( v6 <= v4 );
  }
  v8 = v2;
  if ( v2 <= v3->m_liveInfoFromHandle.m_hashMod )
  {
    do
    {
      v9 = v3->m_liveInfoFromHandle.m_elem;
      v10 = *(_QWORD *)&v9[v8].val.m_refCount;
      v11 = v9[v8].val.m_variant.m_class;
      v12 = v9[v8].val.m_variant.m_object;
      v21 = *(_QWORD *)&v9[v8].val.m_refCount;
      if ( hkClass::getAttribute(v9[v8].val.m_variant.m_class, "hk.PostFinish") )
      {
        if ( v3->m_postFinishObjects.m_size == (v3->m_postFinishObjects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v3->m_postFinishObjects,
            16);
        v13 = &v3->m_postFinishObjects.m_data[v3->m_postFinishObjects.m_size];
        if ( v13 )
        {
          v13->m_object = v12;
          v13->m_class = v11;
        }
        ++v3->m_postFinishObjects.m_size;
      }
      if ( (signed __int16)v10 > 0 )
      {
        v14 = WORD2(v21);
        if ( SHIDWORD(v21) <= -1 )
          v14 = hkClass::getObjectSize(v11);
        v12[4] = v14;
        v12[5] = v10;
      }
      v15 = v5->vfptr;
      v16 = hkClass::getName(v11);
      ((void (__fastcall *)(hkTypeInfoRegistry *, _WORD *, const char *))v15[2].__vecDelDtor)(v5, v12, v16);
      hkClass::hasVtable(v11, &result);
      v17 = v3->m_liveInfoFromHandle.m_hashMod;
      v18 = v8 + 1;
      v19 = v8 + 1;
      if ( v19 <= v17 )
      {
        v20 = &v3->m_liveInfoFromHandle.m_elem[v18];
        do
        {
          if ( v20->key.p0 != (void *)-1i64 )
            break;
          ++v19;
          ++v18;
          ++v20;
        }
        while ( v19 <= v17 );
      }
      v8 = v18;
    }
    while ( v18 <= v3->m_liveInfoFromHandle.m_hashMod );
  }
}

// File Line: 283
// RVA: 0xE4AE10
void __fastcall Copier::postFinishObjects(Copier *this)
{
  hkVariant *v1; // rbx
  Copier *v2; // rsi
  void *v3; // rdi
  hkVariant *v4; // rax

  v1 = this->m_postFinishObjects.m_data;
  v2 = this;
  if ( v1 < &v1[this->m_postFinishObjects.m_size] )
  {
    do
    {
      v3 = v1->m_object;
      v4 = hkClass::getAttribute(v1->m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))v4->m_object)(v3);
      ++v1;
    }
    while ( v1 < &v2->m_postFinishObjects.m_data[v2->m_postFinishObjects.m_size] );
  }
}

// File Line: 299
// RVA: 0xE4AE80
hkResult *__fastcall Copier::processPointersAndAllocations(Copier *this, hkResult *result, hkDataObjectToNative::CopyInfoOut *infoOut)
{
  int v3; // edi
  hkDataObjectToNative::CopyInfoOut *v4; // rsi
  hkResult *v5; // r15
  Copier *v6; // r13
  __int64 v7; // r14
  hkDataObjectToNative::Alloc *v8; // rcx
  hkPackfileData *v9; // rbx
  void *v10; // rbp
  int v11; // eax
  hkPackfileData::Chunk *v12; // rcx
  __int64 v13; // rax
  int v14; // ebx
  __int64 v15; // rdi
  hkDataObjectToNative::PointerInfo *v16; // r9
  hkResult *v17; // rax
  Copier::PointerPatch patch; // [rsp+20h] [rbp-38h]
  hkResult resulta; // [rsp+70h] [rbp+18h]

  v3 = 0;
  v4 = infoOut;
  v5 = result;
  v6 = this;
  if ( infoOut->allocs.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v4->allocs.m_data;
      v9 = v6->m_trackedData.m_pntr;
      v10 = v8[v7].m_addr;
      if ( v8[v7].m_size == -1 )
      {
        if ( v9->m_memory.m_size == (v9->m_memory.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_memory, 8);
        v9->m_memory.m_data[v9->m_memory.m_size++] = v10;
      }
      else
      {
        *(_DWORD *)&patch.m_isVariant.m_bool = v8[v7].m_size;
        v11 = v9->m_chunks.m_capacityAndFlags;
        *(_DWORD *)(&patch.m_isOwning + 3) = 7;
        if ( v9->m_chunks.m_size == (v11 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_chunks, 16);
        v12 = &v9->m_chunks.m_data[v9->m_chunks.m_size];
        if ( v12 )
        {
          v13 = *(_QWORD *)&patch.m_isVariant.m_bool;
          v12->pointer = v10;
          *(_QWORD *)&v12->numBytes = v13;
        }
        ++v9->m_chunks.m_size;
      }
      ++v3;
      ++v7;
    }
    while ( v3 < v4->allocs.m_size );
  }
  v14 = 0;
  if ( v4->pointersOut.m_size <= 0 )
  {
LABEL_17:
    v5->m_enum = 0;
    v17 = v5;
  }
  else
  {
    v15 = 0i64;
    while ( 1 )
    {
      v16 = &v4->pointersOut.m_data[v15];
      patch.m_addr = v16->m_addr;
      patch.m_isVariant.m_bool = v16->m_isVariant.m_bool;
      patch.m_isOwning.m_bool = v16->m_isOwning.m_bool;
      if ( Copier::resolvePointer(v6, &resulta, &patch, &v16->m_handle)->m_enum == 1 )
        break;
      ++v14;
      ++v15;
      if ( v14 >= v4->pointersOut.m_size )
        goto LABEL_17;
    }
    v5->m_enum = 1;
    v17 = v5;
  }
  return v17;
}

// File Line: 337
// RVA: 0xE4A160
hkVariant *__fastcall Copier::deepCopyToNative(Copier *this, hkVariant *result, hkDataObject *topObj)
{
  Copier *v3; // rdi
  hkDataObject *v4; // rbx
  hkVariant *v5; // rsi
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // r14
  hkDataObjectImpl *v9; // rcx
  void **v10; // rcx
  int v11; // edx
  hkDataObject_Handle *v12; // rax
  void *v13; // r8
  hkDataObject_Handle *v14; // rcx
  hkDataObject_Handle *v15; // rax
  signed __int64 v16; // rcx
  int v17; // er9
  __int64 v18; // rcx
  hkDataObjectImpl *v19; // rcx
  bool v20; // zf
  hkDataObjectImpl *v22; // rcx
  Copier::PointerPatch patch; // [rsp+30h] [rbp-39h]
  void *v24; // [rsp+40h] [rbp-29h]
  hkClass *v25; // [rsp+48h] [rbp-21h]
  hkDataObject_Handle handle; // [rsp+50h] [rbp-19h]
  hkDataObjectToNative v27; // [rsp+60h] [rbp-9h]
  __int128 v28; // [rsp+70h] [rbp+7h]
  void *array; // [rsp+80h] [rbp+17h]
  int v30; // [rsp+88h] [rbp+1Fh]
  int v31; // [rsp+8Ch] [rbp+23h]
  char *v32; // [rsp+90h] [rbp+27h]
  int v33; // [rsp+98h] [rbp+2Fh]
  int v34; // [rsp+9Ch] [rbp+33h]
  hkResult resulta; // [rsp+D0h] [rbp+67h]
  hkResult v36; // [rsp+E0h] [rbp+77h]
  hkDataObject obj; // [rsp+E8h] [rbp+7Fh]

  v3 = this;
  v4 = topObj;
  v5 = result;
  v6 = ((__int64 (*)(void))topObj->m_impl->vfptr[2].__vecDelDtor)();
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
  v27.m_classReg = v3->m_classReg.m_pntr;
  v27.m_allocatedOnHeap = v3->m_allocatedOnHeap;
  v8 = v7;
  array = 0i64;
  v30 = 0;
  v31 = 2147483648;
  v32 = 0i64;
  v33 = 0;
  v34 = 2147483648;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 32, 32);
  v9 = v4->m_impl;
  v24 = 0i64;
  v25 = 0i64;
  patch.m_addr = &v24;
  *(_WORD *)&patch.m_isVariant.m_bool = 257;
  handle.p0 = 0i64;
  handle.p1 = 0i64;
  if ( v9 )
  {
    v10 = (void **)v9->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v9->vfptr, (unsigned int)&v28);
  }
  else
  {
    v10 = (void **)&v28;
    _mm_store_si128((__m128i *)&v28, (__m128i)handle);
  }
  handle.p0 = *v10;
  handle.p1 = v10[1];
  Copier::resolvePointer(v3, &resulta, &patch, &handle);
  v11 = v3->m_todos.m_size;
  if ( !v11 )
  {
LABEL_21:
    v5->m_object = v24;
    v5->m_class = v25;
    goto LABEL_22;
  }
  while ( 1 )
  {
    v12 = v3->m_todos.m_data;
    v13 = v3->m_todos.m_data[v11 - 1].p0;
    patch.m_addr = v13;
    *(_QWORD *)&patch.m_isVariant.m_bool = *((_QWORD *)&v12[v11] - 1);
    if ( v13 )
      break;
    v3->m_todos.m_size = v11 - 1;
    --v3->m_copyStack.m_size;
LABEL_20:
    v11 = v3->m_todos.m_size;
    if ( !v11 )
      goto LABEL_21;
  }
  if ( v3->m_copyStack.m_size == (v3->m_copyStack.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_copyStack, 16);
    v13 = patch.m_addr;
  }
  v14 = &v3->m_copyStack.m_data[v3->m_copyStack.m_size];
  if ( v14 )
  {
    v14->p0 = v13;
    v14->p1 = *(void **)&patch.m_isVariant.m_bool;
  }
  ++v3->m_copyStack.m_size;
  v15 = v3->m_todos.m_data;
  v16 = v3->m_todos.m_size;
  v15[v16 - 1].p0 = 0i64;
  *((_QWORD *)&v15[v16] - 1) = 0i64;
  (*(void (__fastcall **)(__int64, hkDataObject *, Copier::PointerPatch *))(*(_QWORD *)v8 + 80i64))(v8, &obj, &patch);
  hkDataObjectToNative::allocateObject(&v27, (hkVariant *)&handle, &obj, (hkDataObjectToNative::CopyInfoOut *)&array);
  if ( handle.p0 )
  {
    v17 = -1;
    v18 = (__int64)&v32[16 * (v33 - 1)];
    if ( *(void **)v18 == handle.p0 )
      v17 = *(_DWORD *)(v18 + 8);
    Copier::markAsDone(v3, (hkDataObject_Handle *)&patch, (hkVariant *)&handle, v17);
    hkDataObjectToNative::fillNativeMembers(
      &v27,
      &resulta,
      handle.p0,
      &obj,
      (hkDataObjectToNative::CopyInfoOut *)&array);
    if ( Copier::processPointersAndAllocations(v3, &v36, (hkDataObjectToNative::CopyInfoOut *)&array)->m_enum == HK_SUCCESS )
    {
      v33 = 0;
      v30 = 0;
      if ( v3->m_destroyOnCopy )
        ((void (*)(void))obj.m_impl->vfptr[28].__vecDelDtor)();
      v19 = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        v20 = v19->m_count-- == 1;
        if ( v20 )
          v19->vfptr->__vecDelDtor((hkDataRefCounted *)&v19->vfptr, 1u);
      }
      goto LABEL_20;
    }
  }
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::clear(&v3->m_pointerPatchesFromHandle);
  v3->m_todos.m_size = 0;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clear((hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> > *)&v3->m_liveInfoFromHandle.m_elem);
  v22 = obj.m_impl;
  v5->m_object = 0i64;
  v5->m_class = 0i64;
  if ( v22 )
  {
    --v22->m_externalCount;
    v20 = v22->m_count-- == 1;
    if ( v20 )
      v22->vfptr->__vecDelDtor((hkDataRefCounted *)&v22->vfptr, 1u);
  }
LABEL_22:
  v33 = 0;
  if ( v34 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v32,
      16 * v34);
  v32 = 0i64;
  v34 = 2147483648;
  v30 = 0;
  if ( v31 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      32 * v31);
  return v5;
}

// File Line: 417
// RVA: 0xE4B630
hkObjectResource *__fastcall Copier::toObject(Copier *this, hkDataObject *obj, hkTypeInfoRegistry *typeReg)
{
  Copier *v3; // rbx
  hkTypeInfoRegistry *v4; // rbp
  hkDataObject *v5; // rsi
  _QWORD **v6; // rax
  hkPackfileData *v7; // rax
  hkPackfileData *v8; // rax
  hkPackfileData *v9; // rdi
  hkReferencedObject *v10; // rcx
  hkReferencedObject *v11; // rcx
  hkObjectResource *v12; // rax
  _QWORD **v13; // rax
  hkObjectResource *v14; // rax
  hkObjectResource *v15; // rax
  hkObjectResource *v16; // rdi
  hkPackfileData *v17; // rax
  hkReferencedObject *v18; // rcx
  hkVariant result; // [rsp+20h] [rbp-18h]

  v3 = this;
  v4 = typeReg;
  v5 = obj;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkPackfileData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 168i64);
  if ( v7 )
  {
    hkPackfileData::hkPackfileData(v7, 0i64);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (hkReferencedObject *)&v3->m_trackedData.m_pntr->vfptr;
  if ( v10 && v10 != (hkReferencedObject *)v9 )
    hkReferencedObject::removeReference(v10);
  v3->m_trackedData.m_pntr = v9;
  Copier::deepCopyToNative(v3, &result, v5);
  if ( result.m_object )
  {
    Copier::finishAndRefcountLiveObjects(v3, v4);
    Copier::postFinishObjects(v3);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkObjectResource *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 48i64);
    if ( v14 )
    {
      hkObjectResource::hkObjectResource(v14, &result);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    hkObjectResource::setClassNameRegistry(v16, v3->m_classReg.m_pntr);
    hkObjectResource::setTypeInfoRegistry(v16, v4);
    v17 = v3->m_trackedData.m_pntr;
    v17->m_destructorsEnabled = 0;
    v17->m_memory.m_size = 0;
    v17->m_chunks.m_size = 0;
    v18 = (hkReferencedObject *)&v3->m_trackedData.m_pntr->vfptr;
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v12 = v16;
  }
  else
  {
    v3->m_trackedData.m_pntr->m_destructorsEnabled = 0;
    v11 = (hkReferencedObject *)&v3->m_trackedData.m_pntr->vfptr;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
    v12 = 0i64;
  }
  v3->m_trackedData.m_pntr = 0i64;
  return v12;
}

// File Line: 468
// RVA: 0xE49960
hkObjectResource *__fastcall hkDataObjectUtil::toObject(hkDataObject *src, unsigned int destroyOnCopy)
{
  hkBuiltinTypeRegistry *v2; // rdi
  hkDataObject *v3; // rbp
  unsigned int v4; // esi
  hkTypeInfoRegistry *v5; // rbx
  hkClassNameRegistry *v6; // rax

  v2 = hkSingleton<hkBuiltinTypeRegistry>::s_instance;
  v3 = src;
  v4 = destroyOnCopy;
  v5 = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v6 = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))v2->vfptr[2].__vecDelDtor)(v2);
  return hkDataObjectUtil::toObjectWithRegistry(v3, v6, v5, v4);
}

// File Line: 473
// RVA: 0xE499D0
hkObjectResource *__fastcall hkDataObjectUtil::toObjectWithRegistry(hkDataObject *src, hkClassNameRegistry *classReg, hkTypeInfoRegistry *typeReg, unsigned int destroyOnCopy)
{
  unsigned int v4; // edi
  hkTypeInfoRegistry *v5; // rsi
  hkClassNameRegistry *v6; // rbx
  hkDataObject *v7; // r14
  hkObjectResource *v8; // rbx
  Copier v10; // [rsp+20h] [rbp-39h]

  v4 = destroyOnCopy;
  v5 = typeReg;
  v6 = classReg;
  v7 = src;
  v10.m_todos.m_capacityAndFlags = 2147483648;
  v10.m_todos.m_data = 0i64;
  v10.m_todos.m_size = 0;
  v10.m_pointerPatchesFromHandle.m_valueChain.m_data = 0i64;
  v10.m_pointerPatchesFromHandle.m_valueChain.m_size = 0;
  v10.m_pointerPatchesFromHandle.m_indexMap.m_elem = 0i64;
  v10.m_pointerPatchesFromHandle.m_indexMap.m_numElems = 0;
  v10.m_liveInfoFromHandle.m_elem = 0i64;
  v10.m_liveInfoFromHandle.m_numElems = 0;
  v10.m_copyStack.m_data = 0i64;
  v10.m_copyStack.m_size = 0;
  v10.m_postFinishObjects.m_data = 0i64;
  v10.m_postFinishObjects.m_size = 0;
  v10.m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&v10.m_pointerPatchesFromHandle.m_indexMap.m_hashMod = -1i64;
  v10.m_liveInfoFromHandle.m_hashMod = -1;
  v10.m_copyStack.m_capacityAndFlags = 2147483648;
  v10.m_postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( classReg )
    hkReferencedObject::addReference((hkReferencedObject *)&classReg->vfptr);
  v10.m_classReg.m_pntr = v6;
  v10.m_trackedData.m_pntr = 0i64;
  v10.m_allocatedOnHeap = 1;
  v10.m_destroyOnCopy = v4;
  v8 = Copier::toObject(&v10, v7, v5);
  Copier::~Copier(&v10);
  return v8;
}

// File Line: 479
// RVA: 0xE49780
hkResource *__fastcall hkDataObjectUtil::toResource(hkDataObject *src, unsigned int destroyOnCopy)
{
  hkDataObject *v2; // rdi
  unsigned int v3; // ebx
  hkClassNameRegistry *v4; // rax

  v2 = src;
  v3 = destroyOnCopy;
  v4 = (hkClassNameRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  return hkDataObjectUtil::toResourceWithRegistry(v2, v4, v3);
}

// File Line: 484
// RVA: 0xE497C0
hkPackfileData *__fastcall hkDataObjectUtil::toResourceWithRegistry(hkDataObject *src, hkClassNameRegistry *classReg, unsigned int destroyOnCopy)
{
  hkPackfileData *v3; // rdi
  unsigned int v4; // er14
  hkClassNameRegistry *v5; // rbx
  hkDataObject *v6; // rsi
  _QWORD **v7; // rax
  hkPackfileData *v8; // rax
  hkPackfileData *v9; // rax
  hkPackfileData *v10; // rbx
  void *v11; // r14
  hkClass *v12; // rsi
  hkPackfileData *v13; // rbx
  const char *v14; // rax
  hkPackfileData *v15; // rbx
  Copier v17; // [rsp+20h] [rbp-39h]
  hkVariant result; // [rsp+A0h] [rbp+47h]

  v3 = 0i64;
  v4 = destroyOnCopy;
  v5 = classReg;
  v6 = src;
  v17.m_todos.m_capacityAndFlags = 2147483648;
  v17.m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 2147483648;
  v17.m_todos.m_data = 0i64;
  v17.m_todos.m_size = 0;
  v17.m_pointerPatchesFromHandle.m_valueChain.m_data = 0i64;
  v17.m_pointerPatchesFromHandle.m_valueChain.m_size = 0;
  v17.m_pointerPatchesFromHandle.m_indexMap.m_elem = 0i64;
  v17.m_pointerPatchesFromHandle.m_indexMap.m_numElems = 0;
  v17.m_liveInfoFromHandle.m_elem = 0i64;
  v17.m_liveInfoFromHandle.m_numElems = 0;
  v17.m_copyStack.m_data = 0i64;
  v17.m_copyStack.m_size = 0;
  v17.m_postFinishObjects.m_data = 0i64;
  v17.m_postFinishObjects.m_size = 0;
  *(_QWORD *)&v17.m_pointerPatchesFromHandle.m_indexMap.m_hashMod = -1i64;
  v17.m_liveInfoFromHandle.m_hashMod = -1;
  v17.m_copyStack.m_capacityAndFlags = 2147483648;
  v17.m_postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( classReg )
    hkReferencedObject::addReference((hkReferencedObject *)&classReg->vfptr);
  v17.m_classReg.m_pntr = v5;
  v17.m_trackedData.m_pntr = 0i64;
  v17.m_allocatedOnHeap = 0;
  v17.m_destroyOnCopy = v4;
  if ( v6->m_impl )
  {
    v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkPackfileData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 168i64);
    if ( v8 )
    {
      hkPackfileData::hkPackfileData(v8, v17.m_classReg.m_pntr);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v17.m_trackedData.m_pntr && v17.m_trackedData.m_pntr != v10 )
      hkReferencedObject::removeReference((hkReferencedObject *)&v17.m_trackedData.m_pntr->vfptr);
    v17.m_trackedData.m_pntr = v10;
    Copier::deepCopyToNative(&v17, &result, v6);
    v11 = result.m_object;
    if ( result.m_object && (v12 = result.m_class) != 0i64 )
    {
      Copier::finishAndTrackObjectsInPackfile(&v17, v17.m_trackedData.m_pntr);
      v13 = v17.m_trackedData.m_pntr;
      v14 = hkClass::getName(v12);
      hkPackfileData::setContentsWithName(v13, v11, v14);
      v15 = v17.m_trackedData.m_pntr;
      hkReferencedObject::addReference((hkReferencedObject *)&v17.m_trackedData.m_pntr->vfptr);
      if ( v17.m_trackedData.m_pntr )
        hkReferencedObject::removeReference((hkReferencedObject *)&v17.m_trackedData.m_pntr->vfptr);
      v17.m_trackedData.m_pntr = 0i64;
      v3 = v15;
    }
    else
    {
      if ( v17.m_trackedData.m_pntr )
        hkReferencedObject::removeReference((hkReferencedObject *)&v17.m_trackedData.m_pntr->vfptr);
      v17.m_trackedData.m_pntr = 0i64;
    }
  }
  Copier::~Copier(&v17);
  return v3;
}

// File Line: 561
// RVA: 0xE49AC0
hkTypeManager::Type *__fastcall hkDataObjectUtil::getBasicType(hkTypeManager *typeManager, hkClassMember::Type type, const char *typeName)
{
  hkTypeManager *v3; // rbx
  TypeInfo *v4; // rcx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  hkTypeManager::Type *result; // rax
  hkTypeManager::Type *v10; // rax

  v3 = typeManager;
  v4 = &s_lut[type];
  v5 = (unsigned __int8)s_lut[type].m_type - 1;
  if ( !v5 )
    return v3->m_builtInTypes[(unsigned __int8)v4->m_subType];
  v6 = v5 - 3;
  if ( !v6 )
    return hkTypeManager::makeTuple(
             v3,
             v3->m_builtInTypes[(unsigned __int8)v4->m_subType],
             (unsigned __int8)v4->m_tupleSize);
  v7 = v6 - 1;
  if ( v7 )
  {
    v8 = v7 - 1;
    if ( v8 )
    {
      if ( v8 == 1 )
        result = hkTypeManager::makePointer(v3, v3->m_homogenousClass);
      else
        result = 0i64;
    }
    else
    {
      result = hkTypeManager::addClass(v3, typeName);
    }
  }
  else if ( typeName )
  {
    v10 = hkTypeManager::addClass(v3, typeName);
    result = hkTypeManager::makePointer(v3, v10);
  }
  else
  {
    result = hkTypeManager::makePointer(v3, v3->m_homogenousClass);
  }
  return result;
}

// File Line: 608
// RVA: 0xE49BD0
hkTypeManager::Type *__fastcall hkDataObjectUtil::getTypeFromMemberTypeClassName(hkTypeManager *typeManager, hkClassMember::Type mtype, hkClassMember::Type stype, const char *typeName, int count)
{
  hkClassMember::Type v5; // er11
  hkTypeManager::Type *v6; // r10
  hkTypeManager *v7; // rbx
  TypeInfo *v8; // r8
  const char *v9; // r8
  hkTypeManager::Type *v10; // rax
  hkTypeManager::Type *v11; // rax
  hkTypeManager::Type *v12; // rax

  v5 = stype;
  v6 = 0i64;
  v7 = typeManager;
  v8 = &s_lut[mtype];
  switch ( v8->m_type )
  {
    case 1:
      v6 = typeManager->m_builtInTypes[(unsigned __int8)v8->m_subType];
      break;
    case 2:
      if ( v5 == 25 )
        v12 = hkTypeManager::addClass(typeManager, typeName);
      else
        v12 = hkDataObjectUtil::getBasicType(typeManager, v5, typeName);
      if ( count )
        v12 = hkTypeManager::makeTuple(v7, v12, count);
      return hkTypeManager::makeArray(v7, v12);
    case 3:
      v9 = 0i64;
      mtype = v5;
      goto LABEL_13;
    case 4:
      v11 = hkTypeManager::makeTuple(
              typeManager,
              typeManager->m_builtInTypes[(unsigned __int8)v8->m_subType],
              (unsigned __int8)v8->m_tupleSize);
      goto LABEL_14;
    case 5:
      v10 = hkDataObjectUtil::getBasicType(typeManager, v5, typeName);
      v11 = hkTypeManager::makePointer(v7, v10);
      goto LABEL_14;
    case 6:
    case 7:
      v9 = typeName;
LABEL_13:
      v11 = hkDataObjectUtil::getBasicType(typeManager, mtype, v9);
LABEL_14:
      v6 = v11;
      break;
    default:
      break;
  }
  if ( count )
    v6 = hkTypeManager::makeTuple(v7, v6, count);
  return v6;
}

// File Line: 680
// RVA: 0xE49B80
hkTypeManager::Type *__fastcall hkDataObjectUtil::getTypeFromMemberType(hkTypeManager *typeManager, hkClassMember::Type mtype, hkClassMember::Type stype, hkClass *klass, int count)
{
  hkClassMember::Type v5; // ebx
  hkClassMember::Type v6; // edi
  hkTypeManager *v7; // rsi
  hkClass *v8; // rax

  v5 = stype;
  v6 = mtype;
  v7 = typeManager;
  if ( klass )
  {
    v8 = (hkClass *)hkClass::getName(klass);
    stype = v5;
    mtype = v6;
    klass = v8;
    typeManager = v7;
  }
  return hkDataObjectUtil::getTypeFromMemberTypeClassName(typeManager, mtype, stype, (const char *)klass, count);
}

// File Line: 692
// RVA: 0xE49D00
hkResult *__fastcall hkDataObjectUtil::deepCopyWorld(hkResult *result, hkDataWorld *dst, hkDataWorld *src)
{
  hkResult *v3; // rbx
  hkDataWorldCloner *v4; // rax
  hkDataWorldCloner v6; // [rsp+20h] [rbp-28h]

  v3 = result;
  hkDataWorldCloner::hkDataWorldCloner(&v6, dst, src);
  hkDataWorldCloner::clone(v4, v3);
  hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle> > *)&v6.m_copied.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  return v3;
}

// File Line: 697
// RVA: 0xE49D40
__int64 __fastcall hkDataObjectUtil::getExtraStorageSize(hkClass *klass, hkDataObject *obj)
{
  unsigned int v2; // er15
  hkDataObject *v3; // r12
  hkClass *v4; // rbp
  int i; // edi
  hkClassMember *v6; // rax
  hkClassMember *v7; // r14
  __int64 v8; // rax
  __int64 v9; // rbx
  int v10; // esi
  int v11; // eax
  bool v12; // zf
  __int64 v14; // [rsp+20h] [rbp-28h]
  __int64 v15; // [rsp+28h] [rbp-20h]

  v2 = 0;
  v3 = obj;
  v4 = klass;
  for ( i = 0; i < (signed int)hkClass::getNumMembers(v4); ++i )
  {
    v6 = hkClass::getMember(v4, i);
    v7 = v6;
    if ( v6->m_type.m_storage == 34 )
    {
      ((void (__fastcall *)(hkDataObjectImpl *, __int64 *, const char *))v3->m_impl->vfptr[3].__vecDelDtor)(
        v3->m_impl,
        &v14,
        v6->m_name);
      v8 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 80i64))(v14, v15);
      v9 = v8;
      if ( v8 )
      {
        ++*(_WORD *)(v8 + 10);
        ++*(_DWORD *)(v8 + 12);
      }
      v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 40i64))(v9);
      hkClassMember::getArrayMemberSize(v7);
      v11 = hkClassMember::getArrayMemberSize(v7);
      --*(_WORD *)(v9 + 10);
      v2 += (v10 * v11 + 15) & 0xFFFFFFF0;
      v12 = (*(_DWORD *)(v9 + 12))-- == 1;
      if ( v12 )
        (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
    }
  }
  return v2;
}

