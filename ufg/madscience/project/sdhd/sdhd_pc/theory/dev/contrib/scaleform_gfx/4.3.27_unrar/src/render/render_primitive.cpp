// File Line: 36
// RVA: 0x93F870
void __fastcall Scaleform::Render::Mesh::Mesh(
        Scaleform::Render::Mesh *this,
        Scaleform::Render::Renderer2DImpl *prenderer,
        Scaleform::Render::MeshProvider *provider,
        Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::MeshBase::MeshBase(this, prenderer, provider, viewMatrix, morphRatio, layer, meshGenFlags);
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  this->CacheItems.Size = 0i64;
  *(_QWORD *)&this->VertexMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->VertexMatrix.M[0][2] = 0i64;
  this->VertexMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->VertexMatrix.M[1][1] = 1065353216i64;
  this->VertexMatrix.M[1][3] = 0.0;
  this->LargeMesh = 0;
}

// File Line: 40
// RVA: 0x94B4F0
void __fastcall Scaleform::Render::Mesh::~Mesh(Scaleform::Render::Mesh *this)
{
  unsigned __int64 Size; // rsi
  _QWORD *p_pData; // rdi
  Scaleform::Render::Scale9GridData *pObject; // rcx
  Scaleform::Render::MeshProvider *v5; // rcx
  __int64 v6; // [rsp+20h] [rbp-18h]

  v6 = -2i64;
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  Size = this->CacheItems.Size;
  if ( Size <= 2 )
    p_pData = &this->CacheItems.AD.pData;
  else
    p_pData = this->CacheItems.AD.pData;
  for ( ; Size; ++p_pData )
  {
    --Size;
    if ( *p_pData )
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, Scaleform::Render::Mesh *, __int64))(***(_QWORD ***)(*p_pData + 16i64)
                                                                                         + 64i64))(
        **(_QWORD **)(*p_pData + 16i64),
        *p_pData,
        0i64,
        this,
        v6);
  }
  if ( this->StagingBufferSize )
  {
    this->pPrev->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::pNext = this->pNext;
    this->pNext->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::pPrev = this->pPrev;
    this->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
    this->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
  }
  if ( this->CacheItems.Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->CacheItems.AD.pData);
  pObject = this->pScale9Grid.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount, 0xFFFFFFFF) == 1 )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v5 = this->pProvider.pObject;
  if ( v5 )
    v5->vfptr->Release(v5);
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 63
// RVA: 0x98E930
__int64 __fastcall Scaleform::Render::Mesh::GetUseStatus(Scaleform::Render::Mesh *this)
{
  unsigned __int64 Size; // rsi
  unsigned int v2; // ebx
  _QWORD *p_pData; // r14
  unsigned __int64 i; // rdi
  __int64 v5; // rcx
  int v6; // eax

  Size = this->CacheItems.Size;
  v2 = 0;
  if ( Size <= 2 )
    p_pData = &this->CacheItems.AD.pData;
  else
    p_pData = this->CacheItems.AD.pData;
  for ( i = 0i64; i < Size; ++i )
  {
    v5 = **(_QWORD **)(p_pData[i] + 16i64);
    v6 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 56i64))(v5);
    if ( v6 > (int)v2 )
      v2 = v6;
  }
  return v2;
}

// File Line: 149
// RVA: 0x94BF20
void __fastcall Scaleform::Render::PrimitiveFill::~PrimitiveFill(Scaleform::Render::PrimitiveFill *this)
{
  Scaleform::Render::PrimitiveFillManager *pManager; // rcx
  Scaleform::Render::PrimitiveFill *key; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::PrimitiveFill::`vftable;
  pManager = this->pManager;
  if ( pManager )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::PrimitiveFill *>(
      &pManager->FillSet,
      &key);
  }
  key = (Scaleform::Render::PrimitiveFill *)&this->Data;
  `eh vector destructor iterator(
    this->Data.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 157
// RVA: 0x997DC0
bool __fastcall Scaleform::Render::PrimitiveFill::IsSolid(unsigned int type)
{
  return type <= 2;
}

// File Line: 186
// RVA: 0x9DD2E0
Scaleform::Render::Image *__fastcall Scaleform::Render::PrimitiveFillManager::createGradientImage(
        Scaleform::Render::PrimitiveFillManager *this,
        Scaleform::Render::GradientData *data,
        float morphRatio)
{
  Scaleform::HashSetLH<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,2,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *p_Gradients; // rdi
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::Render::GradientImage *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r11
  unsigned __int64 v11; // r9
  unsigned __int8 *v12; // r8
  __int64 v13; // r10
  Scaleform::Render::GradientKey key; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::GradientImage *v16; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::Render::GradientImage *v17; // [rsp+78h] [rbp+10h]
  unsigned int v18; // [rsp+80h] [rbp+18h] BYREF

  v16 = (Scaleform::Render::GradientImage *)this;
  key.pData = data;
  key.MorphRatio = morphRatio;
  p_Gradients = &this->Gradients;
  v6 = Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::findIndexAlt<Scaleform::Render::GradientKey>(
         &this->Gradients,
         &key);
  if ( v6 < 0 )
  {
    v18 = 3;
    v8 = (Scaleform::Render::GradientImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::PrimitiveFillManager *, __int64, unsigned int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               72i64,
                                               &v18,
                                               -2i64);
    v17 = v8;
    if ( v8 )
    {
      Scaleform::Render::GradientImage::GradientImage(v8, this, data, morphRatio);
      v7 = v9;
    }
    else
    {
      v7 = 0i64;
    }
    v16 = (Scaleform::Render::GradientImage *)v7;
    v10 = *(_QWORD *)(v7 + 48);
    v18 = *(_DWORD *)(v7 + 64);
    v11 = *(unsigned __int8 *)(v10 + 17);
    if ( *(_WORD *)(v10 + 18) )
    {
      v12 = *(unsigned __int8 **)(v10 + 24);
      v13 = *(unsigned __int16 *)(v10 + 18);
      do
      {
        v11 ^= *((unsigned int *)v12 + 1) ^ *v12 ^ ((unsigned __int64)*((unsigned int *)v12 + 1) >> 16);
        v12 += 8;
        --v13;
      }
      while ( v13 );
    }
    if ( *(_QWORD *)(v10 + 40) )
      v11 ^= (unsigned __int16)v18 ^ ((unsigned __int64)v18 >> 16);
    Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::add<Scaleform::Render::GradientImage *>(
      p_Gradients,
      p_Gradients,
      &v16,
      v11);
  }
  else
  {
    v7 = *(&p_Gradients->pTable[2].EntryCount + 3 * v6);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 8i64))(v7);
  }
  return (Scaleform::Render::Image *)v7;
}

// File Line: 203
// RVA: 0x966610
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        Scaleform::Render::PrimitiveFillData *initdata)
{
  Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> >::TableType *pTable; // rdx
  signed __int64 v5; // rax
  Scaleform::Render::PrimitiveFill *result; // rax
  Scaleform::Render::PrimitiveFill *v7; // rbx
  Scaleform::Render::PrimitiveFill *key; // [rsp+30h] [rbp+8h] BYREF

  pTable = this->FillSet.pTable;
  if ( pTable
    && (v5 = Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::findIndexCore<Scaleform::Render::PrimitiveFillData>(
               &this->FillSet,
               initdata,
               pTable->SizeMask & ((unsigned int)initdata->Type ^ (unsigned __int64)initdata->Textures[1].pObject ^ initdata->SolidColor.Raw ^ ((unsigned __int64)initdata->Textures[0].pObject >> 2) ^ initdata->pFormat->Size ^ (unsigned __int64)(4 * ((unsigned __int8)initdata->FillModes[0].Fill ^ (4 * (unsigned int)(unsigned __int8)initdata->FillModes[1].Fill))))),
        v5 >= 0) )
  {
    result = (Scaleform::Render::PrimitiveFill *)*(&this->FillSet.pTable[2].EntryCount + 3 * v5);
    ++result->RefCount;
  }
  else
  {
    result = (Scaleform::Render::PrimitiveFill *)this->pHAL->vfptr[28].__vecDelDtor(this->pHAL, initdata);
    v7 = result;
    key = result;
    if ( result )
    {
      Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::add<Scaleform::Render::PrimitiveFill *>(
        &this->FillSet,
        &this->FillSet,
        &key,
        (unsigned int)result->Data.Type ^ (unsigned __int64)result->Data.Textures[1].pObject ^ result->Data.SolidColor.Raw ^ ((unsigned __int64)result->Data.Textures[0].pObject >> 2) ^ result->Data.pFormat->Size ^ (unsigned __int64)(4 * ((unsigned __int8)result->Data.FillModes[0].Fill ^ (4 * (unsigned int)(unsigned __int8)result->Data.FillModes[1].Fill))));
      v7->pManager = this;
      return v7;
    }
  }
  return result;
}

// File Line: 222
// RVA: 0x966730
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateFill(
        Scaleform::Render::PrimitiveFillManager *this,
        Scaleform::Render::FillData *initdata,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg,
        Scaleform::Render::TextureManager *mng)
{
  Scaleform::Render::VertexFormat *pVFormat; // rbx
  Scaleform::Render::PrimitiveFill *v9; // rbx
  Scaleform::Ptr<Scaleform::Render::Texture> *Textures; // rcx
  unsigned int Color; // eax
  Scaleform::Render::VertexFormat *v13; // rbx
  Scaleform::Render::VertexFormat *v14; // rbx
  Scaleform::Render::GradientData *pGradient; // rcx
  Scaleform::Render::Texture *v16; // r9
  Scaleform::Render::VertexFormat *v17; // rbx
  Scaleform::Render::Image *GradientImage; // rbx
  Scaleform::Render::Texture *v19; // rax
  Scaleform::Render::ImageFillMode fm0[8]; // [rsp+28h] [rbp-21h] BYREF
  Scaleform::Render::ImageFillMode fm1[8]; // [rsp+30h] [rbp-19h]
  Scaleform::Render::PrimitiveFillData initdataa; // [rsp+38h] [rbp-11h] BYREF
  Scaleform::Render::PrimitiveFillData v23; // [rsp+60h] [rbp+17h] BYREF
  Scaleform::Render::ImageFillMode vars0; // [rsp+B0h] [rbp+67h] BYREF
  float v25; // [rsp+C8h] [rbp+7Fh]

  *(_QWORD *)&fm1[0].Fill = -2i64;
  switch ( initdata->Type )
  {
    case Fill_Mask:
      pVFormat = initdata->pVFormat;
      *(_QWORD *)&initdataa.Type = 1i64;
      *(_WORD *)&initdataa.FillModes[0].Fill = 0;
      `eh vector constructor iterator(
        initdataa.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdataa.pFormat = pVFormat;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
      goto LABEL_3;
    case Fill_SolidColor:
      Color = initdata->Color;
      v13 = initdata->pVFormat;
      initdataa.Type = PrimFill_SolidColor;
      initdataa.SolidColor.Raw = Color;
      *(_WORD *)&initdataa.FillModes[0].Fill = 0;
      `eh vector constructor iterator(
        initdataa.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdataa.pFormat = v13;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
      goto LABEL_3;
    case Fill_VColor:
    case Fill_VColor_TestKey:
      v14 = initdata->pVFormat;
      initdataa.Type = initdata->PrimFill;
      initdataa.SolidColor.Raw = 0;
      *(_WORD *)&initdataa.FillModes[0].Fill = 0;
      `eh vector constructor iterator(
        initdataa.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdataa.pFormat = v14;
      if ( initdata->Type == Fill_VColor_TestKey )
        initdataa.SolidColor.Raw = initdata->Color;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
      goto LABEL_3;
    case Fill_Image:
      pGradient = initdata->pGradient;
      if ( pGradient
        && (v16 = (Scaleform::Render::Texture *)pGradient->vfptr[21].__vecDelDtor(pGradient, (unsigned int)mng)) != 0i64 )
      {
        vars0.Fill = 0;
        Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
          &v23,
          initdata->PrimFill,
          initdata->pVFormat,
          v16,
          &fm0[0].Fill,
          0i64,
          &vars0.Fill);
        v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v23);
LABEL_12:
        Textures = v23.Textures;
      }
      else
      {
        v17 = initdata->pVFormat;
        initdataa.Type = PrimFill_SolidColor;
        initdataa.SolidColor.Raw = -65536;
        *(_WORD *)&initdataa.FillModes[0].Fill = 0;
        `eh vector constructor iterator(
          initdataa.Textures,
          8ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
        initdataa.pFormat = v17;
        v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdataa);
LABEL_3:
        Textures = initdataa.Textures;
      }
      `eh vector destructor iterator(
        Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
      return v9;
    case Fill_Gradient:
      GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, initdata->pGradient, v25);
      if ( gradientImg->pObject )
        ((void (__fastcall *)(Scaleform::Render::Image *))gradientImg->pObject->vfptr[2].__vecDelDtor)(gradientImg->pObject);
      gradientImg->pObject = GradientImage;
      if ( !GradientImage )
        return 0i64;
      vars0.Fill = 0;
      fm0[0] = initdata->FillMode;
      v19 = (Scaleform::Render::Texture *)GradientImage->vfptr[21].__vecDelDtor(GradientImage, (unsigned int)mng);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &v23,
        initdata->PrimFill,
        initdata->pVFormat,
        v19,
        &fm0[0].Fill,
        0i64,
        &vars0.Fill);
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &v23);
      goto LABEL_12;
    default:
      return 0i64;
  }
}

// File Line: 357
// RVA: 0x967C60
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
        Scaleform::Render::PrimitiveFillManager *this,
        unsigned int mergeFlags,
        Scaleform::Render::VertexFormat *vformat,
        Scaleform::Render::FillData *fd0,
        Scaleform::Render::FillData *fd1,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg0,
        Scaleform::Ptr<Scaleform::Render::Image> *gradientImg1,
        Scaleform::Render::TextureManager *textureManager,
        float morphRatio)
{
  Scaleform::Render::PrimitiveFillManager *v12; // rax
  Scaleform::Render::FillType Type; // esi
  Scaleform::Render::FillType v14; // edi
  Scaleform::Render::Image *pImage; // rbp
  Scaleform::Render::Image *GradientImage; // r15
  Scaleform::Render::FillTypeMergeInfo *v17; // rcx
  unsigned __int8 F0; // al
  Scaleform::Render::PrimitiveFillType v19; // ebx
  Scaleform::Render::PrimitiveFill *v20; // rdi
  __int64 v21; // rax
  Scaleform::Render::Texture *v22; // rdi
  Scaleform::Render::Texture *pObject; // rcx
  __int64 v24; // rax
  Scaleform::Render::Texture *v25; // rdi
  Scaleform::Render::Texture *v26; // rcx
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+38h] [rbp-50h] BYREF

  v12 = this;
  Type = fd0->Type;
  v14 = fd1->Type;
  pImage = fd0->pImage;
  GradientImage = fd1->pImage;
  if ( fd0->Type == Fill_Gradient )
  {
    pImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, fd0->pGradient, morphRatio);
    if ( gradientImg0->pObject )
      ((void (__fastcall *)(Scaleform::Render::Image *))gradientImg0->pObject->vfptr[2].__vecDelDtor)(gradientImg0->pObject);
    gradientImg0->pObject = pImage;
    Type = Fill_Image;
    v12 = this;
  }
  if ( v14 == Fill_Gradient )
  {
    GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(v12, fd1->pGradient, morphRatio);
    if ( gradientImg1->pObject )
      ((void (__fastcall *)(Scaleform::Render::Image *))gradientImg1->pObject->vfptr[2].__vecDelDtor)(gradientImg1->pObject);
    gradientImg1->pObject = GradientImage;
    v14 = Fill_Image;
  }
  if ( Type == Fill_VColor_TestKey )
    Type = Fill_VColor;
  if ( v14 == Fill_VColor_TestKey )
    v14 = Fill_VColor;
  v17 = FillTypeMergeTable;
  F0 = FillTypeMergeTable[0].F0;
  do
  {
    if ( F0 == Type
      && mergeFlags == (unsigned __int8)v17->MergeFlags
      && ((unsigned __int8)v17->F1 == v14 || (mergeFlags & 2) == 0) )
    {
      break;
    }
    ++v17;
    F0 = v17->F0;
  }
  while ( v17->F0 );
  v19 = (unsigned __int8)v17->Result;
  initdata.Type = v19;
  v20 = 0i64;
  initdata.SolidColor.Raw = 0;
  *(_WORD *)&initdata.FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  initdata.pFormat = vformat;
  switch ( v19 )
  {
    case PrimFill_Mask:
      goto $LN8_109;
    case PrimFill_SolidColor:
      initdata.SolidColor.Raw = fd0->Color;
      goto $LN8_109;
    case PrimFill_VColor:
    case PrimFill_VColor_EAlpha:
      if ( fd0->Type == Fill_VColor_TestKey )
        initdata.SolidColor.Raw = fd0->Color;
      goto $LN8_109;
    case PrimFill_Texture:
    case PrimFill_Texture_EAlpha:
    case PrimFill_Texture_VColor:
    case PrimFill_Texture_VColor_EAlpha:
      goto LABEL_30;
    case PrimFill_2Texture:
    case PrimFill_2Texture_EAlpha:
      v21 = (__int64)GradientImage->vfptr[21].__vecDelDtor(GradientImage, (unsigned int)textureManager);
      v22 = (Scaleform::Render::Texture *)v21;
      if ( v21 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v21 + 8), 1u);
      pObject = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && pObject )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      initdata.Textures[1].pObject = v22;
      initdata.FillModes[1].Fill = fd1->FillMode.Fill;
LABEL_30:
      v24 = (__int64)pImage->vfptr[21].__vecDelDtor(pImage, (unsigned int)textureManager);
      v25 = (Scaleform::Render::Texture *)v24;
      if ( v24 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v24 + 8), 1u);
      v26 = initdata.Textures[0].pObject;
      if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v26 )
        v26->vfptr->__vecDelDtor(v26, 1u);
      initdata.Textures[0].pObject = v25;
      initdata.FillModes[0].Fill = fd0->FillMode.Fill;
$LN8_109:
      v20 = Scaleform::Render::PrimitiveFillManager::CreateFill(this, &initdata);
      break;
    default:
      break;
  }
  `eh vector destructor iterator(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  return v20;
}

// File Line: 490
// RVA: 0x9407F0
void __fastcall Scaleform::Render::Primitive::Primitive(
        Scaleform::Render::Primitive *this,
        Scaleform::Render::HAL *phal,
        Scaleform::Render::PrimitiveFill *pfill)
{
  Scaleform::Render::PrimitiveFillType Type; // edx
  char v4; // al

  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::`vftable;
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->pHAL = phal;
  if ( pfill )
    ++pfill->RefCount;
  this->pFill.pObject = pfill;
  this->Batches.Root.pPrev = (Scaleform::Render::PrimitiveBatch *)&this->Batches;
  this->Batches.Root.pNext = (Scaleform::Render::PrimitiveBatch *)&this->Batches;
  Type = pfill->Data.Type;
  if ( (unsigned int)(Type - 5) > 5 )
    v4 = 0;
  else
    v4 = ((unsigned int)(Type - 9) <= 1) + 1;
  this->MatricesPerMesh = v4 + 1;
  this->Meshes.Data.Data = 0i64;
  this->Meshes.Data.Size = 0i64;
  this->Meshes.Data.Policy.Capacity = 0i64;
  this->ModifyIndex = 0;
  ++Primitive_CreateCount;
  ++Primitive_Total;
}

// File Line: 497
// RVA: 0x94BDF0
void __fastcall Scaleform::Render::Primitive::~Primitive(Scaleform::Render::Primitive *this)
{
  Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *p_Batches; // rbx
  Scaleform::Render::PrimitiveBatch *pNext; // rdx
  Scaleform::Render::PrimitiveFill *pObject; // rcx

  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  --Primitive_Total;
  p_Batches = &this->Batches;
  if ( (Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *)this->Batches.Root.pNext != &this->Batches )
  {
    do
    {
      pNext = this->Batches.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::PrimitiveBatch *)-1i64;
      pNext->pNext = (Scaleform::Render::PrimitiveBatch *)-1i64;
      if ( pNext->MeshNode.pMeshItem )
      {
        pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
        pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
        pNext->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        pNext->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        pNext->MeshNode.pMeshItem = 0i64;
      }
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    while ( (Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *)p_Batches->Root.pNext != p_Batches );
  }
  Scaleform::ConstructorMov<Scaleform::Render::Primitive::MeshEntry>::DestructArray(
    this->Meshes.Data.Data,
    this->Meshes.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Meshes.Data.Data);
  pObject = this->pFill.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 506
// RVA: 0x9944E0
char __fastcall Scaleform::Render::Primitive::Insert(
        Scaleform::Render::Primitive *this,
        unsigned int index,
        Scaleform::Render::Mesh *pmesh,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  unsigned __int64 v6; // r14
  Scaleform::Render::PrimitiveBatch *v8; // rsi
  Scaleform::Render::PrimitiveBatch *pNext; // rbx
  int v10; // edi
  __int64 v11; // rax
  __int64 v12; // r8
  unsigned int MeshCount; // ecx
  __int64 v14; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::Primitive::MeshEntry val; // [rsp+28h] [rbp-40h] BYREF

  v6 = index;
  v8 = 0i64;
  pNext = this->Batches.Root.pNext;
  v10 = 0;
  v11 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *))this->pHAL->vfptr[62].__vecDelDtor)(this->pHAL);
  v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v11 + 8) + 16i64))(v11 + 8);
  while ( 1 )
  {
    if ( v10 == (_DWORD)v6 )
    {
      if ( v8 && v8->Type == DP_Virtual )
      {
        ++v8->MeshCount;
        goto LABEL_17;
      }
      if ( pNext == (Scaleform::Render::PrimitiveBatch *)&this->Batches || pNext->Type != DP_Virtual )
      {
        v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                this,
                80i64);
        *(_QWORD *)(v14 + 32) = 0i64;
        *(_DWORD *)(v14 + 40) = 3;
        *(_QWORD *)(v14 + 48) = 0i64;
        *(_BYTE *)(v14 + 56) = 0;
        *(_QWORD *)(v14 + 64) = this;
        *(_DWORD *)(v14 + 72) = 1;
        *(_DWORD *)(v14 + 76) = v10;
        *(_QWORD *)(v14 + 8) = pNext->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev;
        *(_QWORD *)v14 = pNext->pPrev;
        pNext->pPrev->pNext = (Scaleform::Render::PrimitiveBatch *)v14;
        pNext->pPrev = (Scaleform::Render::PrimitiveBatch *)v14;
        goto LABEL_17;
      }
    }
    if ( pNext == (Scaleform::Render::PrimitiveBatch *)&this->Batches )
      goto LABEL_17;
    MeshCount = pNext->MeshCount;
    if ( (int)v6 - v10 < MeshCount )
      break;
    v10 += MeshCount;
    v8 = pNext;
    pNext = pNext->pNext;
  }
  ++pNext->MeshCount;
  if ( pNext->Type != DP_Instanced
    || this->Meshes.Data.Data[v10].pMesh.pObject != pmesh
    || pNext->MeshCount > *(_DWORD *)(v12 + 48) )
  {
    pNext->Type = DP_Virtual;
    if ( pNext->MeshNode.pMeshItem )
    {
      pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
      pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
      pNext->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pMeshItem = 0i64;
    }
  }
LABEL_17:
  pHandle = m->pHandle;
  val.M.pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  if ( pmesh )
    _InterlockedExchangeAdd(&pmesh->RefCount, 1u);
  val.pMesh.pObject = pmesh;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->Meshes,
    v6,
    &val);
  if ( (unsigned int)v6 < this->ModifyIndex )
    this->ModifyIndex = v6;
  ++Primitive_Insert;
  if ( val.pMesh.pObject && _InterlockedExchangeAdd(&val.pMesh.pObject->RefCount, 0xFFFFFFFF) == 1 )
    val.pMesh.pObject->vfptr->__vecDelDtor(val.pMesh.pObject, 1u);
  if ( val.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = val.M.pHandle->pHeader;
    if ( val.M.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
  return 1;
}

// File Line: 588
// RVA: 0x9A89C0
void __fastcall Scaleform::Render::Primitive::Remove(
        Scaleform::Render::Primitive *this,
        unsigned int index,
        unsigned int count)
{
  Scaleform::Render::PrimitiveBatch *pNext; // rbx
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // rbp
  unsigned int v7; // esi
  int v8; // edi
  unsigned int MeshCount; // r9d
  Scaleform::Render::PrimitiveBatch *v10; // r8
  $562A4EA56C1311C603F27EF2D0BF37C2 *v11; // rdx
  Scaleform::Render::PrimitiveBatch *pPrev; // rcx
  unsigned int v13; // edx
  bool v14; // zf

  pNext = this->Batches.Root.pNext;
  v4 = count;
  v5 = index;
  v7 = count;
  v8 = 0;
  while ( 1 )
  {
    MeshCount = pNext->MeshCount;
    if ( (int)v5 - v8 < MeshCount )
      break;
    v8 += MeshCount;
LABEL_15:
    pNext = pNext->pNext;
LABEL_16:
    if ( !v7 || pNext == (Scaleform::Render::PrimitiveBatch *)&this->Batches )
      goto LABEL_22;
  }
  if ( (_DWORD)v5 != v8 )
  {
    v13 = v7;
    if ( v7 > v8 + MeshCount - (unsigned int)v5 )
      v13 = v8 + MeshCount - v5;
    v14 = pNext->Type == DP_Instanced;
    pNext->MeshCount = MeshCount - v13;
    if ( !v14 )
    {
      pNext->Type = DP_Virtual;
      if ( pNext->MeshNode.pMeshItem )
      {
        pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
        pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
        pNext->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        pNext->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        pNext->MeshNode.pMeshItem = 0i64;
      }
    }
    v7 -= v13;
    v8 += pNext->MeshCount;
    goto LABEL_15;
  }
  if ( v7 >= MeshCount )
  {
    v10 = pNext;
    v11 = &pNext->8;
    v7 -= MeshCount;
    pPrev = pNext->pPrev;
    pNext = pNext->pNext;
    pPrev->pNext = pNext;
    v11->pNext->pPrev = v10->pPrev;
    v10->pPrev = (Scaleform::Render::PrimitiveBatch *)-1i64;
    v11->pNext = (Scaleform::Render::PrimitiveBatch *)-1i64;
    if ( v10->MeshNode.pMeshItem )
    {
      v10->MeshNode.pPrev->pNext = v10->MeshNode.pNext;
      v10->MeshNode.pNext->pPrev = v10->MeshNode.pPrev;
      v10->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v10->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v10->MeshNode.pMeshItem = 0i64;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
    goto LABEL_16;
  }
  pNext->MeshCount -= v7;
  if ( pNext->Type != DP_Instanced )
  {
    pNext->Type = DP_Virtual;
    if ( pNext->MeshNode.pMeshItem )
    {
      pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
      pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
      pNext->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pMeshItem = 0i64;
    }
  }
LABEL_22:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    &this->Meshes,
    v5,
    v4);
  if ( (unsigned int)v5 < this->ModifyIndex )
    this->ModifyIndex = v5;
}

// File Line: 662
// RVA: 0x9B1D10
void __fastcall Scaleform::Render::Primitive::SetMesh(
        Scaleform::Render::Primitive *this,
        unsigned int index,
        Scaleform::Render::Mesh *pmesh)
{
  Scaleform::Render::Primitive::MeshEntry *v6; // rsi
  Scaleform::Render::Mesh *pObject; // rcx
  Scaleform::Render::PrimitiveBatch *pNext; // rax
  int v9; // r8d

  v6 = &this->Meshes.Data.Data[index];
  if ( v6->pMesh.pObject != pmesh )
  {
    if ( pmesh )
      _InterlockedExchangeAdd(&pmesh->RefCount, 1u);
    pObject = v6->pMesh.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr->__vecDelDtor(
        pObject,
        1u);
    v6->pMesh.pObject = pmesh;
    pNext = this->Batches.Root.pNext;
    v9 = 0;
    if ( index >= pNext->MeshCount )
    {
      do
      {
        v9 += pNext->MeshCount;
        pNext = pNext->pNext;
      }
      while ( index >= v9 + pNext->MeshCount );
    }
    pNext->Type = DP_Virtual;
    if ( pNext->MeshNode.pMeshItem )
    {
      pNext->MeshNode.pPrev->pNext = pNext->MeshNode.pNext;
      pNext->MeshNode.pNext->pPrev = pNext->MeshNode.pPrev;
      pNext->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      pNext->MeshNode.pMeshItem = 0i64;
    }
  }
}

// File Line: 737
// RVA: 0x9A9430
void __fastcall Scaleform::Render::PrimitiveBatch::RemoveAndFree(Scaleform::Render::PrimitiveBatch *this)
{
  this->pPrev->pNext = this->pNext;
  this->pNext->Scaleform::ListNode<Scaleform::Render::PrimitiveBatch>::$562A4EA56C1311C603F27EF2D0BF37C2::pPrev = this->pPrev;
  this->pPrev = (Scaleform::Render::PrimitiveBatch *)-1i64;
  this->pNext = (Scaleform::Render::PrimitiveBatch *)-1i64;
  if ( this->MeshNode.pMeshItem )
  {
    this->MeshNode.pPrev->pNext = this->MeshNode.pNext;
    this->MeshNode.pNext->pPrev = this->MeshNode.pPrev;
    this->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    this->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    this->MeshNode.pMeshItem = 0i64;
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this);
}

// File Line: 745
// RVA: 0x95C960
void __fastcall Scaleform::Render::PrimitiveBatch::CalcMeshSizes(
        Scaleform::Render::PrimitiveBatch *this,
        unsigned int *ptotalVertices,
        unsigned int *ptotalIndices)
{
  Scaleform::Render::Primitive *pPrimitive; // r10
  unsigned int Size; // r9d
  Scaleform::Render::PrimitiveBatch *i; // rax
  unsigned int MeshCount; // ecx
  unsigned int v10; // edx
  unsigned int v11; // r9d
  unsigned int MeshIndex; // r8d
  __int64 v13; // r10
  __int64 v14; // rax
  Scaleform::Render::Mesh *pObject; // rcx

  pPrimitive = this->pPrimitive;
  Size = pPrimitive->Meshes.Data.Size;
  if ( pPrimitive->ModifyIndex < Size )
  {
    for ( i = pPrimitive->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&pPrimitive->Batches; i = i->pPrev )
    {
      Size -= i->MeshCount;
      i->MeshIndex = Size;
      if ( Size < pPrimitive->ModifyIndex )
        break;
    }
    pPrimitive->ModifyIndex = pPrimitive->Meshes.Data.Size;
  }
  if ( this->Type == DP_Instanced )
    MeshCount = 1;
  else
    MeshCount = this->MeshCount;
  v10 = 0;
  v11 = 0;
  if ( MeshCount )
  {
    MeshIndex = this->MeshIndex;
    v13 = MeshCount;
    do
    {
      v14 = MeshIndex++;
      pObject = this->pPrimitive->Meshes.Data.Data[v14].pMesh.pObject;
      v10 += pObject->VertexCount;
      v11 += pObject->IndexCount;
      --v13;
    }
    while ( v13 );
    *ptotalVertices = v10;
    *ptotalIndices = v11;
  }
  else
  {
    *ptotalVertices = 0;
    *ptotalIndices = 0;
  }
}

// File Line: 771
// RVA: 0x939780
void __fastcall Scaleform::Render::ComplexMesh::ComplexMesh(
        Scaleform::Render::ComplexMesh *this,
        Scaleform::Render::Renderer2DImpl *renderer,
        Scaleform::Render::MeshProvider *meshProvider,
        Scaleform::Render::PrimitiveFillManager *fillManager,
        Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  Scaleform::Render::MeshBase::MeshBase(this, renderer, meshProvider, viewMatrix, morphRatio, layer, meshGenFlags);
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  this->UpdateListNode.pPrev = 0i64;
  this->UpdateListNode.pNext = 0i64;
  this->pFillManager = fillManager;
  this->pCacheMeshItem = 0i64;
  this->AllocTooBig = 0;
  *(_QWORD *)&this->VertexMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&this->VertexMatrix.M[0][2] = 0i64;
  this->VertexMatrix.M[1][0] = 0.0;
  *(_QWORD *)&this->VertexMatrix.M[1][1] = 1065353216i64;
  this->VertexMatrix.M[1][3] = 0.0;
  this->FillRecords.Data.Data = 0i64;
  this->FillRecords.Data.Size = 0i64;
  this->FillRecords.Data.Policy.Capacity = 0i64;
  this->FillMatrixCache.Data.Data = 0i64;
  this->FillMatrixCache.Data.Size = 0i64;
  this->FillMatrixCache.Data.Policy.Capacity = 0i64;
  this->GradientImages.Data.Data = 0i64;
  this->GradientImages.Data.Size = 0i64;
  this->GradientImages.Data.Policy.Capacity = 0i64;
}

// File Line: 774
// RVA: 0x9491E0
void __fastcall Scaleform::Render::ComplexMesh::~ComplexMesh(Scaleform::Render::ComplexMesh *this)
{
  Scaleform::Render::MeshCacheItem *pCacheMeshItem; // rdx
  Scaleform::Render::Scale9GridData *pObject; // rcx
  Scaleform::Render::MeshProvider *v4; // rcx

  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  if ( this->UpdateListNode.pPrev )
  {
    this->UpdateListNode.pPrev->pNext = this->UpdateListNode.pNext;
    this->UpdateListNode.pNext->pPrev = this->UpdateListNode.pPrev;
    this->UpdateListNode.pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    this->UpdateListNode.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
  }
  pCacheMeshItem = this->pCacheMeshItem;
  if ( pCacheMeshItem )
    ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, Scaleform::Render::ComplexMesh *, __int64))pCacheMeshItem->pCacheList->pCache->vfptr[4].__vecDelDtor)(
      pCacheMeshItem->pCacheList->pCache,
      pCacheMeshItem,
      0i64,
      this,
      -2i64);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>(&this->GradientImages.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->FillMatrixCache.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>(&this->FillRecords.Data);
  pObject = this->pScale9Grid.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount, 0xFFFFFFFF) == 1 )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v4 = this->pProvider.pObject;
  if ( v4 )
    v4->vfptr->Release(v4);
  this->Scaleform::Render::MeshBase::Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
  this->Scaleform::Render::MeshBase::Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 791
// RVA: 0x993160
char __fastcall Scaleform::Render::ComplexMesh::InitFillRecords(
        Scaleform::Render::ComplexMesh *this,
        Scaleform::Render::VertexOutput::Fill *fills,
        unsigned int fillRecordCount,
        Scaleform::Render::Matrix2x4<float> *vertexMatrix,
        Scaleform::Render::HAL *hal,
        unsigned __int64 *vbSize,
        unsigned int *vertexCount,
        unsigned int *indexCount)
{
  __int64 v9; // r14
  Scaleform::Render::TextureManager *textureManager; // rbx
  Scaleform::Render::ComplexMesh::UpdateNode *p_UpdateListNode; // r12
  Scaleform::Render::ComplexMesh::UpdateNode *pPrev; // rdx
  __int64 v15; // r15
  unsigned int *p_FillIndex0; // rsi
  Scaleform::Render::ComplexMesh::FillRecord *Data; // r14
  Scaleform::Render::PrimitiveFill *v18; // rbx
  Scaleform::Render::PrimitiveFill *pObject; // rcx
  Scaleform::Render::ComplexMesh::UpdateNode *p_mComplexMeshUpdateList; // rcx
  Scaleform::Ptr<Scaleform::Render::Image> *v22; // rbx
  Scaleform::Render::Image *v23; // rcx
  Scaleform::Ptr<Scaleform::Render::Image> *v24; // rbx
  Scaleform::Render::Image *v25; // rcx
  void (__fastcall *pDtor)(void *); // [rsp+20h] [rbp-A9h]
  Scaleform::Ptr<Scaleform::Render::Image> ptr; // [rsp+50h] [rbp-79h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> gradientImg1; // [rsp+58h] [rbp-71h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> *v30; // [rsp+60h] [rbp-69h]
  Scaleform::Render::TextureManager *v31; // [rsp+68h] [rbp-61h]
  Scaleform::Render::FillData fd0; // [rsp+70h] [rbp-59h] BYREF
  Scaleform::Render::FillData fd1; // [rsp+90h] [rbp-39h] BYREF
  Scaleform::Ptr<Scaleform::Render::Image> *v34; // [rsp+B0h] [rbp-19h]
  char v35[8]; // [rsp+B8h] [rbp-11h] BYREF
  __int64 v36; // [rsp+C0h] [rbp-9h]
  unsigned int v37; // [rsp+110h] [rbp+47h]

  v36 = -2i64;
  v9 = fillRecordCount;
  Scaleform::ArrayData<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FillRecords.Data,
    fillRecordCount);
  if ( this->FillRecords.Data.Size != v9 )
    return 0;
  textureManager = (Scaleform::Render::TextureManager *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))hal->vfptr[61].__vecDelDtor)(hal);
  v31 = textureManager;
  p_UpdateListNode = &this->UpdateListNode;
  pPrev = this->UpdateListNode.pPrev;
  if ( pPrev )
  {
    pPrev->pNext = this->UpdateListNode.pNext;
    this->UpdateListNode.pNext->pPrev = p_UpdateListNode->pPrev;
    p_UpdateListNode->pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    this->UpdateListNode.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    this->UpdateListNode.pNext = 0i64;
    p_UpdateListNode->pPrev = 0i64;
  }
  *vbSize = 0i64;
  *indexCount = 0;
  *vertexCount = 0;
  v37 = 0;
  if ( (_DWORD)v9 )
  {
    v15 = 0i64;
    p_FillIndex0 = &fills->FillIndex0;
    while ( 1 )
    {
      Data = this->FillRecords.Data.Data;
      fd0.Type = Fill_VColor;
      fd0.Color = 0;
      fd0.PrimFill = PrimFill_VColor_EAlpha;
      fd0.FillMode.Fill = 0;
      fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      fd1.Type = Fill_VColor;
      fd1.Color = 0;
      fd1.PrimFill = PrimFill_VColor_EAlpha;
      fd1.FillMode.Fill = 0;
      fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      pDtor = (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>;
      `eh vector constructor iterator(
        &ptr,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      LODWORD(pDtor) = this->MGFlags;
      this->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetFillData(
        this->pProvider.pObject,
        &fd0,
        this->Layer,
        *p_FillIndex0,
        (unsigned int)pDtor);
      if ( (p_FillIndex0[2] & 2) != 0 )
        this->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetFillData(
          this->pProvider.pObject,
          &fd1,
          this->Layer,
          p_FillIndex0[1],
          this->MGFlags);
      v18 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
              this->pFillManager,
              p_FillIndex0[2],
              *((Scaleform::Render::VertexFormat **)p_FillIndex0 - 1),
              &fd0,
              &fd1,
              &ptr,
              &gradientImg1,
              textureManager,
              this->MorphRatio);
      pObject = Data[v15].pFill.pObject;
      if ( pObject )
      {
        if ( pObject->RefCount-- == 1 )
          pObject->vfptr->__vecDelDtor(pObject, 1u);
      }
      Data[v15].pFill.pObject = v18;
      if ( !v18 )
        break;
      if ( !p_UpdateListNode->pPrev && (fd0.Type == Fill_Image || fd1.Type == Fill_Image) )
      {
        p_mComplexMeshUpdateList = (Scaleform::Render::ComplexMesh::UpdateNode *)&this->pRenderer2D->mComplexMeshUpdateList;
        p_UpdateListNode->pPrev = p_mComplexMeshUpdateList->pPrev;
        this->UpdateListNode.pNext = p_mComplexMeshUpdateList;
        p_mComplexMeshUpdateList->pPrev->pNext = p_UpdateListNode;
        p_mComplexMeshUpdateList->pPrev = p_UpdateListNode;
      }
      Data[v15].IndexOffset = *indexCount;
      Data[v15].IndexCount = *(p_FillIndex0 - 3);
      Data[v15].VertexByteOffset = *vbSize;
      Data[v15].VertexCount = *(p_FillIndex0 - 4);
      Data[v15].FillMatrixIndex[0] = *p_FillIndex0;
      Data[v15].FillMatrixIndex[1] = p_FillIndex0[1];
      Data[v15].MergeFlags = p_FillIndex0[2];
      if ( ptr.pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v22 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        v34 = v22;
        v30 = v22;
        if ( v22 )
        {
          v23 = ptr.pObject;
          if ( ptr.pObject )
          {
            ((void (__fastcall *)(Scaleform::Render::Image *))ptr.pObject->vfptr[1].__vecDelDtor)(ptr.pObject);
            v23 = ptr.pObject;
          }
          v22->pObject = v23;
        }
      }
      if ( gradientImg1.pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          &this->GradientImages.Data,
          &this->GradientImages,
          this->GradientImages.Data.Size + 1);
        v24 = &this->GradientImages.Data.Data[this->GradientImages.Data.Size - 1];
        v30 = v24;
        v34 = v24;
        if ( v24 )
        {
          v25 = gradientImg1.pObject;
          if ( gradientImg1.pObject )
          {
            ((void (__fastcall *)(Scaleform::Render::Image *))gradientImg1.pObject->vfptr[1].__vecDelDtor)(gradientImg1.pObject);
            v25 = gradientImg1.pObject;
          }
          v24->pObject = v25;
        }
      }
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, char *, Scaleform::Render::VertexFormat **, int))hal->vfptr[66].__vecDelDtor)(
        hal,
        (unsigned int)Data[v15].pFill.pObject->Data.Type,
        Data[v15].pFill.pObject->Data.pFormat,
        Data[v15].pFormats,
        v35,
        &Data[v15].pFormats[1],
        1);
      *vbSize += *(p_FillIndex0 - 4) * Data[v15].pFormats[0]->Size;
      *vertexCount += *(p_FillIndex0 - 4);
      *indexCount += *(p_FillIndex0 - 3);
      `eh vector destructor iterator(
        &ptr,
        8ui64,
        2,
        (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
      ++v37;
      p_FillIndex0 += 8;
      ++v15;
      textureManager = v31;
      if ( v37 >= fillRecordCount )
        goto LABEL_30;
    }
    `eh vector destructor iterator(
      &ptr,
      8ui64,
      2,
      (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
    return 0;
  }
LABEL_30:
  this->VertexMatrix.M[0][0] = vertexMatrix->M[0][0];
  this->VertexMatrix.M[0][1] = vertexMatrix->M[0][1];
  this->VertexMatrix.M[0][2] = vertexMatrix->M[0][2];
  this->VertexMatrix.M[0][3] = vertexMatrix->M[0][3];
  this->VertexMatrix.M[1][0] = vertexMatrix->M[1][0];
  this->VertexMatrix.M[1][1] = vertexMatrix->M[1][1];
  this->VertexMatrix.M[1][2] = vertexMatrix->M[1][2];
  this->VertexMatrix.M[1][3] = vertexMatrix->M[1][3];
  Scaleform::Render::ComplexMesh::updateFillMatrixCache(this, vertexMatrix);
  return 1;
}

// File Line: 875
// RVA: 0x9F9A10
void __fastcall Scaleform::Render::ComplexMesh::updateFillMatrixCache(
        Scaleform::Render::ComplexMesh *this,
        Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  unsigned __int64 v4; // rbp
  unsigned int v5; // r14d
  __int64 v6; // rbx
  __int64 v7; // r12
  Scaleform::Render::Matrix2x4<float> *Data; // rax
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4

  v4 = this->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetFillCount(
         this->pProvider.pObject,
         this->Layer,
         this->MGFlags);
  Scaleform::ArrayData<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FillMatrixCache.Data,
    v4);
  if ( this->FillMatrixCache.Data.Size == v4 )
  {
    v5 = 0;
    if ( (_DWORD)v4 )
    {
      v6 = 0i64;
      v7 = 0i64;
      do
      {
        this->pProvider.pObject->Scaleform::Render::MeshBase::vfptr->GetFillMatrix(
          this->pProvider.pObject,
          this,
          &this->FillMatrixCache.Data.Data[v7],
          this->Layer,
          v5,
          this->MGFlags);
        Data = this->FillMatrixCache.Data.Data;
        ++v5;
        ++v6;
        ++v7;
        v9 = Data[v6 - 1].M[0][0];
        v10 = Data[v6 - 1].M[0][1];
        v11 = Data[v6 - 1].M[1][0];
        v12 = Data[v6 - 1].M[1][1];
        Data[v6 - 1].M[0][0] = (float)(v10 * vertexMatrix->M[1][0]) + (float)(v9 * vertexMatrix->M[0][0]);
        Data[v6 - 1].M[1][0] = (float)(v12 * vertexMatrix->M[1][0]) + (float)(v11 * vertexMatrix->M[0][0]);
        Data[v6 - 1].M[0][1] = (float)(v10 * vertexMatrix->M[1][1]) + (float)(v9 * vertexMatrix->M[0][1]);
        v13 = v12 * vertexMatrix->M[1][1];
        v14 = v11 * vertexMatrix->M[0][1];
        Data[v6 - 1].M[1][2] = 0.0;
        Data[v6 - 1].M[0][2] = 0.0;
        Data[v6 - 1].M[1][1] = v13 + v14;
        Data[v6 - 1].M[0][3] = (float)((float)(v10 * vertexMatrix->M[1][3]) + (float)(v9 * vertexMatrix->M[0][3]))
                             + Data[v6 - 1].M[0][3];
        Data[v6 - 1].M[1][3] = (float)((float)(v12 * vertexMatrix->M[1][3]) + (float)(v11 * vertexMatrix->M[0][3]))
                             + Data[v6 - 1].M[1][3];
      }
      while ( v5 < (unsigned int)v4 );
    }
  }
}

// File Line: 942
// RVA: 0x96FEC0
void __fastcall Scaleform::Render::MaskPrimitive::EmitToHAL(
        Scaleform::Render::MaskPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
    qp->pHAL->vfptr[36].__vecDelDtor(qp->pHAL, (unsigned int)&this[-1].MaskAreas.Data.Size);
}

// File Line: 952
// RVA: 0x9394F0
void __fastcall Scaleform::Render::CacheablePrimitive::CacheablePrimitive(
        Scaleform::Render::CacheablePrimitive *this,
        bool masksPresent)
{
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // rbx
  __int64 v5; // rsi

  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::`vftable;
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  CacheResults = this->CacheResults;
  v5 = 2i64;
  `eh vector constructor iterator(
    this->CacheResults,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  this->PrimitiveArea.Data.Data = 0i64;
  this->PrimitiveArea.Data.Size = 0i64;
  this->PrimitiveArea.Data.Policy.Capacity = 0i64;
  this->MaskPresent = masksPresent;
  this->Caching = Cache_Mesh;
  do
  {
    if ( CacheResults->pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))CacheResults->pObject->vfptr[2].__vecDelDtor)(CacheResults->pObject);
    CacheResults->pObject = 0i64;
    ++CacheResults;
    --v5;
  }
  while ( v5 );
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
    this,
    0);
}

// File Line: 957
// RVA: 0x949040
void __fastcall Scaleform::Render::CacheablePrimitive::~CacheablePrimitive(Scaleform::Render::CacheablePrimitive *this)
{
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // rbx
  __int64 v3; // rdi

  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  CacheResults = this->CacheResults;
  v3 = 2i64;
  do
  {
    if ( CacheResults->pObject )
      ((void (__fastcall *)(Scaleform::Render::RenderTarget *))CacheResults->pObject->vfptr[2].__vecDelDtor)(CacheResults->pObject);
    CacheResults->pObject = 0i64;
    ++CacheResults;
    --v3;
  }
  while ( v3 );
  Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
    this->PrimitiveArea.Data.Data,
    this->PrimitiveArea.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->PrimitiveArea.Data.Data);
  `eh vector destructor iterator(
    this->CacheResults,
    8ui64,
    2,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 963
// RVA: 0x980A60
void __fastcall Scaleform::Render::CacheablePrimitive::GetCacheResults(
        Scaleform::Render::CacheablePrimitive *this,
        Scaleform::Render::RenderTarget **results,
        unsigned int count)
{
  unsigned int v3; // r9d
  signed __int64 v4; // rcx

  v3 = 0;
  if ( count )
  {
    v4 = (char *)this - (char *)results;
    do
    {
      *results = *(Scaleform::Render::RenderTarget **)((char *)results + v4 + 32);
      ++v3;
      ++results;
    }
    while ( v3 < count );
  }
}

// File Line: 974
// RVA: 0x9AE9F0
void __fastcall Scaleform::Render::CacheablePrimitive::SetCacheResults(
        Scaleform::Render::CacheablePrimitive *this,
        Scaleform::Render::CacheablePrimitive::CacheState state,
        Scaleform::Render::RenderTarget **results,
        unsigned int count)
{
  unsigned int v4; // esi
  signed __int64 v9; // r12
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *CacheResults; // rbx
  Scaleform::Render::RenderTarget *v11; // rdi

  v4 = 0;
  v9 = (char *)results - (char *)this;
  this->Caching = state;
  CacheResults = this->CacheResults;
  do
  {
    if ( v4 < count && results )
    {
      v11 = *(Scaleform::Render::RenderTarget **)((char *)&CacheResults[-4].pObject + v9);
      if ( v11 )
        ((void (__fastcall *)(_QWORD))v11->vfptr[1].__vecDelDtor)(*(Scaleform::Render::RenderTarget **)((char *)&CacheResults[-4].pObject + v9));
      if ( CacheResults->pObject )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))CacheResults->pObject->vfptr[2].__vecDelDtor)(CacheResults->pObject);
      CacheResults->pObject = v11;
    }
    else
    {
      if ( CacheResults->pObject )
        ((void (__fastcall *)(Scaleform::Render::RenderTarget *))CacheResults->pObject->vfptr[2].__vecDelDtor)(CacheResults->pObject);
      CacheResults->pObject = 0i64;
    }
    ++v4;
    ++CacheResults;
  }
  while ( v4 < 2 );
  if ( state == Cache_Mesh )
    this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
      this,
      0);
}

// File Line: 996
// RVA: 0x9A8880
void __fastcall Scaleform::Render::CacheablePrimitive::Remove(
        Scaleform::Render::CacheablePrimitive *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  unsigned __int64 i; // rbx

  for ( i = index; i < count; ++i )
    this->Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor(
      this,
      i);
  if ( this->PrimitiveArea.Data.Size == count )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->PrimitiveArea.Data,
      &this->PrimitiveArea,
      0i64);
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
      &this->PrimitiveArea.Data.Data[index],
      count);
    memmove(
      &this->PrimitiveArea.Data.Data[index],
      &this->PrimitiveArea.Data.Data[index + count],
      8 * (this->PrimitiveArea.Data.Size - index - count));
    this->PrimitiveArea.Data.Size -= count;
  }
}

// File Line: 1010
// RVA: 0x96FE50
void __fastcall Scaleform::Render::FilterPrimitive::EmitToHAL(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  bool v5; // zf
  Scaleform::Render::HAL *pHAL; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax

  if ( item != qp->EmitItemBuffer.pItem )
  {
    *(_OWORD *)&qp->EmitItemBuffer.pItem = (unsigned __int64)item;
    v5 = this->PrimitiveArea.Data.Policy.Capacity == 0;
    pHAL = qp->pHAL;
    vfptr = qp->pHAL->vfptr;
    if ( v5 )
      vfptr[48].__vecDelDtor(pHAL, (unsigned int)this);
    else
      vfptr[47].__vecDelDtor(pHAL, (unsigned int)&this[-1].MaskPresent);
  }
}

// File Line: 1024
// RVA: 0x99F760
__int64 __fastcall Scaleform::Render::FilterPrimitive::Prepare(
        Scaleform::Render::FilterPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp,
        __int64 a4)
{
  __int64 v6; // r8

  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *, bool *, Scaleform::Render::RenderQueueProcessor *, __int64))qp->pHAL->vfptr[74].__vecDelDtor)(
         qp->pHAL,
         &this[-1].MaskPresent,
         qp,
         a4) )
  {
    LOBYTE(v6) = this->PrimitiveArea.Data.Policy.Capacity == 0;
    ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, __int64))qp->pHAL->vfptr[46].__vecDelDtor)(
      qp->pHAL,
      &this[-1].MaskPresent,
      v6);
  }
  return 0i64;
}

// File Line: 1037
// RVA: 0x9F8180
void __fastcall Scaleform::Render::FilterPrimitive::uncachePrimitive(
        Scaleform::Render::FilterPrimitive *this,
        unsigned __int64 index)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // r8
  Scaleform::Render::Matrix2x4<float> *v6; // rdx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-28h] BYREF

  v4 = &this->PrimitiveArea.Data.Data[index];
  if ( v4->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    if ( (v4->pHandle->pHeader->Format & 2) != 0 )
    {
      pHeader = v4->pHandle->pHeader;
      if ( (pHeader->Format & 2) != 0 )
        v6 = (Scaleform::Render::Matrix2x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[1]
                                                           + 1];
      else
        v6 = &Scaleform::Render::Matrix2x4<float>::Identity;
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v4, v6);
    }
    v7 = &this->PrimitiveArea.Data.Data[index];
    memset(&m, 0, sizeof(m));
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(v7, &m, 1u);
  }
}

// File Line: 1055
// RVA: 0x96FD50
void __fastcall Scaleform::Render::BlendPrimitive::EmitToHAL(
        Scaleform::Render::BlendPrimitive *this,
        Scaleform::Render::RenderQueueItem *item,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  bool v5; // cc
  Scaleform::Render::HAL *pHAL; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax

  if ( item != qp->EmitItemBuffer.pItem )
  {
    *(_OWORD *)&qp->EmitItemBuffer.pItem = (unsigned __int64)item;
    v5 = SLODWORD(this->PrimitiveArea.Data.Policy.Capacity) < 20;
    pHAL = qp->pHAL;
    vfptr = qp->pHAL->vfptr;
    if ( v5 )
      vfptr[39].__vecDelDtor(pHAL, (unsigned int)&this[-1].MaskPresent);
    else
      vfptr[40].__vecDelDtor(pHAL, (unsigned int)this);
  }
}

// File Line: 1069
// RVA: 0x99F690
__int64 __fastcall Scaleform::Render::BlendPrimitive::Prepare(
        Scaleform::Render::BlendPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp,
        __int64 a4)
{
  unsigned int Capacity; // eax
  Scaleform::Render::HAL *pHAL; // rcx
  int v8; // ecx

  Capacity = this->PrimitiveArea.Data.Policy.Capacity;
  if ( Capacity == 21 )
  {
    pHAL = qp->pHAL;
    LOBYTE(qp) = 1;
    ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, Scaleform::Render::RenderQueueProcessor *, __int64))pHAL->vfptr[46].__vecDelDtor)(
      pHAL,
      &this[-1].MaskPresent,
      qp,
      a4);
    return 0i64;
  }
  else
  {
    if ( Capacity <= 0xE )
    {
      v8 = 24804;
      if ( _bittest(&v8, Capacity) )
        ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, _QWORD, __int64))qp->pHAL->vfptr[46].__vecDelDtor)(
          qp->pHAL,
          &this[-1].MaskPresent,
          0i64,
          a4);
    }
    return 0i64;
  }
}

// File Line: 1084
// RVA: 0x96FFC0
void __fastcall Scaleform::Render::ViewMatrix3DPrimitive::EmitToHAL(
        Scaleform::Render::ViewMatrix3DPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ViewMatrix.M[2][0]) )
    Scaleform::Render::HAL::PushView3D(
      qp->pHAL,
      (Scaleform::Render::Matrix3x4<float> *)&this->Scaleform::Render::RenderQueueItem::Interface);
  else
    Scaleform::Render::HAL::PopView3D(qp->pHAL);
}

// File Line: 1095
// RVA: 0x96FF10
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::EmitToHAL(
        Scaleform::Render::ProjectionMatrix3DPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ProjectionMatrix.M[3][0]) )
    Scaleform::Render::HAL::PushProj3D(
      qp->pHAL,
      (Scaleform::Render::Matrix4x4<float> *)&this->Scaleform::Render::RenderQueueItem::Interface);
  else
    Scaleform::Render::HAL::PopProj3D(qp->pHAL);
}

// File Line: 1106
// RVA: 0x96FFA0
void __fastcall Scaleform::Render::UserDataPrimitive::EmitToHAL(
        Scaleform::Render::UserDataPrimitive *this,
        Scaleform::Render::RenderQueueItem *__formal,
        Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rax

  vfptr = qp->pHAL->vfptr;
  if ( *(_QWORD *)&this->RefCount )
    ((void (*)(void))vfptr[72].__vecDelDtor)();
  else
    ((void (*)(void))vfptr[73].__vecDelDtor)();
}

