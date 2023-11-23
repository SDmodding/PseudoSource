// File Line: 52
// RVA: 0x15D7C10
void dynamic_initializer_for__hkxTriangleSelectionChannelClass__()
{
  hkClass::hkClass(
    &hkxTriangleSelectionChannelClass,
    "hkxTriangleSelectionChannel",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxTriangleSelectionChannelClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xE335E0
hkClass *__fastcall hkxTriangleSelectionChannel::staticClass()
{
  return &hkxTriangleSelectionChannelClass;
}

// File Line: 62
// RVA: 0xE335F0
void __fastcall finishLoadedObjecthkxTriangleSelectionChannel(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxTriangleSelectionChannel::`vftable;
}

// File Line: 68
// RVA: 0xE33610
void __fastcall cleanupLoadedObjecthkxTriangleSelectionChannel(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE33620
void **__fastcall getVtablehkxTriangleSelectionChannel()
{
  return &hkxTriangleSelectionChannel::`vftable;
}

// File Line: 94
// RVA: 0x15D7C80
void **dynamic_initializer_for__hkxTriangleSelectionChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxTriangleSelectionChannel();
  hkxTriangleSelectionChannelTypeInfo.m_size = 32i64;
  hkxTriangleSelectionChannelTypeInfo.m_typeName = "hkxTriangleSelectionChannel";
  hkxTriangleSelectionChannelTypeInfo.m_vtable = result;
  hkxTriangleSelectionChannelTypeInfo.m_scopedName = "!hkxTriangleSelectionChannel";
  hkxTriangleSelectionChannelTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxTriangleSelectionChannel;
  hkxTriangleSelectionChannelTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxTriangleSelectionChannel;
  return result;
}

