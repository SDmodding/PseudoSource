// File Line: 36
// RVA: 0x93F870
void __fastcall Scaleform::Render::Mesh::Mesh(Scaleform::Render::Mesh *this, Scaleform::Render::Renderer2DImpl *prenderer, Scaleform::Render::MeshProvider *provider, Scaleform::Render::Matrix2x4<float> *viewMatrix, float morphRatio, unsigned int layer, unsigned int meshGenFlags)
{
  Scaleform::Render::Mesh *v7; // rbx

  v7 = this;
  Scaleform::Render::MeshBase::MeshBase(
    (Scaleform::Render::MeshBase *)&this->vfptr,
    prenderer,
    provider,
    viewMatrix,
    morphRatio,
    layer,
    meshGenFlags);
  v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  v7->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  v7->CacheItems.Size = 0i64;
  *(_QWORD *)&v7->VertexMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&v7->VertexMatrix.M[0][2] = 0i64;
  v7->VertexMatrix.M[1][0] = 0.0;
  *(_QWORD *)&v7->VertexMatrix.M[1][1] = 1065353216i64;
  v7->VertexMatrix.M[1][3] = 0.0;
  v7->LargeMesh = 0;
}

// File Line: 40
// RVA: 0x94B4F0
void __fastcall Scaleform::Render::Mesh::~Mesh(Scaleform::Render::Mesh *this)
{
  Scaleform::Render::Mesh *v1; // rbx
  unsigned __int64 v2; // rsi
  Scaleform::Render::MeshCacheItem **v3; // rdi
  Scaleform::Render::Scale9GridData *v4; // rcx
  Scaleform::Render::MeshProvider *v5; // rcx
  signed __int64 v6; // [rsp+20h] [rbp-18h]

  v6 = -2i64;
  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::Mesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  v2 = this->CacheItems.Size;
  if ( v2 <= 2 )
    v3 = (Scaleform::Render::MeshCacheItem **)&this->CacheItems.8;
  else
    v3 = this->CacheItems.AD.pData;
  for ( ; v2; ++v3 )
  {
    --v2;
    if ( *v3 )
      ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, Scaleform::Render::Mesh *, signed __int64))(*v3)->pCacheList->pCache->vfptr[4].__vecDelDtor)(
        (*v3)->pCacheList->pCache,
        *v3,
        0i64,
        v1,
        v6);
  }
  if ( v1->StagingBufferSize )
  {
    v1->pPrev->pNext = v1->pNext;
    v1->pNext->pPrev = v1->pPrev;
    v1->pPrev = (Scaleform::Render::MeshStagingNode *)-1i64;
    v1->pNext = (Scaleform::Render::MeshStagingNode *)-1i64;
  }
  if ( v1->CacheItems.Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->CacheItems.AD.pData);
  v4 = v1->pScale9Grid.pObject;
  if ( v4 && _InterlockedExchangeAdd(&v4->RefCount, 0xFFFFFFFF) == 1 && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v5 = v1->pProvider.pObject;
  if ( v5 )
    ((void (__cdecl *)(Scaleform::Render::MeshProvider *))v5->vfptr->Release)(v5);
  v1->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 63
// RVA: 0x98E930
__int64 __fastcall Scaleform::Render::Mesh::GetUseStatus(Scaleform::Render::Mesh *this)
{
  unsigned __int64 v1; // rsi
  unsigned int v2; // ebx
  Scaleform::Render::MeshCacheItem **v3; // r14
  unsigned __int64 v4; // rdi
  int v5; // eax

  v1 = this->CacheItems.Size;
  v2 = 0;
  if ( v1 <= 2 )
    v3 = (Scaleform::Render::MeshCacheItem **)&this->CacheItems.8;
  else
    v3 = this->CacheItems.AD.pData;
  v4 = 0i64;
  if ( v1 )
  {
    do
    {
      v5 = ((__int64 (*)(void))v3[v4]->pCacheList->pCache->vfptr[3].UnlockBuffers)();
      if ( v5 > (signed int)v2 )
        v2 = v5;
      ++v4;
    }
    while ( v4 < v1 );
  }
  return v2;
}

// File Line: 149
// RVA: 0x94BF20
void __fastcall Scaleform::Render::PrimitiveFill::~PrimitiveFill(Scaleform::Render::PrimitiveFill *this)
{
  Scaleform::Render::PrimitiveFill *v1; // rbx
  Scaleform::Render::PrimitiveFillManager *v2; // rcx
  Scaleform::Render::PrimitiveFill *key; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::PrimitiveFill::`vftable;
  v2 = this->pManager;
  if ( v2 )
  {
    key = v1;
    Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::RemoveAlt<Scaleform::Render::PrimitiveFill *>(
      (Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *)&v2->FillSet.pTable,
      &key);
  }
  key = (Scaleform::Render::PrimitiveFill *)((char *)v1 + 16);
  `eh vector destructor iterator(
    v1->Data.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
}

// File Line: 157
// RVA: 0x997DC0
bool __fastcall Scaleform::Render::PrimitiveFill::IsSolid(Scaleform::Render::PrimitiveFillType type)
{
  return (unsigned int)type <= 2;
}

// File Line: 186
// RVA: 0x9DD2E0
Scaleform::Render::Image *__fastcall Scaleform::Render::PrimitiveFillManager::createGradientImage(Scaleform::Render::PrimitiveFillManager *this, Scaleform::Render::GradientData *data, float morphRatio)
{
  Scaleform::Render::GradientData *v3; // rsi
  Scaleform::Render::PrimitiveFillManager *v4; // rbx
  Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rbx
  Scaleform::Render::GradientImage *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r11
  unsigned __int64 v11; // r9
  unsigned __int8 *v12; // r8
  __int64 v13; // r10
  Scaleform::Render::GradientKey key; // [rsp+28h] [rbp-40h]
  Scaleform::Render::GradientImage *v16; // [rsp+70h] [rbp+8h]
  Scaleform::Render::GradientImage *v17; // [rsp+78h] [rbp+10h]
  unsigned int v18; // [rsp+80h] [rbp+18h]

  v16 = (Scaleform::Render::GradientImage *)this;
  v3 = data;
  v4 = this;
  key.pData = data;
  key.MorphRatio = morphRatio;
  v5 = (Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *)&this->Gradients.pTable;
  v6 = Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::findIndexAlt<Scaleform::Render::GradientKey>(
         (Scaleform::HashSetBase<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor> > *)&this->Gradients.pTable,
         &key);
  if ( v6 < 0 )
  {
    v18 = 3;
    v8 = (Scaleform::Render::GradientImage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::PrimitiveFillManager *, signed __int64, unsigned int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                               Scaleform::Memory::pGlobalHeap,
                                               v4,
                                               72i64,
                                               &v18,
                                               -2i64);
    v17 = v8;
    if ( v8 )
    {
      Scaleform::Render::GradientImage::GradientImage(v8, v4, v3, morphRatio);
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
      v5,
      v5,
      &v16,
      v11);
  }
  else
  {
    v7 = *(&v5->pTable[2].EntryCount + 3 * v6);
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v7 + 8i64))(*(&v5->pTable[2].EntryCount + 3 * v6));
  }
  return (Scaleform::Render::Image *)v7;
}

// File Line: 203
// RVA: 0x966610
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateFill(Scaleform::Render::PrimitiveFillManager *this, Scaleform::Render::PrimitiveFillData *initdata)
{
  Scaleform::Render::PrimitiveFillData *v2; // rbx
  Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> >::TableType *v3; // rdx
  Scaleform::Render::PrimitiveFillManager *v4; // rsi
  signed __int64 v5; // rax
  Scaleform::Render::PrimitiveFill *result; // rax
  Scaleform::Render::PrimitiveFill *v7; // rbx
  Scaleform::Render::PrimitiveFill *key; // [rsp+30h] [rbp+8h]

  v2 = initdata;
  v3 = this->FillSet.pTable;
  v4 = this;
  if ( v3
    && (v5 = Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::findIndexCore<Scaleform::Render::PrimitiveFillData>(
               (Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *)&this->FillSet.pTable,
               v2,
               v3->SizeMask & ((unsigned int)v2->Type ^ (_QWORD)v2->Textures[1].pObject ^ v2->SolidColor.Raw ^ ((_QWORD)v2->Textures[0].pObject >> 2) ^ v2->pFormat->Size ^ (unsigned __int64)(4 * ((unsigned __int8)v2->FillModes[0].Fill ^ 4 * (unsigned int)(unsigned __int8)v2->FillModes[1].Fill)))),
        v5 >= 0) )
  {
    result = (Scaleform::Render::PrimitiveFill *)*(&v4->FillSet.pTable[2].EntryCount + 3 * v5);
    ++result->RefCount;
  }
  else
  {
    result = (Scaleform::Render::PrimitiveFill *)v4->pHAL->vfptr[28].__vecDelDtor(
                                                   (Scaleform::RefCountImplCore *)&v4->pHAL->vfptr,
                                                   (unsigned int)v2);
    v7 = result;
    key = result;
    if ( result )
    {
      Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor>>::add<Scaleform::Render::PrimitiveFill *>(
        (Scaleform::HashSetBase<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::Render::PrimitiveFill::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::PrimitiveFill *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::PrimitiveFill *,Scaleform::Render::PrimitiveFill::PtrHashFunctor> > *)&v4->FillSet.pTable,
        &v4->FillSet,
        &key,
        (unsigned int)result->Data.Type ^ (_QWORD)result->Data.Textures[1].pObject ^ result->Data.SolidColor.Raw ^ ((_QWORD)result->Data.Textures[0].pObject >> 2) ^ result->Data.pFormat->Size ^ (unsigned __int64)(4 * ((unsigned __int8)result->Data.FillModes[0].Fill ^ 4 * (unsigned int)(unsigned __int8)result->Data.FillModes[1].Fill)));
      v7->pManager = v4;
      result = v7;
    }
  }
  return result;
}

// File Line: 222
// RVA: 0x966730
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateFill(Scaleform::Render::PrimitiveFillManager *this, Scaleform::Render::FillData *initdata, Scaleform::Ptr<Scaleform::Render::Image> *gradientImg, Scaleform::Render::TextureManager *mng)
{
  Scaleform::Render::TextureManager *v4; // r15
  Scaleform::Ptr<Scaleform::Render::Image> *v5; // rsi
  Scaleform::Render::FillData *v6; // rdi
  Scaleform::Render::PrimitiveFillManager *v7; // r14
  Scaleform::Render::VertexFormat *v8; // rbx
  Scaleform::Render::PrimitiveFill *v9; // rbx
  Scaleform::Ptr<Scaleform::Render::Texture> *v10; // rcx
  Scaleform::Render::PrimitiveFill *result; // rax
  unsigned int v12; // eax
  Scaleform::Render::VertexFormat *v13; // rbx
  Scaleform::Render::VertexFormat *v14; // rbx
  Scaleform::Render::GradientData *v15; // rcx
  Scaleform::Render::Texture *v16; // r9
  char v17; // cl
  Scaleform::Render::VertexFormat *v18; // rbx
  Scaleform::Render::Image *v19; // rbx
  Scaleform::Render::Texture *v20; // rax
  Scaleform::Render::ImageFillMode fm0[8]; // [rsp+28h] [rbp-21h]
  Scaleform::Render::ImageFillMode fm1[8]; // [rsp+30h] [rbp-19h]
  Scaleform::Render::PrimitiveFillData initdataa; // [rsp+38h] [rbp-11h]
  Scaleform::Render::PrimitiveFillData v24; // [rsp+60h] [rbp+17h]
  Scaleform::Render::ImageFillMode vars0; // [rsp+B0h] [rbp+67h]
  float v26; // [rsp+C8h] [rbp+7Fh]

  *(_QWORD *)&fm1[0].Fill = -2i64;
  v4 = mng;
  v5 = gradientImg;
  v6 = initdata;
  v7 = this;
  switch ( initdata->Type )
  {
    case 1:
      v8 = initdata->pVFormat;
      *(_QWORD *)&initdataa.Type = 1i64;
      *(_WORD *)&initdataa.FillModes[0].Fill = 0;
      `eh vector constructor iterator(
        initdataa.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdataa.pFormat = v8;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &initdataa);
      goto LABEL_3;
    case 2:
      v12 = initdata->Color;
      v13 = initdata->pVFormat;
      initdataa.Type = 2;
      initdataa.SolidColor.Raw = v12;
      *(_WORD *)&initdataa.FillModes[0].Fill = 0;
      `eh vector constructor iterator(
        initdataa.Textures,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      initdataa.pFormat = v13;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &initdataa);
      goto LABEL_3;
    case 3:
    case 6:
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
      if ( v6->Type == 6 )
        initdataa.SolidColor.Raw = v6->Color;
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &initdataa);
      goto LABEL_3;
    case 4:
      v15 = initdata->pGradient;
      if ( v15
        && (v16 = (Scaleform::Render::Texture *)v15->vfptr[21].__vecDelDtor(
                                                  (Scaleform::RefCountImplCore *)&v15->vfptr,
                                                  (unsigned int)mng)) != 0i64 )
      {
        vars0.Fill = 0;
        v17 = v6->FillMode.Fill;
        Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
          &v24,
          v6->PrimFill,
          v6->pVFormat,
          v16,
          (__int64)fm0,
          0i64,
          (__int64)&vars0);
        v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &v24);
LABEL_12:
        v10 = v24.Textures;
      }
      else
      {
        v18 = v6->pVFormat;
        initdataa.Type = 2;
        initdataa.SolidColor.Raw = -65536;
        *(_WORD *)&initdataa.FillModes[0].Fill = 0;
        `eh vector constructor iterator(
          initdataa.Textures,
          8ui64,
          2,
          (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
        initdataa.pFormat = v18;
        v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &initdataa);
LABEL_3:
        v10 = initdataa.Textures;
      }
      `eh vector destructor iterator(
        v10,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::StereoImplBase>::~Ptr<Scaleform::Render::StereoImplBase>);
      result = v9;
      break;
    case 5:
      v19 = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, initdata->pGradient, v26);
      if ( v5->pObject )
        ((void (*)(void))v5->pObject->vfptr[2].__vecDelDtor)();
      v5->pObject = v19;
      if ( !v19 )
        goto LABEL_18;
      vars0.Fill = 0;
      fm0[0] = v6->FillMode;
      v20 = (Scaleform::Render::Texture *)v19->vfptr[21].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)&v19->vfptr,
                                            (unsigned int)v4);
      Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        &v24,
        v6->PrimFill,
        v6->pVFormat,
        v20,
        (__int64)fm0,
        0i64,
        (__int64)&vars0);
      v9 = Scaleform::Render::PrimitiveFillManager::CreateFill(v7, &v24);
      goto LABEL_12;
    default:
LABEL_18:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 357
// RVA: 0x967C60
Scaleform::Render::PrimitiveFill *__fastcall Scaleform::Render::PrimitiveFillManager::CreateMergedFill(Scaleform::Render::PrimitiveFillManager *this, unsigned int mergeFlags, Scaleform::Render::VertexFormat *vformat, Scaleform::Render::FillData *fd0, Scaleform::Render::FillData *fd1, Scaleform::Ptr<Scaleform::Render::Image> *gradientImg0, Scaleform::Ptr<Scaleform::Render::Image> *gradientImg1, Scaleform::Render::TextureManager *textureManager, float morphRatio)
{
  Scaleform::Render::FillData *v9; // r14
  Scaleform::Render::VertexFormat *v10; // r13
  unsigned int v11; // ebx
  Scaleform::Render::PrimitiveFillManager *v12; // rax
  Scaleform::Render::FillType v13; // esi
  Scaleform::Render::FillType v14; // edi
  Scaleform::Render::Image *v15; // rbp
  Scaleform::Render::Image *v16; // r15
  Scaleform::Render::FillTypeMergeInfo *v17; // rcx
  unsigned __int8 v18; // al
  int v19; // ebx
  Scaleform::Render::PrimitiveFill *v20; // rdi
  __int64 v21; // rax
  Scaleform::Render::Texture *v22; // rdi
  Scaleform::Render::Texture *v23; // rcx
  __int64 v24; // rax
  Scaleform::Render::Texture *v25; // rdi
  Scaleform::Render::Texture *v26; // rcx
  Scaleform::Render::PrimitiveFillData initdata; // [rsp+38h] [rbp-50h]
  Scaleform::Render::PrimitiveFillManager *v29; // [rsp+90h] [rbp+8h]

  v29 = this;
  v9 = fd0;
  v10 = vformat;
  v11 = mergeFlags;
  v12 = this;
  v13 = fd0->Type;
  v14 = fd1->Type;
  v15 = fd0->pImage;
  v16 = fd1->pImage;
  if ( fd0->Type == 5 )
  {
    v15 = Scaleform::Render::PrimitiveFillManager::createGradientImage(this, fd0->pGradient, morphRatio);
    if ( gradientImg0->pObject )
      ((void (*)(void))gradientImg0->pObject->vfptr[2].__vecDelDtor)();
    gradientImg0->pObject = v15;
    v13 = 4;
    v12 = v29;
  }
  if ( v14 == 5 )
  {
    v16 = Scaleform::Render::PrimitiveFillManager::createGradientImage(v12, fd1->pGradient, morphRatio);
    if ( gradientImg1->pObject )
      ((void (*)(void))gradientImg1->pObject->vfptr[2].__vecDelDtor)();
    gradientImg1->pObject = v16;
    v14 = 4;
  }
  if ( v13 == 6 )
    v13 = 3;
  if ( v14 == 6 )
    v14 = 3;
  v17 = FillTypeMergeTable;
  v18 = FillTypeMergeTable[0].F0;
  do
  {
    if ( v18 == v13 && v11 == (unsigned __int8)v17->MergeFlags && ((unsigned __int8)v17->F1 == v14 || !(v11 & 2)) )
      break;
    ++v17;
    v18 = v17->F0;
  }
  while ( v17->F0 );
  v19 = (unsigned __int8)v17->Result;
  initdata.Type = (unsigned __int8)v17->Result;
  v20 = 0i64;
  initdata.SolidColor.Raw = 0;
  *(_WORD *)&initdata.FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    initdata.Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  initdata.pFormat = v10;
  switch ( v19 )
  {
    case 1:
      goto $LN8_109;
    case 2:
      initdata.SolidColor.Raw = v9->Color;
      goto $LN8_109;
    case 3:
    case 4:
      if ( v9->Type == 6 )
        initdata.SolidColor.Raw = v9->Color;
      goto $LN8_109;
    case 5:
    case 6:
    case 7:
    case 8:
      goto LABEL_30;
    case 9:
    case 10:
      v21 = (__int64)v16->vfptr[21].__vecDelDtor(
                       (Scaleform::RefCountImplCore *)&v16->vfptr,
                       (unsigned int)textureManager);
      v22 = (Scaleform::Render::Texture *)v21;
      if ( v21 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v21 + 8), 1u);
      v23 = initdata.Textures[1].pObject;
      if ( initdata.Textures[1].pObject && !_InterlockedDecrement(&initdata.Textures[1].pObject->RefCount) && v23 )
        v23->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v23->vfptr, 1u);
      initdata.Textures[1].pObject = v22;
      initdata.FillModes[1].Fill = fd1->FillMode.Fill;
LABEL_30:
      v24 = (__int64)v15->vfptr[21].__vecDelDtor(
                       (Scaleform::RefCountImplCore *)&v15->vfptr,
                       (unsigned int)textureManager);
      v25 = (Scaleform::Render::Texture *)v24;
      if ( v24 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v24 + 8), 1u);
      v26 = initdata.Textures[0].pObject;
      if ( initdata.Textures[0].pObject && !_InterlockedDecrement(&initdata.Textures[0].pObject->RefCount) && v26 )
        v26->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v26->vfptr, 1u);
      initdata.Textures[0].pObject = v25;
      initdata.FillModes[0].Fill = v9->FillMode.Fill;
$LN8_109:
      v20 = Scaleform::Render::PrimitiveFillManager::CreateFill(v29, &initdata);
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
void __fastcall Scaleform::Render::Primitive::Primitive(Scaleform::Render::Primitive *this, Scaleform::Render::HAL *phal, Scaleform::Render::PrimitiveFill *pfill)
{
  Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *v3; // rax
  Scaleform::Render::PrimitiveFillType v4; // edx
  char v5; // al
  Scaleform::ArrayLH<Scaleform::Render::Primitive::MeshEntry,2,Scaleform::ArrayDefaultPolicy> *v6; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Primitive,67>::`vftable;
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->pHAL = phal;
  if ( pfill )
    ++pfill->RefCount;
  this->pFill.pObject = pfill;
  v3 = &this->Batches;
  v3->Root.pPrev = (Scaleform::Render::PrimitiveBatch *)v3;
  v3->Root.pNext = (Scaleform::Render::PrimitiveBatch *)v3;
  v4 = pfill->Data.Type;
  if ( (unsigned int)(v4 - 5) > 5 )
    v5 = 0;
  else
    v5 = ((unsigned int)(v4 - 9) <= 1) + 1;
  this->MatricesPerMesh = v5 + 1;
  v6 = &this->Meshes;
  *(_OWORD *)&v6->Data.Data = 0ui64;
  v6->Data.Policy.Capacity = 0i64;
  this->ModifyIndex = 0;
  ++Primitive_CreateCount;
  ++Primitive_Total;
}

// File Line: 497
// RVA: 0x94BDF0
void __fastcall Scaleform::Render::Primitive::~Primitive(Scaleform::Render::Primitive *this)
{
  Scaleform::Render::Primitive *v1; // rdi
  char **v2; // rbx
  Scaleform::Render::PrimitiveBatch *v3; // rdx
  Scaleform::Render::PrimitiveFill *v4; // rcx
  bool v5; // zf

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,67>};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::Primitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  --Primitive_Total;
  v2 = (char **)&this->Batches;
  if ( (Scaleform::List<Scaleform::Render::PrimitiveBatch,Scaleform::Render::PrimitiveBatch> *)this->Batches.Root.pNext != &this->Batches )
  {
    do
    {
      v3 = v1->Batches.Root.pNext;
      v3->pPrev->pNext = v3->pNext;
      v3->pNext->pPrev = v3->pPrev;
      v3->pPrev = (Scaleform::Render::PrimitiveBatch *)-1i64;
      v3->pNext = (Scaleform::Render::PrimitiveBatch *)-1i64;
      if ( v3->MeshNode.pMeshItem )
      {
        v3->MeshNode.pPrev->pNext = v3->MeshNode.pNext;
        v3->MeshNode.pNext->pPrev = v3->MeshNode.pPrev;
        v3->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v3->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v3->MeshNode.pMeshItem = 0i64;
      }
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    while ( v2[1] != (char *)v2 );
  }
  Scaleform::ConstructorMov<Scaleform::Render::Primitive::MeshEntry>::DestructArray(
    v1->Meshes.Data.Data,
    v1->Meshes.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Meshes.Data.Data);
  v4 = v1->pFill.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
  }
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 506
// RVA: 0x9944E0
char __fastcall Scaleform::Render::Primitive::Insert(Scaleform::Render::Primitive *this, unsigned int index, Scaleform::Render::Mesh *pmesh, Scaleform::Render::MatrixPoolImpl::HMatrix *m)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r13
  Scaleform::Render::Mesh *v5; // r12
  unsigned __int64 v6; // r14
  Scaleform::Render::Primitive *v7; // rbp
  Scaleform::Render::PrimitiveBatch *v8; // rsi
  Scaleform::Render::PrimitiveBatch *v9; // rbx
  int v10; // edi
  __int64 v11; // rax
  __int64 v12; // r8
  unsigned int v13; // ecx
  __int64 v14; // rax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v15; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v16; // rbx
  bool v17; // zf
  __int64 v18; // rcx
  Scaleform::Render::Primitive::MeshEntry val; // [rsp+28h] [rbp-40h]

  v4 = m;
  v5 = pmesh;
  v6 = index;
  v7 = this;
  v8 = 0i64;
  v9 = this->Batches.Root.pNext;
  v10 = 0;
  v11 = ((__int64 (__cdecl *)(Scaleform::Render::HAL *))this->pHAL->vfptr[62].__vecDelDtor)(this->pHAL);
  v12 = (*(__int64 (**)(void))(*(_QWORD *)(v11 + 8) + 16i64))();
  while ( 1 )
  {
    if ( v10 == (_DWORD)v6 )
    {
      if ( v8 && v8->Type == 3 )
      {
        ++v8->MeshCount;
        goto LABEL_17;
      }
      if ( v9 == (Scaleform::Render::PrimitiveBatch *)&v7->Batches || v9->Type != 3 )
      {
        v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::Primitive *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                v7,
                80i64);
        *(_QWORD *)(v14 + 32) = 0i64;
        *(_DWORD *)(v14 + 40) = 3;
        *(_QWORD *)(v14 + 48) = 0i64;
        *(_BYTE *)(v14 + 56) = 0;
        *(_QWORD *)(v14 + 64) = v7;
        *(_DWORD *)(v14 + 72) = 1;
        *(_DWORD *)(v14 + 76) = v10;
        *(_QWORD *)(v14 + 8) = v9->pNext->pPrev;
        *(_QWORD *)v14 = v9->pPrev;
        v9->pPrev->pNext = (Scaleform::Render::PrimitiveBatch *)v14;
        v9->pPrev = (Scaleform::Render::PrimitiveBatch *)v14;
        goto LABEL_17;
      }
    }
    if ( v9 == (Scaleform::Render::PrimitiveBatch *)&v7->Batches )
      goto LABEL_17;
    v13 = v9->MeshCount;
    if ( (signed int)v6 - v10 < v13 )
      break;
    v10 += v13;
    v8 = v9;
    v9 = v9->pNext;
  }
  ++v9->MeshCount;
  if ( v9->Type != 2 || v7->Meshes.Data.Data[v10].pMesh.pObject != v5 || v9->MeshCount > *(_DWORD *)(v12 + 48) )
  {
    v9->Type = 3;
    if ( v9->MeshNode.pMeshItem )
    {
      v9->MeshNode.pPrev->pNext = v9->MeshNode.pNext;
      v9->MeshNode.pNext->pPrev = v9->MeshNode.pPrev;
      v9->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v9->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v9->MeshNode.pMeshItem = 0i64;
    }
  }
LABEL_17:
  v15 = v4->pHandle;
  val.M.pHandle = v15;
  if ( v15 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v15->pHeader->RefCount;
  if ( v5 )
    _InterlockedExchangeAdd(&v5->RefCount, 1u);
  val.pMesh.pObject = v5;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,Scaleform::AllocatorLH<Scaleform::Render::ComplexPrimitiveBundle::InstanceEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v7->Meshes.Data,
    v6,
    &val);
  if ( (unsigned int)v6 < v7->ModifyIndex )
    v7->ModifyIndex = v6;
  ++Primitive_Insert;
  if ( val.pMesh.pObject && _InterlockedExchangeAdd(&val.pMesh.pObject->RefCount, 0xFFFFFFFF) == 1 )
    val.pMesh.pObject->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)val.pMesh.pObject, 1u);
  if ( val.M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v16 = val.M.pHandle->pHeader;
    v17 = val.M.pHandle->pHeader->RefCount == 1;
    --v16->RefCount;
    if ( v17 )
    {
      v18 = v16->DataPageOffset;
      *(_WORD *)((char *)&v16[1].RefCount + v18 + 2) += 16 * (unsigned __int8)v16->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v16[1].pHandle + v18))[5].pHeader += (unsigned __int8)v16->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v16->pHandle);
      v16->pHandle = 0i64;
    }
  }
  return 1;
}

// File Line: 588
// RVA: 0x9A89C0
void __fastcall Scaleform::Render::Primitive::Remove(Scaleform::Render::Primitive *this, unsigned int index, unsigned int count)
{
  Scaleform::Render::PrimitiveBatch *v3; // rbx
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // rbp
  Scaleform::Render::Primitive *v6; // r14
  unsigned int v7; // esi
  int v8; // edi
  unsigned int v9; // er9
  Scaleform::Render::PrimitiveBatch *v10; // r8
  $562A4EA56C1311C603F27EF2D0BF37C2 *v11; // rdx
  Scaleform::Render::PrimitiveBatch *v12; // rcx
  unsigned int v13; // edx
  bool v14; // zf

  v3 = this->Batches.Root.pNext;
  v4 = count;
  v5 = index;
  v6 = this;
  v7 = count;
  v8 = 0;
  while ( 1 )
  {
    v9 = v3->MeshCount;
    if ( (signed int)v5 - v8 < v9 )
      break;
    v8 += v9;
LABEL_15:
    v3 = v3->pNext;
LABEL_16:
    if ( !v7 || v3 == (Scaleform::Render::PrimitiveBatch *)&v6->Batches )
      goto LABEL_22;
  }
  if ( (_DWORD)v5 != v8 )
  {
    v13 = v7;
    if ( v7 > v8 + v9 - (unsigned int)v5 )
      v13 = v8 + v9 - v5;
    v14 = v3->Type == 2;
    v3->MeshCount = v9 - v13;
    if ( !v14 )
    {
      v3->Type = 3;
      if ( v3->MeshNode.pMeshItem )
      {
        v3->MeshNode.pPrev->pNext = v3->MeshNode.pNext;
        v3->MeshNode.pNext->pPrev = v3->MeshNode.pPrev;
        v3->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v3->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
        v3->MeshNode.pMeshItem = 0i64;
      }
    }
    v7 -= v13;
    v8 += v3->MeshCount;
    goto LABEL_15;
  }
  if ( v7 >= v9 )
  {
    v10 = v3;
    v11 = &v3->8;
    v7 -= v9;
    v12 = v3->pPrev;
    v3 = v3->pNext;
    v12->pNext = v3;
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
  v3->MeshCount -= v7;
  if ( v3->Type != 2 )
  {
    v3->Type = 3;
    if ( v3->MeshNode.pMeshItem )
    {
      v3->MeshNode.pPrev->pNext = v3->MeshNode.pNext;
      v3->MeshNode.pNext->pPrev = v3->MeshNode.pPrev;
      v3->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v3->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v3->MeshNode.pMeshItem = 0i64;
    }
  }
LABEL_22:
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveMultipleAt(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Primitive::MeshEntry,Scaleform::AllocatorLH<Scaleform::Render::Primitive::MeshEntry,2>,Scaleform::ArrayDefaultPolicy> > *)&v6->Meshes.Data,
    v5,
    v4);
  if ( (unsigned int)v5 < v6->ModifyIndex )
    v6->ModifyIndex = v5;
}

// File Line: 662
// RVA: 0x9B1D10
void __fastcall Scaleform::Render::Primitive::SetMesh(Scaleform::Render::Primitive *this, unsigned int index, Scaleform::Render::Mesh *pmesh)
{
  Scaleform::Render::Mesh *v3; // rbx
  unsigned int v4; // edi
  Scaleform::Render::Primitive *v5; // rbp
  Scaleform::Render::Primitive::MeshEntry *v6; // rsi
  Scaleform::Render::Mesh *v7; // rcx
  Scaleform::Render::PrimitiveBatch *v8; // rax
  int v9; // er8

  v3 = pmesh;
  v4 = index;
  v5 = this;
  v6 = &this->Meshes.Data.Data[index];
  if ( v6->pMesh.pObject != pmesh )
  {
    if ( pmesh )
      _InterlockedExchangeAdd(&pmesh->RefCount, 1u);
    v7 = v6->pMesh.pObject;
    if ( v7 && !_InterlockedDecrement(&v7->RefCount) && v7 )
      v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
    v6->pMesh.pObject = v3;
    v8 = v5->Batches.Root.pNext;
    v9 = 0;
    if ( v4 >= v8->MeshCount )
    {
      do
      {
        v9 += v8->MeshCount;
        v8 = v8->pNext;
      }
      while ( v4 >= v9 + v8->MeshCount );
    }
    v8->Type = 3;
    if ( v8->MeshNode.pMeshItem )
    {
      v8->MeshNode.pPrev->pNext = v8->MeshNode.pNext;
      v8->MeshNode.pNext->pPrev = v8->MeshNode.pPrev;
      v8->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v8->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
      v8->MeshNode.pMeshItem = 0i64;
    }
  }
}

// File Line: 737
// RVA: 0x9A9430
void __fastcall Scaleform::Render::PrimitiveBatch::RemoveAndFree(Scaleform::Render::PrimitiveBatch *this)
{
  this->pPrev->pNext = this->pNext;
  this->pNext->pPrev = this->pPrev;
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
void __fastcall Scaleform::Render::PrimitiveBatch::CalcMeshSizes(Scaleform::Render::PrimitiveBatch *this, unsigned int *ptotalVertices, unsigned int *ptotalIndices)
{
  Scaleform::Render::Primitive *v3; // r10
  unsigned int *v4; // rdi
  unsigned int *v5; // rsi
  unsigned int v6; // er9
  Scaleform::Render::PrimitiveBatch *v7; // rbx
  Scaleform::Render::PrimitiveBatch *i; // rax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  unsigned int v11; // er9
  unsigned int v12; // er8
  __int64 v13; // r10
  __int64 v14; // rax
  Scaleform::Render::Mesh *v15; // rcx

  v3 = this->pPrimitive;
  v4 = ptotalIndices;
  v5 = ptotalVertices;
  v6 = v3->Meshes.Data.Size;
  v7 = this;
  if ( v3->ModifyIndex < v6 )
  {
    for ( i = v3->Batches.Root.pPrev; i != (Scaleform::Render::PrimitiveBatch *)&v3->Batches; i = i->pPrev )
    {
      v6 -= i->MeshCount;
      i->MeshIndex = v6;
      if ( v6 < v3->ModifyIndex )
        break;
    }
    v3->ModifyIndex = v3->Meshes.Data.Size;
  }
  if ( this->Type == 2 )
    v9 = 1;
  else
    v9 = this->MeshCount;
  v10 = 0;
  v11 = 0;
  if ( v9 )
  {
    v12 = v7->MeshIndex;
    v13 = v9;
    do
    {
      v14 = v12++;
      v15 = v7->pPrimitive->Meshes.Data.Data[v14].pMesh.pObject;
      v10 += v15->VertexCount;
      v11 += v15->IndexCount;
      --v13;
    }
    while ( v13 );
    *v5 = v10;
    *v4 = v11;
  }
  else
  {
    *v5 = 0;
    *ptotalIndices = 0;
  }
}

// File Line: 771
// RVA: 0x939780
void __fastcall Scaleform::Render::ComplexMesh::ComplexMesh(Scaleform::Render::ComplexMesh *this, Scaleform::Render::Renderer2DImpl *renderer, Scaleform::Render::MeshProvider *meshProvider, Scaleform::Render::PrimitiveFillManager *fillManager, Scaleform::Render::Matrix2x4<float> *viewMatrix, float morphRatio, unsigned int layer, unsigned int meshGenFlags)
{
  Scaleform::Render::PrimitiveFillManager *v8; // rbx
  Scaleform::Render::ComplexMesh *v9; // rdi
  signed __int64 v10; // [rsp+78h] [rbp+20h]
  signed __int64 v11; // [rsp+78h] [rbp+20h]
  signed __int64 v12; // [rsp+78h] [rbp+20h]

  v8 = fillManager;
  v9 = this;
  Scaleform::Render::MeshBase::MeshBase(
    (Scaleform::Render::MeshBase *)&this->vfptr,
    renderer,
    meshProvider,
    viewMatrix,
    morphRatio,
    layer,
    meshGenFlags);
  v9->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  v9->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  v9->UpdateListNode.pPrev = 0i64;
  v9->UpdateListNode.pNext = 0i64;
  v9->pFillManager = v8;
  v9->pCacheMeshItem = 0i64;
  v9->AllocTooBig = 0;
  *(_QWORD *)&v9->VertexMatrix.M[0][0] = 1065353216i64;
  *(_QWORD *)&v9->VertexMatrix.M[0][2] = 0i64;
  v9->VertexMatrix.M[1][0] = 0.0;
  *(_QWORD *)&v9->VertexMatrix.M[1][1] = 1065353216i64;
  v9->VertexMatrix.M[1][3] = 0.0;
  v10 = (signed __int64)&v9->FillRecords;
  *(_OWORD *)v10 = 0ui64;
  *(_QWORD *)(v10 + 16) = 0i64;
  v11 = (signed __int64)&v9->FillMatrixCache;
  *(_OWORD *)v11 = 0ui64;
  *(_QWORD *)(v11 + 16) = 0i64;
  v12 = (signed __int64)&v9->GradientImages;
  *(_OWORD *)v12 = 0ui64;
  *(_QWORD *)(v12 + 16) = 0i64;
}

// File Line: 774
// RVA: 0x9491E0
void __fastcall Scaleform::Render::ComplexMesh::~ComplexMesh(Scaleform::Render::ComplexMesh *this)
{
  Scaleform::Render::ComplexMesh *v1; // rbx
  Scaleform::Render::MeshCacheItem *v2; // rdx
  Scaleform::Render::Scale9GridData *v3; // rcx
  Scaleform::Render::MeshProvider *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::ComplexMesh::`vftable{for `Scaleform::Render::MeshStagingNode};
  if ( this->UpdateListNode.pPrev )
  {
    this->UpdateListNode.pPrev->pNext = this->UpdateListNode.pNext;
    this->UpdateListNode.pNext->pPrev = this->UpdateListNode.pPrev;
    this->UpdateListNode.pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    this->UpdateListNode.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
  }
  v2 = this->pCacheMeshItem;
  if ( v2 )
    ((void (__fastcall *)(Scaleform::Render::MeshCache *, Scaleform::Render::MeshCacheItem *, _QWORD, Scaleform::Render::ComplexMesh *, signed __int64))v2->pCacheList->pCache->vfptr[4].__vecDelDtor)(
      v2->pCacheList->pCache,
      v2,
      0i64,
      this,
      -2i64);
  Scaleform::ArrayData<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayData<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>(&v1->GradientImages.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->FillMatrixCache.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy> *)&v1->FillRecords.Data.Data);
  v3 = v1->pScale9Grid.pObject;
  if ( v3 && _InterlockedExchangeAdd(&v3->RefCount, 0xFFFFFFFF) == 1 && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  v4 = v1->pProvider.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::MeshProvider *))v4->vfptr->Release)(v4);
  v1->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 791
// RVA: 0x993160
char __fastcall Scaleform::Render::ComplexMesh::InitFillRecords(Scaleform::Render::ComplexMesh *this, Scaleform::Render::VertexOutput::Fill *fills, unsigned int fillRecordCount, Scaleform::Render::Matrix2x4<float> *vertexMatrix, Scaleform::Render::HAL *hal, unsigned __int64 *vbSize, unsigned int *vertexCount, unsigned int *indexCount)
{
  Scaleform::Render::Matrix2x4<float> *v8; // r13
  __int64 v9; // r14
  Scaleform::Render::VertexOutput::Fill *v10; // rsi
  Scaleform::Render::ComplexMesh *v11; // rdi
  Scaleform::Render::TextureManager *textureManager; // rbx
  Scaleform::Render::ComplexMesh::UpdateNode *v13; // r12
  Scaleform::Render::ComplexMesh::UpdateNode *v14; // rdx
  __int64 v15; // r15
  unsigned int *v16; // rsi
  Scaleform::Render::ComplexMesh::FillRecord *v17; // r14
  unsigned int pDtor; // ST20_4
  unsigned int v19; // ST20_4
  Scaleform::Render::PrimitiveFill *v20; // rbx
  Scaleform::Render::PrimitiveFill *v21; // rcx
  bool v22; // zf
  signed __int64 v23; // rcx
  Scaleform::Ptr<Scaleform::Render::Image> *v24; // rbx
  __int64 v25; // rcx
  Scaleform::Ptr<Scaleform::Render::Image> *v26; // rbx
  Scaleform::Render::Image *v27; // rcx
  Scaleform::Ptr<Scaleform::Render::Image> *gradientImg1; // [rsp+30h] [rbp-99h]
  __int64 ptr; // [rsp+50h] [rbp-79h]
  Scaleform::Ptr<Scaleform::Render::Image> v31; // [rsp+58h] [rbp-71h]
  Scaleform::Ptr<Scaleform::Render::Image> *v32; // [rsp+60h] [rbp-69h]
  Scaleform::Render::TextureManager *v33; // [rsp+68h] [rbp-61h]
  Scaleform::Render::FillData fd0; // [rsp+70h] [rbp-59h]
  Scaleform::Render::FillData fd1; // [rsp+90h] [rbp-39h]
  Scaleform::Ptr<Scaleform::Render::Image> *v36; // [rsp+B0h] [rbp-19h]
  char v37; // [rsp+B8h] [rbp-11h]
  __int64 v38; // [rsp+C0h] [rbp-9h]
  unsigned int v39; // [rsp+110h] [rbp+47h]
  unsigned int v40; // [rsp+120h] [rbp+57h]

  v40 = fillRecordCount;
  v38 = -2i64;
  v8 = vertexMatrix;
  v9 = fillRecordCount;
  v10 = fills;
  v11 = this;
  Scaleform::ArrayData<Scaleform::Render::ComplexMesh::FillRecord,Scaleform::AllocatorLH<Scaleform::Render::ComplexMesh::FillRecord,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->FillRecords.Data,
    fillRecordCount);
  if ( v11->FillRecords.Data.Size != v9 )
    return 0;
  textureManager = (Scaleform::Render::TextureManager *)((__int64 (*)(void))hal->vfptr[61].__vecDelDtor)();
  v33 = textureManager;
  v13 = &v11->UpdateListNode;
  v14 = v11->UpdateListNode.pPrev;
  if ( v14 )
  {
    v14->pNext = v11->UpdateListNode.pNext;
    v11->UpdateListNode.pNext->pPrev = v13->pPrev;
    v13->pPrev = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    v11->UpdateListNode.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)-1i64;
    v11->UpdateListNode.pNext = 0i64;
    v13->pPrev = 0i64;
  }
  *vbSize = 0i64;
  *indexCount = 0;
  *vertexCount = 0;
  v39 = 0;
  if ( (_DWORD)v9 )
  {
    v15 = 0i64;
    v16 = &v10->FillIndex0;
    while ( 1 )
    {
      v17 = v11->FillRecords.Data.Data;
      fd0.Type = 3;
      fd0.Color = 0;
      fd0.PrimFill = 4;
      fd0.FillMode.Fill = 0;
      fd0.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      fd1.Type = 3;
      fd1.Color = 0;
      fd1.PrimFill = 4;
      fd1.FillMode.Fill = 0;
      fd1.pVFormat = &Scaleform::Render::VertexXY16iCF32::Format;
      `eh vector constructor iterator(
        &ptr,
        8ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
      pDtor = v11->MGFlags;
      ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, _QWORD, _QWORD))v11->pProvider.pObject->vfptr->GetFillData)(
        v11->pProvider.pObject,
        &fd0,
        v11->Layer,
        *v16);
      if ( v16[2] & 2 )
      {
        v19 = v11->MGFlags;
        ((void (__fastcall *)(Scaleform::Render::MeshProvider *, Scaleform::Render::FillData *, _QWORD, _QWORD))v11->pProvider.pObject->vfptr->GetFillData)(
          v11->pProvider.pObject,
          &fd1,
          v11->Layer,
          v16[1]);
      }
      v20 = Scaleform::Render::PrimitiveFillManager::CreateMergedFill(
              v11->pFillManager,
              v16[2],
              *((Scaleform::Render::VertexFormat **)v16 - 1),
              &fd0,
              &fd1,
              (Scaleform::Ptr<Scaleform::Render::Image> *)&ptr,
              &v31,
              textureManager,
              v11->MorphRatio);
      v21 = v17[v15].pFill.pObject;
      if ( v21 )
      {
        v22 = v21->RefCount-- == 1;
        if ( v22 )
          v21->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v21->vfptr, 1u);
      }
      v17[v15].pFill.pObject = v20;
      if ( !v20 )
        break;
      if ( !v13->pPrev && (fd0.Type == 4 || fd1.Type == 4) )
      {
        v23 = (signed __int64)&v11->pRenderer2D->mComplexMeshUpdateList;
        v13->pPrev = *(Scaleform::Render::ComplexMesh::UpdateNode **)v23;
        v11->UpdateListNode.pNext = (Scaleform::Render::ComplexMesh::UpdateNode *)v23;
        *(_QWORD *)(*(_QWORD *)v23 + 8i64) = v13;
        *(_QWORD *)v23 = v13;
      }
      v17[v15].IndexOffset = *indexCount;
      v17[v15].IndexCount = *(v16 - 3);
      v17[v15].VertexByteOffset = *vbSize;
      v17[v15].VertexCount = *(v16 - 4);
      v17[v15].FillMatrixIndex[0] = *v16;
      v17[v15].FillMatrixIndex[1] = v16[1];
      v17[v15].MergeFlags = v16[2];
      if ( ptr )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy> *)&v11->GradientImages.Data.Data,
          &v11->GradientImages,
          v11->GradientImages.Data.Size + 1);
        v24 = &v11->GradientImages.Data.Data[v11->GradientImages.Data.Size - 1];
        v36 = v24;
        v32 = v24;
        if ( v24 )
        {
          v25 = ptr;
          if ( ptr )
          {
            (*(void (**)(void))(*(_QWORD *)ptr + 8i64))();
            v25 = ptr;
          }
          v24->pObject = (Scaleform::Render::Image *)v25;
        }
      }
      if ( v31.pObject )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
          (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Image>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Image>,2>,Scaleform::ArrayDefaultPolicy> *)&v11->GradientImages.Data.Data,
          &v11->GradientImages,
          v11->GradientImages.Data.Size + 1);
        v26 = &v11->GradientImages.Data.Data[v11->GradientImages.Data.Size - 1];
        v32 = v26;
        v36 = v26;
        if ( v26 )
        {
          v27 = v31.pObject;
          if ( v31.pObject )
          {
            ((void (*)(void))v31.pObject->vfptr[1].__vecDelDtor)();
            v27 = v31.pObject;
          }
          v26->pObject = v27;
        }
      }
      LODWORD(gradientImg1) = 1;
      ((void (__fastcall *)(Scaleform::Render::HAL *, _QWORD, Scaleform::Render::VertexFormat *, Scaleform::Render::VertexFormat **, char *, Scaleform::Render::VertexFormat **, Scaleform::Ptr<Scaleform::Render::Image> *))hal->vfptr[66].__vecDelDtor)(
        hal,
        (unsigned int)v17[v15].pFill.pObject->Data.Type,
        v17[v15].pFill.pObject->Data.pFormat,
        v17[v15].pFormats,
        &v37,
        &v17[v15].pFormats[1],
        gradientImg1);
      *vbSize += *(v16 - 4) * v17[v15].pFormats[0]->Size;
      *vertexCount += *(v16 - 4);
      *indexCount += *(v16 - 3);
      `eh vector destructor iterator(
        &ptr,
        8ui64,
        2,
        (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
      ++v39;
      v16 += 8;
      ++v15;
      textureManager = v33;
      if ( v39 >= v40 )
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
  v11->VertexMatrix.M[0][0] = v8->M[0][0];
  v11->VertexMatrix.M[0][1] = v8->M[0][1];
  v11->VertexMatrix.M[0][2] = v8->M[0][2];
  v11->VertexMatrix.M[0][3] = v8->M[0][3];
  v11->VertexMatrix.M[1][0] = v8->M[1][0];
  v11->VertexMatrix.M[1][1] = v8->M[1][1];
  v11->VertexMatrix.M[1][2] = v8->M[1][2];
  v11->VertexMatrix.M[1][3] = v8->M[1][3];
  Scaleform::Render::ComplexMesh::updateFillMatrixCache(v11, v8);
  return 1;
}

// File Line: 875
// RVA: 0x9F9A10
void __fastcall Scaleform::Render::ComplexMesh::updateFillMatrixCache(Scaleform::Render::ComplexMesh *this, Scaleform::Render::Matrix2x4<float> *vertexMatrix)
{
  Scaleform::Render::ComplexMesh *v2; // rdi
  float *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned int v5; // er14
  __int64 v6; // rbx
  __int64 v7; // r12
  Scaleform::Render::Matrix2x4<float> *v8; // rax
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  __int64 v17; // [rsp+20h] [rbp-48h]
  __int64 v18; // [rsp+28h] [rbp-40h]

  v2 = this;
  v3 = (float *)vertexMatrix;
  v4 = this->pProvider.pObject->vfptr->GetFillCount(this->pProvider.pObject, v2->Layer, v2->MGFlags);
  Scaleform::ArrayData<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v2->FillMatrixCache.Data,
    v4);
  if ( v2->FillMatrixCache.Data.Size == v4 )
  {
    v5 = 0;
    if ( (_DWORD)v4 )
    {
      v6 = 0i64;
      v7 = 0i64;
      do
      {
        LODWORD(v18) = v2->MGFlags;
        LODWORD(v17) = v5;
        v2->pProvider.pObject->vfptr->GetFillMatrix(
          v2->pProvider.pObject,
          (Scaleform::Render::MeshBase *)&v2->vfptr,
          &v2->FillMatrixCache.Data.Data[v7],
          v2->Layer,
          v17,
          v18);
        v8 = v2->FillMatrixCache.Data.Data;
        ++v5;
        ++v6;
        ++v7;
        v9 = v8[v6 - 1].M[0][0];
        v10 = *((float *)&v8[v6] - 7);
        v11 = *((float *)&v8[v6] - 4);
        v12 = *((float *)&v8[v6] - 3);
        v13 = *((float *)&v8[v6] - 3);
        v14 = *((float *)&v8[v6] - 4);
        v8[v6 - 1].M[0][0] = (float)(*((float *)&v8[v6] - 7) * v3[4]) + (float)(v8[v6 - 1].M[0][0] * *v3);
        *((float *)&v8[v6] - 4) = (float)(v13 * v3[4]) + (float)(v14 * *v3);
        *((float *)&v8[v6] - 7) = (float)(v10 * v3[5]) + (float)(v9 * v3[1]);
        v15 = v12 * v3[5];
        v16 = v11 * v3[1];
        *((_DWORD *)&v8[v6] - 2) = 0;
        *((_DWORD *)&v8[v6] - 6) = 0;
        *((float *)&v8[v6] - 3) = v15 + v16;
        *((float *)&v8[v6] - 5) = (float)((float)(v10 * v3[7]) + (float)(v9 * v3[3])) + *((float *)&v8[v6] - 5);
        *((float *)&v8[v6] - 1) = (float)((float)(v12 * v3[7]) + (float)(v11 * v3[3])) + *((float *)&v8[v6] - 1);
      }
      while ( v5 < (unsigned int)v4 );
    }
  }
}

// File Line: 942
// RVA: 0x96FEC0
void __fastcall Scaleform::Render::MaskPrimitive::EmitToHAL(Scaleform::Render::MaskPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( qp->QueueEmitFilter == QPF_All )
    qp->pHAL->vfptr[36].__vecDelDtor(
      (Scaleform::RefCountImplCore *)qp->pHAL,
      (unsigned int)&this[-1].MaskAreas.Data.Size);
}

// File Line: 952
// RVA: 0x9394F0
void __fastcall Scaleform::Render::CacheablePrimitive::CacheablePrimitive(Scaleform::Render::CacheablePrimitive *this, bool masksPresent)
{
  bool v2; // di
  Scaleform::Render::CacheablePrimitive *v3; // r14
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *v4; // rbx
  signed __int64 v5; // rsi
  signed __int64 v6; // [rsp+80h] [rbp+18h]

  v2 = masksPresent;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>::`vftable;
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v4 = this->CacheResults;
  v5 = 2i64;
  `eh vector constructor iterator(
    this->CacheResults,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v6 = (signed __int64)&v3->PrimitiveArea;
  *(_OWORD *)v6 = 0ui64;
  *(_QWORD *)(v6 + 16) = 0i64;
  v3->MaskPresent = v2;
  v3->Caching = 0;
  do
  {
    if ( v4->pObject )
      ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v4->pObject->vfptr[2].__vecDelDtor)(v4->pObject);
    v4->pObject = 0i64;
    ++v4;
    --v5;
  }
  while ( v5 );
  v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 0);
}

// File Line: 957
// RVA: 0x949040
void __fastcall Scaleform::Render::CacheablePrimitive::~CacheablePrimitive(Scaleform::Render::CacheablePrimitive *this)
{
  Scaleform::Render::CacheablePrimitive *v1; // rsi
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::CacheablePrimitive,67>};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::CacheablePrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  v2 = this->CacheResults;
  v3 = 2i64;
  do
  {
    if ( v2->pObject )
      ((void (__cdecl *)(Scaleform::Render::RenderTarget *))v2->pObject->vfptr[2].__vecDelDtor)(v2->pObject);
    v2->pObject = 0i64;
    ++v2;
    --v3;
  }
  while ( v3 );
  Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
    v1->PrimitiveArea.Data.Data,
    v1->PrimitiveArea.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->PrimitiveArea.Data.Data);
  `eh vector destructor iterator(
    v1->CacheResults,
    8ui64,
    2,
    (void (__fastcall *)(void *))ARefPtr<SSClassDescBase>::~ARefPtr<SSClassDescBase>);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 963
// RVA: 0x980A60
void __fastcall Scaleform::Render::CacheablePrimitive::GetCacheResults(Scaleform::Render::CacheablePrimitive *this, Scaleform::Render::RenderTarget **results, unsigned int count)
{
  unsigned int v3; // er9
  signed __int64 v4; // rcx

  v3 = 0;
  if ( count )
  {
    v4 = (char *)this - (char *)results;
    if ( count <= 0 )
    {
      *results = 0i64;
      goto LABEL_5;
    }
    do
    {
      *results = *(Scaleform::Render::RenderTarget **)((char *)results + v4 + 32);
LABEL_5:
      ++v3;
      ++results;
    }
    while ( v3 < count );
  }
}

// File Line: 974
// RVA: 0x9AE9F0
void __fastcall Scaleform::Render::CacheablePrimitive::SetCacheResults(Scaleform::Render::CacheablePrimitive *this, Scaleform::Render::CacheablePrimitive::CacheState state, Scaleform::Render::RenderTarget **results, unsigned int count)
{
  unsigned int v4; // esi
  unsigned int v5; // er14
  Scaleform::Render::RenderTarget **v6; // rbp
  Scaleform::Render::CacheablePrimitive::CacheState v7; // er13
  Scaleform::Render::CacheablePrimitive *v8; // r15
  signed __int64 v9; // r12
  Scaleform::Ptr<Scaleform::Render::RenderTarget> *v10; // rbx
  Scaleform::Render::RenderTarget *v11; // rdi

  v4 = 0;
  v5 = count;
  v6 = results;
  v7 = state;
  v8 = this;
  v9 = (char *)results - (char *)this;
  this->Caching = state;
  v10 = this->CacheResults;
  do
  {
    if ( v4 < v5 && v6 )
    {
      v11 = *(Scaleform::Render::RenderTarget **)((char *)&v10[-4].pObject + v9);
      if ( v11 )
        ((void (__fastcall *)(_QWORD))v11->vfptr[1].__vecDelDtor)(*(Scaleform::Render::RenderTarget **)((char *)&v10[-4].pObject + v9));
      if ( v10->pObject )
        ((void (*)(void))v10->pObject->vfptr[2].__vecDelDtor)();
      v10->pObject = v11;
    }
    else
    {
      if ( v10->pObject )
        ((void (*)(void))v10->pObject->vfptr[2].__vecDelDtor)();
      v10->pObject = 0i64;
    }
    ++v4;
    ++v10;
  }
  while ( v4 < 2 );
  if ( v7 == Cache_Mesh )
    v8->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 0);
}

// File Line: 996
// RVA: 0x9A8880
void __fastcall Scaleform::Render::CacheablePrimitive::Remove(Scaleform::Render::CacheablePrimitive *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // r14
  Scaleform::Render::CacheablePrimitive *v5; // rdi
  unsigned __int64 i; // rbx

  v3 = count;
  v4 = index;
  v5 = this;
  for ( i = index; i < v3; ++i )
    v5->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, i);
  if ( v5->PrimitiveArea.Data.Size == v3 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Render::MatrixPoolImpl::HMatrix,Scaleform::AllocatorLH<Scaleform::Render::MatrixPoolImpl::HMatrix,2>,Scaleform::ArrayDefaultPolicy> *)&v5->PrimitiveArea.Data.Data,
      &v5->PrimitiveArea,
      0i64);
  }
  else
  {
    Scaleform::ConstructorMov<Scaleform::Render::MatrixPoolImpl::HMatrix>::DestructArray(
      &v5->PrimitiveArea.Data.Data[v4],
      v3);
    memmove(
      &v5->PrimitiveArea.Data.Data[v4],
      &v5->PrimitiveArea.Data.Data[v4 + v3],
      8 * (v5->PrimitiveArea.Data.Size - v4 - v3));
    v5->PrimitiveArea.Data.Size -= v3;
  }
}

// File Line: 1010
// RVA: 0x96FE50
void __fastcall Scaleform::Render::FilterPrimitive::EmitToHAL(Scaleform::Render::FilterPrimitive *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::RenderQueueItem *v3; // rax
  Scaleform::Render::FilterPrimitive *v4; // rdx
  bool v5; // zf
  Scaleform::Render::HAL *v6; // rcx
  Scaleform::RefCountImplCoreVtbl *v7; // rax

  v3 = item;
  v4 = this;
  if ( v3 != qp->EmitItemBuffer.pItem )
  {
    *(_OWORD *)&qp->EmitItemBuffer.pItem = (unsigned __int64)v3;
    v5 = this->PrimitiveArea.Data.Policy.Capacity == 0;
    v6 = qp->pHAL;
    v7 = qp->pHAL->vfptr;
    if ( v5 )
      v7[48].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v4);
    else
      v7[47].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v4[-1].MaskPresent);
  }
}

// File Line: 1024
// RVA: 0x99F760
__int64 __fastcall Scaleform::Render::FilterPrimitive::Prepare(Scaleform::Render::FilterPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp, __int64 a4)
{
  Scaleform::Render::FilterPrimitive *v4; // rdi
  Scaleform::Render::RenderQueueProcessor *v5; // rbx
  __int64 v6; // r8

  v4 = this;
  v5 = qp;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::HAL *, bool *, Scaleform::Render::RenderQueueProcessor *, __int64))qp->pHAL->vfptr[74].__vecDelDtor)(
         qp->pHAL,
         &this[-1].MaskPresent,
         qp,
         a4) )
  {
    LOBYTE(v6) = v4->PrimitiveArea.Data.Policy.Capacity == 0;
    ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, __int64))v5->pHAL->vfptr[46].__vecDelDtor)(
      v5->pHAL,
      &v4[-1].MaskPresent,
      v6);
  }
  return 0i64;
}

// File Line: 1037
// RVA: 0x9F8180
void __fastcall Scaleform::Render::FilterPrimitive::uncachePrimitive(Scaleform::Render::FilterPrimitive *this, unsigned __int64 index)
{
  Scaleform::Render::FilterPrimitive *v2; // rdi
  unsigned __int64 v3; // rbx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // rcx
  Scaleform::Render::MatrixPoolImpl::DataHeader *v5; // r8
  Scaleform::Render::Matrix2x4<float> *v6; // rdx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = index;
  v4 = &this->PrimitiveArea.Data.Data[index];
  if ( v4->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    if ( v4->pHandle->pHeader->Format & 2 )
    {
      v5 = v4->pHandle->pHeader;
      if ( v5->Format & 2 )
        v6 = (Scaleform::Render::Matrix2x4<float> *)&v5[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->Format & 0xF].Offsets[1]
                                                      + 1];
      else
        v6 = &Scaleform::Render::Matrix2x4<float>::Identity;
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v4, v6);
    }
    v7 = &v2->PrimitiveArea.Data.Data[v3];
    *(_OWORD *)&m.M[0][0] = 0i64;
    *(_OWORD *)&m.M[1][0] = 0i64;
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(v7, &m, 1u);
  }
}

// File Line: 1055
// RVA: 0x96FD50
void __fastcall Scaleform::Render::BlendPrimitive::EmitToHAL(Scaleform::Render::BlendPrimitive *this, Scaleform::Render::RenderQueueItem *item, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::Render::RenderQueueItem *v3; // rax
  Scaleform::Render::BlendPrimitive *v4; // rdx
  bool v5; // sf
  unsigned __int8 v6; // of
  Scaleform::Render::HAL *v7; // rcx
  Scaleform::RefCountImplCoreVtbl *v8; // rax

  v3 = item;
  v4 = this;
  if ( v3 != qp->EmitItemBuffer.pItem )
  {
    *(_OWORD *)&qp->EmitItemBuffer.pItem = (unsigned __int64)v3;
    v6 = __OFSUB__(this->PrimitiveArea.Data.Policy.Capacity, 20);
    v5 = LODWORD(this->PrimitiveArea.Data.Policy.Capacity) - 20 < 0;
    v7 = qp->pHAL;
    v8 = qp->pHAL->vfptr;
    if ( v5 ^ v6 )
      v8[39].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&v4[-1].MaskPresent);
    else
      v8[40].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v4);
  }
}

// File Line: 1069
// RVA: 0x99F690
__int64 __fastcall Scaleform::Render::BlendPrimitive::Prepare(Scaleform::Render::BlendPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp, __int64 a4)
{
  unsigned int v4; // eax
  Scaleform::Render::BlendPrimitive *v5; // rdx
  Scaleform::Render::HAL *v6; // rcx
  __int64 result; // rax
  signed int v8; // ecx

  v4 = this->PrimitiveArea.Data.Policy.Capacity;
  v5 = this;
  if ( v4 == 21 )
  {
    v6 = qp->pHAL;
    LOBYTE(qp) = 1;
    ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, Scaleform::Render::RenderQueueProcessor *, __int64))v6->vfptr[46].__vecDelDtor)(
      v6,
      &v5[-1].MaskPresent,
      qp,
      a4);
    result = 0i64;
  }
  else
  {
    if ( v4 <= 0xE )
    {
      v8 = 24804;
      if ( _bittest(&v8, v4) )
        ((void (__fastcall *)(Scaleform::Render::HAL *, bool *, _QWORD, __int64))qp->pHAL->vfptr[46].__vecDelDtor)(
          qp->pHAL,
          &v5[-1].MaskPresent,
          0i64,
          a4);
    }
    result = 0i64;
  }
  return result;
}

// File Line: 1084
// RVA: 0x96FFC0
void __fastcall Scaleform::Render::ViewMatrix3DPrimitive::EmitToHAL(Scaleform::Render::ViewMatrix3DPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ViewMatrix.M[2][0]) )
    Scaleform::Render::HAL::PushView3D(qp->pHAL, (Scaleform::Render::Matrix3x4<float> *)&this->vfptr);
  else
    Scaleform::Render::HAL::PopView3D(qp->pHAL);
}

// File Line: 1095
// RVA: 0x96FF10
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::EmitToHAL(Scaleform::Render::ProjectionMatrix3DPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp)
{
  if ( LOBYTE(this->ProjectionMatrix.M[3][0]) )
    Scaleform::Render::HAL::PushProj3D(qp->pHAL, (Scaleform::Render::Matrix4x4<float> *)&this->vfptr);
  else
    Scaleform::Render::HAL::PopProj3D(qp->pHAL);
}

// File Line: 1106
// RVA: 0x96FFA0
void __fastcall Scaleform::Render::UserDataPrimitive::EmitToHAL(Scaleform::Render::UserDataPrimitive *this, Scaleform::Render::RenderQueueItem *__formal, Scaleform::Render::RenderQueueProcessor *qp)
{
  Scaleform::RefCountImplCoreVtbl *v3; // rax

  v3 = qp->pHAL->vfptr;
  if ( *(_QWORD *)&this->RefCount )
    ((void (*)(void))v3[72].__vecDelDtor)();
  else
    ((void (*)(void))v3[73].__vecDelDtor)();
}

