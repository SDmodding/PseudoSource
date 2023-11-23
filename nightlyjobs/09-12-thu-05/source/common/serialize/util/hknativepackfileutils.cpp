// File Line: 72
// RVA: 0xE59D30
void __fastcall LOCALNAMESPACE::hkNativeResource::callDestructors(LOCALNAMESPACE::hkNativeResource *this)
{
  if ( this->m_contents )
  {
    hkNativePackfileUtils::unload((_QWORD *)this->m_data.m_data, this->m_data.m_size);
    this->m_contents = 0i64;
    this->m_contentsTypeName = 0i64;
  }
}

// File Line: 82
// RVA: 0xE59C50
void __fastcall LOCALNAMESPACE::hkNativeResource::~hkNativeResource(LOCALNAMESPACE::hkNativeResource *this)
{
  int m_capacityAndFlags; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&LOCALNAMESPACE::hkNativeResource::`vftable;
  if ( this->m_contents )
  {
    hkNativePackfileUtils::unload((_QWORD *)this->m_data.m_data, this->m_data.m_size);
    this->m_contents = 0i64;
    this->m_contentsTypeName = 0i64;
  }
  m_capacityAndFlags = this->m_data.m_capacityAndFlags;
  this->m_data.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_data.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_data.m_data = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 87
// RVA: 0xE59E20
const char *__fastcall LOCALNAMESPACE::hkNativeResource::getName(LOCALNAMESPACE::hkNativeResource *this)
{
  return "hkNativeResource";
}

// File Line: 91
// RVA: 0xE59D60
void *__fastcall LOCALNAMESPACE::hkNativeResource::getContentsPointer(
        LOCALNAMESPACE::hkNativeResource *this,
        const char *typeName,
        hkTypeInfoRegistry *ignoredBecauseAlreadyDone)
{
  __int64 v5; // rbx
  hkClass *v6; // rbp
  hkClass *v7; // rax
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  if ( typeName
    && (v5 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, const char *, hkTypeInfoRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(
               hkSingleton<hkBuiltinTypeRegistry>::s_instance,
               typeName,
               ignoredBecauseAlreadyDone),
        v6 = (hkClass *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v5 + 32i64))(
                          v5,
                          this->m_contentsTypeName),
        v7 = (hkClass *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v5 + 32i64))(v5, typeName),
        v6)
    && v7
    && !hkClass::isSuperClass(v7, &result, v6)->m_bool )
  {
    return 0i64;
  }
  else
  {
    return this->m_contents;
  }
}

// File Line: 111
// RVA: 0xE59E00
void __fastcall LOCALNAMESPACE::hkNativeResource::getImportsExports(
        LOCALNAMESPACE::hkNativeResource *this,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  hkNativePackfileUtils::getImportsExports((_QWORD *)this->m_data.m_data, expOut, impOut);
}

// File Line: 129
// RVA: 0xE588C0
hkResource *__fastcall hkNativePackfileUtils::load(
        const void *packfileData,
        int dataSize,
        hkTypeInfoRegistry *userRegistry)
{
  int RequiredBufferSize; // eax
  int v7; // ebx
  void *v8; // rdi
  _QWORD **Value; // rax
  __int64 v10; // rbx
  __int64 v11; // rax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array[2]; // [rsp+30h] [rbp-28h] BYREF
  hkResult result; // [rsp+78h] [rbp+20h] BYREF

  array[0].m_capacityAndFlags = 0x80000000;
  array[0].m_data = 0i64;
  array[0].m_size = 0;
  RequiredBufferSize = hkNativePackfileUtils::getRequiredBufferSize(packfileData, dataSize);
  v7 = RequiredBufferSize;
  if ( RequiredBufferSize > 0 )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&array[0].m_data,
      RequiredBufferSize,
      1);
  array[0].m_size = v7;
  v8 = hkNativePackfileUtils::load(packfileData, dataSize, array[0].m_data, v7, userRegistry);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v10 )
  {
    v11 = *(_QWORD *)array[0].m_data[2].m_identifier;
    *(_QWORD *)v10 = &LOCALNAMESPACE::hkNativeResource::`vftable;
    *(_DWORD *)(v10 + 8) = 0x1FFFF;
    *(_QWORD *)(v10 + 16) = 0i64;
    *(_DWORD *)(v10 + 24) = 0;
    *(_DWORD *)(v10 + 28) = 0x80000000;
    *(_QWORD *)(v10 + 32) = v8;
    *(_QWORD *)(v10 + 40) = v11;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v10 + 16),
      array);
  }
  else
  {
    v10 = 0i64;
  }
  array[0].m_size = 0;
  if ( array[0].m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array[0].m_data,
      array[0].m_capacityAndFlags & 0x3FFFFFFF);
  return (hkResource *)v10;
}

// File Line: 139
// RVA: 0xE596E0
char *__fastcall getSectionDataByIndex(
        char *base,
        hkArrayBase<hkPackfileSectionHeader *> *sections,
        int sectionIndex,
        int offset)
{
  hkPackfileSectionHeader *v4; // rdx

  v4 = sections->m_data[sectionIndex];
  if ( v4->m_localFixupsOffset )
    return &base[offset + v4->m_absoluteDataStart];
  else
    return 0i64;
}

// File Line: 151
// RVA: 0xE59540
hkResult *__fastcall hkNativePackfileUtils::validatePackfileHeader(
        hkResult *result,
        const char *packfileData,
        const char **errOut)
{
  bool v7; // zf
  const char *v8; // rax
  const char *CurrentVersion; // rax
  int dst[10]; // [rsp+20h] [rbp-48h] BYREF
  char v11; // [rsp+48h] [rbp-20h]
  __int64 v12; // [rsp+58h] [rbp-10h]

  if ( packfileData )
  {
    hkString::memSet(dst, -1, 0x40u);
    v7 = *(_DWORD *)packfileData == 1474355287;
    dst[0] = 1474355287;
    dst[1] = 281067536;
    v11 = 0;
    v12 = 0i64;
    if ( v7 && *((_DWORD *)packfileData + 1) == 281067536 )
    {
      if ( packfileData[16] == hkStructureLayout::HostLayoutRules.m_bytesInPointer )
      {
        if ( packfileData[17] == hkStructureLayout::HostLayoutRules.m_littleEndian )
        {
          if ( packfileData[18] == hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization )
          {
            if ( packfileData[19] == hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization )
            {
              if ( ((unsigned __int8)packfileData & 3) != 0 )
              {
                if ( errOut )
                {
                  v8 = "Packfile data source needs to be 4 byte aligned";
                  goto LABEL_31;
                }
              }
              else
              {
                if ( packfileData[40] != -1 )
                {
                  CurrentVersion = hkVersionUtil::getCurrentVersion();
                  if ( !(unsigned int)hkString::strCmp(packfileData + 40, CurrentVersion) )
                  {
                    result->m_enum = HK_SUCCESS;
                    return result;
                  }
                  if ( !errOut )
                    goto LABEL_32;
                  v8 = "Packfile contents are not up to date";
                  goto LABEL_31;
                }
                if ( errOut )
                {
                  v8 = "Packfile file format is too old";
                  goto LABEL_31;
                }
              }
            }
            else if ( errOut )
            {
              v8 = "Trying to process a binary file with a different empty base class optimization than this platform.";
              goto LABEL_31;
            }
          }
          else if ( errOut )
          {
            v8 = "Trying to process a binary file with a different padding optimization than this platform.";
            goto LABEL_31;
          }
        }
        else if ( errOut )
        {
          v8 = "Trying to process a binary file with a different endian than this platform.";
          goto LABEL_31;
        }
      }
      else if ( errOut )
      {
        v8 = "Trying to process a binary file with a different pointer size than this platform.";
LABEL_31:
        *errOut = v8;
      }
    }
    else if ( errOut )
    {
      v8 = "Missing packfile magic header. Is this from a binary file?";
      goto LABEL_31;
    }
LABEL_32:
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( errOut )
    *errOut = "Pointer is null";
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 170
// RVA: 0xE58A10
__int64 __fastcall hkNativePackfileUtils::getRequiredBufferSize(hkPackfileHeader *packfileData, int packfileSize)
{
  unsigned int v2; // ebx
  unsigned int v4; // ebp
  int i; // esi
  hkPackfileSectionHeader *SectionHeader; // rax

  v2 = 0;
  v4 = 0;
  for ( i = 0;
        i < packfileData->m_numSections;
        v2 += SectionHeader->m_localFixupsOffset + SectionHeader->m_endOffset - SectionHeader->m_exportsOffset )
  {
    SectionHeader = hkPackfileHeader::getSectionHeader(packfileData, packfileData, i++);
    v4 += (SectionHeader->m_exportsOffset - SectionHeader->m_virtualFixupsOffset) / 12;
  }
  return v2 + 16 * (v4 + 4i64 * (unsigned int)packfileData->m_numSections + 3);
}

// File Line: 199
// RVA: 0xE59710
void __fastcall copySection(
        hkPackfileSectionHeader *inSection,
        hkPackfileSectionHeader *outSection,
        int outCurOffset,
        char *packfileData,
        char *outBuffer,
        int packfileSize,
        int outBufferSize)
{
  __int64 v8; // rsi
  char *v11; // rdi

  v8 = outCurOffset;
  hkString::memCpy(outSection, inSection, 0x13u);
  outSection->m_nullByte = inSection->m_nullByte;
  outSection->m_absoluteDataStart = v8;
  outSection->m_localFixupsOffset = inSection->m_localFixupsOffset;
  outSection->m_globalFixupsOffset = inSection->m_localFixupsOffset;
  outSection->m_virtualFixupsOffset = inSection->m_localFixupsOffset;
  outSection->m_exportsOffset = inSection->m_localFixupsOffset;
  outSection->m_importsOffset = inSection->m_importsOffset + inSection->m_localFixupsOffset - inSection->m_exportsOffset;
  outSection->m_endOffset = inSection->m_endOffset + inSection->m_localFixupsOffset - inSection->m_exportsOffset;
  v11 = &packfileData[inSection->m_absoluteDataStart];
  hkString::memCpy(&outBuffer[v8], v11, inSection->m_localFixupsOffset);
  hkString::memCpy(
    &outBuffer[v8 + outSection->m_exportsOffset],
    &v11[inSection->m_exportsOffset],
    inSection->m_importsOffset - inSection->m_exportsOffset);
  hkString::memCpy(
    &outBuffer[v8 + outSection->m_importsOffset],
    &v11[inSection->m_importsOffset],
    inSection->m_endOffset - inSection->m_importsOffset);
}

// File Line: 231
// RVA: 0xE59800
void __fastcall applyLocalFixups(
        hkPackfileSectionHeader *inSection,
        hkPackfileSectionHeader *outSection,
        int outCurOffset,
        char *packfileData,
        char *outBuffer)
{
  __int64 m_localFixupsOffset; // rdx
  char *v6; // r10
  char *v7; // r8
  int v8; // r9d
  char *v9; // r8
  __int64 v10; // rax

  m_localFixupsOffset = inSection->m_localFixupsOffset;
  v6 = &outBuffer[outCurOffset];
  v7 = &packfileData[inSection->m_absoluteDataStart];
  v8 = 0;
  v9 = &v7[m_localFixupsOffset];
  if ( (inSection->m_globalFixupsOffset - (int)m_localFixupsOffset) / 4 > 0 )
  {
    do
    {
      v10 = *(int *)v9;
      if ( (_DWORD)v10 != -1 )
        *(_QWORD *)&v6[v10] = &v6[*((int *)v9 + 1)];
      v8 += 2;
      v9 += 8;
    }
    while ( v8 < (inSection->m_globalFixupsOffset - inSection->m_localFixupsOffset) / 4 );
  }
}

// File Line: 253
// RVA: 0xE59870
void __fastcall applyGlobalFixups(
        hkPackfileSectionHeader *inSection,
        hkPackfileSectionHeader *outSection,
        char *packfileData,
        char *outBuffer,
        hkArrayBase<hkPackfileSectionHeader *> *outSectionAddresses)
{
  int v6; // r10d
  char *v7; // rdi
  __int64 v9; // rcx
  char *v10; // r8
  __int64 v11; // rdx
  hkPackfileSectionHeader *v12; // r9
  char *v13; // rax

  v6 = 0;
  v7 = &outBuffer[outSection->m_absoluteDataStart];
  v9 = inSection->m_globalFixupsOffset + inSection->m_absoluteDataStart + 8i64;
  if ( (inSection->m_virtualFixupsOffset - inSection->m_globalFixupsOffset) / 4 > 0 )
  {
    v10 = &packfileData[v9];
    do
    {
      v11 = *((int *)v10 - 2);
      if ( (_DWORD)v11 != -1 )
      {
        v12 = outSectionAddresses->m_data[*((int *)v10 - 1)];
        if ( v12->m_localFixupsOffset )
          v13 = &outBuffer[*(_DWORD *)v10 + v12->m_absoluteDataStart];
        else
          v13 = 0i64;
        *(_QWORD *)&v7[v11] = v13;
      }
      v6 += 3;
      v10 += 12;
    }
    while ( v6 < (inSection->m_virtualFixupsOffset - inSection->m_globalFixupsOffset) / 4 );
  }
}

// File Line: 279
// RVA: 0xE59920
void __fastcall applyVirtualFixups(
        hkPackfileSectionHeader *inSection,
        hkPackfileSectionHeader *outSection,
        char *packfileData,
        _QWORD *outBuffer,
        hkArrayBase<hkPackfileSectionHeader *> *outSectionAddresses,
        hkArray<LOCALNAMESPACE::TrackedObjectsArray_Element,hkContainerHeapAllocator> *map,
        hkTypeInfoRegistry *finishRegistry,
        hkClassNameRegistry *classNameRegistry,
        hkArray<hkVariant,hkContainerHeapAllocator> *postFinishObjects)
{
  char *v10; // r11
  __int64 v11; // r9
  int v12; // r10d
  _DWORD *v13; // r14
  __int64 v14; // rdi
  hkPackfileSectionHeader *v15; // rdx
  char *v16; // r8
  char *v17; // r15
  __int64 v18; // rax
  hkTypeInfo *v19; // rbx
  LOCALNAMESPACE::TrackedObjectsArray_Element *v20; // rcx
  char *v21; // rdx
  hkClass *v22; // rax
  hkClass *v23; // rbx
  hkVariant *v24; // rax
  __int64 v25; // kr00_8
  char *v26; // [rsp+20h] [rbp-78h]
  __int64 v27; // [rsp+28h] [rbp-70h]
  __int64 v28; // [rsp+30h] [rbp-68h]
  __int64 v29; // [rsp+40h] [rbp-58h]
  int v32; // [rsp+B0h] [rbp+18h]
  char *v33; // [rsp+B8h] [rbp+20h]

  v10 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v32 = 0;
  v33 = v10;
  v11 = (__int64)&packfileData[inSection->m_virtualFixupsOffset + inSection->m_absoluteDataStart];
  v26 = (char *)outBuffer + *((int *)outBuffer + 1);
  if ( (inSection->m_exportsOffset - inSection->m_virtualFixupsOffset) / 4 > 0 )
  {
    v12 = 0;
    v13 = (_DWORD *)(v11 + 8);
    v28 = -v11;
    v27 = -4 - v11;
    do
    {
      v14 = (int)*(v13 - 2);
      if ( (_DWORD)v14 != -1 )
      {
        v15 = outSectionAddresses->m_data[*(v13 - 1)];
        if ( v15->m_localFixupsOffset )
          v16 = (char *)outBuffer + *v13 + v15->m_absoluteDataStart;
        else
          v16 = 0i64;
        v17 = &v10[v14];
        v18 = ((__int64 (__fastcall *)(hkTypeInfoRegistry *, char *, char *))finishRegistry->vfptr[2].__vecDelDtor)(
                finishRegistry,
                &v10[v14],
                v16);
        v19 = (hkTypeInfo *)v18;
        if ( v18 )
        {
          if ( map )
          {
            LODWORD(v29) = v14 + outSection->m_absoluteDataStart;
            if ( map->m_size == (map->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&map->m_data, 16);
            v20 = &map->m_data[map->m_size];
            if ( v20 )
            {
              v20->m_typeInfo = v19;
              *(_QWORD *)&v20->m_offset = v29;
            }
            ++map->m_size;
            if ( v17 == v26 )
              outBuffer[5] = v19;
          }
          else
          {
            v21 = (char *)outBuffer + outSection->m_absoluteDataStart + outSection->m_virtualFixupsOffset;
            *(_DWORD *)&v21[(_QWORD)v13 + v27] = HIDWORD(v18);
            *(_DWORD *)&v21[(_QWORD)v13 + v28] = v18;
          }
          if ( classNameRegistry )
          {
            v22 = (hkClass *)classNameRegistry->vfptr[2].__vecDelDtor(classNameRegistry, v19->m_typeName);
            v23 = v22;
            if ( v22 )
            {
              if ( hkClass::getAttribute(v22, "hk.PostFinish") )
              {
                if ( postFinishObjects->m_size == (postFinishObjects->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    &hkContainerHeapAllocator::s_alloc,
                    (const void **)&postFinishObjects->m_data,
                    16);
                v24 = &postFinishObjects->m_data[postFinishObjects->m_size];
                if ( v24 )
                {
                  v24->m_object = v17;
                  v24->m_class = v23;
                }
                ++postFinishObjects->m_size;
              }
            }
          }
        }
        v12 = v32;
        v10 = v33;
      }
      v12 += 3;
      v13 += 3;
      v32 = v12;
      v25 = inSection->m_exportsOffset - inSection->m_virtualFixupsOffset;
    }
    while ( v12 < ((BYTE4(v25) & 3) + (int)v25) >> 2 );
  }
}ortsOffset - inSection->m_vi

// File Line: 354
// RVA: 0xE58AB0
char *__fastcall hkNativePackfileUtils::load(
        hkPackfileHeader *packfileData,
        int packfileSize,
        char *outBuffer,
        int outBufferSize,
        hkTypeInfoRegistry *userRegistry)
{
  char *v5; // r12
  int m_numSections; // r10d
  int v9; // edi
  int m_size; // ecx
  int v11; // r15d
  hkLifoAllocator *Value; // rax
  hkPackfileSectionHeader **m_cur; // r8
  int v14; // edx
  char *v15; // rcx
  hkPackfileSectionHeader **v16; // rax
  int m_capacityAndFlags; // edi
  bool v18; // cc
  int v19; // r13d
  hkPackfileSectionHeader *v20; // r14
  int v21; // edi
  __int64 v22; // r13
  hkPackfileSectionHeader *SectionHeader; // rax
  hkPackfileSectionHeader *v24; // r14
  int i; // edi
  hkPackfileSectionHeader *v26; // rax
  hkTypeInfoRegistry *v27; // r15
  __int64 v28; // rax
  int v29; // r8d
  hkClassNameRegistry *classNameRegistry; // r13
  int v31; // ecx
  int v32; // edi
  hkPackfileSectionHeader *v33; // rax
  int v34; // r14d
  __int64 v35; // rdi
  void *m_object; // rbx
  hkVariant *Attribute; // rax
  __int64 v38; // r14
  char *v39; // r14
  int v40; // eax
  char *v41; // rdi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // r8d
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+50h] [rbp-30h] BYREF
  hkArrayBase<hkPackfileSectionHeader *> array; // [rsp+60h] [rbp-20h] BYREF
  void *p; // [rsp+70h] [rbp-10h]
  int v49; // [rsp+78h] [rbp-8h]
  hkPackfileSectionHeader *inSection; // [rsp+C0h] [rbp+40h]

  v5 = outBuffer + 24;
  *(_DWORD *)outBuffer = -720334526;
  if ( outBuffer != (char *)-24i64 )
  {
    m_numSections = packfileData->m_numSections;
    *((_DWORD *)outBuffer + 8) = m_numSections;
    *(_QWORD *)v5 = outBuffer + 48;
    *((_DWORD *)outBuffer + 9) = m_numSections | 0x80000000;
  }
  v9 = packfileData->m_numSections;
  array.m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  m_size = 0;
  array.m_size = 0;
  v49 = v9;
  v11 = (v9 << 6) + 48;
  if ( v9 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkPackfileSectionHeader **)Value->m_cur;
    v14 = (8 * v9 + 127) & 0xFFFFFF80;
    v15 = (char *)m_cur + v14;
    if ( v14 > Value->m_slabSize || v15 > Value->m_end )
    {
      v16 = (hkPackfileSectionHeader **)hkLifoAllocator::allocateFromNewSlab(Value, v14);
      m_size = array.m_size;
      array.m_data = v16;
    }
    else
    {
      Value->m_cur = v15;
      m_size = array.m_size;
      array.m_data = m_cur;
    }
  }
  else
  {
    array.m_data = 0i64;
  }
  m_capacityAndFlags = v9 | 0x80000000;
  v18 = *((_DWORD *)v5 + 2) <= 0;
  array.m_capacityAndFlags = m_capacityAndFlags;
  v19 = 0;
  p = array.m_data;
  if ( !v18 )
  {
    while ( 1 )
    {
      v20 = (hkPackfileSectionHeader *)(*(_QWORD *)v5 + ((__int64)v19 << 6));
      if ( m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
        m_size = array.m_size;
      }
      ++v19;
      array.m_data[m_size] = v20;
      m_size = ++array.m_size;
      if ( v19 >= *((_DWORD *)v5 + 2) )
        break;
      m_capacityAndFlags = array.m_capacityAndFlags;
    }
  }
  v21 = 0;
  if ( packfileData->m_numSections > 0 )
  {
    v22 = 0i64;
    do
    {
      SectionHeader = hkPackfileHeader::getSectionHeader(packfileData, packfileData, v21);
      v24 = (hkPackfileSectionHeader *)(v22 + *(_QWORD *)v5);
      inSection = SectionHeader;
      copySection(SectionHeader, v24, v11, packfileData, outBuffer, packfileSize, outBufferSize);
      if ( v21 == packfileData->m_contentsSectionIndex )
        *((_DWORD *)outBuffer + 1) = v11 + packfileData->m_contentsSectionOffset;
      applyLocalFixups(inSection, v24, v11, packfileData, outBuffer);
      v11 += v24->m_endOffset;
      ++v21;
      v22 += 64i64;
    }
    while ( v21 < packfileData->m_numSections );
  }
  for ( i = 0; i < packfileData->m_numSections; ++i )
  {
    v26 = hkPackfileHeader::getSectionHeader(packfileData, packfileData, i);
    if ( v26->m_virtualFixupsOffset != v26->m_globalFixupsOffset )
      applyGlobalFixups(
        v26,
        (hkPackfileSectionHeader *)(*(_QWORD *)v5 + ((__int64)i << 6)),
        packfileData,
        outBuffer,
        &array);
  }
  if ( outBuffer != (char *)-8i64 )
  {
    *((_DWORD *)outBuffer + 4) = 0;
    *((_QWORD *)outBuffer + 1) = &outBuffer[v11];
    *((_DWORD *)outBuffer + 5) = (outBufferSize - v11) | 0x80000000;
  }
  v27 = userRegistry;
  if ( !userRegistry )
    v27 = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, _QWORD))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
                                  hkSingleton<hkBuiltinTypeRegistry>::s_instance,
                                  0i64);
  v28 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v29 = 0x80000000;
  *((_QWORD *)outBuffer + 5) = 0i64;
  classNameRegistry = (hkClassNameRegistry *)v28;
  postFinishObjects.m_data = 0i64;
  v31 = 0;
  postFinishObjects.m_size = 0;
  postFinishObjects.m_capacityAndFlags = 0x80000000;
  v32 = 0;
  if ( packfileData->m_numSections > 0 )
  {
    do
    {
      v33 = hkPackfileHeader::getSectionHeader(packfileData, packfileData, v32);
      if ( v33->m_exportsOffset != v33->m_virtualFixupsOffset )
        applyVirtualFixups(
          v33,
          (hkPackfileSectionHeader *)(*(_QWORD *)v5 + ((__int64)v32 << 6)),
          packfileData,
          outBuffer,
          &array,
          (hkArray<LOCALNAMESPACE::TrackedObjectsArray_Element,hkContainerHeapAllocator> *)(outBuffer + 8),
          v27,
          classNameRegistry,
          &postFinishObjects);
      ++v32;
    }
    while ( v32 < packfileData->m_numSections );
    v29 = postFinishObjects.m_capacityAndFlags;
    v31 = postFinishObjects.m_size;
  }
  v34 = 0;
  if ( v31 > 0 )
  {
    v35 = 0i64;
    do
    {
      m_object = postFinishObjects.m_data[v35].m_object;
      Attribute = hkClass::getAttribute(postFinishObjects.m_data[v35].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))Attribute->m_object)(m_object);
      ++v34;
      ++v35;
    }
    while ( v34 < postFinishObjects.m_size );
    v29 = postFinishObjects.m_capacityAndFlags;
  }
  v38 = *((int *)outBuffer + 1);
  postFinishObjects.m_size = 0;
  v39 = &outBuffer[v38];
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * v29);
  v40 = array.m_size;
  v41 = (char *)p;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( p == array.m_data )
    v40 = 0;
  array.m_size = v40;
  v42 = (8 * v49 + 127) & 0xFFFFFF80;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (v42 + 15) & 0xFFFFFFF0;
  if ( v42 > v43->m_slabSize || &v41[v44] != v43->m_cur || v43->m_firstNonLifoEnd == v41 )
    hkLifoAllocator::slowBlockFree(v43, v41, v44);
  else
    v43->m_cur = v41;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  return v39;
}

// File Line: 455
// RVA: 0xE58EC0
char *__fastcall hkNativePackfileUtils::loadInPlace(
        hkPackfileHeader *packfileData,
        int dataSize,
        hkTypeInfoRegistry *userRegistry,
        const char **errOut)
{
  __int64 v4; // r15
  int m_flags; // eax
  int m_numSections; // ebx
  int v10; // r13d
  hkLifoAllocator *Value; // rax
  hkPackfileSectionHeader **m_cur; // r8
  int v13; // edx
  char *v14; // rcx
  int v15; // ebx
  hkPackfileSectionHeader *SectionHeader; // rax
  int m_size; // edx
  hkPackfileSectionHeader *v18; // rsi
  int i; // esi
  hkPackfileSectionHeader *v20; // rbx
  int m_absoluteDataStart; // r14d
  int v22; // ebx
  __int64 v23; // rsi
  hkPackfileSectionHeader *v24; // rcx
  __int64 v25; // rax
  bool v26; // cc
  int v27; // ecx
  int m_capacityAndFlags; // r8d
  hkClassNameRegistry *classNameRegistry; // r14
  int v30; // esi
  __int64 v31; // rbx
  hkPackfileSectionHeader *v32; // rcx
  int v33; // r14d
  __int64 v34; // rsi
  void *m_object; // rbx
  hkVariant *Attribute; // rax
  char *v37; // rsi
  int v38; // eax
  char *v39; // rdi
  signed int v40; // ebx
  hkLifoAllocator *v41; // rax
  int v42; // r8d
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+50h] [rbp+7h] BYREF
  hkArrayBase<hkPackfileSectionHeader *> array; // [rsp+60h] [rbp+17h] BYREF
  void *p; // [rsp+70h] [rbp+27h]
  int v46; // [rsp+78h] [rbp+2Fh]
  hkResult result; // [rsp+C8h] [rbp+7Fh] BYREF

  v4 = 0i64;
  if ( errOut )
    *errOut = 0i64;
  if ( hkNativePackfileUtils::validatePackfileHeader(&result, packfileData, errOut)->m_enum )
    return 0i64;
  m_flags = packfileData->m_flags;
  if ( (m_flags & 1) != 0 )
    return 0i64;
  m_numSections = packfileData->m_numSections;
  v10 = -1;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  packfileData->m_flags = m_flags | 1;
  v46 = m_numSections;
  if ( m_numSections )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkPackfileSectionHeader **)Value->m_cur;
    v13 = (8 * m_numSections + 127) & 0xFFFFFF80;
    v14 = (char *)m_cur + v13;
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
    {
      array.m_data = (hkPackfileSectionHeader **)hkLifoAllocator::allocateFromNewSlab(Value, v13);
    }
    else
    {
      Value->m_cur = v14;
      array.m_data = m_cur;
    }
  }
  else
  {
    array.m_data = 0i64;
  }
  array.m_capacityAndFlags = m_numSections | 0x80000000;
  v15 = 0;
  for ( p = array.m_data; v15 < packfileData->m_numSections; ++array.m_size )
  {
    SectionHeader = hkPackfileHeader::getSectionHeader(packfileData, packfileData, v15);
    m_size = array.m_size;
    v18 = SectionHeader;
    if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 8);
      m_size = array.m_size;
    }
    ++v15;
    array.m_data[m_size] = v18;
  }
  for ( i = 0; i < packfileData->m_numSections; ++v4 )
  {
    v20 = array.m_data[v4];
    m_absoluteDataStart = v20->m_absoluteDataStart;
    hkString::strCmp(v20->m_sectionTag, "__types__");
    if ( i == packfileData->m_contentsSectionIndex )
      v10 = m_absoluteDataStart + packfileData->m_contentsSectionOffset;
    applyLocalFixups(v20, v20, m_absoluteDataStart, packfileData, packfileData);
    ++i;
  }
  v22 = 0;
  if ( packfileData->m_numSections > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = array.m_data[v23];
      if ( v24->m_virtualFixupsOffset != v24->m_globalFixupsOffset )
        applyGlobalFixups(v24, array.m_data[v23], packfileData, packfileData, &array);
      ++v22;
      ++v23;
    }
    while ( v22 < packfileData->m_numSections );
  }
  if ( !userRegistry )
    userRegistry = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v25 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v26 = packfileData->m_numSections <= 0;
  v27 = 0;
  m_capacityAndFlags = 0x80000000;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_size = 0;
  classNameRegistry = (hkClassNameRegistry *)v25;
  v30 = 0;
  postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( !v26 )
  {
    v31 = 0i64;
    do
    {
      v32 = array.m_data[v31];
      if ( v32->m_exportsOffset != v32->m_virtualFixupsOffset )
        applyVirtualFixups(
          v32,
          v32,
          packfileData,
          packfileData,
          &array,
          0i64,
          userRegistry,
          classNameRegistry,
          &postFinishObjects);
      ++v30;
      ++v31;
    }
    while ( v30 < packfileData->m_numSections );
    m_capacityAndFlags = postFinishObjects.m_capacityAndFlags;
    v27 = postFinishObjects.m_size;
  }
  v33 = 0;
  if ( v27 > 0 )
  {
    v34 = 0i64;
    do
    {
      m_object = postFinishObjects.m_data[v34].m_object;
      Attribute = hkClass::getAttribute(postFinishObjects.m_data[v34].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))Attribute->m_object)(m_object);
      ++v33;
      ++v34;
    }
    while ( v33 < postFinishObjects.m_size );
    m_capacityAndFlags = postFinishObjects.m_capacityAndFlags;
  }
  v37 = (char *)packfileData + v10;
  postFinishObjects.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * m_capacityAndFlags);
  v38 = array.m_size;
  v39 = (char *)p;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_capacityAndFlags = 0x80000000;
  if ( p == array.m_data )
    v38 = 0;
  array.m_size = v38;
  v40 = (8 * v46 + 127) & 0xFFFFFF80;
  v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v42 = (v40 + 15) & 0xFFFFFFF0;
  if ( v40 > v41->m_slabSize || &v39[v42] != v41->m_cur || v41->m_firstNonLifoEnd == v39 )
    hkLifoAllocator::slowBlockFree(v41, v39, v42);
  else
    v41->m_cur = v39;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
  return v37;
}

// File Line: 553
// RVA: 0xE59290
const char *__fastcall hkNativePackfileUtils::getContentsClassName(_DWORD *packfileData, int dataSize)
{
  int v3; // eax
  int v4; // edx

  if ( packfileData
    && dataSize >= 64
    && *packfileData == 1474355287
    && packfileData[1] == 281067536
    && (v3 = packfileData[5], v3 > 0)
    && dataSize >= (v3 + 1) << 6
    && (v4 = packfileData[9] + packfileData[16 * (__int64)(int)packfileData[8] + 21], v4 <= dataSize) )
  {
    return (char *)packfileData + v4;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 578
// RVA: 0xE59380
void __fastcall hkNativePackfileUtils::unload(_QWORD *buffer, int bufferSize)
{
  unsigned __int64 v3; // rdi
  int v4; // r8d
  int v5; // r8d

  *(_DWORD *)buffer = 0;
  v3 = buffer[1];
  if ( v3 < v3 + 16i64 * *((int *)buffer + 4) )
  {
    do
    {
      hkTypeInfo::cleanupLoadedObject(*(hkTypeInfo **)v3, (char *)buffer + *(int *)(v3 + 8));
      v3 += 16i64;
    }
    while ( v3 < buffer[1] + 16i64 * *((int *)buffer + 4) );
  }
  v4 = *((_DWORD *)buffer + 9);
  *((_DWORD *)buffer + 8) = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, (void *)buffer[3], v4 << 6);
  buffer[3] = 0i64;
  *((_DWORD *)buffer + 9) = 0x80000000;
  v5 = *((_DWORD *)buffer + 5);
  *((_DWORD *)buffer + 4) = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, (void *)buffer[1], 16 * v5);
  buffer[1] = 0i64;
  *((_DWORD *)buffer + 5) = 0x80000000;
}

// File Line: 597
// RVA: 0xE59460
void __fastcall hkNativePackfileUtils::unloadInPlace(hkPackfileHeader *buffer, int bufferSize)
{
  int i; // ebp
  hkPackfileSectionHeader *SectionHeader; // rdi
  int m_virtualFixupsOffset; // edx
  int v6; // eax
  int v7; // esi
  unsigned int *v8; // rbx
  __int64 v9; // rdx
  hkTypeInfo *v10; // rcx

  for ( i = 0; i < buffer->m_numSections; ++i )
  {
    SectionHeader = hkPackfileHeader::getSectionHeader(buffer, buffer, i);
    m_virtualFixupsOffset = SectionHeader->m_virtualFixupsOffset;
    v6 = SectionHeader->m_exportsOffset - m_virtualFixupsOffset;
    if ( v6 )
    {
      v7 = 0;
      if ( v6 / 4 > 0 )
      {
        v8 = (unsigned int *)((char *)&buffer->m_magic[2] + SectionHeader->m_absoluteDataStart + m_virtualFixupsOffset);
        do
        {
          v9 = (int)*(v8 - 2);
          if ( (_DWORD)v9 != -1 )
          {
            v10 = (hkTypeInfo *)(*v8 | (unsigned __int64)((__int64)(int)*(v8 - 1) << 32));
            if ( v10 )
              hkTypeInfo::cleanupLoadedObject(v10, (char *)buffer + v9 + SectionHeader->m_absoluteDataStart);
          }
          v7 += 3;
          v8 += 3;
        }
        while ( v7 < (SectionHeader->m_exportsOffset - SectionHeader->m_virtualFixupsOffset) / 4 );
      }
    }
  }
}

// File Line: 632
// RVA: 0xE592F0
void __fastcall hkNativePackfileUtils::getImportsExports(
        _QWORD *loadedBuffer,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut)
{
  int v3; // esi
  __int64 v7; // r14
  hkPackfileSectionHeader *v8; // rdi
  char *v9; // rbx

  v3 = 0;
  if ( *((int *)loadedBuffer + 8) > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = (hkPackfileSectionHeader *)(v7 + loadedBuffer[3]);
      v9 = (char *)loadedBuffer + v8->m_absoluteDataStart;
      hkPackfileSectionHeader::getExports(v8, v9, expOut);
      hkPackfileSectionHeader::getImports(v8, v9, impOut);
      ++v3;
      v7 += 64i64;
    }
    while ( v3 < *((_DWORD *)loadedBuffer + 8) );
  }
}

// File Line: 646
// RVA: 0xE59BC0
void __fastcall getImportsExportsInPlace(
        hkPackfileSectionHeader *loadedBuffer,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut)
{
  int v3; // esi
  hkPackfileSectionHeader *i; // rbx
  char *v8; // rdi

  v3 = 0;
  for ( i = loadedBuffer + 1; v3 < loadedBuffer->m_absoluteDataStart; ++i )
  {
    v8 = &loadedBuffer->m_sectionTag[i->m_absoluteDataStart];
    hkPackfileSectionHeader::getExports(i, v8, expOut);
    hkPackfileSectionHeader::getImports(i, v8, impOut);
    ++v3;
  }
}

