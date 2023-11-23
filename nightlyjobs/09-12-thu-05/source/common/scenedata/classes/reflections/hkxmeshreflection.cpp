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
void __fastcall finishLoadedObjecthkxMeshUserChannelInfo(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  hkStringPtr *v3; // rcx

  if ( p )
  {
    v3 = p + 4;
    v3[-4].m_stringAndFlag = (const char *)&hkxMesh::UserChannelInfo::`vftable;
    hkStringPtr::hkStringPtr(v3, finishing);
    hkStringPtr::hkStringPtr(p + 5, finishing);
  }
}

// File Line: 72
// RVA: 0xE32630
void __fastcall cleanupLoadedObjecthkxMeshUserChannelInfo(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE32640
void **__fastcall getVtablehkxMeshUserChannelInfo()
{
  hkStringPtr v1; // [rsp+40h] [rbp-18h] BYREF
  hkStringPtr v2; // [rsp+48h] [rbp-10h] BYREF

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
  hkxMeshUserChannelInfoTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMeshUserChannelInfo;
  hkxMeshUserChannelInfoTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMeshUserChannelInfo;
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
    1);
}

// File Line: 129
// RVA: 0xE325C0
hkClass *__fastcall hkxMesh::staticClass()
{
  return &hkxMeshClass;
}

// File Line: 136
// RVA: 0xE32680
void __fastcall finishLoadedObjecthkxMesh(hkxMesh *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkxMesh::hkxMesh(p, finishing);
}

// File Line: 142
// RVA: 0xE326A0
void __fastcall cleanupLoadedObjecthkxMesh(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 146
// RVA: 0xE326B0
hkBaseObjectVtbl *__fastcall getVtablehkxMesh()
{
  hkxMesh v1; // [rsp+20h] [rbp-38h] BYREF

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
  hkxMeshTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxMesh;
  hkxMeshTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxMesh;
  return result;
}

