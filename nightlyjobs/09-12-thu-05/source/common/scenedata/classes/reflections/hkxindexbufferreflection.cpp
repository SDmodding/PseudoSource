// File Line: 54
// RVA: 0x15D6AE0
hkClassEnum *dynamic_initializer_for__hkxIndexBufferClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxIndexBufferIndexTypeEnum;
  hkxIndexBufferClass_Members.m_enum = hkxIndexBufferIndexTypeEnum;
  return result;
}

// File Line: 75
// RVA: 0x15D6A70
void dynamic_initializer_for__hkxIndexBufferClass__()
{
  hkClass::hkClass(
    &hkxIndexBufferClass,
    "hkxIndexBuffer",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    &hkxIndexBufferEnums,
    1,
    &hkxIndexBufferClass_Members,
    5,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 78
// RVA: 0xE31F80
hkClass *__fastcall hkxIndexBuffer::staticClass()
{
  return &hkxIndexBufferClass;
}

// File Line: 85
// RVA: 0xE31F90
void __fastcall finishLoadedObjecthkxIndexBuffer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxIndexBuffer::`vftable';
}

// File Line: 91
// RVA: 0xE31FB0
void __fastcall cleanupLoadedObjecthkxIndexBuffer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 95
// RVA: 0xE31FC0
void **__fastcall getVtablehkxIndexBuffer()
{
  return &hkxIndexBuffer::`vftable';
}

// File Line: 117
// RVA: 0x15D6AF0
void **dynamic_initializer_for__hkxIndexBufferTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxIndexBuffer();
  hkxIndexBufferTypeInfo.m_size = 64i64;
  hkxIndexBufferTypeInfo.m_typeName = "hkxIndexBuffer";
  hkxIndexBufferTypeInfo.m_vtable = result;
  hkxIndexBufferTypeInfo.m_scopedName = "!hkxIndexBuffer";
  hkxIndexBufferTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxIndexBuffer;
  hkxIndexBufferTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxIndexBuffer;
  return result;
}

