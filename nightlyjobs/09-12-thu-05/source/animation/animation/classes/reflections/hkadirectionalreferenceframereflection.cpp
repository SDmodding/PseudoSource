// File Line: 52
// RVA: 0x15BEC50
void dynamic_initializer_for__hkaDirectionalReferenceFrameClass__()
{
  hkClass::hkClass(
    &hkaDirectionalReferenceFrameClass,
    "hkaDirectionalReferenceFrame",
    &hkaParameterizedReferenceFrameClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkaDirectionalReferenceFrameClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xB1D400
hkClass *__fastcall hkaDirectionalReferenceFrame::staticClass()
{
  return &hkaDirectionalReferenceFrameClass;
}

// File Line: 62
// RVA: 0xB1D410
void __fastcall finishLoadedObjecthkaDirectionalReferenceFrame(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame);
}

// File Line: 68
// RVA: 0xB1D430
void __fastcall cleanupLoadedObjecthkaDirectionalReferenceFrame(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 72
// RVA: 0xB1D440
hkBaseObjectVtbl *__fastcall getVtablehkaDirectionalReferenceFrame()
{
  hkaDirectionalReferenceFrame v1; // [rsp+20h] [rbp-78h]

  hkaDirectionalReferenceFrame::hkaDirectionalReferenceFrame(&v1, 0);
  return v1.vfptr;
}

// File Line: 94
// RVA: 0x15BECC0
hkBaseObjectVtbl *dynamic_initializer_for__hkaDirectionalReferenceFrameTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaDirectionalReferenceFrame();
  hkaDirectionalReferenceFrameTypeInfo.m_size = 112i64;
  hkaDirectionalReferenceFrameTypeInfo.m_typeName = "hkaDirectionalReferenceFrame";
  hkaDirectionalReferenceFrameTypeInfo.m_vtable = result;
  hkaDirectionalReferenceFrameTypeInfo.m_scopedName = "!hkaDirectionalReferenceFrame";
  hkaDirectionalReferenceFrameTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaDirectionalReferenceFrame;
  hkaDirectionalReferenceFrameTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaDirectionalReferenceFrame;
  return result;
}

