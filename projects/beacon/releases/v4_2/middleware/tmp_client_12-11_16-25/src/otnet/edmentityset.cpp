// File Line: 12
// RVA: 0xEDD9C0
void __fastcall OSuite::ZOEdmEntitySet::ZOEdmEntitySet(OSuite::ZOEdmEntitySet *this, OSuite::ZString *schema, OSuite::ZString *entitySetName, OSuite::ZString *entityTypeName)
{
  OSuite::ZString *v4; // rsi
  OSuite::ZOEdmEntitySet *v5; // rdi
  OSuite::ZString *v6; // rbx
  OSuite::ZString *v7; // rax
  OSuite::ZString *v8; // rax

  v4 = entityTypeName;
  v5 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr, schema, entitySetName);
  v6 = 0i64;
  v5->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmEntitySet::`vftable;
  v5->m_EntityType = 0i64;
  v7 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v7 )
  {
    v7->m_pString = 0i64;
    OSuite::ZString::ZString(v7, v4);
    v6 = v8;
  }
  v5->m_EntityTypeName = v6;
}

// File Line: 24
// RVA: 0xEDDA60
void __fastcall OSuite::ZOEdmEndRole::CleanTempData(OSuite::ZOEdmEntitySet *this)
{
  OSuite::ZOEdmEntitySet *v1; // rbx
  OSuite::ZString *v2; // rcx

  v1 = this;
  v2 = this->m_EntityTypeName;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v1->m_EntityTypeName = 0i64;
}

