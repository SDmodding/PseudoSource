// File Line: 98
// RVA: 0x94B930
void __fastcall Scaleform::Render::MeshStagingNode::~MeshStagingNode(Scaleform::Render::MeshStagingNode *this)
{
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
}

// File Line: 101
// RVA: 0x99CD40
void __fastcall Scaleform::Render::MeshStagingNode::OnStagingNodeEvict(Scaleform::Render::MeshStagingNode *this)
{
  this->StagingBufferSize = 0i64;
}

// File Line: 142
// RVA: 0x94B860
void __fastcall Scaleform::Render::MeshProvider::~MeshProvider(Scaleform::Render::MeshProvider *this)
{
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable';
}

// File Line: 157
// RVA: 0x9873A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshProvider::GetIdentityBounds(Scaleform::Render::MeshProvider *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx

  v2 = result;
  this->vfptr->GetBounds(this, result, &Scaleform::Render::Matrix2x4<float>::Identity);
  return v2;
}

// File Line: 209
// RVA: 0x954970
void __fastcall Scaleform::Render::MeshProvider_RCImpl::AddRef(Scaleform::Render::MeshProvider_RCImpl *this)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)&this[-1].vfptr, 1u);
}

// File Line: 210
// RVA: 0x9A7C40
void __fastcall Scaleform::Render::MeshProvider_RCImpl::Release(Scaleform::Render::MeshProvider_RCImpl *this)
{
  volatile int *v1; // rcx

  v1 = &this[-1].RefCount;
  if ( !_InterlockedDecrement(v1 + 2) )
  {
    if ( v1 )
      (**(void (__fastcall ***)(char *, signed __int64))v1)((char *)v1, 1i64);
  }
}

// File Line: 247
// RVA: 0x93F910
void __fastcall Scaleform::Render::MeshBase::MeshBase(Scaleform::Render::MeshBase *this, Scaleform::Render::Renderer2DImpl *prenderer, Scaleform::Render::MeshProvider *provider, Scaleform::Render::Matrix2x4<float> *viewMatrix, float morphRatio, unsigned int layer, unsigned int meshGenFlags)
{
  Scaleform::Render::Matrix2x4<float> *v7; // rsi
  Scaleform::Render::MeshProvider *v8; // rdi
  Scaleform::Render::MeshBase *v9; // rbx

  v7 = viewMatrix;
  v8 = provider;
  v9 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::`vftable';
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable';
  this->StagingBufferSize = 0i64;
  this->StagingBufferOffset = 0i64;
  this->StagingBufferIndexOffset = 0i64;
  *(_QWORD *)&this->PinCount = 0i64;
  this->IndexCount = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshBase::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>'};
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshBase::`vftable'{for `Scaleform::Render::MeshStagingNode'};
  this->pRenderer2D = prenderer;
  if ( provider )
    (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&provider->vfptr->__vecDelDtor + 1))(provider);
  v9->pProvider.pObject = v8;
  v9->pScale9Grid.pObject = 0i64;
  v9->ViewMatrix.M[0][0] = v7->M[0][0];
  v9->ViewMatrix.M[0][1] = v7->M[0][1];
  v9->ViewMatrix.M[0][2] = v7->M[0][2];
  v9->ViewMatrix.M[0][3] = v7->M[0][3];
  v9->ViewMatrix.M[1][0] = v7->M[1][0];
  v9->ViewMatrix.M[1][1] = v7->M[1][1];
  v9->ViewMatrix.M[1][2] = v7->M[1][2];
  v9->ViewMatrix.M[1][3] = v7->M[1][3];
  v9->MorphRatio = morphRatio;
  v9->Layer = layer;
  v9->MGFlags = meshGenFlags;
}

// File Line: 261
// RVA: 0x9B36A0
void __fastcall Scaleform::Render::MeshBase::SetScale9Grid(Scaleform::Render::MeshBase *this, Scaleform::Render::Scale9GridData *s9g)
{
  Scaleform::Render::Scale9GridData *v2; // rbx
  Scaleform::Render::MeshBase *v3; // rdi
  Scaleform::Render::Scale9GridData *v4; // rcx

  v2 = s9g;
  v3 = this;
  if ( s9g )
    _InterlockedExchangeAdd(&s9g->RefCount, 1u);
  v4 = this->pScale9Grid.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
  {
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v3->pScale9Grid.pObject = v2;
  }
  else
  {
    v3->pScale9Grid.pObject = s9g;
  }
}

// File Line: 263
// RVA: 0x997740
_BOOL8 __fastcall Scaleform::Render::MeshBase::IsEvicted(Scaleform::Render::MeshBase *this)
{
  return this->StagingBufferSize == 0;
}

// File Line: 292
// RVA: 0x94DA70
void __fastcall Scaleform::Render::VertexOutput::~VertexOutput(Scaleform::Render::VertexOutput *this)
{
  this->vfptr = (Scaleform::Render::VertexOutputVtbl *)&Scaleform::Render::VertexOutput::`vftable';
}

// File Line: 379
// RVA: 0x99CD10
void __fastcall Scaleform::Render::Mesh::OnStagingNodeEvict(Scaleform::Render::Mesh *this)
{
  bool v1; // zf
  bool *v2; // rdx
  __int64 v3; // rcx

  v1 = *(_QWORD *)&this->MorphRatio == 0i64;
  this->pPrev = 0i64;
  if ( v1 )
  {
    v2 = &this[-1].LargeMesh;
    v3 = *(_QWORD *)&this->IndexCount;
    if ( v3 )
      (*(void (__fastcall **)(__int64, bool *))(*(_QWORD *)v3 + 32i64))(v3, v2);
  }
}

// File Line: 386
// RVA: 0x997720
bool __fastcall Scaleform::Render::Mesh::IsEvicted(Scaleform::Render::Mesh *this)
{
  return !this->CacheItems.Size && !this->StagingBufferSize;
}

// File Line: 484
// RVA: 0x940A40
void __fastcall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(Scaleform::Render::PrimitiveFillData *this, Scaleform::Render::PrimitiveFillType type, Scaleform::Render::VertexFormat *format, Scaleform::Render::Texture *texture0, __int64 fm0, Scaleform::Render::Texture *texture1, __int64 fm1)
{
  Scaleform::Render::Texture *v7; // rdi
  Scaleform::Render::VertexFormat *v8; // rbx
  Scaleform::Render::PrimitiveFillData *v9; // rsi
  Scaleform::Render::Texture *v10; // rcx
  Scaleform::Render::Texture *v11; // rcx

  v7 = texture0;
  v8 = format;
  v9 = this;
  this->Type = type;
  this->SolidColor.Raw = 0;
  *(_WORD *)&this->FillModes[0].Fill = 0;
  `eh vector constructor iterator'(
    this->Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v9->pFormat = v8;
  v9->FillModes[0].Fill = *(_BYTE *)fm0;
  v9->FillModes[1].Fill = *(_BYTE *)fm1;
  if ( v7 )
    _InterlockedExchangeAdd(&v7->RefCount, 1u);
  v10 = v9->Textures[0].pObject;
  if ( v10 && !_InterlockedDecrement(&v10->RefCount) && v10 )
    v10->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
  v9->Textures[0].pObject = v7;
  if ( texture1 )
    _InterlockedExchangeAdd(&texture1->RefCount, 1u);
  v11 = v9->Textures[1].pObject;
  if ( v11 && !_InterlockedDecrement(&v11->RefCount) && v11 )
    v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
  v9->Textures[1].pObject = texture1;
}

// File Line: 493
// RVA: 0x940940
void __fastcall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(Scaleform::Render::PrimitiveFillData *this, Scaleform::Render::PrimitiveFillData *src)
{
  Scaleform::Render::PrimitiveFillData *v2; // rsi
  Scaleform::Render::PrimitiveFillData *v3; // rdi
  Scaleform::Render::Texture *v4; // rcx
  Scaleform::Render::Texture *v5; // rcx
  Scaleform::Render::Texture *v6; // rcx
  Scaleform::Render::Texture *v7; // rcx

  v2 = src;
  v3 = this;
  this->Type = src->Type;
  this->SolidColor.Raw = src->SolidColor.Raw;
  *(_WORD *)&this->FillModes[0].Fill = 0;
  `eh vector constructor iterator'(
    this->Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v3->pFormat = v2->pFormat;
  v3->FillModes[0].Fill = v2->FillModes[0].Fill;
  v3->FillModes[1].Fill = v2->FillModes[1].Fill;
  v4 = v2->Textures[0].pObject;
  if ( v4 )
    _InterlockedExchangeAdd(&v4->RefCount, 1u);
  v5 = v3->Textures[0].pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
    v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
  v3->Textures[0].pObject = v2->Textures[0].pObject;
  v6 = v2->Textures[1].pObject;
  if ( v6 )
    _InterlockedExchangeAdd(&v6->RefCount, 1u);
  v7 = v3->Textures[1].pObject;
  if ( v7 && !_InterlockedDecrement(&v7->RefCount) && v7 )
    v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
  v3->Textures[1].pObject = v2->Textures[1].pObject;
}

// File Line: 539
// RVA: 0x985380
unsigned __int64 __fastcall Scaleform::Render::PrimitiveFillData::GetHashValue(Scaleform::Render::PrimitiveFillData *this)
{
  return (unsigned int)this->Type ^ (_QWORD)this->Textures[1].pObject ^ this->SolidColor.Raw ^ ((_QWORD)this->Textures[0].pObject >> 2) ^ this->pFormat->Size ^ (unsigned __int64)(4 * (4 * (unsigned __int8)this->FillModes[1].Fill ^ (unsigned int)(unsigned __int8)this->FillModes[0].Fill));
}

// File Line: 547
// RVA: 0xA006D0
bool __fastcall Scaleform::Render::PrimitiveFillData::RequiresBlend(Scaleform::Render::PrimitiveFillData *this)
{
  bool result; // al
  signed int v2; // ebx
  Scaleform::Ptr<Scaleform::Render::Texture> *v3; // rdi

  switch ( this->Type )
  {
    case 0:
    case 1:
      result = 0;
      break;
    case 2:
      result = this->SolidColor.Channels.Alpha != -1;
      break;
    case 5:
    case 9:
    case 0xB:
      v2 = 0;
      v3 = this->Textures;
      while ( !v3->pObject )
      {
$LN8_116:
        ++v2;
        ++v3;
        if ( v2 >= 2 )
          return 0;
      }
      switch ( ((unsigned int (*)(void))v3->pObject->vfptr[4].__vecDelDtor)() )
      {
        case 3u:
        case 4u:
        case 0x36u:
        case 0x38u:
        case 0x3Fu:
        case 0xC8u:
          goto $LN8_116;
        default:
          result = 1;
          break;
      }
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

// File Line: 638
// RVA: 0x9408C0
void __fastcall Scaleform::Render::PrimitiveFill::PrimitiveFill(Scaleform::Render::PrimitiveFill *this, Scaleform::Render::PrimitiveFillData *srcData, Scaleform::Render::PrimitiveFillManager *manager)
{
  Scaleform::Render::PrimitiveFillManager *v3; // rbx
  Scaleform::Render::PrimitiveFill *v4; // rdi

  v3 = manager;
  v4 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,71>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::PrimitiveFill,71>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::PrimitiveFill::`vftable';
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData(&this->Data, srcData);
  v4->pManager = v3;
}

// File Line: 695
// RVA: 0x94BFC0
void __fastcall Scaleform::Render::PrimitiveFillManager::~PrimitiveFillManager(Scaleform::Render::PrimitiveFillManager *this)
{
  Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *v1; // rbx

  v1 = (Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable';
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->Gradients);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>(v1 + 3);
  v1->pTable = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 743
// RVA: 0x948FF0
void __fastcall Scaleform::Render::CacheBase::~CacheBase(Scaleform::Render::CacheBase *this)
{
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable';
}

// File Line: 773
// RVA: 0x9BB5B0
void __fastcall Scaleform::Render::RQCacheInterface::UnlockCaches(Scaleform::Render::RQCacheInterface *this)
{
  signed int v1; // ebx
  Scaleform::Render::RQCacheInterface *v2; // rdi
  unsigned int *v3; // rbp
  signed __int64 v4; // rsi

  v1 = 1;
  v2 = this;
  v3 = &this->LockFlags;
  v4 = 2i64;
  do
  {
    if ( v1 & *v3 )
    {
      if ( v2->pCaches[0] )
        ((void (*)(void))v2->pCaches[0]->vfptr->UnlockBuffers)();
    }
    v1 = __ROL4__(v1, 1);
    v2 = (Scaleform::Render::RQCacheInterface *)((char *)v2 + 8);
    --v4;
  }
  while ( v4 );
}

// File Line: 823
// RVA: 0x94B180
void __fastcall Scaleform::Render::RenderQueueItem::Interface::~Interface(Scaleform::Render::RenderQueueItem::Interface *this)
{
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
}

// File Line: 1062
// RVA: 0x960450
void __fastcall Scaleform::Render::PrimitiveBatch::ClearCacheItem(Scaleform::Render::PrimitiveBatch *this)
{
  if ( this->MeshNode.pMeshItem )
  {
    this->MeshNode.pPrev->pNext = this->MeshNode.pNext;
    this->MeshNode.pNext->pPrev = this->MeshNode.pPrev;
    this->MeshNode.pPrev = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    this->MeshNode.pNext = (Scaleform::Render::MeshCacheItemUseNode *)-1i64;
    this->MeshNode.pMeshItem = 0i64;
  }
}

// File Line: 1127
// RVA: 0x997700
bool __fastcall Scaleform::Render::ComplexMesh::IsEvicted(Scaleform::Render::ComplexMesh *this)
{
  return !this->pCacheMeshItem && !this->StagingBufferSize;
}

// File Line: 1336
// RVA: 0x94DB10
void __fastcall Scaleform::Render::ViewMatrix3DPrimitive::~ViewMatrix3DPrimitive(Scaleform::Render::ViewMatrix3DPrimitive *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 1363
// RVA: 0x940DB0
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::ProjectionMatrix3DPrimitive(Scaleform::Render::ProjectionMatrix3DPrimitive *this)
{
  Scaleform::Render::ProjectionMatrix3DPrimitive *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::`vftable';
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  memset(&this->ProjectionMatrix, 0, 0x40ui64);
  v1->ProjectionMatrix.M[0][0] = 1.0;
  v1->ProjectionMatrix.M[1][1] = 1.0;
  v1->ProjectionMatrix.M[2][2] = 1.0;
  v1->ProjectionMatrix.M[3][3] = 1.0;
  v1->bHasProjectionMatrix = 0;
}

// File Line: 1364
// RVA: 0x94C0E0
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::~ProjectionMatrix3DPrimitive(Scaleform::Render::ProjectionMatrix3DPrimitive *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

// File Line: 1390
// RVA: 0x946D10
void __fastcall Scaleform::Render::UserDataPrimitive::UserDataPrimitive(Scaleform::Render::UserDataPrimitive *this, Scaleform::Render::UserDataState::Data *data)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::`vftable';
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  if ( data )
    _InterlockedExchangeAdd(&data->RefCount, 1u);
  this->pUserData.pObject = data;
}

// File Line: 1391
// RVA: 0x94D950
void __fastcall Scaleform::Render::UserDataPrimitive::~UserDataPrimitive(Scaleform::Render::UserDataPrimitive *this)
{
  Scaleform::Render::UserDataPrimitive *v1; // rbx
  Scaleform::Render::UserDataState::Data *v2; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>'};
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
  v2 = this->pUserData.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v1->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
}

