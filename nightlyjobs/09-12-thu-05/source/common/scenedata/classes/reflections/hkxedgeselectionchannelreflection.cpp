// File Line: 52
// RVA: 0x15D6670
void dynamic_initializer_for__hkxEdgeSelectionChannelClass__()
{
  hkClass::hkClass(
    &hkxEdgeSelectionChannelClass,
    "hkxEdgeSelectionChannel",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxEdgeSelectionChannelClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xE31BF0
hkClass *__fastcall hkxEdgeSelectionChannel::staticClass()
{
  return &hkxEdgeSelectionChannelClass;
}

// File Line: 62
// RVA: 0xE31C00
void __fastcall finishLoadedObjecthkxEdgeSelectionChannel(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxEdgeSelectionChannel::`vftable;
}

// File Line: 68
// RVA: 0xE31C20
void __fastcall cleanupLoadedObjecthkxEdgeSelectionChannel(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE31C30
void **__fastcall getVtablehkxEdgeSelectionChannel()
{
  return &hkxEdgeSelectionChannel::`vftable;
}

// File Line: 94
// RVA: 0x15D66E0
void **dynamic_initializer_for__hkxEdgeSelectionChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxEdgeSelectionChannel();
  hkxEdgeSelectionChannelTypeInfo.m_size = 32i64;
  hkxEdgeSelectionChannelTypeInfo.m_typeName = "hkxEdgeSelectionChannel";
  hkxEdgeSelectionChannelTypeInfo.m_vtable = result;
  hkxEdgeSelectionChannelTypeInfo.m_scopedName = "!hkxEdgeSelectionChannel";
  hkxEdgeSelectionChannelTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxEdgeSelectionChannel;
  hkxEdgeSelectionChannelTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxEdgeSelectionChannel;
  return result;
}

