// File Line: 18
// RVA: 0xE5F8D0
void __fastcall hkDataClass::getAllDeclaredMemberInfo(hkDataClass *this, hkArrayBase<hkDataClass_MemberInfo> *minfos)
{
  hkDataClass *v2; // rsi
  hkArrayBase<hkDataClass_MemberInfo> *v3; // r14
  unsigned int v4; // ebx
  int v5; // ebp
  __int64 v6; // rdi

  v2 = this;
  v3 = minfos;
  v4 = 0;
  v5 = ((__int64 (*)(void))this->m_impl->vfptr[6].__vecDelDtor)();
  if ( v5 > 0 )
  {
    v6 = 0i64;
    do
    {
      ((void (__fastcall *)(hkDataClassImpl *, _QWORD, hkDataClass_MemberInfo *))v2->m_impl->vfptr[7].__vecDelDtor)(
        v2->m_impl,
        v4++,
        &v3->m_data[v6]);
      ++v6;
    }
    while ( (signed int)v4 < v5 );
  }
}

// File Line: 29
// RVA: 0xE5F950
void __fastcall hkDataClass::getCinfo(hkDataClass *this, hkDataClass::Cinfo *cinfo)
{
  hkDataClass *v2; // r15
  hkDataClass::Cinfo *v3; // r14
  __int64 v4; // rax
  __int64 v5; // rax
  int v6; // eax
  int v7; // ecx
  __int64 v8; // rdi
  int v9; // ecx
  int v10; // er9
  unsigned int v11; // ebx
  __int64 v12; // rsi
  __int64 v13; // rdi
  hkDataClassImpl *v14; // rcx
  hkDataClass::Cinfo::Member *v15; // rdx
  const char *v16; // rax
  __int128 v17; // [rsp+30h] [rbp-38h]
  __int128 v18; // [rsp+40h] [rbp-28h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = this;
  v3 = cinfo;
  cinfo->name = (const char *)((__int64 (*)(void))this->m_impl->vfptr[2].__vecDelDtor)();
  v3->version = ((__int64 (*)(void))v2->m_impl->vfptr[3].__vecDelDtor)();
  if ( ((__int64 (*)(void))v2->m_impl->vfptr[4].__vecDelDtor)() )
  {
    v4 = ((__int64 (*)(void))v2->m_impl->vfptr[4].__vecDelDtor)();
    v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
  }
  else
  {
    v5 = 0i64;
  }
  v3->parent = (const char *)v5;
  v6 = ((__int64 (*)(void))v2->m_impl->vfptr[6].__vecDelDtor)();
  v7 = v3->members.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = v6;
  if ( v7 < v6 )
  {
    v9 = 2 * v7;
    v10 = v8;
    if ( (signed int)v8 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->members, v10, 24);
  }
  v3->members.m_size = v8;
  v11 = 0;
  v12 = v8;
  if ( (signed int)v8 > 0 )
  {
    v13 = 0i64;
    do
    {
      v14 = v2->m_impl;
      v17 = 0ui64;
      v18 = 0ui64;
      ((void (__fastcall *)(hkDataClassImpl *, _QWORD, __int128 *))v14->vfptr[7].__vecDelDtor)(v14, v11, &v17);
      v15 = v3->members.m_data;
      v16 = (const char *)v17;
      ++v11;
      v15[v13].type = (hkTypeManager::Type *)v18;
      v15[v13].name = v16;
      ++v13;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 57
// RVA: 0xE5F890
hkTypeManager::Type *__fastcall hkDataObject_Value::getType(hkDataObject_Value *this)
{
  const struct _hkDataObject_MemberHandle *v1; // rdx
  hkDataObjectImpl *v2; // rcx
  __int64 v4; // [rsp+20h] [rbp-28h]
  __int64 v5; // [rsp+28h] [rbp-20h]
  __int128 v6; // [rsp+30h] [rbp-18h]

  v1 = this->m_handle;
  v2 = this->m_impl;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0ui64;
  ((void (__fastcall *)(hkDataObjectImpl *, const struct _hkDataObject_MemberHandle *, __int64 *))v2->vfptr[25].__vecDelDtor)(
    v2,
    v1,
    &v4);
  return (hkTypeManager::Type *)v6;
}

// File Line: 71
// RVA: 0xE5FA80
void __fastcall hkDataWorld::renameClass(hkDataWorld *this, hkDataClass *klass, const char *newName)
{
  ;
}

// File Line: 72
// RVA: 0xE5FA90
void __fastcall hkDataWorld::removeClass(hkDataWorld *this, hkDataClass *klass)
{
  ;
}

// File Line: 74
// RVA: 0xE5FAA0
void __fastcall hkDataWorld::setClassVersion(hkDataWorld *this, hkDataClass *klass, int newVersion)
{
  ;
}

// File Line: 75
// RVA: 0xE5FAB0
void __fastcall hkDataWorld::setClassParent(hkDataWorld *this, hkDataClass *klass, hkDataClass *parent)
{
  ;
}

// File Line: 77
// RVA: 0xE5FAE0
void __fastcall hkDataWorld::renameClassMember(hkDataWorld *this, hkDataClass *klass, const char *oldName, const char *newName)
{
  ;
}

// File Line: 78
// RVA: 0xE5FAF0
void __fastcall hkDataWorld::removeClassMember(hkDataWorld *this, hkDataClass *klass, const char *name)
{
  ;
}

// File Line: 79
// RVA: 0xE5FB00
void __fastcall hkDataWorld::findObjectsByBaseClass(hkDataWorld *this, const char *baseClassName, hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  ;
}

// File Line: 80
// RVA: 0xE5FB10
void __fastcall hkDataWorld::findObjectsByExactClass(hkDataWorld *this, const char *className, hkArray<hkDataObjectImpl *,hkContainerTempAllocator> *objectsOut)
{
  ;
}

// File Line: 81
// RVA: 0xE5FB20
void __fastcall hkDataWorld::castObject(hkDataWorld *this, hkDataObject *obj, hkDataClass *objClass)
{
  ;
}

// File Line: 82
// RVA: 0xE5FAD0
void __fastcall hkDataWorld::setClassMemberDefault(hkDataWorld *this, hkDataClass *klass, const char *name, const void *valuePtr)
{
  ;
}

// File Line: 85
// RVA: 0xE5FB30
hkDataClassImpl *__fastcall hkDataWorld::copyClassFromWorld(hkDataWorld *this, const char *name, hkDataWorld *worldFrom)
{
  return 0i64;
}

// File Line: 90
// RVA: 0xE5FAC0
void __fastcall hkDataWorld::addClassMember(hkDataWorld *this, hkDataClass *klass, const char *name, hkTypeManager::Type *type)
{
  ;
}

// File Line: 95
// RVA: 0xE5FB40
void __fastcall hkDataWorld::addClassMemberTypeExpression(hkDataWorld *this, hkDataClass *klass, const char *name, const char *expr, const char *className, const void *valuePtr)
{
  const char *v6; // rdi
  const char *v7; // r14
  hkDataClass *v8; // r15
  hkDataWorld *v9; // rbx
  hkTypeManager *v10; // rax
  hkTypeManager *v11; // rsi
  hkTypeManager::Type *v12; // rdi
  hkStringBuf v13; // [rsp+30h] [rbp-98h]

  v6 = expr;
  v7 = name;
  v8 = klass;
  v9 = this;
  v10 = (hkTypeManager *)((__int64 (*)(void))this->vfptr[5].__first_virtual_table_function__)();
  v11 = v10;
  if ( className )
  {
    v13.m_string.m_capacityAndFlags = -2147483520;
    v13.m_string.m_size = 1;
    v13.m_string.m_storage[0] = 0;
    v13.m_string.m_data = v13.m_string.m_storage;
    hkStringBuf::append(&v13, v6, -1);
    hkStringBuf::append(&v13, "C", -1);
    hkStringBuf::append(&v13, className, -1);
    hkStringBuf::append(&v13, ";", -1);
    v12 = hkTypeManager::parseTypeExpression(v11, v13.m_string.m_data);
    v13.m_string.m_size = 0;
    if ( v13.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v13.m_string.m_data,
        v13.m_string.m_capacityAndFlags & 0x3FFFFFFF);
    v13.m_string.m_data = 0i64;
    v13.m_string.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v12 = hkTypeManager::parseTypeExpression(v10, v6);
  }
  if ( v12 )
    ((void (__fastcall *)(hkDataWorld *, hkDataClass *, const char *, hkTypeManager::Type *, const void *))v9->vfptr[8].__vecDelDtor)(
      v9,
      v8,
      v7,
      v12,
      valuePtr);
}

