// File Line: 63
// RVA: 0x15D7EF0
void dynamic_initializer_for__hkxVertexBufferVertexDataClass__()
{
  hkClass::hkClass(
    &hkxVertexBufferVertexDataClass,
    "hkxVertexBufferVertexData",
    0i64,
    104,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexBuffer_VertexDataClass_Members,
    11,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 66
// RVA: 0xE33A40
hkClass *__fastcall hkxVertexBuffer::VertexData::staticClass()
{
  return &hkxVertexBufferVertexDataClass;
}

// File Line: 73
// RVA: 0xE33A50
void __fastcall finishLoadedObjecthkxVertexBufferVertexData(void *p, int finishing)
{
  ;
}

// File Line: 79
// RVA: 0xE33A60
// attributes: thunk
void __fastcall cleanupLoadedObjecthkxVertexBufferVertexData(hkxVertexBuffer::VertexData *p)
{
  hkxVertexBuffer::VertexData::~VertexData(p);
}

// File Line: 118
// RVA: 0x15D7E20
void dynamic_initializer_for__hkxVertexBufferClass__()
{
  hkClass::hkClass(
    &hkxVertexBufferClass,
    "hkxVertexBuffer",
    &hkReferencedObjectClass,
    136,
    0i64,
    0,
    0i64,
    0,
    &hkxVertexBuffer::Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 121
// RVA: 0xE33A30
hkClass *__fastcall hkxVertexBuffer::staticClass()
{
  return &hkxVertexBufferClass;
}

// File Line: 128
// RVA: 0xE33A70
void __fastcall finishLoadedObjecthkxVertexBuffer(hkxVertexBuffer *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkxVertexBuffer::hkxVertexBuffer(p, finishing);
}

// File Line: 134
// RVA: 0xE33A90
void __fastcall cleanupLoadedObjecthkxVertexBuffer(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 138
// RVA: 0xE33AA0
hkBaseObjectVtbl *__fastcall getVtablehkxVertexBuffer()
{
  hkxVertexBuffer v1; // [rsp+20h] [rbp-98h] BYREF

  hkxVertexBuffer::hkxVertexBuffer(&v1, 0);
  return v1.vfptr;
}

// File Line: 160
// RVA: 0x15D7E90
hkBaseObjectVtbl *dynamic_initializer_for__hkxVertexBufferTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkxVertexBuffer();
  hkxVertexBufferTypeInfo.m_size = 136i64;
  hkxVertexBufferTypeInfo.m_typeName = "hkxVertexBuffer";
  hkxVertexBufferTypeInfo.m_vtable = result;
  hkxVertexBufferTypeInfo.m_scopedName = "!hkxVertexBuffer";
  hkxVertexBufferTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxVertexBuffer;
  hkxVertexBufferTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxVertexBuffer;
  return result;
}

