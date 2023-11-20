// File Line: 24
// RVA: 0xE78920
void __fastcall myTrackedObjectCallback(void *ptr, hkClass *klass, hkBool wasAdded, unsigned __int64 tagId, void *userCallbackHandle)
{
  if ( wasAdded.m_bool )
    hkInspectProcess::addTopLevelObject((hkInspectProcess *)userCallbackHandle, ptr, klass, tagId);
  else
    hkInspectProcess::removeTopLevelObject((hkInspectProcess *)userCallbackHandle, ptr);
}

// File Line: 40
// RVA: 0xE77DF0
hkProcess *__fastcall hkInspectProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkInspectProcess *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkInspectProcess *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 96i64);
  if ( v3 && (hkInspectProcess::hkInspectProcess(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 45
// RVA: 0xE77E50
void hkInspectProcess::registerProcess(void)
{
  hkInspectProcess::m_tag = hkProcessFactory::registerProcess(
                              hkSingleton<hkProcessFactory>::s_instance,
                              "ObjectInspection",
                              hkInspectProcess::create);
}

// File Line: 51
// RVA: 0xE78770
void __fastcall hkInspectProcess::hkInspectProcess(hkInspectProcess *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkInspectProcess *v2; // rbx
  hkVisualDebugger *v3; // rcx
  _QWORD **v4; // rax
  hkPlatformObjectWriter::Cache *v5; // rax
  hkPlatformObjectWriter::Cache *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkInspectProcess::`vftable{for `hkReferencedObject};
  v2 = this;
  this->vfptr = (hkProcessVtbl *)&hkInspectProcess::`vftable{for `hkProcess};
  this->m_autoUpdateList.m_data = 0i64;
  this->m_autoUpdateList.m_size = 0;
  this->m_autoUpdateList.m_capacityAndFlags = 2147483648;
  if ( contexts->m_size <= 0 )
    v3 = 0i64;
  else
    v3 = (*contexts->m_data)->m_owner;
  v2->m_vdb = v3;
  if ( v3 )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&v3->vfptr);
    hkVisualDebugger::addTrackedObjectCallback(v2->m_vdb, myTrackedObjectCallback, v2);
  }
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkPlatformObjectWriter::Cache *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                          v4[11],
                                          64i64);
  if ( v5 )
  {
    hkPlatformObjectWriter::Cache::Cache(v5);
    v2->m_cache = v6;
  }
  else
  {
    v2->m_cache = 0i64;
  }
}

// File Line: 62
// RVA: 0xE78830
void __fastcall hkInspectProcess::~hkInspectProcess(hkInspectProcess *this)
{
  hkVisualDebugger *v1; // rbp
  hkInspectProcess *v2; // rbx
  int v3; // esi
  __int64 v4; // rdi
  int v5; // er8

  v1 = this->m_vdb;
  this->vfptr = (hkBaseObjectVtbl *)&hkInspectProcess::`vftable{for `hkReferencedObject};
  v2 = this;
  this->vfptr = (hkProcessVtbl *)&hkInspectProcess::`vftable{for `hkProcess};
  if ( v1 )
  {
    v3 = 0;
    if ( v1->m_trackedObjects.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        hkInspectProcess::removeTopLevelObject(v2, v1->m_trackedObjects.m_data[v4].m_ptr);
        ++v3;
        ++v4;
      }
      while ( v3 < v1->m_trackedObjects.m_size );
    }
    hkVisualDebugger::removeTrackedObjectCallback(v2->m_vdb, myTrackedObjectCallback);
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_vdb->vfptr);
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v2->m_cache->vfptr);
  v5 = v2->m_autoUpdateList.m_capacityAndFlags;
  v2->m_autoUpdateList.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_autoUpdateList.m_data,
      16 * v5);
  v2->m_autoUpdateList.m_data = 0i64;
  v2->m_autoUpdateList.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xE78390
void __fastcall hkInspectProcess::init(hkInspectProcess *this)
{
  hkInspectProcess *v1; // rbx
  hkClass *v2; // rdi
  hkClass **v3; // rdi
  hkClass *v4; // rax
  hkInspectProcess::ObjectPair *v5; // rsi
  int v6; // edi
  hkInspectProcess *v7; // rbp
  __int64 v8; // rbx
  hkStructureLayout layout; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->m_autoUpdateList.m_data )
  {
    hkOArchive::write32u(*(hkOArchive **)&this->m_selectable.m_bool, 0x2Fu);
    hkOArchive::write8u(*(hkOArchive **)&v1->m_selectable.m_bool, 32);
    v2 = &hkClassClass;
    if ( *(_QWORD *)&v1->m_autoUpdateList.m_size )
    {
      hkStructureLayout::hkStructureLayout(&layout, &hkStructureLayout::MsvcWin32LayoutRules);
      v2 = hkPlatformObjectWriter::Cache::get(
             *(hkPlatformObjectWriter::Cache **)&v1->m_autoUpdateList.m_size,
             &hkClassClass,
             &layout);
    }
    hkOArchive::write64u(*(hkOArchive **)&v1->m_selectable.m_bool, (unsigned __int64)v2);
    hkOArchive::write8u(*(hkOArchive **)&v1->m_selectable.m_bool, hkStructureLayout::HostLayoutRules.m_bytesInPointer);
    hkOArchive::write8u(*(hkOArchive **)&v1->m_selectable.m_bool, hkStructureLayout::HostLayoutRules.m_littleEndian);
    hkOArchive::write8u(
      *(hkOArchive **)&v1->m_selectable.m_bool,
      hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization);
    hkOArchive::write8u(
      *(hkOArchive **)&v1->m_selectable.m_bool,
      hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization);
    hkOArchive::write16u(*(hkOArchive **)&v1->m_selectable.m_bool, 4u);
    v3 = hkInspectProcess::s_specialClassClasses;
    do
    {
      v4 = *v3;
      if ( *(_QWORD *)&v1->m_autoUpdateList.m_size )
      {
        hkStructureLayout::hkStructureLayout(&layout, &hkStructureLayout::MsvcWin32LayoutRules);
        v4 = hkPlatformObjectWriter::Cache::get(
               *(hkPlatformObjectWriter::Cache **)&v1->m_autoUpdateList.m_size,
               *v3,
               &layout);
      }
      hkOArchive::write64u(*(hkOArchive **)&v1->m_selectable.m_bool, (unsigned __int64)v4);
      ++v3;
    }
    while ( (signed __int64)v3 < (signed __int64)&hkInspectProcess `RTTI Type Descriptor );
    v5 = v1->m_autoUpdateList.m_data;
    v6 = 0;
    if ( SLODWORD(v5[4].klass) > 0 )
    {
      v7 = (hkInspectProcess *)((char *)v1 - 16);
      v8 = 0i64;
      do
      {
        hkInspectProcess::addTopLevelObject(
          v7,
          *(void **)((char *)v5[4].obj + v8),
          *(hkClass **)((char *)v5[4].obj + v8 + 8),
          *(_QWORD *)((char *)v5[4].obj + v8 + 16));
        ++v6;
        v8 += 24i64;
      }
      while ( v6 < SLODWORD(v5[4].klass) );
    }
  }
}

// File Line: 132
// RVA: 0xE782F0
void __fastcall hkInspectProcess::step(hkInspectProcess *this, float frameTimeInMs)
{
  int v2; // ebx
  hkInspectProcess *v3; // rdi
  __int64 v4; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > writtenObjects; // [rsp+30h] [rbp-18h]

  v2 = 0;
  v3 = this;
  writtenObjects.m_hashMod = -1;
  writtenObjects.m_elem = 0i64;
  writtenObjects.m_numElems = 0;
  if ( SLODWORD(this->m_processHandler) > 0 )
  {
    v4 = 0i64;
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear(&writtenObjects);
      hkInspectProcess::writeObject(
        (hkInspectProcess *)((char *)v3 - 16),
        v3->m_displayHandler[v4].vfptr,
        (hkClass *)v3->m_displayHandler[v4 + 1].vfptr,
        0,
        (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)&writtenObjects);
      ++v2;
      v4 += 2i64;
    }
    while ( v2 < SLODWORD(v3->m_processHandler) );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &writtenObjects,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&writtenObjects);
}

// File Line: 150
// RVA: 0xE78960
_FindMemberItem

// File Line: 232
// RVA: 0xE77E80
void __fastcall hkInspectProcess::getConsumableCommands(hkInspectProcess *this, char **commands, int *numCommands)
{
  *commands = inspectProcess_cmds;
  *numCommands = 5;
}

// File Line: 238
// RVA: 0xE77EA0
void __fastcall hkInspectProcess::consumeCommand(hkInspectProcess *this, char command)
{
  hkInspectProcess *v2; // rsi
  __int64 v3; // r15
  int v4; // er14
  __int32 v5; // ecx
  int v6; // er12
  unsigned __int16 *v7; // r8
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // er9
  __int64 v12; // r14
  int v13; // edi
  hkResultEnum v14; // ecx
  void *v15; // rax
  void *v16; // rdx
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // er9
  hkIArchive *v21; // rcx
  hkDebugDisplayHandlerVtbl *v22; // rsi
  hkClassMember *member; // rax
  void *v24; // rax
  hkDebugDisplayHandlerVtbl *v25; // rdi
  hkClass *v26; // r14
  char v27; // r15
  int v28; // ebx
  bool v29; // r9
  __int64 v30; // r8
  __int64 v31; // rcx
  hkDebugDisplayHandler *v32; // rax
  bool v33; // al
  hkDebugDisplayHandler *v34; // rcx
  signed __int64 v35; // rdi
  signed __int64 v36; // rcx
  signed __int64 v37; // rdx
  __int64 v38; // rax
  void *buf; // [rsp+30h] [rbp-28h]
  int v40; // [rsp+38h] [rbp-20h]
  int v41; // [rsp+3Ch] [rbp-1Ch]
  hkArray<unsigned short,hkContainerHeapAllocator> memberPath; // [rsp+40h] [rbp-18h]
  hkResult result; // [rsp+98h] [rbp+40h]
  hkDebugDisplayHandlerVtbl *array; // [rsp+A0h] [rbp+48h]
  hkClass *klass; // [rsp+A8h] [rbp+50h]

  v2 = this;
  if ( command == 35 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->vfptr, &array, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &klass, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &result, 1, 1);
    v25 = array;
    if ( array )
    {
      v26 = klass;
      if ( klass )
      {
        v27 = result.m_enum;
        v28 = 0;
        memberPath.m_data = 0i64;
        memberPath.m_size = 0;
        memberPath.m_capacityAndFlags = -1;
        v29 = klass == &hkClassClass || result.m_enum & 2;
        hkInspectProcess::writeObject(
          (hkInspectProcess *)((char *)v2 - 16),
          array,
          klass,
          (hkBool)v29,
          (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)&memberPath);
        v30 = SLODWORD(v2->m_processHandler);
        v31 = 0i64;
        if ( (signed int)v30 > 0 )
        {
          v32 = v2->m_displayHandler;
          do
          {
            if ( v32->vfptr == v25 )
              break;
            ++v31;
            ++v28;
            v32 += 2;
          }
          while ( v31 < v30 );
        }
        v33 = v28 != (_DWORD)v30;
        if ( v27 & 1 )
        {
          if ( !v33 )
          {
            if ( LODWORD(v2->m_processHandler) == (HIDWORD(v2->m_processHandler) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v2->m_displayHandler,
                16);
            v34 = &v2->m_displayHandler[2 * LODWORD(v2->m_processHandler)++];
            v34[1].vfptr = (hkDebugDisplayHandlerVtbl *)v26;
            v34->vfptr = v25;
          }
        }
        else if ( v33 && --LODWORD(v2->m_processHandler) != v28 )
        {
          v35 = 2i64;
          v36 = (signed __int64)&v2->m_displayHandler[2 * v28];
          v37 = (signed __int64)&v2->m_displayHandler[2 * SLODWORD(v2->m_processHandler)] - v36;
          do
          {
            v38 = *(_QWORD *)(v37 + v36);
            v36 += 8i64;
            *(_QWORD *)(v36 - 8) = v38;
            --v35;
          }
          while ( v35 );
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&memberPath,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _((AMD_HD3D *)&memberPath);
      }
    }
  }
  else if ( command == 37 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->vfptr, &array, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &klass, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &result, 2, 1);
    LOWORD(v3) = result.m_enum;
    memberPath.m_data = 0i64;
    memberPath.m_size = 0;
    memberPath.m_capacityAndFlags = 2147483648;
    v4 = LOWORD(result.m_enum);
    v5 = LOWORD(result.m_enum);
    v6 = LOWORD(result.m_enum);
    if ( LOWORD(result.m_enum) )
    {
      result.m_enum = 2 * LOWORD(result.m_enum);
      v7 = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                 (int *)&result);
      v5 = result.m_enum / 2;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = 2147483648;
    memberPath.m_size = v6;
    if ( v5 )
      v8 = v5;
    memberPath.m_data = v7;
    memberPath.m_capacityAndFlags = v8;
    v9 = v8 & 0x3FFFFFFF;
    if ( v9 < v4 )
    {
      v10 = 2 * v9;
      v11 = v4;
      if ( v4 < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &memberPath, v11, 2);
    }
    v3 = (unsigned __int16)v3;
    memberPath.m_size = v4;
    v12 = 0i64;
    if ( (signed __int64)(unsigned __int16)v3 > 0 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &result, 2, 1);
        memberPath.m_data[v12++] = result.m_enum;
      }
      while ( v12 < v3 );
    }
    hkIArchive::readArrayGeneric((hkIArchive *)v2->vfptr, &result, 4, 1);
    v13 = result.m_enum;
    buf = 0i64;
    v14 = result.m_enum;
    v40 = 0;
    v41 = 2147483648;
    if ( result.m_enum )
    {
      v15 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              (int *)&result);
      v14 = result.m_enum;
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = 2147483648;
    buf = v16;
    if ( v14 )
      v17 = v14;
    v40 = v13;
    v41 = v17;
    v18 = v17 & 0x3FFFFFFF;
    if ( v18 < v13 )
    {
      v19 = 2 * v18;
      v20 = v13;
      if ( v13 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &buf, v20, 1);
      v16 = buf;
    }
    v21 = (hkIArchive *)v2->vfptr;
    v40 = v13;
    hkIArchive::readRaw(v21, v16, v13);
    v22 = array;
    if ( array )
    {
      if ( klass )
      {
        if ( memberPath.m_size > 0 )
        {
          if ( v13 )
          {
            member = hkClass::getMember(klass, *memberPath.m_data);
            v24 = FindMemberItem(
                    (char *)v22 + member->m_offset,
                    &memberPath,
                    0,
                    (hkClassMember::Type)(unsigned __int8)member->m_type.m_storage,
                    (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage,
                    member);
            if ( v24 )
              hkString::memCpy(v24, buf, v13);
          }
        }
      }
    }
    v40 = 0;
    if ( v41 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        buf,
        v41 & 0x3FFFFFFF);
    buf = 0i64;
    v41 = 2147483648;
    memberPath.m_size = 0;
    if ( memberPath.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        memberPath.m_data,
        2 * (memberPath.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 335
// RVA: 0xE785E0
signed __int64 __fastcall hkInspectProcess::addTopLevelObject(hkInspectProcess *this, void *ptr, hkClass *klass, unsigned __int64 tag)
{
  hkInspectProcess *v4; // rbx
  void *v5; // rsi
  unsigned __int64 v6; // rbp
  hkClass *v7; // rdi
  __int64 v8; // rax
  hkBool result; // [rsp+30h] [rbp+8h]

  v4 = this;
  v5 = ptr;
  v6 = tag;
  v7 = klass;
  hkOArchive::write32u((hkOArchive *)&this->m_outStream->vfptr, 0x19u);
  if ( v4->m_vdb->m_classReg && hkClass::hasVtable(v7, &result)->m_bool )
  {
    v8 = ((__int64 (__fastcall *)(hkVtableClassRegistry *, void *))v4->m_vdb->m_classReg->vfptr[2].__first_virtual_table_function__)(
           v4->m_vdb->m_classReg,
           v5);
    if ( !v8 )
      v8 = (__int64)v7;
    v7 = (hkClass *)v8;
  }
  hkOArchive::write8u((hkOArchive *)&v4->m_outStream->vfptr, 33);
  hkOArchive::write64u((hkOArchive *)&v4->m_outStream->vfptr, (unsigned __int64)v5);
  hkOArchive::write64u((hkOArchive *)&v4->m_outStream->vfptr, (unsigned __int64)v7);
  hkOArchive::write64u((hkOArchive *)&v4->m_outStream->vfptr, v6);
  return 25i64;
}

// File Line: 359
// RVA: 0xE786A0
signed __int64 __fastcall hkInspectProcess::removeTopLevelObject(hkInspectProcess *this, void *ptr)
{
  hkInspectProcess *v2; // rbx
  void *v3; // rdi
  __int64 v4; // r9
  int v5; // er8
  __int64 v6; // rdx
  hkInspectProcess::ObjectPair *v7; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // rax
  signed __int64 v11; // r9
  __int64 v12; // rcx

  v2 = this;
  v3 = ptr;
  hkOArchive::write32u((hkOArchive *)&this->m_outStream->vfptr, 9u);
  hkOArchive::write8u((hkOArchive *)&v2->m_outStream->vfptr, 34);
  hkOArchive::write64u((hkOArchive *)&v2->m_outStream->vfptr, (unsigned __int64)v3);
  v4 = v2->m_autoUpdateList.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 > 0 )
  {
    v7 = v2->m_autoUpdateList.m_data;
    while ( v7->obj != v3 )
    {
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        return 9i64;
    }
    if ( --v2->m_autoUpdateList.m_size != v5 )
    {
      v9 = 2i64;
      v10 = (signed __int64)&v2->m_autoUpdateList.m_data[v5];
      v11 = (signed __int64)&v2->m_autoUpdateList.m_data[v2->m_autoUpdateList.m_size] - v10;
      do
      {
        v12 = *(_QWORD *)(v11 + v10);
        v10 += 8i64;
        *(_QWORD *)(v10 - 8) = v12;
        --v9;
      }
      while ( v9 );
    }
  }
  return 9i64;
}

// File Line: 382
// RVA: 0xE78500
__int64 __fastcall hkInspectProcess::writeObject(hkInspectProcess *this, const void *ptr, hkClass *klass, hkBool recur, hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *writtenObjects)
{
  hkInspectProcess *v5; // rbx
  hkClass *v6; // rdi
  const void *v7; // rsi
  const char *v8; // rax
  bool v9; // zf
  hkVisualDebugger *v10; // rax
  __int64 result; // rax
  char v12; // [rsp+88h] [rbp+20h]

  v12 = recur.m_bool;
  v5 = this;
  v6 = klass;
  v7 = ptr;
  v8 = hkClass::getName(klass);
  v9 = (unsigned int)hkString::strCmp(v8, "hkClass") == 0;
  v10 = v5->m_vdb;
  if ( v9 )
    result = hkObjectSerialize::writeObject(
               v5->m_outStream,
               36,
               v7,
               &hkClassClass,
               writtenObjects,
               1,
               v12 != 0,
               0,
               v10->m_classReg,
               v5->m_cache,
               (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
  else
    result = hkObjectSerialize::writeObject(
               v5->m_outStream,
               36,
               v7,
               v6,
               writtenObjects,
               1,
               v12 != 0,
               0,
               v10->m_classReg,
               v5->m_cache,
               0);
  return result;
}

