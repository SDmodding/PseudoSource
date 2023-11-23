// File Line: 68
// RVA: 0x15BF0C0
void dynamic_initializer_for__hkaParameterizedAnimationReferenceFrameClass__()
{
  hkClass::hkClass(
    &hkaParameterizedAnimationReferenceFrameClass,
    "hkaParameterizedAnimationReferenceFrame",
    &hkaDefaultAnimatedReferenceFrameClass,
    128,
    0i64,
    0,
    &hkaParameterizedAnimationReferenceFrameEnums,
    1,
    &hkaParameterizedAnimationReferenceFrameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 71
// RVA: 0xB1D960
hkClass *__fastcall hkaParameterizedAnimationReferenceFrame::staticClass()
{
  return &hkaParameterizedAnimationReferenceFrameClass;
}

// File Line: 78
// RVA: 0xB1D970
void __fastcall finishLoadedObjecthkaParameterizedAnimationReferenceFrame(_BYTE *p, int finishing)
{
  if ( p )
  {
    p[16] = 1;
    *(_QWORD *)p = &hkaParameterizedAnimationReferenceFrame::`vftable;
  }
}

// File Line: 84
// RVA: 0xB1D990
void __fastcall cleanupLoadedObjecthkaParameterizedAnimationReferenceFrame(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 88
// RVA: 0xB1D9A0
void **__fastcall getVtablehkaParameterizedAnimationReferenceFrame()
{
  return &hkaParameterizedAnimationReferenceFrame::`vftable;
}

// File Line: 110
// RVA: 0x15BF130
void **dynamic_initializer_for__hkaParameterizedAnimationReferenceFrameTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaParameterizedAnimationReferenceFrame();
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_size = 128i64;
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_typeName = "hkaParameterizedAnimationReferenceFrame";
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_vtable = result;
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_scopedName = "!hkaParameterizedAnimationReferenceFrame";
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaParameterizedAnimationReferenceFrame;
  hkaParameterizedAnimationReferenceFrameTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaParameterizedAnimationReferenceFrame;
  return result;
}

