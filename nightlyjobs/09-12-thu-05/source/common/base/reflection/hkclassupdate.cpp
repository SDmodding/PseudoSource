// File Line: 32
// RVA: 0x12FEFC0
void __fastcall anonymous_namespace_::walkMembers(hkClass *klass, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass, int walkingFlag, void (__fastcall *memberCallback)(hkClassMember *))
{
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v4; // rsi
  __int64 v5; // rbx
  hkClass *v6; // rdi
  void (__fastcall *v7)(hkClassMember *); // rbp
  int v8; // ecx
  __int64 v9; // rax
  int v10; // ebx
  hkClassMember *v11; // rax
  hkClassMember *v12; // rsi
  hkClass *v13; // rax
  hkClass *v14; // rax
  int v15; // eax
  bool v16; // zf
  __int64 v17; // [rsp+20h] [rbp-28h]
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v18; // [rsp+58h] [rbp+10h]
  int walkingFlaga; // [rsp+60h] [rbp+18h]

  walkingFlaga = walkingFlag;
  v18 = updateFlagFromClass;
  v4 = updateFlagFromClass;
  v5 = walkingFlag;
  v6 = klass;
  v7 = memberCallback;
  v8 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&updateFlagFromClass->m_map.m_elem,
         (unsigned __int64)klass,
         0i64);
  if ( !(v8 & (unsigned int)v5) )
  {
    v9 = v5;
    v17 = v5;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_map.m_elem,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        (unsigned __int64)v6,
        v9 | v8);
      v10 = 0;
      if ( (signed int)hkClass::getNumDeclaredMembers(v6) > 0 )
      {
        do
        {
          v11 = hkClass::getDeclaredMember(v6, v10);
          v12 = v11;
          v13 = hkClassMember::getClass(v11);
          if ( v13 )
            anonymous_namespace_::walkMembers(v13, v18, walkingFlaga, v7);
          v7(v12);
          ++v10;
        }
        while ( v10 < (signed int)hkClass::getNumDeclaredMembers(v6) );
        v4 = v18;
      }
      if ( !hkClass::getParent(v6) )
        break;
      v14 = hkClass::getParent(v6);
      v6 = v14;
      v15 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v4->m_map.m_elem,
              (unsigned __int64)v14,
              0i64);
      v16 = (v15 & walkingFlaga) == 0;
      v8 = v15;
      v9 = v17;
    }
    while ( v16 );
  }
}

// File Line: 56
// RVA: 0x12FF0D0
void __fastcall anonymous_namespace_::updatePointerCharToCString(hkClassMember *klassMem)
{
  if ( klassMem->m_type.m_storage == 20 && klassMem->m_subtype.m_storage == 2 )
    *(_WORD *)&klassMem->m_type.m_storage = 29;
}

// File Line: 66
// RVA: 0x12FF0F0
void __fastcall anonymous_namespace_::updateClassVersion1Inplace(hkClass *classInOut, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass)
{
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v2; // rbp
  hkClass *v3; // rdi
  int i; // eax
  hkClass *v5; // rbx
  __int64 j; // rsi
  hkClassMember *v7; // rax
  int k; // ebx
  hkClassMember *v9; // rax
  hkClass *v10; // rax
  hkClass *v11; // rax

  v2 = updateFlagFromClass;
  v3 = classInOut;
  for ( i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&updateFlagFromClass->m_map.m_elem,
              (unsigned __int64)classInOut,
              0i64);
        !(i & 1);
        i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_map.m_elem,
              (unsigned __int64)v11,
              0i64) )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v3,
      i | 1i64);
    v5 = v3;
    for ( j = hkClass::getMemberByName(&hkClassVersion1Class, "hasVtable")->m_offset;
          hkClass::getParent(v5);
          v5 = hkClass::getParent(v5) )
    {
      *(const char **)((char *)&v5->m_name + j) = 0i64;
    }
    if ( *((_BYTE *)&v5->m_name + j) )
    {
      v7 = hkClass::getMemberByName(&hkClassVersion1Class, "numImplementedInterfaces");
      ++*(_DWORD *)((char *)&v5->m_name + v7->m_offset);
    }
    *(const char **)((char *)&v5->m_name + j) = 0i64;
    for ( k = 0; k < (signed int)hkClass::getNumDeclaredMembers(v3); ++k )
    {
      v9 = hkClass::getDeclaredMember(v3, k);
      if ( v9->m_class )
      {
        v10 = hkClassMember::getStructClass(v9);
        anonymous_namespace_::updateClassVersion1Inplace(v10, v2);
      }
    }
    if ( !hkClass::getParent(v3) )
      break;
    v11 = hkClass::getParent(v3);
    v3 = v11;
  }
}

// File Line: 105
// RVA: 0x12FF240
void __fastcall anonymous_namespace_::updateConstraintInstance300(hkClass *classInOut, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass)
{
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v2; // rdi
  hkClass *v3; // rbx
  int v4; // eax
  const char *v5; // rax
  hkClassMember *v6; // rbx

  v2 = updateFlagFromClass;
  v3 = classInOut;
  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&updateFlagFromClass->m_map.m_elem,
         (unsigned __int64)classInOut,
         0i64);
  if ( !(v4 & 4) )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v2->m_map.m_elem,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (unsigned __int64)v3,
      v4 | 4i64);
    v5 = hkClass::getName(v3);
    if ( !(unsigned int)hkString::strCmp(v5, "hkpConstraintInstance") )
    {
      v6 = hkClass::getDeclaredMember(v3, 2);
      *((_BYTE *)&v6->m_name + hkClass::getMember(&hkClassMemberClass, 4)->m_offset) = 25;
    }
  }
}

// File Line: 122
// RVA: 0x12FF2D0
void __fastcall anonymous_namespace_::updateEnumSizeAndTypeZero(hkClassMember *member)
{
  char v1; // al
  char v2; // al
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax

  if ( member->m_type.m_storage == 19 )
  {
    v1 = member->m_subtype.m_storage;
    member->m_subtype.m_storage = 0;
    member->m_type.m_storage = v1;
    member->m_flags.m_storage |= 0x400u;
  }
  v2 = member->m_type.m_storage;
  if ( v2 == 24 || v2 == 31 )
  {
    v3 = member->m_flags.m_storage;
    if ( v3 & 8 )
    {
      member->m_subtype.m_storage = 4;
      member->m_flags.m_storage = v3 & 0xFFF7;
    }
    v4 = member->m_flags.m_storage;
    if ( v4 & 0x10 )
    {
      member->m_subtype.m_storage = 6;
      member->m_flags.m_storage = v4 & 0xFFEF;
    }
    v5 = member->m_flags.m_storage;
    if ( v5 & 0x20 )
    {
      member->m_subtype.m_storage = 8;
      member->m_flags.m_storage = v5 & 0xFFDF;
    }
  }
}

// File Line: 149
// RVA: 0x12FEF40
void __fastcall hkClass::updateMetadataInplace(hkClass *c, hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updated, int sourceVersion)
{
  int v3; // ebx
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v4; // rdi
  hkClass *v5; // rsi

  v3 = sourceVersion;
  v4 = updated;
  v5 = c;
  if ( sourceVersion == 1 )
  {
    anonymous_namespace_::updateClassVersion1Inplace(c, updated);
    anonymous_namespace_::updateConstraintInstance300(v5, v4);
  }
  else if ( sourceVersion >= 4 )
  {
    goto LABEL_5;
  }
  anonymous_namespace_::walkMembers(v5, v4, 2, anonymous_namespace_::updatePointerCharToCString);
LABEL_5:
  if ( v3 < 5 )
    anonymous_namespace_::walkMembers(v5, v4, 8, anonymous_namespace_::updateEnumSizeAndTypeZero);
}

// File Line: 166
// RVA: 0x12FEEC0
void __fastcall hkClass::updateMetadataInplace(hkClass **c, int sourceVersion)
{
  hkClass *v2; // rax
  __int64 v3; // rbx
  int v4; // esi
  hkClass **v5; // rdi
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> updated; // [rsp+20h] [rbp-18h]

  v2 = *c;
  v3 = 0i64;
  v4 = sourceVersion;
  v5 = c;
  updated.m_map.m_hashMod = -1;
  updated.m_map.m_elem = 0i64;
  for ( updated.m_map.m_numElems = 0; v2; ++v3 )
  {
    hkClass::updateMetadataInplace(v2, &updated, v4);
    v2 = v5[v3 + 1];
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&updated.m_map.m_elem,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&updated);
}

