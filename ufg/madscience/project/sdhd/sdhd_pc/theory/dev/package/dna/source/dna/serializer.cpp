// File Line: 456
// RVA: 0x1AE4B0
__int64 __fastcall DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectType *reflection_type,
        const char *address)
{
  unsigned int v3; // ebx
  DNA::DNAPropertyBagSerializer::CreateContext *v7; // rax
  unsigned __int64 mData; // rcx
  UFG::qReflectType *mType; // rsi
  UFG::ReflectionDB *v10; // rax

  v3 = 0;
  if ( !this->mAllCreatedBags.size )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    v7 = &this->mAllCreatedBags.p[(unsigned __int64)v3];
    mData = (unsigned __int64)v7->mData;
    if ( (unsigned __int64)address >= mData )
    {
      mType = v7->mType;
      if ( (unsigned __int64)address < v7->mType->mNumBytes + mData )
      {
        v10 = UFG::ReflectionDB::Instance();
        if ( UFG::ReflectionDB::IsDerivedFrom(v10, mType->mNameUID, reflection_type->mNameUID) )
          break;
      }
    }
    if ( ++v3 >= this->mAllCreatedBags.size )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 471
// RVA: 0x1AE1B0
void __fastcall DNA::DNAPropertyBagSerializer::BindChildObjectsToParents(DNA::DNAPropertyBagSerializer *this)
{
  unsigned int i; // ebx
  unsigned __int64 v3; // r15
  char *v4; // r14
  int ObjectIndexFromAddress; // edi
  int v6; // eax
  DNA::DNAPropertyBagSerializer::CreateContext *p; // rdx
  DNA::PropertyBag *mProperties; // rsi
  DNA::PropertyBag *v9; // rdi
  UFG::qTree64Base *SchemaType; // rax
  DNA::PropertyWrapper *Property; // rax
  DNA::PropertyBagWrapper v12; // [rsp+28h] [rbp-40h] BYREF

  for ( i = 0; i < this->mPatches.size; ++i )
  {
    v3 = (unsigned __int64)i << 6;
    v4 = (char *)this->mPatches.p + v3;
    ObjectIndexFromAddress = DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(
                               this,
                               *(UFG::qReflectType **)v4,
                               *((const char **)v4 + 4));
    v6 = DNA::DNAPropertyBagSerializer::FindObjectIndexFromAddress(
           this,
           *((UFG::qReflectType **)v4 + 3),
           *((const char **)v4 + 5));
    if ( ObjectIndexFromAddress >= 0 && v6 >= 0 )
    {
      p = this->mAllCreatedBags.p;
      mProperties = p[(unsigned __int64)(unsigned int)ObjectIndexFromAddress].mProperties;
      v9 = p[(unsigned __int64)(unsigned int)v6].mProperties;
      SchemaType = DNA::PropertyBag::GetSchemaType(mProperties);
      DNA::PropertyBagWrapper::PropertyBagWrapper(&v12, (DNA::SchemaType *)SchemaType);
      DNA::PropertyBagWrapper::AddPropertyBag(&v12, mProperties);
      Property = DNA::PropertyBagWrapper::GetProperty(
                   &v12,
                   (*(UFG::qReflectField **)((char *)&this->mPatches.p->mField + v3))->mName);
      DNA::PropertyWrapper::Set(Property, *((_DWORD *)v4 + 4), v9, 0);
      DNA::PropertyBag::SetOwner(v9, mProperties);
      DNA::PropertyBagWrapper::~PropertyBagWrapper(&v12);
    }
  }
}

// File Line: 516
// RVA: 0x1ADBF0
void __fastcall DNA::DNAPropertyBagSerializer::BeginObject(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  DNA::Database *v6; // rax
  unsigned __int64 v7; // rdi
  __int64 v8; // rdx
  unsigned int size; // r8d
  UFG::qReflectVisitor::ObjectData *v10; // rax
  char *mData; // rbx
  DNA::Database *v12; // rax
  DNA::PropertyBag *Bag; // r12
  DNA::Database *v14; // rax
  UFG::qTree64Base *Schema; // rax
  __int64 v16; // r13
  unsigned int v17; // r14d
  unsigned int capacity; // edi
  unsigned int v19; // ebx
  unsigned int v20; // edi
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  DNA::PropertyBag **v23; // r12
  __int64 i; // r9
  __int64 v25; // r14
  unsigned int v26; // edi
  unsigned int v27; // eax
  DNA::DNAPropertyBagSerializer::CreateContext *v28; // rcx
  UFG::qString v29; // [rsp+48h] [rbp-B0h] BYREF
  __int64 v30; // [rsp+70h] [rbp-88h]
  UFG::qString v31; // [rsp+78h] [rbp-80h] BYREF
  DNA::PropertyBagWrapper v32; // [rsp+A0h] [rbp-58h] BYREF
  DNA::PropertyBag *v33; // [rsp+100h] [rbp+8h]

  v30 = -2i64;
  if ( !this->mObjectStack.size )
  {
    DNA::Database::Instance();
    v7 = DNA::Database::GenUID(v6);
    if ( (reflection_type->mFlags & 0x10) != 0 )
      v7 = *((_QWORD *)object_data + 1);
    UFG::qString::qString(&v31, reflection_type->mName);
    v8 = 0i64;
    size = this->mTrackedObjects.size;
    if ( size )
    {
      while ( 1 )
      {
        v10 = &this->mTrackedObjects.p[v8];
        if ( v10->mObjectData == object_data && v10->mReflectionType == reflection_type )
          break;
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= size )
          goto LABEL_10;
      }
      UFG::qString::Set(&v31, v10->mName.mData, v10->mName.mLength, 0i64, 0);
    }
LABEL_10:
    mData = this->mFilePath.mData;
    DNA::Database::Instance();
    Bag = DNA::Database::CreateBag(v12, v31.mData, reflection_type->mName, mData, v7);
    v33 = Bag;
    DNA::Database::Instance();
    Schema = DNA::Database::GetSchema(v14, reflection_type->mName);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&v32, (DNA::SchemaType *)Schema);
    DNA::PropertyBagWrapper::AddPropertyBag(&v32, Bag);
    v16 = this->mObjectStack.size;
    v17 = v16 + 1;
    capacity = this->mObjectStack.capacity;
    v19 = 1;
    if ( (int)v16 + 1 > capacity )
    {
      if ( capacity )
        v20 = 2 * capacity;
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
        if ( this->mObjectStack.p )
        {
          for ( i = 0i64; (unsigned int)i < this->mObjectStack.size; i = (unsigned int)(i + 1) )
            v22[i] = (UFG::allocator::free_link)this->mObjectStack.p[i];
          operator delete[](this->mObjectStack.p);
        }
        this->mObjectStack.p = v23;
        this->mObjectStack.capacity = v20;
        Bag = v33;
      }
    }
    this->mObjectStack.size = v17;
    this->mObjectStack.p[v16] = Bag;
    UFG::qString::qString(&v29);
    v25 = this->mAllCreatedBags.size;
    v26 = v25 + 1;
    v27 = this->mAllCreatedBags.capacity;
    if ( (int)v25 + 1 > v27 )
    {
      if ( v27 )
        v19 = 2 * v27;
      for ( ; v19 < v26; v19 *= 2 )
        ;
      if ( v19 - v26 > 0x10000 )
        v19 = v25 + 65537;
      UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(&this->mAllCreatedBags, v19, "qArray.Add");
    }
    this->mAllCreatedBags.size = v26;
    v28 = &this->mAllCreatedBags.p[v25];
    v28->mType = reflection_type;
    v28->mData = object_data;
    v28->mProperties = Bag;
    UFG::qString::Set(&v28->mName, v29.mData, v29.mLength, 0i64, 0);
    UFG::qString::~qString(&v29);
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&v32);
    UFG::qString::~qString(&v31);
  }
}

// File Line: 559
// RVA: 0x1AE2C0
bool __fastcall DNA::DNAPropertyBagSerializer::DiscoverObjectField(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectField *reflection_field,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  unsigned int mFlags; // eax

  mFlags = reflection_field->mFlags;
  return (mFlags & 8) == 0 && (mFlags & 0x80u) == 0;
}

// File Line: 570
// RVA: 0x1ADED0
char __fastcall DNA::DNAPropertyBagSerializer::BeginObjectField(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectField *reflection_field,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mObjectStack; // r14
  __int64 v9; // r10
  DNA::PropertyBag *v10; // rdi
  unsigned int mFlags; // eax
  UFG::qTree64Base *v12; // rax
  unsigned __int64 v13; // rcx
  signed int v14; // esi
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *p_mAllCreatedBags; // r15
  DNA::PropertyWrapper *Property; // rax
  DNA::PropertyBag *v17; // rsi
  __int64 size; // rbp
  unsigned int v19; // ebx
  unsigned int capacity; // edx
  unsigned int v21; // edx
  UFG::qReflectType *v22; // rax
  __int64 v23; // rsi
  unsigned int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  DNA::DNAPropertyBagSerializer::CreateContext *v27; // rcx
  UFG::qTree64Base *SchemaType; // rax
  unsigned __int64 mArrayLength; // rsi
  unsigned __int64 mNumBytes; // r14
  unsigned int v32; // edi
  __int64 v33; // rax
  const char *v34; // [rsp+30h] [rbp-C8h]
  __int64 v35; // [rsp+38h] [rbp-C0h]
  DNA::PropertyBagWrapper wrapper; // [rsp+40h] [rbp-B8h] BYREF
  UFG::qReflectType *v37; // [rsp+70h] [rbp-88h]
  const char *v38; // [rsp+78h] [rbp-80h]
  DNA::PropertyBag *v39; // [rsp+80h] [rbp-78h]
  UFG::qString v40; // [rsp+88h] [rbp-70h] BYREF
  __int64 v41; // [rsp+B0h] [rbp-48h]
  signed int v42; // [rsp+100h] [rbp+8h]
  DNA::PropertyBagWrapper *v; // [rsp+108h] [rbp+10h] BYREF

  v41 = -2i64;
  p_mObjectStack = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mObjectStack;
  v9 = this->mObjectStack.size - 1;
  v10 = this->mObjectStack.p[v9];
  mFlags = reflection_field->mFlags;
  if ( (mFlags & 8) != 0 || (mFlags & 0x80u) != 0 )
  {
    SchemaType = DNA::PropertyBag::GetSchemaType(this->mObjectStack.p[v9]);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)SchemaType);
    DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, v10);
    mArrayLength = reflection_field->mArrayLength;
    mNumBytes = reflection_type->mNumBytes;
    v32 = 0;
    if ( mArrayLength )
    {
      v33 = 0i64;
      do
      {
        DNA::DNAPropertyBagSerializer::WriteSimpleType(
          this,
          &wrapper,
          reflection_field,
          reflection_type,
          v32++,
          &object_data[mNumBytes * v33]);
        v33 = v32;
      }
      while ( v32 < mArrayLength );
    }
    DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
    return 0;
  }
  else
  {
    v12 = DNA::PropertyBag::GetSchemaType(this->mObjectStack.p[v9]);
    DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)v12);
    DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, v10);
    v13 = reflection_type->mNumBytes;
    v14 = reflection_field->mArrayLength - 1;
    v42 = v14;
    if ( v14 >= 0 )
    {
      p_mAllCreatedBags = &this->mAllCreatedBags;
      v35 = -(__int64)v13;
      v34 = &object_data[v13 * v14];
      do
      {
        Property = DNA::PropertyBagWrapper::GetProperty(&wrapper, reflection_field->mName);
        v = 0i64;
        DNA::PropertyWrapper::Get(Property, v14, &v, 0);
        v17 = *v->mPropertyBags.p;
        size = p_mObjectStack->size;
        v19 = size + 1;
        capacity = p_mObjectStack->capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v21 = 2 * capacity;
          else
            v21 = 1;
          for ( ; v21 < v19; v21 *= 2 )
            ;
          if ( v21 <= 2 )
            v21 = 2;
          if ( v21 - v19 > 0x10000 )
            v21 = size + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mObjectStack, v21, "qArray.Add");
        }
        p_mObjectStack->size = v19;
        p_mObjectStack->p[size] = (UFG::qReflectInventoryBase *)v17;
        UFG::qString::qString(&v40);
        v22 = reflection_type;
        v37 = reflection_type;
        v38 = v34;
        v39 = v17;
        v23 = p_mAllCreatedBags->size;
        v24 = v23 + 1;
        v25 = p_mAllCreatedBags->capacity;
        if ( (int)v23 + 1 > v25 )
        {
          if ( v25 )
            v26 = 2 * v25;
          else
            v26 = 1;
          for ( ; v26 < v24; v26 *= 2 )
            ;
          if ( v26 - v24 > 0x10000 )
            v26 = v23 + 65537;
          UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(p_mAllCreatedBags, v26, "qArray.Add");
          v22 = v37;
        }
        p_mAllCreatedBags->size = v24;
        v27 = &p_mAllCreatedBags->p[v23];
        v27->mType = v22;
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
    return 1;
  }
}

// File Line: 626
// RVA: 0x1AD850
bool __fastcall DNA::DNAPropertyBagSerializer::BeginArrayField(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectField *reflection_field,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  UFG::qArray<DNA::DNAPropertyBagSerializer::ArrayContext,0> *p_mArrayContexts; // rdi
  __int64 size; // rsi
  DNA::PropertyBag *v7; // rbp
  unsigned int capacity; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  DNA::DNAPropertyBagSerializer::ArrayContext *p; // rax
  __int64 v12; // rcx

  p_mArrayContexts = &this->mArrayContexts;
  size = this->mArrayContexts.size;
  v7 = this->mObjectStack.p[this->mObjectStack.size - 1];
  capacity = this->mArrayContexts.capacity;
  v9 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v10 = 2 * capacity;
    else
      v10 = 1;
    for ( ; v10 < v9; v10 *= 2 )
      ;
    if ( v10 - v9 > 0x10000 )
      v10 = size + 65537;
    UFG::qArray<DNA::DNAPropertyBagSerializer::ArrayContext,0>::Reallocate(p_mArrayContexts, v10, "qArray.Add");
  }
  p = p_mArrayContexts->p;
  p_mArrayContexts->size = v9;
  v12 = size;
  p[v12].mData = object_data;
  p[v12].mProperties = v7;
  return 0;
}

// File Line: 635
// RVA: 0x1AD320
__int64 __fastcall DNA::DNAPropertyBagSerializer::BeginArray(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectVisitor::ArrayData *array_data)
{
  unsigned int v4; // r12d
  int v5; // edx
  unsigned int size; // ecx
  DNA::DNAPropertyBagSerializer::ArrayContext *p; // r8
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mObjectStack; // r15
  __int64 v9; // rcx
  unsigned int v10; // edi
  unsigned int capacity; // ebx
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  DNA::PropertyBag **v15; // r13
  unsigned int i; // r9d
  UFG::qTree64Base *SchemaType; // rax
  UFG::qReflectType *mSubType; // rbx
  unsigned int mFlags; // eax
  unsigned int v20; // ecx
  unsigned int j; // edi
  const char *v22; // r15
  unsigned __int64 v23; // rbx
  UFG::ReflectionDB *v24; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *Type; // rax
  unsigned int v26; // ecx
  unsigned int v27; // edx
  DNA::DNAPropertyBagSerializer::CreateContext *v28; // rbx
  DNA::PropertyWrapper *v29; // r10
  unsigned __int64 v30; // rax
  signed int v31; // ecx
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *p_mAllCreatedBags; // r13
  unsigned __int64 v33; // rdx
  const char *v34; // rbx
  DNA::PropertyBag **v35; // rcx
  DNA::PropertyBag *Bag; // rdi
  unsigned __int64 id; // r13
  unsigned __int64 OwnerUID; // rsi
  UFG::qString *SchemaName; // rbx
  UFG::qString *Name; // rax
  const char *mData; // rbx
  const char *v42; // rdi
  DNA::Database *v43; // rax
  __int64 v44; // rsi
  unsigned int v45; // ebx
  unsigned int v46; // edx
  unsigned int v47; // edx
  UFG::qReflectType *v48; // rax
  __int64 v49; // rdi
  unsigned int v50; // ebx
  unsigned int v51; // edx
  unsigned int v52; // edx
  DNA::DNAPropertyBagSerializer::CreateContext *v53; // rcx
  unsigned __int8 v54; // bl
  unsigned __int64 mNumBytes; // rbx
  unsigned __int64 v57; // [rsp+30h] [rbp-D0h]
  DNA::PropertyWrapper *v58; // [rsp+38h] [rbp-C8h]
  const char *v59; // [rsp+40h] [rbp-C0h]
  __int64 v60; // [rsp+48h] [rbp-B8h]
  UFG::qReflectType *v61; // [rsp+50h] [rbp-B0h]
  DNA::PropertyBag *v62; // [rsp+60h] [rbp-A0h]
  UFG::qString v63; // [rsp+68h] [rbp-98h] BYREF
  DNA::PropertyBagWrapper wrapper; // [rsp+90h] [rbp-70h] BYREF
  __int64 v65; // [rsp+B8h] [rbp-48h]
  UFG::qString result; // [rsp+C0h] [rbp-40h] BYREF
  UFG::qString v67; // [rsp+E8h] [rbp-18h] BYREF
  unsigned int v68; // [rsp+160h] [rbp+60h]
  DNA::PropertyWrapper *Property; // [rsp+160h] [rbp+60h]
  unsigned int v70; // [rsp+160h] [rbp+60h]
  DNA::PropertyBag *propertyBag; // [rsp+168h] [rbp+68h]
  bool propertyBaga; // [rsp+168h] [rbp+68h]
  DNA::PropertyBagWrapper *v; // [rsp+170h] [rbp+70h] BYREF
  UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0> *v74; // [rsp+178h] [rbp+78h]

  v65 = -2i64;
  v4 = 0;
  propertyBag = 0i64;
  v5 = 0;
  size = this->mArrayContexts.size;
  if ( size )
  {
    p = this->mArrayContexts.p;
    while ( p[v5].mData != (const char *)array_data->mArrayLocation )
    {
      if ( ++v5 >= size )
        goto LABEL_7;
    }
    propertyBag = p[v5].mProperties;
  }
LABEL_7:
  p_mObjectStack = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mObjectStack;
  v9 = this->mObjectStack.size;
  v68 = v9;
  v10 = v9 + 1;
  capacity = this->mObjectStack.capacity;
  if ( (int)v9 + 1 > capacity )
  {
    if ( capacity )
      v12 = 2 * capacity;
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
      if ( this->mObjectStack.p )
      {
        for ( i = 0; i < p_mObjectStack->size; ++i )
          v14[i] = (UFG::allocator::free_link)this->mObjectStack.p[i];
        operator delete[](this->mObjectStack.p);
      }
      this->mObjectStack.p = v15;
      this->mObjectStack.capacity = v12;
      v9 = v68;
    }
  }
  p_mObjectStack->size = v10;
  this->mObjectStack.p[v9] = propertyBag;
  SchemaType = DNA::PropertyBag::GetSchemaType(propertyBag);
  DNA::PropertyBagWrapper::PropertyBagWrapper(&wrapper, (DNA::SchemaType *)SchemaType);
  DNA::PropertyBagWrapper::AddPropertyBag(&wrapper, propertyBag);
  mSubType = array_data->mSubType;
  mFlags = mSubType->mFlags;
  if ( (mFlags & 1) != 0 || (mFlags & 8) != 0 || (mFlags & 0x80u) != 0 )
  {
    mNumBytes = mSubType->mNumBytes;
    if ( array_data->mArraySize )
    {
      do
      {
        DNA::DNAPropertyBagSerializer::WriteSimpleType(
          this,
          &wrapper,
          array_data->mOwnerField,
          array_data->mSubType,
          v4,
          &array_data->mArrayData[mNumBytes * v4]);
        ++v4;
      }
      while ( v4 < array_data->mArraySize );
    }
LABEL_69:
    v54 = 0;
    goto LABEL_70;
  }
  v20 = array_data->mArrayField->mFlags;
  if ( (v20 & 0x4000) != 0 )
  {
    if ( (v20 & 0x10) != 0 )
    {
      Property = DNA::PropertyBagWrapper::GetProperty(&wrapper, array_data->mOwnerField->mName);
      for ( j = 0; j < array_data->mArraySize; ++j )
      {
        v22 = &array_data->mArrayData[8 * j];
        v23 = *(_QWORD *)(*(_QWORD *)v22 + 56i64);
        v24 = UFG::ReflectionDB::Instance();
        Type = UFG::ReflectionDB::GetType(v24, v23);
        v26 = 0;
        v27 = this->mAllCreatedBags.size;
        if ( v27 )
        {
          while ( 1 )
          {
            v28 = &this->mAllCreatedBags.p[(unsigned __int64)v26];
            if ( v28->mData == *(const char **)v22
              && (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v28->mType == Type )
            {
              break;
            }
            if ( ++v26 >= v27 )
              goto LABEL_37;
          }
          DNA::PropertyBag::SetOwner(v28->mProperties, propertyBag);
          DNA::PropertyWrapper::Set(Property, j, v28->mProperties, 0);
        }
LABEL_37:
        ;
      }
    }
    goto LABEL_69;
  }
  v29 = DNA::PropertyBagWrapper::GetProperty(&wrapper, array_data->mOwnerField->mName);
  v58 = v29;
  propertyBaga = (array_data->mArrayField->mFlags & 0x10) != 0;
  v30 = array_data->mSubType->mNumBytes;
  v31 = array_data->mArraySize - 1;
  v70 = v31;
  if ( v31 >= 0 )
  {
    p_mAllCreatedBags = &this->mAllCreatedBags;
    v74 = &this->mAllCreatedBags;
    v33 = v30 * v31;
    v57 = v33;
    v60 = -(__int64)v30;
    do
    {
      v34 = &array_data->mArrayData[v33];
      v59 = v34;
      v = 0i64;
      DNA::PropertyWrapper::Get(v29, v31, &v, 0);
      v35 = v->mPropertyBags.p;
      Bag = *v35;
      if ( propertyBaga )
      {
        id = *((_QWORD *)v34 + 1);
        if ( id - 1 <= 0xFFFFFFFFFFFFFFFDui64 )
        {
          OwnerUID = DNA::PropertyBag::GetOwnerUID(*v35);
          SchemaName = DNA::PropertyBag::GetSchemaName(Bag, &result);
          Name = DNA::PropertyBag::GetName(Bag, &v67);
          mData = SchemaName->mData;
          v42 = Name->mData;
          DNA::Database::Instance();
          Bag = DNA::Database::CreateBag(v43, v42, mData, &customCaption, id);
          UFG::qString::~qString(&v67);
          UFG::qString::~qString(&result);
          DNA::PropertyBag::SetOwnerUID(Bag, OwnerUID);
          DNA::PropertyWrapper::Set(v58, v70, Bag, 0);
        }
        p_mAllCreatedBags = v74;
      }
      v44 = p_mObjectStack->size;
      v45 = v44 + 1;
      v46 = p_mObjectStack->capacity;
      if ( (int)v44 + 1 > v46 )
      {
        if ( v46 )
          v47 = 2 * v46;
        else
          v47 = 1;
        for ( ; v47 < v45; v47 *= 2 )
          ;
        if ( v47 <= 2 )
          v47 = 2;
        if ( v47 - v45 > 0x10000 )
          v47 = v44 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mObjectStack, v47, "qArray.Add");
      }
      p_mObjectStack->size = v45;
      p_mObjectStack->p[v44] = (UFG::qReflectInventoryBase *)Bag;
      UFG::qString::qString(&v63);
      v48 = array_data->mSubType;
      v61 = v48;
      v62 = Bag;
      v49 = p_mAllCreatedBags->size;
      v50 = v49 + 1;
      v51 = p_mAllCreatedBags->capacity;
      if ( (int)v49 + 1 > v51 )
      {
        if ( v51 )
          v52 = 2 * v51;
        else
          v52 = 1;
        for ( ; v52 < v50; v52 *= 2 )
          ;
        if ( v52 - v50 > 0x10000 )
          v52 = v49 + 65537;
        UFG::qArray<DNA::DNAPropertyBagSerializer::CreateContext,0>::Reallocate(p_mAllCreatedBags, v52, "qArray.Add");
        v48 = v61;
      }
      p_mAllCreatedBags->size = v50;
      v53 = &p_mAllCreatedBags->p[v49];
      v53->mType = v48;
      v53->mData = v59;
      v53->mProperties = v62;
      UFG::qString::Set(&v53->mName, v63.mData, v63.mLength, 0i64, 0);
      UFG::qString::~qString(&v63);
      v31 = v70 - 1;
      v70 = v31;
      v33 = v60 + v57;
      v57 += v60;
      v29 = v58;
    }
    while ( v31 >= 0 );
  }
  v54 = 1;
LABEL_70:
  DNA::PropertyBagWrapper::~PropertyBagWrapper(&wrapper);
  return v54;
}

// File Line: 739
// RVA: 0x1AE2E0
void __fastcall DNA::DNAPropertyBagSerializer::EndObject(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  unsigned int size; // eax

  size = this->mObjectStack.size;
  if ( size > 1 )
    this->mObjectStack.size = size - 1;
  else
    this->mObjectStack.size = 0;
}

// File Line: 745
// RVA: 0x1AD900
void __fastcall DNA::DNAPropertyBagSerializer::BeginBytes(
        DNA::DNAPropertyBagSerializer *this,
        UFG::qReflectField *reflection_field,
        UFG::qReflectType *reflection_type,
        UFG::qSymbolUC *data)
{
  DNA::PropertyBag *v7; // rbx
  UFG::qTree64Base *SchemaType; // rax
  unsigned __int64 mArrayLength; // r12
  unsigned int i; // esi
  DNA::PropertyWrapper *Property; // rax
  DNA::PropertyWrapper *v12; // r14
  unsigned int mFlags; // ecx
  UFG::qTree64Base::BaseNode *mUID; // rbp
  unsigned __int64 v15; // rcx
  const char *mName; // rbx
  UFG::ReflectionDB *v17; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  UFG::qTree64Base::BaseNode *v19; // rdx
  UFG::qTree64Base::BaseNode **p_mParent; // rax
  char *v21; // r8
  unsigned int v22; // eax
  char *v23; // rax
  unsigned __int64 mNameUID; // rax
  UFG::qString v25; // [rsp+20h] [rbp-A8h] BYREF
  __int64 v26; // [rsp+48h] [rbp-80h]
  UFG::qString v27; // [rsp+50h] [rbp-78h] BYREF
  DNA::PropertyBagWrapper v28; // [rsp+78h] [rbp-50h] BYREF
  unsigned __int64 mNumBytes; // [rsp+D0h] [rbp+8h]

  v26 = -2i64;
  v7 = this->mObjectStack.p[this->mObjectStack.size - 1];
  SchemaType = DNA::PropertyBag::GetSchemaType(v7);
  DNA::PropertyBagWrapper::PropertyBagWrapper(&v28, (DNA::SchemaType *)SchemaType);
  DNA::PropertyBagWrapper::AddPropertyBag(&v28, v7);
  mArrayLength = reflection_field->mArrayLength;
  mNumBytes = reflection_type->mNumBytes;
  for ( i = 0; i < mArrayLength; ++i )
  {
    Property = DNA::PropertyBagWrapper::GetProperty(&v28, reflection_field->mName);
    v12 = Property;
    mFlags = reflection_type->mFlags;
    if ( (mFlags & 4) != 0 )
    {
      mUID = 0i64;
      v15 = reflection_type->mNumBytes;
      if ( v15 == 4 )
      {
        mUID = (UFG::qTree64Base::BaseNode *)(int)data->mUID;
      }
      else if ( v15 == 8 )
      {
        mUID = *(UFG::qTree64Base::BaseNode **)&data->mUID;
      }
      UFG::qString::qString(&v27);
      mName = reflection_type->mName;
      v17 = UFG::ReflectionDB::Instance();
      Enum = UFG::ReflectionDB::GetEnum(v17, mName);
      if ( !Enum
        || (v19 = Enum[1].mTree.mHead.mChildren[0],
            p_mParent = &Enum[1].mTree.mHead.mParent,
            v19 == (UFG::qTree64Base::BaseNode *)p_mParent) )
      {
LABEL_13:
        UFG::qPrintf(
          "Warning: DNAPacker.exe could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
          reflection_field->mName,
          reflection_type->mName);
      }
      else
      {
        while ( mUID != v19->mNeighbours[0] )
        {
          v19 = v19->mParent;
          if ( v19 == (UFG::qTree64Base::BaseNode *)p_mParent )
            goto LABEL_13;
        }
        UFG::qString::Set(&v27, (const char *)v19->mChildren[0]);
      }
      DNA::PropertyWrapper::Set(v12, i, v27.mData, 0);
      UFG::qString::~qString(&v27);
    }
    else if ( (mFlags & 8) != 0 )
    {
      if ( data[2].mUID )
        v21 = *(char **)&data->mUID;
      else
        v21 = &customCaption;
      DNA::PropertyWrapper::Set(Property, i, v21, 0);
    }
    else if ( (mFlags & 0x80u) == 0 )
    {
      mNameUID = reflection_type->mNameUID;
      if ( mNameUID == DNA::kBasicTypeUID_long_long )
      {
        DNA::PropertyWrapper::Set(v12, i, *(_QWORD *)&data->mUID, 0);
      }
      else if ( mNameUID == DNA::kBasicTypeUID_long || mNameUID == DNA::kBasicTypeUID_int )
      {
        DNA::PropertyWrapper::Set(v12, i, data->mUID, 0);
      }
      else if ( mNameUID == DNA::kBasicTypeUID_unsigned_long_long )
      {
        DNA::PropertyWrapper::Set(v12, i, *(_QWORD *)&data->mUID, 0);
      }
      else if ( mNameUID == DNA::kBasicTypeUID_unsigned_long || mNameUID == DNA::kBasicTypeUID_unsigned_int )
      {
        DNA::PropertyWrapper::Set(v12, i, data->mUID, 0);
      }
      else if ( mNameUID == DNA::kBasicTypeUID_float )
      {
        DNA::PropertyWrapper::Set(v12, i, *(float *)&data->mUID, 0);
      }
      else if ( mNameUID == DNA::kBasicTypeUID_bool
             || mNameUID != DNA::kBasicTypeUID_void && mNameUID == DNA::kBasicTypeUID_char )
      {
        DNA::PropertyWrapper::Set(v12, i, data->mUID, 0);
      }
    }
    else
    {
      UFG::qString::qString(&v25);
      v22 = reflection_type->mFlags;
      if ( (v22 & 0x100) != 0 || (v22 & 0x200) == 0 )
        v23 = UFG::qSymbol::as_cstr_dbg(data);
      else
        v23 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)data);
      UFG::qString::Set(&v25, v23);
      DNA::PropertyWrapper::Set(v12, i, v25.mData, 0);
      UFG::qString::~qString(&v25);
    }
    data = (UFG::qSymbolUC *)((char *)data + mNumBytes);
  }
  DNA::PropertyBagWrapper::~PropertyBagWrapper(&v28);
}

// File Line: 763
// RVA: 0x1AECA0
void __fastcall DNA::DNAPropertyBagSerializer::WriteSimpleType(
        DNA::DNAPropertyBagSerializer *this,
        DNA::PropertyBagWrapper *wrapper,
        UFG::qReflectField *field,
        UFG::qReflectType *reflection_type,
        unsigned int array_index,
        UFG::qSymbolUC *element_data)
{
  DNA::PropertyWrapper *Property; // rdi
  unsigned int mFlags; // eax
  UFG::qTree64Base::BaseNode *mUID; // rsi
  unsigned __int64 mNumBytes; // rax
  const char *mName; // rbx
  UFG::ReflectionDB *v13; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  UFG::qTree64Base::BaseNode *v15; // rdx
  UFG::qTree64Base::BaseNode **p_mParent; // rax
  char *v17; // r8
  unsigned int v18; // eax
  char *v19; // rax
  unsigned __int64 mNameUID; // rax
  UFG::qString v21; // [rsp+28h] [rbp-30h] BYREF

  Property = DNA::PropertyBagWrapper::GetProperty(wrapper, field->mName);
  mFlags = reflection_type->mFlags;
  if ( (mFlags & 4) != 0 )
  {
    mUID = 0i64;
    mNumBytes = reflection_type->mNumBytes;
    if ( mNumBytes == 4 )
    {
      mUID = (UFG::qTree64Base::BaseNode *)(int)element_data->mUID;
    }
    else if ( mNumBytes == 8 )
    {
      mUID = *(UFG::qTree64Base::BaseNode **)&element_data->mUID;
    }
    UFG::qString::qString(&v21);
    mName = reflection_type->mName;
    v13 = UFG::ReflectionDB::Instance();
    Enum = UFG::ReflectionDB::GetEnum(v13, mName);
    if ( !Enum
      || (v15 = Enum[1].mTree.mHead.mChildren[0],
          p_mParent = &Enum[1].mTree.mHead.mParent,
          v15 == (UFG::qTree64Base::BaseNode *)p_mParent) )
    {
LABEL_12:
      UFG::qPrintf(
        "Warning: DNAPacker.exe could not find enum value for field %s of type %s.  Replacing with an empty string.\n",
        field->mName,
        reflection_type->mName);
    }
    else
    {
      while ( mUID != v15->mNeighbours[0] )
      {
        v15 = v15->mParent;
        if ( v15 == (UFG::qTree64Base::BaseNode *)p_mParent )
          goto LABEL_12;
      }
      UFG::qString::Set(&v21, (const char *)v15->mChildren[0]);
    }
    DNA::PropertyWrapper::Set(Property, array_index, v21.mData, 0);
    UFG::qString::~qString(&v21);
  }
  else if ( (mFlags & 8) != 0 )
  {
    if ( element_data[2].mUID )
      v17 = *(char **)&element_data->mUID;
    else
      v17 = &customCaption;
    DNA::PropertyWrapper::Set(Property, array_index, v17, 0);
  }
  else if ( (mFlags & 0x80u) == 0 )
  {
    mNameUID = reflection_type->mNameUID;
    if ( mNameUID == DNA::kBasicTypeUID_long_long )
    {
      DNA::PropertyWrapper::Set(Property, array_index, *(_QWORD *)&element_data->mUID, 0);
    }
    else if ( mNameUID == DNA::kBasicTypeUID_long || mNameUID == DNA::kBasicTypeUID_int )
    {
      DNA::PropertyWrapper::Set(Property, array_index, element_data->mUID, 0);
    }
    else if ( mNameUID == DNA::kBasicTypeUID_unsigned_long_long )
    {
      DNA::PropertyWrapper::Set(Property, array_index, *(_QWORD *)&element_data->mUID, 0);
    }
    else if ( mNameUID == DNA::kBasicTypeUID_unsigned_long || mNameUID == DNA::kBasicTypeUID_unsigned_int )
    {
      DNA::PropertyWrapper::Set(Property, array_index, element_data->mUID, 0);
    }
    else if ( mNameUID == DNA::kBasicTypeUID_float )
    {
      DNA::PropertyWrapper::Set(Property, array_index, *(float *)&element_data->mUID, 0);
    }
    else if ( mNameUID == DNA::kBasicTypeUID_bool
           || mNameUID != DNA::kBasicTypeUID_void && mNameUID == DNA::kBasicTypeUID_char )
    {
      DNA::PropertyWrapper::Set(Property, array_index, element_data->mUID, 0);
    }
  }
  else
  {
    UFG::qString::qString(&v21);
    v18 = reflection_type->mFlags;
    if ( (v18 & 0x100) != 0 || (v18 & 0x200) == 0 )
      v19 = UFG::qSymbol::as_cstr_dbg(element_data);
    else
      v19 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)element_data);
    UFG::qString::Set(&v21, v19);
    DNA::PropertyWrapper::Set(Property, array_index, v21.mData, 0);
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
__int64 __fastcall DNA::WriteToBuffer(
        UFG::qReflectObject *object,
        const char *name,
        const char **buffer,
        unsigned int *buffer_size)
{
  unsigned __int64 mTypeUID; // rbx
  UFG::ReflectionDB *v9; // rax
  UFG::qReflectType *Type; // rax
  DNA::Database *v11; // rax
  DNA::PropertyBag *v12; // rbx
  DNA::Database *v13; // rax
  DNA::Database *v14; // rax
  unsigned __int8 v15; // di
  DNA::PropertyBagHandle *i; // rbx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mPrev; // rcx
  UFG::qNode<DNA::PropertyBagHandle,DNA::PropertyBagHandle> *mNext; // rax
  UFG::qReflectType *v19; // rcx
  UFG::qReflectVisitor::ObjectData *p; // rax
  DNA::DNAPropertyBagSerializer v22; // [rsp+18h] [rbp-79h] BYREF
  __int64 v23; // [rsp+A8h] [rbp+17h]
  UFG::qString namea; // [rsp+B0h] [rbp+1Fh] BYREF
  DNA::Query query; // [rsp+F8h] [rbp+67h] BYREF

  v23 = -2i64;
  memset(&v22.mTrackedObjects, 0, 48);
  UFG::qString::qString(&v22.mFilePath);
  memset(&v22.mObjectStack, 0, 48);
  mTypeUID = object->mTypeUID;
  v9 = UFG::ReflectionDB::Instance();
  Type = (UFG::qReflectType *)UFG::ReflectionDB::GetType(v9, mTypeUID);
  UFG::qReflectVisitor::TrackObject(&v22, Type, (const char *)object);
  UFG::qString::qString(&namea, name);
  UFG::qReflectVisitor::SetObjectName(&v22, v22.mTrackedObjects.size - 1, &namea);
  UFG::qString::~qString(&namea);
  UFG::qString::Set(&v22.mFilePath, "__WRITE_TO_BUFFER__");
  UFG::qReflectVisitor::VisitObjects(&v22);
  DNA::DNAPropertyBagSerializer::BindChildObjectsToParents(&v22);
  query.mRoot = DNA::Query::FilePath("__WRITE_TO_BUFFER__");
  *(_QWORD *)&v22.mTrackedObjects.size = &v22.mTrackedObjects;
  v22.mTrackedObjects.p = (UFG::qReflectVisitor::ObjectData *)&v22.mTrackedObjects;
  DNA::Database::Instance();
  DNA::Database::GetPropertyBags(
    v11,
    &query,
    (UFG::qList<DNA::PropertyBagHandle,DNA::PropertyBagHandle,1,0> *)&v22.mTrackedObjects);
  v12 = DNA::PropertyBagHandle::Get((DNA::PropertyBagHandle *)v22.mTrackedObjects.p);
  DNA::Database::Instance();
  if ( DNA::Database::SaveToBuffer(v13, buffer, buffer_size, v12) )
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
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    DNA::PropertyBagHandle::~PropertyBagHandle(i);
    operator delete[](i);
  }
  v19 = *(UFG::qReflectType **)&v22.mTrackedObjects.size;
  p = v22.mTrackedObjects.p;
  *(_QWORD *)(*(_QWORD *)&v22.mTrackedObjects.size + 8i64) = v22.mTrackedObjects.p;
  p->mReflectionType = v19;
  *(_QWORD *)&v22.mTrackedObjects.size = &v22.mTrackedObjects;
  v22.mTrackedObjects.p = (UFG::qReflectVisitor::ObjectData *)&v22.mTrackedObjects;
  if ( query.mRoot )
    ((void (__fastcall *)(DNA::IQueryNode *, __int64))query.mRoot->vfptr->~IQueryNode)(query.mRoot, 1i64);
  DNA::DNAPropertyBagSerializer::~DNAPropertyBagSerializer(&v22);
  return v15;
}

// File Line: 963
// RVA: 0x1AE3C0
char __fastcall DNA::FindEnumValueFromString(const char *enum_name, UFG::qString *string_data, __int64 *value_to_write)
{
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *v8; // rbp
  UFG::qTree64Base::BaseNode *v9; // rbx
  UFG::qTree64Base::BaseNode **p_mParent; // rdi
  __int64 v11; // rax
  UFG::qTree64Base::BaseNode *v12; // rcx

  v6 = UFG::ReflectionDB::Instance();
  Enum = UFG::ReflectionDB::GetEnum(v6, enum_name);
  v8 = Enum;
  if ( !Enum )
    return 0;
  v9 = Enum[1].mTree.mHead.mChildren[0];
  p_mParent = &Enum[1].mTree.mHead.mParent;
  if ( v9 != (UFG::qTree64Base::BaseNode *)&Enum[1].mTree.mHead.mParent )
  {
    while ( (unsigned int)UFG::qStringCompare((const char *)v9->mChildren[0], string_data->mData, -1) )
    {
      v9 = v9->mParent;
      if ( v9 == (UFG::qTree64Base::BaseNode *)p_mParent )
        goto LABEL_5;
    }
    goto LABEL_12;
  }
LABEL_5:
  v9 = v8[1].mTree.mHead.mChildren[0];
  if ( v9 == (UFG::qTree64Base::BaseNode *)p_mParent )
  {
LABEL_8:
    v11 = UFG::qToInt64(string_data->mData, 0i64);
    *value_to_write = v11;
    v12 = v8[1].mTree.mHead.mChildren[0];
    if ( v12 != (UFG::qTree64Base::BaseNode *)p_mParent )
    {
      while ( (UFG::qTree64Base::BaseNode *)v11 != v12->mNeighbours[0] )
      {
        v12 = v12->mParent;
        if ( v12 == (UFG::qTree64Base::BaseNode *)p_mParent )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  while ( !UFG::qString::EndsWith(string_data, (const char *)v9->mChildren[0], -1) )
  {
    v9 = v9->mParent;
    if ( v9 == (UFG::qTree64Base::BaseNode *)p_mParent )
      goto LABEL_8;
  }
LABEL_12:
  *value_to_write = (__int64)v9->mNeighbours[0];
  return 1;
}

// File Line: 1013
// RVA: 0x1AE340
char __fastcall DNA::FindEnumStringFromValue(
        const char *enum_name,
        UFG::qTree64Base::BaseNode **value_to_write,
        UFG::qString *string_data)
{
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectEnum,UFG::qReflectEnum,0> *Enum; // rax
  UFG::qTree64Base::BaseNode *v8; // rdx
  UFG::qTree64Base::BaseNode **p_mParent; // rax

  v6 = UFG::ReflectionDB::Instance();
  Enum = UFG::ReflectionDB::GetEnum(v6, enum_name);
  if ( !Enum )
    return 0;
  v8 = Enum[1].mTree.mHead.mChildren[0];
  p_mParent = &Enum[1].mTree.mHead.mParent;
  if ( v8 == (UFG::qTree64Base::BaseNode *)p_mParent )
    return 0;
  while ( *value_to_write != v8->mNeighbours[0] )
  {
    v8 = v8->mParent;
    if ( v8 == (UFG::qTree64Base::BaseNode *)p_mParent )
      return 0;
  }
  UFG::qString::Set(string_data, (const char *)v8->mChildren[0]);
  return 1;
}

// File Line: 1030
// RVA: 0x1AE9F0
bool __fastcall DNA::IsHidden(UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rbx
  unsigned __int64 v6; // rax
  UFG::qTree64Base *v8; // rbx
  unsigned __int64 v9; // rax

  v4 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v4, type->mNameUID);
  if ( !Schema )
    return 0;
  v6 = UFG::qStringHash64("IsHidden", 0xFFFFFFFFFFFFFFFFui64);
  if ( UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[1].mTree.mHead.mParent, v6) )
    return 1;
  v8 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[2].mTree.mHead.mParent, field->mNameUID);
  if ( !v8 )
    return 0;
  v9 = UFG::qStringHash64("IsHidden", 0xFFFFFFFFFFFFFFFFui64);
  return UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v8 + 64), v9) != 0i64;
}

// File Line: 1052
// RVA: 0x1AE7A0
_BOOL8 __fastcall DNA::HasEditor(UFG::qReflectType *type, const char *editor)
{
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rbx
  unsigned __int64 v6; // rax
  UFG::qTree64Base *v7; // rax

  v4 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v4, type->mNameUID);
  if ( Schema
    && (v6 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64),
        (v7 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[1].mTree.mHead.mParent, v6)) != 0i64) )
  {
    return (unsigned int)UFG::qStringCompare((const char *)v7[1].mHead.mUID, editor, -1) == 0;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1067
// RVA: 0x1AE6A0
BOOL __fastcall DNA::HasEditor(UFG::qReflectField *field, const char *editor)
{
  UFG::ReflectionDB *v4; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *Type; // rbx
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rbx
  unsigned __int64 v8; // rax
  UFG::qTree64Base *v9; // rax
  UFG::qTree64Base *v11; // rbx
  unsigned __int64 v12; // rax
  UFG::qTree64Base *v13; // rax

  v4 = UFG::ReflectionDB::Instance();
  Type = UFG::ReflectionDB::GetType(v4, field->mTypeUID);
  v6 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v6, (unsigned __int64)Type[1].mTree.mHead.mChildren[0]);
  if ( !Schema )
    return 0;
  v8 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64);
  v9 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[1].mTree.mHead.mParent, v8);
  if ( v9 && !(unsigned int)UFG::qStringCompare((const char *)v9[1].mHead.mUID, editor, -1) )
    return 1;
  v11 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[2].mTree.mHead.mParent, field->mNameUID);
  if ( v11
    && (v12 = UFG::qStringHash64("Editor", 0xFFFFFFFFFFFFFFFFui64),
        (v13 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v11 + 64), v12)) != 0i64) )
  {
    return UFG::qStringCompare((const char *)v13[1].mHead.mUID, editor, -1) == 0;
  }
  else
  {
    return 0;
  }
}

// File Line: 1095
// RVA: 0x1AE910
bool __fastcall DNA::HasRange(UFG::qReflectType *type, UFG::qReflectField *field, float *min, float *max)
{
  UFG::ReflectionDB *v8; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rax
  UFG::qTree64Base *v10; // rbx
  unsigned __int64 v11; // rax
  UFG::qTree64Base *v12; // rdi
  unsigned __int64 v13; // rax
  UFG::qTree64Base *v14; // rax
  UFG::qTree64Base *v15; // rbx
  float v16; // xmm0_4
  const char *mUID; // rcx
  float v18; // xmm0_4
  bool result; // al

  v8 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v8, type->mNameUID);
  if ( !Schema )
    return 0;
  v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[2].mTree.mHead.mParent, field->mNameUID);
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
  mUID = (const char *)v15[1].mHead.mUID;
  *min = v16;
  v18 = UFG::qToFloat(mUID, 0.0);
  result = 1;
  *max = v18;
  return result;
}

// File Line: 1117
// RVA: 0x1AE840
char __fastcall DNA::HasRange(UFG::qReflectType *type, UFG::qReflectField *field, int *min, int *max)
{
  UFG::ReflectionDB *v8; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rax
  UFG::qTree64Base *v10; // rbx
  unsigned __int64 v11; // rax
  UFG::qTree64Base *v12; // rdi
  unsigned __int64 v13; // rax
  UFG::qTree64Base *v14; // rax
  UFG::qTree64Base *v15; // rbx

  v8 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v8, type->mNameUID);
  if ( !Schema )
    return 0;
  v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[2].mTree.mHead.mParent, field->mNameUID);
  if ( !v10 )
    return 0;
  v11 = UFG::qStringHash64("Min", 0xFFFFFFFFFFFFFFFFui64);
  v12 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v11);
  v13 = UFG::qStringHash64("Max", 0xFFFFFFFFFFFFFFFFui64);
  v14 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v10 + 64), v13);
  v15 = v14;
  if ( !v12 || !v14 )
    return 0;
  *min = UFG::qToInt32((const char *)v12[1].mHead.mUID, 0);
  *max = UFG::qToInt32((const char *)v15[1].mHead.mUID, 0);
  return 1;
}

// File Line: 1139
// RVA: 0x1AE550
UFG::qString *__fastcall DNA::GetDisplayName(UFG::qString *result, UFG::qReflectType *type, UFG::qReflectField *field)
{
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectSchema,UFG::qReflectSchema,0> *Schema; // rax
  UFG::qTree64Base *v8; // rbx
  unsigned __int64 v9; // rax
  UFG::qTree64Base *v10; // rax
  char *v11; // rax
  const char *mName; // r10
  const char *v13; // rdx
  char v14; // r8
  char v15; // r8
  char format[256]; // [rsp+30h] [rbp-108h] BYREF

  v6 = UFG::ReflectionDB::Instance();
  Schema = UFG::ReflectionDB::GetSchema(v6, type->mNameUID);
  if ( !Schema
    || (v8 = UFG::qTree64Base::Get((UFG::qTree64Base *)&Schema[2].mTree.mHead.mParent, field->mNameUID)) == 0i64
    || (v9 = UFG::qStringHash64("DisplayName", 0xFFFFFFFFFFFFFFFFui64),
        (v10 = UFG::qTree64Base::Get((UFG::qTree64Base *)((char *)v8 + 64), v9)) == 0i64) )
  {
    v11 = format;
    mName = field->mName;
    v13 = mName;
    if ( !*mName )
    {
LABEL_21:
      *v11 = 0;
      UFG::qString::qString(result, format);
      return result;
    }
    while ( 1 )
    {
      if ( v13 == mName && *v13 == 109 )
      {
        v14 = v13[1];
        if ( v14 == 95 )
        {
          ++v13;
          goto LABEL_20;
        }
        if ( (unsigned __int8)(v14 - 65) <= 0x19u )
          goto LABEL_20;
      }
      v15 = *v13;
      if ( *v13 == 95 )
      {
        *v11 = 32;
LABEL_19:
        ++v11;
        goto LABEL_20;
      }
      if ( v11 == format || (unsigned __int8)(v15 - 97) > 0x19u || (unsigned __int8)(v13[1] - 65) > 0x19u )
      {
        *v11 = v15;
        goto LABEL_19;
      }
      *v11 = v15;
      v11[1] = 32;
      v11 += 2;
LABEL_20:
      if ( !*++v13 )
        goto LABEL_21;
    }
  }
  UFG::qString::qString(result, (const char *)v10[1].mHead.mUID);
  return result;
}

