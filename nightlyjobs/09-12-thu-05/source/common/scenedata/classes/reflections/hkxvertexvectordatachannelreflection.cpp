// File Line: 52
// RVA: 0x15D81E0
void dynamic_initializer_for__hkxVertexVectorDataChannelClass__()
{
  hkClass::hkClass(
    &hkxVertexVectorDataChannelClass,
    "hkxVertexVectorDataChannel",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexVectorDataChannelClass_Members,
    1,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 55
// RVA: 0xE33BB0
hkClass *__fastcall hkxVertexVectorDataChannel::staticClass()
{
  return &hkxVertexVectorDataChannelClass;
}

// File Line: 62
// RVA: 0xE33BC0
void __fastcall finishLoadedObjecthkxVertexVectorDataChannel(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxVertexVectorDataChannel::`vftable;
}

// File Line: 68
// RVA: 0xE33BE0
void __fastcall cleanupLoadedObjecthkxVertexVectorDataChannel(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE33BF0
void **__fastcall getVtablehkxVertexVectorDataChannel()
{
  return &hkxVertexVectorDataChannel::`vftable;
}

// File Line: 94
// RVA: 0x15D8250
void **dynamic_initializer_for__hkxVertexVectorDataChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxVertexVectorDataChannel();
  hkxVertexVectorDataChannelTypeInfo.m_size = 32i64;
  hkxVertexVectorDataChannelTypeInfo.m_typeName = "hkxVertexVectorDataChannel";
  hkxVertexVectorDataChannelTypeInfo.m_vtable = result;
  hkxVertexVectorDataChannelTypeInfo.m_scopedName = "!hkxVertexVectorDataChannel";
  hkxVertexVectorDataChannelTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxVertexVectorDataChannel;
  hkxVertexVectorDataChannelTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxVertexVectorDataChannel;
  return result;
}

