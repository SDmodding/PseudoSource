// File Line: 20
// RVA: 0xEDD694
void __fastcall OSuite::ZOEdmProperty::ZOEdmProperty(OSuite::ZOEdmProperty *this, OSuite::ZString *name, OSuite::EdmType edmType, OSuite::ZString *complexTypeName, bool nullable)
{
  OSuite::ZString *v5; // rbx
  OSuite::ZOEdmProperty *v6; // rsi
  OSuite::ZString *v7; // rbp
  OSuite::EdmType v8; // edi
  OSuite::ZString *v9; // rbx
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rax
  OSuite::ZString schema; // [rsp+20h] [rbp-28h]

  v5 = name;
  v6 = this;
  v7 = complexTypeName;
  v8 = edmType;
  OSuite::ZString::ZString(&schema, &customWorldMapCaption);
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&v6->vfptr, &schema, v5);
  OSuite::ZString::~ZString(&schema);
  v9 = 0i64;
  v6->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmProperty::`vftable;
  v6->m_Type = v8;
  v6->m_ComplexType = 0i64;
  v6->m_ComplexTypeName = 0i64;
  v6->m_Nullable = nullable;
  if ( v8 == 16 )
  {
    v10 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
    if ( v10 )
    {
      v10->m_pString = 0i64;
      OSuite::ZString::ZString(v10, v7);
      v9 = v11;
    }
    v6->m_ComplexTypeName = v9;
  }
}

// File Line: 35
// RVA: 0xEDD818
void __fastcall OSuite::ZOEdmProperty::CleanTempData(OSuite::ZOEdmProperty *this)
{
  OSuite::ZOEdmProperty *v1; // rbx
  OSuite::ZString *v2; // rcx

  v1 = this;
  v2 = this->m_ComplexTypeName;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
    v1->m_ComplexTypeName = 0i64;
  }
}

// File Line: 58
// RVA: 0xEDD5D0
void __fastcall OSuite::ZOEdmNavigationProperty::ZOEdmNavigationProperty(OSuite::ZOEdmNavigationProperty *this, OSuite::ZString *schema, OSuite::ZString *name, OSuite::ZString *association, OSuite::ZString *fromRole, OSuite::ZString *toRole)
{
  OSuite::ZString *v6; // rsi
  OSuite::ZOEdmNavigationProperty *v7; // rdi
  OSuite::ZString *v8; // rbx
  OSuite::ZString *v9; // rax
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rax
  OSuite::ZString *v12; // rax
  OSuite::ZString *v13; // rax
  OSuite::ZString *v14; // rax

  v6 = association;
  v7 = this;
  OSuite::ZOEdmBase::ZOEdmBase((OSuite::ZOEdmBase *)&this->vfptr, schema, name);
  v8 = 0i64;
  v7->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOEdmNavigationProperty::`vftable;
  v7->m_Association = 0i64;
  v7->m_FromRole = 0i64;
  v7->m_ToRole = 0i64;
  v9 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v9 )
  {
    v9->m_pString = 0i64;
    OSuite::ZString::ZString(v9, v6);
  }
  else
  {
    v10 = 0i64;
  }
  v7->m_AssociationName = v10;
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
  v7->m_FromRoleName = v12;
  v13 = (OSuite::ZString *)OSuite::ZObject::operator new(0x18ui64);
  if ( v13 )
  {
    v13->m_pString = 0i64;
    OSuite::ZString::ZString(v13, toRole);
    v8 = v14;
  }
  v7->m_ToRoleName = v8;
}

// File Line: 74
// RVA: 0xEDD7C0
void __fastcall OSuite::ZOEdmNavigationProperty::CleanTempData(OSuite::ZOEdmNavigationProperty *this)
{
  OSuite::ZOEdmNavigationProperty *v1; // rbx
  OSuite::ZString *v2; // rcx
  OSuite::ZString *v3; // rcx
  OSuite::ZString *v4; // rcx

  v1 = this;
  v2 = this->m_AssociationName;
  if ( v2 )
    v2->vfptr->__vecDelDtor((OSuite::ZObject *)&v2->vfptr, 1u);
  v3 = v1->m_FromRoleName;
  v1->m_AssociationName = 0i64;
  if ( v3 )
    v3->vfptr->__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 1u);
  v4 = v1->m_ToRoleName;
  v1->m_FromRoleName = 0i64;
  if ( v4 )
    v4->vfptr->__vecDelDtor((OSuite::ZObject *)&v4->vfptr, 1u);
  v1->m_ToRoleName = 0i64;
}

