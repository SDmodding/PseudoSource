// File Line: 55
// RVA: 0x15D8960
void dynamic_initializer_for__hkRootLevelContainerNamedVariantClass__()
{
  hkClass::hkClass(
    &hkRootLevelContainerNamedVariantClass,
    "hkRootLevelContainerNamedVariant",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkRootLevelContainer::NamedVariant::Members,
    3,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 58
// RVA: 0xE39170
hkClass *__fastcall hkRootLevelContainer::NamedVariant::staticClass()
{
  return &hkRootLevelContainerNamedVariantClass;
}

// File Line: 65
// RVA: 0xE39180
void __fastcall finishLoadedObjecthkRootLevelContainerNamedVariant(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkRootLevelContainer::NamedVariant::NamedVariant);
}

// File Line: 71
// RVA: 0xE391A0
void __fastcall cleanupLoadedObjecthkRootLevelContainerNamedVariant(void *p)
{
  hkStringPtr *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = (hkStringPtr *)p;
  v2 = (hkReferencedObject *)*((_QWORD *)p + 2);
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1[2].m_stringAndFlag = 0i64;
  hkStringPtr::~hkStringPtr(v1 + 1);
  hkStringPtr::~hkStringPtr(v1);
}

// File Line: 107
// RVA: 0x15D8900
void dynamic_initializer_for__hkRootLevelContainerClass__()
{
  hkClass::hkClass(
    &hkRootLevelContainerClass,
    "hkRootLevelContainer",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkRootLevelContainerClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 110
// RVA: 0xE39160
hkClass *__fastcall hkRootLevelContainer::staticClass()
{
  return &hkRootLevelContainerClass;
}

// File Line: 117
// RVA: 0xE391E0
void __fastcall finishLoadedObjecthkRootLevelContainer(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkRootLevelContainer::hkRootLevelContainer);
}

// File Line: 123
// RVA: 0xE39200
void __fastcall cleanupLoadedObjecthkRootLevelContainer(void *p)
{
  hkRootLevelContainer::`scalar deleting destructor((hkRootLevelContainer *)p, 0);
}

