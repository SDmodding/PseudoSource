// File Line: 24
// RVA: 0xE78920
void __fastcall myTrackedObjectCallback(
        void *ptr,
        hkClass *klass,
        hkBool wasAdded,
        __int64 tagId,
        hkInspectProcess *userCallbackHandle)
{
  if ( wasAdded.m_bool )
    hkInspectProcess::addTopLevelObject(userCallbackHandle, (__int64)ptr, klass, tagId);
  else
    hkInspectProcess::removeTopLevelObject(userCallbackHandle, ptr);
}

// File Line: 40
// RVA: 0xE77DF0
hkProcess *__fastcall hkInspectProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  _QWORD **Value; // rax
  hkInspectProcess *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkInspectProcess *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
  if ( v3 && (hkInspectProcess::hkInspectProcess(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
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
void __fastcall hkInspectProcess::hkInspectProcess(
        hkInspectProcess *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkVisualDebugger *m_owner; // rcx
  _QWORD **Value; // rax
  hkPlatformObjectWriter::Cache *v5; // rax
  hkPlatformObjectWriter::Cache *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkInspectProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkInspectProcess::`vftable{for `hkProcess};
  this->m_autoUpdateList.m_data = 0i64;
  this->m_autoUpdateList.m_size = 0;
  this->m_autoUpdateList.m_capacityAndFlags = 0x80000000;
  if ( contexts->m_size <= 0 )
    m_owner = 0i64;
  else
    m_owner = (*contexts->m_data)->m_owner;
  this->m_vdb = m_owner;
  if ( m_owner )
  {
    hkReferencedObject::addReference(m_owner);
    hkVisualDebugger::addTrackedObjectCallback(this->m_vdb, myTrackedObjectCallback, this);
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkPlatformObjectWriter::Cache *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          64i64);
  if ( v5 )
  {
    hkPlatformObjectWriter::Cache::Cache(v5);
    this->m_cache = v6;
  }
  else
  {
    this->m_cache = 0i64;
  }
}

// File Line: 62
// RVA: 0xE78830
void __fastcall hkInspectProcess::~hkInspectProcess(hkInspectProcess *this)
{
  hkVisualDebugger *m_vdb; // rbp
  int v3; // esi
  __int64 v4; // rdi
  int m_capacityAndFlags; // r8d

  m_vdb = this->m_vdb;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkInspectProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkInspectProcess::`vftable{for `hkProcess};
  if ( m_vdb )
  {
    v3 = 0;
    if ( m_vdb->m_trackedObjects.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        hkInspectProcess::removeTopLevelObject(this, m_vdb->m_trackedObjects.m_data[v4].m_ptr);
        ++v3;
        ++v4;
      }
      while ( v3 < m_vdb->m_trackedObjects.m_size );
    }
    hkVisualDebugger::removeTrackedObjectCallback(this->m_vdb, myTrackedObjectCallback);
    hkReferencedObject::removeReference(this->m_vdb);
  }
  hkReferencedObject::removeReference(this->m_cache);
  m_capacityAndFlags = this->m_autoUpdateList.m_capacityAndFlags;
  this->m_autoUpdateList.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_autoUpdateList.m_data,
      16 * m_capacityAndFlags);
  this->m_autoUpdateList.m_data = 0i64;
  this->m_autoUpdateList.m_capacityAndFlags = 0x80000000;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 81
// RVA: 0xE78390
void __fastcall hkInspectProcess::init(hkInspectProcess *this)
{
  hkClass *v2; // rdi
  hkClass **v3; // rdi
  hkClass *v4; // rax
  hkInspectProcess::ObjectPair *m_data; // rsi
  int v6; // edi
  hkInspectProcess *v7; // rbp
  __int64 v8; // rbx
  hkStructureLayout layout; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_autoUpdateList.m_data )
  {
    hkOArchive::write32u(*(hkOArchive **)&this->m_selectable.m_bool, 0x2Fu);
    hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, 32);
    v2 = &hkClassClass;
    if ( *(_QWORD *)&this->m_autoUpdateList.m_size )
    {
      hkStructureLayout::hkStructureLayout(&layout, (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
      v2 = hkPlatformObjectWriter::Cache::get(
             *(hkPlatformObjectWriter::Cache **)&this->m_autoUpdateList.m_size,
             &hkClassClass,
             &layout);
    }
    hkOArchive::write64u(*(hkOArchive **)&this->m_selectable.m_bool, (__int64)v2);
    hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, hkStructureLayout::HostLayoutRules.m_bytesInPointer);
    hkOArchive::write8u(*(hkOArchive **)&this->m_selectable.m_bool, hkStructureLayout::HostLayoutRules.m_littleEndian);
    hkOArchive::write8u(
      *(hkOArchive **)&this->m_selectable.m_bool,
      hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization);
    hkOArchive::write8u(
      *(hkOArchive **)&this->m_selectable.m_bool,
      hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization);
    hkOArchive::write16u(*(hkOArchive **)&this->m_selectable.m_bool, 4u);
    v3 = hkInspectProcess::s_specialClassClasses;
    do
    {
      v4 = *v3;
      if ( *(_QWORD *)&this->m_autoUpdateList.m_size )
      {
        hkStructureLayout::hkStructureLayout(&layout, (hkStructureLayout *)&hkStructureLayout::MsvcWin32LayoutRules);
        v4 = hkPlatformObjectWriter::Cache::get(
               *(hkPlatformObjectWriter::Cache **)&this->m_autoUpdateList.m_size,
               *v3,
               &layout);
      }
      hkOArchive::write64u(*(hkOArchive **)&this->m_selectable.m_bool, (__int64)v4);
      ++v3;
    }
    while ( (__int64)v3 < (__int64)&hkInspectProcess `RTTI Type Descriptor );
    m_data = this->m_autoUpdateList.m_data;
    v6 = 0;
    if ( SLODWORD(m_data[4].klass) > 0 )
    {
      v7 = (hkInspectProcess *)((char *)this - 16);
      v8 = 0i64;
      do
      {
        hkInspectProcess::addTopLevelObject(
          v7,
          *(void **)((char *)m_data[4].obj + v8),
          *(hkClass **)((char *)m_data[4].obj + v8 + 8),
          *(_QWORD *)((char *)m_data[4].obj + v8 + 16));
        ++v6;
        v8 += 24i64;
      }
      while ( v6 < SLODWORD(m_data[4].klass) );
    }
  }
}

// File Line: 132
// RVA: 0xE782F0
void __fastcall hkInspectProcess::step(hkInspectProcess *this, float frameTimeInMs)
{
  int v2; // ebx
  __int64 v4; // rsi
  _BYTE writtenObjects[24]; // [rsp+30h] [rbp-18h] BYREF

  v2 = 0;
  *(_DWORD *)&writtenObjects[12] = -1;
  *(_QWORD *)writtenObjects = 0i64;
  *(_DWORD *)&writtenObjects[8] = 0;
  if ( SLODWORD(this->m_processHandler) > 0 )
  {
    v4 = 0i64;
    do
    {
      hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::clear((hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)writtenObjects);
      hkInspectProcess::writeObject(
        (hkInspectProcess *)((char *)this - 16),
        this->m_displayHandler[v4].vfptr,
        (hkClass *)this->m_displayHandler[v4 + 1].vfptr,
        0,
        (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)writtenObjects);
      ++v2;
      v4 += 2i64;
    }
    while ( v2 < SLODWORD(this->m_processHandler) );
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)writtenObjects,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)writtenObjects);
}

// File Line: 150
// RVA: 0xE78960
_QWORD *__fastcall FindMemberItem(
        _BYTE *memberPtr,
        hkArray<unsigned short,hkContainerHeapAllocator> *memberPath,
        int curMemberIndex,
        hkClassMember::Type t,
        hkClassMember::Type subType,
        hkClassMember *member)
{
  unsigned int v6; // r9d
  _QWORD *v8; // r14
  __int64 v10; // rsi
  int m_storage; // r9d
  int v12; // eax
  int v13; // ebx
  int ArrayMemberSize; // eax
  hkClass *StructClass; // rax
  hkClassMember *v16; // rax

  v6 = t - 1;
  v8 = memberPtr;
  v10 = 2i64 * curMemberIndex + 2;
  while ( 2 )
  {
    switch ( v6 )
    {
      case 0u:
        return v8;
      case 1u:
        m_storage = 12;
        v12 = 4 * *(unsigned __int16 *)((char *)memberPath->m_data + v10);
        v10 += 2i64;
        v8 = (_QWORD *)((char *)v8 + 4 * v12);
        goto LABEL_9;
      case 3u:
        v13 = *(unsigned __int16 *)((char *)memberPath->m_data + v10);
        ArrayMemberSize = hkClassMember::getArrayMemberSize(member);
        m_storage = (unsigned __int8)member->m_subtype.m_storage;
        memberPtr = (_BYTE *)(*v8 + v13 * ArrayMemberSize);
        v10 += 2i64;
        v8 = memberPtr;
        goto LABEL_9;
      case 4u:
        if ( !member )
          return 0i64;
        if ( !member->m_class )
          return 0i64;
        StructClass = hkClassMember::getStructClass(member);
        if ( !StructClass )
          return 0i64;
        v16 = hkClass::getMember(StructClass, *(unsigned __int16 *)((char *)memberPath->m_data + v10));
        v10 += 2i64;
        m_storage = (unsigned __int8)v16->m_type.m_storage;
        member = v16;
        v8 = (_QWORD *)((char *)v8 + v16->m_offset);
LABEL_9:
        v6 = m_storage - 1;
        if ( v6 <= 0x1F )
          continue;
        return 0i64;
      case 6u:
      case 7u:
      case 8u:
        JUMPOUT(0x140000000i64);
      case 9u:
        JUMPOUT(0x141010100i64);
      case 0xAu:
        __inbyte((unsigned __int16)memberPath);
        memberPtr[1] = memberPtr[1];
        JUMPOUT(0x142050106i64);
      case 0xBu:
        JUMPOUT(0x140050305i64);
      case 0xCu:
        JUMPOUT(0x145050304i64);
      case 0xDu:
        JUMPOUT(0x140000005i64);
      case 0xEu:
        JUMPOUT(0x150E98348i64);
      case 0xFu:
        JUMPOUT(0x140000BE9i64);
      case 0x10u:
        JUMPOUT(0x20CCCCC00i64);
      case 0x11u:
      case 0x12u:
        JUMPOUT(0x20CCCCCCCi64);
      case 0x13u:
        JUMPOUT(0x1645C8948i64);
      case 0x14u:
        JUMPOUT(0x1C3485708i64);
      case 0x15u:
        JUMPOUT(0x21A8B20ECi64);
      case 0x16u:
        JUMPOUT(0x228F98B48i64);
      case 0x17u:
        JUMPOUT(0x23FFFFD6Ci64);
      case 0x18u:
        JUMPOUT(0x1B401C3F6i64);
      case 0x19u:
        JUMPOUT(0x187B70F32i64);
      case 0x1Au:
        JUMPOUT(0x23FFFB908i64);
      case 0x1Bu:
        JUMPOUT(0x1A0BB0000i64);
      case 0x1Cu:
        JUMPOUT(0x1A6000000i64);
      case 0x1Du:
        JUMPOUT(0x14374C13Bi64);
      case 0x1Eu:
        JUMPOUT(0x1CBD8B70Fi64);
      case 0x1Fu:
        JUMPOUT(0x1A2D94B0Di64);
      default:
        return 0i64;
    }
  }
}

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
  unsigned __int16 v3; // r15
  int m_enum_low; // r14d
  __int32 v5; // ecx
  int v6; // r12d
  unsigned __int16 *v7; // r8
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // r9d
  __int64 v12; // r14
  hkResultEnum v13; // edi
  hkResultEnum v14; // ecx
  void *v15; // rax
  void *v16; // rdx
  unsigned int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // r9d
  hkProcessVtbl *vfptr; // rcx
  hkDebugDisplayHandlerVtbl *v22; // rsi
  hkClassMember *member; // rax
  void *MemberItem; // rax
  hkDebugDisplayHandlerVtbl *v25; // rdi
  hkClass *v26; // r14
  char m_enum; // r15
  int v28; // ebx
  bool v29; // r9
  __int64 m_processHandler_low; // r8
  __int64 v31; // rcx
  hkDebugDisplayHandler *m_displayHandler; // rax
  hkDebugDisplayHandler *v33; // rcx
  __int64 v34; // rdi
  hkDebugDisplayHandler *v35; // rcx
  char *v36; // rdx
  hkDebugDisplayHandlerVtbl *v37; // rax
  void *buf; // [rsp+30h] [rbp-28h] BYREF
  hkResultEnum v39; // [rsp+38h] [rbp-20h]
  int v40; // [rsp+3Ch] [rbp-1Ch]
  hkArray<unsigned short,hkContainerHeapAllocator> memberPath; // [rsp+40h] [rbp-18h] BYREF
  hkResult result; // [rsp+98h] [rbp+40h] BYREF
  hkDebugDisplayHandlerVtbl *array; // [rsp+A0h] [rbp+48h] BYREF
  hkClass *klass; // [rsp+A8h] [rbp+50h] BYREF

  if ( command == 35 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &array, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &klass, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &result, 1, 1);
    v25 = array;
    if ( array )
    {
      v26 = klass;
      if ( klass )
      {
        m_enum = result.m_enum;
        v28 = 0;
        memberPath.m_data = 0i64;
        memberPath.m_size = 0;
        memberPath.m_capacityAndFlags = -1;
        v29 = klass == &hkClassClass || (result.m_enum & 2) != 0;
        hkInspectProcess::writeObject(
          (hkInspectProcess *)((char *)this - 16),
          array,
          klass,
          (hkBool)v29,
          (hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *)&memberPath);
        m_processHandler_low = SLODWORD(this->m_processHandler);
        v31 = 0i64;
        if ( (int)m_processHandler_low > 0 )
        {
          m_displayHandler = this->m_displayHandler;
          do
          {
            if ( m_displayHandler->vfptr == v25 )
              break;
            ++v31;
            ++v28;
            m_displayHandler += 2;
          }
          while ( v31 < m_processHandler_low );
        }
        if ( (m_enum & 1) != 0 )
        {
          if ( v28 == (_DWORD)m_processHandler_low )
          {
            if ( LODWORD(this->m_processHandler) == (HIDWORD(this->m_processHandler) & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_displayHandler, 16);
            v33 = &this->m_displayHandler[2 * LODWORD(this->m_processHandler)++];
            v33[1].vfptr = (hkDebugDisplayHandlerVtbl *)v26;
            v33->vfptr = v25;
          }
        }
        else if ( v28 != (_DWORD)m_processHandler_low && --LODWORD(this->m_processHandler) != v28 )
        {
          v34 = 2i64;
          v35 = &this->m_displayHandler[2 * v28];
          v36 = (char *)((char *)&this->m_displayHandler[2 * SLODWORD(this->m_processHandler)] - (char *)v35);
          do
          {
            v37 = *(hkDebugDisplayHandlerVtbl **)((char *)&v35->vfptr + (_QWORD)v36);
            ++v35;
            v35[-1].vfptr = v37;
            --v34;
          }
          while ( v34 );
        }
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&memberPath,
          &hkContainerHeapAllocator::s_alloc);
        _((AMD_HD3D *)&memberPath);
      }
    }
  }
  else if ( command == 37 )
  {
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &array, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &klass, 8, 1);
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &result, 2, 1);
    v3 = result.m_enum;
    memberPath.m_data = 0i64;
    memberPath.m_size = 0;
    memberPath.m_capacityAndFlags = 0x80000000;
    m_enum_low = LOWORD(result.m_enum);
    v5 = LOWORD(result.m_enum);
    v6 = LOWORD(result.m_enum);
    if ( LOWORD(result.m_enum) )
    {
      result.m_enum = 2 * LOWORD(result.m_enum);
      v7 = (unsigned __int16 *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                 &hkContainerHeapAllocator::s_alloc,
                                 &result);
      v5 = result.m_enum / 2;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = 0x80000000;
    memberPath.m_size = v6;
    if ( v5 )
      v8 = v5;
    memberPath.m_data = v7;
    memberPath.m_capacityAndFlags = v8;
    v9 = v8 & 0x3FFFFFFF;
    if ( v9 < m_enum_low )
    {
      v10 = 2 * v9;
      v11 = m_enum_low;
      if ( m_enum_low < v10 )
        v11 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&memberPath.m_data, v11, 2);
    }
    memberPath.m_size = m_enum_low;
    v12 = 0i64;
    if ( v3 )
    {
      do
      {
        hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &result, 2, 1);
        memberPath.m_data[v12++] = result.m_enum;
      }
      while ( v12 < v3 );
    }
    hkIArchive::readArrayGeneric((hkIArchive *)this->hkProcess::vfptr, &result, 4, 1);
    v13 = result.m_enum;
    buf = 0i64;
    v14 = result.m_enum;
    v39 = HK_SUCCESS;
    v40 = 0x80000000;
    if ( result.m_enum )
    {
      v15 = hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &result);
      v14 = result.m_enum;
      v16 = v15;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = 0x80000000;
    buf = v16;
    if ( v14 )
      v17 = v14;
    v39 = v13;
    v40 = v17;
    v18 = v17 & 0x3FFFFFFF;
    if ( v18 < v13 )
    {
      v19 = 2 * v18;
      v20 = v13;
      if ( v13 < v19 )
        v20 = v19;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&buf, v20, 1);
      v16 = buf;
    }
    vfptr = this->hkProcess::vfptr;
    v39 = v13;
    hkIArchive::readRaw((hkIArchive *)vfptr, v16, v13);
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
            MemberItem = FindMemberItem(
                           (char *)v22 + member->m_offset,
                           &memberPath,
                           0,
                           (hkClassMember::Type)(unsigned __int8)member->m_type.m_storage,
                           (hkClassMember::Type)(unsigned __int8)member->m_subtype.m_storage,
                           member);
            if ( MemberItem )
              hkString::memCpy(MemberItem, buf, v13);
          }
        }
      }
    }
    v39 = HK_SUCCESS;
    if ( v40 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, buf, v40 & 0x3FFFFFFF);
    buf = 0i64;
    v40 = 0x80000000;
    memberPath.m_size = 0;
    if ( memberPath.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        memberPath.m_data,
        2 * (memberPath.m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 335
// RVA: 0xE785E0
__int64 __fastcall hkInspectProcess::addTopLevelObject(
        hkInspectProcess *this,
        __int64 ptr,
        hkClass *klass,
        __int64 tag)
{
  hkClass *v8; // rax
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  hkOArchive::write32u(this->m_outStream, 0x19u);
  if ( this->m_vdb->m_classReg && hkClass::hasVtable(klass, &result)->m_bool )
  {
    v8 = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, __int64))this->m_vdb->m_classReg->vfptr[2].__first_virtual_table_function__)(
                      this->m_vdb->m_classReg,
                      ptr);
    if ( !v8 )
      v8 = klass;
    klass = v8;
  }
  hkOArchive::write8u(this->m_outStream, 33);
  hkOArchive::write64u(this->m_outStream, ptr);
  hkOArchive::write64u(this->m_outStream, (__int64)klass);
  hkOArchive::write64u(this->m_outStream, tag);
  return 25i64;
}

// File Line: 359
// RVA: 0xE786A0
__int64 __fastcall hkInspectProcess::removeTopLevelObject(hkInspectProcess *this, void *ptr)
{
  __int64 m_size; // r9
  int v5; // r8d
  __int64 v6; // rdx
  hkInspectProcess::ObjectPair *i; // rcx
  __int64 v9; // rdx
  hkInspectProcess::ObjectPair *v10; // rax
  char *v11; // r9
  hkClass *v12; // rcx

  hkOArchive::write32u(this->m_outStream, 9u);
  hkOArchive::write8u(this->m_outStream, 34);
  hkOArchive::write64u(this->m_outStream, (__int64)ptr);
  m_size = this->m_autoUpdateList.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_autoUpdateList.m_data; i->obj != ptr; ++i )
    {
      ++v6;
      ++v5;
      if ( v6 >= m_size )
        return 9i64;
    }
    if ( --this->m_autoUpdateList.m_size != v5 )
    {
      v9 = 2i64;
      v10 = &this->m_autoUpdateList.m_data[v5];
      v11 = (char *)((char *)&this->m_autoUpdateList.m_data[this->m_autoUpdateList.m_size] - (char *)v10);
      do
      {
        v12 = *(hkClass **)((char *)&v10->obj + (_QWORD)v11);
        v10 = (hkInspectProcess::ObjectPair *)((char *)v10 + 8);
        v10[-1].klass = v12;
        --v9;
      }
      while ( v9 );
    }
  }
  return 9i64;
}

// File Line: 382
// RVA: 0xE78500
__int64 __fastcall hkInspectProcess::writeObject(
        hkInspectProcess *this,
        hkClass *ptr,
        hkClass *klass,
        hkBool recur,
        hkPointerMap<void const *,hkClass const *,hkContainerHeapAllocator> *writtenObjects)
{
  const char *Name; // rax
  bool v9; // zf
  hkVisualDebugger *m_vdb; // rax

  Name = hkClass::getName(klass);
  v9 = (unsigned int)hkString::strCmp(Name, "hkClass") == 0;
  m_vdb = this->m_vdb;
  if ( v9 )
    return hkObjectSerialize::writeObject(
             this->m_outStream,
             36,
             ptr,
             &hkClassClass,
             writtenObjects,
             1,
             recur.m_bool != 0,
             0,
             m_vdb->m_classReg,
             this->m_cache,
             (hkFlags<enum hkObjectCopier::ObjectCopierFlagBits,unsigned int>)2);
  else
    return hkObjectSerialize::writeObject(
             this->m_outStream,
             36,
             ptr,
             klass,
             writtenObjects,
             1,
             recur.m_bool != 0,
             0,
             m_vdb->m_classReg,
             this->m_cache,
             0);
}

