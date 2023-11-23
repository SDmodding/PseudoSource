// File Line: 14
// RVA: 0xE3BDF0
void __fastcall hkStaticClassNameRegistry::hkStaticClassNameRegistry(
        hkStaticClassNameRegistry *this,
        hkClass *const *classes,
        int classVersion,
        const char *name)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_classes = classes;
  this->vfptr = (hkBaseObjectVtbl *)&hkStaticClassNameRegistry::`vftable;
  this->m_classVersion = classVersion;
  this->m_ready = 0;
  this->m_name = name;
}

// File Line: 20
// RVA: 0xE3BE20
void __fastcall hkStaticClassNameRegistry::hkStaticClassNameRegistry(
        hkStaticClassNameRegistry *this,
        hkClass *const *classes,
        int classVersion,
        const char *name)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkStaticClassNameRegistry::`vftable;
  this->m_classes = classes;
  this->m_classVersion = classVersion;
  this->m_ready = 1;
  this->m_name = name;
}

// File Line: 25
// RVA: 0xE3BE60
const char *__fastcall hkStaticClassNameRegistry::getName(hkStaticClassNameRegistry *this)
{
  return this->m_name;
}

// File Line: 30
// RVA: 0xE3BF00
void __fastcall hkStaticClassNameRegistry::getClasses(
        hkStaticClassNameRegistry *this,
        hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  hkClass *const *m_classes; // rax
  __int64 v5; // rbx
  int i; // edi
  __int64 m_size; // r15
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  hkClass **m_data; // rax
  hkClass **v12; // rdx
  hkClass *const *v13; // rax
  __int64 v14; // rcx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  hkStaticClassNameRegistry::checkIfReady(this);
  m_classes = this->m_classes;
  v5 = 0i64;
  for ( i = 0; *m_classes; ++i )
    ++m_classes;
  m_size = classes->m_size;
  v8 = m_size + i;
  v9 = classes->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (int)m_size + i )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&classes->m_data, v8, 8);
  }
  m_data = classes->m_data;
  classes->m_size += i;
  v12 = &m_data[m_size];
  v13 = this->m_classes;
  if ( *v13 )
  {
    v14 = 0i64;
    do
    {
      ++v5;
      v12[v14] = *v13;
      v14 = v5;
      v13 = &this->m_classes[v5];
    }
    while ( *v13 );
  }
}

// File Line: 45
// RVA: 0xE3BE70
hkClass *__fastcall hkStaticClassNameRegistry::getClassByName(hkStaticClassNameRegistry *this, const char *className)
{
  hkClass *const *m_classes; // rax
  int v5; // edi
  __int64 v6; // rbx
  __int64 v7; // rcx
  const char *Name; // rax
  bool v9; // zf

  hkStaticClassNameRegistry::checkIfReady(this);
  m_classes = this->m_classes;
  v5 = 0;
  v6 = 0i64;
  if ( !*m_classes )
    return 0i64;
  v7 = 0i64;
  while ( 1 )
  {
    Name = hkClass::getName(m_classes[v7]);
    v9 = (unsigned int)hkString::strCmp(className, Name) == 0;
    m_classes = this->m_classes;
    if ( v9 )
      break;
    ++v6;
    ++v5;
    v7 = v6;
    if ( !m_classes[v6] )
      return 0i64;
  }
  return m_classes[v5];
}

// File Line: 58
// RVA: 0xE3BFD0
void __fastcall hkStaticClassNameRegistry::checkIfReady(hkStaticClassNameRegistry *this)
{
  if ( !this->m_ready )
  {
    hkVersionUtil::recomputeClassMemberOffsets((hkClass **)this->m_classes, this->m_classVersion);
    this->m_ready = 1;
  }
}

