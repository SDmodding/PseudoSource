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
    2u);
}

// File Line: 61
// RVA: 0xB1D1D0
hkClass *__fastcall hkaBoneAttachment::staticClass()
{
  return &hkaBoneAttachmentClass;
}

// File Line: 68
// RVA: 0xB1D1E0
void __fastcall finishLoadedObjecthkaBoneAttachment(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 16);
    v3[-2].m_stringAndFlag = (const char *)&hkaBoneAttachment::`vftable';
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 13, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 74
// RVA: 0xB1D230
void __fastcall cleanupLoadedObjecthkaBoneAttachment(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xB1D240
void **__fastcall getVtablehkaBoneAttachment()
{
  hkStringPtr v1; // [rsp+30h] [rbp-78h]
  hkStringPtr v2; // [rsp+88h] [rbp-20h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkaBoneAttachment::`vftable';
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
  hkaBoneAttachmentTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaBoneAttachment;
  hkaBoneAttachmentTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaBoneAttachment;
  return result;
}

