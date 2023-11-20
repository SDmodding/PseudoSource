// File Line: 50
// RVA: 0x15C6D50
void dynamic_initializer_for__hkSphereClass__()
{
  hkClass::hkClass(&hkSphereClass, "hkSphere", 0i64, 16, 0i64, 0, 0i64, 0, &hkSphere::Members, 1, 0i64, 0i64, 0, 0);
}

// File Line: 53
// RVA: 0xC55060
hkClass *__fastcall hkSphere::staticClass()
{
  return &hkSphereClass;
}

// File Line: 60
// RVA: 0xC55070
void __fastcall cleanupLoadedObjecthkSphere(void *p)
{
  ;
}

