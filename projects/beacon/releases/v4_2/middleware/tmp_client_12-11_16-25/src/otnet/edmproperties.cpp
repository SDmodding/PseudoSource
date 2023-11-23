// File Line: 20
// RVA: 0xEDD694
void __fastcall OSuite::ZOEdmProperty::ZOEdmProperty(
        OSuite::ZOEdmProperty *this,
        OSuite::ZString *name,
        OSuite::EdmType edmType,
        OSuite::ZString *complexTypeName,
        bool nullable)
{
  OSuite::ZString *v9; // rbx
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rax
  OSuite::ZString schema; // [rsp+20h] [rbp-28h] BYREF

  OSuite::ZString::ZString(&schema, &customCaption);
  OSuite::ZOEdmBase::ZOEdmBase(this, &schema, name);
  OSuite::ZString::~ZString(&schema);
  v9 = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmProperty::`vftable;
  this->m_Type = edmType;
  this->m_ComplexType = 0i64;
  this->m_ComplexTypeName = 0i64;
  this->m_Nullable = nullable;
  if ( edmType == EDM_COMPLEX )
  {
    v10 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( v10 )
    {
      v10->m_pString = 0i64;
      OSuite::ZString::ZString(v10, complexTypeName);
      v9 = v11;
    }
    this->m_ComplexTypeName = v9;
  }
}

// File Line: 35
// RVA: 0xEDD818
void __fastcall OSuite::ZOEdmProperty::CleanTempData(OSuite::ZOEdmProperty *this)
{
  OSuite::ZString *m_ComplexTypeName; // rcx

  m_ComplexTypeName = this->m_ComplexTypeName;
  if ( m_ComplexTypeName )
  {
    m_ComplexTypeName->OSuite::ZObject::vfptr->__vecDelDtor(m_ComplexTypeName, 1u);
    this->m_ComplexTypeName = 0i64;
  }
}

// File Line: 58
// RVA: 0xEDD5D0
void __fastcall OSuite::ZOEdmNavigationProperty::ZOEdmNavigationProperty(
        OSuite::ZOEdmNavigationProperty *this,
        OSuite::ZString *schema,
        OSuite::ZString *name,
        OSuite::ZString *association,
        OSuite::ZString *fromRole,
        OSuite::ZString *toRole)
{
  OSuite::ZString *v8; // rbx
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rax
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rax

  OSuite::ZOEdmBase::ZOEdmBase(this, schema, name);
  v8 = 0i64;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmNavigationProperty::`vftable;
  this->m_Association = 0i64;
  this->m_FromRole = 0i64;
  this->m_ToRole = 0i64;
  v9 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v9 )
  {
    v9->m_pString = 0i64;
    OSuite::ZString::ZString(v9, association);
  }
  else
  {
    v10 = 0i64;
  }
  this->m_AssociationName = v10;
  v11 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v11 )
  {
    v11->m_pString = 0i64;
    OSuite::ZString::ZString(v11, fromRole);
  }
  else
  {
    v12 = 0i64;
  }
  this->m_FromRoleName = v12;
  v13 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v13 )
  {
    v13->m_pString = 0i64;
    OSuite::ZString::ZString(v13, toRole);
    v8 = v14;
  }
  this->m_ToRoleName = v8;
}

// File Line: 74
// RVA: 0xEDD7C0
void __fastcall OSuite::ZOEdmNavigationProperty::CleanTempData(OSuite::ZOEdmNavigationProperty *this)
{
  OSuite::ZString *m_AssociationName; // rcx
  OSuite::ZString *m_FromRoleName; // rcx
  OSuite::ZString *m_ToRoleName; // rcx

  m_AssociationName = this->m_AssociationName;
  if ( m_AssociationName )
    m_AssociationName->OSuite::ZObject::vfptr->__vecDelDtor(m_AssociationName, 1u);
  m_FromRoleName = this->m_FromRoleName;
  this->m_AssociationName = 0i64;
  if ( m_FromRoleName )
    m_FromRoleName->OSuite::ZObject::vfptr->__vecDelDtor(m_FromRoleName, 1u);
  m_ToRoleName = this->m_ToRoleName;
  this->m_FromRoleName = 0i64;
  if ( m_ToRoleName )
    m_ToRoleName->OSuite::ZObject::vfptr->__vecDelDtor(m_ToRoleName, 1u);
  this->m_ToRoleName = 0i64;
}

