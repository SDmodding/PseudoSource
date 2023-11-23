// File Line: 51
// RVA: 0x15BE180
void dynamic_initializer_for__hkaBoneClass__()
{
  hkClass::hkClass(&hkaBoneClass, "hkaBone", 0i64, 16, 0i64, 0, 0i64, 0, &hkaBoneClass_Members, 2, 0i64, 0i64, 0, 0);
}

// File Line: 54
// RVA: 0xB1C650
hkClass *__fastcall hkaBone::staticClass()
{
  return &hkaBoneClass;
}

// File Line: 61
// RVA: 0xB1C660
void __fastcall finishLoadedObjecthkaBone(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p, finishing);
}

// File Line: 67
// RVA: 0xB1C680
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaBone(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p);
}

