// File Line: 60
// RVA: 0x15D5EF0
void dynamic_initializer_for__hkAlignSceneToNodeOptionsClass__()
{
  hkClass::hkClass(
    &hkAlignSceneToNodeOptionsClass,
    "hkAlignSceneToNodeOptions",
    &hkReferencedObjectClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkAlignSceneToNodeOptions::Members,
    9,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 63
// RVA: 0xE31630
hkClass *__fastcall hkAlignSceneToNodeOptions::staticClass()
{
  return &hkAlignSceneToNodeOptionsClass;
}

// File Line: 70
// RVA: 0xE31640
void __fastcall finishLoadedObjecthkAlignSceneToNodeOptions(
        hkAlignSceneToNodeOptions *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkAlignSceneToNodeOptions::hkAlignSceneToNodeOptions(p, finishing);
}

// File Line: 76
// RVA: 0xE31660
void __fastcall cleanupLoadedObjecthkAlignSceneToNodeOptions(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 80
// RVA: 0xE31670
hkBaseObjectVtbl *__fastcall getVtablehkAlignSceneToNodeOptions()
{
  hkAlignSceneToNodeOptions v1; // [rsp+20h] [rbp-38h] BYREF

  hkAlignSceneToNodeOptions::hkAlignSceneToNodeOptions(&v1, 0);
  return v1.vfptr;
}

// File Line: 102
// RVA: 0x15D5F60
hkBaseObjectVtbl *dynamic_initializer_for__hkAlignSceneToNodeOptionsTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkAlignSceneToNodeOptions();
  hkAlignSceneToNodeOptionsTypeInfo.m_size = 40i64;
  hkAlignSceneToNodeOptionsTypeInfo.m_typeName = "hkAlignSceneToNodeOptions";
  hkAlignSceneToNodeOptionsTypeInfo.m_vtable = result;
  hkAlignSceneToNodeOptionsTypeInfo.m_scopedName = "!hkAlignSceneToNodeOptions";
  hkAlignSceneToNodeOptionsTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkAlignSceneToNodeOptions;
  hkAlignSceneToNodeOptionsTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkAlignSceneToNodeOptions;
  return result;
}

