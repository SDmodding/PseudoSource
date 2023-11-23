// File Line: 15
// RVA: 0xE3C530
void __fastcall hkMemoryResourceHandle::hkMemoryResourceHandle(hkMemoryResourceHandle *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceHandle::`vftable;
  this->m_variant.m_pntr = 0i64;
  hkStringPtr::hkStringPtr(&this->m_name);
  this->m_references.m_data = 0i64;
  this->m_references.m_size = 0;
  this->m_references.m_capacityAndFlags = 0x80000000;
}

// File Line: 21
// RVA: 0xE3C580
void __fastcall hkMemoryResourceHandle::hkMemoryResourceHandle(
        hkMemoryResourceHandle *this,
        hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *p_m_name; // rcx

  p_m_name = &this->m_name;
  p_m_name[-3].m_stringAndFlag = (const char *)&hkMemoryResourceHandle::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, flag);
}

// File Line: 26
// RVA: 0xE3C5B0
void __fastcall hkMemoryResourceHandle::~hkMemoryResourceHandle(hkMemoryResourceHandle *this)
{
  int m_size; // edi
  hkMemoryResourceHandle::ExternalLink *m_data; // rcx
  int v4; // edi
  hkStringPtr *p_m_memberName; // rbx
  int m_capacityAndFlags; // r8d
  hkReferencedObject *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceHandle::`vftable;
  m_size = this->m_references.m_size;
  m_data = this->m_references.m_data;
  v4 = m_size - 1;
  if ( v4 >= 0 )
  {
    p_m_memberName = &m_data[v4].m_memberName;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_memberName + 1);
      hkStringPtr::~hkStringPtr(p_m_memberName);
      p_m_memberName -= 2;
      --v4;
    }
    while ( v4 >= 0 );
  }
  m_capacityAndFlags = this->m_references.m_capacityAndFlags;
  this->m_references.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_references.m_data,
      16 * m_capacityAndFlags);
  this->m_references.m_data = 0i64;
  this->m_references.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_name);
  m_pntr = this->m_variant.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_variant.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 31
// RVA: 0xE3CB20
void __fastcall hkMemoryResourceHandle::clearExternalLinks(hkMemoryResourceHandle *this)
{
  hkMemoryResourceHandle::ExternalLink *m_data; // rcx
  int v3; // edi
  hkStringPtr *p_m_memberName; // rbx

  m_data = this->m_references.m_data;
  v3 = this->m_references.m_size - 1;
  if ( v3 >= 0 )
  {
    p_m_memberName = &m_data[v3].m_memberName;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_memberName + 1);
      hkStringPtr::~hkStringPtr(p_m_memberName);
      p_m_memberName -= 2;
      --v3;
    }
    while ( v3 >= 0 );
  }
  this->m_references.m_size = 0;
}

// File Line: 37
// RVA: 0xE3C670
const char *__fastcall hkMemoryResourceHandle::getName(hkMemoryResourceHandle *this, hkStringBuf *buffer)
{
  const char *result; // rax

  result = (const char *)((unsigned __int64)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  if ( !result )
    return "null";
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
void __fastcall hkMemoryResourceHandle::addExternalLink(
        hkMemoryResourceHandle *this,
        const char *memberName,
        const char *externalId)
{
  hkArray<hkMemoryResourceHandle::ExternalLink,hkContainerHeapAllocator> *p_m_references; // rdi
  hkStringPtr *p_m_memberName; // rbx
  hkStringPtr *v7; // rbx

  p_m_references = &this->m_references;
  if ( this->m_references.m_size == (this->m_references.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_references->m_data, 16);
  p_m_memberName = &p_m_references->m_data[p_m_references->m_size].m_memberName;
  if ( p_m_memberName )
  {
    hkStringPtr::hkStringPtr(p_m_memberName);
    hkStringPtr::hkStringPtr(p_m_memberName + 1);
  }
  v7 = &p_m_references->m_data[p_m_references->m_size++].m_memberName;
  hkStringPtr::operator=(v7, memberName);
  hkStringPtr::operator=(v7 + 1, externalId);
}

// File Line: 78
// RVA: 0xE3C780
void __fastcall hkMemoryResourceHandle::removeExternalLink(hkMemoryResourceHandle *this, const char *memberName)
{
  int v2; // edi
  __int64 i; // rbx
  __int64 v6; // r14
  hkMemoryResourceHandle::ExternalLink *v7; // rbx
  __int64 v8; // rcx
  hkMemoryResourceHandle::ExternalLink *m_data; // rax
  __int64 v10; // rdx
  hkMemoryResourceHandle::ExternalLink *v11; // r8
  hkMemoryResourceHandle::ExternalLink *v12; // rax
  signed __int64 v13; // r8
  const char *v14; // rcx

  v2 = 0;
  if ( this->m_references.m_size > 0 )
  {
    for ( i = 0i64;
          (unsigned int)hkString::strCmp(
                          (const char *)((unsigned __int64)this->m_references.m_data[i].m_memberName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          memberName);
          ++i )
    {
      if ( ++v2 >= this->m_references.m_size )
        return;
    }
    v6 = v2;
    v7 = &this->m_references.m_data[v6];
    hkStringPtr::~hkStringPtr(&v7->m_externalId);
    hkStringPtr::~hkStringPtr(&v7->m_memberName);
    v8 = --this->m_references.m_size;
    if ( (_DWORD)v8 != v2 )
    {
      m_data = this->m_references.m_data;
      v10 = 2i64;
      v11 = &m_data[v8];
      v12 = &m_data[v6];
      v13 = (char *)v11 - (char *)v12;
      do
      {
        v14 = *(const char **)((char *)&v12->m_memberName.m_stringAndFlag + v13);
        v12 = (hkMemoryResourceHandle::ExternalLink *)((char *)v12 + 8);
        v12[-1].m_externalId.m_stringAndFlag = v14;
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 91
// RVA: 0xE3C860
void __fastcall hkMemoryResourceHandle::getExternalLinks(
        hkMemoryResourceHandle *this,
        hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *linksOut)
{
  int m_capacityAndFlags; // eax
  int v3; // r14d
  hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *v4; // rbx
  int m_size; // r9d
  int v6; // eax
  int v8; // eax
  hkRefVariant *p_m_variant; // rdx
  __int64 i; // r15
  __int64 v11; // r12
  int v12; // eax
  hkResourceHandle::Link *v13; // r12
  hkReferencedObject *m_pntr; // rbp
  const char *v15; // rdi
  hkClass *Class; // rsi
  char *v17; // rax
  int v18; // ebx
  unsigned int v19; // ebx
  hkClassMember *v20; // rax
  hkClassMember *v21; // rbx
  char *v22; // rax
  hkClassMember *MemberByName; // rax
  void **v24; // rax
  hkOstream *v25; // rax
  hkOstream *v26; // rax
  hkErrStream v27; // [rsp+30h] [rbp-468h] BYREF
  hkClassMemberAccessor v28; // [rsp+48h] [rbp-450h] BYREF
  char dst[512]; // [rsp+60h] [rbp-438h] BYREF
  char buf[512]; // [rsp+260h] [rbp-238h] BYREF
  hkResult result; // [rsp+4A0h] [rbp+8h] BYREF
  hkArray<hkResourceHandle::Link,hkContainerHeapAllocator> *v32; // [rsp+4A8h] [rbp+10h]

  v32 = linksOut;
  m_capacityAndFlags = linksOut->m_capacityAndFlags;
  v3 = 0;
  v4 = linksOut;
  linksOut->m_size = 0;
  m_size = this->m_references.m_size;
  v6 = m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v8 = 2 * v6;
    if ( m_size < v8 )
      m_size = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&linksOut->m_data, m_size, 32);
  }
  if ( this->m_references.m_size > 0 )
  {
    p_m_variant = &this->m_variant;
    for ( i = 0i64; ; ++i )
    {
      v11 = v4->m_size;
      v12 = v11 + 1;
      v13 = &v4->m_data[v11];
      v4->m_size = v12;
      m_pntr = p_m_variant->m_pntr;
      v15 = (const char *)((unsigned __int64)this->m_references.m_data[i].m_memberName.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      Class = hkRefVariant::getClass(p_m_variant);
      v17 = hkString::strChr(v15, 46);
      v18 = (int)v17;
      if ( v17 )
        break;
LABEL_11:
      MemberByName = hkClass::getMemberByName(Class, v15);
      if ( !MemberByName )
        goto LABEL_14;
      v13->m_memberName = v15;
      hkClassMemberAccessor::hkClassMemberAccessor(&v28, m_pntr, MemberByName);
      v4 = v32;
      v13->m_memberAccessor.m_address = *v24;
      v13->m_memberAccessor.m_member = (hkClassMember *)v24[1];
      v13->m_externalId = (const char *)((unsigned __int64)this->m_references.m_data[i].m_externalId.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
LABEL_15:
      ++v3;
      p_m_variant = &this->m_variant;
      if ( v3 >= this->m_references.m_size )
        return;
    }
    while ( 1 )
    {
      v19 = v18 - (_DWORD)v15;
      hkString::memCpy(dst, v15, v19);
      dst[v19] = 0;
      v15 += (int)(v19 + 1);
      v20 = hkClass::getMemberByName(Class, dst);
      v21 = v20;
      if ( !v20 )
        break;
      if ( v20->m_type.m_storage != 25 )
      {
        hkErrStream::hkErrStream(&v27, buf, 512);
        v25 = hkOstream::operator<<(&v27, "Member is not of type struct : ");
        hkOstream::operator<<(v25, dst);
        hkError::messageWarning(0xF032EDFE, buf, "ResourceDatabase\\hkResourceHandle.cpp", 128);
        hkOstream::~hkOstream(&v27);
        break;
      }
      Class = hkClassMember::getClass(v20);
      m_pntr = (hkReferencedObject *)((char *)m_pntr + v21->m_offset);
      v22 = hkString::strChr(v15, 46);
      v18 = (int)v22;
      if ( !v22 )
        goto LABEL_11;
    }
LABEL_14:
    v4 = v32;
    --v32->m_size;
    hkErrStream::hkErrStream(&v27, buf, 512);
    v26 = hkOstream::operator<<(&v27, "Cannot find member : ");
    hkOstream::operator<<(v26, v15);
    hkError::messageWarning(0xF032EDF1, buf, "ResourceDatabase\\hkResourceHandle.cpp", 146);
    hkOstream::~hkOstream(&v27);
    goto LABEL_15;
  }
}

// File Line: 154
// RVA: 0xE3C000
void __fastcall hkResourceHandle::tryToResolveLinks(hkResourceHandle *this, hkResourceMap *map)
{
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v5; // rbx
  __int64 v6; // r15
  char *v7; // rsi
  void *v8; // rdi
  hkClassMemberAccessor *v9; // rbp
  hkClassMember *ClassMember; // r12
  hkClass *Class; // rsi
  const char *Name; // rsi
  const char *v13; // rdi
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  char *v17; // [rsp+20h] [rbp-268h] BYREF
  int v18; // [rsp+28h] [rbp-260h]
  int v19; // [rsp+2Ch] [rbp-25Ch]
  hkErrStream v20; // [rsp+30h] [rbp-258h] BYREF
  char buf[512]; // [rsp+50h] [rbp-238h] BYREF
  hkBool result; // [rsp+290h] [rbp+8h] BYREF
  hkClass *k; // [rsp+2A0h] [rbp+18h] BYREF

  v17 = 0i64;
  v18 = 0;
  vfptr = this->vfptr;
  v19 = 0x80000000;
  ((void (__fastcall *)(hkResourceHandle *, char **))vfptr[5].__first_virtual_table_function__)(this, &v17);
  v5 = v18 - 1;
  if ( v18 - 1 >= 0 )
  {
    v6 = 32i64 * (v18 - 1);
    do
    {
      v7 = v17;
      v8 = (void *)map->vfptr->findObjectByName(map, *(const char **)&v17[v6 + 8], &k);
      if ( v8 )
      {
        v9 = (hkClassMemberAccessor *)&v7[v6];
        ClassMember = hkClassMemberAccessor::getClassMember((hkClassMemberAccessor *)&v7[v6 + 16]);
        Class = hkClassMember::getClass(ClassMember);
        if ( hkClass::isSuperClass(Class, &result, k)->m_bool || k == Class )
        {
          if ( v8 == (void *)((__int64 (__fastcall *)(hkResourceHandle *))this->vfptr[3].__vecDelDtor)(this) )
            break;
          *hkClassMemberAccessor::asPointer(v9 + 1, 0) = v8;
          this->vfptr[5].__vecDelDtor(this, (unsigned int)ClassMember->m_name);
        }
        else
        {
          hkErrStream::hkErrStream(&v20, buf, 512);
          Name = hkClass::getName(Class);
          v13 = hkClass::getName(k);
          v14 = hkOstream::operator<<(&v20, "Class mismatch, cannot resolve link: ");
          v15 = hkOstream::operator<<(v14, v13);
          v16 = hkOstream::operator<<(v15, " != ");
          hkOstream::operator<<(v16, Name);
          hkError::messageWarning(0xF034ED21, buf, "ResourceDatabase\\hkResourceHandle.cpp", 178);
          hkOstream::~hkOstream(&v20);
        }
      }
      v6 -= 32i64;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v18 = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v17, 32 * v19);
}

// File Line: 198
// RVA: 0xE3C470
void __fastcall hkResourceContainer::tryToResolveLinks(hkResourceContainer *this, hkResourceMap *map)
{
  int v3; // edi
  __int64 v4; // rbx
  hkArray<hkResourceHandle *,hkContainerHeapAllocator> resourcesOut; // [rsp+20h] [rbp-18h] BYREF

  resourcesOut.m_data = 0i64;
  resourcesOut.m_size = 0;
  resourcesOut.m_capacityAndFlags = 0x80000000;
  hkResourceContainer::findAllResourceRecursively(this, &resourcesOut);
  v3 = 0;
  if ( resourcesOut.m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      ((void (__fastcall *)(hkResourceHandle *, hkResourceMap *))resourcesOut.m_data[v4]->vfptr[6].__first_virtual_table_function__)(
        resourcesOut.m_data[v4],
        map);
      ++v3;
      ++v4;
    }
    while ( v3 < resourcesOut.m_size );
  }
  resourcesOut.m_size = 0;
  if ( resourcesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      resourcesOut.m_data,
      8 * resourcesOut.m_capacityAndFlags);
}

// File Line: 209
// RVA: 0xE3C3B0
void __fastcall hkResourceContainer::getPath(hkResourceContainer *this, hkStringBuf *pathOut)
{
  hkResourceContainer *v4; // rax
  hkBaseObjectVtbl *vfptr; // rax
  const char *v6; // rbx
  char *v7; // [rsp+20h] [rbp-98h] BYREF
  int v8; // [rsp+28h] [rbp-90h]
  int v9; // [rsp+2Ch] [rbp-8Ch]
  char v10; // [rsp+30h] [rbp-88h] BYREF

  v4 = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *))this->vfptr[4].__first_virtual_table_function__)(this);
  if ( v4 )
    hkResourceContainer::getPath(v4, pathOut);
  v7 = &v10;
  vfptr = this->vfptr;
  v9 = -2147483520;
  v8 = 1;
  v10 = 0;
  v6 = (const char *)vfptr[2].__vecDelDtor(this, (unsigned int)&v7);
  hkStringBuf::operator+=(pathOut, "/");
  hkStringBuf::operator+=(pathOut, v6);
  v8 = 0;
  if ( v9 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v7, v9 & 0x3FFFFFFF);
}

// File Line: 224
// RVA: 0xE3C240
void __fastcall hkResourceContainer::findAllResourceRecursively(
        hkResourceContainer *this,
        hkArray<hkResourceHandle *,hkContainerHeapAllocator> *resourcesOut)
{
  hkResourceContainer *i; // rdi
  hkResourceHandle *j; // rdi

  for ( i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
                                     this,
                                     0i64,
                                     0i64);
        i;
        i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, hkResourceContainer *))this->vfptr[6].__first_virtual_table_function__)(
                                     this,
                                     0i64,
                                     i) )
  {
    hkResourceContainer::findAllResourceRecursively(i, resourcesOut);
  }
  for ( j = (hkResourceHandle *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD, _QWORD))this->vfptr[4].__vecDelDtor)(
                                  this,
                                  0i64,
                                  0i64,
                                  0i64);
        j;
        j = (hkResourceHandle *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD, hkResourceHandle *))this->vfptr[4].__vecDelDtor)(
                                  this,
                                  0i64,
                                  0i64,
                                  j) )
  {
    if ( resourcesOut->m_size == (resourcesOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&resourcesOut->m_data, 8);
    resourcesOut->m_data[resourcesOut->m_size++] = j;
  }
}

// File Line: 237
// RVA: 0xE3C310
void __fastcall hkResourceContainer::findAllContainersRecursively(
        hkResourceContainer *this,
        hkArray<hkResourceContainer *,hkContainerHeapAllocator> *resourcesOut)
{
  hkResourceContainer *i; // rbx

  if ( resourcesOut->m_size == (resourcesOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&resourcesOut->m_data, 8);
  resourcesOut->m_data[resourcesOut->m_size++] = this;
  for ( i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
                                     this,
                                     0i64,
                                     0i64);
        i;
        i = (hkResourceContainer *)((__int64 (__fastcall *)(hkResourceContainer *, _QWORD, hkResourceContainer *))this->vfptr[6].__first_virtual_table_function__)(
                                     this,
                                     0i64,
                                     i) )
  {
    hkResourceContainer::findAllContainersRecursively(i, resourcesOut);
  }
}

// File Line: 248
// RVA: 0xE3CB80
void __fastcall hkMemoryResourceContainer::hkMemoryResourceContainer(hkMemoryResourceContainer *this, const char *name)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceContainer::`vftable;
  hkStringPtr::hkStringPtr(&this->m_name, name);
  this->m_parent = 0i64;
  this->m_resourceHandles.m_data = 0i64;
  this->m_resourceHandles.m_size = 0;
  this->m_resourceHandles.m_capacityAndFlags = 0x80000000;
  this->m_children.m_data = 0i64;
  this->m_children.m_size = 0;
  this->m_children.m_capacityAndFlags = 0x80000000;
}

// File Line: 252
// RVA: 0xE3CBE0
void __fastcall hkMemoryResourceContainer::hkMemoryResourceContainer(
        hkMemoryResourceContainer *this,
        hkFinishLoadedObjectFlag flag)
{
  hkStringPtr *p_m_name; // rcx
  int v4; // edx
  __int64 v5; // r8

  p_m_name = &this->m_name;
  p_m_name[-2].m_stringAndFlag = (const char *)&hkMemoryResourceContainer::`vftable;
  hkStringPtr::hkStringPtr(p_m_name, flag);
  if ( flag.m_finishing )
  {
    v4 = 0;
    if ( this->m_children.m_size > 0 )
    {
      v5 = 0i64;
      do
      {
        ++v4;
        this->m_children.m_data[v5++].m_pntr->m_parent = this;
      }
      while ( v4 < this->m_children.m_size );
    }
  }
}

// File Line: 264
// RVA: 0xE3CC40
void __fastcall hkMemoryResourceContainer::~hkMemoryResourceContainer(hkMemoryResourceContainer *this)
{
  hkRefPtr<hkMemoryResourceContainer> *m_data; // rsi
  int v3; // eax
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  int m_capacityAndFlags; // r8d
  hkRefPtr<hkMemoryResourceHandle> *v7; // rsi
  int v8; // eax
  __int64 j; // rbx
  hkReferencedObject *v10; // rcx
  int v11; // r8d

  this->vfptr = (hkBaseObjectVtbl *)&hkMemoryResourceContainer::`vftable;
  m_data = this->m_children.m_data;
  v3 = this->m_children.m_size - 1;
  for ( i = v3; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  m_capacityAndFlags = this->m_children.m_capacityAndFlags;
  this->m_children.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_children.m_data,
      8 * m_capacityAndFlags);
  this->m_children.m_data = 0i64;
  this->m_children.m_capacityAndFlags = 0x80000000;
  v7 = this->m_resourceHandles.m_data;
  v8 = this->m_resourceHandles.m_size - 1;
  for ( j = v8; j >= 0; v7[j--].m_pntr = 0i64 )
  {
    v10 = v7[j].m_pntr;
    if ( v10 )
      hkReferencedObject::removeReference(v10);
  }
  v11 = this->m_resourceHandles.m_capacityAndFlags;
  this->m_resourceHandles.m_size = 0;
  if ( v11 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_resourceHandles.m_data,
      8 * v11);
  this->m_resourceHandles.m_data = 0i64;
  this->m_resourceHandles.m_capacityAndFlags = 0x80000000;
  hkStringPtr::~hkStringPtr(&this->m_name);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 269
// RVA: 0xE3CD60
hkResourceHandle *__fastcall hkMemoryResourceContainer::createResource(
        hkMemoryResourceContainer *this,
        const char *name,
        void *object,
        hkClass *klass)
{
  _QWORD **Value; // rax
  hkMemoryResourceHandle *v9; // rax
  hkReferencedObject *v10; // rax
  hkReferencedObject *v11; // rbx
  hkRefPtr<hkMemoryResourceHandle> *v12; // rsi

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkMemoryResourceHandle *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v9 )
  {
    hkMemoryResourceHandle::hkMemoryResourceHandle(v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  ((void (__fastcall *)(hkReferencedObject *, const char *))v11->vfptr[2].__first_virtual_table_function__)(v11, name);
  ((void (__fastcall *)(hkReferencedObject *, void *, hkClass *))v11->vfptr[4].__vecDelDtor)(v11, object, klass);
  hkReferencedObject::addReference(v11);
  if ( this->m_resourceHandles.m_size == (this->m_resourceHandles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_resourceHandles.m_data, 8);
  v12 = &this->m_resourceHandles.m_data[this->m_resourceHandles.m_size];
  if ( v12 )
  {
    hkReferencedObject::addReference(v11);
    v12->m_pntr = (hkMemoryResourceHandle *)v11;
  }
  ++this->m_resourceHandles.m_size;
  hkReferencedObject::removeReference(v11);
  hkReferencedObject::removeReference(v11);
  return (hkResourceHandle *)v11;
}

// File Line: 281
// RVA: 0xE3CE60
hkMemoryResourceHandle *__fastcall hkMemoryResourceContainer::findResourceByName(
        hkMemoryResourceContainer *this,
        const char *objectName,
        hkClass *klass,
        hkMemoryResourceHandle *prevObject)
{
  int v6; // ebx
  __int64 v7; // r10
  hkRefPtr<hkMemoryResourceHandle> *v9; // rcx
  __int64 i; // r14
  hkRefPtr<hkMemoryResourceHandle> *m_data; // rax
  hkMemoryResourceHandle *m_pntr; // rsi
  hkMemoryResourceHandle *v13; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  const char *v15; // rax
  int v16; // eax
  hkClass *v17; // rax
  hkClass *v18; // rbp
  const char *Name; // rdi
  const char *v21; // rbx
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkErrStream v25; // [rsp+20h] [rbp-2D8h] BYREF
  char *v26; // [rsp+40h] [rbp-2B8h] BYREF
  int v27; // [rsp+48h] [rbp-2B0h]
  int v28; // [rsp+4Ch] [rbp-2ACh]
  char v29; // [rsp+50h] [rbp-2A8h] BYREF
  char buf[552]; // [rsp+D0h] [rbp-228h] BYREF
  hkBool result; // [rsp+300h] [rbp+8h] BYREF

  v6 = 0;
  v7 = 0i64;
  do
  {
    if ( !prevObject )
      break;
    if ( v6 >= this->m_resourceHandles.m_size )
      break;
    ++v6;
    v9 = &this->m_resourceHandles.m_data[v7++];
  }
  while ( v9->m_pntr != prevObject );
  if ( v6 >= this->m_resourceHandles.m_size )
    return 0i64;
  for ( i = v6; ; ++i )
  {
    m_data = this->m_resourceHandles.m_data;
    m_pntr = m_data[i].m_pntr;
    if ( objectName )
    {
      v13 = m_data[i].m_pntr;
      v26 = &v29;
      vfptr = m_pntr->vfptr;
      v28 = -2147483520;
      v27 = 1;
      v29 = 0;
      v15 = (const char *)vfptr[2].__vecDelDtor(v13, (unsigned int)&v26);
      v16 = hkString::strCmp(objectName, v15);
      v27 = 0;
      if ( v16 )
      {
        if ( v28 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v26, v28 & 0x3FFFFFFF);
        goto LABEL_17;
      }
      if ( v28 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v26, v28 & 0x3FFFFFFF);
    }
    if ( !klass )
      break;
    v17 = (hkClass *)((__int64 (__fastcall *)(hkMemoryResourceHandle *))m_pntr->vfptr[3].__first_virtual_table_function__)(m_pntr);
    v18 = v17;
    if ( klass == v17 || hkClass::isSuperClass(klass, &result, v17)->m_bool )
      break;
    if ( objectName )
    {
      hkErrStream::hkErrStream(&v25, buf, 512);
      Name = hkClass::getName(v18);
      v21 = hkClass::getName(klass);
      v22 = hkOstream::operator<<(&v25, "Class mismatch, cannot resolve link: ");
      v23 = hkOstream::operator<<(v22, v21);
      v24 = hkOstream::operator<<(v23, " != ");
      hkOstream::operator<<(v24, Name);
      hkError::messageWarning(0xF034ED22, buf, "ResourceDatabase\\hkResourceHandle.cpp", 312);
      hkOstream::~hkOstream(&v25);
      return 0i64;
    }
LABEL_17:
    if ( ++v6 >= this->m_resourceHandles.m_size )
      return 0i64;
  }
  return m_pntr;
}

// File Line: 326
// RVA: 0xE3D090
void __fastcall hkMemoryResourceContainer::destroyResource(
        hkMemoryResourceContainer *this,
        hkMemoryResourceHandle *resourceHandle)
{
  __int64 m_size; // rcx
  int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkMemoryResourceHandle> *m_data; // rax
  hkRefPtr<hkMemoryResourceHandle> *v8; // r14
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkMemoryResourceHandle> *v10; // rax
  int v11; // ecx
  __int64 v12; // rdx
  hkMemoryResourceHandle *v13; // rcx

  if ( resourceHandle )
    hkReferencedObject::addReference(resourceHandle);
  m_size = this->m_resourceHandles.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    m_data = this->m_resourceHandles.m_data;
    while ( m_data->m_pntr != resourceHandle )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_7;
    }
  }
  if ( resourceHandle )
    hkReferencedObject::removeReference(resourceHandle);
  if ( v5 > -1 )
  {
    v8 = this->m_resourceHandles.m_data;
    m_pntr = v8[v5].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    v8[v5].m_pntr = 0i64;
    --this->m_resourceHandles.m_size;
    v10 = &this->m_resourceHandles.m_data[v5];
    v11 = 8 * (this->m_resourceHandles.m_size - v5);
    if ( v11 > 0 )
    {
      v12 = ((unsigned int)(v11 - 1) >> 3) + 1;
      do
      {
        v13 = v10[1].m_pntr;
        ++v10;
        v10[-1].m_pntr = v13;
        --v12;
      }
      while ( v12 );
    }
  }
}

// File Line: 336
// RVA: 0xE3CD50
const char *__fastcall hkMemoryResourceContainer::getName(hkMemoryResourceContainer *this, hkStringBuf *buffer)
{
  return (const char *)((unsigned __int64)this->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 341
// RVA: 0xE3D170
hkMemoryResourceContainer *__fastcall hkMemoryResourceContainer::createContainer(
        hkMemoryResourceContainer *this,
        const char *name)
{
  hkMemoryResourceContainer *result; // rax
  _QWORD **Value; // rax
  hkMemoryResourceContainer *v6; // rax
  hkReferencedObject *v7; // rax
  hkMemoryResourceContainer *v8; // rbx
  hkRefPtr<hkMemoryResourceContainer> *v9; // r14

  result = (hkMemoryResourceContainer *)((__int64 (__fastcall *)(hkMemoryResourceContainer *, const char *, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
                                          this,
                                          name,
                                          0i64);
  if ( !result )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkMemoryResourceContainer *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                        Value[11],
                                        64i64);
    if ( v6 )
    {
      hkMemoryResourceContainer::hkMemoryResourceContainer(v6, name);
      v8 = (hkMemoryResourceContainer *)v7;
      if ( v7 )
        hkReferencedObject::addReference(v7);
    }
    else
    {
      v8 = 0i64;
    }
    if ( this->m_children.m_size == (this->m_children.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_children.m_data, 8);
    v9 = &this->m_children.m_data[this->m_children.m_size];
    if ( v9 )
    {
      if ( v8 )
        hkReferencedObject::addReference(v8);
      v9->m_pntr = v8;
    }
    ++this->m_children.m_size;
    if ( v8 )
      hkReferencedObject::removeReference(v8);
    v8->m_parent = this;
    hkReferencedObject::removeReference(v8);
    return v8;
  }
  return result;
}

// File Line: 359
// RVA: 0xE3D260
void __fastcall hkMemoryResourceContainer::destroyContainer(
        hkMemoryResourceContainer *this,
        hkMemoryResourceContainer *container2)
{
  __int64 m_size; // rcx
  int v5; // ebx
  __int64 v6; // rdx
  hkRefPtr<hkMemoryResourceContainer> *m_data; // rax
  hkRefPtr<hkMemoryResourceContainer> *v8; // rdi
  hkReferencedObject *m_pntr; // rcx
  __int64 v10; // rax

  if ( container2 )
    hkReferencedObject::addReference(container2);
  m_size = this->m_children.m_size;
  v5 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_7:
    v5 = -1;
  }
  else
  {
    m_data = this->m_children.m_data;
    while ( m_data->m_pntr != container2 )
    {
      ++v6;
      ++v5;
      ++m_data;
      if ( v6 >= m_size )
        goto LABEL_7;
    }
  }
  if ( container2 )
    hkReferencedObject::removeReference(container2);
  if ( v5 > -1 )
  {
    v8 = this->m_children.m_data;
    m_pntr = v8[v5].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    v8[v5].m_pntr = 0i64;
    v10 = --this->m_children.m_size;
    if ( (_DWORD)v10 != v5 )
      this->m_children.m_data[v5].m_pntr = this->m_children.m_data[v10].m_pntr;
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
hkMemoryResourceContainer *__fastcall hkMemoryResourceContainer::findContainerByName(
        hkMemoryResourceContainer *this,
        const char *containerName,
        hkMemoryResourceContainer *prevContainer)
{
  int v3; // ebx
  __int64 v6; // r9
  hkRefPtr<hkMemoryResourceContainer> *v7; // rcx
  __int64 i; // rsi
  hkMemoryResourceContainer *m_pntr; // rbp

  v3 = 0;
  v6 = 0i64;
  do
  {
    if ( !prevContainer )
      break;
    if ( v3 >= this->m_children.m_size )
      break;
    ++v3;
    v7 = &this->m_children.m_data[v6++];
  }
  while ( v7->m_pntr != prevContainer );
  if ( v3 >= this->m_children.m_size )
    return 0i64;
  for ( i = v3; ; ++i )
  {
    m_pntr = this->m_children.m_data[i].m_pntr;
    if ( !containerName
      || !(unsigned int)hkString::strCmp(
                          containerName,
                          (const char *)((unsigned __int64)m_pntr->m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
    {
      break;
    }
    if ( ++v3 >= this->m_children.m_size )
      return 0i64;
  }
  return m_pntr;
}

// File Line: 399
// RVA: 0xE3D330
hkResult *__fastcall hkMemoryResourceContainer::parentTo(
        hkMemoryResourceContainer *this,
        hkResult *result,
        hkMemoryResourceContainer *newParent)
{
  hkMemoryResourceContainer *v6; // rax
  hkMemoryResourceContainer *m_parent; // rax
  int v8; // edi
  __int64 v9; // rcx
  __int64 m_size; // rdx
  hkMemoryResourceContainer **p_m_pntr; // rax
  hkMemoryResourceContainer *v12; // rsi
  hkRefPtr<hkMemoryResourceContainer> *m_data; // r15
  __int64 v14; // r14
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkMemoryResourceContainer> *v16; // rcx
  int v17; // edx
  __int64 v18; // rdx
  hkMemoryResourceContainer *v19; // rax
  hkRefPtr<hkMemoryResourceContainer> *v20; // rsi
  hkOstream *v22; // rax
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  hkOstream *v25; // rax
  hkErrStream v26; // [rsp+20h] [rbp-238h] BYREF
  char buf[536]; // [rsp+40h] [rbp-218h] BYREF

  v6 = newParent;
  if ( newParent )
  {
    while ( v6 != this )
    {
      v6 = (hkMemoryResourceContainer *)((__int64 (__fastcall *)(hkMemoryResourceContainer *))v6->vfptr[4].__first_virtual_table_function__)(v6);
      if ( !v6 )
        goto LABEL_4;
    }
    hkErrStream::hkErrStream(&v26, buf, 512);
    v22 = hkOstream::operator<<(&v26, "Cannot parent ");
    v23 = hkOstream::operator<<(v22, &this->m_name);
    v24 = hkOstream::operator<<(v23, " to ");
    v25 = hkOstream::operator<<(v24, &newParent->m_name);
    hkOstream::operator<<(v25, " as this would create a circular dependency ");
    hkError::messageWarning(0xABBA4554, buf, "ResourceDatabase\\hkResourceHandle.cpp", 408);
    hkOstream::~hkOstream(&v26);
    result->m_enum = HK_FAILURE;
  }
  else
  {
LABEL_4:
    hkReferencedObject::addReference(this);
    if ( this )
      hkReferencedObject::addReference(this);
    m_parent = this->m_parent;
    v8 = 0;
    v9 = 0i64;
    m_size = m_parent->m_children.m_size;
    if ( m_size <= 0 )
    {
LABEL_10:
      v8 = -1;
    }
    else
    {
      p_m_pntr = &m_parent->m_children.m_data->m_pntr;
      while ( *p_m_pntr != this )
      {
        ++v9;
        ++v8;
        ++p_m_pntr;
        if ( v9 >= m_size )
          goto LABEL_10;
      }
    }
    hkReferencedObject::removeReference(this);
    v12 = this->m_parent;
    m_data = v12->m_children.m_data;
    v14 = v8;
    m_pntr = m_data[v14].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    m_data[v8].m_pntr = 0i64;
    --v12->m_children.m_size;
    v16 = &v12->m_children.m_data[v14];
    v17 = 8 * (v12->m_children.m_size - v8);
    if ( v17 > 0 )
    {
      v18 = ((unsigned int)(v17 - 1) >> 3) + 1;
      do
      {
        v19 = v16[1].m_pntr;
        ++v16;
        v16[-1].m_pntr = v19;
        --v18;
      }
      while ( v18 );
    }
    hkReferencedObject::addReference(this);
    if ( newParent->m_children.m_size == (newParent->m_children.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&newParent->m_children.m_data, 8);
    v20 = &newParent->m_children.m_data[newParent->m_children.m_size];
    if ( v20 )
    {
      hkReferencedObject::addReference(this);
      v20->m_pntr = this;
    }
    ++newParent->m_children.m_size;
    hkReferencedObject::removeReference(this);
    this->m_parent = newParent;
    hkReferencedObject::removeReference(this);
    result->m_enum = HK_SUCCESS;
  }
  return result;
}

// File Line: 430
// RVA: 0xE3D610
void __fastcall hkContainerResourceMap::hkContainerResourceMap(
        hkContainerResourceMap *this,
        hkResourceContainer *container)
{
  int v4; // edi
  __int64 v5; // rsi
  hkResourceHandle *v6; // rbx
  const char *v7; // rax
  hkArray<hkResourceHandle *,hkContainerHeapAllocator> resourcesOut; // [rsp+20h] [rbp-B8h] BYREF
  char *v9; // [rsp+30h] [rbp-A8h] BYREF
  int v10; // [rsp+38h] [rbp-A0h]
  int v11; // [rsp+3Ch] [rbp-9Ch]
  char v12; // [rsp+40h] [rbp-98h] BYREF

  this->vfptr = (hkResourceMapVtbl *)&hkContainerResourceMap::`vftable;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_resources.m_map,
    0);
  resourcesOut.m_data = 0i64;
  resourcesOut.m_size = 0;
  resourcesOut.m_capacityAndFlags = 0x80000000;
  hkResourceContainer::findAllResourceRecursively(container, &resourcesOut);
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
      v7 = (const char *)v6->vfptr[2].__vecDelDtor(v6, (unsigned int)&v9);
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &this->m_resources.m_map,
        v7,
        (unsigned __int64)v6);
      v10 = 0;
      if ( v11 >= 0 )
        hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v9, v11 & 0x3FFFFFFF);
      ++v4;
      ++v5;
    }
    while ( v4 < resourcesOut.m_size );
  }
  resourcesOut.m_size = 0;
  if ( resourcesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      resourcesOut.m_data,
      8 * resourcesOut.m_capacityAndFlags);
}

// File Line: 445
// RVA: 0xE3D780
void *__fastcall hkContainerResourceMap::findObjectByName(
        hkContainerResourceMap *this,
        const char *objectName,
        hkClass **klassOut)
{
  void *result; // rax
  void *v5; // rdi

  if ( klassOut )
    *klassOut = 0i64;
  result = (void *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                     (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_resources,
                     objectName,
                     0i64);
  v5 = result;
  if ( result )
  {
    if ( klassOut )
      *klassOut = (hkClass *)(*(__int64 (__fastcall **)(void *))(*(_QWORD *)result + 56i64))(result);
    return (void *)(*(__int64 (__fastcall **)(void *))(*(_QWORD *)v5 + 48i64))(v5);
  }
  return result;
}

