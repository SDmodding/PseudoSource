// File Line: 53
// RVA: 0x15C71E0
void dynamic_initializer_for__hkTraceStreamTitleClass__()
{
  hkClass::hkClass(
    &hkTraceStreamTitleClass,
    "hkTraceStreamTitle",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkTraceStream_TitleClass_Members,
    1,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 56
// RVA: 0xC553E0
hkClass *__fastcall hkTraceStream::Title::staticClass()
{
  return &hkTraceStreamTitleClass;
}

// File Line: 63
// RVA: 0xC553F0
void __fastcall cleanupLoadedObjecthkTraceStreamTitle(void *p)
{
  ;
}

