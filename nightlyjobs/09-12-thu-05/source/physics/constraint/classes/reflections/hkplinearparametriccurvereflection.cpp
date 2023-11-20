// File Line: 59
// RVA: 0x15CD7D0
void dynamic_initializer_for__hkpLinearParametricCurveClass__()
{
  hkClass::hkClass(
    &hkpLinearParametricCurveClass,
    "hkpLinearParametricCurve",
    &hkpParametricCurveClass,
    80,
    0i64,
    0,
    0i64,
    0,
    &hkpLinearParametricCurveClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xD43D20
hkClass *__fastcall hkpLinearParametricCurve::staticClass()
{
  return &hkpLinearParametricCurveClass;
}

// File Line: 69
// RVA: 0xD43D30
void __fastcall finishLoadedObjecthkpLinearParametricCurve(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpLinearParametricCurve::`vftable;
}

// File Line: 75
// RVA: 0xD43D50
void __fastcall cleanupLoadedObjecthkpLinearParametricCurve(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 79
// RVA: 0xD43D60
void **__fastcall getVtablehkpLinearParametricCurve()
{
  return &hkpLinearParametricCurve::`vftable;
}

// File Line: 101
// RVA: 0x15CD840
void **dynamic_initializer_for__hkpLinearParametricCurveTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpLinearParametricCurve();
  hkpLinearParametricCurveTypeInfo.m_size = 80i64;
  hkpLinearParametricCurveTypeInfo.m_typeName = "hkpLinearParametricCurve";
  hkpLinearParametricCurveTypeInfo.m_vtable = result;
  hkpLinearParametricCurveTypeInfo.m_scopedName = "!hkpLinearParametricCurve";
  hkpLinearParametricCurveTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpLinearParametricCurve;
  hkpLinearParametricCurveTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpLinearParametricCurve;
  return result;
}

