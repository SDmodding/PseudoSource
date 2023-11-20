// File Line: 111
// RVA: 0x15DF860
hkClassEnum *dynamic_initializer_for__hkVertexFormat_ElementClass_Members__()
{
  hkClassEnum *result; // rax

  hkVertexFormat_ElementClass_Members.m_enum = hkVertexFormatComponentTypeEnum;
  unk_142128590 = hkVertexFormatComponentUsageEnum;
  result = hkVertexFormatHintFlagsEnum;
  unk_1421285E0 = hkVertexFormatHintFlagsEnum;
  return result;
}

// File Line: 132
// RVA: 0x15DF800
void dynamic_initializer_for__hkVertexFormatElementClass__()
{
  hkClass::hkClass(
    &hkVertexFormatElementClass,
    "hkVertexFormatElement",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkVertexFormat_ElementClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 135
// RVA: 0x1319640
hkClass *__fastcall hkVertexFormat::Element::staticClass()
{
  return &hkVertexFormatElementClass;
}

// File Line: 142
// RVA: 0x1319660
void __fastcall cleanupLoadedObjecthkVertexFormatElement(void *p)
{
  ;
}

// File Line: 179
// RVA: 0x15DF790
void dynamic_initializer_for__hkVertexFormatClass__()
{
  hkClass::hkClass(
    &hkVertexFormatClass,
    "hkVertexFormat",
    0i64,
    260,
    0i64,
    0,
    &hkVertexFormatEnums,
    4,
    &hkVertexFormatClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 182
// RVA: 0x1319630
hkClass *__fastcall hkVertexFormat::staticClass()
{
  return &hkVertexFormatClass;
}

// File Line: 189
// RVA: 0x1319670
void __fastcall finishLoadedObjecthkVertexFormat(void *p, int finishing)
{
  ;
}

// File Line: 195
// RVA: 0x1319680
void __fastcall cleanupLoadedObjecthkVertexFormat(void *p)
{
  ;
}

// File Line: 257
// RVA: 0x15DF730
void dynamic_initializer_for__hkMeshVertexBufferClass__()
{
  hkClass::hkClass(
    &hkMeshVertexBufferClass,
    "hkMeshVertexBuffer",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    &hkMeshVertexBufferEnums,
    2,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 260
// RVA: 0x1319650
hkClass *__fastcall hkMeshVertexBuffer::staticClass()
{
  return &hkMeshVertexBufferClass;
}

