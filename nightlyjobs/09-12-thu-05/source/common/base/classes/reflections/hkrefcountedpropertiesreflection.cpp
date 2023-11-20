// File Line: 68
// RVA: 0x15C7120
void dynamic_initializer_for__hkRefCountedPropertiesEntryClass__()
{
  hkClass::hkClass(
    &hkRefCountedPropertiesEntryClass,
    "hkRefCountedPropertiesEntry",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkRefCountedProperties_EntryClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 71
// RVA: 0xC55340
hkClass *__fastcall hkRefCountedProperties::Entry::staticClass()
{
  return &hkRefCountedPropertiesEntryClass;
}

// File Line: 78
// RVA: 0xC55350
void __fastcall finishLoadedObjecthkRefCountedPropertiesEntry(void *p, int finishing)
{
  ;
}

// File Line: 84
// RVA: 0xC55360
void __fastcall cleanupLoadedObjecthkRefCountedPropertiesEntry(void *p)
{
  _QWORD *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = p;
  v2 = *(hkReferencedObject **)p;
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  *v1 = 0i64;
}

// File Line: 120
// RVA: 0x15C70B0
void dynamic_initializer_for__hkRefCountedPropertiesClass__()
{
  hkClass::hkClass(
    &hkRefCountedPropertiesClass,
    "hkRefCountedProperties",
    0i64,
    16,
    0i64,
    0,
    &hkRefCountedPropertiesEnums,
    1,
    &hkRefCountedProperties::Members,
    1,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 123
// RVA: 0xC55330
hkClass *__fastcall hkRefCountedProperties::staticClass()
{
  return &hkRefCountedPropertiesClass;
}

// File Line: 130
// RVA: 0xC55390
void __fastcall finishLoadedObjecthkRefCountedProperties(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkRefCountedProperties::hkRefCountedProperties);
}

// File Line: 136
// RVA: 0xC553B0
void __fastcall cleanupLoadedObjecthkRefCountedProperties(void *p)
{
  hkRefCountedProperties::~hkRefCountedProperties((hkRefCountedProperties *)p);
}

