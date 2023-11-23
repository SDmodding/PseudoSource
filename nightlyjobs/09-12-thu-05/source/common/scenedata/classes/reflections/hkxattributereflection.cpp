// File Line: 71
// RVA: 0x15D82B0
void dynamic_initializer_for__hkxAttributeClass__()
{
  hkClass::hkClass(
    &hkxAttributeClass,
    "hkxAttribute",
    0i64,
    16,
    0i64,
    0,
    &hkxAttributeEnums,
    1,
    &hkxAttributeClass_Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 74
// RVA: 0xE33C00
hkClass *__fastcall hkxAttribute::staticClass()
{
  return &hkxAttributeClass;
}

// File Line: 81
// RVA: 0xE33C10
void __fastcall finishLoadedObjecthkxAttribute(hkxAttribute *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkxAttribute::hkxAttribute(p, finishing);
}

// File Line: 87
// RVA: 0xE33C30
void __fastcall cleanupLoadedObjecthkxAttribute(hkStringPtr *p)
{
  hkReferencedObject *m_stringAndFlag; // rcx

  m_stringAndFlag = (hkReferencedObject *)p[1].m_stringAndFlag;
  if ( m_stringAndFlag )
    hkReferencedObject::removeReference(m_stringAndFlag);
  p[1].m_stringAndFlag = 0i64;
  hkStringPtr::~hkStringPtr(p);
}

