// File Line: 70
// RVA: 0x15C9920
void dynamic_initializer_for__hkpListShapeChildInfoClass__()
{
  hkClass::hkClass(
    &hkpListShapeChildInfoClass,
    "hkpListShapeChildInfo",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpListShape_ChildInfoClass_Members,
    5,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 73
// RVA: 0xCEAF60
hkClass *__fastcall hkpListShape::ChildInfo::staticClass()
{
  return &hkpListShapeChildInfoClass;
}

// File Line: 80
// RVA: 0xCEAF70
void __fastcall cleanupLoadedObjecthkpListShapeChildInfo(void *p)
{
  ;
}

// File Line: 123
// RVA: 0x15C9990
void dynamic_initializer_for__hkpListShapeClass__()
{
  hkClass::hkClass(
    &hkpListShapeClass,
    "hkpListShape",
    &hkpShapeCollectionClass,
    144,
    0i64,
    0,
    &hkpListShapeEnums,
    1,
    &hkpListShapeClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 126
// RVA: 0xCEAF50
hkClass *__fastcall hkpListShape::staticClass()
{
  return &hkpListShapeClass;
}

// File Line: 133
// RVA: 0xCEAF80
void __fastcall finishLoadedObjecthkpListShape(hkpListShape *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkpListShape::hkpListShape(p, finishing);
}

// File Line: 139
// RVA: 0xCEAFA0
void __fastcall cleanupLoadedObjecthkpListShape(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 143
// RVA: 0xCEAFB0
hkBaseObjectVtbl *__fastcall getVtablehkpListShape()
{
  hkpListShape v1; // [rsp+20h] [rbp-98h] BYREF

  hkpListShape::hkpListShape(&v1, 0);
  return v1.hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr;
}

// File Line: 165
// RVA: 0x15C9A00
hkBaseObjectVtbl *dynamic_initializer_for__hkpListShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpListShape();
  hkpListShapeTypeInfo.m_size = 144i64;
  hkpListShapeTypeInfo.m_typeName = "hkpListShape";
  hkpListShapeTypeInfo.m_vtable = result;
  hkpListShapeTypeInfo.m_scopedName = "!hkpListShape";
  hkpListShapeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpListShape;
  hkpListShapeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpListShape;
  return result;
}

