// File Line: 71
// RVA: 0x15C8990
void dynamic_initializer_for__hkcdStaticPvsBlockHeaderClass__()
{
  hkClass::hkClass(
    &hkcdStaticPvsBlockHeaderClass,
    "hkcdStaticPvsBlockHeader",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticPvs_BlockHeaderClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 74
// RVA: 0xC8E9A0
hkClass *__fastcall hkcdStaticPvs::BlockHeader::staticClass()
{
  return &hkcdStaticPvsBlockHeaderClass;
}

// File Line: 81
// RVA: 0xC8E9B0
void __fastcall cleanupLoadedObjecthkcdStaticPvsBlockHeader(void *p)
{
  ;
}

// File Line: 124
// RVA: 0x15C89F0
void dynamic_initializer_for__hkcdStaticPvsClass__()
{
  hkClass::hkClass(
    &hkcdStaticPvsClass,
    "hkcdStaticPvs",
    0i64,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkcdStaticPvsClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 127
// RVA: 0xC8E990
hkClass *__fastcall hkcdStaticPvs::staticClass()
{
  return &hkcdStaticPvsClass;
}

// File Line: 134
// RVA: 0xC8E9C0
void __fastcall finishLoadedObjecthkcdStaticPvs(void *p, int finishing)
{
  ;
}

// File Line: 140
// RVA: 0xC8E9D0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkcdStaticPvs(hkcdStaticPvs *p)
{
  hkcdStaticPvs::~hkcdStaticPvs(p);
}

