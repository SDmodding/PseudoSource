// File Line: 14
// RVA: 0xE3BDF0
void __fastcall hkStaticClassNameRegistry::hkStaticClassNameRegistry(hkStaticClassNameRegistry *this, hkClass *const *classes, int classVersion, const char *name)
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
void __fastcall hkStaticClassNameRegistry::hkStaticClassNameRegistry(hkStaticClassNameRegistry *this, hkClass *const *classes, int classVersion, const char *name)
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
void __fastcall hkStaticClassNameRegistry::getClasses(hkStaticClassNameRegistry *this, hkArray<hkClass const *,hkContainerHeapAllocator> *classes)
{
  hkArray<hkClass const *,hkContainerHeapAllocator> *v2; // r14
  hkStaticClassNameRegistry *v3; // rsi
  hkClass *const *v4; // rax
  __int64 v5; // rbx
  int i; // edi
  __int64 v7; // r15
  int v8; // er9
  int v9; // eax
  int v10; // eax
  hkClass **v11; // rax
  signed __int64 v12; // rdx
  hkClass *const *v13; // rax
  signed __int64 v14; // rcx
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = classes;
  v3 = this;
  hkStaticClassNameRegistry::checkIfReady(this);
  v4 = v3->m_classes;
  v5 = 0i64;
  for ( i = 0; *v4; ++i )
    ++v4;
  v7 = v2->m_size;
  v8 = v7 + i;
  v9 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v9 < (signed int)v7 + i )
  {
    v10 = 2 * v9;
    if ( v8 < v10 )
      v8 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v8, 8);
  }
  v11 = v2->m_data;
  v2->m_size += i;
  v12 = (signed __int64)&v11[v7];
  v13 = v3->m_classes;
  if ( *v13 )
  {
    v14 = 0i64;
    do
    {
      ++v5;
      *(hkClass **)(v14 + v12) = *v13;
      v14 = 8 * v5;
      v13 = &v3->m_classes[v5];
    }
    while ( *v13 );
  }
}

// File Line: 45
// RVA: 0xE3BE70
hkClass *__fastcall hkStaticClassNameRegistry::getClassByName(hkStaticClassNameRegistry *this, const char *className)
{
  const char *v2; // rbp
  hkStaticClassNameRegistry *v3; // rsi
  hkClass *const *v4; // rax
  int v5; // edi
  signed __int64 v6; // rbx
  signed __int64 v7; // rcx
  const char *v8; // rax
  bool v9; // zf

  v2 = className;
  v3 = this;
  hkStaticClassNameRegistry::checkIfReady(this);
  v4 = v3->m_classes;
  v5 = 0;
  v6 = 0i64;
  if ( !*v4 )
    return 0i64;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = hkClass::getName(v4[v7]);
    v9 = (unsigned int)hkString::strCmp(v2, v8) == 0;
    v4 = v3->m_classes;
    if ( v9 )
      break;
    ++v6;
    ++v5;
    v7 = v6;
    if ( !v4[v6] )
      return 0i64;
  }
  return v4[v5];
}

// File Line: 58
// RVA: 0xE3BFD0
void __fastcall hkStaticClassNameRegistry::checkIfReady(hkStaticClassNameRegistry *this)
{
  hkStaticClassNameRegistry *v1; // rbx

  v1 = this;
  if ( !this->m_ready )
  {
    hkVersionUtil::recomputeClassMemberOffsets(this->m_classes, this->m_classVersion);
    v1->m_ready = 1;
  }
}

