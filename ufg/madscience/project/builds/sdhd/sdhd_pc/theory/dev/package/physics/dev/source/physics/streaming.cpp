// File Line: 108
// RVA: 0xA0A70
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::AddTypeInfo(UFG::NativePackfileUtils::FastTypeRegistry *this, const char *typeName, hkTypeInfo *typeInfo)
{
  hkTypeInfo *v3; // rdi
  const char *v4; // rbp
  UFG::NativePackfileUtils::FastTypeRegistry *v5; // rsi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  char *v8; // rbx
  int v9; // eax

  v3 = typeInfo;
  v4 = typeName;
  v5 = this;
  v6 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&v5->mNodes.mTree, v6)) != 0i64 )
  {
    v7->mNULL.mChild[1] = (UFG::qBaseNodeRB *)v3;
  }
  else
  {
    v8 = UFG::qMalloc(0x40ui64, "FastTypeRegistryNode", 0i64);
    if ( v8 )
    {
      v9 = UFG::qStringHash32(v4, 0xFFFFFFFF);
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
    UFG::qBaseTreeRB::Add(&v5->mNodes.mTree, (UFG::qBaseNodeRB *)v8);
    *((_QWORD *)v8 + 6) = v3;
  }
}

// File Line: 121
// RVA: 0xA0110
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::AddClass(UFG::NativePackfileUtils::FastTypeRegistry *this, const char *typeName, hkClass *klass)
{
  hkClass *v3; // rdi
  const char *v4; // rbp
  UFG::NativePackfileUtils::FastTypeRegistry *v5; // rsi
  unsigned int v6; // eax
  UFG::qBaseNodeRB *v7; // rbx
  unsigned int v8; // eax

  v3 = klass;
  v4 = typeName;
  v5 = this;
  v6 = UFG::qStringHash32(typeName, 0xFFFFFFFF);
  if ( !v6 || (v7 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&v5->mNodes.mTree, v6)) == 0i64 )
  {
    v7 = (UFG::qBaseNodeRB *)UFG::qMalloc(0x40ui64, "FastTypeRegistryNode", 0i64);
    if ( v7 )
    {
      v8 = UFG::qStringHash32(v4, 0xFFFFFFFF);
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
    UFG::qBaseTreeRB::Add(&v5->mNodes.mTree, v7);
  }
  v7[1].mChild[0] = (UFG::qBaseNodeRB *)v3;
  if ( hkClass::getAttribute(v3, "hk.PostFinish") )
    LOBYTE(v7[1].mUID) = 1;
}

// File Line: 183
// RVA: 0xABEC0
void __fastcall UFG::NativePackfileUtils::FastTypeRegistry::Init(UFG::NativePackfileUtils::FastTypeRegistry *this)
{
  UFG::NativePackfileUtils::FastTypeRegistry *v1; // r14
  hkTypeInfoRegistry *v2; // rbx
  Dummy *v3; // rbx
  hkTypeInfo *v4; // rax
  __int64 v5; // rax
  int v6; // esi
  __int64 v7; // rdi
  char *v8; // rbx
  const char *v9; // rax
  char *v10; // [rsp+28h] [rbp-48h]
  int v11; // [rsp+30h] [rbp-40h]
  int v12; // [rsp+34h] [rbp-3Ch]
  hkTypeInfoRegistry v13; // [rsp+38h] [rbp-38h]
  hkStringMap<hkTypeInfo const *,hkContainerHeapAllocator> *result; // [rsp+A0h] [rbp+30h]

  v1 = this;
  if ( !this->mbInited )
  {
    v2 = (hkTypeInfoRegistry *)((__int64 (__cdecl *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    *(_DWORD *)&v13.m_memSizeAndFlags = 0x1FFFF;
    result = &v13.m_map;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
      &v13.m_map.m_map,
      0);
    v13.m_finishFlag = 1;
    v13.m_informMemoryTracker = 1;
    v13.vfptr = (hkBaseObjectVtbl *)&UFG::NativePackfileUtils::_hkTypeInfoRegistry::`vftable';
    hkTypeInfoRegistry::merge(&v13, v2);
    v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
      (hkBool *)&result,
      v3);
    while ( (_BYTE)result )
    {
      v4 = (hkTypeInfo *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
                           v3);
      UFG::NativePackfileUtils::FastTypeRegistry::AddTypeInfo(v1, v4->m_typeName, v4);
      v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
             v3);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v13.m_map,
        (hkBool *)&result,
        v3);
    }
    v5 = ((__int64 (__cdecl *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    v10 = 0i64;
    v11 = 0;
    v12 = 2147483648;
    (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v5 + 40i64))(v5, &v10);
    v6 = 0;
    if ( v11 > 0 )
    {
      v7 = 0i64;
      do
      {
        v8 = v10;
        v9 = hkClass::getName(*(hkClass **)&v10[v7]);
        UFG::NativePackfileUtils::FastTypeRegistry::AddClass(v1, v9, *(hkClass **)&v8[v7]);
        ++v6;
        v7 += 8i64;
      }
      while ( v6 < v11 );
    }
    v1->mbInited = 1;
    v11 = 0;
    if ( v12 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v10,
        8 * v12);
    v10 = 0i64;
    v12 = 2147483648;
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
  return atexit(UFG::NativePackfileUtils::_dynamic_atexit_destructor_for__gFastTypeRegistry__);
}

// File Line: 296
// RVA: 0xB8E40
hkResult *__fastcall UFG::NativePackfileUtils::validatePackfileHeader(hkResult *result, const void *packfileData)
{
  const char *v2; // rdi
  hkResult *v3; // rbx
  hkResult *v4; // rax
  bool v5; // zf
  const char *v6; // rax
  int dst; // [rsp+20h] [rbp-48h]
  int v8; // [rsp+24h] [rbp-44h]
  char v9; // [rsp+48h] [rbp-20h]
  __int64 v10; // [rsp+58h] [rbp-10h]

  v2 = (const char *)packfileData;
  v3 = result;
  if ( packfileData )
  {
    hkString::memSet(&dst, -1, 64);
    v5 = *(_DWORD *)v2 == 1474355287;
    dst = 1474355287;
    v8 = 281067536;
    v9 = 0;
    v10 = 0i64;
    if ( !v5
      || *((_DWORD *)v2 + 1) != 281067536
      || v2[16] != hkStructureLayout::HostLayoutRules.m_bytesInPointer
      || v2[17] != hkStructureLayout::HostLayoutRules.m_littleEndian
      || v2[18] != hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
      || v2[19] != hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization
      || (unsigned __int8)v2 & 3
      || v2[40] == -1 )
    {
      v3->m_enum = 1;
      v4 = v3;
    }
    else
    {
      v6 = hkVersionUtil::getCurrentVersion();
      v5 = hkString::strCmp(v2 + 40, v6) == 0;
      v4 = v3;
      v3->m_enum = !v5;
    }
  }
  else
  {
    result->m_enum = 1;
    v4 = result;
  }
  return v4;
}

// File Line: 366
// RVA: 0xB5FA0
void __fastcall UFG::NativePackfileUtils::_applyVirtualFixups(hkPackfileSectionHeader *inSection, hkPackfileSectionHeader *outSection, const void *packfileData, void *outBuffer, hkPackfileSectionHeader *outSections, hkArray<UFG::NativePackfileUtils::TrackedObjectsArray_Element,hkContainerHeapAllocator> *map, hkTypeInfoRegistry *finishRegistry, hkClassNameRegistry *classNameRegistry, hkArray<hkVariant,hkContainerHeapAllocator> *postFinishObjects, UFG::NativePackfileUtils::Fixups *fixups)
{
  _DWORD *v10; // r13
  char *v11; // r9
  int v12; // er12
  _DWORD *v13; // r15
  __int64 v14; // rdx
  signed __int64 v15; // rax
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
  hkPackfileSectionHeader *v27; // [rsp+60h] [rbp+8h]
  char *v28; // [rsp+68h] [rbp+10h]
  char *v29; // [rsp+70h] [rbp+18h]

  v27 = inSection;
  v10 = outBuffer;
  v11 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v12 = 0;
  v28 = v11;
  v29 = (char *)v10 + (signed int)v10[1];
  if ( (inSection->m_exportsOffset - inSection->m_virtualFixupsOffset) / 4 > 0 )
  {
    v13 = (char *)packfileData + inSection->m_virtualFixupsOffset + inSection->m_absoluteDataStart + 8;
    do
    {
      v14 = (signed int)*(v13 - 2);
      if ( (_DWORD)v14 != -1 )
      {
        v15 = (signed __int64)(signed int)*(v13 - 1) << 6;
        if ( *(int *)((char *)&outSections->m_localFixupsOffset + v15) )
          v16 = (char *)v10 + *v13 + *(int *)((char *)&outSections->m_absoluteDataStart + v15);
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
                  UFG::NativePackfileUtils::Fixups::AddFixup(fixups, v10 + 10, v10[10], (unsigned int)v23);
                  *((_QWORD *)v10 + 5) = v23;
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
                          hkArrayUtil::_reserveMore(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                            postFinishObjects,
                            16);
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
      v13 += 3;
    }
    while ( v12 < (v27->m_exportsOffset - v27->m_virtualFixupsOffset) / 4 );
  }
}

// File Line: 428
// RVA: 0xB8280
char *__fastcall UFG::NativePackfileUtils::loadInPlace(void *packfileData, int dataSize, UFG::NativePackfileUtils::Fixups *fixups)
{
  UFG::NativePackfileUtils::Fixups *v3; // r13
  hkPackfileSectionHeader *v4; // rdi
  int v6; // esi
  hkPackfileSectionHeader *outSections; // r15
  unsigned int v8; // er8
  __int64 v9; // rdx
  char *v10; // r8
  int *v11; // r9
  signed int v12; // er12
  int v13; // ebx
  __int64 v14; // rcx
  __int64 v15; // rdx
  int v16; // er10
  int v17; // kr00_4
  int v18; // ebx
  int v19; // eax
  __int64 v20; // rcx
  char *v21; // r11
  int v22; // er10
  __int64 v23; // rcx
  signed __int64 v24; // rax
  char *v25; // rax
  hkTypeInfoRegistry *finishRegistry; // rbp
  hkClassNameRegistry *classNameRegistry; // r14
  hkPackfileSectionHeader *v28; // rbx
  int v29; // esi
  __int64 v30; // r14
  void *v31; // rbx
  hkVariant *v32; // rax
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+58h] [rbp-40h]
  hkResult result; // [rsp+B8h] [rbp+20h]

  v3 = fixups;
  v4 = (hkPackfileSectionHeader *)packfileData;
  UFG::NativePackfileUtils::FastTypeRegistry::Init(&UFG::NativePackfileUtils::gFastTypeRegistry);
  if ( UFG::NativePackfileUtils::validatePackfileHeader(&result, v4)->m_enum )
    return 0i64;
  v6 = 0;
  outSections = v4 + 1;
  if ( v4->m_absoluteDataStart <= 0 )
    outSections = 0i64;
  v8 = v4->m_pad[2];
  if ( v8 & 1 )
    return 0i64;
  UFG::NativePackfileUtils::Fixups::AddFixup(v3, &v4->m_pad[2], v8, v8 | 1);
  v4->m_pad[2] |= 1u;
  v12 = -1;
  v13 = 0;
  if ( v4->m_absoluteDataStart > 0 )
  {
    v11 = &outSections->m_globalFixupsOffset;
    do
    {
      v14 = *(v11 - 2);
      if ( v13 == v4->m_localFixupsOffset )
        v12 = v14 + v4->m_globalFixupsOffset;
      v15 = *(v11 - 1);
      v10 = &v4->m_sectionTag[v14 + v15];
      v16 = 0;
      v17 = *v11 - v15;
      v9 = (v17 >> 31) & 3;
      if ( ((signed int)v9 + v17) >> 2 > 0 )
      {
        do
        {
          if ( *(_DWORD *)v10 != -1 )
            *(_QWORD *)&v4->m_sectionTag[v14 + *(signed int *)v10] = (char *)v4 + v14 + *((signed int *)v10 + 1);
          v16 += 2;
          v10 += 8;
          v9 = ((*v11 - *(v11 - 1)) >> 31) & 3;
        }
        while ( v16 < (*v11 - *(v11 - 1)) / 4 );
      }
      ++v13;
      v11 += 16;
    }
    while ( v13 < v4->m_absoluteDataStart );
  }
  v18 = 0;
  if ( v4->m_absoluteDataStart > 0 )
  {
    v11 = &outSections->m_virtualFixupsOffset;
    do
    {
      v9 = (unsigned int)*(v11 - 1);
      v19 = *v11 - v9;
      if ( *v11 != (_DWORD)v9 )
      {
        v20 = *(v11 - 3);
        v21 = &v4->m_sectionTag[v20];
        v10 = (char *)((signed int)v9 + (signed int)v20 + 8i64);
        v22 = 0;
        v9 = (v19 >> 31) & 3;
        if ( v19 / 4 > 0 )
        {
          v10 = &v10[(_QWORD)v4];
          do
          {
            v23 = *((signed int *)v10 - 2);
            if ( (_DWORD)v23 != -1 )
            {
              v24 = (signed __int64)*((signed int *)v10 - 1) << 6;
              if ( *(int *)((char *)&outSections->m_localFixupsOffset + v24) )
                v25 = &v4->m_sectionTag[*(_DWORD *)v10 + *(int *)((char *)&outSections->m_absoluteDataStart + v24)];
              else
                v25 = 0i64;
              *(_QWORD *)&v21[v23] = v25;
            }
            v22 += 3;
            v10 += 12;
            v9 = ((*v11 - *(v11 - 1)) >> 31) & 3;
          }
          while ( v22 < (*v11 - *(v11 - 1)) / 4 );
        }
      }
      ++v18;
      v11 += 16;
    }
    while ( v18 < v4->m_absoluteDataStart );
  }
  finishRegistry = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, __int64, char *, int *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
                                           hkSingleton<hkBuiltinTypeRegistry>::s_instance,
                                           v9,
                                           v10,
                                           v11);
  classNameRegistry = (hkClassNameRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_size = 0;
  postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( v4->m_absoluteDataStart > 0 )
  {
    v28 = outSections;
    do
    {
      if ( v28->m_exportsOffset != v28->m_virtualFixupsOffset )
        UFG::NativePackfileUtils::_applyVirtualFixups(
          v28,
          v28,
          v4,
          v4,
          outSections,
          0i64,
          finishRegistry,
          classNameRegistry,
          &postFinishObjects,
          v3);
      ++v6;
      ++v28;
    }
    while ( v6 < v4->m_absoluteDataStart );
  }
  v29 = 0;
  if ( postFinishObjects.m_size > 0 )
  {
    v30 = 0i64;
    do
    {
      v31 = postFinishObjects.m_data[v30].m_object;
      v32 = hkClass::getAttribute(postFinishObjects.m_data[v30].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))v32->m_object)(v31);
      ++v29;
      ++v30;
    }
    while ( v29 < postFinishObjects.m_size );
  }
  postFinishObjects.m_size = 0;
  if ( postFinishObjects.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * postFinishObjects.m_capacityAndFlags);
  return (char *)v4 + v12;
}

// File Line: 519
// RVA: 0xB8DE0
void __fastcall UFG::NativePackfileUtils::unloadInPlace(void *buffer, int bufferSize, UFG::NativePackfileUtils::Fixups *fixups)
{
  int v3; // edx
  int v4; // er10
  __int64 v5; // r9
  __int64 v6; // r9

  *((_DWORD *)buffer + 14) &= 0xFFFFFFFE;
  v3 = 0;
  v4 = 0;
  if ( fixups->zeroFixups.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      ++v4;
      ++v5;
      *(_DWORD *)fixups->zeroFixups.m_data[v5 - 1] = 0;
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
      *(_DWORD *)fixups->nonZeroFixups.m_data[v6 - 1].addr = *((_DWORD *)&fixups->nonZeroFixups.m_data[v6] - 2);
    }
    while ( v3 < fixups->nonZeroFixups.m_size );
  }
}

