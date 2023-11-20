// File Line: 56
// RVA: 0x15D7170
void dynamic_initializer_for__hkxMeshUserChannelInfoClass__()
{
  hkClass::hkClass(
    &hkxMeshUserChannelInfoClass,
    "hkxMeshUserChannelInfo",
    &hkxAttributeHolderClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkxMesh_UserChannelInfoClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xE325D0
hkClass *__fastcall hkxMesh::UserChannelInfo::staticClass()
{
  return &hkxMeshUserChannelInfoClass;
}

// File Line: 66
// RVA: 0xE325E0
void __fastcall finishLoadedObjecthkxMeshUserChannelInfo(void *p, int finishing)
{
  hkStringPtr *v2; // rbx
  hkStringPtr *v3; // rcx
  int v4; // edi

  if ( p )
  {
    v2 = (hkStringPtr *)p;
    v3 = (hkStringPtr *)((char *)p + 32);
    v3[-4].m_stringAndFlag = (const char *)&hkxMesh::UserChannelInfo::`vftable;
    v4 = finishing;
    hkStringPtr::hkStringPtr(v3, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v2 + 5, (hkFinishLoadedObjectFlag)v4);
  }
}

// File Line: 72
// RVA: 0xE32630
void __fastcall cleanupLoadedObjecthkxMeshUserChannelInfo(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE32640
void **__fastcall getVtablehkxMeshUserChannelInfo()
{
  hkStringPtr v1; // [rsp+40h] [rbp-18h]
  hkStringPtr v2; // [rsp+48h] [rbp-10h]

  hkStringPtr::hkStringPtr(&v1, 0);
  hkStringPtr::hkStringPtr(&v2, 0);
  return &hkxMesh::UserChannelInfo::`vftable;
}

// File Line: 98
// RVA: 0x15D71E0
void **dynamic_initializer_for__hkxMeshUserChannelInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxMeshUserChannelInfo();
  hkxMeshUserChannelInfoTypeInfo.m_size = 48i64;
  hkxMeshUserChannelInfoTypeInfo.m_typeName = "hkxMeshUserChannelInfo";
  hkxMeshUserChannelInfoTypeInfo.m_vtable = result;
  hkxMeshUserChannelInfoTypeInfo.m_scopedName = "!hkxMesh::UserChannelInfo";
  hkxMeshUserChannelInfoTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxMeshUserChannelInfo;
  hkxMeshUserChannelInfoTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxMeshUserChannelInfo;
  return result;
}

// File Line: 126
// RVA: 0x15D70A0
void dynamic_initializer_for__hkxMeshClass__()
{
  hkClass::hkClass(
    &hkxMeshClass,
    "hkxMesh",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkxMeshClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 129
// RVA: 0xE325C0
hkClass *__fastcall hkxMesh::staticClass()
{
  return &hkxMeshClass;
}

// File Line: 136
// RVA: 0xE32680
void __fastcall finishLoadedObjecthkxMesh(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkxMesh::hkxMesh);
}

// File Line: 142
// RVA: 0xE326A0
void __fastcall cleanupLoadedObjecthkxMesh(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 146
// RVA: 0xE326B0
hkBaseObjectVtbl *__fastcall getVtablehkxMesh()
{
  hkxMesh v1; // [rsp+20h] [rbp-38h]

  hkxMesh::hkxMesh(&v1, 0);
  return v1.vfptr;
}

// File Line: 168
// RVA: 0x15D7110
hkBaseObjectVtbl *dynamic_initializer_for__hkxMeshTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkxMesh();
  hkxMeshTypeInfo.m_size = 48i64;
  hkxMeshTypeInfo.m_typeName = "hkxMesh";
  hkxMeshTypeInfo.m_vtable = result;
  hkxMeshTypeInfo.m_scopedName = "!hkxMesh";
  hkxMeshTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxMesh;
  hkxMeshTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxMesh;
  return result;
}

