// File Line: 61
// RVA: 0x15DF600
void dynamic_initializer_for__hkMemoryMeshBodyClass__()
{
  hkClass::hkClass(
    &hkMemoryMeshBodyClass,
    "hkMemoryMeshBody",
    &hkMeshBodyClass,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkMemoryMeshBody::Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0x13195C0
hkClass *__fastcall hkMemoryMeshBody::staticClass()
{
  return &hkMemoryMeshBodyClass;
}

// File Line: 71
// RVA: 0x13195D0
void __fastcall finishLoadedObjecthkMemoryMeshBody(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkMemoryMeshBody::hkMemoryMeshBody);
}

// File Line: 77
// RVA: 0x13195F0
void __fastcall cleanupLoadedObjecthkMemoryMeshBody(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 81
// RVA: 0x1319600
hkBaseObjectVtbl *__fastcall getVtablehkMemoryMeshBody()
{
  hkMemoryMeshBody v1; // [rsp+20h] [rbp-88h]

  hkMemoryMeshBody::hkMemoryMeshBody(&v1, 0);
  return v1.vfptr;
}

// File Line: 103
// RVA: 0x15DF670
hkBaseObjectVtbl *dynamic_initializer_for__hkMemoryMeshBodyTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkMemoryMeshBody();
  hkMemoryMeshBodyTypeInfo.m_size = 128i64;
  hkMemoryMeshBodyTypeInfo.m_typeName = "hkMemoryMeshBody";
  hkMemoryMeshBodyTypeInfo.m_vtable = result;
  hkMemoryMeshBodyTypeInfo.m_scopedName = "!hkMemoryMeshBody";
  hkMemoryMeshBodyTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkMemoryMeshBody;
  hkMemoryMeshBodyTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkMemoryMeshBody;
  return result;
}

