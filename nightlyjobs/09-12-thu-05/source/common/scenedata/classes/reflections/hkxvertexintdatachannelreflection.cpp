// File Line: 52
// RVA: 0x15D8040
void dynamic_initializer_for__hkxVertexIntDataChannelClass__()
{
  hkClass::hkClass(
    &hkxVertexIntDataChannelClass,
    "hkxVertexIntDataChannel",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexIntDataChannelClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 55
// RVA: 0xE33B10
hkClass *__fastcall hkxVertexIntDataChannel::staticClass()
{
  return &hkxVertexIntDataChannelClass;
}

// File Line: 62
// RVA: 0xE33B20
void __fastcall finishLoadedObjecthkxVertexIntDataChannel(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxVertexIntDataChannel::`vftable;
}

// File Line: 68
// RVA: 0xE33B40
void __fastcall cleanupLoadedObjecthkxVertexIntDataChannel(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE33B50
void **__fastcall getVtablehkxVertexIntDataChannel()
{
  return &hkxVertexIntDataChannel::`vftable;
}

// File Line: 94
// RVA: 0x15D80B0
void **dynamic_initializer_for__hkxVertexIntDataChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxVertexIntDataChannel();
  hkxVertexIntDataChannelTypeInfo.m_size = 32i64;
  hkxVertexIntDataChannelTypeInfo.m_typeName = "hkxVertexIntDataChannel";
  hkxVertexIntDataChannelTypeInfo.m_vtable = result;
  hkxVertexIntDataChannelTypeInfo.m_scopedName = "!hkxVertexIntDataChannel";
  hkxVertexIntDataChannelTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxVertexIntDataChannel;
  hkxVertexIntDataChannelTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxVertexIntDataChannel;
  return result;
}

