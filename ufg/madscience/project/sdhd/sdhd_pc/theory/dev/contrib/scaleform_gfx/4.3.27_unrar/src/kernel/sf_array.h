// File Line: 62
// RVA: 0x14FAAE0
__int64 dynamic_initializer_for__TracksEnum_unsigned_long_::mDataPath__()
{
  UFG::qString::qString(&TracksEnum<unsigned long>::mDataPath);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__TracksEnum_unsigned_long_::mDataPath__);
}

// File Line: 92
// RVA: 0x7863D0
void __fastcall Scaleform::ArrayDataBase<long const *,Scaleform::AllocatorDH<long const *,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<long const *,Scaleform::AllocatorDH<long const *,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}

// File Line: 103
// RVA: 0x9601A0
void __fastcall Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease(
        Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned __int64 Size; // rdi
  Scaleform::Render::TextMeshLayer *i; // rbx

  Size = this->Size;
  for ( i = &this->Data[Size - 1]; Size; --Size )
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(i--);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
  this->Data = 0i64;
  this->Size = 0i64;
  this->Policy.Capacity = 0i64;
}

// File Line: 112
// RVA: 0x812C50
void __fastcall Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned __int64 newCapacity)
{
  unsigned int *Data; // rdx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  unsigned int *v8; // rax
  int v9; // [rsp+48h] [rbp+20h] BYREF

  Data = this->Data;
  if ( newCapacity )
  {
    v6 = (newCapacity + 3) & 0xFFFFFFFFFFFFFFFCui64;
    v7 = 4 * v6;
    if ( Data )
    {
      v8 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, Data, v7);
      this->Policy.Capacity = v6;
      this->Data = v8;
      return;
    }
    v9 = 339;
    this->Data = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   pheapAddr,
                                   v7,
                                   &v9);
  }
  else
  {
    v6 = 0i64;
    if ( Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Data = 0i64;
      this->Policy.Capacity = 0i64;
      return;
    }
  }
  this->Policy.Capacity = v6;
}

// File Line: 174
// RVA: 0x903640
void __fastcall Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned __int64 newSize)
{
  unsigned __int64 Size; // rdi
  __int64 v7; // rdi
  Scaleform::GFx::DisplayList::DisplayEntry *i; // rbx

  Size = this->Size;
  if ( newSize >= Size )
  {
    if ( newSize <= this->Policy.Capacity )
    {
      this->Size = newSize;
    }
    else
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize + (newSize >> 2));
      this->Size = newSize;
    }
  }
  else
  {
    v7 = Size - newSize;
    for ( i = &this->Data[v7 - 1 + newSize]; v7; --v7 )
    {
      if ( i->pCharacter )
        Scaleform::RefCountNTSImpl::Release(i->pCharacter);
      --i;
    }
    if ( newSize < this->Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pheapAddr,
        newSize);
    this->Size = newSize;
  }
}

// File Line: 223
// RVA: 0x6C5600
void __fastcall Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *a)
{
  unsigned __int64 Size; // rsi
  Scaleform::GFx::AS2::ArraySortFunctor *Data; // rbp
  unsigned __int64 v5; // rbx

  this->Data = 0i64;
  this->Size = 0i64;
  this->Policy.Capacity = 0i64;
  Size = a->Size;
  Data = a->Data;
  if ( Size )
  {
    v5 = this->Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      this,
      this,
      v5 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(&this->Data[v5], Size, Data);
  }
}

// File Line: 232
// RVA: 0x814130
void __fastcall Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned __int64 newSize)
{
  if ( newSize >= this->Size )
  {
    if ( newSize > this->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        this,
        newSize + (newSize >> 2));
      this->Size = newSize;
      return;
    }
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      this,
      newSize);
    this->Size = newSize;
    return;
  }
  this->Size = newSize;
}

// File Line: 240
// RVA: 0x9A2000
void __fastcall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        Scaleform::Render::Matrix3x4<float> *val)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r8
  float *v6; // rdx

  v4 = this->Size + 1;
  if ( v4 >= this->Size )
  {
    if ( v4 <= this->Policy.Capacity )
      goto LABEL_7;
    v5 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= this->Policy.Capacity >> 1 )
      goto LABEL_7;
    v5 = this->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
    this,
    this,
    v5);
LABEL_7:
  this->Size = v4;
  v6 = (float *)&this->Data[v4 - 1];
  if ( v6 )
  {
    *v6 = val->M[0][0];
    v6[1] = val->M[0][1];
    v6[2] = val->M[0][2];
    v6[3] = val->M[0][3];
    v6[4] = val->M[1][0];
    v6[5] = val->M[1][1];
    v6[6] = val->M[1][2];
    v6[7] = val->M[1][3];
    v6[8] = val->M[2][0];
    v6[9] = val->M[2][1];
    v6[10] = val->M[2][2];
    v6[11] = val->M[2][3];
  }
}

// File Line: 254
// RVA: 0x958820
void __fastcall Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Append(
        Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *this,
        Scaleform::Waitable::HandlerStruct *other,
        unsigned __int64 count)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 Size; // rdi
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r8
  Scaleform::Waitable::HandlerStruct *v9; // rdi

  if ( !count )
    return;
  v3 = count;
  Size = this->Size;
  v7 = Size + count;
  if ( Size + count >= Size )
  {
    if ( v7 <= this->Policy.Capacity )
      goto LABEL_8;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= this->Policy.Capacity >> 1 )
      goto LABEL_8;
    v8 = Size + count;
  }
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
    this,
    this,
    v8);
LABEL_8:
  this->Size = v7;
  v9 = &this->Data[Size];
  do
  {
    if ( v9 )
    {
      v9->Handler = other->Handler;
      v9->pUserData = other->pUserData;
    }
    ++other;
    ++v9;
    --v3;
  }
  while ( v3 );
}

// File Line: 288
// RVA: 0x893C10
void __fastcall Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::MemoryHeap *pHeap; // rax
  unsigned __int64 Size; // rsi
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *Data; // rbp
  unsigned __int64 v6; // rbx

  this->Data = 0i64;
  this->Size = 0i64;
  this->Policy.Capacity = 0i64;
  pHeap = a->pHeap;
  this->pHeap = pHeap;
  Size = a->Size;
  Data = a->Data;
  if ( Size )
  {
    v6 = this->Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      this,
      pHeap,
      v6 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::ConstructArray(&this->Data[v6], Size, Data);
  }
}

// File Line: 296
// RVA: 0x814320
void __fastcall Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned __int64 newSize)
{
  __int64 *pHeap; // rdx

  pHeap = (__int64 *)this->pHeap;
  if ( newSize >= this->Size )
  {
    if ( newSize > this->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        this,
        pHeap,
        newSize + (newSize >> 2));
      this->Size = newSize;
      return;
    }
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      this,
      pHeap,
      newSize);
    this->Size = newSize;
    return;
  }
  this->Size = newSize;
}

// File Line: 304
// RVA: 0x80A890
void __fastcall Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *val)
{
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *v4; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax

  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this->pHeap,
    this->Size + 1);
  v4 = &this->Data[this->Size - 1];
  if ( v4 )
  {
    pNode = val->First.pNode;
    v4->First.pNode = val->First.pNode;
    ++pNode->RefCount;
    v4->Second = val->Second;
    v4->Third = val->Third;
  }
}

// File Line: 362
// RVA: 0x711220
void __fastcall Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(
        Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *this,
        unsigned __int64 newSize)
{
  unsigned __int64 Size; // rsi
  Scaleform::GFx::ASString *v5; // r8
  __int64 i; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax

  Size = this->Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    this,
    this,
    newSize);
  if ( newSize > Size )
  {
    v5 = &this->Data[Size];
    for ( i = newSize - Size; i; --i )
    {
      if ( v5 )
      {
        pNode = this->DefaultValue.pNode;
        v5->pNode = pNode;
        ++pNode->RefCount;
      }
      ++v5;
    }
  }
}

// File Line: 426
// RVA: 0x6D2C40
void __fastcall Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,325>::operator delete(void *p)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p);
}

// File Line: 455
// RVA: 0x8BB680
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *this)
{
  Scaleform::GFx::ExecuteTag **v2; // rax
  int v3; // [rsp+30h] [rbp+8h] BYREF

  if ( this->Data.Size && (this->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Data.Data )
    {
      v2 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            this->Data.Data,
                                            256i64);
    }
    else
    {
      v3 = 2;
      v2 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            256i64,
                                            &v3);
    }
    this->Data.Data = v2;
    this->Data.Policy.Capacity = 32i64;
    this->Data.Size = 0i64;
  }
  else
  {
    this->Data.Size = 0i64;
  }
}

// File Line: 501
// RVA: 0x80A730
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int64 *val)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v4; // rdi
  unsigned __int64 v6; // r8
  unsigned __int64 *Data; // rcx

  Size = this->Data.Size;
  v4 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v4 > this->Data.Policy.Capacity )
    {
      v6 = v4 + (v4 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    v6 = Size + 1;
LABEL_6:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &this->Data,
      this->Data.pHeap,
      v6);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  Data[v4 - 1] = *val;
}

// File Line: 523
// RVA: 0x80AED0
Scaleform::GFx::AS3::Abc::MetadataInfo::Item *__fastcall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>>::PushDefault(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> > *this)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *Data; // rcx
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v6; // rcx

  Size = this->Data.Size;
  v3 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v3 <= this->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= this->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)this,
    this,
    v4);
LABEL_7:
  Data = this->Data.Data;
  this->Data.Size = v3;
  v6 = &Data[v3 - 1];
  if ( v6 )
    *v6 = 0i64;
  return &this->Data.Data[this->Data.Size - 1];
}

// File Line: 529
// RVA: 0x8F08F0
Scaleform::Ptr<Scaleform::GFx::ASStringNode> *__fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::Pop(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::Ptr<Scaleform::GFx::ASStringNode> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v3; // rdx
  Scaleform::GFx::ASStringNode *pObject; // rax

  v3 = &this->Data.Data[this->Data.Size];
  pObject = v3[-1].pObject;
  if ( pObject )
    ++pObject->RefCount;
  result->pObject = v3[-1].pObject;
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size - 1);
  return result;
}

// File Line: 546
// RVA: 0x6D2C60
Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *__fastcall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *a)
{
  __int64 v2; // rdi
  __int64 v3; // r12
  __int64 v4; // r13
  __int64 v5; // r14
  __int64 v6; // r15
  unsigned __int64 v9; // rbp
  __int64 v10; // rbx
  Scaleform::GFx::AS2::Value *Data; // rsi
  Scaleform::GFx::AS2::Value *v12; // rdi
  Scaleform::GFx::ASStringNode *pStringNode; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::ASStringNode *v16; // r8
  Scaleform::GFx::AS2::LocalFrame *v17; // rdx
  char v18; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // rcx
  unsigned int v22; // eax
  Scaleform::GFx::ASStringNode *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v28; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // [rsp+30h] [rbp-38h]
  char v30; // [rsp+38h] [rbp-30h]
  __int64 v31; // [rsp+40h] [rbp-28h]
  __int64 v32; // [rsp+48h] [rbp-20h]
  __int64 v33; // [rsp+50h] [rbp-18h]
  __int64 v34; // [rsp+58h] [rbp-10h]
  __int64 v35; // [rsp+60h] [rbp-8h]

  v35 = v2;
  v34 = v3;
  v33 = v4;
  v32 = v5;
  v31 = v6;
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    a->Data.Size);
  v9 = 0i64;
  if ( this->Data.Size )
  {
    v10 = 0i64;
    do
    {
      Data = a->Data.Data;
      v12 = &this->Data.Data[v10];
      if ( v12->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&this->Data.Data[v10]);
      v12->T.Type = Data[v10].T.Type;
      switch ( Data[v10].T.Type )
      {
        case 2:
          v12->V.BooleanValue = Data[v10].V.BooleanValue;
          break;
        case 3:
          v12->V.pStringNode = Data[v10].V.pStringNode;
          break;
        case 4:
          v12->NV.Int32Value = Data[v10].NV.Int32Value;
          break;
        case 5:
        case 0xB:
          pStringNode = Data[v10].V.pStringNode;
          v12->V.pStringNode = pStringNode;
          ++pStringNode->RefCount;
          break;
        case 6:
          v14 = Data[v10].V.pStringNode;
          if ( v14 )
          {
            if ( (*(unsigned int (__fastcall **)(unsigned int *))(*(_QWORD *)&v14->Size + 16i64))(&v14->Size) != 23 )
              goto LABEL_32;
            v12->T.Type = 8;
            v15 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&Data[v10].V.pStringNode->Size + 96i64))(
                    &Data[v10].V.pStringNode->Size,
                    &v28);
            v12->V.FunctionValue.Flags = 0;
            v16 = *(Scaleform::GFx::ASStringNode **)v15;
            v12->V.pStringNode = *(Scaleform::GFx::ASStringNode **)v15;
            if ( v16 )
              v16->RefCount = (v16->RefCount + 1) & 0x8FFFFFFF;
            v12->V.FunctionValue.pLocalFrame = 0i64;
            v17 = *(Scaleform::GFx::AS2::LocalFrame **)(v15 + 8);
            if ( v17 )
              Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v12->V.FunctionValue, v17, *(_BYTE *)(v15 + 16) & 1);
            v18 = v30;
            if ( (v30 & 2) == 0 )
            {
              v19 = v28;
              if ( v28 )
              {
                RefCount = v28->RefCount;
                if ( (RefCount & 0x3FFFFFF) != 0 )
                {
                  v28->RefCount = RefCount - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v19);
                  v18 = v30;
                }
              }
            }
            v28 = 0i64;
            if ( (v18 & 1) == 0 )
            {
              v21 = v29;
              if ( v29 )
              {
                v22 = v29->RefCount;
                if ( (v22 & 0x3FFFFFF) != 0 )
                {
                  v29->RefCount = v22 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v21);
                }
              }
            }
            v29 = 0i64;
          }
          else
          {
            v12->V.pStringNode = 0i64;
          }
          break;
        case 7:
          v23 = Data[v10].V.pStringNode;
          v12->V.pStringNode = v23;
          if ( v23 )
            ++LODWORD(v23->pData);
          break;
        case 8:
        case 0xC:
          v12->V.FunctionValue.Flags = 0;
          v24 = Data[v10].V.pStringNode;
          v12->V.pStringNode = v24;
          if ( v24 )
            v24->RefCount = (v24->RefCount + 1) & 0x8FFFFFFF;
          v12->V.FunctionValue.pLocalFrame = 0i64;
          pLocalFrame = Data[v10].V.FunctionValue.pLocalFrame;
          if ( pLocalFrame )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
              &v12->V.FunctionValue,
              pLocalFrame,
              Data[v10].V.FunctionValue.Flags & 1);
          break;
        case 9:
LABEL_32:
          v26 = Data[v10].V.pStringNode;
          v12->V.pStringNode = v26;
          v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
          break;
        default:
          break;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < this->Data.Size );
  }
  return this;
}

// File Line: 556
// RVA: 0x811F00
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int64 index,
        unsigned __int64 num)
{
  unsigned __int64 v6; // rbx

  if ( this->Data.Size == num )
  {
    Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->Data,
      0i64);
  }
  else
  {
    v6 = index;
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(&this->Data.Data[index], num);
    memmove(&this->Data.Data[v6], &this->Data.Data[index + num], 32 * (this->Data.Size - index - num));
    this->Data.Size -= num;
  }
}

// File Line: 576
// RVA: 0x8FEDA0
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int64 index)
{
  unsigned __int64 Size; // r8

  Size = this->Data.Size;
  if ( Size == 1 )
  {
    if ( (this->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( this->Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        this->Data.Data = 0i64;
      }
      this->Data.Policy.Capacity = 0i64;
    }
    this->Data.Size = 0i64;
  }
  else
  {
    memmove(&this->Data.Data[index], &this->Data.Data[index + 1], 8 * (Size - index) - 8);
    --this->Data.Size;
  }
}

// File Line: 595
// RVA: 0x7F5E40
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int64 index,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned __int64 Size; // r8

  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size + 1);
  Size = this->Data.Size;
  if ( index < Size - 1 )
    memmove(&this->Data.Data[index + 1], &this->Data.Data[index], 32 * (Size - index - 1));
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&this->Data.Data[index].Flags, val);
}

// File Line: 611
// RVA: 0x8E6990
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned __int64 index,
        unsigned __int64 num,
        Scaleform::GFx::AS3::Value *val)
{
  unsigned __int64 v5; // rsi
  unsigned __int64 v8; // rdi
  Scaleform::GFx::AS3::Value *v9; // rcx

  v5 = num;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    num + this->Data.Size);
  if ( index < this->Data.Size - v5 )
    memmove(&this->Data.Data[index + v5], &this->Data.Data[index], 32 * (this->Data.Size - index - v5));
  if ( v5 )
  {
    v8 = index;
    do
    {
      v9 = &this->Data.Data[v8];
      if ( v9 )
      {
        v9->Flags = val->Flags;
        v9->Bonus.pWeakProxy = val->Bonus.pWeakProxy;
        v9->value.VS._1.VStr = val->value.VS._1.VStr;
        v9->value.VS._2.VObj = val->value.VS._2.VObj;
        if ( (val->Flags & 0x1F) > 9 )
        {
          if ( (val->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(val);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(val);
        }
      }
      ++v8;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 801
// RVA: 0x893BE0
void __fastcall Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>(
        Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *this)
{
  this->Data.Data = 0i64;
  this->Data.Size = 0i64;
  this->Data.Policy.Capacity = 0i64;
}

// File Line: 899
// RVA: 0x94DBB0
Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>::operator=(
        Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *a)
{
  unsigned __int64 i; // rax

  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
    a->Data.Size);
  for ( i = 0i64; i < this->Data.Size; this->Data.Data[i - 1] = a->Data.Data[i - 1] )
    ++i;
  return this;
}

// File Line: 921
// RVA: 0x790290
Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *this,
        Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *a)
{
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx

  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    a->Data.Size);
  v4 = 0i64;
  if ( this->Data.Size )
  {
    v5 = 0i64;
    do
    {
      Scaleform::GFx::AS3::Value::Assign(&this->Data.Data[v5], &a->Data.Data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < this->Data.Size );
  }
  return this;
}

