// File Line: 13
// RVA: 0xE65650
bool __fastcall baseOrSameClass_0(const char *typeName, const char *topLevelClassName, hkClassNameRegistry *classReg)
{
  hkClass *v5; // rbx
  hkClass *v6; // rax
  hkBool result; // [rsp+40h] [rbp+18h] BYREF

  v5 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, topLevelClassName);
  v6 = (hkClass *)classReg->vfptr[2].__vecDelDtor(classReg, typeName);
  return hkClass::isSuperClass(v6, &result, v5)->m_bool != 0;
}

// File Line: 27
// RVA: 0xE65360
void __fastcall hkObjectResource::hkObjectResource(hkObjectResource *this, hkVariant *v)
{
  hkReferencedObject *v3; // rax
  hkClassNameRegistry *v4; // rdi
  hkReferencedObject *v5; // rax
  hkTypeInfoRegistry *v6; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectResource::`vftable;
  this->m_topLevelObject = *v;
  v3 = (hkReferencedObject *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v4 = (hkClassNameRegistry *)v3;
  if ( v3 )
    hkReferencedObject::addReference(v3);
  this->m_classRegistry.m_pntr = v4;
  v5 = (hkReferencedObject *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v6 = (hkTypeInfoRegistry *)v5;
  if ( v5 )
  {
    hkReferencedObject::addReference(v5);
    this->m_typeRegistry.m_pntr = v6;
  }
  else
  {
    this->m_typeRegistry.m_pntr = 0i64;
  }
}

// File Line: 32
// RVA: 0xE65410
void __fastcall hkObjectResource::~hkObjectResource(hkObjectResource *this)
{
  hkClass *m_class; // r8
  hkTypeInfoRegistry *m_pntr; // rdi
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  unsigned int ObjectSize; // eax
  void *m_object; // rdi
  unsigned int v8; // ebx
  _QWORD **Value; // rax
  hkTypeInfoRegistry *v10; // rcx
  hkClassNameRegistry *v11; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  m_class = this->m_topLevelObject.m_class;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectResource::`vftable;
  if ( m_class )
  {
    if ( hkClass::isSuperClass(&hkReferencedObjectClass, &result, m_class)->m_bool )
    {
      hkReferencedObject::removeReference((hkReferencedObject *)this->m_topLevelObject.m_object);
    }
    else
    {
      m_pntr = this->m_typeRegistry.m_pntr;
      if ( m_pntr )
      {
        vfptr = m_pntr->vfptr;
        Name = hkClass::getName(this->m_topLevelObject.m_class);
        ((void (__fastcall *)(hkTypeInfoRegistry *, void *, const char *))vfptr[2].__first_virtual_table_function__)(
          m_pntr,
          this->m_topLevelObject.m_object,
          Name);
      }
      ObjectSize = hkClass::getObjectSize(this->m_topLevelObject.m_class);
      m_object = this->m_topLevelObject.m_object;
      v8 = ObjectSize;
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*Value[11] + 16i64))(Value[11], m_object, v8);
    }
  }
  v10 = this->m_typeRegistry.m_pntr;
  if ( v10 )
    hkReferencedObject::removeReference(v10);
  this->m_typeRegistry.m_pntr = 0i64;
  v11 = this->m_classRegistry.m_pntr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  this->m_classRegistry.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 51
// RVA: 0xE655D0
void __fastcall hkObjectResource::setClassNameRegistry(hkObjectResource *this, hkClassNameRegistry *classReg)
{
  hkClassNameRegistry *m_pntr; // rcx

  if ( classReg )
    hkReferencedObject::addReference(classReg);
  m_pntr = this->m_classRegistry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_classRegistry.m_pntr = classReg;
}

// File Line: 56
// RVA: 0xE65610
void __fastcall hkObjectResource::setTypeInfoRegistry(hkObjectResource *this, hkTypeInfoRegistry *typeReg)
{
  hkTypeInfoRegistry *m_pntr; // rcx

  if ( typeReg )
    hkReferencedObject::addReference(typeReg);
  m_pntr = this->m_typeRegistry.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_typeRegistry.m_pntr = typeReg;
}

// File Line: 61
// RVA: 0xE65400
const char *__fastcall hkObjectResource::getName(hkObjectResource *this)
{
  return 0i64;
}

// File Line: 66
// RVA: 0xE654F0
void __fastcall hkObjectResource::getImportsExports(
        hkObjectResource *this,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  ;
}

// File Line: 70
// RVA: 0xE65500
void *__fastcall hkObjectResource::getContentsPointer(
        hkObjectResource *this,
        const char *typeName,
        hkTypeInfoRegistry *typeRegistry)
{
  hkClassNameRegistry *m_pntr; // rdi
  const char *Name; // rax
  hkClass *v7; // rbx
  hkClass *v8; // rax
  hkBool result; // [rsp+38h] [rbp+10h] BYREF

  if ( !typeName )
    return this->m_topLevelObject.m_object;
  m_pntr = this->m_classRegistry.m_pntr;
  Name = hkClass::getName(this->m_topLevelObject.m_class);
  v7 = (hkClass *)m_pntr->vfptr[2].__vecDelDtor(m_pntr, (unsigned int)Name);
  v8 = (hkClass *)m_pntr->vfptr[2].__vecDelDtor(m_pntr, (unsigned int)typeName);
  if ( hkClass::isSuperClass(v8, &result, v7)->m_bool )
    return this->m_topLevelObject.m_object;
  else
    return 0i64;
}

// File Line: 85
// RVA: 0xE65590
void *__fastcall hkObjectResource::stealContentsPointer(
        hkObjectResource *this,
        const char *typeName,
        hkTypeInfoRegistry *typeRegistry)
{
  void *result; // rax

  result = (void *)((__int64 (__fastcall *)(hkObjectResource *, const char *, hkTypeInfoRegistry *))this->vfptr[3].__vecDelDtor)(
                     this,
                     typeName,
                     typeRegistry);
  if ( result )
  {
    this->m_topLevelObject.m_object = 0i64;
    this->m_topLevelObject.m_class = 0i64;
  }
  return result;
}

// File Line: 96
// RVA: 0xE655C0
const char *__fastcall hkObjectResource::getContentsTypeName(hkObjectResource *this)
{
  return hkClass::getName(this->m_topLevelObject.m_class);
}

