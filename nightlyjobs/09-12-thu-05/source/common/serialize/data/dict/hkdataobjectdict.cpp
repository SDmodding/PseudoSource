// File Line: 86
// RVA: 0x15D89E0
__int64 anonymous_namespace_::_dynamic_initializer_for__InternedNullRefCounted__()
{
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__InternedNullRefCounted__);
}

// File Line: 115
// RVA: 0xE43B00
void __fastcall `anonymous namespace::Union::clearArray(
        Union *this,
        hkTypeManager::Type *typeIn,
        Union *u,
        int n,
        unsigned int destroyStructs)
{
  __int64 v7; // rbp
  __int64 v8; // rbx
  __int64 v9; // rcx
  bool v10; // zf
  __int64 v11; // rsi
  _DWORD *v12; // rbx
  __int64 v13; // rbx
  __int64 v14; // rcx

  if ( (unsigned int)(LODWORD(this->r) - 8) <= 1 )
  {
    v14 = *(_QWORD *)&typeIn->m_subType;
    if ( *(_QWORD *)&typeIn->m_subType )
    {
      v10 = (*(_DWORD *)(v14 + 12))-- == 1;
      if ( v10 )
        (**(void (__fastcall ***)(__int64, __int64, Union *))v14)(v14, 1i64, u);
    }
    *(_QWORD *)&typeIn->m_subType = 0i64;
  }
  else
  {
    v7 = (int)u;
    switch ( LODWORD(this->r) )
    {
      case 5:
        v13 = 0i64;
        if ( (int)u > 0 )
        {
          do
          {
            hkString::strFree(*((char **)&typeIn->m_subType + v13));
            *((_QWORD *)&typeIn->m_subType + v13++) = 0i64;
          }
          while ( v13 < v7 );
        }
        break;
      case 6:
        v11 = 0i64;
        if ( (int)u > 0 )
        {
          do
          {
            v12 = (_DWORD *)*((_QWORD *)&typeIn->m_subType + v11);
            *((_QWORD *)&typeIn->m_subType + v11) = 0i64;
            if ( v12 )
            {
              if ( n )
                (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v12 + 224i64))(v12);
              v10 = v12[3]-- == 1;
              if ( v10 )
                (**(void (__fastcall ***)(_DWORD *, __int64))v12)(v12, 1i64);
            }
            ++v11;
          }
          while ( v11 < v7 );
        }
        break;
      case 7:
        v8 = 0i64;
        if ( (int)u > 0 )
        {
          do
          {
            v9 = *((_QWORD *)&typeIn->m_subType + v8);
            *((_QWORD *)&typeIn->m_subType + v8) = 0i64;
            if ( v9 )
            {
              v10 = (*(_DWORD *)(v9 + 12))-- == 1;
              if ( v10 )
                (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
            }
            ++v8;
          }
          while ( v8 < v7 );
        }
        break;
    }
  }
}

// File Line: 375
// RVA: 0xE40FE0
void __fastcall hkDataClassDict::hkDataClassDict(
        hkDataClassDict *this,
        hkDataWorldDict *root,
        const char *name,
        int version)
{
  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  this->m_world = root;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataClassDict::`vftable;
  hkDataWorldDict::ObjectTracker::internClassNameHandle(root->m_tracker, &this->m_name, name);
  this->m_version = version;
  this->m_parent.m_pntr = 0i64;
  this->m_enums.m_data = 0i64;
  this->m_enums.m_size = 0;
  this->m_enums.m_capacityAndFlags = 0x80000000;
  this->m_memberInfo.m_data = 0i64;
  this->m_memberInfo.m_size = 0;
  this->m_memberInfo.m_capacityAndFlags = 0x80000000;
  this->m_hiddenMemberInfo.m_data = 0i64;
  this->m_hiddenMemberInfo.m_size = 0;
  this->m_hiddenMemberInfo.m_capacityAndFlags = 0x80000000;
}

// File Line: 447
// RVA: 0xE44590
const char *__fastcall hkDataClassDict::getName(hkDataClassDict *this)
{
  return this->m_name.m_cached.m_pntr->m_cachedString;
}

// File Line: 462
// RVA: 0xE44C50
hkBool *__fastcall hkDataClassDict::isSuperClass(hkDataClassDict *this, hkBool *result, hkDataClassImpl *k)
{
  hkDataClassImpl *v3; // rdi
  const char *v6; // rax
  hkDataWorldDict::ObjectTracker *m_tracker; // r14
  char *v8; // rsi
  const char *v9; // rbx

  v3 = k;
  if ( k )
  {
    while ( 1 )
    {
      v6 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[2].__vecDelDtor)(v3);
      m_tracker = this->m_world->m_tracker;
      v8 = (char *)v6;
      if ( v6 )
      {
        v9 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                             v6,
                             0i64);
        if ( !v9 )
        {
          v9 = hkString::strDup(v8);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            &m_tracker->m_interns.m_map,
            v9,
            (unsigned __int64)v9);
        }
      }
      else
      {
        v9 = 0i64;
      }
      if ( v9 == this->m_name.m_cached.m_pntr->m_cachedString )
        break;
      v3 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[4].__vecDelDtor)(v3);
      if ( !v3 )
        goto LABEL_8;
    }
    result->m_bool = 1;
  }
  else
  {
LABEL_8:
    result->m_bool = 0;
  }
  return result;
}

// File Line: 482
// RVA: 0xE44250
__int64 __fastcall hkDataClassDict::getDeclaredMemberIndexByName(hkDataClassDict *this, char *nameIn)
{
  unsigned int v2; // edi
  hkDataWorldDict::ObjectTracker *m_tracker; // r14
  const char *v6; // rbx
  __int64 m_size; // rdx
  __int64 v8; // rcx
  hkDataClassDict::MemberInfo *i; // rax

  v2 = 0;
  m_tracker = this->m_world->m_tracker;
  if ( nameIn )
  {
    v6 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         nameIn,
                         0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(nameIn);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v6,
        (unsigned __int64)v6);
    }
  }
  else
  {
    v6 = 0i64;
  }
  m_size = this->m_memberInfo.m_size;
  v8 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = this->m_memberInfo.m_data; i->m_name.m_cachedString != v6; ++i )
  {
    ++v8;
    ++v2;
    if ( v8 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 494
// RVA: 0xE44310
void __fastcall hkDataClassDict::getDeclaredMemberInfo(hkDataClassDict *this, int i, hkDataClass_MemberInfo *info)
{
  hkDataClassDict::MemberInfo *v3; // r9
  const char *m_cachedString; // rax

  v3 = &this->m_memberInfo.m_data[i];
  m_cachedString = v3->m_name.m_cachedString;
  info->m_owner = this;
  info->m_name = m_cachedString;
  info->m_type = v3->m_type;
  info->m_valuePtr = v3->m_valuePtr;
}

// File Line: 504
// RVA: 0xE445B0
__int64 __fastcall hkDataClassDict::getNumMembers(hkDataClassDict *this)
{
  hkDataClassDict *m_pntr; // rdx
  __int64 result; // rax

  m_pntr = this->m_parent.m_pntr;
  for ( result = (unsigned int)this->m_memberInfo.m_size; m_pntr; m_pntr = m_pntr->m_parent.m_pntr )
    result = (unsigned int)(m_pntr->m_memberInfo.m_size + result);
  return result;
}

// File Line: 516
// RVA: 0xE443C0
__int64 __fastcall hkDataClassDict::getMemberIndexByName(hkDataClassDict *this, char *nameIn)
{
  hkDataClassDict *m_pntr; // rsi
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v5; // rbx
  __int64 m_size; // rdx
  int v7; // edi
  __int64 v8; // rcx
  hkDataClassDict::MemberInfo *m_data; // rax
  int v11; // edi

  m_pntr = this;
  m_tracker = this->m_world->m_tracker;
  if ( nameIn )
  {
    v5 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         nameIn,
                         0i64);
    if ( !v5 )
    {
      v5 = hkString::strDup(nameIn);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v5,
        (unsigned __int64)v5);
    }
  }
  else
  {
    v5 = 0i64;
  }
  while ( 1 )
  {
    m_size = m_pntr->m_memberInfo.m_size;
    v7 = 0;
    v8 = 0i64;
    if ( m_size > 0 )
      break;
LABEL_9:
    m_pntr = m_pntr->m_parent.m_pntr;
    if ( !m_pntr )
      return 0xFFFFFFFFi64;
  }
  m_data = m_pntr->m_memberInfo.m_data;
  while ( m_data->m_name.m_cachedString != v5 )
  {
    ++v8;
    ++v7;
    ++m_data;
    if ( v8 >= m_size )
      goto LABEL_9;
  }
  v11 = v7 - ((__int64 (__fastcall *)(hkDataClassDict *))m_pntr->vfptr[6].__vecDelDtor)(m_pntr);
  return v11 + ((unsigned int (__fastcall *)(hkDataClassDict *))m_pntr->vfptr[9].__vecDelDtor)(m_pntr);
}

// File Line: 534
// RVA: 0xE44480
void __fastcall hkDataClassDict::getMemberInfo(hkDataClassDict *this, int memberIndex, hkDataClass_MemberInfo *info)
{
  hkDataClassDict *m_pntr; // rbx
  int v5; // edi
  __int64 v6; // rcx
  const char *v7; // rax

  m_pntr = this;
  v5 = memberIndex - ((__int64 (__fastcall *)(hkDataClassDict *))this->vfptr[9].__vecDelDtor)(this);
  while ( 1 )
  {
    v5 += m_pntr->m_memberInfo.m_size;
    if ( v5 >= 0 )
      break;
    m_pntr = m_pntr->m_parent.m_pntr;
    if ( !m_pntr )
      return;
  }
  v6 = (__int64)&m_pntr->m_memberInfo.m_data[v5];
  v7 = *(const char **)v6;
  info->m_owner = m_pntr;
  info->m_name = v7;
  info->m_type = *(hkTypeManager::Type **)(v6 + 16);
  info->m_valuePtr = *(const void **)(v6 + 24);
}

// File Line: 554
// RVA: 0xE44120
void __fastcall hkDataClassDict::getAllMemberInfo(hkDataClassDict *this, hkArrayBase<hkDataClass_MemberInfo> *infos)
{
  hkDataClassDict *m_pntr; // r8
  hkDataClass_MemberInfo *i; // r10
  __int64 m_size; // rdx
  hkDataClassDict::MemberInfo *m_data; // rcx
  hkTypeManager::Type **p_m_type; // rax
  char *v8; // r9
  hkTypeManager::Type *v9; // rcx

  m_pntr = this;
  for ( i = &infos->m_data[infos->m_size]; m_pntr; m_pntr = m_pntr->m_parent.m_pntr )
  {
    m_size = m_pntr->m_memberInfo.m_size;
    m_data = m_pntr->m_memberInfo.m_data;
    i -= m_size;
    if ( m_size > 0 )
    {
      p_m_type = &m_data->m_type;
      v8 = (char *)((char *)i - (char *)m_data);
      do
      {
        v9 = *(p_m_type - 2);
        *(hkTypeManager::Type **)((char *)p_m_type + (_QWORD)v8 - 8) = (hkTypeManager::Type *)this;
        p_m_type += 4;
        *(hkTypeManager::Type **)((char *)p_m_type + (_QWORD)v8 - 48) = v9;
        *(hkTypeManager::Type **)((char *)p_m_type + (_QWORD)v8 - 32) = *(p_m_type - 4);
        *(hkTypeManager::Type **)((char *)p_m_type + (_QWORD)v8 - 24) = *(p_m_type - 3);
        --m_size;
      }
      while ( m_size );
    }
  }
}

// File Line: 624
// RVA: 0xE42840
void __fastcall hkDataClassDict::addMember(
        hkDataClassDict *this,
        InternedString name,
        hkTypeManager::Type *type,
        const char *valuePtr)
{
  hkArrayBase<hkDataClassDict::MemberInfo> *p_m_memberInfo; // rdi
  InternedString *p_m_name; // rax

  p_m_memberInfo = &this->m_memberInfo;
  if ( this->m_memberInfo.m_size == (this->m_memberInfo.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_world->m_allocator, (const void **)&p_m_memberInfo->m_data, 32);
  p_m_name = &p_m_memberInfo->m_data[p_m_memberInfo->m_size].m_name;
  if ( p_m_name )
  {
    p_m_name->m_cachedString = name.m_cachedString;
    p_m_name[1].m_cachedString = 0i64;
    p_m_name[2].m_cachedString = (const char *)type;
    p_m_name[3].m_cachedString = valuePtr;
  }
  ++p_m_memberInfo->m_size;
}

// File Line: 635
// RVA: 0xE45350
hkResult *__fastcall hkDataClassDict::removeMember(hkDataClassDict *this, hkResult *result, InternedString name)
{
  hkDataClassDict *m_pntr; // r9
  int v4; // r11d
  int v6; // r10d
  __int64 v7; // rcx
  const char **p_m_cachedString; // rax
  int v9; // r11d
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  hkResultEnum v13; // r11d
  __int64 m_size; // r10
  int v15; // edx
  __int64 v16; // rcx
  const char **v17; // rax
  hkResult *v18; // rax

  m_pntr = this;
  v4 = this->m_memberInfo.m_size - 1;
  v6 = v4;
  v7 = v4;
  if ( v4 < 0 )
  {
LABEL_5:
    v6 = -1;
  }
  else
  {
    p_m_cachedString = &m_pntr->m_memberInfo.m_data[v4].m_name.m_cachedString;
    while ( *p_m_cachedString != name.m_cachedString )
    {
      --v6;
      p_m_cachedString -= 4;
      if ( --v7 < 0 )
        goto LABEL_5;
    }
  }
  m_pntr->m_memberInfo.m_size = v4;
  v9 = 32 * (v4 - v6);
  v10 = (__int64)&m_pntr->m_memberInfo.m_data[v6];
  if ( v9 > 0 )
  {
    v11 = ((unsigned int)(v9 - 1) >> 3) + 1;
    do
    {
      v12 = *(_QWORD *)(v10 + 32);
      v10 += 8i64;
      *(_QWORD *)(v10 - 8) = v12;
      --v11;
    }
    while ( v11 );
  }
  v13 = HK_SUCCESS;
  while ( 1 )
  {
    m_size = m_pntr->m_memberInfo.m_size;
    v15 = 0;
    v16 = 0i64;
    if ( m_size > 0 )
      break;
LABEL_14:
    m_pntr = m_pntr->m_parent.m_pntr;
    if ( !m_pntr )
    {
      v18 = result;
      LOBYTE(v13) = 0;
      result->m_enum = v13;
      return v18;
    }
  }
  v17 = &m_pntr->m_memberInfo.m_data->m_name.m_cachedString;
  while ( *v17 != name.m_cachedString )
  {
    ++v16;
    ++v15;
    v17 += 4;
    if ( v16 >= m_size )
      goto LABEL_14;
  }
  v18 = result;
  LOBYTE(v13) = &m_pntr->m_memberInfo.m_data[v15] != 0;
  result->m_enum = v13;
  return v18;
}

// File Line: 714
// RVA: 0xE459A0
void __fastcall hkDataClassDict::selfDestruct(hkDataClassDict *this)
{
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rsi
  int v4; // ebp
  __int64 v5; // r14
  hkDataClassDict::Enum *v6; // rdi
  int v7; // r8d
  _QWORD **Value; // rax
  int v9; // r8d
  InternedStringRefCounted *m_pntr; // rcx

  m_capacityAndFlags = this->m_memberInfo.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_memberInfo.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_memberInfo.m_data, 32 * m_capacityAndFlags);
  this->m_memberInfo.m_data = 0i64;
  this->m_memberInfo.m_capacityAndFlags = 0x80000000;
  v4 = 0;
  if ( this->m_enums.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = this->m_enums.m_data[v5];
      v7 = v6->m_items.m_capacityAndFlags;
      v6->m_items.m_size = 0;
      if ( v7 >= 0 )
        m_allocator->vfptr->bufFree(m_allocator, v6->m_items.m_data, 16 * v7);
      v6->m_items.m_data = 0i64;
      v6->m_items.m_capacityAndFlags = 0x80000000;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkDataClassDict::Enum *, __int64))(*Value[11] + 16i64))(Value[11], v6, 24i64);
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_enums.m_size );
  }
  v9 = this->m_enums.m_capacityAndFlags;
  this->m_enums.m_size = 0;
  if ( v9 >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_enums.m_data, 8 * v9);
  this->m_enums.m_data = 0i64;
  this->m_enums.m_capacityAndFlags = 0x80000000;
  hkReferencedObject::addReference(&InternedNullRefCounted);
  m_pntr = this->m_name.m_cached.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_name.m_cached.m_pntr = &InternedNullRefCounted;
}

// File Line: 792
// RVA: 0xE44880
const char *__fastcall SSUnaryParam::get_expected_type(hkDynamicClassNameRegistry *this)
{
  return this->m_name;
}

// File Line: 797
// RVA: 0xE440C0
void __fastcall hkDataObjectDict::getAllMemberHandles(
        hkDataObjectDict *this,
        hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  const struct _hkDataObject_MemberHandle **v2; // r9
  hkDataClassDict *i; // r8
  __int64 m_size; // rdx
  hkDataClassDict::MemberInfo *m_data; // rcx
  __int64 j; // rax

  v2 = &handles->m_data[handles->m_size];
  for ( i = this->m_class.m_pntr; i; i = i->m_parent.m_pntr )
  {
    m_size = i->m_memberInfo.m_size;
    m_data = i->m_memberInfo.m_data;
    v2 -= m_size;
    for ( j = 0i64; j < m_size; ++m_data )
      v2[j++] = (const struct _hkDataObject_MemberHandle *)m_data;
  }
}

// File Line: 802
// RVA: 0xE45AE0
void __fastcall hkDataObjectDict::selfDestruct(hkDataObjectDict *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataObjectDict::MemberData *m_data; // r11
  hkDataClassDict *m_pntr; // r9
  __int64 m_size; // r10
  int v7; // r8d
  __int64 v8; // rdx
  hkDataClassDict::MemberInfo *v9; // rcx
  __int64 v10; // rcx
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  unsigned int v13; // [rsp+20h] [rbp-8h]

  v1 = 0;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_memberData.m_data;
      m_pntr = this->m_class.m_pntr;
      if ( m_pntr )
      {
        while ( 1 )
        {
          m_size = m_pntr->m_memberInfo.m_size;
          v7 = 0;
          v8 = 0i64;
          if ( m_size > 0 )
            break;
LABEL_8:
          m_pntr = m_pntr->m_parent.m_pntr;
          if ( !m_pntr )
            goto LABEL_12;
        }
        v9 = m_pntr->m_memberInfo.m_data;
        while ( v9->m_name.m_cachedString != m_data[v3].m_memberName.m_cachedString )
        {
          ++v8;
          ++v7;
          ++v9;
          if ( v8 >= m_size )
            goto LABEL_8;
        }
        v10 = (__int64)&m_pntr->m_memberInfo.m_data[v7];
        if ( v10 )
          `anonymous namespace::Union::clearArray(
            *(Union **)(v10 + 16),
            (hkTypeManager::Type *)&m_data[v1].m_value,
            (Union *)1,
            0,
            v13);
      }
LABEL_12:
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_memberData.m_size );
  }
  m_capacityAndFlags = this->m_memberData.m_capacityAndFlags;
  m_allocator = this->m_class.m_pntr->m_world->m_allocator;
  this->m_memberData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_memberData.m_data, 16 * m_capacityAndFlags);
  this->m_memberData.m_capacityAndFlags = 0x80000000;
  this->m_memberData.m_data = 0i64;
}

// File Line: 811
// RVA: 0xE43C30
void __fastcall hkDataObjectDict::destroy(hkDataObjectDict *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataObjectDict::MemberData *m_data; // r11
  hkDataClassDict *m_pntr; // r9
  __int64 m_size; // r10
  int v7; // r8d
  __int64 v8; // rdx
  hkDataClassDict::MemberInfo *v9; // rcx
  __int64 v10; // rcx
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  unsigned int v13; // [rsp+20h] [rbp-8h]

  v1 = 0;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_memberData.m_data;
      m_pntr = this->m_class.m_pntr;
      if ( m_pntr )
      {
        while ( 1 )
        {
          m_size = m_pntr->m_memberInfo.m_size;
          v7 = 0;
          v8 = 0i64;
          if ( m_size > 0 )
            break;
LABEL_8:
          m_pntr = m_pntr->m_parent.m_pntr;
          if ( !m_pntr )
            goto LABEL_12;
        }
        v9 = m_pntr->m_memberInfo.m_data;
        while ( v9->m_name.m_cachedString != m_data[v3].m_memberName.m_cachedString )
        {
          ++v8;
          ++v7;
          ++v9;
          if ( v8 >= m_size )
            goto LABEL_8;
        }
        v10 = (__int64)&m_pntr->m_memberInfo.m_data[v7];
        if ( v10 )
          `anonymous namespace::Union::clearArray(
            *(Union **)(v10 + 16),
            (hkTypeManager::Type *)&m_data[v1].m_value,
            (Union *)1,
            1,
            v13);
      }
LABEL_12:
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_memberData.m_size );
  }
  m_capacityAndFlags = this->m_memberData.m_capacityAndFlags;
  m_allocator = this->m_class.m_pntr->m_world->m_allocator;
  this->m_memberData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_memberData.m_data, 16 * m_capacityAndFlags);
  this->m_memberData.m_capacityAndFlags = 0x80000000;
  this->m_memberData.m_data = 0i64;
}

// File Line: 820
// RVA: 0xE45450
void __fastcall hkDataObjectDict::removeMember(hkDataObjectDict *this, InternedString name)
{
  __int64 m_size; // r9
  int v3; // ebx
  __int64 v4; // r8
  hkDataObjectDict::MemberData *i; // rax
  hkDataClassDict *m_pntr; // r9
  hkDataObjectDict::MemberData *v8; // r11
  __int64 v9; // r10
  int v10; // r8d
  __int64 v11; // rdx
  hkDataClassDict::MemberInfo *m_data; // rcx
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // r8
  hkDataObjectDict::MemberData *v17; // rcx
  __int64 v18; // r8
  Union v19; // rax
  unsigned int v20; // [rsp+20h] [rbp-8h]

  m_size = this->m_memberData.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_memberData.m_data; i->m_memberName.m_cachedString != name.m_cachedString; ++i )
    {
      ++v4;
      ++v3;
      if ( v4 >= m_size )
        return;
    }
    m_pntr = this->m_class.m_pntr;
    v8 = &this->m_memberData.m_data[v3];
    if ( m_pntr )
    {
      while ( 1 )
      {
        v9 = m_pntr->m_memberInfo.m_size;
        v10 = 0;
        v11 = 0i64;
        if ( v9 > 0 )
          break;
LABEL_11:
        m_pntr = m_pntr->m_parent.m_pntr;
        if ( !m_pntr )
          goto LABEL_15;
      }
      m_data = m_pntr->m_memberInfo.m_data;
      while ( m_data->m_name.m_cachedString != v8->m_memberName.m_cachedString )
      {
        ++v11;
        ++v10;
        ++m_data;
        if ( v11 >= v9 )
          goto LABEL_11;
      }
      v13 = (__int64)&m_pntr->m_memberInfo.m_data[v10];
      if ( v13 )
        `anonymous namespace::Union::clearArray(
          *(Union **)(v13 + 16),
          (hkTypeManager::Type *)&v8->m_value,
          (Union *)1,
          0,
          v20);
    }
LABEL_15:
    v14 = --this->m_memberData.m_size;
    if ( (_DWORD)v14 != v3 )
    {
      v15 = 2i64;
      v16 = 16 * v14;
      v17 = &this->m_memberData.m_data[v3];
      v18 = v16 - 16i64 * v3;
      do
      {
        v19.i = *(__int64 *)((char *)&v17->m_memberName.m_cachedString + v18);
        v17 = (hkDataObjectDict::MemberData *)((char *)v17 + 8);
        v17[-1].m_value = v19;
        --v15;
      }
      while ( v15 );
    }
  }
}

// File Line: 849
// RVA: 0xE44D20
_BOOL8 __fastcall hkDataObjectDict::isValid(hkDataObjectDict *this, int it)
{
  return it < this->m_memberData.m_size;
}

// File Line: 858
// RVA: 0xE44540
const char *__fastcall hkDataObjectDict::getMemberName(hkDataObjectDict *this, int it)
{
  return this->m_memberData.m_data[it].m_memberName.m_cachedString;
}

// File Line: 862
// RVA: 0xE44570
hkDataObject_Value *__fastcall hkDataObjectDict::getMemberValue(
        hkDataObjectDict *this,
        hkDataObject_Value *result,
        int it)
{
  hkDataObjectDict::MemberData *m_data; // rax
  const struct _hkDataObject_MemberHandle *m_cachedString; // rcx
  hkDataObject_Value *v5; // rax

  m_data = this->m_memberData.m_data;
  result->m_impl = this;
  m_cachedString = (const struct _hkDataObject_MemberHandle *)m_data[it].m_memberName.m_cachedString;
  v5 = result;
  result->m_handle = m_cachedString;
  return v5;
}

// File Line: 881
// RVA: 0xE421A0
hkDataObjectDict::MemberAccess *__fastcall hkDataObjectDict::_readAccess(
        hkDataObjectDict *this,
        hkDataObjectDict::MemberAccess *result,
        const struct _hkDataObject_MemberHandle *handle,
        hkTypeManager::SubType subType)
{
  int m_size; // r10d
  unsigned int v5; // ebp
  int v6; // esi
  int v9; // eax
  hkDataObjectDict::MemberData *m_data; // r9
  bool v11; // zf
  hkDataObjectDict::MemberData *v12; // rax
  hkDataObjectDict::MemberData *v13; // r14
  hkTypeManager::Type *v14; // r13
  hkTypeManager::SubType m_subType; // ecx
  Union v16; // rax
  hkDataClassDict *m_pntr; // rax
  _QWORD *v18; // rax
  __int64 v19; // rbx
  _QWORD *v20; // rdi
  unsigned int TupleSize; // eax
  int v22; // eax
  __int64 v23; // rbx
  __int64 i; // rdi
  hkDataWorldDict *m_world; // rbx
  hkBaseObjectVtbl *vfptr; // rdi
  const char *TypeName; // rax
  hkTypeManager::Type *v28; // rax
  __int64 v29; // r8
  __int64 v30; // rax
  float *v31; // rdx
  hkDataObjectDict::MemberAccess *v32; // rax
  hkTypeManager::Type *m_parent; // [rsp+60h] [rbp+8h] BYREF
  hkDataObjectDict::MemberAccess *v34; // [rsp+68h] [rbp+10h]

  v34 = result;
  m_size = this->m_memberData.m_size;
  v5 = 0;
  v6 = -1;
  v9 = 0;
  if ( m_size <= 0 )
    goto LABEL_7;
  m_data = this->m_memberData.m_data;
  do
  {
    v11 = m_data->m_memberName.m_cachedString == *(const char **)handle;
    ++m_data;
    if ( v11 )
      v6 = v9;
    ++v9;
  }
  while ( v9 < m_size );
  if ( v6 == -1 )
  {
LABEL_7:
    v6 = this->m_memberData.m_size;
    if ( m_size == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        this->m_class.m_pntr->m_world->m_allocator,
        (const void **)&this->m_memberData.m_data,
        16);
    v12 = &this->m_memberData.m_data[this->m_memberData.m_size];
    if ( v12 )
      v12->m_memberName.m_cachedString = 0i64;
    v13 = &this->m_memberData.m_data[this->m_memberData.m_size++];
    v13->m_memberName.m_cachedString = *(const char **)handle;
    v14 = (hkTypeManager::Type *)*((_QWORD *)handle + 2);
    m_subType = v14->m_subType;
    if ( v14->m_subType == SUB_TYPE_ARRAY )
    {
      hkDataArrayDict_create(this->m_class.m_pntr->m_world, v14->m_parent, 0);
      v13->m_value = v16;
      ++*(_DWORD *)(v16.i + 12);
      goto LABEL_33;
    }
    switch ( m_subType )
    {
      case SUB_TYPE_TUPLE:
        m_pntr = this->m_class.m_pntr;
        m_parent = v14->m_parent;
        hkDataArrayDict_create(m_pntr->m_world, m_parent, 0);
        v13->m_value.i = (__int64)v18;
        v19 = *v18;
        v20 = v18;
        TupleSize = hkTypeManager::Type::getTupleSize(v14);
        (*(void (__fastcall **)(_QWORD *, _QWORD))(v19 + 32))(v20, TupleSize);
        ++*(_DWORD *)(v13->m_value.i + 12);
        if ( *((_QWORD *)handle + 3) )
        {
          if ( m_parent->m_subType == SUB_TYPE_REAL )
          {
            v22 = hkTypeManager::Type::getTupleSize(v14);
            v23 = 0i64;
            for ( i = v22; v23 < i; ++v5 )
            {
              (*(void (__fastcall **)(Union, _QWORD))(*(_QWORD *)v13->m_value.i + 128i64))(v13->m_value, v5);
              ++v23;
            }
          }
        }
        goto LABEL_33;
      case SUB_TYPE_POINTER:
        goto LABEL_32;
      case SUB_TYPE_CLASS:
        m_world = this->m_class.m_pntr->m_world;
        vfptr = m_world->vfptr;
        TypeName = hkTypeManager::Type::getTypeName(v14);
        v28 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))vfptr[4].__first_virtual_table_function__)(
                                       m_world,
                                       TypeName);
        LOBYTE(v29) = 1;
        m_parent = v28;
        v30 = ((__int64 (__fastcall *)(hkDataWorldDict *, hkTypeManager::Type **, __int64))this->m_class.m_pntr->m_world->vfptr[2].__vecDelDtor)(
                this->m_class.m_pntr->m_world,
                &m_parent,
                v29);
        if ( v30 )
        {
          ++*(_WORD *)(v30 + 10);
          ++*(_DWORD *)(v30 + 12);
        }
        v13->m_value.i = v30;
        ++*(_DWORD *)(v30 + 12);
        --*(_WORD *)(v30 + 10);
        v11 = (*(_DWORD *)(v30 + 12))-- == 1;
        if ( v11 )
          (**(void (__fastcall ***)(__int64, __int64))v30)(v30, 1i64);
        goto LABEL_33;
    }
    v31 = (float *)*((_QWORD *)handle + 3);
    if ( !v31 )
    {
LABEL_32:
      v13->m_value.i = 0i64;
      goto LABEL_33;
    }
    if ( ((m_subType - 2) & 0xFFFFFFFD) != 0 )
    {
      if ( m_subType == SUB_TYPE_REAL )
      {
        v13->m_value.r = *v31;
      }
      else if ( m_subType == SUB_TYPE_CSTRING )
      {
        v13->m_value.i = (__int64)hkString::strDup(*((char **)handle + 3));
      }
    }
    else
    {
      v13->m_value.i = *(_QWORD *)v31;
    }
  }
LABEL_33:
  v32 = v34;
  v34->info = (hkDataClassDict::MemberInfo *)handle;
  v32->index = v6;
  return v32;
}

// File Line: 976
// RVA: 0xE42540
hkDataObjectDict::MemberAccess *__fastcall hkDataObjectDict::_writeAccess(
        hkDataObjectDict *this,
        hkDataObjectDict::MemberAccess *result,
        Union **handle,
        hkTypeManager::SubType subType)
{
  __int64 m_size; // rbp
  int v5; // ebx
  __int64 v6; // r9
  hkDataObjectDict::MemberData *m_data; // rax
  hkArrayBase<hkDataObjectDict::MemberData> *p_m_memberData; // rbx
  hkDataObjectDict::MemberData *v11; // rax
  __int64 v12; // rax
  _QWORD *p_m_cachedString; // rcx
  Union *v14; // rax
  unsigned int v16; // [rsp+20h] [rbp-8h]

  m_size = this->m_memberData.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    p_m_memberData = &this->m_memberData;
    if ( this->m_memberData.m_size == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        this->m_class.m_pntr->m_world->m_allocator,
        (const void **)&this->m_memberData.m_data,
        16);
    v11 = &p_m_memberData->m_data[p_m_memberData->m_size];
    if ( v11 )
      v11->m_memberName.m_cachedString = 0i64;
    v12 = p_m_memberData->m_size;
    result->index = m_size;
    p_m_cachedString = &p_m_memberData->m_data[v12].m_memberName.m_cachedString;
    p_m_memberData->m_size = v12 + 1;
    v14 = *handle;
    p_m_cachedString[1] = 0i64;
    *p_m_cachedString = v14;
  }
  else
  {
    m_data = this->m_memberData.m_data;
    while ( (Union *)m_data->m_memberName.m_cachedString != *handle )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    `anonymous namespace::Union::clearArray(
      handle[2],
      (hkTypeManager::Type *)&this->m_memberData.m_data[v5].m_value,
      (Union *)1,
      0,
      v16);
    result->index = v5;
  }
  result->info = (hkDataClassDict::MemberInfo *)handle;
  return result;
}

// File Line: 998
// RVA: 0xE42120
__int64 __fastcall hkDataObjectDict::_hasMember(hkDataObjectDict *this, InternedString name)
{
  __int64 m_size; // r9
  unsigned int v3; // r11d
  __int64 v4; // r8
  hkDataObjectDict::MemberData *m_data; // rax
  hkDataClassDict *i; // r9
  __int64 v7; // r10
  int v8; // r8d
  __int64 v9; // rcx
  const char **p_m_cachedString; // rax
  __int64 v12; // rcx

  m_size = this->m_memberData.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    for ( i = this->m_class.m_pntr; i; i = i->m_parent.m_pntr )
    {
      v7 = i->m_memberInfo.m_size;
      v8 = 0;
      v9 = 0i64;
      if ( v7 > 0 )
      {
        p_m_cachedString = &i->m_memberInfo.m_data->m_name.m_cachedString;
        while ( *p_m_cachedString != name.m_cachedString )
        {
          ++v9;
          ++v8;
          p_m_cachedString += 4;
          if ( v9 >= v7 )
            goto LABEL_11;
        }
        v12 = (__int64)&i->m_memberInfo.m_data[v8];
        if ( v12 )
        {
          LOBYTE(v3) = *(_QWORD *)(v12 + 24) != 0i64;
          return v3;
        }
        return 0i64;
      }
LABEL_11:
      ;
    }
    return 0i64;
  }
  else
  {
    m_data = this->m_memberData.m_data;
    while ( m_data->m_memberName.m_cachedString != name.m_cachedString )
    {
      ++v4;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
    return 1i64;
  }
}

// File Line: 1015
// RVA: 0xE44900
__int64 __fastcall hkDataObjectDict::hasMember(hkDataObjectDict *this, char *name)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v5; // rbx

  m_tracker = this->m_class.m_pntr->m_world->m_tracker;
  if ( name )
  {
    v5 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         name,
                         0i64);
    if ( !v5 )
    {
      v5 = hkString::strDup(name);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v5,
        (unsigned __int64)v5);
    }
  }
  else
  {
    v5 = 0i64;
  }
  return hkDataObjectDict::_hasMember(this, (InternedString)v5);
}

// File Line: 1020
// RVA: 0xE44C10
__int64 __fastcall hkDataObjectDict::isSet(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  __int64 m_size; // rdx
  __int64 v6; // rcx
  const char *v7; // r8
  hkDataObjectDict::MemberData *i; // rax

  if ( *((_QWORD *)handle + 3) )
    return 1i64;
  m_size = this->m_memberData.m_size;
  v6 = 0i64;
  if ( m_size > 0 )
  {
    v7 = *(const char **)handle;
    for ( i = this->m_memberData.m_data; i->m_memberName.m_cachedString != v7; ++i )
    {
      if ( ++v6 >= m_size )
        return 0i64;
    }
    return 1i64;
  }
  return 0i64;
}

// File Line: 1041
// RVA: 0xE42740
hkDataObject_Value *__fastcall hkDataObjectDict::accessByName(
        hkDataObjectDict *this,
        hkDataObject_Value *result,
        char *name)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v7; // rbx
  hkDataClassDict *m_pntr; // r8
  __int64 m_size; // r9
  int v10; // edx
  __int64 v11; // rcx
  hkDataClassDict::MemberInfo *m_data; // rax
  const struct _hkDataObject_MemberHandle *v14; // rax

  m_tracker = this->m_class.m_pntr->m_world->m_tracker;
  if ( name )
  {
    v7 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         name,
                         0i64);
    if ( !v7 )
    {
      v7 = hkString::strDup(name);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v7,
        (unsigned __int64)v7);
    }
  }
  else
  {
    v7 = 0i64;
  }
  m_pntr = this->m_class.m_pntr;
  if ( !m_pntr )
    goto LABEL_11;
  while ( 1 )
  {
    m_size = m_pntr->m_memberInfo.m_size;
    v10 = 0;
    v11 = 0i64;
    if ( m_size > 0 )
      break;
LABEL_10:
    m_pntr = m_pntr->m_parent.m_pntr;
    if ( !m_pntr )
      goto LABEL_11;
  }
  m_data = m_pntr->m_memberInfo.m_data;
  while ( m_data->m_name.m_cachedString != v7 )
  {
    ++v11;
    ++v10;
    ++m_data;
    if ( v11 >= m_size )
      goto LABEL_10;
  }
  v14 = (const struct _hkDataObject_MemberHandle *)&m_pntr->m_memberInfo.m_data[v10];
  if ( v14 )
  {
    result->m_handle = v14;
    result->m_impl = this;
    return result;
  }
  else
  {
LABEL_11:
    result->m_impl = 0i64;
    result->m_handle = 0i64;
    return result;
  }
}

// File Line: 1058
// RVA: 0xE42A90
hkDataArrayImpl *__fastcall hkDataObjectDict::asArray(
        hkDataObjectDict *this,
        const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_ARRAY);
  return this->m_memberData.m_data[result.index].m_value.a;
}

// File Line: 1065
// RVA: 0xE43080
const char *__fastcall hkDataObjectDict::asString(
        hkDataObjectDict *this,
        const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_CSTRING);
  return this->m_memberData.m_data[result.index].m_value.s;
}

// File Line: 1072
// RVA: 0xE42C80
Union __fastcall hkDataObjectDict::asInt(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_VOID);
  if ( ((result.info->m_type->m_subType - 2) & 0xFFFFFFFD) != 0 )
    return 0i64;
  else
    return this->m_memberData.m_data[result.index].m_value;
}

// File Line: 1084
// RVA: 0xE42DB0
hkDataObjectImpl *__fastcall hkDataObjectDict::asObject(
        hkDataObjectDict *this,
        const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_CLASS);
  return this->m_memberData.m_data[result.index].m_value.o;
}

// File Line: 1090
// RVA: 0xE43160
hkDataRefCountedVtbl *__fastcall hkDataObjectDict::asVec(
        hkDataObjectDict *this,
        const struct _hkDataObject_MemberHandle *handle,
        int nreal)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_TUPLE);
  return hkRealArrayImplementation_getReals(this->m_memberData.m_data[result.index].m_value.a, nreal);
}

// File Line: 1099
// RVA: 0xE42E70
float __fastcall hkDataObjectDict::asReal(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_REAL);
  return this->m_memberData.m_data[result.index].m_value.r;
}

// File Line: 1106
// RVA: 0xE43520
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, hkDataObject_Value *value)
{
  hkDataObjectImpl *m_impl; // rdi
  hkTypeManager::Type *m_type; // r10
  hkTypeManager::SubType m_subType; // r8d
  hkTypeManager::Type *v8; // rdx
  __int64 v9; // r9
  __int64 v10; // rax
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-28h] BYREF
  hkDataObjectDict::MemberAccess v12; // [rsp+30h] [rbp-18h] BYREF

  m_impl = value->m_impl;
  hkDataObjectDict::_readAccess((hkDataObjectDict *)value->m_impl, &result, value->m_handle, SUB_TYPE_VOID);
  hkDataObjectDict::_writeAccess(this, &v12, handle, SUB_TYPE_VOID);
  m_type = result.info->m_type;
  m_subType = m_type->m_subType;
  v8 = v12.info->m_type;
  v9 = 2i64 * result.index;
  v10 = *(_QWORD *)(*(_QWORD *)&m_impl[1].m_memSize + 16i64 * result.index + 8);
  if ( (unsigned int)(m_type->m_subType - 8) <= 1 )
  {
    if ( (unsigned int)(v8->m_subType - 8) > 1 )
      goto LABEL_10;
    goto LABEL_8;
  }
  if ( m_subType == SUB_TYPE_POINTER && v8->m_subType == SUB_TYPE_POINTER || m_subType == SUB_TYPE_CLASS && m_type == v8 )
  {
LABEL_8:
    if ( v10 )
      ++*(_DWORD *)(v10 + 12);
  }
LABEL_10:
  this->m_memberData.m_data[v12.index].m_value.i = *(_QWORD *)(*(_QWORD *)&m_impl[1].m_memSize + 8 * v9 + 8);
}

// File Line: 1150
// RVA: 0xE43750
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, hkDataObjectImpl *value)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  if ( value )
    ++value->m_count;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_CLASS);
  this->m_memberData.m_data[result.index].m_value.i = (__int64)value;
}

// File Line: 1160
// RVA: 0xE436B0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, hkDataArrayImpl *value)
{
  hkTypeManager::Type *v5; // rbp
  hkTypeManager::Type *m_parent; // rsi
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF
  hkBool v8; // [rsp+50h] [rbp+18h] BYREF

  ++value->m_count;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  v5 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataArrayImpl *))value->vfptr[1].__vecDelDtor)(value);
  m_parent = result.info->m_type->m_parent;
  if ( hkTypeManager::Type::isEqual(m_parent, &v8, v5)->m_bool
    || m_parent->m_subType == SUB_TYPE_CLASS
    && !hkTypeManager::Type::getTypeName(m_parent)
    && v5->m_subType == SUB_TYPE_CLASS )
  {
    this->m_memberData.m_data[result.index].m_value.i = (__int64)value;
  }
}

// File Line: 1186
// RVA: 0xE437A0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, char *value)
{
  char *v5; // rdx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_CSTRING);
  if ( value )
    v5 = hkString::strDup(value);
  else
    v5 = 0i64;
  this->m_memberData.m_data[result.index].m_value.i = (__int64)v5;
}

// File Line: 1192
// RVA: 0xE43660
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, float r)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-28h] BYREF

  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_REAL);
  this->m_memberData.m_data[result.index].m_value.r = r;
}

// File Line: 1198
// RVA: 0xE438D0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, hkHalf r)
{
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_REAL);
  LODWORD(this->m_memberData.m_data[result.index].m_value.r) = r.m_value << 16;
}

// File Line: 1204
// RVA: 0xE43800
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, const float *r, int nreal)
{
  hkTypeManager::Type *m_type; // rsi
  hkTypeManager::Type *m_parent; // rdx
  hkDataObjectDict::MemberData *v9; // rdi
  __int64 *v10; // rax
  __int64 v11; // rbx
  unsigned int TupleSize; // eax
  hkDataRefCountedVtbl *Reals; // rax
  unsigned int v14; // r8d
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  m_type = result.info->m_type;
  if ( m_type->m_subType == SUB_TYPE_TUPLE )
  {
    m_parent = m_type->m_parent;
    if ( m_parent->m_subType == SUB_TYPE_REAL )
    {
      v9 = &this->m_memberData.m_data[result.index];
      if ( !v9->m_value.i )
      {
        hkDataArrayDict_create(this->m_class.m_pntr->m_world, m_parent, 0);
        v9->m_value.i = (__int64)v10;
        v11 = *v10;
        TupleSize = hkTypeManager::Type::getTupleSize(m_type);
        (*(void (__fastcall **)(Union, _QWORD))(v11 + 32))(v9->m_value, TupleSize);
        ++*(_DWORD *)(v9->m_value.i + 12);
      }
      Reals = hkRealArrayImplementation_getReals(v9->m_value.a, nreal);
      hkString::memCpy(Reals, r, v14);
    }
  }
}

// File Line: 1230
// RVA: 0xE43920
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, Union valueIn)
{
  hkTypeManager::Type *m_type; // rcx
  hkDataObjectDict::MemberData *v6; // r9
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  m_type = result.info->m_type;
  v6 = &this->m_memberData.m_data[result.index];
  switch ( m_type->m_subType )
  {
    case SUB_TYPE_BYTE:
      goto LABEL_4;
    case SUB_TYPE_REAL:
      v6->m_value.r = (float)SLODWORD(valueIn.r);
      return;
    case SUB_TYPE_INT:
LABEL_4:
      v6->m_value = valueIn;
      break;
  }
}

// File Line: 1249
// RVA: 0xE435F0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, Union **handle, int valueIn)
{
  Union v3; // rdi
  hkTypeManager::Type *m_type; // rcx
  hkDataObjectDict::MemberData *v6; // r9
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h] BYREF

  v3.i = valueIn;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  m_type = result.info->m_type;
  v6 = &this->m_memberData.m_data[result.index];
  switch ( m_type->m_subType )
  {
    case SUB_TYPE_BYTE:
      goto LABEL_4;
    case SUB_TYPE_REAL:
      v6->m_value.r = (float)SLODWORD(v3.r);
      return;
    case SUB_TYPE_INT:
LABEL_4:
      v6->m_value = v3;
      break;
  }
}

// File Line: 1301
// RVA: 0xE43990
void __fastcall BasicArrayImplementation<hkDataArrayImpl *>::clear(VecArrayImplementation *this)
{
  this->m_data.m_size = 0;
}

// File Line: 1305
// RVA: 0xE455E0
void __fastcall BasicArrayImplementation<hkDataArrayImpl *>::reserve(
        BasicArrayImplementation<hkDataObjectImpl *> *this,
        int n)
{
  int v2; // r9d
  int v3; // eax
  int v4; // eax
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v2 = n;
  v3 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < n )
  {
    v4 = 2 * v3;
    if ( n < v4 )
      v2 = v4;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v2, 8);
  }
}

// File Line: 1309
// RVA: 0xE467F0
void __fastcall BasicArrayImplementation<hkDataObjectImpl *>::setSize(
        BasicArrayImplementation<hkDataObjectImpl *> *this,
        int n)
{
  hkArrayBase<hkDataObjectImpl *> *p_m_data; // rbx
  int v4; // eax
  int v5; // r9d
  int v6; // eax
  int v7; // edx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  p_m_data = &this->m_data;
  v4 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < n )
  {
    v5 = n;
    v6 = 2 * v4;
    if ( n < v6 )
      v5 = v6;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v5, 8);
  }
  v7 = n - p_m_data->m_size;
  if ( v7 > 0 )
    memset(&p_m_data->m_data[p_m_data->m_size], 0, 8i64 * v7);
  p_m_data->m_size = n;
}

// File Line: 1331
// RVA: 0xE413A0
void __fastcall VariableIntArrayImplementation::~VariableIntArrayImplementation(VariableIntArrayImplementation *this)
{
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  int v4; // r8d
  hkMemoryAllocator *v5; // rcx

  this->vfptr = (hkDataRefCountedVtbl *)&VariableIntArrayImplementation::`vftable;
  m_capacityAndFlags = this->m_int32Array.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_int32Array.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_int32Array.m_data, 4 * m_capacityAndFlags);
  this->m_int32Array.m_data = 0i64;
  this->m_int32Array.m_capacityAndFlags = 0x80000000;
  v4 = this->m_int64Array.m_capacityAndFlags;
  v5 = this->m_world->m_allocator;
  this->m_int64Array.m_size = 0;
  if ( v4 >= 0 )
    v5->vfptr->bufFree(v5, this->m_int64Array.m_data, 8 * v4);
  this->m_int64Array.m_data = 0i64;
  this->m_int64Array.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 1338
// RVA: 0xE44820
hkTypeManager::Type *__fastcall VariableIntArrayImplementation::getType(VariableIntArrayImplementation *this)
{
  return this->m_world->m_typeManager.m_builtInTypes[4];
}

// File Line: 1343
// RVA: 0xE44860
__int64 __fastcall VariableIntArrayImplementation::getUnderlyingIntegerSize(VariableIntArrayImplementation *this)
{
  __int64 result; // rax

  result = 8i64;
  if ( !this->m_arrayType )
    return 4i64;
  return result;
}

// File Line: 1355
// RVA: 0xE43A90
void __fastcall VariableIntArrayImplementation::clear(VariableIntArrayImplementation *this)
{
  hkDataWorldDict *m_world; // rax
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx

  m_world = this->m_world;
  this->m_int32Array.m_size = 0;
  m_capacityAndFlags = this->m_int64Array.m_capacityAndFlags;
  m_allocator = m_world->m_allocator;
  this->m_int64Array.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_int64Array.m_data, 8 * m_capacityAndFlags);
  this->m_int64Array.m_data = 0i64;
  this->m_int64Array.m_capacityAndFlags = 0x80000000;
  this->m_arrayType = 0;
  this->m_assigned.m_bool = 0;
}

// File Line: 1369
// RVA: 0xE456A0
void __fastcall VariableIntArrayImplementation::reserve(VariableIntArrayImplementation *this, int n)
{
  int m_arrayType; // edx
  const void **p_m_data; // r8
  int v5; // eax
  hkDataWorldDict *m_world; // rdx
  hkResult *p_result; // rcx
  hkMemoryAllocator *m_allocator; // rdx
  int v9; // eax
  int sizeElem; // [rsp+20h] [rbp-18h]
  char v11; // [rsp+40h] [rbp+8h] BYREF
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  m_arrayType = this->m_arrayType;
  if ( m_arrayType )
  {
    if ( m_arrayType != 1 )
      return;
    p_m_data = (const void **)&this->m_int64Array.m_data;
    v5 = this->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 >= n )
      return;
    m_world = this->m_world;
    sizeElem = 8;
    p_result = (hkResult *)&v11;
  }
  else
  {
    p_m_data = (const void **)&this->m_int32Array.m_data;
    v5 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 >= n )
      return;
    m_world = this->m_world;
    sizeElem = 4;
    p_result = &result;
  }
  m_allocator = m_world->m_allocator;
  v9 = 2 * v5;
  if ( n < v9 )
    n = v9;
  hkArrayUtil::_reserve(p_result, m_allocator, p_m_data, n, sizeElem);
}

// File Line: 1384
// RVA: 0xE42F40
hkResult *__fastcall VariableIntArrayImplementation::asStridedBasicArray(
        VariableIntArrayImplementation *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  void *m_data; // rax

  if ( this->m_arrayType )
  {
    arrOut->m_type = 9;
    arrOut->m_size = this->m_int64Array.m_size;
    m_data = this->m_int64Array.m_data;
    arrOut->m_stride = 8;
  }
  else
  {
    arrOut->m_type = TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR;
    arrOut->m_size = this->m_int32Array.m_size;
    m_data = this->m_int32Array.m_data;
    arrOut->m_stride = 4;
  }
  arrOut->m_data = m_data;
  arrOut->m_tupleSize = 1;
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 1404
// RVA: 0xE469D0
void __fastcall VariableIntArrayImplementation::setSize(VariableIntArrayImplementation *this, int size)
{
  int m_arrayType; // ecx
  int v5; // eax
  int v6; // r9d
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  m_arrayType = this->m_arrayType;
  if ( m_arrayType )
  {
    if ( m_arrayType == 1 )
    {
      v5 = this->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v5 < size )
      {
        v6 = size;
        v7 = 2 * v5;
        if ( size < v7 )
          v6 = v7;
        hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int64Array.m_data, v6, 8);
      }
      v8 = size - this->m_int64Array.m_size;
      if ( v8 > 0 )
        memset(&this->m_int64Array.m_data[this->m_int64Array.m_size], 0, 8i64 * v8);
      this->m_int64Array.m_size = size;
    }
  }
  else
  {
    v9 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < size )
    {
      v10 = size;
      v11 = 2 * v9;
      if ( size < v11 )
        v10 = v11;
      hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int32Array.m_data, v10, 4);
    }
    v12 = size - this->m_int32Array.m_size;
    v13 = &this->m_int32Array.m_data[this->m_int32Array.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13++ = 0;
        --v14;
      }
    }
    this->m_int32Array.m_size = size;
  }
  if ( !size )
    this->m_assigned.m_bool = 0;
}

// File Line: 1424
// RVA: 0xE445F0
__int64 __fastcall VariableIntArrayImplementation::getSize(VariableIntArrayImplementation *this)
{
  int m_arrayType; // edx

  m_arrayType = this->m_arrayType;
  if ( !m_arrayType )
    return (unsigned int)this->m_int32Array.m_size;
  if ( m_arrayType == 1 )
    return (unsigned int)this->m_int64Array.m_size;
  return 0i64;
}

// File Line: 1438
// RVA: 0xE42C30
__int64 __fastcall VariableIntArrayImplementation::asInt(VariableIntArrayImplementation *this, int index)
{
  int m_arrayType; // r8d

  m_arrayType = this->m_arrayType;
  if ( !m_arrayType )
    return (unsigned int)this->m_int32Array.m_data[index];
  if ( m_arrayType == 1 )
    return LODWORD(this->m_int64Array.m_data[index]);
  return 0i64;
}

// File Line: 1454
// RVA: 0xE42B90
__int64 __fastcall VariableIntArrayImplementation::asInt64(VariableIntArrayImplementation *this, int index)
{
  int m_arrayType; // r8d

  m_arrayType = this->m_arrayType;
  if ( !m_arrayType )
    return this->m_int32Array.m_data[index];
  if ( m_arrayType == 1 )
    return this->m_int64Array.m_data[index];
  return 0i64;
}

// File Line: 1469
// RVA: 0xE464A0
void __fastcall VariableIntArrayImplementation::setHalf(VariableIntArrayImplementation *this, int index, hkHalf val)
{
  this->m_int32Array.m_data[index] = (unsigned __int16)val.m_value;
}

// File Line: 1479
// RVA: 0xE42B20
hkHalf *__fastcall VariableIntArrayImplementation::asHalf(
        VariableIntArrayImplementation *this,
        hkHalf *result,
        int index)
{
  hkHalf *v3; // rax

  v3 = result;
  result->m_value = this->m_int32Array.m_data[index];
  return v3;
}

// File Line: 1489
// RVA: 0xE46520
void __fastcall VariableIntArrayImplementation::setInt(VariableIntArrayImplementation *this, __int64 index, int val)
{
  if ( this->m_arrayType )
  {
    ((void (__fastcall *)(VariableIntArrayImplementation *, __int64, _QWORD))this->vfptr[20].__vecDelDtor)(
      this,
      index,
      val);
    this->m_assigned.m_bool = 1;
  }
  else
  {
    this->m_int32Array.m_data[(int)index] = val;
    this->m_assigned.m_bool = 1;
  }
}

// File Line: 1502
// RVA: 0xE42400
void __fastcall VariableIntArrayImplementation::_reallocateArray(VariableIntArrayImplementation *this)
{
  int m_size; // esi
  int v3; // eax
  int v4; // eax
  int v5; // r9d
  int v6; // edx
  __int64 v7; // r8
  __int64 v8; // r9
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  hkErrStream v11; // [rsp+30h] [rbp-228h] BYREF
  char buf[512]; // [rsp+50h] [rbp-208h] BYREF
  hkResult result; // [rsp+260h] [rbp+8h] BYREF

  if ( this->m_assigned.m_bool )
  {
    hkErrStream::hkErrStream(&v11, buf, 512);
    hkOstream::operator<<(
      &v11,
      "Converting DataObjectArray from 32-bit to 64-bit. If this is intended, always use 64-bit values");
    hkError::messageWarning(0x3599E1EDu, buf, "Data\\Dict\\hkDataObjectDict.cpp", 1506);
    hkOstream::~hkOstream(&v11);
  }
  m_size = this->m_int32Array.m_size;
  v3 = this->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < m_size )
  {
    v4 = 2 * v3;
    v5 = this->m_int32Array.m_size;
    if ( m_size < v4 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int64Array.m_data, v5, 8);
  }
  this->m_int64Array.m_size = m_size;
  v6 = 0;
  if ( this->m_int32Array.m_size > 0 )
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      ++v6;
      this->m_int64Array.m_data[v7++] = this->m_int32Array.m_data[v8++];
    }
    while ( v6 < this->m_int32Array.m_size );
  }
  m_capacityAndFlags = this->m_int32Array.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_int32Array.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_int32Array.m_data, 4 * m_capacityAndFlags);
  this->m_int32Array.m_data = 0i64;
  this->m_int32Array.m_capacityAndFlags = 0x80000000;
  this->m_arrayType = 1;
}

// File Line: 1519
// RVA: 0xE464B0
void __fastcall VariableIntArrayImplementation::setInt64(VariableIntArrayImplementation *this, int index, __int64 val)
{
  __int64 v4; // rsi

  v4 = index;
  if ( this->m_arrayType != 1 )
    VariableIntArrayImplementation::_reallocateArray(this);
  this->m_assigned.m_bool = 1;
  this->m_int64Array.m_data[v4] = val;
}

// File Line: 1531
// RVA: 0xE45FD0
void __fastcall VariableIntArrayImplementation::setAll(
        VariableIntArrayImplementation *this,
        const __int64 *in,
        int size)
{
  int i; // ebx

  this->vfptr[4].__vecDelDtor(this, size);
  for ( i = 0; i < size; ++in )
    ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, _QWORD))this->vfptr[20].__vecDelDtor)(
      this,
      (unsigned int)i++,
      *in);
}

// File Line: 1545
// RVA: 0xE45EE0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const int *in, int size)
{
  hkDataWorldDict *m_world; // rax
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  hkArrayBase<int> *p_m_int32Array; // rbx
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // r8d
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  if ( this->m_arrayType )
  {
    m_world = this->m_world;
    this->m_arrayType = 0;
    m_capacityAndFlags = this->m_int64Array.m_capacityAndFlags;
    m_allocator = m_world->m_allocator;
    this->m_int64Array.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      m_allocator->vfptr->bufFree(m_allocator, this->m_int64Array.m_data, 8 * m_capacityAndFlags);
    this->m_int64Array.m_data = 0i64;
    this->m_int64Array.m_capacityAndFlags = 0x80000000;
  }
  p_m_int32Array = &this->m_int32Array;
  v10 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < size )
  {
    v11 = 2 * v10;
    v12 = size;
    if ( size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int32Array.m_data, v12, 4);
  }
  v13 = size - this->m_int32Array.m_size;
  v14 = &p_m_int32Array->m_data[this->m_int32Array.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14++ = 0;
      --v15;
    }
  }
  p_m_int32Array->m_size = size;
  hkString::memCpy(p_m_int32Array->m_data, in, 4 * size);
}

// File Line: 1556
// RVA: 0xE45FC0
void __fastcall UFG::CharacterSubjectComponent::ContainsPlayer(
        VariableIntArrayImplementation *this,
        const unsigned int *in,
        __int64 size)
{
  ((void (__fastcall *)(VariableIntArrayImplementation *, const unsigned int *, __int64))this->vfptr[32].__vecDelDtor)(
    this,
    in,
    size);
}

// File Line: 1561
// RVA: 0xE45CE0
void __fastcall VariableIntArrayImplementation::setAll(
        VariableIntArrayImplementation *this,
        const __int16 *in,
        int size)
{
  int v3; // ebx
  hkDataWorldDict *m_world; // rax
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  v3 = 0;
  if ( this->m_arrayType )
  {
    m_world = this->m_world;
    this->m_arrayType = 0;
    m_capacityAndFlags = this->m_int64Array.m_capacityAndFlags;
    m_allocator = m_world->m_allocator;
    this->m_int64Array.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      m_allocator->vfptr->bufFree(m_allocator, this->m_int64Array.m_data, 8 * m_capacityAndFlags);
    this->m_int64Array.m_data = 0i64;
    this->m_int64Array.m_capacityAndFlags = 0x80000000;
  }
  v10 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < size )
  {
    v11 = 2 * v10;
    v12 = size;
    if ( size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int32Array.m_data, v12, 4);
  }
  v13 = size - this->m_int32Array.m_size;
  v14 = &this->m_int32Array.m_data[this->m_int32Array.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14++ = 0;
      --v15;
    }
  }
  this->m_int32Array.m_size = size;
  if ( size > 0 )
  {
    do
      ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, _QWORD))this->vfptr[18].__vecDelDtor)(
        this,
        (unsigned int)v3++,
        (unsigned int)*in++);
    while ( v3 < size );
  }
}

// File Line: 1575
// RVA: 0xE45DE0
void __fastcall VariableIntArrayImplementation::setAll(
        VariableIntArrayImplementation *this,
        const unsigned __int16 *in,
        int size)
{
  int v3; // ebx
  hkDataWorldDict *m_world; // rax
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  v3 = 0;
  if ( this->m_arrayType )
  {
    m_world = this->m_world;
    this->m_arrayType = 0;
    m_capacityAndFlags = this->m_int64Array.m_capacityAndFlags;
    m_allocator = m_world->m_allocator;
    this->m_int64Array.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      m_allocator->vfptr->bufFree(m_allocator, this->m_int64Array.m_data, 8 * m_capacityAndFlags);
    this->m_int64Array.m_data = 0i64;
    this->m_int64Array.m_capacityAndFlags = 0x80000000;
  }
  v10 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < size )
  {
    v11 = 2 * v10;
    v12 = size;
    if ( size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_int32Array.m_data, v12, 4);
  }
  v13 = size - this->m_int32Array.m_size;
  v14 = &this->m_int32Array.m_data[this->m_int32Array.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14++ = 0;
      --v15;
    }
  }
  this->m_int32Array.m_size = size;
  if ( size > 0 )
  {
    do
      ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, _QWORD))this->vfptr[18].__vecDelDtor)(
        this,
        (unsigned int)v3++,
        *in++);
    while ( v3 < size );
  }
}

// File Line: 1617
// RVA: 0xE42BE0
__int64 __fastcall ByteArrayImplementation::asInt(ByteArrayImplementation *this, int i)
{
  return (unsigned __int8)this->m_data.m_data[i];
}

// File Line: 1619
// RVA: 0xE46510
void __fastcall ByteArrayImplementation::setInt(ByteArrayImplementation *this, int i, char val)
{
  this->m_data.m_data[i] = val;
}

// File Line: 1622
// RVA: 0xE42EB0
hkResult *__fastcall ByteArrayImplementation::asStridedBasicArray(
        ByteArrayImplementation *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  int m_size; // eax
  char *m_data; // rax
  hkResult *v5; // rax

  arrOut->m_type = TYPE_USER_CONTACT_MGR;
  m_size = this->m_data.m_size;
  result->m_enum = HK_SUCCESS;
  arrOut->m_size = m_size;
  m_data = this->m_data.m_data;
  arrOut->m_tupleSize = 1;
  arrOut->m_data = m_data;
  v5 = result;
  arrOut->m_stride = 1;
  return v5;
}

// File Line: 1633
// RVA: 0xE45BD0
void __fastcall ByteArrayImplementation::setAll(ByteArrayImplementation *this, const char *vals, int n)
{
  hkArrayBase<unsigned char> *p_m_data; // rdi
  int v5; // eax
  int v7; // eax
  int v8; // r9d
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  p_m_data = &this->m_data;
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = n;
    if ( n < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&p_m_data->m_data, v8, 1);
  }
  p_m_data->m_size = n;
  hkString::memCpy(p_m_data->m_data, vals, n);
}

// File Line: 1651
// RVA: 0xE46E30
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::View::swizzleObjectMember(
        ArrayOfTuplesImplementation::View *this,
        const char *name)
{
  hkDataRefCountedVtbl *v3; // rdi
  _QWORD **Value; // rax
  hkDataArrayImpl *result; // rax
  int m_baseIndex; // ecx

  v3 = (hkDataRefCountedVtbl *)this->m_owner->vfptr[10].__vecDelDtor(this->m_owner, name);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( !result )
    return 0i64;
  m_baseIndex = this->m_baseIndex;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&ArrayOfTuplesImplementation::View::`vftable;
  result[1].vfptr = v3;
  *(_DWORD *)&result[1].m_memSize = m_baseIndex;
  return result;
}

// File Line: 1657
// RVA: 0xE44830
hkTypeManager::Type *__fastcall ArrayOfTuplesImplementation::View::getType(ArrayOfTuplesImplementation::View *this)
{
  return *(hkTypeManager::Type **)(((__int64 (__fastcall *)(ArrayOfTuplesImplementation *))this->m_owner->vfptr[1].__vecDelDtor)(this->m_owner)
                                 + 8);
}

// File Line: 1665
// RVA: 0xE44200
hkDataClassImpl *__fastcall ArrayOfTuplesImplementation::View::getClass(ArrayOfTuplesImplementation::View *this)
{
  hkTypeManager::Type *v2; // rax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *TypeName; // rax

  v2 = (hkTypeManager::Type *)((__int64 (__fastcall *)(ArrayOfTuplesImplementation::View *))this->vfptr[1].__vecDelDtor)(this);
  if ( v2->m_subType != SUB_TYPE_CLASS )
    return 0i64;
  vfptr = this->m_owner->m_world->vfptr;
  TypeName = hkTypeManager::Type::getTypeName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))vfptr[4].__first_virtual_table_function__)(
                              this->m_owner->m_world,
                              TypeName);
}

// File Line: 1681
// RVA: 0xE43AF0
void __fastcall ArrayOfTuplesImplementation::View::clear(ArrayOfTuplesImplementation::View *this)
{
  ((void (__fastcall *)(hkDataArrayImpl *))this->m_owner->m_impl->vfptr[2].__vecDelDtor)(this->m_owner->m_impl);
}

// File Line: 1693
// RVA: 0xE44630
int __fastcall ArrayOfTuplesImplementation::View::getSize(ArrayOfTuplesImplementation::View *this)
{
  hkTypeManager::Type *v1; // rax

  v1 = (hkTypeManager::Type *)((__int64 (__fastcall *)(ArrayOfTuplesImplementation *))this->m_owner->vfptr[1].__vecDelDtor)(this->m_owner);
  return hkTypeManager::Type::getTupleSize(v1);
}

// File Line: 1700
// RVA: 0xE460E0
void __fastcall ArrayOfTuplesImplementation::View::setAll(
        ArrayOfTuplesImplementation::View *this,
        const char *v,
        int n)
{
  int v3; // edi
  __int64 v6; // rbx
  __int64 v7; // rbp

  if ( n > 0 )
  {
    v3 = 0;
    v6 = 0i64;
    v7 = n;
    do
    {
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))this->m_owner->m_impl->vfptr[18].__vecDelDtor)(
        this->m_owner->m_impl,
        (unsigned int)(v3 + this->m_baseIndex),
        (unsigned __int8)v[v6++]);
      ++v3;
    }
    while ( v6 < v7 );
  }
}

// File Line: 1708
// RVA: 0xE461E0
void __fastcall ArrayOfTuplesImplementation::View::setAll(
        ArrayOfTuplesImplementation::View *this,
        const float *v,
        int n)
{
  int v3; // edi
  __int64 v5; // rbx
  __int64 v6; // rbp

  if ( n > 0 )
  {
    v3 = 0;
    v5 = 0i64;
    v6 = n;
    do
    {
      this->m_owner->m_impl->vfptr[16].__vecDelDtor(this->m_owner->m_impl, v3 + this->m_baseIndex);
      ++v5;
      ++v3;
    }
    while ( v5 < v6 );
  }
}

// File Line: 1716
// RVA: 0xE46160
void __fastcall ArrayOfTuplesImplementation::View::setAll(ArrayOfTuplesImplementation::View *this, const int *v, int n)
{
  int v3; // edi
  __int64 v6; // rbx
  __int64 v7; // rbp

  if ( n > 0 )
  {
    v3 = 0;
    v6 = 0i64;
    v7 = n;
    do
    {
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))this->m_owner->m_impl->vfptr[18].__vecDelDtor)(
        this->m_owner->m_impl,
        (unsigned int)(v3 + this->m_baseIndex),
        (unsigned int)v[v6++]);
      ++v3;
    }
    while ( v6 < v7 );
  }
}

// File Line: 1729
// RVA: 0xE46D10
void __fastcall ArrayOfTuplesImplementation::View::setVec(
        ArrayOfTuplesImplementation::View *this,
        int index,
        const float *val)
{
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const float *))this->m_owner->m_impl->vfptr[12].__vecDelDtor)(
    this->m_owner->m_impl,
    (unsigned int)(this->m_baseIndex + index),
    val);
}

// File Line: 1730
// RVA: 0xE43060
const char *__fastcall ArrayOfTuplesImplementation::View::asString(ArrayOfTuplesImplementation::View *this, int index)
{
  return (const char *)this->m_owner->m_impl->vfptr[13].__vecDelDtor(
                         this->m_owner->m_impl,
                         (unsigned int)(this->m_baseIndex + index));
}

// File Line: 1731
// RVA: 0xE466D0
void __fastcall ArrayOfTuplesImplementation::View::setReal(
        ArrayOfTuplesImplementation::View *this,
        int index,
        float val)
{
  this->m_owner->m_impl->vfptr[16].__vecDelDtor(this->m_owner->m_impl, this->m_baseIndex + index);
}

// File Line: 1732
// RVA: 0xE46560
void __fastcall ArrayOfTuplesImplementation::View::setInt(
        ArrayOfTuplesImplementation::View *this,
        int index,
        __int64 val)
{
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))this->m_owner->m_impl->vfptr[18].__vecDelDtor)(
    this->m_owner->m_impl,
    (unsigned int)(this->m_baseIndex + index),
    val);
}

// File Line: 1733
// RVA: 0xE42BC0
void *__fastcall ArrayOfTuplesImplementation::View::asInt64(ArrayOfTuplesImplementation::View *this, int index)
{
  return this->m_owner->m_impl->vfptr[19].__vecDelDtor(this->m_owner->m_impl, (unsigned int)(this->m_baseIndex + index));
}

// File Line: 1734
// RVA: 0xE46690
void __fastcall ArrayOfTuplesImplementation::View::setObject(
        ArrayOfTuplesImplementation::View *this,
        int index,
        hkDataObjectImpl *val)
{
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))this->m_owner->m_impl->vfptr[22].__vecDelDtor)(
    this->m_owner->m_impl,
    (unsigned int)(this->m_baseIndex + index),
    val);
}

// File Line: 1735
// RVA: 0xE42A70
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::View::asArray(
        ArrayOfTuplesImplementation::View *this,
        int index)
{
  return (hkDataArrayImpl *)this->m_owner->m_impl->vfptr[23].__vecDelDtor(
                              this->m_owner->m_impl,
                              (unsigned int)(this->m_baseIndex + index));
}

// File Line: 1782
// RVA: 0xE46D30
ArrayOfTuplesImplementation *__fastcall ArrayOfTuplesImplementation::swizzleObjectMember(
        ArrayOfTuplesImplementation *this,
        const char *name)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  int m_tupleCount; // edx
  hkDataArrayImpl *v7; // rax
  ArrayOfTuplesImplementation *m_swizzle; // rsi
  hkDataArrayImpl *v9; // rdi
  hkDataArrayImpl *m_impl; // rcx
  bool v11; // zf

  if ( !this->m_swizzle )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
    if ( v5 )
    {
      m_tupleCount = this->m_tupleCount;
      *(_QWORD *)(v5 + 16) = this->m_world;
      *(_DWORD *)(v5 + 32) = m_tupleCount;
      *(_QWORD *)(v5 + 8) = 0xFFFFi64;
      *(_QWORD *)v5 = &ArrayOfTuplesImplementation::`vftable;
      *(_QWORD *)(v5 + 24) = 0i64;
      *(_QWORD *)(v5 + 40) = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
    this->m_swizzle = (ArrayOfTuplesImplementation *)v5;
    ++*(_DWORD *)(v5 + 12);
  }
  v7 = (hkDataArrayImpl *)this->m_impl->vfptr[10].__vecDelDtor(this->m_impl, name);
  m_swizzle = this->m_swizzle;
  v9 = v7;
  if ( v7 )
    ++v7->m_count;
  m_impl = m_swizzle->m_impl;
  if ( m_impl && (v11 = m_impl->m_count == 1, --m_impl->m_count, v11) )
  {
    m_impl->vfptr->__vecDelDtor(m_impl, 1u);
    m_swizzle->m_impl = v9;
  }
  else
  {
    m_swizzle->m_impl = v7;
  }
  return this->m_swizzle;
}

// File Line: 1793
// RVA: 0xE447C0
hkTypeManager::Type *__fastcall ArrayOfTuplesImplementation::getType(ArrayOfTuplesImplementation *this)
{
  hkTypeManager::Type *v2; // rbx
  hkTypeManager *v3; // rax

  v2 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataArrayImpl *))this->m_impl->vfptr[1].__vecDelDtor)(this->m_impl);
  v3 = (hkTypeManager *)((__int64 (__fastcall *)(hkDataWorldDict *))this->m_world->vfptr[5].__first_virtual_table_function__)(this->m_world);
  return hkTypeManager::makeTuple(v3, v2, this->m_tupleCount);
}

// File Line: 1803
// RVA: 0xE441B0
hkDataClassImpl *__fastcall ArrayOfTuplesImplementation::getClass(ArrayOfTuplesImplementation *this)
{
  hkTypeManager::Type *v2; // rax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *TypeName; // rax

  v2 = (hkTypeManager::Type *)((__int64 (__fastcall *)(ArrayOfTuplesImplementation *))this->vfptr[1].__vecDelDtor)(this);
  if ( v2->m_subType != SUB_TYPE_CLASS )
    return 0i64;
  vfptr = this->m_world->vfptr;
  TypeName = hkTypeManager::Type::getTypeName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))vfptr[4].__first_virtual_table_function__)(
                              this->m_world,
                              TypeName);
}

// File Line: 1818
// RVA: 0xE45620
void __fastcall ArrayOfTuplesImplementation::reserve(ArrayOfTuplesImplementation *this, int n)
{
  this->m_impl->vfptr[3].__vecDelDtor(this->m_impl, n * this->m_tupleCount);
}

// File Line: 1822
// RVA: 0xE46940
void __fastcall ArrayOfTuplesImplementation::setSize(ArrayOfTuplesImplementation *this, int n)
{
  this->m_impl->vfptr[4].__vecDelDtor(this->m_impl, n * this->m_tupleCount);
}

// File Line: 1826
// RVA: 0xE445D0
__int64 __fastcall ArrayOfTuplesImplementation::getSize(ArrayOfTuplesImplementation *this)
{
  return (unsigned int)(((int (__fastcall *)(hkDataArrayImpl *))this->m_impl->vfptr[5].__vecDelDtor)(this->m_impl)
                      / this->m_tupleCount);
}

// File Line: 1831
// RVA: 0xE42920
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::asArray(ArrayOfTuplesImplementation *this, int idx)
{
  _QWORD **Value; // rax
  hkDataArrayImpl *result; // rax
  int m_tupleCount; // edx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( !result )
    return 0i64;
  m_tupleCount = this->m_tupleCount;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&ArrayOfTuplesImplementation::View::`vftable;
  result[1].vfptr = (hkDataRefCountedVtbl *)this;
  *(_DWORD *)&result[1].m_memSize = idx * m_tupleCount;
  return result;
}

// File Line: 1838
// RVA: 0xE46260
void __fastcall ArrayOfTuplesImplementation::setArray(ArrayOfTuplesImplementation *this, int idx, hkDataArrayImpl *src)
{
  int v5; // r14d
  unsigned __int64 v6; // rdx
  int i; // ebx
  unsigned int v8; // eax
  int j; // ebx
  int n; // ebx
  void *v11; // rax
  int m; // ebx
  void *v13; // rax
  int ii; // ebx
  void *v15; // rax
  unsigned int k; // ebx
  bool v17; // zf
  hkDataRefCountedVtbl *vfptr; // rax
  unsigned int v19; // eax
  __int64 v20; // rax

  v5 = idx * this->m_tupleCount;
  ((__int64 (__fastcall *)(hkDataArrayImpl *))src->vfptr[1].__vecDelDtor)(src);
  v6 = 0x140000000ui64;
  switch ( 0x140000000ui64 )
  {
    case 0ui64:
      for ( i = 0; i < this->m_tupleCount; ++i )
      {
        v8 = (unsigned int)src->vfptr[17].__vecDelDtor(src, (unsigned int)i);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))this->m_impl->vfptr[18].__vecDelDtor)(
          this->m_impl,
          (unsigned int)(v5 + i),
          v8);
      }
      break;
    case 1ui64:
      for ( j = 0; j < this->m_tupleCount; ++j )
      {
        src->vfptr[15].__vecDelDtor(src, j);
        this->m_impl->vfptr[16].__vecDelDtor(this->m_impl, v5 + j);
      }
      break;
    case 2ui64:
      for ( k = 0; (signed int)k < this->m_tupleCount; ++k )
      {
        v17 = src->vfptr[39].__vecDelDtor(src, v6) == 0;
        vfptr = src->vfptr;
        if ( v17 )
        {
          v19 = (unsigned int)vfptr[17].__vecDelDtor(src, k);
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))this->m_impl->vfptr[18].__vecDelDtor)(
            this->m_impl,
            v5 + k,
            v19);
        }
        else
        {
          v20 = (__int64)vfptr[19].__vecDelDtor(src, k);
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))this->m_impl->vfptr[20].__vecDelDtor)(
            this->m_impl,
            v5 + k,
            v20);
        }
      }
      break;
    case 3ui64:
      for ( m = 0; m < this->m_tupleCount; ++m )
      {
        v13 = src->vfptr[13].__vecDelDtor(src, (unsigned int)m);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))this->m_impl->vfptr[14].__vecDelDtor)(
          this->m_impl,
          (unsigned int)(v5 + m),
          v13);
      }
      break;
    case 4ui64:
      for ( n = 0; n < this->m_tupleCount; ++n )
      {
        v11 = src->vfptr[21].__vecDelDtor(src, (unsigned int)n);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))this->m_impl->vfptr[22].__vecDelDtor)(
          this->m_impl,
          (unsigned int)(v5 + n),
          v11);
      }
      break;
    case 5ui64:
      for ( ii = 0; ii < this->m_tupleCount; ++ii )
      {
        v15 = src->vfptr[21].__vecDelDtor(src, (unsigned int)ii);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, void *))this->m_impl->vfptr[22].__vecDelDtor)(
          this->m_impl,
          (unsigned int)(v5 + ii),
          v15);
      }
      break;
    default:
      return;
  }
}

// File Line: 1899
// RVA: 0xE42E30
float __fastcall RealArrayImplementation::asReal(RealArrayImplementation *this, int i)
{
  return this->m_data.m_data[i];
}

// File Line: 1900
// RVA: 0xE466B0
void __fastcall RealArrayImplementation::setReal(RealArrayImplementation *this, int i, float val)
{
  this->m_data.m_data[i] = val;
}

// File Line: 1903
// RVA: 0xE42EE0
hkResult *__fastcall RealArrayImplementation::asStridedBasicArray(
        RealArrayImplementation *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  float *m_data; // rax

  m_data = this->m_data.m_data;
  result->m_enum = HK_SUCCESS;
  arrOut->m_data = m_data;
  LODWORD(m_data) = this->m_data.m_size;
  arrOut->m_stride = 4;
  arrOut->m_size = (int)m_data;
  arrOut->m_type = TYPE_NULL_CONTACT_MGR|0x8;
  arrOut->m_tupleSize = 1;
  return result;
}

// File Line: 1915
// RVA: 0xE45C40
void __fastcall RealArrayImplementation::setAll(RealArrayImplementation *this, const float *vals, int n)
{
  hkArrayBase<float> *p_m_data; // rdi
  int v5; // eax
  int v7; // eax
  int v8; // r9d
  hkResult result; // [rsp+50h] [rbp+18h] BYREF

  p_m_data = &this->m_data;
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = n;
    if ( n < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&p_m_data->m_data, v8, 4);
  }
  p_m_data->m_size = n;
  hkString::memCpy(p_m_data->m_data, vals, 4 * n);
}

// File Line: 1932
// RVA: 0xE42E40
float __fastcall RealArrayView::asReal(RealArrayView *this, int i)
{
  return this->m_data[i];
}

// File Line: 1933
// RVA: 0xE466C0
void __fastcall RealArrayView::setReal(RealArrayView *this, int i, float val)
{
  this->m_data[i] = val;
}

// File Line: 1936
// RVA: 0xE44800
hkTypeManager::Type *__fastcall RealArrayView::getType(RealArrayView *this)
{
  return *(hkTypeManager::Type **)(((__int64 (__fastcall *)(hkDataWorldDict *))this->m_world->vfptr[5].__first_virtual_table_function__)(this->m_world)
                                 + 48);
}

// File Line: 1947
// RVA: 0xE42F10
hkResult *__fastcall RealArrayView::asStridedBasicArray(
        RealArrayView *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  float *m_data; // rax

  m_data = this->m_data;
  result->m_enum = HK_SUCCESS;
  arrOut->m_data = m_data;
  LODWORD(m_data) = this->m_size;
  arrOut->m_stride = 4;
  arrOut->m_size = (int)m_data;
  arrOut->m_tupleSize = 1;
  arrOut->m_type = TYPE_NULL_CONTACT_MGR|0x8;
  return result;
}

// File Line: 1959
// RVA: 0xE45CC0
void __fastcall RealArrayView::setAll(RealArrayView *this, const float *vals, int n)
{
  hkString::memCpy(this->m_data, vals, 4 * n);
}

// File Line: 1982
// RVA: 0xE43100
float *__fastcall VecArrayImplementation::asVec(VecArrayImplementation *this, int index)
{
  return &this->m_data.m_data[index * hkTypeManager::Type::getTupleSize(this->m_type)];
}

// File Line: 1984
// RVA: 0xE46C00
void __fastcall VecArrayImplementation::setVec(VecArrayImplementation *this, int index, const float *val)
{
  __int64 v5; // r14
  __int64 v6; // rbx
  int TupleSize; // eax
  __int64 v8; // r11
  float *m_data; // r10
  unsigned __int64 v10; // rax
  float *v11; // rcx
  char *v12; // r8
  unsigned __int64 v13; // rdx
  int v14; // eax
  const float *v15; // rdx
  signed __int64 v16; // r8
  __int64 v17; // r11
  int v18; // eax

  v5 = index;
  v6 = 0i64;
  TupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  v8 = TupleSize;
  if ( TupleSize >= 4i64 )
  {
    m_data = this->m_data.m_data;
    v10 = 4 * TupleSize * v5;
    v11 = &m_data[v10 / 4];
    v12 = (char *)((char *)&val[v10 / 0xFFFFFFFFFFFFFFFCui64] - (char *)m_data);
    v13 = ((unsigned __int64)(v8 - 4) >> 2) + 1;
    v6 = 4 * v13;
    do
    {
      v14 = *(_DWORD *)((char *)v11 + (_QWORD)v12);
      v11 += 4;
      *((_DWORD *)v11 - 4) = v14;
      *(v11 - 3) = *(float *)((char *)v11 + (_QWORD)v12 - 12);
      *(v11 - 2) = *(float *)((char *)v11 + (_QWORD)val + 4 * (2 - v8 * v5) - (_QWORD)m_data - 16);
      *(v11 - 1) = *(float *)((char *)v11 + (_QWORD)val + 4 * (3 - v8 * v5) - (_QWORD)m_data - 16);
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < v8 )
  {
    v15 = &val[v6];
    v16 = (char *)&this->m_data.m_data[v8 * v5] - (char *)val;
    v17 = v8 - v6;
    do
    {
      v18 = *(_DWORD *)v15++;
      *(_DWORD *)((char *)v15 + v16 - 4) = v18;
      --v17;
    }
    while ( v17 );
  }
}

// File Line: 2004
// RVA: 0xE45710
void __fastcall VecArrayImplementation::reserve(VecArrayImplementation *this, int n)
{
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  v3 = n * hkTypeManager::Type::getTupleSize(this->m_type);
  v4 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v3, 4);
  }
}

// File Line: 2006
// RVA: 0xE46AD0
void __fastcall VecArrayImplementation::setSize(VecArrayImplementation *this, int n)
{
  int TupleSize; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  int v8; // r9d
  int v9; // edx
  float *v10; // rdi
  __int64 v11; // rcx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  TupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = n * TupleSize;
  if ( v5 < n * TupleSize )
  {
    v7 = 2 * v5;
    v8 = n * TupleSize;
    if ( v6 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v8, 4);
  }
  v9 = v6 - this->m_data.m_size;
  v10 = &this->m_data.m_data[this->m_data.m_size];
  v11 = v9;
  if ( v9 > 0 )
  {
    while ( v11 )
    {
      *v10++ = 0.0;
      --v11;
    }
  }
  this->m_data.m_size = v6;
}

// File Line: 2009
// RVA: 0xE44610
__int64 __fastcall VecArrayImplementation::getSize(VecArrayImplementation *this)
{
  int m_size; // ebx

  m_size = this->m_data.m_size;
  return (unsigned int)(m_size / hkTypeManager::Type::getTupleSize(this->m_type));
}

// File Line: 2012
// RVA: 0xE429D0
hkDataArrayImpl *__fastcall VecArrayImplementation::asArray(VecArrayImplementation *this, int index)
{
  int TupleSize; // edi
  _QWORD **Value; // rax
  hkDataArrayImpl *result; // rax
  float *v7; // r8
  hkDataRefCountedVtbl *m_world; // rcx

  TupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( !result )
    return 0i64;
  v7 = &this->m_data.m_data[index * TupleSize];
  m_world = (hkDataRefCountedVtbl *)this->m_world;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&RealArrayView::`vftable;
  *(_QWORD *)&result[1].m_memSize = v7;
  result[1].vfptr = m_world;
  LODWORD(result[2].vfptr) = TupleSize;
  return result;
}

// File Line: 2018
// RVA: 0xE46030
void __fastcall VecArrayImplementation::setAll(VecArrayImplementation *this, const float *data, int size)
{
  int TupleSize; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // r9d
  int v11; // r8d
  float *v12; // rdi
  __int64 v13; // rcx
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  TupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  v7 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = size * TupleSize;
  if ( v7 < size * TupleSize )
  {
    v9 = 2 * v7;
    v10 = size * TupleSize;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v10, 4);
  }
  v11 = v8 - this->m_data.m_size;
  v12 = &this->m_data.m_data[this->m_data.m_size];
  v13 = v11;
  if ( v11 > 0 )
  {
    while ( v13 )
    {
      *v12++ = 0.0;
      --v13;
    }
  }
  this->m_data.m_size = v8;
  hkString::memCpy(this->m_data.m_data, data, 4 * v8);
}

// File Line: 2041
// RVA: 0xE42FA0
hkResult *__fastcall VecArrayImplementation::asStridedBasicArray(
        VecArrayImplementation *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  int m_size; // ebx
  int TupleSize; // eax

  arrOut->m_data = this->m_data.m_data;
  m_size = this->m_data.m_size;
  arrOut->m_size = m_size / hkTypeManager::Type::getTupleSize(this->m_type);
  TupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  arrOut->m_type = TYPE_NULL_CONTACT_MGR|0x8;
  arrOut->m_stride = 4 * TupleSize;
  arrOut->m_tupleSize = hkTypeManager::Type::getTupleSize(this->m_type);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 2054
// RVA: 0xE40750
hkDataRefCountedVtbl *__fastcall hkRealArrayImplementation_getReals(hkDataArrayImpl *arrayIn, int numReals)
{
  if ( *(_DWORD *)&arrayIn[1].m_memSize < numReals )
    return 0i64;
  else
    return arrayIn[1].vfptr;
}

// File Line: 2073
// RVA: 0xE411E0
void __fastcall PointerArrayImplementation::~PointerArrayImplementation(PointerArrayImplementation *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataObjectImpl *v4; // rcx
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&PointerArrayImplementation::`vftable;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_data.m_data[v3];
      if ( v4 )
      {
        if ( v4->m_count-- == 1 )
          v4->vfptr->__vecDelDtor(v4, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_data.m_size );
  }
  this->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<hkDataObjectImpl *>::`vftable;
  m_capacityAndFlags = this->m_data.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_data.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_data.m_data, 8 * m_capacityAndFlags);
  this->m_data.m_data = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2083
// RVA: 0xE42D10
char *__fastcall CstringArrayImplementation::asString(CstringArrayImplementation *this, int i)
{
  return this->m_data.m_data[i];
}

// File Line: 2099
// RVA: 0xE41130
void __fastcall CstringArrayImplementation::~CstringArrayImplementation(CstringArrayImplementation *this)
{
  int v1; // esi
  __int64 v3; // rdi
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&CstringArrayImplementation::`vftable;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkString::strFree(this->m_data.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_data.m_size );
  }
  this->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<char *>::`vftable;
  m_capacityAndFlags = this->m_data.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_data.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_data.m_data, 8 * m_capacityAndFlags);
  this->m_data.m_data = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2107
// RVA: 0xE46B70
void __fastcall CstringArrayImplementation::setString(CstringArrayImplementation *this, int i, char *val)
{
  __int64 v4; // rdi

  v4 = i;
  hkString::strFree(this->m_data.m_data[v4]);
  if ( val )
    this->m_data.m_data[v4] = hkString::strDup(val);
  else
    this->m_data.m_data[v4] = 0i64;
}

// File Line: 2123
// RVA: 0xE41070
void __fastcall ArrayArrayImplementation::~ArrayArrayImplementation(ArrayArrayImplementation *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataArrayImpl *v4; // rcx
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&ArrayArrayImplementation::`vftable;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_data.m_data[v3];
      if ( v4 )
      {
        if ( v4->m_count-- == 1 )
          v4->vfptr->__vecDelDtor(v4, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_data.m_size );
  }
  this->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<hkDataArrayImpl *>::`vftable;
  m_capacityAndFlags = this->m_data.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_data.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_data.m_data, 8 * m_capacityAndFlags);
  this->m_data.m_data = 0i64;
  this->m_data.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2128
// RVA: 0xE439D0
void __fastcall ArrayArrayImplementation::clear(ArrayArrayImplementation *this)
{
  int v1; // ebx
  __int64 v3; // rdi
  hkDataArrayImpl *v4; // rcx

  v1 = 0;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->m_data.m_data[v3];
      if ( v4 )
      {
        if ( v4->m_count-- == 1 )
          v4->vfptr->__vecDelDtor(v4, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_data.m_size );
  }
}

// File Line: 2139
// RVA: 0xE46580
void __fastcall PointerArrayImplementation::setObject(PointerArrayImplementation *this, int i, hkDataObjectImpl *val)
{
  __int64 v5; // rsi
  hkDataObjectImpl **m_data; // rax
  hkDataObjectImpl *v7; // rcx

  if ( val )
    ++val->m_count;
  v5 = i;
  m_data = this->m_data.m_data;
  v7 = m_data[v5];
  if ( v7 )
  {
    if ( v7->m_count-- == 1 )
      v7->vfptr->__vecDelDtor(v7, 1u);
    m_data = this->m_data.m_data;
  }
  m_data[v5] = val;
}

// File Line: 2151
// RVA: 0xE46870
void __fastcall ArrayArrayImplementation::setSize(ArrayArrayImplementation *this, int n)
{
  int v4; // edi
  __int64 v5; // rbx
  hkDataArrayImpl *v6; // rcx
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  int v11; // edx
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  if ( n < this->m_data.m_size )
  {
    v4 = n;
    v5 = n;
    do
    {
      v6 = this->m_data.m_data[v5];
      if ( v6 )
      {
        if ( v6->m_count-- == 1 )
          v6->vfptr->__vecDelDtor(v6, 1u);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_data.m_size );
  }
  v8 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < n )
  {
    v9 = 2 * v8;
    v10 = n;
    if ( n < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, (const void **)&this->m_data.m_data, v10, 8);
  }
  v11 = n - this->m_data.m_size;
  if ( v11 > 0 )
    memset(&this->m_data.m_data[this->m_data.m_size], 0, 8i64 * v11);
  this->m_data.m_size = n;
}

// File Line: 2167
// RVA: 0xE428C0
void __fastcall ArrayArrayImplementation::asArray(ArrayArrayImplementation *this, int i)
{
  __int64 v3; // rdi
  hkDataArrayImpl *v4; // rax

  v3 = i;
  if ( !this->m_data.m_data[v3] )
  {
    hkDataArrayDict_create(this->m_world, this->m_type->m_parent, 0);
    ++v4->m_count;
    this->m_data.m_data[v3] = v4;
  }
}

// File Line: 2234
// RVA: 0xE41FF0
__int64 __fastcall StructArrayImplementation::_find(StructArrayImplementation *this, char *nameIn)
{
  unsigned int v2; // edi
  hkDataWorldDict::ObjectTracker *m_tracker; // r14
  const char *v6; // rbx
  __int64 m_size; // rdx
  __int64 v8; // rcx
  StructArrayImplementation::MemberData *i; // rax

  v2 = 0;
  m_tracker = this->m_class.m_pntr->m_world->m_tracker;
  if ( nameIn )
  {
    v6 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         nameIn,
                         0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(nameIn);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v6,
        (unsigned __int64)v6);
    }
  }
  else
  {
    v6 = 0i64;
  }
  m_size = this->m_memberData.m_size;
  v8 = 0i64;
  if ( m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = this->m_memberData.m_data; i->m_memberName.m_cachedString != v6; ++i )
  {
    ++v8;
    ++v2;
    if ( v8 >= m_size )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 2240
// RVA: 0xE41DA0
__int64 __fastcall StructArrayImplementation::_addMember(
        StructArrayImplementation *this,
        hkDataClassDict::MemberInfo *mi,
        unsigned int size)
{
  StructArrayImplementation::MemberData *v7; // rax
  StructArrayImplementation::MemberData *v8; // rsi
  hkTypeManager::Type *m_type; // r15
  hkTypeManager::Type *Terminal; // rax
  hkDataArrayImpl *v11; // rax
  unsigned int i; // edi
  hkTypeManager::SubType m_subType; // ecx
  hkDataClassDict *m_pntr; // rbx
  const char *TypeName; // rbp
  __int64 v16; // rax
  unsigned __int64 v17; // rax
  __int64 v18; // rax
  __int64 v19; // rbx
  unsigned __int64 v21; // [rsp+58h] [rbp+10h] BYREF

  if ( mi->m_type->m_subType == SUB_TYPE_VOID )
    return 0xFFFFFFFFi64;
  if ( this->m_memberData.m_size == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_world->m_allocator, (const void **)&this->m_memberData.m_data, 16);
  v7 = &this->m_memberData.m_data[this->m_memberData.m_size];
  if ( v7 )
    v7->m_memberName.m_cachedString = 0i64;
  v8 = &this->m_memberData.m_data[this->m_memberData.m_size++];
  v8->m_memberName.m_cachedString = mi->m_name.m_cachedString;
  m_type = mi->m_type;
  Terminal = hkTypeManager::Type::findTerminal(m_type);
  if ( Terminal->m_subType == SUB_TYPE_CLASS )
    hkTypeManager::Type::getTypeName(Terminal);
  hkDataArrayDict_create(this->m_world, m_type, 0);
  v8->m_values = v11;
  ++v11->m_count;
  v8->m_values->vfptr[4].__vecDelDtor(v8->m_values, size);
  if ( mi->m_valuePtr || m_type->m_subType == SUB_TYPE_CLASS )
  {
    for ( i = 0; (int)i < (int)size; ++i )
    {
      m_subType = m_type->m_subType;
      if ( ((m_type->m_subType - 2) & 0xFFFFFFFD) != 0 )
      {
        switch ( m_subType )
        {
          case SUB_TYPE_REAL:
            v8->m_values->vfptr[16].__vecDelDtor(v8->m_values, i);
            break;
          case SUB_TYPE_TUPLE:
            if ( m_type->m_parent->m_subType == SUB_TYPE_REAL )
              ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const void *))v8->m_values->vfptr[12].__vecDelDtor)(
                v8->m_values,
                i,
                mi->m_valuePtr);
            break;
          case SUB_TYPE_CLASS:
            m_pntr = this->m_class.m_pntr;
            TypeName = hkTypeManager::Type::getTypeName(m_type);
            v16 = ((__int64 (__fastcall *)(hkDataClassDict *))m_pntr->vfptr[1].__vecDelDtor)(m_pntr);
            if ( TypeName )
              v17 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)(*(_QWORD *)(v16 + 16)
                                                                                               + 8i64),
                      TypeName,
                      0i64);
            else
              v17 = 0i64;
            v21 = v17;
            v18 = ((__int64 (__fastcall *)(hkDataWorldDict *, unsigned __int64 *, _QWORD))this->m_class.m_pntr->m_world->vfptr[2].__vecDelDtor)(
                    this->m_class.m_pntr->m_world,
                    &v21,
                    0i64);
            v19 = v18;
            if ( v18 )
            {
              ++*(_WORD *)(v18 + 10);
              ++*(_DWORD *)(v18 + 12);
            }
            ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v8->m_values->vfptr[22].__vecDelDtor)(
              v8->m_values,
              i,
              v18);
            if ( v19 )
            {
              --*(_WORD *)(v19 + 10);
              if ( (*(_DWORD *)(v19 + 12))-- == 1 )
                (**(void (__fastcall ***)(__int64, __int64))v19)(v19, 1i64);
            }
            break;
          case SUB_TYPE_CSTRING:
            ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const void *))v8->m_values->vfptr[14].__vecDelDtor)(
              v8->m_values,
              i,
              mi->m_valuePtr);
            break;
        }
      }
      else
      {
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v8->m_values->vfptr[20].__vecDelDtor)(
          v8->m_values,
          i,
          *(_QWORD *)mi->m_valuePtr);
      }
    }
  }
  return (unsigned int)(this->m_memberData.m_size - 1);
}

// File Line: 2344
// RVA: 0xE420B0
__int64 __fastcall StructArrayImplementation::_findOrAdd(
        StructArrayImplementation *this,
        hkDataClassDict::MemberInfo *handle)
{
  __int64 m_size; // r10
  __int64 v3; // r8
  __int64 v6; // r9
  StructArrayImplementation::MemberData *m_data; // rax
  unsigned int v8; // eax

  m_size = this->m_memberData.m_size;
  v3 = 0i64;
  v6 = 0i64;
  if ( m_size > 0 )
  {
    m_data = this->m_memberData.m_data;
    while ( m_data->m_memberName.m_cachedString != handle->m_name.m_cachedString )
    {
      ++v6;
      v3 = (unsigned int)(v3 + 1);
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_5;
    }
    if ( (_DWORD)v3 != -1 )
      return (unsigned int)v3;
  }
LABEL_5:
  v8 = ((__int64 (__fastcall *)(StructArrayImplementation *, hkDataClassDict::MemberInfo *, __int64, __int64))this->vfptr[5].__vecDelDtor)(
         this,
         handle,
         v3,
         v6);
  return StructArrayImplementation::_addMember(this, handle, v8);
}

// File Line: 2356
// RVA: 0xE452B0
void __fastcall StructArrayImplementation::removeMember(StructArrayImplementation *this, InternedString s)
{
  __int64 m_size; // r9
  int v3; // ebx
  __int64 v5; // r8
  StructArrayImplementation::MemberData *i; // rax
  hkDataArrayImpl *m_values; // rcx
  int v9; // edx
  StructArrayImplementation::MemberData *v10; // rax
  __int64 v11; // rdx
  hkDataArrayImpl *m_cachedString; // rcx

  m_size = this->m_memberData.m_size;
  v3 = 0;
  v5 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = this->m_memberData.m_data; i->m_memberName.m_cachedString != s.m_cachedString; ++i )
    {
      ++v5;
      ++v3;
      if ( v5 >= m_size )
        return;
    }
    m_values = i->m_values;
    if ( m_values->m_count-- == 1 )
      ((void (__fastcall *)(hkDataArrayImpl *, __int64, __int64))m_values->vfptr->__vecDelDtor)(m_values, 1i64, v5);
    v9 = 16 * (--this->m_memberData.m_size - v3);
    v10 = &this->m_memberData.m_data[v3];
    if ( v9 > 0 )
    {
      v11 = ((unsigned int)(v9 - 1) >> 3) + 1;
      do
      {
        m_cachedString = (hkDataArrayImpl *)v10[1].m_memberName.m_cachedString;
        v10 = (StructArrayImplementation::MemberData *)((char *)v10 + 8);
        v10[-1].m_values = m_cachedString;
        --v11;
      }
      while ( v11 );
    }
  }
}

// File Line: 2394
// RVA: 0xE42630
hkDataObject_Value *__fastcall StructArrayImplementation::Object::accessByName(
        StructArrayImplementation::Object *this,
        hkDataObject_Value *result,
        char *nameIn)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v7; // rbx
  hkDataClassDict *m_pntr; // r8
  __int64 m_size; // r9
  int v10; // edx
  __int64 v11; // rcx
  hkDataClassDict::MemberInfo *m_data; // rax
  const struct _hkDataObject_MemberHandle *v14; // rax

  m_tracker = this->m_impl->m_class.m_pntr->m_world->m_tracker;
  if ( nameIn )
  {
    v7 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         nameIn,
                         0i64);
    if ( !v7 )
    {
      v7 = hkString::strDup(nameIn);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v7,
        (unsigned __int64)v7);
    }
  }
  else
  {
    v7 = 0i64;
  }
  m_pntr = this->m_impl->m_class.m_pntr;
  if ( !m_pntr )
    goto LABEL_11;
  while ( 1 )
  {
    m_size = m_pntr->m_memberInfo.m_size;
    v10 = 0;
    v11 = 0i64;
    if ( m_size > 0 )
      break;
LABEL_10:
    m_pntr = m_pntr->m_parent.m_pntr;
    if ( !m_pntr )
      goto LABEL_11;
  }
  m_data = m_pntr->m_memberInfo.m_data;
  while ( m_data->m_name.m_cachedString != v7 )
  {
    ++v11;
    ++v10;
    ++m_data;
    if ( v11 >= m_size )
      goto LABEL_10;
  }
  v14 = (const struct _hkDataObject_MemberHandle *)&m_pntr->m_memberInfo.m_data[v10];
  if ( v14 )
  {
    result->m_handle = v14;
    result->m_impl = this;
    return result;
  }
  else
  {
LABEL_11:
    result->m_impl = 0i64;
    result->m_handle = 0i64;
    return result;
  }
}

// File Line: 2409
// RVA: 0xE448A0
__int64 __fastcall StructArrayImplementation::Object::hasMember(
        StructArrayImplementation::Object *this,
        const char *name)
{
  StructArrayImplementation *m_impl; // rcx
  __int64 m_size; // r8
  __int64 v5; // rdx
  StructArrayImplementation::MemberData *i; // rcx
  const char *v8; // [rsp+30h] [rbp+8h] BYREF

  ((void (__fastcall *)(StructArrayImplementation::Object *, const char **, const char *))this->vfptr[30].__vecDelDtor)(
    this,
    &v8,
    name);
  m_impl = this->m_impl;
  m_size = m_impl->m_memberData.m_size;
  v5 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = m_impl->m_memberData.m_data; v8 != i->m_memberName.m_cachedString; ++i )
  {
    if ( ++v5 >= m_size )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2421
// RVA: 0xE44BE0
__int64 __fastcall StructArrayImplementation::Object::isSet(
        StructArrayImplementation::Object *this,
        const char **handle)
{
  StructArrayImplementation *m_impl; // rax
  __int64 v3; // rcx
  __int64 m_size; // r8
  const char *v5; // rdx
  StructArrayImplementation::MemberData *i; // rax

  m_impl = this->m_impl;
  v3 = 0i64;
  m_size = m_impl->m_memberData.m_size;
  if ( m_size <= 0 )
    return 0i64;
  v5 = *handle;
  for ( i = m_impl->m_memberData.m_data; v5 != i->m_memberName.m_cachedString; ++i )
  {
    if ( ++v3 >= m_size )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2435
// RVA: 0xE443B0
hkDataObject_Handle *__fastcall hkDataObjectDict::getHandle(hkDataObjectDict *this, hkDataObject_Handle *result)
{
  result->p0 = this;
  result->p1 = 0i64;
  return result;
}

// File Line: 2447
// RVA: 0xE44D10
_BOOL8 __fastcall StructArrayImplementation::Object::isValid(StructArrayImplementation::Object *this, int it)
{
  return it < this->m_impl->m_memberData.m_size;
}

// File Line: 2451
// RVA: 0xE445A0
__int64 __fastcall hkDataObjectNative::getNextMember(hkDataObjectDict *this, int it)
{
  return (unsigned int)(it + 1);
}

// File Line: 2455
// RVA: 0xE44520
const char *__fastcall StructArrayImplementation::Object::getMemberName(
        StructArrayImplementation::Object *this,
        int it)
{
  return this->m_impl->m_memberData.m_data[it].m_memberName.m_cachedString;
}

// File Line: 2459
// RVA: 0xE44550
hkDataObject_Value *__fastcall StructArrayImplementation::Object::getMemberValue(
        StructArrayImplementation::Object *this,
        hkDataObject_Value *result,
        int it)
{
  StructArrayImplementation *m_impl; // rax
  const struct _hkDataObject_MemberHandle *m_cachedString; // rcx
  hkDataObject_Value *v5; // rax

  m_impl = this->m_impl;
  result->m_impl = this;
  m_cachedString = (const struct _hkDataObject_MemberHandle *)m_impl->m_memberData.m_data[it].m_memberName.m_cachedString;
  v5 = result;
  result->m_handle = m_cachedString;
  return v5;
}

// File Line: 2464
// RVA: 0xE44060
void __fastcall StructArrayImplementation::Object::getAllMemberHandles(
        StructArrayImplementation::Object *this,
        hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  const struct _hkDataObject_MemberHandle **v2; // r9
  hkDataClassDict *i; // r8
  __int64 m_size; // rdx
  hkDataClassDict::MemberInfo *m_data; // rcx
  __int64 j; // rax

  v2 = &handles->m_data[handles->m_size];
  for ( i = this->m_impl->m_class.m_pntr; i; i = i->m_parent.m_pntr )
  {
    m_size = i->m_memberInfo.m_size;
    m_data = i->m_memberInfo.m_data;
    v2 -= m_size;
    for ( j = 0i64; j < m_size; ++m_data )
      v2[j++] = (const struct _hkDataObject_MemberHandle *)m_data;
  }
}

// File Line: 2468
// RVA: 0xE44A00
InternedString *__fastcall StructArrayImplementation::Object::intern(
        StructArrayImplementation::Object *this,
        InternedString *result,
        const char *name)
{
  hkDataWorldDict::ObjectTracker::intern(this->m_impl->m_class.m_pntr->m_world->m_tracker, result, name);
  return result;
}

// File Line: 2476
// RVA: 0xE430C0
const float *__fastcall StructArrayImplementation::Object::asVec(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        int n)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (const float *)m_values->vfptr[11].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2487
// RVA: 0xE43020
const char *__fastcall StructArrayImplementation::Object::asString(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (const char *)m_values->vfptr[13].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2488
// RVA: 0xE42990
hkDataArrayImpl *__fastcall StructArrayImplementation::Object::asArray(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (hkDataArrayImpl *)m_values->vfptr[23].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2489
// RVA: 0xE42BF0
void *__fastcall StructArrayImplementation::Object::asInt(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return m_values->vfptr[17].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2490
// RVA: 0xE42B50
void *__fastcall StructArrayImplementation::Object::asInt64(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return m_values->vfptr[19].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2491
// RVA: 0xE42DF0
void __fastcall StructArrayImplementation::Object::asReal(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  m_values->vfptr[15].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2492
// RVA: 0xE42AD0
hkHalf *__fastcall StructArrayImplementation::Object::asHalf(
        StructArrayImplementation::Object *this,
        hkHalf *result,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, hkHalf *, _QWORD))m_values->vfptr[25].__vecDelDtor)(
    m_values,
    result,
    (unsigned int)this->m_index);
  return result;
}

// File Line: 2496
// RVA: 0xE42CD0
hkDataObjectImpl *__fastcall StructArrayImplementation::Object::asObject(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (hkDataObjectImpl *)m_values->vfptr[21].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2502
// RVA: 0xE431B0
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        hkDataObject_Value *valueIn)
{
  int v5; // eax

  v5 = StructArrayImplementation::_findOrAdd(this->m_impl, handle);
  hkDataArrayImpl::set(this->m_impl->m_memberData.m_data[v5].m_values, this->m_index, valueIn);
}

// File Line: 2508
// RVA: 0xE43390
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        hkDataObjectImpl *valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))m_values->vfptr[22].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2514
// RVA: 0xE43340
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        hkDataArrayImpl *valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataArrayImpl *))m_values->vfptr[24].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2520
// RVA: 0xE433E0
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        const char *valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const char *))m_values->vfptr[14].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2526
// RVA: 0xE432F0
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        float valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  m_values->vfptr[16].__vecDelDtor(m_values, this->m_index);
}

// File Line: 2532
// RVA: 0xE43480
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        hkHalf valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))m_values->vfptr[26].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    (unsigned __int16)valueIn.m_value);
}

// File Line: 2538
// RVA: 0xE43430
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        const float *valueIn,
        int nreal)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const float *))m_values->vfptr[12].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2544
// RVA: 0xE43200
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        char valueIn)
{
  unsigned int v4; // edi
  hkDataArrayImpl *m_values; // rcx

  v4 = valueIn;
  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))m_values->vfptr[18].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    v4);
}

// File Line: 2550
// RVA: 0xE43250
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        __int16 valueIn)
{
  unsigned int v4; // edi
  hkDataArrayImpl *m_values; // rcx

  v4 = valueIn;
  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))m_values->vfptr[18].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    v4);
}

// File Line: 2556
// RVA: 0xE432A0
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        unsigned int valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))m_values->vfptr[18].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2562
// RVA: 0xE434D0
void __fastcall StructArrayImplementation::Object::assign(
        StructArrayImplementation::Object *this,
        hkDataClassDict::MemberInfo *handle,
        __int64 valueIn)
{
  hkDataArrayImpl *m_values; // rcx

  m_values = this->m_impl->m_memberData.m_data[(int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))m_values->vfptr[20].__vecDelDtor)(
    m_values,
    (unsigned int)this->m_index,
    valueIn);
}

// File Line: 2568
// RVA: 0xE44500
void __fastcall hkDataObjectDict::getMemberInfo(
        hkDataObjectDict *this,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataClass_MemberInfo *infoOut)
{
  const char *v3; // rax

  v3 = *(const char **)handle;
  infoOut->m_owner = 0i64;
  infoOut->m_name = v3;
  infoOut->m_type = (hkTypeManager::Type *)*((_QWORD *)handle + 2);
  infoOut->m_valuePtr = (const void *)*((_QWORD *)handle + 3);
}

// File Line: 2584
// RVA: 0xE40F00
void __fastcall StructArrayImplementation::StructArrayImplementation(
        StructArrayImplementation *this,
        hkDataWorldDict *world,
        hkTypeManager::Type *type,
        hkDataClassDict *klass,
        int size)
{
  int v5; // esi
  hkDataClassDict *m_pntr; // rdi
  int v8; // ecx
  hkDataClassDict *v9; // rax
  hkDataClassDict::MemberInfo *v10; // rdx

  v5 = 0;
  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  this->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::`vftable;
  this->m_memberData.m_data = 0i64;
  this->m_memberData.m_size = 0;
  this->m_memberData.m_capacityAndFlags = 0x80000000;
  if ( klass )
    ++klass->m_count;
  this->m_class.m_pntr = klass;
  this->m_type = type;
  this->m_size = size;
  this->m_world = world;
  if ( ((int (__fastcall *)(hkDataClassDict *))klass->vfptr[9].__vecDelDtor)(klass) > 0 )
  {
    do
    {
      m_pntr = this->m_class.m_pntr;
      v8 = v5 - ((__int64 (__fastcall *)(hkDataClassDict *))m_pntr->vfptr[9].__vecDelDtor)(m_pntr);
      v9 = m_pntr;
      while ( 1 )
      {
        v8 += v9->m_memberInfo.m_size;
        if ( v8 >= 0 )
          break;
        v9 = v9->m_parent.m_pntr;
        if ( !v9 )
        {
          v10 = m_pntr->m_memberInfo.m_data - 1;
          goto LABEL_9;
        }
      }
      v10 = &v9->m_memberInfo.m_data[v8];
LABEL_9:
      StructArrayImplementation::_addMember(this, v10, this->m_size);
      ++v5;
    }
    while ( v5 < ((int (__fastcall *)(hkDataClassDict *))this->m_class.m_pntr->vfptr[9].__vecDelDtor)(this->m_class.m_pntr) );
  }
  hkDataWorldDict::ObjectTracker::trackStructArray(this->m_world->m_tracker, this);
}

// File Line: 2592
// RVA: 0xE412A0
void __fastcall StructArrayImplementation::~StructArrayImplementation(StructArrayImplementation *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataArrayImpl *m_values; // rcx
  bool v5; // zf
  hkDataWorldDict::ObjectTracker *m_tracker; // rdi
  unsigned __int64 v7; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v8; // rax
  int m_capacityAndFlags; // r8d
  hkMemoryAllocator *m_allocator; // rcx
  hkDataClassDict *m_pntr; // rcx
  hkResult result; // [rsp+30h] [rbp+8h] BYREF

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::`vftable;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_values = this->m_memberData.m_data[v3].m_values;
      v5 = m_values->m_count-- == 1;
      if ( v5 )
        m_values->vfptr->__vecDelDtor(m_values, 1u);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_memberData.m_size );
  }
  m_tracker = this->m_world->m_tracker;
  v7 = ((__int64 (__fastcall *)(StructArrayImplementation *))this->vfptr[6].__vecDelDtor)(this);
  v8 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                                                            &m_tracker->m_arraysFromClass.m_map,
                                                                                            v7,
                                                                                            0i64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
    v8,
    &result,
    (unsigned __int64)this);
  m_capacityAndFlags = this->m_memberData.m_capacityAndFlags;
  m_allocator = this->m_world->m_allocator;
  this->m_memberData.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    m_allocator->vfptr->bufFree(m_allocator, this->m_memberData.m_data, 16 * m_capacityAndFlags);
  this->m_memberData.m_data = 0i64;
  this->m_memberData.m_capacityAndFlags = 0x80000000;
  m_pntr = this->m_class.m_pntr;
  if ( m_pntr )
  {
    v5 = m_pntr->m_count-- == 1;
    if ( v5 )
      m_pntr->vfptr->__vecDelDtor(m_pntr, 1u);
  }
  this->m_class.m_pntr = 0i64;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2602
// RVA: 0xE44890
hkDataWorldDict *__fastcall Scaleform::SysAllocPagedMalloc::GetBase(VecArrayImplementation *this)
{
  return this->m_world;
}

// File Line: 2606
// RVA: 0xE42D20
hkDataObjectImpl *__fastcall StructArrayImplementation::asObject(StructArrayImplementation *this, int i)
{
  _QWORD **Value; // rax
  hkDataObjectImpl *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( !result )
    return 0i64;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result[1].vfptr = (hkDataRefCountedVtbl *)this;
  result->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::Object::`vftable;
  *(_DWORD *)&result[1].m_memSize = i;
  return result;
}

// File Line: 2610
// RVA: 0xE465E0
void __fastcall StructArrayImplementation::setObject(StructArrayImplementation *this, int index, hkDataObjectImpl *val)
{
  int v3; // esi
  __int64 v7; // r14
  StructArrayImplementation::MemberData *m_data; // rdi
  hkDataObject_Value *v9; // rax
  char v11[16]; // [rsp+20h] [rbp-28h] BYREF

  ++val->m_count;
  v3 = 0;
  if ( this->m_memberData.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      m_data = this->m_memberData.m_data;
      v9 = (hkDataObject_Value *)((__int64 (__fastcall *)(hkDataObjectImpl *, char *, const char *))val->vfptr[3].__vecDelDtor)(
                                   val,
                                   v11,
                                   m_data[v7].m_memberName.m_cachedString);
      hkDataArrayImpl::set(m_data[v7].m_values, index, v9);
      ++v3;
      ++v7;
    }
    while ( v3 < this->m_memberData.m_size );
  }
  if ( val->m_count-- == 1 )
    val->vfptr->__vecDelDtor(val, 1i64);
}

// File Line: 2631
// RVA: 0xE43A30
void __fastcall StructArrayImplementation::clear(StructArrayImplementation *this)
{
  int v1; // edi
  __int64 v3; // rsi
  hkDataArrayImpl *m_values; // rcx

  v1 = 0;
  if ( this->m_memberData.m_size <= 0 )
  {
    this->m_size = 0;
  }
  else
  {
    v3 = 0i64;
    do
    {
      m_values = this->m_memberData.m_data[v3].m_values;
      ((void (__fastcall *)(hkDataArrayImpl *))m_values->vfptr[2].__vecDelDtor)(m_values);
      ++v1;
      ++v3;
    }
    while ( v1 < this->m_memberData.m_size );
    this->m_size = 0;
  }
}

// File Line: 2639
// RVA: 0xE45640
void __fastcall StructArrayImplementation::reserve(StructArrayImplementation *this, unsigned int n)
{
  int v2; // ebx
  __int64 v5; // rdi
  hkDataArrayImpl *m_values; // rcx

  v2 = 0;
  if ( this->m_memberData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_values = this->m_memberData.m_data[v5].m_values;
      m_values->vfptr[3].__vecDelDtor(m_values, n);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_memberData.m_size );
  }
}

// File Line: 2646
// RVA: 0xE46960
void __fastcall StructArrayImplementation::setSize(StructArrayImplementation *this, unsigned int n)
{
  int v2; // ebx
  __int64 v5; // rdi
  hkDataArrayImpl *m_values; // rcx

  v2 = 0;
  this->m_size = n;
  if ( this->m_memberData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_values = this->m_memberData.m_data[v5].m_values;
      m_values->vfptr[4].__vecDelDtor(m_values, n);
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_memberData.m_size );
  }
}

// File Line: 2671
// RVA: 0xE46E00
hkDataArrayImpl *__fastcall StructArrayImplementation::swizzleObjectMember(StructArrayImplementation *this, char *name)
{
  return this->m_memberData.m_data[(int)StructArrayImplementation::_find(this, name)].m_values;
}

// File Line: 2679
// RVA: 0xE402C0
void __fastcall hkDataArrayDict_create(hkDataWorldDict *world, hkTypeManager::Type *t, int size)
{
  _QWORD **v6; // rax
  __int64 v7; // rax
  int v8; // ebx
  __int64 v9; // rdi
  hkDataArrayImpl *v10; // rax
  hkTypeManager::Type *v11; // rdx
  _QWORD **v12; // rax
  __int64 v13; // rax
  _QWORD **v14; // rax
  __int64 v15; // rdi
  int TupleSize; // eax
  _QWORD **v17; // rax
  __int64 v18; // rax
  _QWORD **v19; // rax
  __int64 v20; // rax
  _QWORD **v21; // rax
  __int64 v22; // rax
  _QWORD **Value; // rax
  __int64 v24; // rax
  hkTypeManager::Type *m_parent; // rdi
  hkBaseObjectVtbl *v26; // rbx
  const char *v27; // rax
  _QWORD **v28; // rax
  __int64 v29; // rax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *TypeName; // rax
  hkDataClassDict *v32; // rbx
  _QWORD **v33; // rax
  StructArrayImplementation *v34; // rax
  hkDataArrayImpl *v35; // [rsp+58h] [rbp+10h]

  switch ( t->m_subType )
  {
    case SUB_TYPE_BYTE:
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
      if ( v24 )
      {
        *(_QWORD *)(v24 + 8) = 0xFFFFi64;
        *(_QWORD *)(v24 + 16) = 0i64;
        *(_DWORD *)(v24 + 24) = 0;
        *(_DWORD *)(v24 + 28) = 0x80000000;
        *(_QWORD *)(v24 + 32) = world;
        *(_QWORD *)v24 = &ByteArrayImplementation::`vftable;
        *(_QWORD *)(v24 + 40) = t;
      }
      break;
    case SUB_TYPE_REAL:
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 48i64);
      if ( v22 )
      {
        *(_QWORD *)(v22 + 8) = 0xFFFFi64;
        *(_QWORD *)(v22 + 16) = 0i64;
        *(_DWORD *)(v22 + 24) = 0;
        *(_DWORD *)(v22 + 28) = 0x80000000;
        *(_QWORD *)(v22 + 32) = world;
        *(_QWORD *)v22 = &RealArrayImplementation::`vftable;
        *(_QWORD *)(v22 + 40) = t;
      }
      break;
    case SUB_TYPE_INT:
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v17[11] + 8i64))(v17[11], 72i64);
      if ( v18 )
      {
        *(_QWORD *)(v18 + 8) = 0xFFFFi64;
        *(_QWORD *)(v18 + 16) = world;
        *(_DWORD *)(v18 + 24) = 0;
        *(_QWORD *)v18 = &VariableIntArrayImplementation::`vftable;
        *(_QWORD *)(v18 + 32) = 0i64;
        *(_DWORD *)(v18 + 40) = 0;
        *(_DWORD *)(v18 + 44) = 0x80000000;
        *(_QWORD *)(v18 + 48) = 0i64;
        *(_DWORD *)(v18 + 56) = 0;
        *(_DWORD *)(v18 + 60) = 0x80000000;
        *(_BYTE *)(v18 + 64) = 0;
      }
      break;
    case SUB_TYPE_CSTRING:
      v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v19[11] + 8i64))(v19[11], 48i64);
      if ( v20 )
      {
        *(_QWORD *)(v20 + 8) = 0xFFFFi64;
        *(_QWORD *)(v20 + 16) = 0i64;
        *(_DWORD *)(v20 + 24) = 0;
        *(_DWORD *)(v20 + 28) = 0x80000000;
        *(_QWORD *)(v20 + 32) = world;
        *(_QWORD *)v20 = &CstringArrayImplementation::`vftable;
        *(_QWORD *)(v20 + 40) = t;
      }
      break;
    case SUB_TYPE_CLASS:
      vfptr = world->vfptr;
      TypeName = hkTypeManager::Type::getTypeName(t);
      v32 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))vfptr[4].__first_virtual_table_function__)(
                                 world,
                                 TypeName);
      if ( v32 )
      {
        v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v34 = (StructArrayImplementation *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v33[11] + 8i64))(
                                             v33[11],
                                             64i64);
        if ( v34 )
          StructArrayImplementation::StructArrayImplementation(v34, world, t, v32, size);
      }
      break;
    case SUB_TYPE_POINTER:
      m_parent = t->m_parent;
      if ( !hkTypeManager::Type::getTypeName(m_parent)
        || (v26 = world->vfptr,
            v27 = hkTypeManager::Type::getTypeName(m_parent),
            ((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v26[4].__first_virtual_table_function__)(
              world,
              v27)) )
      {
        v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v29 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 48i64);
        if ( v29 )
        {
          *(_QWORD *)(v29 + 8) = 0xFFFFi64;
          *(_QWORD *)(v29 + 16) = 0i64;
          *(_DWORD *)(v29 + 24) = 0;
          *(_DWORD *)(v29 + 28) = 0x80000000;
          *(_QWORD *)(v29 + 32) = world;
          *(_QWORD *)v29 = &PointerArrayImplementation::`vftable;
          *(_QWORD *)(v29 + 40) = t;
        }
      }
      break;
    case SUB_TYPE_ARRAY:
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 48i64);
      v8 = 0;
      v9 = v7;
      if ( v7 )
      {
        *(_QWORD *)(v7 + 8) = 0xFFFFi64;
        *(_QWORD *)(v7 + 16) = 0i64;
        *(_DWORD *)(v7 + 24) = 0;
        *(_DWORD *)(v7 + 28) = 0x80000000;
        *(_QWORD *)(v7 + 32) = world;
        *(_QWORD *)(v7 + 40) = t;
        *(_QWORD *)v7 = &ArrayArrayImplementation::`vftable;
      }
      else
      {
        v9 = 0i64;
      }
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 32i64))(v9, (unsigned int)size);
      if ( size > 0 )
      {
        do
        {
          v10 = hkDataArrayDict_create(world, t->m_parent, 0);
          (*(void (__fastcall **)(__int64, _QWORD, hkDataArrayImpl *))(*(_QWORD *)v9 + 192i64))(
            v9,
            (unsigned int)v8++,
            v10);
        }
        while ( v8 < size );
      }
      break;
    case SUB_TYPE_TUPLE:
      v11 = t->m_parent;
      if ( v11->m_subType == SUB_TYPE_REAL )
      {
        v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v12[11] + 8i64))(v12[11], 48i64);
        if ( v13 )
        {
          *(_QWORD *)(v13 + 8) = 0xFFFFi64;
          *(_QWORD *)v13 = &VecArrayImplementation::`vftable;
          *(_QWORD *)(v13 + 16) = 0i64;
          *(_DWORD *)(v13 + 24) = 0;
          *(_DWORD *)(v13 + 28) = 0x80000000;
          *(_QWORD *)(v13 + 32) = world;
          *(_QWORD *)(v13 + 40) = t;
        }
      }
      else
      {
        v35 = hkDataArrayDict_create(world, v11, 0);
        v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v15 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 48i64);
        if ( v15 )
        {
          TupleSize = hkTypeManager::Type::getTupleSize(t);
          *(_QWORD *)v15 = &ArrayOfTuplesImplementation::`vftable;
          *(_QWORD *)(v15 + 8) = 0xFFFFi64;
          *(_QWORD *)(v15 + 16) = world;
          *(_DWORD *)(v15 + 32) = TupleSize;
          *(_QWORD *)(v15 + 40) = 0i64;
          *(_QWORD *)(v15 + 24) = v35;
          if ( v35 )
            ++v35->m_count;
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 2768
// RVA: 0xE40770
void __fastcall hkDataWorldDict::ObjectTracker::ObjectTracker(
        hkDataWorldDict::ObjectTracker *this,
        hkMemoryAllocator *mall)
{
  this->m_allocator = mall;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classes.m_map,
    0);
  this->m_derivedFromParent.m_valueChain.m_capacityAndFlags = 0x80000000;
  this->m_derivedFromParent.m_valueChain.m_data = 0i64;
  this->m_derivedFromParent.m_valueChain.m_size = 0;
  this->m_derivedFromParent.m_indexMap.m_map.m_elem = 0i64;
  this->m_derivedFromParent.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&this->m_derivedFromParent.m_indexMap.m_map.m_hashMod = -1i64;
  this->m_topLevelObject = 0i64;
  this->m_objectsFromClass.m_valueChain.m_data = 0i64;
  this->m_objectsFromClass.m_valueChain.m_size = 0;
  this->m_objectsFromClass.m_valueChain.m_capacityAndFlags = 0x80000000;
  this->m_objectsFromClass.m_indexMap.m_map.m_elem = 0i64;
  this->m_objectsFromClass.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&this->m_objectsFromClass.m_indexMap.m_map.m_hashMod = -1i64;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_interns.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_internedClassNames.m_map,
    0);
  this->m_arraysFromClass.m_map.m_elem = 0i64;
  this->m_arraysFromClass.m_map.m_numElems = 0;
  this->m_arraysFromClass.m_map.m_hashMod = -1;
}

// File Line: 2773
// RVA: 0xE40820
void __fastcall hkDataWorldDict::ObjectTracker::~ObjectTracker(hkDataWorldDict::ObjectTracker *this)
{
  int m_size; // ebx
  __int64 v2; // rdi
  hkLifoAllocator *Value; // rcx
  _QWORD *m_cur; // rax
  int v6; // edx
  char *v7; // r8
  int m_numElems; // ebx
  int v9; // r12d
  hkLifoAllocator *v10; // rax
  char *v11; // rsi
  int v12; // edx
  char *v13; // rcx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *p_m_classes; // rbx
  Dummy *Iterator; // r14
  unsigned __int64 v16; // rax
  __int64 v17; // rcx
  hkDataClassDict *v18; // r15
  int FirstIndex; // eax
  int v20; // ecx
  __int64 v21; // rbx
  hkDataObjectDict *v22; // rsi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rax
  int v24; // eax
  int v25; // r15d
  __int64 v26; // r14
  hkDataObjectDict *v27; // rsi
  __int64 v28; // rax
  unsigned int m_externalCount; // edi
  const char *v30; // rbx
  hkOstream *v31; // rax
  hkOstream *v32; // rax
  hkOstream *v33; // rax
  hkOstream *v34; // rax
  int v35; // ebx
  __int64 v36; // rcx
  bool v37; // zf
  char *v38; // rbx
  __int64 v39; // rdi
  void (__fastcall ***v40)(_QWORD, __int64); // rcx
  Dummy *Next; // rbx
  hkReferencedObject *v42; // rax
  Dummy *v43; // rbx
  char *v44; // rax
  hkPointerMap<hkDataClassDict *,hkPointerMap<hkDataArrayImpl *,int,hkContainerHeapAllocator> *,hkContainerHeapAllocator> *p_m_arraysFromClass; // rsi
  __int64 m_hashMod; // r8
  int v47; // edx
  __int64 v48; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *m_elem; // rax
  int v50; // ebx
  AMD_HD3D *val; // rdi
  _QWORD **v52; // rax
  __int64 v53; // r8
  int v54; // edx
  __int64 v55; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v56; // rax
  signed int v57; // ebx
  hkLifoAllocator *v58; // rax
  void *v59; // rdx
  int v60; // r8d
  int v61; // eax
  char *v62; // rdi
  signed int v63; // ebx
  hkLifoAllocator *v64; // rax
  int v65; // r8d
  int m_capacityAndFlags; // r8d
  int v67; // r8d
  _QWORD *array; // [rsp+20h] [rbp-E0h] BYREF
  int v69; // [rsp+28h] [rbp-D8h]
  int v70; // [rsp+2Ch] [rbp-D4h]
  void *v71; // [rsp+30h] [rbp-D0h]
  int v72; // [rsp+38h] [rbp-C8h]
  hkErrStream v73; // [rsp+40h] [rbp-C0h] BYREF
  char buf[576]; // [rsp+60h] [rbp-A0h] BYREF
  hkBool result; // [rsp+2B0h] [rbp+1B0h] BYREF
  int v76; // [rsp+2B8h] [rbp+1B8h]
  int v77; // [rsp+2C0h] [rbp+1C0h]
  void *p; // [rsp+2C8h] [rbp+1C8h]

  m_size = this->m_objectsFromClass.m_valueChain.m_size;
  v2 = 0i64;
  array = 0i64;
  v69 = 0;
  v70 = 0x80000000;
  v72 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = Value->m_cur;
    v6 = (8 * m_size + 127) & 0xFFFFFF80;
    v7 = (char *)m_cur + v6;
    if ( v6 > Value->m_slabSize || v7 > Value->m_end )
      m_cur = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(Value, v6);
    else
      Value->m_cur = v7;
  }
  else
  {
    m_cur = 0i64;
  }
  array = m_cur;
  v71 = m_cur;
  v70 = m_size | 0x80000000;
  m_numElems = this->m_classes.m_map.m_numElems;
  v9 = 0;
  v76 = m_numElems;
  if ( m_numElems )
  {
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (8 * m_numElems + 127) & 0xFFFFFF80;
    p = v11;
    v13 = &v11[v12];
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
    {
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
      p = v11;
    }
    else
    {
      v10->m_cur = v13;
    }
  }
  else
  {
    v11 = 0i64;
    p = 0i64;
  }
  v77 = m_numElems | 0x80000000;
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::clear(&this->m_derivedFromParent);
  p_m_classes = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes;
  this->m_topLevelObject = 0i64;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    v16 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(p_m_classes, Iterator);
    v17 = v9++;
    *(_QWORD *)&v11[8 * v17] = v16;
    v18 = (hkDataClassDict *)v16;
    FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                   (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_objectsFromClass,
                   v16);
    if ( FirstIndex != -1 )
    {
      v20 = v69;
      do
      {
        v21 = FirstIndex;
        v22 = this->m_objectsFromClass.m_valueChain.m_data[FirstIndex].value;
        if ( v20 == (v70 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
          v20 = v69;
        }
        array[v20] = v22;
        m_data = this->m_objectsFromClass.m_valueChain.m_data;
        v20 = ++v69;
        FirstIndex = m_data[v21].next;
      }
      while ( FirstIndex != -1 );
      hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
        &this->m_objectsFromClass,
        v18);
      v11 = (char *)p;
      p_m_classes = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes;
    }
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(p_m_classes, Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_classes, &result, Iterator);
  }
  v24 = v69;
  v25 = 0;
  if ( v69 > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = (hkDataObjectDict *)array[v26];
      if ( v27->m_externalCount > 0 )
      {
        hkErrStream::hkErrStream(&v73, buf, 512);
        v28 = ((__int64 (__fastcall *)(hkDataObjectDict *))v27->vfptr[2].__vecDelDtor)(v27);
        m_externalCount = v27->m_externalCount;
        v30 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v28 + 16i64))(v28);
        v31 = hkOstream::operator<<(&v73, "The object of class ");
        v32 = hkOstream::operator<<(v31, v30);
        v33 = hkOstream::operator<<(
                v32,
                " is about to be removed and all references to it will be invalid.\nHowever, the object is referenced (");
        v34 = hkOstream::operator<<(v33, m_externalCount);
        hkOstream::operator<<(v34, ") from outside the world and it will lead to unexpected behavior or crash.");
        hkError::messageWarning(0x760D3795u, buf, "Data\\Dict\\hkDataObjectDict.cpp", 2802);
        hkOstream::~hkOstream(&v73);
      }
      hkDataObjectDict::selfDestruct(v27);
      v24 = v69;
      ++v25;
      ++v26;
    }
    while ( v25 < v69 );
    v2 = 0i64;
  }
  v35 = 0;
  if ( v24 > 0 )
  {
    do
    {
      v36 = array[v2];
      v37 = (*(_DWORD *)(v36 + 12))-- == 1;
      if ( v37 )
        (**(void (__fastcall ***)(__int64, __int64))v36)(v36, 1i64);
      ++v35;
      ++v2;
    }
    while ( v35 < v69 );
  }
  if ( v9 > 0 )
  {
    v38 = (char *)p;
    v39 = (unsigned int)v9;
    do
    {
      v40 = *(void (__fastcall ****)(_QWORD, __int64))v38;
      v37 = (*(_DWORD *)(*(_QWORD *)v38 + 12i64))-- == 1;
      if ( v37 )
        (**v40)(v40, 1i64);
      v38 += 8;
      --v39;
    }
    while ( v39 );
  }
  Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
    &result,
    Next);
  while ( result.m_bool )
  {
    v42 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
                                  Next);
    hkReferencedObject::removeReference(v42);
    Next = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
             Next);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
      &result,
      Next);
  }
  v43 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
    &result,
    v43);
  while ( result.m_bool )
  {
    v44 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
                    v43);
    hkString::strFree(v44);
    v43 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
            v43);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
      &result,
      v43);
  }
  p_m_arraysFromClass = &this->m_arraysFromClass;
  m_hashMod = this->m_arraysFromClass.m_map.m_hashMod;
  v47 = 0;
  v48 = 0i64;
  if ( m_hashMod >= 0 )
  {
    m_elem = p_m_arraysFromClass->m_map.m_elem;
    do
    {
      if ( m_elem->key != -1i64 )
        break;
      ++v48;
      ++v47;
      ++m_elem;
    }
    while ( v48 <= m_hashMod );
  }
  v50 = v47;
  if ( v47 <= this->m_arraysFromClass.m_map.m_hashMod )
  {
    do
    {
      val = (AMD_HD3D *)p_m_arraysFromClass->m_map.m_elem[v50].val;
      if ( val )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)p_m_arraysFromClass->m_map.m_elem[v50].val,
          &hkContainerHeapAllocator::s_alloc);
        _(val);
        v52 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, AMD_HD3D *, __int64))(*v52[11] + 16i64))(v52[11], val, 16i64);
      }
      v53 = this->m_arraysFromClass.m_map.m_hashMod;
      v54 = v50 + 1;
      v55 = v50 + 1;
      if ( v55 <= v53 )
      {
        v56 = &p_m_arraysFromClass->m_map.m_elem[v54];
        do
        {
          if ( v56->key != -1i64 )
            break;
          ++v55;
          ++v54;
          ++v56;
        }
        while ( v55 <= v53 );
      }
      v50 = v54;
    }
    while ( v54 <= this->m_arraysFromClass.m_map.m_hashMod );
  }
  v57 = (8 * v76 + 127) & 0xFFFFFF80;
  v58 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v59 = p;
  v60 = (v57 + 15) & 0xFFFFFFF0;
  if ( v57 > v58->m_slabSize || (char *)p + v60 != v58->m_cur || v58->m_firstNonLifoEnd == p )
  {
    hkLifoAllocator::slowBlockFree(v58, (char *)p, v60);
    v59 = p;
  }
  else
  {
    v58->m_cur = p;
  }
  if ( v77 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v59, 8 * v77);
  v61 = v69;
  v62 = (char *)v71;
  if ( v71 == array )
    v61 = 0;
  v69 = v61;
  v63 = (8 * v72 + 127) & 0xFFFFFF80;
  v64 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v65 = (v63 + 15) & 0xFFFFFFF0;
  if ( v63 > v64->m_slabSize || &v62[v65] != v64->m_cur || v64->m_firstNonLifoEnd == v62 )
    hkLifoAllocator::slowBlockFree(v64, v62, v65);
  else
    v64->m_cur = v62;
  v69 = 0;
  if ( v70 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v70);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_arraysFromClass.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_arraysFromClass);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_internedClassNames.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_interns.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_objectsFromClass.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_objectsFromClass.m_indexMap);
  m_capacityAndFlags = this->m_objectsFromClass.m_valueChain.m_capacityAndFlags;
  this->m_objectsFromClass.m_valueChain.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_objectsFromClass.m_valueChain.m_data,
      16 * m_capacityAndFlags);
  this->m_objectsFromClass.m_valueChain.m_data = 0i64;
  this->m_objectsFromClass.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &this->m_derivedFromParent.m_indexMap.m_map,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&this->m_derivedFromParent.m_indexMap);
  v67 = this->m_derivedFromParent.m_valueChain.m_capacityAndFlags;
  this->m_derivedFromParent.m_valueChain.m_size = 0;
  if ( v67 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_derivedFromParent.m_valueChain.m_data,
      16 * v67);
  this->m_derivedFromParent.m_valueChain.m_data = 0i64;
  this->m_derivedFromParent.m_valueChain.m_capacityAndFlags = 0x80000000;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_classes.m_map);
}

// File Line: 2849
// RVA: 0xE46F40
void __fastcall hkDataWorldDict::ObjectTracker::trackStructArray(
        hkDataWorldDict::ObjectTracker *this,
        hkDataArrayImpl *a)
{
  unsigned __int64 v4; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  _QWORD **Value; // rax
  __int64 v7; // rax

  v4 = ((__int64 (__fastcall *)(hkDataArrayImpl *))a->vfptr[6].__vecDelDtor)(a);
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                                                            &this->m_arraysFromClass.m_map,
                                                                                            v4,
                                                                                            0i64);
  if ( !v5 )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 16i64);
    v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v7;
    if ( v7 )
    {
      *(_QWORD *)v7 = 0i64;
      *(_DWORD *)(v7 + 8) = 0;
      *(_DWORD *)(v7 + 12) = -1;
    }
    else
    {
      v5 = 0i64;
    }
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &this->m_arraysFromClass.m_map,
      &hkContainerHeapAllocator::s_alloc,
      v4,
      (unsigned __int64)v5);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    v5,
    &hkContainerHeapAllocator::s_alloc,
    (unsigned __int64)a,
    0i64);
}

// File Line: 2873
// RVA: 0xE44650
void __fastcall hkDataWorldDict::ObjectTracker::getTrackedStructArrays(
        hkDataWorldDict::ObjectTracker *this,
        hkDataClassDict *c,
        unsigned int baseClass,
        hkArray<hkDataArrayImpl *,hkContainerTempAllocator> *arraysOut)
{
  hkDataWorldDict::ObjectTracker *v4; // rsi
  hkDataClassDict *v6; // rbx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdi
  int v9; // ebx
  __int64 m_size; // rsi
  int v11; // r9d
  int v12; // eax
  int v13; // eax
  __int64 v14; // r9
  int v15; // edx
  hkDataArrayImpl **v16; // r10
  __int64 v17; // rcx
  _QWORD *v18; // rax
  __int64 v19; // rcx
  __int64 v20; // r9
  __int64 v21; // rcx
  _QWORD *v22; // rax
  int FirstIndex; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v25; // rbx
  hkResult result; // [rsp+30h] [rbp-28h] BYREF

  v4 = this;
  v6 = c;
  v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &this->m_arraysFromClass.m_map,
         (unsigned __int64)c,
         0i64);
  v8 = v7;
  if ( v7 )
  {
    v9 = *(_DWORD *)(v7 + 8) & 0x7FFFFFFF;
    if ( v9 )
    {
      m_size = arraysOut->m_size;
      v11 = m_size + v9;
      v12 = arraysOut->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v12 < (int)m_size + v9 )
      {
        v13 = 2 * v12;
        if ( v11 < v13 )
          v11 = v13;
        hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&arraysOut->m_data, v11, 8);
      }
      arraysOut->m_size += v9;
      v14 = *(int *)(v8 + 12);
      v15 = 0;
      v16 = &arraysOut->m_data[m_size];
      v17 = 0i64;
      if ( (int)v14 >= 0 )
      {
        v18 = *(_QWORD **)v8;
        do
        {
          if ( *v18 != -1i64 )
            break;
          ++v17;
          ++v15;
          v18 += 2;
        }
        while ( v17 <= v14 );
      }
      if ( v15 <= (int)v14 )
      {
        do
        {
          ++v16;
          v19 = 2i64 * v15++;
          *(v16 - 1) = *(hkDataArrayImpl **)(*(_QWORD *)v8 + 8 * v19);
          v20 = *(int *)(v8 + 12);
          v21 = v15;
          if ( v15 <= v20 )
          {
            v22 = (_QWORD *)(*(_QWORD *)v8 + 16i64 * v15);
            do
            {
              if ( *v22 != -1i64 )
                break;
              ++v21;
              ++v15;
              v22 += 2;
            }
            while ( v21 <= v20 );
          }
        }
        while ( v15 <= (int)v20 );
      }
      v4 = this;
    }
    v6 = c;
  }
  if ( baseClass )
  {
    FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                   (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v4->m_derivedFromParent,
                   (unsigned __int64)v6);
    if ( FirstIndex != -1 )
    {
      m_data = v4->m_derivedFromParent.m_valueChain.m_data;
      do
      {
        v25 = FirstIndex;
        hkDataWorldDict::ObjectTracker::getTrackedStructArrays(v4, m_data[FirstIndex].value, baseClass, arraysOut);
        m_data = v4->m_derivedFromParent.m_valueChain.m_data;
        FirstIndex = m_data[v25].next;
      }
      while ( FirstIndex != -1 );
    }
  }
}

// File Line: 2897
// RVA: 0xE46EB0
void __fastcall hkDataWorldDict::ObjectTracker::trackClass(
        hkDataWorldDict::ObjectTracker *this,
        hkDataObjectDict *klass)
{
  hkDataClassDict *v4; // rdi
  const char *v5; // rax
  Dummy *Key; // rax
  const char *v7; // rax
  hkBool result; // [rsp+40h] [rbp+8h] BYREF
  hkDataObjectDict *value; // [rsp+48h] [rbp+10h] BYREF

  value = klass;
  v4 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))klass->vfptr[4].__vecDelDtor)(klass);
  v5 = (const char *)((__int64 (__fastcall *)(hkDataObjectDict *))klass->vfptr[2].__vecDelDtor)(klass);
  Key = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
          v5);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
    &result,
    Key);
  if ( !result.m_bool )
  {
    v7 = (const char *)((__int64 (__fastcall *)(hkDataObjectDict *))klass->vfptr[2].__vecDelDtor)(klass);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &this->m_classes.m_map,
      v7,
      (unsigned __int64)klass);
    if ( v4 )
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
        v4,
        &value);
  }
}

// File Line: 2921
// RVA: 0xE43D20
void __fastcall hkDataWorldDict::ObjectTracker::findTrackedClasses(
        hkDataWorldDict::ObjectTracker *this,
        hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  int m_numElems; // r9d
  int v4; // eax
  int v6; // eax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *p_m_classes; // rdi
  Dummy *Iterator; // rsi
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_numElems = this->m_classes.m_map.m_numElems;
  v4 = classesOut->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < m_numElems )
  {
    v6 = 2 * v4;
    if ( m_numElems < v6 )
      m_numElems = v6;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerTempAllocator::s_alloc,
      (const void **)&classesOut->m_data,
      m_numElems,
      8);
  }
  p_m_classes = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(p_m_classes);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_classes, (hkBool *)&result, Iterator);
  while ( LOBYTE(result.m_enum) )
  {
    classesOut->m_data[classesOut->m_size++] = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                                                    p_m_classes,
                                                                    Iterator);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(p_m_classes, Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(p_m_classes, (hkBool *)&result, Iterator);
  }
}

// File Line: 2931
// RVA: 0xE43DE0
void __fastcall hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(
        hkDataWorldDict::ObjectTracker *this,
        const char *className,
        unsigned int baseClass,
        unsigned int addStructs,
        hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *v5; // rdi
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbp
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *p_m_objectsFromClass; // rsi
  int FirstIndex; // eax
  __int64 v10; // rdi
  hkDataObjectImpl *value; // rbp
  unsigned __int64 v12; // rax
  _QWORD *v13; // r10
  __int64 v14; // r9
  int v15; // edx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  int v18; // eax
  int v19; // esi
  __int64 v20; // rdi
  hkDataObjectImpl *v21; // rbp
  __int64 v22; // r9
  int v23; // edx
  __int64 v24; // rcx
  _QWORD *v25; // rax
  int next; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v28; // rdi
  const char *v29; // rax
  unsigned __int64 k; // [rsp+30h] [rbp-38h]
  unsigned __int64 v31; // [rsp+38h] [rbp-30h]
  int v33; // [rsp+78h] [rbp+10h]

  if ( className )
  {
    v5 = this;
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
           className,
           0i64);
    v7 = v6;
    k = v6;
    if ( v6 )
    {
      p_m_objectsFromClass = &v5->m_objectsFromClass;
      FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                     (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v5->m_objectsFromClass,
                     v6);
      if ( FirstIndex != -1 )
      {
        do
        {
          v10 = FirstIndex;
          value = p_m_objectsFromClass->m_valueChain.m_data[FirstIndex].value;
          if ( objectsOut->m_size == (objectsOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&objectsOut->m_data, 8);
          objectsOut->m_data[objectsOut->m_size++] = value;
          FirstIndex = p_m_objectsFromClass->m_valueChain.m_data[v10].next;
        }
        while ( FirstIndex != -1 );
        v5 = this;
        v7 = k;
      }
      if ( addStructs )
      {
        v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                &v5->m_arraysFromClass.m_map,
                v7,
                0i64);
        v13 = (_QWORD *)v12;
        v31 = v12;
        if ( v12 )
        {
          if ( (*(_DWORD *)(v12 + 8) & 0x7FFFFFFF) != 0 )
          {
            v14 = *(int *)(v12 + 12);
            v15 = 0;
            v16 = 0i64;
            if ( (int)v14 >= 0 )
            {
              v17 = *(_QWORD **)v12;
              do
              {
                if ( *v17 != -1i64 )
                  break;
                ++v16;
                ++v15;
                v17 += 2;
              }
              while ( v16 <= v14 );
            }
            v18 = v15;
            v33 = v15;
            if ( v15 <= (int)v14 )
            {
              do
              {
                v19 = 0;
                v20 = *(_QWORD *)(*v13 + 16i64 * v18);
                if ( (*(int (__fastcall **)(__int64))(*(_QWORD *)v20 + 40i64))(v20) > 0 )
                {
                  do
                  {
                    v21 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v20 + 168i64))(
                                                v20,
                                                (unsigned int)v19);
                    if ( objectsOut->m_size == (objectsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(
                        &hkContainerTempAllocator::s_alloc,
                        (const void **)&objectsOut->m_data,
                        8);
                    ++v19;
                    objectsOut->m_data[objectsOut->m_size++] = v21;
                  }
                  while ( v19 < (*(int (__fastcall **)(__int64))(*(_QWORD *)v20 + 40i64))(v20) );
                }
                v13 = (_QWORD *)v31;
                v22 = *(int *)(v31 + 12);
                v23 = v33 + 1;
                v24 = v33 + 1;
                if ( v24 <= v22 )
                {
                  v25 = (_QWORD *)(*(_QWORD *)v31 + 16i64 * v23);
                  do
                  {
                    if ( *v25 != -1i64 )
                      break;
                    ++v24;
                    ++v23;
                    v25 += 2;
                  }
                  while ( v24 <= v22 );
                }
                v18 = v23;
                v33 = v23;
              }
              while ( v23 <= (int)v22 );
            }
          }
        }
      }
      if ( baseClass )
      {
        next = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                 (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
                 k);
        if ( next != -1 )
        {
          m_data = this->m_derivedFromParent.m_valueChain.m_data;
          do
          {
            v28 = next;
            v29 = (const char *)((__int64 (__fastcall *)(hkDataClassDict *))m_data[next].value->vfptr[2].__vecDelDtor)(m_data[next].value);
            hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(this, v29, baseClass, addStructs, objectsOut);
            m_data = this->m_derivedFromParent.m_valueChain.m_data;
            next = m_data[v28].next;
          }
          while ( next != -1 );
        }
      }
    }
  }
}

// File Line: 2984
// RVA: 0xE44E90
void __fastcall hkDataWorldDict::ObjectTracker::removeClassContent(
        hkDataWorldDict::ObjectTracker *this,
        hkDataClassDict *klass)
{
  hkDataWorldDict::ObjectTracker *v2; // rdi
  const char *v4; // rax
  int FirstIndex; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v7; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *p_m_objectsFromClass; // rsi
  int next; // ebx
  hkLifoAllocator *Value; // rax
  _QWORD *m_cur; // rcx
  char *v12; // rdx
  int v13; // edx
  int v14; // ecx
  __int64 v15; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v16; // rax
  __int64 v17; // rsi
  _QWORD *v18; // rcx
  __int64 v19; // rax
  unsigned int v20; // edi
  const char *v21; // rbx
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  int v26; // ebx
  __int64 v27; // rdi
  __int64 v28; // rcx
  int v30; // eax
  char *v31; // rdi
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // r8d
  _QWORD *array; // [rsp+20h] [rbp-E0h] BYREF
  int v36; // [rsp+28h] [rbp-D8h]
  int i; // [rsp+2Ch] [rbp-D4h]
  void *p; // [rsp+30h] [rbp-D0h]
  int v39; // [rsp+38h] [rbp-C8h]
  hkErrStream v40; // [rsp+40h] [rbp-C0h] BYREF
  char buf[544]; // [rsp+60h] [rbp-A0h] BYREF
  hkDataObjectDict *v43; // [rsp+298h] [rbp+198h]
  int v44; // [rsp+298h] [rbp+198h]
  hkDataClassDict *k; // [rsp+2A0h] [rbp+1A0h]
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v46; // [rsp+2A8h] [rbp+1A8h]

  v2 = this;
  v4 = (const char *)((__int64 (__fastcall *)(hkDataClassDict *))klass->vfptr[2].__vecDelDtor)(klass);
  if ( v4 )
    k = (hkDataClassDict *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
                             v4,
                             0i64);
  else
    k = 0i64;
  FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                 (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v2->m_derivedFromParent,
                 (unsigned __int64)klass);
  if ( FirstIndex != -1 )
  {
    m_data = v2->m_derivedFromParent.m_valueChain.m_data;
    do
    {
      v7 = FirstIndex;
      hkDataWorldDict::ObjectTracker::removeClassContent(v2, m_data[FirstIndex].value);
      m_data = v2->m_derivedFromParent.m_valueChain.m_data;
      FirstIndex = m_data[v7].next;
    }
    while ( FirstIndex != -1 );
  }
  p_m_objectsFromClass = &v2->m_objectsFromClass;
  v46 = &v2->m_objectsFromClass;
  next = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
           (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v2->m_objectsFromClass,
           (unsigned __int64)k);
  if ( next != -1 )
  {
    i = 0x80000000;
    array = 0i64;
    v36 = 0;
    v39 = 512;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = Value->m_cur;
    v12 = (char *)(m_cur + 512);
    if ( Value->m_slabSize < 4096 || v12 > Value->m_end )
      m_cur = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(Value, 4096);
    else
      Value->m_cur = v12;
    v13 = -2147483136;
    array = m_cur;
    p = m_cur;
    v14 = v36;
    for ( i = -2147483136; ; v13 = i )
    {
      v15 = next;
      v43 = p_m_objectsFromClass->m_valueChain.m_data[v15].value;
      if ( v14 == (v13 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v14 = v36;
      }
      array[v14] = v43;
      v16 = p_m_objectsFromClass->m_valueChain.m_data;
      v14 = ++v36;
      next = v16[v15].next;
      if ( next == -1 )
        break;
    }
    v44 = 0;
    if ( v14 > 0 )
    {
      v17 = 0i64;
      do
      {
        v18 = array;
        if ( v2->m_topLevelObject == (hkDataObjectDict *)array[v17] )
          v2->m_topLevelObject = 0i64;
        if ( *(__int16 *)(v18[v17] + 10i64) > 0 )
        {
          hkErrStream::hkErrStream(&v40, buf, 512);
          v19 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)array[v17] + 16i64))(array[v17]);
          v20 = *(__int16 *)(array[v17] + 10i64);
          v21 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19);
          v22 = hkOstream::operator<<(&v40, "The object of class ");
          v23 = hkOstream::operator<<(v22, v21);
          v24 = hkOstream::operator<<(
                  v23,
                  " is about to be removed and all references to it will be invalid.\n"
                  "However, the object is referenced (");
          v25 = hkOstream::operator<<(v24, v20);
          hkOstream::operator<<(v25, ") from outside the world and it will lead to unexpected behavior or crash.");
          hkError::messageWarning(0x760D3794u, buf, "Data\\Dict\\hkDataObjectDict.cpp", 3017);
          hkOstream::~hkOstream(&v40);
          v18 = array;
          v2 = this;
        }
        hkDataObjectDict::selfDestruct((hkDataObjectDict *)v18[v17]);
        v14 = v36;
        ++v17;
        ++v44;
      }
      while ( v44 < v36 );
      p_m_objectsFromClass = v46;
    }
    v26 = 0;
    if ( v14 > 0 )
    {
      v27 = 0i64;
      do
      {
        v28 = array[v27];
        if ( (*(_DWORD *)(v28 + 12))-- == 1 )
          (**(void (__fastcall ***)(__int64, __int64))v28)(v28, 1i64);
        ++v26;
        ++v27;
      }
      while ( v26 < v36 );
    }
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
      p_m_objectsFromClass,
      k);
    v30 = v36;
    v31 = (char *)p;
    if ( p == array )
      v30 = 0;
    v36 = v30;
    v32 = (8 * v39 + 127) & 0xFFFFFF80;
    v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (v32 + 15) & 0xFFFFFFF0;
    if ( v32 > v33->m_slabSize || &v31[v34] != v33->m_cur || v33->m_firstNonLifoEnd == v31 )
      hkLifoAllocator::slowBlockFree(v33, v31, v34);
    else
      v33->m_cur = v31;
    v36 = 0;
    if ( i >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * i);
  }
}

// File Line: 3030
// RVA: 0xE47000
void __fastcall hkDataWorldDict::ObjectTracker::untrackClass(
        hkDataWorldDict::ObjectTracker *this,
        hkDataClassDict *klass)
{
  hkDataClassDict *v3; // rsi
  const char *v4; // rax
  unsigned __int64 v5; // rbx
  hkDataClassDict *v6; // rax
  __int64 v7; // rbx
  hkLifoAllocator *Value; // rax
  _QWORD *m_cur; // rcx
  char *v10; // rdx
  int FirstIndex; // eax
  int v12; // ecx
  __int64 v13; // rbx
  hkDataObjectDict *v14; // rdi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rax
  int v16; // edi
  __int64 v17; // rcx
  char *v19; // rdi
  signed int v20; // ebx
  hkLifoAllocator *v21; // rax
  int v22; // r8d
  hkReferencedObject *v23; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *p_m_derivedFromParent; // [rsp+20h] [rbp-38h]
  _QWORD *array; // [rsp+28h] [rbp-30h] BYREF
  int v26; // [rsp+30h] [rbp-28h]
  int v27; // [rsp+34h] [rbp-24h]
  void *p; // [rsp+38h] [rbp-20h]
  int v29; // [rsp+40h] [rbp-18h]
  hkDataClassDict *v; // [rsp+88h] [rbp+30h] BYREF
  bool v32; // [rsp+90h] [rbp+38h]
  unsigned __int64 key; // [rsp+98h] [rbp+40h]

  v = klass;
  v3 = klass;
  v4 = (const char *)((__int64 (__fastcall *)(hkDataClassDict *))klass->vfptr[2].__vecDelDtor)(klass);
  key = (unsigned __int64)v4;
  if ( v4 )
    v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
           v4,
           0i64);
  else
    v5 = 0i64;
  hkDataWorldDict::ObjectTracker::removeClassContent(this, v3);
  v6 = (hkDataClassDict *)(*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v5 + 32i64))(v5);
  if ( v6 )
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByValue(
      &this->m_derivedFromParent,
      v6,
      &v);
  hkDataClassDict::selfDestruct(v3);
  v7 = 0i64;
  array = 0i64;
  v26 = 0;
  v27 = 0x80000000;
  v29 = 64;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = Value->m_cur;
  v10 = (char *)(m_cur + 64);
  if ( Value->m_slabSize < 512 || v10 > Value->m_end )
    m_cur = (_QWORD *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
  else
    Value->m_cur = v10;
  array = m_cur;
  p = m_cur;
  v27 = -2147483584;
  p_m_derivedFromParent = (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent;
  FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                 (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
                 (unsigned __int64)v3);
  v32 = FirstIndex != -1;
  if ( FirstIndex == -1 )
  {
    v12 = v26;
  }
  else
  {
    v12 = v26;
    do
    {
      v13 = FirstIndex;
      v14 = p_m_derivedFromParent->m_valueChain.m_data[FirstIndex].value;
      if ( v12 == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 8);
        v12 = v26;
      }
      array[v12] = v14;
      m_data = p_m_derivedFromParent->m_valueChain.m_data;
      v12 = ++v26;
      FirstIndex = m_data[v13].next;
    }
    while ( FirstIndex != -1 );
    v3 = v;
    v7 = 0i64;
  }
  v16 = 0;
  if ( v12 > 0 )
  {
    do
    {
      hkDataWorldDict::ObjectTracker::untrackClass(this, (hkDataClassDict *)array[v7]);
      v17 = array[v7];
      if ( (*(_DWORD *)(v17 + 12))-- == 1 )
        (**(void (__fastcall ***)(__int64, __int64))v17)(v17, 1i64);
      v12 = v26;
      ++v16;
      ++v7;
    }
    while ( v16 < v26 );
    v3 = v;
  }
  if ( v32 )
  {
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
      p_m_derivedFromParent,
      v3);
    v12 = v26;
  }
  v19 = (char *)p;
  if ( p == array )
    v12 = 0;
  v26 = v12;
  v20 = (8 * v29 + 127) & 0xFFFFFF80;
  v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v22 = (v20 + 15) & 0xFFFFFFF0;
  if ( v20 > v21->m_slabSize || &v19[v22] != v21->m_cur || v21->m_firstNonLifoEnd == v19 )
    hkLifoAllocator::slowBlockFree(v21, v19, v22);
  else
    v21->m_cur = v19;
  v26 = 0;
  if ( v27 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 8 * v27);
  v23 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
                                (const char *)key,
                                0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
    &this->m_internedClassNames.m_map,
    (hkResult *)&v,
    (const char *)key);
  hkReferencedObject::removeReference(v23);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
    &this->m_classes.m_map,
    (hkResult *)&v,
    (const char *)key);
}

// File Line: 3094
// RVA: 0xE45770
void __fastcall hkDataWorldDict::ObjectTracker::retrackDerivedClass(
        hkDataWorldDict::ObjectTracker *this,
        hkDataClassDict *oldParent,
        hkDataObjectDict *klass)
{
  signed int FirstIndex; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // r8
  hkDataClassDict *v8; // rax
  hkDataObjectDict *value; // [rsp+40h] [rbp+18h] BYREF

  value = klass;
  if ( oldParent )
  {
    FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                   (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
                   (unsigned __int64)oldParent);
    if ( FirstIndex != -1 )
    {
      m_data = this->m_derivedFromParent.m_valueChain.m_data;
      while ( (hkDataObjectDict *)m_data[FirstIndex].value != klass )
      {
        FirstIndex = m_data[FirstIndex].next;
        if ( FirstIndex == -1 )
          goto LABEL_8;
      }
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
        oldParent,
        FirstIndex);
    }
  }
LABEL_8:
  v8 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))klass->vfptr[4].__vecDelDtor)(klass);
  if ( v8 )
    hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
      (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
      v8,
      &value);
}

// File Line: 3118
// RVA: 0xE45810
void __fastcall hkDataWorldDict::ObjectTracker::retrackRenamedClass(
        hkDataWorldDict::ObjectTracker *this,
        const char *oldName,
        char *newName)
{
  const char *v3; // rbx
  unsigned __int64 v7; // r15
  unsigned __int64 v8; // rdi
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  v3 = 0i64;
  if ( oldName )
    v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
           oldName,
           0i64);
  else
    v7 = 0i64;
  if ( newName )
  {
    v3 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
                         newName,
                         0i64);
    if ( !v3 )
    {
      v3 = hkString::strDup(newName);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_interns.m_map,
        v3,
        (unsigned __int64)v3);
    }
  }
  if ( oldName != v3 )
  {
    v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
           oldName,
           0i64);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
      &this->m_internedClassNames.m_map,
      &result,
      oldName);
    *(_QWORD *)(v8 + 16) = v3;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_internedClassNames.m_map, v3, v8);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(&this->m_classes.m_map, &result, oldName);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_classes.m_map, v3, v7);
}

// File Line: 3135
// RVA: 0xE45900
void __fastcall hkDataWorldDict::ObjectTracker::retractCastedObject(
        hkDataWorldDict::ObjectTracker *this,
        hkDataObjectDict *obj,
        hkDataClassDict *newClass)
{
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *p_m_objectsFromClass; // rdi
  hkDataClassDict *v6; // rsi
  signed int i; // eax
  __int64 v8; // rbx
  hkDataObjectDict *value; // [rsp+48h] [rbp+10h] BYREF

  value = obj;
  p_m_objectsFromClass = &this->m_objectsFromClass;
  v6 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))obj->vfptr[2].__vecDelDtor)(obj);
  for ( i = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)p_m_objectsFromClass,
              (unsigned __int64)v6); v6; i = p_m_objectsFromClass->m_valueChain.m_data[v8].next )
  {
    if ( i == -1 )
      break;
    v8 = i;
    if ( obj == p_m_objectsFromClass->m_valueChain.m_data[i].value )
    {
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
        p_m_objectsFromClass,
        v6,
        i);
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
        p_m_objectsFromClass,
        newClass,
        &value);
      v6 = 0i64;
    }
  }
}

// File Line: 3161
// RVA: 0xE44A30
InternedString *__fastcall hkDataWorldDict::ObjectTracker::intern(
        hkDataWorldDict::ObjectTracker *this,
        InternedString *result,
        char *sin)
{
  hkStringMap<char *,hkContainerHeapAllocator> *p_m_interns; // rbp
  const char *v6; // rdi
  InternedString *v7; // rax

  if ( sin )
  {
    p_m_interns = &this->m_interns;
    v6 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
                         sin,
                         0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(sin);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &p_m_interns->m_map,
        v6,
        (unsigned __int64)v6);
    }
    result->m_cachedString = v6;
    return result;
  }
  else
  {
    v7 = result;
    result->m_cachedString = 0i64;
  }
  return v7;
}

// File Line: 3179
// RVA: 0xE44AC0
InternedStringHandle *__fastcall hkDataWorldDict::ObjectTracker::internClassNameHandle(
        hkDataWorldDict::ObjectTracker *this,
        InternedStringHandle *result,
        char *sin)
{
  __int64 v6; // rbx
  _QWORD **Value; // rax
  const char *v8; // rsi

  result->m_cached.m_pntr = 0i64;
  hkReferencedObject::addReference(&InternedNullRefCounted);
  if ( result->m_cached.m_pntr )
    hkReferencedObject::removeReference(result->m_cached.m_pntr);
  result->m_cached.m_pntr = &InternedNullRefCounted;
  if ( sin )
  {
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_internedClassNames,
           sin,
           0i64);
    if ( !v6 )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 24i64);
      if ( v6 )
      {
        v8 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
                             sin,
                             0i64);
        if ( !v8 )
        {
          v8 = hkString::strDup(sin);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            &this->m_interns.m_map,
            v8,
            (unsigned __int64)v8);
        }
        *(_QWORD *)(v6 + 16) = v8;
        *(_QWORD *)v6 = &`anonymous namespace::InternedStringRefCounted::`vftable;
        *(_DWORD *)(v6 + 8) = 0x1FFFF;
      }
      else
      {
        v6 = 0i64;
      }
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_internedClassNames.m_map,
        *(const char **)(v6 + 16),
        v6);
    }
    hkReferencedObject::addReference((hkReferencedObject *)v6);
    if ( result->m_cached.m_pntr )
      hkReferencedObject::removeReference(result->m_cached.m_pntr);
    result->m_cached.m_pntr = (InternedStringRefCounted *)v6;
  }
  return result;
}

// File Line: 3211
// RVA: 0xE3ED80
void __fastcall hkDataWorldDict::hkDataWorldDict(hkDataWorldDict *this)
{
  _QWORD **Value; // rax
  hkDataWorldDict::ObjectTracker *v3; // rax
  hkDataWorldDict::ObjectTracker *v4; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  hkTypeManager::hkTypeManager(&this->m_typeManager);
  this->m_allocator = (hkMemoryAllocator *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkDataWorldDict::ObjectTracker *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           184i64);
  if ( v3 )
  {
    hkDataWorldDict::ObjectTracker::ObjectTracker(v3, this->m_allocator);
    this->m_tracker = v4;
  }
  else
  {
    this->m_tracker = 0i64;
  }
}

// File Line: 3217
// RVA: 0xE3EE10
void __fastcall hkDataWorldDict::hkDataWorldDict(hkDataWorldDict *this, hkMemoryAllocator *mall)
{
  _QWORD **Value; // rax
  hkDataWorldDict::ObjectTracker *v5; // rax
  hkDataWorldDict::ObjectTracker *v6; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  hkTypeManager::hkTypeManager(&this->m_typeManager);
  this->m_allocator = mall;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataWorldDict::ObjectTracker *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                           Value[11],
                                           184i64);
  if ( v5 )
  {
    hkDataWorldDict::ObjectTracker::ObjectTracker(v5, this->m_allocator);
    this->m_tracker = v6;
  }
  else
  {
    this->m_tracker = 0i64;
  }
}

// File Line: 3223
// RVA: 0xE3EEA0
void __fastcall hkDataWorldDict::~hkDataWorldDict(hkDataWorldDict *this)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rdi
  _QWORD **Value; // rax

  m_tracker = this->m_tracker;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  if ( m_tracker )
  {
    hkDataWorldDict::ObjectTracker::~ObjectTracker(m_tracker);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkDataWorldDict::ObjectTracker *, __int64))(*Value[11] + 16i64))(
      Value[11],
      m_tracker,
      184i64);
  }
  hkTypeManager::~hkTypeManager(&this->m_typeManager);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 3228
// RVA: 0xE3EF10
hkDataObject *__fastcall hkDataWorldDict::getContents(hkDataWorldDict *this, hkDataObject *result)
{
  hkDataObjectDict *m_topLevelObject; // rcx
  hkDataObject *v3; // rax

  m_topLevelObject = this->m_tracker->m_topLevelObject;
  v3 = result;
  result->m_impl = m_topLevelObject;
  if ( m_topLevelObject )
  {
    ++m_topLevelObject->m_externalCount;
    ++m_topLevelObject->m_count;
  }
  return v3;
}

// File Line: 3233
// RVA: 0xE3F1A0
hkDataObjectDict *__fastcall hkDataWorldDict::newObject(
        hkDataWorldDict *this,
        hkDataClass *klass,
        bool createdDuringPatching)
{
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkDataObjectDict *v8; // rbx
  hkDataClassImpl *m_impl; // rdx
  hkDataRefCountedVtbl *vfptr; // rdx
  hkDataWorldDict::ObjectTracker *m_tracker; // rdi
  hkDataClassDict *v12; // rax
  hkDataObjectDict *result; // rax
  hkDataObjectDict *value; // [rsp+30h] [rbp+8h] BYREF

  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = (hkDataObjectDict *)v7;
  if ( v7 )
  {
    m_impl = klass->m_impl;
    *(_QWORD *)(v7 + 8) = 0xFFFFi64;
    *(_QWORD *)v7 = &hkDataObjectDict::`vftable;
    if ( m_impl )
      ++m_impl->m_count;
    *(_QWORD *)(v7 + 16) = m_impl;
    *(_QWORD *)(v7 + 24) = 0i64;
    *(_DWORD *)(v7 + 32) = 0;
    *(_DWORD *)(v7 + 36) = 0x80000000;
    *(_DWORD *)(v7 + 40) = createdDuringPatching;
  }
  else
  {
    v8 = 0i64;
  }
  ++v8->m_count;
  vfptr = v8->vfptr;
  m_tracker = this->m_tracker;
  value = v8;
  v12 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))vfptr[2].__vecDelDtor)(v8);
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
    &m_tracker->m_objectsFromClass,
    v12,
    &value);
  result = v8;
  if ( !m_tracker->m_topLevelObject )
    m_tracker->m_topLevelObject = v8;
  return result;
}

// File Line: 3241
// RVA: 0xE3EF40
hkDataClassDict *__fastcall hkDataWorldDict::newClass(hkDataWorldDict *this, hkDataClass::Cinfo *cinfo)
{
  hkDataWorldDict *v2; // rbx
  _QWORD **Value; // rax
  hkDataClassDict *v5; // rax
  hkDataClassDict *v6; // rax
  hkDataClassDict *v7; // rbp
  const char *parent; // rdx
  unsigned __int64 v9; // rax
  hkDataClassDict *v10; // rbx
  hkDataClassDict *m_pntr; // rcx
  int v13; // r15d
  __int64 v14; // r12
  hkDataClass::Cinfo::Member *m_data; // r13
  char *name; // r14
  const char *v17; // rbx
  hkTypeManager::Type *type; // r14
  hkDataClassDict::MemberInfo *v19; // rax
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *p_m_map; // [rsp+68h] [rbp+10h]

  v2 = this;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataClassDict *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
  if ( v5 )
  {
    hkDataClassDict::hkDataClassDict(v5, v2, cinfo->name, cinfo->version);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  parent = cinfo->parent;
  if ( parent )
  {
    v9 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_tracker->m_classes,
           parent,
           0i64);
    v10 = (hkDataClassDict *)v9;
    if ( v9 )
      ++*(_DWORD *)(v9 + 12);
    m_pntr = v7->m_parent.m_pntr;
    if ( m_pntr )
    {
      if ( m_pntr->m_count-- == 1 )
        m_pntr->vfptr->__vecDelDtor(m_pntr, 1u);
    }
    v7->m_parent.m_pntr = v10;
    v2 = this;
  }
  ++v7->m_count;
  hkDataWorldDict::ObjectTracker::trackClass(v2->m_tracker, v7);
  v13 = 0;
  if ( cinfo->members.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      m_data = cinfo->members.m_data;
      name = (char *)m_data[v14].name;
      if ( name )
      {
        p_m_map = &v2->m_tracker->m_interns.m_map;
        v17 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                              (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)p_m_map,
                              m_data[v14].name,
                              0i64);
        if ( !v17 )
        {
          v17 = hkString::strDup(name);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(p_m_map, v17, (unsigned __int64)v17);
        }
      }
      else
      {
        v17 = 0i64;
      }
      type = m_data[v14].type;
      if ( v7->m_memberInfo.m_size == (v7->m_memberInfo.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v7->m_world->m_allocator, (const void **)&v7->m_memberInfo.m_data, 32);
      v19 = &v7->m_memberInfo.m_data[v7->m_memberInfo.m_size];
      if ( v19 )
      {
        v19->m_name.m_cachedString = v17;
        v19->m_default.i = 0i64;
        v19->m_type = type;
        v19->m_valuePtr = 0i64;
      }
      ++v7->m_memberInfo.m_size;
      v2 = this;
      ++v13;
      ++v14;
    }
    while ( v13 < cinfo->members.m_size );
  }
  hkTypeManager::addClass(&v2->m_typeManager, cinfo->name);
  return v7;
}

// File Line: 3269
// RVA: 0xE3F100
hkDataArrayImpl *__fastcall hkDataWorldDict::newArray(
        hkDataWorldDict *this,
        hkDataObject *obj,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataClass_MemberInfo *minfo)
{
  hkTypeManager::Type *m_type; // rbx
  hkDataWorldDict *v7; // rdi
  int TupleSize; // eax
  int v9; // r8d
  hkDataArrayImpl *v10; // rax
  hkDataObjectImpl *m_impl; // rcx
  hkDataArrayImpl *v12; // rbx

  m_type = minfo->m_type;
  v7 = this;
  if ( m_type->m_subType == SUB_TYPE_TUPLE )
  {
    TupleSize = hkTypeManager::Type::getTupleSize(minfo->m_type);
    this = v7;
    v9 = TupleSize;
  }
  else
  {
    v9 = 0;
  }
  v10 = hkDataArrayDict_create(this, m_type->m_parent, v9);
  m_impl = obj->m_impl;
  v12 = v10;
  if ( v10 )
  {
    ++v10->m_externalCount;
    ++v10->m_count;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))m_impl->vfptr[22].__vecDelDtor)(
    m_impl,
    handle,
    v10);
  if ( v12 )
  {
    --v12->m_externalCount;
    if ( v12->m_count-- == 1 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  return v12;
}

// File Line: 3292
// RVA: 0xE3F270
hkEnum<enum hkDataWorld::DataWorldType,int> *__fastcall hkDataWorldDict::getType(
        hkDataWorldDict *this,
        hkEnum<enum hkDataWorld::DataWorldType,int> *result)
{
  result->m_storage = 1;
  return result;
}

// File Line: 3298
// RVA: 0xE3F280
void __fastcall hkDataWorldDict::findAllClasses(
        hkDataWorldDict *this,
        hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  hkDataWorldDict::ObjectTracker::findTrackedClasses(this->m_tracker, classesOut);
}

// File Line: 3303
// RVA: 0xE3F2B0
hkDataClassDict *__fastcall hkDataWorldDict::wrapClass(hkDataWorldDict *this, hkClass *klass)
{
  hkClass *v3; // rbp
  _QWORD **Value; // rax
  hkDataClassDict *v5; // rdi
  int DescribedVersion; // ebx
  const char *Name; // rax
  hkDataClassDict *v8; // rax
  hkDataClassDict *v9; // rdi
  hkClass *Parent; // rax
  const char *v11; // rax
  hkDataClassImpl *v12; // rbx
  hkClass *v13; // rax
  hkDataClassDict *m_pntr; // rcx
  int v16; // ebx
  hkArrayBase<hkDataClassDict::MemberInfo> *p_m_memberInfo; // rsi
  hkClassMember *DeclaredMember; // rbp
  hkDataWorldDict *v19; // rax
  hkClass *Class; // rax
  hkClass *v21; // rbx
  hkVariant *Attribute; // rax
  hkClassMemberAccessor *v23; // rcx
  hkVariant *v24; // rax
  hkClassMember::Type m_storage; // ebx
  hkClassMember::Type v26; // edi
  int count; // eax
  char *m_name; // rdi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *m_tracker; // rbp
  const char *v30; // rbx
  const char **p_m_cachedString; // rax
  hkDataClassDict *v33; // [rsp+30h] [rbp-58h]
  hkClassMemberAccessor v34; // [rsp+38h] [rbp-50h] BYREF
  hkClassMemberAccessor v35; // [rsp+48h] [rbp-40h] BYREF
  int v38; // [rsp+A0h] [rbp+18h]
  hkTypeManager::Type *typeName; // [rsp+A8h] [rbp+20h]
  char *typeNamea; // [rsp+A8h] [rbp+20h]

  v3 = klass;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataClassDict *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 96i64);
  if ( v5 )
  {
    DescribedVersion = hkClass::getDescribedVersion(v3);
    Name = hkClass::getName(v3);
    hkDataClassDict::hkDataClassDict(v5, this, Name, DescribedVersion);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v33 = v9;
  if ( hkClass::getParent(v3) )
  {
    Parent = hkClass::getParent(v3);
    v11 = hkClass::getName(Parent);
    if ( !v11
      || (v12 = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                     (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_tracker->m_classes,
                                     v11,
                                     0i64)) == 0i64 )
    {
      v13 = hkClass::getParent(v3);
      v12 = hkDataWorldDict::wrapClass(this, v13);
    }
    if ( v12 )
      ++v12->m_count;
    m_pntr = v9->m_parent.m_pntr;
    if ( m_pntr )
    {
      if ( m_pntr->m_count-- == 1 )
        m_pntr->vfptr->__vecDelDtor(m_pntr, 1u);
    }
    v9->m_parent.m_pntr = (hkDataClassDict *)v12;
  }
  ++v9->m_count;
  hkDataWorldDict::ObjectTracker::trackClass(this->m_tracker, v9);
  v16 = 0;
  v38 = 0;
  if ( (int)hkClass::getNumDeclaredMembers(v3) > 0 )
  {
    p_m_memberInfo = &v9->m_memberInfo;
    while ( 1 )
    {
      DeclaredMember = hkClass::getDeclaredMember(v3, v16);
      v19 = this;
      typeName = this->m_typeManager.m_builtInTypes[1];
      if ( (DeclaredMember->m_flags.m_storage & 0x400) == 0 )
        break;
LABEL_24:
      m_name = (char *)DeclaredMember->m_name;
      m_tracker = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v19->m_tracker;
      if ( m_name )
      {
        v30 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                              m_tracker + 5,
                              m_name,
                              0i64);
        if ( !v30 )
        {
          v30 = hkString::strDup(m_name);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&m_tracker[5],
            v30,
            (unsigned __int64)v30);
        }
      }
      else
      {
        v30 = 0i64;
      }
      v9 = v33;
      if ( p_m_memberInfo->m_size == (p_m_memberInfo->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v33->m_world->m_allocator, (const void **)&p_m_memberInfo->m_data, 32);
      p_m_cachedString = &p_m_memberInfo->m_data[p_m_memberInfo->m_size].m_name.m_cachedString;
      if ( p_m_cachedString )
      {
        *p_m_cachedString = v30;
        p_m_cachedString[1] = 0i64;
        p_m_cachedString[2] = (const char *)typeName;
        p_m_cachedString[3] = 0i64;
      }
      v3 = klass;
      ++p_m_memberInfo->m_size;
      v16 = ++v38;
      if ( v38 >= (int)hkClass::getNumDeclaredMembers(klass) )
        return v9;
    }
    Class = hkClassMember::getClass(DeclaredMember);
    typeNamea = 0i64;
    v21 = Class;
    if ( Class )
    {
      typeNamea = (char *)hkClass::getName(Class);
      Attribute = hkClassMember::getAttribute(DeclaredMember, s_hkDataObjectTypeAttributeID);
      if ( Attribute )
      {
        hkClassMemberAccessor::hkClassMemberAccessor(&v34, Attribute, "typeName");
        v23 = &v34;
LABEL_22:
        typeNamea = *hkClassMemberAccessor::asCstring(v23, 0);
        goto LABEL_23;
      }
      v24 = hkClass::getAttribute(v21, s_hkDataObjectTypeAttributeID);
      if ( v24 )
      {
        hkClassMemberAccessor::hkClassMemberAccessor(&v35, v24, "typeName");
        v23 = &v35;
        goto LABEL_22;
      }
    }
LABEL_23:
    m_storage = (unsigned __int8)DeclaredMember->m_subtype.m_storage;
    v26 = (unsigned __int8)DeclaredMember->m_type.m_storage;
    count = hkClassMember::getCstyleArraySize(DeclaredMember);
    typeName = hkDataObjectUtil::getTypeFromMemberTypeClassName(&this->m_typeManager, v26, m_storage, typeNamea, count);
    v19 = this;
    goto LABEL_24;
  }
  return v9;
}

// File Line: 3356
// RVA: 0xE3F5B0
hkDataClassImpl *__fastcall hkDataWorldDict::copyClassFromWorld(
        hkDataWorldDict *this,
        const char *name,
        hkDataWorld *worldFrom)
{
  hkDataClassImpl *v6; // rax
  hkDataClassImpl *v7; // rax
  __int64 v8; // r14
  __int64 v9; // rax
  __int64 v10; // rsi
  __int32 v11; // eax
  __int32 v12; // ecx
  __int64 v13; // rbx
  hkDataClass_MemberInfo *v14; // r8
  int v15; // eax
  __int64 v16; // rdx
  hkTypeManager::Type **p_m_type; // rax
  int m_size; // ecx
  int v19; // r15d
  hkTypeManager *p_m_typeManager; // rcx
  hkDataClass_MemberInfo *m_data; // r12
  hkTypeManager::Type *v22; // rsi
  hkTypeManager::Type *Terminal; // r13
  hkBaseObjectVtbl *vfptr; // rbx
  const char *TypeName; // rax
  hkBaseObjectVtbl *v26; // rbx
  const char *v27; // rax
  __int64 v28; // [rsp+30h] [rbp-29h] BYREF
  __int64 v29; // [rsp+38h] [rbp-21h]
  hkArrayBase<hkDataClass_MemberInfo> minfos; // [rsp+40h] [rbp-19h] BYREF
  __int64 v31; // [rsp+50h] [rbp-9h] BYREF
  int v32; // [rsp+58h] [rbp-1h]
  __int64 v33; // [rsp+60h] [rbp+7h]
  void *array; // [rsp+68h] [rbp+Fh] BYREF
  int v35; // [rsp+70h] [rbp+17h]
  int v36; // [rsp+74h] [rbp+1Bh]
  hkResult result; // [rsp+C0h] [rbp+67h] BYREF
  hkDataWorld *v38; // [rsp+D0h] [rbp+77h]
  hkDataClass v39; // [rsp+D8h] [rbp+7Fh] BYREF

  v38 = worldFrom;
  v6 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldDict *))this->vfptr[4].__first_virtual_table_function__)(this);
  if ( v6 )
    return v6;
  v7 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))worldFrom->vfptr[4].__first_virtual_table_function__)(
                            worldFrom,
                            name);
  v8 = 0i64;
  array = 0i64;
  v35 = 0;
  v36 = 0x80000000;
  v39.m_impl = v7;
  v31 = ((__int64 (__fastcall *)(hkDataClassImpl *))v7->vfptr[2].__vecDelDtor)(v7);
  v32 = ((__int64 (__fastcall *)(hkDataClassImpl *))v39.m_impl->vfptr[3].__vecDelDtor)(v39.m_impl);
  v9 = ((__int64 (__fastcall *)(hkDataClassImpl *))v39.m_impl->vfptr[4].__vecDelDtor)(v39.m_impl);
  if ( !v9 )
  {
    v33 = 0i64;
LABEL_5:
    v10 = ((__int64 (__fastcall *)(hkDataWorldDict *, __int64 *))this->vfptr[1].__first_virtual_table_function__)(
            this,
            &v31);
    v29 = v10;
    v11 = ((__int64 (__fastcall *)(hkDataClassImpl *))v39.m_impl->vfptr[6].__vecDelDtor)(v39.m_impl);
    minfos.m_data = 0i64;
    minfos.m_size = 0;
    v12 = v11;
    minfos.m_capacityAndFlags = 0x80000000;
    v13 = v11;
    if ( v11 )
    {
      result.m_enum = 32 * v11;
      v14 = (hkDataClass_MemberInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        &hkContainerTempAllocator::s_alloc,
                                        &result);
      v12 = result.m_enum / 32;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = 0x80000000;
    minfos.m_data = v14;
    if ( v12 )
      v15 = v12;
    minfos.m_size = v13;
    v16 = v13;
    minfos.m_capacityAndFlags = v15;
    if ( (int)v13 > 0 )
    {
      p_m_type = &v14->m_type;
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
        --v16;
      }
      while ( v16 );
    }
    hkDataClass::getAllDeclaredMemberInfo(&v39, &minfos);
    m_size = minfos.m_size;
    if ( (v36 & 0x3FFFFFFF) < minfos.m_size )
    {
      if ( minfos.m_size < 2 * (v36 & 0x3FFFFFFF) )
        m_size = 2 * (v36 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 24);
      m_size = minfos.m_size;
    }
    v28 = v10;
    v19 = 0;
    if ( m_size > 0 )
    {
      p_m_typeManager = &this->m_typeManager;
      do
      {
        m_data = minfos.m_data;
        v22 = hkTypeManager::copyType(p_m_typeManager, minfos.m_data[v8].m_type);
        Terminal = hkTypeManager::Type::findTerminal(v22);
        if ( Terminal->m_subType == SUB_TYPE_CLASS )
        {
          vfptr = v38->vfptr;
          TypeName = hkTypeManager::Type::getTypeName(v22);
          if ( ((__int64 (__fastcall *)(hkDataWorld *, const char *))vfptr[4].__first_virtual_table_function__)(
                 v38,
                 TypeName) )
          {
            v26 = this->vfptr;
            v27 = hkTypeManager::Type::getTypeName(Terminal);
            ((void (__fastcall *)(hkDataWorldDict *, const char *, hkDataWorld *))v26[11].__first_virtual_table_function__)(
              this,
              v27,
              v38);
          }
        }
        ((void (__fastcall *)(hkDataWorldDict *, __int64 *, const char *, hkTypeManager::Type *, _QWORD))this->vfptr[8].__vecDelDtor)(
          this,
          &v28,
          m_data[v8].m_name,
          v22,
          0i64);
        ++v19;
        ++v8;
        p_m_typeManager = &this->m_typeManager;
      }
      while ( v19 < minfos.m_size );
      v10 = v29;
    }
    minfos.m_size = 0;
    if ( minfos.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        minfos.m_data,
        32 * minfos.m_capacityAndFlags);
    minfos.m_data = 0i64;
    minfos.m_capacityAndFlags = 0x80000000;
    goto LABEL_29;
  }
  v33 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  v10 = ((__int64 (__fastcall *)(hkDataWorldDict *, __int64))this->vfptr[4].__first_virtual_table_function__)(this, v31);
  if ( !v10 )
    goto LABEL_5;
LABEL_29:
  v35 = 0;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 24 * (v36 & 0x3FFFFFFF));
  return (hkDataClassImpl *)v10;
}

// File Line: 3406
// RVA: 0xE3F290
hkDataClassImpl *__fastcall hkDataWorldDict::findClass(hkDataWorldDict *this, const char *name)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rcx

  m_tracker = this->m_tracker;
  if ( name )
    return (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_classes,
                                name,
                                0i64);
  else
    return 0i64;
}

// File Line: 3411
// RVA: 0xE40220
hkDataObject *__fastcall hkDataWorldDict::findObject(
        hkDataWorldDict *this,
        hkDataObject *result,
        hkDataObject_Handle *handle)
{
  _WORD *p0; // rax

  p0 = handle->p0;
  result->m_impl = (hkDataObjectImpl *)handle->p0;
  if ( p0 )
  {
    ++p0[5];
    ++*((_DWORD *)p0 + 3);
  }
  return result;
}

// File Line: 3416
// RVA: 0xE3F8B0
void __fastcall hkDataWorldDict::renameClass(hkDataWorldDict *this, hkDataClass *klass, const char *newName)
{
  const char *v5; // rax
  hkDataWorldDict::ObjectTracker *m_tracker; // r14
  char *v7; // rdi
  const char *v8; // rbx

  v5 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
  m_tracker = this->m_tracker;
  v7 = (char *)v5;
  if ( v5 )
  {
    v8 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         v5,
                         0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(v7);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  if ( hkTypeManager::getClass(&this->m_typeManager, v8) )
    hkTypeManager::renameClass(&this->m_typeManager, v8, newName);
  hkDataWorldDict::ObjectTracker::retrackRenamedClass(this->m_tracker, v8, newName);
}

// File Line: 3432
// RVA: 0xE3F970
void __fastcall hkDataWorldDict::removeClass(hkDataWorldDict *this, hkDataClass *klass)
{
  const char *v4; // rax
  hkTypeManager::Type *Class; // rax
  hkDataClassDict *m_impl; // rbx

  v4 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
  Class = hkTypeManager::getClass(&this->m_typeManager, v4);
  if ( Class )
    hkTypeManager::removeClass(&this->m_typeManager, Class);
  m_impl = (hkDataClassDict *)klass->m_impl;
  klass->m_impl = 0i64;
  hkDataWorldDict::ObjectTracker::untrackClass(this->m_tracker, m_impl);
  if ( m_impl->m_count-- == 1 )
    m_impl->vfptr->__vecDelDtor(m_impl, 1u);
}

// File Line: 3448
// RVA: 0xE3F9F0
void __fastcall hkDataWorldDict::setClassVersion(hkDataWorldDict *this, hkDataClass *klass, int newVersion)
{
  LODWORD(klass->m_impl[2].vfptr) = newVersion;
}

// File Line: 3454
// RVA: 0xE3FA00
void __fastcall hkDataWorldDict::setClassParent(hkDataWorldDict *this, hkDataClass *klass, hkDataClass *parent)
{
  __int64 v6; // rax
  hkDataClassImpl *m_impl; // rbx
  hkDataClassImpl *v8; // rdi
  hkDataClassDict *v9; // r14
  __int64 v10; // rcx

  v6 = ((__int64 (*)(void))klass->m_impl->vfptr[4].__vecDelDtor)();
  m_impl = parent->m_impl;
  v8 = klass->m_impl;
  v9 = (hkDataClassDict *)v6;
  if ( m_impl )
    ++m_impl->m_count;
  v10 = *(_QWORD *)&v8[2].m_memSize;
  if ( v10 )
  {
    if ( (*(_DWORD *)(v10 + 12))-- == 1 )
      (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
  }
  *(_QWORD *)&v8[2].m_memSize = m_impl;
  hkDataWorldDict::ObjectTracker::retrackDerivedClass(this->m_tracker, v9, (hkDataClassDict *)klass->m_impl);
}

// File Line: 3464
// RVA: 0xE3FA90
void __fastcall hkDataWorldDict::addClassMember(
        hkDataWorldDict *this,
        hkDataClass *klass,
        char *name,
        hkTypeManager::Type *type,
        const void *valuePtr)
{
  hkDataClassDict *m_impl; // rdi
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v9; // rbx
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_impl = (hkDataClassDict *)klass->m_impl;
  m_tracker = this->m_tracker;
  if ( name )
  {
    v9 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         name,
                         0i64);
    if ( !v9 )
    {
      v9 = hkString::strDup(name);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v9,
        (unsigned __int64)v9);
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( m_impl->vfptr[8].__vecDelDtor(m_impl, (unsigned int)name) != (void *)-1i64 )
    hkDataClassDict::removeMember(m_impl, &result, (InternedString)v9);
  hkDataClassDict::addMember(m_impl, (InternedString)v9, type, valuePtr);
}

// File Line: 3479
// RVA: 0xE40160
void __fastcall hkDataWorldDict::setClassMemberDefault(
        hkDataWorldDict *this,
        hkDataClass *klass,
        char *name,
        void *(__fastcall *valuePtr)(hkDataRefCounted *this, unsigned int))
{
  hkDataClassImpl *m_impl; // rsi
  hkDataWorldDict::ObjectTracker *m_tracker; // rbp
  const char *v8; // rbx
  int v9; // edx
  __int64 v10; // rcx
  hkDataRefCountedVtbl *v11; // rax

  m_impl = klass->m_impl;
  m_tracker = this->m_tracker;
  if ( name )
  {
    v8 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         name,
                         0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(name);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v9 = *(_DWORD *)&m_impl[4].m_memSize - 1;
  v10 = v9;
  if ( v9 < 0 )
  {
LABEL_9:
    v9 = -1;
  }
  else
  {
    v11 = &m_impl[4].vfptr[4 * v9];
    while ( (const char *)v11->__vecDelDtor != v8 )
    {
      --v9;
      v11 -= 4;
      if ( --v10 < 0 )
        goto LABEL_9;
    }
  }
  m_impl[4].vfptr[4 * v9 + 3].__vecDelDtor = valuePtr;
}

// File Line: 3489
// RVA: 0xE3FB40
void __fastcall hkDataWorldDict::renameClassMember(
        hkDataWorldDict *this,
        hkDataClass *klass,
        char *oldName,
        char *newName)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // r14
  hkDataWorldDict *v8; // r12
  const char *v9; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v10; // r14
  const char *v11; // rdi
  hkDataClassImpl *m_impl; // rcx
  const char *v13; // rax
  hkDataWorldDict::ObjectTracker *v14; // r13
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r12
  int FirstIndex; // eax
  int m_size; // ecx
  __int64 v19; // rsi
  hkDataObjectImpl *value; // r15
  int next; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v23; // rsi
  const char *v24; // rax
  int v25; // r8d
  __int64 v26; // r9
  hkDataObjectImpl *v27; // rcx
  __int64 v28; // rax
  __int64 vfptr_low; // rdx
  const char **v30; // r10
  const char **v31; // rcx
  hkDataWorldDict::ObjectTracker *v32; // rcx
  __int64 v33; // r9
  int v34; // r10d
  int v35; // r8d
  __int64 v36; // rcx
  hkDataArrayImpl *v37; // rax
  __int64 v38; // rdx
  const char **vfptr; // rax
  int v40; // edx
  __int64 v41; // rcx
  hkDataClassDict::MemberInfo *v42; // rax
  hkArray<hkDataObjectImpl *,hkContainerTempAllocator> array; // [rsp+30h] [rbp-50h] BYREF
  hkArray<hkDataArrayImpl *,hkContainerTempAllocator> arraysOut; // [rsp+40h] [rbp-40h] BYREF
  hkDataClassDict *c; // [rsp+98h] [rbp+18h]

  m_tracker = this->m_tracker;
  c = (hkDataClassDict *)klass->m_impl;
  v8 = this;
  if ( oldName )
  {
    v9 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         oldName,
                         0i64);
    if ( !v9 )
    {
      v9 = hkString::strDup(oldName);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v9,
        (unsigned __int64)v9);
    }
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v8->m_tracker;
  if ( newName )
  {
    v11 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                          v10 + 5,
                          newName,
                          0i64);
    if ( !v11 )
    {
      v11 = hkString::strDup(newName);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v10[5],
        v11,
        (unsigned __int64)v11);
    }
  }
  else
  {
    v11 = 0i64;
  }
  m_impl = klass->m_impl;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v13 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))m_impl->vfptr[2].__vecDelDtor)(m_impl);
  v14 = v8->m_tracker;
  array.m_size = 0;
  if ( v13 )
  {
    v15 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v14->m_classes,
            v13,
            0i64);
    v16 = v15;
    if ( v15 )
    {
      FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                     (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v14->m_objectsFromClass,
                     v15);
      if ( FirstIndex != -1 )
      {
        m_size = array.m_size;
        do
        {
          v19 = FirstIndex;
          value = v14->m_objectsFromClass.m_valueChain.m_data[FirstIndex].value;
          if ( m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 8);
            m_size = array.m_size;
          }
          array.m_data[m_size] = value;
          m_size = ++array.m_size;
          FirstIndex = v14->m_objectsFromClass.m_valueChain.m_data[v19].next;
        }
        while ( FirstIndex != -1 );
      }
      next = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
               (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v14->m_derivedFromParent,
               v16);
      if ( next != -1 )
      {
        m_data = v14->m_derivedFromParent.m_valueChain.m_data;
        do
        {
          v23 = next;
          v24 = (const char *)((__int64 (__fastcall *)(hkDataClassDict *))m_data[next].value->vfptr[2].__vecDelDtor)(m_data[next].value);
          hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(v14, v24, 1u, 0, &array);
          m_data = v14->m_derivedFromParent.m_valueChain.m_data;
          next = m_data[v23].next;
        }
        while ( next != -1 );
      }
    }
    v8 = this;
  }
  v25 = 0;
  if ( array.m_size > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = array.m_data[v26];
      v28 = 0i64;
      vfptr_low = SLODWORD(v27[2].vfptr);
      if ( vfptr_low > 0 )
      {
        v30 = *(const char ***)&v27[1].m_memSize;
        v31 = v30;
        while ( *v31 != v9 )
        {
          ++v28;
          v31 += 2;
          if ( v28 >= vfptr_low )
            goto LABEL_29;
        }
        v30[2 * v28] = v11;
      }
LABEL_29:
      ++v25;
      ++v26;
    }
    while ( v25 < array.m_size );
  }
  v32 = v8->m_tracker;
  arraysOut.m_data = 0i64;
  arraysOut.m_size = 0;
  arraysOut.m_capacityAndFlags = 0x80000000;
  hkDataWorldDict::ObjectTracker::getTrackedStructArrays(v32, c, 1u, &arraysOut);
  v34 = arraysOut.m_size;
  v35 = 0;
  if ( arraysOut.m_size > 0 )
  {
    v33 = 0i64;
    do
    {
      v36 = 0i64;
      v37 = arraysOut.m_data[v33];
      v38 = *(int *)&v37[1].m_memSize;
      if ( v38 > 0 )
      {
        vfptr = (const char **)v37[1].vfptr;
        while ( *vfptr != v9 )
        {
          ++v36;
          vfptr += 2;
          if ( v36 >= v38 )
            goto LABEL_38;
        }
        *vfptr = v11;
        v34 = arraysOut.m_size;
      }
LABEL_38:
      ++v35;
      ++v33;
    }
    while ( v35 < v34 );
  }
  v40 = c->m_memberInfo.m_size - 1;
  v41 = v40;
  if ( v40 < 0 )
  {
LABEL_43:
    v40 = -1;
  }
  else
  {
    v42 = &c->m_memberInfo.m_data[v40];
    while ( v42->m_name.m_cachedString != v9 )
    {
      --v40;
      --v42;
      if ( --v41 < 0 )
        goto LABEL_43;
    }
  }
  c->m_memberInfo.m_data[v40].m_name.m_cachedString = v11;
  arraysOut.m_size = 0;
  if ( arraysOut.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkDataArrayImpl **, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      arraysOut.m_data,
      (unsigned int)(8 * arraysOut.m_capacityAndFlags),
      v33 * 8);
  arraysOut.m_data = 0i64;
  array.m_size = 0;
  arraysOut.m_capacityAndFlags = 0x80000000;
  if ( array.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkDataObjectImpl **, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      (unsigned int)(8 * array.m_capacityAndFlags),
      v33 * 8);
}

// File Line: 3512
// RVA: 0xE3FEC0
void __fastcall hkDataWorldDict::removeClassMember(hkDataWorldDict *this, hkDataClass *klass, char *name)
{
  hkDataClassDict *m_impl; // r12
  hkDataWorldDict::ObjectTracker *m_tracker; // rsi
  const char *v8; // rbx
  hkDataClassImpl *v9; // rcx
  const char *v10; // rax
  hkDataWorldDict::ObjectTracker *v11; // r15
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r12
  int FirstIndex; // eax
  int m_size; // ecx
  __int64 v16; // rdi
  hkDataObjectImpl *value; // r14
  int next; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *m_data; // rcx
  __int64 v20; // rdi
  const char *v21; // rax
  int v22; // esi
  __int64 v23; // rdi
  hkDataWorldDict::ObjectTracker *v24; // rcx
  int v25; // esi
  __int64 v26; // rdi
  hkArray<hkDataObjectImpl *,hkContainerTempAllocator> array; // [rsp+30h] [rbp-20h] BYREF
  hkArray<hkDataArrayImpl *,hkContainerTempAllocator> arraysOut; // [rsp+40h] [rbp-10h] BYREF
  hkDataClassImpl *result; // [rsp+80h] [rbp+30h] BYREF

  m_impl = (hkDataClassDict *)klass->m_impl;
  m_tracker = this->m_tracker;
  result = klass->m_impl;
  if ( name )
  {
    v8 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&m_tracker->m_interns,
                         name,
                         0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(name);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &m_tracker->m_interns.m_map,
        v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v9 = klass->m_impl;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  v10 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))v9->vfptr[2].__vecDelDtor)(v9);
  v11 = this->m_tracker;
  array.m_size = 0;
  if ( v10 )
  {
    v12 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v11->m_classes,
            v10,
            0i64);
    v13 = v12;
    if ( v12 )
    {
      FirstIndex = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                     (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v11->m_objectsFromClass,
                     v12);
      if ( FirstIndex != -1 )
      {
        m_size = array.m_size;
        do
        {
          v16 = FirstIndex;
          value = v11->m_objectsFromClass.m_valueChain.m_data[FirstIndex].value;
          if ( m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&array.m_data, 8);
            m_size = array.m_size;
          }
          array.m_data[m_size] = value;
          m_size = ++array.m_size;
          FirstIndex = v11->m_objectsFromClass.m_valueChain.m_data[v16].next;
        }
        while ( FirstIndex != -1 );
      }
      next = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
               (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v11->m_derivedFromParent,
               v13);
      if ( next != -1 )
      {
        m_data = v11->m_derivedFromParent.m_valueChain.m_data;
        do
        {
          v20 = next;
          v21 = (const char *)((__int64 (__fastcall *)(hkDataClassDict *))m_data[next].value->vfptr[2].__vecDelDtor)(m_data[next].value);
          hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(v11, v21, 1u, 0, &array);
          m_data = v11->m_derivedFromParent.m_valueChain.m_data;
          next = m_data[v20].next;
        }
        while ( next != -1 );
      }
    }
    m_impl = (hkDataClassDict *)result;
  }
  v22 = 0;
  if ( array.m_size > 0 )
  {
    v23 = 0i64;
    do
    {
      hkDataObjectDict::removeMember((hkDataObjectDict *)array.m_data[v23], (InternedString)v8);
      ++v22;
      ++v23;
    }
    while ( v22 < array.m_size );
  }
  v24 = this->m_tracker;
  arraysOut.m_data = 0i64;
  arraysOut.m_size = 0;
  arraysOut.m_capacityAndFlags = 0x80000000;
  hkDataWorldDict::ObjectTracker::getTrackedStructArrays(v24, m_impl, 1u, &arraysOut);
  v25 = 0;
  if ( arraysOut.m_size > 0 )
  {
    v26 = 0i64;
    do
    {
      StructArrayImplementation::removeMember((StructArrayImplementation *)arraysOut.m_data[v26], (InternedString)v8);
      ++v25;
      ++v26;
    }
    while ( v25 < arraysOut.m_size );
  }
  hkDataClassDict::removeMember(m_impl, (hkResult *)&result, (InternedString)v8);
  arraysOut.m_size = 0;
  if ( arraysOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      arraysOut.m_data,
      8 * arraysOut.m_capacityAndFlags);
  arraysOut.m_data = 0i64;
  arraysOut.m_capacityAndFlags = 0x80000000;
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      array.m_data,
      8 * array.m_capacityAndFlags);
}

// File Line: 3535
// RVA: 0xE40240
void __fastcall hkDataWorldDict::castObject(hkDataWorldDict *this, hkDataObject *obj, hkDataClass *castClass)
{
  hkDataWorldDict::ObjectTracker::retractCastedObject(
    this->m_tracker,
    (hkDataObjectDict *)obj->m_impl,
    (hkDataClassDict *)castClass->m_impl);
}

// File Line: 3544
// RVA: 0xE40290
void __fastcall hkDataWorldDict::findObjectsByExactClass(
        hkDataWorldDict *this,
        const char *className,
        hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rcx

  m_tracker = this->m_tracker;
  objectsOut->m_size = 0;
  hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(m_tracker, className, 0, 1u, objectsOut);
}

// File Line: 3549
// RVA: 0xE40260
void __fastcall hkDataWorldDict::findObjectsByBaseClass(
        hkDataWorldDict *this,
        const char *className,
        hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *m_tracker; // rcx

  m_tracker = this->m_tracker;
  objectsOut->m_size = 0;
  hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(m_tracker, className, 1u, 1u, objectsOut);
}

