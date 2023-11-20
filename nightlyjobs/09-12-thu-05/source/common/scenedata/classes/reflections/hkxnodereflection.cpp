// File Line: 56
// RVA: 0x15D7310
void dynamic_initializer_for__hkxNodeAnnotationDataClass__()
{
  hkClass::hkClass(
    &hkxNodeAnnotationDataClass,
    "hkxNodeAnnotationData",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkxNode_AnnotationDataClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xE329B0
hkClass *__fastcall hkxNode::AnnotationData::staticClass()
{
  return &hkxNodeAnnotationDataClass;
}

// File Line: 66
// RVA: 0xE329C0
void __fastcall finishLoadedObjecthkxNodeAnnotationData(void *p, int finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr((hkStringPtr *)p + 1, (hkFinishLoadedObjectFlag)finishing);
}

// File Line: 72
// RVA: 0xE329E0
void __fastcall cleanupLoadedObjecthkxNodeAnnotationData(void *p)
{
  hkStringPtr::~hkStringPtr((hkStringPtr *)p + 1);
}

// File Line: 117
// RVA: 0x15D7370
void dynamic_initializer_for__hkxNodeClass__()
{
  hkClass::hkClass(
    &hkxNodeClass,
    "hkxNode",
    &hkxAttributeHolderClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkxNodeClass_Members,
    9,
    0i64,
    0i64,
    0,
    4u);
}

// File Line: 120
// RVA: 0xE329A0
hkClass *__fastcall hkxNode::staticClass()
{
  return &hkxNodeClass;
}

// File Line: 127
// RVA: 0xE329F0
void __fastcall finishLoadedObjecthkxNode(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 32);
    v3[-4].m_stringAndFlag = (const char *)&hkxNode::`vftable;
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 14, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 133
// RVA: 0xE32A40
void __fastcall cleanupLoadedObjecthkxNode(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 137
// RVA: 0xE32A50
void **__fastcall getVtablehkxNode()
{
  hkStringPtr v1; // [rsp+40h] [rbp-68h]
  hkStringPtr v2; // [rsp+90h] [rbp-18h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkxNode::`vftable;
}

// File Line: 159
// RVA: 0x15D73E0
void **dynamic_initializer_for__hkxNodeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxNode();
  hkxNodeTypeInfo.m_size = 128i64;
  hkxNodeTypeInfo.m_typeName = "hkxNode";
  hkxNodeTypeInfo.m_vtable = result;
  hkxNodeTypeInfo.m_scopedName = "!hkxNode";
  hkxNodeTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxNode;
  hkxNodeTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxNode;
  return result;
}

