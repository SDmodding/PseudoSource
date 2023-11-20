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
  hkDataClassNative *v1; // rdi
  hkClass *result; // rax
  hkBaseObjectVtbl *v3; // rbx
  const char *v4; // rax

  v1 = this;
  result = hkClass::getParent(this->m_class);
  if ( result )
  {
    v3 = v1->m_world->vfptr;
    v4 = hkClass::getName(result);
    result = (hkClass *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))v3[4].__first_virtual_table_function__)(
                          v1->m_world,
                          v4);
  }
  return result;
}

// File Line: 61
// RVA: 0xE48FF0
hkBool *__fastcall hkDataClassNative::isSuperClass(hkDataClassNative *this, hkBool *result, hkDataClassImpl *k)
{
  hkDataClassImpl *v3; // rbx
  hkBool *v4; // rsi
  hkDataClassNative *v5; // r14
  const char *v6; // rdi
  const char *v7; // rax

  v3 = k;
  v4 = result;
  v5 = this;
  if ( k )
  {
    while ( 1 )
    {
      v6 = (const char *)((__int64 (__fastcall *)(hkDataClassNative *))v5->vfptr[2].__vecDelDtor)(v5);
      v7 = (const char *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[2].__vecDelDtor)(v3);
      if ( !(unsigned int)hkString::strCmp(v7, v6) )
        break;
      v3 = (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataClassImpl *))v3->vfptr[4].__vecDelDtor)(v3);
      if ( !v3 )
        goto LABEL_4;
    }
    v4->m_bool = 1;
  }
  else
  {
LABEL_4:
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 76
// RVA: 0xE48E90
__int64 __fastcall hkDataClassNative::getNumDeclaredMembers(hkDataClassNative *this)
{
  return hkClass::getNumDeclaredMembers(this->m_class);
}

// File Line: 80
// RVA: 0xE48CE0
signed __int64 __fastcall hkDataClassNative::getDeclaredMemberIndexByName(hkDataClassNative *this, const char *name)
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
signed __int64 __fastcall hkDataClassNative::getMemberIndexByName(hkDataClassNative *this, const char *name)
{
  return hkClass::getMemberIndexByName(this->m_class, name);
}

// File Line: 94
// RVA: 0xE47DB0
void __fastcall hkDataClassNative::_fillMemberInfo(hkDataClassImpl *clsIn, hkDataWorldNative *world, hkClassMember *mem, hkDataClass_MemberInfo *info)
{
  hkDataClassImpl *v4; // rbx
  hkDataClass_MemberInfo *v5; // r12
  hkClassMember *v6; // r15
  hkDataWorldNative *v7; // r14
  __int64 v8; // rax
  const char *v9; // r10
  __int64 v10; // rax
  hkClass *v11; // rbp
  hkVariant *v12; // rax
  hkClassNameRegistry *v13; // rbx
  hkBaseObjectVtbl *v14; // rdi
  char **v15; // rax
  __int64 v16; // rax
  const char *v17; // rax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  hkBaseObjectVtbl *v20; // rsi
  int v21; // ST20_4
  hkClassMemberAccessor v22; // [rsp+30h] [rbp-28h]

  v4 = clsIn;
  v5 = info;
  v6 = mem;
  v7 = world;
  v8 = ((__int64 (__fastcall *)(hkDataWorldNative *))world->vfptr[5].__first_virtual_table_function__)(world);
  v9 = v6->m_name;
  v5->m_owner = v4;
  v5->m_name = v9;
  if ( !((v6->m_flags.m_storage >> 10) & 1) || v7->m_accessSerializeIgnored.m_bool )
  {
    v11 = hkClassMember::getClass(v6);
    if ( v11 )
    {
      v12 = hkClassMember::getAttribute(v6, s_hkDataObjectTupeAttributeID);
      if ( v12 )
      {
        hkClassMemberAccessor::hkClassMemberAccessor(&v22, v12, "typeName");
        v13 = v7->m_reg.m_pntr;
        v14 = v13->vfptr;
        v15 = hkClassMemberAccessor::asCstring(&v22, 0);
        v16 = (__int64)v14[2].__vecDelDtor((hkBaseObject *)&v13->vfptr, (unsigned int)*v15);
LABEL_9:
        v11 = (hkClass *)v16;
        goto LABEL_10;
      }
      v17 = hkClass::getName(v11);
      if ( !(unsigned int)hkString::strCmp(v17, "hkpMaxSizeMotion") )
      {
        v16 = (__int64)v7->m_reg.m_pntr->vfptr[2].__vecDelDtor(
                         (hkBaseObject *)&v7->m_reg.m_pntr->vfptr,
                         (unsigned int)"hkpMotion");
        goto LABEL_9;
      }
    }
LABEL_10:
    v18 = (unsigned __int8)v6->m_subtype.m_storage;
    v19 = (unsigned __int8)v6->m_type.m_storage;
    v20 = v7->vfptr;
    v21 = hkClassMember::getCstyleArraySize(v6);
    v10 = ((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, hkClass *, int))v20[12].__vecDelDtor)(
            v7,
            v19,
            v18,
            v11,
            v21);
    goto LABEL_11;
  }
  v10 = *(_QWORD *)(v8 + 32);
LABEL_11:
  v5->m_type = (hkTypeManager::Type *)v10;
}

// File Line: 136
// RVA: 0xE48CF0
void __fastcall hkDataClassNative::getDeclaredMemberInfo(hkDataClassNative *this, int i, hkDataClass_MemberInfo *info)
{
  hkDataClassNative *v3; // rdi
  hkDataClass_MemberInfo *v4; // rsi
  int v5; // ebx
  hkClassMember *v6; // rax

  v3 = this;
  v4 = info;
  v5 = i;
  v6 = hkClass::getDeclaredMember(this->m_class, i);
  hkDataClassNative::_fillMemberInfo((hkDataClassImpl *)&v3->vfptr, v3->m_world, v6, v4);
  v4->m_valuePtr = hkClass::getDeclaredDefault(v3->m_class, v5);
}

// File Line: 141
// RVA: 0xE48DA0
void __fastcall hkDataClassNative::getMemberInfo(hkDataClassNative *this, int i, hkDataClass_MemberInfo *info)
{
  hkDataClassNative *v3; // rdi
  hkDataClass_MemberInfo *v4; // rsi
  int v5; // ebx
  hkClassMember *v6; // rax

  v3 = this;
  v4 = info;
  v5 = i;
  v6 = hkClass::getMember(this->m_class, i);
  hkDataClassNative::_fillMemberInfo((hkDataClassImpl *)&v3->vfptr, v3->m_world, v6, v4);
  v4->m_valuePtr = hkClass::getDefault(v3->m_class, v5);
}

// File Line: 146
// RVA: 0xE48B80
void __fastcall hkDataClassNative::getAllMemberInfo(hkDataClassNative *this, hkArrayBase<hkDataClass_MemberInfo> *infos)
{
  hkClass *v2; // rbx
  hkDataClassNative *v3; // r15
  hkDataClass_MemberInfo *i; // r14
  int v5; // edi
  int v6; // ebp
  hkDataClass_MemberInfo *v7; // rsi
  hkClassMember *v8; // rax
  const char *v9; // rax

  v2 = this->m_class;
  v3 = this;
  for ( i = &infos->m_data[infos->m_size]; v2; v2 = hkClass::getParent(v2) )
  {
    v5 = 0;
    v6 = hkClass::getNumDeclaredMembers(v2);
    i -= v6;
    if ( v6 > 0 )
    {
      v7 = i;
      do
      {
        v8 = hkClass::getDeclaredMember(v2, v5);
        hkDataClassNative::_fillMemberInfo((hkDataClassImpl *)&v3->vfptr, v3->m_world, v8, v7);
        v9 = hkClass::getDeclaredDefault(v2, v5++);
        ++v7;
        v7[-1].m_valuePtr = v9;
      }
      while ( v5 < v6 );
    }
  }
}

// File Line: 169
// RVA: 0xE47EE0
void __fastcall hkDataClassNative::_getAllMemberHandles(hkDataClassNative *this, hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  hkClass *v2; // rsi
  const struct _hkDataObject_MemberHandle **i; // r14
  int v4; // ebx
  int v5; // ebp
  const struct _hkDataObject_MemberHandle **v6; // rdi
  hkClassMember *v7; // rax

  v2 = this->m_class;
  for ( i = &handles->m_data[handles->m_size]; v2; v2 = hkClass::getParent(v2) )
  {
    v4 = 0;
    v5 = hkClass::getNumDeclaredMembers(v2);
    i -= v5;
    if ( v5 > 0 )
    {
      v6 = i;
      do
      {
        v7 = hkClass::getMember(v2, v4++);
        ++v6;
        *(v6 - 1) = (const struct _hkDataObject_MemberHandle *)v7;
      }
      while ( v4 < v5 );
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
  this->m_address = hkVariantDataUtil::reserveArray(this->m_arrayObject, this->m_nativeType, this->m_class, n);
}

// File Line: 232
// RVA: 0xE495E0
void __fastcall hkDataArrayNative::setSize(hkDataArrayNative *this, int n)
{
  int size; // edi
  hkDataArrayNative *v3; // rbx

  size = n;
  v3 = this;
  if ( n != ((unsigned int (*)(void))this->vfptr[5].__vecDelDtor)() )
    v3->m_address = hkVariantDataUtil::setArraySize(
                      v3->m_world->m_infoReg.m_pntr,
                      v3->m_arrayObject,
                      v3->m_nativeType,
                      v3->m_class,
                      size);
}

// File Line: 240
// RVA: 0xE48F00
__int64 __fastcall hkDataArrayNative::getSize(hkDataArrayNative *this)
{
  __int64 result; // rax

  if ( this->m_arrayObject )
    result = hkVariantDataUtil::getArraySize(this->m_arrayObject);
  else
    result = (unsigned int)this->m_arraySize;
  return result;
}

// File Line: 251
// RVA: 0xE48F30
signed __int64 __fastcall hkDataArrayNative::getUnderlyingIntegerSize(hkDataArrayNative *this)
{
  signed __int64 result; // rax

  result = 8i64;
  if ( (unsigned int)(this->m_nativeType - 9) > 1 )
    result = 4i64;
  return result;
}

// File Line: 263
// RVA: 0xE48C40
hkDataClassImpl *__fastcall hkDataArrayNative::getClass(hkDataArrayNative *this)
{
  hkDataArrayNative *v1; // rdi
  hkClass *v2; // rcx
  hkBaseObjectVtbl *v3; // rbx
  const char *v4; // rax

  v1 = this;
  v2 = this->m_class;
  if ( !v2 )
    return 0i64;
  v3 = v1->m_world->vfptr;
  v4 = hkClass::getName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))v3[4].__first_virtual_table_function__)(
                              v1->m_world,
                              v4);
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
void __fastcall hkDataArrayNative::asReal(hkDataArrayNative *this, int index)
{
  hkVariantDataUtil::getReal(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride);
}

// File Line: 283
// RVA: 0xE48450
__int64 __fastcall hkDataArrayNative::asInt64(hkDataArrayNative *this, int index)
{
  return hkVariantDataUtil::getInt(
           this->m_nativeType,
           this->m_nativeSubType,
           (char *)this->m_address + index * this->m_elementStride);
}

// File Line: 287
// RVA: 0xE484C0
hkClassAccessor *__fastcall hkDataArrayNative::asObject(hkDataArrayNative *this, int index)
{
  hkDataArrayNative *v2; // rbx
  hkVariant *v3; // rax
  hkClass *v4; // rdx
  hkClassAccessor *v5; // rax
  hkVariant v; // [rsp+30h] [rbp-28h]
  hkVariant result; // [rsp+40h] [rbp-18h]

  v2 = this;
  v3 = hkVariantDataUtil::getObject(
         &result,
         this->m_nativeType,
         this->m_class,
         this->m_world->m_vtable.m_pntr,
         this->m_world->m_reg.m_pntr,
         (char *)this->m_address + index * this->m_elementStride);
  v.m_object = v3->m_object;
  v4 = v3->m_class;
  v.m_class = v3->m_class;
  if ( v.m_object && v4 )
    v5 = hkNativeDataObjectImplCreate(&v, v2->m_world, 0);
  else
    v5 = 0i64;
  return v5;
}

// File Line: 293
// RVA: 0xE47FF0
hkDataArrayImpl *__fastcall hkDataArrayNative::asArray(hkDataArrayNative *this, int index)
{
  hkDataArrayNative *v2; // rbx
  char *v3; // rsi
  hkClassMember::Type v4; // ecx
  int v5; // ebp
  _QWORD **v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  hkDataWorldNative *v9; // rcx
  hkClass *v10; // r9
  hkClassMember::Type v11; // er8
  hkClassMember::Type v12; // edx
  int v13; // er10
  int v15; // ebp
  _QWORD **v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdi
  __int64 v19; // r8
  hkDataWorldNative *v20; // rcx
  hkClass *v21; // r9
  __int64 v22; // rdx
  int v23; // er10

  v2 = this;
  v3 = (char *)this->m_address + index * this->m_elementStride;
  if ( this->m_tupleCount )
  {
    v4 = this->m_nativeType;
    if ( v4 == 25 )
      v5 = hkClass::getObjectSize(v2->m_class);
    else
      v5 = hkClassMember::getClassMemberTypeProperties(v4)->m_size;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 80i64);
    v8 = v7;
    if ( v7 )
    {
      v9 = v2->m_world;
      v10 = v2->m_class;
      v11 = v2->m_nativeSubType;
      v12 = v2->m_nativeType;
      v13 = v2->m_tupleCount;
      *(_QWORD *)(v7 + 8) = 0xFFFFi64;
      *(_QWORD *)(v7 + 16) = v9;
      *(_QWORD *)(v7 + 24) = v3;
      *(_DWORD *)(v7 + 32) = v13;
      *(_DWORD *)(v7 + 36) = v5;
      *(_DWORD *)(v7 + 40) = v12;
      *(_QWORD *)v7 = &hkDataArrayNative::`vftable;
      *(_DWORD *)(v7 + 44) = v11;
      *(_QWORD *)(v7 + 48) = v10;
      *(_DWORD *)(v7 + 64) = 0;
      *(_QWORD *)(v7 + 72) = 0i64;
      *(_QWORD *)(v7 + 56) = ((__int64 (__cdecl *)(hkDataWorldNative *))v9->vfptr[12].__vecDelDtor)(v9);
      return (hkDataArrayImpl *)v8;
    }
    return 0i64;
  }
  if ( this->m_nativeType != 22 )
    return 0i64;
  v15 = hkVariantDataUtil::calcElementSize(this->m_nativeSubType, 0, this->m_class, 0);
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 80i64);
  v18 = v17;
  if ( !v17 )
    return 0i64;
  v19 = *(_QWORD *)v3;
  v20 = v2->m_world;
  v21 = v2->m_class;
  v22 = (unsigned int)v2->m_nativeSubType;
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
  hkDataArrayNative *v2; // rbp
  hkClassMember *v3; // rax
  unsigned int v4; // er12
  hkClassMember *v5; // r14
  char *v6; // r15
  _QWORD **v7; // rax
  hkDataArrayImpl *result; // rax
  hkDataArrayImpl *v9; // rsi
  unsigned int v10; // edi
  int v11; // ebx
  hkClass *v12; // rax
  hkDataRefCountedVtbl *v13; // rcx
  int v14; // er10
  int v15; // ST20_4

  v2 = this;
  v3 = hkClass::getMemberByName(this->m_class, name);
  v4 = (unsigned __int8)v3->m_type.m_storage;
  v5 = v3;
  v6 = (char *)v2->m_address + v3->m_offset;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkDataArrayImpl *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 80i64);
  v9 = result;
  if ( result )
  {
    v10 = (unsigned __int8)v5->m_subtype.m_storage;
    v11 = hkClassMember::getCstyleArraySize(v5);
    v12 = hkClassMember::getClass(v5);
    v13 = (hkDataRefCountedVtbl *)v2->m_world;
    v14 = v2->m_elementStride;
    LODWORD(v9[2].vfptr) = v2->m_arraySize;
    v9->vfptr = (hkDataRefCountedVtbl *)&hkDataArrayNative::`vftable;
    *(_QWORD *)&v9->m_memSize = 0xFFFFi64;
    v9[1].vfptr = v13;
    *(_QWORD *)&v9[4].m_memSize = 0i64;
    *(_QWORD *)&v9[1].m_memSize = v6;
    HIDWORD(v9[2].vfptr) = v14;
    *(_DWORD *)&v9[2].m_memSize = v4;
    v9[2].m_count = v10;
    v9[3].vfptr = (hkDataRefCountedVtbl *)v12;
    LODWORD(v9[4].vfptr) = v11;
    v15 = v11;
    *(_QWORD *)&v9[3].m_memSize = (*((__int64 (__fastcall **)(hkDataRefCountedVtbl *, _QWORD, _QWORD, hkClass *, int))v13->__vecDelDtor
                                   + 24))(
                                    v13,
                                    v4,
                                    v10,
                                    v12,
                                    v15);
    result = v9;
  }
  return result;
}

// File Line: 329
// RVA: 0xE48660
hkResult *__fastcall hkDataArrayNative::asStridedBasicArray(hkDataArrayNative *this, hkResult *result, hkStridedBasicArray *arrOut)
{
  hkStridedBasicArray *v3; // rbx
  hkResult *v4; // rsi
  hkDataArrayNative *v5; // rdi
  hkClassMember::Type v6; // eax
  int v7; // eax

  arrOut->m_tupleSize = 1;
  v3 = arrOut;
  arrOut->m_type = this->m_nativeType;
  v4 = result;
  v5 = this;
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
      arrOut->m_type = 11;
      break;
    case 0x18:
    case 0x1F:
      v6 = this->m_nativeSubType;
      arrOut->m_tupleSize = 1;
      arrOut->m_type = v6;
      break;
    default:
      break;
  }
  v7 = ((__int64 (*)(void))this->vfptr[5].__vecDelDtor)();
  v4->m_enum = 0;
  v3->m_size = v7;
  v3->m_stride = v5->m_elementStride;
  v3->m_data = v5->m_address;
  return v4;
}

// File Line: 397
// RVA: 0xE493E0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, hkBool *v, int n)
{
  int v3; // edi
  hkBool *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 1 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_REPORT_CONTACT_MGR);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 398
// RVA: 0xE49120
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, int n)
{
  int v3; // edi
  const char *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 2 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 399
// RVA: 0xE490C0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, int n)
{
  int v3; // edi
  const char *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 3 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_NULL_CONTACT_MGR);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 400
// RVA: 0xE49180
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const char *v, int n)
{
  hkClassMember::Type v3; // eax
  int v4; // esi
  const char *v5; // rbp
  hkDataArrayNative *v6; // rdi
  hkClassMember::Type v7; // ebx
  hkClassMember::TypeProperties *v8; // rax

  v3 = this->m_nativeType;
  v4 = n;
  v5 = v;
  v6 = this;
  v7 = 4;
  if ( v3 == 1 )
  {
    v7 = 1;
  }
  else if ( v3 == 2 )
  {
    v7 = 2;
  }
  if ( v7 == v3 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v8 = hkClassMember::getClassMemberTypeProperties(v7);
    hkString::memCpy(v6->m_address, v5, v4 * v8->m_size);
  }
}

// File Line: 401
// RVA: 0xE49200
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const __int16 *v, int n)
{
  int v3; // edi
  const __int16 *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 5 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_MAX);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 402
// RVA: 0xE49260
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned __int16 *v, int n)
{
  int v3; // edi
  const unsigned __int16 *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 6 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_USER_CONTACT_MGR|TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 403
// RVA: 0xE492C0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const int *v, int n)
{
  int v3; // edi
  const int *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 7 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_MAX|TYPE_CONVEX_LIST_CONTACT_MGR);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 404
// RVA: 0xE49320
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned int *v, int n)
{
  int v3; // edi
  const unsigned int *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 8 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)8);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 405
// RVA: 0xE494A0
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const __int64 *v, int n)
{
  int v3; // edi
  const __int64 *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 9 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)9);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 406
// RVA: 0xE49500
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const unsigned __int64 *v, int n)
{
  int v3; // edi
  const unsigned __int64 *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 10 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)10);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 407
// RVA: 0xE49380
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, const float *v, int n)
{
  int v3; // edi
  const float *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 11 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties(TYPE_NULL_CONTACT_MGR|0x8);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
  }
}

// File Line: 408
// RVA: 0xE49440
void __fastcall hkDataArrayNative::setAll(hkDataArrayNative *this, hkHalf *v, int n)
{
  int v3; // edi
  hkHalf *v4; // rsi
  hkDataArrayNative *v5; // rbx
  hkClassMember::TypeProperties *v6; // rax

  v3 = n;
  v4 = v;
  v5 = this;
  if ( this->m_nativeType == 32 )
  {
    this->vfptr[4].__vecDelDtor((hkDataRefCounted *)this, n);
    v6 = hkClassMember::getClassMemberTypeProperties((hkClassMember::Type)32);
    hkString::memCpy(v5->m_address, v4, v3 * v6->m_size);
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
  hkVariantDataUtil::setString(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 412
// RVA: 0xE495C0
void __fastcall hkDataArrayNative::setReal(hkDataArrayNative *this, int index, float val)
{
  hkVariantDataUtil::setReal(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 413
// RVA: 0xE49560
void __fastcall hkDataArrayNative::setHalf(hkDataArrayNative *this, int index, hkHalf val)
{
  hkVariantDataUtil::setHalf(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 414
// RVA: 0xE495A0
void __fastcall hkDataArrayNative::setInt(hkDataArrayNative *this, int index, int val)
{
  hkVariantDataUtil::setInt(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 415
// RVA: 0xE49580
void __fastcall hkDataArrayNative::setInt64(hkDataArrayNative *this, int index, __int64 val)
{
  hkVariantDataUtil::setInt(this->m_nativeType, (char *)this->m_address + index * this->m_elementStride, val);
}

// File Line: 461
// RVA: 0xE47C00
void __fastcall hkDataObjectNative::hkDataObjectNative(hkDataObjectNative *this, hkDataObject_Handle *h, hkDataWorldNative *world)
{
  hkDataWorldNative *v3; // rsi
  hkClass *v4; // rax
  hkDataObject_Handle *v5; // rdi
  hkDataObjectNative *v6; // rbx

  *(_QWORD *)&this->m_memSize = 0xFFFFi64;
  v3 = world;
  this->vfptr = (hkDataRefCountedVtbl *)&hkDataObjectNative::`vftable;
  v4 = (hkClass *)h->p1;
  v5 = h;
  v6 = this;
  if ( !v4 )
    v4 = (hkClass *)((__int64 (__fastcall *)(hkVtableClassRegistry *, void *))world->m_vtable.m_pntr->vfptr[2].__first_virtual_table_function__)(
                      world->m_vtable.m_pntr,
                      h->p0);
  hkClassAccessor::hkClassAccessor(&v6->m_object, v5->p0, v4);
  v6->m_world = v3;
  v6->m_hasOwnedRef.m_bool = 0;
}

// File Line: 475
// RVA: 0xE48D50
hkDataObject_Handle *__fastcall hkDataObjectNative::getHandle(hkDataObjectNative *this, hkDataObject_Handle *result)
{
  hkClass *v2; // rbx
  hkDataObject_Handle *v3; // rdi
  bool v4; // zf
  hkDataObject_Handle *v5; // rax
  hkBool resulta; // [rsp+30h] [rbp+8h]

  v2 = this->m_object.m_variant.m_class;
  v3 = result;
  result->p0 = this->m_object.m_variant.m_object;
  v4 = hkClass::hasVtable(v2, &resulta)->m_bool == 0;
  v5 = v3;
  if ( !v4 )
    v2 = 0i64;
  v3->p1 = v2;
  return v5;
}

// File Line: 488
// RVA: 0xE48C90
hkDataClassImpl *__fastcall hkDataObjectNative::getClass(hkDataObjectNative *this)
{
  hkDataObjectNative *v1; // rdi
  hkClass *v2; // rcx
  hkBaseObjectVtbl *v3; // rbx
  const char *v4; // rax

  v1 = this;
  v2 = this->m_object.m_variant.m_class;
  if ( !v2 )
    return 0i64;
  v3 = v1->m_world->vfptr;
  v4 = hkClass::getName(v2);
  return (hkDataClassImpl *)((__int64 (__fastcall *)(hkDataWorldNative *, const char *))v3[4].__first_virtual_table_function__)(
                              v1->m_world,
                              v4);
}

// File Line: 493
// RVA: 0xE47F80
hkDataObject_Value *__fastcall hkDataObjectNative::accessByName(hkDataObjectNative *this, hkDataObject_Value *result, const char *name)
{
  hkDataObject_Value *v3; // rbx
  hkDataObjectNative *v4; // rdi
  hkClassMember *v5; // rax
  hkClassMemberAccessor v7; // [rsp+20h] [rbp-18h]
  hkBool resulta; // [rsp+40h] [rbp+8h]

  v3 = result;
  v4 = this;
  hkClassMemberAccessor::hkClassMemberAccessor(&v7, &this->m_object.m_variant, name);
  if ( hkClassMemberAccessor::isOk(&v7, &resulta)->m_bool )
  {
    v5 = hkClassMemberAccessor::getClassMember(&v7);
    v3->m_impl = (hkDataObjectImpl *)&v4->vfptr;
    v3->m_handle = (const struct _hkDataObject_MemberHandle *)v5;
  }
  else
  {
    v3->m_impl = 0i64;
    v3->m_handle = 0i64;
  }
  return v3;
}

// File Line: 505
// RVA: 0xE48F70
_BOOL8 __fastcall hkDataObjectNative::hasMember(hkDataObjectNative *this, const char *name)
{
  hkClassMemberAccessor v3; // [rsp+20h] [rbp-18h]
  hkBool result; // [rsp+40h] [rbp+8h]

  hkClassMemberAccessor::hkClassMemberAccessor(&v3, &this->m_object.m_variant, name);
  return hkClassMemberAccessor::isOk(&v3, &result)->m_bool != 0;
}

// File Line: 511
// RVA: 0xE48FB0
_BOOL8 __fastcall hkDataObjectNative::isSet(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkClassMemberAccessor v3; // [rsp+20h] [rbp-18h]
  hkBool result; // [rsp+40h] [rbp+8h]

  hkClassMemberAccessor::hkClassMemberAccessor(&v3, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  return hkClassMemberAccessor::isOk(&v3, &result)->m_bool != 0;
}

// File Line: 521
// RVA: 0xE49070
_BOOL8 __fastcall hkDataObjectNative::isValid(hkDataObjectNative *this, int it)
{
  return it < (signed int)hkClass::getNumMembers(this->m_object.m_variant.m_class);
}

// File Line: 529
// RVA: 0xE48E20
const char *__fastcall hkDataObjectNative::getMemberName(hkDataObjectNative *this, int it)
{
  return hkClass::getMember(this->m_object.m_variant.m_class, it)->m_name;
}

// File Line: 533
// RVA: 0xE48E40
hkDataObject_Value *__fastcall hkDataObjectNative::getMemberValue(hkDataObjectNative *this, hkDataObject_Value *result, int it)
{
  hkDataObjectNative *v3; // rbx
  hkDataObject_Value *v4; // rdi
  hkClassMember *v5; // rax

  v3 = this;
  v4 = result;
  v5 = hkClass::getMember(this->m_object.m_variant.m_class, it);
  v4->m_impl = (hkDataObjectImpl *)&v3->vfptr;
  v4->m_handle = (const struct _hkDataObject_MemberHandle *)v5;
  return v4;
}

// File Line: 539
// RVA: 0xE48B60
void __fastcall hkDataObjectNative::getAllMemberHandles(hkDataObjectNative *this, hkArrayBase<_hkDataObject_MemberHandle const *> *handles)
{
  hkArrayBase<_hkDataObject_MemberHandle const *> *v2; // rbx
  hkDataClassNative *v3; // rax

  v2 = handles;
  v3 = (hkDataClassNative *)((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
  hkDataClassNative::_getAllMemberHandles(v3, v2);
}

// File Line: 548
// RVA: 0xE48190
hkDataArrayImpl *__fastcall hkDataObjectNative::asArray(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkClassMember *v2; // rbx
  hkDataObjectNative *v3; // r13
  _DWORD *v4; // r15
  _QWORD *v5; // rax
  char *v6; // rbp
  int v7; // er12
  hkClass **v8; // rax
  hkClass *v9; // rsi
  hkClassMember::Type v10; // edi
  int v11; // ebx
  hkClass *v12; // rax
  _QWORD **v13; // rax
  __int64 v14; // rax
  hkDataArrayImpl *v15; // rbx
  hkDataWorldNative *v16; // rcx
  hkDataArrayImpl *result; // rax
  unsigned __int16 *v18; // rax
  hkClassMember *v19; // rax
  int v20; // eax
  hkClass *v21; // rax
  _QWORD **v22; // rax
  __int64 v23; // rax
  hkDataArrayImpl *v24; // r14
  hkDataWorldNative *v25; // rcx
  hkClassMemberAccessor v26; // [rsp+30h] [rbp-38h]

  v2 = (hkClassMember *)handle;
  v3 = this;
  hkClassMemberAccessor::hkClassMemberAccessor(&v26, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v4 = 0i64;
  switch ( v2->m_type.m_storage )
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
      v6 = (char *)hkClassMemberAccessor::getAddress(&v26);
      v19 = hkClassMemberAccessor::getClassMember(&v26);
      v20 = hkClassMember::getCstyleArraySize(v19);
      v10 = (unsigned __int8)v2->m_type.m_storage;
      v7 = v20;
      v21 = hkClassMember::getClass(v2);
      v9 = v21;
      if ( v10 == 25 )
        v11 = hkClass::getObjectSize(v21);
      else
        v11 = hkClassMember::getClassMemberTypeProperties(v10)->m_size;
      goto LABEL_17;
    case 0x16:
    case 0x1A:
      v4 = hkClassMemberAccessor::getAddress(&v26);
      v6 = *(char **)v4;
      v7 = v4[2];
      goto LABEL_5;
    case 0x1B:
      v5 = hkClassMemberAccessor::getAddress(&v26);
      v6 = (char *)v5[1];
      v7 = *((_DWORD *)v5 + 4);
      v4 = v5 + 1;
      v8 = (hkClass **)hkClassMemberAccessor::getAddress(&v26);
      v9 = *v8;
      if ( !*v8 )
        goto LABEL_16;
      v10 = 25;
      v11 = hkClass::getObjectSize(*v8);
      goto LABEL_17;
    case 0x22:
      v18 = (unsigned __int16 *)hkClassMemberAccessor::getAddress(&v26);
      v7 = *v18;
      v6 = (char *)v18 + v18[1];
LABEL_5:
      v12 = hkClassMember::getClass(v2);
      v10 = (unsigned __int8)v2->m_subtype.m_storage;
      v9 = v12;
      v11 = hkClassMember::getClassMemberTypeProperties(v10)->m_size;
      if ( v10 )
      {
        if ( v11 == -1 )
          v11 = hkClass::getObjectSize(v9);
LABEL_17:
        v22 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v23 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v22[11] + 8i64))(v22[11], 80i64);
        v24 = (hkDataArrayImpl *)v23;
        if ( v23 )
        {
          v25 = v3->m_world;
          *(_QWORD *)(v23 + 8) = 0xFFFFi64;
          *(_DWORD *)(v23 + 44) = 0;
          *(_DWORD *)(v23 + 64) = 0;
          *(_QWORD *)(v23 + 24) = v6;
          *(_QWORD *)(v23 + 16) = v25;
          *(_DWORD *)(v23 + 32) = v7;
          *(_DWORD *)(v23 + 36) = v11;
          *(_QWORD *)v23 = &hkDataArrayNative::`vftable;
          *(_DWORD *)(v23 + 40) = v10;
          *(_QWORD *)(v23 + 48) = v9;
          *(_QWORD *)(v23 + 72) = v4;
          *(_QWORD *)(v23 + 56) = ((__int64 (__fastcall *)(hkDataWorldNative *, _QWORD, _QWORD, hkClass *, _DWORD))v25->vfptr[12].__vecDelDtor)(
                                    v25,
                                    (unsigned int)v10,
                                    0i64,
                                    v9,
                                    0);
        }
        else
        {
          v24 = 0i64;
        }
        result = v24;
      }
      else
      {
        v13 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v14 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v13[11] + 8i64))(v13[11], 80i64);
        v15 = (hkDataArrayImpl *)v14;
        if ( v14 )
        {
          v16 = v3->m_world;
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
          result = v15;
        }
        else
        {
          result = 0i64;
        }
      }
      return result;
    default:
      v6 = 0i64;
      v7 = 0;
      v9 = 0i64;
LABEL_16:
      v11 = 0;
      v10 = 0;
      goto LABEL_17;
  }
}

// File Line: 672
// RVA: 0xE48760
const char *__fastcall hkDataObjectNative::asString(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  const struct _hkDataObject_MemberHandle *v2; // rbx
  const void *v3; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h]

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  LODWORD(v2) = *((unsigned __int8 *)v2 + 24);
  v3 = hkClassMemberAccessor::getAddress(&v5);
  return hkVariantDataUtil::getString((hkClassMember::Type)v2, v3);
}

// File Line: 678
// RVA: 0xE48470
__int64 __fastcall hkDataObjectNative::asInt(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  const struct _hkDataObject_MemberHandle *v2; // rdi
  hkClassMember::Type v3; // ebx
  const void *v4; // rax
  hkClassMemberAccessor v6; // [rsp+20h] [rbp-18h]

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v6, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v3 = *((unsigned __int8 *)v2 + 25);
  LODWORD(v2) = *((unsigned __int8 *)v2 + 24);
  v4 = hkClassMemberAccessor::getAddress(&v6);
  return hkVariantDataUtil::getInt((hkClassMember::Type)v2, v3, v4);
}

// File Line: 684
// RVA: 0xE48540
hkClassAccessor *__fastcall hkDataObjectNative::asObject(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  hkClassMember *v2; // r14
  hkDataObjectNative *v3; // r15
  hkDataWorldNative *v4; // rax
  hkClassMember::Type v5; // ebp
  hkClassNameRegistry *classReg; // rdi
  hkVtableClassRegistry *v7; // rsi
  const void *data; // rbx
  hkClass *v9; // rax
  hkVariant *v10; // rax
  hkClass *v11; // rdx
  hkClassAccessor *v12; // rax
  hkVariant v; // [rsp+30h] [rbp-48h]
  hkClassMemberAccessor v14; // [rsp+40h] [rbp-38h]
  hkVariant result; // [rsp+50h] [rbp-28h]

  v2 = (hkClassMember *)handle;
  v3 = this;
  hkClassMemberAccessor::hkClassMemberAccessor(&v14, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v4 = v3->m_world;
  v5 = (unsigned __int8)v2->m_type.m_storage;
  classReg = v4->m_reg.m_pntr;
  v7 = v4->m_vtable.m_pntr;
  data = hkClassMemberAccessor::asRaw(&v14);
  v9 = hkClassMember::getClass(v2);
  v10 = hkVariantDataUtil::getObject(&result, v5, v9, v7, classReg, data);
  v.m_object = v10->m_object;
  v11 = v10->m_class;
  v.m_class = v10->m_class;
  if ( v.m_object && v11 )
    v12 = hkNativeDataObjectImplCreate(&v, v3->m_world, 0);
  else
    v12 = 0i64;
  return v12;
}

// File Line: 691
// RVA: 0xE487D0
const float *__fastcall hkDataObjectNative::asVec(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, int nreal)
{
  hkClassMember *v3; // rbp
  hkDataObjectNative *v4; // rbx
  hkClassMember::Type v5; // esi
  hkDataWorldNative *v6; // rdi
  const void *v7; // rbx
  int v8; // eax
  hkClassMemberAccessor v10; // [rsp+20h] [rbp-18h]

  v3 = (hkClassMember *)handle;
  v4 = this;
  hkClassMemberAccessor::hkClassMemberAccessor(&v10, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v5 = (unsigned __int8)v3->m_type.m_storage;
  v6 = v4->m_world;
  v7 = hkClassMemberAccessor::getAddress(&v10);
  v8 = hkClassMember::getCstyleArraySize(v3);
  return hkVariantDataUtil::getReals(v5, v8, v7, &v6->m_buffer);
}

// File Line: 697
// RVA: 0xE48620
float __fastcall hkDataObjectNative::asReal(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle)
{
  const struct _hkDataObject_MemberHandle *v2; // rbx
  const void *v3; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h]

  v2 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  LODWORD(v2) = *((unsigned __int8 *)v2 + 24);
  v3 = hkClassMemberAccessor::getAddress(&v5);
  return hkVariantDataUtil::getReal((hkClassMember::Type)v2, v3);
}

// File Line: 703
// RVA: 0xE48840
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, hkDataObject_Value *valueIn)
{
  hkDataObjectImpl::assignValueImpl((hkDataObjectImpl *)&this->vfptr, handle, valueIn);
}

// File Line: 707
// RVA: 0xE48910
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, hkDataObjectImpl *val)
{
  hkDataObjectImpl *v3; // rbp
  hkClassMember *v4; // rdi
  hkBool v5; // si
  hkDataRefCountedVtbl *v6; // rbx
  hkClass *v7; // rdi
  void **v8; // rax
  hkDataRefCountedVtbl *v9; // rdx
  hkClass *v10; // rcx
  void **v11; // r8
  void **v12; // rbx
  hkClass *v13; // rax
  hkClassMemberAccessor v14; // [rsp+20h] [rbp-18h]

  v3 = val;
  v4 = (hkClassMember *)handle;
  v5.m_bool = ~(unsigned __int8)(*((_WORD *)handle + 14) >> 9) & 1;
  hkClassMemberAccessor::hkClassMemberAccessor(&v14, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  if ( v3 )
  {
    v6 = v3[1].vfptr;
    v7 = *(hkClass **)&v3[1].m_memSize;
    v8 = (void **)hkClassMemberAccessor::getAddress(&v14);
    v9 = v6;
    v10 = v7;
    v11 = v8;
  }
  else
  {
    if ( !hkClassMember::getClass(v4) )
      return;
    v12 = (void **)hkClassMemberAccessor::getAddress(&v14);
    v13 = hkClassMember::getClass(v4);
    v11 = v12;
    v10 = v13;
    v9 = 0i64;
  }
  hkVariantDataUtil::setPointer(v10, v9, v11, v5);
}

// File Line: 739
// RVA: 0xE489C0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, const char *value)
{
  const char *v3; // rdi
  const struct _hkDataObject_MemberHandle *v4; // rbx
  void *v5; // rax
  hkClassMemberAccessor v6; // [rsp+20h] [rbp-18h]

  v3 = value;
  v4 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v6, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  LODWORD(v4) = *((unsigned __int8 *)v4 + 24);
  v5 = hkClassMemberAccessor::getAddress(&v6);
  hkVariantDataUtil::setString((hkClassMember::Type)v4, v5, v3);
}

// File Line: 745
// RVA: 0xE488C0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, float r)
{
  const struct _hkDataObject_MemberHandle *v3; // rbx
  void *v4; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-28h]

  v3 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  LODWORD(v3) = *((unsigned __int8 *)v3 + 24);
  v4 = hkClassMemberAccessor::getAddress(&v5);
  hkVariantDataUtil::setReal((hkClassMember::Type)v3, v4, r);
}

// File Line: 751
// RVA: 0xE48A90
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, hkHalf r)
{
  const struct _hkDataObject_MemberHandle *v3; // rbx
  void *v4; // rax
  hkClassMemberAccessor v5; // [rsp+20h] [rbp-18h]
  __int16 v6; // [rsp+50h] [rbp+18h]

  v6 = r.m_value;
  v3 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v5, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  LODWORD(v3) = *((unsigned __int8 *)v3 + 24);
  v4 = hkClassMemberAccessor::getAddress(&v5);
  hkVariantDataUtil::setReal((hkClassMember::Type)v3, v4, COERCE_FLOAT(v6 << 16));
}

// File Line: 757
// RVA: 0xE48A10
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, const float *r, int nreal)
{
  const float *v4; // r14
  hkClassMember *v5; // rsi
  int numRealsIn; // ebp
  hkClassMember::Type v7; // edi
  void *v8; // rbx
  int v9; // eax
  hkClassMemberAccessor v10; // [rsp+30h] [rbp-18h]

  v4 = r;
  v5 = (hkClassMember *)handle;
  numRealsIn = nreal;
  hkClassMemberAccessor::hkClassMemberAccessor(&v10, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v7 = (unsigned __int8)v5->m_type.m_storage;
  v8 = hkClassMemberAccessor::getAddress(&v10);
  v9 = hkClassMember::getCstyleArraySize(v5);
  hkVariantDataUtil::setReals(v7, v9, v4, v8, numRealsIn);
}

// File Line: 763
// RVA: 0xE48AE0
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, __int64 valueIn)
{
  __int64 v3; // rsi
  const struct _hkDataObject_MemberHandle *v4; // rdi
  hkClassMember::Type v5; // ebx
  void *v6; // rax
  hkClassMemberAccessor v7; // [rsp+20h] [rbp-18h]

  v3 = valueIn;
  v4 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v7, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v5 = *((unsigned __int8 *)v4 + 25);
  LODWORD(v4) = *((unsigned __int8 *)v4 + 24);
  v6 = hkClassMemberAccessor::getAddress(&v7);
  hkVariantDataUtil::setInt((hkClassMember::Type)v4, v5, v6, v3);
}

// File Line: 769
// RVA: 0xE48850
void __fastcall hkDataObjectNative::assign(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, int valueIn)
{
  __int64 v3; // rbp
  const struct _hkDataObject_MemberHandle *v4; // rbx
  hkClassMember::Type v5; // edi
  hkClassMember::Type v6; // esi
  void *v7; // rax
  hkClassMemberAccessor v8; // [rsp+20h] [rbp-18h]

  v3 = valueIn;
  v4 = handle;
  hkClassMemberAccessor::hkClassMemberAccessor(&v8, this->m_object.m_variant.m_object, (hkClassMember *)handle);
  v5 = *((unsigned __int8 *)v4 + 25);
  v6 = *((unsigned __int8 *)v4 + 24);
  v7 = hkClassMemberAccessor::getAddress(&v8);
  hkVariantDataUtil::setInt(v6, v5, v7, v3);
}

// File Line: 775
// RVA: 0xE48E00
void __fastcall hkDataObjectNative::getMemberInfo(hkDataObjectNative *this, const struct _hkDataObject_MemberHandle *handle, hkDataClass_MemberInfo *infoOut)
{
  hkDataClassNative::_fillMemberInfo(0i64, this->m_world, (hkClassMember *)handle, infoOut);
}

// File Line: 791
// RVA: 0xE47A70
hkClassAccessor *__fastcall hkNativeDataObjectImplCreate(hkVariant *v, hkDataWorldNative *w, hkBool isRefOwned)
{
  hkVariant *v3; // rdi
  hkClass *v4; // rcx
  hkDataWorldNative *v5; // rsi
  hkBaseObjectVtbl *v6; // rbx
  const char *v7; // rax
  __int64 v8; // rax
  const char *v9; // rbx
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  _QWORD **v14; // rax
  hkClassAccessor *v15; // rax
  hkClassAccessor *v16; // rbx
  hkErrStream v18; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]
  char v20; // [rsp+260h] [rbp+18h]

  v20 = isRefOwned.m_bool;
  v3 = v;
  v4 = v->m_class;
  v5 = w;
  if ( v4 )
  {
    v6 = w->vfptr;
    v7 = hkClass::getName(v4);
    v8 = ((__int64 (__fastcall *)(hkDataWorldNative *, const char *))v6[4].__first_virtual_table_function__)(v5, v7);
    if ( v8 )
    {
      v3->m_class = *(hkClass **)(v8 + 16);
    }
    else
    {
      hkErrStream::hkErrStream(&v18, &buf, 512);
      v9 = hkClass::getName(v3->m_class);
      v10 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "Ignore object at 0x");
      v11 = hkOstream::operator<<(v10, v3->m_object, (int)v10);
      v12 = hkOstream::operator<<(v11, ". Class ");
      v13 = hkOstream::operator<<(v12, v9);
      hkOstream::operator<<(v13, " is not registered in the provided hkDataWorldNative.");
      hkError::messageWarning(402671418, &buf, "Data\\Native\\hkDataObjectNative.cpp", 800);
      hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
      v3->m_object = 0i64;
      v3->m_class = 0i64;
    }
  }
  v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v15 = (hkClassAccessor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 48i64);
  v16 = v15;
  if ( !v15 )
    return 0i64;
  v15->m_variant.m_class = (hkClass *)0xFFFF;
  v15->m_variant.m_object = &hkDataObjectNative::`vftable;
  hkClassAccessor::hkClassAccessor(v15 + 1, v3);
  v16[2].m_variant.m_object = v5;
  LOBYTE(v16[2].m_variant.m_class) = v20;
  return v16;
}

// File Line: 816
// RVA: 0xE47BD0
void __fastcall hkDataArrayNative::setObject(hkDataArrayNative *this, int index, hkDataObjectImpl *val)
{
  if ( this->m_nativeType != 25 )
    hkVariantDataUtil::setPointer(
      *(hkClass **)&val[1].m_memSize,
      val[1].vfptr,
      (void **)((char *)this->m_address + index * this->m_elementStride),
      (hkBool)1);
}

// File Line: 842
// RVA: 0xE472B0
void __fastcall hkDataWorldNative::hkDataWorldNative(hkDataWorldNative *this, hkBool accessSerializeIgnored)
{
  hkDataWorldNative *v2; // rbx
  hkReferencedObject *v3; // rax
  hkVtableClassRegistry *v4; // rdi
  hkReferencedObject *v5; // rcx
  hkReferencedObject *v6; // rax
  hkClassNameRegistry *v7; // rdi
  hkReferencedObject *v8; // rcx
  hkReferencedObject *v9; // rax
  hkTypeInfoRegistry *v10; // rdi
  hkReferencedObject *v11; // rcx
  char v12; // [rsp+38h] [rbp+10h]

  v12 = accessSerializeIgnored.m_bool;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkDataWorldNative::`vftable;
  this->m_reg.m_pntr = 0i64;
  this->m_vtable.m_pntr = 0i64;
  this->m_infoReg.m_pntr = 0i64;
  v2 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_classes.m_map,
    0);
  v2->m_accessSerializeIgnored.m_bool = v12;
  hkTypeManager::hkTypeManager(&v2->m_typeManager);
  v2->m_buffer.m_data = 0i64;
  v2->m_buffer.m_size = 0;
  v2->m_buffer.m_capacityAndFlags = 2147483648;
  v2->m_contents.m_class = 0i64;
  v2->m_contents.m_object = 0i64;
  v3 = (hkReferencedObject *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  v4 = (hkVtableClassRegistry *)v3;
  if ( v3 )
    hkReferencedObject::addReference(v3);
  v5 = (hkReferencedObject *)&v2->m_vtable.m_pntr->vfptr;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v2->m_vtable.m_pntr = v4;
  v6 = (hkReferencedObject *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__vecDelDtor)();
  v7 = (hkClassNameRegistry *)v6;
  if ( v6 )
    hkReferencedObject::addReference(v6);
  v8 = (hkReferencedObject *)&v2->m_reg.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v2->m_reg.m_pntr = v7;
  v9 = (hkReferencedObject *)((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)();
  v10 = (hkTypeInfoRegistry *)v9;
  if ( v9 )
    hkReferencedObject::addReference(v9);
  v11 = (hkReferencedObject *)&v2->m_infoReg.m_pntr->vfptr;
  if ( v11 )
    hkReferencedObject::removeReference(v11);
  v2->m_infoReg.m_pntr = v10;
}

// File Line: 851
// RVA: 0xE473C0
void __fastcall hkDataWorldNative::~hkDataWorldNative(hkDataWorldNative *this)
{
  hkDataWorldNative *v1; // rbx
  hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *v2; // rcx
  Dummy *v3; // rdi
  void (__fastcall ***v4)(_QWORD, signed __int64); // rax
  int v5; // er8
  hkReferencedObject *v6; // rcx
  hkReferencedObject *v7; // rcx
  hkReferencedObject *v8; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes;
  *(_QWORD *)&v2[-2].m_numElems = &hkDataWorldNative::`vftable;
  v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getIterator(v2);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
    (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_classes,
    &result,
    v3);
  while ( result.m_bool )
  {
    v4 = (void (__fastcall ***)(_QWORD, signed __int64))hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::getValue(
                                                          (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_classes,
                                                          v3);
    if ( v4 )
      (**v4)(v4, 1i64);
    v3 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getNext(
           (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_classes,
           v3);
    hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::isValid(
      (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&v1->m_classes,
      &result,
      v3);
  }
  v5 = v1->m_buffer.m_capacityAndFlags;
  v1->m_buffer.m_size = 0;
  if ( v5 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_buffer.m_data,
      v5 & 0x3FFFFFFF);
  v1->m_buffer.m_data = 0i64;
  v1->m_buffer.m_capacityAndFlags = 2147483648;
  hkTypeManager::~hkTypeManager(&v1->m_typeManager);
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::~hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(&v1->m_classes.m_map);
  v6 = (hkReferencedObject *)&v1->m_infoReg.m_pntr->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v1->m_infoReg.m_pntr = 0i64;
  v7 = (hkReferencedObject *)&v1->m_vtable.m_pntr->vfptr;
  if ( v7 )
    hkReferencedObject::removeReference(v7);
  v1->m_vtable.m_pntr = 0i64;
  v8 = (hkReferencedObject *)&v1->m_reg.m_pntr->vfptr;
  if ( v8 )
    hkReferencedObject::removeReference(v8);
  v1->m_reg.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 860
// RVA: 0xE47A60
hkTypeManager::Type *__fastcall hkDataWorldNative::getTypeFromMemberType(hkDataWorldNative *this, hkClassMember::Type mtype, hkClassMember::Type stype, hkClass *klass, int count)
{
  return hkDataObjectUtil::getTypeFromMemberType(&this->m_typeManager, mtype, stype, klass, count);
}

// File Line: 865
// RVA: 0xE479E0
void __fastcall hkDataWorldNative::setClassRegistry(hkDataWorldNative *this, hkClassNameRegistry *r)
{
  hkClassNameRegistry *v2; // rbx
  hkDataWorldNative *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = r;
  v3 = this;
  if ( r )
    hkReferencedObject::addReference((hkReferencedObject *)&r->vfptr);
  v4 = (hkReferencedObject *)&v3->m_reg.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_reg.m_pntr = v2;
}

// File Line: 870
// RVA: 0xE47A20
void __fastcall hkDataWorldNative::setVtableRegistry(hkDataWorldNative *this, hkVtableClassRegistry *vt)
{
  hkVtableClassRegistry *v2; // rbx
  hkDataWorldNative *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = vt;
  v3 = this;
  if ( vt )
    hkReferencedObject::addReference((hkReferencedObject *)&vt->vfptr);
  v4 = (hkReferencedObject *)&v3->m_vtable.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_vtable.m_pntr = v2;
}

// File Line: 875
// RVA: 0xE47920
hkDataObjectImpl *__fastcall hkDataWorldNative::wrapObject(hkDataWorldNative *this, void *object, hkClass *klass)
{
  hkVariant v; // [rsp+20h] [rbp-18h]

  v.m_object = object;
  v.m_class = klass;
  return hkNativeDataObjectImplCreate(&v, this, 0);
}

// File Line: 882
// RVA: 0xE47950
void __fastcall hkDataWorldNative::setContents(hkDataWorldNative *this, void *object, hkClass *klass)
{
  hkClassNameRegistry *v3; // rbx
  hkDataWorldNative *v4; // rbp
  hkBaseObjectVtbl *v5; // rdi
  hkClass *v6; // rsi
  void *v7; // r14
  const char *v8; // rax
  __int64 v9; // rbx
  hkBool result; // [rsp+40h] [rbp+8h]

  v3 = this->m_reg.m_pntr;
  this->m_contents.m_object = object;
  v4 = this;
  v5 = v3->vfptr;
  v6 = klass;
  v7 = object;
  v8 = hkClass::getName(klass);
  v9 = (__int64)v5[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, (unsigned int)v8);
  if ( hkClass::hasVtable(v6, &result)->m_bool )
    v4->m_contents.m_class = hkVariantDataUtil::findMostDerivedClass(v7, v4->m_vtable.m_pntr, v4->m_reg.m_pntr);
  else
    v4->m_contents.m_class = (hkClass *)v9;
  if ( !v4->m_contents.m_class )
    v4->m_contents.m_object = 0i64;
}

// File Line: 910
// RVA: 0xE477E0
hkDataClassImpl *__fastcall hkDataWorldNative::findClass(hkDataWorldNative *this, const char *name)
{
  const char *v2; // rdi
  hkDataWorldNative *v3; // rsi
  hkDataClassImpl *result; // rax
  __int64 v5; // rbp
  _QWORD **v6; // rax
  _QWORD *v7; // rax
  unsigned __int64 v8; // rbx

  v2 = name;
  v3 = this;
  if ( name )
  {
    result = (hkDataClassImpl *)hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
                                  (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_classes,
                                  (unsigned __int64)name,
                                  0i64);
    if ( result )
      return result;
    v5 = (__int64)v3->m_reg.m_pntr->vfptr[2].__vecDelDtor((hkBaseObject *)&v3->m_reg.m_pntr->vfptr, (unsigned int)v2);
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (_QWORD *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 32i64);
  v8 = (unsigned __int64)v7;
  if ( v7 )
  {
    v7[1] = 0xFFFFi64;
    v7[2] = v5;
    *v7 = &hkDataClassNative::`vftable;
    v7[3] = v3;
  }
  else
  {
    v8 = 0i64;
  }
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
    &v3->m_classes.m_map,
    (unsigned __int64)v2,
    v8);
  return (hkDataClassImpl *)v8;
}

// File Line: 923
// RVA: 0xE476B0
void __fastcall hkDataWorldNative::findAllClasses(hkDataWorldNative *this, hkArray<hkDataClassImpl *,hkContainerTempAllocator> *classesOut)
{
  hkDataWorldNative *v2; // r14
  hkClassNameRegistry *v3; // rcx
  hkArray<hkDataClassImpl *,hkContainerTempAllocator> *v4; // rbx
  int v5; // ebp
  __int64 v6; // rsi
  hkBaseObjectVtbl *v7; // rdi
  const char *v8; // rax
  __int64 v9; // rdi
  char *v10; // [rsp+20h] [rbp-18h]
  int v11; // [rsp+28h] [rbp-10h]
  int v12; // [rsp+2Ch] [rbp-Ch]

  v2 = this;
  v3 = this->m_reg.m_pntr;
  v4 = classesOut;
  if ( v3 )
  {
    v10 = 0i64;
    v11 = 0;
    v12 = 2147483648;
    ((void (__fastcall *)(hkClassNameRegistry *, char **))v3->vfptr[2].__first_virtual_table_function__)(v3, &v10);
    v5 = 0;
    if ( v11 > 0 )
    {
      v6 = 0i64;
      do
      {
        if ( !(hkClass::getFlags(*(hkClass **)&v10[v6])->m_storage & 1) )
        {
          v7 = v2->vfptr;
          v8 = hkClass::getName(*(hkClass **)&v10[v6]);
          v9 = ((__int64 (__fastcall *)(hkDataWorldNative *, const char *))v7[4].__first_virtual_table_function__)(
                 v2,
                 v8);
          if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 8);
          v4->m_data[v4->m_size++] = (hkDataClassImpl *)v9;
        }
        ++v5;
        v6 += 8i64;
      }
      while ( v5 < v11 );
    }
    v11 = 0;
    if ( v12 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v10,
        8 * v12);
  }
}

// File Line: 943
// RVA: 0xE478B0
hkDataObject *__fastcall hkDataWorldNative::findObject(hkDataWorldNative *this, hkDataObject *result, hkDataObject_Handle *handle)
{
  hkDataWorldNative *v3; // rsi
  hkDataObject_Handle *v4; // rdi
  hkDataObject *v5; // rbx
  _QWORD **v6; // rax
  hkDataObjectNative *v7; // rax

  v3 = this;
  v4 = handle;
  v5 = result;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkDataObjectNative *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  if ( v7 )
    hkDataObjectNative::hkDataObjectNative(v7, v4, v3);
  v5->m_impl = (hkDataObjectImpl *)&v7->vfptr;
  if ( v7 )
  {
    ++v7->m_externalCount;
    ++v7->m_count;
  }
  return v5;
}

// File Line: 948
// RVA: 0xE476A0
hkEnum<enum hkDataWorld::DataWorldType,int> *__fastcall hkDataWorldNative::getType(hkDataWorldNative *this, hkEnum<enum hkDataWorld::DataWorldType,int> *result)
{
  result->m_storage = 0;
  return result;
}

// File Line: 953
// RVA: 0xE47500
hkDataObject *__fastcall hkDataWorldNative::getContents(hkDataWorldNative *this, hkDataObject *result)
{
  hkDataWorldNative *v2; // rsi
  hkDataObject *v3; // rdi
  _QWORD **v4; // rax
  hkClassAccessor *v5; // rax
  hkClassAccessor *v6; // rbx
  hkDataObject *v7; // rax

  v2 = this;
  v3 = result;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkClassAccessor *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
  v6 = v5;
  if ( v5 )
  {
    v5->m_variant.m_class = (hkClass *)0xFFFF;
    v5->m_variant.m_object = &hkDataObjectNative::`vftable;
    hkClassAccessor::hkClassAccessor(v5 + 1, &v2->m_contents);
    v6[2].m_variant.m_object = v2;
    LOBYTE(v6[2].m_variant.m_class) = 0;
  }
  else
  {
    v6 = 0i64;
  }
  v3->m_impl = (hkDataObjectImpl *)v6;
  v7 = v3;
  if ( v6 )
  {
    ++WORD1(v6->m_variant.m_class);
    ++HIDWORD(v6->m_variant.m_class);
  }
  return v7;
}

// File Line: 958
// RVA: 0xE47590
hkDataObjectImpl *__fastcall hkDataWorldNative::newObject(hkDataWorldNative *this, hkDataClass *klass, __int64 __formal)
{
  hkClassNameRegistry *v3; // rbx
  hkDataWorldNative *v4; // rdi
  hkDataClass *v5; // r14
  __int64 v6; // rax
  hkClass *v7; // rsi
  _QWORD **v8; // rax
  void *v9; // rax
  int v10; // eax
  __int64 v11; // rbx
  __int64 v12; // rax
  hkTypeInfo *v13; // rax
  void *dst; // [rsp+20h] [rbp-18h]
  hkClass *v16; // [rsp+28h] [rbp-10h]

  v3 = this->m_reg.m_pntr;
  v4 = this;
  v5 = klass;
  v6 = ((__int64 (__fastcall *)(hkDataClassImpl *, hkDataClass *, __int64))klass->m_impl->vfptr[2].__vecDelDtor)(
         klass->m_impl,
         klass,
         __formal);
  v7 = (hkClass *)v3->vfptr[2].__vecDelDtor((hkBaseObject *)&v3->vfptr, v6);
  LODWORD(v3) = hkClass::getObjectSize(v7);
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (void *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v8[11] + 8i64))(v8[11], (unsigned int)v3);
  v16 = v7;
  dst = v9;
  if ( v9 )
  {
    v10 = hkClass::getObjectSize(v7);
    hkString::memSet(dst, 0, v10);
    v11 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[1].__first_virtual_table_function__)();
    v12 = ((__int64 (*)(void))v5->m_impl->vfptr[2].__vecDelDtor)();
    v13 = (hkTypeInfo *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 56i64))(v11, v12);
    if ( v13 )
      hkTypeInfo::finishLoadedObject(v13, dst, 0);
  }
  return hkNativeDataObjectImplCreate((hkVariant *)&dst, v4, 0);
}

// File Line: 977
// RVA: 0xE47680
hkDataClassImpl *__fastcall hkDataWorldNative::newClass(hkDataWorldNative *this, hkDataClass::Cinfo *cinfo)
{
  return 0i64;
}

// File Line: 982
// RVA: 0xE47690
hkDataArrayImpl *__fastcall hkDataWorldNative::newArray(hkDataWorldNative *this, hkDataObject *_obj, const struct _hkDataObject_MemberHandle *handle, hkDataClass_MemberInfo *minfo)
{
  return 0i64;
}

