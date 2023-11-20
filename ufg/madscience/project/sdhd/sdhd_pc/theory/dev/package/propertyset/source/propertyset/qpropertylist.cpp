// File Line: 46
// RVA: 0x1ED3A0
void __fastcall UFG::qPropertyList::qPropertyList(UFG::qPropertyList *this)
{
  UFG::qPropertyList *v1; // rsi
  unsigned int v2; // ebx
  unsigned int v3; // eax
  unsigned int v4; // ebp
  UFG::qPropertyType *v5; // rdi
  UFG::qOffset64<unsigned char *> *v6; // rcx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // edi
  UFG::qPropertyList *v9; // rax
  unsigned int v10; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = 0;
  UFG::qPropertyCollection::qPropertyCollection((UFG::qPropertyCollection *)&this->mFlags, 0);
  Assembly::GetRCX(&v1->mValues);
  Assembly::GetRCX(&v1->mWeights);
  v3 = v1->mTypeUID;
  if ( v3 == 26 )
  {
    v10 = v1->mNumElements;
    v4 = 0;
    if ( v10 )
    {
      do
      {
        if ( v1->mTypeUID == 26
          && v4 < v1->mNumElements
          && (v5 = UFG::qPropertyType::Get(0x1Au),
              (v6 = (UFG::qOffset64<unsigned char *> *)&UFG::qOffset64<unsigned char *>::Get(&v1->mValues, 0i64)[v4 * ((v5->Alignment + v5->mByteSize - 1) & ~(v5->Alignment - 1))]) != 0i64) )
        {
          v7 = (UFG::qPropertySet *)UFG::qOffset64<unsigned char *>::Get(v6, 0i64);
        }
        else
        {
          v7 = 0i64;
        }
        if ( v7 )
          UFG::qPropertySet::qPropertySet(v7);
        ++v4;
      }
      while ( v4 < v10 );
    }
  }
  else if ( v3 == 25 )
  {
    v8 = v1->mNumElements;
    if ( v8 )
    {
      do
      {
        v9 = UFG::qPropertyList::Get<UFG::qPropertyList>(v1, v2);
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
  UFG::qPropertyList *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // esi
  unsigned int v4; // edi
  UFG::qPropertySet *v5; // rax
  unsigned int v6; // esi
  unsigned int v7; // edi
  UFG::qPropertyList *v8; // rax

  v1 = this;
  if ( this->mFlags & 1 )
  {
    v2 = this->mTypeUID;
    if ( v2 == 26 )
    {
      v3 = this->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qPropertySet>(v1, v4);
          UFG::qPropertySet::~qPropertySet(v5);
          ++v4;
        }
        while ( v4 < v3 );
LABEL_5:
        v1->mFlags |= 0x10000u;
        return;
      }
    }
    else if ( v2 == 25 )
    {
      v6 = this->mNumElements;
      v7 = 0;
      if ( v6 )
      {
        do
        {
          v8 = UFG::qPropertyList::Get<UFG::qPropertyList>(v1, v7);
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
    v1->mFlags |= 0x10000u;
  }
}

// File Line: 122
// RVA: 0x1F4060
UFG::allocator::free_link *__fastcall UFG::qPropertyList::Create(const char *dbg_tag)
{
  UFG::allocator::free_link *result; // rax
  UFG::qPropertyList *v2; // rsi

  result = UFG::qMemoryPool::Allocate(&gPropertySetMemoryPool, 0x30ui64, dbg_tag, 0i64, 1u);
  v2 = (UFG::qPropertyList *)result;
  if ( result )
  {
    UFG::qPropertyCollection::qPropertyCollection((UFG::qPropertyCollection *)result);
    Assembly::GetRCX(&v2->mValues);
    Assembly::GetRCX(&v2->mWeights);
    *(_QWORD *)&v2->mTypeUID = 29i64;
    v2->mFlags = 4;
    *(_QWORD *)&v2->mNumElements = 0i64;
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mValues, 0i64);
    UFG::qOffset64<unsigned long *>::Set(&v2->mWeights, 0i64);
    result = (UFG::allocator::free_link *)v2;
  }
  return result;
}

// File Line: 128
// RVA: 0x1F2460
UFG::allocator::free_link *__fastcall UFG::qPropertyList::Clone(UFG::qPropertyList *this)
{
  UFG::qPropertyList *v1; // rbp
  UFG::allocator::free_link *v2; // rax
  UFG::allocator::free_link *v3; // rsi

  v1 = this;
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
  UFG::qPropertyList::CopyFrom((UFG::qPropertyList *)v3, v1);
  return v3;
}

// File Line: 141
// RVA: 0x1EB2D0
void __fastcall UFG::qPropertyList::SetPtr<char const>(UFG::qPropertyList *this, unsigned int property_type_uid, unsigned int index, const char *property_set_data)
{
  const char *v4; // rsi
  UFG::qOffset64<char const *> *v5; // rax
  UFG::qOffset64<UFG::qPropertySet *> *v6; // rdi
  char *v7; // rax
  int v8; // eax
  char *v9; // rbx

  v4 = property_set_data;
  v5 = (UFG::qOffset64<char const *> *)UFG::qPropertyList::SetInternal(this, property_type_uid, index, 0i64);
  v6 = (UFG::qOffset64<UFG::qPropertySet *> *)v5;
  if ( v5->mOffset )
  {
    v7 = (char *)UFG::qOffset64<char const *>::Get(v5, 0i64);
    UFG::qPropertySet_Free(v7);
    v6->mOffset = 0i64;
  }
  v8 = UFG::qStringLength(v4);
  v9 = (char *)UFG::qPropertySet_Allocate(v8 + 1, "PropertyString", 0x1000u);
  UFG::qStringCopy(v9, 0x7FFFFFFF, v4, -1);
  UFG::qOffset64<unsigned long *>::operator=(v6, v9);
}

// File Line: 188
// RVA: 0x1EB020
void __fastcall UFG::qPropertyList::Set<UFG::qPropertySet>(UFG::qPropertyList *this, unsigned int index, UFG::qPropertySet *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertySet>(this, 0x1Au, index, v);
}

// File Line: 189
// RVA: 0x1EAFD0
void __fastcall UFG::qPropertyList::Set<UFG::qPropertyList>(UFG::qPropertyList *this, unsigned int index, UFG::qPropertyList *v)
{
  UFG::qPropertyList::SetPtr<UFG::qPropertyList>(this, 0x19u, index, v);
}

// File Line: 193
// RVA: 0x1E8E70
void __fastcall UFG::qPropertyList::Add<bool>(UFG::qPropertyList *this, bool v)
{
  unsigned int v2; // er8
  bool va; // [rsp+38h] [rbp+10h]

  v2 = this->mNumElements;
  va = v;
  UFG::qPropertyList::SetInternal(this, 9u, v2, &va);
}

// File Line: 195
// RVA: 0x1E8BA0
void __fastcall UFG::qPropertyList::Add<signed char>(UFG::qPropertyList *this, char v)
{
  char va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 0, this->mNumElements, &va);
}

// File Line: 196
// RVA: 0x1E8BE0
void __fastcall UFG::qPropertyList::Add<short>(UFG::qPropertyList *this, __int16 v)
{
  __int16 va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 1u, this->mNumElements, &va);
}

// File Line: 197
// RVA: 0x1E8C40
void __fastcall UFG::qPropertyList::Add<long>(UFG::qPropertyList *this, int v)
{
  int va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 2u, this->mNumElements, &va);
}

// File Line: 198
// RVA: 0x1E8E10
void __fastcall UFG::qPropertyList::Add<__int64>(UFG::qPropertyList *this, __int64 v)
{
  __int64 va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 3u, this->mNumElements, &va);
}

// File Line: 199
// RVA: 0x1E8BC0
void __fastcall UFG::qPropertyList::Add<unsigned char>(UFG::qPropertyList *this, char v)
{
  char va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 5u, this->mNumElements, &va);
}

// File Line: 200
// RVA: 0x1E8C10
void __fastcall UFG::qPropertyList::Add<unsigned short>(UFG::qPropertyList *this, unsigned __int16 v)
{
  unsigned __int16 va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 6u, this->mNumElements, &va);
}

// File Line: 201
// RVA: 0x1E8C60
void __fastcall UFG::qPropertyList::Add<unsigned long>(UFG::qPropertyList *this, unsigned int v)
{
  unsigned int va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 7u, this->mNumElements, &va);
}

// File Line: 202
// RVA: 0x1E8E40
void __fastcall UFG::qPropertyList::Add<unsigned __int64>(UFG::qPropertyList *this, unsigned __int64 v)
{
  unsigned __int64 va; // [rsp+38h] [rbp+10h]

  va = v;
  UFG::qPropertyList::SetInternal(this, 8u, this->mNumElements, &va);
}

// File Line: 204
// RVA: 0x1E8C80
void __fastcall UFG::qPropertyList::Add<float>(UFG::qPropertyList *this, float v)
{
  float va; // [rsp+38h] [rbp+10h]

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
__int64 __fastcall UFG::qPropertyList::AddItem(UFG::qPropertyList *this, ePropertyType type_uid)
{
  ePropertyType v2; // ebx
  UFG::qPropertyList *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qPropertySet *v5; // rax
  unsigned int v7; // er8
  char *v8; // r9
  char dest; // [rsp+20h] [rbp-48h]
  UFG::qSymbol result; // [rsp+78h] [rbp+10h]

  v2 = type_uid;
  v3 = this;
  if ( (signed int)type_uid < 22 )
  {
LABEL_6:
    UFG::qMemSet(&dest, 0, 0x40u);
    v7 = v3->mNumElements;
    v8 = &dest;
    type_uid = v2;
    this = v3;
    goto LABEL_7;
  }
  if ( (signed int)type_uid > 23 )
  {
    if ( type_uid == 26 )
    {
      v4 = UFG::qSymbol::create_from_string(&result, "PropSet");
      v5 = UFG::qPropertySet::CreateContainedSet(v4, "qPropertyList::AddItem()");
      UFG::qPropertyList::SetPtr<UFG::qPropertySet>(v3, v2, v3->mNumElements, v5);
      return v3->mNumElements - 1;
    }
    goto LABEL_6;
  }
  v7 = this->mNumElements;
  v8 = (char *)&UFG::gNullQSymbol;
LABEL_7:
  UFG::qPropertyList::SetInternal(this, type_uid, v7, v8);
  return v3->mNumElements - 1;
}

// File Line: 258
// RVA: 0x1EA580
bool *__fastcall UFG::qPropertyList::Get<bool>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v4; // rbx
  char *v5; // rcx
  bool *result; // rax

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 9 )
    return 0i64;
  if ( index >= this->mNumElements )
    return 0i64;
  v4 = UFG::qPropertyType::Get(9u);
  v5 = &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                               * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))];
  if ( !v5 )
    return 0i64;
  result = &qPropertyList_False;
  if ( *v5 )
    result = &qPropertyList_True;
  return result;
}

// File Line: 264
// RVA: 0x1E9F80
UFG::qSymbol *__fastcall UFG::qPropertyList::Get<UFG::qSymbol>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 22 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x16u);
  return (UFG::qSymbol *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                 * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 265
// RVA: 0x1EA040
UFG::qSymbolUC *__fastcall UFG::qPropertyList::Get<UFG::qSymbolUC>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 23 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x17u);
  return (UFG::qSymbolUC *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                   * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 266
// RVA: 0x1EA340
UFG::qWiseSymbol *__fastcall UFG::qPropertyList::Get<UFG::qWiseSymbol>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 24 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x18u);
  return (UFG::qWiseSymbol *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                     * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 267
// RVA: 0x1E9580
char *__fastcall UFG::qPropertyList::Get<signed char>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 268
// RVA: 0x1E96F0
char *__fastcall UFG::qPropertyList::Get<short>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 1 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(1u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 269
// RVA: 0x1E9870
char *__fastcall UFG::qPropertyList::Get<long>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 2 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(2u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 270
// RVA: 0x1EA400
char *__fastcall UFG::qPropertyList::Get<__int64>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 3 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(3u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 271
// RVA: 0x1E9BC0
__m128 *__fastcall UFG::qPropertyList::Get<__m128>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 4 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(4u);
  return (__m128 *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                           * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 273
// RVA: 0x1E9630
char *__fastcall UFG::qPropertyList::Get<unsigned char>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 5 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(5u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 274
// RVA: 0x1E97B0
char *__fastcall UFG::qPropertyList::Get<unsigned short>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 6 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(6u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 275
// RVA: 0x1E9930
char *__fastcall UFG::qPropertyList::Get<unsigned long>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 7 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(7u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 276
// RVA: 0x1EA4C0
char *__fastcall UFG::qPropertyList::Get<unsigned __int64>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 8 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(8u);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                 * (~(v5->Alignment - 1) & (v5->Alignment
                                                                                          + v5->mByteSize
                                                                                          - 1))];
}

// File Line: 278
// RVA: 0x1E99F0
float *__fastcall UFG::qPropertyList::Get<float>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 10 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0xAu);
  return (float *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                          * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 279
// RVA: 0x1EA100
UFG::qVector2 *__fastcall UFG::qPropertyList::Get<UFG::qVector2>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 17 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x11u);
  return (UFG::qVector2 *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                  * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 280
// RVA: 0x1EA1C0
UFG::qVector3 *__fastcall UFG::qPropertyList::Get<UFG::qVector3>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 18 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x12u);
  return (UFG::qVector3 *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                  * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 281
// RVA: 0x1EA280
UFG::qVector4 *__fastcall UFG::qPropertyList::Get<UFG::qVector4>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 19 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x13u);
  return (UFG::qVector4 *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                  * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 282
// RVA: 0x1E9D20
UFG::qMatrix44 *__fastcall UFG::qPropertyList::Get<UFG::qMatrix44>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v5; // rbx

  v2 = index;
  v3 = this;
  if ( this->mTypeUID != 20 || index >= this->mNumElements )
    return 0i64;
  v5 = UFG::qPropertyType::Get(0x14u);
  return (UFG::qMatrix44 *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2
                                                                                   * (~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1))];
}

// File Line: 286
// RVA: 0x1E9AB0
const char *__fastcall UFG::qPropertyList::Get<char const *>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v4; // rbx
  UFG::qOffset64<char const *> *v5; // rcx
  const char *result; // rax

  v2 = index;
  v3 = this;
  if ( this->mTypeUID == 12
    && index < this->mNumElements
    && (v4 = UFG::qPropertyType::Get(0xCu),
        (v5 = (UFG::qOffset64<char const *> *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2 * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))]) != 0i64) )
  {
    result = UFG::qOffset64<char const *>::Get(v5, 0i64);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 298
// RVA: 0x1F8E90
char __fastcall UFG::qPropertyList::GetVariant(UFG::qPropertyList *this, unsigned int index, qPropertySetVariant *value)
{
  qPropertySetVariant *v3; // rbx
  char v4; // cl
  char result; // al
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
  float v18; // xmm0_4
  UFG::qVector3 *v19; // rax
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::qVector4 *v22; // rax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  UFG::qMatrix44 *v26; // rax
  UFG::qVector4 v27; // xmm3
  UFG::qVector4 v28; // xmm2
  UFG::qVector4 v29; // xmm1
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  UFG::qWiseSymbol *v32; // rax

  v3 = value;
  switch ( this->mTypeUID )
  {
    case 0u:
      v4 = *UFG::qPropertyList::Get<signed char>(this, index);
      v3->meType = 0;
      v3->mValueI8 = v4;
      goto $LN19_8;
    case 1u:
      v6 = *(_WORD *)UFG::qPropertyList::Get<short>(this, index);
      v3->meType = 1;
      result = 1;
      v3->mValueI16 = v6;
      break;
    case 2u:
      v7 = *(_DWORD *)UFG::qPropertyList::Get<long>(this, index);
      v3->meType = 2;
      result = 1;
      v3->mValueI32 = v7;
      break;
    case 3u:
      v8 = *(_QWORD *)UFG::qPropertyList::Get<__int64>(this, index);
      v3->meType = 3;
      result = 1;
      v3->mValueI64 = v8;
      break;
    case 4u:
      v9 = *($9C4F4E44B7DEC05B9F65CCD36F88E8FF *)UFG::qPropertyList::Get<__m128>(this, index);
      v3->meType = 4;
      result = 1;
      v3->16 = v9;
      break;
    case 5u:
      v10 = *UFG::qPropertyList::Get<unsigned char>(this, index);
      v3->meType = 5;
      result = 1;
      v3->mValueI8 = v10;
      break;
    case 6u:
      v11 = *(_WORD *)UFG::qPropertyList::Get<unsigned short>(this, index);
      v3->meType = 6;
      result = 1;
      v3->mValueI16 = v11;
      break;
    case 7u:
      v12 = *(_DWORD *)UFG::qPropertyList::Get<unsigned long>(this, index);
      v3->meType = 7;
      result = 1;
      v3->mValueI32 = v12;
      break;
    case 8u:
      v13 = *(_QWORD *)UFG::qPropertyList::Get<unsigned __int64>(this, index);
      v3->meType = 8;
      result = 1;
      v3->mValueI64 = v13;
      break;
    case 9u:
      v14 = *UFG::qPropertyList::Get<bool>(this, index);
      v3->meType = 9;
      result = 1;
      v3->mValueI8 = v14;
      break;
    case 0xAu:
      v15 = *(_DWORD *)UFG::qPropertyList::Get<float>(this, index);
      v3->meType = 10;
      result = 1;
      v3->mValueI32 = v15;
      break;
    case 0xBu:
$LN19_8:
      result = 1;
      break;
    case 0xCu:
      v16 = UFG::qPropertyList::Get<char const *>(this, index);
      UFG::qString::Set(&v3->mValueString, v16);
      v3->meType = 12;
      result = 1;
      break;
    case 0x11u:
      v17 = UFG::qPropertyList::Get<UFG::qVector2>(this, index);
      v18 = v17->y;
      v3->mValueVector2.x = v17->x;
      v3->mValueVector2.y = v18;
      v3->meType = 17;
      result = 1;
      break;
    case 0x12u:
      v19 = UFG::qPropertyList::Get<UFG::qVector3>(this, index);
      v20 = v19->y;
      v21 = v19->z;
      v3->mValueVector3.x = v19->x;
      result = 1;
      v3->mValueVector3.y = v20;
      v3->mValueVector3.z = v21;
      v3->meType = 18;
      break;
    case 0x13u:
      v22 = UFG::qPropertyList::Get<UFG::qVector4>(this, index);
      v23 = v22->x;
      v24 = v22->y;
      v25 = v22->z;
      result = 1;
      v3->mValueVector3.x = v23;
      v3->mValueVector3.y = v24;
      v3->mValueVector3.z = v25;
      v3->meType = 19;
      break;
    case 0x14u:
      v26 = UFG::qPropertyList::Get<UFG::qMatrix44>(this, index);
      v27 = v26->v1;
      v28 = v26->v2;
      v29 = v26->v3;
      v3->mValueMatrix44.v0 = v26->v0;
      v3->mValueMatrix44.v1 = v27;
      result = 1;
      v3->mValueMatrix44.v2 = v28;
      v3->mValueMatrix44.v3 = v29;
      v3->meType = 20;
      break;
    case 0x16u:
      v30 = UFG::qPropertyList::Get<UFG::qSymbol>(this, index)->mUID;
      result = 1;
      v3->mValueSymbol.mUID = v30;
      v3->meType = 22;
      break;
    case 0x17u:
      v31 = UFG::qPropertyList::Get<UFG::qSymbolUC>(this, index)->mUID;
      result = 1;
      v3->mValueSymbolUC.mUID = v31;
      v3->meType = 23;
      break;
    case 0x18u:
      v32 = UFG::qPropertyList::Get<UFG::qWiseSymbol>(this, index);
      UFG::qWiseSymbol::operator=(&v3->mValueWiseSymbol, v32);
      v3->meType = 24;
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
char __fastcall UFG::qPropertyList::SetVariant(UFG::qPropertyList *this, unsigned int index, qPropertySetVariant *value)
{
  char result; // al
  $9C4F4E44B7DEC05B9F65CCD36F88E8FF v4; // [rsp+20h] [rbp-18h]
  __int64 v; // [rsp+50h] [rbp+18h]

  switch ( value->meType )
  {
    case 0:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 0, index, &v);
      result = 1;
      break;
    case 1:
      LOWORD(v) = value->mValueI16;
      UFG::qPropertyList::SetInternal(this, 1u, index, &v);
      result = 1;
      break;
    case 2:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 2u, index, &v);
      result = 1;
      break;
    case 3:
      v = value->mValueI64;
      UFG::qPropertyList::SetInternal(this, 3u, index, &v);
      result = 1;
      break;
    case 4:
      v4 = value->16;
      UFG::qPropertyList::SetInternal(this, 4u, index, &v4);
      result = 1;
      break;
    case 5:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 5u, index, &v);
      result = 1;
      break;
    case 6:
      LOWORD(v) = value->mValueI16;
      UFG::qPropertyList::SetInternal(this, 6u, index, &v);
      result = 1;
      break;
    case 7:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 7u, index, &v);
      result = 1;
      break;
    case 8:
      v = value->mValueI64;
      UFG::qPropertyList::SetInternal(this, 8u, index, &v);
      result = 1;
      break;
    case 9:
      LOBYTE(v) = value->mValueI8;
      UFG::qPropertyList::SetInternal(this, 9u, index, &v);
      result = 1;
      break;
    case 0xA:
      LODWORD(v) = value->mValueI32;
      UFG::qPropertyList::SetInternal(this, 0xAu, index, &v);
      result = 1;
      break;
    case 0xB:
    case 0xC:
      UFG::qPropertyList::SetPtr<char const>(this, 0xCu, index, value->mValueString.mData);
      result = 1;
      break;
    case 0x11:
      UFG::qPropertyList::SetInternal(this, 0x11u, index, &value->mValueVector2);
      result = 1;
      break;
    case 0x12:
      UFG::qPropertyList::SetInternal(this, 0x12u, index, &value->mValueVector3);
      result = 1;
      break;
    case 0x13:
      UFG::qPropertyList::SetInternal(this, 0x13u, index, &value->mValueVector4);
      result = 1;
      break;
    case 0x16:
      UFG::qPropertyList::SetInternal(this, 0x16u, index, &value->mValueSymbol);
      result = 1;
      break;
    case 0x17:
      UFG::qPropertyList::SetInternal(this, 0x17u, index, &value->mValueSymbolUC);
      result = 1;
      break;
    case 0x18:
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
  UFG::qPropertyList *v2; // rsi
  UFG::qPropertyList *v3; // rbp
  char *v4; // rax
  unsigned int v5; // ebx
  char *v6; // rdi
  char *v7; // rax
  char *v8; // rdx
  char *v9; // rdi
  unsigned int *v10; // rbx
  unsigned int v11; // eax
  unsigned int v12; // edi
  UFG::qPropertyType *v13; // rbx
  UFG::qOffset64<unsigned char *> *v14; // rcx
  UFG::qSymbol *v15; // r8
  UFG::qPropertySet *v16; // ST20_8
  UFG::qOffset64<UFG::qPropertySet *> *v17; // rbx
  UFG::qPropertySet *v18; // rdi
  unsigned int v19; // ebp
  UFG::qPropertyType *v20; // rbx
  UFG::qPropertyList *v21; // rsi
  UFG::qOffset64<UFG::qPropertySet *> *v22; // rbx
  UFG::qPropertyList *v23; // rdi
  unsigned __int64 v24; // rbx
  UFG::qPropertyType *v25; // rdi
  const char *v26; // rax
  const char *v27; // rbp
  UFG::qOffset64<UFG::qPropertySet *> *v28; // rsi
  unsigned int v29; // edi
  void *v30; // rbx
  void *target; // [rsp+20h] [rbp-38h]
  UFG::qPropertyType *v32; // [rsp+28h] [rbp-30h]
  UFG::qPropertyType *v33; // [rsp+28h] [rbp-30h]
  UFG::qPropertyType *v34; // [rsp+28h] [rbp-30h]
  UFG::qPropertyList *owningList; // [rsp+60h] [rbp+8h]
  unsigned int owningLista; // [rsp+60h] [rbp+8h]
  UFG::qPropertyList *v37; // [rsp+68h] [rbp+10h]
  unsigned int v38; // [rsp+68h] [rbp+10h]
  unsigned int *source; // [rsp+70h] [rbp+18h]
  unsigned int sourcea; // [rsp+70h] [rbp+18h]
  unsigned int sourceb; // [rsp+70h] [rbp+18h]
  void *sourcec; // [rsp+70h] [rbp+18h]
  char *v43; // [rsp+78h] [rbp+20h]

  v37 = source_list;
  owningList = this;
  v2 = this;
  v3 = source_list;
  v4 = UFG::qOffset64<unsigned char *>::Get(&source_list->mValues, 0i64);
  v5 = v3->mNumElements * v3->mElementSize;
  v6 = v4;
  v7 = (char *)UFG::qPropertySet_Allocate(v5, "PropertyData", 0x1000u);
  v8 = v6;
  v43 = v7;
  v9 = v7;
  UFG::qMemCopy(v7, v8, v5);
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mValues, v9);
  v2->mNumElements = v3->mNumElements;
  v2->mElementSize = v3->mElementSize;
  v2->mTotalWeight = v3->mTotalWeight;
  v2->mTypeUID = v3->mTypeUID;
  source = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v3->mWeights);
  if ( source )
  {
    v10 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v2->mWeights);
    target = UFG::qPropertySet_Allocate(4 * v3->mNumElements, "PropertyWeights", 0);
    UFG::qMemCopy(target, source, 4 * v3->mNumElements);
    if ( v10 )
      UFG::qPropertySet_Free(v10);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mWeights, target);
  }
  v11 = v2->mTypeUID;
  switch ( v11 )
  {
    case 0x1Au:
      v32 = UFG::qPropertyType::Get(0x1Au);
      v12 = 0;
      v38 = 0;
      sourcea = v2->mNumElements;
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
          v16 = (UFG::qPropertySet *)v15;
          v17 = (UFG::qOffset64<UFG::qPropertySet *> *)&v43[v12
                                                          * (~(v32->Alignment - 1) & (v32->Alignment + v32->mByteSize - 1))];
          v18 = UFG::qPropertySet::CreateContainedSet(v15 + 16, "qPropertySet");
          UFG::qOffset64<unsigned long *>::operator=(v17, v18);
          UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v18->mFlags, owningList);
          UFG::qPropertySet::AddRef(v18);
          UFG::qPropertySet::CopyFrom(v18, v16, 1);
          v12 = v38 + 1;
          v38 = v12;
        }
        while ( v12 < sourcea );
      }
      break;
    case 0x19u:
      v19 = 0;
      v20 = UFG::qPropertyType::Get(0x19u);
      v33 = v20;
      sourceb = v2->mNumElements;
      if ( sourceb )
      {
        do
        {
          v21 = UFG::qPropertyList::Get<UFG::qPropertyList>(v37, v19);
          v22 = (UFG::qOffset64<UFG::qPropertySet *> *)&v9[v19
                                                         * (~(v20->Alignment - 1) & (v20->Alignment + v20->mByteSize - 1))];
          v23 = UFG::qPropertyList::Create("qPropertyList");
          UFG::qOffset64<unsigned long *>::operator=(v22, v23);
          UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v23->mFlags, owningList);
          UFG::qPropertyList::CopyFrom(v23, v21);
          v20 = v33;
          v9 = v43;
          ++v19;
        }
        while ( v19 < sourceb );
      }
      break;
    case 0xCu:
      LODWORD(v24) = 0;
      v25 = UFG::qPropertyType::Get(0xCu);
      v34 = v25;
      owningLista = v2->mNumElements;
      sourcec = 0i64;
      if ( owningLista )
      {
        do
        {
          v26 = UFG::qPropertyList::Get<char const *>(v3, v24);
          v27 = &customWorldMapCaption;
          if ( v26 )
            v27 = v26;
          v28 = (UFG::qOffset64<UFG::qPropertySet *> *)&v43[(unsigned int)v24
                                                          * (~(v25->Alignment - 1) & (v25->Alignment + v25->mByteSize - 1))];
          v29 = (unsigned __int64)UFG::qStringLength(v27) + 1;
          v30 = UFG::qPropertySet_Allocate(v29, "PropertyListString", 0);
          UFG::qOffset64<unsigned long *>::operator=(v28, v30);
          UFG::qMemCopy(v30, v27, v29);
          v3 = v37;
          v25 = v34;
          v24 = (unsigned int)((_DWORD)sourcec + 1);
          sourcec = (void *)v24;
        }
        while ( (unsigned int)v24 < owningLista );
      }
      break;
  }
}

// File Line: 506
// RVA: 0x1F8920
char *__fastcall UFG::qPropertyList::GetValuePtr(UFG::qPropertyList *this, unsigned int type_uid, unsigned int index)
{
  UFG::qPropertyList *v3; // rdi
  unsigned int v4; // ecx
  unsigned int v5; // esi
  UFG::qPropertyType *v7; // rbx

  v3 = this;
  v4 = this->mTypeUID;
  v5 = index;
  if ( type_uid != v4 || index >= v3->mNumElements )
    return 0i64;
  v7 = UFG::qPropertyType::Get(v4);
  return &UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v5
                                                                 * (~(v7->Alignment - 1) & (v7->Alignment
                                                                                          + v7->mByteSize
                                                                                          - 1))];
}

// File Line: 532
// RVA: 0x1FB050
void __fastcall UFG::RecalcPropertyListPtrOffsets(void *old_data, void *new_data, unsigned int element_count, UFG::qPropertyType *type)
{
  char *v4; // rbp
  UFG::qPropertyType *v5; // rdi
  unsigned int v6; // esi
  char *v7; // rbx
  int v8; // er9
  __int64 v9; // rdx
  __int64 v10; // r8
  __int64 v11; // rax

  v4 = (char *)old_data;
  v5 = type;
  v6 = element_count;
  v7 = (char *)new_data;
  if ( (unsigned __int8)UFG::qPropertyType::IsPtrType(type->mNameUID) )
  {
    v8 = ~(v5->Alignment - 1) & (v5->Alignment + v5->mByteSize - 1);
    if ( v6 )
    {
      v9 = 0i64;
      v10 = v6;
      do
      {
        v11 = *(_QWORD *)&v7[v9];
        if ( v11 )
          *(_QWORD *)&v7[v9] = &v4[v11 - (_QWORD)v7];
        v9 = (unsigned int)(v8 + v9);
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 553
// RVA: 0x1FD420
UFG::qPropertyType *__fastcall UFG::qPropertyList::SetInternal(UFG::qPropertyList *this, unsigned int type_uid, unsigned int index, const void *v)
{
  const void *v4; // rbp
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::qPropertyList *v7; // rsi
  UFG::qPropertyType *result; // rax
  UFG::qPropertyType *v9; // r14
  unsigned int v10; // er13
  UFG::qOffset64<unsigned long *> *v11; // rcx
  unsigned int v12; // er14
  unsigned int *v13; // rax
  UFG::qPropertyType *v14; // rbx
  unsigned int v15; // edi
  unsigned int v16; // er13
  unsigned int *v17; // rdi
  void *v18; // rbx
  char *v19; // rcx
  char *target; // [rsp+20h] [rbp-38h]
  unsigned int *old_data; // [rsp+28h] [rbp-30h]
  unsigned int v22; // [rsp+68h] [rbp+10h]

  v4 = v;
  v5 = index;
  v6 = type_uid;
  v7 = this;
  if ( type_uid == 29 || index > this->mNumElements )
    return 0i64;
  result = UFG::qPropertyType::Get(type_uid);
  v9 = result;
  if ( result )
  {
    if ( v7->mTypeUID == 29 )
    {
      v7->mTypeUID = v6;
      v7->mElementSize = result->mByteSize;
    }
    v10 = v7->mNumElements;
    v11 = (UFG::qOffset64<unsigned long *> *)&v7->mValues;
    if ( v5 >= v10 )
    {
      v15 = v7->mElementSize;
      v22 = v15;
      v16 = v15 * v10;
      old_data = UFG::qOffset64<unsigned long *>::operator unsigned long *(v11);
      target = (char *)UFG::qPropertySet_Allocate(v15 + v16, "PropertyData", 0x1000u);
      UFG::qMemCopy(target, old_data, v16);
      UFG::qMemSet(&target[v16], 0, v15);
      UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v7->mValues, target);
      if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&v7->mWeights) )
      {
        v17 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v7->mWeights);
        v18 = UFG::qPropertySet_Allocate(4 * v7->mNumElements + 4, "PropertyWeights", 0);
        UFG::qMemCopy(v18, v17, 4 * v7->mNumElements);
        *((_DWORD *)v18 + v7->mNumElements) = 0;
        UFG::qPropertySet_Free(v17);
        UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v7->mWeights, v18);
        v15 = v22;
      }
      UFG::RecalcPropertyListPtrOffsets(old_data, target, ++v7->mNumElements, v9);
      UFG::qPropertySet_Free(old_data);
      v19 = (char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&v7->mValues)
          + v16;
      if ( v4 )
        UFG::qMemCopy(v19, v4, v15);
      else
        UFG::qMemSet(v19, 0, v15);
      result = (UFG::qPropertyType *)((char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&v7->mValues)
                                    + v16);
    }
    else
    {
      v12 = v7->mElementSize;
      v13 = UFG::qOffset64<unsigned long *>::operator unsigned long *(v11);
      v14 = (UFG::qPropertyType *)((char *)v13 + v5 * v12);
      if ( v4 )
        UFG::qMemCopy((char *)v13 + v5 * v12, v4, v12);
      result = v14;
    }
  }
  return result;
}

// File Line: 659
// RVA: 0x1EB490
void __fastcall UFG::qPropertyList::SetPtr<UFG::qPropertyList>(UFG::qPropertyList *this, unsigned int property_type_uid, unsigned int index, UFG::qPropertyList *property_set_data)
{
  char *v4; // [rsp+20h] [rbp-38h]
  UFG::qPropertyList *v5; // [rsp+30h] [rbp-28h]
  signed __int64 v6; // [rsp+38h] [rbp-20h]
  signed __int64 v7; // [rsp+40h] [rbp-18h]
  UFG::qPropertyList *owningList; // [rsp+60h] [rbp+8h]
  AMD_HD3D *v9; // [rsp+78h] [rbp+20h]

  v9 = (AMD_HD3D *)property_set_data;
  owningList = this;
  v4 = (char *)UFG::qPropertyList::SetInternal(this, property_type_uid, index, 0i64);
  if ( *(_QWORD *)v4 )
    v5 = (UFG::qPropertyList *)&v4[*(_QWORD *)v4];
  else
    v5 = 0i64;
  if ( v5 )
  {
    if ( v5 != (UFG::qPropertyList *)v9 )
    {
      UFG::qPropertyList::ReleaseRef(v5);
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)&v5->mFlags, 0i64);
      if ( v9 )
        v6 = (char *)v9 - v4;
      else
        v6 = 0i64;
      *(_QWORD *)v4 = v6;
      _(v9);
      UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)v9, owningList);
    }
  }
  else
  {
    if ( v9 )
      v7 = (char *)v9 - v4;
    else
      v7 = 0i64;
    *(_QWORD *)v4 = v7;
    _(v9);
    UFG::qPropertyCollection::SetOwner((UFG::qPropertyCollection *)v9, owningList);
  }
}

// File Line: 705
// RVA: 0x1FEC10
void __fastcall UFG::qPropertyList::SetWeight(UFG::qPropertyList *this, unsigned int index, unsigned int w)
{
  UFG::qPropertyList *v3; // rbx
  unsigned int v4; // esi
  __int64 v5; // r14
  unsigned int *v6; // rdi

  v3 = this;
  v4 = w;
  v5 = index;
  v6 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
  if ( !v6 )
  {
    v6 = (unsigned int *)UFG::qPropertySet_Allocate(4 * v3->mNumElements, "PropertyWeights", 0);
    UFG::qMemSet(v6, 0, 4 * v3->mNumElements);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v3->mWeights, v6);
  }
  v3->mTotalWeight -= v6[v5];
  v6[v5] = v4;
  v3->mTotalWeight += v4;
}

// File Line: 719
// RVA: 0x1F8010
__int64 __fastcall UFG::qPropertyList::GetRandomIndex(UFG::qPropertyList *this)
{
  int v1; // esi
  UFG::qPropertyList *v2; // rdi
  unsigned int *v3; // rbx
  unsigned int v4; // edi
  int v5; // ecx
  __int64 result; // rax

  v1 = this->mTotalWeight;
  v2 = this;
  v3 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&this->mWeights);
  if ( !v3 )
    return UFG::qRandom(v2->mNumElements, &UFG::qDefaultSeed);
  v4 = v2->mNumElements;
  v5 = UFG::qRandom(v1, &UFG::qDefaultSeed);
  result = 0i64;
  if ( !v4 )
    return 0i64;
  while ( 1 )
  {
    v5 -= *v3;
    if ( v5 < 0 )
      break;
    result = (unsigned int)(result + 1);
    ++v3;
    if ( (unsigned int)result >= v4 )
      return 0i64;
  }
  return result;
}

// File Line: 753
// RVA: 0x1E94D0
signed __int64 __fastcall UFG::qPropertyList::FindElement<UFG::qPropertySet>(UFG::qPropertyList *this, UFG::qPropertySet *v)
{
  unsigned int v2; // ebp
  unsigned int v3; // ebx
  UFG::qPropertySet *v4; // r14
  UFG::qPropertyList *v5; // rsi
  UFG::qPropertyType *v6; // rdi
  UFG::qOffset64<unsigned char *> *v7; // rcx
  char *v8; // rax

  v2 = this->mNumElements;
  v3 = 0;
  v4 = v;
  v5 = this;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  while ( 1 )
  {
    if ( v5->mTypeUID == 26
      && v3 < v5->mNumElements
      && (v6 = UFG::qPropertyType::Get(0x1Au),
          (v7 = (UFG::qOffset64<unsigned char *> *)&UFG::qOffset64<unsigned char *>::Get(&v5->mValues, 0i64)[v3 * ((v6->mByteSize + v6->Alignment - 1) & ~(v6->Alignment - 1))]) != 0i64) )
    {
      v8 = UFG::qOffset64<unsigned char *>::Get(v7, 0i64);
    }
    else
    {
      v8 = 0i64;
    }
    if ( v8 == (char *)v4 )
      break;
    if ( ++v3 >= v2 )
      return 0xFFFFFFFFi64;
  }
  return v3;
}

// File Line: 768
// RVA: 0x1F5680
void __fastcall UFG::qPropertyList::FreePropertyPtrData(UFG::qPropertyList *this, char *values, unsigned int element_index, UFG::qPropertyType *_property_type)
{
  unsigned int v4; // eax
  UFG::qPropertyCollection *v5; // rax
  UFG::qPropertySet *v6; // rbx
  UFG::qPropertyCollection *v7; // rax
  UFG::qPropertyList *v8; // rbx
  UFG::qOffset64<char const *> *v9; // rbx
  char *v10; // rax

  v4 = _property_type->mNameUID;
  switch ( v4 )
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
  UFG::qPropertyList *v2; // r13
  __int64 v3; // r12
  unsigned int v4; // er14
  int v5; // ebp
  char *v6; // rsi
  char *v7; // r15
  unsigned int v8; // ebx
  unsigned int *v9; // rsi
  char *v10; // rdi
  unsigned int v11; // er8
  unsigned int v12; // er9
  __int64 v13; // r10
  __int64 v14; // rax
  char *v15; // [rsp+60h] [rbp+8h]
  UFG::qPropertyType *v16; // [rsp+70h] [rbp+18h]

  v2 = this;
  v3 = index;
  v16 = UFG::qPropertyType::Get(this->mTypeUID);
  v4 = v2->mNumElements - 1;
  v5 = ~(v16->Alignment - 1) & (v16->Alignment + v16->mByteSize - 1);
  v6 = (char *)UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&v2->mValues);
  v15 = v6;
  v7 = (char *)UFG::qPropertySet_Allocate(v4 * v5, "PropertyListData", 0x1000u);
  UFG::qPropertyList::FreePropertyPtrData(v2, v6, v3, v16);
  v8 = v5 * (v2->mNumElements - v3 - 1);
  UFG::qMemCopy(v7, v6, v3 * v5);
  UFG::qMemCopy(&v7[(signed int)v3 * v5], &v6[(signed int)v3 * v5 + v5], v8);
  if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&v2->mWeights) )
  {
    v9 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v2->mWeights);
    v10 = (char *)UFG::qPropertySet_Allocate(4 * v4, "PropertyListWeights", 0);
    UFG::qMemCopy(v10, v9, 4 * v3);
    UFG::qMemCopy(&v10[4 * v3], v9, 4 * (v2->mNumElements - v3) - 4);
    v2->mTotalWeight -= v9[v3];
    UFG::qPropertySet_Free(v9);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mWeights, v10);
    v6 = v15;
  }
  if ( (unsigned __int8)UFG::qPropertyType::IsPtrType(v16->mNameUID) )
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
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v2->mValues, v7);
  UFG::qPropertySet_Free(v6);
  v2->mNumElements = v4;
  if ( !v4 )
    v2->mTypeUID = 29;
}

// File Line: 883
// RVA: 0x1FB810
void __fastcall UFG::qPropertyList::RemoveAll(UFG::qPropertyList *this)
{
  UFG::qPropertyList *v1; // rbp
  unsigned int *v2; // r14
  UFG::qPropertyType *v3; // rdi
  unsigned int i; // ebx
  unsigned int v5; // eax
  UFG::qPropertyCollection *v6; // rax
  UFG::qPropertySet *v7; // rsi
  UFG::qPropertyCollection *v8; // rax
  UFG::qPropertyList *v9; // rsi
  _QWORD *v10; // rsi
  char *v11; // rax
  unsigned int *v12; // rax

  v1 = this;
  v2 = UFG::qOffset64<unsigned long *>::operator unsigned long *((UFG::qOffset64<unsigned long *> *)&this->mValues);
  v3 = UFG::qPropertyType::Get(v1->mTypeUID);
  if ( (unsigned __int8)UFG::qPropertyType::IsPtrType(v1->mTypeUID) )
  {
    for ( i = 0; i < v1->mNumElements; ++i )
    {
      v5 = v3->mNameUID;
      switch ( v5 )
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
          v10 = (_QWORD *)((char *)v2 + i * (~(v3->Alignment - 1) & (v3->Alignment + v3->mByteSize - 1)));
          v11 = (char *)UFG::qOffset64<char const *>::Get(
                          (UFG::qOffset64<char const *> *)((char *)v2
                                                         + i
                                                         * (~(v3->Alignment - 1) & (v3->Alignment + v3->mByteSize - 1))),
                          0i64);
          if ( v11 )
          {
            UFG::qPropertySet_Free(v11);
            *v10 = 0i64;
          }
          break;
      }
    }
  }
  UFG::qPropertySet_Free(v2);
  UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v1->mValues, 0i64);
  v1->mNumElements = 0;
  if ( UFG::qOffset64<unsigned long *>::operator unsigned long *(&v1->mWeights) )
  {
    v12 = UFG::qOffset64<unsigned long *>::operator unsigned long *(&v1->mWeights);
    UFG::qPropertySet_Free(v12);
    UFG::qOffset64<unsigned long *>::operator=((UFG::qOffset64<UFG::qPropertySet *> *)&v1->mWeights, 0i64);
  }
  v1->mTypeUID = 29;
}

