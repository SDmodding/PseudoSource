// File Line: 12
// RVA: 0xE3D950
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(
        hkRootLevelContainer::NamedVariant *this,
        const char *name,
        void *object,
        hkClass *klass)
{
  const char *v8; // rbp
  hkClass *Class; // rax

  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::hkStringPtr(&this->m_className);
  v8 = 0i64;
  this->m_variant.m_pntr = 0i64;
  hkStringPtr::operator=(&this->m_name, name);
  hkRefVariant::set(&this->m_variant, object, klass);
  if ( hkRefVariant::getClass(&this->m_variant) )
  {
    Class = hkRefVariant::getClass(&this->m_variant);
    v8 = hkClass::getName(Class);
  }
  hkStringPtr::operator=(&this->m_className, v8);
}

// File Line: 17
// RVA: 0xE3DA00
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(
        hkRootLevelContainer::NamedVariant *this,
        const char *name,
        hkVariant *v)
{
  hkRefVariant *p_m_variant; // rsi
  const char *v7; // rbp
  hkReferencedObject *m_pntr; // rcx
  hkReferencedObject *v9; // rbx
  hkClass *Class; // rax
  hkRefVariant v11; // [rsp+40h] [rbp+8h] BYREF

  hkStringPtr::hkStringPtr(&this->m_name);
  hkStringPtr::hkStringPtr(&this->m_className);
  p_m_variant = &this->m_variant;
  v7 = 0i64;
  this->m_variant.m_pntr = 0i64;
  hkStringPtr::operator=(&this->m_name, name);
  hkRefVariant::hkRefVariant(&v11, v);
  m_pntr = v11.m_pntr;
  if ( &this->m_variant != &v11 )
  {
    v9 = v11.m_pntr;
    if ( v11.m_pntr )
    {
      hkReferencedObject::addReference(v11.m_pntr);
      m_pntr = v11.m_pntr;
    }
    if ( p_m_variant->m_pntr )
    {
      hkReferencedObject::removeReference(p_m_variant->m_pntr);
      m_pntr = v11.m_pntr;
    }
    p_m_variant->m_pntr = v9;
  }
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  if ( hkRefVariant::getClass(&this->m_variant) )
  {
    Class = hkRefVariant::getClass(&this->m_variant);
    v7 = hkClass::getName(Class);
  }
  hkStringPtr::operator=(&this->m_className, v7);
}

// File Line: 23
// RVA: 0xE3DAF0
void __fastcall hkRootLevelContainer::NamedVariant::NamedVariant(
        hkRootLevelContainer::NamedVariant *this,
        hkFinishLoadedObjectFlag f)
{
  hkStringPtr::hkStringPtr(&this->m_name, f);
  hkStringPtr::hkStringPtr(&this->m_className, f);
}

// File Line: 27
// RVA: 0xE3D940
void __fastcall hkRootLevelContainer::hkRootLevelContainer(hkRootLevelContainer *this, hkFinishLoadedObjectFlag f)
{
  ;
}

// File Line: 31
// RVA: 0xE3DB20
hkReferencedObject *__fastcall hkRootLevelContainer::findObjectByType(
        hkRootLevelContainer *this,
        const char *typeName,
        hkReferencedObject *prevObject)
{
  int v3; // ebx
  __int64 v6; // r9
  hkRootLevelContainer::NamedVariant *v7; // rcx
  unsigned __int64 i; // rsi
  hkRootLevelContainer::NamedVariant *m_data; // rbp
  hkClass *Class; // rax
  const char *Name; // rax
  hkRootLevelContainer::NamedVariant *v12; // rbp
  hkClass *v13; // rax
  const char *v14; // rax

  v3 = 0;
  v6 = 0i64;
  do
  {
    if ( !prevObject )
      break;
    if ( v3 >= this->m_namedVariants.m_size )
      break;
    ++v3;
    v7 = &this->m_namedVariants.m_data[v6++];
  }
  while ( v7->m_variant.m_pntr != prevObject );
  if ( v3 >= this->m_namedVariants.m_size )
    return 0i64;
  for ( i = v3; ; ++i )
  {
    m_data = this->m_namedVariants.m_data;
    if ( hkRefVariant::getClass(&this->m_namedVariants.m_data[i].m_variant) )
    {
      Class = hkRefVariant::getClass(&m_data[i].m_variant);
      Name = hkClass::getName(Class);
    }
    else
    {
      Name = (const char *)((unsigned __int64)m_data[i].m_className.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
    }
    if ( Name )
    {
      v12 = this->m_namedVariants.m_data;
      if ( hkRefVariant::getClass(&this->m_namedVariants.m_data[i].m_variant) )
      {
        v13 = hkRefVariant::getClass(&v12[i].m_variant);
        v14 = hkClass::getName(v13);
      }
      else
      {
        v14 = (const char *)((unsigned __int64)v12[i].m_className.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
      }
      if ( !(unsigned int)hkString::strCmp(typeName, v14) )
        break;
    }
    if ( ++v3 >= this->m_namedVariants.m_size )
      return 0i64;
  }
  return this->m_namedVariants.m_data[v3].m_variant.m_pntr;
}

// File Line: 47
// RVA: 0xE3DC40
hkReferencedObject *__fastcall hkRootLevelContainer::findObjectByName(
        hkRootLevelContainer *this,
        const char *objectName,
        hkReferencedObject *prevObject)
{
  int v3; // ebx
  __int64 v6; // r9
  hkRootLevelContainer::NamedVariant *v7; // rcx
  __int64 i; // rsi

  v3 = 0;
  v6 = 0i64;
  do
  {
    if ( !prevObject )
      break;
    if ( v3 >= this->m_namedVariants.m_size )
      break;
    ++v3;
    v7 = &this->m_namedVariants.m_data[v6++];
  }
  while ( v7->m_variant.m_pntr != prevObject );
  if ( v3 >= this->m_namedVariants.m_size )
    return 0i64;
  for ( i = v3;
        ((unsigned __int64)this->m_namedVariants.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64) == 0
     || (unsigned int)hkString::strCmp(
                        objectName,
                        (const char *)((unsigned __int64)this->m_namedVariants.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
        ++i )
  {
    if ( ++v3 >= this->m_namedVariants.m_size )
      return 0i64;
  }
  return this->m_namedVariants.m_data[v3].m_variant.m_pntr;
}

