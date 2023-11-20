// File Line: 109
// RVA: 0xE50710
void __fastcall `anonymous namespace::Writer::Writer(Writer *this, hkStreamWriter *sw, hkTagfileWriter::AddDataObjectListener *listener, hkTagfileWriter::Options *options)
{
  hkTagfileWriter::AddDataObjectListener *v4; // rdi
  hkTagfileWriter::Options *v5; // r14
  Writer *v6; // r13
  int v7; // er9
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // eax
  __int64 v13; // rdx
  signed __int64 v14; // r8
  __int128 v15; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v4 = listener;
  v5 = options;
  v6 = this;
  hkOArchive::hkOArchive(&this->m_oa, sw, 0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v6->m_writtenStrings.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v6->m_doneClasses.m_map,
    0);
  v6->m_currentRememberTag = 1;
  v6->m_detailIndexFromObject.m_hashMod = -1;
  v6->m_detailIndexFromObject.m_elem = 0i64;
  v6->m_detailIndexFromObject.m_numElems = 0;
  v6->m_bitfieldBuf.m_data = 0i64;
  v6->m_bitfieldBuf.m_size = 0;
  v6->m_bitfieldBuf.m_capacityAndFlags = 2147483648;
  v6->m_details.m_data = 0i64;
  v6->m_details.m_size = 0;
  v6->m_details.m_capacityAndFlags = 2147483648;
  v6->m_listenerCache.m_listener = v4;
  v6->m_listenerCache.m_indexFromHandle.m_elem = 0i64;
  v6->m_listenerCache.m_indexFromHandle.m_numElems = 0;
  v6->m_listenerCache.m_indexFromHandle.m_hashMod = -1;
  v6->m_listenerCache.m_cachedObjects.m_data = 0i64;
  v6->m_listenerCache.m_cachedObjects.m_size = 0;
  v6->m_listenerCache.m_cachedObjects.m_capacityAndFlags = 2147483648;
  v6->m_log = 0i64;
  v6->m_writeSerializeIgnored.m_bool = v5->m_writeSerializeIgnored.m_bool;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v6->m_doneClasses.m_map,
    (unsigned __int64)&customWorldMapCaption,
    0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v6->m_writtenStrings.m_map,
    (unsigned __int64)&customWorldMapCaption,
    0i64);
  v15 = 0ui64;
  _mm_store_si128((__m128i *)&v15, (__m128i)0i64);
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v6->m_detailIndexFromObject,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (hkDataObject_Handle *)&v15,
    0);
  v7 = 512;
  v8 = v6->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < 512 )
  {
    v9 = 2 * v8;
    if ( v9 > 512 )
      v7 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v6->m_bitfieldBuf,
      v7,
      1);
  }
  v10 = 128;
  v11 = v6->m_details.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v11 < 128 )
  {
    v12 = 2 * v11;
    if ( v12 > 128 )
      v10 = v12;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      &v6->m_details,
      v10,
      24);
  }
  if ( v6->m_details.m_size == (v6->m_details.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v6->m_details, 24);
  v13 = v6->m_details.m_size;
  v14 = (signed __int64)&v6->m_details.m_data[v13];
  v6->m_details.m_size = v13 + 1;
  *(_QWORD *)v14 = 0i64;
  *(_QWORD *)(v14 + 8) = 0i64;
  *(_DWORD *)(v14 + 20) = 0;
  *(_DWORD *)(v14 + 16) = -1;
}

// File Line: 124
// RVA: 0xE50A10
void __fastcall `anonymous namespace::Writer::~Writer(Writer *this)
{
  Writer *v1; // rbx
  int v2; // eax
  int v3; // er8

  v1 = this;
  `anonymous namespace::Writer::ListenerCache::~ListenerCache(&this->m_listenerCache);
  v2 = v1->m_details.m_capacityAndFlags;
  v1->m_details.m_size = 0;
  if ( v2 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v1->m_details.m_data,
      24 * (v2 & 0x3FFFFFFF));
  v1->m_details.m_data = 0i64;
  v1->m_details.m_capacityAndFlags = 2147483648;
  v3 = v1->m_bitfieldBuf.m_capacityAndFlags;
  v1->m_bitfieldBuf.m_size = 0;
  if ( v3 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v1->m_bitfieldBuf.m_data,
      v3 & 0x3FFFFFFF);
  v1->m_bitfieldBuf.m_data = 0i64;
  v1->m_bitfieldBuf.m_capacityAndFlags = 2147483648;
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v1->m_detailIndexFromObject,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_doneClasses.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_writtenStrings.m_map);
  hkOArchive::~hkOArchive(&v1->m_oa);
}

// File Line: 129
// RVA: 0xE52D90
void __fastcall `anonymous namespace::Writer::writeInt(Writer *this, __int64 i)
{
  Writer *v2; // rdi
  unsigned __int64 v3; // rbx
  char v4; // dl
  unsigned __int64 v5; // rbx
  char j; // dl
  char v7; // dl

  v2 = this;
  if ( i == 0x8000000000000000i64 )
  {
    hkOArchive::write8u(&this->m_oa, 129);
    v3 = 0x200000000000000i64;
  }
  else if ( i >= 0 )
  {
    v3 = 2 * i;
  }
  else
  {
    v3 = -2 * i | 1;
  }
  v4 = v3;
  v5 = v3 >> 7;
  for ( j = v4 & 0x7F; v5; j = v7 & 0x7F )
  {
    hkOArchive::write8u(&v2->m_oa, j | 0x80);
    v7 = v5;
    v5 >>= 7;
  }
  hkOArchive::write8u(&v2->m_oa, j);
}

// File Line: 174
// RVA: 0xE53190
void __fastcall `anonymous namespace::Writer::writeString(Writer *this, const char *s)
{
  const char *v2; // rsi
  Writer *v3; // rdi
  int v4; // eax
  unsigned int v5; // ebx

  v2 = s;
  v3 = this;
  if ( s )
  {
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_writtenStrings,
           (unsigned __int64)s,
           0xFFFFFFFFFFFFFFFFui64);
    if ( v4 == -1 )
    {
      v5 = hkString::strLen(v2);
      `anonymous namespace::Writer::writeInt(v3, (signed int)v5);
      hkOArchive::writeRaw(&v3->m_oa, v2, v5);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v3->m_writtenStrings.m_map,
        (unsigned __int64)v2,
        v3->m_writtenStrings.m_map.m_numElems + 1);
    }
    else
    {
      `anonymous namespace::Writer::writeInt(v3, -v4);
    }
  }
  else
  {
    hkOArchive::write8u(&this->m_oa, 3);
  }
}

// File Line: 226
// RVA: 0xE52A70
unsigned __int64 __fastcall `anonymous namespace::Writer::writeClass(Writer *this, hkDataClass *klass)
{
  Writer *v2; // rsi
  hkDataClass *v3; // rbx
  unsigned __int64 result; // rax
  unsigned __int64 v5; // rax
  int v6; // eax
  hkDataRefCountedVtbl *v7; // rdx
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rax
  int v10; // eax
  __int64 v11; // rdi
  int v12; // edx
  hkDataClass_MemberInfo *v13; // rcx
  int v14; // eax
  hkTypeManager::Type **v15; // rax
  __int64 v16; // rdx
  const char *v17; // rax
  int v18; // eax
  __int64 v19; // rdi
  hkDataClass_MemberInfo *v20; // rbx
  hkLegacyType::Type v21; // eax
  char v22; // bl
  hkDataClass *v23; // rbx
  __int64 v24; // rax
  __int64 v25; // rax
  const char *v26; // rax
  __int64 v27; // rdi
  hkDataClassImpl *v28; // rcx
  _QWORD *v29; // rax
  __int64 v30; // rdi
  _QWORD *v31; // rbx
  const char *v32; // rax
  __int64 v33; // [rsp+20h] [rbp-30h]
  unsigned __int64 v34; // [rsp+28h] [rbp-28h]
  hkDataClass v35; // [rsp+30h] [rbp-20h]
  hkArrayBase<hkDataClass_MemberInfo> minfos; // [rsp+38h] [rbp-18h]
  hkDataClass *v37; // [rsp+78h] [rbp+28h]
  hkDataClass klassa; // [rsp+80h] [rbp+30h]
  char *className; // [rsp+88h] [rbp+38h]

  v37 = klass;
  v2 = this;
  v3 = klass;
  if ( !klass->m_impl )
    return 0i64;
  v5 = ((__int64 (*)(void))klass->m_impl->vfptr[2].__vecDelDtor)();
  result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_doneClasses,
             v5,
             0xFFFFFFFFFFFFFFFFui64);
  if ( (result & 0x80000000) != 0i64 )
  {
    klassa.m_impl = (hkDataClassImpl *)((__int64 (*)(void))v3->m_impl->vfptr[4].__vecDelDtor)();
    v6 = `anonymous namespace::Writer::writeClass(v2, &klassa);
    v7 = v3->m_impl->vfptr;
    LODWORD(className) = v6;
    v8 = ((__int64 (*)(void))v7[2].__vecDelDtor)();
    result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_doneClasses,
               v8,
               0xFFFFFFFFFFFFFFFFui64);
    if ( (_DWORD)result == -1 )
    {
      v34 = (unsigned int)v2->m_doneClasses.m_map.m_numElems;
      v9 = ((__int64 (*)(void))v3->m_impl->vfptr[2].__vecDelDtor)();
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v2->m_doneClasses.m_map,
        v9,
        (signed int)v34);
      v10 = ((__int64 (*)(void))v3->m_impl->vfptr[6].__vecDelDtor)();
      minfos.m_capacityAndFlags = 2147483648;
      v11 = v10;
      minfos.m_data = 0i64;
      minfos.m_size = 0;
      v12 = v10;
      if ( v10 )
      {
        LODWORD(klassa.m_impl) = 32 * v10;
        v13 = (hkDataClass_MemberInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                          (int *)&klassa);
        v12 = SLODWORD(klassa.m_impl) / 32;
      }
      else
      {
        v13 = 0i64;
      }
      v14 = 2147483648;
      minfos.m_data = v13;
      if ( v12 )
        v14 = v12;
      minfos.m_size = v11;
      v33 = v11;
      minfos.m_capacityAndFlags = v14;
      if ( v11 > 0 )
      {
        v15 = &v13->m_type;
        v16 = v11;
        do
        {
          if ( v15 != (hkTypeManager::Type **)16 )
          {
            *(v15 - 2) = 0i64;
            *(v15 - 1) = 0i64;
            *v15 = 0i64;
            v15[1] = 0i64;
          }
          v15 += 4;
          --v16;
        }
        while ( v16 );
      }
      hkDataClass::getAllDeclaredMemberInfo(v3, &minfos);
      hkOArchive::write8u(&v2->m_oa, 4);
      v17 = (const char *)((__int64 (*)(void))v3->m_impl->vfptr[2].__vecDelDtor)();
      `anonymous namespace::Writer::writeString(v2, v17);
      v18 = ((__int64 (*)(void))v3->m_impl->vfptr[3].__vecDelDtor)();
      `anonymous namespace::Writer::writeInt(v2, v18);
      ((void (*)(void))v3->m_impl->vfptr[3].__vecDelDtor)();
      `anonymous namespace::Writer::writeInt(v2, (signed int)className);
      `anonymous namespace::Writer::writeInt(v2, v11);
      if ( v11 > 0 )
      {
        klassa.m_impl = 0i64;
        v35.m_impl = (hkDataClassImpl *)v11;
        v19 = 0i64;
        while ( 1 )
        {
          v20 = minfos.m_data;
          `anonymous namespace::Writer::writeString(v2, minfos.m_data[v19].m_name);
          v21 = hkTypeManager::getLegacyType(v20[v19].m_type, (const char **)&className, (int *)&klassa);
          v22 = v21;
          `anonymous namespace::Writer::writeInt(v2, v21);
          if ( v22 & 0x20 )
            `anonymous namespace::Writer::writeInt(v2, SLODWORD(klassa.m_impl));
          if ( (v22 & 0xFu) - 8 > 1 )
            goto LABEL_23;
          if ( !className )
            break;
          v23 = v37;
          v24 = ((__int64 (*)(void))v37->m_impl->vfptr[1].__vecDelDtor)();
          v25 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v24 + 72i64))(v24, className);
          v26 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 16i64))(v25);
          `anonymous namespace::Writer::writeString(v2, v26);
LABEL_24:
          ++v19;
          if ( !--v35.m_impl )
          {
            v27 = v33;
            if ( v33 > 0 )
            {
              v28 = 0i64;
              klassa.m_impl = 0i64;
              do
              {
                className = (char *)hkTypeManager::Type::findTerminal(*(hkTypeManager::Type **)((char *)&v28[1].vfptr
                                                                                              + (unsigned __int64)minfos.m_data));
                if ( *(_DWORD *)className == 6 )
                {
                  v29 = (_QWORD *)((__int64 (*)(void))v23->m_impl->vfptr[1].__vecDelDtor)();
                  v30 = *v29;
                  v31 = v29;
                  v32 = hkTypeManager::Type::getTypeName((hkTypeManager::Type *)className);
                  v35.m_impl = (hkDataClassImpl *)(*(__int64 (__fastcall **)(_QWORD *, const char *))(v30 + 72))(
                                                    v31,
                                                    v32);
                  `anonymous namespace::Writer::writeClass(v2, &v35);
                  v27 = v33;
                }
                v23 = v37;
                v28 = klassa.m_impl + 2;
                v33 = --v27;
                klassa.m_impl += 2;
              }
              while ( v27 );
            }
            goto LABEL_30;
          }
        }
        hkOArchive::write8u(&v2->m_oa, 3);
LABEL_23:
        v23 = v37;
        goto LABEL_24;
      }
LABEL_30:
      minfos.m_size = 0;
      if ( minfos.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          minfos.m_data,
          32 * minfos.m_capacityAndFlags);
      result = v34;
    }
  }
  return result;
}

// File Line: 333
// RVA: 0xE504E0
signed __int64 __usercall `anonymous namespace::Writer::worthWriting<hkDataObject_Value>@<rax>(Writer *this@<rcx>, hkDataObject_Value *value@<rdx>, float a3@<xmm0>)
{
  hkDataObject_Value *v3; // rbx
  signed __int64 result; // rax
  __int64 v5; // rax
  BOOL v6; // ebx
  bool v7; // zf
  __int64 v8; // rax
  __int64 v9; // rbx
  int v10; // eax
  BOOL v11; // edi

  v3 = value;
  switch ( hkDataObject_Value::getType(value)->m_subType )
  {
    case 2:
    case 4:
      result = (__int64)v3->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle) != 0;
      break;
    case 3:
      v3->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
      result = a3 != 0.0;
      break;
    case 5:
      result = (__int64)v3->m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle) != 0;
      break;
    case 6:
    case 7:
      v5 = (__int64)v3->m_impl->vfptr[13].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
      if ( v5 )
      {
        ++*(_WORD *)(v5 + 10);
        ++*(_DWORD *)(v5 + 12);
      }
      v6 = v5 != 0;
      if ( v5 )
      {
        --*(_WORD *)(v5 + 10);
        v7 = (*(_DWORD *)(v5 + 12))-- == 1;
        if ( v7 )
          (**(void (__fastcall ***)(__int64, signed __int64))v5)(v5, 1i64);
      }
      result = (unsigned int)v6;
      break;
    case 8:
      v8 = (__int64)v3->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)v3->m_impl, (unsigned int)v3->m_handle);
      v9 = v8;
      if ( v8 )
      {
        ++*(_WORD *)(v8 + 10);
        ++*(_DWORD *)(v8 + 12);
      }
      v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8);
      --*(_WORD *)(v9 + 10);
      v7 = (*(_DWORD *)(v9 + 12))-- == 1;
      v11 = v10 != 0;
      if ( v7 )
        (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
      result = (unsigned int)v11;
      break;
    case 9:
      result = 1i64;
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 379
// RVA: 0xE50650
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(Writer::MemberWriteFlags *this, int nm)
{
  int v2; // esi
  Writer::MemberWriteFlags *v3; // rbx
  signed int v4; // ebp
  int v5; // er9
  signed __int64 v6; // rcx
  int v7; // eax
  int v8; // eax
  int v9; // er9
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = nm;
  v3 = this;
  this->m_flags.m_capacityAndFlags = 2147483648;
  this->m_flags.m_data = 0i64;
  this->m_flags.m_size = 0;
  v4 = (nm + 7) & 0xFFFFFFF8;
  if ( v4 > 0 )
  {
    v5 = (nm + 7) & 0xFFFFFFF8;
    if ( v4 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v5, 1);
  }
  v6 = v4 - v3->m_flags.m_size;
  if ( v6 > 0 )
    memset(&v3->m_flags.m_data[v3->m_flags.m_size], 0, v6);
  v3->m_flags.m_size = v4;
  v7 = v3->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < v2 )
  {
    v8 = 2 * v7;
    v9 = v2;
    if ( v2 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v3, v9, 1);
  }
  v3->m_flags.m_size = v2;
}

// File Line: 389
// RVA: 0xE516B0
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::fromBytes(Writer::MemberWriteFlags *this, const char *inb, int numBytes)
{
  int v3; // ebp
  __int64 v4; // r14
  int v5; // eax
  const char *v6; // r15
  signed int v7; // esi
  Writer::MemberWriteFlags *v8; // rbx
  int v9; // eax
  int v10; // er9
  __int64 v11; // rcx
  int v12; // eax
  char *v13; // rdi
  unsigned __int64 v14; // rcx
  __int64 v15; // r8
  __int64 v16; // rdi
  unsigned __int8 v17; // dl
  unsigned __int8 v18; // cl
  char v19; // cl
  char v20; // cl
  char v21; // cl
  char v22; // cl
  char v23; // cl
  int v24; // eax
  int v25; // eax
  int v26; // er9
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = this->m_flags.m_size;
  v4 = numBytes;
  v5 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = inb;
  v7 = (v3 + 7) & 0xFFFFFFF8;
  v8 = this;
  if ( v5 < v7 )
  {
    v9 = 2 * v5;
    v10 = (v3 + 7) & 0xFFFFFFF8;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v10, 1);
  }
  v11 = v8->m_flags.m_size;
  v12 = v7 - v11;
  v13 = &v8->m_flags.m_data[v11];
  v14 = v7 - (signed int)v11;
  if ( v12 > 0 )
    memset(v13, 0, v14);
  v15 = 0i64;
  v8->m_flags.m_size = v7;
  v16 = 0i64;
  if ( (signed int)v4 > 0 )
  {
    do
    {
      v17 = v6[v15++];
      v18 = v17;
      v17 >>= 1;
      v16 += 8i64;
      v8->m_flags.m_data[v16 - 8] = v18 & 1;
      v19 = v17 & 1;
      v17 >>= 1;
      v8->m_flags.m_data[v16 - 7] = v19;
      v20 = v17 & 1;
      v17 >>= 1;
      v8->m_flags.m_data[v16 - 6] = v20;
      v21 = v17 & 1;
      v17 >>= 1;
      v8->m_flags.m_data[v16 - 5] = v21;
      v22 = v17 & 1;
      v17 >>= 1;
      v8->m_flags.m_data[v16 - 4] = v22;
      v23 = v17 & 1;
      v17 >>= 1;
      v8->m_flags.m_data[v16 - 3] = v23;
      v8->m_flags.m_data[v16 - 2] = v17 & 1;
      v8->m_flags.m_data[v16 - 1] = (v17 >> 1) & 1;
    }
    while ( v15 < v4 );
  }
  v24 = v8->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v24 < v3 )
  {
    v25 = 2 * v24;
    v26 = v3;
    if ( v3 < v25 )
      v26 = v25;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v8, v26, 1);
  }
  v8->m_flags.m_size = v3;
}

// File Line: 409
// RVA: 0xE52640
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::toBytes(Writer::MemberWriteFlags *this, char *out)
{
  int v2; // ebp
  char *v3; // r14
  int v4; // eax
  Writer::MemberWriteFlags *v5; // rbx
  signed int v6; // esi
  int v7; // eax
  int v8; // er9
  __int64 v9; // rcx
  int v10; // eax
  char *v11; // rdi
  unsigned __int64 v12; // rcx
  int v13; // edx
  __int64 i; // rdi
  char v15; // cl
  int v16; // eax
  int v17; // eax
  int v18; // er9
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = this->m_flags.m_size;
  v3 = out;
  v4 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  v6 = (v2 + 7) & 0xFFFFFFF8;
  if ( v4 < v6 )
  {
    v7 = 2 * v4;
    v8 = (v2 + 7) & 0xFFFFFFF8;
    if ( v6 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, this, v8, 1);
  }
  v9 = v5->m_flags.m_size;
  v10 = v6 - v9;
  v11 = &v5->m_flags.m_data[v9];
  v12 = v6 - (signed int)v9;
  if ( v10 > 0 )
    memset(v11, 0, v12);
  v13 = 0;
  v5->m_flags.m_size = v6;
  for ( i = 0i64;
        v13 < v5->m_flags.m_size;
        *(v3 - 1) = v5->m_flags.m_data[i - 8] | 2
                                              * (v5->m_flags.m_data[i - 7] | 2
                                                                           * (v5->m_flags.m_data[i - 6] | 2 * (v5->m_flags.m_data[i - 5] | 2 * (v5->m_flags.m_data[i - 4] | 2 * (v5->m_flags.m_data[i - 3] | 2 * (v5->m_flags.m_data[i - 2] | 2 * v15)))))) )
  {
    v13 += 8;
    ++v3;
    v15 = v5->m_flags.m_data[i + 7];
    i += 8i64;
  }
  v16 = v5->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 < v2 )
  {
    v17 = 2 * v16;
    v18 = v2;
    if ( v2 < v17 )
      v18 = v17;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v18, 1);
  }
  v5->m_flags.m_size = v2;
}

// File Line: 465
// RVA: 0xE51A20
void __fastcall `anonymous namespace::Writer::scanArray(Writer *this, hkDataArray *arrToScan, hkArray<Writer::TodoItem,hkContainerTempAllocator> *objsTodo, unsigned int immediate)
{
  Writer *v4; // rdi
  hkArray<Writer::TodoItem,hkContainerTempAllocator> *v5; // rsi
  hkDataArray *v6; // rbx
  int v7; // eax
  int v8; // eax
  signed int v9; // ebx
  signed int i; // edi
  hkDataArrayImpl *v11; // rax
  hkDataArrayImpl *v12; // rcx
  bool v13; // zf
  __int64 v14; // rax
  __int64 v15; // rbx
  __int128 *v16; // rax
  hkDataArrayImpl *v17; // rcx
  int v18; // eax
  __int64 v19; // rdx
  signed __int64 v20; // r8
  hkDataArrayImpl *v21; // rax
  hkDataArrayImpl *v22; // rax
  hkDataArrayImpl *v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rdi
  unsigned int v26; // esi
  __int64 v27; // rax
  __int64 v28; // rbx
  __int64 *v29; // rax
  __int64 v30; // rcx
  signed int *v31; // r9
  int v32; // eax
  __int64 v33; // rdx
  signed __int64 v34; // r8
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rbx
  unsigned int v38; // edi
  hkDataObjectImpl *v39; // rax
  hkDataObjectImpl *v40; // rcx
  __int64 v41; // [rsp+0h] [rbp-69h]
  unsigned int v42; // [rsp+0h] [rbp-69h]
  int v43; // [rsp+0h] [rbp-69h]
  int v44; // [rsp+4h] [rbp-65h]
  int v45; // [rsp+4h] [rbp-65h]
  hkDataArray arrToScana; // [rsp+8h] [rbp-61h]
  hkDataArray v47; // [rsp+10h] [rbp-59h]
  hkDataObject objToScan; // [rsp+18h] [rbp-51h]
  __int128 v49; // [rsp+20h] [rbp-49h]
  __int128 v50; // [rsp+30h] [rbp-39h]
  __int64 v51; // [rsp+40h] [rbp-29h]
  __int64 v52; // [rsp+48h] [rbp-21h]
  __int128 v53; // [rsp+50h] [rbp-19h]
  __int64 v54; // [rsp+60h] [rbp-9h]
  __int128 v55; // [rsp+70h] [rbp+7h]
  char v56; // [rsp+80h] [rbp+17h]
  Writer *v57; // [rsp+D0h] [rbp+67h]
  hkDataArray *v58; // [rsp+D8h] [rbp+6Fh]
  void *array; // [rsp+E0h] [rbp+77h]
  void *retaddr; // [rsp+E8h] [rbp+7Fh]

  v4 = this;
  v5 = objsTodo;
  v6 = arrToScan;
  v7 = *(_DWORD *)((__int64 (*)(void))arrToScan->m_impl->vfptr[1].__vecDelDtor)();
  if ( v7 == 6 )
  {
    ((void (*)(void))v6->m_impl->vfptr[6].__vecDelDtor)();
    `anonymous namespace::Writer::writeClass(v4, (hkDataClass *)&arrToScana);
    if ( ((signed int (*)(void))arrToScana.m_impl->vfptr[9].__vecDelDtor)() <= 0 )
      return;
    while ( 1 )
    {
      v51 = 0i64;
      v52 = 0i64;
      v53 = 0ui64;
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64 *))arrToScana.m_impl->vfptr[10].__vecDelDtor)(
        arrToScana.m_impl,
        v42,
        &v51);
      if ( *(_DWORD *)v53 == 6 )
      {
        v36 = (__int64)v58->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)&v58->m_impl->vfptr, v51);
        v37 = v36;
        if ( v36 )
        {
          ++*(_WORD *)(v36 + 10);
          ++*(_DWORD *)(v36 + 12);
        }
        v38 = 0;
        if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v36 + 40i64))(v36) > 0 )
        {
          do
          {
            v39 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v37 + 168i64))(v37, v38);
            objToScan.m_impl = v39;
            if ( v39 )
            {
              ++v39->m_externalCount;
              ++v39->m_count;
            }
            `anonymous namespace::Writer::scanObjectForPointers(v57, &objToScan, v5, 1u);
            v40 = objToScan.m_impl;
            if ( objToScan.m_impl )
            {
              --objToScan.m_impl->m_externalCount;
              v13 = v40->m_count-- == 1;
              if ( v13 )
                v40->vfptr->__vecDelDtor((hkDataRefCounted *)&v40->vfptr, 1u);
            }
            ++v38;
          }
          while ( (signed int)v38 < v45 );
        }
        --*(_WORD *)(v37 + 10);
        v13 = (*(_DWORD *)(v37 + 12))-- == 1;
        if ( v13 )
          (**(void (__fastcall ***)(__int64, signed __int64))v37)(v37, 1i64);
      }
      else
      {
        if ( *(_DWORD *)v53 != 7 )
        {
          if ( *(_DWORD *)v53 == 8 )
          {
            v22 = (hkDataArrayImpl *)v58->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)&v58->m_impl->vfptr, v51);
            v47.m_impl = v22;
            if ( v22 )
            {
              ++v22->m_externalCount;
              ++v22->m_count;
            }
            `anonymous namespace::Writer::scanArray(v4, &v47, v5, (unsigned int)retaddr);
            v23 = v47.m_impl;
            if ( v47.m_impl )
            {
              --v47.m_impl->m_externalCount;
              v13 = v23->m_count-- == 1;
              if ( v13 )
                v23->vfptr->__vecDelDtor((hkDataRefCounted *)&v23->vfptr, 1u);
            }
          }
          goto LABEL_50;
        }
        v24 = (__int64)v58->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)&v58->m_impl->vfptr, v51);
        v25 = v24;
        if ( v24 )
        {
          ++*(_WORD *)(v24 + 10);
          ++*(_DWORD *)(v24 + 12);
        }
        v26 = 0;
        if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v24 + 40i64))(v24) > 0 )
        {
          v49 = 0ui64;
          do
          {
            v27 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v25 + 168i64))(v25, v26);
            v28 = v27;
            if ( v27 )
            {
              ++*(_WORD *)(v27 + 10);
              ++*(_DWORD *)(v27 + 12);
              v29 = (__int64 *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v27 + 8i64))(v27, &v56);
            }
            else
            {
              _mm_store_si128((__m128i *)&v55, (__m128i)0i64);
              v29 = (__int64 *)&v55;
            }
            v30 = *v29;
            v31 = (signed int *)array;
            *(_QWORD *)&v50 = v29[1];
            v32 = *((_DWORD *)array + 3);
            v54 = v30;
            if ( *((_DWORD *)array + 2) == (v32 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, array, 24);
              v31 = (signed int *)array;
            }
            v33 = v31[2];
            v34 = *(_QWORD *)v31 + 24 * v33;
            v31[2] = v33 + 1;
            v35 = v54;
            *(_DWORD *)(v34 + 16) = 0;
            *(_QWORD *)v34 = v35;
            *(_QWORD *)(v34 + 8) = v50;
            if ( v28 )
            {
              --*(_WORD *)(v28 + 10);
              v13 = (*(_DWORD *)(v28 + 12))-- == 1;
              if ( v13 )
                (**(void (__fastcall ***)(__int64, signed __int64))v28)(v28, 1i64);
            }
            ++v26;
          }
          while ( (signed int)v26 < v44 );
        }
        --*(_WORD *)(v25 + 10);
        v13 = (*(_DWORD *)(v25 + 12))-- == 1;
        if ( v13 )
          (**(void (__fastcall ***)(__int64, signed __int64))v25)(v25, 1i64);
        v5 = (hkArray<Writer::TodoItem,hkContainerTempAllocator> *)array;
      }
      v4 = v57;
LABEL_50:
      if ( v43 + 1 >= ((signed int (*)(void))arrToScana.m_impl->vfptr[9].__vecDelDtor)() )
        return;
    }
  }
  if ( v7 == 7 )
  {
    if ( ((signed int (*)(void))v6->m_impl->vfptr[5].__vecDelDtor)() > 0 )
    {
      v50 = 0ui64;
      do
      {
        v14 = ((__int64 (*)(void))v6->m_impl->vfptr[21].__vecDelDtor)();
        v15 = v14;
        if ( v14 )
        {
          ++*(_WORD *)(v14 + 10);
          ++*(_DWORD *)(v14 + 12);
          v16 = (__int128 *)(*(__int64 (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v14 + 8i64))(v14, &v55);
        }
        else
        {
          _mm_store_si128((__m128i *)&v49, (__m128i)0i64);
          v16 = &v49;
        }
        v17 = *(hkDataArrayImpl **)v16;
        arrToScana.m_impl = (hkDataArrayImpl *)*((_QWORD *)v16 + 1);
        v18 = v5->m_capacityAndFlags;
        v47.m_impl = v17;
        if ( v5->m_size == (v18 & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
        v19 = v5->m_size;
        v20 = (signed __int64)&v5->m_data[v19];
        v5->m_size = v19 + 1;
        v21 = v47.m_impl;
        *(_DWORD *)(v20 + 16) = 0;
        *(_QWORD *)v20 = v21;
        *(hkDataArray *)(v20 + 8) = arrToScana;
        if ( v15 )
        {
          --*(_WORD *)(v15 + 10);
          v13 = (*(_DWORD *)(v15 + 12))-- == 1;
          if ( v13 )
            (**(void (__fastcall ***)(__int64, signed __int64))v15)(v15, 1i64);
        }
        v6 = v58;
      }
      while ( (signed int)v41 + 1 < SHIDWORD(v41) );
    }
  }
  else if ( (unsigned int)(v7 - 8) <= 1 )
  {
    v8 = ((__int64 (*)(void))v6->m_impl->vfptr[5].__vecDelDtor)();
    v9 = 0;
    for ( i = v8; v9 < i; ++v9 )
    {
      v11 = (hkDataArrayImpl *)v58->m_impl->vfptr[23].__vecDelDtor((hkDataRefCounted *)v58->m_impl, v9);
      arrToScana.m_impl = v11;
      if ( v11 )
      {
        ++v11->m_externalCount;
        ++v11->m_count;
      }
      `anonymous namespace::Writer::scanArray(v57, &arrToScana, v5, (unsigned int)retaddr);
      v12 = arrToScana.m_impl;
      if ( arrToScana.m_impl )
      {
        --arrToScana.m_impl->m_externalCount;
        v13 = v12->m_count-- == 1;
        if ( v13 )
          v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
      }
    }
  }
}

// File Line: 555
// RVA: 0xE51ED0
void __fastcall `anonymous namespace::Writer::scanObjectForPointers(Writer *this, hkDataObject *objToScan, hkArray<Writer::TodoItem,hkContainerTempAllocator> *objsTodo, unsigned int immediate)
{
  unsigned int v4; // esi
  hkArray<Writer::TodoItem,hkContainerTempAllocator> *v5; // rdi
  hkDataObject *v6; // rbx
  hkTypeManager::Type *v7; // rbx
  hkTypeManager::SubType v8; // eax
  hkDataArrayImpl *v9; // rax
  hkDataArrayImpl *v10; // rbx
  bool v11; // zf
  hkDataObjectImpl *v12; // rax
  hkDataObjectImpl *v13; // rbx
  __int128 *v14; // rax
  __int64 v15; // rsi
  __int64 v16; // rdx
  signed __int64 v17; // r8
  hkDataArrayImpl *v18; // rax
  hkDataObjectImpl *v19; // rax
  __int128 *v20; // rax
  __int64 v21; // rdx
  hkDataObjectImpl *v22; // rcx
  unsigned int i; // [rsp+20h] [rbp-49h]
  hkDataArray arrToScan; // [rsp+28h] [rbp-41h]
  hkDataObject_Value v25; // [rsp+30h] [rbp-39h]
  hkDataObject objToScana; // [rsp+40h] [rbp-29h]
  __m128i v27; // [rsp+50h] [rbp-19h]
  __m128i v28; // [rsp+60h] [rbp-9h]
  __int128 v29; // [rsp+70h] [rbp+7h]
  __int128 v30; // [rsp+80h] [rbp+17h]
  char v31; // [rsp+90h] [rbp+27h]
  char v32; // [rsp+A0h] [rbp+37h]
  Writer *v33; // [rsp+D0h] [rbp+67h]
  hkDataObject *v34; // [rsp+D8h] [rbp+6Fh]
  unsigned int v35; // [rsp+E8h] [rbp+7Fh]

  v35 = immediate;
  v34 = objToScan;
  v33 = this;
  v4 = immediate;
  v5 = objsTodo;
  v6 = objToScan;
  ((void (*)(void))objToScan->m_impl->vfptr[2].__vecDelDtor)();
  for ( i = ((__int64 (*)(void))v6->m_impl->vfptr[5].__vecDelDtor)();
        v6->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)v6->m_impl, i);
        i = (__int64)v34->m_impl->vfptr[7].__vecDelDtor((hkDataRefCounted *)v34->m_impl, i) )
  {
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v6->m_impl->vfptr[9].__vecDelDtor)(
      v6->m_impl,
      &v25,
      i);
    v7 = hkDataObject_Value::getType(&v25);
    if ( hkTypeManager::Type::findTerminal(v7)->m_subType == 6 )
    {
      v8 = v7->m_subType;
      if ( v7->m_subType == 6 )
      {
        v19 = (hkDataObjectImpl *)v25.m_impl->vfptr[13].__vecDelDtor(
                                    (hkDataRefCounted *)v25.m_impl,
                                    (unsigned int)v25.m_handle);
        if ( v4 )
        {
          objToScana.m_impl = v19;
          if ( v19 )
          {
            ++v19->m_externalCount;
            ++v19->m_count;
          }
          `anonymous namespace::Writer::scanObjectForPointers(v33, &objToScana, v5, 1u);
          v22 = objToScana.m_impl;
          if ( objToScana.m_impl )
          {
            --objToScana.m_impl->m_externalCount;
            v11 = v22->m_count-- == 1;
            if ( v11 )
              v22->vfptr->__vecDelDtor((hkDataRefCounted *)&v22->vfptr, 1u);
          }
          goto LABEL_23;
        }
        v13 = v19;
        if ( v19 )
        {
          ++v19->m_externalCount;
          ++v19->m_count;
        }
        v28 = 0ui64;
        if ( v19 )
        {
          v20 = (__int128 *)v19->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v19->vfptr, (unsigned int)&v32);
        }
        else
        {
          v20 = &v29;
          _mm_store_si128((__m128i *)&v29, v28);
        }
        v15 = *(_QWORD *)v20;
        arrToScan.m_impl = (hkDataArrayImpl *)*((_QWORD *)v20 + 1);
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
        v21 = v5->m_size;
        v17 = (signed __int64)&v5->m_data[v21];
        v5->m_size = v21 + 1;
        *(_DWORD *)(v17 + 16) = 1;
        goto LABEL_19;
      }
      if ( v8 == 7 )
      {
        v12 = (hkDataObjectImpl *)v25.m_impl->vfptr[13].__vecDelDtor(
                                    (hkDataRefCounted *)v25.m_impl,
                                    (unsigned int)v25.m_handle);
        v13 = v12;
        if ( v12 )
        {
          ++v12->m_externalCount;
          ++v12->m_count;
        }
        v27 = 0ui64;
        if ( v12 )
        {
          v14 = (__int128 *)v12->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v12->vfptr, (unsigned int)&v31);
        }
        else
        {
          v14 = &v30;
          _mm_store_si128((__m128i *)&v30, v27);
        }
        v15 = *(_QWORD *)v14;
        arrToScan.m_impl = (hkDataArrayImpl *)*((_QWORD *)v14 + 1);
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 24);
        v16 = v5->m_size;
        v17 = (signed __int64)&v5->m_data[v16];
        v5->m_size = v16 + 1;
        *(_DWORD *)(v17 + 16) = 0;
LABEL_19:
        v18 = arrToScan.m_impl;
        *(_QWORD *)v17 = v15;
        *(_QWORD *)(v17 + 8) = v18;
        if ( v13 )
        {
          --v13->m_externalCount;
          v11 = v13->m_count-- == 1;
          if ( v11 )
            v13->vfptr->__vecDelDtor((hkDataRefCounted *)&v13->vfptr, 1u);
        }
        v4 = v35;
        goto LABEL_23;
      }
      if ( (unsigned int)(v8 - 8) <= 1 )
      {
        v9 = (hkDataArrayImpl *)v25.m_impl->vfptr[10].__vecDelDtor(
                                  (hkDataRefCounted *)v25.m_impl,
                                  (unsigned int)v25.m_handle);
        v10 = v9;
        arrToScan.m_impl = v9;
        if ( v9 )
        {
          ++v9->m_externalCount;
          ++v9->m_count;
        }
        `anonymous namespace::Writer::scanArray(v33, &arrToScan, v5, v4);
        if ( v10 )
        {
          --v10->m_externalCount;
          v11 = v10->m_count-- == 1;
          if ( v11 )
            v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
        }
      }
    }
LABEL_23:
    v6 = v34;
  }
}

// File Line: 605
// RVA: 0xE521D0
void __fastcall `anonymous namespace::Writer::scanObjectTree(Writer *this, hkDataWorld *world, hkDataObject *topObj, unsigned int topIsStruct)
{
  hkDataObject *v4; // rbx
  hkDataWorld *v5; // r12
  Writer *v6; // rsi
  unsigned int v7; // er14
  hkDataObjectImpl *v8; // rcx
  Writer::MemberWriteFlags *v9; // rax
  char *v10; // rbx
  __int64 v11; // rdi
  int v12; // edx
  signed __int64 v13; // rcx
  _QWORD *v14; // rax
  __int64 v15; // r8
  __int64 v16; // rax
  hkDataObjectImpl *v17; // rbx
  __int128 *v18; // rax
  __int128 v19; // xmm0
  int v20; // eax
  __int64 i; // rdi
  __int64 v22; // rax
  int v23; // eax
  int v24; // edi
  __int64 v25; // rdx
  signed __int64 v26; // r14
  _QWORD *v27; // rax
  __int64 v28; // rdx
  signed int v29; // ecx
  __int64 v30; // r15
  int v31; // ecx
  int v32; // er14
  int v33; // er9
  int v34; // ecx
  bool v35; // zf
  hkDataObjectImpl *v36; // rcx
  _QWORD *array; // [rsp+30h] [rbp-C8h]
  int v38; // [rsp+38h] [rbp-C0h]
  int v39; // [rsp+3Ch] [rbp-BCh]
  Writer::MemberWriteFlags v40; // [rsp+40h] [rbp-B8h]
  hkDataClass klass; // [rsp+50h] [rbp-A8h]
  hkDataObject objToScan; // [rsp+58h] [rbp-A0h]
  __int64 v43; // [rsp+60h] [rbp-98h]
  __int64 v44; // [rsp+68h] [rbp-90h]
  __int64 v45; // [rsp+70h] [rbp-88h]
  __int128 v46; // [rsp+78h] [rbp-80h]
  hkDataObject_Value value; // [rsp+88h] [rbp-70h]
  __int128 v48; // [rsp+98h] [rbp-60h]
  char v49; // [rsp+A8h] [rbp-50h]
  char v50; // [rsp+B8h] [rbp-40h]
  char v51; // [rsp+C8h] [rbp-30h]
  hkDataObject object; // [rsp+128h] [rbp+30h]
  hkResult result; // [rsp+130h] [rbp+38h]

  v4 = topObj;
  v5 = world;
  v6 = this;
  v7 = topIsStruct;
  array = 0i64;
  v38 = 0;
  v39 = 2147483648;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 128, 24);
  v8 = v4->m_impl;
  v40.m_flags.m_data = 0i64;
  *(_QWORD *)&v40.m_flags.m_size = 0i64;
  if ( v8 )
  {
    v9 = (Writer::MemberWriteFlags *)v8->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v8->vfptr, (unsigned int)&v46);
  }
  else
  {
    v9 = &v40;
    _mm_store_si128((__m128i *)&v40, (__m128i)v40);
  }
  v10 = v9->m_flags.m_data;
  v11 = *(_QWORD *)&v9->m_flags.m_size;
  v12 = v38;
  if ( v38 == (v39 & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 24);
    v12 = v38;
  }
  v13 = 3i64 * v12;
  v14 = array;
  v38 = v12 + 1;
  array[v13] = v10;
  v14[v13 + 1] = v11;
  LODWORD(v14[v13 + 2]) = v7;
  while ( v38 )
  {
    v43 = array[3 * v38 - 3];
    v15 = array[3 * v38 - 2];
    v44 = array[3 * v38 - 2];
    v16 = array[3 * v38-- - 1];
    v45 = v16;
    if ( v43 || v15 )
    {
      ((void (__fastcall *)(hkDataWorld *, hkDataObject *, __int64 *))v5->vfptr[5].__vecDelDtor)(v5, &object, &v43);
      `anonymous namespace::Writer::ListenerCache::callListenerAndCache(&v6->m_listenerCache, &objToScan, &object);
      v17 = objToScan.m_impl;
      if ( objToScan.m_impl )
      {
        v18 = (__int128 *)objToScan.m_impl->vfptr[1].__vecDelDtor(
                            (hkDataRefCounted *)objToScan.m_impl,
                            (unsigned int)&v51);
        v19 = *v18;
        v48 = *v18;
        if ( (unsigned int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
                             (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v6->m_detailIndexFromObject,
                             (hkDataObject_Handle *)&v48,
                             -1) == -1 )
        {
          klass.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *))v17->vfptr[2].__vecDelDtor)(v17);
          `anonymous namespace::Writer::writeClass(v6, &klass);
          v20 = ((__int64 (*)(void))klass.m_impl->vfptr[9].__vecDelDtor)();
          `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v40, v20);
          for ( i = ((unsigned int (__fastcall *)(hkDataObjectImpl *))v17->vfptr[5].__vecDelDtor)(v17);
                v17->vfptr[6].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, i);
                i = (unsigned int)v17->vfptr[7].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, i) )
          {
            ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v17->vfptr[9].__vecDelDtor)(
              v17,
              &value,
              (unsigned int)i);
            if ( (unsigned int)`anonymous namespace::Writer::worthWriting<hkDataObject_Value>(
                                 v6,
                                 &value,
                                 *(float *)&v19) )
            {
              v22 = (__int64)v17->vfptr[8].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, i);
              v23 = (__int64)klass.m_impl->vfptr[11].__vecDelDtor((hkDataRefCounted *)klass.m_impl, v22);
              v40.m_flags.m_data[v23] = 1;
            }
          }
          v24 = v6->m_detailIndexFromObject.m_numElems & 0x7FFFFFFF;
          v46 = *(_OWORD *)v17->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, (unsigned int)&v49);
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
            (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v6->m_detailIndexFromObject,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            (hkDataObject_Handle *)&v46,
            v24);
          if ( v6->m_details.m_size == (v6->m_details.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v6->m_details, 24);
          v25 = v6->m_details.m_size;
          v26 = (signed __int64)&v6->m_details.m_data[v25];
          v6->m_details.m_size = v25 + 1;
          v27 = (_QWORD *)v17->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v17->vfptr, (unsigned int)&v50);
          v28 = v27[1];
          *(_QWORD *)v26 = *v27;
          *(_QWORD *)(v26 + 8) = v28;
          *(_DWORD *)(v26 + 16) = v6->m_bitfieldBuf.m_size;
          if ( (_DWORD)v45 )
          {
            v29 = -1;
          }
          else
          {
            v29 = v6->m_currentRememberTag;
            v6->m_currentRememberTag = v29 + 1;
          }
          *(_DWORD *)(v26 + 20) = v29;
          v30 = v6->m_bitfieldBuf.m_size;
          v31 = v6->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFF;
          v32 = (signed int)((v40.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
          v33 = v30 + v32;
          if ( v31 >= (signed int)v30 + v32 )
          {
            result.m_enum = 0;
          }
          else
          {
            v34 = 2 * v31;
            if ( v33 < v34 )
              v33 = v34;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
              &v6->m_bitfieldBuf,
              v33,
              1);
          }
          v6->m_bitfieldBuf.m_size += v32;
          `anonymous namespace::Writer::MemberWriteFlags::toBytes(&v40, &v6->m_bitfieldBuf.m_data[v30]);
          `anonymous namespace::Writer::scanObjectForPointers(
            v6,
            &objToScan,
            (hkArray<Writer::TodoItem,hkContainerTempAllocator> *)&array,
            0);
          v40.m_flags.m_size = 0;
          if ( v40.m_flags.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              v40.m_flags.m_data,
              v40.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
          v40.m_flags.m_data = 0i64;
          v40.m_flags.m_capacityAndFlags = 2147483648;
        }
        --v17->m_externalCount;
        v35 = v17->m_count-- == 1;
        if ( v35 )
          v17->vfptr->__vecDelDtor((hkDataRefCounted *)&v17->vfptr, 1u);
      }
      v36 = object.m_impl;
      if ( object.m_impl )
      {
        --object.m_impl->m_externalCount;
        v35 = v36->m_count-- == 1;
        if ( v35 )
          v36->vfptr->__vecDelDtor((hkDataRefCounted *)&v36->vfptr, 1u);
      }
    }
  }
  v38 = 0;
  if ( v39 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      24 * (v39 & 0x3FFFFFFF));
}

// File Line: 669
// RVA: 0xE50AE0
void __usercall `anonymous namespace::Writer::_writeArrayItems(Writer *this@<rcx>, hkDataArray *arr@<rdx>, int asize@<r8d>, float a4@<xmm0>)
{
  Writer *v4; // rbx
  int v5; // esi
  hkDataArray *v6; // rdi
  __int64 v7; // rax
  int v8; // er9
  int i; // edi
  hkDataArrayImpl *v10; // rax
  int v11; // eax
  hkDataArrayImpl *v12; // rcx
  bool v13; // zf
  int j; // edi
  char v15; // al
  int l; // edi
  int v17; // eax
  int m; // edi
  __int64 v19; // rax
  int k; // edi
  int v21; // edi
  signed int v22; // eax
  __int64 v23; // rax
  const float *v24; // rax
  __int64 v25; // rax
  unsigned int v26; // eax
  __int64 v27; // rdx
  int v28; // er8
  _QWORD *v29; // rcx
  unsigned int v30; // eax
  _QWORD *v31; // rax
  __int64 v32; // rax
  signed __int64 v33; // rcx
  __int64 v34; // r8
  __int64 v35; // rax
  hkDataArrayImpl *v36; // rbx
  int v37; // esi
  char *v38; // rcx
  int v39; // eax
  int v40; // er9
  unsigned __int64 v41; // rcx
  __int64 v42; // rdx
  hkDataArrayImpl *v43; // rdi
  hkDataArrayImpl *v44; // rax
  hkDataArrayImpl *v45; // rcx
  int ii; // edi
  hkDataArrayImpl *v47; // rax
  hkDataArrayImpl *v48; // rbx
  int n; // edi
  const char *v50; // rax
  int jj; // edi
  hkDataArrayImpl *v52; // rax
  __int64 v53; // rbx
  hkDataArrayImpl *v54; // rcx
  int nm; // [rsp+30h] [rbp-29h]
  int nma; // [rsp+30h] [rbp-29h]
  __int64 buf2; // [rsp+38h] [rbp-21h]
  __int64 v58; // [rsp+40h] [rbp-19h]
  char *v59; // [rsp+48h] [rbp-11h]
  int v60; // [rsp+50h] [rbp-9h]
  int v61; // [rsp+54h] [rbp-5h]
  char *array; // [rsp+58h] [rbp-1h]
  int nbytes; // [rsp+60h] [rbp+7h]
  int v64; // [rsp+64h] [rbp+Bh]
  Writer::MemberWriteFlags v65; // [rsp+68h] [rbp+Fh]
  hkDataArray_Value value; // [rsp+78h] [rbp+1Fh]
  Writer *v67; // [rsp+C0h] [rbp+67h]
  hkDataArray v68; // [rsp+C8h] [rbp+6Fh]
  int v69; // [rsp+D0h] [rbp+77h]
  hkDataArray arra; // [rsp+D8h] [rbp+7Fh]

  v69 = asize;
  v68.m_impl = (hkDataArrayImpl *)arr;
  v67 = this;
  v4 = this;
  v5 = asize;
  v6 = arr;
  v7 = ((__int64 (*)(void))arr->m_impl->vfptr[1].__vecDelDtor)();
  v8 = *(_DWORD *)v7;
  if ( *(_DWORD *)v7 == 9 && (**(_DWORD **)(v7 + 8) != 3 || (*(_DWORD *)(v7 + 16) - 4) & 0xFFFFFFF3) )
  {
    for ( i = 0; i < v5; ++i )
    {
      v10 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor
                                + 23))(
                                 v68.m_impl->vfptr,
                                 (unsigned int)i);
      arra.m_impl = v10;
      if ( v10 )
      {
        ++v10->m_externalCount;
        ++v10->m_count;
        v10 = arra.m_impl;
      }
      v11 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
      `anonymous namespace::Writer::_writeArrayItems(v4, &arra, v11);
      v12 = arra.m_impl;
      if ( arra.m_impl )
      {
        --arra.m_impl->m_externalCount;
        v13 = v12->m_count-- == 1;
        if ( v13 )
          v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
      }
    }
  }
  else
  {
    switch ( v8 )
    {
      case 2:
        for ( j = 0; j < v5; ++j )
        {
          v15 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor + 17))(
                  v68.m_impl->vfptr,
                  (unsigned int)j);
          hkOArchive::write8u(&v4->m_oa, v15);
        }
        break;
      case 3:
        for ( k = 0; k < v5; ++k )
        {
          (*((void (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor + 15))(
            v68.m_impl->vfptr,
            (unsigned int)k);
          hkOArchive::writeFloat32(&v4->m_oa, a4);
        }
        break;
      case 4:
        if ( (unsigned int)v6->m_impl->vfptr[9].__vecDelDtor((hkDataRefCounted *)&v6->m_impl->vfptr, v7) == 4 )
        {
          hkOArchive::write8u(&v4->m_oa, 8);
          for ( l = 0; l < v5; ++l )
          {
            v17 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor + 17))(
                    v68.m_impl->vfptr,
                    (unsigned int)l);
            `anonymous namespace::Writer::writeInt(v4, v17);
          }
        }
        else
        {
          hkOArchive::write8u(&v4->m_oa, 16);
          for ( m = 0; m < v5; ++m )
          {
            v19 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor + 19))(
                    v68.m_impl->vfptr,
                    (unsigned int)m);
            `anonymous namespace::Writer::writeInt(v4, v19);
          }
        }
        break;
      case 5:
        for ( n = 0; n < v5; ++n )
        {
          v50 = (const char *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor
                               + 13))(
                                v68.m_impl->vfptr,
                                (unsigned int)n);
          `anonymous namespace::Writer::writeString(v4, v50);
        }
        break;
      case 6:
        v25 = (__int64)v6->m_impl->vfptr[6].__vecDelDtor((hkDataRefCounted *)&v6->m_impl->vfptr, v7);
        v26 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v25 + 72i64))(v25);
        v61 = 2147483648;
        v59 = 0i64;
        v60 = 0;
        LODWORD(v27) = v26;
        nma = v26;
        v28 = v26;
        if ( v26 )
        {
          LODWORD(arra.m_impl) = 32 * v26;
          v29 = (_QWORD *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, hkDataArray *, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                            &hkContainerTempAllocator::s_alloc,
                            &arra,
                            v26);
          LODWORD(v27) = nma;
          v28 = SLODWORD(arra.m_impl) / 32;
        }
        else
        {
          v29 = 0i64;
        }
        v30 = 2147483648;
        v60 = v27;
        v27 = (signed int)v27;
        if ( v28 )
          v30 = v28;
        v59 = (char *)v29;
        v61 = v30;
        v58 = v27;
        if ( v27 > 0 )
        {
          v31 = v29 + 2;
          do
          {
            if ( v31 != (_QWORD *)16 )
            {
              *(v31 - 2) = 0i64;
              *(v31 - 1) = 0i64;
              *v31 = 0i64;
              v31[1] = 0i64;
            }
            v31 += 4;
            --v27;
          }
          while ( v27 );
        }
        v32 = (*((__int64 (**)(void))v68.m_impl->vfptr->__vecDelDtor + 6))();
        (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v32 + 96i64))(v32, &v59);
        `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v65, nma);
        arra.m_impl = 0i64;
        if ( v58 > 0 )
        {
          v33 = v58;
          v34 = 0i64;
          buf2 = 0i64;
          do
          {
            if ( **(_DWORD **)&v59[v34 + 16] != 1 )
            {
              v35 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor + 10))(
                      v68.m_impl->vfptr,
                      *(_QWORD *)&v59[v34]);
              v36 = (hkDataArrayImpl *)v35;
              if ( v35 )
              {
                ++*(_WORD *)(v35 + 10);
                ++*(_DWORD *)(v35 + 12);
              }
              v37 = 0;
              if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v35 + 40i64))(v35) > 0 )
              {
                while ( 1 )
                {
                  value.m_impl = v36;
                  value.m_index = v37;
                  if ( (unsigned int)`anonymous namespace::Writer::worthWriting<hkDataArray_Value>(v67, &value, a4) )
                    break;
                  if ( ++v37 >= ((signed int (__fastcall *)(hkDataArrayImpl *))v36->vfptr[5].__vecDelDtor)(v36) )
                    goto LABEL_59;
                }
                v65.m_flags.m_data[(unsigned __int64)arra.m_impl] = 1;
              }
LABEL_59:
              --v36->m_externalCount;
              v13 = v36->m_count-- == 1;
              if ( v13 )
                v36->vfptr->__vecDelDtor((hkDataRefCounted *)&v36->vfptr, 1u);
              v33 = v58;
              v34 = buf2;
            }
            v34 += 32i64;
            buf2 = v34;
            ++arra.m_impl;
          }
          while ( (signed __int64)arra.m_impl < v33 );
          v5 = v69;
          v4 = v67;
        }
        v38 = 0i64;
        nbytes = 0;
        array = 0i64;
        v64 = 2147483648;
        v39 = (signed int)((v65.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
        LODWORD(arra.m_impl) = v39;
        if ( v39 > 0 )
        {
          v40 = (signed int)((v65.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
          if ( v39 < 0 )
            v40 = 0;
          hkArrayUtil::_reserve(
            (hkResult *)&buf2,
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
            &array,
            v40,
            1);
          v38 = array;
          v39 = (int)arra.m_impl;
        }
        nbytes = v39;
        `anonymous namespace::Writer::MemberWriteFlags::toBytes(&v65, v38);
        hkOArchive::writeRaw(&v4->m_oa, array, (unsigned int)nbytes);
        nbytes = 0;
        if ( v64 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            v64 & 0x3FFFFFFF);
        v41 = 0i64;
        arra.m_impl = 0i64;
        if ( v58 > 0 )
        {
          v42 = 0i64;
          v43 = v68.m_impl;
          buf2 = 0i64;
          do
          {
            if ( v65.m_flags.m_data[v41] )
            {
              v44 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v43->vfptr->__vecDelDtor
                                        + 10))(
                                         v43->vfptr,
                                         *(_QWORD *)&v59[v42]);
              v68.m_impl = v44;
              if ( v44 )
              {
                ++v44->m_externalCount;
                ++v44->m_count;
              }
              `anonymous namespace::Writer::_writeArrayItems(v4, &v68, v5);
              v45 = v68.m_impl;
              if ( v68.m_impl )
              {
                --v68.m_impl->m_externalCount;
                v13 = v45->m_count-- == 1;
                if ( v13 )
                  v45->vfptr->__vecDelDtor((hkDataRefCounted *)&v45->vfptr, 1u);
              }
            }
            buf2 += 32i64;
            v42 = buf2;
            v41 = (unsigned __int64)++arra.m_impl;
          }
          while ( (signed __int64)arra.m_impl < v58 );
        }
        v65.m_flags.m_size = 0;
        if ( v65.m_flags.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v65.m_flags.m_data,
            v65.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
        v65.m_flags.m_data = 0i64;
        v65.m_flags.m_capacityAndFlags = 2147483648;
        v60 = 0;
        if ( v61 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v59,
            32 * v61);
        break;
      case 7:
        for ( ii = 0; ii < v5; ++ii )
        {
          v47 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor
                                    + 21))(
                                     v68.m_impl->vfptr,
                                     (unsigned int)ii);
          v48 = v47;
          arra.m_impl = v47;
          if ( v47 )
          {
            ++v47->m_externalCount;
            ++v47->m_count;
          }
          `anonymous namespace::Writer::writeObjectReference(v67, (hkDataObject *)&arra);
          if ( v48 )
          {
            --v48->m_externalCount;
            v13 = v48->m_count-- == 1;
            if ( v13 )
              v48->vfptr->__vecDelDtor((hkDataRefCounted *)&v48->vfptr, 1u);
          }
        }
        break;
      case 8:
        for ( jj = 0; jj < v5; ++jj )
        {
          v52 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor
                                    + 23))(
                                     v68.m_impl->vfptr,
                                     (unsigned int)jj);
          arra.m_impl = v52;
          if ( v52 )
          {
            ++v52->m_externalCount;
            ++v52->m_count;
            v52 = arra.m_impl;
          }
          v53 = ((signed int (__fastcall *)(hkDataArrayImpl *))v52->vfptr[5].__vecDelDtor)(v52);
          `anonymous namespace::Writer::writeInt(v67, v53);
          `anonymous namespace::Writer::_writeArrayItems(v67, &arra, v53);
          v54 = arra.m_impl;
          if ( arra.m_impl )
          {
            --arra.m_impl->m_externalCount;
            v13 = v54->m_count-- == 1;
            if ( v13 )
              v54->vfptr->__vecDelDtor((hkDataRefCounted *)&v54->vfptr, 1u);
          }
        }
        break;
      case 9:
        if ( v8 == 9 && **(_DWORD **)(v7 + 8) == 3 && !((*(_DWORD *)(v7 + 16) - 4) & 0xFFFFFFF3) )
        {
          v21 = 0;
          LODWORD(arra.m_impl) = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v7);
          if ( LODWORD(arra.m_impl) == 4 )
          {
            v22 = 3;
            LODWORD(arra.m_impl) = 3;
            nm = 0;
            LODWORD(buf2) = 0;
            if ( v5 > 0 )
            {
              while ( 1 )
              {
                v23 = (*((__int64 (**)(void))v68.m_impl->vfptr->__vecDelDtor + 11))();
                if ( hkString::memCmp((const void *)(v23 + 12), &buf2, 4) )
                  break;
                if ( ++nm >= v5 )
                {
                  v22 = (signed int)arra.m_impl;
                  goto LABEL_35;
                }
              }
              v22 = 4;
              LODWORD(arra.m_impl) = 4;
            }
LABEL_35:
            `anonymous namespace::Writer::writeInt(v4, v22);
          }
          if ( v5 > 0 )
          {
            do
            {
              v24 = (const float *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v68.m_impl->vfptr->__vecDelDtor
                                    + 11))(
                                     v68.m_impl->vfptr,
                                     (unsigned int)v21);
              hkOArchive::writeArrayFloat32(&v4->m_oa, v24, (int)arra.m_impl);
              ++v21;
            }
            while ( v21 < v5 );
          }
        }
        break;
      default:
        return;
    }
  }
}

// File Line: 844
// RVA: 0xE52750
void __usercall `anonymous namespace::Writer::writeBinaryValue(Writer *this@<rcx>, hkDataObject_Value *value@<rdx>, hkDataClass_MemberInfo *minfo@<r8>, float a4@<xmm0>)
{
  Writer *v4; // r14
  hkDataClass_MemberInfo *v5; // rbp
  hkDataObject_Value *v6; // rdi
  hkTypeManager::Type *v7; // rax
  hkTypeManager::SubType v8; // er10
  hkTypeManager::Type *v9; // rsi
  hkDataArrayImpl *v10; // rax
  _WORD *v11; // rbx
  int v12; // eax
  hkDataArrayImpl *v13; // rax
  hkDataArrayImpl *v14; // rbx
  __int64 v15; // r15
  hkTypeManager::Type *v16; // rcx
  hkTypeManager::Type *v17; // rbp
  __int64 v18; // rax
  _QWORD *v19; // rax
  __int64 v20; // rsi
  _QWORD *v21; // rdi
  const char *v22; // rax
  __int64 v23; // rax
  unsigned __int64 v24; // rax
  int v25; // eax
  bool v26; // zf
  char v27; // al
  __int64 v28; // rax
  unsigned int v29; // eax
  int v30; // ebx
  const float *v31; // rax
  hkDataObjectImpl *v32; // rax
  hkDataArrayImpl *v33; // rax
  hkDataArrayImpl *v34; // rcx
  const char *v35; // rax
  hkDataObject obj; // [rsp+20h] [rbp-28h]
  hkDataArray arr; // [rsp+68h] [rbp+20h]

  v4 = this;
  v5 = minfo;
  v6 = value;
  v7 = hkDataObject_Value::getType(value);
  v8 = v7->m_subType;
  v9 = v7;
  if ( v7->m_subType == 9 && (v7->m_parent->m_subType != 3 || (v7->m_extra.m_size - 4) & 0xFFFFFFF3) )
  {
    v10 = (hkDataArrayImpl *)v6->m_impl->vfptr[10].__vecDelDtor(
                               (hkDataRefCounted *)v6->m_impl,
                               (unsigned int)v6->m_handle);
    v11 = v10;
    arr.m_impl = v10;
    if ( v10 )
    {
      ++v10->m_externalCount;
      ++v10->m_count;
    }
    v12 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v10->vfptr[5].__vecDelDtor)(v10);
    `anonymous namespace::Writer::_writeArrayItems(v4, &arr, v12, a4);
LABEL_26:
    --v11[5];
    v26 = (*((_DWORD *)v11 + 3))-- == 1;
    if ( v26 )
      (**(void (__fastcall ***)(void *, signed __int64))v11)(v11, 1i64);
  }
  else if ( v8 == 8 )
  {
    v13 = (hkDataArrayImpl *)v6->m_impl->vfptr[10].__vecDelDtor(
                               (hkDataRefCounted *)v6->m_impl,
                               (unsigned int)v6->m_handle);
    v14 = v13;
    arr.m_impl = v13;
    if ( v13 )
    {
      ++v13->m_externalCount;
      ++v13->m_count;
    }
    v15 = ((signed int (__fastcall *)(hkDataArrayImpl *))v13->vfptr[5].__vecDelDtor)(v13);
    `anonymous namespace::Writer::writeInt(v4, v15);
    v16 = v5->m_type->m_parent;
    if ( v16->m_subType == 6 && !hkTypeManager::Type::getTypeName(v16) )
    {
      v17 = v9->m_parent;
      v18 = ((__int64 (*)(void))v6->m_impl->vfptr[2].__vecDelDtor)();
      v19 = (_QWORD *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 8i64))(v18);
      v20 = *v19;
      v21 = v19;
      v22 = hkTypeManager::Type::getTypeName(v17);
      v23 = (*(__int64 (__fastcall **)(_QWORD *, const char *))(v20 + 72))(v21, v22);
      v24 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v23 + 16i64))(v23);
      v25 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_doneClasses,
              v24,
              0i64);
      `anonymous namespace::Writer::writeInt(v4, v25);
    }
    `anonymous namespace::Writer::_writeArrayItems(v4, &arr, v15, a4);
    --v14->m_externalCount;
    v26 = v14->m_count-- == 1;
    if ( v26 )
      v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
  }
  else
  {
    switch ( v8 )
    {
      case 2:
        v27 = (__int64)v6->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)v6->m_impl, (unsigned int)v6->m_handle);
        hkOArchive::write8u(&v4->m_oa, v27);
        break;
      case 3:
        v6->m_impl->vfptr[15].__vecDelDtor((hkDataRefCounted *)v6->m_impl, (unsigned int)v6->m_handle);
        hkOArchive::writeFloat32(&v4->m_oa, a4);
        break;
      case 4:
        v28 = (__int64)v6->m_impl->vfptr[12].__vecDelDtor((hkDataRefCounted *)v6->m_impl, (unsigned int)v6->m_handle);
        `anonymous namespace::Writer::writeInt(v4, v28);
        break;
      case 5:
        v35 = (const char *)v6->m_impl->vfptr[11].__vecDelDtor(
                              (hkDataRefCounted *)v6->m_impl,
                              (unsigned int)v6->m_handle);
        `anonymous namespace::Writer::writeString(v4, v35);
        break;
      case 6:
        v33 = (hkDataArrayImpl *)v6->m_impl->vfptr[13].__vecDelDtor(
                                   (hkDataRefCounted *)v6->m_impl,
                                   (unsigned int)v6->m_handle);
        arr.m_impl = v33;
        if ( v33 )
        {
          ++v33->m_externalCount;
          ++v33->m_count;
        }
        `anonymous namespace::Writer::writeStructReal(v4, (hkDataObject *)&arr);
        v34 = arr.m_impl;
        if ( arr.m_impl )
        {
          --arr.m_impl->m_externalCount;
          v26 = v34->m_count-- == 1;
          if ( v26 )
            v34->vfptr->__vecDelDtor((hkDataRefCounted *)&v34->vfptr, 1u);
        }
        break;
      case 7:
        v32 = (hkDataObjectImpl *)v6->m_impl->vfptr[13].__vecDelDtor(
                                    (hkDataRefCounted *)v6->m_impl,
                                    (unsigned int)v6->m_handle);
        v11 = v32;
        obj.m_impl = v32;
        if ( v32 )
        {
          ++v32->m_externalCount;
          ++v32->m_count;
        }
        `anonymous namespace::Writer::writeObjectReference(v4, &obj);
        if ( v11 )
          goto LABEL_26;
        break;
      case 9:
        if ( v8 == 9 && v7->m_parent->m_subType == 3 && !((v7->m_extra.m_size - 4) & 0xFFFFFFF3) )
        {
          v29 = hkTypeManager::Type::getTupleSize(v7);
          v30 = v29;
          v31 = (const float *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, _QWORD))v6->m_impl->vfptr[14].__vecDelDtor)(
                                 v6->m_impl,
                                 v6->m_handle,
                                 v29);
          hkOArchive::writeArrayFloat32(&v4->m_oa, v31, v30);
        }
        break;
      default:
        return;
    }
  }
}

// File Line: 946
// RVA: 0xE52F80
void __fastcall `anonymous namespace::Writer::writeObjectReference(Writer *this, hkDataObject *obj)
{
  hkDataObject *v2; // rbx
  Writer *v3; // rdi
  int v4; // eax
  hkDataObjectImpl *v5; // rbx
  __m128i *v6; // rax
  int v7; // eax
  bool v8; // zf
  __m128i v9; // [rsp+20h] [rbp-18h]

  v2 = obj;
  v3 = this;
  if ( this->m_listenerCache.m_listener )
  {
    if ( obj->m_impl )
    {
      v9 = *(__m128i *)obj->m_impl->vfptr[1].__vecDelDtor((hkDataRefCounted *)obj->m_impl, (unsigned int)&v9);
      v4 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
             (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v3->m_listenerCache.m_indexFromHandle,
             (hkDataObject_Handle *)&v9,
             -1);
      if ( v4 != -1 )
        v2 = v3->m_listenerCache.m_cachedObjects.m_data[v4];
    }
  }
  v5 = v2->m_impl;
  if ( v5 )
  {
    ++v5->m_externalCount;
    ++v5->m_count;
  }
  v9 = 0ui64;
  if ( v5 )
  {
    v6 = (__m128i *)v5->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v5->vfptr, (unsigned int)&v9);
  }
  else
  {
    v6 = &v9;
    _mm_store_si128(&v9, v9);
  }
  v9 = *v6;
  v7 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v3->m_detailIndexFromObject,
         (hkDataObject_Handle *)&v9,
         -1);
  `anonymous namespace::Writer::writeInt(v3, v3->m_details.m_data[v7].objectRememberTag);
  if ( v5 )
  {
    --v5->m_externalCount;
    v8 = v5->m_count-- == 1;
    if ( v8 )
      v5->vfptr->__vecDelDtor((hkDataRefCounted *)&v5->vfptr, 1u);
  }
}

// File Line: 957
// RVA: 0xE52E20
void __fastcall `anonymous namespace::Writer::writeObjectReal(Writer *this, hkDataObject *obj)
{
  hkDataObject *v2; // r14
  Writer *v3; // rdi
  int v4; // eax
  hkDataObject v5; // rbx
  int v6; // esi
  __m128i *v7; // rax
  Writer::ObjectDetails *v8; // rbp
  __int64 v9; // rax
  unsigned __int64 v10; // rax
  bool v11; // zf
  __m128i v12; // [rsp+20h] [rbp-18h]

  v2 = obj;
  v3 = this;
  if ( this->m_listenerCache.m_listener
    && obj->m_impl
    && (v12 = *(__m128i *)obj->m_impl->vfptr[1].__vecDelDtor((hkDataRefCounted *)obj->m_impl, (unsigned int)&v12),
        v4 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
               (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v3->m_listenerCache.m_indexFromHandle,
               (hkDataObject_Handle *)&v12,
               -1),
        v4 != -1) )
  {
    v5.m_impl = v3->m_listenerCache.m_cachedObjects.m_data[v4]->m_impl;
  }
  else
  {
    v5.m_impl = v2->m_impl;
  }
  if ( v5.m_impl )
  {
    ++v5.m_impl->m_externalCount;
    ++v5.m_impl->m_count;
  }
  v6 = 0;
  v12 = 0ui64;
  if ( v5.m_impl )
  {
    v7 = (__m128i *)((__int64 (__fastcall *)(hkDataObject, __m128i *))v5.m_impl->vfptr[1].__vecDelDtor)(v5, &v12);
  }
  else
  {
    v7 = &v12;
    _mm_store_si128(&v12, v12);
  }
  v12 = *v7;
  v8 = &v3->m_details.m_data[(signed int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
                                           (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v3->m_detailIndexFromObject,
                                           (hkDataObject_Handle *)&v12,
                                           -1)];
  hkOArchive::write8u(&v3->m_oa, 8);
  v9 = ((__int64 (__fastcall *)(hkDataObject))v5.m_impl->vfptr[2].__vecDelDtor)(v5);
  if ( v9 )
  {
    v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_doneClasses,
           v10,
           0xFFFFFFFFFFFFFFFFui64);
  }
  `anonymous namespace::Writer::writeInt(v3, v6);
  `anonymous namespace::Writer::_writeMembersCommon(v3, v2, v8);
  --v5.m_impl->m_externalCount;
  v11 = v5.m_impl->m_count-- == 1;
  if ( v11 )
    ((void (__fastcall *)(hkDataObject, signed __int64))v5.m_impl->vfptr->__vecDelDtor)(v5, 1i64);
}

// File Line: 970
// RVA: 0xE53240
void __fastcall `anonymous namespace::Writer::writeStructReal(Writer *this, hkDataObject *obj)
{
  Writer *v2; // rdi
  hkDataObjectImpl *v3; // rcx
  hkDataObject *v4; // rbx
  __m128i *v5; // rax
  int v6; // eax
  __m128i v7; // [rsp+20h] [rbp-18h]

  v2 = this;
  v3 = obj->m_impl;
  v4 = obj;
  v7 = 0ui64;
  if ( v3 )
  {
    v5 = (__m128i *)v3->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, (unsigned int)&v7);
  }
  else
  {
    v5 = &v7;
    _mm_store_si128(&v7, v7);
  }
  v7 = *v5;
  v6 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_detailIndexFromObject,
         (hkDataObject_Handle *)&v7,
         -1);
  `anonymous namespace::Writer::_writeMembersCommon(v2, v4, &v2->m_details.m_data[v6]);
}

// File Line: 983
// RVA: 0xE51250
void __fastcall `anonymous namespace::Writer::_writeMembersCommon(Writer *this, hkDataObject *obj, Writer::ObjectDetails *details)
{
  Writer *v3; // r15
  Writer::ObjectDetails *v4; // rsi
  hkDataObject *v5; // r12
  __int64 v6; // rax
  __int64 v7; // rbx
  int v8; // eax
  __int64 v9; // r14
  char *v10; // r13
  char *v11; // rdx
  signed int v12; // esi
  int v13; // edx
  _QWORD *v14; // rcx
  unsigned int v15; // eax
  _QWORD *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rbx
  __int64 v19; // rdi
  hkDataClass_MemberInfo *v20; // rsi
  char *v21; // [rsp+20h] [rbp-30h]
  int v22; // [rsp+28h] [rbp-28h]
  int v23; // [rsp+2Ch] [rbp-24h]
  Writer::MemberWriteFlags v24; // [rsp+30h] [rbp-20h]
  hkDataObject_Value value; // [rsp+40h] [rbp-10h]
  int v26; // [rsp+80h] [rbp+30h]

  v3 = this;
  v4 = details;
  v5 = obj;
  v6 = ((__int64 (*)(void))obj->m_impl->vfptr[2].__vecDelDtor)();
  v7 = v6;
  v8 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 72i64))(v6);
  v9 = v8;
  `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v24, v8);
  v10 = &v3->m_bitfieldBuf.m_data[v4->bitfieldStartIndex];
  v11 = &v3->m_bitfieldBuf.m_data[v4->bitfieldStartIndex];
  LODWORD(v4) = (signed int)((v24.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
  hkOArchive::writeRaw(&v3->m_oa, v11, (unsigned int)v4);
  `anonymous namespace::Writer::MemberWriteFlags::fromBytes(&v24, v10, (int)v4);
  v12 = (unsigned int)v4 | 0x80000000;
  if ( v12 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v10,
      v12 & 0x3FFFFFFF);
  v13 = v9;
  v23 = 2147483648;
  v21 = 0i64;
  v22 = 0;
  if ( (_DWORD)v9 )
  {
    v26 = 32 * v9;
    v14 = (_QWORD *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                      &v26);
    v13 = v26 / 32;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 2147483648;
  v21 = (char *)v14;
  if ( v13 )
    v15 = v13;
  v22 = v9;
  v23 = v15;
  if ( v9 > 0 )
  {
    v16 = v14 + 2;
    v17 = v9;
    do
    {
      if ( v16 != (_QWORD *)16 )
      {
        *(v16 - 2) = 0i64;
        *(v16 - 1) = 0i64;
        *v16 = 0i64;
        v16[1] = 0i64;
      }
      v16 += 4;
      --v17;
    }
    while ( v17 );
  }
  (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v7 + 96i64))(v7, &v21);
  v18 = 0i64;
  if ( v9 > 0 )
  {
    v19 = 0i64;
    do
    {
      v20 = (hkDataClass_MemberInfo *)&v21[v19];
      if ( v24.m_flags.m_data[v18] )
      {
        ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))v5->m_impl->vfptr[3].__vecDelDtor)(
          v5->m_impl,
          &value,
          v20->m_name);
        `anonymous namespace::Writer::writeBinaryValue(v3, &value, v20);
      }
      ++v18;
      v19 += 32i64;
    }
    while ( v18 < v9 );
  }
  v22 = 0;
  if ( v23 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v21,
      32 * v23);
  v21 = 0i64;
  v23 = 2147483648;
  v24.m_flags.m_size = 0;
  if ( v24.m_flags.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v24.m_flags.m_data,
      v24.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 1048
// RVA: 0xE53080
hkResult *__fastcall `anonymous namespace::Writer::writeObjectTree(Writer *this, hkResult *result, hkDataObject *topObj)
{
  Writer *v3; // rdi
  hkDataObject *v4; // rbx
  hkResult *v5; // r15
  __int64 v6; // rax
  hkDataWorld *v7; // r14
  signed int v8; // esi
  signed __int64 v9; // rbx
  hkDataObjectImpl *v10; // rcx
  bool v11; // zf
  hkDataObject obj; // [rsp+40h] [rbp+8h]

  v3 = this;
  v4 = topObj;
  v5 = result;
  v6 = ((__int64 (*)(void))topObj->m_impl->vfptr[2].__vecDelDtor)();
  v7 = (hkDataWorld *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
  hkOArchive::write32(&v3->m_oa, -894431970);
  hkOArchive::write32(&v3->m_oa, -804128050);
  hkOArchive::write8u(&v3->m_oa, 2);
  hkOArchive::write8u(&v3->m_oa, 8);
  `anonymous namespace::Writer::writeString(v3, "hk_2013.2.0-r1");
  `anonymous namespace::Writer::scanObjectTree(v3, v7, v4, 0);
  v8 = 1;
  if ( v3->m_details.m_size > 1 )
  {
    v9 = 1i64;
    do
    {
      if ( v3->m_details.m_data[v9].objectRememberTag != -1 )
      {
        v7->vfptr[5].__vecDelDtor((hkBaseObject *)&v7->vfptr, (unsigned int)&obj);
        `anonymous namespace::Writer::writeObjectReal(v3, &obj);
        v10 = obj.m_impl;
        if ( obj.m_impl )
        {
          --obj.m_impl->m_externalCount;
          v11 = v10->m_count-- == 1;
          if ( v11 )
            v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < v3->m_details.m_size );
  }
  hkOArchive::write8u(&v3->m_oa, 14);
  v5->m_enum = 0;
  return v5;
}

// File Line: 1081
// RVA: 0xE50930
void __fastcall `anonymous namespace::Writer::ListenerCache::~ListenerCache(Writer::ListenerCache *this)
{
  int v1; // edi
  Writer::ListenerCache *v2; // rbx
  __int64 v3; // r14
  hkDataObject *v4; // rsi
  hkDataObjectImpl *v5; // rcx
  bool v6; // zf
  _QWORD **v7; // rax
  int v8; // er8

  v1 = 0;
  v2 = this;
  if ( this->m_cachedObjects.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_cachedObjects.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_impl;
        if ( v4->m_impl )
        {
          --v5->m_externalCount;
          v6 = v5->m_count-- == 1;
          if ( v6 )
            v5->vfptr->__vecDelDtor((hkDataRefCounted *)&v5->vfptr, 1u);
        }
        v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkDataObject *, signed __int64))(*v7[11] + 16i64))(v7[11], v4, 8i64);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_cachedObjects.m_size );
  }
  v8 = v2->m_cachedObjects.m_capacityAndFlags;
  v2->m_cachedObjects.m_size = 0;
  if ( v8 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v2->m_cachedObjects.m_data,
      8 * v8);
  v2->m_cachedObjects.m_data = 0i64;
  v2->m_cachedObjects.m_capacityAndFlags = 2147483648;
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v2->m_indexFromHandle,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
}

// File Line: 1103
// RVA: 0xE51470
hkDataObject *__fastcall `anonymous namespace::Writer::ListenerCache::callListenerAndCache(Writer::ListenerCache *this, hkDataObject *result, hkDataObject *object)
{
  hkDataObject *v3; // rsi
  hkDataObject *v4; // rbx
  Writer::ListenerCache *v5; // rdi
  __m128i *v6; // rax
  __m128i v7; // xmm6
  int v8; // eax
  _WORD *v9; // rcx
  __m128i *v10; // rax
  __int64 v11; // r15
  __int64 v12; // r14
  hkDataObjectImpl *v13; // r8
  __m128i *v14; // rax
  bool v15; // zf
  hkDataObjectImpl *v16; // rax
  int v18; // er9
  _QWORD **v19; // rax
  hkDataObject *v20; // rax
  hkDataObject *v21; // rsi
  _WORD *v22; // rcx
  __int64 v23; // r8
  hkDataObject **v24; // rdx
  _WORD *v25; // rax
  _WORD *v26; // rcx
  __m128i v27; // [rsp+20h] [rbp-30h]
  char v28; // [rsp+30h] [rbp-20h]
  _WORD *v29; // [rsp+80h] [rbp+30h]

  v3 = object;
  v4 = result;
  v5 = this;
  if ( !this->m_listener || !object->m_impl )
  {
LABEL_15:
    v16 = v3->m_impl;
    goto LABEL_16;
  }
  v6 = (__m128i *)object->m_impl->vfptr[1].__vecDelDtor((hkDataRefCounted *)object->m_impl, (unsigned int)&v27);
  v7 = *v6;
  v27 = *v6;
  v8 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v5->m_indexFromHandle,
         (hkDataObject_Handle *)&v27,
         -1);
  if ( v8 != -1 )
  {
    v16 = v5->m_cachedObjects.m_data[v8]->m_impl;
LABEL_16:
    v4->m_impl = v16;
    if ( v16 )
    {
      ++v16->m_externalCount;
      ++v16->m_count;
    }
    return v4;
  }
  ((void (__fastcall *)(hkTagfileWriter::AddDataObjectListener *, _WORD **, hkDataObject *))v5->m_listener->vfptr[1].__first_virtual_table_function__)(
    v5->m_listener,
    &v29,
    v3);
  v9 = v29;
  v27 = 0ui64;
  if ( v29 )
  {
    v10 = (__m128i *)(*(__int64 (__fastcall **)(_WORD *, char *))(*(_QWORD *)v29 + 8i64))(v29, &v28);
    v9 = v29;
  }
  else
  {
    v10 = &v27;
    _mm_store_si128(&v27, v27);
  }
  v11 = v10->m128i_i64[0];
  v12 = v10->m128i_i64[1];
  v13 = v3->m_impl;
  v27 = 0ui64;
  if ( v13 )
  {
    v14 = (__m128i *)v13->vfptr[1].__vecDelDtor((hkDataRefCounted *)&v13->vfptr, (unsigned int)&v27);
    v9 = v29;
  }
  else
  {
    v14 = &v27;
    _mm_store_si128(&v27, v27);
  }
  if ( v11 == v14->m128i_i64[0] && v12 == v14->m128i_i64[1] )
  {
    if ( v9 )
    {
      --v9[5];
      v15 = (*((_DWORD *)v9 + 3))-- == 1;
      if ( v15 )
        (**(void (__fastcall ***)(_WORD *, signed __int64))v9)(v9, 1i64);
    }
    goto LABEL_15;
  }
  v18 = v5->m_cachedObjects.m_size;
  _mm_store_si128(&v27, v7);
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&v5->m_indexFromHandle,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (hkDataObject_Handle *)&v27,
    v18);
  v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v20 = (hkDataObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 8i64);
  v21 = v20;
  if ( v20 )
  {
    v20->m_impl = (hkDataObjectImpl *)v29;
    v22 = v29;
    if ( v29 )
    {
      ++v29[5];
      ++*((_DWORD *)v22 + 3);
    }
  }
  else
  {
    v21 = 0i64;
  }
  if ( v5->m_cachedObjects.m_size == (v5->m_cachedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &v5->m_cachedObjects, 8);
  v23 = v5->m_cachedObjects.m_size;
  v24 = &v5->m_cachedObjects.m_data[v23];
  v5->m_cachedObjects.m_size = v23 + 1;
  *v24 = v21;
  v25 = v29;
  v4->m_impl = (hkDataObjectImpl *)v29;
  if ( v25 )
  {
    ++v25[5];
    ++*((_DWORD *)v25 + 3);
    v26 = v29;
    if ( v29 )
    {
      --v29[5];
      v15 = (*((_DWORD *)v26 + 3))-- == 1;
      if ( v15 )
        (**(void (__fastcall ***)(_WORD *, signed __int64))v26)(v26, 1i64);
    }
  }
  return v4;
}

// File Line: 1149
// RVA: 0xE502B0
hkResult *__fastcall hkBinaryTagfileWriter::save(hkBinaryTagfileWriter *this, hkResult *result, hkDataObject *obj, hkStreamWriter *stream, hkTagfileWriter::AddDataObjectListener *userListener, hkTagfileWriter::Options *options)
{
  hkStreamWriter *v6; // rdi
  hkDataObject *v7; // rbx
  hkResult *v8; // rsi
  Writer v10; // [rsp+20h] [rbp-C8h]
  hkResult resulta; // [rsp+F8h] [rbp+10h]

  v6 = stream;
  v7 = obj;
  v8 = result;
  `anonymous namespace::Writer::Writer(&v10, stream, userListener, options);
  `anonymous namespace::Writer::writeObjectTree(&v10, &resulta, v7);
  v6->vfptr[2].__first_virtual_table_function__((hkBaseObject *)&v6->vfptr);
  v8->m_enum = *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, hkResult *))v6->vfptr[1].__first_virtual_table_function__)(
                           v6,
                           &resulta) == 0;
  `anonymous namespace::Writer::~Writer(&v10);
  return v8;
}

