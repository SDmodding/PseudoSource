// File Line: 108
// RVA: 0xE49E50
void __fastcall Copier::~Copier(Copier *this)
{
  hkPackfileData *m_pntr; // rcx
  hkClassNameRegistry *v3; // rcx
  int m_capacityAndFlags; // r8d
  int v5; // r8d
  int v6; // eax
  int v7; // r8d

  m_pntr = this->m_trackedData.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_trackedData.m_pntr = 0i64;
  v3 = this->m_classReg.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_classReg.m_pntr = 0i64;
  m_capacityAndFlags = this->m_postFinishObjects.m_capacityAndFlags;
  this->m_postFinishObjects.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_postFinishObjects.m_data,
      16 * m_capacityAndFlags);
  this->m_postFinishObjects.m_data = 0i64;
  this->m_postFinishObjects.m_capacityAndFlags = 0x80000000;
  v5 = this->m_copyStack.m_capacityAndFlags;
  this->m_copyStack.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_copyStack.m_data,
      16 * v5);
  this->m_copyStack.m_data = 0i64;
  this->m_copyStack.m_capacityAndFlags = 0x80000000;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(
    &this->m_liveInfoFromHandle,
    &hkContainerHeapAllocator::s_alloc);
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_pointerPatchesFromHandle.m_indexMap,
    &hkContainerHeapAllocator::s_alloc);
  v6 = this->m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags;
  this->m_pointerPatchesFromHandle.m_valueChain.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_pointerPatchesFromHandle.m_valueChain.m_data,
      24 * (v6 & 0x3FFFFFFF));
  this->m_pointerPatchesFromHandle.m_valueChain.m_data = 0i64;
  this->m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 0x80000000;
  v7 = this->m_todos.m_capacityAndFlags;
  this->m_todos.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_todos.m_data, 16 * v7);
  this->m_todos.m_capacityAndFlags = 0x80000000;
  this->m_todos.m_data = 0i64;
}

// File Line: 121
// RVA: 0xE4ACD0
void __fastcall Copier::markAsDone(Copier *this, hkVariant *handle, hkVariant *v, int objectSize)
{
  int v6; // r14d
  int v9; // esi
  int i; // eax
  __int64 v11; // rcx
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *m_data; // rax
  __int64 v13; // r8
  __int64 v14; // rcx
  void **v15; // rdx
  hkClass *m_class; // rbx
  bool v17; // zf
  int v18; // eax
  hkVariant v19; // [rsp+20h] [rbp-40h] BYREF
  __int64 v20; // [rsp+30h] [rbp-30h]
  Copier::LiveObjectInfo v21; // [rsp+40h] [rbp-20h] BYREF
  hkBool v22; // [rsp+A0h] [rbp+40h] BYREF
  hkBool result; // [rsp+B8h] [rbp+58h] BYREF

  v6 = 0;
  v9 = 0;
  v19 = *handle;
  for ( i = hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
              &this->m_pointerPatchesFromHandle,
              (hkDataObject_Handle *)&v19);
        i != -1;
        i = *(int *)((char *)&this->m_pointerPatchesFromHandle.m_valueChain.m_data->next + v13) )
  {
    v11 = 3i64 * i;
    m_data = this->m_pointerPatchesFromHandle.m_valueChain.m_data;
    v13 = 8 * v11;
    v14 = *(_QWORD *)&m_data[(unsigned __int64)v11 / 3].value.m_isVariant.m_bool;
    v15 = *(void ***)((char *)&m_data->value.m_addr + v13);
    *v15 = v->m_object;
    if ( (_BYTE)v14 )
      v15[1] = v->m_class;
    v9 += BYTE1(v14) != 0;
  }
  v19 = *handle;
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::removeKey(
    &this->m_pointerPatchesFromHandle,
    (hkDataObject_Handle *)&v19);
  v19 = *v;
  m_class = v19.m_class;
  if ( !hkClass::hasVtable(v19.m_class, &result)->m_bool
    || (v17 = hkClass::isSuperClass(&hkReferencedObjectClass, &v22, m_class)->m_bool == 0, v18 = 1, v17) )
  {
    v18 = 0;
  }
  HIDWORD(v20) = objectSize;
  if ( v18 )
    v6 = v9;
  LODWORD(v20) = v6;
  v21.m_variant = v19;
  v19 = *handle;
  *(_QWORD *)&v21.m_refCount = v20;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::insert(
    &this->m_liveInfoFromHandle,
    &hkContainerHeapAllocator::s_alloc,
    (hkDataObject_Handle *)&v19,
    &v21);
}

// File Line: 153
// RVA: 0xE4B400
hkResult *__fastcall Copier::resolvePointer(
        Copier *this,
        hkResult *result,
        Copier::PointerPatch *patch,
        hkDataObject_Handle *handle)
{
  __int64 m_size; // r8
  int v9; // r10d
  __int64 v10; // r9
  hkDataObject_Handle *m_data; // rcx
  int Key; // eax
  bool v13; // zf
  __int64 v14; // rcx
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *m_elem; // rax
  void *m_object; // rdx
  hkClass *m_class; // r8
  _QWORD *m_addr; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v19; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v20; // rcx
  __int64 v21; // rax
  hkDataObject_Handle *v22; // rcx
  int FirstIndex; // eax
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator> >::Value *v24; // r8
  hkDataObject_Handle *v25; // rdx
  hkDataObject_Handle v27; // [rsp+20h] [rbp-28h] BYREF
  __int64 v28; // [rsp+30h] [rbp-18h]

  if ( !this->m_allocatedOnHeap )
    goto LABEL_8;
  if ( !patch->m_isOwning.m_bool )
    goto LABEL_8;
  m_size = this->m_copyStack.m_size;
  v9 = 0;
  v10 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_8;
  m_data = this->m_copyStack.m_data;
  while ( m_data->p0 != handle->p0 || m_data->p1 != handle->p1 )
  {
    ++v10;
    ++v9;
    ++m_data;
    if ( v10 >= m_size )
      goto LABEL_8;
  }
  if ( v9 == -1 )
  {
LABEL_8:
    v27 = *handle;
    Key = (unsigned int)hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::findKey(
                          &this->m_liveInfoFromHandle,
                          &v27);
    if ( Key <= this->m_liveInfoFromHandle.m_hashMod )
    {
      v13 = patch->m_isVariant.m_bool == 0;
      v14 = Key;
      m_elem = this->m_liveInfoFromHandle.m_elem;
      m_object = m_elem[v14].val.m_variant.m_object;
      m_class = m_elem[v14].val.m_variant.m_class;
      v28 = *(_QWORD *)&m_elem[v14].val.m_refCount;
      m_addr = patch->m_addr;
      *(_QWORD *)patch->m_addr = m_object;
      if ( !v13 )
        m_addr[1] = m_class;
      LODWORD(v28) = (patch->m_isOwning.m_bool != 0) + (_DWORD)v28;
      v19 = this->m_liveInfoFromHandle.m_elem;
      v19[v14].val.m_variant.m_object = m_object;
      v20 = &v19[v14];
      v21 = v28;
      v20->val.m_variant.m_class = m_class;
      *(_QWORD *)&v20->val.m_refCount = v21;
      goto LABEL_33;
    }
    v27 = *handle;
    if ( hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
           &this->m_pointerPatchesFromHandle,
           &v27) == -1 )
    {
      if ( patch->m_isOwning.m_bool )
      {
        if ( this->m_todos.m_size == (this->m_todos.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_todos.m_data, 16);
        v22 = &this->m_todos.m_data[this->m_todos.m_size];
        if ( v22 )
        {
          v22->p0 = handle->p0;
          v22->p1 = handle->p1;
        }
LABEL_31:
        ++this->m_todos.m_size;
      }
    }
    else if ( patch->m_isOwning.m_bool )
    {
      v27 = *handle;
      FirstIndex = hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::getFirstIndex(
                     &this->m_pointerPatchesFromHandle,
                     &v27);
      if ( FirstIndex != -1 )
      {
        v24 = this->m_pointerPatchesFromHandle.m_valueChain.m_data;
        while ( !v24[FirstIndex].value.m_isOwning.m_bool )
        {
          FirstIndex = v24[FirstIndex].next;
          if ( FirstIndex == -1 )
            goto LABEL_27;
        }
        goto LABEL_32;
      }
LABEL_27:
      if ( this->m_todos.m_size == (this->m_todos.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_todos.m_data, 16);
      v25 = &this->m_todos.m_data[this->m_todos.m_size];
      if ( v25 )
      {
        v25->p0 = handle->p0;
        v25->p1 = handle->p1;
      }
      goto LABEL_31;
    }
LABEL_32:
    v27 = *handle;
    hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::insert(
      &this->m_pointerPatchesFromHandle,
      &v27,
      patch);
LABEL_33:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 215
// RVA: 0xE4A740
void __fastcall Copier::finishAndTrackObjectsInPackfile(Copier *this, hkPackfileData *trackedData)
{
  int v2; // r9d
  __int64 m_hashMod; // rcx
  __int64 v6; // r8
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *m_elem; // rax
  int v8; // edi
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v9; // rax
  hkClass *m_class; // rbp
  unsigned __int64 m_object; // r14
  const char *Name; // rax
  hkVariant *v13; // rax
  __int64 v14; // r10
  int v15; // r9d
  __int64 v16; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v17; // r8

  v2 = 0;
  m_hashMod = this->m_liveInfoFromHandle.m_hashMod;
  v6 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_liveInfoFromHandle.m_elem;
    do
    {
      if ( m_elem->key.p0 != (void *)-1i64 )
        break;
      ++v6;
      ++v2;
      ++m_elem;
    }
    while ( v6 <= m_hashMod );
  }
  v8 = v2;
  if ( v2 <= this->m_liveInfoFromHandle.m_hashMod )
  {
    do
    {
      v9 = this->m_liveInfoFromHandle.m_elem;
      m_class = v9[v8].val.m_variant.m_class;
      m_object = (unsigned __int64)v9[v8].val.m_variant.m_object;
      Name = hkClass::getName(m_class);
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &trackedData->m_trackedObjects.m_map,
        &hkContainerHeapAllocator::s_alloc,
        m_object,
        (unsigned __int64)Name);
      if ( hkClass::getAttribute(m_class, "hk.PostFinish") )
      {
        if ( trackedData->m_postFinishObjects.m_size == (trackedData->m_postFinishObjects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&trackedData->m_postFinishObjects.m_data,
            16);
        v13 = &trackedData->m_postFinishObjects.m_data[trackedData->m_postFinishObjects.m_size];
        if ( v13 )
        {
          v13->m_object = (void *)m_object;
          v13->m_class = m_class;
        }
        ++trackedData->m_postFinishObjects.m_size;
      }
      v14 = this->m_liveInfoFromHandle.m_hashMod;
      v15 = v8 + 1;
      v16 = v8 + 1;
      if ( v16 <= v14 )
      {
        v17 = &this->m_liveInfoFromHandle.m_elem[v15];
        do
        {
          if ( v17->key.p0 != (void *)-1i64 )
            break;
          ++v16;
          ++v15;
          ++v17;
        }
        while ( v16 <= v14 );
      }
      v8 = v15;
    }
    while ( v15 <= this->m_liveInfoFromHandle.m_hashMod );
  }
}

// File Line: 233
// RVA: 0xE4A5C0
void __fastcall Copier::finishAndRefcountLiveObjects(Copier *this, hkTypeInfoRegistry *typeReg)
{
  int v2; // r9d
  __int64 m_hashMod; // rcx
  __int64 v6; // r8
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *m_elem; // rax
  int v8; // ebp
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v9; // rax
  __int64 v10; // r15
  hkClass *m_class; // r14
  _WORD *m_object; // rdi
  hkVariant *v13; // rax
  __int16 ObjectSize; // ax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  __int64 v17; // r10
  int v18; // r9d
  __int64 v19; // rax
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle> >::Pair *v20; // r8
  hkBool result; // [rsp+70h] [rbp+8h] BYREF

  v2 = 0;
  m_hashMod = this->m_liveInfoFromHandle.m_hashMod;
  v6 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = this->m_liveInfoFromHandle.m_elem;
    do
    {
      if ( m_elem->key.p0 != (void *)-1i64 )
        break;
      ++v6;
      ++v2;
      ++m_elem;
    }
    while ( v6 <= m_hashMod );
  }
  v8 = v2;
  if ( v2 <= this->m_liveInfoFromHandle.m_hashMod )
  {
    do
    {
      v9 = this->m_liveInfoFromHandle.m_elem;
      v10 = *(_QWORD *)&v9[v8].val.m_refCount;
      m_class = v9[v8].val.m_variant.m_class;
      m_object = v9[v8].val.m_variant.m_object;
      if ( hkClass::getAttribute(m_class, "hk.PostFinish") )
      {
        if ( this->m_postFinishObjects.m_size == (this->m_postFinishObjects.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_postFinishObjects.m_data,
            16);
        v13 = &this->m_postFinishObjects.m_data[this->m_postFinishObjects.m_size];
        if ( v13 )
        {
          v13->m_object = m_object;
          v13->m_class = m_class;
        }
        ++this->m_postFinishObjects.m_size;
      }
      if ( (__int16)v10 > 0 )
      {
        ObjectSize = WORD2(v10);
        if ( SHIDWORD(v10) <= -1 )
          ObjectSize = hkClass::getObjectSize(m_class);
        m_object[4] = ObjectSize;
        m_object[5] = v10;
      }
      vfptr = typeReg->vfptr;
      Name = hkClass::getName(m_class);
      ((void (__fastcall *)(hkTypeInfoRegistry *, _WORD *, const char *))vfptr[2].__vecDelDtor)(typeReg, m_object, Name);
      hkClass::hasVtable(m_class, &result);
      v17 = this->m_liveInfoFromHandle.m_hashMod;
      v18 = v8 + 1;
      v19 = v8 + 1;
      if ( v19 <= v17 )
      {
        v20 = &this->m_liveInfoFromHandle.m_elem[v18];
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
    while ( v18 <= this->m_liveInfoFromHandle.m_hashMod );
  }
}

// File Line: 283
// RVA: 0xE4AE10
void __fastcall Copier::postFinishObjects(Copier *this)
{
  hkVariant *m_data; // rbx
  void *m_object; // rdi
  hkVariant *Attribute; // rax

  m_data = this->m_postFinishObjects.m_data;
  if ( m_data < &m_data[this->m_postFinishObjects.m_size] )
  {
    do
    {
      m_object = m_data->m_object;
      Attribute = hkClass::getAttribute(m_data->m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))Attribute->m_object)(m_object);
      ++m_data;
    }
    while ( m_data < &this->m_postFinishObjects.m_data[this->m_postFinishObjects.m_size] );
  }
}

// File Line: 299
// RVA: 0xE4AE80
hkResult *__fastcall Copier::processPointersAndAllocations(
        Copier *this,
        hkResult *result,
        hkDataObjectToNative::CopyInfoOut *infoOut)
{
  int v3; // edi
  __int64 v7; // r14
  hkDataObjectToNative::Alloc *m_data; // rcx
  hkPackfileData *m_pntr; // rbx
  void *m_addr; // rbp
  int m_capacityAndFlags; // eax
  hkPackfileData::Chunk *v12; // rcx
  __int64 v13; // rax
  int v14; // ebx
  __int64 v15; // rdi
  hkDataObjectToNative::PointerInfo *v16; // r9
  Copier::PointerPatch patch; // [rsp+20h] [rbp-38h] BYREF
  hkResult resulta; // [rsp+70h] [rbp+18h] BYREF

  v3 = 0;
  if ( infoOut->allocs.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      m_data = infoOut->allocs.m_data;
      m_pntr = this->m_trackedData.m_pntr;
      m_addr = m_data[v7].m_addr;
      if ( m_data[v7].m_size == -1 )
      {
        if ( m_pntr->m_memory.m_size == (m_pntr->m_memory.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_pntr->m_memory.m_data, 8);
        m_pntr->m_memory.m_data[m_pntr->m_memory.m_size++] = m_addr;
      }
      else
      {
        *(_DWORD *)&patch.m_isVariant.m_bool = m_data[v7].m_size;
        m_capacityAndFlags = m_pntr->m_chunks.m_capacityAndFlags;
        *(_DWORD *)(&patch.m_isOwning + 3) = 7;
        if ( m_pntr->m_chunks.m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_pntr->m_chunks.m_data, 16);
        v12 = &m_pntr->m_chunks.m_data[m_pntr->m_chunks.m_size];
        if ( v12 )
        {
          v13 = *(_QWORD *)&patch.m_isVariant.m_bool;
          v12->pointer = m_addr;
          *(_QWORD *)&v12->numBytes = v13;
        }
        ++m_pntr->m_chunks.m_size;
      }
      ++v3;
      ++v7;
    }
    while ( v3 < infoOut->allocs.m_size );
  }
  v14 = 0;
  if ( infoOut->pointersOut.m_size <= 0 )
  {
LABEL_17:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  else
  {
    v15 = 0i64;
    while ( 1 )
    {
      v16 = &infoOut->pointersOut.m_data[v15];
      patch = *(Copier::PointerPatch *)&v16->m_addr;
      if ( Copier::resolvePointer(this, &resulta, &patch, &v16->m_handle)->m_enum == HK_FAILURE )
        break;
      ++v14;
      ++v15;
      if ( v14 >= infoOut->pointersOut.m_size )
        goto LABEL_17;
    }
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 337
// RVA: 0xE4A160
hkVariant *__fastcall Copier::deepCopyToNative(Copier *this, hkVariant *result, hkDataObject *topObj)
{
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // r14
  hkDataObjectImpl *m_impl; // rcx
  hkDataObject_Handle *v10; // rcx
  int m_size; // edx
  hkDataObject_Handle *m_data; // rax
  void *p0; // r8
  hkDataObject_Handle *v14; // rcx
  hkDataObject_Handle *v15; // rax
  __int64 v16; // rcx
  int v17; // r9d
  hkDataObjectToNative::Alloc *v18; // rcx
  hkDataObjectImpl *v19; // rcx
  bool v20; // zf
  hkDataObjectImpl *v22; // rcx
  Copier::PointerPatch patch; // [rsp+30h] [rbp-39h] BYREF
  void *v24; // [rsp+40h] [rbp-29h] BYREF
  hkClass *v25; // [rsp+48h] [rbp-21h]
  hkDataObject_Handle handle; // [rsp+50h] [rbp-19h] BYREF
  hkDataObjectToNative v27; // [rsp+60h] [rbp-9h] BYREF
  hkDataObject_Handle v28; // [rsp+70h] [rbp+7h] BYREF
  hkDataObjectToNative::CopyInfoOut array[2]; // [rsp+80h] [rbp+17h] BYREF
  hkResult resulta; // [rsp+D0h] [rbp+67h] BYREF
  hkResult v31; // [rsp+E0h] [rbp+77h] BYREF
  hkDataObject obj; // [rsp+E8h] [rbp+7Fh] BYREF

  v6 = ((__int64 (__fastcall *)(hkDataObjectImpl *))topObj->m_impl->vfptr[2].__vecDelDtor)(topObj->m_impl);
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
  v27.m_classReg = this->m_classReg.m_pntr;
  v27.m_allocatedOnHeap = this->m_allocatedOnHeap;
  v8 = v7;
  array[0].pointersOut.m_data = 0i64;
  array[0].pointersOut.m_size = 0;
  array[0].pointersOut.m_capacityAndFlags = 0x80000000;
  array[0].allocs.m_data = 0i64;
  array[0].allocs.m_size = 0;
  array[0].allocs.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(
    &resulta,
    &hkContainerTempAllocator::s_alloc,
    (const void **)&array[0].pointersOut.m_data,
    32,
    32);
  m_impl = topObj->m_impl;
  v24 = 0i64;
  v25 = 0i64;
  patch.m_addr = &v24;
  *(_WORD *)&patch.m_isVariant.m_bool = 257;
  handle.p0 = 0i64;
  handle.p1 = 0i64;
  if ( m_impl )
  {
    v10 = (hkDataObject_Handle *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v28);
  }
  else
  {
    v10 = &v28;
    v28 = handle;
  }
  handle = *v10;
  Copier::resolvePointer(this, &resulta, &patch, &handle);
  m_size = this->m_todos.m_size;
  if ( !m_size )
  {
LABEL_21:
    result->m_object = v24;
    result->m_class = v25;
    goto LABEL_22;
  }
  while ( 1 )
  {
    m_data = this->m_todos.m_data;
    p0 = this->m_todos.m_data[m_size - 1].p0;
    patch.m_addr = p0;
    *(_QWORD *)&patch.m_isVariant.m_bool = m_data[m_size - 1].p1;
    if ( p0 )
      break;
    this->m_todos.m_size = m_size - 1;
    --this->m_copyStack.m_size;
LABEL_20:
    m_size = this->m_todos.m_size;
    if ( !m_size )
      goto LABEL_21;
  }
  if ( this->m_copyStack.m_size == (this->m_copyStack.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_copyStack.m_data, 16);
    p0 = patch.m_addr;
  }
  v14 = &this->m_copyStack.m_data[this->m_copyStack.m_size];
  if ( v14 )
  {
    v14->p0 = p0;
    v14->p1 = *(void **)&patch.m_isVariant.m_bool;
  }
  ++this->m_copyStack.m_size;
  v15 = this->m_todos.m_data;
  v16 = this->m_todos.m_size;
  v15[v16 - 1].p0 = 0i64;
  v15[v16 - 1].p1 = 0i64;
  (*(void (__fastcall **)(__int64, hkDataObject *, Copier::PointerPatch *))(*(_QWORD *)v8 + 80i64))(v8, &obj, &patch);
  hkDataObjectToNative::allocateObject(&v27, (hkVariant *)&handle, &obj, array);
  if ( handle.p0 )
  {
    v17 = -1;
    v18 = &array[0].allocs.m_data[array[0].allocs.m_size - 1];
    if ( v18->m_addr == handle.p0 )
      v17 = v18->m_size;
    Copier::markAsDone(this, (hkDataObject_Handle *)&patch, (hkVariant *)&handle, v17);
    hkDataObjectToNative::fillNativeMembers(&v27, &resulta, handle.p0, &obj, array);
    if ( Copier::processPointersAndAllocations(this, &v31, array)->m_enum == HK_SUCCESS )
    {
      array[0].allocs.m_size = 0;
      array[0].pointersOut.m_size = 0;
      if ( this->m_destroyOnCopy )
        ((void (__fastcall *)(hkDataObjectImpl *))obj.m_impl->vfptr[28].__vecDelDtor)(obj.m_impl);
      v19 = obj.m_impl;
      if ( obj.m_impl )
      {
        --obj.m_impl->m_externalCount;
        v20 = v19->m_count-- == 1;
        if ( v20 )
          v19->vfptr->__vecDelDtor(v19, 1u);
      }
      goto LABEL_20;
    }
  }
  hkSerializeMultiMap<hkDataObject_Handle,Copier::PointerPatch,hkMap<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>,hkContainerHeapAllocator>>::clear(&this->m_pointerPatchesFromHandle);
  this->m_todos.m_size = 0;
  hkMapBase<hkDataObject_Handle,Copier::LiveObjectInfo,hkMapOperations<hkDataObject_Handle>>::clear(&this->m_liveInfoFromHandle);
  v22 = obj.m_impl;
  result->m_object = 0i64;
  result->m_class = 0i64;
  if ( v22 )
  {
    --v22->m_externalCount;
    v20 = v22->m_count-- == 1;
    if ( v20 )
      v22->vfptr->__vecDelDtor(v22, 1u);
  }
LABEL_22:
  array[0].allocs.m_size = 0;
  if ( array[0].allocs.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array[0].allocs.m_data,
      16 * array[0].allocs.m_capacityAndFlags);
  array[0].allocs.m_data = 0i64;
  array[0].allocs.m_capacityAndFlags = 0x80000000;
  array[0].pointersOut.m_size = 0;
  if ( array[0].pointersOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array[0].pointersOut.m_data,
      32 * array[0].pointersOut.m_capacityAndFlags);
  return result;
}

// File Line: 417
// RVA: 0xE4B630
hkObjectResource *__fastcall Copier::toObject(Copier *this, hkDataObject *obj, hkTypeInfoRegistry *typeReg)
{
  _QWORD **Value; // rax
  hkPackfileData *v7; // rax
  hkPackfileData *v8; // rax
  hkPackfileData *v9; // rdi
  hkPackfileData *m_pntr; // rcx
  hkPackfileData *v11; // rcx
  hkObjectResource *v12; // rax
  _QWORD **v13; // rax
  hkObjectResource *v14; // rax
  hkObjectResource *v15; // rax
  hkObjectResource *v16; // rdi
  hkPackfileData *v17; // rax
  hkPackfileData *v18; // rcx
  hkVariant result; // [rsp+20h] [rbp-18h] BYREF

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkPackfileData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 168i64);
  if ( v7 )
  {
    hkPackfileData::hkPackfileData(v7, 0i64);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  m_pntr = this->m_trackedData.m_pntr;
  if ( m_pntr && m_pntr != v9 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_trackedData.m_pntr = v9;
  Copier::deepCopyToNative(this, &result, obj);
  if ( result.m_object )
  {
    Copier::finishAndRefcountLiveObjects(this, typeReg);
    Copier::postFinishObjects(this);
    v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v14 = (hkObjectResource *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 48i64);
    if ( v14 )
    {
      hkObjectResource::hkObjectResource(v14, &result);
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    hkObjectResource::setClassNameRegistry(v16, this->m_classReg.m_pntr);
    hkObjectResource::setTypeInfoRegistry(v16, typeReg);
    v17 = this->m_trackedData.m_pntr;
    v17->m_destructorsEnabled = 0;
    v17->m_memory.m_size = 0;
    v17->m_chunks.m_size = 0;
    v18 = this->m_trackedData.m_pntr;
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v12 = v16;
  }
  else
  {
    this->m_trackedData.m_pntr->m_destructorsEnabled = 0;
    v11 = this->m_trackedData.m_pntr;
    if ( v11 )
      hkReferencedObject::removeReference(v11);
    v12 = 0i64;
  }
  this->m_trackedData.m_pntr = 0i64;
  return v12;
}

// File Line: 468
// RVA: 0xE49960
hkObjectResource *__fastcall hkDataObjectUtil::toObject(hkDataObject *src, unsigned int destroyOnCopy)
{
  hkBuiltinTypeRegistry *v2; // rdi
  hkTypeInfoRegistry *v5; // rbx
  hkClassNameRegistry *v6; // rax

  v2 = hkSingleton<hkBuiltinTypeRegistry>::s_instance;
  v5 = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v6 = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))v2->vfptr[2].__vecDelDtor)(v2);
  return hkDataObjectUtil::toObjectWithRegistry(src, v6, v5, destroyOnCopy);
}

// File Line: 473
// RVA: 0xE499D0
hkObjectResource *__fastcall hkDataObjectUtil::toObjectWithRegistry(
        hkDataObject *src,
        hkClassNameRegistry *classReg,
        hkTypeInfoRegistry *typeReg,
        unsigned int destroyOnCopy)
{
  hkObjectResource *v8; // rbx
  Copier v10; // [rsp+20h] [rbp-39h] BYREF

  v10.m_todos.m_capacityAndFlags = 0x80000000;
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
  v10.m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&v10.m_pointerPatchesFromHandle.m_indexMap.m_hashMod = -1i64;
  v10.m_liveInfoFromHandle.m_hashMod = -1;
  v10.m_copyStack.m_capacityAndFlags = 0x80000000;
  v10.m_postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( classReg )
    hkReferencedObject::addReference(classReg);
  v10.m_classReg.m_pntr = classReg;
  v10.m_trackedData.m_pntr = 0i64;
  v10.m_allocatedOnHeap = 1;
  v10.m_destroyOnCopy = destroyOnCopy;
  v8 = Copier::toObject(&v10, src, typeReg);
  Copier::~Copier(&v10);
  return v8;
}

// File Line: 479
// RVA: 0xE49780
hkResource *__fastcall hkDataObjectUtil::toResource(hkDataObject *src, unsigned int destroyOnCopy)
{
  hkClassNameRegistry *v4; // rax

  v4 = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  return hkDataObjectUtil::toResourceWithRegistry(src, v4, destroyOnCopy);
}

// File Line: 484
// RVA: 0xE497C0
hkPackfileData *__fastcall hkDataObjectUtil::toResourceWithRegistry(
        hkDataObject *src,
        hkClassNameRegistry *classReg,
        unsigned int destroyOnCopy)
{
  hkPackfileData *v3; // rdi
  _QWORD **Value; // rax
  hkPackfileData *v8; // rax
  hkPackfileData *v9; // rax
  hkPackfileData *v10; // rbx
  void *m_object; // r14
  hkClass *m_class; // rsi
  hkPackfileData *m_pntr; // rbx
  const char *Name; // rax
  hkPackfileData *v15; // rbx
  Copier v17; // [rsp+20h] [rbp-39h] BYREF
  hkVariant result; // [rsp+A0h] [rbp+47h] BYREF

  v3 = 0i64;
  v17.m_todos.m_capacityAndFlags = 0x80000000;
  v17.m_pointerPatchesFromHandle.m_valueChain.m_capacityAndFlags = 0x80000000;
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
  v17.m_copyStack.m_capacityAndFlags = 0x80000000;
  v17.m_postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( classReg )
    hkReferencedObject::addReference(classReg);
  v17.m_classReg.m_pntr = classReg;
  v17.m_trackedData.m_pntr = 0i64;
  v17.m_allocatedOnHeap = 0;
  v17.m_destroyOnCopy = destroyOnCopy;
  if ( src->m_impl )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (hkPackfileData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 168i64);
    if ( v8 )
    {
      hkPackfileData::hkPackfileData(v8, v17.m_classReg.m_pntr);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    v17.m_trackedData.m_pntr = v10;
    Copier::deepCopyToNative(&v17, &result, src);
    m_object = result.m_object;
    if ( result.m_object && (m_class = result.m_class) != 0i64 )
    {
      Copier::finishAndTrackObjectsInPackfile(&v17, v17.m_trackedData.m_pntr);
      m_pntr = v17.m_trackedData.m_pntr;
      Name = hkClass::getName(m_class);
      hkPackfileData::setContentsWithName(m_pntr, m_object, Name);
      v15 = v17.m_trackedData.m_pntr;
      hkReferencedObject::addReference(v17.m_trackedData.m_pntr);
      if ( v17.m_trackedData.m_pntr )
        hkReferencedObject::removeReference(v17.m_trackedData.m_pntr);
      v17.m_trackedData.m_pntr = 0i64;
      v3 = v15;
    }
    else
    {
      if ( v17.m_trackedData.m_pntr )
        hkReferencedObject::removeReference(v17.m_trackedData.m_pntr);
      v17.m_trackedData.m_pntr = 0i64;
    }
  }
  Copier::~Copier(&v17);
  return v3;
}

// File Line: 561
// RVA: 0xE49AC0
hkTypeManager::Type *__fastcall hkDataObjectUtil::getBasicType(
        hkTypeManager *typeManager,
        hkClassMember::Type type,
        const char *typeName)
{
  TypeInfo *v4; // rcx
  hkTypeManager::Type *v6; // rax

  v4 = &s_lut[type];
  switch ( v4->m_type )
  {
    case 1:
      return typeManager->m_builtInTypes[(unsigned __int8)v4->m_subType];
    case 4:
      return hkTypeManager::makeTuple(
               typeManager,
               typeManager->m_builtInTypes[(unsigned __int8)v4->m_subType],
               (unsigned __int8)v4->m_tupleSize);
    case 5:
      if ( !typeName )
        return hkTypeManager::makePointer(typeManager, typeManager->m_homogenousClass);
      v6 = hkTypeManager::addClass(typeManager, typeName);
      return hkTypeManager::makePointer(typeManager, v6);
    case 6:
      return hkTypeManager::addClass(typeManager, typeName);
    case 7:
      return hkTypeManager::makePointer(typeManager, typeManager->m_homogenousClass);
    default:
      return 0i64;
  }
}

// File Line: 608
// RVA: 0xE49BD0
hkTypeManager::Type *__fastcall hkDataObjectUtil::getTypeFromMemberTypeClassName(
        hkTypeManager *typeManager,
        hkClassMember::Type mtype,
        hkClassMember::Type stype,
        const char *typeName,
        int count)
{
  hkTypeManager::Type *v6; // r10
  TypeInfo *v8; // r8
  const char *v9; // r8
  hkTypeManager::Type *v10; // rax
  hkTypeManager::Type *Tuple; // rax
  hkTypeManager::Type *BasicType; // rax

  v6 = 0i64;
  v8 = &s_lut[mtype];
  switch ( v8->m_type )
  {
    case 1:
      v6 = typeManager->m_builtInTypes[(unsigned __int8)v8->m_subType];
      break;
    case 2:
      if ( stype == 25 )
        BasicType = hkTypeManager::addClass(typeManager, typeName);
      else
        BasicType = hkDataObjectUtil::getBasicType(typeManager, stype, typeName);
      if ( count )
        BasicType = hkTypeManager::makeTuple(typeManager, BasicType, count);
      return hkTypeManager::makeArray(typeManager, BasicType);
    case 3:
      v9 = 0i64;
      mtype = stype;
      goto LABEL_13;
    case 4:
      Tuple = hkTypeManager::makeTuple(
                typeManager,
                typeManager->m_builtInTypes[(unsigned __int8)v8->m_subType],
                (unsigned __int8)v8->m_tupleSize);
      goto LABEL_14;
    case 5:
      v10 = hkDataObjectUtil::getBasicType(typeManager, stype, typeName);
      Tuple = hkTypeManager::makePointer(typeManager, v10);
      goto LABEL_14;
    case 6:
    case 7:
      v9 = typeName;
LABEL_13:
      Tuple = hkDataObjectUtil::getBasicType(typeManager, mtype, v9);
LABEL_14:
      v6 = Tuple;
      break;
    default:
      break;
  }
  if ( count )
    return hkTypeManager::makeTuple(typeManager, v6, count);
  return v6;
}

// File Line: 680
// RVA: 0xE49B80
hkTypeManager::Type *__fastcall hkDataObjectUtil::getTypeFromMemberType(
        hkTypeManager *typeManager,
        hkClassMember::Type mtype,
        hkClassMember::Type stype,
        hkClass *klass,
        int count)
{
  hkClassMember::Type v5; // ebx
  hkClassMember::Type v6; // edi
  hkTypeManager *v7; // rsi
  hkClass *Name; // rax

  v5 = stype;
  v6 = mtype;
  v7 = typeManager;
  if ( klass )
  {
    Name = (hkClass *)hkClass::getName(klass);
    stype = v5;
    mtype = v6;
    klass = Name;
    typeManager = v7;
  }
  return hkDataObjectUtil::getTypeFromMemberTypeClassName(typeManager, mtype, stype, (const char *)klass, count);
}

// File Line: 692
// RVA: 0xE49D00
hkResult *__fastcall hkDataObjectUtil::deepCopyWorld(hkResult *result, hkDataWorld *dst, hkDataWorld *src)
{
  hkDataWorldCloner *v4; // rax
  hkDataWorldCloner v6; // [rsp+20h] [rbp-28h] BYREF

  hkDataWorldCloner::hkDataWorldCloner(&v6, dst, src);
  hkDataWorldCloner::clone(v4, result);
  hkMapBase<hkDataObject_Handle,hkDataObject_Handle,hkMapOperations<hkDataObject_Handle>>::clearAndDeallocate(
    &v6.m_copied,
    &hkContainerHeapAllocator::s_alloc);
  return result;
}

// File Line: 697
// RVA: 0xE49D40
__int64 __fastcall hkDataObjectUtil::getExtraStorageSize(hkClass *klass, hkDataObject *obj)
{
  unsigned int v2; // r15d
  int i; // edi
  hkClassMember *Member; // rax
  hkClassMember *v7; // r14
  __int64 v8; // rax
  __int64 v9; // rbx
  int v10; // esi
  int ArrayMemberSize; // eax
  __int64 v14[5]; // [rsp+20h] [rbp-28h] BYREF

  v2 = 0;
  for ( i = 0; i < (int)hkClass::getNumMembers(klass); ++i )
  {
    Member = hkClass::getMember(klass, i);
    v7 = Member;
    if ( Member->m_type.m_storage == 34 )
    {
      ((void (__fastcall *)(hkDataObjectImpl *, __int64 *, const char *))obj->m_impl->vfptr[3].__vecDelDtor)(
        obj->m_impl,
        v14,
        Member->m_name);
      v8 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v14[0] + 80i64))(v14[0], v14[1]);
      v9 = v8;
      if ( v8 )
      {
        ++*(_WORD *)(v8 + 10);
        ++*(_DWORD *)(v8 + 12);
      }
      v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 40i64))(v9);
      hkClassMember::getArrayMemberSize(v7);
      ArrayMemberSize = hkClassMember::getArrayMemberSize(v7);
      --*(_WORD *)(v9 + 10);
      v2 += (v10 * ArrayMemberSize + 15) & 0xFFFFFFF0;
      if ( (*(_DWORD *)(v9 + 12))-- == 1 )
        (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
    }
  }
  return v2;
}

