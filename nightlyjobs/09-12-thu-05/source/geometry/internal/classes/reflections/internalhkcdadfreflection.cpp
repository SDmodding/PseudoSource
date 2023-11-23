// File Line: 71
// RVA: 0x15C9440
void dynamic_initializer_for__hkcdAdfClass__()
{
  hkClass::hkClass(&hkcdAdfClass, "hkcdAdf", 0i64, 128, 0i64, 0, 0i64, 0, &hkcdAdfClass_Members, 7, 0i64, 0i64, 0, 0);
}

// File Line: 74
// RVA: 0xC8F510
hkClass *__fastcall hkcdAdf::staticClass()
{
  return &hkcdAdfClass;
}

// File Line: 81
// RVA: 0xC8F520
void __fastcall finishLoadedObjecthkcdAdf(void *p, int finishing)
{
  ;
}

// File Line: 87
// RVA: 0xC8F530
// attributes: thunk
void __fastcall cleanupLoadedObjecthkcdAdf(hkcdAdf *p)
{
  hkcdAdf::~hkcdAdf(p);
}

