// File Line: 67
// RVA: 0x15D8770
void dynamic_initializer_for__hkResourceBaseClass__()
{
  hkClass::hkClass(
    &hkResourceBaseClass,
    "hkResourceBase",
    &hkReferencedObjectClass,
    16,
    0i64,
    0,
    &hkResourceBaseEnums,
    1,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 70
// RVA: 0xE38FD0
hkClass *__fastcall hkResourceBase::staticClass()
{
  return &hkResourceBaseClass;
}

// File Line: 94
// RVA: 0x15D8830
void dynamic_initializer_for__hkResourceHandleClass__()
{
  hkClass::hkClass(
    &hkResourceHandleClass,
    "hkResourceHandle",
    &hkResourceBaseClass,
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

// File Line: 97
// RVA: 0xE38FE0
hkClass *__fastcall hkResourceHandle::staticClass()
{
  return &hkResourceHandleClass;
}

// File Line: 121
// RVA: 0x15D87D0
void dynamic_initializer_for__hkResourceContainerClass__()
{
  hkClass::hkClass(
    &hkResourceContainerClass,
    "hkResourceContainer",
    &hkResourceBaseClass,
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

// File Line: 124
// RVA: 0xE38FF0
hkClass *__fastcall hkResourceContainer::staticClass()
{
  return &hkResourceContainerClass;
}

// File Line: 151
// RVA: 0x15D86A0
void dynamic_initializer_for__hkMemoryResourceHandleExternalLinkClass__()
{
  hkClass::hkClass(
    &hkMemoryResourceHandleExternalLinkClass,
    "hkMemoryResourceHandleExternalLink",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkMemoryResourceHandle_ExternalLinkClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 154
// RVA: 0xE39010
hkClass *__fastcall hkMemoryResourceHandle::ExternalLink::staticClass()
{
  return &hkMemoryResourceHandleExternalLinkClass;
}

// File Line: 161
// RVA: 0xE39030
void __fastcall finishLoadedObjecthkMemoryResourceHandleExternalLink(void *p, int finishing)
{
  int v2; // edi
  hkStringPtr *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (hkStringPtr *)p;
    hkStringPtr::hkStringPtr((hkStringPtr *)p, (hkFinishLoadedObjectFlag)finishing);
    hkStringPtr::hkStringPtr(v3 + 1, (hkFinishLoadedObjectFlag)v2);
  }
}

// File Line: 167
// RVA: 0xE39070
void __fastcall cleanupLoadedObjecthkMemoryResourceHandleExternalLink(void *p)
{
  hkStringPtr *v1; // rbx

  v1 = (hkStringPtr *)p;
  hkStringPtr::~hkStringPtr((hkStringPtr *)p + 1);
  hkStringPtr::~hkStringPtr(v1);
}

// File Line: 205
// RVA: 0x15D8630
void dynamic_initializer_for__hkMemoryResourceHandleClass__()
{
  hkClass::hkClass(
    &hkMemoryResourceHandleClass,
    "hkMemoryResourceHandle",
    &hkResourceHandleClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkMemoryResourceHandle::Members,
    3,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 208
// RVA: 0xE39000
hkClass *__fastcall hkMemoryResourceHandle::staticClass()
{
  return &hkMemoryResourceHandleClass;
}

// File Line: 215
// RVA: 0xE390A0
void __fastcall finishLoadedObjecthkMemoryResourceHandle(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkMemoryResourceHandle::hkMemoryResourceHandle);
}

// File Line: 221
// RVA: 0xE390C0
void __fastcall cleanupLoadedObjecthkMemoryResourceHandle(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 225
// RVA: 0xE390D0
hkBaseObjectVtbl *__fastcall getVtablehkMemoryResourceHandle()
{
  hkMemoryResourceHandle v1; // [rsp+20h] [rbp-38h]

  hkMemoryResourceHandle::hkMemoryResourceHandle(&v1, 0);
  return v1.vfptr;
}

// File Line: 247
// RVA: 0x15D8710
hkBaseObjectVtbl *dynamic_initializer_for__hkMemoryResourceHandleTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkMemoryResourceHandle();
  hkMemoryResourceHandleTypeInfo.m_size = 48i64;
  hkMemoryResourceHandleTypeInfo.m_typeName = "hkMemoryResourceHandle";
  hkMemoryResourceHandleTypeInfo.m_vtable = result;
  hkMemoryResourceHandleTypeInfo.m_scopedName = "!hkMemoryResourceHandle";
  hkMemoryResourceHandleTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkMemoryResourceHandle;
  hkMemoryResourceHandleTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkMemoryResourceHandle;
  return result;
}

// File Line: 275
// RVA: 0x15D8560
void dynamic_initializer_for__hkMemoryResourceContainerClass__()
{
  hkClass::hkClass(
    &hkMemoryResourceContainerClass,
    "hkMemoryResourceContainer",
    &hkResourceContainerClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkMemoryResourceContainer::Members,
    4,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 278
// RVA: 0xE39020
hkClass *__fastcall hkMemoryResourceContainer::staticClass()
{
  return &hkMemoryResourceContainerClass;
}

// File Line: 285
// RVA: 0xE390F0
void __fastcall finishLoadedObjecthkMemoryResourceContainer(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkMemoryResourceContainer::hkMemoryResourceContainer);
}

// File Line: 291
// RVA: 0xE39110
void __fastcall cleanupLoadedObjecthkMemoryResourceContainer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 295
// RVA: 0xE39120
hkBaseObjectVtbl *__fastcall getVtablehkMemoryResourceContainer()
{
  hkMemoryResourceContainer v1; // [rsp+20h] [rbp-48h]

  hkMemoryResourceContainer::hkMemoryResourceContainer(&v1, 0);
  return v1.vfptr;
}

// File Line: 317
// RVA: 0x15D85D0
hkBaseObjectVtbl *dynamic_initializer_for__hkMemoryResourceContainerTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkMemoryResourceContainer();
  hkMemoryResourceContainerTypeInfo.m_size = 64i64;
  hkMemoryResourceContainerTypeInfo.m_typeName = "hkMemoryResourceContainer";
  hkMemoryResourceContainerTypeInfo.m_vtable = result;
  hkMemoryResourceContainerTypeInfo.m_scopedName = "!hkMemoryResourceContainer";
  hkMemoryResourceContainerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkMemoryResourceContainer;
  hkMemoryResourceContainerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkMemoryResourceContainer;
  return result;
}

