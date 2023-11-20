// File Line: 14
// RVA: 0xE37120
hkxAttributeGroup *__fastcall hkxAttributeGroup::operator=(hkxAttributeGroup *this, hkxAttributeGroup *other)
{
  hkxAttributeGroup *v2; // r14
  hkxAttributeGroup *v3; // rbp
  int v4; // er9
  int v5; // eax
  __int64 v6; // rdi
  hkReferencedObject **v7; // rbx
  int v8; // ecx
  hkxAttribute *v9; // rbx
  __int64 v10; // rdi
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = other;
  v3 = this;
  hkStringPtr::operator=(&this->m_name, &other->m_name);
  if ( (v3->m_attributes.m_capacityAndFlags & 0x3FFFFFFF) < 0 )
  {
    v4 = 0;
    if ( 2 * (v3->m_attributes.m_capacityAndFlags & 0x3FFFFFFF) > 0 )
      v4 = 2 * (v3->m_attributes.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_attributes,
      v4,
      16);
  }
  v5 = v3->m_attributes.m_size - 1;
  v6 = v5;
  if ( v5 >= 0 )
  {
    v7 = &v3->m_attributes.m_data[v5].m_value.m_pntr;
    do
    {
      if ( *v7 )
        hkReferencedObject::removeReference(*v7);
      *v7 = 0i64;
      hkStringPtr::~hkStringPtr((hkStringPtr *)v7 - 1);
      v7 -= 2;
      --v6;
    }
    while ( v6 >= 0 );
  }
  v8 = -v3->m_attributes.m_size;
  v9 = &v3->m_attributes.m_data[v3->m_attributes.m_size];
  if ( v8 >= 0 && v3->m_attributes.m_size != 0 )
  {
    v10 = (unsigned int)v8;
    do
    {
      if ( v9 )
        hkxAttribute::hkxAttribute(v9);
      ++v9;
      --v10;
    }
    while ( v10 );
  }
  v3->m_attributes.m_size = 0;
  if ( v2->m_attributes.m_size )
    hkArrayBase<hkxAttribute>::_insertAt(
      (hkArrayBase<hkxAttribute> *)&v3->m_attributes.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      0,
      v2->m_attributes.m_data,
      v2->m_attributes.m_size);
  return v3;
}

// File Line: 24
// RVA: 0xE37230
hkResult *__fastcall hkxAttributeGroup::getBoolValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, hkBool *boolOut)
{
  hkResult *v5; // rbx
  bool v6; // bp
  const char *v7; // rdi
  hkxAttributeGroup *v8; // rsi
  hkxSparselyAnimatedBool *v9; // rax
  char *v10; // rax
  hkxSparselyAnimatedInt *v11; // rax
  int *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findBoolAttributeByName(this, name);
  if ( v9 )
  {
    v10 = &v9->m_bools.m_data->m_bool;
    v5->m_enum = 0;
    boolOut->m_bool = *v10;
  }
  else
  {
    v11 = hkxAttributeGroup::findIntAttributeByName(v8, v7);
    if ( v11 )
    {
      v12 = v11->m_ints.m_data;
      v5->m_enum = 0;
      boolOut->m_bool = *v12 != 0;
    }
    else
    {
      if ( v6 )
      {
        hkErrStream::hkErrStream(&v18, &buf, 512);
        v13 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "Bool attribute ");
        v14 = hkOstream::operator<<(v13, v7);
        v15 = hkOstream::operator<<(v14, " not found in ");
        v16 = hkOstream::operator<<(v15, &v8->m_name);
        hkOstream::operator<<(v16, " attribute group");
        hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 47);
        hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
      }
      v5->m_enum = 1;
    }
  }
  return v5;
}

// File Line: 54
// RVA: 0xE37360
hkResult *__fastcall hkxAttributeGroup::getIntValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, int *intOut)
{
  hkResult *v5; // rbx
  bool v6; // bp
  const char *v7; // rdi
  hkxAttributeGroup *v8; // rsi
  hkxSparselyAnimatedEnum *v9; // rax
  int *v10; // rax
  hkxSparselyAnimatedBool *v11; // rax
  hkBool *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = (hkxSparselyAnimatedEnum *)hkxAttributeGroup::findIntAttributeByName(this, name);
  if ( v9 )
    goto LABEL_12;
  v11 = hkxAttributeGroup::findBoolAttributeByName(v8, v7);
  if ( v11 )
  {
    v12 = v11->m_bools.m_data;
    v5->m_enum = 0;
    *intOut = v12->m_bool != 0;
    return v5;
  }
  v9 = hkxAttributeGroup::findEnumAttributeByName(v8, v7);
  if ( v9 )
  {
LABEL_12:
    v10 = v9->m_ints.m_data;
    v5->m_enum = 0;
    *intOut = *v10;
  }
  else
  {
    if ( v6 )
    {
      hkErrStream::hkErrStream(&v18, &buf, 512);
      v13 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "Integer attribute ");
      v14 = hkOstream::operator<<(v13, v7);
      v15 = hkOstream::operator<<(v14, " not found in ");
      v16 = hkOstream::operator<<(v15, &v8->m_name);
      hkOstream::operator<<(v16, " attribute group");
      hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 87);
      hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
    }
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 94
// RVA: 0xE374A0
hkResult *__fastcall hkxAttributeGroup::getIntValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, unsigned int *intOut)
{
  hkResult *v5; // rbx

  v5 = result;
  hkxAttributeGroup::getIntValue(this, result, name, warnIfNotFound, (int *)intOut);
  return v5;
}

// File Line: 100
// RVA: 0xE374D0
hkResult *__fastcall hkxAttributeGroup::getStringValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, const char **stringOut)
{
  hkResult *v5; // rbx
  bool v6; // bp
  const char *v7; // rdi
  hkxAttributeGroup *v8; // rsi
  hkxSparselyAnimatedString *v9; // rax
  hkStringPtr *v10; // rax
  hkxSparselyAnimatedEnum *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkResult resulta; // [rsp+20h] [rbp-228h]
  hkErrStream v18; // [rsp+28h] [rbp-220h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findStringAttributeByName(this, name);
  if ( v9 )
  {
    v10 = v9->m_strings.m_data;
    v5->m_enum = 0;
    *stringOut = (const char *)((_QWORD)v10->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  }
  else
  {
    v11 = hkxAttributeGroup::findEnumAttributeByName(v8, v7);
    if ( v11 )
    {
      hkxEnum::getNameOfValue(v11->m_enum.m_pntr, &resulta, *v11->m_ints.m_data, stringOut);
      v5->m_enum = 0;
    }
    else
    {
      if ( v6 )
      {
        hkErrStream::hkErrStream(&v18, &buf, 512);
        v12 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "String attribute ");
        v13 = hkOstream::operator<<(v12, v7);
        v14 = hkOstream::operator<<(v13, " not found in ");
        v15 = hkOstream::operator<<(v14, &v8->m_name);
        hkOstream::operator<<(v15, " attribute group");
        hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 125);
        hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
      }
      v5->m_enum = 1;
    }
  }
  return v5;
}

// File Line: 132
// RVA: 0xE37610
hkResult *__fastcall hkxAttributeGroup::getFloatValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, float *floatOut)
{
  hkResult *v5; // rbx
  bool v6; // di
  const char *v7; // rsi
  hkxAttributeGroup *v8; // rbp
  hkxAnimatedFloat *v9; // rax
  float *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findFloatAttributeByName(this, name);
  if ( v9 )
  {
    v10 = v9->m_floats.m_data;
    v5->m_enum = 0;
    *floatOut = *v10;
  }
  else
  {
    if ( v6 )
    {
      hkErrStream::hkErrStream(&v16, &buf, 512);
      v11 = hkOstream::operator<<((hkOstream *)&v16.vfptr, "Float attribute ");
      v12 = hkOstream::operator<<(v11, v7);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &v8->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 142);
      hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    }
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 149
// RVA: 0xE37710
hkResult *__fastcall hkxAttributeGroup::getVectorValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, hkVector4f *vectorOut)
{
  hkResult *v5; // rbx
  bool v6; // di
  const char *v7; // rsi
  hkxAttributeGroup *v8; // rbp
  hkxAnimatedVector *v9; // rax
  hkVector4f *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findVectorAttributeByName(this, name);
  if ( v9 )
  {
    v10 = (hkVector4f *)v9->m_vectors.m_data;
    v5->m_enum = 0;
    *vectorOut = (hkVector4f)v10->m_quad;
  }
  else
  {
    if ( v6 )
    {
      hkErrStream::hkErrStream(&v16, &buf, 512);
      v11 = hkOstream::operator<<((hkOstream *)&v16.vfptr, "Float attribute ");
      v12 = hkOstream::operator<<(v11, v7);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &v8->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 159);
      hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    }
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 166
// RVA: 0xE37810
hkResult *__fastcall hkxAttributeGroup::getQuaternionValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, hkQuaternionf *quaternionOut)
{
  hkResult *v5; // rbx
  bool v6; // di
  const char *v7; // rsi
  hkxAttributeGroup *v8; // rbp
  hkxAnimatedQuaternion *v9; // rax
  hkQuaternionf *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findQuaternionAttributeByName(this, name);
  if ( v9 )
  {
    v10 = (hkQuaternionf *)v9->m_quaternions.m_data;
    v5->m_enum = 0;
    *quaternionOut = (hkQuaternionf)v10->m_vec.m_quad;
  }
  else
  {
    if ( v6 )
    {
      hkErrStream::hkErrStream(&v16, &buf, 512);
      v11 = hkOstream::operator<<((hkOstream *)&v16.vfptr, "Quaternion attribute ");
      v12 = hkOstream::operator<<(v11, v7);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &v8->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 176);
      hkOstream::~hkOstream((hkOstream *)&v16.vfptr);
    }
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 183
// RVA: 0xE37910
hkResult *__fastcall hkxAttributeGroup::getMatrixValue(hkxAttributeGroup *this, hkResult *result, const char *name, bool warnIfNotFound, hkMatrix4f *matrixOut)
{
  hkResult *v5; // rbx
  bool v6; // di
  const char *v7; // rsi
  hkxAttributeGroup *v8; // rbp
  hkxAnimatedMatrix *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkErrStream v15; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v5 = result;
  v6 = warnIfNotFound;
  v7 = name;
  v8 = this;
  v9 = hkxAttributeGroup::findMatrixAttributeByName(this, name);
  if ( v9 )
  {
    hkMatrix4f::set4x4ColumnMajor(matrixOut, v9->m_matrices.m_data);
    v5->m_enum = 0;
  }
  else
  {
    if ( v6 )
    {
      hkErrStream::hkErrStream(&v15, &buf, 512);
      v10 = hkOstream::operator<<((hkOstream *)&v15.vfptr, "Matrix attribute ");
      v11 = hkOstream::operator<<(v10, v7);
      v12 = hkOstream::operator<<(v11, " not found in ");
      v13 = hkOstream::operator<<(v12, &v8->m_name);
      hkOstream::operator<<(v13, " attribute group");
      hkError::messageWarning(-1413829759, &buf, "Attributes\\hkxAttributeGroup.cpp", 193);
      hkOstream::~hkOstream((hkOstream *)&v15.vfptr);
    }
    v5->m_enum = 1;
  }
  return v5;
}

// File Line: 200
// RVA: 0xE37B10
signed __int64 __fastcall hkxAttributeGroup::findAttributeIndexByName(hkxAttributeGroup *this, const char *name)
{
  int v2; // ebx
  const char *v3; // rbp
  hkxAttributeGroup *v4; // rsi
  __int64 v5; // rdi

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( this->m_attributes.m_size <= 0 )
    return 0xFFFFFFFFi64;
  v5 = 0i64;
  while ( (unsigned int)hkString::strCasecmp(
                          (const char *)((_QWORD)v4->m_attributes.m_data[v5].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                          v3) )
  {
    ++v2;
    ++v5;
    if ( v2 >= v4->m_attributes.m_size )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v2;
}

// File Line: 212
// RVA: 0xE37B90
hkRefVariant *__fastcall hkxAttributeGroup::findAttributeVariantByName(hkxAttributeGroup *this, hkRefVariant *result, const char *name)
{
  hkRefVariant *v3; // rsi
  hkxAttributeGroup *v4; // rbx
  int v5; // eax
  char v6; // di
  hkReferencedObject *v7; // rbx
  hkReferencedObject **v8; // rax
  hkReferencedObject **v9; // r14
  signed __int64 v10; // rbx
  hkReferencedObject *v11; // rcx
  hkVariant v; // [rsp+20h] [rbp-28h]
  hkReferencedObject *v14; // [rsp+58h] [rbp+10h]
  hkRefVariant v15; // [rsp+68h] [rbp+20h]

  v3 = result;
  LODWORD(v14) = 0;
  v4 = this;
  v5 = hkxAttributeGroup::findAttributeIndexByName(this, name);
  v.m_object = 0i64;
  v.m_class = 0i64;
  if ( v5 >= 0 )
  {
    v6 = 2;
    v10 = (signed __int64)&v4->m_attributes.m_data[v5];
    v11 = *(hkReferencedObject **)(v10 + 8);
    if ( v11 )
      hkReferencedObject::addReference(v11);
    v7 = *(hkReferencedObject **)(v10 + 8);
    v9 = &v14;
    v14 = v7;
  }
  else
  {
    v6 = 1;
    hkRefVariant::hkRefVariant(&v15, &v);
    v7 = v14;
    v9 = v8;
  }
  if ( *v9 )
    hkReferencedObject::addReference(*v9);
  v3->m_pntr = *v9;
  if ( v6 & 2 )
  {
    v6 &= 0xFDu;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  if ( v6 & 1 && v15.m_pntr )
    hkReferencedObject::removeReference(v15.m_pntr);
  return v3;
}

// File Line: 221
// RVA: 0xE37C70
hkReferencedObject *__fastcall hkxAttributeGroup::findAttributeObjectByName(hkxAttributeGroup *this, const char *name, hkClass *type)
{
  hkClass *v3; // rdi
  hkReferencedObject *v4; // rcx
  hkClass *v5; // rax
  const char *v6; // rbx
  const char *v7; // rax
  int v8; // eax
  hkReferencedObject *v9; // rbx
  hkRefVariant result; // [rsp+48h] [rbp+20h]

  v3 = type;
  hkxAttributeGroup::findAttributeVariantByName(this, &result, name);
  v4 = result.m_pntr;
  if ( !result.m_pntr
    || v3
    && (v5 = hkRefVariant::getClass(&result),
        v6 = hkClass::getName(v5),
        v7 = hkClass::getName(v3),
        v8 = hkString::strCasecmp(v7, v6),
        v4 = result.m_pntr,
        v8) )
  {
    v9 = 0i64;
  }
  else
  {
    v9 = v4;
  }
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  return v9;
}

// File Line: 233
// RVA: 0xE37A10
hkReferencedObject *__fastcall hkxAttributeGroup::findBoolAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxSparselyAnimatedBoolClass);
}

// File Line: 239
// RVA: 0xE37A30
hkReferencedObject *__fastcall hkxAttributeGroup::findIntAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxSparselyAnimatedIntClass);
}

// File Line: 245
// RVA: 0xE37A50
hkReferencedObject *__fastcall hkxAttributeGroup::findEnumAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxSparselyAnimatedEnumClass);
}

// File Line: 251
// RVA: 0xE37A70
hkReferencedObject *__fastcall hkxAttributeGroup::findStringAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxSparselyAnimatedStringClass);
}

// File Line: 257
// RVA: 0xE37A90
hkReferencedObject *__fastcall hkxAttributeGroup::findFloatAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedFloatClass);
}

// File Line: 263
// RVA: 0xE37AB0
hkReferencedObject *__fastcall hkxAttributeGroup::findVectorAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedVectorClass);
}

// File Line: 268
// RVA: 0xE37AD0
hkReferencedObject *__fastcall hkxAttributeGroup::findQuaternionAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedQuaternionClass);
}

// File Line: 274
// RVA: 0xE37AF0
hkReferencedObject *__fastcall hkxAttributeGroup::findMatrixAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedMatrixClass);
}

