// File Line: 58
// RVA: 0x15BEAB0
void dynamic_initializer_for__hkaBoneAttachmentClass__()
{
  hkClass::hkClass(
    &hkaBoneAttachmentClass,
    "hkaBoneAttachment",
    &hkReferencedObjectClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkaBoneAttachmentClass_Members,
    5,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 61
// RVA: 0xB1D1D0
hkClass *__fastcall hkaBoneAttachment::staticClass()
{
  return &hkaBoneAttachmentClass;
}

// File Line: 68
// RVA: 0xB1D1E0
void __fastcall finishLoadedObjecthkaBoneAttachment(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 2;
    v3[-2].m_stringAndFlag = (const char *)&hkaBoneAttachment::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    hkStringPtr::hkStringPtr(p + 13, finishing);
  }
}

// File Line: 74
// RVA: 0xB1D230
void __fastcall cleanupLoadedObjecthkaBoneAttachment(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xB1D240
void **__fastcall getVtablehkaBoneAttachment()
{
  hkStringPtr v1; // [rsp+30h] [rbp-78h] BYREF
  hkStringPtr v2; // [rsp+88h] [rbp-20h] BYREF

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkaBoneAttachment::`vftable;
}

// File Line: 100
// RVA: 0x15BEB20
void **dynamic_initializer_for__hkaBoneAttachmentTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaBoneAttachment();
  hkaBoneAttachmentTypeInfo.m_size = 128i64;
  hkaBoneAttachmentTypeInfo.m_typeName = "hkaBoneAttachment";
  hkaBoneAttachmentTypeInfo.m_vtable = result;
  hkaBoneAttachmentTypeInfo.m_scopedName = "!hkaBoneAttachment";
  hkaBoneAttachmentTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaBoneAttachment;
  hkaBoneAttachmentTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaBoneAttachment;
  return result;
}

