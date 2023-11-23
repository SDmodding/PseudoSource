// File Line: 54
// RVA: 0x15D8320
void dynamic_initializer_for__hkxAttributeGroupClass__()
{
  hkClass::hkClass(
    &hkxAttributeGroupClass,
    "hkxAttributeGroup",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkxAttributeGroupClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE33C60
hkClass *__fastcall hkxAttributeGroup::staticClass()
{
  return &hkxAttributeGroupClass;
}

// File Line: 64
// RVA: 0xE33C70
void __fastcall finishLoadedObjecthkxAttributeGroup(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p, finishing);
}

// File Line: 70
// RVA: 0xE33C90
// attributes: thunk
void __fastcall cleanupLoadedObjecthkxAttributeGroup(hkxAttributeGroup *p)
{
  hkxAttributeGroup::~hkxAttributeGroup(p);
}

