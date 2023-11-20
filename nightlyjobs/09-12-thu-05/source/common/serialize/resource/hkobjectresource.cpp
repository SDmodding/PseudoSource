// File Line: 13
// RVA: 0xE65650
bool __fastcall baseOrSameClass_0(const char *typeName, const char *topLevelClassName, hkClassNameRegistry *classReg)
{
  const char *v3; // rdi
  hkClassNameRegistry *v4; // rsi
  hkClass *v5; // rbx
  hkClass *v6; // rax
  hkBool result; // [rsp+40h] [rbp+18h]

  v3 = typeName;
  v4 = classReg;
  v5 = (hkClass *)classReg->vfptr[2].__vecDelDtor((hkBaseObject *)classReg, (unsigned int)topLevelClassName);
  v6 = (hkClass *)v4->vfptr[2].__vecDelDtor((hkBaseObject *)&v4->vfptr, (unsigned int)v3);
  return hkClass::isSuperClass(v6, &result, v5)->m_bool != 0;
}

// File Line: 27
// RVA: 0xE65360
void __fastcall hkObjectResource::hkObjectResource(hkObjectResource *this, hkVariant *v)
{
  hkObjectResource *v2; // rbx
  hkReferencedObject *v3; // rax
  hkClassNameRegistry *v4; // rdi
  hkReferencedObject *v5; // rax
  hkTypeInfoRegistry *v6; // rdi

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectResource::`vftable;
  this->m_topLevelObject = *v;
  v3 = (hkReferencedObject *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  v4 = (hkClassNameRegistry *)v3;
  if ( v3 )
    hkReferencedObject::addReference(v3);
  v2->m_classRegistry.m_pntr = v4;
  v5 = (hkReferencedObject *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)();
  v6 = (hkTypeInfoRegistry *)v5;
  if ( v5 )
  {
    hkReferencedObject::addReference(v5);
    v2->m_typeRegistry.m_pntr = v6;
  }
  else
  {
    v2->m_typeRegistry.m_pntr = 0i64;
  }
}

// File Line: 32
// RVA: 0xE65410
void __fastcall hkObjectResource::~hkObjectResource(hkObjectResource *this)
{
  hkClass *v1; // r8
  hkObjectResource *v2; // rsi
  hkTypeInfoRegistry *v3; // rdi
  hkBaseObjectVtbl *v4; // rbx
  const char *v5; // rax
  unsigned int v6; // eax
  void *v7; // rdi
  unsigned int v8; // ebx
  _QWORD **v9; // rax
  hkReferencedObject *v10; // rcx
  hkReferencedObject *v11; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this->m_topLevelObject.m_class;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkObjectResource::`vftable;
  if ( v1 )
  {
    if ( hkClass::isSuperClass(&hkReferencedObjectClass, &result, v1)->m_bool )
    {
      hkReferencedObject::removeReference((hkReferencedObject *)v2->m_topLevelObject.m_object);
    }
    else
    {
      v3 = v2->m_typeRegistry.m_pntr;
      if ( v3 )
      {
        v4 = v3->vfptr;
        v5 = hkClass::getName(v2->m_topLevelObject.m_class);
        ((void (__fastcall *)(hkTypeInfoRegistry *, void *, const char *))v4[2].__first_virtual_table_function__)(
          v3,
          v2->m_topLevelObject.m_object,
          v5);
      }
      v6 = hkClass::getObjectSize(v2->m_topLevelObject.m_class);
      v7 = v2->m_topLevelObject.m_object;
      v8 = v6;
      v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      (*(void (__fastcall **)(_QWORD *, void *, _QWORD))(*v9[11] + 16i64))(v9[11], v7, v8);
    }
  }
  v10 = (hkReferencedObject *)&v2->m_typeRegistry.m_pntr->vfptr;
  if ( v10 )
    hkReferencedObject::removeReference(v10);
  v2->m_typeRegistry.m_pntr = 0i64;
  v11 = (hkReferencedObject *)&v2->m_classRegistry.m_pntr->vfptr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  v2->m_classRegistry.m_pntr = 0i64;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 51
// RVA: 0xE655D0
void __fastcall hkObjectResource::setClassNameRegistry(hkObjectResource *this, hkClassNameRegistry *classReg)
{
  hkClassNameRegistry *v2; // rbx
  hkObjectResource *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = classReg;
  v3 = this;
  if ( classReg )
    hkReferencedObject::addReference((hkReferencedObject *)&classReg->vfptr);
  v4 = (hkReferencedObject *)&v3->m_classRegistry.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_classRegistry.m_pntr = v2;
}

// File Line: 56
// RVA: 0xE65610
void __fastcall hkObjectResource::setTypeInfoRegistry(hkObjectResource *this, hkTypeInfoRegistry *typeReg)
{
  hkTypeInfoRegistry *v2; // rbx
  hkObjectResource *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = typeReg;
  v3 = this;
  if ( typeReg )
    hkReferencedObject::addReference((hkReferencedObject *)&typeReg->vfptr);
  v4 = (hkReferencedObject *)&v3->m_typeRegistry.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_typeRegistry.m_pntr = v2;
}

// File Line: 61
// RVA: 0xE65400
const char *__fastcall hkObjectResource::getName(hkObjectResource *this)
{
  return 0i64;
}

// File Line: 66
// RVA: 0xE654F0
void __fastcall hkObjectResource::getImportsExports(hkObjectResource *this, hkArray<hkResource::Import,hkContainerHeapAllocator> *impOut, hkArray<hkResource::Export,hkContainerHeapAllocator> *expOut)
{
  ;
}

// File Line: 70
// RVA: 0xE65500
void *__fastcall hkObjectResource::getContentsPointer(hkObjectResource *this, const char *typeName, hkTypeInfoRegistry *typeRegistry)
{
  const char *v3; // rbp
  hkObjectResource *v4; // rsi
  hkClassNameRegistry *v5; // rdi
  const char *v6; // rax
  hkClass *v7; // rbx
  hkClass *v8; // rax
  void *v9; // rax
  hkBool result; // [rsp+38h] [rbp+10h]

  v3 = typeName;
  v4 = this;
  if ( !typeName
    || (v5 = this->m_classRegistry.m_pntr,
        v6 = hkClass::getName(this->m_topLevelObject.m_class),
        v7 = (hkClass *)v5->vfptr[2].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)v6),
        v8 = (hkClass *)v5->vfptr[2].__vecDelDtor((hkBaseObject *)&v5->vfptr, (unsigned int)v3),
        hkClass::isSuperClass(v8, &result, v7)->m_bool) )
  {
    v9 = v4->m_topLevelObject.m_object;
  }
  else
  {
    v9 = 0i64;
  }
  return v9;
}

// File Line: 85
// RVA: 0xE65590
void *__fastcall hkObjectResource::stealContentsPointer(hkObjectResource *this, const char *typeName, hkTypeInfoRegistry *typeRegistry)
{
  hkObjectResource *v3; // rbx
  void *result; // rax

  v3 = this;
  result = (void *)((__int64 (__fastcall *)(hkObjectResource *, const char *, hkTypeInfoRegistry *))this->vfptr[3].__vecDelDtor)(
                     this,
                     typeName,
                     typeRegistry);
  if ( result )
  {
    v3->m_topLevelObject.m_object = 0i64;
    v3->m_topLevelObject.m_class = 0i64;
  }
  return result;
}

// File Line: 96
// RVA: 0xE655C0
const char *__fastcall hkObjectResource::getContentsTypeName(hkObjectResource *this)
{
  return hkClass::getName(this->m_topLevelObject.m_class);
}

