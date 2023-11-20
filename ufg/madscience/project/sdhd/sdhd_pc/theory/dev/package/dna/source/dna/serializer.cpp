// File Line: 456
// RVA: 0x1AE4B0
signed __int64 __fastcall DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(DNA::DNAPropertyBagSerializer *this, UFG::qReflectType *reflection_type, const char *address)
{
  unsigned int v3; // ebx
  const char *v4; // rbp
  UFG::qReflectType *v5; // r14
  DNA::DNAPropertyBagSerializer *v6; // rdi
  DNA::DNAPropertyBagSerializer::CreateContext *v7; // rax
  unsigned __int64 v8; // rcx
  UFG::qReflectType *v9; // rsi
  UFG::ReflectionDB *v10; // rax

  v3 = 0;
  v4 = address;
  v5 = reflection_type;
  v6 = this;
  if ( !this->mAllCreatedBags.size )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v7 = &v6->mAllCreatedBags.p[(unsigned __int64)v3];
    v8 = (unsigned __int64)v7->mData;
    if ( (unsigned __int64)v4 >= v8 )
    {
      v9 = v7->mType;
      if ( (unsigned __int64)v4 < v7->mType->mNumBytes + v8 )
      {
        v10 = UFG::ReflectionDB::Instance();
        if ( UFG::ReflectionDB::IsDerivedFrom(v10, v9->mNameUID, v5->mNameUID) )
          break;
      }
    }
    if ( ++v3 >= v6->mAllCreatedBags.size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 471
// RVA: 0x1AE1B0
void __fastcall DNA::DNAPropertyBagSerializer::BindChildObjectsToParents(DNA::DNAPropertyBagSerializer *this)
{
  DNA::DNAPropertyBagSerializer *v1; // rbp
  unsigned int v2; // ebx
  unsigned __int64 v3; // r15
  char *v4; // r14
  int v5; // edi
  int v6; // eax
  DNA::DNAPropertyBagSerializer::CreateContext *v7; // rdx
  DNA::PropertyBag *v8; // rsi
  DNA::PropertyBag *v9; // rdi
  UFG::qTree64Base *v10; // rax
  DNA::PropertyWrapper *v11; // rax
  DNA::PropertyBagWrapper v12; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = 0;
  if ( this->mPatches.size )
  {
    do
    {
      v3 = (unsigned __int64)v2 << 6;
      v4 = (char *)v1->mPatches.p + v3;
      v5 = DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(
             v1,
             *(UFG::qReflectType **)v4,
             *((const char **)v4 + 4));
      v6 = DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(
             v1,
             *((UFG::qReflectType **)v4 + 3),
             *((const char **)v4 + 5));
      if ( v5 >= 0 && v6 >= 0 )
      {
        v7 = v1->mAllCreatedBags.p;
        v8 = v7[(unsigned __int64)(unsigned int)v5].mProperties;
        v9 = v7[(unsigned __int64)(unsigned int)v6].mProperties;
        v10 = DNA::PropertyBag::GetSchemaType(v8);
        DNA::PropertyBagWrapper::PropertyBagWrapper(&v12, (DNA::SchemaType *)v10);
        DNA::PropertyBagWrapper::AddPropertyBag(&v12, v8);
        v11 = DNA::PropertyBagWrapper::GetProperty(
                &v12,
                (*(UFG::qReflectField **)((char *)&v1->mPatches.p->mField + v3))->mName);
        DNA::PropertyWrapper::Set(v11, *((_DWORD *)v4 + 4), v9, 0);
        DNA::PropertyBag::SetOwner(v9, v8);
        DNA::PropertyBagWrapper::~PropertyBagWrapper(&v12);
      }
      ++v2;
    }
    while ( v2 < v1->mPatches.size );
  }
}

// File Line: 516
// RVA: 0x1ADBF0
void __fastcall DNA::DNAPropertyBagSerializer::BeginObject(DNA::DNAPropertyBagSerializer *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  const char *v3; // r15
  UFG::qReflectType *v4; // rbp
  DNA::DNAPropertyBagSerializer *v5; // rsi
  DNA::Database *v6; // rax
  unsigned __int64 v7; // rdi
  __int64 v8; // rdx
  unsigned int v9; // er8
  signed __int64 v10; // rax
  const char *v11; // rbx
  DNA::Database *v12; // rax
  DNA::PropertyBag *v13; // r12
  DNA::Database *v14; // rax
  UFG::qTree64Base *v15; // rax
  __int64 v16; // r13
  unsigned int v17; // er14
  unsigned int v18; // edi
  unsigned int v19; // ebx
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  DNA::PropertyBag **v23; // r12
  __int64 v24; // r9
  __int64 v25; // r14
  unsigned int v26; // edi
  unsigned int v27; // eax
  DNA::DNAPropertyBagSerializer::CreateContext *v28; // rcx
  UFG::qString v29; // [rsp+48h] [rbp-B0h]
  __int64 v30; // [rsp+70h] [rbp-88h]
  UFG::qString v31; // [rsp+78h] [rbp-80h]
  DNA::PropertyBagWrapper v32; // [rsp+A0h] [rbp-58h]
  DNA::PropertyBag *v33; // [rsp+100h] [rbp+8h]

  v30 = -2i64;
  v3 = object_data;
  v4 = reflection_type;
  v5 = this;
  if ( !this->mObjectStack.size )
  {
    DNA::Database::Instance();
    v7 = DNA::Database::GenUID(v6);
    if ( v4->mFlags & 0x10 )
      v7 = *((_QWORD *)v3 + 1);
    UFG::qString::qString(&v31, v4->mName);
    v8 = 0i64;
    v9 = v5->mTrackedObjects.size;
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = (signed __int64)&v5->mTrackedObjects.p[v8];
        if ( *(const char **)(v10 + 8) == v3 && *(UFG::qReflectType **)v10 == v4 )
          break;
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= v9 )
          goto LABEL_10;
      }
      UFG::qString::Set(&v31, *(const char **)(v10 + 40), *(_DWORD *)(v10 + 36), 0i64, 0);
    }
LABEL_10:
    v11 = v5->mFilePath.mData;
    DNA::Database::Instance();
    v13 = DNA::Database::CreateBag(v12, v31.mData, v4->mName, v11, v7);
    v33 = v13;
    DNA::Database::Instance();
    v15 = DNA::Database::GetSchema(v14, v4->mName);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&v32, (DNA::SchemaType *)v15);
    DNA::PropertyBagWrapper::AddPropertyBag(&v32, v13);
    v16 = v5->mObjectStack.size;
    v17 = v16 + 1;
    v18 = v5->mObjectStack.capacity;
    v19 = 1;
    if ( (signed int)v16 + 1 > v18 )
    {
      if ( v18 )
        v20 = 2 * v18;
      else
        v20 = 1;
      for ( ; v20 < v17; v20 *= 2 )
        ;
      if ( v20 <= 2 )
        v20 = 2;
      if ( v20 - v17 > 0x10000 )
        v20 = v16 + 65537;
      if ( v20 != (_DWORD)v16 )
      {
        v21 = 8i64 * v20;
        if ( !is_mul_ok(v20, 8ui64) )
          v21 = -1i64;
        v22 = UFG::qMalloc(v21, "qArray.Add", 0i64);
        v23 = (DNA::PropertyBag **)v22;
        if ( v5->mObjectStack.p )
        {
          v24 = 0i64;
          if ( v5->mObjectStack.size )
          {
            do
            {
              v22[v24] = (UFG::allocator::free_link)v5->mObjectStack.p[v24];
              v24 = (unsigned int)(v24 + 1);
            }
            while ( (unsigned int)v24 < v5->mObjectStack.size );
          }
          operator delete[](v5->mObjectStack.p);
        }
        v5->mObjectStack.p = v23;
        v5->mObjectStack.capacity = v20;
        v13 = v33;
      }
    }
    v5->mObjectStack.size = v17;
    v5->mObjectStack.p[v16] = v13;
    UFG::qString::qString(&v29);
    v25 = v5->mAllCreatedBags.size;
    v26 = v25 + 1;
    v27 = v5->mAllCreatedBags.capacity;
    if ( (signed int)v25 + 1 > v27 )
    {
      if ( v27 )
        v19 = 2 * v27;
      for ( ; v19 < v26; v19 *= 2 )
        ;
      if ( v19 - v26 > 0x10000 )
        v19 = v25 + 65537;
      UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(&v5->mAllCreatedBags, v19, "qArray.Add");
    }
    v5->mAllCreatedBags.size = v26;
    v28 = &v5->mAllCreatedBags.p[v25];
    v28->mType = v4;
    v28->mData = v3;
    v28->mProperties = v13;
    UFG::qString::Set(&v28->mName, v29.mData, v29.mLength, 0i64, 0);
    UFG::qString::~qString(&v29);
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&v32);
    UFG::qString::~qString(&v31);
  }
}

// File Line: 559
// RVA: 0x1AE2C0
bool __fastcall DNA::DNAPropertyBagSerializer::DiscoverObjectField(DNA::DNAPropertyBagSerializer *this, UFG::qReflectField *reflection_field, UFG::qReflectType *reflection_type, const char *object_data)
{
  unsigned int v4; // eax

  v4 = reflection_field->mFlags;
  return !(v4 & 8) && (v4 & 0x80u) == 0;
}

// File Line: 570
// RVA: 0x1ADED0
char __fastcall DNA::DNAPropertyBagSerializer::BeginObjectField(DNA::DNAPropertyBagSerializer *this, UFG::qReflectField *reflection_field, UFG::qReflectType *reflection_type, const char *object_data)
{
  const char *v4; // rbp
  UFG::qReflectType *v5; // r12
  UFG::qReflectField *v6; // r13
  DNA::DNAPropertyBagSerializer *v7; // rbx
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v8; // r14
  __int64 v9; // r10
  DNA::PropertyBag *v10; // rdi
  unsigned int v11; // eax
  UFG::qTree64Base *v12; // rax
  unsigned __int64 v13; // rcx
  signed int v14; // esi
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *v15; // r15
  DNA::PropertyWrapper *v16; // rax
  DNA::PropertyBag *v17; // rsi
  __int64 v18; // rbp
  unsigned int v19; // ebx
  unsigned int v20; // edx
  unsigned int v21; // edx
  __int64 v22; // rax
  __int64 v23; // rsi
  unsigned int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  DNA::DNAPropertyBagSerializer::CreateContext *v27; // rcx
  char result; // al
  UFG::qTree64Base *v29; // rax
  unsigned __int64 v30; // rsi
  unsigned __int64 v31; // r14
  unsigned int v32; // edi
  __int64 v33; // rax
  __int64 v34; // [rsp+30h] [rbp-C8h]
  signed __int64 v35; // [rsp+38h] [rbp-C0h]
  DNA::PropertyBagWrapper wrapper; // [rsp+40h] [rbp-B8h]
  UFG::qReflectType *v37; // [rsp+70h] [rbp-88h]
  const char *v38; // [rsp+78h] [rbp-80h]
  DNA::PropertyBag *v39; // [rsp+80h] [rbp-78h]
  UFG::qString v40; // [rsp+88h] [rbp-70h]
  __int64 v41; // [rsp+B0h] [rbp-48h]
  signed int v42; // [rsp+100h] [rbp+8h]
  DNA::PropertyBagWrapper *v; // [rsp+108h] [rbp+10h]

  v41 = -2i64;
  v4 = object_data;
  v5 = reflection_type;
  v6 = reflection_field;
  v7 = this;
  v8 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mObjectStack;
  v9 = this->mObjectStack.size - 1;
  v10 = this->mObjectStack.p[v9];
  v11 = reflection_field->mFlags;
  if ( v11 & 8 || (v11 & 0x80u) != 0 )
  {
    v29 = DNA::PropertyBag::GetSchemaType(this->mObjectStack.p[v9]);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)v29);
    DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, v10);
    v30 = v6->mArrayLength;
    v31 = v5->mNumBytes;
    v32 = 0;
    if ( v30 )
    {
      v33 = 0i64;
      do
      {
        DNA::DNAPropertyBagSerializer::WriteSimpleType(v7, &wrapper, v6, v5, v32++, &v4[v31 * v33]);
        v33 = v32;
      }
      while ( v32 < v30 );
    }
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
    result = 0;
  }
  else
  {
    v12 = DNA::PropertyBag::GetSchemaType(this->mObjectStack.p[v9]);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)v12);
    DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, v10);
    v13 = v5->mNumBytes;
    v14 = v6->mArrayLength - 1;
    v42 = v14;
    if ( v14 >= 0 )
    {
      v15 = &v7->mAllCreatedBags;
      v35 = -(signed __int64)v13;
      v34 = (__int64)&v4[v13 * v14];
      do
      {
        v16 = DNA::PropertyBagWrapper::GetProperty(&wrapper, v6->mName);
        v = 0i64;
        DNA::PropertyWrapper::Get(v16, v14, &v, 0);
        v17 = *v->mPropertyBags.p;
        v18 = v8->size;
        v19 = v18 + 1;
        v20 = v8->capacity;
        if ( (signed int)v18 + 1 > v20 )
        {
          if ( v20 )
            v21 = 2 * v20;
          else
            v21 = 1;
          for ( ; v21 < v19; v21 *= 2 )
            ;
          if ( v21 <= 2 )
            v21 = 2;
          if ( v21 - v19 > 0x10000 )
            v21 = v18 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v8, v21, "qArray.Add");
        }
        v8->size = v19;
        v8->p[v18] = (UFG::qReflectInventoryBase *)v17;
        UFG::qString::qString(&v40);
        v22 = (__int64)v5;
        v37 = v5;
        v38 = (const char *)v34;
        v39 = v17;
        v23 = v15->size;
        v24 = v23 + 1;
        v25 = v15->capacity;
        if ( (signed int)v23 + 1 > v25 )
        {
          if ( v25 )
            v26 = 2 * v25;
          else
            v26 = 1;
          for ( ; v26 < v24; v26 *= 2 )
            ;
          if ( v26 - v24 > 0x10000 )
            v26 = v23 + 65537;
          UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(v15, v26, "qArray.Add");
          v22 = (__int64)v37;
        }
        v15->size = v24;
        v27 = &v15->p[v23];
        v27->mType = (UFG::qReflectType *)v22;
        v27->mData = v38;
        v27->mProperties = v39;
        UFG::qString::Set(&v27->mName, v40.mData, v40.mLength, 0i64, 0);
        UFG::qString::~qString(&v40);
        v14 = v42 - 1;
        v42 = v14;
        v34 += v35;
      }
      while ( v14 >= 0 );
    }
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
    result = 1;
  }
  return result;
}

// File Line: 626
// RVA: 0x1AD850
bool __fastcall DNA::DNAPropertyBagSerializer::BeginArrayField(DNA::DNAPropertyBagSerializer *this, UFG::qReflectField *reflection_field, UFG::qReflectType *reflection_type, const char *object_data)
{
  UFG::qArray<DNA::DNAPropertyBagSerializer::ArrayContext,0> *v4; // rdi
  signed __int64 v5; // rsi
  const char *v6; // r14
  DNA::PropertyBag *v7; // rbp
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  DNA::DNAPropertyBagSerializer::ArrayContext *v11; // rax
  signed __int64 v12; // rcx

  v4 = &this->mArrayContexts;
  v5 = this->mArrayContexts.size;
  v6 = object_data;
  v7 = this->mObjectStack.p[this->mObjectStack.size - 1];
  v8 = this->mArrayContexts.capacity;
  v9 = v5 + 1;
  if ( (signed int)v5 + 1 > v8 )
  {
    if ( v8 )
      v10 = 2 * v8;
    else
      v10 = 1;
    for ( ; v10 < v9; v10 *= 2 )
      ;
    if ( v10 - v9 > 0x10000 )
      v10 = v5 + 65537;
    UFG::qArray<DNA::DNAPropertyBagSerializer::ArrayContext,0>::Reallocate(v4, v10, "qArray.Add");
  }
  v11 = v4->p;
  v4->size = v9;
  v12 = v5;
  v11[v12].mData = v6;
  v11[v12].mProperties = v7;
  return 0;
}

// File Line: 635
// RVA: 0x1AD320
__int64 __fastcall DNA::DNAPropertyBagSerializer::BeginArray(DNA::DNAPropertyBagSerializer *this, UFG::qReflectVisitor::ArrayData *array_data)
{
  UFG::qReflectVisitor::ArrayData *v2; // r14
  DNA::DNAPropertyBagSerializer *v3; // rsi
  unsigned int v4; // er12
  int v5; // edx
  unsigned int v6; // ecx
  DNA::DNAPropertyBagSerializer::ArrayContext *v7; // r8
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v8; // r15
  __int64 v9; // rcx
  unsigned int v10; // edi
  unsigned int v11; // ebx
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  DNA::PropertyBag **v15; // r13
  unsigned int i; // er9
  UFG::qTree64Base *v17; // rax
  UFG::qReflectType *v18; // rbx
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int j; // edi
  signed __int64 v22; // r15
  unsigned __int64 v23; // rbx
  UFG::ReflectionDB *v24; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v25; // rax
  unsigned int v26; // ecx
  unsigned int v27; // edx
  unsigned __int64 v28; // rbx
  DNA::PropertyWrapper *v29; // rax
  DNA::PropertyWrapper *v30; // r10
  unsigned __int64 v31; // rax
  signed int v32; // ecx
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *v33; // r13
  unsigned __int64 v34; // rdx
  const char *v35; // rbx
  DNA::PropertyBag **v36; // rcx
  DNA::PropertyBag *v37; // rdi
  unsigned __int64 id; // r13
  unsigned __int64 v39; // rsi
  UFG::qString *v40; // rbx
  UFG::qString *v41; // rax
  const char *v42; // rbx
  const char *v43; // rdi
  DNA::Database *v44; // rax
  __int64 v45; // rsi
  unsigned int v46; // ebx
  unsigned int v47; // edx
  unsigned int v48; // edx
  UFG::qReflectType *v49; // rax
  __int64 v50; // rdi
  unsigned int v51; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edx
  DNA::DNAPropertyBagSerializer::CreateContext *v54; // rcx
  unsigned __int8 v55; // bl
  unsigned __int64 v56; // rbx
  unsigned __int64 v58; // [rsp+30h] [rbp-D0h]
  DNA::PropertyWrapper *v59; // [rsp+38h] [rbp-C8h]
  const char *v60; // [rsp+40h] [rbp-C0h]
  signed __int64 v61; // [rsp+48h] [rbp-B8h]
  UFG::qReflectType *v62; // [rsp+50h] [rbp-B0h]
  DNA::PropertyBag *v63; // [rsp+60h] [rbp-A0h]
  UFG::qString v64; // [rsp+68h] [rbp-98h]
  DNA::PropertyBagWrapper wrapper; // [rsp+90h] [rbp-70h]
  __int64 v66; // [rsp+B8h] [rbp-48h]
  UFG::qString result; // [rsp+C0h] [rbp-40h]
  UFG::qString v68; // [rsp+E8h] [rbp-18h]
  unsigned int v69; // [rsp+160h] [rbp+60h]
  DNA::PropertyWrapper *v70; // [rsp+160h] [rbp+60h]
  unsigned int v71; // [rsp+160h] [rbp+60h]
  DNA::PropertyBag *propertyBag; // [rsp+168h] [rbp+68h]
  int propertyBaga; // [rsp+168h] [rbp+68h]
  DNA::PropertyBagWrapper *v; // [rsp+170h] [rbp+70h]
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *v75; // [rsp+178h] [rbp+78h]

  v66 = -2i64;
  v2 = array_data;
  v3 = this;
  v4 = 0;
  propertyBag = 0i64;
  v5 = 0;
  v6 = this->mArrayContexts.size;
  if ( v6 )
  {
    v7 = v3->mArrayContexts.p;
    while ( v7[v5].mData != (const char *)v2->mArrayLocation )
    {
      if ( ++v5 >= v6 )
        goto LABEL_7;
    }
    propertyBag = v7[v5].mProperties;
  }
LABEL_7:
  v8 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v3->mObjectStack;
  v9 = v3->mObjectStack.size;
  v69 = v9;
  v10 = v9 + 1;
  v11 = v3->mObjectStack.capacity;
  if ( (signed int)v9 + 1 > v11 )
  {
    if ( v11 )
      v12 = 2 * v11;
    else
      v12 = 1;
    for ( ; v12 < v10; v12 *= 2 )
      ;
    if ( v12 <= 2 )
      v12 = 2;
    if ( v12 - v10 > 0x10000 )
      v12 = v9 + 65537;
    if ( v12 != (_DWORD)v9 )
    {
      v13 = 8i64 * v12;
      if ( !is_mul_ok(v12, 8ui64) )
        v13 = -1i64;
      v14 = UFG::qMalloc(v13, "qArray.Add", 0i64);
      v15 = (DNA::PropertyBag **)v14;
      if ( v3->mObjectStack.p )
      {
        for ( i = 0; i < v8->size; ++i )
          v14[i] = (UFG::allocator::free_link)v3->mObjectStack.p[i];
        operator delete[](v3->mObjectStack.p);
      }
      v3->mObjectStack.p = v15;
      v3->mObjectStack.capacity = v12;
      v9 = v69;
    }
  }
  v8->size = v10;
  v3->mObjectStack.p[v9] = propertyBag;
  v17 = DNA::PropertyBag::GetSchemaType(propertyBag);
  DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)v17);
  DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, propertyBag);
  v18 = v2->mSubType;
  v19 = v18->mFlags;
  if ( v19 & 1 || v19 & 8 || (v19 & 0x80u) != 0 )
  {
    v56 = v18->mNumBytes;
    if ( v2->mArraySize )
    {
      do
      {
        DNA::DNAPropertyBagSerializer::WriteSimpleType(
          v3,
          &wrapper,
          v2->mOwnerField,
          v2->mSubType,
          v4,
          &v2->mArrayData[v56 * v4]);
        ++v4;
      }
      while ( v4 < v2->mArraySize );
    }
LABEL_69:
    v55 = 0;
    goto LABEL_70;
  }
  v20 = v2->mArrayField->mFlags;
  if ( _bittest((const signed int *)&v20, 0xEu) )
  {
    if ( v20 & 0x10 )
    {
      v70 = DNA::PropertyBagWrapper::GetProperty(&wrapper, v2->mOwnerField->mName);
      for ( j = 0; j < v2->mArraySize; ++j )
      {
        v22 = (signed __int64)&v2->mArrayData[8 * j];
        v23 = *(_QWORD *)(*(_QWORD *)v22 + 56i64);
        v24 = UFG::ReflectionDB::Instance();
        v25 = UFG::ReflectionDB::GetType(v24, v23);
        v26 = 0;
        v27 = v3->mAllCreatedBags.size;
        if ( v27 )
        {
          while ( 1 )
          {
            v28 = (unsigned __int64)&v3->mAllCreatedBags.p[(unsigned __int64)v26];
            if ( *(_QWORD *)(v28 + 8) == *(_QWORD *)v22
              && *(UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> **)v28 == v25 )
            {
              break;
            }
            if ( ++v26 >= v27 )
              goto LABEL_37;
          }
          DNA::PropertyBag::SetOwner(*(DNA::PropertyBag **)(v28 + 16), propertyBag);
          DNA::PropertyWrapper::Set(v70, j, *(DNA::PropertyBag **)(v28 + 16), 0);
        }
LABEL_37:
        ;
      }
    }
    goto LABEL_69;
  }
  v29 = DNA::PropertyBagWrapper::GetProperty(&wrapper, v2->mOwnerField->mName);
  v30 = v29;
  v59 = v29;
  LODWORD(v29) = v2->mArrayField->mFlags >> 4;
  LOBYTE(v29) = (unsigned __int8)v29 & 1;
  propertyBaga = (signed int)v29;
  v31 = v2->mSubType->mNumBytes;
  v32 = v2->mArraySize - 1;
  v71 = v32;
  if ( v32 >= 0 )
  {
    v33 = &v3->mAllCreatedBags;
    v75 = &v3->mAllCreatedBags;
    v34 = v31 * v32;
    v58 = v31 * v32;
    v61 = -(signed __int64)v31;
    do
    {
      v35 = &v2->mArrayData[v34];
      v60 = &v2->mArrayData[v34];
      v = 0i64;
      DNA::PropertyWrapper::Get(v30, v32, &v, 0);
      v36 = v->mPropertyBags.p;
      v37 = *v36;
      if ( (_BYTE)propertyBaga == 1 )
      {
        id = *((_QWORD *)v35 + 1);
        if ( id - 1 <= 0xFFFFFFFFFFFFFFFDui64 )
        {
          v39 = DNA::PropertyBag::GetOwnerUID(*v36);
          v40 = DNA::PropertyBag::GetSchemaName(v37, &result);
          v41 = DNA::PropertyBag::GetName(v37, &v68);
          v42 = v40->mData;
          v43 = v41->mData;
          DNA::Database::Instance();
          v37 = DNA::Database::CreateBag(v44, v43, v42, &customWorldMapCaption, id);
          UFG::qString::~qString(&v68);
          UFG::qString::~qString(&result);
          DNA::PropertyBag::SetOwnerUID(v37, v39);
          DNA::PropertyWrapper::Set(v59, v71, v37, 0);
        }
        v33 = v75;
      }
      v45 = v8->size;
      v46 = v45 + 1;
      v47 = v8->capacity;
      if ( (signed int)v45 + 1 > v47 )
      {
        if ( v47 )
          v48 = 2 * v47;
        else
          v48 = 1;
        for ( ; v48 < v46; v48 *= 2 )
          ;
        if ( v48 <= 2 )
          v48 = 2;
        if ( v48 - v46 > 0x10000 )
          v48 = v45 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v8, v48, "qArray.Add");
      }
      v8->size = v46;
      v8->p[v45] = (UFG::qReflectInventoryBase *)v37;
      UFG::qString::qString(&v64);
      v49 = v2->mSubType;
      v62 = v2->mSubType;
      v63 = v37;
      v50 = v33->size;
      v51 = v50 + 1;
      v52 = v33->capacity;
      if ( (signed int)v50 + 1 > v52 )
      {
        if ( v52 )
          v53 = 2 * v52;
        else
          v53 = 1;
        for ( ; v53 < v51; v53 *= 2 )
          ;
        if ( v53 - v51 > 0x10000 )
          v53 = v50 + 65537;
        UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(v33, v53, "qArray.Add");
        v49 = v62;
      }
      v33->size = v51;
      v54 = &v33->p[v50];
      v54->mType = v49;
      v54->mData = v60;
      v54->mProperties = v63;
      UFG::qString::Set(&v54->mName, v64.mData, v64.mLength, 0i64, 0);
      UFG::qString::~qString(&v64);
      v32 = v71 - 1;
      v71 = v32;
      v34 = v61 + v58;
      v58 += v61;
      v30 = v59;
    }
    while ( v32 >= 0 );
  }
  v55 = 1;
LABEL_70:
  DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
  return v55;
}

// File Line: 739
// RVA: 0x1AE2E0
void __fastcall DNA::DNAPropertyBagSerializer::EndObject(DNA::DNAPropertyBagSerializer *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  __int64 v3; // r8
  __int64 v4; // r9
  unsigned int v5; // eax

  v3 = (signed int)this->mObjectStack.size;
  if ( (_DWORD)v3 != this->mObjectStack.size )
  {
    v4 = v3;
    do
    {
      LODWORD(v3) = v3 + 1;
      ++v4;
      this->mObjectStack.p[v4 - 2] = this->mObjectStack.p[v4 - 1];
    }
    while ( (_DWORD)v3 != this->mObjectStack.size );
  }
  v5 = this->mObjectStack.size;
  if ( v5 > 1 )
    this->mObjectStack.size = v5 - 1;
  else
    this->mObjectStack.size = 0;
}

// File Line: 745
// RVA: 0x1AD900
void __fastcall DNA::DNAPropertyBagSerializer::BeginBytes(DNA::DNAPropertyBagSerializer *this, UFG::qReflectField *reflection_field, UFG::qReflectType *reflection_type, const char *data)
{
  char *v4; // rdi
  UFG::qReflectType *v5; // r15
  UFG::qReflectField *v6; // r13
  DNA::PropertyBag *v7; // rbx
  UFG::qTree64Base *v8; // rax
  unsigned __int64 v9; // r12
  unsigned int v10; // esi
  DNA::PropertyWrapper *v11; // rax
  DNA::PropertyWrapper *v12; // r14
  unsigned int v13; // ecx
  __int64 v14; // rbp
  unsigned __int64 v15; // rcx
  const char *v16; // rbx
  UFG::ReflectionDB *v17; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v18; // rax
  UFG::qTree64Base::BaseNode *v19; // rdx
  signed __int64 v20; // rax
  const char *v21; // r8
  unsigned int v22; // eax
  char *v23; // rax
  unsigned __int64 v24; // rax
  UFG::qString v25; // [rsp+20h] [rbp-A8h]
  __int64 v26; // [rsp+48h] [rbp-80h]
  UFG::qString v27; // [rsp+50h] [rbp-78h]
  DNA::PropertyBagWrapper v28; // [rsp+78h] [rbp-50h]
  unsigned __int64 v29; // [rsp+D0h] [rbp+8h]

  v26 = -2i64;
  v4 = (char *)data;
  v5 = reflection_type;
  v6 = reflection_field;
  v7 = this->mObjectStack.p[this->mObjectStack.size - 1];
  v8 = DNA::PropertyBag::GetSchemaType(v7);
  DNA::PropertyBagWrapper::PropertyBagWrapper(&v28, (DNA::SchemaType *)v8);
  DNA::PropertyBagWrapper::AddPropertyBag(&v28, v7);
  v9 = v6->mArrayLength;
  v29 = v5->mNumBytes;
  v10 = 0;
  if ( v9 )
  {
    do
    {
      v11 = DNA::PropertyBagWrapper::GetProperty(&v28, v6->mName);
      v12 = v11;
      v13 = v5->mFlags;
      if ( v13 & 4 )
      {
        v14 = 0i64;
        v15 = v5->mNumBytes;
        if ( v15 == 4 )
        {
          v14 = *(signed int *)v4;
        }
        else if ( v15 == 8 )
        {
          v14 = *(_QWORD *)v4;
        }
        UFG::qString::qString(&v27);
        v16 = v5->mName;
        v17 = UFG::ReflectionDB::Instance();
        v18 = UFG::ReflectionDB::GetEnum(v17, v16);
        if ( v18
          && (v19 = v18[1].mTree.mHead.mChildren[0],
              v20 = (signed __int64)&v18[1].mTree.mHead.mParent,
              v19 != (UFG::qTree64Base::BaseNode *)v20) )
        {
          while ( (UFG::qTree64Base::BaseNode *)v14 != v19->mNeighbours[0] )
          {
            v19 = v19->mParent;
            if ( v19 == (UFG::qTree64Base::BaseNode *)v20 )
              goto LABEL_13;
          }
          UFG::qString::Set(&v27, (const char *)v19->mChildren[0]);
        }
        else
        {
LABEL_13:
          UFG::qPrintf(
            "Warning: DNAPacker.exe could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
            v6->mName,
            v5->mName);
        }
        DNA::PropertyWrapper::Set(v12, v10, v27.mData, 0);
        UFG::qString::~qString(&v27);
      }
      else if ( v13 & 8 )
      {
        if ( *((_DWORD *)v4 + 2) )
          v21 = *(const char **)v4;
        else
          v21 = &customWorldMapCaption;
        DNA::PropertyWrapper::Set(v11, v10, v21, 0);
      }
      else if ( (v13 & 0x80u) == 0 )
      {
        v24 = v5->mNameUID;
        if ( v24 == DNA::kBasicTypeUID_long_long )
        {
          DNA::PropertyWrapper::Set(v12, v10, *(_QWORD *)v4, 0);
        }
        else if ( v24 == DNA::kBasicTypeUID_long || v24 == DNA::kBasicTypeUID_int )
        {
          DNA::PropertyWrapper::Set(v12, v10, *(_DWORD *)v4, 0);
        }
        else if ( v24 == DNA::kBasicTypeUID_unsigned_long_long )
        {
          DNA::PropertyWrapper::Set(v12, v10, *(_QWORD *)v4, 0);
        }
        else if ( v24 == DNA::kBasicTypeUID_unsigned_long || v24 == DNA::kBasicTypeUID_unsigned_int )
        {
          DNA::PropertyWrapper::Set(v12, v10, *(_DWORD *)v4, 0);
        }
        else if ( v24 == DNA::kBasicTypeUID_float )
        {
          DNA::PropertyWrapper::Set(v12, v10, *(float *)v4, 0);
        }
        else if ( v24 == DNA::kBasicTypeUID_bool || v24 != DNA::kBasicTypeUID_void && v24 == DNA::kBasicTypeUID_char )
        {
          DNA::PropertyWrapper::Set(v12, v10, *v4, 0);
        }
      }
      else
      {
        UFG::qString::qString(&v25);
        v22 = v5->mFlags;
        if ( _bittest((const signed int *)&v22, 8u) )
        {
          v23 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
        }
        else if ( _bittest((const signed int *)&v22, 9u) )
        {
          v23 = (char *)UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)v4);
        }
        else
        {
          v23 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v4);
        }
        UFG::qString::Set(&v25, v23);
        DNA::PropertyWrapper::Set(v12, v10, v25.mData, 0);
        UFG::qString::~qString(&v25);
      }
      v4 += v29;
      ++v10;
    }
    while ( v10 < v9 );
  }
  DNA::PropertyBagWrapper::~PropertyBagWrapper(&v28);
}

// File Line: 763
// RVA: 0x1AECA0
void __fastcall DNA::DNAPropertyBagSerializer::WriteSimpleType(DNA::DNAPropertyBagSerializer *this, DNA::PropertyBagWrapper *wrapper, UFG::qReflectField *field, UFG::qReflectType *reflection_type, unsigned int array_index, const char *element_data)
{
  UFG::qReflectType *v6; // rbp
  UFG::qReflectField *v7; // r14
  DNA::PropertyWrapper *v8; // rdi
  unsigned int v9; // eax
  __int64 v10; // rsi
  unsigned __int64 v11; // rax
  const char *v12; // rbx
  UFG::ReflectionDB *v13; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v14; // rax
  UFG::qTree64Base::BaseNode *v15; // rdx
  signed __int64 v16; // rax
  const char *v17; // r8
  unsigned int v18; // eax
  char *v19; // rax
  unsigned __int64 v20; // rax
  UFG::qString v21; // [rsp+28h] [rbp-30h]

  v6 = reflection_type;
  v7 = field;
  v8 = DNA::PropertyBagWrapper::GetProperty(wrapper, field->mName);
  v9 = v6->mFlags;
  if ( v9 & 4 )
  {
    v10 = 0i64;
    v11 = v6->mNumBytes;
    if ( v11 == 4 )
    {
      v10 = *(signed int *)element_data;
    }
    else if ( v11 == 8 )
    {
      v10 = *(_QWORD *)element_data;
    }
    UFG::qString::qString(&v21);
    v12 = v6->mName;
    v13 = UFG::ReflectionDB::Instance();
    v14 = UFG::ReflectionDB::GetEnum(v13, v12);
    if ( v14
      && (v15 = v14[1].mTree.mHead.mChildren[0],
          v16 = (signed __int64)&v14[1].mTree.mHead.mParent,
          v15 != (UFG::qTree64Base::BaseNode *)v16) )
    {
      while ( (UFG::qTree64Base::BaseNode *)v10 != v15->mNeighbours[0] )
      {
        v15 = v15->mParent;
        if ( v15 == (UFG::qTree64Base::BaseNode *)v16 )
          goto LABEL_12;
      }
      UFG::qString::Set(&v21, (const char *)v15->mChildren[0]);
    }
    else
    {
LABEL_12:
      UFG::qPrintf(
        "Warning: DNAPacker.exe could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
        v7->mName,
        v6->mName);
    }
    DNA::PropertyWrapper::Set(v8, array_index, v21.mData, 0);
    UFG::qString::~qString(&v21);
  }
  else if ( v9 & 8 )
  {
    if ( *((_DWORD *)element_data + 2) )
      v17 = *(const char **)element_data;
    else
      v17 = &customWorldMapCaption;
    DNA::PropertyWrapper::Set(v8, array_index, v17, 0);
  }
  else if ( (v9 & 0x80u) == 0 )
  {
    v20 = v6->mNameUID;
    if ( v20 == DNA::kBasicTypeUID_long_long )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *(_QWORD *)element_data, 0);
    }
    else if ( v20 == DNA::kBasicTypeUID_long || v20 == DNA::kBasicTypeUID_int )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *(_DWORD *)element_data, 0);
    }
    else if ( v20 == DNA::kBasicTypeUID_unsigned_long_long )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *(_QWORD *)element_data, 0);
    }
    else if ( v20 == DNA::kBasicTypeUID_unsigned_long || v20 == DNA::kBasicTypeUID_unsigned_int )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *(_DWORD *)element_data, 0);
    }
    else if ( v20 == DNA::kBasicTypeUID_float )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *(float *)element_data, 0);
    }
    else if ( v20 == DNA::kBasicTypeUID_bool || v20 != DNA::kBasicTypeUID_void && v20 == DNA::kBasicTypeUID_char )
    {
      DNA::PropertyWrapper::Set(v8, array_index, *element_data, 0);
    }
  }
  else
  {
    UFG::qString::qString(&v21);
    v18 = v6->mFlags;
    if ( _bittest((const signed int *)&v18, 8u) )
    {
      v19 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)element_data);
    }
    else if ( _bittest((const signed int *)&v18, 9u) )
    {
      v19 = (char *)UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)element_data);
    }
    else
    {
      v19 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)element_data);
    }
    UFG::qString::Set(&v21, v19);
    DNA::PropertyWrapper::Set(v8, array_index, v21.mData, 0);
    UFG::qString::~qString(&v21);
  }
}

// File Line: 873
// RVA: 0x14699F0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_long_long__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("long long", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_long_long = result;
  return result;
}

// File Line: 874
// RVA: 0x14699D0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_long__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("long", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_long = result;
  return result;
}

// File Line: 875
// RVA: 0x14699B0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_int__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("int", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_int = result;
  return result;
}

// File Line: 876
// RVA: 0x1469A30
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_short__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("short", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_short = result;
  return result;
}

// File Line: 877
// RVA: 0x1469AB0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_unsigned_long_long__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("unsigned long long", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_unsigned_long_long = result;
  return result;
}

// File Line: 878
// RVA: 0x1469A90
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_unsigned_long__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("unsigned long", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_unsigned_long = result;
  return result;
}

// File Line: 879
// RVA: 0x1469A70
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_unsigned_int__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("unsigned int", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_unsigned_int = result;
  return result;
}

// File Line: 880
// RVA: 0x1469AD0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_unsigned_short__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("unsigned short", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_unsigned_short = result;
  return result;
}

// File Line: 881
// RVA: 0x1469A50
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_unsigned_char__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("unsigned char", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_unsigned_char = result;
  return result;
}

// File Line: 882
// RVA: 0x1469990
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_float__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("float", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_float = result;
  return result;
}

// File Line: 883
// RVA: 0x1469970
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_double__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("double", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_double = result;
  return result;
}

// File Line: 884
// RVA: 0x1469A10
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_pointer__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("pointer", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_pointer = result;
  return result;
}

// File Line: 885
// RVA: 0x1469930
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_bool__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("bool", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_bool = result;
  return result;
}

// File Line: 886
// RVA: 0x1469AF0
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_void__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("void", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_void = result;
  return result;
}

// File Line: 887
// RVA: 0x1469950
unsigned __int64 DNA::_dynamic_initializer_for__kBasicTypeUID_char__()
{
  unsigned __int64 result; // rax

  result = UFG::qStringHash64("char", 0xFFFFFFFFFFFFFFFFui64);
  DNA::kBasicTypeUID_char = result;
  return result;
}

// File Line: 939
// RVA: 0x1AEF80
__int64 __fastcall DNA::WriteToBuffer(UFG::qReflectObject *object, const char *name, const char **buffer, unsigned int *buffer_size)
{
  unsigned int *v4; // r14
  const char **v5; // r15
  const char *v6; // rsi
  UFG::qReflectObject *v7; // rdi
  unsigned __int64 v8; // rbx
  UFG::ReflectionDB *v9; // rax
  UFG::qReflectType *v10; // rax
  DNA::Database *v11; // rax
  DNA::PropertyBag *v12; // rbx
  DNA::Database *v13; // rax
  DNA::Database *v14; // rax
  unsigned __int8 v15; // di
  DNA::PropertyBagHandle *i; // rbx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v17; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *v18; // rax
  UFG::qReflectType *v19; // rcx
  UFG::qReflectVisitor::ObjectData *v20; // rax
  UFG::qReflectVisitor v22; // [rsp+18h] [rbp-79h]
  UFG::qString v23; // [rsp+50h] [rbp-41h]
  __int64 v24; // [rsp+78h] [rbp-19h]
  __int64 v25; // [rsp+80h] [rbp-11h]
  __int64 v26; // [rsp+88h] [rbp-9h]
  __int64 v27; // [rsp+90h] [rbp-1h]
  __int64 v28; // [rsp+98h] [rbp+7h]
  __int64 v29; // [rsp+A0h] [rbp+Fh]
  __int64 v30; // [rsp+A8h] [rbp+17h]
  UFG::qString namea; // [rsp+B0h] [rbp+1Fh]
  DNA::Query query; // [rsp+F8h] [rbp+67h]

  v30 = -2i64;
  v4 = buffer_size;
  v5 = buffer;
  v6 = name;
  v7 = object;
  v22.mTrackedObjects.p = 0i64;
  *(_QWORD *)&v22.mTrackedObjects.size = 0i64;
  v22.mPatches.p = 0i64;
  *(_QWORD *)&v22.mPatches.size = 0i64;
  v22.mArrays.p = 0i64;
  *(_QWORD *)&v22.mArrays.size = 0i64;
  UFG::qString::qString(&v23);
  v25 = 0i64;
  v24 = 0i64;
  v27 = 0i64;
  v26 = 0i64;
  v29 = 0i64;
  v28 = 0i64;
  v8 = v7->mTypeUID;
  v9 = UFG::ReflectionDB::Instance();
  v10 = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v9, v8);
  UFG::qReflectVisitor::TrackObject(&v22, v10, (const char *)v7);
  UFG::qString::qString(&namea, v6);
  UFG::qReflectVisitor::SetObjectName(&v22, v22.mTrackedObjects.size - 1, &namea);
  UFG::qString::~qString(&namea);
  UFG::qString::Set(&v23, "__WRITE_TO_BUFFER__");
  UFG::qReflectVisitor::VisitObjects(&v22);
  DNA::DNAPropertyBagSerializer::BindChildObjectsToParents((DNA::DNAPropertyBagSerializer *)&v22);
  query.mRoot = DNA::Query::FilePath("__WRITE_TO_BUFFER__");
  *(_QWORD *)&v22.mTrackedObjects.size = (char *)&v22 + 8;
  v22.mTrackedObjects.p = (UFG::qReflectVisitor::ObjectData *)&v22.mTrackedObjects;
  DNA::Database::Instance();
  DNA::Database::GetPropertyBags(
    v11,
    &query,
    (UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *)&v22.mTrackedObjects);
  v12 = DNA::PropertyBagHandle::Get((DNA::PropertyBagHandle *)v22.mTrackedObjects.p);
  DNA::Database::Instance();
  if ( DNA::Database::SaveToBuffer(v13, v5, v4, v12) )
  {
    DNA::Database::Instance();
    DNA::Database::Unload(v14, "__WRITE_TO_BUFFER__");
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
  for ( i = (DNA::PropertyBagHandle *)v22.mTrackedObjects.p;
        (UFG::qArray<UFG::qReflectVisitor::ObjectData,0> *)v22.mTrackedObjects.p != &v22.mTrackedObjects;
        i = (DNA::PropertyBagHandle *)v22.mTrackedObjects.p )
  {
    v17 = i->mPrev;
    v18 = i->mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    i->mPrev = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&i->mPrev;
    i->mNext = (UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *)&i->mPrev;
    DNA::PropertyBagHandle::~PropertyBagHandle(i);
    operator delete[](i);
  }
  v19 = *(UFG::qReflectType **)&v22.mTrackedObjects.size;
  v20 = v22.mTrackedObjects.p;
  *(_QWORD *)(*(_QWORD *)&v22.mTrackedObjects.size + 8i64) = v22.mTrackedObjects.p;
  v20->mReflectionType = v19;
  *(_QWORD *)&v22.mTrackedObjects.size = (char *)&v22 + 8;
  v22.mTrackedObjects.p = (UFG::qReflectVisitor::ObjectData *)&v22.mTrackedObjects;
  if ( query.mRoot )
    ((void (__fastcall *)(DNA::IQueryNode *, signed __int64))query.mRoot->vfptr->~IQueryNode)(query.mRoot, 1i64);
  DNA::DNAPropertyBagSerializer::~DNAPropertyBagSerializer((DNA::DNAPropertyBagSerializer *)&v22);
  return v15;
}

// File Line: 963
// RVA: 0x1AE3C0
char __fastcall DNA::FindEnumValueFromString(const char *enum_name, UFG::qString *string_data, __int64 *value_to_write)
{
  __int64 *v3; // r14
  UFG::qString *v4; // rsi
  const char *v5; // rbx
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v7; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v8; // rbp
  UFG::qTree64Base::BaseNode *v9; // rbx
  signed __int64 v10; // rdi
  __int64 v11; // rax
  UFG::qTree64Base::BaseNode *v12; // rcx

  v3 = value_to_write;
  v4 = string_data;
  v5 = enum_name;
  v6 = UFG::ReflectionDB::Instance();
  v7 = UFG::ReflectionDB::GetEnum(v6, v5);
  v8 = v7;
  if ( !v7 )
    return 0;
  v9 = v7[1].mTree.mHead.mChildren[0];
  v10 = (signed __int64)&v7[1].mTree.mHead.mParent;
  if ( v9 != (UFG::qTree64Base::BaseNode *)&v7[1].mTree.mHead.mParent )
  {
    while ( (unsigned int)UFG::qStringCompare((const char *)v9->mChildren[0], v4->mData, -1) )
    {
      v9 = v9->mParent;
      if ( v9 == (UFG::qTree64Base::BaseNode *)v10 )
        goto LABEL_5;
    }
    goto LABEL_13;
  }
LABEL_5:
  v9 = v8[1].mTree.mHead.mChildren[0];
  if ( v9 == (UFG::qTree64Base::BaseNode *)v10 )
  {
LABEL_8:
    v11 = UFG::qToInt64(v4->mData, 0i64);
    *v3 = v11;
    v12 = v8[1].mTree.mHead.mChildren[0];
    if ( v12 != (UFG::qTree64Base::BaseNode *)v10 )
    {
      while ( (UFG::qTree64Base::BaseNode *)v11 != v12->mNeighbours[0] )
      {
        v12 = v12->mParent;
        if ( v12 == (UFG::qTree64Base::BaseNode *)v10 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  while ( !(unsigned int)UFG::qString::EndsWith(v4, (const char *)v9->mChildren[0], -1) )
  {
    v9 = v9->mParent;
    if ( v9 == (UFG::qTree64Base::BaseNode *)v10 )
      goto LABEL_8;
  }
LABEL_13:
  *v3 = (__int64)v9->mNeighbours[0];
  return 1;
}

// File Line: 1013
// RVA: 0x1AE340
char __fastcall DNA::FindEnumStringFromValue(const char *enum_name, const __int64 *value_to_write, UFG::qString *string_data)
{
  UFG::qString *v3; // rsi
  const __int64 *v4; // rdi
  const char *v5; // rbx
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v7; // rax
  UFG::qTree64Base::BaseNode *v8; // rdx
  signed __int64 v9; // rax

  v3 = string_data;
  v4 = value_to_write;
  v5 = enum_name;
  v6 = UFG::ReflectionDB::Instance();
  v7 = UFG::ReflectionDB::GetEnum(v6, v5);
  if ( !v7 )
    return 0;
  v8 = v7[1].mTree.mHead.mChildren[0];
  v9 = (signed __int64)&v7[1].mTree.mHead.mParent;
  if ( v8 == (UFG::qTree64Base::BaseNode *)v9 )
    return 0;
  while ( (UFG::qTree64Base::BaseNode *)*v4 != v8->mNeighbours[0] )
  {
    v8 = v8->mParent;
    if ( v8 == (UFG::qTree64Base::BaseNode *)v9 )
      return 0;
  }
  UFG::qString::Set(v3, (const char *)v8->mChildren[0]);
  return 1;
}

// File Line: 1030
// RVA: 0x1AE9F0
char __fastcall DNA::IsHidden(UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::qReflectField *v2; // rdi
  UFG::qReflectType *v3; // rbx
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v5; // rbx
  unsigned __int64 v6; // rax
  UFG::qTree64Base *v8; // rbx
  unsigned __int64 v9; // rax
  UFG::qTree64Base *v10; // rax
  char v11; // cl

  v2 = field;
  v3 = type;
  v4 = UFG::ReflectionDB::Instance();
  v5 = UFG::ReflectionDB::GetSchema(v4, v3->mNameUID);
  if ( !v5 )
    return 0;
  v6 = UFG::qStringHash64("IsHidden", 0xFFFFFFFFFFFFFFFFui64);
  if ( UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v5[1].mTree + 8), v6) )
    return 1;
  v8 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v5[2].mTree + 8), v2->mNameUID);
  if ( !v8 )
    return 0;
  v9 = UFG::qStringHash64("IsHidden", 0xFFFFFFFFFFFFFFFFui64);
  v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v8 + 64), v9);
  v11 = 0;
  if ( v10 )
    v11 = 1;
  return v11;
}

// File Line: 1052
// RVA: 0x1AE7A0
__int64 __fastcall DNA::HasEditor(UFG::qReflectType *type, const char *editor)
{
  const char *v2; // rdi
  UFG::qReflectType *v3; // rbx
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v5; // rbx
  unsigned __int64 v6; // rax
  UFG::qTree64Base *v7; // rax
  int v8; // eax
  unsigned __int8 v9; // cl

  v2 = editor;
  v3 = type;
  v4 = UFG::ReflectionDB::Instance();
  v5 = UFG::ReflectionDB::GetSchema(v4, v3->mNameUID);
  if ( !v5 )
    return 0i64;
  v6 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64);
  v7 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v5[1].mTree + 8), v6);
  if ( !v7 )
    return 0i64;
  v8 = UFG::qStringCompare((const char *)v7[1].mHead.mUID, v2, -1);
  v9 = 0;
  if ( !v8 )
    v9 = 1;
  return v9;
}

// File Line: 1067
// RVA: 0x1AE6A0
signed int __fastcall DNA::HasEditor(UFG::qReflectField *field, const char *editor)
{
  const char *v2; // rdi
  UFG::qReflectField *v3; // rsi
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v5; // rbx
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v7; // rbx
  unsigned __int64 v8; // rax
  UFG::qTree64Base *v9; // rax
  UFG::qTree64Base *v11; // rbx
  unsigned __int64 v12; // rax
  UFG::qTree64Base *v13; // rax
  int v14; // eax
  unsigned __int8 v15; // cl

  v2 = editor;
  v3 = field;
  v4 = UFG::ReflectionDB::Instance();
  v5 = UFG::ReflectionDB::GetType(v4, v3->mTypeUID);
  v6 = UFG::ReflectionDB::Instance();
  v7 = UFG::ReflectionDB::GetSchema(v6, (unsigned __int64)v5[1].mTree.mHead.mChildren[0]);
  if ( !v7 )
    return 0;
  v8 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64);
  v9 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v7[1].mTree + 8), v8);
  if ( v9 && !(unsigned int)UFG::qStringCompare((const char *)v9[1].mHead.mUID, v2, -1) )
    return 1;
  v11 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v7[2].mTree + 8), v3->mNameUID);
  if ( !v11 )
    return 0;
  v12 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64);
  v13 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v11 + 64), v12);
  if ( !v13 )
    return 0;
  v14 = UFG::qStringCompare((const char *)v13[1].mHead.mUID, v2, -1);
  v15 = 0;
  if ( !v14 )
    v15 = 1;
  return v15;
}

// File Line: 1095
// RVA: 0x1AE910
char __fastcall DNA::HasRange(UFG::qReflectType *type, UFG::qReflectField *field, float *min, float *max)
{
  float *v4; // rsi
  float *v5; // rbp
  UFG::qReflectField *v6; // rdi
  UFG::qReflectType *v7; // rbx
  UFG::ReflectionDB *v8; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v9; // rax
  UFG::qTree64Base *v10; // rbx
  unsigned __int64 v11; // rax
  UFG::qTree64Base *v12; // rdi
  unsigned __int64 v13; // rax
  UFG::qTree64Base *v14; // rax
  UFG::qTree64Base *v15; // rbx
  float v16; // xmm0_4
  const char *v17; // rcx
  float v18; // xmm0_4
  char result; // al

  v4 = max;
  v5 = min;
  v6 = field;
  v7 = type;
  v8 = UFG::ReflectionDB::Instance();
  v9 = UFG::ReflectionDB::GetSchema(v8, v7->mNameUID);
  if ( !v9 )
    return 0;
  v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v9[2].mTree + 8), v6->mNameUID);
  if ( !v10 )
    return 0;
  v11 = UFG::qStringHash64("Min", 0xFFFFFFFFFFFFFFFFui64);
  v12 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v11);
  v13 = UFG::qStringHash64("Max", 0xFFFFFFFFFFFFFFFFui64);
  v14 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v13);
  v15 = v14;
  if ( !v12 || !v14 )
    return 0;
  v16 = UFG::qToFloat((const char *)v12[1].mHead.mUID, 0.0);
  v17 = (const char *)v15[1].mHead.mUID;
  *v5 = v16;
  v18 = UFG::qToFloat(v17, 0.0);
  result = 1;
  *v4 = v18;
  return result;
}

// File Line: 1117
// RVA: 0x1AE840
char __fastcall DNA::HasRange(UFG::qReflectType *type, UFG::qReflectField *field, int *min, int *max)
{
  int *v4; // rsi
  int *v5; // r14
  UFG::qReflectField *v6; // rdi
  UFG::qReflectType *v7; // rbx
  UFG::ReflectionDB *v8; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v9; // rax
  UFG::qTree64Base *v10; // rbx
  unsigned __int64 v11; // rax
  UFG::qTree64Base *v12; // rdi
  unsigned __int64 v13; // rax
  UFG::qTree64Base *v14; // rax
  UFG::qTree64Base *v15; // rbx

  v4 = max;
  v5 = min;
  v6 = field;
  v7 = type;
  v8 = UFG::ReflectionDB::Instance();
  v9 = UFG::ReflectionDB::GetSchema(v8, v7->mNameUID);
  if ( !v9 )
    return 0;
  v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v9[2].mTree + 8), v6->mNameUID);
  if ( !v10 )
    return 0;
  v11 = UFG::qStringHash64("Min", 0xFFFFFFFFFFFFFFFFui64);
  v12 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v11);
  v13 = UFG::qStringHash64("Max", 0xFFFFFFFFFFFFFFFFui64);
  v14 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v13);
  v15 = v14;
  if ( !v12 || !v14 )
    return 0;
  *v5 = UFG::qToInt32((const char *)v12[1].mHead.mUID, 0);
  *v4 = UFG::qToInt32((const char *)v15[1].mHead.mUID, 0);
  return 1;
}

// File Line: 1139
// RVA: 0x1AE550
UFG::qString *__fastcall DNA::GetDisplayName(UFG::qString *result, UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::qReflectField *v3; // rdi
  UFG::qReflectType *v4; // rbx
  UFG::qString *v5; // rsi
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *v7; // rax
  UFG::qTree64Base *v8; // rbx
  unsigned __int64 v9; // rax
  UFG::qTree64Base *v10; // rax
  char *v11; // rax
  const char *v12; // r10
  char *v13; // rdx
  char v14; // r8
  char v15; // r8
  char format; // [rsp+30h] [rbp-108h]

  v3 = field;
  v4 = type;
  v5 = result;
  v6 = UFG::ReflectionDB::Instance();
  v7 = UFG::ReflectionDB::GetSchema(v6, v4->mNameUID);
  if ( !v7
    || (v8 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)&v7[2].mTree + 8), v3->mNameUID)) == 0i64
    || (v9 = UFG::qStringHash64("DisplayName", 0xFFFFFFFFFFFFFFFFui64),
        (v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v8 + 64), v9)) == 0i64) )
  {
    v11 = &format;
    v12 = v3->mName;
    v13 = (char *)v12;
    if ( !*v12 )
    {
LABEL_21:
      *v11 = 0;
      UFG::qString::qString(v5, &format);
      return v5;
    }
    while ( 1 )
    {
      if ( v13 != v12 || *v13 != 109 )
        goto LABEL_25;
      v14 = v13[1];
      if ( v14 == 95 )
        goto LABEL_11;
      if ( (unsigned __int8)(v14 - 65) > 0x19u )
      {
LABEL_25:
        v15 = *v13;
        if ( *v13 == 95 )
        {
          *v11 = 32;
LABEL_19:
          ++v11;
          goto LABEL_20;
        }
        if ( v11 == &format || (unsigned __int8)(v15 - 97) > 0x19u || (unsigned __int8)(v13[1] - 65) > 0x19u )
        {
          *v11 = v15;
          goto LABEL_19;
        }
        *v11 = v15;
        v11[1] = 32;
        v11 += 2;
      }
      else if ( v14 == 95 )
      {
LABEL_11:
        ++v13;
        goto LABEL_20;
      }
LABEL_20:
      if ( !*++v13 )
        goto LABEL_21;
    }
  }
  UFG::qString::qString(v5, (const char *)v10[1].mHead.mUID);
  return v5;
}

