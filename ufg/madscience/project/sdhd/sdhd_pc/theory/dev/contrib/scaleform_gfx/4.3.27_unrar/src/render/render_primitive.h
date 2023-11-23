// File Line: 98
// RVA: 0x94B930
void __fastcall Scaleform::Render::MeshStagingNode::~MeshStagingNode(Scaleform::Render::MeshStagingNode *this)
{
  this->vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
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
  this->vfptr = (Scaleform::Render::MeshProviderVtbl *)&Scaleform::Render::MeshProvider::`vftable;
}

// File Line: 157
// RVA: 0x9873A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::MeshProvider::GetIdentityBounds(
        Scaleform::Render::MeshProvider *this,
        Scaleform::Render::Rect<float> *result)
{
  this->vfptr->GetBounds(this, result, &Scaleform::Render::Matrix2x4<float>::Identity);
  return result;
}

// File Line: 209
// RVA: 0x954970
void __fastcall Scaleform::Render::MeshProvider_RCImpl::AddRef(Scaleform::Render::MeshProvider_RCImpl *this)
{
  _InterlockedExchangeAdd((volatile signed __int32 *)&this[-1].Scaleform::Render::MeshProvider, 1u);
}

// File Line: 210
// RVA: 0x9A7C40
void __fastcall Scaleform::Render::MeshProvider_RCImpl::Release(Scaleform::Render::MeshProvider_RCImpl *this)
{
  volatile int *p_RefCount; // rcx

  p_RefCount = &this[-1].RefCount;
  if ( !_InterlockedDecrement(p_RefCount + 2) )
  {
    if ( p_RefCount )
      (**(void (__fastcall ***)(char *, __int64))p_RefCount)((char *)p_RefCount, 1i64);
  }
}

// File Line: 247
// RVA: 0x93F910
void __fastcall Scaleform::Render::MeshBase::MeshBase(
        Scaleform::Render::MeshBase *this,
        Scaleform::Render::Renderer2DImpl *prenderer,
        Scaleform::Render::MeshProvider *provider,
        Scaleform::Render::Matrix2x4<float> *viewMatrix,
        float morphRatio,
        unsigned int layer,
        unsigned int meshGenFlags)
{
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::`vftable;
  this->Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshStagingNode::`vftable;
  this->StagingBufferSize = 0i64;
  this->StagingBufferOffset = 0i64;
  this->StagingBufferIndexOffset = 0i64;
  *(_QWORD *)&this->PinCount = 0i64;
  this->IndexCount = 0;
  this->Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::MeshBase::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::MeshBase,68>};
  this->Scaleform::Render::MeshStagingNode::vfptr = (Scaleform::Render::MeshStagingNodeVtbl *)&Scaleform::Render::MeshBase::`vftable{for `Scaleform::Render::MeshStagingNode};
  this->pRenderer2D = prenderer;
  if ( provider )
    (*((void (__fastcall **)(Scaleform::Render::MeshProvider *))&provider->vfptr->__vecDelDtor + 1))(provider);
  this->pProvider.pObject = provider;
  this->pScale9Grid.pObject = 0i64;
  this->ViewMatrix.M[0][0] = viewMatrix->M[0][0];
  this->ViewMatrix.M[0][1] = viewMatrix->M[0][1];
  this->ViewMatrix.M[0][2] = viewMatrix->M[0][2];
  this->ViewMatrix.M[0][3] = viewMatrix->M[0][3];
  this->ViewMatrix.M[1][0] = viewMatrix->M[1][0];
  this->ViewMatrix.M[1][1] = viewMatrix->M[1][1];
  this->ViewMatrix.M[1][2] = viewMatrix->M[1][2];
  this->ViewMatrix.M[1][3] = viewMatrix->M[1][3];
  this->MorphRatio = morphRatio;
  this->Layer = layer;
  this->MGFlags = meshGenFlags;
}

// File Line: 261
// RVA: 0x9B36A0
void __fastcall Scaleform::Render::MeshBase::SetScale9Grid(
        Scaleform::Render::MeshBase *this,
        Scaleform::Render::Scale9GridData *s9g)
{
  Scaleform::Render::Scale9GridData *pObject; // rcx

  if ( s9g )
    _InterlockedExchangeAdd(&s9g->RefCount, 1u);
  pObject = this->pScale9Grid.pObject;
  if ( !pObject || _InterlockedDecrement(&pObject->RefCount) )
  {
    this->pScale9Grid.pObject = s9g;
  }
  else
  {
    pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pScale9Grid.pObject = s9g;
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
  this->vfptr = (Scaleform::Render::VertexOutputVtbl *)&Scaleform::Render::VertexOutput::`vftable;
}

// File Line: 379
// RVA: 0x99CD10
void __fastcall Scaleform::Render::Mesh::OnStagingNodeEvict(Scaleform::Render::Mesh *this)
{
  bool v1; // zf
  bool *p_LargeMesh; // rdx
  __int64 v3; // rcx

  v1 = *(_QWORD *)&this->MorphRatio == 0i64;
  this->pPrev = 0i64;
  if ( v1 )
  {
    p_LargeMesh = &this[-1].LargeMesh;
    v3 = *(_QWORD *)&this->IndexCount;
    if ( v3 )
      (*(void (__fastcall **)(__int64, bool *))(*(_QWORD *)v3 + 32i64))(v3, p_LargeMesh);
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
void __fastcall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        Scaleform::Render::PrimitiveFillData *this,
        Scaleform::Render::PrimitiveFillType type,
        Scaleform::Render::VertexFormat *format,
        Scaleform::Render::Texture *texture0,
        char *fm0,
        Scaleform::Render::Texture *texture1,
        char *fm1)
{
  Scaleform::Render::Texture *pObject; // rcx
  Scaleform::Render::Texture *v11; // rcx

  this->Type = type;
  this->SolidColor.Raw = 0;
  *(_WORD *)&this->FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    this->Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  this->pFormat = format;
  this->FillModes[0].Fill = *fm0;
  this->FillModes[1].Fill = *fm1;
  if ( texture0 )
    _InterlockedExchangeAdd(&texture0->RefCount, 1u);
  pObject = this->Textures[0].pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->Textures[0].pObject = texture0;
  if ( texture1 )
    _InterlockedExchangeAdd(&texture1->RefCount, 1u);
  v11 = this->Textures[1].pObject;
  if ( v11 && !_InterlockedDecrement(&v11->RefCount) )
    v11->vfptr->__vecDelDtor(v11, 1u);
  this->Textures[1].pObject = texture1;
}

// File Line: 493
// RVA: 0x940940
void __fastcall Scaleform::Render::PrimitiveFillData::PrimitiveFillData(
        Scaleform::Render::PrimitiveFillData *this,
        Scaleform::Render::PrimitiveFillData *src)
{
  Scaleform::Render::Texture *pObject; // rcx
  Scaleform::Render::Texture *v5; // rcx
  Scaleform::Render::Texture *v6; // rcx
  Scaleform::Render::Texture *v7; // rcx

  this->Type = src->Type;
  this->SolidColor.Raw = src->SolidColor.Raw;
  *(_WORD *)&this->FillModes[0].Fill = 0;
  `eh vector constructor iterator(
    this->Textures,
    8ui64,
    2,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  this->pFormat = src->pFormat;
  *(_WORD *)&this->FillModes[0].Fill = *(_WORD *)&src->FillModes[0].Fill;
  pObject = src->Textures[0].pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount, 1u);
  v5 = this->Textures[0].pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount) )
    v5->vfptr->__vecDelDtor(v5, 1u);
  this->Textures[0].pObject = src->Textures[0].pObject;
  v6 = src->Textures[1].pObject;
  if ( v6 )
    _InterlockedExchangeAdd(&v6->RefCount, 1u);
  v7 = this->Textures[1].pObject;
  if ( v7 && !_InterlockedDecrement(&v7->RefCount) )
    v7->vfptr->__vecDelDtor(v7, 1u);
  this->Textures[1].pObject = src->Textures[1].pObject;
}

// File Line: 539
// RVA: 0x985380
unsigned __int64 __fastcall Scaleform::Render::PrimitiveFillData::GetHashValue(
        Scaleform::Render::PrimitiveFillData *this)
{
  return (unsigned int)this->Type ^ (unsigned __int64)this->Textures[1].pObject ^ this->SolidColor.Raw ^ ((unsigned __int64)this->Textures[0].pObject >> 2) ^ this->pFormat->Size ^ (unsigned __int64)(4 * ((4 * (unsigned __int8)this->FillModes[1].Fill) ^ (unsigned int)(unsigned __int8)this->FillModes[0].Fill));
}

// File Line: 547
// RVA: 0xA006D0
bool __fastcall Scaleform::Render::PrimitiveFillData::RequiresBlend(Scaleform::Render::PrimitiveFillData *this)
{
  bool result; // al
  int v2; // ebx
  Scaleform::Ptr<Scaleform::Render::Texture> *i; // rdi

  switch ( this->Type )
  {
    case PrimFill_None:
    case PrimFill_Mask:
      result = 0;
      break;
    case PrimFill_SolidColor:
      result = this->SolidColor.Channels.Alpha != -1;
      break;
    case PrimFill_Texture:
    case PrimFill_2Texture:
    case PrimFill_UVTexture:
      v2 = 0;
      for ( i = this->Textures; !i->pObject; ++i )
      {
$LN8_116:
        if ( ++v2 >= 2 )
          return 0;
      }
      switch ( ((unsigned int (__fastcall *)(Scaleform::Render::Texture *))i->pObject->vfptr[4].__vecDelDtor)(i->pObject) )
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
void __fastcall Scaleform::Render::PrimitiveFill::PrimitiveFill(
        Scaleform::Render::PrimitiveFill *this,
        Scaleform::Render::PrimitiveFillData *srcData,
        Scaleform::Render::PrimitiveFillManager *manager)
{
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,71>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::PrimitiveFill,71>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::PrimitiveFill::`vftable;
  Scaleform::Render::PrimitiveFillData::PrimitiveFillData(&this->Data, srcData);
  this->pManager = manager;
}

// File Line: 695
// RVA: 0x94BFC0
void __fastcall Scaleform::Render::PrimitiveFillManager::~PrimitiveFillManager(
        Scaleform::Render::PrimitiveFillManager *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::PrimitiveFillManager::`vftable;
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->Gradients);
  Scaleform::HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>::~HashSet<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::Render::GradientImage::PtrHashFunctor,Scaleform::AllocatorLH<Scaleform::Render::GradientImage *,2>,Scaleform::HashsetCachedEntry<Scaleform::Render::GradientImage *,Scaleform::Render::GradientImage::PtrHashFunctor>>((Scaleform::HashSet<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->FillSet);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 743
// RVA: 0x948FF0
void __fastcall Scaleform::Render::CacheBase::~CacheBase(Scaleform::Render::CacheBase *this)
{
  this->vfptr = (Scaleform::Render::CacheBaseVtbl *)&Scaleform::Render::CacheBase::`vftable;
}

// File Line: 773
// RVA: 0x9BB5B0
void __fastcall Scaleform::Render::RQCacheInterface::UnlockCaches(Scaleform::Render::RQCacheInterface *this)
{
  int v1; // ebx
  Scaleform::Render::RQCacheInterface *v2; // rdi
  unsigned int *p_LockFlags; // rbp
  __int64 v4; // rsi

  v1 = 1;
  v2 = this;
  p_LockFlags = &this->LockFlags;
  v4 = 2i64;
  do
  {
    if ( (v1 & *p_LockFlags) != 0 )
    {
      if ( v2->pCaches[0] )
        v2->pCaches[0]->vfptr->UnlockBuffers(v2->pCaches[0]);
    }
    v1 = __ROL4__(v1, 1);
    v2 = (Scaleform::Render::RQCacheInterface *)((char *)v2 + 8);
    --v4;
  }
  while ( v4 );
}

// File Line: 823
// RVA: 0x94B180
void __fastcall Scaleform::Render::RenderQueueItem::Interface::~Interface(
        Scaleform::Render::RenderQueueItem::Interface *this)
{
  this->vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
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
void __fastcall Scaleform::Render::ViewMatrix3DPrimitive::~ViewMatrix3DPrimitive(
        Scaleform::Render::ViewMatrix3DPrimitive *this)
{
  this->Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ViewMatrix3DPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::ViewMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 1363
// RVA: 0x940DB0
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::ProjectionMatrix3DPrimitive(
        Scaleform::Render::ProjectionMatrix3DPrimitive *this)
{
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::`vftable;
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  memset(&this->ProjectionMatrix, 0, sizeof(this->ProjectionMatrix));
  this->ProjectionMatrix.M[0][0] = 1.0;
  this->ProjectionMatrix.M[1][1] = 1.0;
  this->ProjectionMatrix.M[2][2] = 1.0;
  this->ProjectionMatrix.M[3][3] = 1.0;
  this->bHasProjectionMatrix = 0;
}

// File Line: 1364
// RVA: 0x94C0E0
void __fastcall Scaleform::Render::ProjectionMatrix3DPrimitive::~ProjectionMatrix3DPrimitive(
        Scaleform::Render::ProjectionMatrix3DPrimitive *this)
{
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::ProjectionMatrix3DPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::ProjectionMatrix3DPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 1390
// RVA: 0x946D10
void __fastcall Scaleform::Render::UserDataPrimitive::UserDataPrimitive(
        Scaleform::Render::UserDataPrimitive *this,
        Scaleform::Render::UserDataState::Data *data)
{
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::`vftable;
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  if ( data )
    _InterlockedExchangeAdd(&data->RefCount, 1u);
  this->pUserData.pObject = data;
}

// File Line: 1391
// RVA: 0x94D950
void __fastcall Scaleform::Render::UserDataPrimitive::~UserDataPrimitive(Scaleform::Render::UserDataPrimitive *this)
{
  Scaleform::Render::UserDataState::Data *pObject; // rcx

  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable{for `Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>};
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::UserDataPrimitive::`vftable{for `Scaleform::Render::RenderQueueItem::Interface};
  pObject = this->pUserData.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->Scaleform::Render::RenderQueueItem::Interface::vfptr = (Scaleform::Render::RenderQueueItem::InterfaceVtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable;
  this->Scaleform::RefCountBase<Scaleform::Render::UserDataPrimitive,67>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,67>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

