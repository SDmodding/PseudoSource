// File Line: 53
// RVA: 0x15BE750
void dynamic_initializer_for__hkaAngularReferenceFrameClass__()
{
  hkClass::hkClass(
    &hkaAngularReferenceFrameClass,
    "hkaAngularReferenceFrame",
    &hkaParameterizedReferenceFrameClass,
    112,
    0i64,
    0,
    0i64,
    0,
    &hkaAngularReferenceFrameClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xB1CC30
hkClass *__fastcall hkaAngularReferenceFrame::staticClass()
{
  return &hkaAngularReferenceFrameClass;
}

// File Line: 63
// RVA: 0xB1CC40
void __fastcall finishLoadedObjecthkaAngularReferenceFrame(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaAngularReferenceFrame::hkaAngularReferenceFrame);
}

// File Line: 69
// RVA: 0xB1CC60
void __fastcall cleanupLoadedObjecthkaAngularReferenceFrame(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xB1CC70
hkBaseObjectVtbl *__fastcall getVtablehkaAngularReferenceFrame()
{
  hkaAngularReferenceFrame v1; // [rsp+20h] [rbp-78h]

  hkaAngularReferenceFrame::hkaAngularReferenceFrame(&v1, 0);
  return v1.vfptr;
}

// File Line: 95
// RVA: 0x15BE7C0
hkBaseObjectVtbl *dynamic_initializer_for__hkaAngularReferenceFrameTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaAngularReferenceFrame();
  hkaAngularReferenceFrameTypeInfo.m_size = 112i64;
  hkaAngularReferenceFrameTypeInfo.m_typeName = "hkaAngularReferenceFrame";
  hkaAngularReferenceFrameTypeInfo.m_vtable = result;
  hkaAngularReferenceFrameTypeInfo.m_scopedName = "!hkaAngularReferenceFrame";
  hkaAngularReferenceFrameTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaAngularReferenceFrame;
  hkaAngularReferenceFrameTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaAngularReferenceFrame;
  return result;
}

