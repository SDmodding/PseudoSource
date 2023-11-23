// File Line: 51
// RVA: 0x15C5EC0
void dynamic_initializer_for__hkLocalFrameClass__()
{
  hkClass::hkClass(
    &hkLocalFrameClass,
    "hkLocalFrame",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 54
// RVA: 0xC547E0
hkClass *__fastcall hkLocalFrame::staticClass()
{
  return &hkLocalFrameClass;
}

// File Line: 81
// RVA: 0x15C5F20
void dynamic_initializer_for__hkLocalFrameGroupClass__()
{
  hkClass::hkClass(
    &hkLocalFrameGroupClass,
    "hkLocalFrameGroup",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkLocalFrameGroup::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 84
// RVA: 0xC547F0
hkClass *__fastcall hkLocalFrameGroup::staticClass()
{
  return &hkLocalFrameGroupClass;
}

// File Line: 91
// RVA: 0xC54810
void __fastcall finishLoadedObjecthkLocalFrameGroup(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 2;
    v2[-2].m_stringAndFlag = (const char *)&hkLocalFrameGroup::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 97
// RVA: 0xC54840
void __fastcall cleanupLoadedObjecthkLocalFrameGroup(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 101
// RVA: 0xC54850
void **__fastcall getVtablehkLocalFrameGroup()
{
  hkStringPtr v1; // [rsp+30h] [rbp-18h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkLocalFrameGroup::`vftable;
}

// File Line: 123
// RVA: 0x15C5F90
void **dynamic_initializer_for__hkLocalFrameGroupTypeInfo__()
{
  void **result; // rax

  result = getVtablehkLocalFrameGroup();
  hkLocalFrameGroupTypeInfo.m_size = 24i64;
  hkLocalFrameGroupTypeInfo.m_typeName = "hkLocalFrameGroup";
  hkLocalFrameGroupTypeInfo.m_vtable = result;
  hkLocalFrameGroupTypeInfo.m_scopedName = "!hkLocalFrameGroup";
  hkLocalFrameGroupTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkLocalFrameGroup;
  hkLocalFrameGroupTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkLocalFrameGroup;
  return result;
}

// File Line: 153
// RVA: 0x15C5FF0
void dynamic_initializer_for__hkSimpleLocalFrameClass__()
{
  hkClass::hkClass(
    &hkSimpleLocalFrameClass,
    "hkSimpleLocalFrame",
    &hkLocalFrameClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkSimpleLocalFrameClass_Members,
    5,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 156
// RVA: 0xC54800
hkClass *__fastcall hkSimpleLocalFrame::staticClass()
{
  return &hkSimpleLocalFrameClass;
}

// File Line: 163
// RVA: 0xC54880
void __fastcall finishLoadedObjecthkSimpleLocalFrame(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v2; // rcx

  if ( p )
  {
    v2 = p + 14;
    v2[-14].m_stringAndFlag = (const char *)&hkSimpleLocalFrame::`vftable;
    hkStringPtr::hkStringPtr(v2, finishing);
  }
}

// File Line: 169
// RVA: 0xC548B0
void __fastcall cleanupLoadedObjecthkSimpleLocalFrame(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 173
// RVA: 0xC548C0
void **__fastcall getVtablehkSimpleLocalFrame()
{
  hkStringPtr v1; // [rsp+90h] [rbp-18h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  return &hkSimpleLocalFrame::`vftable;
}

// File Line: 195
// RVA: 0x15C6060
void **dynamic_initializer_for__hkSimpleLocalFrameTypeInfo__()
{
  void **result; // rax

  result = getVtablehkSimpleLocalFrame();
  hkSimpleLocalFrameTypeInfo.m_size = 128i64;
  hkSimpleLocalFrameTypeInfo.m_typeName = "hkSimpleLocalFrame";
  hkSimpleLocalFrameTypeInfo.m_vtable = result;
  hkSimpleLocalFrameTypeInfo.m_scopedName = "!hkSimpleLocalFrame";
  hkSimpleLocalFrameTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkSimpleLocalFrame;
  hkSimpleLocalFrameTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkSimpleLocalFrame;
  return result;
}

