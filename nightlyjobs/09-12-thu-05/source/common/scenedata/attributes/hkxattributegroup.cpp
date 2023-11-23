// File Line: 14
// RVA: 0xE37120
hkxAttributeGroup *__fastcall hkxAttributeGroup::operator=(hkxAttributeGroup *this, hkxAttributeGroup *other)
{
  int v4; // eax
  __int64 v5; // rdi
  hkRefVariant *p_m_value; // rbx
  int v7; // ecx
  hkxAttribute *v8; // rbx
  __int64 v9; // rdi

  hkStringPtr::operator=(&this->m_name, &other->m_name);
  v4 = this->m_attributes.m_size - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    p_m_value = &this->m_attributes.m_data[v4].m_value;
    do
    {
      if ( p_m_value->m_pntr )
        hkReferencedObject::removeReference(p_m_value->m_pntr);
      p_m_value->m_pntr = 0i64;
      hkStringPtr::~hkStringPtr((hkStringPtr *)&p_m_value[-1]);
      p_m_value -= 2;
      --v5;
    }
    while ( v5 >= 0 );
  }
  v7 = -this->m_attributes.m_size;
  v8 = &this->m_attributes.m_data[this->m_attributes.m_size];
  if ( v7 >= 0 && this->m_attributes.m_size != 0 )
  {
    v9 = (unsigned int)v7;
    do
    {
      if ( v8 )
        hkxAttribute::hkxAttribute(v8);
      ++v8;
      --v9;
    }
    while ( v9 );
  }
  this->m_attributes.m_size = 0;
  if ( other->m_attributes.m_size )
    hkArrayBase<hkxAttribute>::_insertAt(
      &this->m_attributes,
      &hkContainerHeapAllocator::s_alloc,
      0,
      other->m_attributes.m_data,
      other->m_attributes.m_size);
  return this;
}

// File Line: 24
// RVA: 0xE37230
hkResult *__fastcall hkxAttributeGroup::getBoolValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        hkBool *boolOut)
{
  hkxSparselyAnimatedBool *BoolAttributeByName; // rax
  char *p_m_bool; // rax
  hkxSparselyAnimatedInt *IntAttributeByName; // rax
  int *m_data; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  BoolAttributeByName = hkxAttributeGroup::findBoolAttributeByName(this, name);
  if ( BoolAttributeByName )
  {
    p_m_bool = &BoolAttributeByName->m_bools.m_data->m_bool;
    result->m_enum = HK_SUCCESS;
    boolOut->m_bool = *p_m_bool;
  }
  else
  {
    IntAttributeByName = hkxAttributeGroup::findIntAttributeByName(this, name);
    if ( IntAttributeByName )
    {
      m_data = IntAttributeByName->m_ints.m_data;
      result->m_enum = HK_SUCCESS;
      boolOut->m_bool = *m_data != 0;
    }
    else
    {
      if ( warnIfNotFound )
      {
        hkErrStream::hkErrStream(&v18, buf, 512);
        v13 = hkOstream::operator<<(&v18, "Bool attribute ");
        v14 = hkOstream::operator<<(v13, name);
        v15 = hkOstream::operator<<(v14, " not found in ");
        v16 = hkOstream::operator<<(v15, &this->m_name);
        hkOstream::operator<<(v16, " attribute group");
        hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 47);
        hkOstream::~hkOstream(&v18);
      }
      result->m_enum = HK_FAILURE;
    }
  }
  return result;
}

// File Line: 54
// RVA: 0xE37360
hkResult *__fastcall hkxAttributeGroup::getIntValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        int *intOut)
{
  hkxSparselyAnimatedEnum *IntAttributeByName; // rax
  int *v10; // rax
  hkxSparselyAnimatedBool *BoolAttributeByName; // rax
  hkBool *m_data; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkOstream *v16; // rax
  hkErrStream v18; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  IntAttributeByName = (hkxSparselyAnimatedEnum *)hkxAttributeGroup::findIntAttributeByName(this, name);
  if ( IntAttributeByName )
    goto LABEL_2;
  BoolAttributeByName = hkxAttributeGroup::findBoolAttributeByName(this, name);
  if ( BoolAttributeByName )
  {
    m_data = BoolAttributeByName->m_bools.m_data;
    result->m_enum = HK_SUCCESS;
    *intOut = m_data->m_bool != 0;
    return result;
  }
  IntAttributeByName = hkxAttributeGroup::findEnumAttributeByName(this, name);
  if ( IntAttributeByName )
  {
LABEL_2:
    v10 = IntAttributeByName->m_ints.m_data;
    result->m_enum = HK_SUCCESS;
    *intOut = *v10;
  }
  else
  {
    if ( warnIfNotFound )
    {
      hkErrStream::hkErrStream(&v18, buf, 512);
      v13 = hkOstream::operator<<(&v18, "Integer attribute ");
      v14 = hkOstream::operator<<(v13, name);
      v15 = hkOstream::operator<<(v14, " not found in ");
      v16 = hkOstream::operator<<(v15, &this->m_name);
      hkOstream::operator<<(v16, " attribute group");
      hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 87);
      hkOstream::~hkOstream(&v18);
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 94
// RVA: 0xE374A0
hkResult *__fastcall hkxAttributeGroup::getIntValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        unsigned int *intOut)
{
  hkxAttributeGroup::getIntValue(this, result, name, warnIfNotFound, (int *)intOut);
  return result;
}

// File Line: 100
// RVA: 0xE374D0
hkResult *__fastcall hkxAttributeGroup::getStringValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        const char **stringOut)
{
  hkxSparselyAnimatedString *StringAttributeByName; // rax
  hkStringPtr *m_data; // rax
  hkxSparselyAnimatedEnum *EnumAttributeByName; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkOstream *v15; // rax
  hkResult resulta; // [rsp+20h] [rbp-228h] BYREF
  hkErrStream v18; // [rsp+28h] [rbp-220h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  StringAttributeByName = hkxAttributeGroup::findStringAttributeByName(this, name);
  if ( StringAttributeByName )
  {
    m_data = StringAttributeByName->m_strings.m_data;
    result->m_enum = HK_SUCCESS;
    *stringOut = (const char *)((unsigned __int64)m_data->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64);
  }
  else
  {
    EnumAttributeByName = hkxAttributeGroup::findEnumAttributeByName(this, name);
    if ( EnumAttributeByName )
    {
      hkxEnum::getNameOfValue(
        EnumAttributeByName->m_enum.m_pntr,
        &resulta,
        *EnumAttributeByName->m_ints.m_data,
        stringOut);
      result->m_enum = HK_SUCCESS;
    }
    else
    {
      if ( warnIfNotFound )
      {
        hkErrStream::hkErrStream(&v18, buf, 512);
        v12 = hkOstream::operator<<(&v18, "String attribute ");
        v13 = hkOstream::operator<<(v12, name);
        v14 = hkOstream::operator<<(v13, " not found in ");
        v15 = hkOstream::operator<<(v14, &this->m_name);
        hkOstream::operator<<(v15, " attribute group");
        hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 125);
        hkOstream::~hkOstream(&v18);
      }
      result->m_enum = HK_FAILURE;
    }
  }
  return result;
}

// File Line: 132
// RVA: 0xE37610
hkResult *__fastcall hkxAttributeGroup::getFloatValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        float *floatOut)
{
  hkxAnimatedFloat *FloatAttributeByName; // rax
  float *m_data; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  FloatAttributeByName = hkxAttributeGroup::findFloatAttributeByName(this, name);
  if ( FloatAttributeByName )
  {
    m_data = FloatAttributeByName->m_floats.m_data;
    result->m_enum = HK_SUCCESS;
    *floatOut = *m_data;
  }
  else
  {
    if ( warnIfNotFound )
    {
      hkErrStream::hkErrStream(&v16, buf, 512);
      v11 = hkOstream::operator<<(&v16, "Float attribute ");
      v12 = hkOstream::operator<<(v11, name);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &this->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 142);
      hkOstream::~hkOstream(&v16);
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 149
// RVA: 0xE37710
hkResult *__fastcall hkxAttributeGroup::getVectorValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        hkVector4f *vectorOut)
{
  hkxAnimatedVector *VectorAttributeByName; // rax
  hkVector4f *m_data; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  VectorAttributeByName = hkxAttributeGroup::findVectorAttributeByName(this, name);
  if ( VectorAttributeByName )
  {
    m_data = (hkVector4f *)VectorAttributeByName->m_vectors.m_data;
    result->m_enum = HK_SUCCESS;
    *vectorOut = (hkVector4f)m_data->m_quad;
  }
  else
  {
    if ( warnIfNotFound )
    {
      hkErrStream::hkErrStream(&v16, buf, 512);
      v11 = hkOstream::operator<<(&v16, "Float attribute ");
      v12 = hkOstream::operator<<(v11, name);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &this->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 159);
      hkOstream::~hkOstream(&v16);
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 166
// RVA: 0xE37810
hkResult *__fastcall hkxAttributeGroup::getQuaternionValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        hkQuaternionf *quaternionOut)
{
  hkxAnimatedQuaternion *QuaternionAttributeByName; // rax
  hkQuaternionf *m_data; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkErrStream v16; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  QuaternionAttributeByName = hkxAttributeGroup::findQuaternionAttributeByName(this, name);
  if ( QuaternionAttributeByName )
  {
    m_data = (hkQuaternionf *)QuaternionAttributeByName->m_quaternions.m_data;
    result->m_enum = HK_SUCCESS;
    *quaternionOut = (hkQuaternionf)m_data->m_vec.m_quad;
  }
  else
  {
    if ( warnIfNotFound )
    {
      hkErrStream::hkErrStream(&v16, buf, 512);
      v11 = hkOstream::operator<<(&v16, "Quaternion attribute ");
      v12 = hkOstream::operator<<(v11, name);
      v13 = hkOstream::operator<<(v12, " not found in ");
      v14 = hkOstream::operator<<(v13, &this->m_name);
      hkOstream::operator<<(v14, " attribute group");
      hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 176);
      hkOstream::~hkOstream(&v16);
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 183
// RVA: 0xE37910
hkResult *__fastcall hkxAttributeGroup::getMatrixValue(
        hkxAttributeGroup *this,
        hkResult *result,
        const char *name,
        bool warnIfNotFound,
        hkMatrix4f *matrixOut)
{
  hkxAnimatedMatrix *MatrixAttributeByName; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkErrStream v15; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  MatrixAttributeByName = hkxAttributeGroup::findMatrixAttributeByName(this, name);
  if ( MatrixAttributeByName )
  {
    hkMatrix4f::set4x4ColumnMajor(matrixOut, MatrixAttributeByName->m_matrices.m_data);
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    if ( warnIfNotFound )
    {
      hkErrStream::hkErrStream(&v15, buf, 512);
      v10 = hkOstream::operator<<(&v15, "Matrix attribute ");
      v11 = hkOstream::operator<<(v10, name);
      v12 = hkOstream::operator<<(v11, " not found in ");
      v13 = hkOstream::operator<<(v12, &this->m_name);
      hkOstream::operator<<(v13, " attribute group");
      hkError::messageWarning(0xABBAAB81, buf, "Attributes\\hkxAttributeGroup.cpp", 193);
      hkOstream::~hkOstream(&v15);
    }
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 200
// RVA: 0xE37B10
__int64 __fastcall hkxAttributeGroup::findAttributeIndexByName(hkxAttributeGroup *this, const char *name)
{
  unsigned int v2; // ebx
  __int64 i; // rdi

  v2 = 0;
  if ( this->m_attributes.m_size <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = 0i64;
        (unsigned int)hkString::strCasecmp(
                        (const char *)((unsigned __int64)this->m_attributes.m_data[i].m_name.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64),
                        name);
        ++i )
  {
    if ( (signed int)++v2 >= this->m_attributes.m_size )
      return 0xFFFFFFFFi64;
  }
  return v2;
}

// File Line: 212
// RVA: 0xE37B90
hkRefVariant *__fastcall hkxAttributeGroup::findAttributeVariantByName(
        hkxAttributeGroup *this,
        hkRefVariant *result,
        const char *name)
{
  int AttributeIndexByName; // eax
  char v6; // di
  hkReferencedObject *v7; // rbx
  hkReferencedObject **v8; // rax
  hkReferencedObject **v9; // r14
  hkxAttribute *v10; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkVariant v; // [rsp+20h] [rbp-28h] BYREF
  hkReferencedObject *v14; // [rsp+58h] [rbp+10h] BYREF
  hkRefVariant v15; // [rsp+68h] [rbp+20h] BYREF

  LODWORD(v14) = 0;
  AttributeIndexByName = hkxAttributeGroup::findAttributeIndexByName(this, name);
  v.m_object = 0i64;
  v.m_class = 0i64;
  if ( AttributeIndexByName >= 0 )
  {
    v6 = 2;
    v10 = &this->m_attributes.m_data[AttributeIndexByName];
    m_pntr = v10->m_value.m_pntr;
    if ( m_pntr )
      hkReferencedObject::addReference(m_pntr);
    v7 = v10->m_value.m_pntr;
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
  result->m_pntr = *v9;
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    if ( v7 )
      hkReferencedObject::removeReference(v7);
  }
  if ( (v6 & 1) != 0 && v15.m_pntr )
    hkReferencedObject::removeReference(v15.m_pntr);
  return result;
}

// File Line: 221
// RVA: 0xE37C70
hkReferencedObject *__fastcall hkxAttributeGroup::findAttributeObjectByName(
        hkxAttributeGroup *this,
        const char *name,
        hkClass *type)
{
  hkReferencedObject *m_pntr; // rcx
  hkClass *Class; // rax
  const char *v6; // rbx
  const char *v7; // rax
  int v8; // eax
  hkReferencedObject *v9; // rbx
  hkRefVariant result; // [rsp+48h] [rbp+20h] BYREF

  hkxAttributeGroup::findAttributeVariantByName(this, &result, name);
  m_pntr = result.m_pntr;
  if ( !result.m_pntr
    || type
    && (Class = hkRefVariant::getClass(&result),
        v6 = hkClass::getName(Class),
        v7 = hkClass::getName(type),
        v8 = hkString::strCasecmp(v7, v6),
        m_pntr = result.m_pntr,
        v8) )
  {
    v9 = 0i64;
  }
  else
  {
    v9 = m_pntr;
  }
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  return v9;
}

// File Line: 233
// RVA: 0xE37A10
hkxSparselyAnimatedBool *__fastcall hkxAttributeGroup::findBoolAttributeByName(
        hkxAttributeGroup *this,
        const char *name)
{
  return (hkxSparselyAnimatedBool *)hkxAttributeGroup::findAttributeObjectByName(
                                      this,
                                      name,
                                      &hkxSparselyAnimatedBoolClass);
}

// File Line: 239
// RVA: 0xE37A30
hkxSparselyAnimatedInt *__fastcall hkxAttributeGroup::findIntAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return (hkxSparselyAnimatedInt *)hkxAttributeGroup::findAttributeObjectByName(
                                     this,
                                     name,
                                     &hkxSparselyAnimatedIntClass);
}

// File Line: 245
// RVA: 0xE37A50
hkxSparselyAnimatedEnum *__fastcall hkxAttributeGroup::findEnumAttributeByName(
        hkxAttributeGroup *this,
        const char *name)
{
  return (hkxSparselyAnimatedEnum *)hkxAttributeGroup::findAttributeObjectByName(
                                      this,
                                      name,
                                      &hkxSparselyAnimatedEnumClass);
}

// File Line: 251
// RVA: 0xE37A70
hkxSparselyAnimatedString *__fastcall hkxAttributeGroup::findStringAttributeByName(
        hkxAttributeGroup *this,
        const char *name)
{
  return (hkxSparselyAnimatedString *)hkxAttributeGroup::findAttributeObjectByName(
                                        this,
                                        name,
                                        &hkxSparselyAnimatedStringClass);
}

// File Line: 257
// RVA: 0xE37A90
hkxAnimatedFloat *__fastcall hkxAttributeGroup::findFloatAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return (hkxAnimatedFloat *)hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedFloatClass);
}

// File Line: 263
// RVA: 0xE37AB0
hkxAnimatedVector *__fastcall hkxAttributeGroup::findVectorAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return (hkxAnimatedVector *)hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedVectorClass);
}

// File Line: 268
// RVA: 0xE37AD0
hkxAnimatedQuaternion *__fastcall hkxAttributeGroup::findQuaternionAttributeByName(
        hkxAttributeGroup *this,
        const char *name)
{
  return (hkxAnimatedQuaternion *)hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedQuaternionClass);
}

// File Line: 274
// RVA: 0xE37AF0
hkxAnimatedMatrix *__fastcall hkxAttributeGroup::findMatrixAttributeByName(hkxAttributeGroup *this, const char *name)
{
  return (hkxAnimatedMatrix *)hkxAttributeGroup::findAttributeObjectByName(this, name, &hkxAnimatedMatrixClass);
}

