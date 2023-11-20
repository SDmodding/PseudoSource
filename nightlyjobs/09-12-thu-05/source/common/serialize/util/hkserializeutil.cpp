// File Line: 59
// RVA: 0xE3AE70
__int64 __fastcall anonymous_namespace_::checkTagfileWorld(hkDataWorld *world, hkSerializeUtil::ErrorDetails *errorOut, hkVersionPatchManager *versionManager, hkClassNameRegistry *classReg)
{
  hkBaseObjectVtbl *v4; // rax
  hkSerializeUtil::ErrorDetails *v5; // r15
  hkClassNameRegistry *v6; // r12
  hkVersionPatchManager *v7; // r14
  int v8; // ebx
  __int64 v9; // rdi
  const char *v10; // rbp
  __int64 v11; // rsi
  hkClass *v12; // rax
  unsigned __int64 v13; // rax
  unsigned int v14; // ebx
  char *v16; // rdx
  char *v17; // [rsp+30h] [rbp-C8h]
  int v18; // [rsp+38h] [rbp-C0h]
  int v19; // [rsp+3Ch] [rbp-BCh]
  hkStringBuf v20; // [rsp+40h] [rbp-B8h]

  v4 = world->vfptr;
  v5 = errorOut;
  v6 = classReg;
  v7 = versionManager;
  v19 = 2147483648;
  v17 = 0i64;
  v18 = 0;
  v4[4].__vecDelDtor((hkBaseObject *)&world->vfptr, (unsigned int)&v17);
  v8 = 0;
  if ( v18 <= 0 )
  {
LABEL_7:
    v14 = 1;
  }
  else
  {
    v9 = 0i64;
    while ( 1 )
    {
      v10 = (const char *)(*(__int64 (**)(void))(**(_QWORD **)&v17[v9] + 16i64))();
      v11 = (*(signed int (**)(void))(**(_QWORD **)&v17[v9] + 24i64))();
      v12 = (hkClass *)v6->vfptr[2].__vecDelDtor((hkBaseObject *)&v6->vfptr, (unsigned int)v10);
      if ( !v12 || (unsigned int)hkClass::getDescribedVersion(v12) != (_DWORD)v11 )
      {
        v13 = hkVersionPatchManager::getUid(v7, v10, v11);
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v7->m_patchIndexFromUid.m_map.m_elem,
                             v13,
                             0xFFFFFFFFFFFFFFFFui64) == -1 )
          break;
      }
      ++v8;
      v9 += 8i64;
      if ( v8 >= v18 )
        goto LABEL_7;
    }
    v20.m_string.m_capacityAndFlags = -2147483520;
    v20.m_string.m_storage[0] = 0;
    v20.m_string.m_data = v20.m_string.m_storage;
    v20.m_string.m_size = 1;
    if ( (_DWORD)v11 )
      hkStringBuf::printf(
        &v20,
        "Unable to version data of class %s, version 0x%p\n%s",
        v10,
        v11,
        "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because you"
        "r assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are registe"
        "red properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output for more details.");
    else
      hkStringBuf::printf(
        &v20,
        "Unable to load class %s, version 0x0\n%s",
        v10,
        "No information about this class exists in the serialization system. This could happen if:\n"
        "* You have provided a custom classes file which does not include this class\n"
        "* You have not specified keycodes before including hkProductFeatures.cxx\n"
        "* Custom classes have not been registered.");
    if ( !v5->id.m_storage )
    {
      v16 = v20.m_string.m_data;
      v5->id.m_storage = 4;
      hkStringPtr::operator=(&v5->defaultMessage, v16);
    }
    v20.m_string.m_size = 0;
    if ( v20.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v20.m_string.m_data,
        v20.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    v14 = 0;
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v17,
      8 * v19);
  return v14;
}

// File Line: 91
// RVA: 0xE3B070
hkResult *__fastcall anonymous_namespace_::loadBinaryTagfileIntoWorld(hkResult *result, hkStreamReader *streamIn, hkDataWorldDict *world, hkSerializeUtil::ErrorDetails *errorOut, hkClassNameRegistry *classReg)
{
  hkResult *v5; // rsi
  hkSerializeUtil::ErrorDetails *v6; // rdi
  hkDataWorldDict *v7; // rbp
  hkStreamReader *v8; // rbx
  hkDataObjectImpl *v9; // rcx
  hkClassNameRegistry *v10; // rcx
  hkClassNameRegistry *v11; // rcx
  bool v12; // zf
  hkResult v14; // [rsp+20h] [rbp-48h]
  hkDataObject resulta; // [rsp+28h] [rbp-40h]
  hkBinaryTagfileReader v16; // [rsp+30h] [rbp-38h]
  hkDefaultClassWrapper v17; // [rsp+40h] [rbp-28h]

  v5 = result;
  v6 = errorOut;
  v7 = world;
  v8 = streamIn;
  hkBinaryTagfileReader::hkBinaryTagfileReader(&v16);
  hkBinaryTagfileReader::load(&v16, &resulta, v8, (hkDataWorld *)&v7->vfptr);
  v9 = resulta.m_impl;
  if ( resulta.m_impl )
  {
    if ( !v6
      || (unsigned int)anonymous_namespace_::checkTagfileWorld(
                         (hkDataWorld *)&v7->vfptr,
                         v6,
                         hkSingleton<hkVersionPatchManager>::s_instance,
                         classReg) )
    {
      hkDefaultClassWrapper::hkDefaultClassWrapper(&v17, classReg);
      hkVersionPatchManager::applyPatches(
        hkSingleton<hkVersionPatchManager>::s_instance,
        &v14,
        (hkDataWorld *)&v7->vfptr,
        (hkVersionPatchManager::ClassWrapper *)&v17.vfptr);
      if ( v14.m_enum )
      {
        if ( v6 && !v6->id.m_storage )
        {
          v6->id.m_storage = 4;
          hkStringPtr::operator=(
            &v6->defaultMessage,
            "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because"
            " your assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are"
            " registered properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output "
            "for more details.");
        }
        v10 = v17.m_nameReg.m_pntr;
        v5->m_enum = 1;
        if ( v10 )
          hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
      }
      else
      {
        v11 = v17.m_nameReg.m_pntr;
        v5->m_enum = 0;
        if ( v11 )
          hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
      }
      v17.m_nameReg.m_pntr = 0i64;
      v17.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    }
    else
    {
      v5->m_enum = 1;
    }
    v9 = resulta.m_impl;
  }
  else
  {
    if ( v6 && v6->id.m_storage == LODWORD(resulta.m_impl) )
    {
      v6->id.m_storage = 4;
      hkStringPtr::operator=(
        &v6->defaultMessage,
        "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because you"
        "r assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are registe"
        "red properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output for more details.");
      v9 = resulta.m_impl;
    }
    v5->m_enum = 1;
  }
  if ( v9 )
  {
    --v9->m_externalCount;
    v12 = v9->m_count-- == 1;
    if ( v12 )
      v9->vfptr->__vecDelDtor((hkDataRefCounted *)&v9->vfptr, 1u);
  }
  return v5;
}

// File Line: 127
// RVA: 0xE3B1F0
hkResult *__fastcall anonymous_namespace_::loadXmlTagfileIntoWorld(hkResult *result, hkStreamReader *streamIn, hkDataWorldDict *world, hkSerializeUtil::ErrorDetails *errorOut, hkClassNameRegistry *classReg)
{
  hkSerializeUtil::ErrorDetails *v5; // rbx
  hkDataWorldDict *v6; // rbp
  hkResult *v7; // rdi
  hkDataObjectImpl *v8; // rcx
  hkClassNameRegistry *v9; // rcx
  hkClassNameRegistry *v10; // rcx
  bool v11; // zf
  hkResult v13; // [rsp+20h] [rbp-48h]
  hkDataObject resulta; // [rsp+28h] [rbp-40h]
  hkXmlTagfileReader v15; // [rsp+30h] [rbp-38h]
  hkDefaultClassWrapper v16; // [rsp+40h] [rbp-28h]

  v5 = errorOut;
  v6 = world;
  v7 = result;
  *(_DWORD *)&v15.m_memSizeAndFlags = 0x1FFFF;
  v15.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileReader::`vftable';
  hkXmlTagfileReader::load(&v15, &resulta, streamIn, (hkDataWorld *)&world->vfptr);
  v8 = resulta.m_impl;
  if ( resulta.m_impl )
  {
    if ( !v5
      || (unsigned int)anonymous_namespace_::checkTagfileWorld(
                         (hkDataWorld *)&v6->vfptr,
                         v5,
                         hkSingleton<hkVersionPatchManager>::s_instance,
                         classReg) )
    {
      hkDefaultClassWrapper::hkDefaultClassWrapper(&v16, classReg);
      if ( hkVersionPatchManager::applyPatches(
             hkSingleton<hkVersionPatchManager>::s_instance,
             &v13,
             (hkDataWorld *)&v6->vfptr,
             (hkVersionPatchManager::ClassWrapper *)&v16.vfptr)->m_enum )
      {
        if ( v5 && !v5->id.m_storage )
        {
          v5->id.m_storage = 4;
          hkStringPtr::operator=(
            &v5->defaultMessage,
            "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because"
            " your assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are"
            " registered properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output "
            "for more details.");
        }
        v9 = v16.m_nameReg.m_pntr;
        v7->m_enum = 1;
        if ( v9 )
          hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
      }
      else
      {
        v10 = v16.m_nameReg.m_pntr;
        v7->m_enum = 0;
        if ( v10 )
          hkReferencedObject::removeReference((hkReferencedObject *)&v10->vfptr);
      }
      v16.m_nameReg.m_pntr = 0i64;
      v16.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    }
    else
    {
      v7->m_enum = 1;
    }
    v8 = resulta.m_impl;
  }
  else
  {
    if ( v5 && v5->id.m_storage == LODWORD(resulta.m_impl) )
    {
      v5->id.m_storage = 4;
      hkStringPtr::operator=(
        &v5->defaultMessage,
        "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because you"
        "r assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are registe"
        "red properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output for more details.");
      v8 = resulta.m_impl;
    }
    v7->m_enum = 1;
  }
  if ( v8 )
  {
    --v8->m_externalCount;
    v11 = v8->m_count-- == 1;
    if ( v11 )
      v8->vfptr->__vecDelDtor((hkDataRefCounted *)&v8->vfptr, 1u);
  }
  return v7;
}

// File Line: 159
// RVA: 0xE3B370
hkResource *__fastcall anonymous_namespace_::loadPackfile(hkStreamReader *streamIn, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut, hkTypeInfoRegistry *typeReg, hkSerializeUtil::LoadOptions *options)
{
  bool v5; // zf
  hkSerializeUtil::ErrorDetails *v6; // rdi
  hkSerializeUtil::FormatDetails *v7; // r14
  hkStreamReader *v8; // r12
  const char *v9; // rax
  int v10; // eax
  int v11; // ecx
  int v12; // er9
  hkBaseObjectVtbl *v13; // rax
  int v14; // ebx
  signed __int64 v15; // rsi
  int v16; // er15
  int v17; // eax
  int v18; // ecx
  int v19; // er9
  int v20; // er13
  int v21; // edx
  unsigned int v22; // ebx
  hkBaseObjectVtbl *v23; // rax
  __int64 v24; // r15
  signed __int64 v25; // r9
  signed __int64 v26; // rdx
  __m128i v27; // xmm4
  unsigned int *v28; // rax
  __m128i v29; // xmm0
  __m128i v30; // xmm2
  __m128i v31; // xmm3
  __m128i v32; // xmm3
  __m128i v33; // xmm4
  int v34; // edx
  int v35; // er8
  _DWORD *v36; // rcx
  unsigned __int64 v37; // rax
  int v38; // edx
  int v39; // ecx
  int v40; // er13
  int v41; // er9
  int v42; // ecx
  hkBaseObjectVtbl *v43; // rax
  hkPackfileHeader *v44; // rbx
  hkClassNameRegistry *v45; // rax
  hkResource *v46; // rax
  __int64 v47; // rbx
  int sizeElem; // [rsp+20h] [rbp-11h]
  hkPackfileHeader *array; // [rsp+28h] [rbp-9h]
  int dataSize; // [rsp+30h] [rbp-1h]
  int v52; // [rsp+34h] [rbp+3h]
  hkIstream v53; // [rsp+38h] [rbp+7h]
  void *retaddr; // [rsp+98h] [rbp+67h]
  hkTypeInfoRegistry *userRegistry; // [rsp+A8h] [rbp+77h]
  hkSerializeUtil::LoadOptions *v56; // [rsp+B0h] [rbp+7Fh]

  v5 = details->m_formatType.m_storage == 2;
  v6 = errorOut;
  v7 = details;
  v8 = streamIn;
  array = 0i64;
  dataSize = 0;
  v52 = 2147483648;
  if ( !v5 )
  {
LABEL_47:
    v46 = (hkResource *)((__int64 (__fastcall *)(hkSerializeDeprecated *, hkStreamReader *, hkSerializeUtil::FormatDetails *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[3].__vecDelDtor)(
                          hkSingleton<hkSerializeDeprecated>::s_instance,
                          v8,
                          v7,
                          v6);
    goto LABEL_48;
  }
  if ( hkString::memCmp(&details->m_layoutRules, &hkStructureLayout::HostLayoutRules, 4) )
  {
    if ( v6 && !v6->id.m_storage )
    {
      v6->id.m_storage = 3;
      hkStringPtr::operator=(&v6->defaultMessage, "Wrong platform for packfile");
    }
LABEL_46:
    v47 = 0i64;
    goto LABEL_49;
  }
  v9 = hkVersionUtil::getCurrentVersion();
  if ( (_QWORD)v7->m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( !v9 )
      goto LABEL_41;
    v10 = hkString::strCmp((const char *)((_QWORD)v7->m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), v9);
  }
  else
  {
    v10 = -(v9 != 0i64);
  }
  if ( v10 || v7->m_formatVersion != hkBinaryPackfileWriter::CURRENT_FILE_VERSION )
  {
LABEL_41:
    if ( dataSize )
    {
      hkIstream::hkIstream(&v53, array, dataSize);
      v47 = ((__int64 (__fastcall *)(hkSerializeDeprecated *, hkStreamReader *, hkSerializeUtil::FormatDetails *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[3].__vecDelDtor)(
              hkSingleton<hkSerializeDeprecated>::s_instance,
              v53.m_streamReader.m_pntr,
              v7,
              v6);
      hkIstream::~hkIstream(&v53);
      goto LABEL_49;
    }
    goto LABEL_47;
  }
  v11 = dataSize;
  v12 = dataSize + 64;
  if ( (v52 & 0x3FFFFFFF) < dataSize + 64 )
  {
    sizeElem = 1;
    if ( v12 < 2 * (v52 & 0x3FFFFFFF) )
      v12 = 2 * (v52 & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v12,
      sizeElem);
    v11 = dataSize;
  }
  v13 = v8->vfptr;
  dataSize = v11 + 64;
  ((void (__fastcall *)(hkStreamReader *, hkPackfileHeader *, signed __int64))v13[2].__vecDelDtor)(v8, array, 64i64);
  v14 = (signed int)array;
  v15 = array->m_numSections;
  v16 = array->m_numSections << 6;
  LODWORD(retaddr) = array->m_numSections << 6;
  v17 = (unsigned __int64)hkPackfileHeader::getSectionHeader(array, array, 0);
  v18 = dataSize;
  v19 = dataSize + v16;
  v20 = v17 - v14;
  v21 = v52 & 0x3FFFFFFF;
  v22 = 0;
  if ( (v52 & 0x3FFFFFFF) < dataSize + v16 )
  {
    sizeElem = 1;
    if ( v19 < 2 * v21 )
      v19 = 2 * v21;
    hkArrayUtil::_reserve(
      (hkResult *)&sizeElem,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v19,
      sizeElem);
    v18 = dataSize;
  }
  v23 = v8->vfptr;
  dataSize = v16 + v18;
  v24 = (__int64)array->m_magic + v20;
  ((void (__fastcall *)(hkStreamReader *, __int64, _QWORD))v23[2].__vecDelDtor)(
    v8,
    (__int64)array->m_magic + v20,
    (unsigned int)retaddr);
  LODWORD(v25) = 0;
  if ( (signed int)v15 > 0 && (unsigned int)v15 >= 4 )
  {
    v26 = 0i64;
    v27 = 0i64;
    v28 = (unsigned int *)(v24 + 172);
    do
    {
      v29 = _mm_cvtsi32_si128(*v28);
      v26 += 4i64;
      LODWORD(v25) = v25 + 4;
      v30 = _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v28 - 16)), _mm_cvtsi32_si128(v28[16]));
      v31 = _mm_cvtsi32_si128(*(v28 - 32));
      v28 += 64;
      v32 = _mm_add_epi32(_mm_unpacklo_epi32(_mm_unpacklo_epi32(v31, v29), v30), v27);
      v27 = v32;
    }
    while ( v26 < (signed int)v15 - (signed int)v15 % 4 );
    v33 = _mm_add_epi32(v32, _mm_srli_si128(v32, 8));
    v22 = _mm_cvtsi128_si32(_mm_add_epi32(v33, _mm_srli_si128(v33, 4)));
  }
  v25 = (signed int)v25;
  v34 = 0;
  v35 = 0;
  if ( (signed int)v25 < v15 )
  {
    if ( v15 - v25 >= 2 )
    {
      v36 = (_DWORD *)((v25 << 6) + v24 + 108);
      v37 = ((unsigned __int64)(v15 - v25 - 2) >> 1) + 1;
      v25 += 2 * v37;
      do
      {
        v34 += *(v36 - 16);
        v35 += *v36;
        v36 += 32;
        --v37;
      }
      while ( v37 );
    }
    if ( v25 < v15 )
      v22 += *(_DWORD *)((v25 << 6) + v24 + 44);
    v22 += v34 + v35;
  }
  v38 = dataSize;
  v39 = v52;
  v40 = (_DWORD)retaddr + v20;
  if ( (v52 & 0x3FFFFFFF) < (signed int)(dataSize + v22) )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      dataSize + v22,
      1);
    v39 = v52;
    v38 = dataSize;
  }
  v41 = v38 + v22;
  v42 = v39 & 0x3FFFFFFF;
  if ( v42 < (signed int)(v38 + v22) )
  {
    sizeElem = 1;
    if ( v41 < 2 * v42 )
      v41 = 2 * v42;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &array,
      v41,
      sizeElem);
    v38 = dataSize;
  }
  v43 = v8->vfptr;
  dataSize = v22 + v38;
  ((void (__fastcall *)(hkStreamReader *, __int64, _QWORD))v43[2].__vecDelDtor)(v8, (__int64)array->m_magic + v40, v22);
  v44 = array;
  v45 = hkSerializeUtil::LoadOptions::getClassNameRegistry(v56);
  if ( !anonymous_namespace_::classSignaturesUpToDate((hkBool *)&retaddr, v44, v45)->m_bool )
  {
    if ( v56->m_storage & 1 )
    {
      if ( v6 && !v6->id.m_storage )
      {
        v6->id.m_storage = 4;
        hkStringPtr::operator=(&v6->defaultMessage, "Class signatures not up to date.");
        v47 = 0i64;
        goto LABEL_49;
      }
      goto LABEL_46;
    }
    goto LABEL_41;
  }
  v46 = hkNativePackfileUtils::load(array, dataSize, userRegistry);
LABEL_48:
  v47 = (__int64)v46;
LABEL_49:
  dataSize = 0;
  if ( v52 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      v52 & 0x3FFFFFFF);
  return (hkResource *)v47;
}

// File Line: 250
// RVA: 0xE3BB20
hkDataObject *__fastcall `anonymous namespace'::ForwardingPackfileListerer::addDataObjectCallback(ForwardingPackfileListerer *this, hkDataObject *result, hkDataObject *object)
{
  hkDataObject *v3; // rsi
  hkDataObject *v4; // rdi
  ForwardingPackfileListerer *v5; // rbp
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  hkDataObjectImpl *v9; // rcx
  hkClass *v10; // r14
  __m128i *v11; // rax
  void *v12; // rbx
  hkClass *v13; // rax
  hkPackfileWriter::AddObjectListener *v14; // rcx
  hkDataObjectImpl *v15; // rax
  __m128i v17; // [rsp+20h] [rbp-28h]
  hkClass *klass; // [rsp+50h] [rbp+8h]
  void *objecta; // [rsp+68h] [rbp+20h]

  v3 = object;
  v4 = result;
  v5 = this;
  if ( !this->m_listener || !object->m_impl )
    goto LABEL_19;
  v6 = ((__int64 (*)(void))object->m_impl->vfptr[2].__vecDelDtor)();
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
  v8 = (__int64)v5->m_classReg->vfptr[2].__vecDelDtor((hkBaseObject *)&v5->m_classReg->vfptr, v7);
  v9 = v3->m_impl;
  v17 = 0ui64;
  v10 = (hkClass *)v8;
  if ( v9 )
  {
    v11 = (__m128i *)v9->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v9->vfptr, (unsigned int)&v17);
  }
  else
  {
    v11 = &v17;
    _mm_store_si128(&v17, v17);
  }
  v12 = (void *)v11->m128i_i64[0];
  v13 = (hkClass *)v11->m128i_i64[1];
  v14 = v5->m_listener;
  objecta = v12;
  if ( v13 )
    v10 = v13;
  klass = v10;
  ((void (__fastcall *)(hkPackfileWriter::AddObjectListener *, void **, hkClass **))v14->vfptr[1].__first_virtual_table_function__)(
    v14,
    &objecta,
    &klass);
  if ( objecta != v12 || klass != v10 )
  {
    if ( !objecta )
    {
      v4->m_impl = 0i64;
      return v4;
    }
    v15 = hkDataWorldNative::wrapObject(v5->m_nativeWorld, objecta, klass);
  }
  else
  {
LABEL_19:
    v15 = v3->m_impl;
  }
  v4->m_impl = v15;
  if ( v15 )
  {
    ++v15->m_externalCount;
    ++v15->m_count;
  }
  return v4;
}

// File Line: 295
// RVA: 0xE3B7E0
hkObjectResource *__fastcall anonymous_namespace_::loadNewPackfileOnHeap(hkStreamReader *streamIn, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut, hkClassNameRegistry *classReg, hkTypeInfoRegistry *typeReg, hkSerializeUtil::LoadOptions *options)
{
  hkClassNameRegistry *v6; // r14
  hkSerializeUtil::ErrorDetails *v7; // r12
  hkTypeInfoRegistry *v8; // r13
  hkObjectResource *v9; // r15
  Dummy *v10; // rsi
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rax
  hkTypeInfoRegistry *v13; // xmm1_8
  hkResource *v14; // rdi
  hkBaseObjectVtbl *v15; // rbx
  __int64 v16; // rax
  hkClass *v17; // rbx
  void *v18; // rax
  hkDataObjectImpl *v19; // rax
  hkObjectResource *v20; // rax
  hkTypeInfoRegistry *v21; // rcx
  bool v22; // zf
  void **v24; // [rsp+30h] [rbp-D0h]
  int v25; // [rsp+38h] [rbp-C8h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> v26; // [rsp+40h] [rbp-C0h]
  int v27; // [rsp+58h] [rbp-A8h]
  int v28; // [rsp+5Ch] [rbp-A4h]
  __int128 v29; // [rsp+60h] [rbp-A0h]
  hkTypeInfoRegistry *v30; // [rsp+70h] [rbp-90h]
  hkDataWorldNative v31; // [rsp+80h] [rbp-80h]
  hkStreamReader *v32; // [rsp+230h] [rbp+130h]
  hkSerializeUtil::FormatDetails *v33; // [rsp+238h] [rbp+138h]

  v33 = details;
  v32 = streamIn;
  v6 = classReg;
  v24 = &hkTypeInfoRegistry::`vftable';
  v7 = errorOut;
  v25 = 0x1FFFF;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v26,
    0);
  v8 = typeReg;
  v9 = 0i64;
  v27 = 0;
  v28 = 1;
  v10 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&typeReg->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
    (hkBool *)&typeReg,
    v10);
  while ( (_BYTE)typeReg )
  {
    v11 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
            v10);
    v12 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(&v8->m_map.m_map, v10);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v26, v12, v11);
    v10 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
            v10);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
      (hkBool *)&typeReg,
      v10);
  }
  v13 = options->m_typeInfoReg;
  v29 = *(_OWORD *)&options->m_storage;
  v30 = v13;
  v14 = anonymous_namespace_::loadPackfile(
          v32,
          v33,
          v7,
          (hkTypeInfoRegistry *)&v24,
          (hkSerializeUtil::LoadOptions *)&v29);
  if ( v14 )
  {
    hkDataWorldNative::hkDataWorldNative(&v31, 0);
    hkDataWorldNative::setClassRegistry(&v31, v6);
    v15 = v6->vfptr;
    v16 = ((__int64 (__fastcall *)(hkResource *))v14->vfptr[3].__first_virtual_table_function__)(v14);
    v17 = (hkClass *)v15[2].__vecDelDtor((hkBaseObject *)&v6->vfptr, v16);
    if ( v17 )
    {
      v18 = (void *)((__int64 (__fastcall *)(hkResource *, _QWORD, hkTypeInfoRegistry *))v14->vfptr[3].__vecDelDtor)(
                      v14,
                      0i64,
                      v8);
      v19 = hkDataWorldNative::wrapObject(&v31, v18, v17);
      typeReg = (hkTypeInfoRegistry *)v19;
      if ( v19 )
      {
        ++v19->m_externalCount;
        ++v19->m_count;
      }
      v20 = hkDataObjectUtil::toObjectWithRegistry((hkDataObject *)&typeReg, v6, v8, 1u);
      v21 = typeReg;
      v9 = v20;
      if ( typeReg )
      {
        --typeReg->m_referenceCount;
        v22 = (*(_DWORD *)(&v21->m_referenceCount + 1))-- == 1;
        if ( v22 )
          v21->vfptr->__vecDelDtor((hkBaseObject *)&v21->vfptr, 1u);
      }
    }
    hkDataWorldNative::~hkDataWorldNative(&v31);
  }
  if ( v14 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v14->vfptr);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v26);
  return v9;
}

// File Line: 319
// RVA: 0xE3AD70
hkBool *__fastcall anonymous_namespace_::classSignaturesUpToDate(hkBool *result, hkPackfileHeader *packfileHeader, hkClassNameRegistry *classReg)
{
  int v3; // ebp
  hkClassNameRegistry *v4; // r12
  hkPackfileHeader *v5; // r14
  hkBool *v6; // rdi
  hkPackfileHeader *v7; // rbx
  int v8; // esi
  int v9; // eax
  int v10; // er15
  char *v11; // rsi
  hkClass *v12; // rax

  v3 = 0;
  v4 = classReg;
  v5 = packfileHeader;
  v6 = result;
  v7 = packfileHeader + 1;
  v8 = 0;
  if ( packfileHeader->m_numSections <= 0 )
  {
LABEL_4:
    v6->m_bool = 0;
  }
  else
  {
    while ( (unsigned int)hkString::strCmp((const char *)v7, hkBinaryPackfileWriter::SECTION_TAG_CLASSNAMES) )
    {
      ++v8;
      ++v7;
      if ( v8 >= v5->m_numSections )
        goto LABEL_4;
    }
    if ( v7->m_contentsSectionIndex - 6 > 0 )
    {
      do
      {
        v9 = v3 + v7->m_numSections;
        v10 = *(int *)((char *)v5->m_magic + v9);
        v11 = (char *)v5 + v9;
        if ( v11[5] == -1 )
          break;
        if ( *((_BYTE *)&v5->m_magic[1] + v9) != 9
          || (v12 = (hkClass *)v4->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->vfptr, (unsigned int)(v11 + 5))) == 0i64
          || v10 != hkClass::getSignature(v12, 0) )
        {
          v6->m_bool = 0;
          return v6;
        }
        v3 += (unsigned __int64)hkString::strLen(v11 + 5) + 6;
      }
      while ( v3 < v7->m_contentsSectionIndex - 6 );
    }
    v6->m_bool = 1;
  }
  return v6;
}

// File Line: 389
// RVA: 0xE39C90
hkClassNameRegistry *__fastcall hkSerializeUtil::LoadOptions::getClassNameRegistry(hkSerializeUtil::LoadOptions *this)
{
  hkClassNameRegistry *result; // rax

  result = this->m_classNameReg;
  if ( !result )
    result = (hkClassNameRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  return result;
}

// File Line: 396
// RVA: 0xE39CB0
hkTypeInfoRegistry *__fastcall hkSerializeUtil::LoadOptions::getTypeInfoRegistry(hkSerializeUtil::LoadOptions *this)
{
  hkTypeInfoRegistry *result; // rax

  result = this->m_typeInfoReg;
  if ( !result )
    result = (hkTypeInfoRegistry *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)();
  return result;
}

// File Line: 407
// RVA: 0xE39CD0
hkResource *__fastcall hkSerializeUtil::load(hkStreamReader *streamIn, hkSerializeUtil::ErrorDetails *errorOut, hkSerializeUtil::LoadOptions *options)
{
  hkSerializeUtil::LoadOptions *v3; // r15
  hkSerializeUtil::ErrorDetails *v4; // rbx
  hkStreamReader *v5; // r14
  hkClassNameRegistry *classReg; // r12
  hkTypeInfoRegistry *v8; // rdi
  hkLifoAllocator *v9; // rax
  char *v10; // rsi
  unsigned __int64 v11; // rcx
  hkMemoryAllocator **v12; // rax
  hkResource *v13; // rdi
  hkDataObject *v14; // rax
  hkResource *v15; // rax
  hkDataObjectImpl *v16; // rcx
  bool v17; // zf
  hkLifoAllocator *v18; // rax
  hkLifoAllocator *v19; // rax
  unsigned __int64 v20; // rcx
  hkMemoryAllocator **v21; // rax
  hkDataObject *v22; // rax
  __int64 v23; // xmm1_8
  hkDataObject v24; // [rsp+30h] [rbp-D0h]
  hkDataObject v25; // [rsp+38h] [rbp-C8h]
  hkSerializeUtil::FormatDetails details; // [rsp+40h] [rbp-C0h]
  __int128 v27; // [rsp+60h] [rbp-A0h]
  __int64 v28; // [rsp+70h] [rbp-90h]
  hkDataWorldDict world; // [rsp+80h] [rbp-80h]
  hkResult result; // [rsp+1D0h] [rbp+D0h]
  hkResult v31; // [rsp+1E8h] [rbp+E8h]

  v3 = options;
  v4 = errorOut;
  v5 = streamIn;
  if ( !streamIn )
  {
    if ( errorOut )
    {
      if ( !errorOut->id.m_storage )
      {
        errorOut->id.m_storage = 1;
        hkStringPtr::operator=(&errorOut->defaultMessage, "Stream pointer is null");
      }
    }
    return 0i64;
  }
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))streamIn->vfptr[1].__first_virtual_table_function__)(
                   streamIn,
                   &result) )
  {
    classReg = hkSerializeUtil::LoadOptions::getClassNameRegistry(v3);
    v8 = hkSerializeUtil::LoadOptions::getTypeInfoRegistry(v3);
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(v5, &details, v4);
    if ( details.m_formatType.m_storage >= 2 )
    {
      if ( details.m_formatType.m_storage <= 3 )
      {
        v23 = (__int64)v3->m_typeInfoReg;
        v27 = *(_OWORD *)&v3->m_storage;
        v28 = v23;
        v13 = anonymous_namespace_::loadPackfile(v5, &details, v4, v8, (hkSerializeUtil::LoadOptions *)&v27);
LABEL_41:
        hkStringPtr::~hkStringPtr(&details.m_version);
        return v13;
      }
      if ( details.m_formatType.m_storage == 4 )
      {
        v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (char *)v19->m_cur;
        v20 = (unsigned __int64)(v10 + 0x4000);
        if ( v19->m_slabSize < 0x4000 || (void *)v20 > v19->m_end )
          v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v19, 0x4000);
        else
          v19->m_cur = (void *)v20;
        v21 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = 0i64;
        hkDataWorldDict::hkDataWorldDict(&world, v21[11]);
        if ( anonymous_namespace_::loadBinaryTagfileIntoWorld(&v31, v5, &world, v4, classReg)->m_enum
          && !(((unsigned int)v3->m_storage >> 1) & 1) )
        {
          goto LABEL_24;
        }
        v22 = hkDataWorldDict::getContents(&world, &v25);
        v15 = hkDataObjectUtil::toResourceWithRegistry(v22, classReg, 1u);
        v16 = v25.m_impl;
        goto LABEL_21;
      }
      if ( details.m_formatType.m_storage == 5 )
      {
        v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v10 = (char *)v9->m_cur;
        v11 = (unsigned __int64)(v10 + 0x4000);
        if ( v9->m_slabSize < 0x4000 || (void *)v11 > v9->m_end )
          v10 = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 0x4000);
        else
          v9->m_cur = (void *)v11;
        v12 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = 0i64;
        hkDataWorldDict::hkDataWorldDict(&world, v12[11]);
        if ( anonymous_namespace_::loadXmlTagfileIntoWorld(&result, v5, &world, v4, classReg)->m_enum
          && !(((unsigned int)v3->m_storage >> 1) & 1) )
        {
          goto LABEL_24;
        }
        v14 = hkDataWorldDict::getContents(&world, &v24);
        v15 = hkDataObjectUtil::toResourceWithRegistry(v14, classReg, 1u);
        v16 = v24.m_impl;
LABEL_21:
        v13 = v15;
        if ( v16 )
        {
          --v16->m_externalCount;
          v17 = v16->m_count-- == 1;
          if ( v17 )
            v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
        }
LABEL_24:
        hkDataWorldDict::~hkDataWorldDict(&world);
        v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v18->m_slabSize < 0x4000 || v10 + 0x4000 != v18->m_cur || v18->m_firstNonLifoEnd == v10 )
          hkLifoAllocator::slowBlockFree(v18, v10, 0x4000);
        else
          v18->m_cur = v10;
        goto LABEL_41;
      }
    }
    if ( v4 && !v4->id.m_storage )
    {
      v4->id.m_storage = 2;
      hkStringPtr::operator=(&v4->defaultMessage, "Unable to detect format from stream");
    }
    v13 = 0i64;
    goto LABEL_41;
  }
  if ( !v4 || v4->id.m_storage )
    return 0i64;
  v4->id.m_storage = 1;
  hkStringPtr::operator=(&v4->defaultMessage, "Stream is not ok");
  return 0i64;
}

// File Line: 485
// RVA: 0xE3A030
hkResource *__fastcall hkSerializeUtil::load(const char *filename, hkSerializeUtil::ErrorDetails *resultOut, hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *v3; // xmm1_8
  hkSerializeUtil::ErrorDetails *v4; // rbx
  __int64 v5; // rax
  hkResource *v6; // rbx
  __int128 v8; // [rsp+20h] [rbp-48h]
  hkTypeInfoRegistry *v9; // [rsp+30h] [rbp-38h]
  hkIstream v10; // [rsp+40h] [rbp-28h]

  v3 = options->m_typeInfoReg;
  v4 = resultOut;
  v8 = *(_OWORD *)&options->m_storage;
  v9 = v3;
  hkIstream::hkIstream(&v10, filename);
  v6 = hkSerializeUtil::load(*(hkStreamReader **)(v5 + 16), v4, (hkSerializeUtil::LoadOptions *)&v8);
  hkIstream::~hkIstream(&v10);
  return v6;
}

// File Line: 492
// RVA: 0xE3A090
hkResource *__fastcall hkSerializeUtil::load(const void *buf, int buflen, hkSerializeUtil::ErrorDetails *resultOut, hkSerializeUtil::LoadOptions *options)
{
  hkPackfileHeader *v4; // rbx
  hkSerializeUtil::ErrorDetails *v5; // rbp
  int v6; // esi
  hkSerializeUtil::LoadOptions *v7; // rdi
  bool v8; // zf
  const char *v9; // rax
  hkClassNameRegistry *v10; // rax
  __int64 v12; // xmm1_8
  __int64 v13; // rax
  hkResource *v14; // rbx
  __int128 v15; // [rsp+20h] [rbp-88h]
  __int64 v16; // [rsp+30h] [rbp-78h]
  hkIstream v17; // [rsp+40h] [rbp-68h]
  int dst; // [rsp+60h] [rbp-48h]
  int v19; // [rsp+64h] [rbp-44h]
  char v20; // [rsp+88h] [rbp-20h]
  __int64 v21; // [rsp+98h] [rbp-10h]
  hkBool result; // [rsp+B0h] [rbp+8h]

  v4 = (hkPackfileHeader *)buf;
  v5 = resultOut;
  v6 = buflen;
  v7 = options;
  hkString::memSet(&dst, -1, 64);
  v8 = v4->m_magic[0] == 1474355287;
  dst = 1474355287;
  v19 = 281067536;
  v21 = 0i64;
  v20 = 0;
  if ( v8 && v4->m_magic[1] == 281067536 && !hkString::memCmp(v4->m_layoutRules, &hkStructureLayout::HostLayoutRules, 4) )
  {
    v9 = hkVersionUtil::getCurrentVersion();
    if ( !(unsigned int)hkString::strCmp(v4->m_contentsVersion, v9) )
    {
      v10 = hkSerializeUtil::LoadOptions::getClassNameRegistry(v7);
      if ( anonymous_namespace_::classSignaturesUpToDate(&result, v4, v10)->m_bool )
        return hkNativePackfileUtils::load(v4, v6, 0i64);
    }
  }
  v12 = (__int64)v7->m_typeInfoReg;
  v15 = *(_OWORD *)&v7->m_storage;
  v16 = v12;
  hkIstream::hkIstream(&v17, v4, v6);
  v14 = hkSerializeUtil::load(*(hkStreamReader **)(v13 + 16), v5, (hkSerializeUtil::LoadOptions *)&v15);
  hkIstream::~hkIstream(&v17);
  return v14;
}

// File Line: 513
// RVA: 0xE3A1C0
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(hkStreamReader *streamIn, hkSerializeUtil::ErrorDetails *errorOut, hkSerializeUtil::LoadOptions *options)
{
  hkSerializeUtil::LoadOptions *v3; // rsi
  hkSerializeUtil::ErrorDetails *v4; // rbx
  hkStreamReader *v5; // rdi
  hkClassNameRegistry *classReg; // r14
  hkTypeInfoRegistry *v8; // r15
  hkObjectResource *v9; // rbx
  hkDataObject *v10; // rax
  hkObjectResource *v11; // rax
  hkDataObjectImpl *v12; // rcx
  bool v13; // zf
  hkDataObject *v14; // rax
  __int64 v15; // xmm1_8
  hkObjectResource *v16; // rax
  hkSerializeUtil::FormatDetails details; // [rsp+30h] [rbp-D0h]
  hkDataObject v18; // [rsp+48h] [rbp-B8h]
  hkDataObject v19; // [rsp+50h] [rbp-B0h]
  __int128 v20; // [rsp+60h] [rbp-A0h]
  __int64 v21; // [rsp+70h] [rbp-90h]
  hkDataWorldDict world; // [rsp+80h] [rbp-80h]
  hkResult result; // [rsp+1D0h] [rbp+D0h]
  hkResult v24; // [rsp+1E8h] [rbp+E8h]

  v3 = options;
  v4 = errorOut;
  v5 = streamIn;
  if ( !streamIn )
  {
    if ( errorOut )
    {
      if ( !errorOut->id.m_storage )
      {
        errorOut->id.m_storage = 1;
        hkStringPtr::operator=(&errorOut->defaultMessage, "Stream pointer is null");
      }
    }
    return 0i64;
  }
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkResult *))streamIn->vfptr[1].__first_virtual_table_function__)(
                   streamIn,
                   &result) )
  {
    classReg = hkSerializeUtil::LoadOptions::getClassNameRegistry(v3);
    v8 = hkSerializeUtil::LoadOptions::getTypeInfoRegistry(v3);
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(v5, &details, v4);
    if ( details.m_formatType.m_storage == 2 )
    {
      if ( details.m_layoutRules.m_bytesInPointer == hkStructureLayout::HostLayoutRules.m_bytesInPointer
        && details.m_layoutRules.m_littleEndian == hkStructureLayout::HostLayoutRules.m_littleEndian
        && details.m_layoutRules.m_reusePaddingOptimization == hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
        && details.m_layoutRules.m_emptyBaseClassOptimization == hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization
        && (_QWORD)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64
        && !(unsigned int)hkString::strCmp(
                            (const char *)((_QWORD)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            "hk_2013.2.0-r1")
        && details.m_formatVersion == hkBinaryPackfileWriter::CURRENT_FILE_VERSION )
      {
        v15 = (__int64)v3->m_typeInfoReg;
        v20 = *(_OWORD *)&v3->m_storage;
        v21 = v15;
        v16 = anonymous_namespace_::loadNewPackfileOnHeap(
                v5,
                &details,
                v4,
                classReg,
                v8,
                (hkSerializeUtil::LoadOptions *)&v20);
LABEL_40:
        v9 = v16;
        goto LABEL_41;
      }
      if ( v3->m_storage & 1 )
      {
        if ( v4 && !v4->id.m_storage )
        {
          v4->id.m_storage = 4;
          hkStringPtr::operator=(
            &v4->defaultMessage,
            "Packfile required versioning but versioning not supported in this context.");
        }
        goto LABEL_38;
      }
    }
    else if ( details.m_formatType.m_storage != 3 )
    {
      if ( details.m_formatType.m_storage == 4 )
      {
        hkDataWorldDict::hkDataWorldDict(&world);
        if ( anonymous_namespace_::loadBinaryTagfileIntoWorld(&v24, v5, &world, v4, classReg)->m_enum == HK_SUCCESS )
        {
          v14 = hkDataWorldDict::getContents(&world, &v19);
          v11 = hkDataObjectUtil::toObjectWithRegistry(v14, classReg, v8, 1u);
          v12 = v19.m_impl;
          goto LABEL_19;
        }
      }
      else
      {
        if ( details.m_formatType.m_storage != 5 )
        {
          if ( v4 && !v4->id.m_storage )
          {
            v4->id.m_storage = 2;
            hkStringPtr::operator=(&v4->defaultMessage, "Unable to detect format from stream");
            v9 = 0i64;
LABEL_41:
            hkStringPtr::~hkStringPtr(&details.m_version);
            return v9;
          }
LABEL_38:
          v9 = 0i64;
          goto LABEL_41;
        }
        hkDataWorldDict::hkDataWorldDict(&world);
        if ( anonymous_namespace_::loadXmlTagfileIntoWorld(&result, v5, &world, v4, classReg)->m_enum == HK_SUCCESS )
        {
          v10 = hkDataWorldDict::getContents(&world, &v18);
          v11 = hkDataObjectUtil::toObjectWithRegistry(v10, classReg, v8, 1u);
          v12 = v18.m_impl;
LABEL_19:
          v9 = v11;
          if ( v12 )
          {
            --v12->m_externalCount;
            v13 = v12->m_count-- == 1;
            if ( v13 )
            {
              v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
              hkDataWorldDict::~hkDataWorldDict(&world);
              goto LABEL_41;
            }
          }
LABEL_23:
          hkDataWorldDict::~hkDataWorldDict(&world);
          goto LABEL_41;
        }
      }
      v9 = 0i64;
      goto LABEL_23;
    }
    v16 = (hkObjectResource *)((__int64 (__fastcall *)(hkSerializeDeprecated *, hkStreamReader *, hkSerializeUtil::FormatDetails *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[3].__first_virtual_table_function__)(
                                hkSingleton<hkSerializeDeprecated>::s_instance,
                                v5,
                                &details,
                                v4);
    goto LABEL_40;
  }
  if ( !v4 || v4->id.m_storage )
    return 0i64;
  v4->id.m_storage = 1;
  hkStringPtr::operator=(&v4->defaultMessage, "Stream is not ok");
  return 0i64;
}

// File Line: 587
// RVA: 0xE3A4D0
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(const char *filename, hkSerializeUtil::ErrorDetails *errorOut, hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *v3; // xmm1_8
  hkSerializeUtil::ErrorDetails *v4; // rbx
  __int64 v5; // rax
  hkObjectResource *v6; // rbx
  __int128 v8; // [rsp+20h] [rbp-48h]
  hkTypeInfoRegistry *v9; // [rsp+30h] [rbp-38h]
  hkIstream v10; // [rsp+40h] [rbp-28h]

  v3 = options->m_typeInfoReg;
  v4 = errorOut;
  v8 = *(_OWORD *)&options->m_storage;
  v9 = v3;
  hkIstream::hkIstream(&v10, filename);
  v6 = hkSerializeUtil::loadOnHeap(*(hkStreamReader **)(v5 + 16), v4, (hkSerializeUtil::LoadOptions *)&v8);
  hkIstream::~hkIstream(&v10);
  return v6;
}

// File Line: 592
// RVA: 0xE3A530
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(const void *buf, int buflen, hkSerializeUtil::ErrorDetails *errorOut, hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *v4; // xmm1_8
  hkSerializeUtil::ErrorDetails *v5; // rbx
  __int64 v6; // rax
  hkObjectResource *v7; // rbx
  __int128 v9; // [rsp+20h] [rbp-48h]
  hkTypeInfoRegistry *v10; // [rsp+30h] [rbp-38h]
  hkIstream v11; // [rsp+40h] [rbp-28h]

  v4 = options->m_typeInfoReg;
  v5 = errorOut;
  v9 = *(_OWORD *)&options->m_storage;
  v10 = v4;
  hkIstream::hkIstream(&v11, buf, buflen);
  v7 = hkSerializeUtil::loadOnHeap(*(hkStreamReader **)(v6 + 16), v5, (hkSerializeUtil::LoadOptions *)&v9);
  hkIstream::~hkIstream(&v11);
  return v7;
}

// File Line: 597
// RVA: 0xE3A590
hkResult *__fastcall hkSerializeUtil::savePackfile(hkResult *result, const void *object, hkClass *klass, hkStreamWriter *writer, hkPackfileWriter::Options *packFileOptions, hkPackfileWriter::AddObjectListener *userListener, hkSerializeUtil::SaveOptions options)
{
  const void *v7; // r14
  hkStreamWriter *v8; // rdi
  hkClass *v9; // rsi
  hkResult *v10; // rbx
  char v11; // cl
  int v12; // eax
  hkPackfileWriter::Options v14; // [rsp+40h] [rbp-C0h]
  int v15; // [rsp+58h] [rbp-A8h]
  hkStringPtr v16; // [rsp+60h] [rbp-A0h]
  hkErrStream v17; // [rsp+68h] [rbp-98h]
  hkBinaryPackfileWriter buf; // [rsp+80h] [rbp-80h]
  int v19; // [rsp+2B8h] [rbp+1B8h]

  v7 = object;
  v8 = writer;
  v9 = klass;
  v10 = result;
  if ( writer )
  {
    *(_QWORD *)&v14.m_userTag = *(_QWORD *)&packFileOptions->m_userTag;
    *(_QWORD *)&v14.m_writeMetaInfo.m_bool = *(_QWORD *)&packFileOptions->m_writeMetaInfo.m_bool;
    v11 = v14.m_writeSerializedFalse.m_bool;
    v14.m_contentsVersion = packFileOptions->m_contentsVersion;
    if ( options.m_storage & 2 )
      v11 = 1;
    v14.m_writeSerializedFalse.m_bool = v11;
    if ( options.m_storage & 1 )
    {
      v15 = 0;
      hkStringPtr::hkStringPtr(&v16);
      ((void (__fastcall *)(hkSerializeDeprecated *, int *, const void *, hkClass *, hkStreamWriter *, hkPackfileWriter::Options *, hkPackfileWriter::AddObjectListener *, int *, _QWORD, _QWORD))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[2].__vecDelDtor)(
        hkSingleton<hkSerializeDeprecated>::s_instance,
        &v19,
        v7,
        v9,
        v8,
        &v14,
        userListener,
        &v15,
        *(_QWORD *)&v14.m_userTag,
        *(_QWORD *)&v14.m_writeMetaInfo.m_bool);
      v12 = v19;
      if ( v19 == 1 )
      {
        hkErrStream::hkErrStream(&v17, &buf, 512);
        hkOstream::operator<<(
          (hkOstream *)&v17.vfptr,
          (const char *)((unsigned __int64)v16.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        hkError::messageWarning(489022799, (const char *)&buf, "Util\\hkSerializeUtil.cpp", 616);
        hkOstream::~hkOstream((hkOstream *)&v17.vfptr);
        v12 = v19;
      }
      v10->m_enum = v12;
      hkStringPtr::~hkStringPtr(&v16);
    }
    else
    {
      hkBinaryPackfileWriter::hkBinaryPackfileWriter(&buf, &v14);
      hkPackfileWriter::setContents((hkPackfileWriter *)&buf.vfptr, v7, v9, userListener);
      hkBinaryPackfileWriter::save(&buf, v10, v8, &v14);
      hkBinaryPackfileWriter::~hkBinaryPackfileWriter(&buf);
    }
  }
  else
  {
    result->m_enum = 1;
  }
  return v10;
}

// File Line: 625
// RVA: 0xE3A730
hkResult *__fastcall hkSerializeUtil::saveTagfile(hkResult *result, const void *object, hkClass *klass, hkStreamWriter *writer, hkPackfileWriter::AddObjectListener *userListener, hkSerializeUtil::SaveOptions options)
{
  void *v6; // rdi
  hkResult *v7; // rsi
  hkStreamWriter *v8; // r14
  hkClass *v9; // rbx
  __int64 v10; // rax
  char v11; // r8
  hkDataObject *v12; // rax
  hkDataObjectImpl *v13; // rcx
  bool v14; // zf
  hkDataObject *v15; // rax
  hkDataObjectImpl *v16; // rcx
  hkXmlTagfileWriter v18; // [rsp+30h] [rbp-D0h]
  hkTagfileWriter::AddDataObjectListener v19; // [rsp+40h] [rbp-C0h]
  hkPackfileWriter::AddObjectListener *v20; // [rsp+50h] [rbp-B0h]
  hkDataWorldNative *v21; // [rsp+58h] [rbp-A8h]
  __int64 v22; // [rsp+60h] [rbp-A0h]
  hkDataWorldNative v23; // [rsp+70h] [rbp-90h]
  hkDataObject resulta; // [rsp+218h] [rbp+118h]

  v6 = (void *)object;
  v7 = result;
  v8 = writer;
  v9 = klass;
  hkDataWorldNative::hkDataWorldNative(&v23, (hkBool)(((unsigned int)options.m_storage >> 1) & 1));
  hkDataWorldNative::setContents(&v23, v6, v9);
  v10 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  *(_DWORD *)&v19.m_memSizeAndFlags = 0x1FFFF;
  v19.vfptr = (hkBaseObjectVtbl *)&`anonymous namespace'::ForwardingPackfileListerer::`vftable';
  v20 = userListener;
  v22 = v10;
  v21 = &v23;
  if ( !v8 )
  {
    v7->m_enum = 1;
    goto LABEL_13;
  }
  v11 = 0;
  BYTE2(userListener) = 0;
  if ( !(options.m_storage & 8) )
    v11 = 1;
  *(_DWORD *)&v18.m_memSizeAndFlags = 0x1FFFF;
  LOBYTE(userListener) = v11;
  BYTE1(userListener) = 1;
  if ( options.m_storage & 1 )
  {
    v18.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileWriter::`vftable';
    v12 = hkDataWorldNative::getContents(&v23, &resulta);
    hkXmlTagfileWriter::save(&v18, v7, v12, v8, &v19, (hkTagfileWriter::Options *)&userListener);
    v13 = resulta.m_impl;
    if ( resulta.m_impl )
    {
      --resulta.m_impl->m_externalCount;
      v14 = v13->m_count-- == 1;
      if ( v14 )
        v13->vfptr->__vecDelDtor((hkDataRefCounted *)&v13->vfptr, 1u);
    }
  }
  else
  {
    v18.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable';
    v15 = hkDataWorldNative::getContents(&v23, &resulta);
    hkBinaryTagfileWriter::save(
      (hkBinaryTagfileWriter *)&v18,
      v7,
      v15,
      v8,
      &v19,
      (hkTagfileWriter::Options *)&userListener);
    v16 = resulta.m_impl;
    if ( resulta.m_impl )
    {
      --resulta.m_impl->m_externalCount;
      v14 = v16->m_count-- == 1;
      if ( v14 )
      {
        v16->vfptr->__vecDelDtor((hkDataRefCounted *)&v16->vfptr, 1u);
        v18.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
        goto LABEL_13;
      }
    }
  }
  v18.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
LABEL_13:
  v19.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  hkDataWorldNative::~hkDataWorldNative(&v23);
  return v7;
}

// File Line: 659
// RVA: 0xE3A920
hkResult *__fastcall hkSerializeUtil::save(hkResult *result, const void *object, hkClass *klass, hkStreamWriter *writer, hkSerializeUtil::SaveOptions options)
{
  hkResult *v5; // rbx

  v5 = result;
  hkSerializeUtil::saveTagfile(result, object, klass, writer, 0i64, options);
  return v5;
}

// File Line: 664
// RVA: 0xE3AC60
signed __int64 __fastcall hkSerializeUtil::isLoadable(hkStreamReader *sr)
{
  hkStreamReader *v1; // rbx
  int v3; // eax
  const char *v4; // rax
  int v5; // eax
  hkSerializeUtil::FormatDetails details; // [rsp+20h] [rbp-28h]
  hkEnum<enum hkTagfileReader::FormatType,int> result; // [rsp+50h] [rbp+8h]

  v1 = sr;
  if ( sr
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkEnum<enum hkTagfileReader::FormatType,int> *))sr->vfptr[1].__first_virtual_table_function__)(
                   sr,
                   &result) )
  {
    if ( hkTagfileReader::detectFormat(&result, v1)->m_storage > 1 )
      return 1i64;
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(v1, &details, 0i64);
    v3 = details.m_formatType.m_storage;
    if ( details.m_formatType.m_storage == 2 )
    {
      if ( !hkString::memCmp(
              &details.m_layoutRules,
              &hkStructureLayout::HostLayoutRules,
              details.m_formatType.m_storage + 2) )
      {
        v4 = hkVersionUtil::getCurrentVersion();
        if ( (_QWORD)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64 )
        {
          if ( !v4 )
            goto LABEL_16;
          v5 = hkString::strCmp((const char *)((_QWORD)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64), v4);
        }
        else
        {
          v5 = -(v4 != 0i64);
        }
        if ( !v5 && details.m_formatVersion == hkBinaryPackfileWriter::CURRENT_FILE_VERSION )
          goto LABEL_17;
LABEL_16:
        if ( ((unsigned int (__fastcall *)(hkSerializeDeprecated *, hkSerializeUtil::FormatDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[2].__first_virtual_table_function__)(
               hkSingleton<hkSerializeDeprecated>::s_instance,
               &details) )
        {
LABEL_17:
          hkStringPtr::~hkStringPtr(&details.m_version);
          return 1i64;
        }
        goto LABEL_18;
      }
      v3 = details.m_formatType.m_storage;
    }
    if ( v3 != 3 )
    {
LABEL_18:
      hkStringPtr::~hkStringPtr(&details.m_version);
      return 0i64;
    }
    goto LABEL_16;
  }
  return 0i64;
}

// File Line: 696
// RVA: 0xE3A950
hkEnum<enum hkSerializeUtil::FormatType,int> *__fastcall hkSerializeUtil::detectFormat(hkEnum<enum hkSerializeUtil::FormatType,int> *result, hkStreamReader *reader, hkSerializeUtil::ErrorDetails *errorOut)
{
  hkEnum<enum hkSerializeUtil::FormatType,int> *v3; // rsi
  hkSerializeUtil::ErrorDetails *v4; // rbx
  hkStreamReader *v5; // rdi
  hkSerializeUtil::FormatDetails details; // [rsp+20h] [rbp-28h]

  v3 = result;
  v4 = errorOut;
  v5 = reader;
  hkStringPtr::hkStringPtr(&details.m_version);
  hkSerializeUtil::detectFormat(v5, &details, v4);
  v3->m_storage = (int)details.m_formatType;
  hkStringPtr::~hkStringPtr(&details.m_version);
  return v3;
}

// File Line: 752
// RVA: 0xE3BD20
hkBool *__fastcall `anonymous namespace'::PeekStreamReader::isOk(PeekStreamReader *this, hkBool *result)
{
  hkBool *v2; // rbx
  hkBool *v3; // rax
  char v4; // [rsp+30h] [rbp+8h]

  v2 = result;
  if ( this->m_curPos >= 0
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))this->m_underlyingStream->vfptr[1].__first_virtual_table_function__)(
                   this->m_underlyingStream,
                   &v4) )
  {
    v2->m_bool = 1;
    v3 = v2;
  }
  else
  {
    v2->m_bool = 0;
    v3 = v2;
  }
  return v3;
}

// File Line: 757
// RVA: 0xE3BDD0
__int64 __fastcall `anonymous namespace'::PeekStreamReader::read(PeekStreamReader *this, void *buf, __int64 nbytes)
{
  PeekStreamReader *v3; // rbx
  __int64 result; // rax

  v3 = this;
  result = ((__int64 (__fastcall *)(PeekStreamReader *, void *, __int64))this->vfptr[3].__vecDelDtor)(this, buf, nbytes);
  v3->m_curPos += result;
  return result;
}

// File Line: 765
// RVA: 0xE3BD60
__int64 __fastcall `anonymous namespace'::PeekStreamReader::peek(PeekStreamReader *this, void *buf, int nbytes)
{
  int v3; // ebx
  void *v4; // rsi
  PeekStreamReader *v5; // rdi
  __int64 v6; // rax

  v3 = nbytes;
  v4 = buf;
  v5 = this;
  if ( nbytes + this->m_curPos >= this->m_peekBuffer.m_size )
    `anonymous namespace'::PeekStreamReader::expandPeekBuffer(this, nbytes);
  v6 = v5->m_curPos;
  if ( v5->m_peekBuffer.m_size - (signed int)v6 < v3 )
    v3 = v5->m_peekBuffer.m_size - v6;
  if ( v3 )
    hkString::memCpy(v4, &v5->m_peekBuffer.m_data[v6], v3);
  return (unsigned int)v3;
}

// File Line: 788
// RVA: 0xE3BC40
void __fastcall `anonymous namespace'::PeekStreamReader::expandPeekBuffer(PeekStreamReader *this, const int nbytes)
{
  PeekStreamReader *v2; // rsi
  int v3; // edx
  signed int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // er9
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // ecx
  int v12; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = this->m_peekBuffer.m_size + nbytes + 1;
  v4 = (signed int)((double)this->m_peekBuffer.m_size * 1.5);
  if ( v3 > v4 )
    v4 = v3;
  v5 = this->m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v6 = 2 * v5;
    v7 = v4;
    if ( v4 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &this->m_peekBuffer,
      v7,
      1);
  }
  v2->m_peekBuffer.m_size = v4;
  v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v2->m_underlyingStream->vfptr[3].__vecDelDtor)(
         v2->m_underlyingStream,
         v2->m_peekBuffer.m_data,
         (unsigned int)v4);
  v9 = v2->m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v8;
  if ( v9 >= v8 )
  {
    v2->m_peekBuffer.m_size = v8;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v8;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v2->m_peekBuffer,
      v12,
      1);
    v2->m_peekBuffer.m_size = v10;
  }
}

// File Line: 803
// RVA: 0xE3A9B0
void __fastcall hkSerializeUtil::detectFormat(const char *fileName, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut)
{
  hkSerializeUtil::FormatDetails *v3; // rdi
  hkSerializeUtil::ErrorDetails *v4; // rbx
  __int64 v5; // rax
  hkIstream v6; // [rsp+20h] [rbp-28h]

  v3 = details;
  v4 = errorOut;
  hkIstream::hkIstream(&v6, fileName);
  hkSerializeUtil::detectFormat(*(hkStreamReader **)(v5 + 16), v3, v4);
  hkIstream::~hkIstream(&v6);
}

// File Line: 808
// RVA: 0xE3AA00
void __fastcall hkSerializeUtil::detectFormat(hkStreamReader *reader, hkSerializeUtil::FormatDetails *details, hkSerializeUtil::ErrorDetails *errorOut)
{
  hkSerializeUtil::FormatDetails *v3; // rdi
  hkStreamReader *v4; // rbx
  hkSerializeUtil::ErrorDetails *v5; // r15
  PeekStreamReader v6; // [rsp+30h] [rbp-D0h]
  hkXmlTagfileReader v7; // [rsp+60h] [rbp-A0h]
  int v8; // [rsp+70h] [rbp-90h]
  hkStringPtr v9; // [rsp+78h] [rbp-88h]
  hkStringPtr v10; // [rsp+80h] [rbp-80h]
  hkXmlTagfile::Header v11; // [rsp+88h] [rbp-78h]
  hkBinaryTagfileReader v12; // [rsp+98h] [rbp-68h]
  int dst; // [rsp+B0h] [rbp-50h]
  int v14; // [rsp+B4h] [rbp-4Ch]
  int v15; // [rsp+BCh] [rbp-44h]
  char src; // [rsp+C0h] [rbp-40h]
  char string; // [rsp+D8h] [rbp-28h]
  __int64 v18; // [rsp+E8h] [rbp-18h]
  hkBinaryTagfile::Header out; // [rsp+F0h] [rbp-10h]
  hkResult result; // [rsp+140h] [rbp+40h]

  v3 = details;
  v4 = reader;
  *(_QWORD *)&details->m_formatType.m_storage = 0i64;
  v5 = errorOut;
  hkStringPtr::operator=(&details->m_version, 0i64);
  hkMemUtil::memSet(&v3->m_layoutRules, 0, 4);
  v6.vfptr = (hkBaseObjectVtbl *)&`anonymous namespace'::PeekStreamReader::`vftable';
  *(_DWORD *)&v6.m_memSizeAndFlags = 0x1FFFF;
  v6.m_underlyingStream = v4;
  v6.m_peekBuffer.m_data = 0i64;
  v6.m_peekBuffer.m_size = 0;
  v6.m_peekBuffer.m_capacityAndFlags = 2147483648;
  v6.m_curPos = 0;
  `anonymous namespace'::PeekStreamReader::expandPeekBuffer(&v6, 512);
  hkBinaryTagfileReader::hkBinaryTagfileReader(&v12);
  hkStringPtr::hkStringPtr(&out.m_sdk);
  if ( hkBinaryTagfileReader::readHeader(&v12, &result, (hkStreamReader *)&v6.vfptr, &out)->m_enum )
  {
    v6.m_curPos = 0;
    hkString::memSet(&dst, -1, 64);
    dst = 1474355287;
    v14 = 281067536;
    string = 0;
    v18 = 0i64;
    if ( hkPackfileHeader::readHeader(&result, (hkStreamReader *)&v6.vfptr, (hkPackfileHeader *)&dst)->m_enum )
    {
      v6.m_curPos = 0;
      v7.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileReader::`vftable';
      *(_DWORD *)&v7.m_memSizeAndFlags = 0x1FFFF;
      hkStringPtr::hkStringPtr(&v11.m_sdkVersion);
      if ( hkXmlTagfileReader::readHeader(&v7, &result, (hkStreamReader *)&v6.vfptr, &v11)->m_enum )
      {
        v6.m_curPos = 0;
        hkStringPtr::hkStringPtr(&v9);
        hkStringPtr::hkStringPtr(&v10);
        if ( !*(_DWORD *)((__int64 (__fastcall *)(hkSerializeDeprecated *, hkResult *, PeekStreamReader *, int *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[4].__vecDelDtor)(
                           hkSingleton<hkSerializeDeprecated>::s_instance,
                           &result,
                           &v6,
                           &v8,
                           v5) )
        {
          v3->m_formatType.m_storage = 3;
          hkStringPtr::operator=(&v3->m_version, &v9);
          v3->m_formatVersion = v8;
        }
        hkStringPtr::~hkStringPtr(&v10);
        hkStringPtr::~hkStringPtr(&v9);
      }
      else
      {
        v3->m_formatType.m_storage = 5;
      }
      hkStringPtr::~hkStringPtr(&v11.m_sdkVersion);
      v7.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
    }
    else
    {
      v3->m_formatType.m_storage = 2;
      hkStringPtr::operator=(&v3->m_version, &string);
      v3->m_formatVersion = v15;
      hkMemUtil::memCpy(&v3->m_layoutRules, &src, 4);
    }
  }
  else
  {
    v3->m_formatType.m_storage = 4;
  }
  hkStringPtr::~hkStringPtr(&out.m_sdk);
  v12.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  v6.m_peekBuffer.m_size = 0;
  if ( v6.m_peekBuffer.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v6.m_peekBuffer.m_data,
      v6.m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF);
}

