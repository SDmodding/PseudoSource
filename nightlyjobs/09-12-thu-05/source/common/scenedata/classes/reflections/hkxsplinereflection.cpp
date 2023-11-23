// File Line: 55
// RVA: 0x15D7A50
hkClassEnum *dynamic_initializer_for__hkxSpline_ControlPointClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkxSplineControlTypeEnum;
  unk_142115AD8 = hkxSplineControlTypeEnum;
  unk_142115B00 = hkxSplineControlTypeEnum;
  return result;
}

// File Line: 72
// RVA: 0x15D7990
void dynamic_initializer_for__hkxSplineControlPointClass__()
{
  hkClass::hkClass(
    &hkxSplineControlPointClass,
    "hkxSplineControlPoint",
    0i64,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkxSpline_ControlPointClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 75
// RVA: 0xE33230
hkClass *__fastcall hkxSpline::ControlPoint::staticClass()
{
  return &hkxSplineControlPointClass;
}

// File Line: 82
// RVA: 0xE33240
void __fastcall cleanupLoadedObjecthkxSplineControlPoint(void *p)
{
  ;
}

// File Line: 121
// RVA: 0x15D7920
void dynamic_initializer_for__hkxSplineClass__()
{
  hkClass::hkClass(
    &hkxSplineClass,
    "hkxSpline",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    &hkxSplineEnums,
    1,
    &hkxSplineClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 124
// RVA: 0xE33220
hkClass *__fastcall hkxSpline::staticClass()
{
  return &hkxSplineClass;
}

// File Line: 131
// RVA: 0xE33250
void __fastcall finishLoadedObjecthkxSpline(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxSpline::`vftable;
}

// File Line: 137
// RVA: 0xE33270
void __fastcall cleanupLoadedObjecthkxSpline(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 141
// RVA: 0xE33280
void **__fastcall getVtablehkxSpline()
{
  return &hkxSpline::`vftable;
}

// File Line: 163
// RVA: 0x15D79F0
void **dynamic_initializer_for__hkxSplineTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSpline();
  hkxSplineTypeInfo.m_size = 40i64;
  hkxSplineTypeInfo.m_typeName = "hkxSpline";
  hkxSplineTypeInfo.m_vtable = result;
  hkxSplineTypeInfo.m_scopedName = "!hkxSpline";
  hkxSplineTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxSpline;
  hkxSplineTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxSpline;
  return result;
}

