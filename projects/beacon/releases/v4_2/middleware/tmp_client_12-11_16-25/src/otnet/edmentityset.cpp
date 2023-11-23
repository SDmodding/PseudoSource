// File Line: 12
// RVA: 0xEDD9C0
void __fastcall OSuite::ZOEdmEntitySet::ZOEdmEntitySet(
        OSuite::ZOEdmEntitySet *this,
        OSuite::ZString *schema,
        OSuite::ZString *entitySetName,
        OSuite::ZString *entityTypeName)
{
  OSuite::ZString *v6; // rbx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schema, entitySetName);
  v6 = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEntitySet::`vftable;
  this->m_EntityType = 0i64;
  v7 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v7 )
  {
    v7->m_pString = 0i64;
    OSuite::ZString::ZString(v7, entityTypeName);
    v6 = v8;
  }
  this->m_EntityTypeName = v6;
}

// File Line: 24
// RVA: 0xEDDA60
void __fastcall OSuite::ZOEdmEndRole::CleanTempData(OSuite::ZOEdmEntitySet *this)
{
  OSuite::ZString *m_EntityTypeName; // rcx

  m_EntityTypeName = this->m_EntityTypeName;
  if ( m_EntityTypeName )
    m_EntityTypeName->OSuite::ZObject::vfptr->__vecDelDtor(m_EntityTypeName, 1u);
  this->m_EntityTypeName = 0i64;
}

