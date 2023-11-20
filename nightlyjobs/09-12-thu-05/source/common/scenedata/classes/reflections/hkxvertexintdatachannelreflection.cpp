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
    1u);
}

// File Line: 55
// RVA: 0xE33B10
hkClass *__fastcall hkxVertexIntDataChannel::staticClass()
{
  return &hkxVertexIntDataChannelClass;
}

// File Line: 62
// RVA: 0xE33B20
void __fastcall finishLoadedObjecthkxVertexIntDataChannel(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxVertexIntDataChannel::`vftable';
}

// File Line: 68
// RVA: 0xE33B40
void __fastcall cleanupLoadedObjecthkxVertexIntDataChannel(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE33B50
void **__fastcall getVtablehkxVertexIntDataChannel()
{
  return &hkxVertexIntDataChannel::`vftable';
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
  hkxVertexIntDataChannelTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxVertexIntDataChannel;
  hkxVertexIntDataChannelTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxVertexIntDataChannel;
  return result;
}

