// File Line: 108
// RVA: 0xA0A70
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::AddTypeInfo(
        UFG::NativePackfileUtils::FastTypeRegistry *this,
        const char *typeName,
        UFG::qBaseNodeRB *typeInfo)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  char *v8; // rbx
  int v9; // eax

  v6 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&this->mNodes.mTree, v6)) != 0i64 )
  {
    v7->mNULL.mChild[1] = typeInfo;
  }
  else
  {
    v8 = UFG::qMalloc(0x40ui64, "FastTypeRegistryNode", 0i64);
    if ( v8 )
    {
      v9 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
      *(_QWORD *)v8 = 0i64;
      *((_QWORD *)v8 + 1) = 0i64;
      *((_QWORD *)v8 + 2) = 0i64;
      *((_DWORD *)v8 + 6) = v9;
      *((_QWORD *)v8 + 5) = 0i64;
      *((_QWORD *)v8 + 6) = 0i64;
      v8[56] = 0;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mNodes.mTree, (UFG::qBaseNodeRB *)v8);
    *((_QWORD *)v8 + 6) = typeInfo;
  }
}

// File Line: 121
// RVA: 0xA0110
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::AddClass(
        UFG::NativePackfileUtils::FastTypeRegistry *this,
        const char *typeName,
        UFG::qBaseNodeRB *klass)
{
  unsigned int v6; // eax
  UFG::qBaseNodeRB *v7; // rbx
  unsigned int v8; // eax

  v6 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
  if ( !v6 || (v7 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&this->mNodes.mTree, v6)) == 0i64 )
  {
    v7 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x40ui64, "FastTypeRegistryNode", 0i64);
    if ( v7 )
    {
      v8 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
      v7->mParent = 0i64;
      v7->mChild[0] = 0i64;
      v7->mChild[1] = 0i64;
      v7->mUID = v8;
      v7[1].mChild[0] = 0i64;
      v7[1].mChild[1] = 0i64;
      LOBYTE(v7[1].mUID) = 0;
    }
    else
    {
      v7 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mNodes.mTree, v7);
  }
  v7[1].mChild[0] = klass;
  if ( hkClass::getAttribute((hkClass *)klass, "hk.PostFinish") )
    LOBYTE(v7[1].mUID) = 1;
}

// File Line: 183
// RVA: 0xABEC0
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::Init(UFG::NativePackfileUtils::FastTypeRegistry *this)
{
  hkTypeInfoRegistry *v2; // rbx
  Dummy *Iterator; // rbx
  const char **Value; // rax
  __int64 v5; // rax
  int v6; // esi
  __int64 v7; // rdi
  char *v8; // rbx
  const char *Name; // rax
  char *v10; // [rsp+28h] [rbp-48h] BYREF
  int v11; // [rsp+30h] [rbp-40h]
  int v12; // [rsp+34h] [rbp-3Ch]
  hkTypeInfoRegistry v13; // [rsp+38h] [rbp-38h] BYREF
  hkStringMap<hkTypeInfo const *,hkContainerHeapAllocator> *result; // [rsp+A0h] [rbp+30h] BYREF

  if ( !this->mbInited )
  {
    v2 = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    *(_DWORD *)&v13.m_memSizeAndFlags = 0x1FFFF;
    result = &v13.m_map;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v13.m_map.m_map,
      0);
    v13.m_finishFlag = 1;
    v13.m_informMemoryTracker = 1;
    v13.vfptr = (hkBaseObjectVtbl *)&UFG::NativePackfileUtils::_hkTypeInfoRegistry::`vftable;
    hkTypeInfoRegistry::merge(&v13, v2);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
      (hkBool *)&result,
      Iterator);
    while ( (_BYTE)result )
    {
      Value = (const char **)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
                               Iterator);
      UFG::NativePackfileUtils::FastTypeRegistry::AddTypeInfo(this, *Value, (UFG::qBaseNodeRB *)Value);
      Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
                   Iterator);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
        (hkBool *)&result,
        Iterator);
    }
    v5 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    v10 = 0i64;
    v11 = 0;
    v12 = 0x80000000;
    (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v5 + 40i64))(v5, &v10);
    v6 = 0;
    if ( v11 > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = v10;
        Name = hkClass::getName(*(hkClass **)&v10[v7]);
        UFG::NativePackfileUtils::FastTypeRegistry::AddClass(this, Name, *(UFG::qBaseNodeRB **)&v8[v7]);
        ++v6;
        v7 += 8i64;
      }
      while ( v6 < v11 );
    }
    this->mbInited = 1;
    v11 = 0;
    if ( v12 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 8 * v12);
    v10 = 0i64;
    v12 = 0x80000000;
    result = &v13.m_map;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v13.m_map.m_map);
  }
}

// File Line: 215
// RVA: 0x1459030
__int64 UFG::NativePackfileUtils::_dynamic_initializer_for__gFastTypeRegistry__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::NativePackfileUtils::gFastTypeRegistry.mNodes.mTree);
  UFG::NativePackfileUtils::gFastTypeRegistry.mbInited = 0;
  return atexit((int (__fastcall *)())UFG::NativePackfileUtils::_dynamic_atexit_destructor_for__gFastTypeRegistry__);
}

// File Line: 296
// RVA: 0xB8E40
hkResult *__fastcall UFG::NativePackfileUtils::validatePackfileHeader(hkResult *result, const char *packfileData)
{
  hkResult *v4; // rax
  bool v5; // zf
  const char *CurrentVersion; // rax
  int dst[10]; // [rsp+20h] [rbp-48h] BYREF
  char v8; // [rsp+48h] [rbp-20h]
  __int64 v9; // [rsp+58h] [rbp-10h]

  if ( packfileData )
  {
    hkString::memSet(dst, -1, 64);
    v5 = *(_DWORD *)packfileData == 1474355287;
    dst[0] = 1474355287;
    dst[1] = 281067536;
    v8 = 0;
    v9 = 0i64;
    if ( v5
      && *((_DWORD *)packfileData + 1) == 281067536
      && packfileData[16] == hkStructureLayout::HostLayoutRules.m_bytesInPointer
      && packfileData[17] == hkStructureLayout::HostLayoutRules.m_littleEndian
      && packfileData[18] == hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
      && packfileData[19] == hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization
      && ((unsigned __int8)packfileData & 3) == 0
      && packfileData[40] != -1 )
    {
      CurrentVersion = hkVersionUtil::getCurrentVersion();
      v5 = hkString::strCmp(packfileData + 40, CurrentVersion) == 0;
      v4 = result;
      result->m_enum = !v5;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  return v4;
}

// File Line: 366
// RVA: 0xB5FA0
void __fastcall UFG::NativePackfileUtils::_applyVirtualFixups(
        hkPackfileSectionHeader *inSection,
        hkPackfileSectionHeader *outSection,
        char *packfileData,
        _DWORD *outBuffer,
        hkPackfileSectionHeader *outSections,
        hkArray<UFG::NativePackfileUtils::TrackedObjectsArray_Element,hkContainerHeapAllocator> *map,
        hkTypeInfoRegistry *finishRegistry,
        hkClassNameRegistry *classNameRegistry,
        hkArray<hkVariant,hkContainerHeapAllocator> *postFinishObjects,
        UFG::NativePackfileUtils::Fixups *fixups)
{
  char *v11; // r9
  int v12; // r12d
  char *v13; // r15
  __int64 v14; // rdx
  __int64 v15; // rax
  const char *v16; // rcx
  char *v17; // r14
  unsigned int v18; // eax
  unsigned int v19; // ebp
  UFG::qBaseTreeRB *v20; // rax
  UFG::qBaseTreeRB *v21; // rbx
  hkTypeInfo *v22; // rcx
  UFG::qBaseNodeRB *v23; // rdi
  UFG::qBaseTreeRB *v24; // rax
  hkClass *v25; // rbx
  hkVariant *v26; // rax
  char *v28; // [rsp+68h] [rbp+10h]
  char *v29; // [rsp+70h] [rbp+18h]

  v11 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v12 = 0;
  v28 = v11;
  v29 = (char *)outBuffer + (int)outBuffer[1];
  if ( (inSection->m_exportsOffset - inSection->m_virtualFixupsOffset) / 4 > 0 )
  {
    v13 = &packfileData[inSection->m_virtualFixupsOffset + 8 + inSection->m_absoluteDataStart];
    do
    {
      v14 = *((int *)v13 - 2);
      if ( (_DWORD)v14 != -1 )
      {
        v15 = (__int64)*((int *)v13 - 1) << 6;
        if ( *(int *)((char *)&outSections->m_localFixupsOffset + v15) )
          v16 = (char *)outBuffer + *(_DWORD *)v13 + *(int *)((char *)&outSections->m_absoluteDataStart + v15);
        else
          v16 = 0i64;
        v17 = &v11[v14];
        v18 = UFG::qStringHash32(v16, 0xFFFFFFFF);
        v19 = v18;
        if ( v18 )
        {
          v20 = UFG::qBaseTreeRB::Get(&UFG::NativePackfileUtils::gFastTypeRegistry.mNodes.mTree, v18);
          v21 = v20;
          if ( v20 )
          {
            v22 = (hkTypeInfo *)v20->mNULL.mChild[1];
            if ( v22 )
            {
              hkTypeInfo::finishLoadedObject(v22, v17, 1);
              v23 = v21->mNULL.mChild[1];
              if ( v23 )
              {
                if ( v17 == v29 )
                {
                  UFG::NativePackfileUtils::Fixups::AddFixup(fixups, outBuffer + 10, outBuffer[10], (unsigned int)v23);
                  *((_QWORD *)outBuffer + 5) = v23;
                }
                if ( classNameRegistry )
                {
                  v24 = UFG::qBaseTreeRB::Get(&UFG::NativePackfileUtils::gFastTypeRegistry.mNodes.mTree, v19);
                  if ( v24 )
                  {
                    v25 = (hkClass *)v24->mNULL.mChild[0];
                    if ( v25 )
                    {
                      if ( LOBYTE(v24->mNULL.mUID) )
                      {
                        if ( postFinishObjects->m_size == (postFinishObjects->m_capacityAndFlags & 0x3FFFFFFF) )
                          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, postFinishObjects, 16);
                        v26 = &postFinishObjects->m_data[postFinishObjects->m_size];
                        if ( v26 )
                        {
                          v26->m_object = v17;
                          v26->m_class = v25;
                        }
                        ++postFinishObjects->m_size;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v11 = v28;
      }
      v12 += 3;
      v13 += 12;
    }
    while ( v12 < (inSection->m_exportsOffset - inSection->m_virtualFixupsOffset) / 4 );
  }
}

// File Line: 428
// RVA: 0xB8280
char *__fastcall UFG::NativePackfileUtils::loadInPlace(
        hkPackfileSectionHeader *packfileData,
        int dataSize,
        UFG::NativePackfileUtils::Fixups *fixups)
{
  int v6; // esi
  hkPackfileSectionHeader *outSections; // r15
  unsigned int v8; // r8d
  __int64 v9; // rdx
  char *v10; // r8
  int *p_m_globalFixupsOffset; // r9
  int v12; // r12d
  int v13; // ebx
  __int64 v14; // rcx
  __int64 v15; // rdx
  int v16; // r10d
  int v17; // kr00_4
  int v18; // ebx
  int v19; // eax
  __int64 v20; // rcx
  char *v21; // r11
  int v22; // r10d
  __int64 v23; // rcx
  __int64 v24; // rax
  char *v25; // rax
  hkTypeInfoRegistry *finishRegistry; // rbp
  hkClassNameRegistry *classNameRegistry; // r14
  hkPackfileSectionHeader *v28; // rbx
  int v29; // esi
  __int64 v30; // r14
  void *m_object; // rbx
  hkVariant *Attribute; // rax
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+58h] [rbp-40h] BYREF
  hkResult result; // [rsp+B8h] [rbp+20h] BYREF

  UFG::NativePackfileUtils::FastTypeRegistry::Init(&UFG::NativePackfileUtils::gFastTypeRegistry);
  if ( UFG::NativePackfileUtils::validatePackfileHeader(&result, packfileData)->m_enum )
    return 0i64;
  v6 = 0;
  outSections = packfileData + 1;
  if ( packfileData->m_absoluteDataStart <= 0 )
    outSections = 0i64;
  v8 = packfileData->m_pad[2];
  if ( (v8 & 1) != 0 )
    return 0i64;
  UFG::NativePackfileUtils::Fixups::AddFixup(fixups, &packfileData->m_pad[2], v8, v8 | 1);
  packfileData->m_pad[2] |= 1u;
  v12 = -1;
  v13 = 0;
  if ( packfileData->m_absoluteDataStart > 0 )
  {
    p_m_globalFixupsOffset = &outSections->m_globalFixupsOffset;
    do
    {
      v14 = *(p_m_globalFixupsOffset - 2);
      if ( v13 == packfileData->m_localFixupsOffset )
        v12 = v14 + packfileData->m_globalFixupsOffset;
      v15 = *(p_m_globalFixupsOffset - 1);
      v10 = &packfileData->m_sectionTag[v14 + v15];
      v16 = 0;
      v17 = *p_m_globalFixupsOffset - v15;
      v9 = (v17 >> 31) & 3;
      if ( v17 / 4 > 0 )
      {
        do
        {
          if ( *(_DWORD *)v10 != -1 )
            *(_QWORD *)&packfileData->m_sectionTag[v14 + *(int *)v10] = (char *)packfileData + v14 + *((int *)v10 + 1);
          v16 += 2;
          v10 += 8;
          v9 = ((*p_m_globalFixupsOffset - *(p_m_globalFixupsOffset - 1)) >> 31) & 3;
        }
        while ( v16 < (*p_m_globalFixupsOffset - *(p_m_globalFixupsOffset - 1)) / 4 );
      }
      ++v13;
      p_m_globalFixupsOffset += 16;
    }
    while ( v13 < packfileData->m_absoluteDataStart );
  }
  v18 = 0;
  if ( packfileData->m_absoluteDataStart > 0 )
  {
    p_m_globalFixupsOffset = &outSections->m_virtualFixupsOffset;
    do
    {
      v9 = (unsigned int)*(p_m_globalFixupsOffset - 1);
      v19 = *p_m_globalFixupsOffset - v9;
      if ( *p_m_globalFixupsOffset != (_DWORD)v9 )
      {
        v20 = *(p_m_globalFixupsOffset - 3);
        v21 = &packfileData->m_sectionTag[v20];
        v10 = (char *)((int)v9 + (int)v20 + 8i64);
        v22 = 0;
        v9 = (v19 >> 31) & 3;
        if ( v19 / 4 > 0 )
        {
          v10 = &v10[(_QWORD)packfileData];
          do
          {
            v23 = *((int *)v10 - 2);
            if ( (_DWORD)v23 != -1 )
            {
              v24 = (__int64)*((int *)v10 - 1) << 6;
              if ( *(int *)((char *)&outSections->m_localFixupsOffset + v24) )
                v25 = &packfileData->m_sectionTag[*(_DWORD *)v10
                                                + *(int *)((char *)&outSections->m_absoluteDataStart + v24)];
              else
                v25 = 0i64;
              *(_QWORD *)&v21[v23] = v25;
            }
            v22 += 3;
            v10 += 12;
            v9 = ((*p_m_globalFixupsOffset - *(p_m_globalFixupsOffset - 1)) >> 31) & 3;
          }
          while ( v22 < (*p_m_globalFixupsOffset - *(p_m_globalFixupsOffset - 1)) / 4 );
        }
      }
      ++v18;
      p_m_globalFixupsOffset += 16;
    }
    while ( v18 < packfileData->m_absoluteDataStart );
  }
  finishRegistry = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, __int64, char *, int *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
                                           hkSingleton<hkBuiltinTypeRegistry>::s_instance,
                                           v9,
                                           v10,
                                           p_m_globalFixupsOffset);
  classNameRegistry = (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_size = 0;
  postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( packfileData->m_absoluteDataStart > 0 )
  {
    v28 = outSections;
    do
    {
      if ( v28->m_exportsOffset != v28->m_virtualFixupsOffset )
        UFG::NativePackfileUtils::_applyVirtualFixups(
          v28,
          v28,
          packfileData->m_sectionTag,
          packfileData,
          outSections,
          0i64,
          finishRegistry,
          classNameRegistry,
          &postFinishObjects,
          fixups);
      ++v6;
      ++v28;
    }
    while ( v6 < packfileData->m_absoluteDataStart );
  }
  v29 = 0;
  if ( postFinishObjects.m_size > 0 )
  {
    v30 = 0i64;
    do
    {
      m_object = postFinishObjects.m_data[v30].m_object;
      Attribute = hkClass::getAttribute(postFinishObjects.m_data[v30].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))Attribute->m_object)(m_object);
      ++v29;
      ++v30;
    }
    while ( v29 < postFinishObjects.m_size );
  }
  postFinishObjects.m_size = 0;
  if ( postFinishObjects.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * postFinishObjects.m_capacityAndFlags);
  return (char *)packfileData + v12;
}

// File Line: 519
// RVA: 0xB8DE0
void __fastcall UFG::NativePackfileUtils::unloadInPlace(
        _DWORD *buffer,
        int bufferSize,
        UFG::NativePackfileUtils::Fixups *fixups)
{
  int v3; // edx
  int v4; // r10d
  __int64 v5; // r9
  __int64 v6; // r9

  buffer[14] &= ~1u;
  v3 = 0;
  v4 = 0;
  if ( fixups->zeroFixups.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      *(_DWORD *)fixups->zeroFixups.m_data[v5++] = 0;
    }
    while ( v4 < fixups->zeroFixups.m_size );
  }
  if ( fixups->nonZeroFixups.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ++v3;
      ++v6;
      *(_DWORD *)fixups->nonZeroFixups.m_data[v6 - 1].addr = fixups->nonZeroFixups.m_data[v6 - 1].val;
    }
    while ( v3 < fixups->nonZeroFixups.m_size );
  }
}

