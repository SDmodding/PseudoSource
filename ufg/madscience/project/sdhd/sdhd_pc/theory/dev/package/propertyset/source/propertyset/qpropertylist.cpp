// File Line: 46
// RVA: 0x1ED3A0
void __fastcall UFG::qPropertyList::qPropertyList(UFG::qPropertyList *this)
{
  unsigned int v2; // ebx
  unsigned int mTypeUID; // eax
  unsigned int i; // ebp
  UFG::qPropertyType *v5; // rdi
  UFG::qOffset64<unsigned char *> *v6; // rcx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // edi
  UFG::qPropertyList *v9; // rax
  unsigned int mNumElements; // [rsp+50h] [rbp+8h]

  v2 = 0;
  UFG::qPropertyCollection::qPropertyCollection(this, 0);
  Assembly::GetRCX(&this->mValues);
  Assembly::GetRCX(&this->mWeights);
  mTypeUID = this->mTypeUID;
  if ( mTypeUID == 26 )
  {
    mNumElements = this->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      if ( this->mTypeUID == 26
        && i < this->mNumElements
        && (v5 = UFG::qPropertyType::Get(0x1Au),
            (v6 = (UFG::qOffset64<unsigned char *> *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[i * ((v5->Alignment + v5->mByteSize - 1) & ~(v5->Alignment - 1))]) != 0i64) )
      {
        v7 = (UFG::qPropertySet *)UFG::qOffset64<unsigned char *>::Get(v6, 0i64);
      }
      else
      {
        v7 = 0i64;
      }
      if ( v7 )
        UFG::qPropertySet::qPropertySet(v7);
    }
  }
  else if ( mTypeUID == 25 )
  {
    v8 = this->mNumElements;
    if ( v8 )
    {
      do
      {
        v9 = UFG::qPropertyList::Get<UFG::qPropertyList>(this, v2);
        if ( v9 )
          UFG::qPropertyList::qPropertyList(v9);
        ++v2;
      }
      while ( v2 < v8 );
    }
  }
}

// File Line: 87
// RVA: 0x1EE740
void __fastcall UFG::qPropertyList::~qPropertyList(UFG::qPropertyList *this)
{
  unsigned int mTypeUID; // eax
  unsigned int mNumElements; // esi
  unsigned int v4; // edi
  UFG::qPropertySet *v5; // rax
  unsigned int v6; // esi
  unsigned int v7; // edi
  UFG::qPropertyList *v8; // rax

  if ( (this->mFlags & 1) != 0 )
  {
    mTypeUID = this->mTypeUID;
    if ( mTypeUID == 26 )
    {
      mNumElements = this->mNumElements;
      v4 = 0;
      if ( mNumElements )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qPropertySet>(this, v4);
          UFG::qPropertySet::~qPropertySet(v5);
          ++v4;
        }
        while ( v4 < mNumElements );
LABEL_5:
        this->mFlags |= 0x10000u;
        return;
      }
    }
    else if ( mTypeUID == 25 )
    {
      v6 = this->mNumElements;
      v7 = 0;
      if ( v6 )
      {
        do
        {
          v8 = UFG::qPropertyList::Get<UFG::qPropertyList>(this, v7);
          UFG::qPropertyList::~qPropertyList(v8);
          ++v7;
        }
        while ( v7 < v6 );
        goto LABEL_5;
      }
    }
    this->mFlags |= 0x10000u;
  }
  else
  {
    UFG::qPropertyList::RemoveAll(this);
    this->mFlags |= 0x10000u;
  }
}

// File Line: 122
// RVA: 0x1F4060
UFG::qPropertyList *__fastcall UFG::qPropertyList::Create(const char *dbg_tag)
{
  UFG::qPropertyList *result; // rax
  UFG::qPropertyList *v2; // rsi

  result = (UFG::qPropertyList *)UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, 0x30ui64, dbg_tag, 0i64, 1u);
  v2 = result;
  if ( result )
  {
    UFG::qPropertyCollection::qPropertyCollection(result);
    Assembly::GetRCX(&v2->mValues);
    Assembly::GetRCX(&v2->mWeights);
    *(_QWORD *)&v2->mTypeUID = 29i64;
    v2->mFlags = 4;
    *(_QWORD *)&v2->mNumElements = 0i64;
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mValues, 0i64);
    UFG::qOffset64<unsigned long *>::Set(&v2->mWeights, 0i64);
    return v2;
  }
  return result;
}

// File Line: 128
// RVA: 0x1F2460
UFG::allocator::free_link *__fastcall UFG::qPropertyList::Clone(UFG::qPropertyList *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rsi

  v2 = UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, 0x30ui64, "qPropertyList", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    UFG::qPropertyCollection::qPropertyCollection((UFG::qPropertyCollection *)v2);
    Assembly::GetRCX(&v3[2]);
    Assembly::GetRCX(&v3[4]);
    v3[3].mNext = (UFG::allocator::free_link *)29;
    LODWORD(v3->mNext) = 4;
    v3[5].mNext = 0i64;
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v3[2], 0i64);
    UFG::qOffset64<unsigned long *>::Set((UFG::qOffset64<unsigned long *> *)&v3[4], 0i64);
  }
  else
  {
    v3 = 0i64;
  }
  UFG::qPropertyList::CopyFrom((UFG::qPropertyList *)v3, this);
  return v3;
}

// File Line: 141
// RVA: 0x1EB2D0
void __fastcall UFG::qPropertyList::SetPtr<char const>(
        UFG::qPropertyList *this,
        unsigned int property_type_uid,
        unsigned int index,
        char *property_set_data)
{
  UFG::qOffset64<char const *> *v5; // rax
  UFG::qOffset64<UFG::qPropertySet *> *v6; // rdi
  char *v7; // rax
  int v8; // eax
  char *v9; // rbx

  v5 = (UFG::qOffset64<char const *> *)UFG::qPropertyList::SetInternal(this, property_type_uid, index, 0i64);
  v6 = (UFG::qOffset64<UFG::qPropertySet *> *)v5;
  if ( v5->mOffset )
  {
    v7 = (char *)UFG::qOffset64<char const *>::Get(v5, 0i64);
    UFG::qPropertySet_Free(v7);
    v6->mOffset = 0i64;
  }
  v8 = UFG::qStringLength(property_set_data);
  v9 = (char *)UFG::qPropertySet_Allocate(v8 + 1, "PropertyString", 0x1000u);
  UFG::qStringCopy(v9, 0x7FFFFFFF, property_set_data, -1);
  UFG::qOffset64<unsigned long *>::operator=(v6, v9);
}

// File Line: 188
// RVA: 0x1EB020
void __fastcall UFG::qPropertyList::Set<UFG::qPropertySet>(
        UFG::qPropertyList *this,
        unsigned int index,
        UFG::qPropertySet *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertySet>(this, 0x1Au, index, v);
}

// File Line: 189
// RVA: 0x1EAFD0
void __fastcall UFG::qPropertyList::Set<UFG::qPropertyList>(
        UFG::qPropertyList *this,
        unsigned int index,
        UFG::qPropertyList *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertyList>(this, 0x19u, index, v);
}

// File Line: 193
// RVA: 0x1E8E70
void __fastcall UFG::qPropertyList::Add<bool>(UFG::qPropertyList *this, bool v)
{
  unsigned int mNumElements; // r8d
  bool va; // [rsp+38h] [rbp+10h] BYREF

  mNumElements = this->mNumElements;
  va = v;
  UFG::qPropertyList::SetInternal(this, 9u, mNumElements, &va);
}

// File Line: 195
// RVA: 0x1E8BA0
void __fastcall UFG::qPropertyList::Add<signed char>(UFG::qPropertyList *this, char v)
{
  char va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 0, this->mNumElements, &va);
}

// File Line: 196
// RVA: 0x1E8BE0
void __fastcall UFG::qPropertyList::Add<short>(UFG::qPropertyList *this, __int16 v)
{
  __int16 va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 1u, this->mNumElements, &va);
}

// File Line: 197
// RVA: 0x1E8C40
void __fastcall UFG::qPropertyList::Add<long>(UFG::qPropertyList *this, int v)
{
  int va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 2u, this->mNumElements, &va);
}

// File Line: 198
// RVA: 0x1E8E10
void __fastcall UFG::qPropertyList::Add<__int64>(UFG::qPropertyList *this, __int64 v)
{
  __int64 va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 3u, this->mNumElements, &va);
}

// File Line: 199
// RVA: 0x1E8BC0
void __fastcall UFG::qPropertyList::Add<unsigned char>(UFG::qPropertyList *this, char v)
{
  char va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 5u, this->mNumElements, &va);
}

// File Line: 200
// RVA: 0x1E8C10
void __fastcall UFG::qPropertyList::Add<unsigned short>(UFG::qPropertyList *this, unsigned __int16 v)
{
  unsigned __int16 va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 6u, this->mNumElements, &va);
}

// File Line: 201
// RVA: 0x1E8C60
void __fastcall UFG::qPropertyList::Add<unsigned long>(UFG::qPropertyList *this, unsigned int v)
{
  unsigned int va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 7u, this->mNumElements, &va);
}

// File Line: 202
// RVA: 0x1E8E40
void __fastcall UFG::qPropertyList::Add<unsigned __int64>(UFG::qPropertyList *this, __int64 v)
{
  __int64 va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 8u, this->mNumElements, &va);
}

// File Line: 204
// RVA: 0x1E8C80
void __fastcall UFG::qPropertyList::Add<float>(UFG::qPropertyList *this, float v)
{
  float va; // [rsp+38h] [rbp+10h] BYREF

  va = v;
  UFG::qPropertyList::SetInternal(this, 0xAu, this->mNumElements, &va);
}

// File Line: 207
// RVA: 0x1E8D50
void __fastcall UFG::qPropertyList::Add<UFG::qSymbol>(UFG::qPropertyList *this, UFG::qSymbol *v)
{
  UFG::qPropertyList::SetInternal(this, 0x16u, this->mNumElements, v);
}

// File Line: 208
// RVA: 0x1E8D70
void __fastcall UFG::qPropertyList::Add<UFG::qSymbolUC>(UFG::qPropertyList *this, UFG::qSymbolUC *v)
{
  UFG::qPropertyList::SetInternal(this, 0x17u, this->mNumElements, v);
}

// File Line: 209
// RVA: 0x1E8DF0
void __fastcall UFG::qPropertyList::Add<UFG::qWiseSymbol>(UFG::qPropertyList *this, UFG::qWiseSymbol *v)
{
  UFG::qPropertyList::SetInternal(this, 0x18u, this->mNumElements, v);
}

// File Line: 211
// RVA: 0x1E8D90
void __fastcall UFG::qPropertyList::Add<UFG::qVector2>(UFG::qPropertyList *this, UFG::qVector2 *v)
{
  UFG::qPropertyList::SetInternal(this, 0x11u, this->mNumElements, v);
}

// File Line: 212
// RVA: 0x1E8DB0
void __fastcall UFG::qPropertyList::Add<UFG::qVector3>(UFG::qPropertyList *this, UFG::qVector3 *v)
{
  UFG::qPropertyList::SetInternal(this, 0x12u, this->mNumElements, v);
}

// File Line: 213
// RVA: 0x1E8DD0
void __fastcall UFG::qPropertyList::Add<UFG::qVector4>(UFG::qPropertyList *this, UFG::qVector4 *v)
{
  UFG::qPropertyList::SetInternal(this, 0x13u, this->mNumElements, v);
}

// File Line: 214
// RVA: 0x1E8CF0
void __fastcall UFG::qPropertyList::Add<UFG::qMatrix44>(UFG::qPropertyList *this, UFG::qMatrix44 *v)
{
  UFG::qPropertyList::SetInternal(this, 0x14u, this->mNumElements, v);
}

// File Line: 215
// RVA: 0x1E8CD0
void __fastcall UFG::qPropertyList::Add<UFG::qTransQuat>(UFG::qPropertyList *this, UFG::qTransQuat *v)
{
  UFG::qPropertyList::SetInternal(this, 0x1Cu, this->mNumElements, v);
}

// File Line: 217
// RVA: 0x1E8D30
void __fastcall UFG::qPropertyList::Add<UFG::qPropertySet>(UFG::qPropertyList *this, UFG::qPropertySet *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertySet>(this, 0x1Au, this->mNumElements, v);
}

// File Line: 218
// RVA: 0x1E8D10
void __fastcall UFG::qPropertyList::Add<UFG::qPropertyList>(UFG::qPropertyList *this, UFG::qPropertyList *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertyList>(this, 0x19u, this->mNumElements, v);
}

// File Line: 219
// RVA: 0x1E8CB0
void __fastcall UFG::qPropertyList::Add<char const *>(UFG::qPropertyList *this, const char *v)
{
  UFG::qPropertyList::SetPtr<char const>(this, 0xCu, this->mNumElements, v);
}

// File Line: 222
// RVA: 0x1F1970
__int64 __fastcall UFG::qPropertyList::AddItem(UFG::qPropertyList *this, signed int type_uid)
{
  unsigned int v2; // ebx
  UFG::qPropertyList *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *ContainedSet; // rax
  unsigned int mNumElements; // r8d
  char *v8; // r9
  char dest[72]; // [rsp+20h] [rbp-48h] BYREF
  UFG::qSymbol result; // [rsp+78h] [rbp+10h] BYREF

  v2 = type_uid;
  v3 = this;
  if ( type_uid < 22 )
  {
LABEL_6:
    UFG::qMemSet(dest, 0, 0x40u);
    mNumElements = v3->mNumElements;
    v8 = dest;
    type_uid = v2;
    this = v3;
    goto LABEL_7;
  }
  if ( type_uid > 23 )
  {
    if ( type_uid == 26 )
    {
      v4 = UFG::qSymbol::create_from_string(&result, "PropSet");
      ContainedSet = UFG::qPropertySet::CreateContainedSet(v4, "qPropertyList::AddItem()");
      UFG::qPropertyList::SetPtr<UFG::qPropertySet>(v3, v2, v3->mNumElements, ContainedSet);
      return v3->mNumElements - 1;
    }
    goto LABEL_6;
  }
  mNumElements = this->mNumElements;
  v8 = (char *)&UFG::gNullQSymbol;
LABEL_7:
  UFG::qPropertyList::SetInternal(this, type_uid, mNumElements, v8);
  return v3->mNumElements - 1;
}

// File Line: 258
// RVA: 0x1EA580
bool *__fastcall UFG::qPropertyList::Get<bool>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v4; // rbx
  char *v5; // rcx
  bool *result; // rax

  if ( this->mTypeUID != 9 )
    return 0i64;
  if ( index >= this->mNumElements )
    return 0i64;
  v4 = UFG::qPropertyType::Get(9u);
  v5 = &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                 * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))];
  if ( !v5 )
    return 0i64;
  result = &qPropertyList_False;
  if ( *v5 )
    return &qPropertyList_True;
  return result;
}

// File Line: 264
// RVA: 0x1E9F80
UFG::qSymbol *__fastcall UFG::qPropertyList::Get<UFG::qSymbol>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 22 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x16u);
  return (UFG::qSymbol *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                   * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 265
// RVA: 0x1EA040
UFG::qSymbolUC *__fastcall UFG::qPropertyList::Get<UFG::qSymbolUC>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 23 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x17u);
  return (UFG::qSymbolUC *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                     * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 266
// RVA: 0x1EA340
UFG::qWiseSymbol *__fastcall UFG::qPropertyList::Get<UFG::qWiseSymbol>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 24 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x18u);
  return (UFG::qWiseSymbol *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                       * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 267
// RVA: 0x1E9580
char *__fastcall UFG::qPropertyList::Get<signed char>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 268
// RVA: 0x1E96F0
char *__fastcall UFG::qPropertyList::Get<short>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 1 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(1u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 269
// RVA: 0x1E9870
char *__fastcall UFG::qPropertyList::Get<long>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 2 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(2u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 270
// RVA: 0x1EA400
char *__fastcall UFG::qPropertyList::Get<__int64>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 3 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(3u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 271
// RVA: 0x1E9BC0
__m128 *__fastcall UFG::qPropertyList::Get<__m128>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 4 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(4u);
  return (__m128 *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                             * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 273
// RVA: 0x1E9630
char *__fastcall UFG::qPropertyList::Get<unsigned char>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 5 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(5u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 274
// RVA: 0x1E97B0
char *__fastcall UFG::qPropertyList::Get<unsigned short>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 6 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(6u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 275
// RVA: 0x1E9930
char *__fastcall UFG::qPropertyList::Get<unsigned long>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 7 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(7u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 276
// RVA: 0x1EA4C0
char *__fastcall UFG::qPropertyList::Get<unsigned __int64>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 8 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(8u);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                            + v5->mByteSize
                                                                                            - 1))];
}

// File Line: 278
// RVA: 0x1E99F0
float *__fastcall UFG::qPropertyList::Get<float>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 10 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0xAu);
  return (float *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                            * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 279
// RVA: 0x1EA100
UFG::qVector2 *__fastcall UFG::qPropertyList::Get<UFG::qVector2>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 17 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x11u);
  return (UFG::qVector2 *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                    * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 280
// RVA: 0x1EA1C0
UFG::qVector3 *__fastcall UFG::qPropertyList::Get<UFG::qVector3>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 18 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x12u);
  return (UFG::qVector3 *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                    * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 281
// RVA: 0x1EA280
UFG::qVector4 *__fastcall UFG::qPropertyList::Get<UFG::qVector4>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 19 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x13u);
  return (UFG::qVector4 *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                    * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 282
// RVA: 0x1E9D20
UFG::qMatrix44 *__fastcall UFG::qPropertyList::Get<UFG::qMatrix44>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v5; // rbx

  if ( this->mTypeUID != 20 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x14u);
  return (UFG::qMatrix44 *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                                     * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 286
// RVA: 0x1E9AB0
const char *__fastcall UFG::qPropertyList::Get<char const *>(UFG::qPropertyList *this, unsigned int index)
{
  UFG::qPropertyType *v4; // rbx
  UFG::qOffset64<char const *> *v5; // rcx

  if ( this->mTypeUID == 12
    && index < this->mNumElements
    && (v4 = UFG::qPropertyType::Get(0xCu),
        (v5 = (UFG::qOffset64<char const *> *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))]) != 0i64) )
  {
    return UFG::qOffset64<char const *>::Get(v5, 0i64);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 298
// RVA: 0x1F8E90
bool __fastcall UFG::qPropertyList::GetVariant(
        UFG::qPropertyList *this,
        unsigned int index,
        qPropertySetVariant *value)
{
  char v4; // cl
  bool result; // al
  __int16 v6; // cx
  int v7; // ecx
  __int64 v8; // rcx
  $9C4F4E44B7DEC05B9F65CCD36F88E8FF v9; // xmm0
  char v10; // cl
  __int16 v11; // cx
  int v12; // ecx
  __int64 v13; // rcx
  char v14; // cl
  int v15; // ecx
  const char *v16; // rax
  UFG::qVector2 *v17; // rax
  float y; // xmm0_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm0_4
  float z; // xmm1_4
  UFG::qVector4 *v22; // rax
  float x; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  UFG::qMatrix44 *v26; // rax
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  unsigned int mUID; // ecx
  unsigned int v31; // ecx
  UFG::qWiseSymbol *v32; // rax

  switch ( this->mTypeUID )
  {
    case 0u:
      v4 = *UFG::qPropertyList::Get<signed char>(this, index);
      value->meType = UID_int8;
      value->mValueI8 = v4;
      goto $LN19_8;
    case 1u:
      v6 = *(_WORD *)UFG::qPropertyList::Get<short>(this, index);
      value->meType = UID_int16;
      result = 1;
      value->mValueI16 = v6;
      break;
    case 2u:
      v7 = *(_DWORD *)UFG::qPropertyList::Get<long>(this, index);
      value->meType = UID_int32;
      result = 1;
      value->mValueI32 = v7;
      break;
    case 3u:
      v8 = *(_QWORD *)UFG::qPropertyList::Get<__int64>(this, index);
      value->meType = UID_int64;
      result = 1;
      value->mValueI64 = v8;
      break;
    case 4u:
      v9 = *($9C4F4E44B7DEC05B9F65CCD36F88E8FF *)UFG::qPropertyList::Get<__m128>(this, index);
      value->meType = UID_int128;
      result = 1;
      value->16 = v9;
      break;
    case 5u:
      v10 = *UFG::qPropertyList::Get<unsigned char>(this, index);
      value->meType = UID_uint8;
      result = 1;
      value->mValueI8 = v10;
      break;
    case 6u:
      v11 = *(_WORD *)UFG::qPropertyList::Get<unsigned short>(this, index);
      value->meType = UID_uint16;
      result = 1;
      value->mValueI16 = v11;
      break;
    case 7u:
      v12 = *(_DWORD *)UFG::qPropertyList::Get<unsigned long>(this, index);
      value->meType = UID_uint32;
      result = 1;
      value->mValueI32 = v12;
      break;
    case 8u:
      v13 = *(_QWORD *)UFG::qPropertyList::Get<unsigned __int64>(this, index);
      value->meType = UID_uint64;
      result = 1;
      value->mValueI64 = v13;
      break;
    case 9u:
      v14 = *UFG::qPropertyList::Get<bool>(this, index);
      value->meType = UID_bool;
      result = 1;
      value->mValueI8 = v14;
      break;
    case 0xAu:
      v15 = *(_DWORD *)UFG::qPropertyList::Get<float>(this, index);
      value->meType = UID_float;
      result = 1;
      value->mValueI32 = v15;
      break;
    case 0xBu:
$LN19_8:
      result = 1;
      break;
    case 0xCu:
      v16 = UFG::qPropertyList::Get<char const *>(this, index);
      UFG::qString::Set(&value->mValueString, v16);
      value->meType = UID_string;
      result = 1;
      break;
    case 0x11u:
      v17 = UFG::qPropertyList::Get<UFG::qVector2>(this, index);
      y = v17->y;
      value->mValueVector2.x = v17->x;
      value->mValueVector2.y = y;
      value->meType = UID_qVector2;
      result = 1;
      break;
    case 0x12u:
      v19 = UFG::qPropertyList::Get<UFG::qVector3>(this, index);
      v20 = v19->y;
      z = v19->z;
      value->mValueVector3.x = v19->x;
      result = 1;
      value->mValueVector3.y = v20;
      value->mValueVector3.z = z;
      value->meType = UID_qVector3;
      break;
    case 0x13u:
      v22 = UFG::qPropertyList::Get<UFG::qVector4>(this, index);
      x = v22->x;
      v24 = v22->y;
      v25 = v22->z;
      result = 1;
      value->mValueVector3.x = x;
      value->mValueVector3.y = v24;
      value->mValueVector3.z = v25;
      value->meType = UID_qVector4;
      break;
    case 0x14u:
      v26 = UFG::qPropertyList::Get<UFG::qMatrix44>(this, index);
      v27 = v26->v1;
      v28 = v26->v2;
      v29 = v26->v3;
      value->mValueMatrix44.v0 = v26->v0;
      value->mValueMatrix44.v1 = v27;
      result = 1;
      value->mValueMatrix44.v2 = v28;
      value->mValueMatrix44.v3 = v29;
      value->meType = UID_qMatrix44;
      break;
    case 0x16u:
      mUID = UFG::qPropertyList::Get<UFG::qSymbol>(this, index)->mUID;
      result = 1;
      value->mValueSymbol.mUID = mUID;
      value->meType = UID_qSymbol;
      break;
    case 0x17u:
      v31 = UFG::qPropertyList::Get<UFG::qSymbolUC>(this, index)->mUID;
      result = 1;
      value->mValueSymbolUC.mUID = v31;
      value->meType = UID_qSymbolUC;
      break;
    case 0x18u:
      v32 = UFG::qPropertyList::Get<UFG::qWiseSymbol>(this, index);
      UFG::qWiseSymbol::operator=(&value->mValueWiseSymbol, v32);
      value->meType = UID_qWiseSymbol;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 353
// RVA: 0x1FE650
bool __fastcall UFG::qPropertyList::SetVariant(
        UFG::qPropertyList *this,
        unsigned int index,
        qPropertySetVariant *value)
{
  bool result; // al
  $9C4F4E44B7DEC05B9F65CCD36F88E8FF v4; // [rsp+20h] [rbp-18h] BYREF
  __int64 v; // [rsp+50h] [rbp+18h] BYREF

  switch ( value->meType )
  {
    case UID_int8:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 0, index, &v);
      result = 1;
      break;
    case UID_int16:
      LOWORD(v) = value->mValueI16;
      UFG::qPropertyList::SetInternal(this, 1u, index, &v);
      result = 1;
      break;
    case UID_int32:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 2u, index, &v);
      result = 1;
      break;
    case UID_int64:
      v = value->mValueI64;
      UFG::qPropertyList::SetInternal(this, 3u, index, &v);
      result = 1;
      break;
    case UID_int128:
      v4 = value->16;
      UFG::qPropertyList::SetInternal(this, 4u, index, &v4);
      result = 1;
      break;
    case UID_uint8:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 5u, index, &v);
      result = 1;
      break;
    case UID_uint16:
      LOWORD(v) = value->mValueI16;
      UFG::qPropertyList::SetInternal(this, 6u, index, &v);
      result = 1;
      break;
    case UID_uint32:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 7u, index, &v);
      result = 1;
      break;
    case UID_uint64:
      v = value->mValueI64;
      UFG::qPropertyList::SetInternal(this, 8u, index, &v);
      result = 1;
      break;
    case UID_bool:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 9u, index, &v);
      result = 1;
      break;
    case UID_float:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 0xAu, index, &v);
      result = 1;
      break;
    case UID_double:
    case UID_string:
      UFG::qPropertyList::SetPtr<char const>(this, 0xCu, index, value->mValueString.mData);
      result = 1;
      break;
    case UID_qVector2:
      UFG::qPropertyList::SetInternal(this, 0x11u, index, &value->mValueVector2);
      result = 1;
      break;
    case UID_qVector3:
      UFG::qPropertyList::SetInternal(this, 0x12u, index, &value->mValueVector3);
      result = 1;
      break;
    case UID_qVector4:
      UFG::qPropertyList::SetInternal(this, 0x13u, index, &value->mValueVector4);
      result = 1;
      break;
    case UID_qSymbol:
      UFG::qPropertyList::SetInternal(this, 0x16u, index, &value->mValueSymbol);
      result = 1;
      break;
    case UID_qSymbolUC:
      UFG::qPropertyList::SetInternal(this, 0x17u, index, &value->mValueSymbolUC);
      result = 1;
      break;
    case UID_qWiseSymbol:
      UFG::qPropertyList::SetInternal(this, 0x18u, index, &value->mValueWiseSymbol);
      goto LABEL_20;
    default:
LABEL_20:
      result = 1;
      break;
  }
  return result;
}

// File Line: 408
// RVA: 0x1F2650
void __fastcall UFG::qPropertyList::CopyFrom(UFG::qPropertyList *this, UFG::qPropertyList *source_list)
{
  UFG::qPropertyList *v3; // rbp
  char *v4; // rax
  unsigned int v5; // ebx
  char *v6; // rdi
  char *v7; // rax
  char *v8; // rdx
  char *v9; // rdi
  unsigned int *v10; // rbx
  unsigned int mTypeUID; // eax
  unsigned int v12; // edi
  UFG::qPropertyType *v13; // rbx
  UFG::qOffset64<unsigned char *> *v14; // rcx
  UFG::qSymbol *v15; // r8
  UFG::qOffset64<UFG::qPropertySet *> *v16; // rbx
  UFG::qPropertySet *ContainedSet; // rdi
  unsigned int v18; // ebp
  UFG::qPropertyType *v19; // rbx
  UFG::qPropertyList *v20; // rsi
  UFG::qOffset64<UFG::qPropertySet *> *v21; // rbx
  UFG::qPropertyList *v22; // rdi
  unsigned int v23; // ebx
  UFG::qPropertyType *v24; // rdi
  const char *v25; // rax
  const char *v26; // rbp
  UFG::qOffset64<UFG::qPropertySet *> *v27; // rsi
  unsigned int v28; // edi
  void *v29; // rbx
  void *target; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *targeta; // [rsp+20h] [rbp-38h]
  UFG::qPropertyType *v32; // [rsp+28h] [rbp-30h]
  UFG::qPropertyType *v33; // [rsp+28h] [rbp-30h]
  UFG::qPropertyType *v34; // [rsp+28h] [rbp-30h]
  unsigned int owningLista; // [rsp+60h] [rbp+8h]
  unsigned int v38; // [rsp+68h] [rbp+10h]
  unsigned int *source; // [rsp+70h] [rbp+18h]
  unsigned int sourcea; // [rsp+70h] [rbp+18h]
  unsigned int sourceb; // [rsp+70h] [rbp+18h]
  unsigned int sourcec; // [rsp+70h] [rbp+18h]
  char *v43; // [rsp+78h] [rbp+20h]

  v3 = source_list;
  v4 = UFG::qOffset64<unsigned char *>::Get(&source_list->mValues, 0i64);
  v5 = v3->mNumElements * v3->mElementSize;
  v6 = v4;
  v7 = (char *)UFG::qPropertySet_Allocate(v5, "PropertyData", 0x1000u);
  v8 = v6;
  v43 = v7;
  v9 = v7;
  UFG::qMemCopy(v7, v8, v5);
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mValues, v9);
  this->mNumElements = v3->mNumElements;
  this->mElementSize = v3->mElementSize;
  this->mTotalWeight = v3->mTotalWeight;
  this->mTypeUID = v3->mTypeUID;
  source = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v3->mWeights);
  if ( source )
  {
    v10 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
    target = UFG::qPropertySet_Allocate(4 * v3->mNumElements, "PropertyWeights", 0);
    UFG::qMemCopy(target, source, 4 * v3->mNumElements);
    if ( v10 )
      UFG::qPropertySet_Free(v10);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mWeights, target);
  }
  mTypeUID = this->mTypeUID;
  switch ( mTypeUID )
  {
    case 0x1Au:
      v32 = UFG::qPropertyType::Get(0x1Au);
      v12 = 0;
      v38 = 0;
      sourcea = this->mNumElements;
      if ( sourcea )
      {
        do
        {
          if ( v3->mTypeUID == 26
            && v12 < v3->mNumElements
            && (v13 = UFG::qPropertyType::Get(0x1Au),
                (v14 = (UFG::qOffset64<unsigned char *> *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v12 * ((v13->Alignment + v13->mByteSize - 1) & ~(v13->Alignment - 1))]) != 0i64) )
          {
            v15 = (UFG::qSymbol *)UFG::qOffset64<unsigned char *>::Get(v14, 0i64);
          }
          else
          {
            v15 = 0i64;
          }
          targeta = (UFG::qPropertySet *)v15;
          v16 = (UFG::qOffset64<UFG::qPropertySet *> *)&v43[v12
                                                          * (~(v32->Alignment - 1) & (v32->Alignment + v32->mByteSize - 1))];
          ContainedSet = UFG::qPropertySet::CreateContainedSet(v15 + 16, "qPropertySet");
          UFG::qOffset64<unsigned long *>::operator=(v16, ContainedSet);
          UFG::qPropertyCollection::SetOwner(ContainedSet, this);
          UFG::qPropertySet::AddRef(ContainedSet);
          UFG::qPropertySet::CopyFrom(ContainedSet, targeta, 1);
          v12 = v38 + 1;
          v38 = v12;
        }
        while ( v12 < sourcea );
      }
      break;
    case 0x19u:
      v18 = 0;
      v19 = UFG::qPropertyType::Get(0x19u);
      v33 = v19;
      sourceb = this->mNumElements;
      if ( sourceb )
      {
        do
        {
          v20 = UFG::qPropertyList::Get<UFG::qPropertyList>(source_list, v18);
          v21 = (UFG::qOffset64<UFG::qPropertySet *> *)&v9[v18
                                                         * (~(v19->Alignment - 1) & (v19->Alignment + v19->mByteSize - 1))];
          v22 = UFG::qPropertyList::Create("qPropertyList");
          UFG::qOffset64<unsigned long *>::operator=(v21, v22);
          UFG::qPropertyCollection::SetOwner(v22, this);
          UFG::qPropertyList::CopyFrom(v22, v20);
          v19 = v33;
          v9 = v43;
          ++v18;
        }
        while ( v18 < sourceb );
      }
      break;
    case 0xCu:
      v23 = 0;
      v24 = UFG::qPropertyType::Get(0xCu);
      v34 = v24;
      owningLista = this->mNumElements;
      sourcec = 0;
      if ( owningLista )
      {
        do
        {
          v25 = UFG::qPropertyList::Get<char const *>(v3, v23);
          v26 = &customCaption;
          if ( v25 )
            v26 = v25;
          v27 = (UFG::qOffset64<UFG::qPropertySet *> *)&v43[v23
                                                          * (~(v24->Alignment - 1) & (v24->Alignment + v24->mByteSize - 1))];
          v28 = UFG::qStringLength(v26) + 1;
          v29 = UFG::qPropertySet_Allocate(v28, "PropertyListString", 0);
          UFG::qOffset64<unsigned long *>::operator=(v27, v29);
          UFG::qMemCopy(v29, v26, v28);
          v3 = source_list;
          v24 = v34;
          v23 = sourcec + 1;
          sourcec = v23;
        }
        while ( v23 < owningLista );
      }
      break;
  }
}

// File Line: 506
// RVA: 0x1F8920
char *__fastcall UFG::qPropertyList::GetValuePtr(UFG::qPropertyList *this, unsigned int type_uid, unsigned int index)
{
  unsigned int mTypeUID; // ecx
  UFG::qPropertyType *v7; // rbx

  mTypeUID = this->mTypeUID;
  if ( type_uid != mTypeUID || index >= this->mNumElements )
    return 0i64;
  v7 = UFG::qPropertyType::Get(mTypeUID);
  return &UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index
                                                                   * (~(v7->Alignment - 1) & (v7->Alignment
                                                                                            + v7->mByteSize
                                                                                            - 1))];
}

// File Line: 532
// RVA: 0x1FB050
void __fastcall UFG::RecalcPropertyListPtrOffsets(
        char *old_data,
        char *new_data,
        unsigned int element_count,
        UFG::qPropertyType *type)
{
  unsigned int v8; // r9d
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // rax

  if ( UFG::qPropertyType::IsPtrType(type->mNameUID) )
  {
    v8 = ~(type->Alignment - 1) & (type->Alignment + type->mByteSize - 1);
    if ( element_count )
    {
      v9 = 0i64;
      v10 = element_count;
      do
      {
        v11 = *(_QWORD *)&new_data[v9];
        if ( v11 )
          *(_QWORD *)&new_data[v9] = &old_data[v11 - (_QWORD)new_data];
        v9 = v8 + (unsigned int)v9;
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 553
// RVA: 0x1FD420
UFG::qPropertyType *__fastcall UFG::qPropertyList::SetInternal(
        UFG::qPropertyList *this,
        unsigned int type_uid,
        unsigned int index,
        const void *v)
{
  UFG::qPropertyType *result; // rax
  UFG::qPropertyType *v9; // r14
  unsigned int mNumElements; // r13d
  UFG::qOffset64<unsigned char *> *p_mValues; // rcx
  unsigned int v12; // r14d
  unsigned int *v13; // rax
  char *v14; // rbx
  unsigned int mElementSize; // edi
  unsigned int v16; // r13d
  unsigned int *v17; // rdi
  _BYTE *v18; // rbx
  char *v19; // rcx
  char *target; // [rsp+20h] [rbp-38h]
  unsigned int *old_data; // [rsp+28h] [rbp-30h]
  unsigned int v22; // [rsp+68h] [rbp+10h]

  if ( type_uid == 29 || index > this->mNumElements )
    return 0i64;
  result = UFG::qPropertyType::Get(type_uid);
  v9 = result;
  if ( result )
  {
    if ( this->mTypeUID == 29 )
    {
      this->mTypeUID = type_uid;
      this->mElementSize = result->mByteSize;
    }
    mNumElements = this->mNumElements;
    p_mValues = &this->mValues;
    if ( index >= mNumElements )
    {
      mElementSize = this->mElementSize;
      v22 = mElementSize;
      v16 = mElementSize * mNumElements;
      old_data = UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)p_mValues);
      target = (char *)UFG::qPropertySet_Allocate(mElementSize + v16, "PropertyData", 0x1000u);
      UFG::qMemCopy(target, old_data, v16);
      UFG::qMemSet(&target[v16], 0, mElementSize);
      UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mValues, target);
      if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights) )
      {
        v17 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
        v18 = UFG::qPropertySet_Allocate(4 * this->mNumElements + 4, "PropertyWeights", 0);
        UFG::qMemCopy(v18, v17, 4 * this->mNumElements);
        *(_DWORD *)&v18[4 * this->mNumElements] = 0;
        UFG::qPropertySet_Free(v17);
        UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mWeights, v18);
        mElementSize = v22;
      }
      UFG::RecalcPropertyListPtrOffsets((char *)old_data, target, ++this->mNumElements, v9);
      UFG::qPropertySet_Free(old_data);
      v19 = (char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&this->mValues)
          + v16;
      if ( v )
        UFG::qMemCopy(v19, v, mElementSize);
      else
        UFG::qMemSet(v19, 0, mElementSize);
      return (UFG::qPropertyType *)((char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&this->mValues)
                                  + v16);
    }
    else
    {
      v12 = this->mElementSize;
      v13 = UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)p_mValues);
      v14 = (char *)v13 + index * v12;
      if ( v )
        UFG::qMemCopy((char *)v13 + index * v12, v, v12);
      return (UFG::qPropertyType *)v14;
    }
  }
  return result;
}

// File Line: 659
// RVA: 0x1EB490
void __fastcall UFG::qPropertyList::SetPtr<UFG::qPropertyList>(
        UFG::qPropertyList *this,
        unsigned int property_type_uid,
        unsigned int index,
        AMD_HD3D *property_set_data)
{
  char *v4; // [rsp+20h] [rbp-38h]
  UFG::qPropertyList *v5; // [rsp+30h] [rbp-28h]
  char *v6; // [rsp+38h] [rbp-20h]
  char *v7; // [rsp+40h] [rbp-18h]

  v4 = (char *)UFG::qPropertyList::SetInternal(this, property_type_uid, index, 0i64);
  if ( *(_QWORD *)v4 )
    v5 = (UFG::qPropertyList *)&v4[*(_QWORD *)v4];
  else
    v5 = 0i64;
  if ( v5 )
  {
    if ( v5 != (UFG::qPropertyList *)property_set_data )
    {
      UFG::qPropertyList::ReleaseRef(v5);
      UFG::qPropertyCollection::SetOwner(v5, 0i64);
      if ( property_set_data )
        v6 = (char *)((char *)property_set_data - v4);
      else
        v6 = 0i64;
      *(_QWORD *)v4 = v6;
      _(property_set_data);
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)property_set_data, this);
    }
  }
  else
  {
    if ( property_set_data )
      v7 = (char *)((char *)property_set_data - v4);
    else
      v7 = 0i64;
    *(_QWORD *)v4 = v7;
    _(property_set_data);
    UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)property_set_data, this);
  }
}

// File Line: 705
// RVA: 0x1FEC10
void __fastcall UFG::qPropertyList::SetWeight(UFG::qPropertyList *this, unsigned int index, unsigned int w)
{
  __int64 v5; // r14
  unsigned int *v6; // rdi

  v5 = index;
  v6 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
  if ( !v6 )
  {
    v6 = (unsigned int *)UFG::qPropertySet_Allocate(4 * this->mNumElements, "PropertyWeights", 0);
    UFG::qMemSet(v6, 0, 4 * this->mNumElements);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mWeights, v6);
  }
  this->mTotalWeight -= v6[v5];
  v6[v5] = w;
  this->mTotalWeight += w;
}

// File Line: 719
// RVA: 0x1F8010
__int64 __fastcall UFG::qPropertyList::GetRandomIndex(UFG::qPropertyList *this)
{
  unsigned int mTotalWeight; // esi
  unsigned int *v3; // rbx
  unsigned int mNumElements; // edi
  int v5; // ecx
  __int64 result; // rax

  mTotalWeight = this->mTotalWeight;
  v3 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
  if ( !v3 )
    return UFG::qRandom(this->mNumElements, (unsigned int *)&UFG::qDefaultSeed);
  mNumElements = this->mNumElements;
  v5 = UFG::qRandom(mTotalWeight, (unsigned int *)&UFG::qDefaultSeed);
  result = 0i64;
  if ( !mNumElements )
    return 0i64;
  while ( 1 )
  {
    v5 -= *v3;
    if ( v5 < 0 )
      break;
    result = (unsigned int)(result + 1);
    ++v3;
    if ( (unsigned int)result >= mNumElements )
      return 0i64;
  }
  return result;
}

// File Line: 753
// RVA: 0x1E94D0
__int64 __fastcall UFG::qPropertyList::FindElement<UFG::qPropertySet>(UFG::qPropertyList *this, UFG::qPropertySet *v)
{
  unsigned int mNumElements; // ebp
  unsigned int v3; // ebx
  UFG::qPropertyType *v6; // rdi
  UFG::qOffset64<unsigned char *> *v7; // rcx
  UFG::qPropertySet *v8; // rax

  mNumElements = this->mNumElements;
  v3 = 0;
  if ( !mNumElements )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    if ( this->mTypeUID == 26
      && v3 < this->mNumElements
      && (v6 = UFG::qPropertyType::Get(0x1Au),
          (v7 = (UFG::qOffset64<unsigned char *> *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[v3 * ((v6->mByteSize + v6->Alignment - 1) & ~(v6->Alignment - 1))]) != 0i64) )
    {
      v8 = (UFG::qPropertySet *)UFG::qOffset64<unsigned char *>::Get(v7, 0i64);
    }
    else
    {
      v8 = 0i64;
    }
    if ( v8 == v )
      break;
    if ( ++v3 >= mNumElements )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 768
// RVA: 0x1F5680
void __fastcall UFG::qPropertyList::FreePropertyPtrData(
        UFG::qPropertyList *this,
        char *values,
        unsigned int element_index,
        UFG::qPropertyType *_property_type)
{
  unsigned int mNameUID; // eax
  UFG::qPropertyCollection *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertyCollection *v7; // rax
  UFG::qPropertyList *v8; // rbx
  UFG::qOffset64<char const *> *v9; // rbx
  char *v10; // rax

  mNameUID = _property_type->mNameUID;
  switch ( mNameUID )
  {
    case 0x1Au:
      v5 = (UFG::qPropertyCollection *)UFG::qOffset64<unsigned char *>::Get(
                                         (UFG::qOffset64<unsigned char *> *)&values[element_index
                                                                                  * ((_property_type->Alignment
                                                                                    + _property_type->mByteSize
                                                                                    - 1) & ~(_property_type->Alignment
                                                                                           - 1))],
                                         0i64);
      v6 = (UFG::qPropertySet *)v5;
      if ( v5 )
      {
        UFG::qPropertyCollection::SetOwner(v5, 0i64);
        UFG::qPropertySet::ReleaseRef(v6);
      }
      break;
    case 0x19u:
      v7 = (UFG::qPropertyCollection *)UFG::qOffset64<char const *>::Get(
                                         (UFG::qOffset64<char const *> *)&values[element_index
                                                                               * ((_property_type->Alignment
                                                                                 + _property_type->mByteSize
                                                                                 - 1) & ~(_property_type->Alignment - 1))],
                                         0i64);
      v8 = (UFG::qPropertyList *)v7;
      if ( v7 )
      {
        UFG::qPropertyCollection::SetOwner(v7, 0i64);
        UFG::qPropertyList::ReleaseRef(v8);
      }
      break;
    case 0xCu:
      v9 = (UFG::qOffset64<char const *> *)&values[element_index
                                                 * (~(_property_type->Alignment - 1) & (_property_type->Alignment
                                                                                      + _property_type->mByteSize
                                                                                      - 1))];
      v10 = (char *)UFG::qOffset64<char const *>::Get(v9, 0i64);
      if ( v10 )
      {
        UFG::qPropertySet_Free(v10);
        v9->mOffset = 0i64;
      }
      break;
  }
}

// File Line: 808
// RVA: 0x1FB5A0
void __fastcall UFG::qPropertyList::Remove(UFG::qPropertyList *this, unsigned int index)
{
  __int64 v3; // r12
  unsigned int v4; // r14d
  int v5; // ebp
  char *v6; // rsi
  char *v7; // r15
  unsigned int v8; // ebx
  unsigned int *v9; // rsi
  char *v10; // rdi
  unsigned int v11; // r8d
  unsigned int v12; // r9d
  __int64 v13; // r10
  __int64 v14; // rax
  char *v15; // [rsp+60h] [rbp+8h]
  UFG::qPropertyType *v16; // [rsp+70h] [rbp+18h]

  v3 = index;
  v16 = UFG::qPropertyType::Get(this->mTypeUID);
  v4 = this->mNumElements - 1;
  v5 = ~(v16->Alignment - 1) & (v16->Alignment + v16->mByteSize - 1);
  v6 = (char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&this->mValues);
  v15 = v6;
  v7 = (char *)UFG::qPropertySet_Allocate(v4 * v5, "PropertyListData", 0x1000u);
  UFG::qPropertyList::FreePropertyPtrData(this, v6, v3, v16);
  v8 = v5 * (this->mNumElements - v3 - 1);
  UFG::qMemCopy(v7, v6, v3 * v5);
  UFG::qMemCopy(&v7[(int)v3 * v5], &v6[(int)v3 * v5 + v5], v8);
  if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights) )
  {
    v9 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
    v10 = (char *)UFG::qPropertySet_Allocate(4 * v4, "PropertyListWeights", 0);
    UFG::qMemCopy(v10, v9, 4 * v3);
    UFG::qMemCopy(&v10[4 * v3], v9, 4 * (this->mNumElements - v3) - 4);
    this->mTotalWeight -= v9[v3];
    UFG::qPropertySet_Free(v9);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mWeights, v10);
    v6 = v15;
  }
  if ( UFG::qPropertyType::IsPtrType(v16->mNameUID) )
  {
    v11 = 0;
    if ( v4 )
    {
      v12 = 0;
      do
      {
        v13 = v12;
        v14 = *(_QWORD *)&v7[v12];
        if ( v14 )
        {
          v14 -= v7 - v6;
          if ( v11 >= (unsigned int)v3 )
            v14 += v5;
        }
        ++v11;
        v12 += v5;
        *(_QWORD *)&v7[v13] = v14;
      }
      while ( v11 < v4 );
    }
  }
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mValues, v7);
  UFG::qPropertySet_Free(v6);
  this->mNumElements = v4;
  if ( !v4 )
    this->mTypeUID = 29;
}

// File Line: 883
// RVA: 0x1FB810
void __fastcall UFG::qPropertyList::RemoveAll(UFG::qPropertyList *this)
{
  unsigned int *v2; // r14
  UFG::qPropertyType *v3; // rdi
  unsigned int i; // ebx
  unsigned int mNameUID; // eax
  UFG::qPropertyCollection *v6; // rax
  UFG::qPropertySet *v7; // rsi
  UFG::qPropertyCollection *v8; // rax
  UFG::qPropertyList *v9; // rsi
  UFG::qOffset64<char const *> *v10; // rsi
  char *v11; // rax
  unsigned int *v12; // rax

  v2 = UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&this->mValues);
  v3 = UFG::qPropertyType::Get(this->mTypeUID);
  if ( UFG::qPropertyType::IsPtrType(this->mTypeUID) )
  {
    for ( i = 0; i < this->mNumElements; ++i )
    {
      mNameUID = v3->mNameUID;
      switch ( mNameUID )
      {
        case 0x1Au:
          v6 = (UFG::qPropertyCollection *)UFG::qOffset64<unsigned char *>::Get(
                                             (UFG::qOffset64<unsigned char *> *)((char *)v2
                                                                               + i
                                                                               * ((v3->Alignment + v3->mByteSize - 1) & ~(v3->Alignment - 1))),
                                             0i64);
          v7 = (UFG::qPropertySet *)v6;
          if ( v6 )
          {
            UFG::qPropertyCollection::SetOwner(v6, 0i64);
            UFG::qPropertySet::ReleaseRef(v7);
          }
          break;
        case 0x19u:
          v8 = (UFG::qPropertyCollection *)UFG::qOffset64<char const *>::Get(
                                             (UFG::qOffset64<char const *> *)((char *)v2
                                                                            + i
                                                                            * ((v3->Alignment + v3->mByteSize - 1) & ~(v3->Alignment - 1))),
                                             0i64);
          v9 = (UFG::qPropertyList *)v8;
          if ( v8 )
          {
            UFG::qPropertyCollection::SetOwner(v8, 0i64);
            UFG::qPropertyList::ReleaseRef(v9);
          }
          break;
        case 0xCu:
          v10 = (UFG::qOffset64<char const *> *)((char *)v2
                                               + i * (~(v3->Alignment - 1) & (v3->Alignment + v3->mByteSize - 1)));
          v11 = (char *)UFG::qOffset64<char const *>::Get(v10, 0i64);
          if ( v11 )
          {
            UFG::qPropertySet_Free(v11);
            v10->mOffset = 0i64;
          }
          break;
      }
    }
  }
  UFG::qPropertySet_Free(v2);
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mValues, 0i64);
  this->mNumElements = 0;
  if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights) )
  {
    v12 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
    UFG::qPropertySet_Free(v12);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&this->mWeights, 0i64);
  }
  this->mTypeUID = 29;
}

