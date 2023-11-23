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
    1);
}

// File Line: 58
// RVA: 0xE39170
hkClass *__fastcall hkRootLevelContainer::NamedVariant::staticClass()
{
  return &hkRootLevelContainerNamedVariantClass;
}

// File Line: 65
// RVA: 0xE39180
void __fastcall finishLoadedObjecthkRootLevelContainerNamedVariant(
        hkRootLevelContainer::NamedVariant *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkRootLevelContainer::NamedVariant::NamedVariant(p, finishing);
}

// File Line: 71
// RVA: 0xE391A0
void __fastcall cleanupLoadedObjecthkRootLevelContainerNamedVariant(hkStringPtr *p)
{
  hkReferencedObject *m_stringAndFlag; // rcx

  m_stringAndFlag = (hkReferencedObject *)p[2].m_stringAndFlag;
  if ( m_stringAndFlag )
    hkReferencedObject::removeReference(m_stringAndFlag);
  p[2].m_stringAndFlag = 0i64;
  hkStringPtr::~hkStringPtr(p + 1);
  hkStringPtr::~hkStringPtr(p);
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
void __fastcall finishLoadedObjecthkRootLevelContainer(hkRootLevelContainer *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkRootLevelContainer::hkRootLevelContainer(p, finishing);
}

// File Line: 123
// RVA: 0xE39200
void __fastcall cleanupLoadedObjecthkRootLevelContainer(hkRootLevelContainer *p)
{
  hkRootLevelContainer::`scalar deleting destructor(p, 0);
}

