// File Line: 12
// RVA: 0xE3D950
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(hkRootLevelContainer::NamedVariant *this, const char *name, void *object, hkClass *klass)
{
  hkClass *v4; // rdi
  void *v5; // rsi
  const char *v6; // rbx
  hkRootLevelContainer::NamedVariant *v7; // r14
  const char *v8; // rbp
  hkClass *v9; // rax

  v4 = klass;
  v5 = object;
  v6 = name;
  v7 = this;
  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::hkStringPtr(&v7->m_className);
  v8 = 0i64;
  v7->m_variant.m_pntr = 0i64;
  hkStringPtr::operator=(&v7->m_name, v6);
  hkRefVariant::set(&v7->m_variant, v5, v4);
  if ( hkRefVariant::getClass(&v7->m_variant) )
  {
    v9 = hkRefVariant::getClass(&v7->m_variant);
    v8 = hkClass::getName(v9);
  }
  hkStringPtr::operator=(&v7->m_className, v8);
}

// File Line: 17
// RVA: 0xE3DA00
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(hkRootLevelContainer::NamedVariant *this, const char *name, hkVariant *v)
{
  hkVariant *v3; // rdi
  const char *v4; // rbx
  hkRootLevelContainer::NamedVariant *v5; // r14
  hkReferencedObject **v6; // rsi
  const char *v7; // rbp
  hkReferencedObject *v8; // rcx
  hkReferencedObject *v9; // rbx
  hkClass *v10; // rax
  hkRefVariant v11; // [rsp+40h] [rbp+8h]

  v3 = v;
  v4 = name;
  v5 = this;
  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::hkStringPtr(&v5->m_className);
  v6 = &v5->m_variant.m_pntr;
  v7 = 0i64;
  v5->m_variant.m_pntr = 0i64;
  hkStringPtr::operator=(&v5->m_name, v4);
  hkRefVariant::hkRefVariant(&v11, v3);
  v8 = v11.m_pntr;
  if ( &v5->m_variant != &v11 )
  {
    v9 = v11.m_pntr;
    if ( v11.m_pntr )
    {
      hkReferencedObject::addReference(v11.m_pntr);
      v8 = v11.m_pntr;
    }
    if ( *v6 )
    {
      hkReferencedObject::removeReference(*v6);
      v8 = v11.m_pntr;
    }
    *v6 = v9;
  }
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  if ( hkRefVariant::getClass(&v5->m_variant) )
  {
    v10 = hkRefVariant::getClass(&v5->m_variant);
    v7 = hkClass::getName(v10);
  }
  hkStringPtr::operator=(&v5->m_className, v7);
}

// File Line: 23
// RVA: 0xE3DAF0
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(hkRootLevelContainer::NamedVariant *this, hkFinishLoadedObjectFlag f)
{
  hkRootLevelContainer::NamedVariant *v2; // rbx
  int fa; // [rsp+38h] [rbp+10h]

  fa = f.m_finishing;
  v2 = this;
  hkStringPtr::hkStringPtr(&this->m_name, f);
  hkStringPtr::hkStringPtr(&v2->m_className, (hkFinishLoadedObjectFlag)fa);
}

// File Line: 27
// RVA: 0xE3D940
void __fastcall hkRootLevelContainer::hkRootLevelContainer(hkRootLevelContainer *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 31
// RVA: 0xE3DB20
hkReferencedObject *__fastcall hkRootLevelContainer::findObjectByType(hkRootLevelContainer *this, const char *typeName, const void *prevObject)
{
  int v3; // ebx
  const char *v4; // r15
  hkRootLevelContainer *v5; // rdi
  __int64 v6; // r9
  hkRootLevelContainer::NamedVariant *v7; // rcx
  signed __int64 v8; // rsi
  hkRootLevelContainer::NamedVariant *v9; // rbp
  hkClass *v10; // rax
  const char *v11; // rax
  hkRootLevelContainer::NamedVariant *v12; // rbp
  hkClass *v13; // rax
  const char *v14; // rax

  v3 = 0;
  v4 = typeName;
  v5 = this;
  v6 = 0i64;
  do
  {
    if ( !prevObject )
      break;
    if ( v3 >= v5->m_namedVariants.m_size )
      break;
    ++v3;
    v7 = &v5->m_namedVariants.m_data[v6];
    ++v6;
  }
  while ( v7->m_variant.m_pntr != prevObject );
  if ( v3 >= v5->m_namedVariants.m_size )
    return 0i64;
  v8 = v3;
  while ( 1 )
  {
    v9 = v5->m_namedVariants.m_data;
    if ( hkRefVariant::getClass(&v5->m_namedVariants.m_data[v8].m_variant) )
    {
      v10 = hkRefVariant::getClass(&v9[v8].m_variant);
      v11 = hkClass::getName(v10);
    }
    else
    {
      v11 = (const char *)((_QWORD)v9[v8].m_className.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    }
    if ( v11 )
    {
      v12 = v5->m_namedVariants.m_data;
      if ( hkRefVariant::getClass(&v5->m_namedVariants.m_data[v8].m_variant) )
      {
        v13 = hkRefVariant::getClass(&v12[v8].m_variant);
        v14 = hkClass::getName(v13);
      }
      else
      {
        v14 = (const char *)((_QWORD)v12[v8].m_className.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      }
      if ( !(unsigned int)hkString::strCmp(v4, v14) )
        break;
    }
    ++v3;
    ++v8;
    if ( v3 >= v5->m_namedVariants.m_size )
      return 0i64;
  }
  return v5->m_namedVariants.m_data[v3].m_variant.m_pntr;
}

// File Line: 47
// RVA: 0xE3DC40
hkReferencedObject *__fastcall hkRootLevelContainer::findObjectByName(hkRootLevelContainer *this, const char *objectName, const void *prevObject)
{
  int v3; // ebx
  const char *v4; // rbp
  hkRootLevelContainer *v5; // rdi
  __int64 v6; // r9
  hkRootLevelContainer::NamedVariant *v7; // rcx
  signed __int64 v8; // rsi

  v3 = 0;
  v4 = objectName;
  v5 = this;
  v6 = 0i64;
  do
  {
    if ( !prevObject )
      break;
    if ( v3 >= v5->m_namedVariants.m_size )
      break;
    ++v3;
    v7 = &v5->m_namedVariants.m_data[v6];
    ++v6;
  }
  while ( v7->m_variant.m_pntr != prevObject );
  if ( v3 >= v5->m_namedVariants.m_size )
    return 0i64;
  v8 = v3;
  while ( !((_QWORD)v5->m_namedVariants.m_data[v8].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)
       || (unsigned int)hkString::strCmp(
                          v4,
                          (const char *)((_QWORD)v5->m_namedVariants.m_data[v8].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    ++v3;
    ++v8;
    if ( v3 >= v5->m_namedVariants.m_size )
      return 0i64;
  }
  return v5->m_namedVariants.m_data[v3].m_variant.m_pntr;
}

