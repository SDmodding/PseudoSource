// File Line: 32
// RVA: 0x9403F0
void __fastcall Scaleform::Render::TreeText::NodeData::NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  Scaleform::Render::TreeText::NodeData *v1; // rdi

  v1 = this;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  *(_DWORD *)&this->Type = 65541;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memset(&this->M34, 0, 0x30ui64);
  v1->M34.M[0][0] = 1.0;
  v1->M34.M[1][1] = 1.0;
  v1->M34.M[2][2] = 1.0;
  v1->States.ArraySize = 0i64;
  v1->States.DataValue = 0i64;
  v1->Cx.M[0][0] = 1.0;
  v1->Cx.M[0][1] = 1.0;
  v1->Cx.M[0][2] = 1.0;
  *(_QWORD *)&v1->Cx.M[0][3] = 1065353216i64;
  *(_QWORD *)&v1->Cx.M[1][1] = 0i64;
  *(_QWORD *)&v1->Cx.M[1][3] = 0i64;
  *(_QWORD *)&v1->AproxLocalBounds.y1 = 0i64;
  *(_QWORD *)&v1->AproxLocalBounds.y2 = 0i64;
  *(_QWORD *)&v1->AproxParentBounds.y1 = 0i64;
  v1->AproxParentBounds.y2 = 0.0;
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable';
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  v1->pDocView.pObject = 0i64;
  v1->pLayout.pObject = 0i64;
  v1->TextFlags = 0;
}

// File Line: 38
// RVA: 0x940340
void __fastcall Scaleform::Render::TreeText::NodeData::NodeData(Scaleform::Render::TreeText::NodeData *this, Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData> src)
{
  Scaleform::Render::TreeText::NodeData *v2; // rdi
  Scaleform::Render::TreeText::NodeData *v3; // rbx
  Scaleform::Render::ContextImpl::EntryDataVtbl *v4; // r8
  void *(__fastcall *v5)(Scaleform::Render::ContextImpl::EntryData *, unsigned int); // rdx
  Scaleform::Render::ContextImpl::EntryDataVtbl *v6; // rdx
  Scaleform::Render::ContextImpl::EntryData *(__fastcall *v7)(Scaleform::Render::ContextImpl::EntryData *, Scaleform::Render::LinearHeap *); // rax
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> srca; // [rsp+48h] [rbp+10h]

  v2 = src.pC;
  v3 = this;
  srca.pC = (Scaleform::Render::TreeNode::NodeData *)src.pC->vfptr;
  Scaleform::Render::TreeNode::NodeData::NodeData(
    (Scaleform::Render::TreeNode::NodeData *)&this->vfptr,
    (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&srca);
  v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeText::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable';
  v3->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  v4 = v2->vfptr;
  v5 = v2->vfptr[3].__vecDelDtor;
  if ( v5 )
    _InterlockedExchangeAdd((volatile signed __int32 *)v5 + 2, 1u);
  v3->pDocView.pObject = (Scaleform::Render::Text::DocView *)v4[3].__vecDelDtor;
  v6 = v2->vfptr;
  v7 = v2->vfptr[3].ConstructCopy;
  if ( v7 )
    _InterlockedExchangeAdd((volatile signed __int32 *)v7 + 2, 1u);
  v3->pLayout.pObject = (Scaleform::Render::TextLayout *)v6[3].ConstructCopy;
  v3->TextFlags = (char)v2->vfptr[3].CopyTo;
}

// File Line: 43
// RVA: 0x94BB40
void __fastcall Scaleform::Render::TreeText::NodeData::~NodeData(Scaleform::Render::TreeText::NodeData *this)
{
  Scaleform::Render::TreeText::NodeData *v1; // rdi
  Scaleform::Render::TextLayout *v2; // rcx
  Scaleform::Render::Text::DocView *v3; // rcx
  Scaleform::Render::StateData::Interface *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeText::NodeData::`vftable';
  v2 = this->pLayout.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
    v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  v3 = v1->pDocView.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  v4 = v1->States.pInterface;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
      (*(void (__fastcall **)(unsigned __int64, unsigned __int64, signed __int64))(*(_QWORD *)((unsigned __int64)v4 & 0xFFFFFFFFFFFFFFFEui64)
                                                                                 + 16i64))(
        (unsigned __int64)v4 & 0xFFFFFFFFFFFFFFFEui64,
        v1->States.DataValue,
        1i64);
    else
      Scaleform::Render::StateData::ArrayData::Release(v1->States.pArray, (unsigned __int64)v4 >> 1);
    v1->States.ArraySize = 0i64;
    v1->States.DataValue = 0i64;
  }
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
}

// File Line: 47
// RVA: 0x9A10F0
bool __fastcall Scaleform::Render::TreeText::NodeData::PropagateUp(Scaleform::Render::TreeText::NodeData *this, Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::Entry *v2; // r15
  Scaleform::Render::TreeText::NodeData *v3; // rdi
  Scaleform::Render::Text::DocView *v4; // rcx
  unsigned int v5; // ebx
  Scaleform::Render::ContextImpl::EntryData *v6; // rsi
  Scaleform::Render::TextLayout *v7; // rax
  __int64 v8; // rax
  __int64 v9; // r14
  __int64 v10; // rcx
  float *v11; // rax
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm8_4
  float v15; // xmm9_4
  Scaleform::Render::StateBag *v16; // rax
  _QWORD *v17; // rsi
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
  Scaleform::Render::Rect<float> bounds; // [rsp+20h] [rbp-B8h]
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-A8h]
  Scaleform::Render::Rect<float> v37; // [rsp+40h] [rbp-98h]
  __int64 v38; // [rsp+50h] [rbp-88h]
  Scaleform::Render::TextLayout::Builder bld; // [rsp+60h] [rbp-78h]
  int v40; // [rsp+8E8h] [rbp+810h]
  Scaleform::Render::TextLayout *vars0; // [rsp+8F0h] [rbp+818h]

  v38 = -2i64;
  v2 = entry;
  v3 = this;
  bounds = 0i64;
  pr = 0i64;
  v37 = 0i64;
  v4 = this->pDocView.pObject;
  v5 = 0;
  if ( v4 )
  {
    if ( v4->RTFlags & 3 )
      Scaleform::Render::Text::DocView::Format(v4);
    if ( v3->TextFlags & 1 )
    {
      Scaleform::Render::TextLayout::Builder::Builder(&bld, Scaleform::Memory::pGlobalHeap);
      Scaleform::Render::Text::DocView::CreateVisibleTextLayout(v3->pDocView.pObject, &bld);
      v6 = Scaleform::Render::ContextImpl::Entry::getWritableData(v2, 0x400u);
      v40 = 74;
      v7 = (Scaleform::Render::TextLayout *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              v3,
                                              192ui64,
                                              (Scaleform::AllocInfo *)&v40);
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
      v10 = *(_QWORD *)&v6[9].Type;
      if ( v10 && !_InterlockedDecrement((volatile signed __int32 *)(v10 + 8)) && v10 )
        (**(void (__fastcall ***)(__int64, signed __int64))v10)(v10, 1i64);
      *(_QWORD *)&v6[9].Type = v9;
      LOBYTE(v6[10].vfptr) &= 0xFEu;
      Scaleform::Render::TextLayout::Builder::~Builder(&bld);
    }
  }
  v11 = (float *)v3->pLayout.pObject;
  if ( v11 )
  {
    v12 = v11[20];
    bounds.x1 = v12;
    v13 = v11[21];
    bounds.y1 = v13;
    v14 = v11[22];
    bounds.x2 = v14;
    v15 = v11[23];
    bounds.y2 = v15;
    v37.x1 = v12;
    v37.y1 = v13;
    v37.x2 = v14;
    v37.y2 = v15;
    v16 = Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::FilterState>((Scaleform::Render::TreeNode::NodeData *)&v3->vfptr);
    if ( v16 )
    {
      v17 = v16->pData;
      if ( v17 )
      {
        if ( *((_DWORD *)v17 + 6) )
        {
          do
            Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
              *(Scaleform::Render::Filter **)(v17[2] + 8i64 * v5++),
              &bounds);
          while ( v5 < *((_DWORD *)v17 + 6) );
          v15 = bounds.y2;
          v14 = bounds.x2;
          v13 = bounds.y1;
          v12 = bounds.x1;
        }
      }
    }
    if ( (v3->Flags >> 9) & 1 )
    {
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(&v3->M34, &pr, &bounds);
    }
    else
    {
      v18 = _mm_shuffle_ps(*(__m128 *)&v3->M34.M[0][0], *(__m128 *)&v3->M34.M[1][0], 255);
      v19 = _mm_unpacklo_ps(*(__m128 *)&v3->M34.M[0][0], *(__m128 *)&v3->M34.M[1][0]);
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
    v15 = bounds.y2;
    v14 = bounds.x2;
    v13 = bounds.y1;
    v12 = bounds.x1;
  }
  v28 = pr.y2;
  v29 = pr.x2;
  v30 = pr.y1;
  v31 = pr.x1;
  if ( v12 != v3->AproxLocalBounds.x1
    || v14 != v3->AproxLocalBounds.x2
    || v13 != v3->AproxLocalBounds.y1
    || v15 != v3->AproxLocalBounds.y2
    || pr.x1 != v12
    || pr.x2 != v14
    || pr.y1 != v13
    || pr.y2 != v15 )
  {
    v33 = Scaleform::Render::ContextImpl::Entry::getWritableData(v2, 8u);
    *(float *)&v33[7].vfptr = v12;
    *((float *)&v33[7].vfptr + 1) = v13;
    *(float *)&v33[7].Type = v14;
    *(float *)(&v33[7].Flags + 1) = v15;
    *(float *)&v33[8].vfptr = v31;
    *((float *)&v33[8].vfptr + 1) = v30;
    *(float *)&v33[8].Type = v29;
    *(float *)(&v33[8].Flags + 1) = v28;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState((Scaleform::Render::TreeNode::NodeData *)v33, &v37);
    v32 = v3->Flags & 1;
  }
  else
  {
    LOBYTE(v32) = 0;
  }
  return v32;
}

// File Line: 96
// RVA: 0x9F8F70
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::TreeText::NodeData::updateCache(Scaleform::Render::TreeText::NodeData *this, Scaleform::Render::TreeCacheNode *pparent, Scaleform::Render::TreeCacheNode *pinsert, Scaleform::Render::TreeNode *pnode, unsigned __int16 depth)
{
  Scaleform::Render::TreeText *v5; // rbp
  Scaleform::Render::TreeCacheNode *v6; // r15
  Scaleform::Render::TreeCacheNode *v7; // rsi
  Scaleform::Render::TreeText::NodeData *v8; // r14
  Scaleform::Render::TreeCacheNode *v9; // rbx
  int v10; // edi
  Scaleform::Render::TreeCacheNode *v11; // r9
  Scaleform::Render::TreeCacheText *v12; // rax
  Scaleform::Render::TreeCacheNode *v13; // rax
  int v15; // [rsp+88h] [rbp+20h]

  v5 = (Scaleform::Render::TreeText *)pnode;
  v6 = pinsert;
  v7 = pparent;
  v8 = this;
  v9 = pnode->pRenderer;
  if ( !v9 )
  {
    v10 = this->Flags & 0x21 | (unsigned __int8)((pparent->Flags | 2 * (this->Flags & 0x20)) & 0xC0);
    v11 = pparent;
    do
    {
      if ( (_BYTE)v9 )
        break;
      LOBYTE(v9) = (*(_WORD *)((*(_QWORD *)(*(_QWORD *)(((_QWORD)v11->pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                                          + 8
                                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1] - ((_QWORD)v11->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                           + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v11->pNode[-1] - ((_QWORD)v11->pNode & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                          + 40) & 0xFFFFFFFFFFFFFFFEui64)
                             + 10) >> 9) & 1;
      v11 = v11->pParent;
    }
    while ( v11 );
    v15 = 71;
    v12 = (Scaleform::Render::TreeCacheText *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                pparent,
                                                448ui64,
                                                (Scaleform::AllocInfo *)&v15);
    if ( v12 )
    {
      Scaleform::Render::TreeCacheText::TreeCacheText(v12, v5, v7->pRenderer2D, v10 | ((_BYTE)v9 != 0 ? 0x200 : 0));
      v9 = v13;
    }
    else
    {
      v9 = 0i64;
    }
    if ( !v9 )
      return 0i64;
    v5->pRenderer = v9;
  }
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
    v9,
    v7,
    v6,
    (Scaleform::Render::TreeNode::NodeData *)&v8->vfptr,
    depth);
  return v9;
}

// File Line: 126
// RVA: 0x960E40
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::TreeText::NodeData::CloneCreate(Scaleform::Render::TreeText::NodeData *this, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v2; // rdi
  Scaleform::Render::TreeText::NodeData *v3; // rsi
  Scaleform::Render::TreeText::NodeData *v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData> src; // [rsp+50h] [rbp+8h]
  Scaleform::Render::TreeText::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeText::NodeData *v9; // [rsp+60h] [rbp+18h]

  v2 = context;
  v3 = this;
  v4 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176ui64, 0i64);
  v5 = (Scaleform::Render::ContextImpl::EntryData *)&v4->vfptr;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = v3;
    Scaleform::Render::TreeText::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeText::NodeData>)&src);
  }
  return Scaleform::Render::ContextImpl::Context::createEntryHelper(v2, v5);
}

// File Line: 133
// RVA: 0x9B0F40
void __fastcall Scaleform::Render::TreeText::SetLayout(Scaleform::Render::TreeText *this, Scaleform::Render::TextLayout::Builder *b)
{
  Scaleform::Render::TextLayout::Builder *v2; // rdi
  Scaleform::Render::TreeText *v3; // rbx
  Scaleform::Render::ContextImpl::EntryData *v4; // rsi
  Scaleform::Render::TextLayout *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rdi
  __int64 v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rdx
  signed __int64 v10; // rcx
  int v11; // [rsp+60h] [rbp+18h]
  Scaleform::Render::TextLayout *v12; // [rsp+68h] [rbp+20h]

  v2 = b;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v11 = 74;
  v5 = (Scaleform::Render::TextLayout *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeText *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                          Scaleform::Memory::pGlobalHeap,
                                          v3,
                                          192i64,
                                          &v11,
                                          -2i64);
  v12 = v5;
  if ( v5 )
  {
    Scaleform::Render::TextLayout::TextLayout(v5, v2);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = *(_QWORD *)&v4[9].Type;
  if ( v8 && !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) && v8 )
    (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
  *(_QWORD *)&v4[9].Type = v7;
  v9 = &v3->PNode;
  if ( !v3->PNode.pPrev )
  {
    v10 = *(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x18) + 64i64;
    v9->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v10;
    v3->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v10;
    *(_QWORD *)(*(_QWORD *)v10 + 8i64) = v9;
    *(_QWORD *)v10 = v9;
  }
}

// File Line: 140
// RVA: 0x992900
void __fastcall Scaleform::Render::TreeText::Init(Scaleform::Render::TreeText *this, Scaleform::Render::Text::Allocator *pallocator, Scaleform::Render::Text::FontManagerBase *fntMgr, Scaleform::Log *log)
{
  Scaleform::Log *v4; // rsi
  Scaleform::Render::Text::FontManagerBase *v5; // r14
  Scaleform::Render::Text::Allocator *v6; // r15
  Scaleform::Render::TreeText *v7; // rbx
  Scaleform::Render::ContextImpl::EntryData *v8; // rdi
  Scaleform::Render::Text::ParagraphFormat *v9; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v10; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v11; // rsi
  Scaleform::Render::ContextImpl::EntryDataVtbl *v12; // rcx
  Scaleform::MemoryHeap *v13; // rax
  Scaleform::MemoryHeap *v14; // rdx
  Scaleform::MemoryHeap *v15; // rcx
  Scaleform::MemoryHeap *v16; // rax
  Scaleform::Render::Text::StyledText *v17; // rdi
  Scaleform::Render::Text::Allocator *v18; // rax
  Scaleform::Render::Text::ParagraphFormat *v19; // rsi
  Scaleform::Render::Text::ParagraphFormat *v20; // rcx
  Scaleform::Render::Text::ParagraphFormat srcfmt; // [rsp+0h] [rbp-69h]
  int v22; // [rsp+28h] [rbp-41h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+30h] [rbp-39h]
  Scaleform::StringDH *v24; // [rsp+38h] [rbp-31h]
  Scaleform::Render::Text::TextFormat defaultTextFmt; // [rsp+40h] [rbp-29h]
  __int64 v26; // [rsp+90h] [rbp+27h]

  v26 = -2i64;
  v4 = log;
  v5 = fntMgr;
  v6 = pallocator;
  v7 = this;
  v8 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  if ( !v8[9].vfptr )
  {
    v22 = 74;
    v9 = (Scaleform::Render::Text::ParagraphFormat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeText *, signed __int64, int *, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       v7,
                                                       352i64,
                                                       &v22,
                                                       *(_QWORD *)&v22);
    key = v9;
    if ( v9 )
    {
      Scaleform::Render::Text::DocView::DocView((Scaleform::Render::Text::DocView *)v9, v6, v5, v4);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    v12 = v8[9].vfptr;
    if ( v12 && !_InterlockedDecrement((volatile signed __int32 *)&v12->ConstructCopy) && v12 )
      (*(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryDataVtbl *, signed __int64))v12->__vecDelDtor)(
        v12,
        1i64);
    v8[9].vfptr = v11;
    v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v7);
    v14 = v13;
    defaultTextFmt.pAllocator = 0i64;
    defaultTextFmt.RefCount = 1;
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    v24 = &defaultTextFmt.FontList;
    defaultTextFmt.FontList.pHeap = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    defaultTextFmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    v16 = Scaleform::Memory::pGlobalHeap;
    if ( v14 )
      v16 = v14;
    v24 = &defaultTextFmt.Url;
    defaultTextFmt.Url.pHeap = v16;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    defaultTextFmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    defaultTextFmt.pImageDesc.pObject = 0i64;
    defaultTextFmt.pFontHandle.pObject = 0i64;
    defaultTextFmt.ColorV = -16777216;
    defaultTextFmt.LetterSpacing = 0.0;
    defaultTextFmt.FontSize = 0;
    defaultTextFmt.FormatFlags = 0;
    defaultTextFmt.PresentMask = 0;
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&defaultTextFmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
      (Scaleform::Render::Text::StyledText *)v8[9].vfptr->CopyTo,
      &defaultTextFmt);
    srcfmt.pAllocator = 0i64;
    srcfmt.RefCount = 1;
    *(_QWORD *)&srcfmt.BlockIndent = 0i64;
    srcfmt.RightMargin = 0;
    srcfmt.PresentMask = 1;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    srcfmt.pTabStops = 0i64;
    srcfmt.PresentMask &= 0xFFBFu;
    v17 = (Scaleform::Render::Text::StyledText *)v8[9].vfptr->CopyTo;
    v18 = Scaleform::Render::Text::StyledText::GetAllocator(v17);
    v19 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v18, &srcfmt);
    v20 = v17->pDefaultParagraphFormat.pObject;
    if ( v20 )
      Scaleform::Render::Text::ParagraphFormat::Release(v20);
    v17->pDefaultParagraphFormat.pObject = v19;
    Scaleform::Render::TreeText::SetAAMode(v7, 0);
    if ( srcfmt.pAllocator )
    {
      key = &srcfmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&srcfmt.pAllocator->ParagraphFormatStorage.pTable,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, srcfmt.pTabStops);
    Scaleform::Render::Text::TextFormat::~TextFormat(&defaultTextFmt);
  }
}

// File Line: 165
// RVA: 0x992BD0
void __fastcall Scaleform::Render::TreeText::Init(Scaleform::Render::TreeText *this, Scaleform::Render::Text::DocView *docView)
{
  Scaleform::Render::Text::DocView *v2; // rbx
  Scaleform::Render::ContextImpl::EntryData *v3; // rax
  Scaleform::Render::ContextImpl::EntryData *v4; // rdi
  Scaleform::Render::ContextImpl::EntryDataVtbl *v5; // rcx

  v2 = docView;
  v3 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v4 = v3;
  if ( v2 )
    _InterlockedExchangeAdd(&v2->RefCount, 1u);
  v5 = v3[9].vfptr;
  if ( v5 && !_InterlockedDecrement((volatile signed __int32 *)&v5->ConstructCopy) && v5 )
  {
    (*(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryDataVtbl *, signed __int64))v5->__vecDelDtor)(v5, 1i64);
    v4[9].vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)v2;
  }
  else
  {
    v3[9].vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)v2;
  }
}

// File Line: 171
// RVA: 0x982D40
Scaleform::Render::Text::DocView *__fastcall Scaleform::Render::TreeText::GetDocView(Scaleform::Render::TreeText *this)
{
  return *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x20)
                                                          + 8
                                                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                           + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                          + 40)
                                              + 144i64);
}

// File Line: 177
// RVA: 0x9B4260
void __fastcall Scaleform::Render::TreeText::SetText(Scaleform::Render::TreeText *this, const char *putf8Str, unsigned __int64 lengthInBytes)
{
  Scaleform::Render::TreeText *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::Text::DocView *v5; // rcx
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rax

  v3 = this;
  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v5 )
    Scaleform::Render::Text::DocView::SetText(v5, putf8Str, lengthInBytes);
  v6 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v3->0, 0x400u);
  v7 = &v3->PNode;
  LOBYTE(v6[10].vfptr) |= 1u;
  if ( !v3->PNode.pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    v9 = v8[4].pPrev;
    v8 += 4;
    v7->pPrev = v9;
    v3->PNode.pNext = v8;
    v8->pPrev->pNext = v7;
    v8->pPrev = v7;
  }
}

// File Line: 187
// RVA: 0x9B4310
void __fastcall Scaleform::Render::TreeText::SetText(Scaleform::Render::TreeText *this, const wchar_t *pstr, unsigned __int64 lengthInChars)
{
  Scaleform::Render::TreeText *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::Text::DocView *v5; // rcx
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rax

  v3 = this;
  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v5 )
    Scaleform::Render::Text::DocView::SetText(v5, pstr, lengthInChars);
  v6 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v3->0, 0x400u);
  v7 = &v3->PNode;
  LOBYTE(v6[10].vfptr) |= 1u;
  if ( !v3->PNode.pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    v9 = v8[4].pPrev;
    v8 += 4;
    v7->pPrev = v9;
    v3->PNode.pNext = v8;
    v8->pPrev->pNext = v7;
    v8->pPrev = v7;
  }
}

// File Line: 207
// RVA: 0x98CA10
Scaleform::String *__fastcall Scaleform::Render::TreeText::GetText(Scaleform::Render::TreeText *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx
  Scaleform::Render::Text::DocView *v3; // rcx

  v2 = result;
  v3 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v3 )
    Scaleform::Render::Text::DocView::GetText(v3, result);
  else
    Scaleform::String::String(result, &customWorldMapCaption);
  return v2;
}

// File Line: 217
// RVA: 0x9B0A50
void __fastcall Scaleform::Render::TreeText::SetHtmlText(Scaleform::Render::TreeText *this, const char *putf8Str, unsigned __int64 lengthInBytes, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::TreeText *v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::DocView *v6; // rcx
  Scaleform::Render::ContextImpl::EntryData *v7; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rax

  v4 = this;
  v5 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v6 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v6 )
    Scaleform::Render::Text::DocView::ParseHtml(v6, putf8Str, lengthInBytes, 0, pimgInfoArr, 0i64, 0i64, 0i64);
  v7 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v4->0, 0x400u);
  v8 = &v4->PNode;
  LOBYTE(v7[10].vfptr) |= 1u;
  if ( !v4->PNode.pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v5 + 24);
    v10 = v9[4].pPrev;
    v9 += 4;
    v8->pPrev = v10;
    v4->PNode.pNext = v9;
    v9->pPrev->pNext = v8;
    v9->pPrev = v8;
  }
}

// File Line: 229
// RVA: 0x9B0B10
void __fastcall Scaleform::Render::TreeText::SetHtmlText(Scaleform::Render::TreeText *this, const wchar_t *pstr, unsigned __int64 lengthInChars, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::TreeText *v4; // rbx
  unsigned __int64 v5; // rdi
  Scaleform::Render::Text::DocView *v6; // rcx
  Scaleform::Render::ContextImpl::EntryData *v7; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rax

  v4 = this;
  v5 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v6 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v6 )
    Scaleform::Render::Text::DocView::ParseHtml(v6, pstr, lengthInChars, 0, pimgInfoArr, 0i64, 0i64, 0i64);
  v7 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v4->0, 0x400u);
  v8 = &v4->PNode;
  LOBYTE(v7[10].vfptr) |= 1u;
  if ( !v4->PNode.pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v5 + 24);
    v10 = v9[4].pPrev;
    v9 += 4;
    v8->pPrev = v10;
    v4->PNode.pNext = v9;
    v9->pPrev->pNext = v8;
    v9->pPrev = v8;
  }
}

// File Line: 249
// RVA: 0x9872E0
Scaleform::String *__fastcall Scaleform::Render::TreeText::GetHtmlText(Scaleform::Render::TreeText *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx
  Scaleform::Render::Text::DocView *v3; // rcx

  v2 = result;
  v3 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v3 )
    Scaleform::Render::Text::DocView::GetHtml(v3, result);
  else
    Scaleform::String::String(result, &customWorldMapCaption);
  return v2;
}

// File Line: 257
// RVA: 0x9AE6F0
void __fastcall Scaleform::Render::TreeText::SetBounds(Scaleform::Render::TreeText *this, Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  Scaleform::Render::Text::DocView *v4; // rcx
  Scaleform::Render::ContextImpl::EntryData *v5; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(Scaleform::Render::Text::DocView **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                        + 40)
                                            + 144i64);
  if ( v4 )
    Scaleform::Render::Text::DocView::SetViewRect(v4, r, UseExternally);
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v2->0, 0x400u);
  v6 = &v2->PNode;
  LOBYTE(v5[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v2->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 269
// RVA: 0x9805F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::TreeText::GetBounds(Scaleform::Render::TreeText *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  __int64 v3; // rcx
  __int64 v4; // rdi
  Scaleform::Render::Rect<float> *v5; // rax

  v2 = result;
  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v4 = *(_QWORD *)(v3 + 144);
  if ( v4 )
  {
    if ( *(_BYTE *)(v4 + 347) & 3 )
    {
      Scaleform::Render::Text::DocView::Format(*(Scaleform::Render::Text::DocView **)(v3 + 144));
      *(_BYTE *)(v4 + 347) &= 0xFCu;
    }
    v2->x1 = *(float *)(v4 + 176);
    v2->y1 = *(float *)(v4 + 180);
    v2->x2 = *(float *)(v4 + 184);
    v2->y2 = *(float *)(v4 + 188);
    v5 = v2;
  }
  else
  {
    *(_QWORD *)&result->x1 = 0i64;
    *(_QWORD *)&result->x2 = 0i64;
    v5 = result;
  }
  return v5;
}

// File Line: 293
// RVA: 0x9AEAD0
void __fastcall Scaleform::Render::TreeText::SetColor(Scaleform::Render::TreeText *this, __int64 c, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  unsigned int *v6; // rbx
  Scaleform::Render::TreeText *v7; // rsi
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
  Scaleform::Render::ContextImpl::EntryData *v18; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v19; // rdx
  signed __int64 v20; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h]
  __int64 v22; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h]
  Scaleform::StringDH *v24; // [rsp+E0h] [rbp+67h]

  v22 = -2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = (unsigned int *)c;
  v7 = this;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( v10 )
  {
    v11 = *(_QWORD *)(*(_QWORD *)(v10 + 16) + 16i64);
    if ( v11 )
      v12 = *(_QWORD *)(v11 + 48);
    else
      v12 = ((__int64 (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)();
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v13 = Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v13 = (Scaleform::MemoryHeap *)v12;
    v24 = &fmt.FontList;
    fmt.FontList.pHeap = v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    v14 = Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v14 = (Scaleform::MemoryHeap *)v12;
    v24 = &fmt.Url;
    fmt.Url.pHeap = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    fmt.pImageDesc.pObject = 0i64;
    fmt.pFontHandle.pObject = 0i64;
    fmt.ColorV = -16777216;
    fmt.LetterSpacing = 0.0;
    fmt.FontSize = 0;
    fmt.FormatFlags = 0;
    fmt.PresentMask = 0;
    fmt.ColorV = *v6;
    fmt.PresentMask = 1;
    v15 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v15 + 347) &= 0xEFu;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v15 + 16),
      &fmt,
      v5,
      v4);
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v15 + 8i64))(v15, 1i64);
    v16 = *(_QWORD *)(v9 + 144);
    v17 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v16 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v16 + 16), v17);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  v18 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v7->0, 0x400u);
  LOBYTE(v18[10].vfptr) |= 1u;
  v19 = &v7->PNode;
  if ( !v7->PNode.pPrev )
  {
    v20 = *(_QWORD *)(v8 + 24) + 64i64;
    v19->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v20;
    v7->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v20;
    *(_QWORD *)(*(_QWORD *)v20 + 8i64) = v19;
    *(_QWORD *)v20 = v19;
  }
}

// File Line: 308
// RVA: 0x9AF820
void __fastcall Scaleform::Render::TreeText::SetFont(Scaleform::Render::TreeText *this, const char *pfontName, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  const char *v6; // rbx
  Scaleform::Render::TreeText *v7; // rdi
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
  Scaleform::Render::ContextImpl::EntryData *v20; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v21; // rdx
  signed __int64 v22; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h]
  __int64 v24; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h]
  Scaleform::StringDH *v26; // [rsp+E0h] [rbp+67h]

  v24 = -2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = pfontName;
  v7 = this;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
    v26 = &fmt.FontList;
    fmt.FontList.pHeap = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    v26 = &fmt.Url;
    fmt.Url.pHeap = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
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
    while ( v6[v16] );
    Scaleform::Render::Text::TextFormat::SetFontList(&fmt, v6, v16);
    v17 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v17 + 347) &= 0xEFu;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v17 + 16),
      &fmt,
      v5,
      v4);
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v17 + 8i64))(v17, 1i64);
    v18 = *(_QWORD *)(v9 + 144);
    v19 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v18 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v18 + 16), v19);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  v20 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v7->0, 0x400u);
  LOBYTE(v20[10].vfptr) |= 1u;
  v21 = &v7->PNode;
  if ( !v7->PNode.pPrev )
  {
    v22 = *(_QWORD *)(v8 + 24) + 64i64;
    v21->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v22;
    v7->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v22;
    *(_QWORD *)(*(_QWORD *)v22 + 8i64) = v21;
    *(_QWORD *)v22 = v21;
  }
}

// File Line: 323
// RVA: 0x9AFED0
void __fastcall Scaleform::Render::TreeText::SetFontSize(Scaleform::Render::TreeText *this, float fontSize, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  Scaleform::Render::TreeText *v6; // rdi
  unsigned __int64 v7; // rsi
  __int64 v8; // r14
  __int64 v9; // r8
  _QWORD *v10; // r8
  __int64 v11; // rdx
  Scaleform::MemoryHeap *v12; // rdx
  Scaleform::MemoryHeap *v13; // rax
  Scaleform::Render::Text::Allocator *v14; // rax
  signed int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // rbx
  Scaleform::Render::Text::TextFormat *v18; // rax
  Scaleform::Render::ContextImpl::EntryData *v19; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v20; // rdx
  signed __int64 v21; // rcx
  unsigned __int64 v22; // [rsp+8h] [rbp-79h]
  Scaleform::MemoryHeap *v23; // [rsp+10h] [rbp-71h]
  unsigned __int64 v24; // [rsp+18h] [rbp-69h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+20h] [rbp-61h]
  unsigned __int64 *v26; // [rsp+E8h] [rbp+67h]

  fmt.Url.pHeap = (Scaleform::MemoryHeap *)-2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = this;
  v7 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
    v26 = &v22;
    v23 = v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v22 = (unsigned __int64)&Scaleform::String::NullData | 2;
    v14 = (Scaleform::Render::Text::Allocator *)Scaleform::Memory::pGlobalHeap;
    if ( v12 )
      v14 = (Scaleform::Render::Text::Allocator *)v12;
    v26 = &v24;
    fmt.pAllocator = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v24 = (unsigned __int64)&Scaleform::String::NullData | 2;
    *(_QWORD *)&fmt.RefCount = 0i64;
    fmt.FontList.HeapTypeBits = 0i64;
    fmt.FontList.pHeap = (Scaleform::MemoryHeap *)4278190080i64;
    LOWORD(fmt.Url.pData) = 0;
    BYTE2(fmt.Url.HeapTypeBits) = 0;
    WORD2(fmt.Url.HeapTypeBits) = 0;
    if ( fontSize >= 3276.8 )
      LOWORD(v15) = -1;
    else
      v15 = (signed int)(float)(fontSize * 20.0);
    LOWORD(fmt.Url.pData) = v15;
    WORD2(fmt.Url.HeapTypeBits) |= 8u;
    v16 = *(_QWORD *)(v8 + 144);
    *(_BYTE *)(v16 + 347) &= 0xEFu;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v16 + 16),
      &fmt,
      v5,
      v4);
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v16 + 8i64))(v16, 1i64);
    v17 = *(_QWORD *)(v8 + 144);
    v18 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v17 + 16) + 56i64),
            (Scaleform::Render::Text::TextFormat *)((char *)&fmt + 48),
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v17 + 16), v18);
    Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)((char *)&fmt + 48));
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  v19 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v6->0, 0x400u);
  LOBYTE(v19[10].vfptr) |= 1u;
  v20 = &v6->PNode;
  if ( !v6->PNode.pPrev )
  {
    v21 = *(_QWORD *)(v7 + 24) + 64i64;
    v20->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v21;
    v6->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v21;
    *(_QWORD *)(*(_QWORD *)v21 + 8i64) = v20;
    *(_QWORD *)v21 = v20;
  }
}

// File Line: 338
// RVA: 0x9B0110
void __fastcall Scaleform::Render::TreeText::SetFontStyle(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::FontStyle fontStyle, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  Scaleform::Render::TreeText::FontStyle v6; // ebx
  Scaleform::Render::TreeText *v7; // rdi
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
  Scaleform::Render::Text::FontHandle *v18; // rcx
  char v19; // dl
  char v20; // al
  Scaleform::Render::Text::FontHandle *v21; // rcx
  char v22; // dl
  __int64 v23; // rbx
  __int64 v24; // rbx
  Scaleform::Render::Text::TextFormat *v25; // rax
  Scaleform::Render::ContextImpl::EntryData *v26; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v27; // rdx
  signed __int64 v28; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h]
  __int64 v30; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h]
  Scaleform::StringDH *v32; // [rsp+E0h] [rbp+67h]

  v30 = -2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = fontStyle;
  v7 = this;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v10 = *(_QWORD *)(v9 + 144);
  if ( !v10 )
    goto LABEL_65;
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
  v32 = &fmt.FontList;
  fmt.FontList.pHeap = v14;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v15 = Scaleform::Memory::pGlobalHeap;
  if ( v13 )
    v15 = v13;
  v32 = &fmt.Url;
  fmt.Url.pHeap = v15;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  fmt.pImageDesc.pObject = 0i64;
  fmt.pFontHandle.pObject = 0i64;
  fmt.ColorV = -16777216;
  fmt.LetterSpacing = 0.0;
  fmt.FontSize = 0;
  fmt.FormatFlags = 0;
  fmt.PresentMask = 0;
  if ( v6 == 0 )
  {
    v21 = fmt.pFontHandle.pObject;
    if ( (fmt.PresentMask >> 11) & 1 && fmt.FormatFlags & 1 )
    {
      if ( fmt.pFontHandle.pObject && !_InterlockedDecrement(&fmt.pFontHandle.pObject->RefCount) && v21 )
        v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
      v21 = 0i64;
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v22 = fmt.FormatFlags & 0xFE;
    goto LABEL_54;
  }
  v16 = v6 - 1;
  if ( !v16 )
  {
    v21 = fmt.pFontHandle.pObject;
    if ( (fmt.PresentMask >> 11) & 1 && !(fmt.FormatFlags & 1) )
    {
      if ( fmt.pFontHandle.pObject && !_InterlockedDecrement(&fmt.pFontHandle.pObject->RefCount) && v21 )
        v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
      v21 = 0i64;
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v22 = fmt.FormatFlags | 1;
LABEL_54:
    fmt.FormatFlags = v22;
    fmt.PresentMask |= 0x10u;
    if ( (fmt.PresentMask >> 11) & 1 && v22 & 2 )
    {
      if ( v21 )
      {
        if ( !_InterlockedDecrement(&v21->RefCount) && v21 )
          v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
        v22 = fmt.FormatFlags;
      }
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v20 = v22 & 0xFD;
    goto LABEL_63;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v18 = fmt.pFontHandle.pObject;
    if ( (fmt.PresentMask >> 11) & 1 && fmt.FormatFlags & 1 )
    {
      if ( fmt.pFontHandle.pObject && !_InterlockedDecrement(&fmt.pFontHandle.pObject->RefCount) && v18 )
        v18->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, 1u);
      v18 = 0i64;
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v19 = fmt.FormatFlags & 0xFE;
    goto LABEL_21;
  }
  if ( v17 == 1 )
  {
    v18 = fmt.pFontHandle.pObject;
    if ( (fmt.PresentMask >> 11) & 1 && !(fmt.FormatFlags & 1) )
    {
      if ( fmt.pFontHandle.pObject && !_InterlockedDecrement(&fmt.pFontHandle.pObject->RefCount) && v18 )
        v18->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, 1u);
      v18 = 0i64;
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v19 = fmt.FormatFlags | 1;
LABEL_21:
    fmt.FormatFlags = v19;
    fmt.PresentMask |= 0x10u;
    if ( (fmt.PresentMask >> 11) & 1 && !(v19 & 2) )
    {
      if ( v18 )
      {
        if ( !_InterlockedDecrement(&v18->RefCount) && v18 )
          v18->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, 1u);
        v19 = fmt.FormatFlags;
      }
      fmt.pFontHandle.pObject = 0i64;
      fmt.PresentMask &= 0xF7FFu;
    }
    v20 = v19 | 2;
LABEL_63:
    fmt.FormatFlags = v20;
    fmt.PresentMask |= 0x20u;
  }
  v23 = *(_QWORD *)(v9 + 144);
  *(_BYTE *)(v23 + 347) &= 0xEFu;
  Scaleform::Render::Text::StyledText::SetTextFormat(*(Scaleform::Render::Text::StyledText **)(v23 + 16), &fmt, v5, v4);
  (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v23 + 8i64))(v23, 1i64);
  v24 = *(_QWORD *)(v9 + 144);
  v25 = Scaleform::Render::Text::TextFormat::Merge(
          *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v24 + 16) + 56i64),
          &result,
          &fmt);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v24 + 16), v25);
  Scaleform::Render::Text::TextFormat::~TextFormat(&result);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
LABEL_65:
  v26 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v7->0, 0x400u);
  LOBYTE(v26[10].vfptr) |= 1u;
  v27 = &v7->PNode;
  if ( !v7->PNode.pPrev )
  {
    v28 = *(_QWORD *)(v8 + 24) + 64i64;
    v27->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v28;
    v7->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v28;
    *(_QWORD *)(*(_QWORD *)v28 + 8i64) = v27;
    *(_QWORD *)v28 = v27;
  }
}

// File Line: 371
// RVA: 0x9B1270
void __fastcall Scaleform::Render::TreeText::SetLetterSpacing(Scaleform::Render::TreeText *this, float letterSpacing, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  Scaleform::Render::TreeText *v6; // rsi
  unsigned __int64 v7; // rdi
  __int64 v8; // r14
  __int64 v9; // rdx
  __int64 v10; // rax
  __int64 v11; // rdx
  Scaleform::MemoryHeap *v12; // rax
  Scaleform::Render::Text::Allocator *v13; // rax
  __int64 v14; // rbx
  __int64 v15; // rbx
  Scaleform::Render::Text::TextFormat *v16; // rax
  Scaleform::Render::ContextImpl::EntryData *v17; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v18; // rdx
  signed __int64 v19; // rcx
  unsigned __int64 v20; // [rsp+8h] [rbp-79h]
  Scaleform::MemoryHeap *v21; // [rsp+10h] [rbp-71h]
  unsigned __int64 v22; // [rsp+18h] [rbp-69h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+20h] [rbp-61h]
  unsigned __int64 *v24; // [rsp+E8h] [rbp+67h]

  fmt.Url.pHeap = (Scaleform::MemoryHeap *)-2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = this;
  v7 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v8 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v9 = *(_QWORD *)(v8 + 144);
  if ( v9 )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(v9 + 16) + 16i64);
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 48);
    else
      v11 = ((__int64 (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)();
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    v12 = Scaleform::Memory::pGlobalHeap;
    if ( v11 )
      v12 = (Scaleform::MemoryHeap *)v11;
    v24 = &v20;
    v21 = v12;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v20 = (unsigned __int64)&Scaleform::String::NullData | 2;
    v13 = (Scaleform::Render::Text::Allocator *)Scaleform::Memory::pGlobalHeap;
    if ( v11 )
      v13 = (Scaleform::Render::Text::Allocator *)v11;
    v24 = &v22;
    fmt.pAllocator = v13;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v22 = (unsigned __int64)&Scaleform::String::NullData | 2;
    *(_QWORD *)&fmt.RefCount = 0i64;
    fmt.FontList.HeapTypeBits = 0i64;
    fmt.FontList.pHeap = (Scaleform::MemoryHeap *)4278190080i64;
    LOWORD(fmt.Url.pData) = 0;
    BYTE2(fmt.Url.HeapTypeBits) = 0;
    WORD2(fmt.Url.HeapTypeBits) = 2;
    *((float *)&fmt.FontList.pHeap + 1) = letterSpacing * 20.0;
    v14 = *(_QWORD *)(v8 + 144);
    *(_BYTE *)(v14 + 347) &= 0xEFu;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v14 + 16),
      &fmt,
      v5,
      v4);
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v14 + 8i64))(v14, 1i64);
    v15 = *(_QWORD *)(v8 + 144);
    v16 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v15 + 16) + 56i64),
            (Scaleform::Render::Text::TextFormat *)((char *)&fmt + 48),
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v15 + 16), v16);
    Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)((char *)&fmt + 48));
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  v17 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v6->0, 0x400u);
  LOBYTE(v17[10].vfptr) |= 1u;
  v18 = &v6->PNode;
  if ( !v6->PNode.pPrev )
  {
    v19 = *(_QWORD *)(v7 + 24) + 64i64;
    v18->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v19;
    v6->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v19;
    *(_QWORD *)(*(_QWORD *)v19 + 8i64) = v18;
    *(_QWORD *)v19 = v18;
  }
}

// File Line: 386
// RVA: 0x9B4EC0
void __fastcall Scaleform::Render::TreeText::SetUnderline(Scaleform::Render::TreeText *this, bool underline, unsigned __int64 startPos, unsigned __int64 endPos)
{
  unsigned __int64 v4; // r15
  unsigned __int64 v5; // r12
  bool v6; // bl
  Scaleform::Render::TreeText *v7; // rdi
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
  Scaleform::Render::ContextImpl::EntryData *v20; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v21; // rdx
  signed __int64 v22; // rcx
  Scaleform::Render::Text::TextFormat fmt; // [rsp+0h] [rbp-79h]
  __int64 v24; // [rsp+50h] [rbp-29h]
  Scaleform::Render::Text::TextFormat result; // [rsp+58h] [rbp-21h]
  Scaleform::StringDH *v26; // [rsp+E0h] [rbp+67h]

  v24 = -2i64;
  v4 = endPos;
  v5 = startPos;
  v6 = underline;
  v7 = this;
  v8 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v9 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
    v26 = &fmt.FontList;
    fmt.FontList.pHeap = v14;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    v15 = Scaleform::Memory::pGlobalHeap;
    if ( v13 )
      v15 = v13;
    v26 = &fmt.Url;
    fmt.Url.pHeap = v15;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    fmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
    fmt.pImageDesc.pObject = 0i64;
    fmt.pFontHandle.pObject = 0i64;
    fmt.ColorV = -16777216;
    fmt.LetterSpacing = 0.0;
    fmt.FontSize = 0;
    fmt.FormatFlags = 0;
    fmt.PresentMask = 0;
    if ( v6 )
      v16 = 4;
    else
      v16 = 0;
    fmt.FormatFlags = v16;
    fmt.PresentMask |= 0x40u;
    v17 = *(_QWORD *)(v9 + 144);
    *(_BYTE *)(v17 + 347) &= 0xEFu;
    Scaleform::Render::Text::StyledText::SetTextFormat(
      *(Scaleform::Render::Text::StyledText **)(v17 + 16),
      &fmt,
      v5,
      v4);
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v17 + 8i64))(v17, 1i64);
    v18 = *(_QWORD *)(v9 + 144);
    v19 = Scaleform::Render::Text::TextFormat::Merge(
            *(Scaleform::Render::Text::TextFormat **)(*(_QWORD *)(v18 + 16) + 56i64),
            &result,
            &fmt);
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(*(Scaleform::Render::Text::StyledText **)(v18 + 16), v19);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
  }
  v20 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v7->0, 0x400u);
  LOBYTE(v20[10].vfptr) |= 1u;
  v21 = &v7->PNode;
  if ( !v7->PNode.pPrev )
  {
    v22 = *(_QWORD *)(v8 + 24) + 64i64;
    v21->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v22;
    v7->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v22;
    *(_QWORD *)(*(_QWORD *)v22 + 8i64) = v21;
    *(_QWORD *)v22 = v21;
  }
}

// File Line: 401
// RVA: 0x9B1E50
void __fastcall Scaleform::Render::TreeText::SetMultiline(Scaleform::Render::TreeText *this, bool multiline)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v4 )
  {
    if ( multiline )
      *(_BYTE *)(v4 + 344) |= 4u;
    else
      *(_BYTE *)(v4 + 344) &= 0xFBu;
  }
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v6 = &v2->PNode;
  LOBYTE(v5[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v2->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 416
// RVA: 0x997B30
__int64 __fastcall Scaleform::Render::TreeText::IsMultiline(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 144i64);
  if ( result )
    result = ((unsigned int)*(unsigned __int8 *)(result + 344) >> 2) & 1;
  return result;
}

// File Line: 427
// RVA: 0x9B5F40
void __fastcall Scaleform::Render::TreeText::SetWordWrap(Scaleform::Render::TreeText *this, bool wordWrap)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  char v5; // cl
  char v6; // cl
  Scaleform::Render::ContextImpl::EntryData *v7; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( !v4 )
    goto LABEL_8;
  v5 = *(_BYTE *)(v4 + 344);
  if ( wordWrap )
  {
    if ( v5 & 8 )
      goto LABEL_8;
    v6 = v5 | 8;
  }
  else
  {
    if ( !(v5 & 8) )
      goto LABEL_8;
    v6 = v5 & 0xF7;
  }
  *(_BYTE *)(v4 + 347) |= 2u;
  *(_BYTE *)(v4 + 344) = v6;
LABEL_8:
  v7 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v2->0, 0x400u);
  v8 = &v2->PNode;
  LOBYTE(v7[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v10 = v9[4].pPrev;
    v9 += 4;
    v8->pPrev = v10;
    v2->PNode.pNext = v9;
    v9->pPrev->pNext = v8;
    v9->pPrev = v8;
  }
}

// File Line: 443
// RVA: 0x998410
__int64 __fastcall Scaleform::Render::TreeText::IsWordWrap(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 144i64);
  if ( result )
    result = ((unsigned int)*(unsigned __int8 *)(result + 344) >> 3) & 1;
  return result;
}

// File Line: 453
// RVA: 0x9AE0C0
void __fastcall Scaleform::Render::TreeText::SetAlignment(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::Alignment a)
{
  Scaleform::Render::TreeText *v2; // r14
  unsigned __int64 v3; // rsi
  __int64 v4; // rdi
  signed __int16 v5; // dx
  Scaleform::Render::Text::StyledText **v6; // rbx
  __int64 v7; // rdi
  Scaleform::Render::Text::ParagraphFormat *v8; // rbx
  Scaleform::Render::Text::StyledText *v9; // rdi
  Scaleform::Render::Text::Allocator *v10; // rax
  Scaleform::Render::Text::ParagraphFormat *v11; // rbx
  Scaleform::Render::Text::ParagraphFormat *v12; // rcx
  Scaleform::Render::ContextImpl::EntryData *v13; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v14; // rdx
  signed __int64 v15; // rcx
  Scaleform::Render::Text::ParagraphFormat fmt; // [rsp+28h] [rbp-58h]
  Scaleform::Render::Text::ParagraphFormat result; // [rsp+50h] [rbp-30h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+A0h] [rbp+20h]

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  if ( *(_QWORD *)(v4 + 144) )
  {
    switch ( a )
    {
      case 1:
        v5 = 1;
        break;
      case 2:
        v5 = 3;
        break;
      case 3:
        v5 = 2;
        break;
      default:
        v5 = 0;
        break;
    }
    fmt.pAllocator = 0i64;
    fmt.RefCount = 1;
    fmt.pTabStops = 0i64;
    *(_QWORD *)&fmt.BlockIndent = 0i64;
    *(_DWORD *)&fmt.RightMargin = 0;
    fmt.PresentMask = (v5 << 9) & 0x600 | 1;
    v6 = *(Scaleform::Render::Text::StyledText ***)(v4 + 144);
    Scaleform::Render::Text::StyledText::SetParagraphFormat(v6[2], &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
    (*(void (__fastcall **)(Scaleform::Render::Text::StyledText **, signed __int64))&(*v6)->RefCount)(v6, 1i64);
    v7 = *(_QWORD *)(v4 + 144);
    v8 = Scaleform::Render::Text::ParagraphFormat::Merge(
           *(Scaleform::Render::Text::ParagraphFormat **)(*(_QWORD *)(v7 + 16) + 48i64),
           &result,
           &fmt);
    v9 = *(Scaleform::Render::Text::StyledText **)(v7 + 16);
    v10 = Scaleform::Render::Text::StyledText::GetAllocator(v9);
    v11 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v10, v8);
    v12 = v9->pDefaultParagraphFormat.pObject;
    if ( v12 )
      Scaleform::Render::Text::ParagraphFormat::Release(v12);
    v9->pDefaultParagraphFormat.pObject = v11;
    if ( result.pAllocator )
    {
      key = &result;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&result.pAllocator->ParagraphFormatStorage.pTable,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, result.pTabStops);
    result.pTabStops = 0i64;
    if ( fmt.pAllocator )
    {
      key = &fmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&fmt.pAllocator->ParagraphFormatStorage.pTable,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, fmt.pTabStops);
    fmt.pTabStops = 0i64;
  }
  v13 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v2->0, 0x400u);
  LOBYTE(v13[10].vfptr) |= 1u;
  v14 = &v2->PNode;
  if ( !v2->PNode.pPrev )
  {
    v15 = *(_QWORD *)(v3 + 24) + 64i64;
    v14->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v15;
    v2->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v15;
    *(_QWORD *)(*(_QWORD *)v15 + 8i64) = v14;
    *(_QWORD *)v15 = v14;
  }
}

// File Line: 476
// RVA: 0x97FD70
__int64 __fastcall Scaleform::Render::TreeText::GetAlignment(Scaleform::Render::TreeText *this)
{
  __int64 v1; // rax
  unsigned int v2; // ebx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v4; // [rsp+38h] [rbp-30h]
  int v5; // [rsp+40h] [rbp-28h]
  void *v6; // [rsp+48h] [rbp-20h]
  __int64 v7; // [rsp+50h] [rbp-18h]
  int v8; // [rsp+58h] [rbp-10h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+70h] [rbp+8h]

  v1 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  if ( !*(_QWORD *)(v1 + 144) )
    return 0i64;
  v4 = 0i64;
  v2 = 1;
  v5 = 1;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0;
  Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
    *(Scaleform::Render::Text::StyledText **)(*(_QWORD *)(v1 + 144) + 16i64),
    0i64,
    (Scaleform::Render::Text::ParagraphFormat *)&v4,
    0i64,
    0xFFFFFFFFFFFFFFFFui64);
  if ( !(v8 & 0x10000) )
    goto LABEL_8;
  if ( (((unsigned int)HIWORD(v8) >> 9) & 3) != 1 )
  {
    if ( (((unsigned int)HIWORD(v8) >> 9) & 3) == 2 )
    {
      v2 = 3;
      goto LABEL_9;
    }
    if ( (((unsigned int)HIWORD(v8) >> 9) & 3) == 3 )
    {
      v2 = 2;
      goto LABEL_9;
    }
LABEL_8:
    v2 = 0;
  }
LABEL_9:
  if ( v4 )
  {
    key = (Scaleform::Render::Text::ParagraphFormat *)&v4;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      v4 + 3,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
  v6 = 0i64;
  return v2;
}

// File Line: 500
// RVA: 0x9B55B0
void __fastcall Scaleform::Render::TreeText::SetVAlignment(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::VAlignment a)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  Scaleform::Render::TreeText::VAlignment v4; // er9
  __int64 v5; // rdx
  int v6; // er9
  char v7; // al
  Scaleform::Render::ContextImpl::EntryData *v8; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v11; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = a;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v5 )
  {
    v6 = v4 - 1;
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
  v8 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v9 = &v2->PNode;
  LOBYTE(v8[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v10 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v11 = v10[4].pPrev;
    v10 += 4;
    v9->pPrev = v11;
    v2->PNode.pNext = v10;
    v10->pPrev->pNext = v9;
    v10->pPrev = v9;
  }
}

// File Line: 519
// RVA: 0x98EAE0
signed __int64 __fastcall Scaleform::Render::TreeText::GetVAlignment(Scaleform::Render::TreeText *this)
{
  __int64 v1; // rax

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v1 )
  {
    if ( (((unsigned int)*(unsigned __int8 *)(v1 + 345) >> 2) & 3) == 2 )
      return 2i64;
    if ( (((unsigned int)*(unsigned __int8 *)(v1 + 345) >> 2) & 3) == 3 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 538
// RVA: 0x9AE4E0
void __fastcall Scaleform::Render::TreeText::SetBorderColor(Scaleform::Render::TreeText *this, Scaleform::Render::Color *borderColor)
{
  Scaleform::Render::TreeText::SetBorderColor(this, borderColor->Raw);
}

// File Line: 543
// RVA: 0x9AE4F0
void __fastcall Scaleform::Render::TreeText::SetBorderColor(Scaleform::Render::TreeText *this, unsigned int borderColor)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v4 )
    *(_DWORD *)(v4 + 328) = borderColor;
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v6 = &v2->PNode;
  LOBYTE(v5[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v2->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 555
// RVA: 0x980200
Scaleform::Render::Color *__fastcall Scaleform::Render::TreeText::GetBorderColor(Scaleform::Render::TreeText *this, Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rax

  v2 = *(Scaleform::Render::Color **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                + 8
                                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
void __fastcall Scaleform::Render::TreeText::SetBackgroundColor(Scaleform::Render::TreeText *this, Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this, bkgColor->Raw);
}

// File Line: 570
// RVA: 0x9AE320
void __fastcall Scaleform::Render::TreeText::SetBackgroundColor(Scaleform::Render::TreeText *this, unsigned int bkgColor)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v4 )
    *(_DWORD *)(v4 + 332) = bkgColor;
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v6 = &v2->PNode;
  LOBYTE(v5[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v2->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 582
// RVA: 0x980040
Scaleform::Render::Color *__fastcall Scaleform::Render::TreeText::GetBackgroundColor(Scaleform::Render::TreeText *this, Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rax

  v2 = *(Scaleform::Render::Color **)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                + 8
                                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
void __fastcall Scaleform::Render::TreeText::SetAAMode(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::AAMode aa)
{
  Scaleform::Render::TreeText *v2; // rbx
  unsigned __int64 v3; // rdi
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::EntryData *v5; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( v4 )
  {
    if ( aa == 1 )
      *(_BYTE *)(v4 + 344) |= 0x40u;
    else
      *(_BYTE *)(v4 + 344) &= 0xBFu;
  }
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v6 = &v2->PNode;
  LOBYTE(v5[10].vfptr) |= 1u;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v3 + 24);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v2->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 607
// RVA: 0x97FBB0
__int64 __fastcall Scaleform::Render::TreeText::GetAAMode(Scaleform::Render::TreeText *this)
{
  __int64 result; // rax

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 144i64);
  if ( result )
    result = ((unsigned int)*(unsigned __int8 *)(result + 344) >> 6) & 1;
  return result;
}

// File Line: 617
// RVA: 0x992C40
void __fastcall Scaleform::Render::TreeText::Filter::InitByDefaultValues(Scaleform::Render::TreeText::Filter *this)
{
  Scaleform::Render::TreeText::Filter *v1; // rbx
  Scaleform::Render::GradientData *v2; // rcx
  Scaleform::Render::Text::TextFilter v3; // [rsp+30h] [rbp-68h]

  v1 = this;
  Scaleform::Render::Text::TextFilter::TextFilter(&v3);
  v1->Blur.BlurX = v3.BlurX;
  v1->Blur.BlurY = v3.BlurY;
  v1->Blur.Strength = v3.BlurStrength * 100.0;
  v1->Glow.Flags = LOBYTE(v3.ShadowFlags) | 0x80;
  v1->Glow.Color = v3.ShadowParams.Colors[0].Raw & 0xFFFFFF | ((unsigned __int8)v3.ShadowAlpha << 24);
  v1->DropShadow.Angle = v3.ShadowAngle * 0.1;
  v1->DropShadow.Distance = v3.ShadowDistance * 0.050000001;
  v2 = v3.ShadowParams.Gradient.pObject;
  if ( v3.ShadowParams.Gradient.pObject && !_InterlockedDecrement(&v3.ShadowParams.Gradient.pObject->RefCount) )
  {
    if ( v2 )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
  }
}

// File Line: 631
// RVA: 0x9AF430
void __fastcall Scaleform::Render::TreeText::SetFilters(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::Filter *filters, unsigned __int64 filtersCnt)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::TreeText::Filter *v4; // rbx
  Scaleform::Render::TreeText *v5; // r14
  unsigned __int64 v6; // rsi
  __int64 v7; // r15
  signed __int64 v8; // rbx
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm1_4
  float v13; // xmm7_4
  __int64 v14; // rbx
  Scaleform::Render::GradientData *v15; // rcx
  Scaleform::Render::ContextImpl::EntryData *v16; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v17; // rdx
  signed __int64 v18; // rcx
  Scaleform::Render::Text::TextFilter v19; // [rsp+30h] [rbp-A8h]
  unsigned int v20; // [rsp+118h] [rbp+40h]
  unsigned int vars0; // [rsp+130h] [rbp+58h]

  v3 = filtersCnt;
  v4 = filters;
  v5 = this;
  v6 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  if ( *(_QWORD *)(v7 + 144) )
  {
    Scaleform::Render::Text::TextFilter::TextFilter(&v19);
    if ( v3 )
    {
      v8 = (signed __int64)&v4->4;
      while ( *(_DWORD *)(v8 - 4) != 1 )
      {
        if ( *(_DWORD *)(v8 - 4) == 2 )
        {
          v19.BlurX = *(float *)v8 * 20.0;
          v19.BlurY = *(float *)(v8 + 4) * 20.0;
          v19.BlurStrength = *(float *)(v8 + 8) * 0.0099999998;
        }
        else if ( *(_DWORD *)(v8 - 4) == 3 )
        {
          LODWORD(v19.ShadowParams.BlurX) = *(unsigned __int8 *)(v8 + 16);
          v19.ShadowParams.BlurX = *(float *)v8 * 20.0;
          v19.ShadowParams.BlurY = *(float *)(v8 + 4) * 20.0;
          v19.ShadowParams.Strength = *(float *)(v8 + 8) * 0.0099999998;
          v20 = *(_DWORD *)(v8 + 12);
          LOBYTE(v19.ShadowParams.Offset.y) = HIBYTE(v20);
          *(_QWORD *)&v19.ShadowParams.BlurY = 0i64;
          v19.ShadowParams.Colors[0].Raw = v20;
          v9 = sinf(0.0) * 0.0;
          v10 = cosf(0.0) * 0.0;
LABEL_10:
          v19.ShadowParams.Offset.y = v9;
          v19.ShadowParams.Offset.x = v10;
          goto LABEL_11;
        }
LABEL_11:
        v8 += 32i64;
        if ( !--v3 )
          goto LABEL_12;
      }
      LODWORD(v19.ShadowParams.BlurX) = *(unsigned __int8 *)(v8 + 16);
      v19.ShadowParams.BlurX = *(float *)v8 * 20.0;
      v19.ShadowParams.BlurY = *(float *)(v8 + 4) * 20.0;
      v19.ShadowParams.Strength = *(float *)(v8 + 8) * 0.0099999998;
      vars0 = *(_DWORD *)(v8 + 12);
      LOBYTE(v19.ShadowParams.Offset.y) = HIBYTE(vars0);
      v11 = *(float *)(v8 + 20) * 3.141592653589793 * 0.005555555555555556;
      v19.ShadowParams.BlurY = v11;
      v12 = *(float *)(v8 + 24) * 20.0;
      v13 = (float)(signed __int16)(signed int)v12;
      v19.ShadowParams.Offset.x = (float)(signed __int16)(signed int)v12;
      v19.ShadowParams.Colors[0].Raw = vars0;
      v9 = sinf(v11) * v13;
      v10 = cosf(v11) * v13;
      goto LABEL_10;
    }
LABEL_12:
    v14 = *(_QWORD *)(v7 + 144);
    if ( v19.BlurX != *(float *)(v14 + 240)
      || v19.BlurY != *(float *)(v14 + 244)
      || v19.BlurStrength != *(float *)(v14 + 248)
      || !Scaleform::Render::BlurFilterParams::EqualsAll(
            (Scaleform::Render::BlurFilterParams *)(v14 + 256),
            &v19.ShadowParams)
      || *(_DWORD *)(v14 + 304) != LODWORD(v19.ShadowParams.BlurX)
      || *(_BYTE *)(v14 + 316) != LOBYTE(v19.ShadowParams.Offset.y)
      || v19.ShadowParams.BlurY != *(float *)(v14 + 308)
      || v19.ShadowParams.Offset.x != *(float *)(v14 + 312) )
    {
      *(float *)(v14 + 240) = v19.BlurX;
      *(float *)(v14 + 244) = v19.BlurY;
      *(float *)(v14 + 248) = v19.BlurStrength;
      Scaleform::Render::BlurFilterParams::operator=(
        (Scaleform::Render::BlurFilterParams *)(v14 + 256),
        &v19.ShadowParams);
      *(float *)(v14 + 304) = v19.ShadowParams.BlurX;
      *(float *)(v14 + 308) = v19.ShadowParams.BlurY;
      *(float *)(v14 + 312) = v19.ShadowParams.Offset.x;
      *(_BYTE *)(v14 + 316) = LOBYTE(v19.ShadowParams.Offset.y);
    }
    v15 = v19.ShadowParams.Gradient.pObject;
    if ( v19.ShadowParams.Gradient.pObject
      && !_InterlockedDecrement(&v19.ShadowParams.Gradient.pObject->RefCount)
      && v15 )
    {
      v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
    }
    v19.vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  }
  v16 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v5->0, 0x400u);
  LOBYTE(v16[10].vfptr) |= 1u;
  v17 = &v5->PNode;
  if ( !v5->PNode.pPrev )
  {
    v18 = *(_QWORD *)(v6 + 24) + 64i64;
    v17->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v18;
    v5->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v18;
    *(_QWORD *)(*(_QWORD *)v18 + 8i64) = v17;
    *(_QWORD *)v18 = v17;
  }
}

// File Line: 693
// RVA: 0x9841B0
signed __int64 __fastcall Scaleform::Render::TreeText::GetFilters(Scaleform::Render::TreeText *this, Scaleform::Render::TreeText::Filter *filtersBuf, unsigned __int64 filtersCntInBuf)
{
  Scaleform::Render::TreeText::Filter *v3; // r10
  __int64 v4; // r9
  unsigned __int64 v5; // r11
  signed __int64 v6; // rdx
  signed __int64 result; // rax
  unsigned __int64 v8; // r8

  v3 = filtersBuf;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 144i64);
  if ( !v4 )
    return 0i64;
  v5 = 0i64;
  if ( (*(float *)(v4 + 240) != 0.0 || 0.0 != *(float *)(v4 + 244)) && filtersCntInBuf )
  {
    filtersBuf->Type = 2;
    v5 = 1i64;
    filtersBuf->Blur.BlurX = *(float *)(v4 + 240) * 0.050000001;
    filtersBuf->Blur.BlurY = *(float *)(v4 + 244) * 0.050000001;
    filtersBuf->Blur.Strength = *(float *)(v4 + 248) * 100.0;
  }
  if ( (0.0 != *(float *)(v4 + 264) || 0.0 != *(float *)(v4 + 268)) && v5 < filtersCntInBuf )
  {
    if ( 0.0 == *(float *)(v4 + 308) && 0.0 == *(float *)(v4 + 312) )
    {
      v6 = v5;
      v3[v6].Type = 3;
      v3[v6].Glow.Flags = *(_BYTE *)(v4 + 304);
      v3[v6].Blur.BlurX = *(float *)(v4 + 264) * 0.050000001;
      v3[v6].Blur.BlurY = *(float *)(v4 + 268) * 0.050000001;
      v3[v6].Blur.Strength = *(float *)(v4 + 280) * 100.0;
      result = v5 + 1;
      v3[v6].Glow.Color = *(_DWORD *)(v4 + 284) & 0xFFFFFF | (*(unsigned __int8 *)(v4 + 316) << 24);
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
  Scaleform::Render::TreeText *v1; // rbx
  Scaleform::Render::TreeText::Filter filters; // [rsp+20h] [rbp-28h]

  v1 = this;
  filters.Type = 0;
  Scaleform::Render::TreeText::Filter::InitByDefaultValues(&filters);
  Scaleform::Render::TreeText::SetFilters(v1, &filters, 1ui64);
}

// File Line: 748
// RVA: 0x99C780
void __fastcall Scaleform::Render::TreeText::NotifyLayoutChanged(Scaleform::Render::TreeText *this)
{
  Scaleform::Render::TreeText *v1; // rbx
  Scaleform::Render::ContextImpl::EntryData *v2; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v3; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v4; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v5; // rax

  v1 = this;
  v2 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 0x400u);
  v3 = &v1->PNode;
  LOBYTE(v2[10].vfptr) |= 1u;
  if ( !v1->PNode.pPrev )
  {
    v4 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v5 = v4[4].pPrev;
    v4 += 4;
    v3->pPrev = v5;
    v1->PNode.pNext = v4;
    v4->pPrev->pNext = v3;
    v4->pPrev = v3;
  }
}

