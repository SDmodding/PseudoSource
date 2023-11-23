// File Line: 53
// RVA: 0x15D6A10
void dynamic_initializer_for__hkxEnvironmentVariableClass__()
{
  hkClass::hkClass(
    &hkxEnvironmentVariableClass,
    "hkxEnvironmentVariable",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkxEnvironment_VariableClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xE31EB0
hkClass *__fastcall hkxEnvironment::Variable::staticClass()
{
  return &hkxEnvironmentVariableClass;
}

// File Line: 63
// RVA: 0xE31EC0
void __fastcall finishLoadedObjecthkxEnvironmentVariable(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkStringPtr::hkStringPtr(p, finishing);
    hkStringPtr::hkStringPtr(p + 1, finishing);
  }
}

// File Line: 69
// RVA: 0xE31F00
void __fastcall cleanupLoadedObjecthkxEnvironmentVariable(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 1);
  hkStringPtr::~hkStringPtr(p);
}

// File Line: 107
// RVA: 0x15D6940
void dynamic_initializer_for__hkxEnvironmentClass__()
{
  hkClass::hkClass(
    &hkxEnvironmentClass,
    "hkxEnvironment",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkxEnvironment::Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 110
// RVA: 0xE31EA0
hkClass *__fastcall hkxEnvironment::staticClass()
{
  return &hkxEnvironmentClass;
}

// File Line: 117
// RVA: 0xE31F30
void __fastcall finishLoadedObjecthkxEnvironment(hkxEnvironment *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkxEnvironment::hkxEnvironment(p, finishing);
}

// File Line: 123
// RVA: 0xE31F50
void __fastcall cleanupLoadedObjecthkxEnvironment(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 127
// RVA: 0xE31F60
hkBaseObjectVtbl *__fastcall getVtablehkxEnvironment()
{
  hkxEnvironment v1; // [rsp+20h] [rbp-28h] BYREF

  hkxEnvironment::hkxEnvironment(&v1, 0);
  return v1.vfptr;
}

// File Line: 149
// RVA: 0x15D69B0
hkBaseObjectVtbl *dynamic_initializer_for__hkxEnvironmentTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkxEnvironment();
  hkxEnvironmentTypeInfo.m_size = 32i64;
  hkxEnvironmentTypeInfo.m_typeName = "hkxEnvironment";
  hkxEnvironmentTypeInfo.m_vtable = result;
  hkxEnvironmentTypeInfo.m_scopedName = "!hkxEnvironment";
  hkxEnvironmentTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxEnvironment;
  hkxEnvironmentTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxEnvironment;
  return result;
}

