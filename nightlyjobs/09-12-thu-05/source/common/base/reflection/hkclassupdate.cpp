// File Line: 32
// RVA: 0x12FEFC0
void __fastcall anonymous_namespace_::walkMembers(
        hkClass *klass,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass,
        int walkingFlag,
        void (__fastcall *memberCallback)(hkClassMember *))
{
  hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *v4; // rsi
  __int64 v5; // rbx
  hkClass *Parent; // rdi
  int v8; // ecx
  __int64 v9; // rax
  int v10; // ebx
  hkClassMember *DeclaredMember; // rsi
  hkClass *Class; // rax
  int v13; // eax
  bool v14; // zf
  __int64 v15; // [rsp+20h] [rbp-28h]

  v4 = updateFlagFromClass;
  v5 = walkingFlag;
  Parent = klass;
  v8 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &updateFlagFromClass->m_map,
         (unsigned __int64)klass,
         0i64);
  if ( (v8 & (unsigned int)v5) == 0 )
  {
    v9 = v5;
    v15 = v5;
    do
    {
      hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
        &v4->m_map,
        &hkContainerHeapAllocator::s_alloc,
        (unsigned __int64)Parent,
        v9 | v8);
      v10 = 0;
      if ( (int)hkClass::getNumDeclaredMembers(Parent) > 0 )
      {
        do
        {
          DeclaredMember = hkClass::getDeclaredMember(Parent, v10);
          Class = hkClassMember::getClass(DeclaredMember);
          if ( Class )
            anonymous_namespace_::walkMembers(Class, updateFlagFromClass, walkingFlag, memberCallback);
          memberCallback(DeclaredMember);
          ++v10;
        }
        while ( v10 < (int)hkClass::getNumDeclaredMembers(Parent) );
        v4 = updateFlagFromClass;
      }
      if ( !hkClass::getParent(Parent) )
        break;
      Parent = hkClass::getParent(Parent);
      v13 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &v4->m_map,
              (unsigned __int64)Parent,
              0i64);
      v14 = (v13 & walkingFlag) == 0;
      v8 = v13;
      v9 = v15;
    }
    while ( v14 );
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
void __fastcall anonymous_namespace_::updateClassVersion1Inplace(
        hkClass *classInOut,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass)
{
  hkClass *v3; // rdi
  int i; // eax
  hkClass *Parent; // rbx
  __int64 j; // rsi
  hkClassMember *MemberByName; // rax
  int k; // ebx
  hkClassMember *DeclaredMember; // rax
  hkClass *StructClass; // rax

  v3 = classInOut;
  for ( i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &updateFlagFromClass->m_map,
              (unsigned __int64)classInOut,
              0i64);
        (i & 1) == 0;
        i = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
              &updateFlagFromClass->m_map,
              (unsigned __int64)v3,
              0i64) )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &updateFlagFromClass->m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)v3,
      i | 1i64);
    Parent = v3;
    for ( j = hkClass::getMemberByName(&hkClassVersion1Class, "hasVtable")->m_offset;
          hkClass::getParent(Parent);
          Parent = hkClass::getParent(Parent) )
    {
      *(const char **)((char *)&Parent->m_name + j) = 0i64;
    }
    if ( *((_BYTE *)&Parent->m_name + j) )
    {
      MemberByName = hkClass::getMemberByName(&hkClassVersion1Class, "numImplementedInterfaces");
      ++*(_DWORD *)((char *)&Parent->m_name + MemberByName->m_offset);
    }
    *(const char **)((char *)&Parent->m_name + j) = 0i64;
    for ( k = 0; k < (int)hkClass::getNumDeclaredMembers(v3); ++k )
    {
      DeclaredMember = hkClass::getDeclaredMember(v3, k);
      if ( DeclaredMember->m_class )
      {
        StructClass = hkClassMember::getStructClass(DeclaredMember);
        anonymous_namespace_::updateClassVersion1Inplace(StructClass, updateFlagFromClass);
      }
    }
    if ( !hkClass::getParent(v3) )
      break;
    v3 = hkClass::getParent(v3);
  }
}

// File Line: 105
// RVA: 0x12FF240
void __fastcall anonymous_namespace_::updateConstraintInstance300(
        hkClass *classInOut,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updateFlagFromClass)
{
  int v4; // eax
  const char *Name; // rax
  hkClassMember *DeclaredMember; // rbx

  v4 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getWithDefault(
         &updateFlagFromClass->m_map,
         (unsigned __int64)classInOut,
         0i64);
  if ( (v4 & 4) == 0 )
  {
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
      &updateFlagFromClass->m_map,
      &hkContainerHeapAllocator::s_alloc,
      (unsigned __int64)classInOut,
      v4 | 4i64);
    Name = hkClass::getName(classInOut);
    if ( !(unsigned int)hkString::strCmp(Name, "hkpConstraintInstance") )
    {
      DeclaredMember = hkClass::getDeclaredMember(classInOut, 2);
      *((_BYTE *)&DeclaredMember->m_name + hkClass::getMember(&hkClassMemberClass, 4)->m_offset) = 25;
    }
  }
}

// File Line: 122
// RVA: 0x12FF2D0
void __fastcall anonymous_namespace_::updateEnumSizeAndTypeZero(hkClassMember *member)
{
  char m_storage; // al
  char v2; // al
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // ax

  if ( member->m_type.m_storage == 19 )
  {
    m_storage = member->m_subtype.m_storage;
    member->m_subtype.m_storage = 0;
    member->m_type.m_storage = m_storage;
    member->m_flags.m_storage |= 0x400u;
  }
  v2 = member->m_type.m_storage;
  if ( v2 == 24 || v2 == 31 )
  {
    v3 = member->m_flags.m_storage;
    if ( (v3 & 8) != 0 )
    {
      member->m_subtype.m_storage = 4;
      member->m_flags.m_storage = v3 & 0xFFF7;
    }
    v4 = member->m_flags.m_storage;
    if ( (v4 & 0x10) != 0 )
    {
      member->m_subtype.m_storage = 6;
      member->m_flags.m_storage = v4 & 0xFFEF;
    }
    v5 = member->m_flags.m_storage;
    if ( (v5 & 0x20) != 0 )
    {
      member->m_subtype.m_storage = 8;
      member->m_flags.m_storage = v5 & 0xFFDF;
    }
  }
}

// File Line: 149
// RVA: 0x12FEF40
void __fastcall hkClass::updateMetadataInplace(
        hkClass *c,
        hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *updated,
        int sourceVersion)
{
  if ( sourceVersion == 1 )
  {
    anonymous_namespace_::updateClassVersion1Inplace(c, updated);
    anonymous_namespace_::updateConstraintInstance300(c, updated);
  }
  else if ( sourceVersion >= 4 )
  {
    goto LABEL_5;
  }
  anonymous_namespace_::walkMembers(c, updated, 2, anonymous_namespace_::updatePointerCharToCString);
LABEL_5:
  if ( sourceVersion < 5 )
    anonymous_namespace_::walkMembers(c, updated, 8, anonymous_namespace_::updateEnumSizeAndTypeZero);
}

// File Line: 166
// RVA: 0x12FEEC0
void __fastcall hkClass::updateMetadataInplace(hkClass **c, int sourceVersion)
{
  hkClass *v2; // rax
  __int64 v3; // rbx
  _BYTE updated[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = *c;
  v3 = 0i64;
  *(_DWORD *)&updated[12] = -1;
  *(_QWORD *)updated = 0i64;
  for ( *(_DWORD *)&updated[8] = 0; v2; ++v3 )
  {
    hkClass::updateMetadataInplace(
      v2,
      (hkPointerMap<hkClass const *,int,hkContainerHeapAllocator> *)updated,
      sourceVersion);
    v2 = c[v3 + 1];
  }
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)updated,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)updated);
}

