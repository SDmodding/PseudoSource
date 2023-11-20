// File Line: 53
// RVA: 0x15D7FD0
hkClassEnum *dynamic_initializer_for__hkxVertexFloatDataChannelClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxVertexFloatDataChannelVertexFloatDimensionsEnum;
  unk_142115D48 = hkxVertexFloatDataChannelVertexFloatDimensionsEnum;
  return result;
}

// File Line: 70
// RVA: 0x15D7F60
void dynamic_initializer_for__hkxVertexFloatDataChannelClass__()
{
  hkClass::hkClass(
    &hkxVertexFloatDataChannelClass,
    "hkxVertexFloatDataChannel",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    &hkxVertexFloatDataChannelEnums,
    1,
    &hkxVertexFloatDataChannelClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 73
// RVA: 0xE33AC0
hkClass *__fastcall hkxVertexFloatDataChannel::staticClass()
{
  return &hkxVertexFloatDataChannelClass;
}

// File Line: 80
// RVA: 0xE33AD0
void __fastcall finishLoadedObjecthkxVertexFloatDataChannel(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxVertexFloatDataChannel::`vftable;
}

// File Line: 86
// RVA: 0xE33AF0
void __fastcall cleanupLoadedObjecthkxVertexFloatDataChannel(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 90
// RVA: 0xE33B00
void **__fastcall getVtablehkxVertexFloatDataChannel()
{
  return &hkxVertexFloatDataChannel::`vftable;
}

// File Line: 112
// RVA: 0x15D7FE0
void **dynamic_initializer_for__hkxVertexFloatDataChannelTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxVertexFloatDataChannel();
  hkxVertexFloatDataChannelTypeInfo.m_size = 40i64;
  hkxVertexFloatDataChannelTypeInfo.m_typeName = "hkxVertexFloatDataChannel";
  hkxVertexFloatDataChannelTypeInfo.m_vtable = result;
  hkxVertexFloatDataChannelTypeInfo.m_scopedName = "!hkxVertexFloatDataChannel";
  hkxVertexFloatDataChannelTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxVertexFloatDataChannel;
  hkxVertexFloatDataChannelTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxVertexFloatDataChannel;
  return result;
}

