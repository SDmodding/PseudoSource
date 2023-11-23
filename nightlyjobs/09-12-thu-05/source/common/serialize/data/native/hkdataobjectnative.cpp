// File Line: 43
// RVA: 0xE48F60
hkMemoryResourceContainer *__fastcall Scaleform::SysAllocPagedMalloc::GetUsedSpace(hkMemoryResourceContainer *this)
{
  return this->m_parent;
}

// File Line: 48
// RVA: 0xE48E80
const char *__fastcall hkDataClassNative::getName(hkDataClassNative *this)
{
  return hkClass::getName(this->m_class);
}

// File Line: 52
// RVA: 0xE48F50
__int64 __fastcall hkDataClassNative::getVersion(hkDataClassNative *this)
{
  return hkClass::getDescribedVersion(this->m_class);
}

// File Line: 56
// RVA: 0xE48EB0
hkClass *__fastcall hkDataClassNative::getParent(hkDataClassNative *this)
{
  hkClass *result; // rax
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax

  result = hkClass::getParent(this->m_class);
  if ( result )
  {
    vfptr = this->m_world->vfptr;
    Name = hkClass::getName(result);
    return (hkClass *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))vfptr[4].__first_virtual_table_function__)(
                        this->m_world,
                        Name);
  }
  return result;
}

// File Line: 61
// RVA: 0xE48FF0
hkBool *__fastcall hkDataClassNative::isSuperClass(hkDataClassNative *this, hkBool *result, hkDataClassImpl *k)
{
  hkDataClassImpl *v3; // rbx
  const char *v6; // rdi
  const char *v7; // rax

  v3 = k;
  if ( k )
  {
    while ( 1 )
    {
      v6 = (const char *)((__int64 (__fastcall *)(hkDataClassNative *))this->vfptr[2].__vecDelDtor)(this);
      v7 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[2].__vecDelDtor)(v3);
      if ( !(unsigned int)hkString::strCmp(v7, v6) )
        break;
      v3 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[4].__vecDelDtor)(v3);
      if ( !v3 )
        goto LABEL_4;
    }
    result->m_bool = 1;
  }
  else
  {
LABEL_4:
    result->m_bool = 0;
  }
  return result;
}

// File Line: 76
// RVA: 0xE48E90
__int64 __fastcall hkDataClassNative::getNumDeclaredMembers(hkDataClassNative *this)
{
  return hkClass::getNumDeclaredMembers(this->m_class);
}

// File Line: 80
// RVA: 0xE48CE0
__int64 __fastcall hkDataClassNative::getDeclaredMemberIndexByName(hkDataClassNative *this, const char *name)
{
  return hkClass::getDeclaredMemberIndexByName(this->m_class, name);
}

// File Line: 86
// RVA: 0xE48EA0
__int64 __fastcall hkDataClassNative::getNumMembers(hkDataClassNative *this)
{
  return hkClass::getNumMembers(this->m_class);
}

// File Line: 90
// RVA: 0xE48D90
__int64 __fastcall hkDataClassNative::getMemberIndexByName(hkDataClassNative *this, const char *name)
{
  return hkClass::getMemberIndexByName(this->m_class, name);
}

// File Line: 94
// RVA: 0xE47DB0
void __fastcall hkDataClassNative::_fillMemberInfo(
        hkDataClassImpl *clsIn,
        hkDataWorldNative *world,
        hkClassMember *mem,
        hkDataClass_MemberInfo *info)
{
  __int64 v8; // rax
  const char *m_name; // r10
  hkTypeManager::Type *v10; // rax
  hkClass *Class; // rbp
  hkVariant *Attribute; // rax
  hkClassNameRegistry *m_pntr; // rbx
  hkBaseObjectVtbl *vfptr; // rdi
  char **v15; // rax
  hkClass *v16; // rax
  const char *Name; // rax
  unsigned int m_storage; // ebx
  unsigned int v19; // edi
  hkBaseObjectVtbl *v20; // rsi
  int CstyleArraySize; // eax
  hkClassMemberAccessor v22; // [rsp+30h] [rbp-28h] BYREF

  v8 = ((__int64 (__fastcall *)(hkDataWorldNative *))world->vfptr[5].__first_virtual_table_function__)(world);
  m_name = mem->m_name;
  info->m_owner = clsIn;
  info->m_name = m_name;
  if ( (mem->m_flags.m_storage & 0x400) == 0 || world->m_accessSerializeIgnored.m_bool )
  {
    Class = hkClassMember::getClass(mem);
    if ( Class )
    {
      Attribute = hkClassMember::getAttribute(mem, s_hkDataObjectTupeAttributeID);
      if ( Attribute )
      {
        hkClassMemberAccessor::hkClassMemberAccessor(&v22, Attribute, "typeName");
        m_pntr = world->m_reg.m_pntr;
        vfptr = m_pntr->vfptr;
        v15 = hkClassMemberAccessor::asCstring(&v22, 0);
        v16 = (hkClass *)vfptr[2].__vecDelDtor(m_pntr, (unsigned int)*v15);
LABEL_9:
        Class = v16;
        goto LABEL_10;
      }
      Name = hkClass::getName(Class);
      if ( !(unsigned int)hkString::strCmp(Name, "hkpMaxSizeMotion") )
      {
        v16 = (hkClass *)world->m_reg.m_pntr->vfptr[2].__vecDelDtor(world->m_reg.m_pntr, "hkpMotion");
        goto LABEL_9;
      }
    }
LABEL_10:
    m_storage = (unsigned __int8)mem->m_subtype.m_storage;
    v19 = (unsigned __int8)mem->m_type.m_storage;
    v20 = world->vfptr;
    CstyleArraySize = hkClassMember::getCstyleArraySize(mem);
    v10 = (hkTypeManager::Type *)((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, hkClass *, int))v20[12].__vecDelDtor)(
                                   world,
                                   v19,
                                   m_storage,
                                   Class,
                                   CstyleArraySize);
    goto LABEL_11;
  }
  v10 = *(hkTypeManager::Type **)(v8 + 32);
LABEL_11:
  info->m_type = v10;
}

// File Line: 136
// RVA: 0xE48CF0
void __fastcall hkDataClassNative::getDeclaredMemberInfo(hkDataClassNative *this, int i, hkDataClass_MemberInfo *info)
{
  hkClassMember *DeclaredMember; // rax

  DeclaredMember = hkClass::getDeclaredMember(this->m_class, i);
  hkDataClassNative::_fillMemberInfo(this, this->m_world, DeclaredMember, info);
  info->m_valuePtr = hkClass::getDeclaredDefault(this->m_class, i);
}

// File Line: 141
// RVA: 0xE48DA0
void __fastcall hkDataClassNative::getMemberInfo(hkDataClassNative *this, int i, hkDataClass_MemberInfo *info)
{
  hkClassMember *Member; // rax

  Member = hkClass::getMember(this->m_class, i);
  hkDataClassNative::_fillMemberInfo(this, this->m_world, Member, info);
  info->m_valuePtr = hkClass::getDefault(this->m_class, i);
}

// File Line: 146
// RVA: 0xE48B80
void __fastcall hkDataClassNative::getAllMemberInfo(
        hkDataClassNative *this,
        hkArrayBase<hkDataClass_MemberInfo> *infos)
{
  hkClass *m_class; // rbx
  hkDataClass_MemberInfo *i; // r14
  int v5; // edi
  int NumDeclaredMembers; // ebp
  hkDataClass_MemberInfo *v7; // rsi
  hkClassMember *DeclaredMember; // rax
  const char *DeclaredDefault; // rax

  m_class = this->m_class;
  for ( i = &infos->m_data[infos->m_size]; m_class; m_class = hkClass::getParent(m_class) )
  {
    v5 = 0;
    NumDeclaredMembers = hkClass::getNumDeclaredMembers(m_class);
    i -= NumDeclaredMembers;
    if ( NumDeclaredMembers > 0 )
    {
      v7 = i;
      do
      {
        DeclaredMember = hkClass::getDeclaredMember(m_class, v5);
        hkDataClassNative::_fillMemberInfo(this, this->m_world, DeclaredMember, v7);
        DeclaredDefault = hkClass::getDeclaredDefault(m_class, v5++);
        ++v7;
        v7[-1].m_valuePtr = DeclaredDefault;
      }
      while ( v5 < NumDeclaredMembers );
    }
  }
}

// File Line: 169
// RVA: 0xE47EE0
void __fastcall hkDataClassNative::_getAllMemberHandles(
        hkDataClassNative *this,
        hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  hkClass *m_class; // rsi
  const struct _hkDataObject_MemberHandle **i; // r14
  int v4; // ebx
  int NumDeclaredMembers; // ebp
  const struct _hkDataObject_MemberHandle **v6; // rdi
  hkClassMember *Member; // rax

  m_class = this->m_class;
  for ( i = &handles->m_data[handles->m_size]; m_class; m_class = hkClass::getParent(m_class) )
  {
    v4 = 0;
    NumDeclaredMembers = hkClass::getNumDeclaredMembers(m_class);
    i -= NumDeclaredMembers;
    if ( NumDeclaredMembers > 0 )
    {
      v6 = i;
      do
      {
        Member = hkClass::getMember(m_class, v4++);
        *v6++ = (const struct _hkDataObject_MemberHandle *)Member;
      }
      while ( v4 < NumDeclaredMembers );
    }
  }
}

// File Line: 222
// RVA: 0xE48B40
void __fastcall hkDataArrayNative::clear(hkDataArrayNative *this)
{
  hkVariantDataUtil::clearArray(this->m_world->m_infoReg.m_pntr, this->m_arrayObject, this->m_nativeType, this->m_class);
}

// File Line: 227
// RVA: 0xE49090
void __fastcall hkDataArrayNative::reserve(hkDataArrayNative *this, int n)
{
  this->m_address = hkVariantDataUtil::reserveArray(
                      (const void **)this->m_arrayObject,
                      this->m_nativeType,
                      this->m_class,
                      n);
}

// File Line: 232
// RVA: 0xE495E0
void __fastcall hkDataArrayNative::setSize(hkDataArrayNative *this, int n)
{
  if ( n != ((unsigned int (__fastcall *)(hkDataArrayNative *))this->vfptr[5].__vecDelDtor)(this) )
    this->m_address = hkVariantDataUtil::setArraySize(
                        this->m_world->m_infoReg.m_pntr,
                        (const void **)this->m_arrayObject,
                        this->m_nativeType,
                        this->m_class,
                        n);
}

// File Line: 240
// RVA: 0xE48F00
__int64 __fastcall hkDataArrayNative::getSize(hkDataArrayNative *this)
{
  if ( this->m_arrayObject )
    return hkVariantDataUtil::getArraySize((unsigned int *)this->m_arrayObject);
  else
    return (unsigned int)this->m_arraySize;
}

// File Line: 251
// RVA: 0xE48F30
__int64 __fastcall hkDataArrayNative::getUnderlyingIntegerSize(hkDataArrayNative *this)
{
  __int64 result; // rax

  result = 8i64;
  if ( (unsigned int)(this->m_nativeType - 9) > 1 )
    return 4i64;
  return result;
}

// File Line: 263
// RVA: 0xE48C40
hkDataClassImpl *__fastcall hkDataArrayNative::getClass(hkDataArrayNative *this)
{
  hkClass *m_class; // rcx
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax

  m_class = this->m_class;
  if ( !m_class )
    return 0i64;
  vfptr = this->m_world->vfptr;
  Name = hkClass::getName(m_class);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))vfptr[4].__first_virtual_table_function__)(
                              this->m_world,
                              Name);
}

// File Line: 267
// RVA: 0xE487A0
const float *__fastcall hkDataArrayNative::asVec(hkDataArrayNative *this, int index)
{
  return hkVariantDataUtil::getReals(
           this->m_nativeType,
           this->m_tupleCount,
           (char *)this->m_address + index * this->m_elementStride,
           &this->m_world->m_buffer);
}

// File Line: 271
// RVA: 0xE48740
const char *__fastcall hkDataArrayNative::asString(hkDataArrayNative *this, int index)
{
  return hkVariantDataUtil::getString(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride);
}

// File Line: 275
// RVA: 0xE48600
double __fastcall hkDataArrayNative::asReal(hkDataArrayNative *this, int index)
{
  double result; // xmm0_8

  *(float *)&result = hkVariantDataUtil::getReal(
                        this->m_nativeType,
                        (__int16 *)((char *)this->m_address + index * this->m_elementStride));
  return result;
}

// File Line: 283
// RVA: 0xE48450
__int64 __fastcall hkDataArrayNative::asInt64(hkDataArrayNative *this, int index)
{
  return hkVariantDataUtil::getInt(
           this->m_nativeType,
           this->m_nativeSubType,
           (__int64 *)((char *)this->m_address + index * this->m_elementStride));
}

// File Line: 287
// RVA: 0xE484C0
hkClassAccessor *__fastcall hkDataArrayNative::asObject(hkDataArrayNative *this, int index)
{
  hkVariant *Object; // rax
  hkClass *m_class; // rdx
  hkVariant v; // [rsp+30h] [rbp-28h] BYREF
  hkVariant result; // [rsp+40h] [rbp-18h] BYREF

  Object = hkVariantDataUtil::getObject(
             &result,
             this->m_nativeType,
             this->m_class,
             this->m_world->m_vtable.m_pntr,
             this->m_world->m_reg.m_pntr,
             (const void **)((char *)this->m_address + index * this->m_elementStride));
  v.m_object = Object->m_object;
  m_class = Object->m_class;
  v.m_class = m_class;
  if ( v.m_object && m_class )
    return hkNativeDataObjectImplCreate(&v, this->m_world, 0);
  else
    return 0i64;
}

// File Line: 293
// RVA: 0xE47FF0
hkDataArrayImpl *__fastcall hkDataArrayNative::asArray(hkDataArrayNative *this, int index)
{
  char *v3; // rsi
  hkClassMember::Type m_nativeType; // ecx
  int ObjectSize; // ebp
  _QWORD **Value; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  hkDataWorldNative *m_world; // rcx
  hkClass *m_class; // r9
  hkClassMember::Type m_nativeSubType; // r8d
  hkClassMember::Type v12; // edx
  int m_tupleCount; // r10d
  int v15; // ebp
  _QWORD **v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdi
  __int64 v19; // r8
  hkDataWorldNative *v20; // rcx
  hkClass *v21; // r9
  __int64 v22; // rdx
  int v23; // r10d

  v3 = (char *)this->m_address + index * this->m_elementStride;
  if ( this->m_tupleCount )
  {
    m_nativeType = this->m_nativeType;
    if ( m_nativeType == 25 )
      ObjectSize = hkClass::getObjectSize(this->m_class);
    else
      ObjectSize = hkClassMember::getClassMemberTypeProperties(m_nativeType)->m_size;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
    v8 = v7;
    if ( v7 )
    {
      m_world = this->m_world;
      m_class = this->m_class;
      m_nativeSubType = this->m_nativeSubType;
      v12 = this->m_nativeType;
      m_tupleCount = this->m_tupleCount;
      *(_QWORD *)(v7 + 8) = 0xFFFFi64;
      *(_QWORD *)(v7 + 16) = m_world;
      *(_QWORD *)(v7 + 24) = v3;
      *(_DWORD *)(v7 + 32) = m_tupleCount;
      *(_DWORD *)(v7 + 36) = ObjectSize;
      *(_DWORD *)(v7 + 40) = v12;
      *(_QWORD *)v7 = &hkDataArrayNative::`vftable;
      *(_DWORD *)(v7 + 44) = m_nativeSubType;
      *(_QWORD *)(v7 + 48) = m_class;
      *(_DWORD *)(v7 + 64) = 0;
      *(_QWORD *)(v7 + 72) = 0i64;
      *(_QWORD *)(v7 + 56) = ((__int64 (__fastcall *)(hkDataWorldNative *))m_world->vfptr[12].__vecDelDtor)(m_world);
      return (hkDataArrayImpl *)v8;
    }
    return 0i64;
  }
  if ( this->m_nativeType != (TYPE_USER_CONTACT_MGR|TYPE_CONVEX_LIST_CONTACT_MGR|0x10) )
    return 0i64;
  v15 = hkVariantDataUtil::calcElementSize(this->m_nativeSubType, TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR, this->m_class, 0);
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 80i64);
  v18 = v17;
  if ( !v17 )
    return 0i64;
  v19 = *(_QWORD *)v3;
  v20 = this->m_world;
  v21 = this->m_class;
  v22 = (unsigned int)this->m_nativeSubType;
  v23 = *((_DWORD *)v3 + 2);
  *(_QWORD *)(v17 + 8) = 0xFFFFi64;
  *(_QWORD *)(v17 + 24) = v19;
  *(_QWORD *)(v17 + 16) = v20;
  *(_DWORD *)(v17 + 32) = v23;
  *(_DWORD *)(v17 + 36) = v15;
  *(_DWORD *)(v17 + 40) = v22;
  *(_QWORD *)v17 = &hkDataArrayNative::`vftable;
  *(_DWORD *)(v17 + 44) = 0;
  *(_QWORD *)(v17 + 48) = v21;
  *(_DWORD *)(v17 + 64) = 0;
  *(_QWORD *)(v17 + 72) = 0i64;
  *(_QWORD *)(v17 + 56) = ((__int64 (__fastcall *)(hkDataWorldNative *, __int64, _QWORD))v20->vfptr[12].__vecDelDtor)(
                            v20,
                            v22,
                            0i64);
  return (hkDataArrayImpl *)v18;
}

// File Line: 319
// RVA: 0xE49680
hkDataArrayImpl *__fastcall hkDataArrayNative::swizzleObjectMember(hkDataArrayNative *this, const char *name)
{
  hkClassMember *MemberByName; // rax
  unsigned int m_storage; // r12d
  hkClassMember *v5; // r14
  char *v6; // r15
  _QWORD **Value; // rax
  hkDataArrayImpl *result; // rax
  hkDataArrayImpl *v9; // rsi
  unsigned int v10; // edi
  int CstyleArraySize; // ebx
  hkClass *Class; // rax
  hkDataWorldNative *m_world; // rcx
  int m_elementStride; // r10d

  MemberByName = hkClass::getMemberByName(this->m_class, name);
  m_storage = (unsigned __int8)MemberByName->m_type.m_storage;
  v5 = MemberByName;
  v6 = (char *)this->m_address + MemberByName->m_offset;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
  v9 = result;
  if ( result )
  {
    v10 = (unsigned __int8)v5->m_subtype.m_storage;
    CstyleArraySize = hkClassMember::getCstyleArraySize(v5);
    Class = hkClassMember::getClass(v5);
    m_world = this->m_world;
    m_elementStride = this->m_elementStride;
    LODWORD(v9[2].vfptr) = this->m_arraySize;
    v9->vfptr = (hkDataRefCountedVtbl *)&hkDataArrayNative::`vftable;
    *(_QWORD *)&v9->m_memSize = 0xFFFFi64;
    v9[1].vfptr = (hkDataRefCountedVtbl *)m_world;
    *(_QWORD *)&v9[4].m_memSize = 0i64;
    *(_QWORD *)&v9[1].m_memSize = v6;
    HIDWORD(v9[2].vfptr) = m_elementStride;
    *(_DWORD *)&v9[2].m_memSize = m_storage;
    v9[2].m_count = v10;
    v9[3].vfptr = (hkDataRefCountedVtbl *)Class;
    LODWORD(v9[4].vfptr) = CstyleArraySize;
    *(_QWORD *)&v9[3].m_memSize = ((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, hkClass *, int))m_world->vfptr[12].__vecDelDtor)(
                                    m_world,
                                    m_storage,
                                    v10,
                                    Class,
                                    CstyleArraySize);
    return v9;
  }
  return result;
}

// File Line: 329
// RVA: 0xE48660
hkResult *__fastcall hkDataArrayNative::asStridedBasicArray(
        hkDataArrayNative *this,
        hkResult *result,
        hkStridedBasicArray *arrOut)
{
  hkClassMember::Type m_nativeSubType; // eax
  int v7; // eax

  arrOut->m_tupleSize = 1;
  arrOut->m_type = this->m_nativeType;
  switch ( this->m_nativeType )
  {
    case 0xC:
    case 0xD:
      arrOut->m_tupleSize = 4;
      goto LABEL_6;
    case 0xE:
    case 0xF:
    case 0x10:
      arrOut->m_tupleSize = 12;
      goto LABEL_6;
    case 0x11:
    case 0x12:
      arrOut->m_tupleSize = 16;
LABEL_6:
      arrOut->m_type = TYPE_NULL_CONTACT_MGR|0x8;
      break;
    case 0x18:
    case 0x1F:
      m_nativeSubType = this->m_nativeSubType;
      arrOut->m_tupleSize = 1;
      arrOut->m_type = m_nativeSubType;
      break;
    default:
      break;
  }
  v7 = ((__int64 (__fastcall *)(hkDataArrayNative *))this->vfptr[5].__vecDelDtor)(this);
  result->m_enum = HK_SUCCESS;
  arrOut->m_size = v7;
  arrOut->m_stride = this->m_elementStride;
  arrOut->m_data = this->m_address;
  return result;
}

// File Line: 397
// RVA: 0xE493E0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, hkBool *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == TYPE_REPORT_CONTACT_MGR )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_REPORT_CONTACT_MGR);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 398
// RVA: 0xE49120
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == TYPE_CONVEX_LIST_CONTACT_MGR )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 399
// RVA: 0xE490C0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == TYPE_NULL_CONTACT_MGR )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_NULL_CONTACT_MGR);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 400
// RVA: 0xE49180
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, unsigned int n)
{
  hkClassMember::Type m_nativeType; // eax
  hkClassMember::Type v7; // ebx
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  m_nativeType = this->m_nativeType;
  v7 = TYPE_USER_CONTACT_MGR;
  if ( m_nativeType == TYPE_REPORT_CONTACT_MGR )
  {
    v7 = TYPE_REPORT_CONTACT_MGR;
  }
  else if ( m_nativeType == TYPE_CONVEX_LIST_CONTACT_MGR )
  {
    v7 = TYPE_CONVEX_LIST_CONTACT_MGR;
  }
  if ( v7 == m_nativeType )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(v7);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 401
// RVA: 0xE49200
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const __int16 *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == TYPE_MAX )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_MAX);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 402
// RVA: 0xE49260
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned __int16 *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == (TYPE_USER_CONTACT_MGR|TYPE_CONVEX_LIST_CONTACT_MGR) )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_USER_CONTACT_MGR|TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 403
// RVA: 0xE492C0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const int *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == (TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR) )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 404
// RVA: 0xE49320
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned int *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == 8 )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)8);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 405
// RVA: 0xE494A0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const __int64 *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == 9 )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)9);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 406
// RVA: 0xE49500
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned __int64 *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == 10 )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)10);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 407
// RVA: 0xE49380
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const float *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == (TYPE_NULL_CONTACT_MGR|0x8) )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties(TYPE_NULL_CONTACT_MGR|0x8);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 408
// RVA: 0xE49440
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, hkHalf *v, unsigned int n)
{
  hkClassMember::TypeProperties *ClassMemberTypeProperties; // rax

  if ( this->m_nativeType == 32 )
  {
    this->vfptr[4].__vecDelDtor(this, n);
    ClassMemberTypeProperties = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)32);
    hkString::memCpy(this->m_address, v, n * ClassMemberTypeProperties->m_size);
  }
}

// File Line: 410
// RVA: 0xE49650
void __fastcall hkDataArrayNative::setVec(hkDataArrayNative *this, int index, const float *val)
{
  hkVariantDataUtil::setReals(
    this->m_nativeType,
    this->m_tupleCount,
    val,
    (char *)this->m_address + index * this->m_elementStride,
    -1);
}

// File Line: 411
// RVA: 0xE49630
void __fastcall hkDataArrayNative::setString(hkDataArrayNative *this, int index, const char *val)
{
  hkVariantDataUtil::setString(
    this->m_nativeType,
    (hkStringPtr *)((char *)this->m_address + index * this->m_elementStride),
    val);
}

// File Line: 412
// RVA: 0xE495C0
void __fastcall hkDataArrayNative::setReal(hkDataArrayNative *this, int index, float val)
{
  hkVariantDataUtil::setReal(
    this->m_nativeType,
    (float *)((char *)this->m_address + index * this->m_elementStride),
    val);
}

// File Line: 413
// RVA: 0xE49560
void __fastcall hkDataArrayNative::setHalf(hkDataArrayNative *this, int index, hkHalf val)
{
  hkVariantDataUtil::setHalf(
    this->m_nativeType,
    (hkHalf *)((char *)this->m_address + index * this->m_elementStride),
    val);
}

// File Line: 414
// RVA: 0xE495A0
void __fastcall hkDataArrayNative::setInt(hkDataArrayNative *this, int index, BOOL val)
{
  hkVariantDataUtil::setInt(this->m_nativeType, (bool *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 415
// RVA: 0xE49580
void __fastcall hkDataArrayNative::setInt64(hkDataArrayNative *this, int index, _BOOL8 val)
{
  hkVariantDataUtil::setInt(this->m_nativeType, (bool *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 461
// RVA: 0xE47C00
void __fastcall hkDataObjectNative::hkDataObjectNative(
        hkDataObjectNative *this,
        hkDataObject_Handle *h,
        hkDataWorldNative *world)
{
  hkClass *p1; // rax

  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataObjectNative::`vftable;
  p1 = (hkClass *)h->p1;
  if ( !p1 )
    p1 = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, void *))world->m_vtable.m_pntr->vfptr[2].__first_virtual_table_function__)(
                      world->m_vtable.m_pntr,
                      h->p0);
  hkClassAccessor::hkClassAccessor(&this->m_object, h->p0, p1);
  this->m_world = world;
  this->m_hasOwnedRef.m_bool = 0;
}

// File Line: 475
// RVA: 0xE48D50
hkDataObject_Handle *__fastcall hkDataObjectNative::getHandle(hkDataObjectNative *this, hkDataObject_Handle *result)
{
  hkClass *m_class; // rbx
  bool v4; // zf
  hkDataObject_Handle *v5; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h] BYREF

  m_class = this->m_object.m_variant.m_class;
  result->p0 = this->m_object.m_variant.m_object;
  v4 = hkClass::hasVtable(m_class, &resulta)->m_bool == 0;
  v5 = result;
  if ( !v4 )
    m_class = 0i64;
  result->p1 = m_class;
  return v5;
}

// File Line: 488
// RVA: 0xE48C90
hkDataClassImpl *__fastcall hkDataObjectNative::getClass(hkDataObjectNative *this)
{
  hkClass *m_class; // rcx
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax

  m_class = this->m_object.m_variant.m_class;
  if ( !m_class )
    return 0i64;
  vfptr = this->m_world->vfptr;
  Name = hkClass::getName(m_class);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))vfptr[4].__first_virtual_table_function__)(
                              this->m_world,
                              Name);
}

// File Line: 493
// RVA: 0xE47F80
hkDataObject_Value *__fastcall hkDataObjectNative::accessByName(
        hkDataObjectNative *this,
        hkDataObject_Value *result,
        const char *name)
{
  const struct _hkDataObject_MemberHandle *ClassMember; // rax
  hkClassMemberAccessor v7; // [rsp+20h] [rbp-18h] BYREF
  hkBool resulta; // [rsp+40h] [rbp+8h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v7, &this->m_object.m_variant, name);
  if ( hkClassMemberAccessor::isOk(&v7, &resulta)->m_bool )
  {
    ClassMember = (const struct _hkDataObject_MemberHandle *)hkClassMemberAccessor::getClassMember(&v7);
    result->m_impl = this;
    result->m_handle = ClassMember;
  }
  else
  {
    result->m_impl = 0i64;
    result->m_handle = 0i64;
  }
  return result;
}

// File Line: 505
// RVA: 0xE48F70
_BOOL8 __fastcall hkDataObjectNative::hasMember(hkDataObjectNative *this, const char *name)
{
  hkClassMemberAccessor v3; // [rsp+20h] [rbp-18h] BYREF
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v3, &this->m_object.m_variant, name);
  return hkClassMemberAccessor::isOk(&v3, &result)->m_bool != 0;
}

// File Line: 511
// RVA: 0xE48FB0
_BOOL8 __fastcall hkDataObjectNative::isSet(hkDataObjectNative *this, hkClassMember *handle)
{
  hkClassMemberAccessor v3; // [rsp+20h] [rbp-18h] BYREF
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v3, this->m_object.m_variant.m_object, handle);
  return hkClassMemberAccessor::isOk(&v3, &result)->m_bool != 0;
}

// File Line: 521
// RVA: 0xE49070
_BOOL8 __fastcall hkDataObjectNative::isValid(hkDataObjectNative *this, int it)
{
  return it < (int)hkClass::getNumMembers(this->m_object.m_variant.m_class);
}

// File Line: 529
// RVA: 0xE48E20
const char *__fastcall hkDataObjectNative::getMemberName(hkDataObjectNative *this, int it)
{
  return hkClass::getMember(this->m_object.m_variant.m_class, it)->m_name;
}

// File Line: 533
// RVA: 0xE48E40
hkDataObject_Value *__fastcall hkDataObjectNative::getMemberValue(
        hkDataObjectNative *this,
        hkDataObject_Value *result,
        int it)
{
  const struct _hkDataObject_MemberHandle *Member; // rax

  Member = (const struct _hkDataObject_MemberHandle *)hkClass::getMember(this->m_object.m_variant.m_class, it);
  result->m_impl = this;
  result->m_handle = Member;
  return result;
}

// File Line: 539
// RVA: 0xE48B60
void __fastcall hkDataObjectNative::getAllMemberHandles(
        hkDataObjectNative *this,
        hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  hkDataClassNative *v3; // rax

  v3 = (hkDataClassNative *)((__int64 (__fastcall *)(hkDataObjectNative *))this->vfptr[2].__vecDelDtor)(this);
  hkDataClassNative::_getAllMemberHandles(v3, handles);
}

// File Line: 548
// RVA: 0xE48190
hkDataArrayImpl *__fastcall hkDataObjectNative::asArray(hkDataObjectNative *this, hkClassMember *handle)
{
  _DWORD *v4; // r15
  _QWORD *v5; // rax
  char *Address; // rbp
  int v7; // r12d
  hkClass **v8; // rax
  hkClass *v9; // rsi
  hkClassMember::Type m_storage; // edi
  int ObjectSize; // ebx
  hkClass *v12; // rax
  _QWORD **v13; // rax
  __int64 v14; // rax
  __int64 v15; // rbx
  hkDataWorldNative *v16; // rcx
  unsigned __int16 *v18; // rax
  hkClassMember *ClassMember; // rax
  int CstyleArraySize; // eax
  hkClass *Class; // rax
  _QWORD **Value; // rax
  __int64 v23; // rax
  __int64 v24; // r14
  hkDataWorldNative *m_world; // rcx
  hkClassMemberAccessor v26; // [rsp+30h] [rbp-38h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v26, this->m_object.m_variant.m_object, handle);
  v4 = 0i64;
  switch ( handle->m_type.m_storage )
  {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x19:
    case 0x1E:
    case 0x20:
      Address = (char *)hkClassMemberAccessor::getAddress(&v26);
      ClassMember = hkClassMemberAccessor::getClassMember(&v26);
      CstyleArraySize = hkClassMember::getCstyleArraySize(ClassMember);
      m_storage = (unsigned __int8)handle->m_type.m_storage;
      v7 = CstyleArraySize;
      Class = hkClassMember::getClass(handle);
      v9 = Class;
      if ( m_storage == 25 )
        ObjectSize = hkClass::getObjectSize(Class);
      else
        ObjectSize = hkClassMember::getClassMemberTypeProperties(m_storage)->m_size;
      goto LABEL_17;
    case 0x16:
    case 0x1A:
      v4 = hkClassMemberAccessor::getAddress(&v26);
      Address = *(char **)v4;
      v7 = v4[2];
      goto LABEL_5;
    case 0x1B:
      v5 = hkClassMemberAccessor::getAddress(&v26);
      Address = (char *)v5[1];
      v7 = *((_DWORD *)v5 + 4);
      v4 = v5 + 1;
      v8 = (hkClass **)hkClassMemberAccessor::getAddress(&v26);
      v9 = *v8;
      if ( !*v8 )
        goto LABEL_16;
      m_storage = 25;
      ObjectSize = hkClass::getObjectSize(*v8);
      goto LABEL_17;
    case 0x22:
      v18 = (unsigned __int16 *)hkClassMemberAccessor::getAddress(&v26);
      v7 = *v18;
      Address = (char *)v18 + v18[1];
LABEL_5:
      v12 = hkClassMember::getClass(handle);
      m_storage = (unsigned __int8)handle->m_subtype.m_storage;
      v9 = v12;
      ObjectSize = hkClassMember::getClassMemberTypeProperties(m_storage)->m_size;
      if ( m_storage )
      {
        if ( ObjectSize == -1 )
          ObjectSize = hkClass::getObjectSize(v9);
LABEL_17:
        Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v23 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 80i64);
        v24 = v23;
        if ( !v23 )
          return 0i64;
        m_world = this->m_world;
        *(_QWORD *)(v23 + 8) = 0xFFFFi64;
        *(_DWORD *)(v23 + 44) = 0;
        *(_DWORD *)(v23 + 64) = 0;
        *(_QWORD *)(v23 + 24) = Address;
        *(_QWORD *)(v23 + 16) = m_world;
        *(_DWORD *)(v23 + 32) = v7;
        *(_DWORD *)(v23 + 36) = ObjectSize;
        *(_QWORD *)v23 = &hkDataArrayNative::`vftable;
        *(_DWORD *)(v23 + 40) = m_storage;
        *(_QWORD *)(v23 + 48) = v9;
        *(_QWORD *)(v23 + 72) = v4;
        *(_QWORD *)(v23 + 56) = ((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, hkClass *, _DWORD))m_world->vfptr[12].__vecDelDtor)(
                                  m_world,
                                  (unsigned int)m_storage,
                                  0i64,
                                  v9,
                                  0);
        return (hkDataArrayImpl *)v24;
      }
      else
      {
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v13[11] + 8i64))(v13[11], 80i64);
        v15 = v14;
        if ( v14 )
        {
          v16 = this->m_world;
          *(_QWORD *)(v14 + 8) = 0xFFFFi64;
          *(_QWORD *)v14 = &hkDataArrayNative::`vftable;
          *(_QWORD *)(v14 + 16) = v16;
          *(_QWORD *)(v14 + 24) = 0i64;
          *(_QWORD *)(v14 + 32) = 0i64;
          *(_QWORD *)(v14 + 40) = 0i64;
          *(_QWORD *)(v14 + 48) = 0i64;
          *(_DWORD *)(v14 + 64) = 0;
          *(_QWORD *)(v14 + 72) = 0i64;
          *(_QWORD *)(v14 + 56) = ((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, _QWORD, _DWORD))v16->vfptr[12].__vecDelDtor)(
                                    v16,
                                    0i64,
                                    0i64,
                                    0i64,
                                    0);
          return (hkDataArrayImpl *)v15;
        }
        else
        {
          return 0i64;
        }
      }
    default:
      Address = 0i64;
      v7 = 0;
      v9 = 0i64;
LABEL_16:
      ObjectSize = 0;
      m_storage = TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR;
      goto LABEL_17;
  }
}

// File Line: 672
// RVA: 0xE48760
const char *__fastcall hkDataObjectNative::asString(hkDataObjectNative *this, hkClassMember *handle)
{
  hkClassMember *v2; // rbx
  const void *Address; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h] BYREF

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, handle);
  LODWORD(v2) = (unsigned __int8)v2->m_type.m_storage;
  Address = hkClassMemberAccessor::getAddress(&v5);
  return hkVariantDataUtil::getString((hkClassMember::Type)v2, Address);
}

// File Line: 678
// RVA: 0xE48470
__int64 __fastcall hkDataObjectNative::asInt(hkDataObjectNative *this, hkClassMember *handle)
{
  hkClassMember *v2; // rdi
  hkClassMember::Type m_storage; // ebx
  __int64 *Address; // rax
  hkClassMemberAccessor v6; // [rsp+20h] [rbp-18h] BYREF

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v6, this->m_object.m_variant.m_object, handle);
  m_storage = (unsigned __int8)v2->m_subtype.m_storage;
  LODWORD(v2) = (unsigned __int8)v2->m_type.m_storage;
  Address = (__int64 *)hkClassMemberAccessor::getAddress(&v6);
  return hkVariantDataUtil::getInt((hkClassMember::Type)v2, m_storage, Address);
}

// File Line: 684
// RVA: 0xE48540
hkClassAccessor *__fastcall hkDataObjectNative::asObject(hkDataObjectNative *this, hkClassMember *handle)
{
  hkDataWorldNative *m_world; // rax
  hkClassMember::Type m_storage; // ebp
  hkClassNameRegistry *classReg; // rdi
  hkVtableClassRegistry *m_pntr; // rsi
  const void **data; // rbx
  hkClass *Class; // rax
  hkVariant *Object; // rax
  hkClass *m_class; // rdx
  hkVariant v; // [rsp+30h] [rbp-48h] BYREF
  hkClassMemberAccessor v14; // [rsp+40h] [rbp-38h] BYREF
  hkVariant result; // [rsp+50h] [rbp-28h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v14, this->m_object.m_variant.m_object, handle);
  m_world = this->m_world;
  m_storage = (unsigned __int8)handle->m_type.m_storage;
  classReg = m_world->m_reg.m_pntr;
  m_pntr = m_world->m_vtable.m_pntr;
  data = (const void **)hkClassMemberAccessor::asRaw(&v14);
  Class = hkClassMember::getClass(handle);
  Object = hkVariantDataUtil::getObject(&result, m_storage, Class, m_pntr, classReg, data);
  v.m_object = Object->m_object;
  m_class = Object->m_class;
  v.m_class = m_class;
  if ( v.m_object && m_class )
    return hkNativeDataObjectImplCreate(&v, this->m_world, 0);
  else
    return 0i64;
}

// File Line: 691
// RVA: 0xE487D0
const float *__fastcall hkDataObjectNative::asVec(hkDataObjectNative *this, hkClassMember *handle, int nreal)
{
  hkClassMember::Type m_storage; // esi
  hkDataWorldNative *m_world; // rdi
  char *Address; // rbx
  unsigned int CstyleArraySize; // eax
  hkClassMemberAccessor v10; // [rsp+20h] [rbp-18h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v10, this->m_object.m_variant.m_object, handle);
  m_storage = (unsigned __int8)handle->m_type.m_storage;
  m_world = this->m_world;
  Address = (char *)hkClassMemberAccessor::getAddress(&v10);
  CstyleArraySize = hkClassMember::getCstyleArraySize(handle);
  return hkVariantDataUtil::getReals(m_storage, CstyleArraySize, Address, &m_world->m_buffer);
}

// File Line: 697
// RVA: 0xE48620
float __fastcall hkDataObjectNative::asReal(hkDataObjectNative *this, hkClassMember *handle)
{
  hkClassMember *v2; // rbx
  __int16 *Address; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h] BYREF

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, handle);
  LODWORD(v2) = (unsigned __int8)v2->m_type.m_storage;
  Address = (__int16 *)hkClassMemberAccessor::getAddress(&v5);
  return hkVariantDataUtil::getReal((hkClassMember::Type)v2, Address);
}

// File Line: 703
// RVA: 0xE48840
// attributes: thunk
void __fastcall hkDataObjectNative::assign(
        hkDataObjectNative *this,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataObject_Value *valueIn)
{
  hkDataObjectImpl::assignValueImpl(this, handle, valueIn);
}

// File Line: 707
// RVA: 0xE48910
void __fastcall hkDataObjectNative::assign(
        hkDataObjectNative *this,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataObjectImpl *val)
{
  bool v5; // si
  hkDataRefCountedVtbl *vfptr; // rbx
  hkClass *v7; // rdi
  hkReferencedObject **Address; // rax
  hkReferencedObject *v9; // rdx
  hkClass *v10; // rcx
  hkReferencedObject **v11; // r8
  hkReferencedObject **v12; // rbx
  hkClass *Class; // rax
  hkClassMemberAccessor v14; // [rsp+20h] [rbp-18h] BYREF

  v5 = (*((_WORD *)handle + 14) & 0x200) == 0;
  hkClassMemberAccessor::hkClassMemberAccessor(&v14, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  if ( val )
  {
    vfptr = val[1].vfptr;
    v7 = *(hkClass **)&val[1].m_memSize;
    Address = (hkReferencedObject **)hkClassMemberAccessor::getAddress(&v14);
    v9 = (hkReferencedObject *)vfptr;
    v10 = v7;
    v11 = Address;
  }
  else
  {
    if ( !hkClassMember::getClass((hkClassMember *)handle) )
      return;
    v12 = (hkReferencedObject **)hkClassMemberAccessor::getAddress(&v14);
    Class = hkClassMember::getClass((hkClassMember *)handle);
    v11 = v12;
    v10 = Class;
    v9 = 0i64;
  }
  hkVariantDataUtil::setPointer(v10, v9, v11, (hkBool)v5);
}

// File Line: 739
// RVA: 0xE489C0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, const char *value)
{
  hkClassMember *v4; // rbx
  hkStringPtr *Address; // rax
  hkClassMemberAccessor v6; // [rsp+20h] [rbp-18h] BYREF

  v4 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v6, this->m_object.m_variant.m_object, handle);
  LODWORD(v4) = (unsigned __int8)v4->m_type.m_storage;
  Address = (hkStringPtr *)hkClassMemberAccessor::getAddress(&v6);
  hkVariantDataUtil::setString((hkClassMember::Type)v4, Address, value);
}

// File Line: 745
// RVA: 0xE488C0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, float r)
{
  hkClassMember *v3; // rbx
  float *Address; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-28h] BYREF

  v3 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, handle);
  LODWORD(v3) = (unsigned __int8)v3->m_type.m_storage;
  Address = (float *)hkClassMemberAccessor::getAddress(&v5);
  hkVariantDataUtil::setReal((hkClassMember::Type)v3, Address, r);
}

// File Line: 751
// RVA: 0xE48A90
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, hkHalf r)
{
  hkClassMember *v3; // rbx
  float *Address; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h] BYREF

  v3 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, handle);
  LODWORD(v3) = (unsigned __int8)v3->m_type.m_storage;
  Address = (float *)hkClassMemberAccessor::getAddress(&v5);
  hkVariantDataUtil::setReal((hkClassMember::Type)v3, Address, COERCE_FLOAT(r.m_value << 16));
}

// File Line: 757
// RVA: 0xE48A10
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, const float *r, int nreal)
{
  hkClassMember::Type m_storage; // edi
  char *Address; // rbx
  unsigned int CstyleArraySize; // eax
  hkClassMemberAccessor v10; // [rsp+30h] [rbp-18h] BYREF

  hkClassMemberAccessor::hkClassMemberAccessor(&v10, this->m_object.m_variant.m_object, handle);
  m_storage = (unsigned __int8)handle->m_type.m_storage;
  Address = (char *)hkClassMemberAccessor::getAddress(&v10);
  CstyleArraySize = hkClassMember::getCstyleArraySize(handle);
  hkVariantDataUtil::setReals(m_storage, CstyleArraySize, r, Address, nreal);
}

// File Line: 763
// RVA: 0xE48AE0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, _BOOL8 valueIn)
{
  hkClassMember *v4; // rdi
  hkClassMember::Type m_storage; // ebx
  bool *Address; // rax
  hkClassMemberAccessor v7; // [rsp+20h] [rbp-18h] BYREF

  v4 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v7, this->m_object.m_variant.m_object, handle);
  m_storage = (unsigned __int8)v4->m_subtype.m_storage;
  LODWORD(v4) = (unsigned __int8)v4->m_type.m_storage;
  Address = (bool *)hkClassMemberAccessor::getAddress(&v7);
  hkVariantDataUtil::setInt((hkClassMember::Type)v4, m_storage, Address, valueIn);
}

// File Line: 769
// RVA: 0xE48850
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, hkClassMember *handle, int valueIn)
{
  __int64 v3; // rbp
  hkClassMember::Type m_storage; // edi
  hkClassMember::Type v6; // esi
  bool *Address; // rax
  hkClassMemberAccessor v8; // [rsp+20h] [rbp-18h] BYREF

  v3 = valueIn;
  hkClassMemberAccessor::hkClassMemberAccessor(&v8, this->m_object.m_variant.m_object, handle);
  m_storage = (unsigned __int8)handle->m_subtype.m_storage;
  v6 = (unsigned __int8)handle->m_type.m_storage;
  Address = (bool *)hkClassMemberAccessor::getAddress(&v8);
  hkVariantDataUtil::setInt(v6, m_storage, Address, v3);
}

// File Line: 775
// RVA: 0xE48E00
void __fastcall hkDataObjectNative::getMemberInfo(
        hkDataObjectNative *this,
        hkClassMember *handle,
        hkDataClass_MemberInfo *infoOut)
{
  hkDataClassNative::_fillMemberInfo(0i64, this->m_world, handle, infoOut);
}

// File Line: 791
// RVA: 0xE47A70
hkClassAccessor *__fastcall hkNativeDataObjectImplCreate(hkVariant *v, hkDataWorldNative *w, hkBool isRefOwned)
{
  hkClass *m_class; // rcx
  hkBaseObjectVtbl *vfptr; // rbx
  const char *Name; // rax
  __int64 v8; // rax
  const char *v9; // rbx
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  _QWORD **Value; // rax
  hkClassAccessor *v15; // rax
  hkClassAccessor *v16; // rbx
  hkErrStream v18; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  m_class = v->m_class;
  if ( m_class )
  {
    vfptr = w->vfptr;
    Name = hkClass::getName(m_class);
    v8 = ((__int64 (__fastcall *)(hkDataWorldNative *, const char *))vfptr[4].__first_virtual_table_function__)(w, Name);
    if ( v8 )
    {
      v->m_class = *(hkClass **)(v8 + 16);
    }
    else
    {
      hkErrStream::hkErrStream(&v18, buf, 512);
      v9 = hkClass::getName(v->m_class);
      v10 = hkOstream::operator<<(&v18, "Ignore object at 0x");
      v11 = hkOstream::operator<<(v10, v->m_object);
      v12 = hkOstream::operator<<(v11, ". Class ");
      v13 = hkOstream::operator<<(v12, v9);
      hkOstream::operator<<(v13, " is not registered in the provided hkDataWorldNative.");
      hkError::messageWarning(0x1800473Au, buf, "Data\\Native\\hkDataObjectNative.cpp", 800);
      hkOstream::~hkOstream(&v18);
      v->m_object = 0i64;
      v->m_class = 0i64;
    }
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkClassAccessor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v16 = v15;
  if ( !v15 )
    return 0i64;
  v15->m_variant.m_class = (hkClass *)0xFFFF;
  v15->m_variant.m_object = &hkDataObjectNative::`vftable;
  hkClassAccessor::hkClassAccessor(v15 + 1, v);
  v16[2].m_variant.m_object = w;
  LOBYTE(v16[2].m_variant.m_class) = isRefOwned;
  return v16;
}

// File Line: 816
// RVA: 0xE47BD0
void __fastcall hkDataArrayNative::setObject(hkDataArrayNative *this, int index, hkDataObjectImpl *val)
{
  if ( this->m_nativeType != 25 )
    hkVariantDataUtil::setPointer(
      *(hkClass **)&val[1].m_memSize,
      (hkReferencedObject *)val[1].vfptr,
      (hkReferencedObject **)((char *)this->m_address + index * this->m_elementStride),
      (hkBool)1);
}

// File Line: 842
// RVA: 0xE472B0
void __fastcall hkDataWorldNative::hkDataWorldNative(hkDataWorldNative *this, hkBool accessSerializeIgnored)
{
  hkReferencedObject *v3; // rax
  hkVtableClassRegistry *v4; // rdi
  hkVtableClassRegistry *m_pntr; // rcx
  hkReferencedObject *v6; // rax
  hkClassNameRegistry *v7; // rdi
  hkClassNameRegistry *v8; // rcx
  hkReferencedObject *v9; // rax
  hkTypeInfoRegistry *v10; // rdi
  hkTypeInfoRegistry *v11; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldNative::`vftable;
  this->m_reg.m_pntr = 0i64;
  this->m_vtable.m_pntr = 0i64;
  this->m_infoReg.m_pntr = 0i64;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classes.m_map,
    0);
  this->m_accessSerializeIgnored = accessSerializeIgnored;
  hkTypeManager::hkTypeManager(&this->m_typeManager);
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_size = 0;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  this->m_contents.m_class = 0i64;
  this->m_contents.m_object = 0i64;
  v3 = (hkReferencedObject *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v4 = (hkVtableClassRegistry *)v3;
  if ( v3 )
    hkReferencedObject::addReference(v3);
  m_pntr = this->m_vtable.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_vtable.m_pntr = v4;
  v6 = (hkReferencedObject *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v7 = (hkClassNameRegistry *)v6;
  if ( v6 )
    hkReferencedObject::addReference(v6);
  v8 = this->m_reg.m_pntr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  this->m_reg.m_pntr = v7;
  v9 = (hkReferencedObject *)((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  v10 = (hkTypeInfoRegistry *)v9;
  if ( v9 )
    hkReferencedObject::addReference(v9);
  v11 = this->m_infoReg.m_pntr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  this->m_infoReg.m_pntr = v10;
}

// File Line: 851
// RVA: 0xE473C0
void __fastcall hkDataWorldNative::~hkDataWorldNative(hkDataWorldNative *this)
{
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *p_m_classes; // rcx
  Dummy *Iterator; // rdi
  void (__fastcall ***Value)(_QWORD, __int64); // rax
  int m_capacityAndFlags; // r8d
  hkTypeInfoRegistry *m_pntr; // rcx
  hkVtableClassRegistry *v7; // rcx
  hkClassNameRegistry *v8; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  p_m_classes = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes;
  *(_QWORD *)&p_m_classes[-2].m_numElems = &hkDataWorldNative::`vftable;
  Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(p_m_classes);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
    &result,
    Iterator);
  while ( result.m_bool )
  {
    Value = (void (__fastcall ***)(_QWORD, __int64))hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                                      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
                                                      Iterator);
    if ( Value )
      (**Value)(Value, 1i64);
    Iterator = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
                 (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
                 Iterator);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
      &result,
      Iterator);
  }
  m_capacityAndFlags = this->m_buffer.m_capacityAndFlags;
  this->m_buffer.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_buffer.m_data,
      m_capacityAndFlags & 0x3FFFFFFF);
  this->m_buffer.m_data = 0i64;
  this->m_buffer.m_capacityAndFlags = 0x80000000;
  hkTypeManager::~hkTypeManager(&this->m_typeManager);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&this->m_classes.m_map);
  m_pntr = this->m_infoReg.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_infoReg.m_pntr = 0i64;
  v7 = this->m_vtable.m_pntr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  this->m_vtable.m_pntr = 0i64;
  v8 = this->m_reg.m_pntr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  this->m_reg.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 860
// RVA: 0xE47A60
hkTypeManager::Type *__fastcall hkDataWorldNative::getTypeFromMemberType(
        hkDataWorldNative *this,
        hkClassMember::Type mtype,
        hkClassMember::Type stype,
        hkClass *klass,
        int count)
{
  return hkDataObjectUtil::getTypeFromMemberType(&this->m_typeManager, mtype, stype, klass, count);
}

// File Line: 865
// RVA: 0xE479E0
void __fastcall hkDataWorldNative::setClassRegistry(hkDataWorldNative *this, hkClassNameRegistry *r)
{
  hkClassNameRegistry *m_pntr; // rcx

  if ( r )
    hkReferencedObject::addReference(r);
  m_pntr = this->m_reg.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_reg.m_pntr = r;
}

// File Line: 870
// RVA: 0xE47A20
void __fastcall hkDataWorldNative::setVtableRegistry(hkDataWorldNative *this, hkVtableClassRegistry *vt)
{
  hkVtableClassRegistry *m_pntr; // rcx

  if ( vt )
    hkReferencedObject::addReference(vt);
  m_pntr = this->m_vtable.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_vtable.m_pntr = vt;
}

// File Line: 875
// RVA: 0xE47920
hkDataObjectImpl *__fastcall hkDataWorldNative::wrapObject(hkDataWorldNative *this, void *object, hkClass *klass)
{
  hkVariant v; // [rsp+20h] [rbp-18h] BYREF

  v.m_object = object;
  v.m_class = klass;
  return hkNativeDataObjectImplCreate(&v, this, 0);
}

// File Line: 882
// RVA: 0xE47950
void __fastcall hkDataWorldNative::setContents(hkDataWorldNative *this, void *object, hkClass *klass)
{
  hkClassNameRegistry *m_pntr; // rbx
  hkBaseObjectVtbl *vfptr; // rdi
  const char *Name; // rax
  hkClass *v9; // rbx
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  m_pntr = this->m_reg.m_pntr;
  this->m_contents.m_object = object;
  vfptr = m_pntr->vfptr;
  Name = hkClass::getName(klass);
  v9 = (hkClass *)vfptr[2].__vecDelDtor(m_pntr, (unsigned int)Name);
  if ( hkClass::hasVtable(klass, &result)->m_bool )
    this->m_contents.m_class = hkVariantDataUtil::findMostDerivedClass(
                                 object,
                                 this->m_vtable.m_pntr,
                                 this->m_reg.m_pntr);
  else
    this->m_contents.m_class = v9;
  if ( !this->m_contents.m_class )
    this->m_contents.m_object = 0i64;
}

// File Line: 910
// RVA: 0xE477E0
hkDataClassImpl *__fastcall hkDataWorldNative::findClass(hkDataWorldNative *this, const char *name)
{
  hkDataClassImpl *result; // rax
  void *v5; // rbp
  _QWORD **Value; // rax
  _QWORD *v7; // rax
  unsigned __int64 v8; // rbx

  if ( name )
  {
    result = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
                                  name,
                                  0i64);
    if ( result )
      return result;
    v5 = this->m_reg.m_pntr->vfptr[2].__vecDelDtor(this->m_reg.m_pntr, name);
  }
  else
  {
    v5 = 0i64;
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  v8 = (unsigned __int64)v7;
  if ( v7 )
  {
    v7[1] = 0xFFFFi64;
    v7[2] = v5;
    *v7 = &hkDataClassNative::`vftable;
    v7[3] = this;
  }
  else
  {
    v8 = 0i64;
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_classes.m_map, name, v8);
  return (hkDataClassImpl *)v8;
}

// File Line: 923
// RVA: 0xE476B0
void __fastcall hkDataWorldNative::findAllClasses(
        hkDataWorldNative *this,
        hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  hkClassNameRegistry *m_pntr; // rcx
  int v5; // ebp
  __int64 v6; // rsi
  hkBaseObjectVtbl *vfptr; // rdi
  const char *Name; // rax
  hkDataClassImpl *v9; // rdi
  char *v10; // [rsp+20h] [rbp-18h] BYREF
  int v11; // [rsp+28h] [rbp-10h]
  int v12; // [rsp+2Ch] [rbp-Ch]

  m_pntr = this->m_reg.m_pntr;
  if ( m_pntr )
  {
    v10 = 0i64;
    v11 = 0;
    v12 = 0x80000000;
    ((void (__fastcall *)(hkClassNameRegistry *, char **))m_pntr->vfptr[2].__first_virtual_table_function__)(
      m_pntr,
      &v10);
    v5 = 0;
    if ( v11 > 0 )
    {
      v6 = 0i64;
      do
      {
        if ( (hkClass::getFlags(*(hkClass **)&v10[v6])->m_storage & 1) == 0 )
        {
          vfptr = this->vfptr;
          Name = hkClass::getName(*(hkClass **)&v10[v6]);
          v9 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))vfptr[4].__first_virtual_table_function__)(
                                    this,
                                    Name);
          if ( classesOut->m_size == (classesOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&classesOut->m_data, 8);
          classesOut->m_data[classesOut->m_size++] = v9;
        }
        ++v5;
        v6 += 8i64;
      }
      while ( v5 < v11 );
    }
    v11 = 0;
    if ( v12 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v10, 8 * v12);
  }
}

// File Line: 943
// RVA: 0xE478B0
hkDataObject *__fastcall hkDataWorldNative::findObject(
        hkDataWorldNative *this,
        hkDataObject *result,
        hkDataObject_Handle *handle)
{
  _QWORD **Value; // rax
  hkDataObjectNative *v7; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkDataObjectNative *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v7 )
    hkDataObjectNative::hkDataObjectNative(v7, handle, this);
  result->m_impl = v7;
  if ( v7 )
  {
    ++v7->m_externalCount;
    ++v7->m_count;
  }
  return result;
}

// File Line: 948
// RVA: 0xE476A0
hkEnum<enum hkDataWorld::DataWorldType,int> *__fastcall hkDataWorldNative::getType(
        hkDataWorldNative *this,
        hkEnum<enum hkDataWorld::DataWorldType,int> *result)
{
  result->m_storage = 0;
  return result;
}

// File Line: 953
// RVA: 0xE47500
hkDataObject *__fastcall hkDataWorldNative::getContents(hkDataWorldNative *this, hkDataObject *result)
{
  _QWORD **Value; // rax
  hkClassAccessor *v5; // rax
  hkClassAccessor *v6; // rbx
  hkDataObject *v7; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkClassAccessor *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v6 = v5;
  if ( v5 )
  {
    v5->m_variant.m_class = (hkClass *)0xFFFF;
    v5->m_variant.m_object = &hkDataObjectNative::`vftable;
    hkClassAccessor::hkClassAccessor(v5 + 1, &this->m_contents);
    v6[2].m_variant.m_object = this;
    LOBYTE(v6[2].m_variant.m_class) = 0;
  }
  else
  {
    v6 = 0i64;
  }
  result->m_impl = (hkDataObjectImpl *)v6;
  v7 = result;
  if ( v6 )
  {
    ++WORD1(v6->m_variant.m_class);
    ++HIDWORD(v6->m_variant.m_class);
  }
  return v7;
}

// File Line: 958
// RVA: 0xE47590
hkDataObjectImpl *__fastcall hkDataWorldNative::newObject(
        hkDataWorldNative *this,
        hkDataClass *klass,
        __int64 __formal)
{
  hkClassNameRegistry *m_pntr; // rbx
  __int64 v6; // rax
  hkClass *v7; // rsi
  _QWORD **Value; // rax
  void *v9; // rax
  unsigned int ObjectSize; // eax
  __int64 v11; // rbx
  __int64 v12; // rax
  hkTypeInfo *v13; // rax
  hkVariant dst; // [rsp+20h] [rbp-18h] BYREF

  m_pntr = this->m_reg.m_pntr;
  v6 = ((__int64 (__fastcall *)(hkDataClassImpl *, hkDataClass *, __int64))klass->m_impl->vfptr[2].__vecDelDtor)(
         klass->m_impl,
         klass,
         __formal);
  v7 = (hkClass *)m_pntr->vfptr[2].__vecDelDtor(m_pntr, v6);
  LODWORD(m_pntr) = hkClass::getObjectSize(v7);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(Value[11], (unsigned int)m_pntr);
  dst.m_class = v7;
  dst.m_object = v9;
  if ( v9 )
  {
    ObjectSize = hkClass::getObjectSize(v7);
    hkString::memSet(dst.m_object, 0, ObjectSize);
    v11 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
    v12 = ((__int64 (__fastcall *)(hkDataClassImpl *))klass->m_impl->vfptr[2].__vecDelDtor)(klass->m_impl);
    v13 = (hkTypeInfo *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 56i64))(v11, v12);
    if ( v13 )
      hkTypeInfo::finishLoadedObject(v13, dst.m_object, 0);
  }
  return hkNativeDataObjectImplCreate(&dst, this, 0);
}

// File Line: 977
// RVA: 0xE47680
hkDataClassImpl *__fastcall hkDataWorldNative::newClass(hkDataWorldNative *this, hkDataClass::Cinfo *cinfo)
{
  return 0i64;
}

// File Line: 982
// RVA: 0xE47690
hkDataArrayImpl *__fastcall hkDataWorldNative::newArray(
        hkDataWorldNative *this,
        hkDataObject *_obj,
        const struct _hkDataObject_MemberHandle *handle,
        hkDataClass_MemberInfo *minfo)
{
  return 0i64;
}

