// File Line: 16
// RVA: 0xE74E10
hkReferencedObject *__fastcall hkResource::getContents<hkReferencedObject>(hkResource *this)
{
  hkResource *v1; // rsi
  __int64 v2; // rax
  hkBaseObjectVtbl *v3; // rdi
  __int64 v4; // rbx
  hkClass *v5; // rax
  const char *v6; // rax

  v1 = this;
  v2 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)();
  v3 = v1->vfptr;
  v4 = v2;
  v5 = hkReferencedObject::staticClass();
  v6 = hkClass::getName(v5);
  return (hkReferencedObject *)((__int64 (__fastcall *)(hkResource *, const char *, __int64))v3[3].__vecDelDtor)(
                                 v1,
                                 v6,
                                 v4);
}

