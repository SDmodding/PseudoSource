// File Line: 62
// RVA: 0x14FAAE0
__int64 dynamic_initializer_for__TracksEnum_unsigned_long_::mDataPath__()
{
  UFG::qString::qString(&TracksEnum<unsigned long>::mDataPath);
  return atexit(dynamic_atexit_destructor_for__TracksEnum_unsigned_long_::mDataPath__);
}

// File Line: 92
// RVA: 0x7863D0
void __fastcall Scaleform::ArrayDataBase<long const *,Scaleform::AllocatorDH<long const *,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<long const *,Scaleform::AllocatorDH<long const *,2>,Scaleform::ArrayDefaultPolicy>(Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}

// File Line: 103
// RVA: 0x9601A0
void __fastcall Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy>::ClearAndRelease(Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::ArrayDataBase<Scaleform::Render::TextMeshLayer,Scaleform::AllocatorDH<Scaleform::Render::TextMeshLayer,2>,Scaleform::ArrayDefaultPolicy> *v2; // rsi
  Scaleform::Render::TextMeshLayer *i; // rbx

  v1 = this->Size;
  v2 = this;
  for ( i = &this->Data[this->Size - 1]; v1; --v1 )
  {
    Scaleform::Render::TextMeshLayer::~TextMeshLayer(i);
    --i;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2->Data);
  v2->Data = 0i64;
  v2->Size = 0i64;
  v2->Policy.Capacity = 0i64;
}

// File Line: 112
// RVA: 0x812C50
void __fastcall Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *this, const void *pheapAddr, unsigned __int64 newCapacity)
{
  const void *v3; // r10
  unsigned int *v4; // rdx
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  unsigned int *v8; // rax
  int v9; // [rsp+48h] [rbp+20h]

  v3 = pheapAddr;
  v4 = this->Data;
  v5 = this;
  if ( newCapacity )
  {
    v6 = (newCapacity + 3) & 0xFFFFFFFFFFFFFFFCui64;
    v7 = 4 * v6;
    if ( v4 )
    {
      v8 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v4, v7);
      v5->Policy.Capacity = v6;
      v5->Data = v8;
      return;
    }
    v9 = 339;
    this->Data = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   v3,
                                   v7,
                                   (Scaleform::AllocInfo *)&v9);
  }
  else
  {
    v6 = 0i64;
    if ( v4 )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v5->Data = 0i64;
      v5->Policy.Capacity = 0i64;
      return;
    }
  }
  v5->Policy.Capacity = v6;
}

// File Line: 174
// RVA: 0x903640
void __fastcall Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> *this, const void *pheapAddr, unsigned __int64 newSize)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  const void *v5; // rbp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *v6; // r14
  unsigned __int64 v7; // rdi
  Scaleform::RefCountNTSImpl **i; // rbx

  v3 = this->Size;
  v4 = newSize;
  v5 = pheapAddr;
  v6 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy> *)this;
  if ( newSize >= v3 )
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
      v6->Size = v4;
    }
  }
  else
  {
    v7 = v3 - newSize;
    for ( i = (Scaleform::RefCountNTSImpl **)&this->Data[v7 + newSize - 1]; v7; --v7 )
    {
      if ( *i )
        Scaleform::RefCountNTSImpl::Release(*i);
      i -= 2;
    }
    if ( v4 < v6->Policy.Capacity >> 1 )
      Scaleform::ArrayDataBase<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v6,
        v5,
        v4);
    v6->Size = v4;
  }
}

// File Line: 223
// RVA: 0x6C5600
void __fastcall Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>(Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *this, Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::ArrayData<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  unsigned __int64 v3; // rsi
  Scaleform::GFx::AS2::ArraySortFunctor *v4; // rbp
  unsigned __int64 v5; // rbx

  v2 = this;
  this->Data = 0i64;
  this->Size = 0i64;
  this->Policy.Capacity = 0i64;
  v3 = a->Size;
  v4 = a->Data;
  if ( v3 )
  {
    v5 = this->Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      this,
      v5 + v3);
    Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(&v2->Data[v5], v3, v4);
  }
}

// File Line: 232
// RVA: 0x814130
void __fastcall Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *this, unsigned __int64 newSize)
{
  unsigned __int64 v2; // rdi
  Scaleform::ArrayData<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v3; // rbx

  v2 = newSize;
  v3 = this;
  if ( newSize >= this->Size )
  {
    if ( newSize > this->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
        this,
        newSize + (newSize >> 2));
      v3->Size = v2;
      return;
    }
  }
  else if ( newSize < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      this,
      newSize);
    v3->Size = v2;
    return;
  }
  this->Size = newSize;
}

// File Line: 240
// RVA: 0x9A2000
void __fastcall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this, Scaleform::Render::Matrix3x4<float> *val)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rsi
  Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // r8
  Scaleform::Render::Matrix3x4<float> *v6; // rdx

  v2 = val;
  v3 = this;
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
    (Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *)&this->Data,
    this,
    v5);
LABEL_7:
  v3->Size = v4;
  v6 = &v3->Data[v4 - 1];
  if ( v6 )
  {
    v6->M[0][0] = v2->M[0][0];
    v6->M[0][1] = v2->M[0][1];
    v6->M[0][2] = v2->M[0][2];
    v6->M[0][3] = v2->M[0][3];
    v6->M[1][0] = v2->M[1][0];
    v6->M[1][1] = v2->M[1][1];
    v6->M[1][2] = v2->M[1][2];
    v6->M[1][3] = v2->M[1][3];
    v6->M[2][0] = v2->M[2][0];
    v6->M[2][1] = v2->M[2][1];
    v6->M[2][2] = v2->M[2][2];
    v6->M[2][3] = v2->M[2][3];
  }
}

// File Line: 254
// RVA: 0x958820
void __fastcall Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Append(Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *this, Scaleform::Waitable::HandlerStruct *other, unsigned __int64 count)
{
  unsigned __int64 v3; // rsi
  Scaleform::Waitable::HandlerStruct *v4; // rbx
  Scaleform::ArrayData<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *v5; // rbp
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r14
  unsigned __int64 v8; // r8
  Scaleform::Waitable::HandlerStruct *i; // rdi

  if ( !count )
    return;
  v3 = count;
  v4 = other;
  v5 = this;
  v6 = this->Size;
  v7 = v6 + count;
  if ( v6 + count >= v6 )
  {
    if ( v7 <= this->Policy.Capacity )
      goto LABEL_8;
    v8 = v7 + (v7 >> 2);
  }
  else
  {
    if ( v7 >= this->Policy.Capacity >> 1 )
      goto LABEL_8;
    v8 = v6 + count;
  }
  Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1>>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Waitable::HandlerStruct,Scaleform::AllocatorGH<Scaleform::Waitable::HandlerStruct,2>,Scaleform::ArrayConstPolicy<0,16,1> > *)&this->Data,
    this,
    v8);
LABEL_8:
  v5->Size = v7;
  for ( i = &v5->Data[v6]; v3; --v3 )
  {
    if ( i )
    {
      i->Handler = v4->Handler;
      i->pUserData = v4->pUserData;
    }
    ++v4;
    ++i;
  }
}

// File Line: 288
// RVA: 0x893C10
void __fastcall Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>(Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *this, Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::ArrayDataDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  Scaleform::MemoryHeap *v3; // rax
  unsigned __int64 v4; // rsi
  Scaleform::GFx::MovieDataDef::FrameLabelInfo *v5; // rbp
  unsigned __int64 v6; // rbx

  v2 = this;
  this->Data = 0i64;
  this->Size = 0i64;
  this->Policy.Capacity = 0i64;
  v3 = a->pHeap;
  this->pHeap = v3;
  v4 = a->Size;
  v5 = a->Data;
  if ( v4 )
  {
    v6 = this->Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::GFx::MovieDataDef::FrameLabelInfo,Scaleform::AllocatorDH<Scaleform::GFx::MovieDataDef::FrameLabelInfo,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      v3,
      v6 + v4);
    Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::ConstructArray(&v2->Data[v6], v4, v5);
  }
}

// File Line: 296
// RVA: 0x814320
void __fastcall Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *this, unsigned __int64 newSize)
{
  unsigned __int64 v2; // rdi
  Scaleform::MemoryHeap *v3; // rdx
  Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *v4; // rbx

  v2 = newSize;
  v3 = this->pHeap;
  v4 = this;
  if ( v2 >= this->Size )
  {
    if ( v2 > this->Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
        v3,
        v2 + (v2 >> 2));
      v4->Size = v2;
      return;
    }
  }
  else if ( v2 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
      v3,
      v2);
    v4->Size = v2;
    return;
  }
  this->Size = v2;
}

// File Line: 304
// RVA: 0x80A890
void __fastcall Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::PushBack(Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this, Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *val)
{
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *v2; // rdi
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  signed __int64 v4; // rcx
  Scaleform::GFx::ASStringNode *v5; // rax

  v2 = val;
  v3 = this;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
    this->pHeap,
    this->Size + 1);
  v4 = (signed __int64)v3->Data + 8 * (3 * v3->Size - 3);
  if ( v4 )
  {
    v5 = v2->First.pNode;
    *(_QWORD *)v4 = v2->First.pNode;
    ++v5->RefCount;
    *(_QWORD *)(v4 + 8) = v2->Second;
    *(_DWORD *)(v4 + 16) = v2->Third;
  }
}

// File Line: 362
// RVA: 0x711220
void __fastcall Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::Resize(Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *this, unsigned __int64 newSize)
{
  unsigned __int64 v2; // rbx
  Scaleform::ArrayDataCC<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  unsigned __int64 v4; // rsi
  Scaleform::GFx::ASString *v5; // r8
  unsigned __int64 i; // rbx
  Scaleform::GFx::ASStringNode *v7; // rax

  v2 = newSize;
  v3 = this;
  v4 = this->Size;
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy> *)&this->Data,
    this,
    newSize);
  if ( v2 > v4 )
  {
    v5 = &v3->Data[v4];
    for ( i = v2 - v4; i; --i )
    {
      if ( v5 )
      {
        v7 = v3->DefaultValue.pNode;
        v5->pNode = v7;
        ++v7->RefCount;
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
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>>::Clear(Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *this)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > > *v1; // rbx
  Scaleform::GFx::ExecuteTag **v2; // rax
  int v3; // [rsp+30h] [rbp+8h]

  v1 = this;
  if ( this->Data.Size && this->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( this->Data.Data )
    {
      v2 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            this->Data.Data,
                                            256ui64);
    }
    else
    {
      v3 = 2;
      v2 = (Scaleform::GFx::ExecuteTag **)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                            Scaleform::Memory::pGlobalHeap,
                                            256ui64,
                                            (Scaleform::AllocInfo *)&v3);
    }
    v1->Data.Data = v2;
    v1->Data.Policy.Capacity = 32i64;
    v1->Data.Size = 0i64;
  }
  else
  {
    this->Data.Size = 0i64;
  }
}

// File Line: 501
// RVA: 0x80A730
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>>::PushBack(Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> > *this, const unsigned __int64 *val)
{
  unsigned __int64 v2; // rax
  const unsigned __int64 *v3; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> > *v5; // rbx
  unsigned __int64 v6; // r8
  unsigned __int64 *v7; // rcx

  v2 = this->Data.Size;
  v3 = val;
  v4 = v2 + 1;
  v5 = this;
  if ( v2 + 1 >= v2 )
  {
    if ( v4 > this->Data.Policy.Capacity )
    {
      v6 = v4 + (v4 >> 2);
      goto LABEL_6;
    }
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    v6 = v2 + 1;
LABEL_6:
    Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorDH_POD<unsigned __int64,328>,Scaleform::ArrayDefaultPolicy> *)&this->Data.Data,
      this->Data.pHeap,
      v6);
    goto LABEL_7;
  }
LABEL_7:
  v7 = v5->Data.Data;
  v5->Data.Size = v4;
  v7[v4 - 1] = *v3;
}

// File Line: 523
// RVA: 0x80AED0
Scaleform::GFx::AS3::Abc::MetadataInfo::Item *__fastcall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>>::PushDefault(Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> > *v1; // rbx
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // r8
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v5; // rcx
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v6; // rcx

  v1 = this;
  v2 = this->Data.Size;
  v3 = v2 + 1;
  if ( v2 + 1 >= v2 )
  {
    if ( v3 <= this->Data.Policy.Capacity )
      goto LABEL_7;
    v4 = v3 + (v3 >> 2);
  }
  else
  {
    if ( v3 >= this->Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v4 = v2 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)this,
    this,
    v4);
LABEL_7:
  v5 = v1->Data.Data;
  v1->Data.Size = v3;
  v6 = &v5[v3 - 1];
  if ( v6 )
    *v6 = 0i64;
  return &v1->Data.Data[v1->Data.Size - 1];
}

// File Line: 529
// RVA: 0x8F08F0
Scaleform::Ptr<Scaleform::GFx::ASStringNode> *__fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>>::Pop(Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy> > *this, Scaleform::Ptr<Scaleform::GFx::ASStringNode> *result)
{
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v2; // rbx
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v3; // rdx
  Scaleform::GFx::ASStringNode *v4; // rax

  v2 = result;
  v3 = &this->Data.Data[this->Data.Size];
  v4 = v3[-1].pObject;
  if ( v4 )
    ++v4->RefCount;
  v2->pObject = v3[-1].pObject;
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size - 1);
  return v2;
}

// File Line: 546
// RVA: 0x6D2C60
Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *__usercall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=@<rax>(Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *this@<rcx>, Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *a@<rdx>, __int64 a3@<rdi>, __int64 a4@<r12>, __int64 a5@<r13>, __int64 a6@<r14>, __int64 a7@<r15>)
{
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *v7; // r15
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *v8; // r14
  unsigned __int64 v9; // rbp
  __int64 v10; // rbx
  Scaleform::GFx::AS2::Value *v11; // rsi
  Scaleform::GFx::AS2::Value *v12; // rdi
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v16; // rcx
  Scaleform::GFx::AS2::FunctionObject *v17; // r8
  Scaleform::GFx::AS2::LocalFrame *v18; // rdx
  char v19; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // rcx
  unsigned int v21; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // rcx
  unsigned int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v25; // rcx
  Scaleform::GFx::AS2::FunctionObject *v26; // rdx
  Scaleform::GFx::AS2::LocalFrame *v27; // rdx
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v30; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v31; // [rsp+30h] [rbp-38h]
  char v32; // [rsp+38h] [rbp-30h]
  __int64 v33; // [rsp+40h] [rbp-28h]
  __int64 v34; // [rsp+48h] [rbp-20h]
  __int64 v35; // [rsp+50h] [rbp-18h]
  __int64 v36; // [rsp+58h] [rbp-10h]
  __int64 v37; // [rsp+60h] [rbp-8h]

  v37 = a3;
  v36 = a4;
  v35 = a5;
  v34 = a6;
  v33 = a7;
  v7 = a;
  v8 = this;
  Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    a->Data.Size);
  v9 = 0i64;
  if ( v8->Data.Size )
  {
    v10 = 0i64;
    do
    {
      v11 = v7->Data.Data;
      v12 = &v8->Data.Data[v10];
      if ( v12->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v8->Data.Data[v10]);
      v12->T.Type = v11[v10].T.Type;
      switch ( v11[v10].T.Type )
      {
        case 2:
          v12->V.BooleanValue = v11[v10].V.BooleanValue;
          break;
        case 3:
          v12->V.pStringNode = v11[v10].V.pStringNode;
          break;
        case 4:
          v12->NV.Int32Value = v11[v10].NV.Int32Value;
          break;
        case 5:
        case 0xB:
          v13 = v11[v10].V.pStringNode;
          v12->V.pStringNode = v13;
          ++v13->RefCount;
          break;
        case 6:
          v14 = v11[v10].V.pStringNode;
          if ( v14 )
          {
            if ( (*(unsigned int (__cdecl **)(unsigned int *))(*(_QWORD *)&v14->Size + 16i64))(&v14->Size) != 23 )
              goto LABEL_32;
            v12->T.Type = 8;
            v15 = (*(__int64 (__fastcall **)(unsigned int *, Scaleform::GFx::AS2::RefCountBaseGC<323> **))(*(_QWORD *)&v11[v10].V.pStringNode->Size + 96i64))(
                    &v11[v10].V.pStringNode->Size,
                    &v30);
            v16 = (Scaleform::GFx::AS2::FunctionRefBase *)&v12->NV.8;
            v16->Flags = 0;
            v17 = *(Scaleform::GFx::AS2::FunctionObject **)v15;
            v16->Function = *(Scaleform::GFx::AS2::FunctionObject **)v15;
            if ( v17 )
              v17->RefCount = (v17->RefCount + 1) & 0x8FFFFFFF;
            v12->V.FunctionValue.pLocalFrame = 0i64;
            v18 = *(Scaleform::GFx::AS2::LocalFrame **)(v15 + 8);
            if ( v18 )
              Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v16, v18, *(_BYTE *)(v15 + 16) & 1);
            v19 = v32;
            if ( !(v32 & 2) )
            {
              v20 = v30;
              if ( v30 )
              {
                v21 = v30->RefCount;
                if ( v21 & 0x3FFFFFF )
                {
                  v30->RefCount = v21 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
                  v19 = v32;
                }
              }
            }
            v30 = 0i64;
            if ( !(v19 & 1) )
            {
              v22 = v31;
              if ( v31 )
              {
                v23 = v31->RefCount;
                if ( v23 & 0x3FFFFFF )
                {
                  v31->RefCount = v23 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
                }
              }
            }
            v31 = 0i64;
          }
          else
          {
            v12->V.pStringNode = 0i64;
          }
          break;
        case 7:
          v24 = v11[v10].V.pStringNode;
          v12->V.pStringNode = v24;
          if ( v24 )
            ++LODWORD(v24->pData);
          break;
        case 8:
        case 0xC:
          v25 = (Scaleform::GFx::AS2::FunctionRefBase *)&v12->NV.8;
          v25->Flags = 0;
          v26 = v11[v10].V.FunctionValue.Function;
          v25->Function = v26;
          if ( v26 )
            v26->RefCount = (v26->RefCount + 1) & 0x8FFFFFFF;
          v12->V.FunctionValue.pLocalFrame = 0i64;
          v27 = v11[v10].V.FunctionValue.pLocalFrame;
          if ( v27 )
            Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v25, v27, v11[v10].V.FunctionValue.Flags & 1);
          break;
        case 9:
LABEL_32:
          v28 = v11[v10].V.pStringNode;
          v12->V.pStringNode = v28;
          v28->RefCount = (v28->RefCount + 1) & 0x8FFFFFFF;
          break;
        default:
          break;
      }
      ++v9;
      ++v10;
    }
    while ( v9 < v8->Data.Size );
  }
  return v8;
}

// File Line: 556
// RVA: 0x811F00
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this, unsigned __int64 index, unsigned __int64 num)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // r14
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *v5; // rdi
  unsigned __int64 v6; // rbx

  v3 = num;
  v4 = index;
  v5 = this;
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
    memmove(&v5->Data.Data[v6], &v5->Data.Data[v4 + v3], 32 * (v5->Data.Size - v4 - v3));
    v5->Data.Size -= v3;
  }
}

// File Line: 576
// RVA: 0x8FEDA0
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<double,Scaleform::AllocatorDH<double,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy> > *this, unsigned __int64 index)
{
  unsigned __int64 v2; // r8
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,Scaleform::AllocatorDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2>,Scaleform::ArrayDefaultPolicy> > *v3; // rbx

  v2 = this->Data.Size;
  v3 = this;
  if ( v2 == 1 )
  {
    if ( this->Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( this->Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v3->Data.Data = 0i64;
      }
      v3->Data.Policy.Capacity = 0i64;
    }
    v3->Data.Size = 0i64;
  }
  else
  {
    memmove(&this->Data.Data[index], &this->Data.Data[index + 1], 8 * (v2 - index) - 8);
    --v3->Data.Size;
  }
}

// File Line: 595
// RVA: 0x7F5E40
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this, unsigned __int64 index, Scaleform::GFx::AS3::Value *val)
{
  unsigned __int64 v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rsi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *v5; // rdi
  unsigned __int64 v6; // r8

  v3 = index;
  v4 = val;
  v5 = this;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size + 1);
  v6 = v5->Data.Size;
  if ( v3 < v6 - 1 )
    memmove(&v5->Data.Data[v3 + 1], &v5->Data.Data[v3], 32 * (v6 - v3 - 1));
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::Construct(&v5->Data.Data[v3], v4);
}

// File Line: 611
// RVA: 0x8E6990
void __fastcall Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *this, unsigned __int64 index, unsigned __int64 num, Scaleform::GFx::AS3::Value *val)
{
  Scaleform::GFx::AS3::Value *v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rdi
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> > *v7; // r14
  signed __int64 v8; // rdi
  Scaleform::GFx::AS3::Value *v9; // rcx

  v4 = val;
  v5 = num;
  v6 = index;
  v7 = this;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    num + this->Data.Size);
  if ( v6 < v7->Data.Size - v5 )
    memmove(&v7->Data.Data[v6 + v5], &v7->Data.Data[v6], 32 * (v7->Data.Size - v6 - v5));
  if ( v5 )
  {
    v8 = v6;
    do
    {
      v9 = &v7->Data.Data[v8];
      if ( &v7->Data.Data[v8] )
      {
        v9->Flags = v4->Flags;
        v9->Bonus.pWeakProxy = v4->Bonus.pWeakProxy;
        v9->value.VNumber = v4->value.VNumber;
        v9->value.VS._2.VObj = v4->value.VS._2.VObj;
        if ( (v4->Flags & 0x1F) > 9 )
        {
          if ( (v4->Flags >> 9) & 1 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(v4);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v4);
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
void __fastcall Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0>>(Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *this)
{
  this->Data.Data = 0i64;
  this->Data.Size = 0i64;
  this->Data.Policy.Capacity = 0i64;
}

// File Line: 899
// RVA: 0x94DBB0
Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>::operator=(Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *this, Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  unsigned __int64 v4; // rax

  v2 = a;
  v3 = this;
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this,
    a->Data.Size);
  v4 = 0i64;
  if ( v3->Data.Size )
  {
    do
    {
      ++v4;
      v3->Data.Data[v4 - 1] = v2->Data.Data[v4 - 1];
    }
    while ( v4 < v3->Data.Size );
  }
  return v3;
}

// File Line: 921
// RVA: 0x790290
Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy>::operator=(Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *this, Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v2; // r14
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx

  v2 = a;
  v3 = this;
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    a->Data.Size);
  v4 = 0i64;
  if ( v3->Data.Size )
  {
    v5 = 0i64;
    do
    {
      Scaleform::GFx::AS3::Value::Assign(&v3->Data.Data[v5], &v2->Data.Data[v5]);
      ++v4;
      ++v5;
    }
    while ( v4 < v3->Data.Size );
  }
  return v3;
}

