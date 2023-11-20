// File Line: 71
// RVA: 0x15C52C0
void dynamic_initializer_for__hkaiGraphDebugUtilsDebugInfoClass__()
{
  hkClass::hkClass(
    &hkaiGraphDebugUtilsDebugInfoClass,
    "hkaiGraphDebugUtilsDebugInfo",
    0i64,
    192,
    0i64,
    0,
    0i64,
    0,
    &hkaiGraphDebugUtils_DebugInfoClass_Members,
    18,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 74
// RVA: 0xC3E0C0
hkClass *__fastcall hkaiGraphDebugUtils::DebugInfo::staticClass()
{
  return &hkaiGraphDebugUtilsDebugInfoClass;
}

// File Line: 81
// RVA: 0xC3E0D0
void __fastcall cleanupLoadedObjecthkaiGraphDebugUtilsDebugInfo(void *p)
{
  hkaiGraphDebugUtils::DebugInfo::~DebugInfo((hkaiGraphDebugUtils::DebugInfo *)p);
}

