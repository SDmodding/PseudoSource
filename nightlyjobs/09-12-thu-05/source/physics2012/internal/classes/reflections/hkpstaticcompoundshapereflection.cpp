// File Line: 70
// RVA: 0x15D2700
void dynamic_initializer_for__hkpStaticCompoundShapeInstanceClass__()
{
  hkClass::hkClass(
    &hkpStaticCompoundShapeInstanceClass,
    "hkpStaticCompoundShapeInstance",
    0i64,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpStaticCompoundShape::Instance::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 73
// RVA: 0xD99200
hkClass *__fastcall hkpStaticCompoundShape::Instance::staticClass()
{
  return &hkpStaticCompoundShapeInstanceClass;
}

// File Line: 80
// RVA: 0xD99220
void __fastcall cleanupLoadedObjecthkpStaticCompoundShapeInstance(void *p)
{
  ;
}

// File Line: 124
// RVA: 0x15D2680
void dynamic_initializer_for__hkpStaticCompoundShapeClass__()
{
  hkClass::hkClass(
    &hkpStaticCompoundShapeClass,
    "hkpStaticCompoundShape",
    &hkpBvTreeShapeClass,
    160,
    0i64,
    1,
    &hkpStaticCompoundShapeEnums,
    1,
    &hkpStaticCompoundShape::Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 127
// RVA: 0xD99210
hkClass *__fastcall hkpStaticCompoundShape::staticClass()
{
  return &hkpStaticCompoundShapeClass;
}

// File Line: 134
// RVA: 0xD99230
void __fastcall finishLoadedObjecthkpStaticCompoundShape(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkpStaticCompoundShape::hkpStaticCompoundShape);
}

// File Line: 140
// RVA: 0xD99250
void __fastcall cleanupLoadedObjecthkpStaticCompoundShape(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 144
// RVA: 0xD99260
hkBaseObjectVtbl *__fastcall getVtablehkpStaticCompoundShape()
{
  hkpStaticCompoundShape v1; // [rsp+20h] [rbp-A8h]

  hkpStaticCompoundShape::hkpStaticCompoundShape(&v1, 0);
  return v1.vfptr;
}

// File Line: 166
// RVA: 0x15D2760
hkBaseObjectVtbl *dynamic_initializer_for__hkpStaticCompoundShapeTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkpStaticCompoundShape();
  hkpStaticCompoundShapeTypeInfo.m_size = 160i64;
  hkpStaticCompoundShapeTypeInfo.m_typeName = "hkpStaticCompoundShape";
  hkpStaticCompoundShapeTypeInfo.m_vtable = result;
  hkpStaticCompoundShapeTypeInfo.m_scopedName = "!hkpStaticCompoundShape";
  hkpStaticCompoundShapeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpStaticCompoundShape;
  hkpStaticCompoundShapeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpStaticCompoundShape;
  return result;
}

