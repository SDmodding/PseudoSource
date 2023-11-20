// File Line: 86
// RVA: 0x15D89E0
__int64 anonymous_namespace_::_dynamic_initializer_for__InternedNullRefCounted__()
{
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__InternedNullRefCounted__);
}

// File Line: 115
// RVA: 0xE43B00
void __fastcall `anonymous namespace::Union::clearArray(Union *this, hkTypeManager::Type *typeIn, Union *u, int n, unsigned int destroyStructs)
{
  int v5; // er15
  hkTypeManager::Type *v6; // r14
  __int64 v7; // rbp
  __int64 v8; // rbx
  __int64 v9; // rcx
  bool v10; // zf
  __int64 v11; // rsi
  _DWORD *v12; // rbx
  __int64 v13; // rbx
  __int64 v14; // rcx

  v5 = n;
  v6 = typeIn;
  if ( (unsigned int)(LODWORD(this->i) - 8) <= 1 )
  {
    v14 = *(_QWORD *)&typeIn->m_subType;
    if ( *(_QWORD *)&typeIn->m_subType )
    {
      v10 = (*(_DWORD *)(v14 + 12))-- == 1;
      if ( v10 )
        (**(void (__fastcall ***)(__int64, signed __int64, Union *))v14)(v14, 1i64, u);
    }
    *(_QWORD *)&v6->m_subType = 0i64;
  }
  else
  {
    v7 = (signed int)u;
    switch ( LODWORD(this->i) )
    {
      case 5:
        v13 = 0i64;
        if ( (signed int)u > 0 )
        {
          do
          {
            hkString::strFree(*((char **)&v6->m_subType + v13));
            *((_QWORD *)&v6->m_subType + v13++) = 0i64;
          }
          while ( v13 < v7 );
        }
        break;
      case 6:
        v11 = 0i64;
        if ( (signed int)u > 0 )
        {
          do
          {
            v12 = (_DWORD *)*((_QWORD *)&v6->m_subType + v11);
            *((_QWORD *)&v6->m_subType + v11) = 0i64;
            if ( v12 )
            {
              if ( v5 )
                (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v12 + 224i64))(v12);
              v10 = v12[3]-- == 1;
              if ( v10 )
                (**(void (__fastcall ***)(_DWORD *, signed __int64))v12)(v12, 1i64);
            }
            ++v11;
          }
          while ( v11 < v7 );
        }
        break;
      case 7:
        v8 = 0i64;
        if ( (signed int)u > 0 )
        {
          do
          {
            v9 = *((_QWORD *)&v6->m_subType + v8);
            *((_QWORD *)&v6->m_subType + v8) = 0i64;
            if ( v9 )
            {
              v10 = (*(_DWORD *)(v9 + 12))-- == 1;
              if ( v10 )
                (**(void (__fastcall ***)(__int64, signed __int64))v9)(v9, 1i64);
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
void __fastcall hkDataClassDict::hkDataClassDict(hkDataClassDict *this, hkDataWorldDict *root, const char *name, int version)
{
  hkDataClassDict *v4; // rdi
  int v5; // ebx

  v4 = this;
  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  this->m_world = root;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataClassDict::`vftable;
  v5 = version;
  hkDataWorldDict::ObjectTracker::internClassNameHandle(root->m_tracker, &this->m_name, name);
  v4->m_version = v5;
  v4->m_parent.m_pntr = 0i64;
  v4->m_enums.m_data = 0i64;
  v4->m_enums.m_size = 0;
  v4->m_enums.m_capacityAndFlags = 2147483648;
  v4->m_memberInfo.m_data = 0i64;
  v4->m_memberInfo.m_size = 0;
  v4->m_memberInfo.m_capacityAndFlags = 2147483648;
  v4->m_hiddenMemberInfo.m_data = 0i64;
  v4->m_hiddenMemberInfo.m_size = 0;
  v4->m_hiddenMemberInfo.m_capacityAndFlags = 2147483648;
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
  hkBool *v4; // r15
  hkDataClassDict *v5; // rbp
  unsigned __int64 v6; // rax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v7; // r14
  const char *v8; // rsi
  char *v9; // rbx

  v3 = k;
  v4 = result;
  v5 = this;
  if ( k )
  {
    while ( 1 )
    {
      v6 = ((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[2].__vecDelDtor)(v3);
      v7 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v5->m_world->m_tracker;
      v8 = (const char *)v6;
      if ( v6 )
      {
        v9 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                       v7 + 5,
                       v6,
                       0i64);
        if ( !v9 )
        {
          v9 = hkString::strDup(v8);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v7[5],
            (unsigned __int64)v9,
            (unsigned __int64)v9);
        }
      }
      else
      {
        v9 = 0i64;
      }
      if ( v9 == v5->m_name.m_cached.m_pntr->m_cachedString )
        break;
      v3 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[4].__vecDelDtor)(v3);
      if ( !v3 )
        goto LABEL_8;
    }
    v4->m_bool = 1;
  }
  else
  {
LABEL_8:
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 482
// RVA: 0xE44250
signed __int64 __fastcall hkDataClassDict::getDeclaredMemberIndexByName(hkDataClassDict *this, const char *nameIn)
{
  unsigned int v2; // edi
  hkDataWorldDict::ObjectTracker *v3; // r14
  const char *v4; // rbp
  hkDataClassDict *v5; // rsi
  char *v6; // rbx
  __int64 v7; // rdx
  __int64 v8; // rcx
  hkDataClassDict::MemberInfo *v9; // rax

  v2 = 0;
  v3 = this->m_world->m_tracker;
  v4 = nameIn;
  v5 = this;
  if ( nameIn )
  {
    v6 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns,
                   (unsigned __int64)nameIn,
                   0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(v4);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v3->m_interns.m_map,
        (unsigned __int64)v6,
        (unsigned __int64)v6);
    }
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v5->m_memberInfo.m_size;
  v8 = 0i64;
  if ( v7 <= 0 )
    return 0xFFFFFFFFi64;
  v9 = v5->m_memberInfo.m_data;
  while ( v9->m_name.m_cachedString != v6 )
  {
    ++v8;
    ++v2;
    ++v9;
    if ( v8 >= v7 )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 494
// RVA: 0xE44310
void __fastcall hkDataClassDict::getDeclaredMemberInfo(hkDataClassDict *this, int i, hkDataClass_MemberInfo *info)
{
  hkDataClassDict::MemberInfo *v3; // r9
  const char *v4; // rax

  v3 = &this->m_memberInfo.m_data[i];
  v4 = v3->m_name.m_cachedString;
  info->m_owner = (hkDataClassImpl *)&this->vfptr;
  info->m_name = v4;
  info->m_type = v3->m_type;
  info->m_valuePtr = v3->m_valuePtr;
}

// File Line: 504
// RVA: 0xE445B0
__int64 __fastcall hkDataClassDict::getNumMembers(hkDataClassDict *this)
{
  hkDataClassDict *v1; // rdx
  __int64 result; // rax

  v1 = this->m_parent.m_pntr;
  for ( result = (unsigned int)this->m_memberInfo.m_size; v1; v1 = v1->m_parent.m_pntr )
    result = (unsigned int)(v1->m_memberInfo.m_size + result);
  return result;
}

// File Line: 516
// RVA: 0xE443C0
signed __int64 __fastcall hkDataClassDict::getMemberIndexByName(hkDataClassDict *this, const char *nameIn)
{
  const char *v2; // rdi
  hkDataClassDict *v3; // rsi
  hkDataWorldDict::ObjectTracker *v4; // rbp
  char *v5; // rbx
  __int64 v6; // rdx
  int v7; // edi
  __int64 v8; // rcx
  hkDataClassDict::MemberInfo *v9; // rax
  int v11; // edi

  v2 = nameIn;
  v3 = this;
  v4 = this->m_world->m_tracker;
  if ( nameIn )
  {
    v5 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_interns,
                   (unsigned __int64)nameIn,
                   0i64);
    if ( !v5 )
    {
      v5 = hkString::strDup(v2);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v4->m_interns.m_map,
        (unsigned __int64)v5,
        (unsigned __int64)v5);
    }
  }
  else
  {
    v5 = 0i64;
  }
  while ( 1 )
  {
    v6 = v3->m_memberInfo.m_size;
    v7 = 0;
    v8 = 0i64;
    if ( v6 > 0 )
      break;
LABEL_9:
    v3 = v3->m_parent.m_pntr;
    if ( !v3 )
      return 0xFFFFFFFFi64;
  }
  v9 = v3->m_memberInfo.m_data;
  while ( v9->m_name.m_cachedString != v5 )
  {
    ++v8;
    ++v7;
    ++v9;
    if ( v8 >= v6 )
      goto LABEL_9;
  }
  v11 = v7 - (unsigned __int64)((__int64 (__fastcall *)(hkDataClassDict *))v3->vfptr[6].__vecDelDtor)(v3);
  return v11 + ((unsigned int (__fastcall *)(hkDataClassDict *))v3->vfptr[9].__vecDelDtor)(v3);
}

// File Line: 534
// RVA: 0xE44480
void __fastcall hkDataClassDict::getMemberInfo(hkDataClassDict *this, int memberIndex, hkDataClass_MemberInfo *info)
{
  hkDataClass_MemberInfo *v3; // rsi
  hkDataClassDict *v4; // rbx
  int v5; // edi
  hkDataClassDict::MemberInfo *v6; // rcx
  const char *v7; // rax

  v3 = info;
  v4 = this;
  v5 = memberIndex - (unsigned __int64)((__int64 (*)(void))this->vfptr[9].__vecDelDtor)();
  while ( 1 )
  {
    v5 += v4->m_memberInfo.m_size;
    if ( v5 >= 0 )
      break;
    v4 = v4->m_parent.m_pntr;
    if ( !v4 )
      return;
  }
  v6 = &v4->m_memberInfo.m_data[v5];
  v7 = v6->m_name.m_cachedString;
  v3->m_owner = (hkDataClassImpl *)&v4->vfptr;
  v3->m_name = v7;
  v3->m_type = v6->m_type;
  v3->m_valuePtr = v6->m_valuePtr;
}

// File Line: 554
// RVA: 0xE44120
void __fastcall hkDataClassDict::getAllMemberInfo(hkDataClassDict *this, hkArrayBase<hkDataClass_MemberInfo> *infos)
{
  hkDataClassDict *v2; // r11
  hkDataClassDict *v3; // r8
  hkDataClass_MemberInfo *i; // r10
  __int64 v5; // rdx
  hkDataClassDict::MemberInfo *v6; // rcx
  signed __int64 v7; // rax
  char *v8; // r9
  __int64 v9; // rcx

  v2 = this;
  v3 = this;
  for ( i = &infos->m_data[infos->m_size]; v3; v3 = v3->m_parent.m_pntr )
  {
    v5 = v3->m_memberInfo.m_size;
    v6 = v3->m_memberInfo.m_data;
    i -= v5;
    if ( v5 > 0 )
    {
      v7 = (signed __int64)&v6->m_type;
      v8 = (char *)((char *)i - (char *)v6);
      do
      {
        v9 = *(_QWORD *)(v7 - 16);
        *(_QWORD *)&v8[v7 - 8] = v2;
        v7 += 32i64;
        *(_QWORD *)&v8[v7 - 48] = v9;
        *(_QWORD *)&v8[v7 - 32] = *(_QWORD *)(v7 - 32);
        *(_QWORD *)&v8[v7 - 24] = *(_QWORD *)(v7 - 24);
        --v5;
      }
      while ( v5 );
    }
  }
}

// File Line: 624
// RVA: 0xE42840
void __fastcall hkDataClassDict::addMember(hkDataClassDict *this, InternedString name, hkTypeManager::Type *type, const void *valuePtr)
{
  signed int *v4; // rdi
  const char *v5; // rsi
  hkTypeManager::Type *v6; // rbp
  const char *v7; // rbx
  const char **v8; // rax

  v4 = (signed int *)&this->m_memberInfo;
  v5 = (const char *)valuePtr;
  v6 = type;
  v7 = name.m_cachedString;
  if ( this->m_memberInfo.m_size == (this->m_memberInfo.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_world->m_allocator, v4, 32);
  v8 = (const char **)(*(_QWORD *)v4 + 32i64 * v4[2]);
  if ( v8 )
  {
    *v8 = v7;
    v8[1] = 0i64;
    v8[2] = (const char *)v6;
    v8[3] = v5;
  }
  ++v4[2];
}

// File Line: 635
// RVA: 0xE45350
hkResult *__fastcall hkDataClassDict::removeMember(hkDataClassDict *this, hkResult *result, InternedString name)
{
  hkDataClassDict *v3; // r9
  int v4; // er11
  hkResult *v5; // rbx
  signed int v6; // er10
  __int64 v7; // rcx
  const char **v8; // rax
  int v9; // er11
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rax
  hkResultEnum v13; // er11
  __int64 v14; // r10
  int v15; // edx
  __int64 v16; // rcx
  const char **v17; // rax
  hkResult *v18; // rax

  v3 = this;
  v4 = this->m_memberInfo.m_size - 1;
  v5 = result;
  v6 = v4;
  v7 = v4;
  if ( v4 < 0 )
  {
LABEL_5:
    v6 = -1;
  }
  else
  {
    v8 = &v3->m_memberInfo.m_data[v4].m_name.m_cachedString;
    while ( *v8 != name.m_cachedString )
    {
      --v6;
      v8 -= 4;
      if ( --v7 < 0 )
        goto LABEL_5;
    }
  }
  v3->m_memberInfo.m_size = v4;
  v9 = 32 * (v4 - v6);
  v10 = (signed __int64)&v3->m_memberInfo.m_data[v6];
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
  v13 = 0;
  while ( 1 )
  {
    v14 = v3->m_memberInfo.m_size;
    v15 = 0;
    v16 = 0i64;
    if ( v14 > 0 )
      break;
LABEL_14:
    v3 = v3->m_parent.m_pntr;
    if ( !v3 )
    {
      v18 = v5;
      LOBYTE(v13) = 0;
      v5->m_enum = v13;
      return v18;
    }
  }
  v17 = &v3->m_memberInfo.m_data->m_name.m_cachedString;
  while ( *v17 != name.m_cachedString )
  {
    ++v16;
    ++v15;
    v17 += 4;
    if ( v16 >= v14 )
      goto LABEL_14;
  }
  v18 = v5;
  LOBYTE(v13) = &v3->m_memberInfo.m_data[v15] != 0;
  v5->m_enum = v13;
  return v18;
}

// File Line: 714
// RVA: 0xE459A0
void __fastcall hkDataClassDict::selfDestruct(hkDataClassDict *this)
{
  int v1; // er8
  hkMemoryAllocator *v2; // rsi
  hkDataClassDict *v3; // rbx
  int v4; // ebp
  __int64 v5; // r14
  hkDataClassDict::Enum *v6; // rdi
  int v7; // er8
  _QWORD **v8; // rax
  int v9; // er8
  hkReferencedObject *v10; // rcx

  v1 = this->m_memberInfo.m_capacityAndFlags;
  v2 = this->m_world->m_allocator;
  v3 = this;
  this->m_memberInfo.m_size = 0;
  if ( v1 >= 0 )
    v2->vfptr->bufFree(v2, this->m_memberInfo.m_data, 32 * v1);
  v3->m_memberInfo.m_data = 0i64;
  v3->m_memberInfo.m_capacityAndFlags = 2147483648;
  v4 = 0;
  if ( v3->m_enums.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v3->m_enums.m_data[v5];
      v7 = v6->m_items.m_capacityAndFlags;
      v6->m_items.m_size = 0;
      if ( v7 >= 0 )
        v2->vfptr->bufFree(v2, v6->m_items.m_data, 16 * v7);
      v6->m_items.m_data = 0i64;
      v6->m_items.m_capacityAndFlags = 2147483648;
      v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, hkDataClassDict::Enum *, signed __int64))(*v8[11] + 16i64))(v8[11], v6, 24i64);
      ++v4;
      ++v5;
    }
    while ( v4 < v3->m_enums.m_size );
  }
  v9 = v3->m_enums.m_capacityAndFlags;
  v3->m_enums.m_size = 0;
  if ( v9 >= 0 )
    v2->vfptr->bufFree(v2, v3->m_enums.m_data, 8 * v9);
  v3->m_enums.m_data = 0i64;
  v3->m_enums.m_capacityAndFlags = 2147483648;
  hkReferencedObject::addReference((hkReferencedObject *)&InternedNullRefCounted.vfptr);
  v10 = (hkReferencedObject *)&v3->m_name.m_cached.m_pntr->vfptr;
  if ( v10 )
    hkReferencedObject::removeReference(v10);
  v3->m_name.m_cached.m_pntr = &InternedNullRefCounted;
}

// File Line: 792
// RVA: 0xE44880
const char *__fastcall SSUnaryParam::get_expected_type(hkDynamicClassNameRegistry *this)
{
  return this->m_name;
}

// File Line: 797
// RVA: 0xE440C0
void __fastcall hkDataObjectDict::getAllMemberHandles(hkDataObjectDict *this, hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  const struct _hkDataObject_MemberHandle **v2; // r9
  hkDataClassDict *i; // r8
  __int64 v4; // rdx
  hkDataClassDict::MemberInfo *v5; // rcx
  __int64 j; // rax

  v2 = &handles->m_data[handles->m_size];
  for ( i = this->m_class.m_pntr; i; i = i->m_parent.m_pntr )
  {
    v4 = i->m_memberInfo.m_size;
    v5 = i->m_memberInfo.m_data;
    v2 -= v4;
    for ( j = 0i64; j < v4; ++v5 )
      v2[j++] = (const struct _hkDataObject_MemberHandle *)v5;
  }
}

// File Line: 802
// RVA: 0xE45AE0
void __fastcall hkDataObjectDict::selfDestruct(hkDataObjectDict *this)
{
  int v1; // edi
  hkDataObjectDict *v2; // rbx
  __int64 v3; // rsi
  hkDataObjectDict::MemberData *v4; // r11
  hkDataClassDict *v5; // r9
  __int64 v6; // r10
  int v7; // er8
  __int64 v8; // rdx
  hkDataClassDict::MemberInfo *v9; // rcx
  signed __int64 v10; // rcx
  int v11; // er8
  hkMemoryAllocator *v12; // rcx
  unsigned int v13; // [rsp+20h] [rbp-8h]

  v1 = 0;
  v2 = this;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_memberData.m_data;
      v5 = v2->m_class.m_pntr;
      if ( v5 )
      {
        while ( 1 )
        {
          v6 = v5->m_memberInfo.m_size;
          v7 = 0;
          v8 = 0i64;
          if ( v6 > 0 )
            break;
LABEL_8:
          v5 = v5->m_parent.m_pntr;
          if ( !v5 )
            goto LABEL_12;
        }
        v9 = v5->m_memberInfo.m_data;
        while ( v9->m_name.m_cachedString != v4[v3].m_memberName.m_cachedString )
        {
          ++v8;
          ++v7;
          ++v9;
          if ( v8 >= v6 )
            goto LABEL_8;
        }
        v10 = (signed __int64)&v5->m_memberInfo.m_data[v7];
        if ( v10 )
          `anonymous namespace::Union::clearArray(
            *(Union **)(v10 + 16),
            (hkTypeManager::Type *)&v4[v1].m_value,
            (Union *)1,
            0,
            v13);
      }
LABEL_12:
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_memberData.m_size );
  }
  v11 = v2->m_memberData.m_capacityAndFlags;
  v12 = v2->m_class.m_pntr->m_world->m_allocator;
  v2->m_memberData.m_size = 0;
  if ( v11 >= 0 )
    v12->vfptr->bufFree(v12, v2->m_memberData.m_data, 16 * v11);
  v2->m_memberData.m_capacityAndFlags = 2147483648;
  v2->m_memberData.m_data = 0i64;
}

// File Line: 811
// RVA: 0xE43C30
void __fastcall hkDataObjectDict::destroy(hkDataObjectDict *this)
{
  int v1; // edi
  hkDataObjectDict *v2; // rbx
  __int64 v3; // rsi
  hkDataObjectDict::MemberData *v4; // r11
  hkDataClassDict *v5; // r9
  __int64 v6; // r10
  int v7; // er8
  __int64 v8; // rdx
  hkDataClassDict::MemberInfo *v9; // rcx
  signed __int64 v10; // rcx
  int v11; // er8
  hkMemoryAllocator *v12; // rcx
  unsigned int v13; // [rsp+20h] [rbp-8h]

  v1 = 0;
  v2 = this;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_memberData.m_data;
      v5 = v2->m_class.m_pntr;
      if ( v5 )
      {
        while ( 1 )
        {
          v6 = v5->m_memberInfo.m_size;
          v7 = 0;
          v8 = 0i64;
          if ( v6 > 0 )
            break;
LABEL_8:
          v5 = v5->m_parent.m_pntr;
          if ( !v5 )
            goto LABEL_12;
        }
        v9 = v5->m_memberInfo.m_data;
        while ( v9->m_name.m_cachedString != v4[v3].m_memberName.m_cachedString )
        {
          ++v8;
          ++v7;
          ++v9;
          if ( v8 >= v6 )
            goto LABEL_8;
        }
        v10 = (signed __int64)&v5->m_memberInfo.m_data[v7];
        if ( v10 )
          `anonymous namespace::Union::clearArray(
            *(Union **)(v10 + 16),
            (hkTypeManager::Type *)&v4[v1].m_value,
            (Union *)1,
            1,
            v13);
      }
LABEL_12:
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_memberData.m_size );
  }
  v11 = v2->m_memberData.m_capacityAndFlags;
  v12 = v2->m_class.m_pntr->m_world->m_allocator;
  v2->m_memberData.m_size = 0;
  if ( v11 >= 0 )
    v12->vfptr->bufFree(v12, v2->m_memberData.m_data, 16 * v11);
  v2->m_memberData.m_capacityAndFlags = 2147483648;
  v2->m_memberData.m_data = 0i64;
}

// File Line: 820
// RVA: 0xE45450
void __fastcall hkDataObjectDict::removeMember(hkDataObjectDict *this, InternedString name)
{
  __int64 v2; // r9
  int v3; // ebx
  __int64 v4; // r8
  hkDataObjectDict *v5; // rdi
  hkDataObjectDict::MemberData *v6; // rax
  hkDataClassDict *v7; // r9
  hkDataObjectDict::MemberData *v8; // r11
  __int64 v9; // r10
  int v10; // er8
  __int64 v11; // rdx
  hkDataClassDict::MemberInfo *v12; // rcx
  signed __int64 v13; // rcx
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  signed __int64 v16; // r8
  signed __int64 v17; // rcx
  signed __int64 v18; // r8
  __int64 v19; // rax
  unsigned int v20; // [rsp+20h] [rbp-8h]

  v2 = this->m_memberData.m_size;
  v3 = 0;
  v4 = 0i64;
  v5 = this;
  if ( v2 > 0 )
  {
    v6 = this->m_memberData.m_data;
    while ( v6->m_memberName.m_cachedString != name.m_cachedString )
    {
      ++v4;
      ++v3;
      ++v6;
      if ( v4 >= v2 )
        return;
    }
    v7 = this->m_class.m_pntr;
    v8 = &this->m_memberData.m_data[v3];
    if ( v7 )
    {
      while ( 1 )
      {
        v9 = v7->m_memberInfo.m_size;
        v10 = 0;
        v11 = 0i64;
        if ( v9 > 0 )
          break;
LABEL_11:
        v7 = v7->m_parent.m_pntr;
        if ( !v7 )
          goto LABEL_15;
      }
      v12 = v7->m_memberInfo.m_data;
      while ( v12->m_name.m_cachedString != v8->m_memberName.m_cachedString )
      {
        ++v11;
        ++v10;
        ++v12;
        if ( v11 >= v9 )
          goto LABEL_11;
      }
      v13 = (signed __int64)&v7->m_memberInfo.m_data[v10];
      if ( v13 )
        `anonymous namespace::Union::clearArray(
          *(Union **)(v13 + 16),
          (hkTypeManager::Type *)&v8->m_value,
          (Union *)1,
          0,
          v20);
    }
LABEL_15:
    v14 = --v5->m_memberData.m_size;
    if ( (_DWORD)v14 != v3 )
    {
      v15 = 2i64;
      v16 = 16 * v14;
      v17 = (signed __int64)&v5->m_memberData.m_data[v3];
      v18 = v16 - 16i64 * v3;
      do
      {
        v19 = *(_QWORD *)(v18 + v17);
        v17 += 8i64;
        *(_QWORD *)(v17 - 8) = v19;
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
hkDataObject_Value *__fastcall hkDataObjectDict::getMemberValue(hkDataObjectDict *this, hkDataObject_Value *result, int it)
{
  hkDataObjectDict::MemberData *v3; // rax
  const struct _hkDataObject_MemberHandle *v4; // rcx
  hkDataObject_Value *v5; // rax

  v3 = this->m_memberData.m_data;
  result->m_impl = (hkDataObjectImpl *)&this->vfptr;
  v4 = (const struct _hkDataObject_MemberHandle *)v3[it].m_memberName.m_cachedString;
  v5 = result;
  result->m_handle = v4;
  return v5;
}

// File Line: 881
// RVA: 0xE421A0
hkDataObjectDict::MemberAccess *__fastcall hkDataObjectDict::_readAccess(hkDataObjectDict *this, hkDataObjectDict::MemberAccess *result, const struct _hkDataObject_MemberHandle *handle, hkTypeManager::SubType subType)
{
  int v4; // er10
  unsigned int v5; // ebp
  signed int v6; // esi
  const struct _hkDataObject_MemberHandle *v7; // r12
  hkDataObjectDict *v8; // r15
  int v9; // eax
  hkDataObjectDict::MemberData *v10; // r9
  bool v11; // zf
  hkDataObjectDict::MemberData *v12; // rax
  hkDataObjectDict::MemberData *v13; // r14
  hkTypeManager::Type *v14; // r13
  hkTypeManager::SubType v15; // ecx
  Union v16; // rax
  hkDataClassDict *v17; // rax
  _QWORD *v18; // rax
  __int64 v19; // rbx
  _QWORD *v20; // rdi
  unsigned int v21; // eax
  int v22; // eax
  __int64 v23; // r15
  __int64 v24; // rbx
  __int64 v25; // rdi
  __int128 v26; // xmm2
  hkDataWorldDict *v27; // rbx
  hkBaseObjectVtbl *v28; // rdi
  const char *v29; // rax
  hkTypeManager::Type *v30; // rax
  __int64 v31; // r8
  __int64 v32; // rax
  float *v33; // rdx
  hkDataObjectDict::MemberAccess *v34; // rax
  hkTypeManager::Type *v35; // [rsp+60h] [rbp+8h]
  hkDataObjectDict::MemberAccess *v36; // [rsp+68h] [rbp+10h]

  v36 = result;
  v4 = this->m_memberData.m_size;
  v5 = 0;
  v6 = -1;
  v7 = handle;
  v8 = this;
  v9 = 0;
  if ( v4 <= 0 )
    goto LABEL_36;
  v10 = this->m_memberData.m_data;
  do
  {
    v11 = v10->m_memberName.m_cachedString == *(const char **)handle;
    ++v10;
    if ( v11 )
      v6 = v9;
    ++v9;
  }
  while ( v9 < v4 );
  if ( v6 == -1 )
  {
LABEL_36:
    v6 = this->m_memberData.m_size;
    if ( v4 == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_class.m_pntr->m_world->m_allocator, &this->m_memberData, 16);
    v12 = &v8->m_memberData.m_data[v8->m_memberData.m_size];
    if ( v12 )
      v12->m_memberName.m_cachedString = 0i64;
    v13 = &v8->m_memberData.m_data[v8->m_memberData.m_size++];
    v13->m_memberName.m_cachedString = *(const char **)v7;
    v14 = (hkTypeManager::Type *)*((_QWORD *)v7 + 2);
    v15 = v14->m_subType;
    if ( v14->m_subType == 8 )
    {
      hkDataArrayDict_create(v8->m_class.m_pntr->m_world, v14->m_parent, 0);
      v13->m_value = v16;
      ++*(_DWORD *)(v16.i + 12);
      goto LABEL_33;
    }
    switch ( v15 )
    {
      case 9:
        v17 = v8->m_class.m_pntr;
        v35 = v14->m_parent;
        hkDataArrayDict_create(v17->m_world, v35, 0);
        v13->m_value.i = (__int64)v18;
        v19 = *v18;
        v20 = v18;
        v21 = hkTypeManager::Type::getTupleSize(v14);
        (*(void (__fastcall **)(_QWORD *, _QWORD))(v19 + 32))(v20, v21);
        ++*(_DWORD *)(v13->m_value.i + 12);
        if ( *((_QWORD *)v7 + 3) )
        {
          if ( v35->m_subType == 3 )
          {
            v22 = hkTypeManager::Type::getTupleSize(v14);
            v23 = *((_QWORD *)v7 + 3);
            v24 = 0i64;
            v25 = v22;
            if ( v22 > 0 )
            {
              do
              {
                v26 = *(unsigned int *)(v23 + 4 * v24);
                (*(void (__fastcall **)(Union, _QWORD))(*(_QWORD *)v13->m_value.i + 128i64))(v13->m_value, v5);
                ++v24;
                ++v5;
              }
              while ( v24 < v25 );
            }
          }
        }
        goto LABEL_33;
      case 7:
        goto LABEL_37;
      case 6:
        v27 = v8->m_class.m_pntr->m_world;
        v28 = v27->vfptr;
        v29 = hkTypeManager::Type::getTypeName(v14);
        v30 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v28[4].__first_virtual_table_function__)(
                                       v27,
                                       v29);
        LOBYTE(v31) = 1;
        v35 = v30;
        v32 = ((__int64 (__fastcall *)(hkDataWorldDict *, hkTypeManager::Type **, __int64))v8->m_class.m_pntr->m_world->vfptr[2].__vecDelDtor)(
                v8->m_class.m_pntr->m_world,
                &v35,
                v31);
        if ( v32 )
        {
          ++*(_WORD *)(v32 + 10);
          ++*(_DWORD *)(v32 + 12);
        }
        v13->m_value.i = v32;
        ++*(_DWORD *)(v32 + 12);
        --*(_WORD *)(v32 + 10);
        v11 = (*(_DWORD *)(v32 + 12))-- == 1;
        if ( v11 )
          (**(void (__fastcall ***)(__int64, signed __int64))v32)(v32, 1i64);
        goto LABEL_33;
    }
    v33 = (float *)*((_QWORD *)v7 + 3);
    if ( !v33 )
    {
LABEL_37:
      v13->m_value.i = 0i64;
      goto LABEL_33;
    }
    if ( (v15 - 2) & 0xFFFFFFFD )
    {
      if ( v15 == 3 )
      {
        v13->m_value.r = *v33;
      }
      else if ( v15 == 5 )
      {
        v13->m_value.i = (__int64)hkString::strDup(*((const char **)v7 + 3));
      }
    }
    else
    {
      v13->m_value.i = *(_QWORD *)v33;
    }
  }
LABEL_33:
  v34 = v36;
  v36->info = (hkDataClassDict::MemberInfo *)v7;
  v34->index = v6;
  return v34;
}

// File Line: 976
// RVA: 0xE42540
hkDataObjectDict::MemberAccess *__fastcall hkDataObjectDict::_writeAccess(hkDataObjectDict *this, hkDataObjectDict::MemberAccess *result, const struct _hkDataObject_MemberHandle *handle, hkTypeManager::SubType subType)
{
  __int64 v4; // rbp
  int v5; // ebx
  __int64 v6; // r9
  const struct _hkDataObject_MemberHandle *v7; // rsi
  hkDataObjectDict::MemberAccess *v8; // rdi
  hkDataObjectDict::MemberData *v9; // rax
  hkArrayBase<hkDataObjectDict::MemberData> *v10; // rbx
  hkDataObjectDict::MemberData *v11; // rax
  __int64 v12; // rax
  hkDataObjectDict::MemberData *v13; // rcx
  const char *v14; // rax
  unsigned int v16; // [rsp+20h] [rbp-8h]

  v4 = this->m_memberData.m_size;
  v5 = 0;
  v6 = 0i64;
  v7 = handle;
  v8 = result;
  if ( (signed int)v4 <= 0 )
  {
LABEL_5:
    v10 = &this->m_memberData;
    if ( this->m_memberData.m_size == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(this->m_class.m_pntr->m_world->m_allocator, &this->m_memberData, 16);
    v11 = &v10->m_data[v10->m_size];
    if ( v11 )
      v11->m_memberName.m_cachedString = 0i64;
    v12 = v10->m_size;
    v8->index = v4;
    v13 = &v10->m_data[v12];
    v10->m_size = v12 + 1;
    v14 = *(const char **)v7;
    v13->m_value.i = 0i64;
    v13->m_memberName.m_cachedString = v14;
  }
  else
  {
    v9 = this->m_memberData.m_data;
    while ( v9->m_memberName.m_cachedString != *(const char **)handle )
    {
      ++v6;
      ++v5;
      ++v9;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
    `anonymous namespace::Union::clearArray(
      *((Union **)handle + 2),
      (hkTypeManager::Type *)&this->m_memberData.m_data[v5].m_value,
      (Union *)1,
      0,
      v16);
    v8->index = v5;
  }
  v8->info = (hkDataClassDict::MemberInfo *)v7;
  return v8;
}

// File Line: 998
// RVA: 0xE42120
signed __int64 __fastcall hkDataObjectDict::_hasMember(hkDataObjectDict *this, InternedString name)
{
  __int64 v2; // r9
  unsigned int v3; // er11
  __int64 v4; // r8
  hkDataObjectDict::MemberData *v5; // rax
  hkDataClassDict *i; // r9
  __int64 v7; // r10
  int v8; // er8
  __int64 v9; // rcx
  const char **v10; // rax
  signed __int64 result; // rax
  signed __int64 v12; // rcx

  v2 = this->m_memberData.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( v2 <= 0 )
  {
LABEL_5:
    for ( i = this->m_class.m_pntr; i; i = i->m_parent.m_pntr )
    {
      v7 = i->m_memberInfo.m_size;
      v8 = 0;
      v9 = 0i64;
      if ( v7 > 0 )
      {
        v10 = &i->m_memberInfo.m_data->m_name.m_cachedString;
        while ( *v10 != name.m_cachedString )
        {
          ++v9;
          ++v8;
          v10 += 4;
          if ( v9 >= v7 )
            goto LABEL_11;
        }
        v12 = (signed __int64)&i->m_memberInfo.m_data[v8];
        if ( v12 )
        {
          LOBYTE(v3) = *(_QWORD *)(v12 + 24) != 0i64;
          return v3;
        }
        break;
      }
LABEL_11:
      ;
    }
    result = 0i64;
  }
  else
  {
    v5 = this->m_memberData.m_data;
    while ( v5->m_memberName.m_cachedString != name.m_cachedString )
    {
      ++v4;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
    result = 1i64;
  }
  return result;
}

// File Line: 1015
// RVA: 0xE44900
signed __int64 __fastcall hkDataObjectDict::hasMember(hkDataObjectDict *this, const char *name)
{
  const char *v2; // rdi
  hkDataObjectDict *v3; // rsi
  hkDataWorldDict::ObjectTracker *v4; // rbp
  char *v5; // rbx

  v2 = name;
  v3 = this;
  v4 = this->m_class.m_pntr->m_world->m_tracker;
  if ( name )
  {
    v5 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_interns,
                   (unsigned __int64)name,
                   0i64);
    if ( !v5 )
    {
      v5 = hkString::strDup(v2);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v4->m_interns.m_map,
        (unsigned __int64)v5,
        (unsigned __int64)v5);
    }
  }
  else
  {
    v5 = 0i64;
  }
  return hkDataObjectDict::_hasMember(v3, (InternedString)v5);
}

// File Line: 1020
// RVA: 0xE44C10
signed __int64 __fastcall hkDataObjectDict::isSet(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  const struct _hkDataObject_MemberHandle *v2; // r8
  hkDataObjectDict *v3; // rax
  __int64 v5; // rdx
  __int64 v6; // rcx
  const char *v7; // r8
  hkDataObjectDict::MemberData *v8; // rax

  v2 = handle;
  v3 = this;
  if ( *((_QWORD *)handle + 3) )
    return 1i64;
  v5 = this->m_memberData.m_size;
  v6 = 0i64;
  if ( v5 > 0 )
  {
    v7 = *(const char **)v2;
    v8 = v3->m_memberData.m_data;
    while ( v8->m_memberName.m_cachedString != v7 )
    {
      ++v6;
      ++v8;
      if ( v6 >= v5 )
        return 0i64;
    }
    return 1i64;
  }
  return 0i64;
}

// File Line: 1041
// RVA: 0xE42740
hkDataObject_Value *__fastcall hkDataObjectDict::accessByName(hkDataObjectDict *this, hkDataObject_Value *result, const char *name)
{
  const char *v3; // rsi
  hkDataObject_Value *v4; // rdi
  hkDataWorldDict::ObjectTracker *v5; // rbp
  hkDataObjectDict *v6; // r14
  char *v7; // rbx
  hkDataClassDict *v8; // r8
  __int64 v9; // r9
  int v10; // edx
  __int64 v11; // rcx
  char **v12; // rax
  hkDataObject_Value *v13; // rax
  signed __int64 v14; // rax

  v3 = name;
  v4 = result;
  v5 = this->m_class.m_pntr->m_world->m_tracker;
  v6 = this;
  if ( name )
  {
    v7 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_interns,
                   (unsigned __int64)name,
                   0i64);
    if ( !v7 )
    {
      v7 = hkString::strDup(v3);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v5->m_interns.m_map,
        (unsigned __int64)v7,
        (unsigned __int64)v7);
    }
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v6->m_class.m_pntr;
  if ( !v8 )
    goto LABEL_11;
  while ( 1 )
  {
    v9 = v8->m_memberInfo.m_size;
    v10 = 0;
    v11 = 0i64;
    if ( v9 > 0 )
      break;
LABEL_10:
    v8 = v8->m_parent.m_pntr;
    if ( !v8 )
      goto LABEL_11;
  }
  v12 = (char **)v8->m_memberInfo.m_data;
  while ( *v12 != v7 )
  {
    ++v11;
    ++v10;
    v12 += 4;
    if ( v11 >= v9 )
      goto LABEL_10;
  }
  v14 = (signed __int64)&v8->m_memberInfo.m_data[v10];
  if ( v14 )
  {
    v4->m_handle = (const struct _hkDataObject_MemberHandle *)v14;
    v4->m_impl = (hkDataObjectImpl *)&v6->vfptr;
    v13 = v4;
  }
  else
  {
LABEL_11:
    v4->m_impl = 0i64;
    v4->m_handle = 0i64;
    v13 = v4;
  }
  return v13;
}

// File Line: 1058
// RVA: 0xE42A90
hkDataArrayImpl *__fastcall hkDataObjectDict::asArray(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict *v2; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v2 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_ARRAY);
  return v2->m_memberData.m_data[result.index].m_value.a;
}

// File Line: 1065
// RVA: 0xE43080
const char *__fastcall hkDataObjectDict::asString(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict *v2; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v2 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_CSTRING);
  return v2->m_memberData.m_data[result.index].m_value.s;
}

// File Line: 1072
// RVA: 0xE42C80
Union __fastcall hkDataObjectDict::asInt(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict *v2; // rbx
  Union v3; // rax
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v2 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_VOID);
  if ( (result.info->m_type->m_subType - 2) & 0xFFFFFFFD )
    v3.i = 0i64;
  else
    v3.i = (__int64)v2->m_memberData.m_data[result.index].m_value;
  return v3;
}

// File Line: 1084
// RVA: 0xE42DB0
hkDataObjectImpl *__fastcall hkDataObjectDict::asObject(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict *v2; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v2 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_CLASS);
  return v2->m_memberData.m_data[result.index].m_value.o;
}

// File Line: 1090
// RVA: 0xE43160
hkDataRefCountedVtbl *__fastcall hkDataObjectDict::asVec(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, int nreal)
{
  int v3; // edi
  hkDataObjectDict *v4; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v3 = nreal;
  v4 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_TUPLE);
  return hkRealArrayImplementation_getReals(v4->m_memberData.m_data[result.index].m_value.a, v3);
}

// File Line: 1099
// RVA: 0xE42E70
float __fastcall hkDataObjectDict::asReal(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkDataObjectDict *v2; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v2 = this;
  hkDataObjectDict::_readAccess(this, &result, handle, SUB_TYPE_REAL);
  return v2->m_memberData.m_data[result.index].m_value.r;
}

// File Line: 1106
// RVA: 0xE43520
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, hkDataObject_Value *value)
{
  hkDataObjectImpl *v3; // rdi
  const struct _hkDataObject_MemberHandle *v4; // rbx
  hkDataObjectDict *v5; // rsi
  hkTypeManager::Type *v6; // r10
  hkTypeManager::SubType v7; // er8
  hkTypeManager::Type *v8; // rdx
  signed __int64 v9; // r9
  __int64 v10; // rax
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-28h]
  hkDataObjectDict::MemberAccess v12; // [rsp+30h] [rbp-18h]

  v3 = value->m_impl;
  v4 = handle;
  v5 = this;
  hkDataObjectDict::_readAccess((hkDataObjectDict *)value->m_impl, &result, value->m_handle, SUB_TYPE_VOID);
  hkDataObjectDict::_writeAccess(v5, &v12, v4, SUB_TYPE_VOID);
  v6 = result.info->m_type;
  v7 = v6->m_subType;
  v8 = v12.info->m_type;
  v9 = 2i64 * result.index;
  v10 = *(_QWORD *)(*(_QWORD *)&v3[1].m_memSize + 16i64 * result.index + 8);
  if ( (unsigned int)(v6->m_subType - 8) <= 1 )
  {
    if ( (unsigned int)(v8->m_subType - 8) > 1 )
      goto LABEL_10;
    goto LABEL_8;
  }
  if ( v7 == 7 && v8->m_subType == 7 || v7 == 6 && v6 == v8 )
  {
LABEL_8:
    if ( v10 )
      ++*(_DWORD *)(v10 + 12);
  }
LABEL_10:
  v5->m_memberData.m_data[v12.index].m_value.i = *(_QWORD *)(*(_QWORD *)&v3[1].m_memSize + 8 * v9 + 8);
}

// File Line: 1150
// RVA: 0xE43750
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, hkDataObjectImpl *value)
{
  hkDataObjectImpl *v3; // rbx
  hkDataObjectDict *v4; // rdi
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v3 = value;
  v4 = this;
  if ( value )
    ++value->m_count;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_CLASS);
  v4->m_memberData.m_data[result.index].m_value.i = (__int64)v3;
}

// File Line: 1160
// RVA: 0xE436B0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, hkDataArrayImpl *value)
{
  hkDataArrayImpl *v3; // rbx
  hkDataObjectDict *v4; // rdi
  hkTypeManager::Type *v5; // rbp
  hkTypeManager::Type *v6; // rsi
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]
  hkBool v8; // [rsp+50h] [rbp+18h]

  ++value->m_count;
  v3 = value;
  v4 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  v5 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataArrayImpl *))v3->vfptr[1].__vecDelDtor)(v3);
  v6 = result.info->m_type->m_parent;
  if ( hkTypeManager::Type::isEqual(result.info->m_type->m_parent, &v8, v5)->m_bool
    || v6->m_subType == 6 && !hkTypeManager::Type::getTypeName(v6) && v5->m_subType == 6 )
  {
    v4->m_memberData.m_data[result.index].m_value.i = (__int64)v3;
  }
}

// File Line: 1186
// RVA: 0xE437A0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, const char *value)
{
  const char *v3; // rdi
  hkDataObjectDict *v4; // rbx
  char *v5; // rdx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v3 = value;
  v4 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_CSTRING);
  if ( v3 )
    v5 = hkString::strDup(v3);
  else
    v5 = 0i64;
  v4->m_memberData.m_data[result.index].m_value.i = (__int64)v5;
}

// File Line: 1192
// RVA: 0xE43660
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, float r)
{
  hkDataObjectDict *v3; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-28h]

  v3 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_REAL);
  v3->m_memberData.m_data[result.index].m_value.r = r;
}

// File Line: 1198
// RVA: 0xE438D0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, hkHalf r)
{
  hkDataObjectDict *v3; // rbx
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]
  __int16 v5; // [rsp+50h] [rbp+18h]

  v5 = r.m_value;
  v3 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_REAL);
  LODWORD(v3->m_memberData.m_data[result.index].m_value.r) = v5 << 16;
}

// File Line: 1204
// RVA: 0xE43800
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, const float *r, int nreal)
{
  const float *v4; // r14
  int v5; // ebp
  hkDataObjectDict *v6; // rbx
  hkTypeManager::Type *v7; // rsi
  hkTypeManager::Type *v8; // rdx
  signed __int64 v9; // rdi
  __int64 *v10; // rax
  __int64 v11; // rbx
  unsigned int v12; // eax
  hkDataRefCountedVtbl *v13; // rax
  int v14; // er8
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v4 = r;
  v5 = nreal;
  v6 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  v7 = result.info->m_type;
  if ( v7->m_subType == 9 )
  {
    v8 = v7->m_parent;
    if ( v8->m_subType == 3 )
    {
      v9 = (signed __int64)&v6->m_memberData.m_data[result.index];
      if ( !*(_QWORD *)(v9 + 8) )
      {
        hkDataArrayDict_create(v6->m_class.m_pntr->m_world, v8, 0);
        *(_QWORD *)(v9 + 8) = v10;
        v11 = *v10;
        v12 = hkTypeManager::Type::getTupleSize(v7);
        (*(void (__fastcall **)(_QWORD, _QWORD))(v11 + 32))(*(_QWORD *)(v9 + 8), v12);
        ++*(_DWORD *)(*(_QWORD *)(v9 + 8) + 12i64);
      }
      v13 = hkRealArrayImplementation_getReals(*(hkDataArrayImpl **)(v9 + 8), v5);
      hkString::memCpy(v13, v4, v14);
    }
  }
}

// File Line: 1230
// RVA: 0xE43920
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, __int64 valueIn)
{
  __int64 v3; // rdi
  hkDataObjectDict *v4; // rbx
  hkTypeManager::Type *v5; // rcx
  signed __int64 v6; // r9
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v3 = valueIn;
  v4 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  v5 = result.info->m_type;
  v6 = (signed __int64)&v4->m_memberData.m_data[result.index];
  switch ( v5->m_subType )
  {
    case 2:
      goto LABEL_9;
    case 3:
      *(float *)(v6 + 8) = (float)(signed int)v3;
      return;
    case 4:
LABEL_9:
      *(_QWORD *)(v6 + 8) = v3;
      break;
  }
}

// File Line: 1249
// RVA: 0xE435F0
void __fastcall hkDataObjectDict::assign(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, int valueIn)
{
  __int64 v3; // rdi
  hkDataObjectDict *v4; // rbx
  hkTypeManager::Type *v5; // rcx
  signed __int64 v6; // r9
  hkDataObjectDict::MemberAccess result; // [rsp+20h] [rbp-18h]

  v3 = valueIn;
  v4 = this;
  hkDataObjectDict::_writeAccess(this, &result, handle, SUB_TYPE_VOID);
  v5 = result.info->m_type;
  v6 = (signed __int64)&v4->m_memberData.m_data[result.index];
  switch ( v5->m_subType )
  {
    case 2:
      goto LABEL_9;
    case 3:
      *(float *)(v6 + 8) = (float)(signed int)v3;
      return;
    case 4:
LABEL_9:
      *(_QWORD *)(v6 + 8) = v3;
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
void __fastcall BasicArrayImplementation<hkDataArrayImpl *>::reserve(BasicArrayImplementation<hkDataObjectImpl *> *this, int n)
{
  int v2; // er9
  int v3; // eax
  int v4; // eax
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = n;
  v3 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < n )
  {
    v4 = 2 * v3;
    if ( n < v4 )
      v2 = v4;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, &this->m_data, v2, 8);
  }
}

// File Line: 1309
// RVA: 0xE467F0
void __fastcall BasicArrayImplementation<hkDataObjectImpl *>::setSize(BasicArrayImplementation<hkDataObjectImpl *> *this, int n)
{
  hkArrayBase<hkDataObjectImpl *> *v2; // rbx
  int v3; // esi
  int v4; // eax
  int v5; // er9
  int v6; // eax
  int v7; // edx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = &this->m_data;
  v3 = n;
  v4 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < n )
  {
    v5 = n;
    v6 = 2 * v4;
    if ( n < v6 )
      v5 = v6;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, &this->m_data, v5, 8);
  }
  v7 = v3 - v2->m_size;
  if ( v7 > 0 )
    memset(&v2->m_data[v2->m_size], 0, 8i64 * v7);
  v2->m_size = v3;
}

// File Line: 1331
// RVA: 0xE413A0
void __fastcall VariableIntArrayImplementation::~VariableIntArrayImplementation(VariableIntArrayImplementation *this)
{
  VariableIntArrayImplementation *v1; // rbx
  int v2; // er8
  hkMemoryAllocator *v3; // rcx
  int v4; // er8
  hkMemoryAllocator *v5; // rcx

  v1 = this;
  this->vfptr = (hkDataRefCountedVtbl *)&VariableIntArrayImplementation::`vftable;
  v2 = this->m_int32Array.m_capacityAndFlags;
  v3 = this->m_world->m_allocator;
  v1->m_int32Array.m_size = 0;
  if ( v2 >= 0 )
    v3->vfptr->bufFree(v3, v1->m_int32Array.m_data, 4 * v2);
  v1->m_int32Array.m_data = 0i64;
  v1->m_int32Array.m_capacityAndFlags = 2147483648;
  v4 = v1->m_int64Array.m_capacityAndFlags;
  v5 = v1->m_world->m_allocator;
  v1->m_int64Array.m_size = 0;
  if ( v4 >= 0 )
    v5->vfptr->bufFree(v5, v1->m_int64Array.m_data, 8 * v4);
  v1->m_int64Array.m_data = 0i64;
  v1->m_int64Array.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 1338
// RVA: 0xE44820
hkTypeManager::Type *__fastcall VariableIntArrayImplementation::getType(VariableIntArrayImplementation *this)
{
  return this->m_world->m_typeManager.m_builtInTypes[4];
}

// File Line: 1343
// RVA: 0xE44860
signed __int64 __fastcall VariableIntArrayImplementation::getUnderlyingIntegerSize(VariableIntArrayImplementation *this)
{
  signed __int64 result; // rax

  result = 8i64;
  if ( !this->m_arrayType )
    result = 4i64;
  return result;
}

// File Line: 1355
// RVA: 0xE43A90
void __fastcall VariableIntArrayImplementation::clear(VariableIntArrayImplementation *this)
{
  hkDataWorldDict *v1; // rax
  VariableIntArrayImplementation *v2; // rbx
  int v3; // er8
  hkMemoryAllocator *v4; // rcx

  v1 = this->m_world;
  v2 = this;
  this->m_int32Array.m_size = 0;
  v3 = this->m_int64Array.m_capacityAndFlags;
  v4 = v1->m_allocator;
  v2->m_int64Array.m_size = 0;
  if ( v3 >= 0 )
    v4->vfptr->bufFree(v4, v2->m_int64Array.m_data, 8 * v3);
  v2->m_int64Array.m_data = 0i64;
  v2->m_int64Array.m_capacityAndFlags = 2147483648;
  v2->m_arrayType = 0;
  v2->m_assigned.m_bool = 0;
}

// File Line: 1369
// RVA: 0xE456A0
void __fastcall VariableIntArrayImplementation::reserve(VariableIntArrayImplementation *this, int n)
{
  int v2; // er9
  int v3; // edx
  char *v4; // r8
  int v5; // eax
  hkDataWorldDict *v6; // rdx
  hkResult *v7; // rcx
  hkMemoryAllocator *v8; // rdx
  int v9; // eax
  signed int sizeElem; // [rsp+20h] [rbp-18h]
  char v11; // [rsp+40h] [rbp+8h]
  hkResult result; // [rsp+50h] [rbp+18h]

  v2 = n;
  v3 = this->m_arrayType;
  if ( v3 )
  {
    if ( v3 != 1 )
      return;
    v4 = (char *)&this->m_int64Array;
    v5 = this->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 >= v2 )
      return;
    v6 = this->m_world;
    sizeElem = 8;
    v7 = (hkResult *)&v11;
  }
  else
  {
    v4 = (char *)&this->m_int32Array;
    v5 = this->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 >= v2 )
      return;
    v6 = this->m_world;
    sizeElem = 4;
    v7 = &result;
  }
  v8 = v6->m_allocator;
  v9 = 2 * v5;
  if ( v2 < v9 )
    v2 = v9;
  hkArrayUtil::_reserve(v7, v8, v4, v2, sizeElem);
}

// File Line: 1384
// RVA: 0xE42F40
hkResult *__fastcall VariableIntArrayImplementation::asStridedBasicArray(VariableIntArrayImplementation *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  void *v3; // rax

  if ( this->m_arrayType )
  {
    arrOut->m_type = 9;
    arrOut->m_size = this->m_int64Array.m_size;
    v3 = this->m_int64Array.m_data;
    arrOut->m_stride = 8;
  }
  else
  {
    arrOut->m_type = 7;
    arrOut->m_size = this->m_int32Array.m_size;
    v3 = this->m_int32Array.m_data;
    arrOut->m_stride = 4;
  }
  arrOut->m_data = v3;
  arrOut->m_tupleSize = 1;
  result->m_enum = 0;
  return result;
}

// File Line: 1404
// RVA: 0xE469D0
void __fastcall VariableIntArrayImplementation::setSize(VariableIntArrayImplementation *this, int size)
{
  VariableIntArrayImplementation *v2; // rsi
  int v3; // ecx
  int v4; // ebx
  int v5; // eax
  int v6; // er9
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // er9
  int v11; // eax
  int v12; // edx
  int *v13; // rdi
  __int64 v14; // rcx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = this->m_arrayType;
  v4 = size;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v5 = v2->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v5 < size )
      {
        v6 = size;
        v7 = 2 * v5;
        if ( size < v7 )
          v6 = v7;
        hkArrayUtil::_reserve(&result, v2->m_world->m_allocator, &v2->m_int64Array, v6, 8);
      }
      v8 = v4 - v2->m_int64Array.m_size;
      if ( v8 > 0 )
        memset(&v2->m_int64Array.m_data[v2->m_int64Array.m_size], 0, 8i64 * v8);
      v2->m_int64Array.m_size = v4;
    }
  }
  else
  {
    v9 = v2->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < size )
    {
      v10 = size;
      v11 = 2 * v9;
      if ( size < v11 )
        v10 = v11;
      hkArrayUtil::_reserve(&result, v2->m_world->m_allocator, &v2->m_int32Array, v10, 4);
    }
    v12 = v4 - v2->m_int32Array.m_size;
    v13 = &v2->m_int32Array.m_data[v2->m_int32Array.m_size];
    v14 = v12;
    if ( v12 > 0 )
    {
      while ( v14 )
      {
        *v13 = 0;
        ++v13;
        --v14;
      }
    }
    v2->m_int32Array.m_size = v4;
  }
  if ( !v4 )
    v2->m_assigned.m_bool = 0;
}

// File Line: 1424
// RVA: 0xE445F0
__int64 __fastcall VariableIntArrayImplementation::getSize(VariableIntArrayImplementation *this)
{
  int v1; // edx

  v1 = this->m_arrayType;
  if ( !v1 )
    return (unsigned int)this->m_int32Array.m_size;
  if ( v1 == 1 )
    return (unsigned int)this->m_int64Array.m_size;
  return 0i64;
}

// File Line: 1438
// RVA: 0xE42C30
__int64 __fastcall VariableIntArrayImplementation::asInt(VariableIntArrayImplementation *this, int index)
{
  int v2; // er8

  v2 = this->m_arrayType;
  if ( !v2 )
    return (unsigned int)this->m_int32Array.m_data[index];
  if ( v2 == 1 )
    return LODWORD(this->m_int64Array.m_data[index]);
  return 0i64;
}

// File Line: 1454
// RVA: 0xE42B90
__int64 __fastcall VariableIntArrayImplementation::asInt64(VariableIntArrayImplementation *this, int index)
{
  int v2; // er8

  v2 = this->m_arrayType;
  if ( !v2 )
    return this->m_int32Array.m_data[index];
  if ( v2 == 1 )
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
hkHalf *__fastcall VariableIntArrayImplementation::asHalf(VariableIntArrayImplementation *this, hkHalf *result, int index)
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
  VariableIntArrayImplementation *v3; // rbx

  v3 = this;
  if ( this->m_arrayType )
  {
    ((void (__fastcall *)(VariableIntArrayImplementation *, __int64, _QWORD))this->vfptr[20].__vecDelDtor)(
      this,
      index,
      val);
    v3->m_assigned.m_bool = 1;
  }
  else
  {
    this->m_int32Array.m_data[(signed int)index] = val;
    this->m_assigned.m_bool = 1;
  }
}

// File Line: 1502
// RVA: 0xE42400
void __fastcall VariableIntArrayImplementation::_reallocateArray(VariableIntArrayImplementation *this)
{
  VariableIntArrayImplementation *v1; // rbx
  int v2; // esi
  int v3; // eax
  int v4; // eax
  int v5; // er9
  int v6; // edx
  __int64 v7; // r8
  __int64 v8; // r9
  int v9; // er8
  hkMemoryAllocator *v10; // rcx
  hkErrStream v11; // [rsp+30h] [rbp-228h]
  char buf; // [rsp+50h] [rbp-208h]
  hkResult result; // [rsp+260h] [rbp+8h]

  v1 = this;
  if ( this->m_assigned.m_bool )
  {
    hkErrStream::hkErrStream(&v11, &buf, 512);
    hkOstream::operator<<(
      (hkOstream *)&v11.vfptr,
      "Converting DataObjectArray from 32-bit to 64-bit. If this is intended, always use 64-bit values");
    hkError::messageWarning(899277293, &buf, "Data\\Dict\\hkDataObjectDict.cpp", 1506);
    hkOstream::~hkOstream((hkOstream *)&v11.vfptr);
  }
  v2 = v1->m_int32Array.m_size;
  v3 = v1->m_int64Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v3 < v2 )
  {
    v4 = 2 * v3;
    v5 = v1->m_int32Array.m_size;
    if ( v2 < v4 )
      v5 = v4;
    hkArrayUtil::_reserve(&result, v1->m_world->m_allocator, &v1->m_int64Array, v5, 8);
  }
  v1->m_int64Array.m_size = v2;
  v6 = 0;
  if ( v1->m_int32Array.m_size > 0 )
  {
    v7 = 0i64;
    v8 = 0i64;
    do
    {
      ++v6;
      ++v8;
      ++v7;
      v1->m_int64Array.m_data[v7 - 1] = v1->m_int32Array.m_data[v8 - 1];
    }
    while ( v6 < v1->m_int32Array.m_size );
  }
  v9 = v1->m_int32Array.m_capacityAndFlags;
  v10 = v1->m_world->m_allocator;
  v1->m_int32Array.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, v1->m_int32Array.m_data, 4 * v9);
  v1->m_int32Array.m_data = 0i64;
  v1->m_int32Array.m_capacityAndFlags = 2147483648;
  v1->m_arrayType = 1;
}

// File Line: 1519
// RVA: 0xE464B0
void __fastcall VariableIntArrayImplementation::setInt64(VariableIntArrayImplementation *this, int index, __int64 val)
{
  __int64 v3; // rdi
  __int64 v4; // rsi
  VariableIntArrayImplementation *v5; // rbx

  v3 = val;
  v4 = index;
  v5 = this;
  if ( this->m_arrayType != 1 )
    VariableIntArrayImplementation::_reallocateArray(this);
  v5->m_assigned.m_bool = 1;
  v5->m_int64Array.m_data[v4] = v3;
}

// File Line: 1531
// RVA: 0xE45FD0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const __int64 *in, int size)
{
  const __int64 *v3; // rdi
  int v4; // ebp
  VariableIntArrayImplementation *v5; // rsi
  int i; // ebx

  v3 = in;
  v4 = size;
  v5 = this;
  this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, size);
  for ( i = 0; i < v4; ++v3 )
    ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, const __int64))v5->vfptr[20].__vecDelDtor)(
      v5,
      (unsigned int)i++,
      *v3);
}

// File Line: 1545
// RVA: 0xE45EE0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const int *in, int size)
{
  int v3; // esi
  const int *v4; // rbp
  VariableIntArrayImplementation *v5; // rdi
  hkDataWorldDict *v6; // rax
  int v7; // er8
  hkMemoryAllocator *v8; // rcx
  signed __int64 v9; // rbx
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // er8
  _DWORD *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = size;
  v4 = in;
  v5 = this;
  if ( this->m_arrayType )
  {
    v6 = this->m_world;
    this->m_arrayType = 0;
    v7 = this->m_int64Array.m_capacityAndFlags;
    v8 = v6->m_allocator;
    v5->m_int64Array.m_size = 0;
    if ( v7 >= 0 )
      v8->vfptr->bufFree(v8, v5->m_int64Array.m_data, 8 * v7);
    v5->m_int64Array.m_data = 0i64;
    v5->m_int64Array.m_capacityAndFlags = 2147483648;
  }
  v9 = (signed __int64)&v5->m_int32Array;
  v10 = v5->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v3 )
  {
    v11 = 2 * v10;
    v12 = v3;
    if ( v3 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, v5->m_world->m_allocator, &v5->m_int32Array, v12, 4);
  }
  v13 = v3 - v5->m_int32Array.m_size;
  v14 = (_DWORD *)(*(_QWORD *)v9 + 4i64 * v5->m_int32Array.m_size);
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14 = 0;
      ++v14;
      --v15;
    }
  }
  *(_DWORD *)(v9 + 8) = v3;
  hkString::memCpy(*(void **)v9, v4, 4 * v3);
}

// File Line: 1556
// RVA: 0xE45FC0
void __fastcall UFG::CharacterSubjectComponent::ContainsPlayer(VariableIntArrayImplementation *this, const unsigned int *in, __int64 size)
{
  ((void (__fastcall *)(VariableIntArrayImplementation *, const unsigned int *, __int64))this->vfptr[32].__vecDelDtor)(
    this,
    in,
    size);
}

// File Line: 1561
// RVA: 0xE45CE0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const __int16 *in, int size)
{
  int v3; // ebx
  int v4; // er14
  const __int16 *v5; // rbp
  VariableIntArrayImplementation *v6; // rsi
  hkDataWorldDict *v7; // rax
  int v8; // er8
  hkMemoryAllocator *v9; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = 0;
  v4 = size;
  v5 = in;
  v6 = this;
  if ( this->m_arrayType )
  {
    v7 = this->m_world;
    this->m_arrayType = 0;
    v8 = this->m_int64Array.m_capacityAndFlags;
    v9 = v7->m_allocator;
    v6->m_int64Array.m_size = 0;
    if ( v8 >= 0 )
      v9->vfptr->bufFree(v9, v6->m_int64Array.m_data, 8 * v8);
    v6->m_int64Array.m_data = 0i64;
    v6->m_int64Array.m_capacityAndFlags = 2147483648;
  }
  v10 = v6->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v4 )
  {
    v11 = 2 * v10;
    v12 = v4;
    if ( v4 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, v6->m_world->m_allocator, &v6->m_int32Array, v12, 4);
  }
  v13 = v4 - v6->m_int32Array.m_size;
  v14 = &v6->m_int32Array.m_data[v6->m_int32Array.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14 = 0;
      ++v14;
      --v15;
    }
  }
  v6->m_int32Array.m_size = v4;
  if ( v4 > 0 )
  {
    do
    {
      ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, _QWORD))v6->vfptr[18].__vecDelDtor)(
        v6,
        (unsigned int)v3++,
        (unsigned int)*v5);
      ++v5;
    }
    while ( v3 < v4 );
  }
}

// File Line: 1575
// RVA: 0xE45DE0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const unsigned __int16 *in, int size)
{
  int v3; // ebx
  int v4; // er14
  const unsigned __int16 *v5; // rbp
  VariableIntArrayImplementation *v6; // rsi
  hkDataWorldDict *v7; // rax
  int v8; // er8
  hkMemoryAllocator *v9; // rcx
  int v10; // eax
  int v11; // eax
  int v12; // er9
  int v13; // edx
  int *v14; // rdi
  __int64 v15; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = 0;
  v4 = size;
  v5 = in;
  v6 = this;
  if ( this->m_arrayType )
  {
    v7 = this->m_world;
    this->m_arrayType = 0;
    v8 = this->m_int64Array.m_capacityAndFlags;
    v9 = v7->m_allocator;
    v6->m_int64Array.m_size = 0;
    if ( v8 >= 0 )
      v9->vfptr->bufFree(v9, v6->m_int64Array.m_data, 8 * v8);
    v6->m_int64Array.m_data = 0i64;
    v6->m_int64Array.m_capacityAndFlags = 2147483648;
  }
  v10 = v6->m_int32Array.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v4 )
  {
    v11 = 2 * v10;
    v12 = v4;
    if ( v4 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, v6->m_world->m_allocator, &v6->m_int32Array, v12, 4);
  }
  v13 = v4 - v6->m_int32Array.m_size;
  v14 = &v6->m_int32Array.m_data[v6->m_int32Array.m_size];
  v15 = v13;
  if ( v13 > 0 )
  {
    while ( v15 )
    {
      *v14 = 0;
      ++v14;
      --v15;
    }
  }
  v6->m_int32Array.m_size = v4;
  if ( v4 > 0 )
  {
    do
    {
      ((void (__fastcall *)(VariableIntArrayImplementation *, _QWORD, _QWORD))v6->vfptr[18].__vecDelDtor)(
        v6,
        (unsigned int)v3++,
        *v5);
      ++v5;
    }
    while ( v3 < v4 );
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
void __fastcall ByteArrayImplementation::setInt(ByteArrayImplementation *this, int i, int val)
{
  this->m_data.m_data[i] = val;
}

// File Line: 1622
// RVA: 0xE42EB0
hkResult *__fastcall ByteArrayImplementation::asStridedBasicArray(ByteArrayImplementation *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  int v3; // eax
  char *v4; // rax
  hkResult *v5; // rax

  arrOut->m_type = 4;
  v3 = this->m_data.m_size;
  result->m_enum = 0;
  arrOut->m_size = v3;
  v4 = this->m_data.m_data;
  arrOut->m_tupleSize = 1;
  arrOut->m_data = v4;
  v5 = result;
  arrOut->m_stride = 1;
  return v5;
}

// File Line: 1633
// RVA: 0xE45BD0
void __fastcall ByteArrayImplementation::setAll(ByteArrayImplementation *this, const char *vals, int n)
{
  void **v3; // rdi
  int v4; // ebx
  int v5; // eax
  const char *v6; // rsi
  int v7; // eax
  int v8; // er9
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = (void **)&this->m_data.m_data;
  v4 = n;
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = vals;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = n;
    if ( n < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, v3, v8, 1);
  }
  *((_DWORD *)v3 + 2) = v4;
  hkString::memCpy(*v3, v6, v4);
}

// File Line: 1651
// RVA: 0xE46E30
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::View::swizzleObjectMember(ArrayOfTuplesImplementation::View *this, const char *name)
{
  ArrayOfTuplesImplementation::View *v2; // rbx
  hkDataRefCountedVtbl *v3; // rdi
  _QWORD **v4; // rax
  hkDataArrayImpl *result; // rax
  int v6; // ecx

  v2 = this;
  v3 = (hkDataRefCountedVtbl *)this->m_owner->vfptr[10].__vecDelDtor(
                                 (hkDataRefCounted *)this->m_owner,
                                 (unsigned int)name);
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
  if ( !result )
    return 0i64;
  v6 = v2->m_baseIndex;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&ArrayOfTuplesImplementation::View::`vftable;
  result[1].vfptr = v3;
  *(_DWORD *)&result[1].m_memSize = v6;
  return result;
}

// File Line: 1657
// RVA: 0xE44830
hkTypeManager::Type *__fastcall ArrayOfTuplesImplementation::View::getType(ArrayOfTuplesImplementation::View *this)
{
  return *(hkTypeManager::Type **)(((__int64 (*)(void))this->m_owner->vfptr[1].__vecDelDtor)() + 8);
}

// File Line: 1665
// RVA: 0xE44200
hkDataClassImpl *__fastcall ArrayOfTuplesImplementation::View::getClass(ArrayOfTuplesImplementation::View *this)
{
  ArrayOfTuplesImplementation::View *v1; // rdi
  hkTypeManager::Type *v2; // rax
  hkBaseObjectVtbl *v3; // rbx
  const char *v4; // rax

  v1 = this;
  v2 = (hkTypeManager::Type *)((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  if ( v2->m_subType != 6 )
    return 0i64;
  v3 = v1->m_owner->m_world->vfptr;
  v4 = hkTypeManager::Type::getTypeName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v3[4].__first_virtual_table_function__)(
                              v1->m_owner->m_world,
                              v4);
}

// File Line: 1681
// RVA: 0xE43AF0
void __fastcall ArrayOfTuplesImplementation::View::clear(ArrayOfTuplesImplementation::View *this)
{
  ((void (*)(void))this->m_owner->m_impl->vfptr[2].__vecDelDtor)();
}

// File Line: 1693
// RVA: 0xE44630
int __fastcall ArrayOfTuplesImplementation::View::getSize(ArrayOfTuplesImplementation::View *this)
{
  hkTypeManager::Type *v1; // rax

  v1 = (hkTypeManager::Type *)((__int64 (*)(void))this->m_owner->vfptr[1].__vecDelDtor)();
  return hkTypeManager::Type::getTupleSize(v1);
}

// File Line: 1700
// RVA: 0xE460E0
void __fastcall ArrayOfTuplesImplementation::View::setAll(ArrayOfTuplesImplementation::View *this, const char *v, int n)
{
  int v3; // edi
  const char *v4; // r14
  ArrayOfTuplesImplementation::View *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // rbp

  if ( n > 0 )
  {
    v3 = 0;
    v4 = v;
    v5 = this;
    v6 = 0i64;
    v7 = n;
    do
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->m_owner->m_impl->vfptr[18].__vecDelDtor)(
        v5->m_owner->m_impl,
        (unsigned int)(v3++ + v5->m_baseIndex),
        (unsigned __int8)v4[v6++]);
    while ( v6 < v7 );
  }
}

// File Line: 1708
// RVA: 0xE461E0
void __fastcall ArrayOfTuplesImplementation::View::setAll(ArrayOfTuplesImplementation::View *this, const float *v, int n)
{
  int v3; // edi
  const float *v4; // r14
  ArrayOfTuplesImplementation::View *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // rbp
  __int128 v8; // xmm2

  if ( n > 0 )
  {
    v3 = 0;
    v4 = v;
    v5 = this;
    v6 = 0i64;
    v7 = n;
    do
    {
      v8 = LODWORD(v4[v6]);
      v5->m_owner->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v5->m_owner->m_impl, v3 + v5->m_baseIndex);
      ++v6;
      ++v3;
    }
    while ( v6 < v7 );
  }
}

// File Line: 1716
// RVA: 0xE46160
void __fastcall ArrayOfTuplesImplementation::View::setAll(ArrayOfTuplesImplementation::View *this, const int *v, int n)
{
  int v3; // edi
  const int *v4; // r14
  ArrayOfTuplesImplementation::View *v5; // rsi
  __int64 v6; // rbx
  __int64 v7; // rbp

  if ( n > 0 )
  {
    v3 = 0;
    v4 = v;
    v5 = this;
    v6 = 0i64;
    v7 = n;
    do
      ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->m_owner->m_impl->vfptr[18].__vecDelDtor)(
        v5->m_owner->m_impl,
        (unsigned int)(v3++ + v5->m_baseIndex),
        (unsigned int)v4[v6++]);
    while ( v6 < v7 );
  }
}

// File Line: 1729
// RVA: 0xE46D10
void __fastcall ArrayOfTuplesImplementation::View::setVec(ArrayOfTuplesImplementation::View *this, int index, const float *val)
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
                         (hkDataRefCounted *)this->m_owner->m_impl,
                         this->m_baseIndex + index);
}

// File Line: 1731
// RVA: 0xE466D0
void __fastcall ArrayOfTuplesImplementation::View::setReal(ArrayOfTuplesImplementation::View *this, int index, float val)
{
  this->m_owner->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)this->m_owner->m_impl, this->m_baseIndex + index);
}

// File Line: 1732
// RVA: 0xE46560
void __fastcall ArrayOfTuplesImplementation::View::setInt(ArrayOfTuplesImplementation::View *this, int index, __int64 val)
{
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))this->m_owner->m_impl->vfptr[18].__vecDelDtor)(
    this->m_owner->m_impl,
    (unsigned int)(this->m_baseIndex + index),
    val);
}

// File Line: 1733
// RVA: 0xE42BC0
__int64 __fastcall ArrayOfTuplesImplementation::View::asInt64(ArrayOfTuplesImplementation::View *this, int index)
{
  return this->m_owner->m_impl->vfptr[19].__vecDelDtor(
           (hkDataRefCounted *)this->m_owner->m_impl,
           this->m_baseIndex + index);
}

// File Line: 1734
// RVA: 0xE46690
void __fastcall ArrayOfTuplesImplementation::View::setObject(ArrayOfTuplesImplementation::View *this, int index, hkDataObjectImpl *val)
{
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))this->m_owner->m_impl->vfptr[22].__vecDelDtor)(
    this->m_owner->m_impl,
    (unsigned int)(this->m_baseIndex + index),
    val);
}

// File Line: 1735
// RVA: 0xE42A70
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::View::asArray(ArrayOfTuplesImplementation::View *this, int index)
{
  return (hkDataArrayImpl *)this->m_owner->m_impl->vfptr[23].__vecDelDtor(
                              (hkDataRefCounted *)this->m_owner->m_impl,
                              this->m_baseIndex + index);
}

// File Line: 1782
// RVA: 0xE46D30
ArrayOfTuplesImplementation *__fastcall ArrayOfTuplesImplementation::swizzleObjectMember(ArrayOfTuplesImplementation *this, const char *name)
{
  const char *v2; // rdi
  ArrayOfTuplesImplementation *v3; // rbx
  _QWORD **v4; // rax
  __int64 v5; // rax
  int v6; // edx
  __int64 v7; // rax
  ArrayOfTuplesImplementation *v8; // rsi
  __int64 v9; // rdi
  hkDataArrayImpl *v10; // rcx
  bool v11; // zf

  v2 = name;
  v3 = this;
  if ( !this->m_swizzle )
  {
    v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
    if ( v5 )
    {
      v6 = v3->m_tupleCount;
      *(_QWORD *)(v5 + 16) = v3->m_world;
      *(_DWORD *)(v5 + 32) = v6;
      *(_QWORD *)(v5 + 8) = 0xFFFFi64;
      *(_QWORD *)v5 = &ArrayOfTuplesImplementation::`vftable;
      *(_QWORD *)(v5 + 24) = 0i64;
      *(_QWORD *)(v5 + 40) = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
    v3->m_swizzle = (ArrayOfTuplesImplementation *)v5;
    ++*(_DWORD *)(v5 + 12);
  }
  v7 = (__int64)v3->m_impl->vfptr[10].__vecDelDtor((hkDataRefCounted *)&v3->m_impl->vfptr, (unsigned int)v2);
  v8 = v3->m_swizzle;
  v9 = v7;
  if ( v7 )
    ++*(_DWORD *)(v7 + 12);
  v10 = v8->m_impl;
  if ( v10 && (v11 = v10->m_count == 1, --v10->m_count, v11) )
  {
    v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
    v8->m_impl = (hkDataArrayImpl *)v9;
  }
  else
  {
    v8->m_impl = (hkDataArrayImpl *)v7;
  }
  return v3->m_swizzle;
}

// File Line: 1793
// RVA: 0xE447C0
hkTypeManager::Type *__fastcall ArrayOfTuplesImplementation::getType(ArrayOfTuplesImplementation *this)
{
  ArrayOfTuplesImplementation *v1; // rdi
  hkTypeManager::Type *v2; // rbx
  hkTypeManager *v3; // rax

  v1 = this;
  v2 = (hkTypeManager::Type *)((__int64 (*)(void))this->m_impl->vfptr[1].__vecDelDtor)();
  v3 = (hkTypeManager *)((__int64 (*)(void))v1->m_world->vfptr[5].__first_virtual_table_function__)();
  return hkTypeManager::makeTuple(v3, v2, v1->m_tupleCount);
}

// File Line: 1803
// RVA: 0xE441B0
hkDataClassImpl *__fastcall ArrayOfTuplesImplementation::getClass(ArrayOfTuplesImplementation *this)
{
  ArrayOfTuplesImplementation *v1; // rdi
  hkTypeManager::Type *v2; // rax
  hkBaseObjectVtbl *v3; // rbx
  const char *v4; // rax

  v1 = this;
  v2 = (hkTypeManager::Type *)((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
  if ( v2->m_subType != 6 )
    return 0i64;
  v3 = v1->m_world->vfptr;
  v4 = hkTypeManager::Type::getTypeName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v3[4].__first_virtual_table_function__)(
                              v1->m_world,
                              v4);
}

// File Line: 1818
// RVA: 0xE45620
void __fastcall ArrayOfTuplesImplementation::reserve(ArrayOfTuplesImplementation *this, int n)
{
  this->m_impl->vfptr[3].__vecDelDtor((hkDataRefCounted *)this->m_impl, n * this->m_tupleCount);
}

// File Line: 1822
// RVA: 0xE46940
void __fastcall ArrayOfTuplesImplementation::setSize(ArrayOfTuplesImplementation *this, int n)
{
  this->m_impl->vfptr[4].__vecDelDtor((hkDataRefCounted *)this->m_impl, n * this->m_tupleCount);
}

// File Line: 1826
// RVA: 0xE445D0
__int64 __fastcall ArrayOfTuplesImplementation::getSize(ArrayOfTuplesImplementation *this)
{
  return (unsigned int)(((signed int (*)(void))this->m_impl->vfptr[5].__vecDelDtor)() / this->m_tupleCount);
}

// File Line: 1831
// RVA: 0xE42920
hkDataArrayImpl *__fastcall ArrayOfTuplesImplementation::asArray(ArrayOfTuplesImplementation *this, int idx)
{
  ArrayOfTuplesImplementation *v2; // rbx
  int v3; // edi
  _QWORD **v4; // rax
  hkDataArrayImpl *result; // rax
  int v6; // edx

  v2 = this;
  v3 = idx;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
  if ( !result )
    return 0i64;
  v6 = v2->m_tupleCount;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&ArrayOfTuplesImplementation::View::`vftable;
  result[1].vfptr = (hkDataRefCountedVtbl *)v2;
  *(_DWORD *)&result[1].m_memSize = v3 * v6;
  return result;
}

// File Line: 1838
// RVA: 0xE46260
void __fastcall ArrayOfTuplesImplementation::setArray(ArrayOfTuplesImplementation *this, int idx, hkDataArrayImpl *src)
{
  ArrayOfTuplesImplementation *v3; // rdi
  hkDataArrayImpl *v4; // rsi
  int v5; // er14
  int v6; // eax
  signed __int64 v7; // rdx
  int i; // ebx
  unsigned int v9; // eax
  int j; // ebx
  int l; // ebx
  __int64 v12; // rax
  int k; // ebx
  __int64 v14; // rax
  int m; // ebx
  __int64 v16; // rax
  unsigned int v17; // ebx
  bool v18; // zf
  hkDataRefCountedVtbl *v19; // rax
  unsigned int v20; // eax
  __int64 v21; // rax

  v3 = this;
  v4 = src;
  v5 = idx * this->m_tupleCount;
  v6 = *(_DWORD *)((__int64 (__fastcall *)(hkDataArrayImpl *))src->vfptr[1].__vecDelDtor)(src) - 2;
  v7 = 5368709120i64;
  switch ( 0x40000000 )
  {
    case 0:
      for ( i = 0; i < v3->m_tupleCount; ++i )
      {
        v9 = (__int64)v4->vfptr[17].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, i);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v3->m_impl->vfptr[18].__vecDelDtor)(
          v3->m_impl,
          (unsigned int)(v5 + i),
          v9);
      }
      break;
    case 1:
      for ( j = 0; j < v3->m_tupleCount; ++j )
      {
        v4->vfptr[15].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, j);
        v3->m_impl->vfptr[16].__vecDelDtor((hkDataRefCounted *)v3->m_impl, v5 + j);
      }
      break;
    case 2:
      v17 = 0;
      if ( v3->m_tupleCount > 0 )
      {
        do
        {
          v18 = (unsigned int)v4->vfptr[39].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, v7) == 0;
          v19 = v4->vfptr;
          if ( v18 )
          {
            v20 = (__int64)v19[17].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, v17);
            ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v3->m_impl->vfptr[18].__vecDelDtor)(
              v3->m_impl,
              v5 + v17,
              v20);
          }
          else
          {
            v21 = (__int64)v19[19].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, v17);
            ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v3->m_impl->vfptr[20].__vecDelDtor)(
              v3->m_impl,
              v5 + v17,
              v21);
          }
          ++v17;
        }
        while ( (signed int)v17 < v3->m_tupleCount );
      }
      break;
    case 3:
      for ( k = 0; k < v3->m_tupleCount; ++k )
      {
        v14 = (__int64)v4->vfptr[13].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, k);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v3->m_impl->vfptr[14].__vecDelDtor)(
          v3->m_impl,
          (unsigned int)(v5 + k),
          v14);
      }
      break;
    case 4:
      for ( l = 0; l < v3->m_tupleCount; ++l )
      {
        v12 = (__int64)v4->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, l);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v3->m_impl->vfptr[22].__vecDelDtor)(
          v3->m_impl,
          (unsigned int)(v5 + l),
          v12);
      }
      break;
    case 5:
      for ( m = 0; m < v3->m_tupleCount; ++m )
      {
        v16 = (__int64)v4->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, m);
        ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v3->m_impl->vfptr[22].__vecDelDtor)(
          v3->m_impl,
          (unsigned int)(v5 + m),
          v16);
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
hkResult *__fastcall RealArrayImplementation::asStridedBasicArray(RealArrayImplementation *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  float *v3; // rax

  v3 = this->m_data.m_data;
  result->m_enum = 0;
  arrOut->m_data = v3;
  LODWORD(v3) = this->m_data.m_size;
  arrOut->m_stride = 4;
  arrOut->m_size = (signed int)v3;
  arrOut->m_type = 11;
  arrOut->m_tupleSize = 1;
  return result;
}

// File Line: 1915
// RVA: 0xE45C40
void __fastcall RealArrayImplementation::setAll(RealArrayImplementation *this, const float *vals, int n)
{
  void **v3; // rdi
  int v4; // ebx
  int v5; // eax
  const float *v6; // rsi
  int v7; // eax
  int v8; // er9
  hkResult result; // [rsp+50h] [rbp+18h]

  v3 = (void **)&this->m_data.m_data;
  v4 = n;
  v5 = this->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = vals;
  if ( v5 < n )
  {
    v7 = 2 * v5;
    v8 = n;
    if ( n < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, this->m_world->m_allocator, v3, v8, 4);
  }
  *((_DWORD *)v3 + 2) = v4;
  hkString::memCpy(*v3, v6, 4 * v4);
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
  return *(hkTypeManager::Type **)(((__int64 (*)(void))this->m_world->vfptr[5].__first_virtual_table_function__)() + 48);
}

// File Line: 1947
// RVA: 0xE42F10
hkResult *__fastcall RealArrayView::asStridedBasicArray(RealArrayView *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  float *v3; // rax

  v3 = this->m_data;
  result->m_enum = 0;
  arrOut->m_data = v3;
  LODWORD(v3) = this->m_size;
  arrOut->m_stride = 4;
  arrOut->m_size = (signed int)v3;
  arrOut->m_tupleSize = 1;
  arrOut->m_type = 11;
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
  VecArrayImplementation *v3; // rbp
  const float *v4; // rsi
  __int64 v5; // r14
  signed __int64 v6; // rbx
  int v7; // eax
  signed __int64 v8; // r11
  float *v9; // r10
  unsigned __int64 v10; // rax
  float *v11; // rcx
  char *v12; // r8
  unsigned __int64 v13; // rdx
  int v14; // eax
  const float *v15; // rdx
  signed __int64 v16; // r8
  signed __int64 v17; // r11
  int v18; // eax

  v3 = this;
  v4 = val;
  v5 = index;
  v6 = 0i64;
  v7 = hkTypeManager::Type::getTupleSize(this->m_type);
  v8 = v7;
  if ( v7 >= 4i64 )
  {
    v9 = v3->m_data.m_data;
    v10 = 4 * v7 * v5;
    v11 = &v9[v10 / 4];
    v12 = (char *)((char *)&v4[v10 / 0xFFFFFFFFFFFFFFFCui64] - (char *)v9);
    v13 = ((unsigned __int64)(v8 - 4) >> 2) + 1;
    v6 = 4 * v13;
    do
    {
      v14 = *(_DWORD *)((char *)v11 + (_QWORD)v12);
      v11 += 4;
      *((_DWORD *)v11 - 4) = v14;
      *(v11 - 3) = *(float *)((char *)v11 + (_QWORD)v12 - 12);
      *(v11 - 2) = *(float *)((char *)v11 + (_QWORD)v4 + 4 * (2 - v8 * v5) - (_QWORD)v9 - 16);
      *(v11 - 1) = *(float *)((char *)v11 + (_QWORD)v4 + 4 * (3 - v8 * v5) - (_QWORD)v9 - 16);
      --v13;
    }
    while ( v13 );
  }
  if ( v6 < v8 )
  {
    v15 = &v4[v6];
    v16 = (char *)&v3->m_data.m_data[v8 * v5] - (char *)v4;
    v17 = v8 - v6;
    do
    {
      v18 = *(_DWORD *)v15;
      ++v15;
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
  VecArrayImplementation *v2; // rdi
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = n * hkTypeManager::Type::getTupleSize(this->m_type);
  v4 = v2->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v5 = 2 * v4;
    if ( v3 < v5 )
      v3 = v5;
    hkArrayUtil::_reserve(&result, v2->m_world->m_allocator, &v2->m_data, v3, 4);
  }
}

// File Line: 2006
// RVA: 0xE46AD0
void __fastcall VecArrayImplementation::setSize(VecArrayImplementation *this, int n)
{
  VecArrayImplementation *v2; // rbp
  int v3; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // ecx
  int v8; // er9
  int v9; // edx
  float *v10; // rdi
  __int64 v11; // rcx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  v3 = n;
  v4 = hkTypeManager::Type::getTupleSize(this->m_type);
  v5 = v2->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = v3 * v4;
  if ( v5 < v3 * v4 )
  {
    v7 = 2 * v5;
    v8 = v3 * v4;
    if ( v6 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, v2->m_world->m_allocator, &v2->m_data, v8, 4);
  }
  v9 = v6 - v2->m_data.m_size;
  v10 = &v2->m_data.m_data[v2->m_data.m_size];
  v11 = v9;
  if ( v9 > 0 )
  {
    while ( v11 )
    {
      *v10 = 0.0;
      ++v10;
      --v11;
    }
  }
  v2->m_data.m_size = v6;
}

// File Line: 2009
// RVA: 0xE44610
__int64 __fastcall VecArrayImplementation::getSize(VecArrayImplementation *this)
{
  int v1; // ebx

  v1 = this->m_data.m_size;
  return (unsigned int)(v1 / hkTypeManager::Type::getTupleSize(this->m_type));
}

// File Line: 2012
// RVA: 0xE429D0
hkDataArrayImpl *__fastcall VecArrayImplementation::asArray(VecArrayImplementation *this, int index)
{
  VecArrayImplementation *v2; // rbx
  int v3; // esi
  int v4; // edi
  _QWORD **v5; // rax
  hkDataArrayImpl *result; // rax
  signed __int64 v7; // r8
  hkDataRefCountedVtbl *v8; // rcx

  v2 = this;
  v3 = index;
  v4 = hkTypeManager::Type::getTupleSize(this->m_type);
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 40i64);
  if ( !result )
    return 0i64;
  v7 = (signed __int64)&v2->m_data.m_data[v3 * v4];
  v8 = (hkDataRefCountedVtbl *)v2->m_world;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result->vfptr = (hkDataRefCountedVtbl *)&RealArrayView::`vftable;
  *(_QWORD *)&result[1].m_memSize = v7;
  result[1].vfptr = v8;
  LODWORD(result[2].vfptr) = v4;
  return result;
}

// File Line: 2018
// RVA: 0xE46030
void __fastcall VecArrayImplementation::setAll(VecArrayImplementation *this, const float *data, int size)
{
  VecArrayImplementation *v3; // rbp
  int v4; // edi
  const float *v5; // r14
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // ecx
  int v10; // er9
  int v11; // er8
  float *v12; // rdi
  __int64 v13; // rcx
  hkResult result; // [rsp+60h] [rbp+18h]

  v3 = this;
  v4 = size;
  v5 = data;
  v6 = hkTypeManager::Type::getTupleSize(this->m_type);
  v7 = v3->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v4 * v6;
  if ( v7 < v4 * v6 )
  {
    v9 = 2 * v7;
    v10 = v4 * v6;
    if ( v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, v3->m_world->m_allocator, &v3->m_data, v10, 4);
  }
  v11 = v8 - v3->m_data.m_size;
  v12 = &v3->m_data.m_data[v3->m_data.m_size];
  v13 = v11;
  if ( v11 > 0 )
  {
    while ( v13 )
    {
      *v12 = 0.0;
      ++v12;
      --v13;
    }
  }
  v3->m_data.m_size = v8;
  hkString::memCpy(v3->m_data.m_data, v5, 4 * v8);
}

// File Line: 2041
// RVA: 0xE42FA0
hkResult *__fastcall VecArrayImplementation::asStridedBasicArray(VecArrayImplementation *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  VecArrayImplementation *v3; // rdi
  hkStridedBasicArray *v4; // rsi
  int v5; // ebx
  hkResult *v6; // r14
  int v7; // eax

  v3 = this;
  v4 = arrOut;
  arrOut->m_data = this->m_data.m_data;
  v5 = this->m_data.m_size;
  v6 = result;
  arrOut->m_size = v5 / hkTypeManager::Type::getTupleSize(this->m_type);
  v7 = hkTypeManager::Type::getTupleSize(v3->m_type);
  v4->m_type = 11;
  v4->m_stride = 4 * v7;
  v4->m_tupleSize = hkTypeManager::Type::getTupleSize(v3->m_type);
  v6->m_enum = 0;
  return v6;
}

// File Line: 2054
// RVA: 0xE40750
hkDataRefCountedVtbl *__fastcall hkRealArrayImplementation_getReals(hkDataArrayImpl *arrayIn, int numReals)
{
  hkDataRefCountedVtbl *result; // rax

  if ( *(_DWORD *)&arrayIn[1].m_memSize < numReals )
    result = 0i64;
  else
    result = arrayIn[1].vfptr;
  return result;
}

// File Line: 2073
// RVA: 0xE411E0
void __fastcall PointerArrayImplementation::~PointerArrayImplementation(PointerArrayImplementation *this)
{
  int v1; // edi
  PointerArrayImplementation *v2; // rbx
  __int64 v3; // rsi
  hkDataObjectImpl *v4; // rcx
  bool v5; // zf
  int v6; // er8
  hkMemoryAllocator *v7; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&PointerArrayImplementation::`vftable;
  v2 = this;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_data.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_count-- == 1;
        if ( v5 )
          v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_data.m_size );
  }
  v2->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<hkDataObjectImpl *>::`vftable;
  v6 = v2->m_data.m_capacityAndFlags;
  v7 = v2->m_world->m_allocator;
  v2->m_data.m_size = 0;
  if ( v6 >= 0 )
    v7->vfptr->bufFree(v7, v2->m_data.m_data, 8 * v6);
  v2->m_data.m_data = 0i64;
  v2->m_data.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
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
  CstringArrayImplementation *v2; // rbx
  __int64 v3; // rdi
  int v4; // er8
  hkMemoryAllocator *v5; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&CstringArrayImplementation::`vftable;
  v2 = this;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkString::strFree(v2->m_data.m_data[v3]);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_data.m_size );
  }
  v2->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<char *>::`vftable;
  v4 = v2->m_data.m_capacityAndFlags;
  v5 = v2->m_world->m_allocator;
  v2->m_data.m_size = 0;
  if ( v4 >= 0 )
    v5->vfptr->bufFree(v5, v2->m_data.m_data, 8 * v4);
  v2->m_data.m_data = 0i64;
  v2->m_data.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2107
// RVA: 0xE46B70
void __fastcall CstringArrayImplementation::setString(CstringArrayImplementation *this, int i, const char *val)
{
  CstringArrayImplementation *v3; // rbx
  signed __int64 v4; // rdi
  const char *v5; // rsi

  v3 = this;
  v4 = i;
  v5 = val;
  hkString::strFree(this->m_data.m_data[i]);
  if ( v5 )
    v3->m_data.m_data[v4] = hkString::strDup(v5);
  else
    v3->m_data.m_data[v4] = 0i64;
}

// File Line: 2123
// RVA: 0xE41070
void __fastcall ArrayArrayImplementation::~ArrayArrayImplementation(ArrayArrayImplementation *this)
{
  int v1; // edi
  ArrayArrayImplementation *v2; // rbx
  __int64 v3; // rsi
  hkDataArrayImpl *v4; // rcx
  bool v5; // zf
  int v6; // er8
  hkMemoryAllocator *v7; // rcx

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&ArrayArrayImplementation::`vftable;
  v2 = this;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_data.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_count-- == 1;
        if ( v5 )
          v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_data.m_size );
  }
  v2->vfptr = (hkDataRefCountedVtbl *)&BasicArrayImplementation<hkDataArrayImpl *>::`vftable;
  v6 = v2->m_data.m_capacityAndFlags;
  v7 = v2->m_world->m_allocator;
  v2->m_data.m_size = 0;
  if ( v6 >= 0 )
    v7->vfptr->bufFree(v7, v2->m_data.m_data, 8 * v6);
  v2->m_data.m_data = 0i64;
  v2->m_data.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
}

// File Line: 2128
// RVA: 0xE439D0
void __fastcall ArrayArrayImplementation::clear(ArrayArrayImplementation *this)
{
  int v1; // ebx
  ArrayArrayImplementation *v2; // rsi
  __int64 v3; // rdi
  hkDataArrayImpl *v4; // rcx
  bool v5; // zf

  v1 = 0;
  v2 = this;
  if ( this->m_data.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_data.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_count-- == 1;
        if ( v5 )
          v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
      }
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_data.m_size );
  }
}

// File Line: 2139
// RVA: 0xE46580
void __fastcall PointerArrayImplementation::setObject(PointerArrayImplementation *this, int i, hkDataObjectImpl *val)
{
  hkDataObjectImpl *v3; // rbx
  PointerArrayImplementation *v4; // rdi
  signed __int64 v5; // rsi
  hkDataObjectImpl **v6; // rax
  hkDataObjectImpl *v7; // rcx
  bool v8; // zf

  v3 = val;
  v4 = this;
  if ( val )
    ++val->m_count;
  v5 = i;
  v6 = this->m_data.m_data;
  v7 = v6[v5];
  if ( v7 )
  {
    v8 = v7->m_count-- == 1;
    if ( v8 )
      v7->vfptr->__vecDelDtor((hkDataRefCounted *)&v7->vfptr, 1u);
    v6 = v4->m_data.m_data;
  }
  v6[v5] = v3;
}

// File Line: 2151
// RVA: 0xE46870
void __fastcall ArrayArrayImplementation::setSize(ArrayArrayImplementation *this, int n)
{
  int v2; // ebp
  ArrayArrayImplementation *v3; // rsi
  int v4; // edi
  signed __int64 v5; // rbx
  hkDataArrayImpl *v6; // rcx
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int v10; // er9
  int v11; // edx
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = n;
  v3 = this;
  if ( n < this->m_data.m_size )
  {
    v4 = n;
    v5 = n;
    do
    {
      v6 = v3->m_data.m_data[v5];
      if ( v6 )
      {
        v7 = v6->m_count-- == 1;
        if ( v7 )
          v6->vfptr->__vecDelDtor((hkDataRefCounted *)&v6->vfptr, 1u);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->m_data.m_size );
  }
  v8 = v3->m_data.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v2 )
  {
    v9 = 2 * v8;
    v10 = v2;
    if ( v2 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, v3->m_world->m_allocator, &v3->m_data, v10, 8);
  }
  v11 = v2 - v3->m_data.m_size;
  if ( v11 > 0 )
    memset(&v3->m_data.m_data[v3->m_data.m_size], 0, 8i64 * v11);
  v3->m_data.m_size = v2;
}

// File Line: 2167
// RVA: 0xE428C0
void __fastcall ArrayArrayImplementation::asArray(ArrayArrayImplementation *this, int i)
{
  ArrayArrayImplementation *v2; // rbx
  __int64 v3; // rdi
  hkDataArrayImpl *v4; // rax

  v2 = this;
  v3 = i;
  if ( !this->m_data.m_data[v3] )
  {
    hkDataArrayDict_create(this->m_world, this->m_type->m_parent, 0);
    ++v4->m_count;
    v2->m_data.m_data[v3] = v4;
  }
}

// File Line: 2234
// RVA: 0xE41FF0
signed __int64 __fastcall StructArrayImplementation::_find(StructArrayImplementation *this, const char *nameIn)
{
  unsigned int v2; // edi
  const char *v3; // rbp
  hkDataWorldDict::ObjectTracker *v4; // r14
  StructArrayImplementation *v5; // rsi
  char *v6; // rbx
  __int64 v7; // rdx
  __int64 v8; // rcx
  StructArrayImplementation::MemberData *v9; // rax

  v2 = 0;
  v3 = nameIn;
  v4 = this->m_class.m_pntr->m_world->m_tracker;
  v5 = this;
  if ( nameIn )
  {
    v6 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_interns,
                   (unsigned __int64)nameIn,
                   0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(v3);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v4->m_interns.m_map,
        (unsigned __int64)v6,
        (unsigned __int64)v6);
    }
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v5->m_memberData.m_size;
  v8 = 0i64;
  if ( v7 <= 0 )
    return 0xFFFFFFFFi64;
  v9 = v5->m_memberData.m_data;
  while ( v9->m_memberName.m_cachedString != v6 )
  {
    ++v8;
    ++v2;
    ++v9;
    if ( v8 >= v7 )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 2240
// RVA: 0xE41DA0
signed __int64 __fastcall StructArrayImplementation::_addMember(StructArrayImplementation *this, hkDataClassDict::MemberInfo *mi, int size)
{
  int v3; // er12
  hkDataClassDict::MemberInfo *v4; // r14
  StructArrayImplementation *v5; // r13
  StructArrayImplementation::MemberData *v7; // rax
  StructArrayImplementation::MemberData *v8; // rsi
  hkTypeManager::Type *v9; // r15
  hkTypeManager::Type *v10; // rax
  hkDataArrayImpl *v11; // rax
  unsigned int v12; // edi
  hkTypeManager::SubType v13; // ecx
  __int128 v14; // xmm2
  hkDataClassDict *v15; // rbx
  const char *v16; // rbp
  __int64 v17; // rax
  unsigned __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rbx
  bool v21; // zf
  unsigned __int64 v22; // [rsp+58h] [rbp+10h]

  v3 = size;
  v4 = mi;
  v5 = this;
  if ( mi->m_type->m_subType == 1 )
    return 0xFFFFFFFFi64;
  if ( this->m_memberData.m_size == (this->m_memberData.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(this->m_world->m_allocator, &this->m_memberData, 16);
  v7 = &v5->m_memberData.m_data[v5->m_memberData.m_size];
  if ( v7 )
    v7->m_memberName.m_cachedString = 0i64;
  v8 = &v5->m_memberData.m_data[v5->m_memberData.m_size++];
  v8->m_memberName.m_cachedString = v4->m_name.m_cachedString;
  v9 = v4->m_type;
  v10 = hkTypeManager::Type::findTerminal(v4->m_type);
  if ( v10->m_subType == 6 )
    hkTypeManager::Type::getTypeName(v10);
  hkDataArrayDict_create(v5->m_world, v9, 0);
  v8->m_values = v11;
  ++v11->m_count;
  v8->m_values->vfptr[4].__vecDelDtor((hkDataRefCounted *)v8->m_values, v3);
  if ( v4->m_valuePtr || v9->m_subType == 6 )
  {
    v12 = 0;
    if ( v3 > 0 )
    {
      do
      {
        v13 = v9->m_subType;
        if ( (v9->m_subType - 2) & 0xFFFFFFFD )
        {
          switch ( v13 )
          {
            case 3:
              v14 = *(unsigned int *)v4->m_valuePtr;
              v8->m_values->vfptr[16].__vecDelDtor((hkDataRefCounted *)v8->m_values, v12);
              break;
            case 9:
              if ( v9->m_parent->m_subType == 3 )
                ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const void *))v8->m_values->vfptr[12].__vecDelDtor)(
                  v8->m_values,
                  v12,
                  v4->m_valuePtr);
              break;
            case 6:
              v15 = v5->m_class.m_pntr;
              v16 = hkTypeManager::Type::getTypeName(v9);
              v17 = ((__int64 (__fastcall *)(hkDataClassDict *))v15->vfptr[1].__vecDelDtor)(v15);
              if ( v16 )
                v18 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)(*(_QWORD *)(v17 + 16)
                                                                                                 + 8i64),
                        (unsigned __int64)v16,
                        0i64);
              else
                v18 = 0i64;
              v22 = v18;
              v19 = ((__int64 (__fastcall *)(hkDataWorldDict *, unsigned __int64 *, _QWORD))v5->m_class.m_pntr->m_world->vfptr[2].__vecDelDtor)(
                      v5->m_class.m_pntr->m_world,
                      &v22,
                      0i64);
              v20 = v19;
              if ( v19 )
              {
                ++*(_WORD *)(v19 + 10);
                ++*(_DWORD *)(v19 + 12);
              }
              ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v8->m_values->vfptr[22].__vecDelDtor)(
                v8->m_values,
                v12,
                v19);
              if ( v20 )
              {
                --*(_WORD *)(v20 + 10);
                v21 = (*(_DWORD *)(v20 + 12))-- == 1;
                if ( v21 )
                  (**(void (__fastcall ***)(__int64, signed __int64))v20)(v20, 1i64);
              }
              break;
            case 5:
              ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const void *))v8->m_values->vfptr[14].__vecDelDtor)(
                v8->m_values,
                v12,
                v4->m_valuePtr);
              break;
          }
        }
        else
        {
          ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v8->m_values->vfptr[20].__vecDelDtor)(
            v8->m_values,
            v12,
            *(_QWORD *)v4->m_valuePtr);
        }
        ++v12;
      }
      while ( (signed int)v12 < v3 );
    }
  }
  return (unsigned int)(v5->m_memberData.m_size - 1);
}

// File Line: 2344
// RVA: 0xE420B0
signed __int64 __fastcall StructArrayImplementation::_findOrAdd(StructArrayImplementation *this, const struct _hkDataObject_MemberHandle *handle)
{
  __int64 v2; // r10
  __int64 v3; // r8
  hkDataClassDict::MemberInfo *v4; // rdi
  StructArrayImplementation *v5; // rbx
  __int64 v6; // r9
  StructArrayImplementation::MemberData *v7; // rax
  int v8; // eax

  v2 = this->m_memberData.m_size;
  v3 = 0i64;
  v4 = (hkDataClassDict::MemberInfo *)handle;
  v5 = this;
  v6 = 0i64;
  if ( v2 > 0 )
  {
    v7 = this->m_memberData.m_data;
    while ( v7->m_memberName.m_cachedString != *(const char **)handle )
    {
      ++v6;
      v3 = (unsigned int)(v3 + 1);
      ++v7;
      if ( v6 >= v2 )
        goto LABEL_5;
    }
    if ( (_DWORD)v3 != -1 )
      return (unsigned int)v3;
  }
LABEL_5:
  v8 = ((__int64 (__fastcall *)(StructArrayImplementation *, const struct _hkDataObject_MemberHandle *, __int64, __int64))this->vfptr[5].__vecDelDtor)(
         this,
         handle,
         v3,
         v6);
  return StructArrayImplementation::_addMember(v5, v4, v8);
}

// File Line: 2356
// RVA: 0xE452B0
void __fastcall StructArrayImplementation::removeMember(StructArrayImplementation *this, InternedString s)
{
  __int64 v2; // r9
  int v3; // ebx
  StructArrayImplementation *v4; // rdi
  __int64 v5; // r8
  StructArrayImplementation::MemberData *v6; // rax
  hkDataArrayImpl *v7; // rcx
  bool v8; // zf
  int v9; // edx
  signed __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rcx

  v2 = this->m_memberData.m_size;
  v3 = 0;
  v4 = this;
  v5 = 0i64;
  if ( v2 > 0 )
  {
    v6 = this->m_memberData.m_data;
    while ( v6->m_memberName.m_cachedString != s.m_cachedString )
    {
      ++v5;
      ++v3;
      ++v6;
      if ( v5 >= v2 )
        return;
    }
    v7 = v6->m_values;
    v8 = v7->m_count-- == 1;
    if ( v8 )
      ((void (__fastcall *)(hkDataArrayImpl *, signed __int64, __int64))v7->vfptr->__vecDelDtor)(v7, 1i64, v5);
    v9 = 16 * (--v4->m_memberData.m_size - v3);
    v10 = (signed __int64)&v4->m_memberData.m_data[v3];
    if ( v9 > 0 )
    {
      v11 = ((unsigned int)(v9 - 1) >> 3) + 1;
      do
      {
        v12 = *(_QWORD *)(v10 + 16);
        v10 += 8i64;
        *(_QWORD *)(v10 - 8) = v12;
        --v11;
      }
      while ( v11 );
    }
  }
}

// File Line: 2394
// RVA: 0xE42630
hkDataObject_Value *__fastcall StructArrayImplementation::Object::accessByName(StructArrayImplementation::Object *this, hkDataObject_Value *result, const char *nameIn)
{
  const char *v3; // rsi
  hkDataObject_Value *v4; // rdi
  StructArrayImplementation::Object *v5; // r14
  hkDataWorldDict::ObjectTracker *v6; // rbp
  char *v7; // rbx
  hkDataClassDict *v8; // r8
  __int64 v9; // r9
  int v10; // edx
  __int64 v11; // rcx
  char **v12; // rax
  hkDataObject_Value *v13; // rax
  signed __int64 v14; // rax

  v3 = nameIn;
  v4 = result;
  v5 = this;
  v6 = this->m_impl->m_class.m_pntr->m_world->m_tracker;
  if ( nameIn )
  {
    v7 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6->m_interns,
                   (unsigned __int64)nameIn,
                   0i64);
    if ( !v7 )
    {
      v7 = hkString::strDup(v3);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v6->m_interns.m_map,
        (unsigned __int64)v7,
        (unsigned __int64)v7);
    }
  }
  else
  {
    v7 = 0i64;
  }
  v8 = v5->m_impl->m_class.m_pntr;
  if ( !v8 )
    goto LABEL_11;
  while ( 1 )
  {
    v9 = v8->m_memberInfo.m_size;
    v10 = 0;
    v11 = 0i64;
    if ( v9 > 0 )
      break;
LABEL_10:
    v8 = v8->m_parent.m_pntr;
    if ( !v8 )
      goto LABEL_11;
  }
  v12 = (char **)v8->m_memberInfo.m_data;
  while ( *v12 != v7 )
  {
    ++v11;
    ++v10;
    v12 += 4;
    if ( v11 >= v9 )
      goto LABEL_10;
  }
  v14 = (signed __int64)&v8->m_memberInfo.m_data[v10];
  if ( v14 )
  {
    v4->m_handle = (const struct _hkDataObject_MemberHandle *)v14;
    v4->m_impl = (hkDataObjectImpl *)&v5->vfptr;
    v13 = v4;
  }
  else
  {
LABEL_11:
    v4->m_impl = 0i64;
    v4->m_handle = 0i64;
    v13 = v4;
  }
  return v13;
}

// File Line: 2409
// RVA: 0xE448A0
signed __int64 __fastcall StructArrayImplementation::Object::hasMember(StructArrayImplementation::Object *this, const char *name)
{
  StructArrayImplementation::Object *v2; // rbx
  StructArrayImplementation *v3; // rcx
  __int64 v4; // r8
  __int64 v5; // rdx
  StructArrayImplementation::MemberData *v6; // rcx
  const char *v8; // [rsp+30h] [rbp+8h]

  v2 = this;
  ((void (__fastcall *)(StructArrayImplementation::Object *, const char **, const char *))this->vfptr[30].__vecDelDtor)(
    this,
    &v8,
    name);
  v3 = v2->m_impl;
  v4 = v3->m_memberData.m_size;
  v5 = 0i64;
  if ( v4 <= 0 )
    return 0i64;
  v6 = v3->m_memberData.m_data;
  while ( v8 != v6->m_memberName.m_cachedString )
  {
    ++v5;
    ++v6;
    if ( v5 >= v4 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 2421
// RVA: 0xE44BE0
signed __int64 __fastcall StructArrayImplementation::Object::isSet(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation *v2; // rax
  __int64 v3; // rcx
  __int64 v4; // r8
  const char *v5; // rdx
  StructArrayImplementation::MemberData *v6; // rax

  v2 = this->m_impl;
  v3 = 0i64;
  v4 = v2->m_memberData.m_size;
  if ( v4 <= 0 )
    return 0i64;
  v5 = *(const char **)handle;
  v6 = v2->m_memberData.m_data;
  while ( v5 != v6->m_memberName.m_cachedString )
  {
    ++v3;
    ++v6;
    if ( v3 >= v4 )
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
const char *__fastcall StructArrayImplementation::Object::getMemberName(StructArrayImplementation::Object *this, int it)
{
  return this->m_impl->m_memberData.m_data[it].m_memberName.m_cachedString;
}

// File Line: 2459
// RVA: 0xE44550
hkDataObject_Value *__fastcall StructArrayImplementation::Object::getMemberValue(StructArrayImplementation::Object *this, hkDataObject_Value *result, int it)
{
  StructArrayImplementation *v3; // rax
  const struct _hkDataObject_MemberHandle *v4; // rcx
  hkDataObject_Value *v5; // rax

  v3 = this->m_impl;
  result->m_impl = (hkDataObjectImpl *)&this->vfptr;
  v4 = (const struct _hkDataObject_MemberHandle *)v3->m_memberData.m_data[it].m_memberName.m_cachedString;
  v5 = result;
  result->m_handle = v4;
  return v5;
}

// File Line: 2464
// RVA: 0xE44060
void __fastcall StructArrayImplementation::Object::getAllMemberHandles(StructArrayImplementation::Object *this, hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  const struct _hkDataObject_MemberHandle **v2; // r9
  hkDataClassDict *i; // r8
  __int64 v4; // rdx
  hkDataClassDict::MemberInfo *v5; // rcx
  __int64 j; // rax

  v2 = &handles->m_data[handles->m_size];
  for ( i = this->m_impl->m_class.m_pntr; i; i = i->m_parent.m_pntr )
  {
    v4 = i->m_memberInfo.m_size;
    v5 = i->m_memberInfo.m_data;
    v2 -= v4;
    for ( j = 0i64; j < v4; ++v5 )
      v2[j++] = (const struct _hkDataObject_MemberHandle *)v5;
  }
}

// File Line: 2468
// RVA: 0xE44A00
InternedString *__fastcall StructArrayImplementation::Object::intern(StructArrayImplementation::Object *this, InternedString *result, const char *name)
{
  InternedString *v3; // rbx

  v3 = result;
  hkDataWorldDict::ObjectTracker::intern(this->m_impl->m_class.m_pntr->m_world->m_tracker, result, name);
  return v3;
}

// File Line: 2476
// RVA: 0xE430C0
const float *__fastcall StructArrayImplementation::Object::asVec(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, int n)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataArrayImpl *v4; // rcx

  v3 = this;
  v4 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (const float *)v4->vfptr[11].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, v3->m_index);
}

// File Line: 2487
// RVA: 0xE43020
const char *__fastcall StructArrayImplementation::Object::asString(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (const char *)v3->vfptr[13].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2488
// RVA: 0xE42990
hkDataArrayImpl *__fastcall StructArrayImplementation::Object::asArray(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (hkDataArrayImpl *)v3->vfptr[23].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2489
// RVA: 0xE42BF0
__int64 __fastcall StructArrayImplementation::Object::asInt(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return v3->vfptr[17].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2490
// RVA: 0xE42B50
__int64 __fastcall StructArrayImplementation::Object::asInt64(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return v3->vfptr[19].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2491
// RVA: 0xE42DF0
void __fastcall StructArrayImplementation::Object::asReal(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  v3->vfptr[15].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2492
// RVA: 0xE42AD0
hkHalf *__fastcall StructArrayImplementation::Object::asHalf(StructArrayImplementation::Object *this, hkHalf *result, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v3; // rbx
  hkHalf *v4; // rdi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = result;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, hkHalf *, _QWORD))v5->vfptr[25].__vecDelDtor)(
    v5,
    v4,
    (unsigned int)v3->m_index);
  return v4;
}

// File Line: 2496
// RVA: 0xE42CD0
hkDataObjectImpl *__fastcall StructArrayImplementation::Object::asObject(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle)
{
  StructArrayImplementation::Object *v2; // rbx
  hkDataArrayImpl *v3; // rcx

  v2 = this;
  v3 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  return (hkDataObjectImpl *)v3->vfptr[21].__vecDelDtor((hkDataRefCounted *)&v3->vfptr, v2->m_index);
}

// File Line: 2502
// RVA: 0xE431B0
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, hkDataObject_Value *valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataObject_Value *v4; // rdi
  int v5; // eax

  v3 = this;
  v4 = valueIn;
  v5 = StructArrayImplementation::_findOrAdd(this->m_impl, handle);
  hkDataArrayImpl::set(v3->m_impl->m_memberData.m_data[v5].m_values, v3->m_index, v4);
}

// File Line: 2508
// RVA: 0xE43390
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, hkDataObjectImpl *valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataObjectImpl *v4; // rdi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataObjectImpl *))v5->vfptr[22].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2514
// RVA: 0xE43340
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, hkDataArrayImpl *valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataArrayImpl *v4; // rdi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, hkDataArrayImpl *))v5->vfptr[24].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2520
// RVA: 0xE433E0
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, const char *valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  const char *v4; // rdi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const char *))v5->vfptr[14].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2526
// RVA: 0xE432F0
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, float valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataArrayImpl *v4; // rcx

  v3 = this;
  v4 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  v4->vfptr[16].__vecDelDtor((hkDataRefCounted *)&v4->vfptr, v3->m_index);
}

// File Line: 2532
// RVA: 0xE43480
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, hkHalf valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  hkDataArrayImpl *v4; // rcx
  unsigned __int16 v5; // [rsp+40h] [rbp+18h]

  v5 = valueIn.m_value;
  v3 = this;
  v4 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v4->vfptr[26].__vecDelDtor)(
    v4,
    (unsigned int)v3->m_index,
    v5);
}

// File Line: 2538
// RVA: 0xE43430
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, const float *valueIn, int nreal)
{
  StructArrayImplementation::Object *v4; // rbx
  const float *v5; // rdi
  hkDataArrayImpl *v6; // rcx

  v4 = this;
  v5 = valueIn;
  v6 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, const float *))v6->vfptr[12].__vecDelDtor)(
    v6,
    (unsigned int)v4->m_index,
    v5);
}

// File Line: 2544
// RVA: 0xE43200
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, char valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  unsigned int v4; // edi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->vfptr[18].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2550
// RVA: 0xE43250
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, __int16 valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  unsigned int v4; // edi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->vfptr[18].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2556
// RVA: 0xE432A0
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, int valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  unsigned int v4; // edi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, _QWORD))v5->vfptr[18].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2562
// RVA: 0xE434D0
void __fastcall StructArrayImplementation::Object::assign(StructArrayImplementation::Object *this, const struct _hkDataObject_MemberHandle *handle, __int64 valueIn)
{
  StructArrayImplementation::Object *v3; // rbx
  __int64 v4; // rdi
  hkDataArrayImpl *v5; // rcx

  v3 = this;
  v4 = valueIn;
  v5 = this->m_impl->m_memberData.m_data[(signed int)StructArrayImplementation::_findOrAdd(this->m_impl, handle)].m_values;
  ((void (__fastcall *)(hkDataArrayImpl *, _QWORD, __int64))v5->vfptr[20].__vecDelDtor)(
    v5,
    (unsigned int)v3->m_index,
    v4);
}

// File Line: 2568
// RVA: 0xE44500
void __fastcall hkDataObjectDict::getMemberInfo(hkDataObjectDict *this, const struct _hkDataObject_MemberHandle *handle, hkDataClass_MemberInfo *infoOut)
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
void __fastcall StructArrayImplementation::StructArrayImplementation(StructArrayImplementation *this, hkDataWorldDict *world, hkTypeManager::Type *type, hkDataClassDict *klass, int size)
{
  signed int v5; // esi
  StructArrayImplementation *v6; // rbx
  hkDataClassDict *v7; // rdi
  int v8; // ecx
  hkDataClassDict *v9; // rax
  hkDataClassDict::MemberInfo *v10; // rdx

  v5 = 0;
  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  this->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::`vftable;
  v6 = this;
  this->m_memberData.m_data = 0i64;
  this->m_memberData.m_size = 0;
  this->m_memberData.m_capacityAndFlags = 2147483648;
  if ( klass )
    ++klass->m_count;
  this->m_class.m_pntr = klass;
  this->m_type = type;
  this->m_size = size;
  this->m_world = world;
  if ( ((signed int (__fastcall *)(hkDataClassDict *))klass->vfptr[9].__vecDelDtor)(klass) > 0 )
  {
    do
    {
      v7 = v6->m_class.m_pntr;
      v8 = v5 - (unsigned __int64)((__int64 (__fastcall *)(hkDataClassDict *))v7->vfptr[9].__vecDelDtor)(v7);
      v9 = v7;
      while ( 1 )
      {
        v8 += v9->m_memberInfo.m_size;
        if ( v8 >= 0 )
          break;
        v9 = v9->m_parent.m_pntr;
        if ( !v9 )
        {
          v10 = v7->m_memberInfo.m_data - 1;
          goto LABEL_9;
        }
      }
      v10 = &v9->m_memberInfo.m_data[v8];
LABEL_9:
      StructArrayImplementation::_addMember(v6, v10, v6->m_size);
      ++v5;
    }
    while ( v5 < ((signed int (*)(void))v6->m_class.m_pntr->vfptr[9].__vecDelDtor)() );
  }
  hkDataWorldDict::ObjectTracker::trackStructArray(v6->m_world->m_tracker, (hkDataArrayImpl *)&v6->vfptr);
}

// File Line: 2592
// RVA: 0xE412A0
void __fastcall StructArrayImplementation::~StructArrayImplementation(StructArrayImplementation *this)
{
  int v1; // edi
  StructArrayImplementation *v2; // rbx
  __int64 v3; // rsi
  hkDataArrayImpl *v4; // rcx
  bool v5; // zf
  hkDataWorldDict::ObjectTracker *v6; // rdi
  unsigned __int64 v7; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v8; // rax
  int v9; // er8
  hkMemoryAllocator *v10; // rcx
  hkDataClassDict *v11; // rcx
  hkResult result; // [rsp+30h] [rbp+8h]

  v1 = 0;
  this->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::`vftable;
  v2 = this;
  if ( this->m_memberData.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_memberData.m_data[v3].m_values;
      v5 = v4->m_count-- == 1;
      if ( v5 )
        v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_memberData.m_size );
  }
  v6 = v2->m_world->m_tracker;
  v7 = ((__int64 (__fastcall *)(StructArrayImplementation *))v2->vfptr[6].__vecDelDtor)(v2);
  v8 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                                                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v6->m_arraysFromClass.m_map.m_elem,
                                                                                            v7,
                                                                                            0i64);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::remove(
    v8,
    &result,
    (unsigned __int64)v2);
  v9 = v2->m_memberData.m_capacityAndFlags;
  v10 = v2->m_world->m_allocator;
  v2->m_memberData.m_size = 0;
  if ( v9 >= 0 )
    v10->vfptr->bufFree(v10, v2->m_memberData.m_data, 16 * v9);
  v2->m_memberData.m_data = 0i64;
  v2->m_memberData.m_capacityAndFlags = 2147483648;
  v11 = v2->m_class.m_pntr;
  if ( v11 )
  {
    v5 = v11->m_count-- == 1;
    if ( v5 )
      v11->vfptr->__vecDelDtor((hkDataRefCounted *)&v11->vfptr, 1u);
  }
  v2->m_class.m_pntr = 0i64;
  v2->vfptr = (hkDataRefCountedVtbl *)&hkDataRefCounted::`vftable;
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
  hkDataRefCountedVtbl *v2; // rdi
  int v3; // ebx
  _QWORD **v4; // rax
  hkDataObjectImpl *result; // rax

  v2 = (hkDataRefCountedVtbl *)this;
  v3 = i;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
  if ( !result )
    return 0i64;
  *(_QWORD *)&result->m_memSize = 0xFFFFi64;
  result[1].vfptr = v2;
  result->vfptr = (hkDataRefCountedVtbl *)&StructArrayImplementation::Object::`vftable;
  *(_DWORD *)&result[1].m_memSize = v3;
  return result;
}

// File Line: 2610
// RVA: 0xE465E0
void __fastcall StructArrayImplementation::setObject(StructArrayImplementation *this, int index, hkDataObjectImpl *val)
{
  int v3; // esi
  hkDataObjectImpl *v4; // rbx
  int v5; // er15
  StructArrayImplementation *v6; // rbp
  __int64 v7; // r14
  StructArrayImplementation::MemberData *v8; // rdi
  hkDataObject_Value *v9; // rax
  bool v10; // zf
  char v11; // [rsp+20h] [rbp-28h]

  ++val->m_count;
  v3 = 0;
  v4 = val;
  v5 = index;
  v6 = this;
  if ( this->m_memberData.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->m_memberData.m_data;
      v9 = (hkDataObject_Value *)((__int64 (__fastcall *)(hkDataObjectImpl *, char *, const char *))v4->vfptr[3].__vecDelDtor)(
                                   v4,
                                   &v11,
                                   v8[v7].m_memberName.m_cachedString);
      hkDataArrayImpl::set(v8[v7].m_values, v5, v9);
      ++v3;
      ++v7;
    }
    while ( v3 < v6->m_memberData.m_size );
  }
  v10 = v4->m_count-- == 1;
  if ( v10 )
    v4->vfptr->__vecDelDtor((hkDataRefCounted *)&v4->vfptr, 1u);
}

// File Line: 2631
// RVA: 0xE43A30
void __fastcall StructArrayImplementation::clear(StructArrayImplementation *this)
{
  int v1; // edi
  StructArrayImplementation *v2; // rbx
  __int64 v3; // rsi

  v1 = 0;
  v2 = this;
  if ( this->m_memberData.m_size <= 0 )
  {
    this->m_size = 0;
  }
  else
  {
    v3 = 0i64;
    do
    {
      ((void (*)(void))v2->m_memberData.m_data[v3].m_values->vfptr[2].__vecDelDtor)();
      ++v1;
      ++v3;
    }
    while ( v1 < v2->m_memberData.m_size );
    v2->m_size = 0;
  }
}

// File Line: 2639
// RVA: 0xE45640
void __fastcall StructArrayImplementation::reserve(StructArrayImplementation *this, int n)
{
  int v2; // ebx
  unsigned int v3; // ebp
  StructArrayImplementation *v4; // rsi
  __int64 v5; // rdi
  hkDataArrayImpl *v6; // rcx

  v2 = 0;
  v3 = n;
  v4 = this;
  if ( this->m_memberData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_memberData.m_data[v5].m_values;
      v6->vfptr[3].__vecDelDtor((hkDataRefCounted *)&v6->vfptr, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_memberData.m_size );
  }
}

// File Line: 2646
// RVA: 0xE46960
void __fastcall StructArrayImplementation::setSize(StructArrayImplementation *this, int n)
{
  int v2; // ebx
  unsigned int v3; // ebp
  StructArrayImplementation *v4; // rsi
  __int64 v5; // rdi
  hkDataArrayImpl *v6; // rcx

  v2 = 0;
  v3 = n;
  v4 = this;
  this->m_size = n;
  if ( this->m_memberData.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_memberData.m_data[v5].m_values;
      v6->vfptr[4].__vecDelDtor((hkDataRefCounted *)&v6->vfptr, v3);
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_memberData.m_size );
  }
}

// File Line: 2671
// RVA: 0xE46E00
hkDataArrayImpl *__fastcall StructArrayImplementation::swizzleObjectMember(StructArrayImplementation *this, const char *name)
{
  return this->m_memberData.m_data[(signed int)StructArrayImplementation::_find(this, name)].m_values;
}

// File Line: 2679
// RVA: 0xE402C0
void __fastcall hkDataArrayDict_create(hkDataWorldDict *world, hkTypeManager::Type *t, int size)
{
  int v3; // edi
  hkTypeManager::Type *v4; // rbp
  hkDataWorldDict *v5; // rsi
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
  int v16; // eax
  _QWORD **v17; // rax
  __int64 v18; // rax
  _QWORD **v19; // rax
  __int64 v20; // rax
  _QWORD **v21; // rax
  __int64 v22; // rax
  _QWORD **v23; // rax
  __int64 v24; // rax
  hkTypeManager::Type *v25; // rdi
  hkBaseObjectVtbl *v26; // rbx
  const char *v27; // rax
  _QWORD **v28; // rax
  __int64 v29; // rax
  hkBaseObjectVtbl *v30; // rbx
  const char *v31; // rax
  hkDataClassDict *v32; // rbx
  _QWORD **v33; // rax
  StructArrayImplementation *v34; // rax
  hkDataArrayImpl *v35; // [rsp+58h] [rbp+10h]
  int v36; // [rsp+60h] [rbp+18h]

  v36 = size;
  v3 = size;
  v4 = t;
  v5 = world;
  switch ( t->m_subType )
  {
    case 2:
      v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v23[11] + 8i64))(v23[11], 48i64);
      if ( v24 )
      {
        *(_QWORD *)(v24 + 8) = 0xFFFFi64;
        *(_QWORD *)(v24 + 16) = 0i64;
        *(_DWORD *)(v24 + 24) = 0;
        *(_DWORD *)(v24 + 28) = 2147483648;
        *(_QWORD *)(v24 + 32) = v5;
        *(_QWORD *)v24 = &ByteArrayImplementation::`vftable;
        *(_QWORD *)(v24 + 40) = v4;
      }
      break;
    case 3:
      v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v22 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 48i64);
      if ( v22 )
      {
        *(_QWORD *)(v22 + 8) = 0xFFFFi64;
        *(_QWORD *)(v22 + 16) = 0i64;
        *(_DWORD *)(v22 + 24) = 0;
        *(_DWORD *)(v22 + 28) = 2147483648;
        *(_QWORD *)(v22 + 32) = v5;
        *(_QWORD *)v22 = &RealArrayImplementation::`vftable;
        *(_QWORD *)(v22 + 40) = v4;
      }
      break;
    case 4:
      v17 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v18 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v17[11] + 8i64))(v17[11], 72i64);
      if ( v18 )
      {
        *(_QWORD *)(v18 + 8) = 0xFFFFi64;
        *(_QWORD *)(v18 + 16) = v5;
        *(_DWORD *)(v18 + 24) = 0;
        *(_QWORD *)v18 = &VariableIntArrayImplementation::`vftable;
        *(_QWORD *)(v18 + 32) = 0i64;
        *(_DWORD *)(v18 + 40) = 0;
        *(_DWORD *)(v18 + 44) = 2147483648;
        *(_QWORD *)(v18 + 48) = 0i64;
        *(_DWORD *)(v18 + 56) = 0;
        *(_DWORD *)(v18 + 60) = 2147483648;
        *(_BYTE *)(v18 + 64) = 0;
      }
      break;
    case 5:
      v19 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v20 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v19[11] + 8i64))(v19[11], 48i64);
      if ( v20 )
      {
        *(_QWORD *)(v20 + 8) = 0xFFFFi64;
        *(_QWORD *)(v20 + 16) = 0i64;
        *(_DWORD *)(v20 + 24) = 0;
        *(_DWORD *)(v20 + 28) = 2147483648;
        *(_QWORD *)(v20 + 32) = v5;
        *(_QWORD *)v20 = &CstringArrayImplementation::`vftable;
        *(_QWORD *)(v20 + 40) = v4;
      }
      break;
    case 6:
      v30 = world->vfptr;
      v31 = hkTypeManager::Type::getTypeName(t);
      v32 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v30[4].__first_virtual_table_function__)(
                                 v5,
                                 v31);
      if ( v32 )
      {
        v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v34 = (StructArrayImplementation *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v33[11] + 8i64))(
                                             v33[11],
                                             64i64);
        if ( v34 )
          StructArrayImplementation::StructArrayImplementation(v34, v5, v4, v32, v3);
      }
      break;
    case 7:
      v25 = t->m_parent;
      if ( !hkTypeManager::Type::getTypeName(t->m_parent)
        || (v26 = v5->vfptr,
            v27 = hkTypeManager::Type::getTypeName(v25),
            ((__int64 (__fastcall *)(hkDataWorldDict *, const char *))v26[4].__first_virtual_table_function__)(v5, v27)) )
      {
        v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v29 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(v28[11], 48i64);
        if ( v29 )
        {
          *(_QWORD *)(v29 + 8) = 0xFFFFi64;
          *(_QWORD *)(v29 + 16) = 0i64;
          *(_DWORD *)(v29 + 24) = 0;
          *(_DWORD *)(v29 + 28) = 2147483648;
          *(_QWORD *)(v29 + 32) = v5;
          *(_QWORD *)v29 = &PointerArrayImplementation::`vftable;
          *(_QWORD *)(v29 + 40) = v4;
        }
      }
      break;
    case 8:
      v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
      v8 = 0;
      v9 = v7;
      if ( v7 )
      {
        *(_QWORD *)(v7 + 8) = 0xFFFFi64;
        *(_QWORD *)(v7 + 16) = 0i64;
        *(_DWORD *)(v7 + 24) = 0;
        *(_DWORD *)(v7 + 28) = 2147483648;
        *(_QWORD *)(v7 + 32) = v5;
        *(_QWORD *)(v7 + 40) = v4;
        *(_QWORD *)v7 = &ArrayArrayImplementation::`vftable;
      }
      else
      {
        v9 = 0i64;
      }
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 32i64))(v9, (unsigned int)v36);
      if ( v36 > 0 )
      {
        do
        {
          v10 = hkDataArrayDict_create(v5, v4->m_parent, 0);
          (*(void (__fastcall **)(__int64, _QWORD, hkDataArrayImpl *))(*(_QWORD *)v9 + 192i64))(
            v9,
            (unsigned int)v8++,
            v10);
        }
        while ( v8 < v36 );
      }
      break;
    case 9:
      v11 = t->m_parent;
      if ( v11->m_subType == 3 )
      {
        v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v13 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 48i64);
        if ( v13 )
        {
          *(_QWORD *)(v13 + 8) = 0xFFFFi64;
          *(_QWORD *)v13 = &VecArrayImplementation::`vftable;
          *(_QWORD *)(v13 + 16) = 0i64;
          *(_DWORD *)(v13 + 24) = 0;
          *(_DWORD *)(v13 + 28) = 2147483648;
          *(_QWORD *)(v13 + 32) = v5;
          *(_QWORD *)(v13 + 40) = v4;
        }
      }
      else
      {
        v35 = hkDataArrayDict_create(world, v11, 0);
        v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v15 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 48i64);
        if ( v15 )
        {
          v16 = hkTypeManager::Type::getTupleSize(v4);
          *(_QWORD *)v15 = &ArrayOfTuplesImplementation::`vftable;
          *(_QWORD *)(v15 + 8) = 0xFFFFi64;
          *(_QWORD *)(v15 + 16) = v5;
          *(_DWORD *)(v15 + 32) = v16;
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
void __fastcall hkDataWorldDict::ObjectTracker::ObjectTracker(hkDataWorldDict::ObjectTracker *this, hkMemoryAllocator *mall)
{
  hkDataWorldDict::ObjectTracker *v2; // rbx

  this->m_allocator = mall;
  v2 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classes.m_map,
    0);
  v2->m_derivedFromParent.m_valueChain.m_capacityAndFlags = 2147483648;
  v2->m_derivedFromParent.m_valueChain.m_data = 0i64;
  v2->m_derivedFromParent.m_valueChain.m_size = 0;
  v2->m_derivedFromParent.m_indexMap.m_map.m_elem = 0i64;
  v2->m_derivedFromParent.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v2->m_derivedFromParent.m_indexMap.m_map.m_hashMod = -1i64;
  v2->m_topLevelObject = 0i64;
  v2->m_objectsFromClass.m_valueChain.m_data = 0i64;
  v2->m_objectsFromClass.m_valueChain.m_size = 0;
  v2->m_objectsFromClass.m_valueChain.m_capacityAndFlags = 2147483648;
  v2->m_objectsFromClass.m_indexMap.m_map.m_elem = 0i64;
  v2->m_objectsFromClass.m_indexMap.m_map.m_numElems = 0;
  *(_QWORD *)&v2->m_objectsFromClass.m_indexMap.m_map.m_hashMod = -1i64;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v2->m_interns.m_map,
    0);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &v2->m_internedClassNames.m_map,
    0);
  v2->m_arraysFromClass.m_map.m_elem = 0i64;
  v2->m_arraysFromClass.m_map.m_numElems = 0;
  v2->m_arraysFromClass.m_map.m_hashMod = -1;
}

// File Line: 2773
// RVA: 0xE40820
void __fastcall hkDataWorldDict::ObjectTracker::~ObjectTracker(hkDataWorldDict::ObjectTracker *this)
{
  int v1; // ebx
  __int64 v2; // rdi
  hkDataWorldDict::ObjectTracker *v3; // r13
  hkLifoAllocator *v4; // rax
  hkLifoAllocator *v5; // rcx
  char *v6; // rax
  int v7; // edx
  char *v8; // r8
  int v9; // ebx
  unsigned int v10; // er12
  hkLifoAllocator *v11; // rax
  char *v12; // rsi
  int v13; // edx
  char *v14; // rcx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v15; // rbx
  Dummy *v16; // r14
  unsigned __int64 v17; // rax
  __int64 v18; // rcx
  hkDataClassDict *v19; // r15
  int v20; // eax
  int v21; // ecx
  signed __int64 v22; // rbx
  hkDataObjectDict *v23; // rsi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v24; // rax
  int v25; // eax
  int v26; // er15
  __int64 v27; // r14
  hkDataObjectDict *v28; // rsi
  __int64 v29; // rax
  int v30; // edi
  const char *v31; // rbx
  hkOstream *v32; // rax
  hkOstream *v33; // rax
  hkOstream *v34; // rax
  hkOstream *v35; // rax
  int v36; // ebx
  __int64 v37; // rcx
  bool v38; // zf
  char *v39; // rbx
  __int64 v40; // rdi
  __int64 v41; // rcx
  Dummy *v42; // rbx
  hkReferencedObject *v43; // rax
  Dummy *v44; // rbx
  char *v45; // rax
  hkPointerMap<hkDataClassDict *,hkPointerMap<hkDataArrayImpl *,int,hkContainerHeapAllocator> *,hkContainerHeapAllocator> *v46; // rsi
  __int64 v47; // r8
  int v48; // edx
  __int64 v49; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v50; // rax
  int v51; // ebx
  AMD_HD3D *v52; // rdi
  _QWORD **v53; // rax
  __int64 v54; // r8
  int v55; // edx
  __int64 v56; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v57; // rax
  signed int v58; // ebx
  hkLifoAllocator *v59; // rax
  void *v60; // rdx
  int v61; // er8
  int v62; // eax
  char *v63; // rdi
  signed int v64; // ebx
  hkLifoAllocator *v65; // rax
  int v66; // er8
  int v67; // er8
  int v68; // er8
  _QWORD *array; // [rsp+20h] [rbp-E0h]
  int v70; // [rsp+28h] [rbp-D8h]
  int v71; // [rsp+2Ch] [rbp-D4h]
  void *v72; // [rsp+30h] [rbp-D0h]
  int v73; // [rsp+38h] [rbp-C8h]
  hkErrStream v74; // [rsp+40h] [rbp-C0h]
  char buf; // [rsp+60h] [rbp-A0h]
  hkBool result; // [rsp+2B0h] [rbp+1B0h]
  int v77; // [rsp+2B8h] [rbp+1B8h]
  int v78; // [rsp+2C0h] [rbp+1C0h]
  void *p; // [rsp+2C8h] [rbp+1C8h]

  v1 = this->m_objectsFromClass.m_valueChain.m_size;
  v2 = 0i64;
  v3 = this;
  array = 0i64;
  v70 = 0;
  v71 = 2147483648;
  v73 = v1;
  if ( v1 )
  {
    v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = v4;
    v6 = (char *)v4->m_cur;
    v7 = (8 * v1 + 127) & 0xFFFFFF80;
    v8 = &v6[v7];
    if ( v7 > v5->m_slabSize || v8 > v5->m_end )
      v6 = (char *)hkLifoAllocator::allocateFromNewSlab(v5, v7);
    else
      v5->m_cur = v8;
  }
  else
  {
    v6 = 0i64;
  }
  array = v6;
  v72 = v6;
  v71 = v1 | 0x80000000;
  v9 = v3->m_classes.m_map.m_numElems;
  v10 = 0;
  v77 = v9;
  if ( v9 )
  {
    v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (char *)v11->m_cur;
    v13 = (8 * v9 + 127) & 0xFFFFFF80;
    p = v12;
    v14 = &v12[v13];
    if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    {
      v12 = (char *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
      p = v12;
    }
    else
    {
      v11->m_cur = v14;
    }
  }
  else
  {
    v12 = 0i64;
    p = 0i64;
  }
  v78 = v9 | 0x80000000;
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::clear(&v3->m_derivedFromParent);
  v15 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classes;
  v3->m_topLevelObject = 0i64;
  v16 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classes);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classes,
    &result,
    v16);
  while ( result.m_bool )
  {
    v17 = hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(v15, v16);
    v18 = (signed int)v10++;
    *(_QWORD *)&v12[8 * v18] = v17;
    v19 = (hkDataClassDict *)v17;
    v20 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
            (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v3->m_objectsFromClass,
            v17);
    if ( v20 != -1 )
    {
      v21 = v70;
      do
      {
        v22 = v20;
        v23 = v3->m_objectsFromClass.m_valueChain.m_data[v20].value;
        if ( v21 == (v71 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
          v21 = v70;
        }
        array[v21] = v23;
        v24 = v3->m_objectsFromClass.m_valueChain.m_data;
        v21 = v70++ + 1;
        v20 = v24[v22].next;
      }
      while ( v20 != -1 );
      hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
        &v3->m_objectsFromClass,
        v19);
      v12 = (char *)p;
      v15 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_classes;
    }
    v16 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v15, v16);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v15, &result, v16);
  }
  v25 = v70;
  v26 = 0;
  if ( v70 > 0 )
  {
    v27 = 0i64;
    do
    {
      v28 = (hkDataObjectDict *)array[v27];
      if ( v28->m_externalCount > 0 )
      {
        hkErrStream::hkErrStream(&v74, &buf, 512);
        v29 = ((__int64 (__fastcall *)(hkDataObjectDict *))v28->vfptr[2].__vecDelDtor)(v28);
        v30 = v28->m_externalCount;
        v31 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v29 + 16i64))(v29);
        v32 = hkOstream::operator<<((hkOstream *)&v74.vfptr, "The object of class ");
        v33 = hkOstream::operator<<(v32, v31);
        v34 = hkOstream::operator<<(
                v33,
                " is about to be removed and all references to it will be invalid.\nHowever, the object is referenced (");
        v35 = hkOstream::operator<<(v34, v30, (int)v34);
        hkOstream::operator<<(v35, ") from outside the world and it will lead to unexpected behavior or crash.");
        hkError::messageWarning(1980577685, &buf, "Data\\Dict\\hkDataObjectDict.cpp", 2802);
        hkOstream::~hkOstream((hkOstream *)&v74.vfptr);
      }
      hkDataObjectDict::selfDestruct(v28);
      v25 = v70;
      ++v26;
      ++v27;
    }
    while ( v26 < v70 );
    v2 = 0i64;
  }
  v36 = 0;
  if ( v25 > 0 )
  {
    do
    {
      v37 = array[v2];
      v38 = (*(_DWORD *)(v37 + 12))-- == 1;
      if ( v38 )
        (**(void (__fastcall ***)(__int64, signed __int64))v37)(v37, 1i64);
      ++v36;
      ++v2;
    }
    while ( v36 < v70 );
  }
  if ( (signed int)v10 > 0 )
  {
    v39 = (char *)p;
    v40 = v10;
    do
    {
      v41 = *(_QWORD *)v39;
      v38 = *(_DWORD *)(*(_QWORD *)v39 + 12i64) == 1;
      --*(_DWORD *)(v41 + 12);
      if ( v38 )
        (**(void (__fastcall ***)(__int64, signed __int64))v41)(v41, 1i64);
      v39 += 8;
      --v40;
    }
    while ( v40 );
  }
  v42 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_internedClassNames);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_internedClassNames,
    &result,
    v42);
  while ( result.m_bool )
  {
    v43 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_internedClassNames,
                                  v42);
    hkReferencedObject::removeReference(v43);
    v42 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_internedClassNames,
            v42);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_internedClassNames,
      &result,
      v42);
  }
  v44 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator((hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns,
    &result,
    v44);
  while ( result.m_bool )
  {
    v45 = (char *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns,
                    v44);
    hkString::strFree(v45);
    v44 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns,
            v44);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v3->m_interns,
      &result,
      v44);
  }
  v46 = &v3->m_arraysFromClass;
  v47 = v3->m_arraysFromClass.m_map.m_hashMod;
  v48 = 0;
  v49 = 0i64;
  if ( v47 >= 0 )
  {
    v50 = v46->m_map.m_elem;
    do
    {
      if ( v50->key != -1i64 )
        break;
      ++v49;
      ++v48;
      ++v50;
    }
    while ( v49 <= v47 );
  }
  v51 = v48;
  if ( v48 <= v3->m_arraysFromClass.m_map.m_hashMod )
  {
    do
    {
      v52 = (AMD_HD3D *)v46->m_map.m_elem[v51].val;
      if ( v52 )
      {
        hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
          (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v46->m_map.m_elem[v51].val,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
        _(v52);
        v53 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        (*(void (__fastcall **)(_QWORD *, AMD_HD3D *, signed __int64))(*v53[11] + 16i64))(v53[11], v52, 16i64);
      }
      v54 = v3->m_arraysFromClass.m_map.m_hashMod;
      v55 = v51 + 1;
      v56 = v51 + 1;
      if ( v56 <= v54 )
      {
        v57 = &v46->m_map.m_elem[v55];
        do
        {
          if ( v57->key != -1i64 )
            break;
          ++v56;
          ++v55;
          ++v57;
        }
        while ( v56 <= v54 );
      }
      v51 = v55;
    }
    while ( v55 <= v3->m_arraysFromClass.m_map.m_hashMod );
  }
  v58 = (8 * v77 + 127) & 0xFFFFFF80;
  v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v60 = p;
  v61 = (v58 + 15) & 0xFFFFFFF0;
  if ( v58 > v59->m_slabSize || (char *)p + v61 != v59->m_cur || v59->m_firstNonLifoEnd == p )
  {
    hkLifoAllocator::slowBlockFree(v59, p, v61);
    v60 = p;
  }
  else
  {
    v59->m_cur = p;
  }
  if ( v78 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v60,
      8 * v78);
  v62 = v70;
  v63 = (char *)v72;
  if ( v72 == array )
    v62 = 0;
  v70 = v62;
  v64 = (8 * v73 + 127) & 0xFFFFFF80;
  v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v66 = (v64 + 15) & 0xFFFFFFF0;
  if ( v64 > v65->m_slabSize || &v63[v66] != v65->m_cur || v65->m_firstNonLifoEnd == v63 )
    hkLifoAllocator::slowBlockFree(v65, v63, v66);
  else
    v65->m_cur = v63;
  v70 = 0;
  if ( v71 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v71);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_arraysFromClass.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v3->m_arraysFromClass);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v3->m_internedClassNames.m_map);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v3->m_interns.m_map);
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_objectsFromClass.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v3->m_objectsFromClass.m_indexMap);
  v67 = v3->m_objectsFromClass.m_valueChain.m_capacityAndFlags;
  v3->m_objectsFromClass.m_valueChain.m_size = 0;
  if ( v67 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_objectsFromClass.m_valueChain.m_data,
      16 * v67);
  v3->m_objectsFromClass.m_valueChain.m_data = 0i64;
  v3->m_objectsFromClass.m_valueChain.m_capacityAndFlags = 2147483648;
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v3->m_derivedFromParent.m_indexMap.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v3->m_derivedFromParent.m_indexMap);
  v68 = v3->m_derivedFromParent.m_valueChain.m_capacityAndFlags;
  v3->m_derivedFromParent.m_valueChain.m_size = 0;
  if ( v68 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_derivedFromParent.m_valueChain.m_data,
      16 * v68);
  v3->m_derivedFromParent.m_valueChain.m_data = 0i64;
  v3->m_derivedFromParent.m_valueChain.m_capacityAndFlags = 2147483648;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v3->m_classes.m_map);
}

// File Line: 2849
// RVA: 0xE46F40
void __fastcall hkDataWorldDict::ObjectTracker::trackStructArray(hkDataWorldDict::ObjectTracker *this, hkDataArrayImpl *a)
{
  hkDataWorldDict::ObjectTracker *v2; // rbp
  hkDataArrayImpl *v3; // rdi
  unsigned __int64 v4; // rsi
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *v5; // rbx
  _QWORD **v6; // rax
  __int64 v7; // rax

  v2 = this;
  v3 = a;
  v4 = ((__int64 (__fastcall *)(hkDataArrayImpl *))a->vfptr[6].__vecDelDtor)(a);
  v5 = (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                                                                                            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_arraysFromClass.m_map.m_elem,
                                                                                            v4,
                                                                                            0i64);
  if ( !v5 )
  {
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 16i64);
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
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_arraysFromClass.m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v4,
      (unsigned __int64)v5);
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
    v5,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
    (unsigned __int64)v3,
    0i64);
}

// File Line: 2873
// RVA: 0xE44650
void __fastcall hkDataWorldDict::ObjectTracker::getTrackedStructArrays(hkDataWorldDict::ObjectTracker *this, hkDataClassDict *c, unsigned int baseClass, hkArray<hkDataArrayImpl *,hkContainerTempAllocator> *arraysOut)
{
  hkDataWorldDict::ObjectTracker *v4; // rsi
  hkArray<hkDataArrayImpl *,hkContainerTempAllocator> *v5; // rbp
  hkDataClassDict *v6; // rbx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdi
  int v9; // ebx
  __int64 v10; // rsi
  int v11; // er9
  int v12; // eax
  int v13; // eax
  __int64 v14; // r9
  signed int v15; // edx
  signed __int64 v16; // r10
  __int64 v17; // rcx
  _QWORD *v18; // rax
  signed __int64 v19; // rcx
  signed __int64 v20; // r9
  signed __int64 v21; // rcx
  _QWORD *v22; // rax
  int v23; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v24; // rcx
  signed __int64 v25; // rbx
  hkResult result; // [rsp+30h] [rbp-28h]
  hkDataWorldDict::ObjectTracker *v27; // [rsp+60h] [rbp+8h]
  hkDataClassDict *v28; // [rsp+68h] [rbp+10h]
  unsigned int baseClassa; // [rsp+70h] [rbp+18h]

  baseClassa = baseClass;
  v28 = c;
  v27 = this;
  v4 = this;
  v5 = arraysOut;
  v6 = c;
  v7 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&this->m_arraysFromClass.m_map.m_elem,
         (unsigned __int64)c,
         0i64);
  v8 = v7;
  if ( v7 )
  {
    v9 = *(_DWORD *)(v7 + 8) & 0x7FFFFFFF;
    if ( v9 > 0 )
    {
      v10 = v5->m_size;
      v11 = v10 + v9;
      v12 = v5->m_capacityAndFlags & 0x3FFFFFFF;
      if ( v12 < (signed int)v10 + v9 )
      {
        v13 = 2 * v12;
        if ( v11 < v13 )
          v11 = v13;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, v11, 8);
      }
      v5->m_size += v9;
      v14 = *(signed int *)(v8 + 12);
      v15 = 0;
      v16 = (signed __int64)&v5->m_data[v10];
      v17 = 0i64;
      if ( (signed int)v14 >= 0 )
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
      if ( v15 <= (signed int)v14 )
      {
        do
        {
          v16 += 8i64;
          v19 = 2i64 * v15++;
          *(_QWORD *)(v16 - 8) = *(_QWORD *)(*(_QWORD *)v8 + 8 * v19);
          v20 = *(signed int *)(v8 + 12);
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
        while ( v15 <= (signed int)v20 );
      }
      v4 = v27;
    }
    v6 = v28;
  }
  if ( baseClassa )
  {
    v23 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
            (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v4->m_derivedFromParent,
            (unsigned __int64)v6);
    if ( v23 != -1 )
    {
      v24 = v4->m_derivedFromParent.m_valueChain.m_data;
      do
      {
        v25 = v23;
        hkDataWorldDict::ObjectTracker::getTrackedStructArrays(v4, v24[v23].value, baseClassa, v5);
        v24 = v4->m_derivedFromParent.m_valueChain.m_data;
        v23 = v24[v25].next;
      }
      while ( v23 != -1 );
    }
  }
}

// File Line: 2897
// RVA: 0xE46EB0
void __fastcall hkDataWorldDict::ObjectTracker::trackClass(hkDataWorldDict::ObjectTracker *this, hkDataClassDict *klass)
{
  hkDataWorldDict::ObjectTracker *v2; // rsi
  hkDataClassDict *v3; // rbx
  hkDataClassDict *v4; // rdi
  unsigned __int64 v5; // rax
  Dummy *v6; // rax
  unsigned __int64 v7; // rax
  hkBool result; // [rsp+40h] [rbp+8h]
  hkDataObjectDict *value; // [rsp+48h] [rbp+10h]

  value = (hkDataObjectDict *)klass;
  v2 = this;
  v3 = klass;
  v4 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataClassDict *))klass->vfptr[4].__vecDelDtor)(klass);
  v5 = ((__int64 (__fastcall *)(hkDataClassDict *))v3->vfptr[2].__vecDelDtor)(v3);
  v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::findKey(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
         v5);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
    &result,
    v6);
  if ( !result.m_bool )
  {
    v7 = ((__int64 (__fastcall *)(hkDataClassDict *))v3->vfptr[2].__vecDelDtor)(v3);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v2->m_classes.m_map,
      v7,
      (unsigned __int64)v3);
    if ( v4 )
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&v2->m_derivedFromParent,
        v4,
        &value);
  }
}

// File Line: 2921
// RVA: 0xE43D20
void __fastcall hkDataWorldDict::ObjectTracker::findTrackedClasses(hkDataWorldDict::ObjectTracker *this, hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  int v2; // er9
  hkArray<hkDataClassImpl *,hkContainerTempAllocator> *v3; // rbx
  int v4; // eax
  hkDataWorldDict::ObjectTracker *v5; // rdi
  int v6; // eax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v7; // rdi
  Dummy *v8; // rsi
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = this->m_classes.m_map.m_numElems;
  v3 = classesOut;
  v4 = classesOut->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < v2 )
  {
    v6 = 2 * v4;
    if ( v2 < v6 )
      v2 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, classesOut, v2, 8);
  }
  v7 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_classes;
  v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(v7);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v7, (hkBool *)&result, v8);
  while ( LOBYTE(result.m_enum) )
  {
    v3->m_data[v3->m_size++] = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                                    v7,
                                                    v8);
    v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(v7, v8);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(v7, (hkBool *)&result, v8);
  }
}

// File Line: 2931
// RVA: 0xE43DE0
void __fastcall hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(hkDataWorldDict::ObjectTracker *this, const char *className, unsigned int baseClass, unsigned int addStructs, hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *v5; // rdi
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbp
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v8; // rsi
  int v9; // eax
  signed __int64 v10; // rdi
  hkDataObjectImpl *v11; // rbp
  unsigned __int64 v12; // rax
  _QWORD *v13; // r10
  __int64 v14; // r9
  signed int v15; // edx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  signed int v18; // eax
  signed int v19; // esi
  __int64 v20; // rdi
  hkDataObjectImpl *v21; // rbp
  __int64 v22; // r9
  signed int v23; // edx
  __int64 v24; // rcx
  _QWORD *v25; // rax
  int v26; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v27; // rcx
  signed __int64 v28; // rdi
  const char *v29; // rax
  unsigned __int64 k; // [rsp+30h] [rbp-38h]
  unsigned __int64 v31; // [rsp+38h] [rbp-30h]
  hkDataWorldDict::ObjectTracker *v32; // [rsp+70h] [rbp+8h]
  __int64 v33; // [rsp+78h] [rbp+10h]
  unsigned int baseClassa; // [rsp+80h] [rbp+18h]
  unsigned int addStructsa; // [rsp+88h] [rbp+20h]

  if ( className )
  {
    addStructsa = addStructs;
    baseClassa = baseClass;
    v32 = this;
    v5 = this;
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
           (unsigned __int64)className,
           0i64);
    v7 = v6;
    k = v6;
    if ( v6 )
    {
      v8 = &v5->m_objectsFromClass;
      v9 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
             (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v5->m_objectsFromClass,
             v6);
      if ( v9 != -1 )
      {
        do
        {
          v10 = v9;
          v11 = (hkDataObjectImpl *)&v8->m_valueChain.m_data[v9].value->vfptr;
          if ( objectsOut->m_size == (objectsOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, objectsOut, 8);
          objectsOut->m_data[objectsOut->m_size++] = v11;
          v9 = v8->m_valueChain.m_data[v10].next;
        }
        while ( v9 != -1 );
        v5 = v32;
        v7 = k;
      }
      if ( addStructsa )
      {
        v12 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v5->m_arraysFromClass.m_map.m_elem,
                v7,
                0i64);
        v13 = (_QWORD *)v12;
        v31 = v12;
        if ( v12 )
        {
          if ( (*(_DWORD *)(v12 + 8) & 0x7FFFFFFF) > 0 )
          {
            v14 = *(signed int *)(v12 + 12);
            v15 = 0;
            v16 = 0i64;
            if ( (signed int)v14 >= 0 )
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
            if ( v15 <= (signed int)v14 )
            {
              do
              {
                v19 = 0;
                v20 = *(_QWORD *)(*v13 + 16i64 * v18);
                if ( (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v20 + 40i64))(v20) > 0 )
                {
                  do
                  {
                    v21 = (hkDataObjectImpl *)(*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v20 + 168i64))(
                                                v20,
                                                (unsigned int)v19);
                    if ( objectsOut->m_size == (objectsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
                        objectsOut,
                        8);
                    ++v19;
                    objectsOut->m_data[objectsOut->m_size++] = v21;
                  }
                  while ( v19 < (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v20 + 40i64))(v20) );
                }
                v13 = (_QWORD *)v31;
                v22 = *(signed int *)(v31 + 12);
                v23 = v33 + 1;
                v24 = (signed int)v33 + 1;
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
              while ( v23 <= (signed int)v22 );
            }
          }
        }
      }
      if ( baseClassa )
      {
        v26 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
                (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v32->m_derivedFromParent,
                k);
        if ( v26 != -1 )
        {
          v27 = v32->m_derivedFromParent.m_valueChain.m_data;
          do
          {
            v28 = v26;
            v29 = (const char *)((__int64 (*)(void))v27[v26].value->vfptr[2].__vecDelDtor)();
            hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(v32, v29, baseClassa, addStructsa, objectsOut);
            v27 = v32->m_derivedFromParent.m_valueChain.m_data;
            v26 = v27[v28].next;
          }
          while ( v26 != -1 );
        }
      }
    }
  }
}

// File Line: 2984
// RVA: 0xE44E90
void __fastcall hkDataWorldDict::ObjectTracker::removeClassContent(hkDataWorldDict::ObjectTracker *this, hkDataClassDict *klass)
{
  hkDataWorldDict::ObjectTracker *v2; // rdi
  hkDataClassDict *v3; // rbx
  unsigned __int64 v4; // rax
  int v5; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v6; // rcx
  signed __int64 v7; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v8; // rsi
  int v9; // ebx
  hkLifoAllocator *v10; // rax
  char *v11; // rcx
  unsigned __int64 v12; // rdx
  signed int v13; // edx
  int v14; // ecx
  signed __int64 v15; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v16; // rax
  __int64 v17; // rsi
  char *v18; // rcx
  __int64 v19; // rax
  int v20; // edi
  const char *v21; // rbx
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  int v26; // ebx
  __int64 v27; // rdi
  __int64 v28; // rcx
  bool v29; // zf
  int v30; // eax
  char *v31; // rdi
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // er8
  char *array; // [rsp+20h] [rbp-E0h]
  int v36; // [rsp+28h] [rbp-D8h]
  int i; // [rsp+2Ch] [rbp-D4h]
  void *p; // [rsp+30h] [rbp-D0h]
  int v39; // [rsp+38h] [rbp-C8h]
  hkErrStream v40; // [rsp+40h] [rbp-C0h]
  char buf; // [rsp+60h] [rbp-A0h]
  hkDataWorldDict::ObjectTracker *v42; // [rsp+290h] [rbp+190h]
  hkDataObjectDict *v43; // [rsp+298h] [rbp+198h]
  int v44; // [rsp+298h] [rbp+198h]
  hkDataClassDict *k; // [rsp+2A0h] [rbp+1A0h]
  signed __int64 v46; // [rsp+2A8h] [rbp+1A8h]

  v42 = this;
  v2 = this;
  v3 = klass;
  v4 = ((__int64 (__fastcall *)(hkDataClassDict *))klass->vfptr[2].__vecDelDtor)(klass);
  if ( v4 )
    k = (hkDataClassDict *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                             (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
                             v4,
                             0i64);
  else
    k = 0i64;
  v5 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
         (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v2->m_derivedFromParent,
         (unsigned __int64)v3);
  if ( v5 != -1 )
  {
    v6 = v2->m_derivedFromParent.m_valueChain.m_data;
    do
    {
      v7 = v5;
      hkDataWorldDict::ObjectTracker::removeClassContent(v2, v6[v5].value);
      v6 = v2->m_derivedFromParent.m_valueChain.m_data;
      v5 = v6[v7].next;
    }
    while ( v5 != -1 );
  }
  v8 = &v2->m_objectsFromClass;
  v46 = (signed __int64)&v2->m_objectsFromClass;
  v9 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
         (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v2->m_objectsFromClass,
         (unsigned __int64)k);
  if ( v9 != -1 )
  {
    i = 2147483648;
    array = 0i64;
    v36 = 0;
    v39 = 512;
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (unsigned __int64)(v11 + 4096);
    if ( v10->m_slabSize < 4096 || (void *)v12 > v10->m_end )
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, 4096);
    else
      v10->m_cur = (void *)v12;
    v13 = -2147483136;
    array = v11;
    p = v11;
    v14 = v36;
    for ( i = -2147483136; ; v13 = i )
    {
      v15 = v9;
      v43 = v8->m_valueChain.m_data[v15].value;
      if ( v14 == (v13 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v14 = v36;
      }
      *(_QWORD *)&array[8 * v14] = v43;
      v16 = v8->m_valueChain.m_data;
      v14 = v36++ + 1;
      v9 = v16[v15].next;
      if ( v9 == -1 )
        break;
    }
    v44 = 0;
    if ( v14 > 0 )
    {
      v17 = 0i64;
      do
      {
        v18 = array;
        if ( v2->m_topLevelObject == *(hkDataObjectDict **)&array[v17] )
          v2->m_topLevelObject = 0i64;
        if ( *(_WORD *)(*(_QWORD *)&v18[v17] + 10i64) > 0 )
        {
          hkErrStream::hkErrStream(&v40, &buf, 512);
          v19 = (*(__int64 (**)(void))(**(_QWORD **)&array[v17] + 16i64))();
          v20 = *(signed __int16 *)(*(_QWORD *)&array[v17] + 10i64);
          v21 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19);
          v22 = hkOstream::operator<<((hkOstream *)&v40.vfptr, "The object of class ");
          v23 = hkOstream::operator<<(v22, v21);
          v24 = hkOstream::operator<<(
                  v23,
                  " is about to be removed and all references to it will be invalid.\n"
                  "However, the object is referenced (");
          v25 = hkOstream::operator<<(v24, v20, (int)v24);
          hkOstream::operator<<(v25, ") from outside the world and it will lead to unexpected behavior or crash.");
          hkError::messageWarning(1980577684, &buf, "Data\\Dict\\hkDataObjectDict.cpp", 3017);
          hkOstream::~hkOstream((hkOstream *)&v40.vfptr);
          v18 = array;
          v2 = v42;
        }
        hkDataObjectDict::selfDestruct(*(hkDataObjectDict **)&v18[v17]);
        v14 = v36;
        v17 += 8i64;
        ++v44;
      }
      while ( v44 < v36 );
      v8 = (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)v46;
    }
    v26 = 0;
    if ( v14 > 0 )
    {
      v27 = 0i64;
      do
      {
        v28 = *(_QWORD *)&array[v27];
        v29 = (*(_DWORD *)(v28 + 12))-- == 1;
        if ( v29 )
          (**(void (__fastcall ***)(__int64, signed __int64))v28)(v28, 1i64);
        ++v26;
        v27 += 8i64;
      }
      while ( v26 < v36 );
    }
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
      v8,
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
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        8 * i);
  }
}

// File Line: 3030
// RVA: 0xE47000
void __fastcall hkDataWorldDict::ObjectTracker::untrackClass(hkDataWorldDict::ObjectTracker *this, hkDataClassDict *klass)
{
  hkDataWorldDict::ObjectTracker *v2; // rdi
  hkDataClassDict *v3; // rsi
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbx
  hkDataClassDict *v6; // rax
  __int64 v7; // rbx
  hkLifoAllocator *v8; // rax
  char *v9; // rcx
  unsigned __int64 v10; // rdx
  int v11; // eax
  int v12; // ecx
  signed __int64 v13; // rbx
  hkDataObjectDict *v14; // rdi
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v15; // rax
  int v16; // edi
  __int64 v17; // rcx
  bool v18; // zf
  char *v19; // rdi
  signed int v20; // ebx
  hkLifoAllocator *v21; // rax
  int v22; // er8
  hkReferencedObject *v23; // rbx
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *v24; // [rsp+20h] [rbp-38h]
  _QWORD *array; // [rsp+28h] [rbp-30h]
  int v26; // [rsp+30h] [rbp-28h]
  int v27; // [rsp+34h] [rbp-24h]
  void *p; // [rsp+38h] [rbp-20h]
  int v29; // [rsp+40h] [rbp-18h]
  hkDataWorldDict::ObjectTracker *v30; // [rsp+80h] [rbp+28h]
  hkDataClassDict *v; // [rsp+88h] [rbp+30h]
  bool v32; // [rsp+90h] [rbp+38h]
  unsigned __int64 key; // [rsp+98h] [rbp+40h]

  v = klass;
  v30 = this;
  v2 = this;
  v3 = klass;
  v4 = ((__int64 (__fastcall *)(hkDataClassDict *))klass->vfptr[2].__vecDelDtor)(klass);
  key = v4;
  if ( v4 )
    v5 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
           v4,
           0i64);
  else
    v5 = 0i64;
  hkDataWorldDict::ObjectTracker::removeClassContent(v2, v3);
  v6 = (hkDataClassDict *)(*(__int64 (__fastcall **)(unsigned __int64))(*(_QWORD *)v5 + 32i64))(v5);
  if ( v6 )
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByValue(
      &v2->m_derivedFromParent,
      v6,
      &v);
  hkDataClassDict::selfDestruct(v3);
  v7 = 0i64;
  array = 0i64;
  v26 = 0;
  v27 = 2147483648;
  v29 = 64;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (char *)v8->m_cur;
  v10 = (unsigned __int64)(v9 + 512);
  if ( v8->m_slabSize < 512 || (void *)v10 > v8->m_end )
    v9 = (char *)hkLifoAllocator::allocateFromNewSlab(v8, 512);
  else
    v8->m_cur = (void *)v10;
  array = v9;
  p = v9;
  v27 = -2147483584;
  v24 = (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&v2->m_derivedFromParent;
  v11 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
          (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v2->m_derivedFromParent,
          (unsigned __int64)v3);
  v32 = v11 != -1;
  if ( v11 == -1 )
  {
    v12 = v26;
  }
  else
  {
    v12 = v26;
    do
    {
      v13 = v11;
      v14 = v24->m_valueChain.m_data[v11].value;
      if ( v12 == (v27 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 8);
        v12 = v26;
      }
      array[v12] = v14;
      v15 = v24->m_valueChain.m_data;
      v12 = v26++ + 1;
      v11 = v15[v13].next;
    }
    while ( v11 != -1 );
    v3 = v;
    v7 = 0i64;
  }
  v16 = 0;
  if ( v12 > 0 )
  {
    do
    {
      hkDataWorldDict::ObjectTracker::untrackClass(v30, *(hkDataClassDict **)((char *)array + v7));
      v17 = *(_QWORD *)((char *)array + v7);
      v18 = (*(_DWORD *)(v17 + 12))-- == 1;
      if ( v18 )
        (**(void (__fastcall ***)(__int64, signed __int64))v17)(v17, 1i64);
      v12 = v26;
      ++v16;
      v7 += 8i64;
    }
    while ( v16 < v26 );
    v3 = v;
    LODWORD(v7) = 0;
  }
  if ( v32 )
  {
    hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeKey(
      v24,
      v3);
    v12 = v26;
  }
  v19 = (char *)p;
  if ( p == array )
    v12 = v7;
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
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      8 * v27);
  v23 = (hkReferencedObject *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v30->m_internedClassNames,
                                key,
                                0i64);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
    &v30->m_internedClassNames.m_map,
    (hkResult *)&v,
    key);
  hkReferencedObject::removeReference(v23);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(&v30->m_classes.m_map, (hkResult *)&v, key);
}

// File Line: 3094
// RVA: 0xE45770
void __fastcall hkDataWorldDict::ObjectTracker::retrackDerivedClass(hkDataWorldDict::ObjectTracker *this, hkDataClassDict *oldParent, hkDataClassDict *klass)
{
  hkDataWorldDict::ObjectTracker *v3; // rbp
  hkDataClassDict *v4; // rdi
  hkDataClassDict *v5; // rbx
  int v6; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v7; // r8
  hkDataClassDict *v8; // rax
  hkDataObjectDict *value; // [rsp+40h] [rbp+18h]

  value = (hkDataObjectDict *)klass;
  v3 = this;
  v4 = oldParent;
  v5 = klass;
  if ( oldParent )
  {
    v6 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
           (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_derivedFromParent,
           (unsigned __int64)oldParent);
    if ( v6 != -1 )
    {
      v7 = v3->m_derivedFromParent.m_valueChain.m_data;
      while ( v7[v6].value != v5 )
      {
        v6 = v7[v6].next;
        if ( v6 == -1 )
          goto LABEL_8;
      }
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&v3->m_derivedFromParent,
        v4,
        v6);
    }
  }
LABEL_8:
  v8 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataClassDict *))v5->vfptr[4].__vecDelDtor)(v5);
  if ( v8 )
    hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
      (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)&v3->m_derivedFromParent,
      v8,
      &value);
}

// File Line: 3118
// RVA: 0xE45810
void __fastcall hkDataWorldDict::ObjectTracker::retrackRenamedClass(hkDataWorldDict::ObjectTracker *this, const char *oldName, const char *newName)
{
  char *v3; // rbx
  const char *v4; // rdi
  const char *v5; // rbp
  hkDataWorldDict::ObjectTracker *v6; // r14
  unsigned __int64 v7; // r15
  unsigned __int64 v8; // rdi
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = 0i64;
  v4 = newName;
  v5 = oldName;
  v6 = this;
  if ( oldName )
    v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
           (unsigned __int64)oldName,
           0i64);
  else
    v7 = 0i64;
  if ( v4 )
  {
    v3 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6->m_interns,
                   (unsigned __int64)v4,
                   0i64);
    if ( !v3 )
    {
      v3 = hkString::strDup(v4);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v6->m_interns.m_map,
        (unsigned __int64)v3,
        (unsigned __int64)v3);
    }
  }
  if ( v5 != v3 )
  {
    v8 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6->m_internedClassNames,
           (unsigned __int64)v5,
           0i64);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
      &v6->m_internedClassNames.m_map,
      &result,
      (unsigned __int64)v5);
    *(_QWORD *)(v8 + 16) = v3;
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
      &v6->m_internedClassNames.m_map,
      (unsigned __int64)v3,
      v8);
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::remove(
    &v6->m_classes.m_map,
    &result,
    (unsigned __int64)v5);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v6->m_classes.m_map,
    (unsigned __int64)v3,
    v7);
}

// File Line: 3135
// RVA: 0xE45900
void __fastcall hkDataWorldDict::ObjectTracker::retractCastedObject(hkDataWorldDict::ObjectTracker *this, hkDataObjectDict *obj, hkDataClassDict *newClass)
{
  hkDataClassDict *v3; // rbp
  hkDataObjectDict *v4; // r14
  hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *v5; // rdi
  hkDataClassDict *v6; // rsi
  int i; // eax
  signed __int64 v8; // rbx
  hkDataObjectDict *value; // [rsp+48h] [rbp+10h]

  value = obj;
  v3 = newClass;
  v4 = obj;
  v5 = (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&this->m_objectsFromClass;
  v6 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))obj->vfptr[2].__vecDelDtor)(obj);
  for ( i = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              v5,
              (unsigned __int64)v6); v6; i = v5->m_valueChain.m_data[v8 + 1].value )
  {
    if ( i == -1 )
      break;
    v8 = 2i64 * i;
    if ( v4 == (hkDataObjectDict *)v5->m_valueChain.m_data[2 * i] )
    {
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::removeByIndex(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)v5,
        v6,
        i);
      hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
        (hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> > *)v5,
        v3,
        &value);
      v6 = 0i64;
    }
  }
}

// File Line: 3161
// RVA: 0xE44A30
InternedString *__fastcall hkDataWorldDict::ObjectTracker::intern(hkDataWorldDict::ObjectTracker *this, InternedString *result, const char *sin)
{
  const char *v3; // rsi
  InternedString *v4; // rbx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v5; // rbp
  char *v6; // rdi
  InternedString *v7; // rax

  v3 = sin;
  v4 = result;
  if ( sin )
  {
    v5 = &this->m_interns.m_map;
    v6 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_interns,
                   (unsigned __int64)sin,
                   0i64);
    if ( !v6 )
    {
      v6 = hkString::strDup(v3);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        v5,
        (unsigned __int64)v6,
        (unsigned __int64)v6);
    }
    v4->m_cachedString = v6;
    v7 = v4;
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
hkReferencedObject **__fastcall hkDataWorldDict::ObjectTracker::internClassNameHandle(hkDataWorldDict::ObjectTracker *this, InternedStringHandle *result, const char *sin)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v3; // r15
  const char *v4; // rbp
  hkReferencedObject **v5; // rdi
  unsigned __int64 v6; // rbx
  _QWORD **v7; // rax
  char *v8; // rsi

  v3 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)this;
  v4 = sin;
  v5 = (hkReferencedObject **)result;
  result->m_cached.m_pntr = 0i64;
  hkReferencedObject::addReference((hkReferencedObject *)&InternedNullRefCounted.vfptr);
  if ( *v5 )
    hkReferencedObject::removeReference(*v5);
  *v5 = (hkReferencedObject *)&InternedNullRefCounted;
  if ( v4 )
  {
    v6 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           v3 + 6,
           (unsigned __int64)v4,
           0i64);
    if ( !v6 )
    {
      v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v6 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 24i64);
      if ( v6 )
      {
        v8 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                       v3 + 5,
                       (unsigned __int64)v4,
                       0i64);
        if ( !v8 )
        {
          v8 = hkString::strDup(v4);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v3[5],
            (unsigned __int64)v8,
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
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v3[6],
        *(_QWORD *)(v6 + 16),
        v6);
    }
    hkReferencedObject::addReference((hkReferencedObject *)v6);
    if ( *v5 )
      hkReferencedObject::removeReference(*v5);
    *v5 = (hkReferencedObject *)v6;
  }
  return v5;
}

// File Line: 3211
// RVA: 0xE3ED80
void __fastcall hkDataWorldDict::hkDataWorldDict(hkDataWorldDict *this)
{
  hkDataWorldDict *v1; // rbx
  _QWORD **v2; // rax
  hkDataWorldDict::ObjectTracker *v3; // rax
  hkDataWorldDict::ObjectTracker *v4; // rax

  v1 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  hkTypeManager::hkTypeManager(&this->m_typeManager);
  v1->m_allocator = (hkMemoryAllocator *)*((_QWORD *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID) + 11);
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkDataWorldDict::ObjectTracker *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                           v2[11],
                                           184i64);
  if ( v3 )
  {
    hkDataWorldDict::ObjectTracker::ObjectTracker(v3, v1->m_allocator);
    v1->m_tracker = v4;
  }
  else
  {
    v1->m_tracker = 0i64;
  }
}

// File Line: 3217
// RVA: 0xE3EE10
void __fastcall hkDataWorldDict::hkDataWorldDict(hkDataWorldDict *this, hkMemoryAllocator *mall)
{
  hkDataWorldDict *v2; // rdi
  hkMemoryAllocator *v3; // rbx
  _QWORD **v4; // rax
  hkDataWorldDict::ObjectTracker *v5; // rax
  hkDataWorldDict::ObjectTracker *v6; // rax

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  v3 = mall;
  hkTypeManager::hkTypeManager(&this->m_typeManager);
  v2->m_allocator = v3;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataWorldDict::ObjectTracker *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(
                                           v4[11],
                                           184i64);
  if ( v5 )
  {
    hkDataWorldDict::ObjectTracker::ObjectTracker(v5, v2->m_allocator);
    v2->m_tracker = v6;
  }
  else
  {
    v2->m_tracker = 0i64;
  }
}

// File Line: 3223
// RVA: 0xE3EEA0
void __fastcall hkDataWorldDict::~hkDataWorldDict(hkDataWorldDict *this)
{
  hkDataWorldDict::ObjectTracker *v1; // rdi
  hkDataWorldDict *v2; // rbx
  _QWORD **v3; // rax

  v1 = this->m_tracker;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldDict::`vftable;
  if ( v1 )
  {
    hkDataWorldDict::ObjectTracker::~ObjectTracker(v1);
    v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkDataWorldDict::ObjectTracker *, signed __int64))(*v3[11] + 16i64))(
      v3[11],
      v1,
      184i64);
  }
  hkTypeManager::~hkTypeManager(&v2->m_typeManager);
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 3228
// RVA: 0xE3EF10
hkDataObject *__fastcall hkDataWorldDict::getContents(hkDataWorldDict *this, hkDataObject *result)
{
  hkDataObjectDict *v2; // rcx
  hkDataObject *v3; // rax

  v2 = this->m_tracker->m_topLevelObject;
  v3 = result;
  result->m_impl = (hkDataObjectImpl *)&v2->vfptr;
  if ( v2 )
  {
    ++v2->m_externalCount;
    ++v2->m_count;
  }
  return v3;
}

// File Line: 3233
// RVA: 0xE3F1A0
hkDataObjectDict *__fastcall hkDataWorldDict::newObject(hkDataWorldDict *this, hkDataClass *klass, bool createdDuringPatching)
{
  hkDataWorldDict *v3; // rbp
  bool v4; // si
  hkDataClass *v5; // rdi
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkDataObjectDict *v8; // rbx
  hkDataClassImpl *v9; // rdx
  hkDataRefCountedVtbl *v10; // rdx
  hkDataWorldDict::ObjectTracker *v11; // rdi
  hkDataClassDict *v12; // rax
  hkDataObjectDict *result; // rax
  hkDataObjectDict *value; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = createdDuringPatching;
  v5 = klass;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = (hkDataObjectDict *)v7;
  if ( v7 )
  {
    v9 = v5->m_impl;
    *(_QWORD *)(v7 + 8) = 0xFFFFi64;
    *(_QWORD *)v7 = &hkDataObjectDict::`vftable;
    if ( v9 )
      ++v9->m_count;
    *(_QWORD *)(v7 + 16) = v9;
    *(_QWORD *)(v7 + 24) = 0i64;
    *(_DWORD *)(v7 + 32) = 0;
    *(_DWORD *)(v7 + 36) = 2147483648;
    *(_DWORD *)(v7 + 40) = v4;
  }
  else
  {
    v8 = 0i64;
  }
  ++v8->m_count;
  v10 = v8->vfptr;
  v11 = v3->m_tracker;
  value = v8;
  v12 = (hkDataClassDict *)((__int64 (__fastcall *)(hkDataObjectDict *))v10[2].__vecDelDtor)(v8);
  hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::insert(
    &v11->m_objectsFromClass,
    v12,
    &value);
  result = v8;
  if ( !v11->m_topLevelObject )
    v11->m_topLevelObject = v8;
  return result;
}

// File Line: 3241
// RVA: 0xE3EF40
hkDataClassDict *__fastcall hkDataWorldDict::newClass(hkDataWorldDict *this, hkDataClass::Cinfo *cinfo)
{
  hkDataWorldDict *v2; // rbx
  hkDataClass::Cinfo *v3; // rsi
  _QWORD **v4; // rax
  hkDataClassDict *v5; // rax
  hkDataClassDict *v6; // rax
  hkDataClassDict *v7; // rbp
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // rax
  hkDataClassDict *v10; // rbx
  hkDataClassDict *v11; // rcx
  bool v12; // zf
  int v13; // er15
  __int64 v14; // r12
  hkDataClass::Cinfo::Member *v15; // r13
  const char *v16; // r14
  char *v17; // rbx
  hkTypeManager::Type *v18; // r14
  _QWORD *v19; // rax
  hkDataWorldDict *v21; // [rsp+60h] [rbp+8h]
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v22; // [rsp+68h] [rbp+10h]

  v21 = this;
  v2 = this;
  v3 = cinfo;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataClassDict *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 96i64);
  if ( v5 )
  {
    hkDataClassDict::hkDataClassDict(v5, v2, v3->name, v3->version);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (unsigned __int64)v3->parent;
  if ( v8 )
  {
    v9 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_tracker->m_classes,
           v8,
           0i64);
    v10 = (hkDataClassDict *)v9;
    if ( v9 )
      ++*(_DWORD *)(v9 + 12);
    v11 = v7->m_parent.m_pntr;
    if ( v11 )
    {
      v12 = v11->m_count-- == 1;
      if ( v12 )
        v11->vfptr->__vecDelDtor((hkDataRefCounted *)&v11->vfptr, 1u);
    }
    v7->m_parent.m_pntr = v10;
    v2 = v21;
  }
  ++v7->m_count;
  hkDataWorldDict::ObjectTracker::trackClass(v2->m_tracker, v7);
  v13 = 0;
  if ( v3->members.m_size > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = v3->members.m_data;
      v16 = v15[v14].name;
      if ( v16 )
      {
        v22 = &v2->m_tracker->m_interns.m_map;
        v17 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                        (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v22,
                        (unsigned __int64)v15[v14].name,
                        0i64);
        if ( !v17 )
        {
          v17 = hkString::strDup(v16);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            v22,
            (unsigned __int64)v17,
            (unsigned __int64)v17);
        }
      }
      else
      {
        v17 = 0i64;
      }
      v18 = v15[v14].type;
      if ( v7->m_memberInfo.m_size == (v7->m_memberInfo.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v7->m_world->m_allocator, &v7->m_memberInfo, 32);
      v19 = &v7->m_memberInfo.m_data[v7->m_memberInfo.m_size].m_name.m_cachedString;
      if ( v19 )
      {
        *v19 = v17;
        v19[1] = 0i64;
        v19[2] = v18;
        v19[3] = 0i64;
      }
      ++v7->m_memberInfo.m_size;
      v2 = v21;
      ++v13;
      ++v14;
    }
    while ( v13 < v3->members.m_size );
  }
  hkTypeManager::addClass(&v2->m_typeManager, v3->name);
  return v7;
}

// File Line: 3269
// RVA: 0xE3F100
hkDataArrayImpl *__fastcall hkDataWorldDict::newArray(hkDataWorldDict *this, hkDataObject *obj, const struct _hkDataObject_MemberHandle *handle, hkDataClass_MemberInfo *minfo)
{
  hkTypeManager::Type *v4; // rbx
  const struct _hkDataObject_MemberHandle *v5; // rbp
  hkDataObject *v6; // rsi
  hkDataWorldDict *v7; // rdi
  int v8; // eax
  int v9; // er8
  hkDataArrayImpl *v10; // rax
  hkDataObjectImpl *v11; // rcx
  hkDataArrayImpl *v12; // rbx
  bool v13; // zf

  v4 = minfo->m_type;
  v5 = handle;
  v6 = obj;
  v7 = this;
  if ( v4->m_subType == 9 )
  {
    v8 = hkTypeManager::Type::getTupleSize(minfo->m_type);
    this = v7;
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  v10 = hkDataArrayDict_create(this, v4->m_parent, v9);
  v11 = v6->m_impl;
  v12 = v10;
  if ( v10 )
  {
    ++v10->m_externalCount;
    ++v10->m_count;
  }
  ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, hkDataArrayImpl *))v11->vfptr[22].__vecDelDtor)(
    v11,
    v5,
    v10);
  if ( v12 )
  {
    --v12->m_externalCount;
    v13 = v12->m_count-- == 1;
    if ( v13 )
      v12->vfptr->__vecDelDtor((hkDataRefCounted *)&v12->vfptr, 1u);
  }
  return v12;
}

// File Line: 3292
// RVA: 0xE3F270
hkEnum<enum hkDataWorld::DataWorldType,int> *__fastcall hkDataWorldDict::getType(hkDataWorldDict *this, hkEnum<enum hkDataWorld::DataWorldType,int> *result)
{
  result->m_storage = 1;
  return result;
}

// File Line: 3298
// RVA: 0xE3F280
void __fastcall hkDataWorldDict::findAllClasses(hkDataWorldDict *this, hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  hkDataWorldDict::ObjectTracker::findTrackedClasses(this->m_tracker, classesOut);
}

// File Line: 3303
// RVA: 0xE3F2B0
hkDataClassDict *__fastcall hkDataWorldDict::wrapClass(hkDataWorldDict *this, hkClass *klass)
{
  hkDataWorldDict *v2; // rsi
  hkClass *v3; // rbp
  _QWORD **v4; // rax
  hkDataClassDict *v5; // rdi
  int v6; // ebx
  const char *v7; // rax
  hkDataClassDict *v8; // rax
  hkDataClassDict *v9; // rdi
  hkClass *v10; // rax
  const char *v11; // rax
  hkDataClassImpl *v12; // rbx
  hkClass *v13; // rax
  hkDataClassDict *v14; // rcx
  bool v15; // zf
  int v16; // ebx
  hkArrayBase<hkDataClassDict::MemberInfo> *v17; // rsi
  hkClassMember *v18; // rbp
  hkDataWorldDict *v19; // rax
  hkClass *v20; // rax
  hkClass *v21; // rbx
  hkVariant *v22; // rax
  hkClassMemberAccessor *v23; // rcx
  hkVariant *v24; // rax
  hkClassMember::Type v25; // ebx
  hkClassMember::Type v26; // edi
  int count; // eax
  const char *v28; // rdi
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v29; // rbp
  char *v30; // rbx
  char **v31; // rax
  hkDataClassDict *v33; // [rsp+30h] [rbp-58h]
  hkClassMemberAccessor v34; // [rsp+38h] [rbp-50h]
  hkClassMemberAccessor v35; // [rsp+48h] [rbp-40h]
  hkDataWorldDict *v36; // [rsp+90h] [rbp+8h]
  hkClass *v37; // [rsp+98h] [rbp+10h]
  signed int v38; // [rsp+A0h] [rbp+18h]
  char *typeName; // [rsp+A8h] [rbp+20h]
  char *typeNamea; // [rsp+A8h] [rbp+20h]

  v37 = klass;
  v36 = this;
  v2 = this;
  v3 = klass;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkDataClassDict *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 96i64);
  if ( v5 )
  {
    v6 = hkClass::getDescribedVersion(v3);
    v7 = hkClass::getName(v3);
    hkDataClassDict::hkDataClassDict(v5, v2, v7, v6);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v33 = v9;
  if ( hkClass::getParent(v3) )
  {
    v10 = hkClass::getParent(v3);
    v11 = hkClass::getName(v10);
    if ( !v11
      || (v12 = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                     (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_tracker->m_classes,
                                     (unsigned __int64)v11,
                                     0i64)) == 0i64 )
    {
      v13 = hkClass::getParent(v3);
      v12 = hkDataWorldDict::wrapClass(v2, v13);
    }
    if ( v12 )
      ++v12->m_count;
    v14 = v9->m_parent.m_pntr;
    if ( v14 )
    {
      v15 = v14->m_count-- == 1;
      if ( v15 )
        v14->vfptr->__vecDelDtor((hkDataRefCounted *)&v14->vfptr, 1u);
    }
    v9->m_parent.m_pntr = (hkDataClassDict *)v12;
  }
  ++v9->m_count;
  hkDataWorldDict::ObjectTracker::trackClass(v2->m_tracker, v9);
  v16 = 0;
  v38 = 0;
  if ( (signed int)hkClass::getNumDeclaredMembers(v3) > 0 )
  {
    v17 = &v9->m_memberInfo;
    while ( 1 )
    {
      v18 = hkClass::getDeclaredMember(v3, v16);
      v19 = v36;
      typeName = (char *)v36->m_typeManager.m_builtInTypes[1];
      if ( !((v18->m_flags.m_storage >> 10) & 1) )
        break;
LABEL_24:
      v28 = v18->m_name;
      v29 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v19->m_tracker;
      if ( v28 )
      {
        v30 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                        v29 + 5,
                        (unsigned __int64)v28,
                        0i64);
        if ( !v30 )
        {
          v30 = hkString::strDup(v28);
          hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
            (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v29[5],
            (unsigned __int64)v30,
            (unsigned __int64)v30);
        }
      }
      else
      {
        v30 = 0i64;
      }
      v9 = v33;
      if ( v17->m_size == (v17->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(v33->m_world->m_allocator, v17, 32);
      v31 = (char **)&v17->m_data[v17->m_size];
      if ( v31 )
      {
        *v31 = v30;
        v31[1] = 0i64;
        v31[2] = typeName;
        v31[3] = 0i64;
      }
      v3 = v37;
      ++v17->m_size;
      v16 = ++v38;
      if ( v38 >= (signed int)hkClass::getNumDeclaredMembers(v37) )
        return v9;
    }
    v20 = hkClassMember::getClass(v18);
    typeNamea = 0i64;
    v21 = v20;
    if ( v20 )
    {
      typeNamea = (char *)hkClass::getName(v20);
      v22 = hkClassMember::getAttribute(v18, s_hkDataObjectTypeAttributeID);
      if ( v22 )
      {
        hkClassMemberAccessor::hkClassMemberAccessor(&v34, v22, "typeName");
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
    v25 = (unsigned __int8)v18->m_subtype.m_storage;
    v26 = (unsigned __int8)v18->m_type.m_storage;
    count = hkClassMember::getCstyleArraySize(v18);
    typeName = (char *)hkDataObjectUtil::getTypeFromMemberTypeClassName(&v36->m_typeManager, v26, v25, typeNamea, count);
    v19 = v36;
    goto LABEL_24;
  }
  return v9;
}

// File Line: 3356
// RVA: 0xE3F5B0
hkDataClassImpl *__fastcall hkDataWorldDict::copyClassFromWorld(hkDataWorldDict *this, const char *name, hkDataWorld *worldFrom)
{
  hkDataWorld *v3; // rsi
  const char *v4; // rbx
  hkDataWorldDict *v5; // rdi
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
  hkTypeManager::Type **v17; // rax
  int v18; // ecx
  int v19; // er15
  hkTypeManager *v20; // rcx
  hkDataClass_MemberInfo *v21; // r12
  hkTypeManager::Type *v22; // rsi
  hkTypeManager::Type *v23; // r13
  hkBaseObjectVtbl *v24; // rbx
  const char *v25; // rax
  hkBaseObjectVtbl *v26; // rbx
  const char *v27; // rax
  __int64 v28; // [rsp+30h] [rbp-29h]
  __int64 v29; // [rsp+38h] [rbp-21h]
  hkArrayBase<hkDataClass_MemberInfo> minfos; // [rsp+40h] [rbp-19h]
  __int64 v31; // [rsp+50h] [rbp-9h]
  int v32; // [rsp+58h] [rbp-1h]
  __int64 v33; // [rsp+60h] [rbp+7h]
  void *array; // [rsp+68h] [rbp+Fh]
  int v35; // [rsp+70h] [rbp+17h]
  int v36; // [rsp+74h] [rbp+1Bh]
  hkResult result; // [rsp+C0h] [rbp+67h]
  hkDataWorld *v38; // [rsp+D0h] [rbp+77h]
  hkDataClass v39; // [rsp+D8h] [rbp+7Fh]

  v38 = worldFrom;
  v3 = worldFrom;
  v4 = name;
  v5 = this;
  v6 = (hkDataClassImpl *)((__int64 (*)(void))this->vfptr[4].__first_virtual_table_function__)();
  if ( v6 )
    return v6;
  v7 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorld *, const char *))v3->vfptr[4].__first_virtual_table_function__)(
                            v3,
                            v4);
  v8 = 0i64;
  array = 0i64;
  v35 = 0;
  v36 = 2147483648;
  v39.m_impl = v7;
  v31 = ((__int64 (__fastcall *)(hkDataClassImpl *))v7->vfptr[2].__vecDelDtor)(v7);
  v32 = ((__int64 (*)(void))v39.m_impl->vfptr[3].__vecDelDtor)();
  v9 = ((__int64 (*)(void))v39.m_impl->vfptr[4].__vecDelDtor)();
  if ( !v9 )
  {
    v33 = 0i64;
LABEL_5:
    v10 = ((__int64 (__fastcall *)(hkDataWorldDict *, __int64 *))v5->vfptr[1].__first_virtual_table_function__)(
            v5,
            &v31);
    v29 = v10;
    v11 = ((__int64 (*)(void))v39.m_impl->vfptr[6].__vecDelDtor)();
    minfos.m_data = 0i64;
    minfos.m_size = 0;
    v12 = v11;
    minfos.m_capacityAndFlags = 2147483648;
    v13 = v11;
    if ( v11 )
    {
      result.m_enum = 32 * v11;
      v14 = (hkDataClass_MemberInfo *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                                        (int *)&result);
      v12 = result.m_enum / 32;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = 2147483648;
    minfos.m_data = v14;
    if ( v12 )
      v15 = v12;
    minfos.m_size = v13;
    v16 = v13;
    minfos.m_capacityAndFlags = v15;
    if ( (signed int)v13 > 0 )
    {
      v17 = &v14->m_type;
      do
      {
        if ( v17 != (hkTypeManager::Type **)16 )
        {
          *(v17 - 2) = 0i64;
          *(v17 - 1) = 0i64;
          *v17 = 0i64;
          v17[1] = 0i64;
        }
        v17 += 4;
        --v16;
      }
      while ( v16 );
    }
    hkDataClass::getAllDeclaredMemberInfo(&v39, &minfos);
    v18 = minfos.m_size;
    if ( (v36 & 0x3FFFFFFF) < minfos.m_size )
    {
      if ( minfos.m_size < 2 * (v36 & 0x3FFFFFFF) )
        v18 = 2 * (v36 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 24);
      v18 = minfos.m_size;
    }
    v28 = v10;
    v19 = 0;
    if ( v18 > 0 )
    {
      v20 = &v5->m_typeManager;
      do
      {
        v21 = minfos.m_data;
        v22 = hkTypeManager::copyType(v20, *(hkTypeManager::Type **)((char *)&minfos.m_data->m_type + v8));
        v23 = hkTypeManager::Type::findTerminal(v22);
        if ( v23->m_subType == 6 )
        {
          v24 = v38->vfptr;
          v25 = hkTypeManager::Type::getTypeName(v22);
          if ( ((__int64 (__fastcall *)(hkDataWorld *, const char *))v24[4].__first_virtual_table_function__)(v38, v25) )
          {
            v26 = v5->vfptr;
            v27 = hkTypeManager::Type::getTypeName(v23);
            ((void (__fastcall *)(hkDataWorldDict *, const char *, hkDataWorld *))v26[11].__first_virtual_table_function__)(
              v5,
              v27,
              v38);
          }
        }
        ((void (__fastcall *)(hkDataWorldDict *, __int64 *, _QWORD, hkTypeManager::Type *, _QWORD))v5->vfptr[8].__vecDelDtor)(
          v5,
          &v28,
          *(const char **)((char *)&v21->m_name + v8),
          v22,
          0i64);
        ++v19;
        v8 += 32i64;
        v20 = &v5->m_typeManager;
      }
      while ( v19 < minfos.m_size );
      v10 = v29;
      LODWORD(v8) = 0;
    }
    minfos.m_size = v8;
    if ( minfos.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        minfos.m_data,
        32 * minfos.m_capacityAndFlags);
    minfos.m_data = 0i64;
    minfos.m_capacityAndFlags = 2147483648;
    goto LABEL_29;
  }
  v33 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 16i64))(v9);
  v10 = ((__int64 (__fastcall *)(hkDataWorldDict *, __int64))v5->vfptr[4].__first_virtual_table_function__)(v5, v31);
  if ( !v10 )
    goto LABEL_5;
LABEL_29:
  v35 = v8;
  if ( v36 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      24 * (v36 & 0x3FFFFFFF));
  return (hkDataClassImpl *)v10;
}

// File Line: 3406
// RVA: 0xE3F290
hkDataClassImpl *__fastcall hkDataWorldDict::findClass(hkDataWorldDict *this, const char *name)
{
  hkDataWorldDict::ObjectTracker *v2; // rcx
  hkDataClassImpl *result; // rax

  v2 = this->m_tracker;
  if ( name )
    result = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v2->m_classes,
                                  (unsigned __int64)name,
                                  0i64);
  else
    result = 0i64;
  return result;
}

// File Line: 3411
// RVA: 0xE40220
hkDataObject *__fastcall hkDataWorldDict::findObject(hkDataWorldDict *this, hkDataObject *result, hkDataObject_Handle *handle)
{
  _WORD *v3; // rax

  v3 = handle->p0;
  result->m_impl = (hkDataObjectImpl *)handle->p0;
  if ( v3 )
  {
    ++v3[5];
    ++*((_DWORD *)v3 + 3);
  }
  return result;
}

// File Line: 3416
// RVA: 0xE3F8B0
void __fastcall hkDataWorldDict::renameClass(hkDataWorldDict *this, hkDataClass *klass, const char *newName)
{
  hkDataWorldDict *v3; // rsi
  const char *v4; // rbp
  unsigned __int64 v5; // rax
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v6; // r14
  const char *v7; // rdi
  const char *v8; // rbx

  v3 = this;
  v4 = newName;
  v5 = ((__int64 (*)(void))klass->m_impl->vfptr[2].__vecDelDtor)();
  v6 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v3->m_tracker;
  v7 = (const char *)v5;
  if ( v5 )
  {
    v8 = (const char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                         v6 + 5,
                         v5,
                         0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(v7);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v6[5],
        (unsigned __int64)v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  if ( hkTypeManager::getClass(&v3->m_typeManager, v8) )
    hkTypeManager::renameClass(&v3->m_typeManager, v8, v4);
  hkDataWorldDict::ObjectTracker::retrackRenamedClass(v3->m_tracker, v8, v4);
}

// File Line: 3432
// RVA: 0xE3F970
void __fastcall hkDataWorldDict::removeClass(hkDataWorldDict *this, hkDataClass *klass)
{
  hkDataWorldDict *v2; // rsi
  hkDataClass *v3; // rdi
  const char *v4; // rax
  hkTypeManager::Type *v5; // rax
  hkDataClassDict *v6; // rbx
  bool v7; // zf

  v2 = this;
  v3 = klass;
  v4 = (const char *)((__int64 (*)(void))klass->m_impl->vfptr[2].__vecDelDtor)();
  v5 = hkTypeManager::getClass(&v2->m_typeManager, v4);
  if ( v5 )
    hkTypeManager::removeClass(&v2->m_typeManager, v5);
  v6 = (hkDataClassDict *)v3->m_impl;
  v3->m_impl = 0i64;
  hkDataWorldDict::ObjectTracker::untrackClass(v2->m_tracker, v6);
  v7 = v6->m_count-- == 1;
  if ( v7 )
    v6->vfptr->__vecDelDtor((hkDataRefCounted *)&v6->vfptr, 1u);
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
  hkDataWorldDict *v3; // rbp
  hkDataClass *v4; // rbx
  hkDataClassDict **v5; // rsi
  __int64 v6; // rax
  hkDataClassDict *v7; // rbx
  hkDataClassDict *v8; // rdi
  hkDataClassDict *v9; // r14
  hkDataClassDict *v10; // rcx
  bool v11; // zf

  v3 = this;
  v4 = parent;
  v5 = (hkDataClassDict **)klass;
  v6 = ((__int64 (*)(void))klass->m_impl->vfptr[4].__vecDelDtor)();
  v7 = (hkDataClassDict *)v4->m_impl;
  v8 = *v5;
  v9 = (hkDataClassDict *)v6;
  if ( v7 )
    ++v7->m_count;
  v10 = v8->m_parent.m_pntr;
  if ( v10 )
  {
    v11 = v10->m_count-- == 1;
    if ( v11 )
      v10->vfptr->__vecDelDtor((hkDataRefCounted *)&v10->vfptr, 1u);
  }
  v8->m_parent.m_pntr = v7;
  hkDataWorldDict::ObjectTracker::retrackDerivedClass(v3->m_tracker, v9, *v5);
}

// File Line: 3464
// RVA: 0xE3FA90
void __fastcall hkDataWorldDict::addClassMember(hkDataWorldDict *this, hkDataClass *klass, const char *name, hkTypeManager::Type *type, const void *valuePtr)
{
  hkDataClassDict *v5; // rdi
  hkDataWorldDict::ObjectTracker *v6; // rbp
  hkTypeManager::Type *v7; // r14
  const char *v8; // rsi
  char *v9; // rbx
  hkResult result; // [rsp+40h] [rbp+8h]

  v5 = (hkDataClassDict *)klass->m_impl;
  v6 = this->m_tracker;
  v7 = type;
  v8 = name;
  if ( name )
  {
    v9 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v6->m_interns,
                   (unsigned __int64)name,
                   0i64);
    if ( !v9 )
    {
      v9 = hkString::strDup(v8);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v6->m_interns.m_map,
        (unsigned __int64)v9,
        (unsigned __int64)v9);
    }
  }
  else
  {
    v9 = 0i64;
  }
  if ( (unsigned int)v5->vfptr[8].__vecDelDtor((hkDataRefCounted *)&v5->vfptr, (unsigned int)v8) != -1 )
    hkDataClassDict::removeMember(v5, &result, (InternedString)v9);
  hkDataClassDict::addMember(v5, (InternedString)v9, v7, valuePtr);
}

// File Line: 3479
// RVA: 0xE40160
void __fastcall hkDataWorldDict::setClassMemberDefault(hkDataWorldDict *this, hkDataClass *klass, const char *name, const void *valuePtr)
{
  hkDataClassImpl *v4; // rsi
  hkDataWorldDict::ObjectTracker *v5; // rbp
  void *(__fastcall *v6)(hkDataRefCounted *, unsigned int); // r14
  const char *v7; // rdi
  char *v8; // rbx
  int v9; // edx
  __int64 v10; // rcx
  hkDataRefCountedVtbl *v11; // rax

  v4 = klass->m_impl;
  v5 = this->m_tracker;
  v6 = (void *(__fastcall *)(hkDataRefCounted *, unsigned int))valuePtr;
  v7 = name;
  if ( name )
  {
    v8 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v5->m_interns,
                   (unsigned __int64)name,
                   0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(v7);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v5->m_interns.m_map,
        (unsigned __int64)v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v9 = *(_DWORD *)&v4[4].m_memSize - 1;
  v10 = v9;
  if ( v9 < 0 )
  {
LABEL_9:
    v9 = -1;
  }
  else
  {
    v11 = &v4[4].vfptr[4 * v9];
    while ( (char *)v11->__vecDelDtor != v8 )
    {
      --v9;
      v11 -= 4;
      if ( --v10 < 0 )
        goto LABEL_9;
    }
  }
  v4[4].vfptr[4 * v9 + 3].__vecDelDtor = v6;
}

// File Line: 3489
// RVA: 0xE3FB40
void __fastcall hkDataWorldDict::renameClassMember(hkDataWorldDict *this, hkDataClass *klass, const char *oldName, const char *newName)
{
  hkDataWorldDict::ObjectTracker *v4; // r14
  const char *v5; // rsi
  const char *v6; // rdi
  hkDataClass *v7; // r15
  hkDataWorldDict *v8; // r12
  char *v9; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v10; // r14
  char *v11; // rdi
  hkDataClassImpl *v12; // rcx
  unsigned __int64 v13; // rax
  hkDataWorldDict::ObjectTracker *v14; // r13
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r12
  int v17; // eax
  int v18; // ecx
  signed __int64 v19; // rsi
  hkDataObjectDict *v20; // r15
  int v21; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v22; // rcx
  signed __int64 v23; // rsi
  const char *v24; // rax
  int v25; // er8
  __int64 v26; // r9
  __int64 v27; // rcx
  __int64 v28; // rax
  __int64 v29; // rdx
  __int64 v30; // r10
  char **v31; // rcx
  hkDataWorldDict::ObjectTracker *v32; // rcx
  __int64 v33; // r9
  int v34; // er10
  int v35; // er8
  __int64 v36; // rcx
  hkDataArrayImpl *v37; // rax
  __int64 v38; // rdx
  char **v39; // rax
  int v40; // edx
  __int64 v41; // rcx
  hkDataClassDict::MemberInfo *v42; // rax
  __int64 array; // [rsp+30h] [rbp-50h]
  int v44; // [rsp+38h] [rbp-48h]
  int v45; // [rsp+3Ch] [rbp-44h]
  hkArray<hkDataArrayImpl *,hkContainerTempAllocator> arraysOut; // [rsp+40h] [rbp-40h]
  hkDataWorldDict *v47; // [rsp+90h] [rbp+10h]
  hkDataClassDict *c; // [rsp+98h] [rbp+18h]

  v47 = this;
  v4 = this->m_tracker;
  c = (hkDataClassDict *)klass->m_impl;
  v5 = newName;
  v6 = oldName;
  v7 = klass;
  v8 = this;
  if ( oldName )
  {
    v9 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_interns,
                   (unsigned __int64)oldName,
                   0i64);
    if ( !v9 )
    {
      v9 = hkString::strDup(v6);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v4->m_interns.m_map,
        (unsigned __int64)v9,
        (unsigned __int64)v9);
    }
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)v8->m_tracker;
  if ( v5 )
  {
    v11 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                    v10 + 5,
                    (unsigned __int64)v5,
                    0i64);
    if ( !v11 )
    {
      v11 = hkString::strDup(v5);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        (hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *)&v10[5],
        (unsigned __int64)v11,
        (unsigned __int64)v11);
    }
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v7->m_impl;
  array = 0i64;
  v44 = 0;
  v45 = 2147483648;
  v13 = ((__int64 (*)(void))v12->vfptr[2].__vecDelDtor)();
  v14 = v8->m_tracker;
  v44 = 0;
  if ( v13 )
  {
    v15 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v14->m_classes,
            v13,
            0i64);
    v16 = v15;
    if ( v15 )
    {
      v17 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v14->m_objectsFromClass,
              v15);
      if ( v17 != -1 )
      {
        v18 = v44;
        do
        {
          v19 = v17;
          v20 = v14->m_objectsFromClass.m_valueChain.m_data[v17].value;
          if ( v18 == (v45 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
            v18 = v44;
          }
          *(_QWORD *)(array + 8i64 * v18) = v20;
          v18 = v44++ + 1;
          v17 = v14->m_objectsFromClass.m_valueChain.m_data[v19].next;
        }
        while ( v17 != -1 );
      }
      v21 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v14->m_derivedFromParent,
              v16);
      if ( v21 != -1 )
      {
        v22 = v14->m_derivedFromParent.m_valueChain.m_data;
        do
        {
          v23 = v21;
          v24 = (const char *)((__int64 (*)(void))v22[v21].value->vfptr[2].__vecDelDtor)();
          hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(
            v14,
            v24,
            1u,
            0,
            (hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *)&array);
          v22 = v14->m_derivedFromParent.m_valueChain.m_data;
          v21 = v22[v23].next;
        }
        while ( v21 != -1 );
      }
    }
    v8 = v47;
  }
  v25 = 0;
  if ( v44 > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = *(_QWORD *)(array + v26);
      v28 = 0i64;
      v29 = *(signed int *)(v27 + 32);
      if ( v29 > 0 )
      {
        v30 = *(_QWORD *)(v27 + 24);
        v31 = *(char ***)(v27 + 24);
        while ( *v31 != v9 )
        {
          ++v28;
          v31 += 2;
          if ( v28 >= v29 )
            goto LABEL_29;
        }
        *(_QWORD *)(v30 + 16 * v28) = v11;
      }
LABEL_29:
      ++v25;
      v26 += 8i64;
    }
    while ( v25 < v44 );
  }
  v32 = v8->m_tracker;
  arraysOut.m_data = 0i64;
  arraysOut.m_size = 0;
  arraysOut.m_capacityAndFlags = 2147483648;
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
      v38 = *(signed int *)&v37[1].m_memSize;
      if ( v38 > 0 )
      {
        v39 = (char **)v37[1].vfptr;
        while ( *v39 != v9 )
        {
          ++v36;
          v39 += 2;
          if ( v36 >= v38 )
            goto LABEL_38;
        }
        *v39 = v11;
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
  v44 = 0;
  arraysOut.m_capacityAndFlags = 2147483648;
  if ( v45 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      array,
      (unsigned int)(8 * v45),
      v33 * 8);
}

// File Line: 3512
// RVA: 0xE3FEC0
void __fastcall hkDataWorldDict::removeClassMember(hkDataWorldDict *this, hkDataClass *klass, const char *name)
{
  hkDataClassDict *v3; // r12
  hkDataWorldDict::ObjectTracker *v4; // rsi
  const char *v5; // rdi
  hkDataClass *v6; // r14
  hkDataWorldDict *v7; // r13
  char *v8; // rbx
  hkDataClassImpl *v9; // rcx
  unsigned __int64 v10; // rax
  hkDataWorldDict::ObjectTracker *v11; // r15
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r12
  int v14; // eax
  int v15; // ecx
  signed __int64 v16; // rdi
  hkDataObjectDict *v17; // r14
  int v18; // eax
  hkSerializeMultiMap<hkDataClassDict *,hkDataClassDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator> >::Value *v19; // rcx
  signed __int64 v20; // rdi
  const char *v21; // rax
  int v22; // esi
  __int64 v23; // rdi
  hkDataWorldDict::ObjectTracker *v24; // rcx
  int v25; // esi
  __int64 v26; // rdi
  _QWORD *array; // [rsp+30h] [rbp-20h]
  int v28; // [rsp+38h] [rbp-18h]
  int v29; // [rsp+3Ch] [rbp-14h]
  hkArray<hkDataArrayImpl *,hkContainerTempAllocator> arraysOut; // [rsp+40h] [rbp-10h]
  hkDataClassImpl *result; // [rsp+80h] [rbp+30h]

  v3 = (hkDataClassDict *)klass->m_impl;
  v4 = this->m_tracker;
  v5 = name;
  v6 = klass;
  v7 = this;
  result = klass->m_impl;
  if ( name )
  {
    v8 = (char *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                   (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v4->m_interns,
                   (unsigned __int64)name,
                   0i64);
    if ( !v8 )
    {
      v8 = hkString::strDup(v5);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v4->m_interns.m_map,
        (unsigned __int64)v8,
        (unsigned __int64)v8);
    }
  }
  else
  {
    v8 = 0i64;
  }
  v9 = v6->m_impl;
  array = 0i64;
  v28 = 0;
  v29 = 2147483648;
  v10 = ((__int64 (*)(void))v9->vfptr[2].__vecDelDtor)();
  v11 = v7->m_tracker;
  v28 = 0;
  if ( v10 )
  {
    v12 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
            (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v11->m_classes,
            v10,
            0i64);
    v13 = v12;
    if ( v12 )
    {
      v14 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v11->m_objectsFromClass,
              v12);
      if ( v14 != -1 )
      {
        v15 = v28;
        do
        {
          v16 = v14;
          v17 = v11->m_objectsFromClass.m_valueChain.m_data[v14].value;
          if ( v15 == (v29 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, 8);
            v15 = v28;
          }
          array[v15] = v17;
          v15 = v28++ + 1;
          v14 = v11->m_objectsFromClass.m_valueChain.m_data[v16].next;
        }
        while ( v14 != -1 );
      }
      v18 = hkSerializeMultiMap<hkDataClassDict *,hkDataObjectDict *,hkPointerMap<hkDataClassDict *,int,hkContainerHeapAllocator>>::getFirstIndex(
              (hkSerializeMultiMap<unsigned __int64,int,hkPointerMap<unsigned __int64,int,hkContainerHeapAllocator> > *)&v11->m_derivedFromParent,
              v13);
      if ( v18 != -1 )
      {
        v19 = v11->m_derivedFromParent.m_valueChain.m_data;
        do
        {
          v20 = v18;
          v21 = (const char *)((__int64 (*)(void))v19[v18].value->vfptr[2].__vecDelDtor)();
          hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(
            v11,
            v21,
            1u,
            0,
            (hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *)&array);
          v19 = v11->m_derivedFromParent.m_valueChain.m_data;
          v18 = v19[v20].next;
        }
        while ( v18 != -1 );
      }
    }
    v3 = (hkDataClassDict *)result;
  }
  v22 = 0;
  if ( v28 > 0 )
  {
    v23 = 0i64;
    do
    {
      hkDataObjectDict::removeMember((hkDataObjectDict *)array[v23], (InternedString)v8);
      ++v22;
      ++v23;
    }
    while ( v22 < v28 );
  }
  v24 = v7->m_tracker;
  arraysOut.m_data = 0i64;
  arraysOut.m_size = 0;
  arraysOut.m_capacityAndFlags = 2147483648;
  hkDataWorldDict::ObjectTracker::getTrackedStructArrays(v24, v3, 1u, &arraysOut);
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
  hkDataClassDict::removeMember(v3, (hkResult *)&result, (InternedString)v8);
  arraysOut.m_size = 0;
  if ( arraysOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      arraysOut.m_data,
      8 * arraysOut.m_capacityAndFlags);
  arraysOut.m_data = 0i64;
  arraysOut.m_capacityAndFlags = 2147483648;
  v28 = 0;
  if ( v29 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      8 * v29);
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
void __fastcall hkDataWorldDict::findObjectsByExactClass(hkDataWorldDict *this, const char *className, hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *v3; // rcx

  v3 = this->m_tracker;
  objectsOut->m_size = 0;
  hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(v3, className, 0, 1u, objectsOut);
}

// File Line: 3549
// RVA: 0xE40260
void __fastcall hkDataWorldDict::findObjectsByBaseClass(hkDataWorldDict *this, const char *className, hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  hkDataWorldDict::ObjectTracker *v3; // rcx

  v3 = this->m_tracker;
  objectsOut->m_size = 0;
  hkDataWorldDict::ObjectTracker::findTrackedObjectsByBase(v3, className, 1u, 1u, objectsOut);
}

