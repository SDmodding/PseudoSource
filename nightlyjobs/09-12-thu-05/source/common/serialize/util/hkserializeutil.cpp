// File Line: 59
// RVA: 0xE3AE70
__int64 __fastcall anonymous_namespace_::checkTagfileWorld(
        hkDataWorld *world,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkVersionPatchManager *versionManager,
        hkClassNameRegistry *classReg)
{
  hkBaseObjectVtbl *vfptr; // rax
  int v8; // ebx
  __int64 v9; // rdi
  const char *v10; // rbp
  const void *v11; // rsi
  hkClass *v12; // rax
  unsigned __int64 Uid; // rax
  unsigned int v14; // ebx
  char *m_data; // rdx
  char *v17; // [rsp+30h] [rbp-C8h] BYREF
  int v18; // [rsp+38h] [rbp-C0h]
  int v19; // [rsp+3Ch] [rbp-BCh]
  hkStringBuf v20; // [rsp+40h] [rbp-B8h] BYREF

  vfptr = world->vfptr;
  v19 = 0x80000000;
  v17 = 0i64;
  v18 = 0;
  vfptr[4].__vecDelDtor(world, (unsigned int)&v17);
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
      v10 = (const char *)(*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)&v17[v9] + 16i64))(*(_QWORD *)&v17[v9]);
      v11 = (const void *)(*(int (__fastcall **)(_QWORD))(**(_QWORD **)&v17[v9] + 24i64))(*(_QWORD *)&v17[v9]);
      v12 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, v10);
      if ( !v12 || (unsigned int)hkClass::getDescribedVersion(v12) != (_DWORD)v11 )
      {
        Uid = hkVersionPatchManager::getUid(versionManager, v10, (int)v11);
        if ( (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                             &versionManager->m_patchIndexFromUid.m_map,
                             Uid,
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
    if ( !errorOut->id.m_storage )
    {
      m_data = v20.m_string.m_data;
      errorOut->id.m_storage = 4;
      hkStringPtr::operator=(&errorOut->defaultMessage, m_data);
    }
    v20.m_string.m_size = 0;
    if ( v20.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        v20.m_string.m_data,
        v20.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    v14 = 0;
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v17, 8 * v19);
  return v14;
}

// File Line: 91
// RVA: 0xE3B070
hkResult *__fastcall anonymous_namespace_::loadBinaryTagfileIntoWorld(
        hkResult *result,
        hkStreamReader *streamIn,
        hkDataWorldDict *world,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkClassNameRegistry *classReg)
{
  hkDataObjectImpl *m_impl; // rcx
  hkClassNameRegistry *m_pntr; // rcx
  hkClassNameRegistry *v11; // rcx
  hkResult v14; // [rsp+20h] [rbp-48h] BYREF
  hkDataObject resulta; // [rsp+28h] [rbp-40h] BYREF
  hkBinaryTagfileReader v16; // [rsp+30h] [rbp-38h] BYREF
  hkDefaultClassWrapper v17; // [rsp+40h] [rbp-28h] BYREF

  hkBinaryTagfileReader::hkBinaryTagfileReader(&v16);
  hkBinaryTagfileReader::load(&v16, &resulta, streamIn, world);
  m_impl = resulta.m_impl;
  if ( resulta.m_impl )
  {
    if ( !errorOut
      || (unsigned int)anonymous_namespace_::checkTagfileWorld(
                         world,
                         errorOut,
                         hkSingleton<hkVersionPatchManager>::s_instance,
                         classReg) )
    {
      hkDefaultClassWrapper::hkDefaultClassWrapper(&v17, classReg);
      hkVersionPatchManager::applyPatches(hkSingleton<hkVersionPatchManager>::s_instance, &v14, world, &v17);
      if ( v14.m_enum )
      {
        if ( errorOut && !errorOut->id.m_storage )
        {
          errorOut->id.m_storage = 4;
          hkStringPtr::operator=(
            &errorOut->defaultMessage,
            "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because"
            " your assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are"
            " registered properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output "
            "for more details.");
        }
        m_pntr = v17.m_nameReg.m_pntr;
        result->m_enum = HK_FAILURE;
        if ( m_pntr )
          hkReferencedObject::removeReference(m_pntr);
      }
      else
      {
        v11 = v17.m_nameReg.m_pntr;
        result->m_enum = HK_SUCCESS;
        if ( v11 )
          hkReferencedObject::removeReference(v11);
      }
      v17.m_nameReg.m_pntr = 0i64;
      v17.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    else
    {
      result->m_enum = HK_FAILURE;
    }
    m_impl = resulta.m_impl;
  }
  else
  {
    if ( errorOut && errorOut->id.m_storage == LODWORD(resulta.m_impl) )
    {
      errorOut->id.m_storage = 4;
      hkStringPtr::operator=(
        &errorOut->defaultMessage,
        "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because you"
        "r assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are registe"
        "red properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output for more details.");
      m_impl = resulta.m_impl;
    }
    result->m_enum = HK_FAILURE;
  }
  if ( m_impl )
  {
    --m_impl->m_externalCount;
    if ( m_impl->m_count-- == 1 )
      m_impl->vfptr->__vecDelDtor(m_impl, 1u);
  }
  return result;
}

// File Line: 127
// RVA: 0xE3B1F0
hkResult *__fastcall anonymous_namespace_::loadXmlTagfileIntoWorld(
        hkResult *result,
        hkStreamReader *streamIn,
        hkDataWorldDict *world,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkClassNameRegistry *classReg)
{
  hkDataObjectImpl *m_impl; // rcx
  hkClassNameRegistry *m_pntr; // rcx
  hkClassNameRegistry *v10; // rcx
  hkResult v13; // [rsp+20h] [rbp-48h] BYREF
  hkDataObject resulta; // [rsp+28h] [rbp-40h] BYREF
  hkXmlTagfileReader v15; // [rsp+30h] [rbp-38h] BYREF
  hkDefaultClassWrapper v16; // [rsp+40h] [rbp-28h] BYREF

  *(_DWORD *)&v15.m_memSizeAndFlags = 0x1FFFF;
  v15.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileReader::`vftable;
  hkXmlTagfileReader::load(&v15, &resulta, streamIn, world);
  m_impl = resulta.m_impl;
  if ( resulta.m_impl )
  {
    if ( !errorOut
      || (unsigned int)anonymous_namespace_::checkTagfileWorld(
                         world,
                         errorOut,
                         hkSingleton<hkVersionPatchManager>::s_instance,
                         classReg) )
    {
      hkDefaultClassWrapper::hkDefaultClassWrapper(&v16, classReg);
      if ( hkVersionPatchManager::applyPatches(hkSingleton<hkVersionPatchManager>::s_instance, &v13, world, &v16)->m_enum )
      {
        if ( errorOut && !errorOut->id.m_storage )
        {
          errorOut->id.m_storage = 4;
          hkStringPtr::operator=(
            &errorOut->defaultMessage,
            "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because"
            " your assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are"
            " registered properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output "
            "for more details.");
        }
        m_pntr = v16.m_nameReg.m_pntr;
        result->m_enum = HK_FAILURE;
        if ( m_pntr )
          hkReferencedObject::removeReference(m_pntr);
      }
      else
      {
        v10 = v16.m_nameReg.m_pntr;
        result->m_enum = HK_SUCCESS;
        if ( v10 )
          hkReferencedObject::removeReference(v10);
      }
      v16.m_nameReg.m_pntr = 0i64;
      v16.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    else
    {
      result->m_enum = HK_FAILURE;
    }
    m_impl = resulta.m_impl;
  }
  else
  {
    if ( errorOut && errorOut->id.m_storage == LODWORD(resulta.m_impl) )
    {
      errorOut->id.m_storage = 4;
      hkStringPtr::operator=(
        &errorOut->defaultMessage,
        "Patching to latest version failed. Have you registered the necessary patches? Patches may be missing because you"
        "r assets are older than HK_SERIALIZE_MIN_COMPATIBLE_VERSION (if defined). Make sure that the patches are registe"
        "red properly (see hkRegisterPatches.cxx, included by hkProductFeatures.cxx). See the hkError output for more details.");
      m_impl = resulta.m_impl;
    }
    result->m_enum = HK_FAILURE;
  }
  if ( m_impl )
  {
    --m_impl->m_externalCount;
    if ( m_impl->m_count-- == 1 )
      m_impl->vfptr->__vecDelDtor(m_impl, 1u);
  }
  return result;
}

// File Line: 159
// RVA: 0xE3B370
hkResource *__fastcall anonymous_namespace_::loadPackfile(
        hkStreamReader *streamIn,
        hkSerializeUtil::FormatDetails *details,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkTypeInfoRegistry *typeReg,
        hkSerializeUtil::LoadOptions *options)
{
  bool v5; // zf
  const char *CurrentVersion; // rax
  int v10; // eax
  int v11; // ecx
  int v12; // r9d
  hkBaseObjectVtbl *vfptr; // rax
  int v14; // ebx
  __int64 m_numSections; // rsi
  int v16; // r15d
  unsigned int SectionHeader; // eax
  int v18; // ecx
  int v19; // r9d
  int v20; // r13d
  int v21; // edx
  unsigned int v22; // ebx
  hkBaseObjectVtbl *v23; // rax
  char *v24; // r15
  __int64 v25; // r9
  __int64 v26; // rdx
  __m128i v27; // xmm4
  unsigned int *v28; // rax
  __m128i v29; // xmm0
  __m128i v30; // xmm2
  __m128i v31; // xmm3
  __m128i v32; // xmm3
  __m128i v33; // xmm4
  int v34; // edx
  int v35; // r8d
  char *v36; // rcx
  unsigned __int64 v37; // rax
  int v38; // edx
  int v39; // ecx
  int v40; // r13d
  int v41; // r9d
  int v42; // ecx
  hkBaseObjectVtbl *v43; // rax
  hkPackfileHeader *v44; // rbx
  hkClassNameRegistry *ClassNameRegistry; // rax
  hkResource *v46; // rax
  __int64 v47; // rbx
  int sizeElem; // [rsp+20h] [rbp-11h] BYREF
  hkPackfileHeader *array; // [rsp+28h] [rbp-9h] BYREF
  int dataSize; // [rsp+30h] [rbp-1h]
  int v52; // [rsp+34h] [rbp+3h]
  hkIstream v53; // [rsp+38h] [rbp+7h] BYREF
  void *retaddr; // [rsp+98h] [rbp+67h] BYREF
  hkTypeInfoRegistry *userRegistry; // [rsp+A8h] [rbp+77h]
  hkSerializeUtil::LoadOptions *v56; // [rsp+B0h] [rbp+7Fh]

  v5 = details->m_formatType.m_storage == 2;
  array = 0i64;
  dataSize = 0;
  v52 = 0x80000000;
  if ( !v5 )
  {
LABEL_46:
    v46 = (hkResource *)((__int64 (__fastcall *)(hkSerializeDeprecated *, hkStreamReader *, hkSerializeUtil::FormatDetails *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[3].__vecDelDtor)(
                          hkSingleton<hkSerializeDeprecated>::s_instance,
                          streamIn,
                          details,
                          errorOut);
    goto LABEL_47;
  }
  if ( hkString::memCmp(&details->m_layoutRules, &hkStructureLayout::HostLayoutRules, 4u) )
  {
    if ( errorOut && !errorOut->id.m_storage )
    {
      errorOut->id.m_storage = 3;
      hkStringPtr::operator=(&errorOut->defaultMessage, "Wrong platform for packfile");
    }
LABEL_45:
    v47 = 0i64;
    goto LABEL_48;
  }
  CurrentVersion = hkVersionUtil::getCurrentVersion();
  if ( ((unsigned __int64)details->m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( !CurrentVersion )
      goto LABEL_40;
    v10 = hkString::strCmp(
            (const char *)((unsigned __int64)details->m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
            CurrentVersion);
  }
  else
  {
    v10 = -(CurrentVersion != 0i64);
  }
  if ( v10 || details->m_formatVersion != hkBinaryPackfileWriter::CURRENT_FILE_VERSION )
  {
LABEL_40:
    if ( dataSize )
    {
      hkIstream::hkIstream(&v53, array, dataSize);
      v47 = ((__int64 (__fastcall *)(hkSerializeDeprecated *, hkStreamReader *, hkSerializeUtil::FormatDetails *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[3].__vecDelDtor)(
              hkSingleton<hkSerializeDeprecated>::s_instance,
              v53.m_streamReader.m_pntr,
              details,
              errorOut);
      hkIstream::~hkIstream(&v53);
      goto LABEL_48;
    }
    goto LABEL_46;
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
      &hkContainerTempAllocator::s_alloc,
      (const void **)&array,
      v12,
      sizeElem);
    v11 = dataSize;
  }
  vfptr = streamIn->vfptr;
  dataSize = v11 + 64;
  ((void (__fastcall *)(hkStreamReader *, hkPackfileHeader *, __int64))vfptr[2].__vecDelDtor)(streamIn, array, 64i64);
  v14 = (int)array;
  m_numSections = array->m_numSections;
  v16 = array->m_numSections << 6;
  LODWORD(retaddr) = v16;
  SectionHeader = (unsigned int)hkPackfileHeader::getSectionHeader(array, array, 0);
  v18 = dataSize;
  v19 = dataSize + v16;
  v20 = SectionHeader - v14;
  v21 = v52 & 0x3FFFFFFF;
  v22 = 0;
  if ( (v52 & 0x3FFFFFFF) < dataSize + v16 )
  {
    sizeElem = 1;
    if ( v19 < 2 * v21 )
      v19 = 2 * v21;
    hkArrayUtil::_reserve(
      (hkResult *)&sizeElem,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&array,
      v19,
      sizeElem);
    v18 = dataSize;
  }
  v23 = streamIn->vfptr;
  dataSize = v16 + v18;
  v24 = (char *)array + v20;
  ((void (__fastcall *)(hkStreamReader *, char *, _QWORD))v23[2].__vecDelDtor)(streamIn, v24, (unsigned int)retaddr);
  LODWORD(v25) = 0;
  if ( (int)m_numSections >= 4 )
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
    while ( v26 < (int)(m_numSections - (m_numSections & 0x80000003)) );
    v33 = _mm_add_epi32(v32, _mm_srli_si128(v32, 8));
    v22 = _mm_cvtsi128_si32(_mm_add_epi32(v33, _mm_srli_si128(v33, 4)));
  }
  v25 = (int)v25;
  v34 = 0;
  v35 = 0;
  if ( (int)v25 < m_numSections )
  {
    if ( m_numSections - (int)v25 >= 2 )
    {
      v36 = &v24[64 * (__int64)(int)v25 + 108];
      v37 = ((unsigned __int64)(m_numSections - (int)v25 - 2) >> 1) + 1;
      v25 = (int)v25 + 2 * v37;
      do
      {
        v34 += *((_DWORD *)v36 - 16);
        v35 += *(_DWORD *)v36;
        v36 += 128;
        --v37;
      }
      while ( v37 );
    }
    if ( v25 < m_numSections )
      v22 += *(_DWORD *)&v24[64 * v25 + 44];
    v22 += v34 + v35;
  }
  v38 = dataSize;
  v39 = v52;
  v40 = (_DWORD)retaddr + v20;
  if ( (v52 & 0x3FFFFFFF) < (int)(dataSize + v22) )
  {
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&array,
      dataSize + v22,
      1);
    v39 = v52;
    v38 = dataSize;
  }
  v41 = v38 + v22;
  v42 = v39 & 0x3FFFFFFF;
  if ( v42 < (int)(v38 + v22) )
  {
    sizeElem = 1;
    if ( v41 < 2 * v42 )
      v41 = 2 * v42;
    hkArrayUtil::_reserve(
      (hkResult *)&retaddr,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&array,
      v41,
      sizeElem);
    v38 = dataSize;
  }
  v43 = streamIn->vfptr;
  dataSize = v22 + v38;
  ((void (__fastcall *)(hkStreamReader *, char *, _QWORD))v43[2].__vecDelDtor)(streamIn, (char *)array + v40, v22);
  v44 = array;
  ClassNameRegistry = hkSerializeUtil::LoadOptions::getClassNameRegistry(v56);
  if ( !anonymous_namespace_::classSignaturesUpToDate((hkBool *)&retaddr, v44, ClassNameRegistry)->m_bool )
  {
    if ( (v56->m_storage & 1) != 0 )
    {
      if ( errorOut && !errorOut->id.m_storage )
      {
        errorOut->id.m_storage = 4;
        hkStringPtr::operator=(&errorOut->defaultMessage, "Class signatures not up to date.");
        v47 = 0i64;
        goto LABEL_48;
      }
      goto LABEL_45;
    }
    goto LABEL_40;
  }
  v46 = hkNativePackfileUtils::load(array, dataSize, userRegistry);
LABEL_47:
  v47 = (__int64)v46;
LABEL_48:
  dataSize = 0;
  if ( v52 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v52 & 0x3FFFFFFF);
  return (hkResource *)v47;
}

// File Line: 250
// RVA: 0xE3BB20
hkDataObject *__fastcall `anonymous namespace::ForwardingPackfileListerer::addDataObjectCallback(
        ForwardingPackfileListerer *this,
        hkDataObject *result,
        hkDataObject *object)
{
  __int64 v6; // rax
  __int64 v7; // rax
  hkClass *v8; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkClass *v10; // r14
  __int128 *v11; // rax
  void *v12; // rbx
  hkClass *v13; // rax
  hkPackfileWriter::AddObjectListener *m_listener; // rcx
  hkDataObjectImpl *v15; // rax
  __int128 v17[2]; // [rsp+20h] [rbp-28h] BYREF
  hkClass *klass; // [rsp+50h] [rbp+8h] BYREF
  void *objecta; // [rsp+68h] [rbp+20h] BYREF

  if ( !this->m_listener || !object->m_impl )
    goto LABEL_13;
  v6 = ((__int64 (*)(void))object->m_impl->vfptr[2].__vecDelDtor)();
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
  v8 = (hkClass *)this->m_classReg->vfptr[2].__vecDelDtor(this->m_classReg, v7);
  m_impl = object->m_impl;
  v17[0] = 0ui64;
  v10 = v8;
  if ( m_impl )
    v11 = (__int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)v17);
  else
    v11 = v17;
  v12 = *(void **)v11;
  v13 = (hkClass *)*((_QWORD *)v11 + 1);
  m_listener = this->m_listener;
  objecta = v12;
  if ( v13 )
    v10 = v13;
  klass = v10;
  ((void (__fastcall *)(hkPackfileWriter::AddObjectListener *, void **, hkClass **))m_listener->vfptr[1].__first_virtual_table_function__)(
    m_listener,
    &objecta,
    &klass);
  if ( objecta == v12 && klass == v10 )
  {
LABEL_13:
    v15 = object->m_impl;
  }
  else
  {
    if ( !objecta )
    {
      result->m_impl = 0i64;
      return result;
    }
    v15 = hkDataWorldNative::wrapObject(this->m_nativeWorld, objecta, klass);
  }
  result->m_impl = v15;
  if ( v15 )
  {
    ++v15->m_externalCount;
    ++v15->m_count;
  }
  return result;
}

// File Line: 295
// RVA: 0xE3B7E0
hkObjectResource *__fastcall anonymous_namespace_::loadNewPackfileOnHeap(
        hkStreamReader *streamIn,
        hkSerializeUtil::FormatDetails *details,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkClassNameRegistry *classReg,
        hkTypeInfoRegistry *typeReg,
        hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *v8; // r13
  hkObjectResource *v9; // r15
  Dummy *Iterator; // rsi
  unsigned __int64 Value; // rbx
  const char *Key; // rax
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  hkResource *v14; // rdi
  hkBaseObjectVtbl *vfptr; // rbx
  __int64 v16; // rax
  hkClass *v17; // rbx
  void *v18; // rax
  hkDataObjectImpl *v19; // rax
  hkObjectResource *v20; // rax
  hkTypeInfoRegistry *v21; // rcx
  hkTypeInfoRegistry v24; // [rsp+30h] [rbp-D0h] BYREF
  hkSerializeUtil::LoadOptions v25; // [rsp+60h] [rbp-A0h] BYREF
  hkDataWorldNative v26; // [rsp+80h] [rbp-80h] BYREF

  v24.vfptr = (hkBaseObjectVtbl *)&hkTypeInfoRegistry::`vftable;
  *(_DWORD *)&v24.m_memSizeAndFlags = 0x1FFFF;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v24.m_map.m_map,
    0);
  v8 = typeReg;
  v9 = 0i64;
  v24.m_finishFlag = 0;
  v24.m_informMemoryTracker = 1;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&typeReg->m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
    (hkBool *)&typeReg,
    Iterator);
  while ( (_BYTE)typeReg )
  {
    Value = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
              Iterator);
    Key = (const char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getKey(
                          &v8->m_map.m_map,
                          Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&v24.m_map.m_map, Key, Value);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v8->m_map,
      (hkBool *)&typeReg,
      Iterator);
  }
  m_typeInfoReg = options->m_typeInfoReg;
  *(_OWORD *)&v25.m_storage = *(_OWORD *)&options->m_storage;
  v25.m_typeInfoReg = m_typeInfoReg;
  v14 = anonymous_namespace_::loadPackfile(streamIn, details, errorOut, &v24, &v25);
  if ( v14 )
  {
    hkDataWorldNative::hkDataWorldNative(&v26, 0);
    hkDataWorldNative::setClassRegistry(&v26, classReg);
    vfptr = classReg->vfptr;
    v16 = ((__int64 (__fastcall *)(hkResource *))v14->vfptr[3].__first_virtual_table_function__)(v14);
    v17 = (hkClass *)vfptr[2].__vecDelDtor(classReg, v16);
    if ( v17 )
    {
      v18 = (void *)((__int64 (__fastcall *)(hkResource *, _QWORD, hkTypeInfoRegistry *))v14->vfptr[3].__vecDelDtor)(
                      v14,
                      0i64,
                      v8);
      v19 = hkDataWorldNative::wrapObject(&v26, v18, v17);
      typeReg = (hkTypeInfoRegistry *)v19;
      if ( v19 )
      {
        ++v19->m_externalCount;
        ++v19->m_count;
      }
      v20 = hkDataObjectUtil::toObjectWithRegistry((hkDataObject *)&typeReg, classReg, v8, 1u);
      v21 = typeReg;
      v9 = v20;
      if ( typeReg )
      {
        --typeReg->m_referenceCount;
        if ( (*(_DWORD *)(&v21->m_referenceCount + 1))-- == 1 )
          v21->vfptr->__vecDelDtor(v21, 1u);
      }
    }
    hkDataWorldNative::~hkDataWorldNative(&v26);
  }
  if ( v14 )
    hkReferencedObject::removeReference(v14);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v24.m_map.m_map);
  return v9;
}

// File Line: 319
// RVA: 0xE3AD70
hkBool *__fastcall anonymous_namespace_::classSignaturesUpToDate(
        hkBool *result,
        hkPackfileHeader *packfileHeader,
        hkClassNameRegistry *classReg)
{
  int v3; // ebp
  hkPackfileHeader *v7; // rbx
  int v8; // esi
  int v9; // eax
  int v10; // r15d
  char *v11; // rsi
  hkClass *v12; // rax

  v3 = 0;
  v7 = packfileHeader + 1;
  v8 = 0;
  if ( packfileHeader->m_numSections <= 0 )
  {
LABEL_4:
    result->m_bool = 0;
  }
  else
  {
    while ( (unsigned int)hkString::strCmp((const char *)v7, hkBinaryPackfileWriter::SECTION_TAG_CLASSNAMES) )
    {
      ++v8;
      ++v7;
      if ( v8 >= packfileHeader->m_numSections )
        goto LABEL_4;
    }
    if ( v7->m_contentsSectionIndex - 6 > 0 )
    {
      do
      {
        v9 = v3 + v7->m_numSections;
        v10 = *(int *)((char *)packfileHeader->m_magic + v9);
        v11 = (char *)packfileHeader + v9;
        if ( v11[5] == -1 )
          break;
        if ( *((_BYTE *)&packfileHeader->m_magic[1] + v9) != 9
          || (v12 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, v11 + 5)) == 0i64
          || v10 != hkClass::getSignature(v12, 0) )
        {
          result->m_bool = 0;
          return result;
        }
        v3 += hkString::strLen(v11 + 5) + 6;
      }
      while ( v3 < v7->m_contentsSectionIndex - 6 );
    }
    result->m_bool = 1;
  }
  return result;
}

// File Line: 389
// RVA: 0xE39C90
hkClassNameRegistry *__fastcall hkSerializeUtil::LoadOptions::getClassNameRegistry(hkSerializeUtil::LoadOptions *this)
{
  hkClassNameRegistry *result; // rax

  result = this->m_classNameReg;
  if ( !result )
    return (hkClassNameRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  return result;
}

// File Line: 396
// RVA: 0xE39CB0
hkTypeInfoRegistry *__fastcall hkSerializeUtil::LoadOptions::getTypeInfoRegistry(hkSerializeUtil::LoadOptions *this)
{
  hkTypeInfoRegistry *result; // rax

  result = this->m_typeInfoReg;
  if ( !result )
    return (hkTypeInfoRegistry *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  return result;
}

// File Line: 407
// RVA: 0xE39CD0
hkResource *__fastcall hkSerializeUtil::load(
        hkStreamReader *streamIn,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkSerializeUtil::LoadOptions *options)
{
  hkClassNameRegistry *classReg; // r12
  hkTypeInfoRegistry *TypeInfoRegistry; // rdi
  hkLifoAllocator *v9; // rax
  char *m_cur; // rsi
  char *v11; // rcx
  hkMemoryAllocator **v12; // rax
  hkResource *v13; // rdi
  hkDataObject *v14; // rax
  hkResource *v15; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkLifoAllocator *v18; // rax
  hkLifoAllocator *Value; // rax
  char *v20; // rcx
  hkMemoryAllocator **v21; // rax
  hkDataObject *Contents; // rax
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  hkDataObject v24; // [rsp+30h] [rbp-D0h] BYREF
  hkDataObject v25; // [rsp+38h] [rbp-C8h] BYREF
  hkSerializeUtil::FormatDetails details; // [rsp+40h] [rbp-C0h] BYREF
  hkSerializeUtil::LoadOptions v27; // [rsp+60h] [rbp-A0h] BYREF
  hkDataWorldDict world; // [rsp+80h] [rbp-80h] BYREF
  hkResult result; // [rsp+1D0h] [rbp+D0h] BYREF
  hkResult v30; // [rsp+1E8h] [rbp+E8h] BYREF

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
    classReg = hkSerializeUtil::LoadOptions::getClassNameRegistry(options);
    TypeInfoRegistry = hkSerializeUtil::LoadOptions::getTypeInfoRegistry(options);
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(streamIn, &details, errorOut);
    if ( details.m_formatType.m_storage >= 2 )
    {
      if ( details.m_formatType.m_storage <= 3 )
      {
        m_typeInfoReg = options->m_typeInfoReg;
        *(_OWORD *)&v27.m_storage = *(_OWORD *)&options->m_storage;
        v27.m_typeInfoReg = m_typeInfoReg;
        v13 = anonymous_namespace_::loadPackfile(streamIn, &details, errorOut, TypeInfoRegistry, &v27);
LABEL_41:
        hkStringPtr::~hkStringPtr(&details.m_version);
        return v13;
      }
      if ( details.m_formatType.m_storage == 4 )
      {
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (char *)Value->m_cur;
        v20 = m_cur + 0x4000;
        if ( Value->m_slabSize < 0x4000 || v20 > Value->m_end )
          m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 0x4000);
        else
          Value->m_cur = v20;
        v21 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = 0i64;
        hkDataWorldDict::hkDataWorldDict(&world, v21[11]);
        if ( anonymous_namespace_::loadBinaryTagfileIntoWorld(&v30, streamIn, &world, errorOut, classReg)->m_enum
          && (options->m_storage & 2) == 0 )
        {
          goto LABEL_24;
        }
        Contents = hkDataWorldDict::getContents(&world, &v25);
        v15 = hkDataObjectUtil::toResourceWithRegistry(Contents, classReg, 1u);
        m_impl = v25.m_impl;
        goto LABEL_21;
      }
      if ( details.m_formatType.m_storage == 5 )
      {
        v9 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (char *)v9->m_cur;
        v11 = m_cur + 0x4000;
        if ( v9->m_slabSize < 0x4000 || v11 > v9->m_end )
          m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(v9, 0x4000);
        else
          v9->m_cur = v11;
        v12 = (hkMemoryAllocator **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = 0i64;
        hkDataWorldDict::hkDataWorldDict(&world, v12[11]);
        if ( anonymous_namespace_::loadXmlTagfileIntoWorld(&result, streamIn, &world, errorOut, classReg)->m_enum
          && (options->m_storage & 2) == 0 )
        {
          goto LABEL_24;
        }
        v14 = hkDataWorldDict::getContents(&world, &v24);
        v15 = hkDataObjectUtil::toResourceWithRegistry(v14, classReg, 1u);
        m_impl = v24.m_impl;
LABEL_21:
        v13 = v15;
        if ( m_impl )
        {
          --m_impl->m_externalCount;
          if ( m_impl->m_count-- == 1 )
            m_impl->vfptr->__vecDelDtor(m_impl, 1u);
        }
LABEL_24:
        hkDataWorldDict::~hkDataWorldDict(&world);
        v18 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v18->m_slabSize < 0x4000 || m_cur + 0x4000 != v18->m_cur || v18->m_firstNonLifoEnd == m_cur )
          hkLifoAllocator::slowBlockFree(v18, m_cur, 0x4000);
        else
          v18->m_cur = m_cur;
        goto LABEL_41;
      }
    }
    if ( errorOut && !errorOut->id.m_storage )
    {
      errorOut->id.m_storage = 2;
      hkStringPtr::operator=(&errorOut->defaultMessage, "Unable to detect format from stream");
    }
    v13 = 0i64;
    goto LABEL_41;
  }
  if ( !errorOut || errorOut->id.m_storage )
    return 0i64;
  errorOut->id.m_storage = 1;
  hkStringPtr::operator=(&errorOut->defaultMessage, "Stream is not ok");
  return 0i64;
}

// File Line: 485
// RVA: 0xE3A030
hkResource *__fastcall hkSerializeUtil::load(
        const char *filename,
        hkSerializeUtil::ErrorDetails *resultOut,
        hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  __int64 v5; // rax
  hkResource *v6; // rbx
  hkSerializeUtil::LoadOptions v8; // [rsp+20h] [rbp-48h] BYREF
  hkIstream v9; // [rsp+40h] [rbp-28h] BYREF

  m_typeInfoReg = options->m_typeInfoReg;
  *(_OWORD *)&v8.m_storage = *(_OWORD *)&options->m_storage;
  v8.m_typeInfoReg = m_typeInfoReg;
  hkIstream::hkIstream(&v9, filename);
  v6 = hkSerializeUtil::load(*(hkStreamReader **)(v5 + 16), resultOut, &v8);
  hkIstream::~hkIstream(&v9);
  return v6;
}

// File Line: 492
// RVA: 0xE3A090
hkResource *__fastcall hkSerializeUtil::load(
        hkPackfileHeader *buf,
        int buflen,
        hkSerializeUtil::ErrorDetails *resultOut,
        hkSerializeUtil::LoadOptions *options)
{
  bool v8; // zf
  const char *CurrentVersion; // rax
  hkClassNameRegistry *ClassNameRegistry; // rax
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  __int64 v13; // rax
  hkResource *v14; // rbx
  hkSerializeUtil::LoadOptions v15; // [rsp+20h] [rbp-88h] BYREF
  hkIstream v16; // [rsp+40h] [rbp-68h] BYREF
  int dst[10]; // [rsp+60h] [rbp-48h] BYREF
  char v18; // [rsp+88h] [rbp-20h]
  __int64 v19; // [rsp+98h] [rbp-10h]
  hkBool result; // [rsp+B0h] [rbp+8h] BYREF

  hkString::memSet(dst, -1, 0x40u);
  v8 = buf->m_magic[0] == 1474355287;
  dst[0] = 1474355287;
  dst[1] = 281067536;
  v19 = 0i64;
  v18 = 0;
  if ( v8
    && buf->m_magic[1] == 281067536
    && !hkString::memCmp(buf->m_layoutRules, &hkStructureLayout::HostLayoutRules, 4u) )
  {
    CurrentVersion = hkVersionUtil::getCurrentVersion();
    if ( !(unsigned int)hkString::strCmp(buf->m_contentsVersion, CurrentVersion) )
    {
      ClassNameRegistry = hkSerializeUtil::LoadOptions::getClassNameRegistry(options);
      if ( anonymous_namespace_::classSignaturesUpToDate(&result, buf, ClassNameRegistry)->m_bool )
        return hkNativePackfileUtils::load(buf, buflen, 0i64);
    }
  }
  m_typeInfoReg = options->m_typeInfoReg;
  *(_OWORD *)&v15.m_storage = *(_OWORD *)&options->m_storage;
  v15.m_typeInfoReg = m_typeInfoReg;
  hkIstream::hkIstream(&v16, buf, buflen);
  v14 = hkSerializeUtil::load(*(hkStreamReader **)(v13 + 16), resultOut, &v15);
  hkIstream::~hkIstream(&v16);
  return v14;
}

// File Line: 513
// RVA: 0xE3A1C0
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(
        hkStreamReader *streamIn,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkSerializeUtil::LoadOptions *options)
{
  hkClassNameRegistry *classReg; // r14
  hkTypeInfoRegistry *TypeInfoRegistry; // r15
  hkObjectResource *v9; // rbx
  hkDataObject *v10; // rax
  hkObjectResource *v11; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkDataObject *Contents; // rax
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  hkObjectResource *v16; // rax
  hkSerializeUtil::FormatDetails details; // [rsp+30h] [rbp-D0h] BYREF
  hkDataObject v18; // [rsp+48h] [rbp-B8h] BYREF
  hkDataObject v19; // [rsp+50h] [rbp-B0h] BYREF
  hkSerializeUtil::LoadOptions v20; // [rsp+60h] [rbp-A0h] BYREF
  hkDataWorldDict world; // [rsp+80h] [rbp-80h] BYREF
  hkResult result; // [rsp+1D0h] [rbp+D0h] BYREF
  hkResult v23; // [rsp+1E8h] [rbp+E8h] BYREF

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
    classReg = hkSerializeUtil::LoadOptions::getClassNameRegistry(options);
    TypeInfoRegistry = hkSerializeUtil::LoadOptions::getTypeInfoRegistry(options);
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(streamIn, &details, errorOut);
    if ( details.m_formatType.m_storage == 2 )
    {
      if ( details.m_layoutRules.m_bytesInPointer == hkStructureLayout::HostLayoutRules.m_bytesInPointer
        && details.m_layoutRules.m_littleEndian == hkStructureLayout::HostLayoutRules.m_littleEndian
        && details.m_layoutRules.m_reusePaddingOptimization == hkStructureLayout::HostLayoutRules.m_reusePaddingOptimization
        && details.m_layoutRules.m_emptyBaseClassOptimization == hkStructureLayout::HostLayoutRules.m_emptyBaseClassOptimization
        && ((unsigned __int64)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0
        && !(unsigned int)hkString::strCmp(
                            (const char *)((unsigned __int64)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            "hk_2013.2.0-r1")
        && details.m_formatVersion == hkBinaryPackfileWriter::CURRENT_FILE_VERSION )
      {
        m_typeInfoReg = options->m_typeInfoReg;
        *(_OWORD *)&v20.m_storage = *(_OWORD *)&options->m_storage;
        v20.m_typeInfoReg = m_typeInfoReg;
        v16 = anonymous_namespace_::loadNewPackfileOnHeap(
                streamIn,
                &details,
                errorOut,
                classReg,
                TypeInfoRegistry,
                &v20);
LABEL_40:
        v9 = v16;
        goto LABEL_41;
      }
      if ( (options->m_storage & 1) != 0 )
      {
        if ( errorOut && !errorOut->id.m_storage )
        {
          errorOut->id.m_storage = 4;
          hkStringPtr::operator=(
            &errorOut->defaultMessage,
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
        if ( anonymous_namespace_::loadBinaryTagfileIntoWorld(&v23, streamIn, &world, errorOut, classReg)->m_enum == HK_SUCCESS )
        {
          Contents = hkDataWorldDict::getContents(&world, &v19);
          v11 = hkDataObjectUtil::toObjectWithRegistry(Contents, classReg, TypeInfoRegistry, 1u);
          m_impl = v19.m_impl;
          goto LABEL_19;
        }
      }
      else
      {
        if ( details.m_formatType.m_storage != 5 )
        {
          if ( errorOut && !errorOut->id.m_storage )
          {
            errorOut->id.m_storage = 2;
            hkStringPtr::operator=(&errorOut->defaultMessage, "Unable to detect format from stream");
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
        if ( anonymous_namespace_::loadXmlTagfileIntoWorld(&result, streamIn, &world, errorOut, classReg)->m_enum == HK_SUCCESS )
        {
          v10 = hkDataWorldDict::getContents(&world, &v18);
          v11 = hkDataObjectUtil::toObjectWithRegistry(v10, classReg, TypeInfoRegistry, 1u);
          m_impl = v18.m_impl;
LABEL_19:
          v9 = v11;
          if ( m_impl )
          {
            --m_impl->m_externalCount;
            if ( m_impl->m_count-- == 1 )
            {
              m_impl->vfptr->__vecDelDtor(m_impl, 1u);
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
                                streamIn,
                                &details,
                                errorOut);
    goto LABEL_40;
  }
  if ( !errorOut || errorOut->id.m_storage )
    return 0i64;
  errorOut->id.m_storage = 1;
  hkStringPtr::operator=(&errorOut->defaultMessage, "Stream is not ok");
  return 0i64;
}

// File Line: 587
// RVA: 0xE3A4D0
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(
        const char *filename,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  __int64 v5; // rax
  hkObjectResource *v6; // rbx
  hkSerializeUtil::LoadOptions v8; // [rsp+20h] [rbp-48h] BYREF
  hkIstream v9; // [rsp+40h] [rbp-28h] BYREF

  m_typeInfoReg = options->m_typeInfoReg;
  *(_OWORD *)&v8.m_storage = *(_OWORD *)&options->m_storage;
  v8.m_typeInfoReg = m_typeInfoReg;
  hkIstream::hkIstream(&v9, filename);
  v6 = hkSerializeUtil::loadOnHeap(*(hkStreamReader **)(v5 + 16), errorOut, &v8);
  hkIstream::~hkIstream(&v9);
  return v6;
}

// File Line: 592
// RVA: 0xE3A530
hkObjectResource *__fastcall hkSerializeUtil::loadOnHeap(
        const void *buf,
        int buflen,
        hkSerializeUtil::ErrorDetails *errorOut,
        hkSerializeUtil::LoadOptions *options)
{
  hkTypeInfoRegistry *m_typeInfoReg; // xmm1_8
  __int64 v6; // rax
  hkObjectResource *v7; // rbx
  hkSerializeUtil::LoadOptions v9; // [rsp+20h] [rbp-48h] BYREF
  hkIstream v10; // [rsp+40h] [rbp-28h] BYREF

  m_typeInfoReg = options->m_typeInfoReg;
  *(_OWORD *)&v9.m_storage = *(_OWORD *)&options->m_storage;
  v9.m_typeInfoReg = m_typeInfoReg;
  hkIstream::hkIstream(&v10, buf, buflen);
  v7 = hkSerializeUtil::loadOnHeap(*(hkStreamReader **)(v6 + 16), errorOut, &v9);
  hkIstream::~hkIstream(&v10);
  return v7;
}

// File Line: 597
// RVA: 0xE3A590
hkResult *__fastcall hkSerializeUtil::savePackfile(
        hkResult *result,
        const void *object,
        hkClass *klass,
        hkStreamWriter *writer,
        hkPackfileWriter::Options *packFileOptions,
        hkPackfileWriter::AddObjectListener *userListener,
        hkSerializeUtil::SaveOptions options)
{
  char m_bool; // cl
  hkResultEnum v12; // eax
  hkPackfileWriter::Options v14; // [rsp+40h] [rbp-C0h] BYREF
  int v15; // [rsp+58h] [rbp-A8h] BYREF
  hkStringPtr v16; // [rsp+60h] [rbp-A0h] BYREF
  hkErrStream v17; // [rsp+68h] [rbp-98h] BYREF
  hkBinaryPackfileWriter buf; // [rsp+80h] [rbp-80h] BYREF
  hkResultEnum v19; // [rsp+2B8h] [rbp+1B8h] BYREF

  if ( writer )
  {
    v14 = *packFileOptions;
    m_bool = v14.m_writeSerializedFalse.m_bool;
    if ( (options.m_storage & 2) != 0 )
      m_bool = 1;
    v14.m_writeSerializedFalse.m_bool = m_bool;
    if ( (options.m_storage & 1) != 0 )
    {
      v15 = 0;
      hkStringPtr::hkStringPtr(&v16);
      ((void (__fastcall *)(hkSerializeDeprecated *, hkResultEnum *, const void *, hkClass *, hkStreamWriter *, hkPackfileWriter::Options *, hkPackfileWriter::AddObjectListener *, int *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[2].__vecDelDtor)(
        hkSingleton<hkSerializeDeprecated>::s_instance,
        &v19,
        object,
        klass,
        writer,
        &v14,
        userListener,
        &v15);
      v12 = v19;
      if ( v19 == HK_FAILURE )
      {
        hkErrStream::hkErrStream(&v17, (char *)&buf, 512);
        hkOstream::operator<<(&v17, (const char *)((unsigned __int64)v16.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        hkError::messageWarning(0x1D25E54Fu, (const char *)&buf, "Util\\hkSerializeUtil.cpp", 616);
        hkOstream::~hkOstream(&v17);
        v12 = v19;
      }
      result->m_enum = v12;
      hkStringPtr::~hkStringPtr(&v16);
    }
    else
    {
      hkBinaryPackfileWriter::hkBinaryPackfileWriter(&buf, &v14);
      hkPackfileWriter::setContents(&buf, object, klass, userListener);
      hkBinaryPackfileWriter::save(&buf, result, writer, &v14);
      hkBinaryPackfileWriter::~hkBinaryPackfileWriter(&buf);
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 625
// RVA: 0xE3A730
hkResult *__fastcall hkSerializeUtil::saveTagfile(
        hkResult *result,
        void *object,
        hkClass *klass,
        hkStreamWriter *writer,
        hkPackfileWriter::AddObjectListener *userListener,
        hkSerializeUtil::SaveOptions options)
{
  __int64 v10; // rax
  char v11; // r8
  hkDataObject *Contents; // rax
  hkDataObjectImpl *m_impl; // rcx
  bool v14; // zf
  hkDataObject *v15; // rax
  hkDataObjectImpl *v16; // rcx
  hkXmlTagfileWriter v18; // [rsp+30h] [rbp-D0h] BYREF
  hkTagfileWriter::AddDataObjectListener v19; // [rsp+40h] [rbp-C0h] BYREF
  hkPackfileWriter::AddObjectListener *v20; // [rsp+50h] [rbp-B0h]
  hkDataWorldNative *v21; // [rsp+58h] [rbp-A8h]
  __int64 v22; // [rsp+60h] [rbp-A0h]
  hkDataWorldNative v23; // [rsp+70h] [rbp-90h] BYREF
  hkDataObject resulta; // [rsp+218h] [rbp+118h] BYREF

  hkDataWorldNative::hkDataWorldNative(&v23, (hkBool)((options.m_storage & 2) != 0));
  hkDataWorldNative::setContents(&v23, object, klass);
  v10 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  *(_DWORD *)&v19.m_memSizeAndFlags = 0x1FFFF;
  v19.vfptr = (hkBaseObjectVtbl *)&`anonymous namespace::ForwardingPackfileListerer::`vftable;
  v20 = userListener;
  v22 = v10;
  v21 = &v23;
  if ( !writer )
  {
    result->m_enum = HK_FAILURE;
    goto LABEL_13;
  }
  v11 = 0;
  BYTE2(userListener) = 0;
  if ( (options.m_storage & 8) == 0 )
    v11 = 1;
  *(_DWORD *)&v18.m_memSizeAndFlags = 0x1FFFF;
  LOBYTE(userListener) = v11;
  BYTE1(userListener) = 1;
  if ( (options.m_storage & 1) != 0 )
  {
    v18.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileWriter::`vftable;
    Contents = hkDataWorldNative::getContents(&v23, &resulta);
    hkXmlTagfileWriter::save(&v18, result, Contents, writer, &v19, (hkTagfileWriter::Options *)&userListener);
    m_impl = resulta.m_impl;
    if ( resulta.m_impl )
    {
      --resulta.m_impl->m_externalCount;
      v14 = m_impl->m_count-- == 1;
      if ( v14 )
        m_impl->vfptr->__vecDelDtor(m_impl, 1u);
    }
  }
  else
  {
    v18.vfptr = (hkBaseObjectVtbl *)&hkBinaryTagfileWriter::`vftable;
    v15 = hkDataWorldNative::getContents(&v23, &resulta);
    hkBinaryTagfileWriter::save(
      (hkBinaryTagfileWriter *)&v18,
      result,
      v15,
      writer,
      &v19,
      (hkTagfileWriter::Options *)&userListener);
    v16 = resulta.m_impl;
    if ( resulta.m_impl )
    {
      --resulta.m_impl->m_externalCount;
      v14 = v16->m_count-- == 1;
      if ( v14 )
      {
        v16->vfptr->__vecDelDtor(v16, 1u);
        v18.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
        goto LABEL_13;
      }
    }
  }
  v18.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
LABEL_13:
  v19.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  hkDataWorldNative::~hkDataWorldNative(&v23);
  return result;
}

// File Line: 659
// RVA: 0xE3A920
hkResult *__fastcall hkSerializeUtil::save(
        hkResult *result,
        void *object,
        hkClass *klass,
        hkStreamWriter *writer,
        hkSerializeUtil::SaveOptions options)
{
  hkSerializeUtil::saveTagfile(result, object, klass, writer, 0i64, options);
  return result;
}

// File Line: 664
// RVA: 0xE3AC60
__int64 __fastcall hkSerializeUtil::isLoadable(hkStreamReader *sr)
{
  int m_storage; // eax
  const char *CurrentVersion; // rax
  int v5; // eax
  hkSerializeUtil::FormatDetails details; // [rsp+20h] [rbp-28h] BYREF
  hkEnum<enum hkTagfileReader::FormatType,int> result; // [rsp+50h] [rbp+8h] BYREF

  if ( sr
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, hkEnum<enum hkTagfileReader::FormatType,int> *))sr->vfptr[1].__first_virtual_table_function__)(
                   sr,
                   &result) )
  {
    if ( hkTagfileReader::detectFormat(&result, sr)->m_storage > 1 )
      return 1i64;
    hkStringPtr::hkStringPtr(&details.m_version);
    hkSerializeUtil::detectFormat(sr, &details, 0i64);
    m_storage = details.m_formatType.m_storage;
    if ( details.m_formatType.m_storage == 2 )
    {
      if ( !hkString::memCmp(&details.m_layoutRules, &hkStructureLayout::HostLayoutRules, 4u) )
      {
        CurrentVersion = hkVersionUtil::getCurrentVersion();
        if ( ((unsigned __int64)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        {
          if ( !CurrentVersion )
            goto LABEL_16;
          v5 = hkString::strCmp(
                 (const char *)((unsigned __int64)details.m_version.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                 CurrentVersion);
        }
        else
        {
          v5 = -(CurrentVersion != 0i64);
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
      m_storage = details.m_formatType.m_storage;
    }
    if ( m_storage != 3 )
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
hkEnum<enum hkSerializeUtil::FormatType,int> *__fastcall hkSerializeUtil::detectFormat(
        hkEnum<enum hkSerializeUtil::FormatType,int> *result,
        hkStreamReader *reader,
        hkSerializeUtil::ErrorDetails *errorOut)
{
  hkSerializeUtil::FormatDetails details; // [rsp+20h] [rbp-28h] BYREF

  hkStringPtr::hkStringPtr(&details.m_version);
  hkSerializeUtil::detectFormat(reader, &details, errorOut);
  result->m_storage = (int)details.m_formatType;
  hkStringPtr::~hkStringPtr(&details.m_version);
  return result;
}

// File Line: 752
// RVA: 0xE3BD20
hkBool *__fastcall `anonymous namespace::PeekStreamReader::isOk(PeekStreamReader *this, hkBool *result)
{
  char v4; // [rsp+30h] [rbp+8h] BYREF

  if ( this->m_curPos >= 0
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))this->m_underlyingStream->vfptr[1].__first_virtual_table_function__)(
                   this->m_underlyingStream,
                   &v4) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 757
// RVA: 0xE3BDD0
__int64 __fastcall `anonymous namespace::PeekStreamReader::read(PeekStreamReader *this, void *buf, __int64 nbytes)
{
  __int64 result; // rax

  result = ((__int64 (__fastcall *)(PeekStreamReader *, void *, __int64))this->vfptr[3].__vecDelDtor)(this, buf, nbytes);
  this->m_curPos += result;
  return result;
}

// File Line: 765
// RVA: 0xE3BD60
__int64 __fastcall `anonymous namespace::PeekStreamReader::peek(
        PeekStreamReader *this,
        void *buf,
        unsigned int nbytes)
{
  unsigned int v3; // ebx
  __int64 m_curPos; // rax

  v3 = nbytes;
  if ( (signed int)(nbytes + this->m_curPos) >= this->m_peekBuffer.m_size )
    `anonymous namespace::PeekStreamReader::expandPeekBuffer(this, nbytes);
  m_curPos = this->m_curPos;
  if ( this->m_peekBuffer.m_size - (int)m_curPos < (int)v3 )
    v3 = this->m_peekBuffer.m_size - m_curPos;
  if ( v3 )
    hkString::memCpy(buf, &this->m_peekBuffer.m_data[m_curPos], v3);
  return v3;
}

// File Line: 788
// RVA: 0xE3BC40
void __fastcall `anonymous namespace::PeekStreamReader::expandPeekBuffer(PeekStreamReader *this, const int nbytes)
{
  int v3; // edx
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  int v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // ecx
  int v12; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v3 = this->m_peekBuffer.m_size + nbytes + 1;
  v4 = (int)((double)this->m_peekBuffer.m_size * 1.5);
  if ( v3 > v4 )
    v4 = v3;
  v5 = this->m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < v4 )
  {
    v6 = 2 * v5;
    v7 = v4;
    if ( v4 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_peekBuffer.m_data, v7, 1);
  }
  this->m_peekBuffer.m_size = v4;
  v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))this->m_underlyingStream->vfptr[3].__vecDelDtor)(
         this->m_underlyingStream,
         this->m_peekBuffer.m_data,
         (unsigned int)v4);
  v9 = this->m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v8;
  if ( v9 >= v8 )
  {
    this->m_peekBuffer.m_size = v8;
  }
  else
  {
    v11 = 2 * v9;
    v12 = v8;
    if ( v8 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&this->m_peekBuffer.m_data,
      v12,
      1);
    this->m_peekBuffer.m_size = v10;
  }
}

// File Line: 803
// RVA: 0xE3A9B0
void __fastcall hkSerializeUtil::detectFormat(
        const char *fileName,
        hkSerializeUtil::FormatDetails *details,
        hkSerializeUtil::ErrorDetails *errorOut)
{
  __int64 v5; // rax
  hkIstream v6; // [rsp+20h] [rbp-28h] BYREF

  hkIstream::hkIstream(&v6, fileName);
  hkSerializeUtil::detectFormat(*(hkStreamReader **)(v5 + 16), details, errorOut);
  hkIstream::~hkIstream(&v6);
}

// File Line: 808
// RVA: 0xE3AA00
void __fastcall hkSerializeUtil::detectFormat(
        hkStreamReader *reader,
        hkSerializeUtil::FormatDetails *details,
        hkSerializeUtil::ErrorDetails *errorOut)
{
  PeekStreamReader v6; // [rsp+30h] [rbp-D0h] BYREF
  hkXmlTagfileReader v7; // [rsp+60h] [rbp-A0h] BYREF
  int v8; // [rsp+70h] [rbp-90h] BYREF
  hkStringPtr v9; // [rsp+78h] [rbp-88h] BYREF
  hkStringPtr v10; // [rsp+80h] [rbp-80h] BYREF
  hkXmlTagfile::Header v11; // [rsp+88h] [rbp-78h] BYREF
  hkBinaryTagfileReader v12; // [rsp+98h] [rbp-68h] BYREF
  hkPackfileHeader dst; // [rsp+B0h] [rbp-50h] BYREF
  hkBinaryTagfile::Header out; // [rsp+F0h] [rbp-10h] BYREF
  hkResult result; // [rsp+140h] [rbp+40h] BYREF

  *(_QWORD *)&details->m_formatType.m_storage = 0i64;
  hkStringPtr::operator=(&details->m_version, 0i64);
  hkMemUtil::memSet(&details->m_layoutRules, 0, 4u);
  v6.vfptr = (hkBaseObjectVtbl *)&`anonymous namespace::PeekStreamReader::`vftable;
  *(_DWORD *)&v6.m_memSizeAndFlags = 0x1FFFF;
  v6.m_underlyingStream = reader;
  v6.m_peekBuffer.m_data = 0i64;
  v6.m_peekBuffer.m_size = 0;
  v6.m_peekBuffer.m_capacityAndFlags = 0x80000000;
  v6.m_curPos = 0;
  `anonymous namespace::PeekStreamReader::expandPeekBuffer(&v6, 512);
  hkBinaryTagfileReader::hkBinaryTagfileReader(&v12);
  hkStringPtr::hkStringPtr(&out.m_sdk);
  if ( hkBinaryTagfileReader::readHeader(&v12, &result, &v6, &out)->m_enum )
  {
    v6.m_curPos = 0;
    hkString::memSet(&dst, -1, 0x40u);
    dst.m_magic[0] = 1474355287;
    dst.m_magic[1] = 281067536;
    dst.m_contentsVersion[0] = 0;
    *(_QWORD *)&dst.m_flags = 0i64;
    if ( hkPackfileHeader::readHeader(&result, &v6, &dst)->m_enum )
    {
      v6.m_curPos = 0;
      v7.vfptr = (hkBaseObjectVtbl *)&hkXmlTagfileReader::`vftable;
      *(_DWORD *)&v7.m_memSizeAndFlags = 0x1FFFF;
      hkStringPtr::hkStringPtr(&v11.m_sdkVersion);
      if ( hkXmlTagfileReader::readHeader(&v7, &result, &v6, &v11)->m_enum )
      {
        v6.m_curPos = 0;
        hkStringPtr::hkStringPtr(&v9);
        hkStringPtr::hkStringPtr(&v10);
        if ( !*(_DWORD *)((__int64 (__fastcall *)(hkSerializeDeprecated *, hkResult *, PeekStreamReader *, int *, hkSerializeUtil::ErrorDetails *))hkSingleton<hkSerializeDeprecated>::s_instance->vfptr[4].__vecDelDtor)(
                           hkSingleton<hkSerializeDeprecated>::s_instance,
                           &result,
                           &v6,
                           &v8,
                           errorOut) )
        {
          details->m_formatType.m_storage = 3;
          hkStringPtr::operator=(&details->m_version, &v9);
          details->m_formatVersion = v8;
        }
        hkStringPtr::~hkStringPtr(&v10);
        hkStringPtr::~hkStringPtr(&v9);
      }
      else
      {
        details->m_formatType.m_storage = 5;
      }
      hkStringPtr::~hkStringPtr(&v11.m_sdkVersion);
      v7.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
    }
    else
    {
      details->m_formatType.m_storage = 2;
      hkStringPtr::operator=(&details->m_version, dst.m_contentsVersion);
      details->m_formatVersion = dst.m_fileVersion;
      hkMemUtil::memCpy(&details->m_layoutRules, dst.m_layoutRules, 4);
    }
  }
  else
  {
    details->m_formatType.m_storage = 4;
  }
  hkStringPtr::~hkStringPtr(&out.m_sdk);
  v12.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  v6.m_peekBuffer.m_size = 0;
  if ( v6.m_peekBuffer.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v6.m_peekBuffer.m_data,
      v6.m_peekBuffer.m_capacityAndFlags & 0x3FFFFFFF);
}

