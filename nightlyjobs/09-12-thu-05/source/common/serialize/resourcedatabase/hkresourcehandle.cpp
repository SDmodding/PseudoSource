// File Line: 15
// RVA: 0xE3C530
void __fastcall hkMemoryResourceHandle::hkMemoryResourceHandle(hkMemoryResourceHandle *this)
{
  hkMemoryResourceHandle *v1; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceHandle::`vftable';
  this->m_variant.m_pntr = 0i64;
  hkStringPtr::hkStringPtr(&this->m_name);
  v1->m_references.m_data = 0i64;
  v1->m_references.m_size = 0;
  v1->m_references.m_capacityAndFlags = 2147483648;
}

// File Line: 21
// RVA: 0xE3C580
void __fastcall hkMemoryResourceHandle::hkMemoryResourceHandle(hkMemoryResourceHandle *this, hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *v2; // rcx

  v2 = &this->m_name;
  v2[-3].m_stringAndFlag = (const char *)&hkMemoryResourceHandle::`vftable';
  hkStringPtr::hkStringPtr(v2, flag);
}

// File Line: 26
// RVA: 0xE3C5B0
void __fastcall hkMemoryResourceHandle::~hkMemoryResourceHandle(hkMemoryResourceHandle *this)
{
  hkMemoryResourceHandle *v1; // rsi
  int v2; // edi
  hkMemoryResourceHandle::ExternalLink *v3; // rcx
  int v4; // edi
  hkStringPtr *v5; // rbx
  int v6; // er8
  hkReferencedObject *v7; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceHandle::`vftable';
  v2 = this->m_references.m_size;
  v3 = this->m_references.m_data;
  v4 = v2 - 1;
  if ( v4 >= 0 )
  {
    v5 = &v3[v4].m_memberName;
    do
    {
      hkStringPtr::~hkStringPtr(v5 + 1);
      hkStringPtr::~hkStringPtr(v5);
      v5 -= 2;
      --v4;
    }
    while ( v4 >= 0 );
  }
  v6 = v1->m_references.m_capacityAndFlags;
  v1->m_references.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_references.m_data,
      16 * v6);
  v1->m_references.m_data = 0i64;
  v1->m_references.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v7 = v1->m_variant.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v1->m_variant.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 31
// RVA: 0xE3CB20
void __fastcall hkMemoryResourceHandle::clearExternalLinks(hkMemoryResourceHandle *this)
{
  hkMemoryResourceHandle *v1; // rsi
  hkMemoryResourceHandle::ExternalLink *v2; // rcx
  int v3; // edi
  hkStringPtr *v4; // rbx

  v1 = this;
  v2 = this->m_references.m_data;
  v3 = v1->m_references.m_size - 1;
  if ( v3 >= 0 )
  {
    v4 = &v2[v3].m_memberName;
    do
    {
      hkStringPtr::~hkStringPtr(v4 + 1);
      hkStringPtr::~hkStringPtr(v4);
      v4 -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  v1->m_references.m_size = 0;
}

// File Line: 37
// RVA: 0xE3C670
const char *__fastcall hkMemoryResourceHandle::getName(hkMemoryResourceHandle *this, hkStringBuf *buffer)
{
  const char *result; // rax

  result = (const char *)((_QWORD)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !result )
    result = "null";
  return result;
}

// File Line: 47
// RVA: 0xE3C690
void __fastcall hkMemoryResourceHandle::setName(hkMemoryResourceHandle *this, const char *name)
{
  hkStringPtr::operator=(&this->m_name, name);
}

// File Line: 53
// RVA: 0xE3C6A0
hkReferencedObject *__fastcall hkMemoryResourceHandle::getObject(hkMemoryResourceHandle *this)
{
  return this->m_variant.m_pntr;
}

// File Line: 59
// RVA: 0xE3C6B0
hkClass *__fastcall hkMemoryResourceHandle::getClass(hkMemoryResourceHandle *this)
{
  return hkRefVariant::getClass(&this->m_variant);
}

// File Line: 65
// RVA: 0xE3C6C0
void __fastcall hkMemoryResourceHandle::setObject(hkMemoryResourceHandle *this, void *object, hkClass *klass)
{
  hkRefVariant::set(&this->m_variant, object, klass);
}

// File Line: 71
// RVA: 0xE3C6D0
void __fastcall hkMemoryResourceHandle::addExternalLink(hkMemoryResourceHandle *this, const char *memberName, const char *externalId)
{
  signed int *v3; // rdi
  const char *v4; // rsi
  const char *v5; // rbp
  hkStringPtr *v6; // rbx
  hkStringPtr *v7; // rbx
  hkStringPtr *v8; // rcx

  v3 = (signed int *)&this->m_references;
  v4 = externalId;
  v5 = memberName;
  if ( this->m_references.m_size == (this->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
  v6 = (hkStringPtr *)(*(_QWORD *)v3 + 16i64 * v3[2]);
  if ( v6 )
  {
    hkStringPtr::hkStringPtr(v6);
    hkStringPtr::hkStringPtr(v6 + 1);
  }
  v7 = (hkStringPtr *)(*(_QWORD *)v3 + 16i64 * v3[2]);
  v8 = (hkStringPtr *)(*(_QWORD *)v3 + 16i64 * v3[2]++);
  hkStringPtr::operator=(v8, v5);
  hkStringPtr::operator=(v7 + 1, v4);
}

// File Line: 78
// RVA: 0xE3C780
void __fastcall hkMemoryResourceHandle::removeExternalLink(hkMemoryResourceHandle *this, const char *memberName)
{
  int v2; // edi
  const char *v3; // rbp
  hkMemoryResourceHandle *v4; // rsi
  __int64 v5; // rbx
  signed __int64 v6; // r14
  hkStringPtr *v7; // rbx
  __int64 v8; // rcx
  hkMemoryResourceHandle::ExternalLink *v9; // rax
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  signed __int64 v12; // rax
  signed __int64 v13; // r8
  __int64 v14; // rcx

  v2 = 0;
  v3 = memberName;
  v4 = this;
  if ( this->m_references.m_size > 0 )
  {
    v5 = 0i64;
    while ( (unsigned int)hkString::strCmp(
                            (const char *)((_QWORD)v4->m_references.m_data[v5].m_memberName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                            v3) )
    {
      ++v2;
      ++v5;
      if ( v2 >= v4->m_references.m_size )
        return;
    }
    v6 = v2;
    v7 = &v4->m_references.m_data[v6].m_memberName;
    hkStringPtr::~hkStringPtr(v7 + 1);
    hkStringPtr::~hkStringPtr(v7);
    v8 = --v4->m_references.m_size;
    if ( (_DWORD)v8 != v2 )
    {
      v9 = v4->m_references.m_data;
      v10 = 2i64;
      v11 = (signed __int64)&v9[v8];
      v12 = (signed __int64)&v9[v6];
      v13 = v11 - v12;
      do
      {
        v14 = *(_QWORD *)(v13 + v12);
        v12 += 8i64;
        *(_QWORD *)(v12 - 8) = v14;
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 91
// RVA: 0xE3C860
void __fastcall hkMemoryResourceHandle::getExternalLinks(hkMemoryResourceHandle *this, hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *linksOut)
{
  int v2; // eax
  int v3; // er14
  hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *v4; // rbx
  int v5; // er9
  int v6; // eax
  hkMemoryResourceHandle *v7; // r13
  int v8; // eax
  hkRefVariant *v9; // rdx
  __int64 v10; // r15
  __int64 v11; // rcx
  hkResourceHandle::Link *v12; // r12
  hkReferencedObject *v13; // rbp
  const char *v14; // rdi
  hkClass *v15; // rsi
  char *v16; // rax
  int v17; // ebx
  int v18; // ebx
  hkClassMember *v19; // rax
  hkClassMember *v20; // rbx
  char *v21; // rax
  hkClassMember *v22; // rax
  void **v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkErrStream v26; // [rsp+30h] [rbp-468h]
  hkClassMemberAccessor v27; // [rsp+48h] [rbp-450h]
  char dst[512]; // [rsp+60h] [rbp-438h]
  char buf; // [rsp+260h] [rbp-238h]
  hkResult result; // [rsp+4A0h] [rbp+8h]
  hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *v31; // [rsp+4A8h] [rbp+10h]

  v31 = linksOut;
  v2 = linksOut->m_capacityAndFlags;
  v3 = 0;
  v4 = linksOut;
  linksOut->m_size = 0;
  v5 = this->m_references.m_size;
  v6 = v2 & 0x3FFFFFFF;
  v7 = this;
  if ( v6 < v5 )
  {
    v8 = 2 * v6;
    if ( v5 < v8 )
      v5 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, linksOut, v5, 32);
  }
  if ( v7->m_references.m_size > 0 )
  {
    v9 = &v7->m_variant;
    v10 = 0i64;
    while ( 1 )
    {
      v11 = v4->m_size;
      v12 = &v4->m_data[v11];
      v4->m_size = v11 + 1;
      v13 = v9->m_pntr;
      v14 = (const char *)((_QWORD)v7->m_references.m_data[v10].m_memberName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      v15 = hkRefVariant::getClass(v9);
      v16 = hkString::strChr(v14, 46);
      v17 = (signed int)v16;
      if ( v16 )
        break;
LABEL_11:
      v22 = hkClass::getMemberByName(v15, v14);
      if ( !v22 )
        goto LABEL_14;
      v12->m_memberName = v14;
      hkClassMemberAccessor::hkClassMemberAccessor(&v27, v13, v22);
      v4 = v31;
      v12->m_memberAccessor.m_address = *v23;
      v12->m_memberAccessor.m_member = (hkClassMember *)v23[1];
      v12->m_externalId = (const char *)((_QWORD)v7->m_references.m_data[v10].m_externalId.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
LABEL_15:
      ++v3;
      ++v10;
      v9 = &v7->m_variant;
      if ( v3 >= v7->m_references.m_size )
        return;
    }
    while ( 1 )
    {
      v18 = v17 - (_DWORD)v14;
      hkString::memCpy(dst, v14, v18);
      dst[v18] = 0;
      v14 += v18 + 1;
      v19 = hkClass::getMemberByName(v15, dst);
      v20 = v19;
      if ( !v19 )
        break;
      if ( v19->m_type.m_storage != 25 )
      {
        hkErrStream::hkErrStream(&v26, &buf, 512);
        v24 = hkOstream::operator<<((hkOstream *)&v26.vfptr, "Member is not of type struct : ");
        hkOstream::operator<<(v24, dst);
        hkError::messageWarning(-265097730, &buf, "ResourceDatabase\\hkResourceHandle.cpp", 128);
        hkOstream::~hkOstream((hkOstream *)&v26.vfptr);
        break;
      }
      v15 = hkClassMember::getClass(v19);
      v13 = (hkReferencedObject *)((char *)v13 + v20->m_offset);
      v21 = hkString::strChr(v14, 46);
      v17 = (signed int)v21;
      if ( !v21 )
        goto LABEL_11;
    }
LABEL_14:
    v4 = v31;
    --v4->m_size;
    hkErrStream::hkErrStream(&v26, &buf, 512);
    v25 = hkOstream::operator<<((hkOstream *)&v26.vfptr, "Cannot find member : ");
    hkOstream::operator<<(v25, v14);
    hkError::messageWarning(-265097743, &buf, "ResourceDatabase\\hkResourceHandle.cpp", 146);
    hkOstream::~hkOstream((hkOstream *)&v26.vfptr);
    goto LABEL_15;
  }
}

// File Line: 154
// RVA: 0xE3C000
void __fastcall hkResourceHandle::tryToResolveLinks(hkResourceHandle *this, hkResourceMap *map)
{
  hkResourceMap *v2; // r13
  hkBaseObjectVtbl *v3; // rax
  hkResourceHandle *v4; // r14
  __int64 v5; // rbx
  signed __int64 v6; // r15
  char *v7; // rsi
  void *v8; // rdi
  hkClassMemberAccessor *v9; // rbp
  hkClassMember *v10; // r12
  hkClass *v11; // rsi
  const char *v12; // rsi
  const char *v13; // rdi
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  char *v17; // [rsp+20h] [rbp-268h]
  int v18; // [rsp+28h] [rbp-260h]
  int v19; // [rsp+2Ch] [rbp-25Ch]
  hkErrStream v20; // [rsp+30h] [rbp-258h]
  char buf; // [rsp+50h] [rbp-238h]
  hkBool result; // [rsp+290h] [rbp+8h]
  hkClass *k; // [rsp+2A0h] [rbp+18h]

  v2 = map;
  v17 = 0i64;
  v18 = 0;
  v3 = this->vfptr;
  v4 = this;
  v19 = 2147483648;
  ((void (__fastcall *)(hkResourceHandle *, char **))v3[5].__first_virtual_table_function__)(this, &v17);
  v5 = v18 - 1;
  if ( v18 - 1 >= 0 )
  {
    v6 = 32i64 * (v18 - 1);
    do
    {
      v7 = v17;
      v8 = (void *)v2->vfptr->findObjectByName(v2, *(const char **)&v17[v6 + 8], &k);
      if ( v8 )
      {
        v9 = (hkClassMemberAccessor *)&v7[v6];
        v10 = hkClassMemberAccessor::getClassMember((hkClassMemberAccessor *)&v7[v6 + 16]);
        v11 = hkClassMember::getClass(v10);
        if ( hkClass::isSuperClass(v11, &result, k)->m_bool || k == v11 )
        {
          if ( v8 == (void *)((__int64 (__fastcall *)(hkResourceHandle *))v4->vfptr[3].__vecDelDtor)(v4) )
            break;
          *hkClassMemberAccessor::asPointer(v9 + 1, 0) = v8;
          v4->vfptr[5].__vecDelDtor((hkBaseObject *)&v4->vfptr, (unsigned int)v10->m_name);
        }
        else
        {
          hkErrStream::hkErrStream(&v20, &buf, 512);
          v12 = hkClass::getName(v11);
          v13 = hkClass::getName(k);
          v14 = hkOstream::operator<<((hkOstream *)&v20.vfptr, "Class mismatch, cannot resolve link: ");
          v15 = hkOstream::operator<<(v14, v13);
          v16 = hkOstream::operator<<(v15, " != ");
          hkOstream::operator<<(v16, v12);
          hkError::messageWarning(-264966879, &buf, "ResourceDatabase\\hkResourceHandle.cpp", 178);
          hkOstream::~hkOstream((hkOstream *)&v20.vfptr);
        }
      }
      v6 -= 32i64;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v17,
      32 * v19);
}

// File Line: 198
// RVA: 0xE3C470
void __fastcall hkResourceContainer::tryToResolveLinks(hkResourceContainer *this, hkResourceMap *map)
{
  hkResourceMap *v2; // rsi
  int v3; // edi
  __int64 v4; // rbx
  hkArray<hkResourceHandle *,hkContainerHeapAllocator> resourcesOut; // [rsp+20h] [rbp-18h]

  v2 = map;
  resourcesOut.m_data = 0i64;
  resourcesOut.m_size = 0;
  resourcesOut.m_capacityAndFlags = 2147483648;
  hkResourceContainer::findAllResourceRecursively(this, &resourcesOut);
  v3 = 0;
  if ( resourcesOut.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ((void (__fastcall *)(hkResourceHandle *, hkResourceMap *))resourcesOut.m_data[v4]->vfptr[6].__first_virtual_table_function__)(
        resourcesOut.m_data[v4],
        v2);
      ++v3;
      ++v4;
    }
    while ( v3 < resourcesOut.m_size );
  }
  resourcesOut.m_size = 0;
  if ( resourcesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      resourcesOut.m_data,
      8 * resourcesOut.m_capacityAndFlags);
}

// File Line: 209
// RVA: 0xE3C3B0
void __fastcall hkResourceContainer::getPath(hkResourceContainer *this, hkStringBuf *pathOut)
{
  hkStringBuf *v2; // rdi
  hkResourceContainer *v3; // rbx
  hkResourceContainer *v4; // rax
  hkBaseObjectVtbl *v5; // rax
  const char *v6; // rbx
  char *v7; // [rsp+20h] [rbp-98h]
  int v8; // [rsp+28h] [rbp-90h]
  int v9; // [rsp+2Ch] [rbp-8Ch]
  char v10; // [rsp+30h] [rbp-88h]

  v2 = pathOut;
  v3 = this;
  v4 = (hkResourceContainer *)((__int64 (*)(void))this->vfptr[4].__first_virtual_table_function__)();
  if ( v4 )
    hkResourceContainer::getPath(v4, v2);
  v7 = &v10;
  v5 = v3->vfptr;
  v9 = -2147483520;
  v8 = 1;
  v10 = 0;
  v6 = (const char *)v5[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)&v7);
  hkStringBuf::operator+=(v2, "/");
  hkStringBuf::operator+=(v2, v6);
  v8 = 0;
  if ( v9 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v7,
      v9 & 0x3FFFFFFF);
}

// File Line: 224
// RVA: 0xE3C240
void __fastcall hkResourceContainer::findAllResourceRecursively(hkResourceContainer *this, hkArray<hkResourceHandle *,hkContainerHeapAllocator> *resourcesOut)
{
  hkArray<hkResourceHandle *,hkContainerHeapAllocator> *v2; // rbx
  hkResourceContainer *v3; // rsi
  hkResourceContainer *i; // rdi
  __int64 j; // rdi

  v2 = resourcesOut;
  v3 = this;
  for ( i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
                                     this,
                                     0i64,
                                     0i64);
        i;
        i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, hkResourceContainer *))v3->vfptr[6].__first_virtual_table_function__)(
                                     v3,
                                     0i64,
                                     i) )
  {
    hkResourceContainer::findAllResourceRecursively(i, v2);
  }
  for ( j = ((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD, _QWORD))v3->vfptr[4].__vecDelDtor)(
              v3,
              0i64,
              0i64,
              0i64);
        j;
        j = ((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD, __int64))v3->vfptr[4].__vecDelDtor)(
              v3,
              0i64,
              0i64,
              j) )
  {
    if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
    v2->m_data[v2->m_size++] = (hkResourceHandle *)j;
  }
}

// File Line: 237
// RVA: 0xE3C310
void __fastcall hkResourceContainer::findAllContainersRecursively(hkResourceContainer *this, hkArray<hkResourceContainer *,hkContainerHeapAllocator> *resourcesOut)
{
  hkArray<hkResourceContainer *,hkContainerHeapAllocator> *v2; // rdi
  hkResourceContainer *v3; // rsi
  hkResourceContainer *i; // rbx

  v2 = resourcesOut;
  v3 = this;
  if ( resourcesOut->m_size == (resourcesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, resourcesOut, 8);
  v2->m_data[v2->m_size++] = v3;
  for ( i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD))v3->vfptr[6].__first_virtual_table_function__)(
                                     v3,
                                     0i64,
                                     0i64);
        i;
        i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, hkResourceContainer *))v3->vfptr[6].__first_virtual_table_function__)(
                                     v3,
                                     0i64,
                                     i) )
  {
    hkResourceContainer::findAllContainersRecursively(i, v2);
  }
}

// File Line: 248
// RVA: 0xE3CB80
void __fastcall hkMemoryResourceContainer::hkMemoryResourceContainer(hkMemoryResourceContainer *this, const char *name)
{
  hkMemoryResourceContainer *v2; // rbx

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceContainer::`vftable';
  hkStringPtr::hkStringPtr(&this->m_name, name);
  v2->m_parent = 0i64;
  v2->m_resourceHandles.m_data = 0i64;
  v2->m_resourceHandles.m_size = 0;
  v2->m_resourceHandles.m_capacityAndFlags = 2147483648;
  v2->m_children.m_data = 0i64;
  v2->m_children.m_size = 0;
  v2->m_children.m_capacityAndFlags = 2147483648;
}

// File Line: 252
// RVA: 0xE3CBE0
void __fastcall hkMemoryResourceContainer::hkMemoryResourceContainer(hkMemoryResourceContainer *this, hkFinishLoadedObjectFlag flag)
{
  hkMemoryResourceContainer *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edx
  __int64 v5; // r8
  int v6; // [rsp+38h] [rbp+10h]

  v6 = flag.m_finishing;
  v2 = this;
  v3 = &this->m_name;
  v3[-2].m_stringAndFlag = (const char *)&hkMemoryResourceContainer::`vftable';
  hkStringPtr::hkStringPtr(v3, flag);
  if ( v6 )
  {
    v4 = 0;
    if ( v2->m_children.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        ++v4;
        ++v5;
        v2->m_children.m_data[v5 - 1].m_pntr->m_parent = v2;
      }
      while ( v4 < v2->m_children.m_size );
    }
  }
}

// File Line: 264
// RVA: 0xE3CC40
void __fastcall hkMemoryResourceContainer::~hkMemoryResourceContainer(hkMemoryResourceContainer *this)
{
  hkMemoryResourceContainer *v1; // rdi
  hkRefPtr<hkMemoryResourceContainer> *v2; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *v5; // rcx
  int v6; // er8
  hkRefPtr<hkMemoryResourceHandle> *v7; // rsi
  int v8; // eax
  __int64 j; // rbx
  hkReferencedObject *v10; // rcx
  int v11; // er8

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceContainer::`vftable';
  v2 = this->m_children.m_data;
  v3 = this->m_children.m_size - 1;
  for ( i = v3; i >= 0; v2[i--].m_pntr = 0i64 )
  {
    v5 = (hkReferencedObject *)&v2[i].m_pntr->vfptr;
    if ( v5 )
      hkReferencedObject::removeReference(v5);
  }
  v6 = v1->m_children.m_capacityAndFlags;
  v1->m_children.m_size = 0;
  if ( v6 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_children.m_data,
      8 * v6);
  v1->m_children.m_data = 0i64;
  v1->m_children.m_capacityAndFlags = 2147483648;
  v7 = v1->m_resourceHandles.m_data;
  v8 = v1->m_resourceHandles.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = (hkReferencedObject *)&v7[j].m_pntr->vfptr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = v1->m_resourceHandles.m_capacityAndFlags;
  v1->m_resourceHandles.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_resourceHandles.m_data,
      8 * v11);
  v1->m_resourceHandles.m_data = 0i64;
  v1->m_resourceHandles.m_capacityAndFlags = 2147483648;
  hkStringPtr::~hkStringPtr(&v1->m_name);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 269
// RVA: 0xE3CD60
hkReferencedObject *__fastcall hkMemoryResourceContainer::createResource(hkMemoryResourceContainer *this, const char *name, void *object, hkClass *klass)
{
  hkMemoryResourceContainer *v4; // r14
  hkClass *v5; // rdi
  void *v6; // rsi
  const char *v7; // rbp
  _QWORD **v8; // rax
  hkMemoryResourceHandle *v9; // rax
  hkReferencedObject *v10; // rax
  hkReferencedObject *v11; // rbx
  _QWORD *v12; // rsi

  v4 = this;
  v5 = klass;
  v6 = object;
  v7 = name;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkMemoryResourceHandle *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  if ( v9 )
  {
    hkMemoryResourceHandle::hkMemoryResourceHandle(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  ((void (__fastcall *)(hkReferencedObject *, const char *))v11->vfptr[2].__first_virtual_table_function__)(v11, v7);
  ((void (__fastcall *)(hkReferencedObject *, void *, hkClass *))v11->vfptr[4].__vecDelDtor)(v11, v6, v5);
  hkReferencedObject::addReference(v11);
  if ( v4->m_resourceHandles.m_size == (v4->m_resourceHandles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_resourceHandles, 8);
  v12 = &v4->m_resourceHandles.m_data[v4->m_resourceHandles.m_size].m_pntr;
  if ( v12 )
  {
    hkReferencedObject::addReference(v11);
    *v12 = v11;
  }
  ++v4->m_resourceHandles.m_size;
  hkReferencedObject::removeReference(v11);
  hkReferencedObject::removeReference(v11);
  return v11;
}

// File Line: 281
// RVA: 0xE3CE60
hkMemoryResourceHandle *__fastcall hkMemoryResourceContainer::findResourceByName(hkMemoryResourceContainer *this, const char *objectName, hkClass *klass, hkResourceHandle *prevObject)
{
  hkClass *v4; // r15
  const char *v5; // r12
  int v6; // ebx
  __int64 v7; // r10
  hkMemoryResourceContainer *v8; // rdi
  hkResourceHandle **v9; // rcx
  signed __int64 v10; // r14
  hkRefPtr<hkMemoryResourceHandle> *v11; // rax
  hkMemoryResourceHandle *v12; // rsi
  hkMemoryResourceHandle *v13; // rcx
  hkBaseObjectVtbl *v14; // rax
  const char *v15; // rax
  int v16; // eax
  hkClass *v17; // rax
  hkClass *v18; // rbp
  const char *v20; // rdi
  const char *v21; // rbx
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkErrStream v25; // [rsp+20h] [rbp-2D8h]
  char *v26; // [rsp+40h] [rbp-2B8h]
  int v27; // [rsp+48h] [rbp-2B0h]
  int v28; // [rsp+4Ch] [rbp-2ACh]
  char v29; // [rsp+50h] [rbp-2A8h]
  char buf; // [rsp+D0h] [rbp-228h]
  hkBool result; // [rsp+300h] [rbp+8h]

  v4 = klass;
  v5 = objectName;
  v6 = 0;
  v7 = 0i64;
  v8 = this;
  do
  {
    if ( !prevObject )
      break;
    if ( v6 >= v8->m_resourceHandles.m_size )
      break;
    ++v6;
    v9 = (hkResourceHandle **)&v8->m_resourceHandles.m_data[v7];
    ++v7;
  }
  while ( *v9 != prevObject );
  if ( v6 >= v8->m_resourceHandles.m_size )
    return 0i64;
  v10 = v6;
  while ( 1 )
  {
    v11 = v8->m_resourceHandles.m_data;
    v12 = v11[v10].m_pntr;
    if ( v5 )
    {
      v13 = v11[v10].m_pntr;
      v26 = &v29;
      v14 = v12->vfptr;
      v28 = -2147483520;
      v27 = 1;
      v29 = 0;
      v15 = (const char *)v14[2].__vecDelDtor((hkBaseObject *)&v13->vfptr, (unsigned int)&v26);
      v16 = hkString::strCmp(v5, v15);
      v27 = 0;
      if ( v16 )
      {
        if ( v28 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v26,
            v28 & 0x3FFFFFFF);
        goto LABEL_17;
      }
      if ( v28 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v26,
          v28 & 0x3FFFFFFF);
    }
    if ( !v4 )
      return v12;
    v17 = (hkClass *)((__int64 (__fastcall *)(hkMemoryResourceHandle *))v12->vfptr[3].__first_virtual_table_function__)(v12);
    v18 = v17;
    if ( v4 == v17 || hkClass::isSuperClass(v4, &result, v17)->m_bool )
      return v12;
    if ( v5 )
    {
      hkErrStream::hkErrStream(&v25, &buf, 512);
      v20 = hkClass::getName(v18);
      v21 = hkClass::getName(v4);
      v22 = hkOstream::operator<<((hkOstream *)&v25.vfptr, "Class mismatch, cannot resolve link: ");
      v23 = hkOstream::operator<<(v22, v21);
      v24 = hkOstream::operator<<(v23, " != ");
      hkOstream::operator<<(v24, v20);
      hkError::messageWarning(-264966878, &buf, "ResourceDatabase\\hkResourceHandle.cpp", 312);
      hkOstream::~hkOstream((hkOstream *)&v25.vfptr);
      return 0i64;
    }
LABEL_17:
    ++v6;
    ++v10;
    if ( v6 >= v8->m_resourceHandles.m_size )
      return 0i64;
  }
}

// File Line: 326
// RVA: 0xE3D090
void __fastcall hkMemoryResourceContainer::destroyResource(hkMemoryResourceContainer *this, hkResourceHandle *resourceHandle)
{
  hkResourceHandle *v2; // rdi
  hkMemoryResourceContainer *v3; // rsi
  __int64 v4; // rcx
  signed int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkMemoryResourceHandle> *v7; // rax
  hkRefPtr<hkMemoryResourceHandle> *v8; // r14
  hkReferencedObject *v9; // rcx
  signed __int64 v10; // rdi
  hkRefPtr<hkMemoryResourceHandle> *v11; // rax
  int v12; // ecx
  __int64 v13; // rdx
  hkMemoryResourceHandle *v14; // rcx

  v2 = resourceHandle;
  v3 = this;
  if ( resourceHandle )
    hkReferencedObject::addReference((hkReferencedObject *)&resourceHandle->vfptr);
  v4 = v3->m_resourceHandles.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    v7 = v3->m_resourceHandles.m_data;
    while ( (hkResourceHandle *)v7->m_pntr != v2 )
    {
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_7;
    }
  }
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  if ( v5 > -1 )
  {
    v8 = v3->m_resourceHandles.m_data;
    v9 = (hkReferencedObject *)&v8[v5].m_pntr->vfptr;
    v10 = v5;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v8[v10].m_pntr = 0i64;
    --v3->m_resourceHandles.m_size;
    v11 = &v3->m_resourceHandles.m_data[v10];
    v12 = 8 * (v3->m_resourceHandles.m_size - v5);
    if ( v12 > 0 )
    {
      v13 = ((unsigned int)(v12 - 1) >> 3) + 1;
      do
      {
        v14 = v11[1].m_pntr;
        ++v11;
        v11[-1].m_pntr = v14;
        --v13;
      }
      while ( v13 );
    }
  }
}

// File Line: 336
// RVA: 0xE3CD50
const char *__fastcall hkMemoryResourceContainer::getName(hkMemoryResourceContainer *this, hkStringBuf *buffer)
{
  return (const char *)((_QWORD)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 341
// RVA: 0xE3D170
hkResourceContainer *__fastcall hkMemoryResourceContainer::createContainer(hkMemoryResourceContainer *this, const char *name)
{
  const char *v2; // rbx
  hkMemoryResourceContainer *v3; // rsi
  hkResourceContainer *result; // rax
  _QWORD **v5; // rax
  hkMemoryResourceContainer *v6; // rax
  hkReferencedObject *v7; // rax
  hkReferencedObject *v8; // rbx
  hkRefPtr<hkMemoryResourceContainer> *v9; // r14

  v2 = name;
  v3 = this;
  result = (hkResourceContainer *)((__int64 (__fastcall *)(hkMemoryResourceContainer *, const char *, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
                                    this,
                                    name,
                                    0i64);
  if ( !result )
  {
    v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkMemoryResourceContainer *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                        v5[11],
                                        64i64);
    if ( v6 )
    {
      hkMemoryResourceContainer::hkMemoryResourceContainer(v6, v2);
      v8 = v7;
      if ( v7 )
        hkReferencedObject::addReference(v7);
    }
    else
    {
      v8 = 0i64;
    }
    if ( v3->m_children.m_size == (v3->m_children.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_children, 8);
    v9 = &v3->m_children.m_data[v3->m_children.m_size];
    if ( v9 )
    {
      if ( v8 )
        hkReferencedObject::addReference(v8);
      v9->m_pntr = (hkMemoryResourceContainer *)v8;
    }
    ++v3->m_children.m_size;
    if ( v8 )
      hkReferencedObject::removeReference(v8);
    *(_QWORD *)&v8[1].m_memSizeAndFlags = v3;
    hkReferencedObject::removeReference(v8);
    result = (hkResourceContainer *)v8;
  }
  return result;
}

// File Line: 359
// RVA: 0xE3D260
void __fastcall hkMemoryResourceContainer::destroyContainer(hkMemoryResourceContainer *this, hkResourceContainer *container2)
{
  hkResourceContainer *v2; // rdi
  hkMemoryResourceContainer *v3; // rsi
  __int64 v4; // rcx
  signed int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkMemoryResourceContainer> *v7; // rax
  hkRefPtr<hkMemoryResourceContainer> *v8; // rdi
  hkReferencedObject *v9; // rcx
  signed __int64 v10; // r14
  __int64 v11; // rax

  v2 = container2;
  v3 = this;
  if ( container2 )
    hkReferencedObject::addReference((hkReferencedObject *)&container2->vfptr);
  v4 = v3->m_children.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    v7 = v3->m_children.m_data;
    while ( (hkResourceContainer *)v7->m_pntr != v2 )
    {
      ++v6;
      ++v5;
      ++v7;
      if ( v6 >= v4 )
        goto LABEL_7;
    }
  }
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  if ( v5 > -1 )
  {
    v8 = v3->m_children.m_data;
    v9 = (hkReferencedObject *)&v8[v5].m_pntr->vfptr;
    v10 = v5;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v8[v10].m_pntr = 0i64;
    v11 = --v3->m_children.m_size;
    if ( (_DWORD)v11 != v5 )
      v3->m_children.m_data[v10].m_pntr = v3->m_children.m_data[v11].m_pntr;
  }
}

// File Line: 369
// RVA: 0xE3D320
__int64 __fastcall hkMemoryResourceContainer::getNumContainers(hkMemoryResourceContainer *this)
{
  return (unsigned int)this->m_children.m_size;
}

// File Line: 374
// RVA: 0xE3D560
hkMemoryResourceContainer *__fastcall hkMemoryResourceContainer::findContainerByName(hkMemoryResourceContainer *this, const char *containerName, hkResourceContainer *prevContainer)
{
  int v3; // ebx
  const char *v4; // r14
  hkMemoryResourceContainer *v5; // rdi
  __int64 v6; // r9
  hkResourceContainer **v7; // rcx
  signed __int64 v8; // rsi
  hkMemoryResourceContainer *v9; // rbp

  v3 = 0;
  v4 = containerName;
  v5 = this;
  v6 = 0i64;
  do
  {
    if ( !prevContainer )
      break;
    if ( v3 >= v5->m_children.m_size )
      break;
    ++v3;
    v7 = (hkResourceContainer **)&v5->m_children.m_data[v6];
    ++v6;
  }
  while ( *v7 != prevContainer );
  if ( v3 >= v5->m_children.m_size )
    return 0i64;
  v8 = v3;
  while ( 1 )
  {
    v9 = v5->m_children.m_data[v8].m_pntr;
    if ( !v4
      || !(unsigned int)hkString::strCmp(
                          v4,
                          (const char *)((_QWORD)v9->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
    {
      break;
    }
    ++v3;
    ++v8;
    if ( v3 >= v5->m_children.m_size )
      return 0i64;
  }
  return v9;
}

// File Line: 399
// RVA: 0xE3D330
hkResult *__fastcall hkMemoryResourceContainer::parentTo(hkMemoryResourceContainer *this, hkResult *result, hkResourceContainer *newParent)
{
  hkResourceContainer *v3; // rbp
  hkResult *v4; // r12
  hkMemoryResourceContainer *v5; // rbx
  hkResourceContainer *v6; // rax
  hkMemoryResourceContainer *v7; // rax
  signed int v8; // edi
  __int64 v9; // rcx
  __int64 v10; // rdx
  hkMemoryResourceContainer **v11; // rax
  hkMemoryResourceContainer *v12; // rsi
  hkRefPtr<hkMemoryResourceContainer> *v13; // r15
  signed __int64 v14; // r14
  hkReferencedObject *v15; // rcx
  signed __int64 v16; // rcx
  int v17; // edx
  __int64 v18; // rdx
  __int64 v19; // rax
  hkMemoryResourceContainer **v20; // rsi
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkErrStream v26; // [rsp+20h] [rbp-238h]
  char buf; // [rsp+40h] [rbp-218h]

  v3 = newParent;
  v4 = result;
  v5 = this;
  v6 = newParent;
  if ( newParent )
  {
    while ( v6 != (hkResourceContainer *)v5 )
    {
      v6 = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *))v6->vfptr[4].__first_virtual_table_function__)(v6);
      if ( !v6 )
        goto LABEL_4;
    }
    hkErrStream::hkErrStream(&v26, &buf, 512);
    v22 = hkOstream::operator<<((hkOstream *)&v26.vfptr, "Cannot parent '");
    v23 = hkOstream::operator<<(v22, &v5->m_name);
    v24 = hkOstream::operator<<(v23, "' to '");
    v25 = hkOstream::operator<<(v24, (hkStringPtr *)&v3[1]);
    hkOstream::operator<<(v25, "' as this would create a circular dependency ");
    hkError::messageWarning(-1413855916, &buf, "ResourceDatabase\\hkResourceHandle.cpp", 408);
    hkOstream::~hkOstream((hkOstream *)&v26.vfptr);
    v4->m_enum = 1;
  }
  else
  {
LABEL_4:
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
    if ( v5 )
      hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
    v7 = v5->m_parent;
    v8 = 0;
    v9 = 0i64;
    v10 = v7->m_children.m_size;
    if ( v10 <= 0 )
    {
LABEL_10:
      v8 = -1;
    }
    else
    {
      v11 = &v7->m_children.m_data->m_pntr;
      while ( *v11 != v5 )
      {
        ++v9;
        ++v8;
        ++v11;
        if ( v9 >= v10 )
          goto LABEL_10;
      }
    }
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    v12 = v5->m_parent;
    v13 = v12->m_children.m_data;
    v14 = v8;
    v15 = (hkReferencedObject *)&v13[v14].m_pntr->vfptr;
    if ( v15 )
      hkReferencedObject::removeReference(v15);
    v13[v14].m_pntr = 0i64;
    --v12->m_children.m_size;
    v16 = (signed __int64)&v12->m_children.m_data[v14];
    v17 = 8 * (v12->m_children.m_size - v8);
    if ( v17 > 0 )
    {
      v18 = ((unsigned int)(v17 - 1) >> 3) + 1;
      do
      {
        v19 = *(_QWORD *)(v16 + 8);
        v16 += 8i64;
        *(_QWORD *)(v16 - 8) = v19;
        --v18;
      }
      while ( v18 );
    }
    hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
    if ( *(_DWORD *)&v3[3].m_memSizeAndFlags == (*(_DWORD *)(&v3[3].m_referenceCount + 1) & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3[3], 8);
    v20 = (hkMemoryResourceContainer **)(&v3[3].vfptr->__vecDelDtor + *(signed int *)&v3[3].m_memSizeAndFlags);
    if ( v20 )
    {
      hkReferencedObject::addReference((hkReferencedObject *)&v5->vfptr);
      *v20 = v5;
    }
    ++*(_DWORD *)&v3[3].m_memSizeAndFlags;
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    v5->m_parent = (hkMemoryResourceContainer *)v3;
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    v4->m_enum = 0;
  }
  return v4;
}

// File Line: 430
// RVA: 0xE3D610
void __fastcall hkContainerResourceMap::hkContainerResourceMap(hkContainerResourceMap *this, hkResourceContainer *container)
{
  hkResourceContainer *v2; // rbx
  hkContainerResourceMap *v3; // r14
  int v4; // edi
  __int64 v5; // rsi
  hkResourceHandle *v6; // rbx
  unsigned __int64 v7; // rax
  hkArray<hkResourceHandle *,hkContainerHeapAllocator> resourcesOut; // [rsp+20h] [rbp-B8h]
  char *v9; // [rsp+30h] [rbp-A8h]
  int v10; // [rsp+38h] [rbp-A0h]
  int v11; // [rsp+3Ch] [rbp-9Ch]
  char v12; // [rsp+40h] [rbp-98h]

  v2 = container;
  this->vfptr = (hkResourceMapVtbl *)&hkContainerResourceMap::`vftable';
  v3 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_resources.m_map,
    0);
  resourcesOut.m_data = 0i64;
  resourcesOut.m_size = 0;
  resourcesOut.m_capacityAndFlags = 2147483648;
  hkResourceContainer::findAllResourceRecursively(v2, &resourcesOut);
  v4 = 0;
  if ( resourcesOut.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = resourcesOut.m_data[v5];
      v11 = -2147483520;
      v9 = &v12;
      v10 = 1;
      v12 = 0;
      v7 = (__int64)v6->vfptr[2].__vecDelDtor((hkBaseObject *)&v6->vfptr, (unsigned int)&v9);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v3->m_resources.m_map,
        v7,
        (unsigned __int64)v6);
      v10 = 0;
      if ( v11 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
          v9,
          v11 & 0x3FFFFFFF);
      ++v4;
      ++v5;
    }
    while ( v4 < resourcesOut.m_size );
  }
  resourcesOut.m_size = 0;
  if ( resourcesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      resourcesOut.m_data,
      8 * resourcesOut.m_capacityAndFlags);
}

// File Line: 445
// RVA: 0xE3D780
void *__fastcall hkContainerResourceMap::findObjectByName(hkContainerResourceMap *this, const char *objectName, hkClass **klassOut)
{
  hkClass **v3; // rbx
  void *result; // rax
  void *v5; // rdi

  v3 = klassOut;
  if ( klassOut )
    *klassOut = 0i64;
  result = (void *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                     (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_resources,
                     (unsigned __int64)objectName,
                     0i64);
  v5 = result;
  if ( result )
  {
    if ( v3 )
      *v3 = (hkClass *)(*(__int64 (__fastcall **)(void *))(*(_QWORD *)result + 56i64))(result);
    result = (void *)(*(__int64 (__fastcall **)(void *))(*(_QWORD *)v5 + 48i64))(v5);
  }
  return result;
}

