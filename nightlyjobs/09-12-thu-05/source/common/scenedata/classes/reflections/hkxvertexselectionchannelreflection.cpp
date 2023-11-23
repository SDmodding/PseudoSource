// File Line: 52
// RVA: 0x15D8110
void dynamic_initializer_for__hkxVertexSelectionChannelClass__()
{
  hkClass::hkClass(
    &hkxVertexSelectionChannelClass,
    "hkxVertexSelectionChannel",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexSelectionChannelClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xE33B60
hkClass *__fastcall hkxVertexSelectionChannel::staticClass()
{
  return &hkxVertexSelectionChannelClass;
}

// File Line: 62
// RVA: 0xE33B70
void __fastcall finishLoadedObjecthkxVertexSelectionChannel(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxVertexSelectionChannel::`vftable;
}

// File Line: 68
// RVA: 0xE33B90
void __fastcall cleanupLoadedObjecthkxVertexSelectionChannel(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE33BA0
void **__fastcall getVtablehkxVertexSelectionChannel()
{
  return &hkxVertexSelectionChannel::`vftable;
}

// File Line: 94
// RVA: 0x15D8180
void **dynamic_initializer_for__hkxVertexSelectionChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxVertexSelectionChannel();
  hkxVertexSelectionChannelTypeInfo.m_size = 32i64;
  hkxVertexSelectionChannelTypeInfo.m_typeName = "hkxVertexSelectionChannel";
  hkxVertexSelectionChannelTypeInfo.m_vtable = result;
  hkxVertexSelectionChannelTypeInfo.m_scopedName = "!hkxVertexSelectionChannel";
  hkxVertexSelectionChannelTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxVertexSelectionChannel;
  hkxVertexSelectionChannelTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxVertexSelectionChannel;
  return result;
}

