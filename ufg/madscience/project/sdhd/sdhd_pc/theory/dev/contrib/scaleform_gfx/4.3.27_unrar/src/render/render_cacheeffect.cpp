// File Line: 69
// RVA: 0x949010
void __fastcall Scaleform::Render::CacheEffectChain::~CacheEffectChain(Scaleform::Render::CacheEffectChain *this)
{
  Scaleform::Render::CacheEffect *v1; // rbx
  Scaleform::Render::CacheEffect *v2; // rcx

  v1 = this->pEffect;
  if ( this->pEffect )
  {
    do
    {
      v2 = v1;
      v1 = v1->pNext;
      v2->vfptr->__vecDelDtor(v2, 1u);
    }
    while ( v1 );
  }
}

// File Line: 81
// RVA: 0x9BE250
char __fastcall Scaleform::Render::CacheEffectChain::UpdateEffects(Scaleform::Render::CacheEffectChain *this, Scaleform::Render::TreeCacheNode *node, unsigned int changeFlags)
{
  Scaleform::Render::TreeNode *v3; // r9
  char v4; // r13
  unsigned int v5; // ebp
  Scaleform::Render::TreeCacheNode *v6; // r10
  Scaleform::Render::CacheEffectChain *v7; // r12
  Scaleform::Render::CacheEffect *v9; // rbx
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // r14
  __int64 v12; // rsi
  Scaleform::Render::StateData::Interface *v13; // r8
  signed __int64 v14; // r9
  Scaleform::Render::CacheEffect *v15; // rbp
  unsigned __int64 v16; // rcx
  signed __int64 v17; // rdx
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rcx
  Scaleform::Render::StateData::Interface **v20; // rax
  unsigned __int64 v21; // rcx
  Scaleform::Render::StateData::Interface *v22; // r8
  signed __int64 v23; // rdx
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rcx
  Scaleform::Render::StateData::Interface **v26; // rax
  __int64 v27; // rax
  Scaleform::Render::TreeCacheNode *v28; // [rsp+68h] [rbp+10h]
  unsigned int v29; // [rsp+70h] [rbp+18h]

  v29 = changeFlags;
  v28 = node;
  v3 = node->pNode;
  v4 = 0;
  v5 = changeFlags;
  v6 = node;
  v7 = this;
  if ( !v3 )
    return 0;
  v9 = this->pEffect;
  v10 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                  + 8
                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                                                        - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                                            - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !this->pEffect && !*(_QWORD *)(v10 + 64) )
    return 0;
  v11 = 0i64;
  do
  {
    if ( v9 )
    {
      v12 = *(signed int *)(v11 + 5403029584i64);
      if ( v9->vfptr->GetType(v9) == (_DWORD)v12 )
      {
        v15 = v9->pNext;
        if ( v29 & *(_DWORD *)(v11 + 5403029588i64) )
        {
          v16 = *(_QWORD *)(v10 + 64);
          if ( !v16 )
            goto LABEL_18;
          v13 = StateType_Interfaces[v12];
          if ( v16 & 1 )
          {
            if ( (Scaleform::Render::StateData::Interface *)(v16 & 0xFFFFFFFFFFFFFFFEui64) != v13 )
              goto LABEL_18;
            v17 = v10 + 64;
          }
          else
          {
            v18 = 0i64;
            v14 = *(_QWORD *)(v10 + 72) + 4i64;
            v19 = v16 >> 1;
            if ( !v19 )
              goto LABEL_18;
            v20 = (Scaleform::Render::StateData::Interface **)(*(_QWORD *)(v10 + 72) + 4i64);
            while ( *v20 != v13 )
            {
              ++v18;
              v20 += 2;
              if ( v18 >= v19 )
                goto LABEL_18;
            }
            v17 = v14 + 16 * v18;
          }
          if ( !v17 )
          {
LABEL_18:
            ((void (__fastcall *)(Scaleform::Render::CacheEffect *, signed __int64, Scaleform::Render::StateData::Interface *, signed __int64))v9->vfptr->__vecDelDtor)(
              v9,
              1i64,
              v13,
              v14);
            v7->pEffect = v15;
            v9 = v15;
            v5 = v29;
            v4 = 1;
            goto LABEL_38;
          }
          v4 |= ((__int64 (__fastcall *)(Scaleform::Render::CacheEffect *))v9->vfptr->Update)(v9);
        }
        v7 = (Scaleform::Render::CacheEffectChain *)&v9->pNext;
        v9 = v15;
        v5 = v29;
        goto LABEL_38;
      }
      v6 = v28;
    }
    if ( v5 & *(_DWORD *)(v11 + 5403029588i64) )
    {
      v21 = *(_QWORD *)(v10 + 64);
      if ( v21 )
      {
        v22 = StateType_Interfaces[*(signed int *)(v11 + 5403029584i64)];
        if ( v21 & 1 )
        {
          if ( (Scaleform::Render::StateData::Interface *)(v21 & 0xFFFFFFFFFFFFFFFEui64) != v22 )
            goto LABEL_38;
          v23 = v10 + 64;
        }
        else
        {
          v24 = 0i64;
          v25 = v21 >> 1;
          if ( !v25 )
            goto LABEL_38;
          v26 = (Scaleform::Render::StateData::Interface **)(*(_QWORD *)(v10 + 72) + 4i64);
          while ( *v26 != v22 )
          {
            ++v24;
            v26 += 2;
            if ( v24 >= v25 )
              goto LABEL_38;
          }
          v23 = *(_QWORD *)(v10 + 72) + 4i64 + 16 * v24;
        }
        if ( v23 )
        {
          v27 = (*(__int64 (__fastcall **)(Scaleform::Render::TreeCacheNode *, signed __int64, Scaleform::Render::CacheEffect *))(v11 + 5403029592i64))(
                  v6,
                  v23,
                  v9);
          if ( v27 )
          {
            v7->pEffect = (Scaleform::Render::CacheEffect *)v27;
            v7 = (Scaleform::Render::CacheEffectChain *)(v27 + 8);
          }
        }
      }
    }
LABEL_38:
    v6 = v28;
    v11 += 16i64;
  }
  while ( v11 < 0x60 );
  return v4;
}

// File Line: 153
// RVA: 0x9F8B20
void __fastcall Scaleform::Render::CacheEffectChain::updateBundleChain(Scaleform::Render::CacheEffectChain *this, Scaleform::Render::CacheEffect *effect, Scaleform::Render::BundleEntryRange *chain, Scaleform::Render::BundleEntryRange *maskChain)
{
  Scaleform::Render::CacheEffect *v4; // rbx
  Scaleform::Render::CacheEffect *v5; // rdx
  Scaleform::Render::BundleEntryRange *v6; // rdi
  Scaleform::Render::BundleEntryRange *v7; // rsi

  v4 = effect;
  v5 = effect->pNext;
  v6 = maskChain;
  v7 = chain;
  if ( v5 )
    Scaleform::Render::CacheEffectChain::updateBundleChain(this, v5, chain, maskChain);
  v4->vfptr->ChainNext(v4, v7, v6);
}

// File Line: 172
// RVA: 0x93E580
void __fastcall Scaleform::Render::MaskEffect::MaskEffect(Scaleform::Render::MaskEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::MaskEffectState mes, Scaleform::Render::MatrixPoolImpl::HMatrix *areaMatrix, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v5; // r14
  Scaleform::Render::MaskEffectState v6; // ebp
  Scaleform::Render::TreeCacheNode *v7; // rsi
  Scaleform::Render::MaskEffect *v8; // r15
  Scaleform::Render::SortKeyInterface *v9; // rdi
  struct Scaleform::Render::SKI_MaskEnd *v10; // rdi
  struct Scaleform::Render::SKI_MaskEnd *v11; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v12; // rax
  Scaleform::Render::CacheEffect *nexta; // [rsp+B0h] [rbp+28h]
  Scaleform::Render::CacheEffect *nextb; // [rsp+B0h] [rbp+28h]
  Scaleform::Render::CacheEffect *nextc; // [rsp+B0h] [rbp+28h]

  v5 = areaMatrix;
  v6 = mes;
  v7 = node;
  v8 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::MaskEffect::`vftable;
  v9 = SortKeyMaskInterfaces[0];
  SortKeyMaskInterfaces[0]->vfptr->AddRef(SortKeyMaskInterfaces[0], 0i64);
  nexta = (Scaleform::Render::CacheEffect *)&v8->StartEntry;
  *(_OWORD *)&nexta->vfptr = 0ui64;
  nexta->Length = 0;
  nexta[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)v9;
  nexta[1].pNext = 0i64;
  v9->vfptr->AddRef(v9, 0i64);
  v8->StartEntry.pBundle.pObject = 0i64;
  v8->StartEntry.pSourceNode = v7;
  v8->StartEntry.Removed = 0;
  v9->vfptr->Release(v9, 0i64);
  v10 = off_1420BB4C8[0];
  off_1420BB4C8[0]->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)off_1420BB4C8[0], (void *)1);
  nextb = (Scaleform::Render::CacheEffect *)&v8->EndEntry;
  *(_OWORD *)&nextb->vfptr = 0ui64;
  nextb->Length = 0;
  nextb[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)v10;
  nextb[1].pNext = (Scaleform::Render::CacheEffect *)1;
  v10->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)&v10->vfptr, (void *)1);
  v8->EndEntry.pBundle.pObject = 0i64;
  v8->EndEntry.pSourceNode = v7;
  v8->EndEntry.Removed = 0;
  v10->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v10->vfptr, (void *)1);
  v11 = off_1420BB4D0;
  off_1420BB4D0->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)off_1420BB4D0, (void *)2);
  nextc = (Scaleform::Render::CacheEffect *)&v8->PopEntry;
  *(_OWORD *)&nextc->vfptr = 0ui64;
  nextc->Length = 0;
  nextc[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)v11;
  nextc[1].pNext = (Scaleform::Render::CacheEffect *)2;
  v11->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)&v11->vfptr, (void *)2);
  v8->PopEntry.pBundle.pObject = 0i64;
  v8->PopEntry.pSourceNode = v7;
  v8->PopEntry.Removed = 0;
  v11->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v11->vfptr, (void *)2);
  v8->MES = v6;
  v12 = v5->pHandle;
  v8->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)v5->pHandle;
  if ( v12 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v12->pHeader->RefCount;
}

// File Line: 185
// RVA: 0x9BBFE0
char __fastcall Scaleform::Render::MaskEffect::Update(Scaleform::Render::MaskEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::MaskEffect *v2; // rdi
  char v3; // si
  Scaleform::Render::TreeCacheNode *v4; // rbx
  Scaleform::Render::MaskEffectState v6; // ebp
  Scaleform::Render::SortKeyInterface *v7; // rbx
  Scaleform::Render::Rect<float> maskBounds; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [rsp+40h] [rbp-A8h]
  int Dst; // [rsp+60h] [rbp-88h]
  int v11; // [rsp+74h] [rbp-74h]
  int v12; // [rsp+88h] [rbp-60h]
  __int64 v13; // [rsp+90h] [rbp-58h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+A0h] [rbp-48h]

  v13 = -2i64;
  v2 = this;
  v3 = 0;
  v4 = this->StartEntry.pSourceNode;
  if ( !v4 )
    return 0;
  maskBounds = 0i64;
  *(_OWORD *)&boundAreaMatrix.M[0][0] = _xmm;
  *(__m128 *)&boundAreaMatrix.M[1][0] = _xmm;
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v11 = 1065353216;
  v12 = 1065353216;
  memset(&pviewProj, 0, 0x40ui64);
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(v4, (Scaleform::Render::Matrix3x4<float> *)&Dst, &pviewProj);
  v6 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
         v4,
         &maskBounds,
         &boundAreaMatrix,
         (Scaleform::Render::Matrix3x4<float> *)&Dst,
         &pviewProj);
  if ( v2->StartEntry.Key.pImpl->Type != 4 )
  {
    Scaleform::Render::BundleEntry::ClearBundle(&v2->StartEntry);
    v7 = SortKeyMaskInterfaces[0];
    *(Scaleform::Render::SortKeyInterface **)&maskBounds.x1 = SortKeyMaskInterfaces[0];
    v3 = 1;
    *(_QWORD *)&maskBounds.x2 = 0i64;
    SortKeyMaskInterfaces[0]->vfptr->AddRef(SortKeyMaskInterfaces[0], 0i64);
    v7->vfptr->AddRef(v7, 0i64);
    v2->StartEntry.Key.pImpl->vfptr->Release(v2->StartEntry.Key.pImpl, v2->StartEntry.Key.Data);
    v2->StartEntry.Key.pImpl = v7;
    v2->StartEntry.Key.Data = 0i64;
    v7->vfptr->Release(v7, 0i64);
  }
  v2->MES = v6;
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&v2->BoundsMatrix, &boundAreaMatrix);
  return v3;
}

// File Line: 234
// RVA: 0x95DFC0
void __fastcall Scaleform::Render::MaskEffect::ChainNext(Scaleform::Render::MaskEffect *this, Scaleform::Render::BundleEntryRange *chain, Scaleform::Render::BundleEntryRange *maskChain)
{
  Scaleform::Render::BundleEntryRange *v3; // r11
  Scaleform::Render::MaskEffect *v4; // r10
  Scaleform::Render::BundleEntry *v5; // rax
  Scaleform::Render::BundleEntry *v6; // r9
  Scaleform::Render::BundleEntry *v7; // rcx
  Scaleform::Render::BundleEntry *v8; // rax
  unsigned int v9; // edx

  v3 = chain;
  v4 = this;
  if ( this->MES && maskChain && maskChain->Length & 0x7FFFFFFF )
  {
    v5 = maskChain->pFirst;
    v6 = &this->StartEntry;
    this->StartEntry.pChain = 0i64;
    this->StartEntry.ChainHeight = 0;
    v6->pNextPattern = v5;
    v7 = &this->EndEntry;
    maskChain->pLast->pNextPattern = v7;
    v8 = chain->pFirst;
    v4->EndEntry.pChain = 0i64;
    v4->EndEntry.ChainHeight = 0;
    v7->pNextPattern = v8;
    chain->pLast->pNextPattern = &v4->PopEntry;
    v4->PopEntry.pChain = 0i64;
    v4->PopEntry.ChainHeight = 0;
    v9 = (chain->Length & 0x7FFFFFFF) + (maskChain->Length & 0x7FFFFFFF) + 3;
    v4->Length = v9;
    v3->pFirst = v6;
    v3->pLast = &v4->PopEntry;
    v3->Length = v9;
  }
  else
  {
    this->StartEntry.pNextPattern = 0i64;
    this->EndEntry.pNextPattern = chain->pFirst;
    this->PopEntry.pNextPattern = chain->pLast;
    this->Length = chain->Length & 0x7FFFFFFF;
  }
}

// File Line: 267
// RVA: 0x98ADF0
void __fastcall Scaleform::Render::MaskEffect::GetRange(Scaleform::Render::MaskEffect *this, Scaleform::Render::BundleEntryRange *result)
{
  Scaleform::Render::MaskEffect *v2; // rax
  Scaleform::Render::BundleEntry *v3; // rcx
  Scaleform::Render::BundleEntryRange *v4; // r9
  unsigned int v5; // er8
  Scaleform::Render::BundleEntry *v6; // rcx
  unsigned int v7; // edx

  v2 = this;
  v3 = &this->StartEntry;
  v4 = result;
  if ( v3->pNextPattern )
  {
    v5 = v2->Length;
    result->pFirst = v3;
    result->Length = v5;
    result->pLast = &v2->PopEntry;
  }
  else
  {
    v6 = v2->PopEntry.pNextPattern;
    v7 = v2->Length;
    v4->pFirst = v2->EndEntry.pNextPattern;
    v4->pLast = v6;
    v4->Length = v7;
  }
}

// File Line: 276
// RVA: 0x928730
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::MaskEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *__formal, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::TreeCacheNode *v4; // rbx
  Scaleform::Render::MaskEffectState v5; // esi
  Scaleform::Render::MaskEffect *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v9; // rbx
  bool v10; // zf
  __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-79h]
  Scaleform::Render::Rect<float> maskBounds; // [rsp+40h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [rsp+50h] [rbp-59h]
  int Dst; // [rsp+70h] [rbp-39h]
  int v17; // [rsp+84h] [rbp-25h]
  int v18; // [rsp+98h] [rbp-11h]
  __int64 v19; // [rsp+A0h] [rbp-9h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+B0h] [rbp+7h]
  int v21; // [rsp+128h] [rbp+7Fh]

  v19 = -2i64;
  v3 = next;
  v4 = node;
  maskBounds = 0i64;
  *(_OWORD *)&boundAreaMatrix.M[0][0] = _xmm;
  *(__m128 *)&boundAreaMatrix.M[1][0] = _xmm;
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v17 = 1065353216;
  v18 = 1065353216;
  memset(&pviewProj, 0, 0x40ui64);
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(v4, (Scaleform::Render::Matrix3x4<float> *)&Dst, &pviewProj);
  v5 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
         v4,
         &maskBounds,
         &boundAreaMatrix,
         (Scaleform::Render::Matrix3x4<float> *)&Dst,
         &pviewProj);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&v4->pRenderer2D->MPool, &result, &boundAreaMatrix, 0);
  v21 = 71;
  v6 = (Scaleform::Render::MaskEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          v4,
                                          232ui64,
                                          (Scaleform::AllocInfo *)&v21);
  *(_QWORD *)&maskBounds.x1 = v6;
  if ( v6 )
  {
    Scaleform::Render::MaskEffect::MaskEffect(v6, v4, v5, &result, v3);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v9 = result.pHandle->pHeader;
    v10 = result.pHandle->pHeader->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
    {
      v11 = v9->DataPageOffset;
      *(_WORD *)((char *)&v9[1].RefCount + v11 + 2) += 16 * (unsigned __int8)v9->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v9[1].pHandle + v11))[5].pHeader += (unsigned __int8)v9->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v9->pHandle);
      v9->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v8;
}

// File Line: 300
// RVA: 0x938F20
void __fastcall Scaleform::Render::BlendModeEffect::BlendModeEffect(Scaleform::Render::BlendModeEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::MatrixPoolImpl::HMatrix *m, Scaleform::Render::BlendState *state, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::BlendState *v5; // rbp
  Scaleform::Render::MatrixPoolImpl::HMatrix *v6; // r12
  Scaleform::Render::TreeCacheNode *v7; // r15
  Scaleform::Render::BlendModeEffect *v8; // r14
  unsigned int v9; // eax
  signed int v10; // ecx
  Scaleform::Render::CacheEffect *v11; // rsi
  Scaleform::Render::SKI_BlendMode *v12; // rdi
  void *v13; // rdx
  Scaleform::Render::SortKeyInterfaceVtbl *v14; // rax
  unsigned int v15; // eax
  signed int v16; // ecx
  bool v17; // cl
  Scaleform::Render::CacheEffect *v18; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v19; // rax
  Scaleform::Render::CacheEffect *nexta; // [rsp+90h] [rbp+28h]
  Scaleform::Render::CacheEffect *nextb; // [rsp+90h] [rbp+28h]

  v5 = state;
  v6 = m;
  v7 = node;
  v8 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::BlendModeEffect::`vftable;
  v9 = state->DataValue;
  v10 = 24804;
  if ( v9 <= 0xE && _bittest(&v10, v9) )
  {
    v11 = (Scaleform::Render::CacheEffect *)SLODWORD(state->pData);
    v12 = &Scaleform::Render::SKI_BlendMode::StartCacheable_Instance;
    v13 = (void *)SLODWORD(state->pData);
    v14 = Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr;
  }
  else
  {
    v11 = (Scaleform::Render::CacheEffect *)SLODWORD(state->pData);
    v12 = &Scaleform::Render::SKI_BlendMode::Start_Instance;
    v13 = (void *)SLODWORD(state->pData);
    v14 = Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr;
  }
  v14->AddRef((Scaleform::Render::SortKeyInterface *)&v12->vfptr, v13);
  nexta = (Scaleform::Render::CacheEffect *)&v8->StartEntry;
  *(_OWORD *)&nexta->vfptr = 0ui64;
  nexta->Length = 0;
  nexta[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)v12;
  nexta[1].pNext = v11;
  v12->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)&v12->vfptr, v11);
  v8->StartEntry.pBundle.pObject = 0i64;
  v8->StartEntry.pSourceNode = v7;
  v8->StartEntry.Removed = 0;
  v12->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v12->vfptr, v11);
  v15 = v5->DataValue;
  v17 = 0;
  if ( v15 <= 0xE )
  {
    v16 = 24804;
    if ( _bittest(&v16, v15) )
      v17 = 1;
  }
  v18 = (Scaleform::Render::CacheEffect *)((v17 != 0) + 20);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v18);
  nextb = (Scaleform::Render::CacheEffect *)&v8->EndEntry;
  *(_OWORD *)&nextb->vfptr = 0ui64;
  nextb->Length = 0;
  nextb[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::SKI_BlendMode::End_Instance;
  nextb[1].pNext = v18;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v18);
  v8->EndEntry.pBundle.pObject = 0i64;
  v8->EndEntry.pSourceNode = v7;
  v8->EndEntry.Removed = 0;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v18);
  v19 = v6->pHandle;
  v8->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)v6->pHandle;
  if ( v19 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v19->pHeader->RefCount;
}

// File Line: 318
// RVA: 0x9BBD90
char __fastcall Scaleform::Render::BlendModeEffect::Update(Scaleform::Render::BlendModeEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::State *v2; // rbx
  Scaleform::Render::BlendModeEffect *v3; // rsi
  unsigned int v4; // eax
  signed int v5; // edi
  bool v6; // bp
  void *v7; // rax
  void *v8; // rdi
  Scaleform::Render::SKI_BlendMode *v9; // rbx
  void *v10; // rdx
  Scaleform::Render::SortKeyInterfaceVtbl *v11; // rax
  void *v12; // rbx

  v2 = stateArg;
  v3 = this;
  v4 = stateArg->DataValue;
  v5 = 24804;
  v6 = v4 <= 0xE && _bittest(&v5, v4);
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::BundleEntry::ClearBundle(&v3->EndEntry);
  v7 = (void *)SLODWORD(v2->pData);
  if ( (unsigned int)v7 <= 0xE && _bittest(&v5, (unsigned int)v7) )
  {
    v8 = (void *)SLODWORD(v2->pData);
    v9 = &Scaleform::Render::SKI_BlendMode::StartCacheable_Instance;
    v10 = v7;
    v11 = Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr;
  }
  else
  {
    v8 = (void *)SLODWORD(v2->pData);
    v9 = &Scaleform::Render::SKI_BlendMode::Start_Instance;
    v10 = v7;
    v11 = Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr;
  }
  v11->AddRef((Scaleform::Render::SortKeyInterface *)&v9->vfptr, v10);
  v9->vfptr->AddRef((Scaleform::Render::SortKeyInterface *)&v9->vfptr, v8);
  v3->StartEntry.Key.pImpl->vfptr->Release(v3->StartEntry.Key.pImpl, v3->StartEntry.Key.Data);
  v3->StartEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&v9->vfptr;
  v3->StartEntry.Key.Data = v8;
  v9->vfptr->Release((Scaleform::Render::SortKeyInterface *)&v9->vfptr, v8);
  v12 = (void *)((v6 != 0) + 20);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v12);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v12);
  v3->EndEntry.Key.pImpl->vfptr->Release(v3->EndEntry.Key.pImpl, v3->EndEntry.Key.Data);
  v3->EndEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance;
  v3->EndEntry.Key.Data = v12;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_BlendMode::End_Instance,
    v12);
  return 1;
}

// File Line: 337
// RVA: 0x95E090
void __fastcall Scaleform::Render::UserDataEffect::ChainNext(Scaleform::Render::ViewMatrix3DEffect *this, Scaleform::Render::BundleEntryRange *chain, Scaleform::Render::BundleEntryRange *__formal)
{
  Scaleform::Render::BundleEntry *v3; // r8
  Scaleform::Render::BundleEntry *v4; // r9
  unsigned int v5; // eax

  v3 = &this->StartEntry;
  v3->pNextPattern = chain->pFirst;
  v3->pChain = 0i64;
  v3->ChainHeight = 0;
  v4 = &this->EndEntry;
  chain->pLast->pNextPattern = &this->EndEntry;
  v4->pChain = 0i64;
  v4->ChainHeight = 0;
  v5 = (chain->Length & 0x7FFFFFFF) + 2;
  this->Length = v5;
  chain->pFirst = &this->StartEntry;
  chain->pLast = &this->EndEntry;
  chain->Length = v5;
}

// File Line: 342
// RVA: 0x98AD90
void __fastcall Scaleform::Render::BlendModeEffect::GetRange(Scaleform::Render::ViewMatrix3DEffect *this, Scaleform::Render::BundleEntryRange *result)
{
  unsigned int v2; // er8

  v2 = this->Length;
  result->pFirst = &this->StartEntry;
  result->Length = v2;
  result->pLast = &this->EndEntry;
}

// File Line: 347
// RVA: 0x9288C0
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::BlendModeEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *stateArg, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::BlendState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::BlendModeEffect *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v9; // rbx
  bool v10; // zf
  __int64 v11; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-79h]
  Scaleform::Render::Rect<float> returnBounds; // [rsp+40h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+50h] [rbp-59h]
  int Dst; // [rsp+70h] [rbp-39h]
  int v17; // [rsp+84h] [rbp-25h]
  int v18; // [rsp+98h] [rbp-11h]
  __int64 v19; // [rsp+A0h] [rbp-9h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+B0h] [rbp+7h]
  int v21; // [rsp+128h] [rbp+7Fh]

  v19 = -2i64;
  v3 = next;
  v4 = (Scaleform::Render::BlendState *)stateArg;
  v5 = node;
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v17 = 1065353216;
  v18 = 1065353216;
  memset(&pviewProj, 0, 0x40ui64);
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
  *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  returnBounds = 0i64;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(v5, (Scaleform::Render::Matrix3x4<float> *)&Dst, &pviewProj);
  if ( Scaleform::Render::TreeCacheNode::calcCacheableBounds(
         v5,
         &returnBounds,
         &areaMatrix,
         (Scaleform::Render::Matrix3x4<float> *)&Dst,
         &pviewProj,
         0i64) == CacheableBoundResult_CompletelyClipped )
  {
    *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
    *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  }
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&v5->pRenderer2D->MPool, &result, &areaMatrix, 0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(
    &result,
    (Scaleform::Render::Cxform *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                             + 8
                                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5->pNode[-1] - ((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5->pNode[-1] - ((_QWORD)v5->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                             + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                + 80));
  v21 = 71;
  v6 = (Scaleform::Render::BlendModeEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               v5,
                                               160ui64,
                                               (Scaleform::AllocInfo *)&v21);
  *(_QWORD *)&returnBounds.x1 = v6;
  if ( v6 )
  {
    Scaleform::Render::BlendModeEffect::BlendModeEffect(v6, v5, &result, v4, v3);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v9 = result.pHandle->pHeader;
    v10 = result.pHandle->pHeader->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
    {
      v11 = v9->DataPageOffset;
      *(_WORD *)((char *)&v9[1].RefCount + v11 + 2) += 16 * (unsigned __int8)v9->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v9[1].pHandle + v11))[5].pHeader += (unsigned __int8)v9->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v9->pHandle);
      v9->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v8;
}

// File Line: 378
// RVA: 0x93BCD0
void __fastcall Scaleform::Render::FilterEffect::FilterEffect(Scaleform::Render::FilterEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::MatrixPoolImpl::HMatrix *m, Scaleform::Render::FilterState *state, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::FilterState *v5; // rbp
  Scaleform::Render::MatrixPoolImpl::HMatrix *v6; // r12
  Scaleform::Render::TreeCacheNode *v7; // r14
  Scaleform::Render::FilterEffect *v8; // r15
  unsigned int v9; // esi
  Scaleform::Render::CacheEffect *v10; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v11; // rax
  _QWORD *v12; // rax
  __int64 v13; // rbx
  int v14; // eax
  Scaleform::Render::Image *v15; // rdi
  __int64 v16; // rcx
  Scaleform::Render::Matrix2x4<float> ma; // [rsp+40h] [rbp-48h]
  Scaleform::Render::CacheEffect *nexta; // [rsp+B0h] [rbp+28h]
  Scaleform::Render::CacheEffect *nextb; // [rsp+B0h] [rbp+28h]

  v5 = state;
  v6 = m;
  v7 = node;
  v8 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  v9 = 0;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::FilterEffect::`vftable;
  this->Contributing = 1;
  v10 = (Scaleform::Render::CacheEffect *)state->pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    (void *)state->DataValue);
  nexta = (Scaleform::Render::CacheEffect *)&v8->StartEntry;
  *(_OWORD *)&nexta->vfptr = 0ui64;
  nexta->Length = 0;
  nexta[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::SKI_Filter::Start_Instance;
  nexta[1].pNext = v10;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    v10);
  v8->StartEntry.pBundle.pObject = 0i64;
  v8->StartEntry.pSourceNode = v7;
  v8->StartEntry.Removed = 0;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    v10);
  *(_QWORD *)&ma.M[0][0] = &Scaleform::Render::SKI_Filter::End_Instance;
  *(_QWORD *)&ma.M[0][2] = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  nextb = (Scaleform::Render::CacheEffect *)&v8->EndEntry;
  *(_OWORD *)&nextb->vfptr = 0ui64;
  nextb->Length = 0;
  nextb[1].vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::SKI_Filter::End_Instance;
  nextb[1].pNext = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  v8->EndEntry.pBundle.pObject = 0i64;
  v8->EndEntry.pSourceNode = v7;
  v8->EndEntry.Removed = 0;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  v11 = v6->pHandle;
  v8->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)v6->pHandle;
  if ( v11 != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++v11->pHeader->RefCount;
  *(_OWORD *)&ma.M[0][0] = 0i64;
  *(_OWORD *)&ma.M[1][0] = 0i64;
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&v8->BoundsMatrix, &ma, 1u);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(
    &v8->BoundsMatrix,
    &v6->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v6->pHandle->pHeader->Format & 0xF].Offsets[4]
                        + 1],
    0x20ui64);
  v12 = v5->pData;
  if ( *((_DWORD *)v12 + 6) )
  {
    do
    {
      v13 = *(_QWORD *)(v12[2] + 8i64 * v9);
      v14 = *(_DWORD *)(v13 + 16);
      if ( v14 == 5 || v14 == 4 )
      {
        v15 = Scaleform::Render::PrimitiveFillManager::createGradientImage(
                &v7->pRenderer2D->FillManager,
                *(Scaleform::Render::GradientData **)(v13 + 64),
                0.0);
        v16 = *(_QWORD *)(v13 + 80);
        if ( v16 )
          (*(void (__cdecl **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
        *(_QWORD *)(v13 + 80) = v15;
      }
      ++v9;
      v12 = v5->pData;
    }
    while ( v9 < *((_DWORD *)v12 + 6) );
  }
}

// File Line: 400
// RVA: 0x9BEC00
bool __fastcall Scaleform::Render::FilterEffect::UpdateMatrix(Scaleform::Render::FilterEffect *this, Scaleform::Render::Matrix2x4<float> *boundsMatrix, Scaleform::Render::Matrix2x4<float> *newNodeMatrix, bool forceUncache)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *v4; // r12
  Scaleform::Render::Matrix2x4<float> *v5; // rdi
  char v6; // r13
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v7; // rax
  Scaleform::Render::Matrix2x4<float> *v8; // r15
  Scaleform::Render::MatrixPoolImpl::DataHeader *v9; // rbx
  char v10; // dl
  Scaleform::Render::Matrix2x4<float> *v11; // rsi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  bool v15; // r13
  float v16; // xmm3_4
  __m128 v17; // xmm4
  float v18; // xmm7_4
  __m128 v19; // xmm1
  __m128 v20; // xmm8
  float v21; // xmm5_4
  __m128 v22; // xmm1
  float v23; // xmm2_4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  float v26; // xmm5_4
  float v27; // xmm1_4
  bool v28; // si
  float v29; // xmm9_4
  float v30; // xmm0_4
  char v31; // al
  float v32; // xmm1_4
  int v33; // eax
  __int64 v34; // rcx
  float v35; // xmm2_4
  float v36; // xmm2_4
  char v37; // al
  float v38; // xmm7_4
  char v39; // r13
  __m128 v40; // xmm1
  __m128 v41; // xmm8
  float v42; // xmm5_4
  __m128 v43; // xmm1
  float v44; // xmm2_4
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  float v47; // xmm5_4
  float v48; // xmm1_4
  char v49; // al
  char v50; // si
  float v51; // xmm9_4
  float v52; // xmm0_4
  char v53; // al
  Scaleform::Render::MatrixPoolImpl::DataHeader *v54; // rdx
  char v55; // r8
  signed __int64 v56; // rcx
  unsigned int v57; // xmm1_4
  unsigned int v58; // xmm0_4
  Scaleform::Render::Matrix2x4<float> *v59; // rax
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm4_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  Scaleform::Render::Matrix2x4<float> *v67; // rdx
  __m128 v68; // xmm7
  __m128 v69; // xmm8
  __m128 v70; // xmm5
  __m128 v71; // xmm6
  __m128 v72; // xmm0
  __m128 v74; // [rsp+20h] [rbp-79h]
  __m128 v75; // [rsp+30h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> v76; // [rsp+40h] [rbp-59h]
  __int128 Buf2; // [rsp+60h] [rbp-39h]
  __int128 v78; // [rsp+70h] [rbp-29h]
  Scaleform::Render::FilterEffect *v79; // [rsp+100h] [rbp+67h]
  bool v80; // [rsp+118h] [rbp+7Fh]

  v79 = this;
  v4 = &this->BoundsMatrix;
  v5 = boundsMatrix;
  v6 = 0;
  v7 = this->BoundsMatrix.pHandle;
  v8 = newNodeMatrix;
  v9 = v7->pHeader;
  v10 = v7->pHeader->Format;
  if ( v10 & 4 )
    v11 = (Scaleform::Render::Matrix2x4<float> *)&v9[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[2]
                                                   + 1];
  else
    v11 = &Scaleform::Render::Matrix2x4<float>::Identity;
  Buf2 = 0i64;
  v78 = 0i64;
  if ( forceUncache || !(v10 & 4) || !memcmp(v11, &Buf2, 0x20ui64) )
    goto LABEL_47;
  v12 = v8->M[0][3];
  v13 = v11->M[0][3];
  v15 = 1;
  if ( (float)(v12 + 0.000099999997) >= v13 && (float)(v12 - 0.000099999997) <= v13 )
  {
    v14 = v11->M[1][3];
    if ( (float)(v8->M[1][3] + 0.000099999997) >= v14 && (float)(v8->M[1][3] - 0.000099999997) <= v14 )
      v15 = 0;
  }
  v16 = v11->M[1][0];
  v17 = (__m128)LODWORD(v11->M[0][0]);
  v18 = v8->M[1][0];
  v19 = v17;
  v20 = (__m128)LODWORD(v8->M[0][0]);
  v19.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16);
  LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v19);
  v22 = v20;
  v22.m128_f32[0] = (float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v18 * v18);
  LODWORD(v23) = (unsigned __int128)_mm_sqrt_ps(v22);
  v28 = 1;
  if ( (float)(v23 + 0.000099999997) >= v21 && (float)(v23 - 0.000099999997) <= v21 )
  {
    v24 = (__m128)LODWORD(v11->M[0][1]);
    v24.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v11->M[1][1] * v11->M[1][1]);
    v25 = (__m128)LODWORD(v8->M[0][1]);
    LODWORD(v26) = (unsigned __int128)_mm_sqrt_ps(v24);
    v25.m128_f32[0] = (float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v8->M[1][1] * v8->M[1][1]);
    LODWORD(v27) = (unsigned __int128)_mm_sqrt_ps(v25);
    if ( (float)(v27 + 0.000099999997) >= v26 && (float)(v27 - 0.000099999997) <= v26 )
      v28 = 0;
  }
  v29 = atan2f(v16, v17.m128_f32[0]);
  v30 = atan2f(v18, v20.m128_f32[0]);
  if ( (float)(v30 + 0.000099999997) < v29 || (v31 = 1, (float)(v30 - 0.000099999997) > v29) )
    v31 = 0;
  v32 = v5->M[0][3];
  v80 = v31 == 0;
  v33 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v9->Format & 0xF].Offsets[4];
  v34 = v33 * 16;
  v35 = *(float *)&v9[v33 + 1].DataPageOffset;
  if ( (float)(v32 + 0.000099999997) < v35
    || (float)(v32 - 0.000099999997) > v35
    || (v36 = *(float *)&v9[v33 + 2].DataPageOffset, (float)(v5->M[1][3] + 0.000099999997) < v36)
    || (v37 = 0, (float)(v5->M[1][3] - 0.000099999997) > v36) )
  {
    v37 = 1;
  }
  v38 = v5->M[1][0];
  v39 = v37 | v15;
  v40 = (__m128)*(unsigned int *)((char *)&v9[1].pHandle + v34);
  v41 = (__m128)LODWORD(v5->M[0][0]);
  v40.m128_f32[0] = (float)(v40.m128_f32[0] * v40.m128_f32[0])
                  + (float)(*(float *)((char *)&v9[2].pHandle + v34) * *(float *)((char *)&v9[2].pHandle + v34));
  LODWORD(v42) = (unsigned __int128)_mm_sqrt_ps(v40);
  v43 = v41;
  v43.m128_f32[0] = (float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v38 * v38);
  LODWORD(v44) = (unsigned __int128)_mm_sqrt_ps(v43);
  if ( (float)(v44 + 0.000099999997) < v42
    || (float)(v44 - 0.000099999997) > v42
    || (v45 = (__m128)*(unsigned int *)((char *)&v9[1].pHandle + v34 + 4),
        v45.m128_f32[0] = (float)(v45.m128_f32[0] * v45.m128_f32[0])
                        + (float)(*(float *)((char *)&v9[2].pHandle + v34 + 4)
                                * *(float *)((char *)&v9[2].pHandle + v34 + 4)),
        v46 = (__m128)LODWORD(v5->M[0][1]),
        LODWORD(v47) = (unsigned __int128)_mm_sqrt_ps(v45),
        v46.m128_f32[0] = (float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v5->M[1][1] * v5->M[1][1]),
        LODWORD(v48) = (unsigned __int128)_mm_sqrt_ps(v46),
        (float)(v48 + 0.000099999997) < v47)
    || (v49 = 0, (float)(v48 - 0.000099999997) > v47) )
  {
    v49 = 1;
  }
  v50 = v49 | v28;
  v51 = atan2f(*(float *)((char *)&v9[2].pHandle + v34), *(float *)((char *)&v9[1].pHandle + v34));
  v52 = atan2f(v38, v41.m128_f32[0]);
  if ( (float)(v52 + 0.000099999997) < v51 || (v53 = 1, (float)(v52 - 0.000099999997) > v51) )
    v53 = 0;
  v6 = Scaleform::Render::FilterSet::CanCacheAcrossTransform(
         (Scaleform::Render::FilterSet *)v79->StartEntry.Key.Data,
         v39,
         v80 || v53 == 0,
         v50);
  if ( !v6 )
  {
LABEL_47:
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(v4, v8, 1u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(v4, v5, 0x20ui64);
    v67 = v5;
  }
  else
  {
    v54 = v4->pHandle->pHeader;
    v55 = v54->Format;
    if ( v55 & 8 )
      v56 = (signed __int64)&v54[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v54->Format & 0xF].Offsets[3]
                               + 1];
    else
      v56 = 0i64;
    v57 = *(_DWORD *)(v56 + 4);
    v74.m128_i32[0] = *(_DWORD *)v56;
    *(unsigned __int64 *)((char *)v74.m128_u64 + 4) = __PAIR__(*(_DWORD *)(v56 + 8), v57);
    v58 = *(_DWORD *)(v56 + 16);
    v74.m128_i32[3] = *(_DWORD *)(v56 + 12);
    v75.m128_u64[0] = __PAIR__(*(_DWORD *)(v56 + 20), v58);
    v75.m128_u64[1] = *(_QWORD *)(v56 + 24);
    if ( v55 & 4 )
      v59 = (Scaleform::Render::Matrix2x4<float> *)&v54[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v54->Format & 0xF].Offsets[2]
                                                      + 1];
    else
      v59 = &Scaleform::Render::Matrix2x4<float>::Identity;
    v60 = v59->M[0][1];
    v61 = v59->M[0][2];
    v62 = v59->M[0][3];
    v63 = v59->M[1][0];
    v64 = v59->M[1][1];
    v65 = v59->M[1][2];
    v66 = v59->M[1][3];
    v76.M[0][0] = v59->M[0][0];
    *(_QWORD *)&v76.M[0][1] = __PAIR__(LODWORD(v61), LODWORD(v60));
    v76.M[0][3] = v62;
    *(_QWORD *)&v76.M[1][0] = __PAIR__(LODWORD(v64), LODWORD(v63));
    *(_QWORD *)&v76.M[1][2] = __PAIR__(LODWORD(v66), LODWORD(v65));
    *(_QWORD *)&Buf2 = __PAIR__(LODWORD(v60), LODWORD(v76.M[0][0]));
    *((_QWORD *)&Buf2 + 1) = __PAIR__(LODWORD(v62), LODWORD(v61));
    *(_QWORD *)&v78 = __PAIR__(LODWORD(v64), LODWORD(v63));
    *((_QWORD *)&v78 + 1) = __PAIR__(LODWORD(v66), LODWORD(v65));
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v76, (Scaleform::Render::Matrix2x4<float> *)&Buf2);
    v67 = (Scaleform::Render::Matrix2x4<float> *)&v74;
    v68 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    v69 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    v70 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&v8->M[0][0], *(__m128 *)&v8->M[0][0], 85),
                  *(__m128 *)&v76.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v8->M[0][0], *(__m128 *)&v8->M[0][0], 0), *(__m128 *)&v76.M[0][0])),
              _mm_and_ps(*(__m128 *)&v8->M[0][0], v68)),
            v69);
    v71 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&v8->M[1][0], *(__m128 *)&v8->M[1][0], 85),
                  *(__m128 *)&v76.M[1][0]),
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v8->M[1][0], *(__m128 *)&v8->M[1][0], 0), *(__m128 *)&v76.M[0][0])),
              _mm_and_ps(*(__m128 *)&v8->M[1][0], v68)),
            v69);
    v72 = _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v74);
    v74 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 85), v75), _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v74)),
              _mm_and_ps(v70, v68)),
            v69);
    v75 = _mm_and_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v75), v72), _mm_and_ps(v71, v68)),
            v69);
  }
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(v4, v67);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(v4, v5, 0);
  return v6 == 0;
}

// File Line: 471
// RVA: 0x9BBEE0
char __fastcall Scaleform::Render::FilterEffect::Update(Scaleform::Render::FilterEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::State *v2; // rbx
  Scaleform::Render::FilterEffect *v3; // rdi
  void *v4; // ST30_8

  v2 = stateArg;
  v3 = this;
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::BundleEntry::ClearBundle(&v3->EndEntry);
  v4 = v2->pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    v4);
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    v4);
  v3->StartEntry.Key.pImpl->vfptr->Release(v3->StartEntry.Key.pImpl, v3->StartEntry.Key.Data);
  v3->StartEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance;
  v3->StartEntry.Key.Data = v4;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::Start_Instance,
    v4);
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  v3->EndEntry.Key.pImpl->vfptr->Release(v3->EndEntry.Key.pImpl, v3->EndEntry.Key.Data);
  v3->EndEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance;
  v3->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_Filter::End_Instance,
    0i64);
  return 1;
}

// File Line: 486
// RVA: 0x95DF10
void __fastcall Scaleform::Render::FilterEffect::ChainNext(Scaleform::Render::FilterEffect *this, Scaleform::Render::BundleEntryRange *chain, Scaleform::Render::BundleEntryRange *__formal)
{
  Scaleform::Render::FilterEffect *v3; // rbx
  Scaleform::Render::FilterSet *v4; // rcx
  Scaleform::Render::BundleEntryRange *v5; // rdi
  bool v6; // zf
  char v7; // al
  Scaleform::Render::BundleEntry *v8; // rax
  signed __int64 v9; // rdx
  int v10; // eax

  v3 = this;
  v4 = (Scaleform::Render::FilterSet *)this->StartEntry.Key.Data;
  v5 = chain;
  if ( !v4 || (v6 = Scaleform::Render::FilterSet::IsContributing(v4) == 0, v7 = 1, v6) )
    v7 = 0;
  v3->Contributing = v7;
  v6 = v7 == 0;
  v8 = v5->pFirst;
  if ( v6 )
  {
    v3->StartEntry.pNextPattern = v8;
    v3->EndEntry.pNextPattern = v5->pLast;
    v3->Length = v5->Length & 0x7FFFFFFF;
  }
  else
  {
    v3->StartEntry.pNextPattern = v8;
    v3->StartEntry.pChain = 0i64;
    v3->StartEntry.ChainHeight = 0;
    v9 = (signed __int64)&v3->EndEntry;
    v5->pLast->pNextPattern = &v3->EndEntry;
    *(_QWORD *)(v9 + 8) = 0i64;
    *(_WORD *)(v9 + 16) = 0;
    v10 = (v5->Length & 0x7FFFFFFF) + 2;
    v3->Length = v10;
    v5->pFirst = &v3->StartEntry;
    v5->pLast = &v3->EndEntry;
    v5->Length = v10;
  }
}

// File Line: 506
// RVA: 0x98ADB0
void __fastcall Scaleform::Render::FilterEffect::GetRange(Scaleform::Render::FilterEffect *this, Scaleform::Render::BundleEntryRange *result)
{
  Scaleform::Render::BundleEntryRange *v2; // r10
  Scaleform::Render::FilterEffect *v3; // r9
  unsigned int v4; // er8
  Scaleform::Render::BundleEntry *v5; // rcx
  unsigned int v6; // edx

  v2 = result;
  v3 = this;
  if ( this->Contributing )
  {
    v4 = this->Length;
    result->pFirst = &this->StartEntry;
    result->Length = v4;
    result->pLast = &this->EndEntry;
  }
  else
  {
    v5 = this->EndEntry.pNextPattern;
    v6 = v3->Length;
    v2->pFirst = v3->StartEntry.pNextPattern;
    v2->pLast = v5;
    v2->Length = v6;
  }
}

// File Line: 514
// RVA: 0x928AC0
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::FilterEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *stateArg, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::FilterState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v6; // rax
  unsigned __int8 v7; // dl
  Scaleform::Render::MatrixPoolImpl::DataHeader *v8; // rdx
  signed __int64 v9; // rcx
  Scaleform::Render::FilterEffect *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *v13; // rbx
  bool v14; // zf
  __int64 v15; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-D0h]
  Scaleform::Render::Cxform dest; // [rsp+40h] [rbp-C0h]
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+60h] [rbp-A0h]
  Scaleform::Render::Rect<float> returnBounds; // [rsp+80h] [rbp-80h]
  int Dst; // [rsp+90h] [rbp-70h]
  int v22; // [rsp+A4h] [rbp-5Ch]
  int v23; // [rsp+B8h] [rbp-48h]
  __int64 v24; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+D0h] [rbp-30h]
  int v26; // [rsp+148h] [rbp+48h]

  v24 = -2i64;
  v3 = next;
  v4 = (Scaleform::Render::FilterState *)stateArg;
  v5 = node;
  returnBounds = 0i64;
  *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
  *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  *(_OWORD *)&dest.M[0][0] = *(_OWORD *)_xmm;
  *(_OWORD *)&dest.M[1][0] = 0i64;
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v22 = 1065353216;
  v23 = 1065353216;
  memset(&pviewProj, 0, 0x40ui64);
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(v5, (Scaleform::Render::Matrix3x4<float> *)&Dst, &pviewProj);
  Scaleform::Render::TreeCacheNode::CalcCxform(v5, &dest);
  if ( Scaleform::Render::TreeCacheNode::calcCacheableBounds(
         v5,
         &returnBounds,
         &areaMatrix,
         (Scaleform::Render::Matrix3x4<float> *)&Dst,
         &pviewProj,
         0i64) == CacheableBoundResult_CompletelyClipped )
  {
    *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
    *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  }
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&v5->pRenderer2D->MPool, &result, &areaMatrix, 0);
  v6 = result.pHandle;
  v7 = result.pHandle->pHeader->Format;
  if ( !(v7 & 1) )
  {
    if ( dest.M[0][0] == Scaleform::Render::Cxform::Identity.M[0][0]
      && dest.M[0][1] == Scaleform::Render::Cxform::Identity.M[0][1]
      && dest.M[0][2] == Scaleform::Render::Cxform::Identity.M[0][2]
      && dest.M[0][3] == Scaleform::Render::Cxform::Identity.M[0][3]
      && dest.M[1][0] == Scaleform::Render::Cxform::Identity.M[1][0]
      && dest.M[1][1] == Scaleform::Render::Cxform::Identity.M[1][1]
      && dest.M[1][2] == Scaleform::Render::Cxform::Identity.M[1][2]
      && dest.M[1][3] == Scaleform::Render::Cxform::Identity.M[1][3] )
    {
      goto LABEL_14;
    }
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)result.pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      result.pHandle,
      v7 | 1);
    v6 = result.pHandle;
  }
  v8 = v6->pHeader;
  v9 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v6->pHeader->Format & 0xF].Offsets[0]
     + 1i64;
  v8[v9] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&dest.M[0][0];
  v8[v9 + 1] = *(Scaleform::Render::MatrixPoolImpl::DataHeader *)&dest.M[1][0];
LABEL_14:
  v26 = 71;
  v10 = (Scaleform::Render::FilterEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             v5,
                                             168ui64,
                                             (Scaleform::AllocInfo *)&v26);
  *(_QWORD *)&returnBounds.x1 = v10;
  if ( v10 )
  {
    Scaleform::Render::FilterEffect::FilterEffect(v10, v5, &result, v4, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    v13 = result.pHandle->pHeader;
    v14 = result.pHandle->pHeader->RefCount == 1;
    --v13->RefCount;
    if ( v14 )
    {
      v15 = v13->DataPageOffset;
      *(_WORD *)((char *)&v13[1].RefCount + v15 + 2) += 16 * (unsigned __int8)v13->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&v13[1].pHandle + v15))[5].pHeader += (unsigned __int8)v13->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(v13->pHandle);
      v13->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v12;
}

// File Line: 543
// RVA: 0x946FB0
void __fastcall Scaleform::Render::ViewMatrix3DEffect::ViewMatrix3DEffect(Scaleform::Render::ViewMatrix3DEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::ViewMatrix3DState *state, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::TreeCacheNode *v4; // rsi
  Scaleform::Render::ViewMatrix3DEffect *v5; // r14
  void *v6; // rdi
  signed __int64 v7; // [rsp+88h] [rbp+10h]
  signed __int64 v8; // [rsp+88h] [rbp+10h]

  v4 = node;
  v5 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::ViewMatrix3DEffect::`vftable;
  v6 = state->pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    (void *)state->DataValue);
  v7 = (signed __int64)&v5->StartEntry;
  *(_OWORD *)v7 = 0ui64;
  *(_DWORD *)(v7 + 16) = 0;
  *(_QWORD *)(v7 + 24) = &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance;
  *(_QWORD *)(v7 + 32) = v6;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    v6);
  v5->StartEntry.pBundle.pObject = 0i64;
  v5->StartEntry.pSourceNode = v4;
  v5->StartEntry.Removed = 0;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    v6);
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
  v8 = (signed __int64)&v5->EndEntry;
  *(_OWORD *)v8 = 0ui64;
  *(_DWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 24) = &Scaleform::Render::SKI_ViewMatrix3D::End_Instance;
  *(_QWORD *)(v8 + 32) = 0i64;
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
  v5->EndEntry.pBundle.pObject = 0i64;
  v5->EndEntry.pSourceNode = v4;
  v5->EndEntry.Removed = 0;
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
}

// File Line: 547
// RVA: 0x9BCCB0
char __fastcall Scaleform::Render::ViewMatrix3DEffect::Update(Scaleform::Render::ViewMatrix3DEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::State *v2; // rbx
  Scaleform::Render::ViewMatrix3DEffect *v3; // rdi
  void *v4; // ST30_8

  v2 = stateArg;
  v3 = this;
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  v4 = v2->pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    v4);
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    v4);
  v3->StartEntry.Key.pImpl->vfptr->Release(v3->StartEntry.Key.pImpl, v3->StartEntry.Key.Data);
  v3->StartEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance;
  v3->StartEntry.Key.Data = v4;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    v4);
  return 1;
}

// File Line: 568
// RVA: 0x928D80
void __fastcall Scaleform::Render::ViewMatrix3DEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *stateArg, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::ViewMatrix3DState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::ViewMatrix3DEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h]
  Scaleform::Render::ViewMatrix3DEffect *v8; // [rsp+68h] [rbp+20h]

  v3 = next;
  v4 = (Scaleform::Render::ViewMatrix3DState *)stateArg;
  v5 = node;
  v7 = 71;
  v6 = (Scaleform::Render::ViewMatrix3DEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  node,
                                                  152i64,
                                                  &v7,
                                                  -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::ViewMatrix3DEffect::ViewMatrix3DEffect(v6, v5, v4, v3);
}

// File Line: 581
// RVA: 0x940C70
void __fastcall Scaleform::Render::ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(Scaleform::Render::ProjectionMatrix3DEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::ProjectionMatrix3DState *state, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::TreeCacheNode *v4; // rsi
  Scaleform::Render::ProjectionMatrix3DEffect *v5; // r14
  void *v6; // rdi
  signed __int64 v7; // [rsp+88h] [rbp+10h]
  signed __int64 v8; // [rsp+88h] [rbp+10h]

  v4 = node;
  v5 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::ProjectionMatrix3DEffect::`vftable;
  v6 = state->pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    (void *)state->DataValue);
  v7 = (signed __int64)&v5->StartEntry;
  *(_OWORD *)v7 = 0ui64;
  *(_DWORD *)(v7 + 16) = 0;
  *(_QWORD *)(v7 + 24) = &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance;
  *(_QWORD *)(v7 + 32) = v6;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    v6);
  v5->StartEntry.pBundle.pObject = 0i64;
  v5->StartEntry.pSourceNode = v4;
  v5->StartEntry.Removed = 0;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    v6);
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
  v8 = (signed __int64)&v5->EndEntry;
  *(_OWORD *)v8 = 0ui64;
  *(_DWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 24) = &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance;
  *(_QWORD *)(v8 + 32) = 0i64;
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
  v5->EndEntry.pBundle.pObject = 0i64;
  v5->EndEntry.pSourceNode = v4;
  v5->EndEntry.Removed = 0;
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
}

// File Line: 586
// RVA: 0x9BC170
char __fastcall Scaleform::Render::ProjectionMatrix3DEffect::Update(Scaleform::Render::ProjectionMatrix3DEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::State *v2; // rbx
  Scaleform::Render::ProjectionMatrix3DEffect *v3; // rdi
  void *v4; // ST30_8

  v2 = stateArg;
  v3 = this;
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  v4 = v2->pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    v4);
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    v4);
  v3->StartEntry.Key.pImpl->vfptr->Release(v3->StartEntry.Key.pImpl, v3->StartEntry.Key.Data);
  v3->StartEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance;
  v3->StartEntry.Key.Data = v4;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    v4);
  return 1;
}

// File Line: 607
// RVA: 0x928DF0
void __fastcall Scaleform::Render::ProjectionMatrix3DEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *stateArg, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::ProjectionMatrix3DState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::ProjectionMatrix3DEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h]
  Scaleform::Render::ProjectionMatrix3DEffect *v8; // [rsp+68h] [rbp+20h]

  v3 = next;
  v4 = (Scaleform::Render::ProjectionMatrix3DState *)stateArg;
  v5 = node;
  v7 = 71;
  v6 = (Scaleform::Render::ProjectionMatrix3DEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        node,
                                                        152i64,
                                                        &v7,
                                                        -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(v6, v5, v4, v3);
}

// File Line: 620
// RVA: 0x946BD0
void __fastcall Scaleform::Render::UserDataEffect::UserDataEffect(Scaleform::Render::UserDataEffect *this, Scaleform::Render::TreeCacheNode *node, Scaleform::Render::UserDataState *state, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::UserDataState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rdi
  Scaleform::Render::UserDataEffect *v6; // r14
  signed __int64 v7; // [rsp+88h] [rbp+10h]
  signed __int64 v8; // [rsp+88h] [rbp+10h]

  v4 = state;
  v5 = node;
  v6 = this;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::UserDataEffect::`vftable;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    0i64);
  v7 = (signed __int64)&v6->StartEntry;
  *(_OWORD *)v7 = 0ui64;
  *(_DWORD *)(v7 + 16) = 0;
  *(_QWORD *)(v7 + 24) = &Scaleform::Render::SKI_UserData::Start_Instance;
  *(_QWORD *)(v7 + 32) = 0i64;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    0i64);
  v6->StartEntry.pBundle.pObject = 0i64;
  v6->StartEntry.pSourceNode = v5;
  v6->StartEntry.Removed = 0;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    0i64);
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::End_Instance,
    0i64);
  v8 = (signed __int64)&v6->EndEntry;
  *(_OWORD *)v8 = 0ui64;
  *(_DWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 24) = &Scaleform::Render::SKI_UserData::End_Instance;
  *(_QWORD *)(v8 + 32) = 0i64;
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::End_Instance,
    0i64);
  v6->EndEntry.pBundle.pObject = 0i64;
  v6->EndEntry.pSourceNode = v5;
  v6->EndEntry.Removed = 0;
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::End_Instance,
    0i64);
  Scaleform::Render::UserDataEffect::rebuildBundles(v6, v4);
}

// File Line: 625
// RVA: 0x9BCC70
char __fastcall Scaleform::Render::UserDataEffect::Update(Scaleform::Render::UserDataEffect *this, Scaleform::Render::State *stateArg)
{
  Scaleform::Render::UserDataEffect *v2; // rdi
  Scaleform::Render::UserDataState *v3; // rbx

  v2 = this;
  v3 = (Scaleform::Render::UserDataState *)stateArg;
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::UserDataEffect::rebuildBundles(v2, v3);
  return 1;
}

// File Line: 646
// RVA: 0x928E60
void __fastcall Scaleform::Render::UserDataEffect::Create(Scaleform::Render::TreeCacheNode *node, Scaleform::Render::State *stateArg, Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::CacheEffect *v3; // rdi
  Scaleform::Render::UserDataState *v4; // rsi
  Scaleform::Render::TreeCacheNode *v5; // rbx
  Scaleform::Render::UserDataEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h]
  Scaleform::Render::UserDataEffect *v8; // [rsp+68h] [rbp+20h]

  v3 = next;
  v4 = (Scaleform::Render::UserDataState *)stateArg;
  v5 = node;
  v7 = 71;
  v6 = (Scaleform::Render::UserDataEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              node,
                                              152i64,
                                              &v7,
                                              -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::UserDataEffect::UserDataEffect(v6, v5, v4, v3);
}

// File Line: 653
// RVA: 0x9EF350
void __fastcall Scaleform::Render::UserDataEffect::rebuildBundles(Scaleform::Render::UserDataEffect *this, Scaleform::Render::UserDataState *state)
{
  Scaleform::Render::UserDataEffect *v2; // rbx
  void *v3; // rdi

  v2 = this;
  v3 = state->pData;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    (void *)state->DataValue);
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    v3);
  v2->StartEntry.Key.pImpl->vfptr->Release(v2->StartEntry.Key.pImpl, v2->StartEntry.Key.Data);
  v2->StartEntry.Key.pImpl = (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance;
  v2->StartEntry.Key.Data = v3;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->Release(
    (Scaleform::Render::SortKeyInterface *)&Scaleform::Render::SKI_UserData::Start_Instance,
    v3);
}

