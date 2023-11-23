// File Line: 16
// RVA: 0xE74E10
hkReferencedObject *__fastcall hkResource::getContents<hkReferencedObject>(hkResource *this)
{
  __int64 v2; // rax
  hkBaseObjectVtbl *vfptr; // rdi
  __int64 v4; // rbx
  hkClass *v5; // rax
  const char *Name; // rax

  v2 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  vfptr = this->vfptr;
  v4 = v2;
  v5 = hkReferencedObject::staticClass();
  Name = hkClass::getName(v5);
  return (hkReferencedObject *)((__int64 (__fastcall *)(hkResource *, const char *, __int64))vfptr[3].__vecDelDtor)(
                                 this,
                                 Name,
                                 v4);
}

