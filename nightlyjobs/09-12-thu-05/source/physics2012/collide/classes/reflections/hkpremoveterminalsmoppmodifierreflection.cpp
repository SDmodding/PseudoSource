// File Line: 58
// RVA: 0x15CA7C0
void dynamic_initializer_for__hkpRemoveTerminalsMoppModifierClass__()
{
  hkClass::hkClass(
    &hkpRemoveTerminalsMoppModifierClass,
    "hkpRemoveTerminalsMoppModifier",
    &hkReferencedObjectClass,
    48,
    0i64,
    1,
    0i64,
    0,
    &hkpRemoveTerminalsMoppModifier::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xCEBB50
hkClass *__fastcall hkpRemoveTerminalsMoppModifier::staticClass()
{
  return &hkpRemoveTerminalsMoppModifierClass;
}

// File Line: 68
// RVA: 0xCEBB60
void __fastcall finishLoadedObjecthkpRemoveTerminalsMoppModifier(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpRemoveTerminalsMoppModifier::`vftable'{for `hkReferencedObject'};
    *((_QWORD *)p + 2) = &hkpRemoveTerminalsMoppModifier::`vftable'{for `hkpMoppModifier'};
  }
}

// File Line: 74
// RVA: 0xCEBB90
void __fastcall cleanupLoadedObjecthkpRemoveTerminalsMoppModifier(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xCEBBA0
void **__fastcall getVtablehkpRemoveTerminalsMoppModifier()
{
  return &hkpRemoveTerminalsMoppModifier::`vftable'{for `hkReferencedObject'};
}

// File Line: 100
// RVA: 0x15CA830
void **dynamic_initializer_for__hkpRemoveTerminalsMoppModifierTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpRemoveTerminalsMoppModifier();
  hkpRemoveTerminalsMoppModifierTypeInfo.m_size = 48i64;
  hkpRemoveTerminalsMoppModifierTypeInfo.m_typeName = "hkpRemoveTerminalsMoppModifier";
  hkpRemoveTerminalsMoppModifierTypeInfo.m_vtable = result;
  hkpRemoveTerminalsMoppModifierTypeInfo.m_scopedName = "!hkpRemoveTerminalsMoppModifier";
  hkpRemoveTerminalsMoppModifierTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpRemoveTerminalsMoppModifier;
  hkpRemoveTerminalsMoppModifierTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpRemoveTerminalsMoppModifier;
  return result;
}

