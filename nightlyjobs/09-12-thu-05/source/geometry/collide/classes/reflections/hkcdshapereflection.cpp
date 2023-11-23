// File Line: 101
// RVA: 0x15C7960
void dynamic_initializer_for__hkcdShapeTypeClass__()
{
  hkClass::hkClass(
    &hkcdShapeTypeClass,
    "hkcdShapeType",
    0i64,
    1,
    0i64,
    0,
    &hkcdShapeTypeEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 104
// RVA: 0xC8D8D0
hkClass *__fastcall hkcdShapeType::staticClass()
{
  return &hkcdShapeTypeClass;
}

// File Line: 111
// RVA: 0xC8D910
void __fastcall cleanupLoadedObjecthkcdShapeType(void *p)
{
  ;
}

// File Line: 160
// RVA: 0x15C78A0
void dynamic_initializer_for__hkcdShapeDispatchTypeClass__()
{
  hkClass::hkClass(
    &hkcdShapeDispatchTypeClass,
    "hkcdShapeDispatchType",
    0i64,
    1,
    0i64,
    0,
    &hkcdShapeDispatchTypeEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 163
// RVA: 0xC8D8E0
hkClass *__fastcall hkcdShapeDispatchType::staticClass()
{
  return &hkcdShapeDispatchTypeClass;
}

// File Line: 170
// RVA: 0xC8D920
void __fastcall cleanupLoadedObjecthkcdShapeDispatchType(void *p)
{
  ;
}

// File Line: 216
// RVA: 0x15C7900
void dynamic_initializer_for__hkcdShapeInfoCodecTypeClass__()
{
  hkClass::hkClass(
    &hkcdShapeInfoCodecTypeClass,
    "hkcdShapeInfoCodecType",
    0i64,
    1,
    0i64,
    0,
    &hkcdShapeInfoCodecTypeEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 219
// RVA: 0xC8D8F0
hkClass *__fastcall hkcdShapeInfoCodecType::staticClass()
{
  return &hkcdShapeInfoCodecTypeClass;
}

// File Line: 226
// RVA: 0xC8D930
void __fastcall cleanupLoadedObjecthkcdShapeInfoCodecType(void *p)
{
  ;
}

// File Line: 248
// RVA: 0x15C7880
hkClassEnum *dynamic_initializer_for__hkcdShapeClass_Members__()
{
  hkClassEnum *result; // rax

  unk_14210A788 = hkcdShapeDispatchTypeShapeDispatchTypeEnumEnum;
  result = hkcdShapeInfoCodecTypeShapeInfoCodecTypeEnumEnum;
  unk_14210A7D8 = hkcdShapeInfoCodecTypeShapeInfoCodecTypeEnumEnum;
  return result;
}

// File Line: 267
// RVA: 0x15C7810
void dynamic_initializer_for__hkcdShapeClass__()
{
  hkClass::hkClass(
    &hkcdShapeClass,
    "hkcdShape",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkcdShapeClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 270
// RVA: 0xC8D900
hkClass *__fastcall hkcdShape::staticClass()
{
  return &hkcdShapeClass;
}

// File Line: 277
// RVA: 0xC8D940
void __fastcall finishLoadedObjecthkcdShape(hkcdShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkcdShape::hkcdShape(p, finishing);
}

// File Line: 283
// RVA: 0xC8D960
void __fastcall cleanupLoadedObjecthkcdShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 287
// RVA: 0xC8D970
hkBaseObjectVtbl *__fastcall getVtablehkcdShape()
{
  hkcdShape v1; // [rsp+20h] [rbp-28h] BYREF

  hkcdShape::hkcdShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 309
// RVA: 0x15C79C0
hkBaseObjectVtbl *dynamic_initializer_for__hkcdShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkcdShape();
  hkcdShapeTypeInfo.m_size = 24i64;
  hkcdShapeTypeInfo.m_typeName = "hkcdShape";
  hkcdShapeTypeInfo.m_vtable = result;
  hkcdShapeTypeInfo.m_scopedName = "!hkcdShape";
  hkcdShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkcdShape;
  hkcdShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkcdShape;
  return result;
}

