// File Line: 59
// RVA: 0x15BEB80
void dynamic_initializer_for__hkaDefaultAnimatedReferenceFrameClass__()
{
  hkClass::hkClass(
    &hkaDefaultAnimatedReferenceFrameClass,
    "hkaDefaultAnimatedReferenceFrame",
    &hkaAnimatedReferenceFrameClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaDefaultAnimatedReferenceFrameClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xB1D310
hkClass *__fastcall hkaDefaultAnimatedReferenceFrame::staticClass()
{
  return &hkaDefaultAnimatedReferenceFrameClass;
}

// File Line: 69
// RVA: 0xB1D320
void __fastcall finishLoadedObjecthkaDefaultAnimatedReferenceFrame(_BYTE *p, int finishing)
{
  if ( p )
  {
    p[16] = 1;
    *(_QWORD *)p = &hkaDefaultAnimatedReferenceFrame::`vftable;
  }
}

// File Line: 75
// RVA: 0xB1D340
void __fastcall cleanupLoadedObjecthkaDefaultAnimatedReferenceFrame(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 79
// RVA: 0xB1D350
void **__fastcall getVtablehkaDefaultAnimatedReferenceFrame()
{
  return &hkaDefaultAnimatedReferenceFrame::`vftable;
}

// File Line: 101
// RVA: 0x15BEBF0
void **dynamic_initializer_for__hkaDefaultAnimatedReferenceFrameTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaDefaultAnimatedReferenceFrame();
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_size = 96i64;
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_typeName = "hkaDefaultAnimatedReferenceFrame";
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_vtable = result;
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_scopedName = "!hkaDefaultAnimatedReferenceFrame";
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaDefaultAnimatedReferenceFrame;
  hkaDefaultAnimatedReferenceFrameTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaDefaultAnimatedReferenceFrame;
  return result;
}

