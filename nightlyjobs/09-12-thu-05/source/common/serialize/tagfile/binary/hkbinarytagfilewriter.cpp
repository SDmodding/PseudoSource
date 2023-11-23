// File Line: 109
// RVA: 0xE50710
void __fastcall `anonymous namespace::Writer::Writer(
        Writer *this,
        hkStreamWriter *sw,
        hkTagfileWriter::AddDataObjectListener *listener,
        hkTagfileWriter::Options *options)
{
  int v7; // r9d
  int v8; // r9d
  __int64 m_size; // rdx
  Writer::ObjectDetails *v10; // r8
  unsigned __int128 v11; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  hkOArchive::hkOArchive(&this->m_oa, sw, 0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_writtenStrings.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_doneClasses.m_map,
    0);
  this->m_currentRememberTag = 1;
  this->m_detailIndexFromObject.m_hashMod = -1;
  this->m_detailIndexFromObject.m_elem = 0i64;
  this->m_detailIndexFromObject.m_numElems = 0;
  this->m_bitfieldBuf.m_data = 0i64;
  this->m_bitfieldBuf.m_size = 0;
  this->m_bitfieldBuf.m_capacityAndFlags = 0x80000000;
  this->m_details.m_data = 0i64;
  this->m_details.m_size = 0;
  this->m_details.m_capacityAndFlags = 0x80000000;
  this->m_listenerCache.m_listener = listener;
  this->m_listenerCache.m_indexFromHandle.m_elem = 0i64;
  this->m_listenerCache.m_indexFromHandle.m_numElems = 0;
  this->m_listenerCache.m_indexFromHandle.m_hashMod = -1;
  this->m_listenerCache.m_cachedObjects.m_data = 0i64;
  this->m_listenerCache.m_cachedObjects.m_size = 0;
  this->m_listenerCache.m_cachedObjects.m_capacityAndFlags = 0x80000000;
  this->m_log = 0i64;
  this->m_writeSerializeIgnored.m_bool = options->m_writeSerializeIgnored.m_bool;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_doneClasses.m_map,
    &customCaption,
    0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &this->m_writtenStrings.m_map,
    &customCaption,
    0i64);
  v11 = 0ui64;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
    &hkContainerHeapAllocator::s_alloc,
    (hkDataObject_Handle *)&v11,
    0);
  v7 = 512;
  if ( (this->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFFu) < 0x200 )
  {
    if ( 2 * (this->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFF) > 512 )
      v7 = 2 * (this->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&this->m_bitfieldBuf.m_data,
      v7,
      1);
  }
  v8 = 128;
  if ( (this->m_details.m_capacityAndFlags & 0x3FFFFFFFu) < 0x80 )
  {
    if ( 2 * (this->m_details.m_capacityAndFlags & 0x3FFFFFFF) > 128 )
      v8 = 2 * (this->m_details.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_details.m_data, v8, 24);
  }
  if ( this->m_details.m_size == (this->m_details.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_details.m_data, 24);
  m_size = this->m_details.m_size;
  v10 = &this->m_details.m_data[m_size];
  this->m_details.m_size = m_size + 1;
  v10->handle.p0 = 0i64;
  v10->handle.p1 = 0i64;
  v10->objectRememberTag = 0;
  v10->bitfieldStartIndex = -1;
}

// File Line: 124
// RVA: 0xE50A10
void __fastcall `anonymous namespace::Writer::~Writer(Writer *this)
{
  int m_capacityAndFlags; // eax
  int v3; // r8d

  `anonymous namespace::Writer::ListenerCache::~ListenerCache(&this->m_listenerCache);
  m_capacityAndFlags = this->m_details.m_capacityAndFlags;
  this->m_details.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_details.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_details.m_data = 0i64;
  this->m_details.m_capacityAndFlags = 0x80000000;
  v3 = this->m_bitfieldBuf.m_capacityAndFlags;
  this->m_bitfieldBuf.m_size = 0;
  if ( v3 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_bitfieldBuf.m_data,
      v3 & 0x3FFFFFFF);
  this->m_bitfieldBuf.m_data = 0i64;
  this->m_bitfieldBuf.m_capacityAndFlags = 0x80000000;
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
    &hkContainerHeapAllocator::s_alloc);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_doneClasses.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_writtenStrings.m_map);
  hkOArchive::~hkOArchive(&this->m_oa);
}

// File Line: 129
// RVA: 0xE52D90
void __fastcall `anonymous namespace::Writer::writeInt(Writer *this, __int64 i)
{
  unsigned __int64 v3; // rbx
  char v4; // dl
  unsigned __int64 v5; // rbx
  char j; // dl
  char v7; // dl

  if ( i == 0x8000000000000000ui64 )
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
    v3 = (-2 * i) | 1;
  }
  v4 = v3;
  v5 = v3 >> 7;
  for ( j = v4 & 0x7F; v5; j = v7 & 0x7F )
  {
    hkOArchive::write8u(&this->m_oa, j | 0x80);
    v7 = v5;
    v5 >>= 7;
  }
  hkOArchive::write8u(&this->m_oa, j);
}

// File Line: 174
// RVA: 0xE53190
void __fastcall `anonymous namespace::Writer::writeString(Writer *this, const char *s)
{
  int v4; // eax
  unsigned int v5; // ebx

  if ( s )
  {
    v4 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_writtenStrings,
           s,
           0xFFFFFFFFFFFFFFFFui64);
    if ( v4 == -1 )
    {
      v5 = hkString::strLen(s);
      `anonymous namespace::Writer::writeInt(this, (int)v5);
      hkOArchive::writeRaw(&this->m_oa, s, v5);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_writtenStrings.m_map,
        s,
        this->m_writtenStrings.m_map.m_numElems + 1);
    }
    else
    {
      `anonymous namespace::Writer::writeInt(this, -v4);
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
  unsigned __int64 result; // rax
  const char *v5; // rax
  int v6; // eax
  hkDataClassImpl *m_impl; // rcx
  hkDataRefCountedVtbl *vfptr; // rdx
  const char *v9; // rax
  const char *v10; // rax
  int v11; // eax
  __int64 v12; // rdi
  int v13; // edx
  hkDataClass_MemberInfo *v14; // rcx
  int v15; // eax
  hkTypeManager::Type **p_m_type; // rax
  __int64 v17; // rdx
  const char *v18; // rax
  int v19; // eax
  __int64 v20; // rdi
  hkDataClass_MemberInfo *m_data; // rbx
  hkLegacyType::Type LegacyType; // eax
  char v23; // bl
  hkDataClass *v24; // rbx
  __int64 v25; // rax
  __int64 v26; // rax
  const char *v27; // rax
  __int64 v28; // rdi
  hkDataClassImpl *v29; // rcx
  _QWORD *v30; // rax
  __int64 v31; // rdi
  _QWORD *v32; // rbx
  const char *TypeName; // rax
  __int64 v34; // [rsp+20h] [rbp-30h]
  __int64 m_numElems; // [rsp+28h] [rbp-28h]
  hkDataClass v36; // [rsp+30h] [rbp-20h] BYREF
  hkArrayBase<hkDataClass_MemberInfo> minfos; // [rsp+38h] [rbp-18h] BYREF
  hkDataClass klassa; // [rsp+80h] [rbp+30h] BYREF
  char *className; // [rsp+88h] [rbp+38h] BYREF

  if ( !klass->m_impl )
    return 0i64;
  v5 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
  result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_doneClasses,
             v5,
             0xFFFFFFFFFFFFFFFFui64);
  if ( (result & 0x80000000) != 0i64 )
  {
    klassa.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[4].__vecDelDtor)(klass->m_impl);
    v6 = `anonymous namespace::Writer::writeClass(this, &klassa);
    m_impl = klass->m_impl;
    vfptr = klass->m_impl->vfptr;
    LODWORD(className) = v6;
    v9 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))vfptr[2].__vecDelDtor)(m_impl);
    result = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
               (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_doneClasses,
               v9,
               0xFFFFFFFFFFFFFFFFui64);
    if ( (_DWORD)result == -1 )
    {
      m_numElems = (unsigned int)this->m_doneClasses.m_map.m_numElems;
      v10 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_doneClasses.m_map,
        v10,
        (int)m_numElems);
      v11 = ((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[6].__vecDelDtor)(klass->m_impl);
      minfos.m_capacityAndFlags = 0x80000000;
      v12 = v11;
      minfos.m_data = 0i64;
      minfos.m_size = 0;
      v13 = v11;
      if ( v11 )
      {
        LODWORD(klassa.m_impl) = 32 * v11;
        v14 = (hkDataClass_MemberInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerTempAllocator::s_alloc,
                                          &klassa);
        v13 = SLODWORD(klassa.m_impl) / 32;
      }
      else
      {
        v14 = 0i64;
      }
      v15 = 0x80000000;
      minfos.m_data = v14;
      if ( v13 )
        v15 = v13;
      minfos.m_size = v12;
      v34 = v12;
      minfos.m_capacityAndFlags = v15;
      if ( v12 > 0 )
      {
        p_m_type = &v14->m_type;
        v17 = v12;
        do
        {
          if ( p_m_type != (hkTypeManager::Type **)16 )
          {
            *(p_m_type - 2) = 0i64;
            *(p_m_type - 1) = 0i64;
            *p_m_type = 0i64;
            p_m_type[1] = 0i64;
          }
          p_m_type += 4;
          --v17;
        }
        while ( v17 );
      }
      hkDataClass::getAllDeclaredMemberInfo(klass, &minfos);
      hkOArchive::write8u(&this->m_oa, 4);
      v18 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
      `anonymous namespace::Writer::writeString(this, v18);
      v19 = ((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[3].__vecDelDtor)(klass->m_impl);
      `anonymous namespace::Writer::writeInt(this, v19);
      ((void (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[3].__vecDelDtor)(klass->m_impl);
      `anonymous namespace::Writer::writeInt(this, (int)className);
      `anonymous namespace::Writer::writeInt(this, v12);
      if ( v12 > 0 )
      {
        klassa.m_impl = 0i64;
        v36.m_impl = (hkDataClassImpl *)v12;
        v20 = 0i64;
        while ( 1 )
        {
          m_data = minfos.m_data;
          `anonymous namespace::Writer::writeString(this, minfos.m_data[v20].m_name);
          LegacyType = hkTypeManager::getLegacyType(m_data[v20].m_type, (const char **)&className, (int *)&klassa);
          v23 = LegacyType;
          `anonymous namespace::Writer::writeInt(this, LegacyType);
          if ( (v23 & 0x20) != 0 )
            `anonymous namespace::Writer::writeInt(this, SLODWORD(klassa.m_impl));
          if ( (v23 & 0xFu) - 8 > 1 )
            goto LABEL_23;
          if ( !className )
            break;
          v24 = klass;
          v25 = ((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[1].__vecDelDtor)(klass->m_impl);
          v26 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v25 + 72i64))(v25, className);
          v27 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 16i64))(v26);
          `anonymous namespace::Writer::writeString(this, v27);
LABEL_24:
          ++v20;
          if ( !--v36.m_impl )
          {
            v28 = v34;
            if ( v34 > 0 )
            {
              v29 = 0i64;
              klassa.m_impl = 0i64;
              do
              {
                className = (char *)hkTypeManager::Type::findTerminal(*(hkTypeManager::Type **)((char *)&v29[1].vfptr
                                                                                              + (unsigned __int64)minfos.m_data));
                if ( *(_DWORD *)className == 6 )
                {
                  v30 = (_QWORD *)((__int64 (__fastcall *)(hkDataClassImpl *))v24->m_impl->vfptr[1].__vecDelDtor)(v24->m_impl);
                  v31 = *v30;
                  v32 = v30;
                  TypeName = hkTypeManager::Type::getTypeName((hkTypeManager::Type *)className);
                  v36.m_impl = (hkDataClassImpl *)(*(__int64 (__fastcall **)(_QWORD *, const char *))(v31 + 72))(
                                                    v32,
                                                    TypeName);
                  `anonymous namespace::Writer::writeClass(this, &v36);
                  v28 = v34;
                }
                v24 = klass;
                v29 = klassa.m_impl + 2;
                v34 = --v28;
                klassa.m_impl += 2;
              }
              while ( v28 );
            }
            goto LABEL_30;
          }
        }
        hkOArchive::write8u(&this->m_oa, 3);
LABEL_23:
        v24 = klass;
        goto LABEL_24;
      }
LABEL_30:
      minfos.m_size = 0;
      if ( minfos.m_capacityAndFlags >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          &hkContainerTempAllocator::s_alloc,
          minfos.m_data,
          32 * minfos.m_capacityAndFlags);
      return m_numElems;
    }
  }
  return result;
}

// File Line: 333
// RVA: 0xE504E0
__int64 __fastcall `anonymous namespace::Writer::worthWriting<hkDataObject_Value>(
        Writer *this,
        hkDataObject_Value *value)
{
  __int64 result; // rax
  _WORD *v4; // rax
  BOOL v5; // ebx
  bool v6; // zf
  _WORD *v7; // rax
  _WORD *v8; // rbx
  int v9; // eax
  BOOL v10; // edi

  switch ( hkDataObject_Value::getType(value)->m_subType )
  {
    case SUB_TYPE_BYTE:
    case SUB_TYPE_INT:
      result = value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle) != 0;
      break;
    case SUB_TYPE_REAL:
      result = ((float (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *))value->m_impl->vfptr[15].__vecDelDtor)(
                 value->m_impl,
                 value->m_handle) != 0.0;
      break;
    case SUB_TYPE_CSTRING:
      result = value->m_impl->vfptr[11].__vecDelDtor(value->m_impl, value->m_handle) != 0;
      break;
    case SUB_TYPE_CLASS:
    case SUB_TYPE_POINTER:
      v4 = value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
      if ( v4 )
      {
        ++v4[5];
        ++*((_DWORD *)v4 + 3);
      }
      v5 = v4 != 0i64;
      if ( v4 )
      {
        --v4[5];
        v6 = (*((_DWORD *)v4 + 3))-- == 1;
        if ( v6 )
          (**(void (__fastcall ***)(void *, __int64))v4)(v4, 1i64);
      }
      result = v5;
      break;
    case SUB_TYPE_ARRAY:
      v7 = value->m_impl->vfptr[10].__vecDelDtor(value->m_impl, value->m_handle);
      v8 = v7;
      if ( v7 )
      {
        ++v7[5];
        ++*((_DWORD *)v7 + 3);
      }
      v9 = (*(__int64 (__fastcall **)(_WORD *))(*(_QWORD *)v7 + 40i64))(v7);
      --v8[5];
      v6 = (*((_DWORD *)v8 + 3))-- == 1;
      v10 = v9 != 0;
      if ( v6 )
        (**(void (__fastcall ***)(_WORD *, __int64))v8)(v8, 1i64);
      result = v10;
      break;
    case SUB_TYPE_TUPLE:
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
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(
        Writer::MemberWriteFlags *this,
        int nm)
{
  int v4; // ebp
  int v5; // r9d
  signed __int64 v6; // rcx
  int v7; // eax
  int v8; // eax
  int v9; // r9d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_flags.m_capacityAndFlags = 0x80000000;
  this->m_flags.m_data = 0i64;
  this->m_flags.m_size = 0;
  v4 = (nm + 7) & 0xFFFFFFF8;
  if ( nm + 7 >= 0 && v4 != 0 )
  {
    v5 = (nm + 7) & 0xFFFFFFF8;
    if ( nm + 7 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v5, 1);
  }
  v6 = v4 - this->m_flags.m_size;
  if ( v6 > 0 )
    memset(&this->m_flags.m_data[this->m_flags.m_size], 0, v6);
  this->m_flags.m_size = v4;
  v7 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < nm )
  {
    v8 = 2 * v7;
    v9 = nm;
    if ( nm < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v9, 1);
  }
  this->m_flags.m_size = nm;
}

// File Line: 389
// RVA: 0xE516B0
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::fromBytes(
        Writer::MemberWriteFlags *this,
        const char *inb,
        int numBytes)
{
  int m_size; // ebp
  __int64 v4; // r14
  int v5; // eax
  int v7; // esi
  int v9; // eax
  int v10; // r9d
  __int64 v11; // rdi
  int v12; // eax
  char *v13; // rdi
  __int64 v14; // r8
  __int64 v15; // rdi
  unsigned __int8 v16; // dl
  unsigned __int8 v17; // cl
  char v18; // cl
  char v19; // cl
  char v20; // cl
  char v21; // cl
  char v22; // cl
  int v23; // eax
  int v24; // eax
  int v25; // r9d
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  m_size = this->m_flags.m_size;
  v4 = numBytes;
  v5 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = (m_size + 7) & 0xFFFFFFF8;
  if ( v5 < v7 )
  {
    v9 = 2 * v5;
    v10 = (m_size + 7) & 0xFFFFFFF8;
    if ( v7 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v10, 1);
  }
  v11 = this->m_flags.m_size;
  v12 = v7 - v11;
  v13 = &this->m_flags.m_data[v11];
  if ( v12 > 0 )
    memset(v13, 0, v12);
  v14 = 0i64;
  this->m_flags.m_size = v7;
  v15 = 0i64;
  if ( (int)v4 > 0 )
  {
    do
    {
      v16 = inb[v14++];
      v17 = v16;
      v16 >>= 1;
      v15 += 8i64;
      this->m_flags.m_data[v15 - 8] = v17 & 1;
      v18 = v16 & 1;
      v16 >>= 1;
      this->m_flags.m_data[v15 - 7] = v18;
      v19 = v16 & 1;
      v16 >>= 1;
      this->m_flags.m_data[v15 - 6] = v19;
      v20 = v16 & 1;
      v16 >>= 1;
      this->m_flags.m_data[v15 - 5] = v20;
      v21 = v16 & 1;
      v16 >>= 1;
      this->m_flags.m_data[v15 - 4] = v21;
      v22 = v16 & 1;
      v16 >>= 1;
      this->m_flags.m_data[v15 - 3] = v22;
      this->m_flags.m_data[v15 - 2] = v16 & 1;
      this->m_flags.m_data[v15 - 1] = (v16 & 2) != 0;
    }
    while ( v14 < v4 );
  }
  v23 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v23 < m_size )
  {
    v24 = 2 * v23;
    v25 = m_size;
    if ( m_size < v24 )
      v25 = v24;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v25, 1);
  }
  this->m_flags.m_size = m_size;
}

// File Line: 409
// RVA: 0xE52640
void __fastcall `anonymous namespace::Writer::MemberWriteFlags::toBytes(Writer::MemberWriteFlags *this, char *out)
{
  int m_size; // ebp
  int v4; // eax
  int v6; // esi
  int v7; // eax
  int v8; // r9d
  __int64 v9; // rdi
  int v10; // eax
  char *v11; // rdi
  int v12; // edx
  __int64 i; // rdi
  char v14; // cl
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = this->m_flags.m_size;
  v4 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = (m_size + 7) & 0xFFFFFFF8;
  if ( v4 < v6 )
  {
    v7 = 2 * v4;
    v8 = (m_size + 7) & 0xFFFFFFF8;
    if ( v6 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v8, 1);
  }
  v9 = this->m_flags.m_size;
  v10 = v6 - v9;
  v11 = &this->m_flags.m_data[v9];
  if ( v10 > 0 )
    memset(v11, 0, v10);
  v12 = 0;
  this->m_flags.m_size = v6;
  for ( i = 0i64;
        v12 < this->m_flags.m_size;
        *(out - 1) = this->m_flags.m_data[i - 8] | (2
                                                  * (this->m_flags.m_data[i - 7] | (2
                                                                                  * (this->m_flags.m_data[i - 6] | (2 * (this->m_flags.m_data[i - 5] | (2 * (this->m_flags.m_data[i - 4] | (2 * (this->m_flags.m_data[i - 3] | (2 * (this->m_flags.m_data[i - 2] | (2 * v14))))))))))))) )
  {
    v12 += 8;
    ++out;
    v14 = this->m_flags.m_data[i + 7];
    i += 8i64;
  }
  v15 = this->m_flags.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < m_size )
  {
    v16 = 2 * v15;
    v17 = m_size;
    if ( m_size < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&this->m_flags.m_data, v17, 1);
  }
  this->m_flags.m_size = m_size;
}

// File Line: 465
// RVA: 0xE51A20
void __fastcall `anonymous namespace::Writer::scanArray(
        Writer *this,
        hkDataArray *arrToScan,
        hkArray<Writer::TodoItem,hkContainerTempAllocator> *objsTodo,
        unsigned int immediate)
{
  hkDataArray *v6; // rbx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  int i; // edi
  hkDataArrayImpl *v11; // rax
  hkDataArrayImpl *v12; // rcx
  bool v13; // zf
  __int64 v14; // rax
  __int64 v15; // rbx
  __int128 *v16; // rax
  hkDataArrayImpl *v17; // rcx
  int m_capacityAndFlags; // eax
  __int64 m_size; // rdx
  Writer::TodoItem *v20; // r8
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
  int *v31; // r9
  int v32; // eax
  __int64 v33; // rdx
  __int64 v34; // r8
  __int64 v35; // rax
  int v36; // ebx
  __int64 v37; // rax
  __int64 v38; // rbx
  unsigned int v39; // edi
  hkDataObjectImpl *v40; // rax
  hkDataObjectImpl *m_impl; // rcx
  __int64 v42; // [rsp+0h] [rbp-69h]
  unsigned int v43; // [rsp+0h] [rbp-69h]
  int v44; // [rsp+0h] [rbp-69h]
  int v45; // [rsp+4h] [rbp-65h]
  int v46; // [rsp+4h] [rbp-65h]
  int v47; // [rsp+4h] [rbp-65h]
  int v48; // [rsp+4h] [rbp-65h]
  hkDataArray arrToScana; // [rsp+8h] [rbp-61h] BYREF
  hkDataArray v50; // [rsp+10h] [rbp-59h] BYREF
  hkDataObject objToScan; // [rsp+18h] [rbp-51h] BYREF
  __int128 v52; // [rsp+20h] [rbp-49h] BYREF
  __int128 v53; // [rsp+30h] [rbp-39h]
  __int64 v54[2]; // [rsp+40h] [rbp-29h] BYREF
  _DWORD *v55; // [rsp+50h] [rbp-19h]
  __int64 v56; // [rsp+58h] [rbp-11h]
  __int64 v57; // [rsp+60h] [rbp-9h]
  __int128 v58; // [rsp+70h] [rbp+7h] BYREF
  char v59[48]; // [rsp+80h] [rbp+17h] BYREF
  Writer *v60; // [rsp+D0h] [rbp+67h]
  hkDataArray *v61; // [rsp+D8h] [rbp+6Fh]
  void *array; // [rsp+E0h] [rbp+77h]
  void *retaddr; // [rsp+E8h] [rbp+7Fh]

  v6 = arrToScan;
  v7 = *(_DWORD *)((__int64 (*)(void))arrToScan->m_impl->vfptr[1].__vecDelDtor)();
  if ( v7 == 6 )
  {
    ((void (__fastcall *)(hkDataArrayImpl *))v6->m_impl->vfptr[6].__vecDelDtor)(v6->m_impl);
    `anonymous namespace::Writer::writeClass(this, (hkDataClass *)&arrToScana);
    if ( ((int (__fastcall *)(hkDataArrayImpl *))arrToScana.m_impl->vfptr[9].__vecDelDtor)(arrToScana.m_impl) <= 0 )
      return;
    while ( 1 )
    {
      v54[0] = 0i64;
      v54[1] = 0i64;
      v55 = 0i64;
      v56 = 0i64;
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64 *))arrToScana.m_impl->vfptr[10].__vecDelDtor)(
        arrToScana.m_impl,
        v43,
        v54);
      if ( *v55 == 6 )
      {
        v37 = (__int64)v61->m_impl->vfptr[10].__vecDelDtor(v61->m_impl, v54[0]);
        v38 = v37;
        if ( v37 )
        {
          ++*(_WORD *)(v37 + 10);
          ++*(_DWORD *)(v37 + 12);
        }
        v39 = 0;
        v47 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v37 + 40i64))(v37);
        if ( v47 > 0 )
        {
          do
          {
            v40 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v38 + 168i64))(v38, v39);
            objToScan.m_impl = v40;
            if ( v40 )
            {
              ++v40->m_externalCount;
              ++v40->m_count;
            }
            `anonymous namespace::Writer::scanObjectForPointers(v60, &objToScan, objsTodo, 1u);
            m_impl = objToScan.m_impl;
            if ( objToScan.m_impl )
            {
              --objToScan.m_impl->m_externalCount;
              v13 = m_impl->m_count-- == 1;
              if ( v13 )
                m_impl->vfptr->__vecDelDtor(m_impl, 1u);
            }
            ++v39;
          }
          while ( (int)v39 < v48 );
        }
        --*(_WORD *)(v38 + 10);
        v13 = (*(_DWORD *)(v38 + 12))-- == 1;
        if ( v13 )
          (**(void (__fastcall ***)(__int64, __int64))v38)(v38, 1i64);
      }
      else
      {
        if ( *v55 != 7 )
        {
          if ( *v55 == 8 )
          {
            v22 = (hkDataArrayImpl *)v61->m_impl->vfptr[10].__vecDelDtor(v61->m_impl, v54[0]);
            v50.m_impl = v22;
            if ( v22 )
            {
              ++v22->m_externalCount;
              ++v22->m_count;
            }
            `anonymous namespace::Writer::scanArray(this, &v50, objsTodo, (unsigned int)retaddr);
            v23 = v50.m_impl;
            if ( v50.m_impl )
            {
              --v50.m_impl->m_externalCount;
              v13 = v23->m_count-- == 1;
              if ( v13 )
                v23->vfptr->__vecDelDtor(v23, 1u);
            }
          }
          goto LABEL_50;
        }
        v24 = (__int64)v61->m_impl->vfptr[10].__vecDelDtor(v61->m_impl, v54[0]);
        v25 = v24;
        if ( v24 )
        {
          ++*(_WORD *)(v24 + 10);
          ++*(_DWORD *)(v24 + 12);
        }
        v26 = 0;
        v45 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 40i64))(v24);
        if ( v45 > 0 )
        {
          v52 = 0ui64;
          do
          {
            v27 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v25 + 168i64))(v25, v26);
            v28 = v27;
            if ( v27 )
            {
              ++*(_WORD *)(v27 + 10);
              ++*(_DWORD *)(v27 + 12);
              v29 = (__int64 *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v27 + 8i64))(v27, v59);
            }
            else
            {
              v58 = 0ui64;
              v29 = (__int64 *)&v58;
            }
            v30 = *v29;
            v31 = (int *)array;
            *(_QWORD *)&v53 = v29[1];
            v32 = *((_DWORD *)array + 3);
            v57 = v30;
            if ( *((_DWORD *)array + 2) == (v32 & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)array, 24);
              v31 = (int *)array;
            }
            v33 = v31[2];
            v34 = *(_QWORD *)v31 + 24 * v33;
            v31[2] = v33 + 1;
            v35 = v57;
            *(_DWORD *)(v34 + 16) = 0;
            *(_QWORD *)v34 = v35;
            *(_QWORD *)(v34 + 8) = v53;
            if ( v28 )
            {
              --*(_WORD *)(v28 + 10);
              v13 = (*(_DWORD *)(v28 + 12))-- == 1;
              if ( v13 )
                (**(void (__fastcall ***)(__int64, __int64))v28)(v28, 1i64);
            }
            ++v26;
          }
          while ( (int)v26 < v46 );
        }
        --*(_WORD *)(v25 + 10);
        v13 = (*(_DWORD *)(v25 + 12))-- == 1;
        if ( v13 )
          (**(void (__fastcall ***)(__int64, __int64))v25)(v25, 1i64);
        objsTodo = (hkArray<Writer::TodoItem,hkContainerTempAllocator> *)array;
      }
      this = v60;
LABEL_50:
      v36 = v44 + 1;
      if ( v36 >= ((int (__fastcall *)(hkDataArrayImpl *))arrToScana.m_impl->vfptr[9].__vecDelDtor)(arrToScana.m_impl) )
        return;
    }
  }
  if ( v7 == 7 )
  {
    if ( ((int (__fastcall *)(hkDataArrayImpl *))v6->m_impl->vfptr[5].__vecDelDtor)(v6->m_impl) > 0 )
    {
      v53 = 0ui64;
      do
      {
        v14 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v6->m_impl->vfptr[21].__vecDelDtor)(v6->m_impl);
        v15 = v14;
        if ( v14 )
        {
          ++*(_WORD *)(v14 + 10);
          ++*(_DWORD *)(v14 + 12);
          v16 = (__int128 *)(*(__int64 (__fastcall **)(__int64, __int128 *))(*(_QWORD *)v14 + 8i64))(v14, &v58);
        }
        else
        {
          v52 = 0ui64;
          v16 = &v52;
        }
        v17 = *(hkDataArrayImpl **)v16;
        arrToScana.m_impl = (hkDataArrayImpl *)*((_QWORD *)v16 + 1);
        m_capacityAndFlags = objsTodo->m_capacityAndFlags;
        v50.m_impl = v17;
        if ( objsTodo->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&objsTodo->m_data, 24);
        m_size = objsTodo->m_size;
        v20 = &objsTodo->m_data[m_size];
        objsTodo->m_size = m_size + 1;
        v21 = v50.m_impl;
        v20->isStruct = 0;
        v20->handle.p0 = v21;
        v20->handle.p1 = arrToScana.m_impl;
        if ( v15 )
        {
          --*(_WORD *)(v15 + 10);
          v13 = (*(_DWORD *)(v15 + 12))-- == 1;
          if ( v13 )
            (**(void (__fastcall ***)(__int64, __int64))v15)(v15, 1i64);
        }
        v6 = v61;
        LODWORD(v42) = v42 + 1;
      }
      while ( (int)v42 < SHIDWORD(v42) );
    }
  }
  else if ( (unsigned int)(v7 - 8) <= 1 )
  {
    v8 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v6->m_impl->vfptr[5].__vecDelDtor)(v6->m_impl);
    v9 = 0;
    for ( i = v8; (int)v9 < i; ++v9 )
    {
      v11 = (hkDataArrayImpl *)v61->m_impl->vfptr[23].__vecDelDtor(v61->m_impl, v9);
      arrToScana.m_impl = v11;
      if ( v11 )
      {
        ++v11->m_externalCount;
        ++v11->m_count;
      }
      `anonymous namespace::Writer::scanArray(v60, &arrToScana, objsTodo, (unsigned int)retaddr);
      v12 = arrToScana.m_impl;
      if ( arrToScana.m_impl )
      {
        --arrToScana.m_impl->m_externalCount;
        v13 = v12->m_count-- == 1;
        if ( v13 )
          v12->vfptr->__vecDelDtor(v12, 1u);
      }
    }
  }
}

// File Line: 555
// RVA: 0xE51ED0
void __fastcall `anonymous namespace::Writer::scanObjectForPointers(
        Writer *this,
        hkDataObject *objToScan,
        hkArray<Writer::TodoItem,hkContainerTempAllocator> *objsTodo,
        unsigned int immediate)
{
  unsigned int v4; // esi
  hkDataObject *v6; // rbx
  hkTypeManager::Type *Type; // rbx
  hkTypeManager::SubType m_subType; // eax
  hkDataArrayImpl *v9; // rax
  hkDataArrayImpl *v10; // rbx
  bool v11; // zf
  hkDataObjectImpl *v12; // rax
  hkDataObjectImpl *v13; // rbx
  __int128 *v14; // rax
  void *v15; // rsi
  __int64 v16; // rdx
  Writer::TodoItem *v17; // r8
  hkDataArrayImpl *v18; // rax
  hkDataObjectImpl *v19; // rax
  __int128 *v20; // rax
  __int64 m_size; // rdx
  hkDataObjectImpl *m_impl; // rcx
  unsigned int i; // [rsp+20h] [rbp-49h]
  hkDataArray arrToScan; // [rsp+28h] [rbp-41h] BYREF
  hkDataObject_Value v25; // [rsp+30h] [rbp-39h] BYREF
  hkDataObject objToScana; // [rsp+40h] [rbp-29h] BYREF
  __int128 v27; // [rsp+50h] [rbp-19h]
  __int128 v28; // [rsp+60h] [rbp-9h]
  __int128 v29; // [rsp+70h] [rbp+7h] BYREF
  __int128 v30; // [rsp+80h] [rbp+17h] BYREF
  char v31[16]; // [rsp+90h] [rbp+27h] BYREF
  char v32[32]; // [rsp+A0h] [rbp+37h] BYREF

  v4 = immediate;
  v6 = objToScan;
  ((void (*)(void))objToScan->m_impl->vfptr[2].__vecDelDtor)();
  for ( i = ((__int64 (__fastcall *)(hkDataObjectImpl *))v6->m_impl->vfptr[5].__vecDelDtor)(v6->m_impl);
        v6->m_impl->vfptr[6].__vecDelDtor(v6->m_impl, i);
        i = (unsigned int)objToScan->m_impl->vfptr[7].__vecDelDtor(objToScan->m_impl, i) )
  {
    ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v6->m_impl->vfptr[9].__vecDelDtor)(
      v6->m_impl,
      &v25,
      i);
    Type = hkDataObject_Value::getType(&v25);
    if ( hkTypeManager::Type::findTerminal(Type)->m_subType == SUB_TYPE_CLASS )
    {
      m_subType = Type->m_subType;
      if ( Type->m_subType == SUB_TYPE_CLASS )
      {
        v19 = (hkDataObjectImpl *)v25.m_impl->vfptr[13].__vecDelDtor(v25.m_impl, v25.m_handle);
        if ( v4 )
        {
          objToScana.m_impl = v19;
          if ( v19 )
          {
            ++v19->m_externalCount;
            ++v19->m_count;
          }
          `anonymous namespace::Writer::scanObjectForPointers(this, &objToScana, objsTodo, 1u);
          m_impl = objToScana.m_impl;
          if ( objToScana.m_impl )
          {
            --objToScana.m_impl->m_externalCount;
            v11 = m_impl->m_count-- == 1;
            if ( v11 )
              m_impl->vfptr->__vecDelDtor(m_impl, 1u);
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
          v20 = (__int128 *)v19->vfptr[1].__vecDelDtor(v19, (unsigned int)v32);
        }
        else
        {
          v20 = &v29;
          v29 = v28;
        }
        v15 = *(void **)v20;
        arrToScan.m_impl = (hkDataArrayImpl *)*((_QWORD *)v20 + 1);
        if ( objsTodo->m_size == (objsTodo->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&objsTodo->m_data, 24);
        m_size = objsTodo->m_size;
        v17 = &objsTodo->m_data[m_size];
        objsTodo->m_size = m_size + 1;
        v17->isStruct = 1;
        goto LABEL_19;
      }
      if ( m_subType == SUB_TYPE_POINTER )
      {
        v12 = (hkDataObjectImpl *)v25.m_impl->vfptr[13].__vecDelDtor(v25.m_impl, v25.m_handle);
        v13 = v12;
        if ( v12 )
        {
          ++v12->m_externalCount;
          ++v12->m_count;
        }
        v27 = 0ui64;
        if ( v12 )
        {
          v14 = (__int128 *)v12->vfptr[1].__vecDelDtor(v12, (unsigned int)v31);
        }
        else
        {
          v14 = &v30;
          v30 = v27;
        }
        v15 = *(void **)v14;
        arrToScan.m_impl = (hkDataArrayImpl *)*((_QWORD *)v14 + 1);
        if ( objsTodo->m_size == (objsTodo->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&objsTodo->m_data, 24);
        v16 = objsTodo->m_size;
        v17 = &objsTodo->m_data[v16];
        objsTodo->m_size = v16 + 1;
        v17->isStruct = 0;
LABEL_19:
        v18 = arrToScan.m_impl;
        v17->handle.p0 = v15;
        v17->handle.p1 = v18;
        if ( v13 )
        {
          --v13->m_externalCount;
          v11 = v13->m_count-- == 1;
          if ( v11 )
            v13->vfptr->__vecDelDtor(v13, 1u);
        }
        v4 = immediate;
        goto LABEL_23;
      }
      if ( (unsigned int)(m_subType - 8) <= 1 )
      {
        v9 = (hkDataArrayImpl *)v25.m_impl->vfptr[10].__vecDelDtor(v25.m_impl, v25.m_handle);
        v10 = v9;
        arrToScan.m_impl = v9;
        if ( v9 )
        {
          ++v9->m_externalCount;
          ++v9->m_count;
        }
        `anonymous namespace::Writer::scanArray(this, &arrToScan, objsTodo, v4);
        if ( v10 )
        {
          --v10->m_externalCount;
          v11 = v10->m_count-- == 1;
          if ( v11 )
            v10->vfptr->__vecDelDtor(v10, 1u);
        }
      }
    }
LABEL_23:
    v6 = objToScan;
  }
}

// File Line: 605
// RVA: 0xE521D0
void __fastcall `anonymous namespace::Writer::scanObjectTree(
        Writer *this,
        hkDataWorld *world,
        hkDataObject *topObj,
        unsigned int topIsStruct)
{
  hkDataObjectImpl *m_impl; // rcx
  Writer::MemberWriteFlags *v9; // rax
  char *m_data; // rbx
  void *v11; // rdi
  int m_size; // edx
  unsigned __int64 v13; // rcx
  Writer::TodoItem *v14; // rax
  void *p1; // r8
  __int64 v16; // rax
  hkDataObjectImpl *v17; // rbx
  int v18; // eax
  void *v19; // rdi
  __int64 v20; // rax
  int v21; // eax
  int v22; // edi
  __int64 v23; // rdx
  Writer::ObjectDetails *v24; // r14
  void **v25; // rax
  void *v26; // rdx
  int m_currentRememberTag; // ecx
  __int64 v28; // r15
  int v29; // ecx
  int v30; // r14d
  int v31; // r9d
  int v32; // ecx
  bool v33; // zf
  hkDataObjectImpl *v34; // rcx
  hkArray<Writer::TodoItem,hkContainerTempAllocator> array; // [rsp+30h] [rbp-C8h] BYREF
  Writer::MemberWriteFlags v36; // [rsp+40h] [rbp-B8h] BYREF
  hkDataClass klass; // [rsp+50h] [rbp-A8h] BYREF
  hkDataObject objToScan; // [rsp+58h] [rbp-A0h] BYREF
  __int64 v39[2]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v40; // [rsp+70h] [rbp-88h]
  hkDataObject_Handle v41; // [rsp+78h] [rbp-80h] BYREF
  hkDataObject_Value value; // [rsp+88h] [rbp-70h] BYREF
  hkDataObject_Handle v43; // [rsp+98h] [rbp-60h] BYREF
  char v44[16]; // [rsp+A8h] [rbp-50h] BYREF
  char v45[16]; // [rsp+B8h] [rbp-40h] BYREF
  char v46[24]; // [rsp+C8h] [rbp-30h] BYREF
  hkDataObject object; // [rsp+128h] [rbp+30h] BYREF
  hkResult result; // [rsp+130h] [rbp+38h] BYREF

  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 128, 24);
  m_impl = topObj->m_impl;
  v36.m_flags.m_data = 0i64;
  *(_QWORD *)&v36.m_flags.m_size = 0i64;
  if ( m_impl )
    v9 = (Writer::MemberWriteFlags *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v41);
  else
    v9 = &v36;
  m_data = v9->m_flags.m_data;
  v11 = *(void **)&v9->m_flags.m_size;
  m_size = array.m_size;
  if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 24);
    m_size = array.m_size;
  }
  v13 = m_size;
  v14 = array.m_data;
  array.m_size = m_size + 1;
  array.m_data[v13].handle.p0 = m_data;
  v14[v13].handle.p1 = v11;
  v14[v13].isStruct = topIsStruct;
  while ( array.m_size )
  {
    v39[0] = (__int64)array.m_data[array.m_size - 1].handle.p0;
    p1 = array.m_data[array.m_size - 1].handle.p1;
    v39[1] = (__int64)p1;
    v16 = *(_QWORD *)&array.m_data[--array.m_size].isStruct;
    v40 = v16;
    if ( v39[0] || p1 )
    {
      ((void (__fastcall *)(hkDataWorld *, hkDataObject *, __int64 *))world->vfptr[5].__vecDelDtor)(world, &object, v39);
      `anonymous namespace::Writer::ListenerCache::callListenerAndCache(&this->m_listenerCache, &objToScan, &object);
      v17 = objToScan.m_impl;
      if ( objToScan.m_impl )
      {
        v43 = *(hkDataObject_Handle *)objToScan.m_impl->vfptr[1].__vecDelDtor(objToScan.m_impl, v46);
        if ( (unsigned int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
                             (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
                             &v43,
                             0xFFFFFFFF) == -1 )
        {
          klass.m_impl = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataObjectImpl *))v17->vfptr[2].__vecDelDtor)(v17);
          `anonymous namespace::Writer::writeClass(this, &klass);
          v18 = ((__int64 (__fastcall *)(hkDataClassImpl *))klass.m_impl->vfptr[9].__vecDelDtor)(klass.m_impl);
          `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v36, v18);
          v19 = (void *)((unsigned int (__fastcall *)(hkDataObjectImpl *))v17->vfptr[5].__vecDelDtor)(v17);
          if ( v17->vfptr[6].__vecDelDtor(v17, v19) )
          {
            do
            {
              ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, _QWORD))v17->vfptr[9].__vecDelDtor)(
                v17,
                &value,
                (unsigned int)v19);
              if ( (unsigned int)`anonymous namespace::Writer::worthWriting<hkDataObject_Value>(this, &value) )
              {
                v20 = (__int64)v17->vfptr[8].__vecDelDtor(v17, (unsigned int)v19);
                v21 = (int)klass.m_impl->vfptr[11].__vecDelDtor(klass.m_impl, v20);
                v36.m_flags.m_data[v21] = 1;
              }
              v19 = v17->vfptr[7].__vecDelDtor(v17, (unsigned int)v19);
            }
            while ( v17->vfptr[6].__vecDelDtor(v17, (unsigned int)v19) );
          }
          v22 = this->m_detailIndexFromObject.m_numElems & 0x7FFFFFFF;
          v41 = *(hkDataObject_Handle *)v17->vfptr[1].__vecDelDtor(v17, (unsigned int)v44);
          hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
            (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
            &hkContainerHeapAllocator::s_alloc,
            &v41,
            v22);
          if ( this->m_details.m_size == (this->m_details.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_details.m_data, 24);
          v23 = this->m_details.m_size;
          v24 = &this->m_details.m_data[v23];
          this->m_details.m_size = v23 + 1;
          v25 = (void **)v17->vfptr[1].__vecDelDtor(v17, (unsigned int)v45);
          v26 = v25[1];
          v24->handle.p0 = *v25;
          v24->handle.p1 = v26;
          v24->bitfieldStartIndex = this->m_bitfieldBuf.m_size;
          if ( (_DWORD)v40 )
          {
            m_currentRememberTag = -1;
          }
          else
          {
            m_currentRememberTag = this->m_currentRememberTag;
            this->m_currentRememberTag = m_currentRememberTag + 1;
          }
          v24->objectRememberTag = m_currentRememberTag;
          v28 = this->m_bitfieldBuf.m_size;
          v29 = this->m_bitfieldBuf.m_capacityAndFlags & 0x3FFFFFFF;
          v30 = (int)((v36.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
          v31 = v28 + v30;
          if ( v29 >= (int)v28 + v30 )
          {
            result.m_enum = HK_SUCCESS;
          }
          else
          {
            v32 = 2 * v29;
            if ( v31 < v32 )
              v31 = v32;
            hkArrayUtil::_reserve(
              &result,
              &hkContainerTempAllocator::s_alloc,
              (const void **)&this->m_bitfieldBuf.m_data,
              v31,
              1);
          }
          this->m_bitfieldBuf.m_size += v30;
          `anonymous namespace::Writer::MemberWriteFlags::toBytes(&v36, &this->m_bitfieldBuf.m_data[v28]);
          `anonymous namespace::Writer::scanObjectForPointers(this, &objToScan, &array, 0);
          v36.m_flags.m_size = 0;
          if ( v36.m_flags.m_capacityAndFlags >= 0 )
            hkContainerTempAllocator::s_alloc.vfptr->bufFree(
              &hkContainerTempAllocator::s_alloc,
              v36.m_flags.m_data,
              v36.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
          v36.m_flags.m_data = 0i64;
          v36.m_flags.m_capacityAndFlags = 0x80000000;
        }
        --v17->m_externalCount;
        v33 = v17->m_count-- == 1;
        if ( v33 )
          v17->vfptr->__vecDelDtor(v17, 1u);
      }
      v34 = object.m_impl;
      if ( object.m_impl )
      {
        --object.m_impl->m_externalCount;
        v33 = v34->m_count-- == 1;
        if ( v33 )
          v34->vfptr->__vecDelDtor(v34, 1u);
      }
    }
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      24 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}pAllocator::s_alloc,
      array.m_data,
      24 * (array.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 669
// RVA: 0xE50AE0
void __fastcall `anonymous namespace::Writer::_writeArrayItems(Writer *this, hkDataArrayImpl *arr, int asize)
{
  Writer *v3; // rbx
  int v4; // esi
  __int64 v6; // rax
  int v7; // r9d
  int i; // edi
  hkDataArrayImpl *m_impl; // rax
  int v10; // eax
  hkDataArrayImpl *v11; // rcx
  bool v12; // zf
  int j; // edi
  char v14; // al
  int m; // edi
  int v16; // eax
  int n; // edi
  __int64 v18; // rax
  int k; // edi
  double v20; // xmm0_8
  int v21; // edi
  int v22; // eax
  __int64 v23; // rax
  const float *v24; // rax
  void *v25; // rax
  unsigned int v26; // eax
  __int64 v27; // rdx
  int v28; // r8d
  _QWORD *v29; // rcx
  unsigned int v30; // eax
  _QWORD *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // r8
  __int64 v35; // rax
  hkDataArrayImpl *v36; // rbx
  int v37; // esi
  char *v38; // rcx
  int v39; // eax
  unsigned __int64 v40; // rcx
  __int64 v41; // rdx
  hkDataArrayImpl *v42; // rdi
  hkDataArrayImpl *v43; // rax
  hkDataArrayImpl *v44; // rcx
  int jj; // edi
  hkDataArrayImpl *v46; // rax
  hkDataArrayImpl *v47; // rbx
  int ii; // edi
  const char *v49; // rax
  int kk; // edi
  hkDataArrayImpl *v51; // rax
  __int64 v52; // rbx
  hkDataArrayImpl *v53; // rcx
  int nm; // [rsp+30h] [rbp-29h]
  int nma; // [rsp+30h] [rbp-29h]
  __int64 buf2; // [rsp+38h] [rbp-21h] BYREF
  __int64 v57; // [rsp+40h] [rbp-19h]
  char *v58; // [rsp+48h] [rbp-11h] BYREF
  int v59; // [rsp+50h] [rbp-9h]
  int v60; // [rsp+54h] [rbp-5h]
  char *array; // [rsp+58h] [rbp-1h] BYREF
  int nbytes; // [rsp+60h] [rbp+7h]
  int v63; // [rsp+64h] [rbp+Bh]
  Writer::MemberWriteFlags v64; // [rsp+68h] [rbp+Fh] BYREF
  hkDataArray_Value value; // [rsp+78h] [rbp+1Fh] BYREF
  hkDataArray v67; // [rsp+C8h] [rbp+6Fh] BYREF
  int v68; // [rsp+D0h] [rbp+77h]
  hkDataArray arra; // [rsp+D8h] [rbp+7Fh] BYREF

  v68 = asize;
  v67.m_impl = arr;
  v3 = this;
  v4 = asize;
  v6 = (*((__int64 (**)(void))arr->vfptr->__vecDelDtor + 1))();
  v7 = *(_DWORD *)v6;
  if ( *(_DWORD *)v6 == 9 && (**(_DWORD **)(v6 + 8) != 3 || ((*(_DWORD *)(v6 + 16) - 4) & 0xFFFFFFF3) != 0) )
  {
    for ( i = 0; i < v4; ++i )
    {
      m_impl = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor
                                   + 23))(
                                    v67.m_impl->vfptr,
                                    (unsigned int)i);
      arra.m_impl = m_impl;
      if ( m_impl )
      {
        ++m_impl->m_externalCount;
        ++m_impl->m_count;
        m_impl = arra.m_impl;
      }
      v10 = ((__int64 (__fastcall *)(hkDataArrayImpl *))m_impl->vfptr[5].__vecDelDtor)(m_impl);
      `anonymous namespace::Writer::_writeArrayItems(v3, &arra, v10);
      v11 = arra.m_impl;
      if ( arra.m_impl )
      {
        --arra.m_impl->m_externalCount;
        v12 = v11->m_count-- == 1;
        if ( v12 )
          v11->vfptr->__vecDelDtor(v11, 1u);
      }
    }
  }
  else
  {
    switch ( v7 )
    {
      case 2:
        for ( j = 0; j < v4; ++j )
        {
          v14 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor + 17))(
                  v67.m_impl->vfptr,
                  (unsigned int)j);
          hkOArchive::write8u(&v3->m_oa, v14);
        }
        break;
      case 3:
        for ( k = 0; k < v4; ++k )
        {
          v20 = (*((double (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor + 15))(
                  v67.m_impl->vfptr,
                  (unsigned int)k);
          hkOArchive::writeFloat32(&v3->m_oa, *(float *)&v20);
        }
        break;
      case 4:
        if ( (*((unsigned int (__fastcall **)(hkDataRefCountedVtbl *, __int64))arr->vfptr->__vecDelDtor + 9))(
               arr->vfptr,
               v6) == 4 )
        {
          hkOArchive::write8u(&v3->m_oa, 8);
          for ( m = 0; m < v4; ++m )
          {
            v16 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor + 17))(
                    v67.m_impl->vfptr,
                    (unsigned int)m);
            `anonymous namespace::Writer::writeInt(v3, v16);
          }
        }
        else
        {
          hkOArchive::write8u(&v3->m_oa, 16);
          for ( n = 0; n < v4; ++n )
          {
            v18 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor + 19))(
                    v67.m_impl->vfptr,
                    (unsigned int)n);
            `anonymous namespace::Writer::writeInt(v3, v18);
          }
        }
        break;
      case 5:
        for ( ii = 0; ii < v4; ++ii )
        {
          v49 = (const char *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor
                               + 13))(
                                v67.m_impl->vfptr,
                                (unsigned int)ii);
          `anonymous namespace::Writer::writeString(v3, v49);
        }
        break;
      case 6:
        v25 = (void *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, __int64))arr->vfptr->__vecDelDtor + 6))(
                        arr->vfptr,
                        v6);
        v26 = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v25 + 72i64))(v25);
        v60 = 0x80000000;
        v58 = 0i64;
        v59 = 0;
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
        v30 = 0x80000000;
        v59 = v27;
        v27 = (int)v27;
        if ( v28 )
          v30 = v28;
        v58 = (char *)v29;
        v60 = v30;
        v57 = (int)v27;
        if ( (int)v27 > 0i64 )
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
        v32 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *))v67.m_impl->vfptr->__vecDelDtor + 6))(v67.m_impl->vfptr);
        (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v32 + 96i64))(v32, &v58);
        `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v64, nma);
        arra.m_impl = 0i64;
        if ( v57 > 0 )
        {
          v33 = v57;
          v34 = 0i64;
          buf2 = 0i64;
          do
          {
            if ( **(_DWORD **)&v58[v34 + 16] != 1 )
            {
              v35 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor + 10))(
                      v67.m_impl->vfptr,
                      *(_QWORD *)&v58[v34]);
              v36 = (hkDataArrayImpl *)v35;
              if ( v35 )
              {
                ++*(_WORD *)(v35 + 10);
                ++*(_DWORD *)(v35 + 12);
              }
              v37 = 0;
              if ( (*(int (__fastcall **)(__int64))(*(_QWORD *)v35 + 40i64))(v35) > 0 )
              {
                while ( 1 )
                {
                  value.m_impl = v36;
                  value.m_index = v37;
                  if ( (unsigned int)`anonymous namespace::Writer::worthWriting<hkDataArray_Value>(this, &value) )
                    break;
                  if ( ++v37 >= ((int (__fastcall *)(hkDataArrayImpl *))v36->vfptr[5].__vecDelDtor)(v36) )
                    goto LABEL_59;
                }
                v64.m_flags.m_data[(unsigned __int64)arra.m_impl] = 1;
              }
LABEL_59:
              --v36->m_externalCount;
              v12 = v36->m_count-- == 1;
              if ( v12 )
                v36->vfptr->__vecDelDtor(v36, 1u);
              v33 = v57;
              v34 = buf2;
            }
            v34 += 32i64;
            buf2 = v34;
            ++arra.m_impl;
          }
          while ( (__int64)arra.m_impl < v33 );
          v4 = v68;
          v3 = this;
        }
        v38 = 0i64;
        nbytes = 0;
        array = 0i64;
        v63 = 0x80000000;
        v39 = (int)((v64.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
        LODWORD(arra.m_impl) = v39;
        if ( v39 > 0 )
        {
          hkArrayUtil::_reserve(
            (hkResult *)&buf2,
            &hkContainerTempAllocator::s_alloc,
            (const void **)&array,
            (int)((v64.m_flags.m_size + 7) & 0xFFFFFFF8) / 8,
            1);
          v38 = array;
          v39 = (int)arra.m_impl;
        }
        nbytes = v39;
        `anonymous namespace::Writer::MemberWriteFlags::toBytes(&v64, v38);
        hkOArchive::writeRaw(&v3->m_oa, array, (unsigned int)nbytes);
        nbytes = 0;
        if ( v63 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, v63 & 0x3FFFFFFF);
        v40 = 0i64;
        arra.m_impl = 0i64;
        if ( v57 > 0 )
        {
          v41 = 0i64;
          v42 = v67.m_impl;
          buf2 = 0i64;
          do
          {
            if ( v64.m_flags.m_data[v40] )
            {
              v43 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v42->vfptr->__vecDelDtor
                                        + 10))(
                                         v42->vfptr,
                                         *(_QWORD *)&v58[v41]);
              v67.m_impl = v43;
              if ( v43 )
              {
                ++v43->m_externalCount;
                ++v43->m_count;
              }
              `anonymous namespace::Writer::_writeArrayItems(v3, &v67, v4);
              v44 = v67.m_impl;
              if ( v67.m_impl )
              {
                --v67.m_impl->m_externalCount;
                v12 = v44->m_count-- == 1;
                if ( v12 )
                  v44->vfptr->__vecDelDtor(v44, 1u);
              }
            }
            buf2 += 32i64;
            v41 = buf2;
            v40 = (unsigned __int64)++arra.m_impl;
          }
          while ( (__int64)arra.m_impl < v57 );
        }
        v64.m_flags.m_size = 0;
        if ( v64.m_flags.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v64.m_flags.m_data,
            v64.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
        v64.m_flags.m_data = 0i64;
        v64.m_flags.m_capacityAndFlags = 0x80000000;
        v59 = 0;
        if ( v60 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v58, 32 * v60);
        break;
      case 7:
        for ( jj = 0; jj < v4; ++jj )
        {
          v46 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor
                                    + 21))(
                                     v67.m_impl->vfptr,
                                     (unsigned int)jj);
          v47 = v46;
          arra.m_impl = v46;
          if ( v46 )
          {
            ++v46->m_externalCount;
            ++v46->m_count;
          }
          `anonymous namespace::Writer::writeObjectReference(this, (hkDataObject *)&arra);
          if ( v47 )
          {
            --v47->m_externalCount;
            v12 = v47->m_count-- == 1;
            if ( v12 )
              v47->vfptr->__vecDelDtor(v47, 1u);
          }
        }
        break;
      case 8:
        for ( kk = 0; kk < v4; ++kk )
        {
          v51 = (hkDataArrayImpl *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor
                                    + 23))(
                                     v67.m_impl->vfptr,
                                     (unsigned int)kk);
          arra.m_impl = v51;
          if ( v51 )
          {
            ++v51->m_externalCount;
            ++v51->m_count;
            v51 = arra.m_impl;
          }
          v52 = ((int (__fastcall *)(hkDataArrayImpl *))v51->vfptr[5].__vecDelDtor)(v51);
          `anonymous namespace::Writer::writeInt(this, v52);
          `anonymous namespace::Writer::_writeArrayItems(this, &arra, v52);
          v53 = arra.m_impl;
          if ( arra.m_impl )
          {
            --arra.m_impl->m_externalCount;
            v12 = v53->m_count-- == 1;
            if ( v12 )
              v53->vfptr->__vecDelDtor(v53, 1u);
          }
        }
        break;
      case 9:
        if ( v7 == 9 && **(_DWORD **)(v6 + 8) == 3 && ((*(_DWORD *)(v6 + 16) - 4) & 0xFFFFFFF3) == 0 )
        {
          v21 = 0;
          LODWORD(arra.m_impl) = hkTypeManager::Type::getTupleSize((hkTypeManager::Type *)v6);
          if ( LODWORD(arra.m_impl) == 4 )
          {
            v22 = 3;
            LODWORD(arra.m_impl) = 3;
            nm = 0;
            LODWORD(buf2) = 0;
            if ( v4 > 0 )
            {
              while ( 1 )
              {
                v23 = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *))v67.m_impl->vfptr->__vecDelDtor + 11))(v67.m_impl->vfptr);
                if ( hkString::memCmp((const void *)(v23 + 12), &buf2, 4u) )
                  break;
                if ( ++nm >= v4 )
                {
                  v22 = (int)arra.m_impl;
                  goto LABEL_35;
                }
              }
              v22 = 4;
              LODWORD(arra.m_impl) = 4;
            }
LABEL_35:
            `anonymous namespace::Writer::writeInt(v3, v22);
          }
          if ( v4 > 0 )
          {
            do
            {
              v24 = (const float *)(*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD))v67.m_impl->vfptr->__vecDelDtor
                                    + 11))(
                                     v67.m_impl->vfptr,
                                     (unsigned int)v21);
              hkOArchive::writeArrayFloat32(&v3->m_oa, v24, (int)arra.m_impl);
              ++v21;
            }
            while ( v21 < v4 );
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
void __fastcall `anonymous namespace::Writer::writeBinaryValue(
        Writer *this,
        hkDataObject_Value *value,
        hkDataClass_MemberInfo *minfo)
{
  hkTypeManager::Type *Type; // rax
  hkTypeManager::SubType m_subType; // r10d
  hkTypeManager::Type *v8; // rsi
  hkDataArrayImpl *v9; // rax
  _WORD *v10; // rbx
  int v11; // eax
  hkDataArrayImpl *v12; // rax
  hkDataArrayImpl *v13; // rbx
  __int64 v14; // r15
  hkTypeManager::Type *m_parent; // rcx
  hkTypeManager::Type *v16; // rbp
  __int64 v17; // rax
  _QWORD *v18; // rax
  __int64 v19; // rsi
  _QWORD *v20; // rdi
  const char *TypeName; // rax
  __int64 v22; // rax
  const char *v23; // rax
  int v24; // eax
  bool v25; // zf
  char v26; // al
  void *v27; // rax
  float v28; // xmm0_4
  __int64 TupleSize; // rbx
  const float *v30; // rax
  hkDataObjectImpl *v31; // rax
  hkDataArrayImpl *v32; // rax
  hkDataArrayImpl *m_impl; // rcx
  const char *v34; // rax
  hkDataObject obj; // [rsp+20h] [rbp-28h] BYREF
  hkDataArray arr; // [rsp+68h] [rbp+20h] BYREF

  Type = hkDataObject_Value::getType(value);
  m_subType = Type->m_subType;
  v8 = Type;
  if ( Type->m_subType == SUB_TYPE_TUPLE
    && (Type->m_parent->m_subType != SUB_TYPE_REAL || ((Type->m_extra.m_size - 4) & 0xFFFFFFF3) != 0) )
  {
    v9 = (hkDataArrayImpl *)value->m_impl->vfptr[10].__vecDelDtor(value->m_impl, value->m_handle);
    v10 = v9;
    arr.m_impl = v9;
    if ( v9 )
    {
      ++v9->m_externalCount;
      ++v9->m_count;
    }
    v11 = ((__int64 (__fastcall *)(hkDataArrayImpl *))v9->vfptr[5].__vecDelDtor)(v9);
    `anonymous namespace::Writer::_writeArrayItems(this, (hkDataArrayImpl *)&arr, v11);
LABEL_26:
    --v10[5];
    v25 = (*((_DWORD *)v10 + 3))-- == 1;
    if ( v25 )
      (**(void (__fastcall ***)(void *, __int64))v10)(v10, 1i64);
  }
  else if ( m_subType == SUB_TYPE_ARRAY )
  {
    v12 = (hkDataArrayImpl *)value->m_impl->vfptr[10].__vecDelDtor(value->m_impl, value->m_handle);
    v13 = v12;
    arr.m_impl = v12;
    if ( v12 )
    {
      ++v12->m_externalCount;
      ++v12->m_count;
    }
    v14 = ((int (__fastcall *)(hkDataArrayImpl *))v12->vfptr[5].__vecDelDtor)(v12);
    `anonymous namespace::Writer::writeInt(this, v14);
    m_parent = minfo->m_type->m_parent;
    if ( m_parent->m_subType == SUB_TYPE_CLASS && !hkTypeManager::Type::getTypeName(m_parent) )
    {
      v16 = v8->m_parent;
      v17 = ((__int64 (__fastcall *)(hkDataObjectImpl *))value->m_impl->vfptr[2].__vecDelDtor)(value->m_impl);
      v18 = (_QWORD *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 8i64))(v17);
      v19 = *v18;
      v20 = v18;
      TypeName = hkTypeManager::Type::getTypeName(v16);
      v22 = (*(__int64 (__fastcall **)(_QWORD *, const char *))(v19 + 72))(v20, TypeName);
      v23 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 16i64))(v22);
      v24 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_doneClasses,
              v23,
              0i64);
      `anonymous namespace::Writer::writeInt(this, v24);
    }
    `anonymous namespace::Writer::_writeArrayItems(this, (hkDataArrayImpl *)&arr, v14);
    --v13->m_externalCount;
    v25 = v13->m_count-- == 1;
    if ( v25 )
      v13->vfptr->__vecDelDtor(v13, 1u);
  }
  else
  {
    switch ( m_subType )
    {
      case SUB_TYPE_BYTE:
        v26 = (char)value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
        hkOArchive::write8u(&this->m_oa, v26);
        break;
      case SUB_TYPE_REAL:
        v28 = ((float (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *))value->m_impl->vfptr[15].__vecDelDtor)(
                value->m_impl,
                value->m_handle);
        hkOArchive::writeFloat32(&this->m_oa, v28);
        break;
      case SUB_TYPE_INT:
        v27 = value->m_impl->vfptr[12].__vecDelDtor(value->m_impl, value->m_handle);
        `anonymous namespace::Writer::writeInt(this, (__int64)v27);
        break;
      case SUB_TYPE_CSTRING:
        v34 = (const char *)value->m_impl->vfptr[11].__vecDelDtor(value->m_impl, value->m_handle);
        `anonymous namespace::Writer::writeString(this, v34);
        break;
      case SUB_TYPE_CLASS:
        v32 = (hkDataArrayImpl *)value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
        arr.m_impl = v32;
        if ( v32 )
        {
          ++v32->m_externalCount;
          ++v32->m_count;
        }
        `anonymous namespace::Writer::writeStructReal(this, (hkDataObject *)&arr);
        m_impl = arr.m_impl;
        if ( arr.m_impl )
        {
          --arr.m_impl->m_externalCount;
          v25 = m_impl->m_count-- == 1;
          if ( v25 )
            m_impl->vfptr->__vecDelDtor(m_impl, 1u);
        }
        break;
      case SUB_TYPE_POINTER:
        v31 = (hkDataObjectImpl *)value->m_impl->vfptr[13].__vecDelDtor(value->m_impl, value->m_handle);
        v10 = v31;
        obj.m_impl = v31;
        if ( v31 )
        {
          ++v31->m_externalCount;
          ++v31->m_count;
        }
        `anonymous namespace::Writer::writeObjectReference(this, &obj);
        if ( v10 )
          goto LABEL_26;
        break;
      case SUB_TYPE_TUPLE:
        if ( m_subType == SUB_TYPE_TUPLE
          && Type->m_parent->m_subType == SUB_TYPE_REAL
          && ((Type->m_extra.m_size - 4) & 0xFFFFFFF3) == 0 )
        {
          TupleSize = (unsigned int)hkTypeManager::Type::getTupleSize(Type);
          v30 = (const float *)((__int64 (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64))value->m_impl->vfptr[14].__vecDelDtor)(
                                 value->m_impl,
                                 value->m_handle,
                                 TupleSize);
          hkOArchive::writeArrayFloat32(&this->m_oa, v30, TupleSize);
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
  int v4; // eax
  hkDataObjectImpl *m_impl; // rbx
  unsigned __int128 *v6; // rax
  int v7; // eax
  unsigned __int128 v9; // [rsp+20h] [rbp-18h] BYREF

  v2 = obj;
  if ( this->m_listenerCache.m_listener )
  {
    if ( obj->m_impl )
    {
      v9 = *(_OWORD *)obj->m_impl->vfptr[1].__vecDelDtor(obj->m_impl, &v9);
      v4 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
             (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_listenerCache.m_indexFromHandle,
             (hkDataObject_Handle *)&v9,
             0xFFFFFFFF);
      if ( v4 != -1 )
        v2 = this->m_listenerCache.m_cachedObjects.m_data[v4];
    }
  }
  m_impl = v2->m_impl;
  if ( m_impl )
  {
    ++m_impl->m_externalCount;
    ++m_impl->m_count;
  }
  v9 = 0ui64;
  if ( m_impl )
    v6 = (unsigned __int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v9);
  else
    v6 = &v9;
  v9 = *v6;
  v7 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
         (hkDataObject_Handle *)&v9,
         0xFFFFFFFF);
  `anonymous namespace::Writer::writeInt(this, this->m_details.m_data[v7].objectRememberTag);
  if ( m_impl )
  {
    --m_impl->m_externalCount;
    if ( m_impl->m_count-- == 1 )
      m_impl->vfptr->__vecDelDtor(m_impl, 1u);
  }
}

// File Line: 957
// RVA: 0xE52E20
void __fastcall `anonymous namespace::Writer::writeObjectReal(Writer *this, hkDataObject *obj)
{
  int v4; // eax
  hkDataObjectImpl *m_impl; // rbx
  int v6; // esi
  unsigned __int128 *v7; // rax
  Writer::ObjectDetails *v8; // rbp
  __int64 v9; // rax
  const char *v10; // rax
  unsigned __int128 v12; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_listenerCache.m_listener
    && obj->m_impl
    && (v12 = *(_OWORD *)obj->m_impl->vfptr[1].__vecDelDtor(obj->m_impl, &v12),
        v4 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
               (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_listenerCache.m_indexFromHandle,
               (hkDataObject_Handle *)&v12,
               0xFFFFFFFF),
        v4 != -1) )
  {
    m_impl = this->m_listenerCache.m_cachedObjects.m_data[v4]->m_impl;
  }
  else
  {
    m_impl = obj->m_impl;
  }
  if ( m_impl )
  {
    ++m_impl->m_externalCount;
    ++m_impl->m_count;
  }
  v6 = 0;
  v12 = 0ui64;
  if ( m_impl )
    v7 = (unsigned __int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v12);
  else
    v7 = &v12;
  v12 = *v7;
  v8 = &this->m_details.m_data[(int)hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
                                      (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
                                      (hkDataObject_Handle *)&v12,
                                      0xFFFFFFFF)];
  hkOArchive::write8u(&this->m_oa, 8);
  v9 = ((__int64 (__fastcall *)(hkDataObjectImpl *))m_impl->vfptr[2].__vecDelDtor)(m_impl);
  if ( v9 )
  {
    v10 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_doneClasses,
           v10,
           0xFFFFFFFFFFFFFFFFui64);
  }
  `anonymous namespace::Writer::writeInt(this, v6);
  `anonymous namespace::Writer::_writeMembersCommon(this, obj, v8);
  --m_impl->m_externalCount;
  if ( m_impl->m_count-- == 1 )
    m_impl->vfptr->__vecDelDtor(m_impl, 1u);
}

// File Line: 970
// RVA: 0xE53240
void __fastcall `anonymous namespace::Writer::writeStructReal(Writer *this, hkDataObject *obj)
{
  hkDataObjectImpl *m_impl; // rcx
  unsigned __int128 *v5; // rax
  int v6; // eax
  unsigned __int128 v7; // [rsp+20h] [rbp-18h] BYREF

  m_impl = obj->m_impl;
  v7 = 0ui64;
  if ( m_impl )
    v5 = (unsigned __int128 *)m_impl->vfptr[1].__vecDelDtor(m_impl, (unsigned int)&v7);
  else
    v5 = &v7;
  v7 = *v5;
  v6 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_detailIndexFromObject,
         (hkDataObject_Handle *)&v7,
         0xFFFFFFFF);
  `anonymous namespace::Writer::_writeMembersCommon(this, obj, &this->m_details.m_data[v6]);
}

// File Line: 983
// RVA: 0xE51250
void __fastcall `anonymous namespace::Writer::_writeMembersCommon(
        Writer *this,
        hkDataObject *obj,
        Writer::ObjectDetails *details)
{
  __int64 v6; // rbx
  int v7; // eax
  __int64 v8; // r14
  char *v9; // r13
  int v10; // edx
  _QWORD *v11; // rcx
  unsigned int v12; // eax
  _QWORD *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // rbx
  __int64 v16; // rdi
  hkDataClass_MemberInfo *v17; // rsi
  char *v18; // [rsp+20h] [rbp-30h] BYREF
  int v19; // [rsp+28h] [rbp-28h]
  int v20; // [rsp+2Ch] [rbp-24h]
  Writer::MemberWriteFlags v21; // [rsp+30h] [rbp-20h] BYREF
  hkDataObject_Value value; // [rsp+40h] [rbp-10h] BYREF
  int v23; // [rsp+80h] [rbp+30h] BYREF

  v6 = ((__int64 (*)(void))obj->m_impl->vfptr[2].__vecDelDtor)();
  v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 72i64))(v6);
  v8 = v7;
  `anonymous namespace::Writer::MemberWriteFlags::MemberWriteFlags(&v21, v7);
  v9 = &this->m_bitfieldBuf.m_data[details->bitfieldStartIndex];
  LODWORD(details) = (int)((v21.m_flags.m_size + 7) & 0xFFFFFFF8) / 8;
  hkOArchive::writeRaw(&this->m_oa, v9, (unsigned int)details);
  `anonymous namespace::Writer::MemberWriteFlags::fromBytes(&v21, v9, (int)details);
  v10 = v8;
  v20 = 0x80000000;
  v18 = 0i64;
  v19 = 0;
  if ( (_DWORD)v8 )
  {
    v23 = 32 * v8;
    v11 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v23);
    v10 = v23 / 32;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 0x80000000;
  v18 = (char *)v11;
  if ( v10 )
    v12 = v10;
  v19 = v8;
  v20 = v12;
  if ( v8 > 0 )
  {
    v13 = v11 + 2;
    v14 = v8;
    do
    {
      if ( v13 != (_QWORD *)16 )
      {
        *(v13 - 2) = 0i64;
        *(v13 - 1) = 0i64;
        *v13 = 0i64;
        v13[1] = 0i64;
      }
      v13 += 4;
      --v14;
    }
    while ( v14 );
  }
  (*(void (__fastcall **)(__int64, char **))(*(_QWORD *)v6 + 96i64))(v6, &v18);
  v15 = 0i64;
  if ( v8 > 0 )
  {
    v16 = 0i64;
    do
    {
      v17 = (hkDataClass_MemberInfo *)&v18[v16];
      if ( v21.m_flags.m_data[v15] )
      {
        ((void (__fastcall *)(hkDataObjectImpl *, hkDataObject_Value *, const char *))obj->m_impl->vfptr[3].__vecDelDtor)(
          obj->m_impl,
          &value,
          v17->m_name);
        `anonymous namespace::Writer::writeBinaryValue(this, &value, v17);
      }
      ++v15;
      v16 += 32i64;
    }
    while ( v15 < v8 );
  }
  v19 = 0;
  if ( v20 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v18, 32 * v20);
  v18 = 0i64;
  v20 = 0x80000000;
  v21.m_flags.m_size = 0;
  if ( v21.m_flags.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v21.m_flags.m_data,
      v21.m_flags.m_capacityAndFlags & 0x3FFFFFFF);
}

// File Line: 1048
// RVA: 0xE53080
hkResult *__fastcall `anonymous namespace::Writer::writeObjectTree(
        Writer *this,
        hkResult *result,
        hkDataObject *topObj)
{
  __int64 v6; // rax
  hkDataWorld *v7; // r14
  int v8; // esi
  __int64 v9; // rbx
  hkDataObjectImpl *m_impl; // rcx
  hkDataObject obj; // [rsp+40h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(hkDataObjectImpl *))topObj->m_impl->vfptr[2].__vecDelDtor)(topObj->m_impl);
  v7 = (hkDataWorld *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 8i64))(v6);
  hkOArchive::write32(&this->m_oa, -894431970);
  hkOArchive::write32(&this->m_oa, -804128050);
  hkOArchive::write8u(&this->m_oa, 2);
  hkOArchive::write8u(&this->m_oa, 8);
  `anonymous namespace::Writer::writeString(this, "hk_2013.2.0-r1");
  `anonymous namespace::Writer::scanObjectTree(this, v7, topObj, 0);
  v8 = 1;
  if ( this->m_details.m_size > 1 )
  {
    v9 = 1i64;
    do
    {
      if ( this->m_details.m_data[v9].objectRememberTag != -1 )
      {
        v7->vfptr[5].__vecDelDtor(v7, (unsigned int)&obj);
        `anonymous namespace::Writer::writeObjectReal(this, &obj);
        m_impl = obj.m_impl;
        if ( obj.m_impl )
        {
          --obj.m_impl->m_externalCount;
          if ( m_impl->m_count-- == 1 )
            m_impl->vfptr->__vecDelDtor(m_impl, 1u);
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < this->m_details.m_size );
  }
  hkOArchive::write8u(&this->m_oa, 14);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 1081
// RVA: 0xE50930
void __fastcall `anonymous namespace::Writer::ListenerCache::~ListenerCache(Writer::ListenerCache *this)
{
  int v1; // edi
  __int64 v3; // r14
  hkDataObject *v4; // rsi
  hkDataObjectImpl *m_impl; // rcx
  _QWORD **Value; // rax
  int m_capacityAndFlags; // r8d

  v1 = 0;
  if ( this->m_cachedObjects.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_cachedObjects.m_data[v3];
      if ( v4 )
      {
        m_impl = v4->m_impl;
        if ( v4->m_impl )
        {
          --m_impl->m_externalCount;
          if ( m_impl->m_count-- == 1 )
            m_impl->vfptr->__vecDelDtor(m_impl, 1u);
        }
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, hkDataObject *, __int64))(*Value[11] + 16i64))(Value[11], v4, 8i64);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_cachedObjects.m_size );
  }
  m_capacityAndFlags = this->m_cachedObjects.m_capacityAndFlags;
  this->m_cachedObjects.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      this->m_cachedObjects.m_data,
      8 * m_capacityAndFlags);
  this->m_cachedObjects.m_data = 0i64;
  this->m_cachedObjects.m_capacityAndFlags = 0x80000000;
  hkMapBase<hkDataObject_Handle,int,`anonymous namespace::Writer::HandleOps>::clearAndDeallocate(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_indexFromHandle,
    &hkContainerHeapAllocator::s_alloc);
}

// File Line: 1103
// RVA: 0xE51470
hkDataObject *__fastcall `anonymous namespace::Writer::ListenerCache::callListenerAndCache(
        Writer::ListenerCache *this,
        hkDataObject *result,
        hkDataObject *object)
{
  unsigned __int128 v6; // xmm6
  int v7; // eax
  hkDataObjectImpl *v8; // rcx
  unsigned __int128 *v9; // rax
  __int64 v10; // r15
  __int64 v11; // r14
  hkDataObjectImpl *v12; // r8
  unsigned __int128 *v13; // rax
  bool v14; // zf
  hkDataObjectImpl *m_impl; // rax
  int m_size; // r9d
  _QWORD **Value; // rax
  hkDataObjectImpl **v19; // rax
  hkDataObject *v20; // rsi
  hkDataObjectImpl *v21; // rcx
  __int64 v22; // r8
  hkDataObject **v23; // rdx
  hkDataObjectImpl *v24; // rax
  hkDataObjectImpl *v25; // rcx
  unsigned __int128 v26; // [rsp+20h] [rbp-30h] BYREF
  char v27[16]; // [rsp+30h] [rbp-20h] BYREF
  hkDataObjectImpl *v28; // [rsp+80h] [rbp+30h] BYREF

  if ( !this->m_listener || !object->m_impl )
  {
LABEL_15:
    m_impl = object->m_impl;
    goto LABEL_16;
  }
  v6 = *(_OWORD *)object->m_impl->vfptr[1].__vecDelDtor(object->m_impl, &v26);
  v26 = v6;
  v7 = hkMapBase<hkDataObject_Handle,int,`anonymous namespace::HandleOps>::getWithDefault(
         (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_indexFromHandle,
         (hkDataObject_Handle *)&v26,
         0xFFFFFFFF);
  if ( v7 != -1 )
  {
    m_impl = this->m_cachedObjects.m_data[v7]->m_impl;
LABEL_16:
    result->m_impl = m_impl;
    if ( m_impl )
    {
      ++m_impl->m_externalCount;
      ++m_impl->m_count;
    }
    return result;
  }
  ((void (__fastcall *)(hkTagfileWriter::AddDataObjectListener *, hkDataObjectImpl **, hkDataObject *))this->m_listener->vfptr[1].__first_virtual_table_function__)(
    this->m_listener,
    &v28,
    object);
  v8 = v28;
  v26 = 0ui64;
  if ( v28 )
  {
    v9 = (unsigned __int128 *)v28->vfptr[1].__vecDelDtor(v28, (unsigned int)v27);
    v8 = v28;
  }
  else
  {
    v9 = &v26;
  }
  v10 = *(_QWORD *)v9;
  v11 = *((_QWORD *)v9 + 1);
  v12 = object->m_impl;
  v26 = 0ui64;
  if ( v12 )
  {
    v13 = (unsigned __int128 *)v12->vfptr[1].__vecDelDtor(v12, (unsigned int)&v26);
    v8 = v28;
  }
  else
  {
    v13 = &v26;
  }
  if ( v10 == *(_QWORD *)v13 && v11 == *((_QWORD *)v13 + 1) )
  {
    if ( v8 )
    {
      --v8->m_externalCount;
      v14 = v8->m_count-- == 1;
      if ( v14 )
        v8->vfptr->__vecDelDtor(v8, 1u);
    }
    goto LABEL_15;
  }
  m_size = this->m_cachedObjects.m_size;
  v26 = v6;
  hkMapBase<hkDataObject_Handle,int,hkMapOperations<hkDataObject_Handle>>::insert(
    (hkMapBase<hkDataObject_Handle,int,HandleOps> *)&this->m_indexFromHandle,
    &hkContainerHeapAllocator::s_alloc,
    (hkDataObject_Handle *)&v26,
    m_size);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v19 = (hkDataObjectImpl **)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 8i64);
  v20 = (hkDataObject *)v19;
  if ( v19 )
  {
    *v19 = v28;
    v21 = v28;
    if ( v28 )
    {
      ++v28->m_externalCount;
      ++v21->m_count;
    }
  }
  else
  {
    v20 = 0i64;
  }
  if ( this->m_cachedObjects.m_size == (this->m_cachedObjects.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&this->m_cachedObjects.m_data, 8);
  v22 = this->m_cachedObjects.m_size;
  v23 = &this->m_cachedObjects.m_data[v22];
  this->m_cachedObjects.m_size = v22 + 1;
  *v23 = v20;
  v24 = v28;
  result->m_impl = v28;
  if ( v24 )
  {
    ++v24->m_externalCount;
    ++v24->m_count;
    v25 = v28;
    if ( v28 )
    {
      --v28->m_externalCount;
      v14 = v25->m_count-- == 1;
      if ( v14 )
        v25->vfptr->__vecDelDtor(v25, 1u);
    }
  }
  return result;
}

// File Line: 1149
// RVA: 0xE502B0
hkResult *__fastcall hkBinaryTagfileWriter::save(
        hkBinaryTagfileWriter *this,
        hkResult *result,
        hkDataObject *obj,
        hkStreamWriter *stream,
        hkTagfileWriter::AddDataObjectListener *userListener,
        hkTagfileWriter::Options *options)
{
  Writer v10; // [rsp+20h] [rbp-C8h] BYREF
  hkResult resulta; // [rsp+F8h] [rbp+10h] BYREF

  `anonymous namespace::Writer::Writer(&v10, stream, userListener, options);
  `anonymous namespace::Writer::writeObjectTree(&v10, &resulta, obj);
  stream->vfptr[2].__first_virtual_table_function__(stream);
  result->m_enum = *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, hkResult *))stream->vfptr[1].__first_virtual_table_function__)(
                               stream,
                               &resulta) == 0;
  `anonymous namespace::Writer::~Writer(&v10);
  return result;
}

