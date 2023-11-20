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
    1u);
}

// File Line: 74
// RVA: 0xE33C00
hkClass *__fastcall hkxAttribute::staticClass()
{
  return &hkxAttributeClass;
}

// File Line: 81
// RVA: 0xE33C10
void __fastcall finishLoadedObjecthkxAttribute(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkxAttribute::hkxAttribute);
}

// File Line: 87
// RVA: 0xE33C30
void __fastcall cleanupLoadedObjecthkxAttribute(void *p)
{
  hkStringPtr *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = (hkStringPtr *)p;
  v2 = (hkReferencedObject *)*((_QWORD *)p + 1);
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1[1].m_stringAndFlag = 0i64;
  hkStringPtr::~hkStringPtr(v1);
}

