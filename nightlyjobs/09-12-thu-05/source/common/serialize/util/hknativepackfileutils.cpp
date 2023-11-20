// File Line: 72
// RVA: 0xE59D30
void __fastcall LOCALNAMESPACE::hkNativeResource::callDestructors(LOCALNAMESPACE::hkNativeResource *this)
{
  LOCALNAMESPACE::hkNativeResource *v1; // rbx

  v1 = this;
  if ( this->m_contents )
  {
    hkNativePackfileUtils::unload(this->m_data.m_data, this->m_data.m_size);
    v1->m_contents = 0i64;
    v1->m_contentsTypeName = 0i64;
  }
}

// File Line: 82
// RVA: 0xE59C50
void __fastcall LOCALNAMESPACE::hkNativeResource::~hkNativeResource(LOCALNAMESPACE::hkNativeResource *this)
{
  LOCALNAMESPACE::hkNativeResource *v1; // rbx
  int v2; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&LOCALNAMESPACE::hkNativeResource::`vftable;
  if ( this->m_contents )
  {
    hkNativePackfileUtils::unload(this->m_data.m_data, this->m_data.m_size);
    v1->m_contents = 0i64;
    v1->m_contentsTypeName = 0i64;
  }
  v2 = v1->m_data.m_capacityAndFlags;
  v1->m_data.m_size = 0;
  if ( v2 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_data.m_data,
      v2 & 0x3FFFFFFF);
  v1->m_data.m_data = 0i64;
  v1->m_data.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 87
// RVA: 0xE59E20
const char *__fastcall LOCALNAMESPACE::hkNativeResource::getName(LOCALNAMESPACE::hkNativeResource *this)
{
  return "hkNativeResource";
}

// File Line: 91
// RVA: 0xE59D60
void *__fastcall LOCALNAMESPACE::hkNativeResource::getContentsPointer(LOCALNAMESPACE::hkNativeResource *this, const char *typeName, hkTypeInfoRegistry *ignoredBecauseAlreadyDone)
{
  const char *v3; // rsi
  LOCALNAMESPACE::hkNativeResource *v4; // rdi
  __int64 v5; // rbx
  hkClass *v6; // rbp
  hkClass *v7; // rax
  void *v8; // rax
  hkBool result; // [rsp+38h] [rbp+10h]

  v3 = typeName;
  v4 = this;
  if ( typeName
    && (v5 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, const char *, hkTypeInfoRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(
               hkSingleton<hkBuiltinTypeRegistry>::s_instance,
               typeName,
               ignoredBecauseAlreadyDone),
        v6 = (hkClass *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v5 + 32i64))(
                          v5,
                          v4->m_contentsTypeName),
        v7 = (hkClass *)(*(__int64 (__fastcall **)(__int64, const char *))(*(_QWORD *)v5 + 32i64))(v5, v3),
        v6)
    && v7
    && !hkClass::isSuperClass(v7, &result, v6)->m_bool )
  {
    v8 = 0i64;
  }
  else
  {
    v8 = v4->m_contents;
  }
  return v8;
}

// File Line: 111
// RVA: 0xE59E00
void __fastcall LOCALNAMESPACE::hkNativeResource::getImportsExports(LOCALNAMESPACE::hkNativeResource *this, hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut, hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  hkNativePackfileUtils::getImportsExports(this->m_data.m_data, expOut, impOut);
}

// File Line: 129
// RVA: 0xE588C0
hkResource *__fastcall hkNativePackfileUtils::load(const void *packfileData, int dataSize, hkTypeInfoRegistry *userRegistry)
{
  hkTypeInfoRegistry *v3; // rbp
  int v4; // edi
  const void *v5; // rsi
  int v6; // eax
  int v7; // ebx
  int v8; // er9
  void *v9; // rdi
  _QWORD **v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rax
  signed __int64 v13; // rcx
  _QWORD **array; // [rsp+30h] [rbp-28h]
  int v16; // [rsp+38h] [rbp-20h]
  int v17; // [rsp+3Ch] [rbp-1Ch]
  hkResult result; // [rsp+78h] [rbp+20h]

  v3 = userRegistry;
  v4 = dataSize;
  v5 = packfileData;
  v17 = 2147483648;
  array = 0i64;
  v16 = 0;
  v6 = hkNativePackfileUtils::getRequiredBufferSize(packfileData, dataSize);
  v7 = v6;
  if ( v6 > 0 )
  {
    v8 = v6;
    if ( v6 < 0 )
      v8 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v8, 1);
  }
  v16 = v7;
  v9 = hkNativePackfileUtils::load(v5, v4, array, v7, v3);
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 48i64);
  if ( v11 )
  {
    v12 = *array[5];
    *(_QWORD *)v11 = &LOCALNAMESPACE::hkNativeResource::`vftable;
    v13 = v11 + 16;
    *(_DWORD *)(v11 + 8) = 0x1FFFF;
    *(_QWORD *)v13 = 0i64;
    *(_DWORD *)(v13 + 8) = 0;
    *(_DWORD *)(v13 + 12) = 2147483648;
    *(_QWORD *)(v11 + 32) = v9;
    *(_QWORD *)(v11 + 40) = v12;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)(v11 + 16),
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
  }
  else
  {
    v11 = 0i64;
  }
  v16 = 0;
  if ( v17 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      v17 & 0x3FFFFFFF);
  return (hkResource *)v11;
}

// File Line: 139
// RVA: 0xE596E0
char *__fastcall getSectionDataByIndex(void *base, hkArrayBase<hkPackfileSectionHeader *> *sections, int sectionIndex, int offset)
{
  hkPackfileSectionHeader *v4; // rdx
  char *result; // rax

  v4 = sections->m_data[sectionIndex];
  if ( v4->m_localFixupsOffset )
    result = (char *)base + offset + v4->m_absoluteDataStart;
  else
    result = 0i64;
  return result;
}

// File Line: 151
// RVA: 0xE59540
hkResult *__fastcall hkNativePackfileUtils::validatePackfileHeader(hkResult *result, const void *packfileData, const char **errOut)
{
  const char **v3; // rdi
  const char *v4; // rsi
  hkResult *v5; // rbx
  bool v7; // zf
  const char *v8; // rax
  const char *v9; // rax
  int dst; // [rsp+20h] [rbp-48h]
  int v11; // [rsp+24h] [rbp-44h]
  char v12; // [rsp+48h] [rbp-20h]
  __int64 v13; // [rsp+58h] [rbp-10h]

  v3 = errOut;
  v4 = (const char *)packfileData;
  v5 = result;
  if ( packfileData )
  {
    hkString::memSet(&dst, -1, 64);
    v7 = *(_DWORD *)v4 == 1474355287;
    dst = 1474355287;
    v11 = 281067536;
    v12 = 0;
    v13 = 0i64;
    if ( v7 && *((_DWORD *)v4 + 1) == 281067536 )
    {
      if ( v4[16] == hkStructureLayout::HostLayoutRules.m_bytesInPointer )
      {
        if ( v4[17] == hkStructureLayout::HostLayoutRules.m_littleEndian )
        {
          if ( v4[18] == hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization )
          {
            if ( v4[19] == hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization )
            {
              if ( (unsigned __int8)v4 & 3 )
              {
                if ( v3 )
                {
                  v8 = "Packfile data source needs to be 4 byte aligned";
                  goto LABEL_31;
                }
              }
              else
              {
                if ( v4[40] != -1 )
                {
                  v9 = hkVersionUtil::getCurrentVersion();
                  if ( !(unsigned int)hkString::strCmp(v4 + 40, v9) )
                  {
                    v5->m_enum = 0;
                    return v5;
                  }
                  if ( !v3 )
                    goto LABEL_32;
                  v8 = "Packfile contents are not up to date";
                  goto LABEL_31;
                }
                if ( v3 )
                {
                  v8 = "Packfile file format is too old";
                  goto LABEL_31;
                }
              }
            }
            else if ( v3 )
            {
              v8 = "Trying to process a binary file with a different empty base class optimization than this platform.";
              goto LABEL_31;
            }
          }
          else if ( v3 )
          {
            v8 = "Trying to process a binary file with a different padding optimization than this platform.";
            goto LABEL_31;
          }
        }
        else if ( v3 )
        {
          v8 = "Trying to process a binary file with a different endian than this platform.";
          goto LABEL_31;
        }
      }
      else if ( v3 )
      {
        v8 = "Trying to process a binary file with a different pointer size than this platform.";
LABEL_31:
        *v3 = v8;
        goto LABEL_32;
      }
    }
    else if ( v3 )
    {
      v8 = "Missing packfile magic header. Is this from a binary file?";
      goto LABEL_31;
    }
LABEL_32:
    v5->m_enum = 1;
    return v5;
  }
  if ( errOut )
    *errOut = "Pointer is null";
  result->m_enum = 1;
  return result;
}

// File Line: 170
// RVA: 0xE58A10
signed __int64 __fastcall hkNativePackfileUtils::getRequiredBufferSize(const void *packfileData, int packfileSize)
{
  unsigned int v2; // ebx
  hkPackfileHeader *v3; // rdi
  unsigned int v4; // ebp
  int v5; // esi
  hkPackfileSectionHeader *v6; // rax
  signed __int64 v7; // kr00_8

  v2 = 0;
  v3 = (hkPackfileHeader *)packfileData;
  v4 = 0;
  v5 = 0;
  if ( *((_DWORD *)packfileData + 5) > 0 )
  {
    do
    {
      v6 = hkPackfileHeader::getSectionHeader(v3, v3, v5++);
      v7 = 715827883i64 * (v6->m_exportsOffset - v6->m_virtualFixupsOffset);
      v4 += (HIDWORD(v7) >> 31) + (SHIDWORD(v7) >> 1);
      v2 += v6->m_localFixupsOffset + v6->m_endOffset - v6->m_exportsOffset;
    }
    while ( v5 < v3->m_numSections );
  }
  return v2 + 16 * (v4 + 4i64 * (unsigned int)v3->m_numSections + 3);
}

// File Line: 199
// RVA: 0xE59710
void __fastcall copySection(hkPackfileSectionHeader *inSection, hkPackfileSectionHeader *outSection, int outCurOffset, const void *packfileData, void *outBuffer, int packfileSize, int outBufferSize)
{
  hkPackfileSectionHeader *v7; // r14
  __int64 v8; // rsi
  hkPackfileSectionHeader *v9; // rbp
  char *v10; // rbx
  char *v11; // rdi

  v7 = outSection;
  v8 = outCurOffset;
  v9 = inSection;
  v10 = (char *)packfileData;
  hkString::memCpy(outSection, inSection, 19);
  v7->m_nullByte = v9->m_nullByte;
  v7->m_absoluteDataStart = v8;
  v7->m_localFixupsOffset = v9->m_localFixupsOffset;
  v7->m_globalFixupsOffset = v9->m_localFixupsOffset;
  v7->m_virtualFixupsOffset = v9->m_localFixupsOffset;
  v7->m_exportsOffset = v9->m_localFixupsOffset;
  v7->m_importsOffset = v9->m_importsOffset + v9->m_localFixupsOffset - v9->m_exportsOffset;
  v7->m_endOffset = v9->m_endOffset + v9->m_localFixupsOffset - v9->m_exportsOffset;
  v11 = &v10[v9->m_absoluteDataStart];
  hkString::memCpy((char *)outBuffer + v8, v11, v9->m_localFixupsOffset);
  hkString::memCpy(
    (char *)outBuffer + v8 + v7->m_exportsOffset,
    &v11[v9->m_exportsOffset],
    v9->m_importsOffset - v9->m_exportsOffset);
  hkString::memCpy(
    (char *)outBuffer + v8 + v7->m_importsOffset,
    &v11[v9->m_importsOffset],
    v9->m_endOffset - v9->m_importsOffset);
}

// File Line: 231
// RVA: 0xE59800
void __fastcall applyLocalFixups(hkPackfileSectionHeader *inSection, hkPackfileSectionHeader *outSection, int outCurOffset, const void *packfileData, void *outBuffer)
{
  __int64 v5; // rdx
  char *v6; // r10
  char *v7; // r8
  int v8; // er9
  char *v9; // r8
  __int64 v10; // rax

  v5 = inSection->m_localFixupsOffset;
  v6 = (char *)outBuffer + outCurOffset;
  v7 = (char *)packfileData + inSection->m_absoluteDataStart;
  v8 = 0;
  v9 = &v7[v5];
  if ( (inSection->m_globalFixupsOffset - (signed int)v5) / 4 > 0 )
  {
    do
    {
      v10 = *(signed int *)v9;
      if ( (_DWORD)v10 != -1 )
        *(_QWORD *)&v6[v10] = &v6[*((signed int *)v9 + 1)];
      v8 += 2;
      v9 += 8;
    }
    while ( v8 < (inSection->m_globalFixupsOffset - inSection->m_localFixupsOffset) / 4 );
  }
}

// File Line: 253
// RVA: 0xE59870
void __fastcall applyGlobalFixups(hkPackfileSectionHeader *inSection, hkPackfileSectionHeader *outSection, const void *packfileData, void *outBuffer, hkArrayBase<hkPackfileSectionHeader *> *outSectionAddresses)
{
  hkPackfileSectionHeader *v5; // r11
  int v6; // er10
  char *v7; // rdi
  char *v8; // rsi
  signed __int64 v9; // rcx
  _DWORD *v10; // r8
  __int64 v11; // rdx
  hkPackfileSectionHeader *v12; // r9
  char *v13; // rax

  v5 = inSection;
  v6 = 0;
  v7 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v8 = (char *)outBuffer;
  v9 = inSection->m_globalFixupsOffset + inSection->m_absoluteDataStart + 8i64;
  if ( (v5->m_virtualFixupsOffset - v5->m_globalFixupsOffset) / 4 > 0 )
  {
    v10 = (char *)packfileData + v9;
    do
    {
      v11 = (signed int)*(v10 - 2);
      if ( (_DWORD)v11 != -1 )
      {
        v12 = outSectionAddresses->m_data[*(v10 - 1)];
        if ( v12->m_localFixupsOffset )
          v13 = &v8[*v10 + v12->m_absoluteDataStart];
        else
          v13 = 0i64;
        *(_QWORD *)&v7[v11] = v13;
      }
      v6 += 3;
      v10 += 3;
    }
    while ( v6 < (v5->m_virtualFixupsOffset - v5->m_globalFixupsOffset) / 4 );
  }
}

// File Line: 279
// RVA: 0xE59920
void __fastcall applyVirtualFixups(hkPackfileSectionHeader *inSection, hkPackfileSectionHeader *outSection, const void *packfileData, void *outBuffer, hkArrayBase<hkPackfileSectionHeader *> *outSectionAddresses, hkArray<LOCALNAMESPACE::TrackedObjectsArray_Element,hkContainerHeapAllocator> *map, hkTypeInfoRegistry *finishRegistry, hkClassNameRegistry *classNameRegistry, hkArray<hkVariant,hkContainerHeapAllocator> *postFinishObjects)
{
  _QWORD *v9; // r13
  char *v10; // r11
  signed __int64 v11; // r9
  int v12; // er10
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
  char *v25; // [rsp+20h] [rbp-78h]
  signed __int64 v26; // [rsp+28h] [rbp-70h]
  signed __int64 v27; // [rsp+30h] [rbp-68h]
  __int64 v28; // [rsp+40h] [rbp-58h]
  hkPackfileSectionHeader *v29; // [rsp+A0h] [rbp+8h]
  hkPackfileSectionHeader *v30; // [rsp+A8h] [rbp+10h]
  int v31; // [rsp+B0h] [rbp+18h]
  char *v32; // [rsp+B8h] [rbp+20h]

  v30 = outSection;
  v29 = inSection;
  v9 = outBuffer;
  v10 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v31 = 0;
  v32 = (char *)outBuffer + outSection->m_absoluteDataStart;
  v11 = (signed __int64)packfileData + inSection->m_virtualFixupsOffset + inSection->m_absoluteDataStart;
  v25 = (char *)v9 + *((signed int *)v9 + 1);
  if ( (inSection->m_exportsOffset - inSection->m_virtualFixupsOffset) / 4 > 0 )
  {
    v12 = 0;
    v13 = (_DWORD *)(v11 + 8);
    v27 = -v11;
    v26 = -4 - v11;
    do
    {
      v14 = (signed int)*(v13 - 2);
      if ( (_DWORD)v14 != -1 )
      {
        v15 = outSectionAddresses->m_data[*(v13 - 1)];
        if ( v15->m_localFixupsOffset )
          v16 = (char *)v9 + *v13 + v15->m_absoluteDataStart;
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
            LODWORD(v28) = v14 + v30->m_absoluteDataStart;
            if ( map->m_size == (map->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, map, 16);
            v20 = &map->m_data[map->m_size];
            if ( v20 )
            {
              v20->m_typeInfo = v19;
              *(_QWORD *)&v20->m_offset = v28;
            }
            ++map->m_size;
            if ( v17 == v25 )
              v9[5] = v19;
          }
          else
          {
            v21 = (char *)v9 + v30->m_absoluteDataStart + v30->m_virtualFixupsOffset;
            *(_DWORD *)&v21[(_QWORD)v13 + v26] = HIDWORD(v18);
            *(_DWORD *)&v21[(_QWORD)v13 + v27] = v18;
          }
          if ( classNameRegistry )
          {
            v22 = (hkClass *)classNameRegistry->vfptr[2].__vecDelDtor(
                               (hkBaseObject *)classNameRegistry,
                               (unsigned int)v19->m_typeName);
            v23 = v22;
            if ( v22 )
            {
              if ( hkClass::getAttribute(v22, "hk.PostFinish") )
              {
                if ( postFinishObjects->m_size == (postFinishObjects->m_capacityAndFlags & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(
                    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                    postFinishObjects,
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
        v12 = v31;
        v10 = v32;
      }
      v12 += 3;
      v13 += 3;
      v31 = v12;
    }
    while ( v12 < (v29->m_exportsOffset - v29->m_virtualFixupsOffset) / 4 );
  }
}

// File Line: 354
// RVA: 0xE58AB0
char *__fastcall hkNativePackfileUtils::load(const void *packfileData, int packfileSize, void *outBuffer, int outBufferSize, hkTypeInfoRegistry *userRegistry)
{
  char *v5; // r12
  char *v6; // rsi
  hkPackfileHeader *v7; // rbx
  int v8; // er10
  int v9; // edi
  int v10; // ecx
  int v11; // er15
  hkLifoAllocator *v12; // rax
  int v13; // edx
  char *v14; // rcx
  void *v15; // rax
  unsigned int v16; // edi
  bool v17; // zf
  bool v18; // sf
  int v19; // er13
  signed __int64 v20; // r14
  int v21; // edi
  __int64 v22; // r13
  hkPackfileSectionHeader *v23; // rax
  hkPackfileSectionHeader *v24; // r14
  int i; // edi
  hkPackfileSectionHeader *v26; // rax
  hkTypeInfoRegistry *v27; // r15
  __int64 v28; // rax
  int v29; // er8
  hkClassNameRegistry *classNameRegistry; // r13
  int v31; // ecx
  int v32; // edi
  hkPackfileSectionHeader *v33; // rax
  int v34; // er14
  __int64 v35; // rdi
  void *v36; // rbx
  hkVariant *v37; // rax
  __int64 v38; // r14
  char *v39; // r14
  int v40; // eax
  char *v41; // rdi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // er8
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+50h] [rbp-30h]
  void *array; // [rsp+60h] [rbp-20h]
  int v48; // [rsp+68h] [rbp-18h]
  int v49; // [rsp+6Ch] [rbp-14h]
  void *p; // [rsp+70h] [rbp-10h]
  int v51; // [rsp+78h] [rbp-8h]
  hkPackfileSectionHeader *inSection; // [rsp+C0h] [rbp+40h]
  int v53; // [rsp+C8h] [rbp+48h]
  int v54; // [rsp+D8h] [rbp+58h]

  v54 = outBufferSize;
  v53 = packfileSize;
  v5 = (char *)outBuffer + 24;
  v6 = (char *)outBuffer;
  v7 = (hkPackfileHeader *)packfileData;
  *(_DWORD *)outBuffer = -720334526;
  if ( outBuffer != (void *)-24i64 )
  {
    v8 = *((_DWORD *)packfileData + 5);
    *((_DWORD *)outBuffer + 8) = v8;
    *(_QWORD *)v5 = (char *)outBuffer + 48;
    *((_DWORD *)outBuffer + 9) = v8 | 0x80000000;
  }
  v9 = *((_DWORD *)packfileData + 5);
  v49 = 2147483648;
  array = 0i64;
  v10 = 0;
  v48 = 0;
  v51 = v9;
  v11 = (v9 << 6) + 48;
  if ( v9 )
  {
    v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    outBuffer = v12->m_cur;
    v13 = (8 * v9 + 127) & 0xFFFFFF80;
    v14 = (char *)outBuffer + v13;
    if ( v13 > v12->m_slabSize || v14 > v12->m_end )
    {
      v15 = hkLifoAllocator::allocateFromNewSlab(v12, v13);
      v10 = v48;
      outBuffer = v15;
      array = v15;
    }
    else
    {
      v12->m_cur = v14;
      v10 = v48;
      array = outBuffer;
    }
  }
  else
  {
    array = 0i64;
  }
  v16 = v9 | 0x80000000;
  v17 = *((_DWORD *)v5 + 2) == 0;
  v18 = *((_DWORD *)v5 + 2) < 0;
  v49 = v16;
  v19 = 0;
  p = array;
  if ( !v18 && !v17 )
  {
    while ( 1 )
    {
      v20 = *(_QWORD *)v5 + ((signed __int64)v19 << 6);
      if ( v10 == (v16 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v10 = v48;
      }
      ++v19;
      *((_QWORD *)array + v10) = v20;
      v10 = v48++ + 1;
      if ( v19 >= *((_DWORD *)v5 + 2) )
        break;
      v16 = v49;
    }
  }
  v21 = 0;
  if ( v7->m_numSections > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = hkPackfileHeader::getSectionHeader(v7, v7, v21);
      v24 = (hkPackfileSectionHeader *)(v22 + *(_QWORD *)v5);
      inSection = v23;
      copySection(v23, (hkPackfileSectionHeader *)(v22 + *(_QWORD *)v5), v11, v7, v6, v53, v54);
      if ( v21 == v7->m_contentsSectionIndex )
        *((_DWORD *)v6 + 1) = v11 + v7->m_contentsSectionOffset;
      applyLocalFixups(inSection, v24, v11, v7, v6);
      v11 += v24->m_endOffset;
      ++v21;
      v22 += 64i64;
    }
    while ( v21 < v7->m_numSections );
  }
  for ( i = 0; i < v7->m_numSections; ++i )
  {
    v26 = hkPackfileHeader::getSectionHeader(v7, v7, i);
    if ( v26->m_virtualFixupsOffset != v26->m_globalFixupsOffset )
      applyGlobalFixups(
        v26,
        (hkPackfileSectionHeader *)(*(_QWORD *)v5 + ((signed __int64)i << 6)),
        v7,
        v6,
        (hkArrayBase<hkPackfileSectionHeader *> *)&array);
  }
  if ( v6 != (char *)-8i64 )
  {
    *((_DWORD *)v6 + 4) = 0;
    *((_QWORD *)v6 + 1) = &v6[v11];
    *((_DWORD *)v6 + 5) = (v54 - v11) | 0x80000000;
  }
  v27 = userRegistry;
  if ( !userRegistry )
    v27 = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, _QWORD, void *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
                                  hkSingleton<hkBuiltinTypeRegistry>::s_instance,
                                  0i64,
                                  outBuffer);
  v28 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, hkBaseObjectVtbl *, void *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(
          hkSingleton<hkBuiltinTypeRegistry>::s_instance,
          hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr,
          outBuffer);
  v29 = 2147483648;
  *((_QWORD *)v6 + 5) = 0i64;
  classNameRegistry = (hkClassNameRegistry *)v28;
  postFinishObjects.m_data = 0i64;
  v31 = 0;
  postFinishObjects.m_size = 0;
  postFinishObjects.m_capacityAndFlags = 2147483648;
  v32 = 0;
  if ( v7->m_numSections > 0 )
  {
    do
    {
      v33 = hkPackfileHeader::getSectionHeader(v7, v7, v32);
      if ( v33->m_exportsOffset != v33->m_virtualFixupsOffset )
        applyVirtualFixups(
          v33,
          (hkPackfileSectionHeader *)(*(_QWORD *)v5 + ((signed __int64)v32 << 6)),
          v7,
          v6,
          (hkArrayBase<hkPackfileSectionHeader *> *)&array,
          (hkArray<LOCALNAMESPACE::TrackedObjectsArray_Element,hkContainerHeapAllocator> *)(v6 + 8),
          v27,
          classNameRegistry,
          &postFinishObjects);
      ++v32;
    }
    while ( v32 < v7->m_numSections );
    v29 = postFinishObjects.m_capacityAndFlags;
    v31 = postFinishObjects.m_size;
  }
  v34 = 0;
  if ( v31 > 0 )
  {
    v35 = 0i64;
    do
    {
      v36 = postFinishObjects.m_data[v35].m_object;
      v37 = hkClass::getAttribute(postFinishObjects.m_data[v35].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))v37->m_object)(v36);
      ++v34;
      ++v35;
    }
    while ( v34 < postFinishObjects.m_size );
    v29 = postFinishObjects.m_capacityAndFlags;
  }
  v38 = *((signed int *)v6 + 1);
  postFinishObjects.m_size = 0;
  v39 = &v6[v38];
  if ( v29 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * v29);
  v40 = v48;
  v41 = (char *)p;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( p == array )
    v40 = 0;
  v48 = v40;
  v42 = (8 * v51 + 127) & 0xFFFFFF80;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (v42 + 15) & 0xFFFFFFF0;
  if ( v42 > v43->m_slabSize || &v41[v44] != v43->m_cur || v43->m_firstNonLifoEnd == v41 )
    hkLifoAllocator::slowBlockFree(v43, v41, v44);
  else
    v43->m_cur = v41;
  v48 = 0;
  if ( v49 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v49);
  return v39;
}

// File Line: 455
// RVA: 0xE58EC0
char *__fastcall hkNativePackfileUtils::loadInPlace(void *packfileData, int dataSize, hkTypeInfoRegistry *userRegistry, const char **errOut)
{
  __int64 v4; // r15
  hkTypeInfoRegistry *finishRegistry; // r12
  hkPackfileHeader *outBuffer; // rdi
  __int64 v7; // rdx
  char *v8; // r8
  int v10; // eax
  int v11; // ebx
  int v12; // er13
  hkLifoAllocator *v13; // rax
  char *v14; // rcx
  int v15; // ebx
  hkPackfileSectionHeader *v16; // rax
  hkPackfileSectionHeader *v17; // rsi
  int v18; // esi
  hkPackfileSectionHeader *v19; // rbx
  int v20; // er14
  int v21; // ebx
  __int64 v22; // rsi
  hkPackfileSectionHeader *v23; // rcx
  __int64 v24; // rax
  bool v25; // zf
  bool v26; // sf
  int v27; // ecx
  int v28; // er8
  hkClassNameRegistry *classNameRegistry; // r14
  int v30; // esi
  __int64 v31; // rbx
  hkPackfileSectionHeader *v32; // rcx
  int v33; // er14
  __int64 v34; // rsi
  void *v35; // rbx
  hkVariant *v36; // rax
  char *v37; // rsi
  unsigned int v38; // eax
  char *v39; // rdi
  signed int v40; // ebx
  hkLifoAllocator *v41; // rax
  int v42; // er8
  hkArray<hkVariant,hkContainerHeapAllocator> postFinishObjects; // [rsp+50h] [rbp+7h]
  char *array; // [rsp+60h] [rbp+17h]
  unsigned int v45; // [rsp+68h] [rbp+1Fh]
  int v46; // [rsp+6Ch] [rbp+23h]
  void *p; // [rsp+70h] [rbp+27h]
  int v48; // [rsp+78h] [rbp+2Fh]
  hkResult result; // [rsp+C8h] [rbp+7Fh]

  v4 = 0i64;
  finishRegistry = userRegistry;
  outBuffer = (hkPackfileHeader *)packfileData;
  if ( errOut )
    *errOut = 0i64;
  if ( hkNativePackfileUtils::validatePackfileHeader(&result, packfileData, errOut)->m_enum )
    return 0i64;
  v10 = outBuffer->m_flags;
  if ( v10 & 1 )
    return 0i64;
  v11 = outBuffer->m_numSections;
  v12 = -1;
  array = 0i64;
  v45 = 0;
  v46 = 2147483648;
  outBuffer->m_flags = v10 | 1;
  v48 = v11;
  if ( v11 )
  {
    v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v8 = (char *)v13->m_cur;
    v7 = (8 * v11 + 127) & 0xFFFFFF80;
    v14 = &v8[(signed int)v7];
    if ( (signed int)v7 > v13->m_slabSize || v14 > v13->m_end )
    {
      v8 = (char *)hkLifoAllocator::allocateFromNewSlab(v13, v7);
      array = v8;
    }
    else
    {
      v13->m_cur = v14;
      array = v8;
    }
  }
  else
  {
    array = 0i64;
  }
  v46 = v11 | 0x80000000;
  v15 = 0;
  for ( p = array; v15 < outBuffer->m_numSections; ++v45 )
  {
    v16 = hkPackfileHeader::getSectionHeader(outBuffer, outBuffer, v15);
    v7 = v45;
    v17 = v16;
    if ( v45 == (v46 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
      v7 = v45;
    }
    ++v15;
    *(_QWORD *)&array[8 * (signed int)v7] = v17;
  }
  v18 = 0;
  if ( outBuffer->m_numSections > 0 )
  {
    do
    {
      v19 = *(hkPackfileSectionHeader **)&array[v4];
      v20 = v19->m_absoluteDataStart;
      hkString::strCmp(v19->m_sectionTag, "__types__");
      if ( v18 == outBuffer->m_contentsSectionIndex )
        v12 = v20 + outBuffer->m_contentsSectionOffset;
      applyLocalFixups(v19, v19, v20, outBuffer, outBuffer);
      ++v18;
      v4 += 8i64;
    }
    while ( v18 < outBuffer->m_numSections );
    LODWORD(v4) = 0;
  }
  v21 = v4;
  if ( outBuffer->m_numSections > 0 )
  {
    v22 = 0i64;
    do
    {
      v23 = *(hkPackfileSectionHeader **)&array[v22];
      if ( v23->m_virtualFixupsOffset != v23->m_globalFixupsOffset )
        applyGlobalFixups(
          v23,
          *(hkPackfileSectionHeader **)&array[v22],
          outBuffer,
          outBuffer,
          (hkArrayBase<hkPackfileSectionHeader *> *)&array);
      ++v21;
      v22 += 8i64;
    }
    while ( v21 < outBuffer->m_numSections );
  }
  if ( !finishRegistry )
    finishRegistry = (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, __int64, char *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(
                                             hkSingleton<hkBuiltinTypeRegistry>::s_instance,
                                             v7,
                                             v8);
  v24 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *, hkBaseObjectVtbl *, char *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(
          hkSingleton<hkBuiltinTypeRegistry>::s_instance,
          hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr,
          v8);
  v25 = outBuffer->m_numSections == 0;
  v26 = outBuffer->m_numSections < 0;
  v27 = 0;
  v28 = 2147483648;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_size = 0;
  classNameRegistry = (hkClassNameRegistry *)v24;
  v30 = 0;
  postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( !v26 && !v25 )
  {
    v31 = 0i64;
    do
    {
      v32 = *(hkPackfileSectionHeader **)&array[v31];
      if ( v32->m_exportsOffset != v32->m_virtualFixupsOffset )
        applyVirtualFixups(
          v32,
          v32,
          outBuffer,
          outBuffer,
          (hkArrayBase<hkPackfileSectionHeader *> *)&array,
          0i64,
          finishRegistry,
          classNameRegistry,
          &postFinishObjects);
      ++v30;
      v31 += 8i64;
    }
    while ( v30 < outBuffer->m_numSections );
    v28 = postFinishObjects.m_capacityAndFlags;
    v27 = postFinishObjects.m_size;
  }
  v33 = v4;
  if ( v27 > 0 )
  {
    v34 = 0i64;
    do
    {
      v35 = postFinishObjects.m_data[v34].m_object;
      v36 = hkClass::getAttribute(postFinishObjects.m_data[v34].m_class, "hk.PostFinish");
      (*(void (__fastcall **)(void *))v36->m_object)(v35);
      ++v33;
      ++v34;
    }
    while ( v33 < postFinishObjects.m_size );
    v28 = postFinishObjects.m_capacityAndFlags;
  }
  v37 = (char *)outBuffer + v12;
  postFinishObjects.m_size = v4;
  if ( v28 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      postFinishObjects.m_data,
      16 * v28);
  v38 = v45;
  v39 = (char *)p;
  postFinishObjects.m_data = 0i64;
  postFinishObjects.m_capacityAndFlags = 2147483648;
  if ( p == array )
    v38 = v4;
  v45 = v38;
  v40 = (8 * v48 + 127) & 0xFFFFFF80;
  v41 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v42 = (v40 + 15) & 0xFFFFFFF0;
  if ( v40 > v41->m_slabSize || &v39[v42] != v41->m_cur || v41->m_firstNonLifoEnd == v39 )
    hkLifoAllocator::slowBlockFree(v41, v39, v42);
  else
    v41->m_cur = v39;
  v45 = v4;
  if ( v46 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v46);
  return v37;
}

// File Line: 553
// RVA: 0xE59290
const char *__fastcall hkNativePackfileUtils::getContentsClassName(const void *packfileData, int dataSize)
{
  int v2; // er8
  int v3; // eax
  int v4; // edx
  const char *result; // rax

  v2 = dataSize;
  if ( packfileData
    && dataSize >= 64
    && *(_QWORD *)packfileData == 1207175876561657943i64
    && (v3 = *((_DWORD *)packfileData + 5), v3 > 0)
    && dataSize >= (v3 + 1) << 6
    && (v4 = *((_DWORD *)packfileData + 9)
           + *((_DWORD *)packfileData + 16 * (signed __int64)*((signed int *)packfileData + 8) + 21),
        v4 <= v2) )
  {
    result = (char *)packfileData + v4;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 578
// RVA: 0xE59380
void __fastcall hkNativePackfileUtils::unload(void *buffer, int bufferSize)
{
  _QWORD *v2; // rbx
  unsigned __int64 v3; // rdi
  int v4; // er8
  int v5; // er8

  v2 = buffer;
  *(_DWORD *)buffer = 0;
  v3 = *((_QWORD *)buffer + 1);
  if ( v3 < v3 + 16i64 * *((signed int *)buffer + 4) )
  {
    do
    {
      hkTypeInfo::cleanupLoadedObject(*(hkTypeInfo **)v3, (char *)v2 + *(signed int *)(v3 + 8));
      v3 += 16i64;
    }
    while ( v3 < v2[1] + 16i64 * *((signed int *)v2 + 4) );
  }
  v4 = *((_DWORD *)v2 + 9);
  *((_DWORD *)v2 + 8) = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)v2[3],
      v4 << 6);
  v2[3] = 0i64;
  *((_DWORD *)v2 + 9) = 2147483648;
  v5 = *((_DWORD *)v2 + 5);
  *((_DWORD *)v2 + 4) = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)v2[1],
      16 * v5);
  v2[1] = 0i64;
  *((_DWORD *)v2 + 5) = 2147483648;
}

// File Line: 597
// RVA: 0xE59460
void __fastcall hkNativePackfileUtils::unloadInPlace(void *buffer, int bufferSize)
{
  int v2; // ebp
  hkPackfileHeader *v3; // r14
  hkPackfileSectionHeader *v4; // rax
  hkPackfileSectionHeader *v5; // rdi
  int v6; // edx
  int v7; // eax
  int v8; // esi
  unsigned int *v9; // rbx
  __int64 v10; // rdx
  hkTypeInfo *v11; // rcx

  v2 = 0;
  v3 = (hkPackfileHeader *)buffer;
  if ( *((_DWORD *)buffer + 5) > 0 )
  {
    do
    {
      v4 = hkPackfileHeader::getSectionHeader(v3, v3, v2);
      v5 = v4;
      v6 = v4->m_virtualFixupsOffset;
      v7 = v4->m_exportsOffset - v6;
      if ( v7 )
      {
        v8 = 0;
        if ( v7 / 4 > 0 )
        {
          v9 = (unsigned int *)((char *)&v3->m_userTag + v5->m_absoluteDataStart + v6);
          do
          {
            v10 = (signed int)*(v9 - 2);
            if ( (_DWORD)v10 != -1 )
            {
              v11 = (hkTypeInfo *)(*v9 | (unsigned __int64)((signed __int64)(signed int)*(v9 - 1) << 32));
              if ( v11 )
                hkTypeInfo::cleanupLoadedObject(v11, (char *)v3 + v10 + v5->m_absoluteDataStart);
            }
            v8 += 3;
            v9 += 3;
          }
          while ( v8 < (v5->m_exportsOffset - v5->m_virtualFixupsOffset) / 4 );
        }
      }
      ++v2;
    }
    while ( v2 < v3->m_numSections );
  }
}

// File Line: 632
// RVA: 0xE592F0
void __fastcall hkNativePackfileUtils::getImportsExports(const void *loadedBuffer, hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut, hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut)
{
  int v3; // esi
  hkArray<hkResource::Import,hkContainerHeapAllocator> *v4; // r15
  hkArray<hkResource::Export,hkContainerHeapAllocator> *v5; // r12
  _QWORD *v6; // rbp
  __int64 v7; // r14
  hkPackfileSectionHeader *v8; // rdi
  char *v9; // rbx

  v3 = 0;
  v4 = impOut;
  v5 = expOut;
  v6 = loadedBuffer;
  if ( *((_DWORD *)loadedBuffer + 8) > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = (hkPackfileSectionHeader *)(v7 + v6[3]);
      v9 = (char *)v6 + v8->m_absoluteDataStart;
      hkPackfileSectionHeader::getExports(v8, (char *)v6 + v8->m_absoluteDataStart, v5);
      hkPackfileSectionHeader::getImports(v8, v9, v4);
      ++v3;
      v7 += 64i64;
    }
    while ( v3 < *((_DWORD *)v6 + 8) );
  }
}

// File Line: 646
// RVA: 0xE59BC0
void __fastcall getImportsExportsInPlace(const void *loadedBuffer, hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut, hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut)
{
  int v3; // esi
  hkArray<hkResource::Import,hkContainerHeapAllocator> *v4; // r14
  hkArray<hkResource::Export,hkContainerHeapAllocator> *v5; // r15
  _DWORD *v6; // rbp
  hkPackfileSectionHeader *v7; // rbx
  char *v8; // rdi

  v3 = 0;
  v4 = impOut;
  v5 = expOut;
  v6 = loadedBuffer;
  v7 = (hkPackfileSectionHeader *)((char *)loadedBuffer + 64);
  if ( *((_DWORD *)loadedBuffer + 5) > 0 )
  {
    do
    {
      v8 = (char *)v6 + v7->m_absoluteDataStart;
      hkPackfileSectionHeader::getExports(v7, (char *)v6 + v7->m_absoluteDataStart, v5);
      hkPackfileSectionHeader::getImports(v7, v8, v4);
      ++v3;
      ++v7;
    }
    while ( v3 < v6[5] );
  }
}

