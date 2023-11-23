// File Line: 32
// RVA: 0x9403F0
void __fastcall Scaleform::Render::TreeText::NodeData::NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable;
  *(_DWORD *)&this->Type = 65541;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable;
  memset(&this->M34, 0, sizeof(this->M34));
  this->M34.M[0][0] = 1.0;
  this->M34.M[1][1] = 1.0;
  this->M34.M[2][2] = 1.0;
  this->States.ArraySize = 0i64;
  this->States.DataValue = 0i64;
  this->Cx.M[0][0] = 1.0;
  this->Cx.M[0][1] = 1.0;
  this->Cx.M[0][2] = 1.0;
  *(_QWORD *)&this->Cx.M[0][3] = 1065353216i64;
  *(_QWORD *)&this->Cx.M[1][1] = 0i64;
  *(_QWORD *)&this->Cx.M[1][3] = 0i64;
  *(_QWORD *)&this->AproxLocalBounds.y1 = 0i64;
  *(_QWORD *)&this->AproxLocalBounds.y2 = 0i64;
  *(_QWORD *)&this->AproxParentBounds.y1 = 0i64;
  this->AproxParentBounds.y2 = 0.0;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable;
  this->pDocView.pObject = 0i64;
  this->pLayout.pObject = 0i64;
  this->TextFlags = 0;
}

// File Line: 38
// RVA: 0x940340
void __fastcall Scaleform::Render::TreeText::NodeData::NodeData(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData> src)
{
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // r8
  void *(__fastcall *vecDelDtor)(Scaleform::Render::ContextImpl::EntryData *, unsigned int); // rdx
  Scaleform::Render::ContextImpl::EntryDataVtbl *v6; // rdx
  Scaleform::Render::ContextImpl::EntryData *(__fastcall *ConstructCopy)(Scaleform::Render::ContextImpl::EntryData *, Scaleform::Render::LinearHeap *); // rax
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> srca; // [rsp+48h] [rbp+10h] BYREF

  srca.pC = (Scaleform::Render::TreeNode::NodeData *)src.pC->vfptr;
  Scaleform::Render::TreeNode::NodeData::NodeData(
    this,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&srca);
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable;
  vfptr = src.pC->vfptr;
  vecDelDtor = src.pC->vfptr[3].__vecDelDtor;
  if ( vecDelDtor )
    _InterlockedExchangeAdd((volatile signed __int32 *)vecDelDtor + 2, 1u);
  this->pDocView.pObject = (Scaleform::Render::Text::DocView *)vfptr[3].__vecDelDtor;
  v6 = src.pC->vfptr;
  ConstructCopy = src.pC->vfptr[3].ConstructCopy;
  if ( ConstructCopy )
    _InterlockedExchangeAdd((volatile signed __int32 *)ConstructCopy + 2, 1u);
  this->pLayout.pObject = (Scaleform::Render::TextLayout *)v6[3].ConstructCopy;
  this->TextFlags = (char)src.pC->vfptr[3].CopyTo;
}

// File Line: 43
// RVA: 0x94BB40
void __fastcall Scaleform::Render::TreeText::NodeData::~NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  Scaleform::Render::TextLayout *pObject; // rcx
  Scaleform::Render::Text::DocView *v3; // rcx
  Scaleform::Render::StateData::Interface *pInterface; // rcx

  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable;
  pObject = this->pLayout.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v3 = this->pDocView.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
    v3->vfptr->__vecDelDtor(v3, 1u);
  pInterface = this->States.pInterface;
  if ( pInterface )
  {
    if ( ((unsigned __int8)pInterface & 1) != 0 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, __int64))(*(_QWORD *)((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64)
                                                                          + 16i64))(
        (unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64,
        this->States.DataValue,
        1i64);
    else
      Scaleform::Render::StateData::ArrayData::Release(this->States.pArray, (unsigned __int64)pInterface >> 1);
    this->States.ArraySize = 0i64;
    this->States.DataValue = 0i64;
  }
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable;
}

// File Line: 47
// RVA: 0x9A10F0
bool __fastcall Scaleform::Render::TreeText::NodeData::PropagateUp(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::Text::DocView *pObject; // rcx
  unsigned int v5; // ebx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rsi
  Scaleform::Render::TextLayout *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  __int64 v10; // rcx
  Scaleform::Render::TextLayout *v11; // rax
  float x1; // xmm6_4
  float y1; // xmm7_4
  float x2; // xmm8_4
  float y2; // xmm9_4
  Scaleform::Render::StateBag *v16; // rax
  _QWORD *pData; // rsi
  __m128 v18; // xmm4
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  float v28; // xmm10_4
  float v29; // xmm11_4
  float v30; // xmm12_4
  float v31; // xmm13_4
  __int16 v32; // ax
  Scaleform::Render::ContextImpl::EntryData *v33; // rax
  Scaleform::Render::Rect<float> bounds; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::Render::Rect<float> v37; // [rsp+40h] [rbp-98h] BYREF
  __int64 v38; // [rsp+50h] [rbp-88h]
  Scaleform::Render::TextLayout::Builder bld; // [rsp+60h] [rbp-78h] BYREF
  int v40; // [rsp+8E8h] [rbp+810h] BYREF
  Scaleform::Render::TextLayout *vars0; // [rsp+8F0h] [rbp+818h]

  v38 = -2i64;
  bounds = 0i64;
  pr = 0i64;
  v37 = 0i64;
  pObject = this->pDocView.pObject;
  v5 = 0;
  if ( pObject )
  {
    if ( (pObject->RTFlags & 3) != 0 )
      Scaleform::Render::Text::DocView::Format(pObject);
    if ( (this->TextFlags & 1) != 0 )
    {
      Scaleform::Render::TextLayout::Builder::Builder(&bld, Scaleform::Memory::pGlobalHeap);
      Scaleform::Render::Text::DocView::CreateVisibleTextLayout(this->pDocView.pObject, &bld);
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 0x400u);
      v40 = 74;
      v7 = (Scaleform::Render::TextLayout *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              192i64,
                                              &v40);
      vars0 = v7;
      if ( v7 )
      {
        Scaleform::Render::TextLayout::TextLayout(v7, &bld);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      v10 = *(_QWORD *)&WritableData[9].Type;
      if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) )
        (**(void (__fastcall ***)(__int64, __int64))v10)(v10, 1i64);
      *(_QWORD *)&WritableData[9].Type = v9;
      LOBYTE(WritableData[10].vfptr) &= ~1u;
      Scaleform::Render::TextLayout::Builder::~Builder(&bld);
    }
  }
  v11 = this->pLayout.pObject;
  if ( v11 )
  {
    x1 = v11->Bounds.x1;
    bounds.x1 = x1;
    y1 = v11->Bounds.y1;
    bounds.y1 = y1;
    x2 = v11->Bounds.x2;
    bounds.x2 = x2;
    y2 = v11->Bounds.y2;
    bounds.y2 = y2;
    v37.x1 = x1;
    v37.y1 = y1;
    v37.x2 = x2;
    v37.y2 = y2;
    v16 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>(this);
    if ( v16 )
    {
      pData = v16->pData;
      if ( pData )
      {
        if ( *((_DWORD *)pData + 6) )
        {
          do
            Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
              *(Scaleform::Render::Filter **)(pData[2] + 8i64 * v5++),
              &bounds);
          while ( v5 < *((_DWORD *)pData + 6) );
          y2 = bounds.y2;
          x2 = bounds.x2;
          y1 = bounds.y1;
          x1 = bounds.x1;
        }
      }
    }
    if ( (this->Flags & 0x200) != 0 )
    {
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &bounds);
    }
    else
    {
      v18 = _mm_shuffle_ps(*(__m128 *)&this->M34.M[0][0], *(__m128 *)&this->M34.M[1][0], 255);
      v19 = _mm_unpacklo_ps(*(__m128 *)&this->M34.M[0][0], *(__m128 *)&this->M34.M[1][0]);
      v20 = _mm_mul_ps(_mm_unpacklo_ps((__m128)bounds, (__m128)bounds), v19);
      v21 = _mm_mul_ps(_mm_unpackhi_ps((__m128)bounds, (__m128)bounds), v19);
      v22 = _mm_unpacklo_ps(v20, v21);
      v23 = _mm_unpackhi_ps(v20, v21);
      v24 = _mm_add_ps(v23, v22);
      v25 = _mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v23);
      v26 = _mm_min_ps(v24, v25);
      v27 = _mm_max_ps(v24, v25);
      pr = (Scaleform::Render::Rect<float>)_mm_add_ps(
                                             _mm_shuffle_ps(
                                               _mm_min_ps(v26, _mm_shuffle_ps(v26, v26, 177)),
                                               _mm_max_ps(v27, _mm_shuffle_ps(v27, v27, 177)),
                                               136),
                                             _mm_shuffle_ps(v18, v18, 136));
    }
  }
  else
  {
    y2 = bounds.y2;
    x2 = bounds.x2;
    y1 = bounds.y1;
    x1 = bounds.x1;
  }
  v28 = pr.y2;
  v29 = pr.x2;
  v30 = pr.y1;
  v31 = pr.x1;
  if ( x1 == this->AproxLocalBounds.x1
    && x2 == this->AproxLocalBounds.x2
    && y1 == this->AproxLocalBounds.y1
    && y2 == this->AproxLocalBounds.y2
    && pr.x1 == x1
    && pr.x2 == x2
    && pr.y1 == y1
    && pr.y2 == y2 )
  {
    LOBYTE(v32) = 0;
  }
  else
  {
    v33 = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 8u);
    *(float *)&v33[7].vfptr = x1;
    *((float *)&v33[7].vfptr + 1) = y1;
    *(float *)&v33[7].Type = x2;
    *(float *)(&v33[7].Flags + 1) = y2;
    *(float *)&v33[8].vfptr = v31;
    *((float *)&v33[8].vfptr + 1) = v30;
    *(float *)&v33[8].Type = v29;
    *(float *)(&v33[8].Flags + 1) = v28;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState((Scaleform::Render::TreeNode::NodeData *)v33, &v37);
    return this->Flags & 1;
  }
  return v32;
}

// File Line: 96
// RVA: 0x9F8F70
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::TreeText::NodeData::updateCache(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeText *pnode,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // rbx
  __int16 v10; // di
  Scaleform::Render::TreeCacheNode *v11; // r9
  Scaleform::Render::TreeCacheText *v12; // rax
  Scaleform::Render::TreeCacheNode *v13; // rax
  int v15; // [rsp+88h] [rbp+20h] BYREF

  pRenderer = pnode->pRenderer;
  if ( !pRenderer )
  {
    v10 = this->Flags & 0x21 | ((unsigned __int8)pparent->Flags | (unsigned __int8)(2 * (this->Flags & 0x20))) & 0xC0;
    v11 = pparent;
    do
    {
      if ( (_BYTE)pRenderer )
        break;
      LOBYTE(pRenderer) = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v11->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                             + 0x28)
                                                 + 8i64
                                                 * (unsigned int)((int)(LODWORD(v11->pNode)
                                                                      - ((__int64)v11->pNode & 0xFFFFF000)
                                                                      - 56)
                                                                / 56)
                                                 + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                    + 10) & 0x200) != 0;
      v11 = v11->pParent;
    }
    while ( v11 );
    v15 = 71;
    v12 = (Scaleform::Render::TreeCacheText *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                pparent,
                                                448i64,
                                                &v15);
    if ( v12 )
    {
      Scaleform::Render::TreeCacheText::TreeCacheText(
        v12,
        pnode,
        pparent->pRenderer2D,
        v10 | ((_BYTE)pRenderer != 0 ? 0x200 : 0));
      pRenderer = v13;
    }
    else
    {
      pRenderer = 0i64;
    }
    if ( !pRenderer )
      return 0i64;
    pnode->pRenderer = pRenderer;
  }
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(pRenderer, pparent, pinsert, this, depth);
  return pRenderer;
}

// File Line: 126
// RVA: 0x960E40
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeText::NodeData::CloneCreate(
        Scaleform::Render::TreeText::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData> src; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Render::TreeText::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeText::NodeData *v9; // [rsp+60h] [rbp+18h]

  v4 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176i64, 0i64);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = this;
    Scaleform::Render::TreeText::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData>)&src);
  }
  return (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v5);
}

// File Line: 133
// RVA: 0x9B0F40
void __fastcall Scaleform::Render::TreeText::SetLayout(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TextLayout::Builder *b)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rsi
  Scaleform::Render::TextLayout *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi
  __int64 v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  int v11; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::Render::TextLayout *v12; // [rsp+68h] [rbp+20h]

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  v11 = 74;
  v5 = (Scaleform::Render::TextLayout *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeText *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                          Scaleform::Memory::pGlobalHeap,
                                          this,
                                          192i64,
                                          &v11,
                                          -2i64);
  v12 = v5;
  if ( v5 )
  {
    Scaleform::Render::TextLayout::TextLayout(v5, b);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = *(_QWORD *)&WritableData[9].Type;
  if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
    (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
  *(_QWORD *)&WritableData[9].Type = v7;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v10 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                             + 0x18)
                                                                 + 64i64);
    p_PNode->pPrev = v10->pPrev;
    this->PNode.pNext = v10;
    v10->pPrev->pNext = p_PNode;
    v10->pPrev = p_PNode;
  }
}

// File Line: 140
// RVA: 0x992900
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::Render::TreeText::Init(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Text::Allocator *pallocator,
        Scaleform::Render::Text::FontManagerBase *fntMgr,
        Scaleform::Log *log)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rdi
  Scaleform::Render::Text::ParagraphFormat *v9; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v10; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v11; // rsi
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // rcx
  Scaleform::MemoryHeap *v13; // rax
  Scaleform::MemoryHeap *v14; // rdx
  Scaleform::MemoryHeap *v15; // rcx
  Scaleform::MemoryHeap *v16; // rax
  Scaleform::Render::Text::StyledText *CopyTo; // rdi
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::ParagraphFormat *v19; // rsi
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::Text::ParagraphFormat srcfmt; // [rsp+0h] [rbp-69h] BYREF
  int v22; // [rsp+28h] [rbp-41h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+30h] [rbp-39h] BYREF
  Scaleform::StringDH *p_FontList; // [rsp+38h] [rbp-31h]
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [rsp+40h] [rbp-29h] BYREF
  __int64 v26; // [rsp+90h] [rbp+27h]

  v26 = -2i64;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  if ( !WritableData[9].vfptr )
  {
    v22 = 74;
    v9 = (Scaleform::Render::Text::ParagraphFormat *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       352i64,
                                                       &v22);
    key = v9;
    if ( v9 )
    {
      Scaleform::Render::Text::DocView::DocView((Scaleform::Render::Text::DocView *)v9, pallocator, fntMgr, log);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    vfptr = WritableData[9].vfptr;
    if ( vfptr && !_InterlockedDecrement((volatile signed __int32 *)&vfptr->ConstructCopy) )
      (*(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryDataVtbl *, __int64))vfptr->__vecDelDtor)(
        vfptr,
        1i64);
    WritableData[9].vfptr = v11;
    v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    v14 = v13;
    defaultTextFmt.pAllocator = 0i64;
    defaultTextFmt.RefCount = 1;
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    p_FontList = &defaultTextFmt.FontList;
    defaultTextFmt.FontList.pHeap = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    defaultTextFmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    v16 = Scaleform::Memory::pGlobalHeap;
    if ( v14 )
      v16 = v14;
    p_FontList = &defaultTextFmt.Url;
    defaultTextFmt.Url.pHeap = v16;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    defaultTextFmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    defaultTextFmt.pImageDesc.pObject = 0i64;
    defaultTextFmt.pFontHandle.pObject = 0i64;
    defaultTextFmt.ColorV = -16777216;
    defaultTextFmt.LetterSpacing = 0.0;
    defaultTextFmt.FontSize = 0;
    defaultTextFmt.FormatFlags = 0;
    defaultTextFmt.PresentMask = 0;
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
      (Scaleform::Render::Text::StyledText *)WritableData[9].vfptr->CopyTo,
      &defaultTextFmt);
    srcfmt.pAllocator = 0i64;
    srcfmt.RefCount = 1;
    *(_QWORD *)&srcfmt.BlockIndent = 0i64;
    srcfmt.RightMargin = 0;
    srcfmt.PresentMask = 1;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    srcfmt.pTabStops = 0i64;
    srcfmt.PresentMask &= ~0x40u;
    CopyTo = (Scaleform::Render::Text::StyledText *)WritableData[9].vfptr->CopyTo;
    Allocator = Scaleform::Render::Text::StyledText::GetAllocator(CopyTo);
    v19 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(Allocator, &srcfmt);
    pObject = CopyTo->pDefaultParagraphFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    CopyTo->pDefaultParagraphFormat.pObject = v19;
    Scaleform::Render::TreeText::SetAAMode(this, AA_Animation);
    if ( srcfmt.pAllocator )
    {
      key = &srcfmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        &srcfmt.pAllocator->ParagraphFormatStorage,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, srcfmt.pTabStops);
    Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
  }
}

// File Line: 165
// RVA: 0x992BD0
void __fastcall Scaleform::Render::TreeText::Init(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::ContextImpl::EntryDataVtbl *docView)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::EntryData *v4; // rdi
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // rcx

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  v4 = WritableData;
  if ( docView )
    _InterlockedExchangeAdd((volatile signed __int32 *)&docView->ConstructCopy, 1u);
  vfptr = WritableData[9].vfptr;
  if ( !vfptr || _InterlockedDecrement((volatile signed __int32 *)&vfptr->ConstructCopy) )
  {
    WritableData[9].vfptr = docView;
  }
  else
  {
    (*(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryDataVtbl *, __int64))vfptr->__vecDelDtor)(vfptr, 1i64);
    v4[9].vfptr = docView;
  }
}

// File Line: 171
// RVA: 0x982D40
Scaleform::Render::Text::DocView *__fastcall Scaleform::Render::TreeText::GetDocView(Scaleform::Render::TreeText *this)
{
  return *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x20)
                                                          + 8i64
                                                          * (unsigned int)((int)((_DWORD)this
                                                                               - ((unsigned int)this & 0xFFFFF000)
                                                                               - 56)
                                                                         / 56)
                                                          + 40)
                                              + 144i64);
}

// File Line: 177
// RVA: 0x9B4260
void __fastcall Scaleform::Render::TreeText::SetText(
        Scaleform::Render::TreeText *this,
        char *putf8Str,
        unsigned __int64 lengthInBytes)
{
  unsigned __int64 v4; // rdi
  Scaleform::Render::Text::DocView *v5; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v5 )
    Scaleform::Render::Text::DocView::SetText(v5, putf8Str, lengthInBytes);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    pPrev = v8[4].pPrev;
    v8 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v8;
    v8->pPrev->pNext = p_PNode;
    v8->pPrev = p_PNode;
  }
}

// File Line: 187
// RVA: 0x9B4310
void __fastcall Scaleform::Render::TreeText::SetText(
        Scaleform::Render::TreeText *this,
        const wchar_t *pstr,
        unsigned __int64 lengthInChars)
{
  unsigned __int64 v4; // rdi
  Scaleform::Render::Text::DocView *v5; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v5 )
    Scaleform::Render::Text::DocView::SetText(v5, pstr, lengthInChars);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    pPrev = v8[4].pPrev;
    v8 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v8;
    v8->pPrev->pNext = p_PNode;
    v8->pPrev = p_PNode;
  }
}

// File Line: 207
// RVA: 0x98CA10
Scaleform::String *__fastcall Scaleform::Render::TreeText::GetText(
        Scaleform::Render::TreeText *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::DocView *v3; // rcx

  v3 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v3 )
    Scaleform::Render::Text::DocView::GetText(v3, result);
  else
    Scaleform::String::String(result, &customCaption);
  return result;
}

// File Line: 217
// RVA: 0x9B0A50
void __fastcall Scaleform::Render::TreeText::SetHtmlText(
        Scaleform::Render::TreeText *this,
        const char *putf8Str,
        unsigned __int64 lengthInBytes,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::DocView *v6; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v5 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v6 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v6 )
    Scaleform::Render::Text::DocView::ParseHtml(v6, putf8Str, lengthInBytes, 0, pimgInfoArr, 0i64, 0i64, 0i64);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v5 + 24);
    pPrev = v9[4].pPrev;
    v9 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v9;
    v9->pPrev->pNext = p_PNode;
    v9->pPrev = p_PNode;
  }
}

// File Line: 229
// RVA: 0x9B0B10
void __fastcall Scaleform::Render::TreeText::SetHtmlText(
        Scaleform::Render::TreeText *this,
        const wchar_t *pstr,
        unsigned __int64 lengthInChars,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::DocView *v6; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v5 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v6 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v6 )
    Scaleform::Render::Text::DocView::ParseHtml(v6, pstr, lengthInChars, 0, pimgInfoArr, 0i64, 0i64, 0i64);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v5 + 24);
    pPrev = v9[4].pPrev;
    v9 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v9;
    v9->pPrev->pNext = p_PNode;
    v9->pPrev = p_PNode;
  }
}

// File Line: 249
// RVA: 0x9872E0
Scaleform::String *__fastcall Scaleform::Render::TreeText::GetHtmlText(
        Scaleform::Render::TreeText *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::DocView *v3; // rcx

  v3 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v3 )
    Scaleform::Render::Text::DocView::GetHtml(v3, result);
  else
    Scaleform::String::String(result, &customCaption);
  return result;
}

// File Line: 257
// RVA: 0x9AE6F0
void __fastcall Scaleform::Render::TreeText::SetBounds(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Rect<float> *r)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::Text::DocView *v4; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64
                                                        * (unsigned int)((int)((_DWORD)this
                                                                             - ((unsigned int)this & 0xFFFFF000)
                                                                             - 56)
                                                                       / 56)
                                                        + 40)
                                            + 144i64);
  if ( v4 )
    Scaleform::Render::Text::DocView::SetViewRect(v4, r, UseExternally);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 269
// RVA: 0x9805F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::TreeText::GetBounds(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Rect<float> *result)
{
  __int64 v3; // rcx
  __int64 v4; // rdi

  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v4 = *(_QWORD *)(v3 + 144);
  if ( v4 )
  {
    if ( (*(_BYTE *)(v4 + 347) & 3) != 0 )
    {
      Scaleform::Render::Text::DocView::Format(*(Scaleform::Render::Text::DocView **)(v3 + 144));
      *(_BYTE *)(v4 + 347) &= 0xFCu;
    }
    result->x1 = *(float *)(v4 + 176);
    result->y1 = *(float *)(v4 + 180);
    result->x2 = *(float *)(v4 + 184);
    result->y2 = *(float *)(v4 + 188);
    return result;
  }
  else
  {
    *(_QWORD *)&result->x1 = 0i64;
    *(_QWORD *)&result->x2 = 0i64;
    return result;
  }
}

// File Line: 293
// RVA: 0x9AEAD0
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::Render::TreeText::SetColor(
        Scaleform::Render::TreeText *this,
        unsigned int *c,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v8; // rdi
  __int64 v9; // r14
  __int64 v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rdx
  Scaleform::MemoryHeap *v13; // rax
  Scaleform::MemoryHeap *v14; // rax
  __int64 v15; // rbx
  __int64 v16; // rbx
  Scaleform::Render::Text::TextFormat *v17; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v20; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h] BYREF
  __int64 v22; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::StringDH *p_FontList; // [rsp+E0h] [rbp+67h]

  v22 = -2i64;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( v10 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 16i64);
    if ( v11 )
      v12 = *(_QWORD *)(v11 + 48);
    else
      v12 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(Scaleform::Memory::pGlobalHeap);
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v13 = Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v13 = (Scaleform::MemoryHeap *)v12;
    p_FontList = &fmt.FontList;
    fmt.FontList.pHeap = v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    v14 = Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v14 = (Scaleform::MemoryHeap *)v12;
    p_FontList = &fmt.Url;
    fmt.Url.pHeap = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    fmt.pImageDesc.pObject = 0i64;
    fmt.pFontHandle.pObject = 0i64;
    fmt.ColorV = -16777216;
    fmt.LetterSpacing = 0.0;
    fmt.FontSize = 0;
    fmt.FormatFlags = 0;
    fmt.PresentMask = 0;
    fmt.ColorV = *c;
    fmt.PresentMask = 1;
    v15 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v15 + 347) &= ~0x10u;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v15 + 16),
      &fmt,
      startPos,
      endPos);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v15 + 8i64))(v15, 1i64);
    v16 = *(_QWORD *)(v9 + 144);
    v17 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v16 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v16 + 16), v17);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v20 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v8 + 24) + 64i64);
    p_PNode->pPrev = v20->pPrev;
    this->PNode.pNext = v20;
    v20->pPrev->pNext = p_PNode;
    v20->pPrev = p_PNode;
  }
}

// File Line: 308
// RVA: 0x9AF820
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::Render::TreeText::SetFont(
        Scaleform::Render::TreeText *this,
        const char *pfontName,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v8; // rsi
  __int64 v9; // r14
  __int64 v10; // r8
  _QWORD *v11; // r8
  __int64 v12; // rdx
  Scaleform::MemoryHeap *v13; // rdx
  Scaleform::MemoryHeap *v14; // rax
  Scaleform::MemoryHeap *v15; // rax
  unsigned __int64 v16; // r8
  __int64 v17; // rbx
  __int64 v18; // rbx
  Scaleform::Render::Text::TextFormat *v19; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v22; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h] BYREF
  __int64 v24; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::StringDH *p_FontList; // [rsp+E0h] [rbp+67h]

  v24 = -2i64;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( v10 )
  {
    v11 = *(_QWORD **)(v10 + 16);
    v12 = v11[2];
    if ( v12 )
      v13 = *(Scaleform::MemoryHeap **)(v12 + 48);
    else
      v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v11);
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v14 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v14 = v13;
    p_FontList = &fmt.FontList;
    fmt.FontList.pHeap = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    p_FontList = &fmt.Url;
    fmt.Url.pHeap = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    fmt.pImageDesc.pObject = 0i64;
    fmt.pFontHandle.pObject = 0i64;
    fmt.ColorV = -16777216;
    fmt.LetterSpacing = 0.0;
    fmt.FontSize = 0;
    fmt.FormatFlags = 0;
    fmt.PresentMask = 0;
    v16 = -1i64;
    do
      ++v16;
    while ( pfontName[v16] );
    Scaleform::Render::Text::TextFormat::SetFontList(&fmt, pfontName, v16);
    v17 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v17 + 347) &= ~0x10u;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v17 + 16),
      &fmt,
      startPos,
      endPos);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v17 + 8i64))(v17, 1i64);
    v18 = *(_QWORD *)(v9 + 144);
    v19 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v18 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v18 + 16), v19);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v22 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v8 + 24) + 64i64);
    p_PNode->pPrev = v22->pPrev;
    this->PNode.pNext = v22;
    v22->pPrev->pNext = p_PNode;
    v22->pPrev = p_PNode;
  }
}

// File Line: 323
// RVA: 0x9AFED0
void __fastcall Scaleform::Render::TreeText::SetFontSize(
        Scaleform::Render::TreeText *this,
        float fontSize,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v7; // rsi
  __int64 v8; // r14
  __int64 v9; // r8
  _QWORD *v10; // r8
  __int64 v11; // rdx
  Scaleform::MemoryHeap *v12; // rdx
  Scaleform::MemoryHeap *v13; // rax
  Scaleform::Render::Text::Allocator *v14; // rax
  int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rbx
  Scaleform::Render::Text::TextFormat *v18; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v21; // rcx
  __int64 v22[2]; // [rsp+8h] [rbp-79h] BYREF
  __int64 v23; // [rsp+18h] [rbp-69h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [rsp+20h] [rbp-61h] BYREF
  __int64 *v25; // [rsp+E8h] [rbp+67h]

  fmt.Url.pHeap = (Scaleform::MemoryHeap *)-2i64;
  v7 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v9 = *(_QWORD *)(v8 + 144);
  if ( v9 )
  {
    v10 = *(_QWORD **)(v9 + 16);
    v11 = v10[2];
    if ( v11 )
      v12 = *(Scaleform::MemoryHeap **)(v11 + 48);
    else
      v12 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v10);
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v13 = Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v13 = v12;
    v25 = v22;
    v22[1] = (__int64)v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v22[0] = (__int64)&Scaleform::String::NullData.Size + 2;
    v14 = (Scaleform::Render::Text::Allocator *)Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v14 = (Scaleform::Render::Text::Allocator *)v12;
    v25 = &v23;
    fmt.pAllocator = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v23 = (__int64)&Scaleform::String::NullData.Size + 2;
    *(_QWORD *)&fmt.RefCount = 0i64;
    fmt.FontList.HeapTypeBits = 0i64;
    fmt.FontList.pHeap = (Scaleform::MemoryHeap *)4278190080i64;
    LOWORD(fmt.Url.pData) = 0;
    BYTE2(fmt.Url.HeapTypeBits) = 0;
    WORD2(fmt.Url.HeapTypeBits) = 0;
    if ( fontSize >= 3276.8 )
      LOWORD(v15) = -1;
    else
      v15 = (int)(float)(fontSize * 20.0);
    LOWORD(fmt.Url.pData) = v15;
    WORD2(fmt.Url.HeapTypeBits) |= 8u;
    v16 = *(_QWORD *)(v8 + 144);
    *(_BYTE *)(v16 + 347) &= ~0x10u;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v16 + 16),
      &fmt,
      startPos,
      endPos);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v16 + 8i64))(v16, 1i64);
    v17 = *(_QWORD *)(v8 + 144);
    v18 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v17 + 16) + 56i64),
            (Scaleform::Render::Text::TextFormat *)&fmt.pImageDesc,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v17 + 16), v18);
    Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)&fmt.pImageDesc);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v21 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v7 + 24) + 64i64);
    p_PNode->pPrev = v21->pPrev;
    this->PNode.pNext = v21;
    v21->pPrev->pNext = p_PNode;
    v21->pPrev = p_PNode;
  }
}

// File Line: 338
// RVA: 0x9B0110
// bad sp value at call has been detected, the output may be wrong!
void __fastcall Scaleform::Render::TreeText::SetFontStyle(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::FontStyle fontStyle,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v8; // rsi
  __int64 v9; // r14
  __int64 v10; // r8
  _QWORD *v11; // r8
  __int64 v12; // rdx
  Scaleform::MemoryHeap *v13; // rdx
  Scaleform::MemoryHeap *v14; // rax
  Scaleform::MemoryHeap *v15; // rax
  int v16; // ebx
  int v17; // ebx
  char v18; // dl
  char v19; // al
  char v20; // dl
  __int64 v21; // rbx
  __int64 v22; // rbx
  Scaleform::Render::Text::TextFormat *v23; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v26; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h] BYREF
  __int64 v28; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h] BYREF
  Scaleform::StringDH *p_FontList; // [rsp+E0h] [rbp+67h]

  v28 = -2i64;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( !v10 )
    goto LABEL_27;
  v11 = *(_QWORD **)(v10 + 16);
  v12 = v11[2];
  if ( v12 )
    v13 = *(Scaleform::MemoryHeap **)(v12 + 48);
  else
    v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v11);
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  v14 = Scaleform::Memory::pGlobalHeap;
  if ( v13 )
    v14 = v13;
  p_FontList = &fmt.FontList;
  fmt.FontList.pHeap = v14;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  v15 = Scaleform::Memory::pGlobalHeap;
  if ( v13 )
    v15 = v13;
  p_FontList = &fmt.Url;
  fmt.Url.pHeap = v15;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  fmt.pImageDesc.pObject = 0i64;
  fmt.pFontHandle.pObject = 0i64;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0.0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  if ( !fontStyle )
  {
    v20 = fmt.FormatFlags & 0xFE;
LABEL_21:
    fmt.FormatFlags = v20;
    fmt.PresentMask |= 0x10u;
    if ( (fmt.PresentMask & 0x800) != 0 && (v20 & 2) != 0 )
    {
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= ~0x800u;
    }
    v19 = v20 & 0xFD;
    goto LABEL_25;
  }
  v16 = fontStyle - 1;
  if ( !v16 )
  {
    v20 = fmt.FormatFlags | 1;
    goto LABEL_21;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v18 = fmt.FormatFlags & 0xFE;
LABEL_14:
    fmt.FormatFlags = v18;
    fmt.PresentMask |= 0x10u;
    if ( (fmt.PresentMask & 0x800) != 0 && (v18 & 2) == 0 )
    {
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= ~0x800u;
    }
    v19 = v18 | 2;
LABEL_25:
    fmt.FormatFlags = v19;
    fmt.PresentMask |= 0x20u;
    goto LABEL_26;
  }
  if ( v17 == 1 )
  {
    v18 = fmt.FormatFlags | 1;
    goto LABEL_14;
  }
LABEL_26:
  v21 = *(_QWORD *)(v9 + 144);
  *(_BYTE *)(v21 + 347) &= ~0x10u;
  Scaleform::Render::Text::StyledText::SetTextFormat(
    *(Scaleform::Render::Text::StyledText **)(v21 + 16),
    &fmt,
    startPos,
    endPos);
  (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v21 + 8i64))(v21, 1i64);
  v22 = *(_QWORD *)(v9 + 144);
  v23 = Scaleform::Render::Text::TextFormat::Merge(
          *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v22 + 16) + 56i64),
          &result,
          &fmt);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v22 + 16), v23);
  Scaleform::Render::Text::TextFormat::~TextFormat(&result);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
LABEL_27:
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v26 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v8 + 24) + 64i64);
    p_PNode->pPrev = v26->pPrev;
    this->PNode.pNext = v26;
    v26->pPrev->pNext = p_PNode;
    v26->pPrev = p_PNode;
  }
}

// File Line: 371
// RVA: 0x9B1270
void __fastcall Scaleform::Render::TreeText::SetLetterSpacing(
        Scaleform::Render::TreeText *this,
        float letterSpacing,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v7; // rdi
  __int64 v8; // r14
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // rdx
  Scaleform::MemoryHeap *v12; // rax
  Scaleform::MemoryHeap *v13; // rax
  __int64 v14; // rbx
  __int64 v15; // rbx
  Scaleform::Render::Text::TextFormat *v16; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v19; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+20h] [rbp-89h] BYREF
  __int64 v21; // [rsp+70h] [rbp-39h]
  Scaleform::Render::Text::TextFormat result; // [rsp+78h] [rbp-31h] BYREF

  v21 = -2i64;
  v7 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v9 = *(_QWORD *)(v8 + 144);
  if ( v9 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(v9 + 16) + 16i64);
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 48);
    else
      v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(Scaleform::Memory::pGlobalHeap);
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v12 = Scaleform::Memory::pGlobalHeap;
    if ( v11 )
      v12 = (Scaleform::MemoryHeap *)v11;
    fmt.FontList.pHeap = v12;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    v13 = Scaleform::Memory::pGlobalHeap;
    if ( v11 )
      v13 = (Scaleform::MemoryHeap *)v11;
    fmt.Url.pHeap = v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
    fmt.pImageDesc.pObject = 0i64;
    fmt.pFontHandle.pObject = 0i64;
    fmt.ColorV = -16777216;
    fmt.FontSize = 0;
    fmt.FormatFlags = 0;
    fmt.PresentMask = 2;
    fmt.LetterSpacing = letterSpacing * 20.0;
    v14 = *(_QWORD *)(v8 + 144);
    *(_BYTE *)(v14 + 347) &= ~0x10u;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v14 + 16),
      &fmt,
      startPos,
      endPos);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 8i64))(v14, 1i64);
    v15 = *(_QWORD *)(v8 + 144);
    v16 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v15 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v15 + 16), v16);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v19 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v7 + 24) + 64i64);
    p_PNode->pPrev = v19->pPrev;
    this->PNode.pNext = v19;
    v19->pPrev->pNext = p_PNode;
    v19->pPrev = p_PNode;
  }
}

// File Line: 386
// RVA: 0x9B4EC0
void __fastcall Scaleform::Render::TreeText::SetUnderline(
        Scaleform::Render::TreeText *this,
        bool underline,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  unsigned __int64 v8; // rsi
  __int64 v9; // r14
  __int64 v10; // r8
  _QWORD *v11; // r8
  __int64 v12; // rdx
  Scaleform::MemoryHeap *v13; // rdx
  Scaleform::MemoryHeap *v14; // rax
  Scaleform::MemoryHeap *v15; // rax
  char v16; // al
  __int64 v17; // rbx
  __int64 v18; // rbx
  Scaleform::Render::Text::TextFormat *v19; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v22; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-A1h] BYREF
  Scaleform::MemoryHeap *v24; // [rsp+50h] [rbp-51h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-49h] BYREF

  result.Url.HeapTypeBits = -2i64;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( v10 )
  {
    v11 = *(_QWORD **)(v10 + 16);
    v12 = v11[2];
    if ( v12 )
      v13 = *(Scaleform::MemoryHeap **)(v12 + 48);
    else
      v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v11);
    fmt.Url.pHeap = 0i64;
    LODWORD(fmt.pImageDesc.pObject) = 1;
    v14 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v14 = v13;
    *(_QWORD *)&fmt.ColorV = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.pFontHandle.pObject = (Scaleform::Render::Text::FontHandle *)((char *)&Scaleform::String::NullData.Size + 2);
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    v24 = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    *(_QWORD *)&fmt.FontSize = (char *)&Scaleform::String::NullData.Size + 2;
    result.pAllocator = 0i64;
    *(_QWORD *)&result.RefCount = 0i64;
    result.FontList.HeapTypeBits = 4278190080i64;
    LOWORD(result.FontList.pHeap) = 0;
    BYTE2(result.FontList.pHeap) = 0;
    WORD2(result.FontList.pHeap) = 0;
    if ( underline )
      v16 = 4;
    else
      v16 = 0;
    BYTE2(result.FontList.pHeap) = v16;
    WORD2(result.FontList.pHeap) |= 0x40u;
    v17 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v17 + 347) &= ~0x10u;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v17 + 16),
      (Scaleform::Render::Text::TextFormat *)&fmt.Url.pHeap,
      startPos,
      endPos);
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v17 + 8i64))(v17, 1i64);
    v18 = *(_QWORD *)(v9 + 144);
    v19 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v18 + 16) + 56i64),
            (Scaleform::Render::Text::TextFormat *)&result.Url.pHeap,
            (Scaleform::Render::Text::TextFormat *)&fmt.Url.pHeap);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v18 + 16), v19);
    Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)&result.Url.pHeap);
    Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)&fmt.Url.pHeap);
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v22 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v8 + 24) + 64i64);
    p_PNode->pPrev = v22->pPrev;
    this->PNode.pNext = v22;
    v22->pPrev->pNext = p_PNode;
    v22->pPrev = p_PNode;
  }
}this->PNode.pNext = v22;
    v22->pPrev->pNext = p_PNode;
    v22->pPrev = p_PNode;
  }

// File Line: 401
// RVA: 0x9B1E50
void __fastcall Scaleform::Render::TreeText::SetMultiline(Scaleform::Render::TreeText *this, bool multiline)
{
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v4 )
  {
    if ( multiline )
      *(_BYTE *)(v4 + 344) |= 4u;
    else
      *(_BYTE *)(v4 + 344) &= ~4u;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 416
// RVA: 0x997B30
__int64 __fastcall Scaleform::Render::TreeText::IsMultiline(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                                 + 40)
                     + 144i64);
  if ( result )
    return (*(unsigned __int8 *)(result + 344) >> 2) & 1;
  return result;
}

// File Line: 427
// RVA: 0x9B5F40
void __fastcall Scaleform::Render::TreeText::SetWordWrap(Scaleform::Render::TreeText *this, bool wordWrap)
{
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  char v5; // cl
  char v6; // cl
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( !v4 )
    goto LABEL_8;
  v5 = *(_BYTE *)(v4 + 344);
  if ( wordWrap )
  {
    if ( (v5 & 8) != 0 )
      goto LABEL_8;
    v6 = v5 | 8;
  }
  else
  {
    if ( (v5 & 8) == 0 )
      goto LABEL_8;
    v6 = v5 & 0xF7;
  }
  *(_BYTE *)(v4 + 347) |= 2u;
  *(_BYTE *)(v4 + 344) = v6;
LABEL_8:
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v9[4].pPrev;
    v9 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v9;
    v9->pPrev->pNext = p_PNode;
    v9->pPrev = p_PNode;
  }
}

// File Line: 443
// RVA: 0x998410
__int64 __fastcall Scaleform::Render::TreeText::IsWordWrap(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                                 + 40)
                     + 144i64);
  if ( result )
    return (*(unsigned __int8 *)(result + 344) >> 3) & 1;
  return result;
}

// File Line: 453
// RVA: 0x9AE0C0
void __fastcall Scaleform::Render::TreeText::SetAlignment(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::Alignment a)
{
  unsigned __int64 v3; // rsi
  __int64 v4; // rdi
  __int16 v5; // dx
  Scaleform::Render::Text::StyledText **v6; // rbx
  __int64 v7; // rdi
  Scaleform::Render::Text::ParagraphFormat *v8; // rbx
  Scaleform::Render::Text::StyledText *v9; // rdi
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // rbx
  Scaleform::Render::Text::ParagraphFormat *pObject; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v15; // rcx
  Scaleform::Render::Text::ParagraphFormat fmt; // [rsp+28h] [rbp-58h] BYREF
  Scaleform::Render::Text::ParagraphFormat result; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+A0h] [rbp+20h] BYREF

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  if ( *(_QWORD *)(v4 + 144) )
  {
    switch ( a )
    {
      case Align_TopCenter:
        v5 = 1;
        break;
      case Align_BottomCenter:
        v5 = 3;
        break;
      case Align_CenterLeft:
        v5 = 2;
        break;
      default:
        v5 = 0;
        break;
    }
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    memset(&fmt.pTabStops, 0, 18);
    fmt.PresentMask = (v5 << 9) & 0x600 | 1;
    v6 = *(Scaleform::Render::Text::StyledText ***)(v4 + 144);
    Scaleform::Render::Text::StyledText::SetParagraphFormat(v6[2], &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
    (*(void (__fastcall **)(Scaleform::Render::Text::StyledText **, __int64))&(*v6)->RefCount)(v6, 1i64);
    v7 = *(_QWORD *)(v4 + 144);
    v8 = Scaleform::Render::Text::ParagraphFormat::Merge(
           *(Scaleform::Render::Text::ParagraphFormat **)(*(_QWORD *)(v7 + 16) + 48i64),
           &result,
           &fmt);
    v9 = *(Scaleform::Render::Text::StyledText **)(v7 + 16);
    Allocator = Scaleform::Render::Text::StyledText::GetAllocator(v9);
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(Allocator, v8);
    pObject = v9->pDefaultParagraphFormat.pObject;
    if ( pObject )
      Scaleform::Render::Text::ParagraphFormat::Release(pObject);
    v9->pDefaultParagraphFormat.pObject = ParagraphFormat;
    if ( result.pAllocator )
    {
      key = &result;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        &result.pAllocator->ParagraphFormatStorage,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, result.pTabStops);
    result.pTabStops = 0i64;
    if ( fmt.pAllocator )
    {
      key = &fmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        &fmt.pAllocator->ParagraphFormatStorage,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, fmt.pTabStops);
    fmt.pTabStops = 0i64;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v15 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v3 + 24) + 64i64);
    p_PNode->pPrev = v15->pPrev;
    this->PNode.pNext = v15;
    v15->pPrev->pNext = p_PNode;
    v15->pPrev = p_PNode;
  }
}

// File Line: 476
// RVA: 0x97FD70
__int64 __fastcall Scaleform::Render::TreeText::GetAlignment(Scaleform::Render::TreeText *this)
{
  __int64 v1; // rax
  unsigned int v2; // ebx
  Scaleform::Render::Text::ParagraphFormat v4; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+70h] [rbp+8h] BYREF

  v1 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  if ( !*(_QWORD *)(v1 + 144) )
    return 0i64;
  v4.pAllocator = 0i64;
  v2 = 1;
  v4.RefCount = 1;
  memset(&v4.pTabStops, 0, 20);
  Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
    *(Scaleform::Render::Text::StyledText **)(*(_QWORD *)(v1 + 144) + 16i64),
    0i64,
    &v4,
    0i64,
    0xFFFFFFFFFFFFFFFFui64);
  if ( (v4.PresentMask & 1) == 0 )
    goto LABEL_8;
  if ( ((v4.PresentMask >> 9) & 3) != 1 )
  {
    if ( ((v4.PresentMask >> 9) & 3) == 2 )
    {
      v2 = 3;
      goto LABEL_9;
    }
    if ( ((v4.PresentMask >> 9) & 3) == 3 )
    {
      v2 = 2;
      goto LABEL_9;
    }
LABEL_8:
    v2 = 0;
  }
LABEL_9:
  if ( v4.pAllocator )
  {
    key = &v4;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &v4.pAllocator->ParagraphFormatStorage,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4.pTabStops);
  v4.pTabStops = 0i64;
  return v2;
}

// File Line: 500
// RVA: 0x9B55B0
void __fastcall Scaleform::Render::TreeText::SetVAlignment(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::VAlignment a)
{
  unsigned __int64 v3; // rdi
  __int64 v5; // rdx
  int v6; // r9d
  char v7; // al
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v5 )
  {
    v6 = a - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        v7 = 2;
      else
        v7 = 1;
    }
    else
    {
      v7 = 3;
    }
    *(_BYTE *)(v5 + 345) &= 0xF3u;
    *(_BYTE *)(v5 + 345) |= 4 * (v7 & 3);
    *(_BYTE *)(v5 + 347) |= 1u;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v10 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v10[4].pPrev;
    v10 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v10;
    v10->pPrev->pNext = p_PNode;
    v10->pPrev = p_PNode;
  }
}

// File Line: 519
// RVA: 0x98EAE0
__int64 __fastcall Scaleform::Render::TreeText::GetVAlignment(Scaleform::Render::TreeText *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v1 )
  {
    if ( ((*(unsigned __int8 *)(v1 + 345) >> 2) & 3) == 2 )
      return 2i64;
    if ( ((*(unsigned __int8 *)(v1 + 345) >> 2) & 3) == 3 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 538
// RVA: 0x9AE4E0
void __fastcall Scaleform::Render::TreeText::SetBorderColor(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Color *borderColor)
{
  Scaleform::Render::TreeText::SetBorderColor(this, borderColor->Raw);
}

// File Line: 543
// RVA: 0x9AE4F0
void __fastcall Scaleform::Render::TreeText::SetBorderColor(
        Scaleform::Render::TreeText *this,
        unsigned int borderColor)
{
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v4 )
    *(_DWORD *)(v4 + 328) = borderColor;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 555
// RVA: 0x980200
Scaleform::Render::Color *__fastcall Scaleform::Render::TreeText::GetBorderColor(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rax

  v2 = *(Scaleform::Render::Color **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                + 8i64
                                                * (unsigned int)((int)((_DWORD)this
                                                                     - ((unsigned int)this & 0xFFFFF000)
                                                                     - 56)
                                                               / 56)
                                                + 40)
                                    + 144i64);
  if ( v2 )
    *result = v2[82];
  else
    result->Raw = 0;
  return result;
}

// File Line: 565
// RVA: 0x9AE310
void __fastcall Scaleform::Render::TreeText::SetBackgroundColor(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this, bkgColor->Raw);
}

// File Line: 570
// RVA: 0x9AE320
void __fastcall Scaleform::Render::TreeText::SetBackgroundColor(
        Scaleform::Render::TreeText *this,
        unsigned int bkgColor)
{
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v4 )
    *(_DWORD *)(v4 + 332) = bkgColor;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 582
// RVA: 0x980040
Scaleform::Render::Color *__fastcall Scaleform::Render::TreeText::GetBackgroundColor(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rax

  v2 = *(Scaleform::Render::Color **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                + 8i64
                                                * (unsigned int)((int)((_DWORD)this
                                                                     - ((unsigned int)this & 0xFFFFF000)
                                                                     - 56)
                                                               / 56)
                                                + 40)
                                    + 144i64);
  if ( v2 )
    *result = v2[83];
  else
    result->Raw = 0;
  return result;
}

// File Line: 592
// RVA: 0x9AE000
void __fastcall Scaleform::Render::TreeText::SetAAMode(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::AAMode aa)
{
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( v4 )
  {
    if ( aa == AA_Readability )
      *(_BYTE *)(v4 + 344) |= 0x40u;
    else
      *(_BYTE *)(v4 + 344) &= ~0x40u;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 607
// RVA: 0x97FBB0
__int64 __fastcall Scaleform::Render::TreeText::GetAAMode(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64
                                 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                                 + 40)
                     + 144i64);
  if ( result )
    return (*(unsigned __int8 *)(result + 344) >> 6) & 1;
  return result;
}

// File Line: 617
// RVA: 0x992C40
void __fastcall Scaleform::Render::TreeText::Filter::InitByDefaultValues(Scaleform::Render::TreeText::Filter *this)
{
  Scaleform::Render::GradientData *pObject; // rcx
  Scaleform::Render::Text::TextFilter v3; // [rsp+30h] [rbp-68h] BYREF

  Scaleform::Render::Text::TextFilter::TextFilter(&v3);
  this->Blur.BlurX = v3.BlurX;
  this->Blur.BlurY = v3.BlurY;
  this->Blur.Strength = v3.BlurStrength * 100.0;
  this->Glow.Flags = LOBYTE(v3.ShadowFlags) | 0x80;
  this->Glow.Color = v3.ShadowParams.Colors[0].Raw & 0xFFFFFF | ((unsigned __int8)v3.ShadowAlpha << 24);
  this->DropShadow.Angle = v3.ShadowAngle * 0.1;
  this->DropShadow.Distance = v3.ShadowDistance * 0.050000001;
  pObject = v3.ShadowParams.Gradient.pObject;
  if ( v3.ShadowParams.Gradient.pObject && !_InterlockedDecrement(&v3.ShadowParams.Gradient.pObject->RefCount) )
  {
    if ( pObject )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
}

// File Line: 631
// RVA: 0x9AF430
void __fastcall Scaleform::Render::TreeText::SetFilters(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::Filter *filters,
        unsigned __int64 filtersCnt)
{
  unsigned __int64 v6; // rsi
  __int64 v7; // r15
  $AD53D16137C3AE4177DAFEDA37259559 *v8; // rbx
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  __int64 v13; // rbx
  Scaleform::Render::GradientData *pObject; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v17; // rcx
  Scaleform::Render::Text::TextFilter v18; // [rsp+30h] [rbp-A8h] BYREF
  unsigned int Color; // [rsp+118h] [rbp+40h]
  unsigned int vars0; // [rsp+130h] [rbp+58h]

  v6 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  if ( *(_QWORD *)(v7 + 144) )
  {
    Scaleform::Render::Text::TextFilter::TextFilter(&v18);
    if ( filtersCnt )
    {
      v8 = &filters->4;
      while ( LODWORD(v8[-1].DropShadow.Distance) != 1 )
      {
        if ( LODWORD(v8[-1].DropShadow.Distance) == 2 )
        {
          v18.BlurX = v8->Blur.BlurX * 20.0;
          v18.BlurY = v8->Blur.BlurY * 20.0;
          v18.BlurStrength = v8->Blur.Strength * 0.0099999998;
        }
        else if ( LODWORD(v8[-1].DropShadow.Distance) == 3 )
        {
          LODWORD(v18.ShadowParams.BlurX) = (unsigned __int8)v8->Glow.Flags;
          v18.ShadowParams.BlurX = v8->Blur.BlurX * 20.0;
          v18.ShadowParams.BlurY = v8->Blur.BlurY * 20.0;
          v18.ShadowParams.Strength = v8->Blur.Strength * 0.0099999998;
          Color = v8->Glow.Color;
          LOBYTE(v18.ShadowParams.Offset.y) = HIBYTE(Color);
          *(_QWORD *)&v18.ShadowParams.BlurY = 0i64;
          v18.ShadowParams.Colors[0].Raw = Color;
          v9 = sinf(0.0) * 0.0;
          v10 = cosf(0.0) * 0.0;
LABEL_10:
          v18.ShadowParams.Offset.y = v9;
          v18.ShadowParams.Offset.x = v10;
        }
        v8 = ($AD53D16137C3AE4177DAFEDA37259559 *)((char *)v8 + 32);
        if ( !--filtersCnt )
          goto LABEL_12;
      }
      LODWORD(v18.ShadowParams.BlurX) = (unsigned __int8)v8->Glow.Flags;
      v18.ShadowParams.BlurX = v8->Blur.BlurX * 20.0;
      v18.ShadowParams.BlurY = v8->Blur.BlurY * 20.0;
      v18.ShadowParams.Strength = v8->Blur.Strength * 0.0099999998;
      vars0 = v8->Glow.Color;
      LOBYTE(v18.ShadowParams.Offset.y) = HIBYTE(vars0);
      v11 = v8->DropShadow.Angle * 3.141592653589793 * 0.005555555555555556;
      v18.ShadowParams.BlurY = v11;
      v12 = (float)(__int16)(int)(float)(v8->DropShadow.Distance * 20.0);
      v18.ShadowParams.Offset.x = v12;
      v18.ShadowParams.Colors[0].Raw = vars0;
      v9 = sinf(v11) * v12;
      v10 = cosf(v11) * v12;
      goto LABEL_10;
    }
LABEL_12:
    v13 = *(_QWORD *)(v7 + 144);
    if ( v18.BlurX != *(float *)(v13 + 240)
      || v18.BlurY != *(float *)(v13 + 244)
      || v18.BlurStrength != *(float *)(v13 + 248)
      || !Scaleform::Render::BlurFilterParams::EqualsAll(
            (Scaleform::Render::BlurFilterParams *)(v13 + 256),
            &v18.ShadowParams)
      || *(_DWORD *)(v13 + 304) != LODWORD(v18.ShadowParams.BlurX)
      || *(_BYTE *)(v13 + 316) != LOBYTE(v18.ShadowParams.Offset.y)
      || v18.ShadowParams.BlurY != *(float *)(v13 + 308)
      || v18.ShadowParams.Offset.x != *(float *)(v13 + 312) )
    {
      *(float *)(v13 + 240) = v18.BlurX;
      *(float *)(v13 + 244) = v18.BlurY;
      *(float *)(v13 + 248) = v18.BlurStrength;
      Scaleform::Render::BlurFilterParams::operator=(
        (Scaleform::Render::BlurFilterParams *)(v13 + 256),
        &v18.ShadowParams);
      *(float *)(v13 + 304) = v18.ShadowParams.BlurX;
      *(float *)(v13 + 308) = v18.ShadowParams.BlurY;
      *(float *)(v13 + 312) = v18.ShadowParams.Offset.x;
      *(_BYTE *)(v13 + 316) = LOBYTE(v18.ShadowParams.Offset.y);
    }
    pObject = v18.ShadowParams.Gradient.pObject;
    if ( v18.ShadowParams.Gradient.pObject
      && !_InterlockedDecrement(&v18.ShadowParams.Gradient.pObject->RefCount)
      && pObject )
    {
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    v18.vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  }
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  LOBYTE(WritableData[10].vfptr) |= 1u;
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v17 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(v6 + 24) + 64i64);
    p_PNode->pPrev = v17->pPrev;
    this->PNode.pNext = v17;
    v17->pPrev->pNext = p_PNode;
    v17->pPrev = p_PNode;
  }
}

// File Line: 693
// RVA: 0x9841B0
unsigned __int64 __fastcall Scaleform::Render::TreeText::GetFilters(
        Scaleform::Render::TreeText *this,
        Scaleform::Render::TreeText::Filter *filtersBuf,
        unsigned __int64 filtersCntInBuf)
{
  __int64 v4; // r9
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // rdx
  unsigned __int64 result; // rax
  unsigned __int64 v8; // r8

  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 144i64);
  if ( !v4 )
    return 0i64;
  v5 = 0i64;
  if ( (*(float *)(v4 + 240) != 0.0 || *(float *)(v4 + 244) != 0.0) && filtersCntInBuf )
  {
    filtersBuf->Type = 2;
    v5 = 1i64;
    filtersBuf->Blur.BlurX = *(float *)(v4 + 240) * 0.050000001;
    filtersBuf->Blur.BlurY = *(float *)(v4 + 244) * 0.050000001;
    filtersBuf->Blur.Strength = *(float *)(v4 + 248) * 100.0;
  }
  if ( (*(float *)(v4 + 264) != 0.0 || *(float *)(v4 + 268) != 0.0) && v5 < filtersCntInBuf )
  {
    if ( *(float *)(v4 + 308) == 0.0 && *(float *)(v4 + 312) == 0.0 )
    {
      v6 = v5;
      filtersBuf[v6].Type = 3;
      filtersBuf[v6].Glow.Flags = *(_BYTE *)(v4 + 304);
      filtersBuf[v6].Blur.BlurX = *(float *)(v4 + 264) * 0.050000001;
      filtersBuf[v6].Blur.BlurY = *(float *)(v4 + 268) * 0.050000001;
      filtersBuf[v6].Blur.Strength = *(float *)(v4 + 280) * 100.0;
      result = v5 + 1;
      filtersBuf[v6].Glow.Color = *(_DWORD *)(v4 + 284) & 0xFFFFFF | (*(unsigned __int8 *)(v4 + 316) << 24);
      return result;
    }
    v8 = v5;
    filtersBuf[v8].Type = 1;
    filtersBuf[v8].Glow.Flags = *(_BYTE *)(v4 + 304);
    filtersBuf[v8].Blur.BlurX = *(float *)(v4 + 264) * 0.050000001;
    filtersBuf[v8].Blur.BlurY = *(float *)(v4 + 268) * 0.050000001;
    filtersBuf[v8].Blur.Strength = *(float *)(v4 + 280) * 100.0;
    ++v5;
    filtersBuf[v8].Glow.Color = *(_DWORD *)(v4 + 284) & 0xFFFFFF | (*(unsigned __int8 *)(v4 + 316) << 24);
    filtersBuf[v8].DropShadow.Angle = (float)(*(float *)(v4 + 308) * 180.0) * 0.3183098861837907;
    filtersBuf[v8].DropShadow.Distance = *(float *)(v4 + 312) * 0.050000001;
  }
  return v5;
}

// File Line: 742
// RVA: 0x960590
void __fastcall Scaleform::Render::TreeText::ClearFilters(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::TreeText::Filter filters; // [rsp+20h] [rbp-28h] BYREF

  filters.Type = 0;
  Scaleform::Render::TreeText::Filter::InitByDefaultValues(&filters);
  Scaleform::Render::TreeText::SetFilters(this, &filters, 1ui64);
}

// File Line: 748
// RVA: 0x99C780
void __fastcall Scaleform::Render::TreeText::NotifyLayoutChanged(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v4; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400u);
  p_PNode = &this->PNode;
  LOBYTE(WritableData[10].vfptr) |= 1u;
  if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v4 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v4[4].pPrev;
    v4 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v4;
    v4->pPrev->pNext = p_PNode;
    v4->pPrev = p_PNode;
  }
}

