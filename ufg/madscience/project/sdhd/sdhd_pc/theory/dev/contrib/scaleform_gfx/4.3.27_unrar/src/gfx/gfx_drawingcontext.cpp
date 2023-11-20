// File Line: 33
// RVA: 0x895F50
void __fastcall Scaleform::GFx::DrawingContext::DrawingContext(Scaleform::GFx::DrawingContext *this, Scaleform::Render::ContextImpl::Context *renCtxt, Scaleform::GFx::ImageCreator *imgCreator)
{
  Scaleform::GFx::ImageCreator *v3; // rdi
  Scaleform::GFx::DrawingContext *v4; // rbx
  Scaleform::Render::ContextImpl::Entry *v5; // rdi
  Scaleform::Render::ContextImpl::Entry *v6; // rcx
  bool v7; // zf

  v3 = imgCreator;
  v4 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,322>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawingContext,322>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawingContext::`vftable;
  this->pTreeContainer.pObject = 0i64;
  this->RenContext = renCtxt;
  if ( imgCreator )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)imgCreator);
  v4->ImgCreator.pObject = v3;
  v4->Shapes.pObject = 0i64;
  v4->mFillStyle.pFill.pObject = 0i64;
  v4->mLineStyle.pFill.pObject = 0i64;
  v4->mLineStyle.pDashes.pObject = 0i64;
  *(_QWORD *)&v4->PosInfo.Pos = 0i64;
  *(_QWORD *)&v4->PosInfo.StartY = 0i64;
  *(_QWORD *)&v4->PosInfo.LastY = 0i64;
  *(_QWORD *)&v4->PosInfo.StrokeBase = 0i64;
  *(_QWORD *)&v4->PosInfo.NumStrokeBits = 0i64;
  *(_QWORD *)&v4->PosInfo.Fill1 = 0i64;
  v4->PosInfo.Sfactor = 1.0;
  v4->PosInfo.Initialized = 0;
  v4->States = 1;
  v4->pPrev = 0i64;
  v4->pNext = 0i64;
  v5 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(v4->RenContext);
  v6 = (Scaleform::Render::ContextImpl::Entry *)&v4->pTreeContainer.pObject->0;
  if ( v6 )
  {
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
  }
  v4->pTreeContainer.pObject = (Scaleform::Render::TreeContainer *)v5;
  Scaleform::GFx::DrawingContext::Clear(v4);
}

// File Line: 41
// RVA: 0x8A41B0
void __fastcall Scaleform::GFx::DrawingContext::~DrawingContext(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::ContextImpl::Entry *v7; // rcx
  bool v8; // zf

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawingContext::`vftable;
  if ( this->pPrev && this->pNext )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::GFx::DrawingContext *)-1i64;
    this->pNext = (Scaleform::GFx::DrawingContext *)-1i64;
  }
  v2 = (Scaleform::Render::RenderBuffer *)this->mLineStyle.pDashes.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->mLineStyle.pFill.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->mFillStyle.pFill.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)v1->Shapes.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::Render::RenderBuffer *)v1->ImgCreator.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = (Scaleform::Render::ContextImpl::Entry *)&v1->pTreeContainer.pObject->0;
  if ( v7 )
  {
    v8 = v7->RefCount-- == 1;
    if ( v8 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->vfptr);
}

// File Line: 47
// RVA: 0x8BC050
void __fastcall Scaleform::GFx::DrawingContext::Clear(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rdi
  Scaleform::GFx::DrawingContext::PackedShape *v2; // rax
  unsigned __int64 v3; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v4; // rax
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rsi
  Scaleform::Render::RenderBuffer *v6; // rcx
  __int64 v7; // rdx
  __int64 v8; // rax

  v1 = this;
  v2 = (Scaleform::GFx::DrawingContext::PackedShape *)this->RenContext->pHeap->vfptr->Alloc(
                                                        (Scaleform::MemoryHeap *)this,
                                                        128ui64,
                                                        0i64);
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::DrawingContext::PackedShape::PackedShape(v2, v1->RenContext->pHeap);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (Scaleform::Render::RenderBuffer *)v1->Shapes.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v1->Shapes.pObject = v5;
  v1->States = 1;
  *(_QWORD *)&v1->Ex = 0i64;
  v1->StY = 1.1754944e-38;
  v1->StX = 1.1754944e-38;
  *(_QWORD *)&v1->StrokeStyle = 0i64;
  v1->FillStyle1 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)(((_QWORD)v1->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pTreeContainer.pObject[-1]
                                                                                       - ((_QWORD)v1->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pTreeContainer.pObject[-1]
                                                                           - ((_QWORD)v1->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v8 = *(_QWORD *)(v7 + 144);
  if ( v8 )
  {
    if ( v8 & 1 )
    {
      v3 = *(_QWORD *)((v8 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    }
    else
    {
      LOBYTE(v3) = *(_QWORD *)(v7 + 152) != 0i64;
      ++v3;
    }
  }
  Scaleform::Render::TreeContainer::Remove(v1->pTreeContainer.pObject, 0i64, v3);
  v1->States |= 0x80u;
}

// File Line: 59
// RVA: 0x909B40
void __fastcall Scaleform::GFx::DrawingContext::SetNoLine(Scaleform::GFx::DrawingContext *this)
{
  this->States &= 0xFDu;
  this->StrokeStyle = 0;
}

// File Line: 65
// RVA: 0x909B30
void __fastcall Scaleform::GFx::DrawingContext::SetNoFill(Scaleform::GFx::DrawingContext *this)
{
  *(_QWORD *)&this->FillStyle0 = 0i64;
}

// File Line: 94
// RVA: 0x8BA1E0
void __fastcall Scaleform::GFx::DrawingContext::ChangeLineStyle(Scaleform::GFx::DrawingContext *this, float lineWidth, unsigned int rgba, bool hinting, unsigned int scaling, unsigned int caps, unsigned int joins, float miterLimit)
{
  bool v8; // si
  unsigned int v9; // edi
  float v10; // xmm6_4
  Scaleform::GFx::DrawingContext *v11; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v12; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v13; // rcx
  int v14; // xmm0_4
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v17; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v18; // rcx
  int v19; // xmm0_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v20; // [rsp+40h] [rbp-48h]
  int v21; // [rsp+48h] [rbp-40h]

  v8 = hinting;
  v9 = rgba;
  v10 = lineWidth;
  v11 = this;
  if ( rgba & 0xFF000000 )
  {
    if ( lineWidth <= 0.0 )
      v10 = FLOAT_0_050000001;
    if ( !Scaleform::GFx::DrawingContext::SameLineStyle(this, v10, rgba, hinting, scaling, caps, joins, miterLimit) )
    {
      v12 = v11->Shapes.pObject;
      if ( v12 && !((unsigned __int8 (*)(void))v12->vfptr[1].__vecDelDtor)() )
      {
        v11->States |= 0x80u;
        if ( v11->States & 8 )
        {
          v13 = v11->Shapes.pObject;
          v14 = LODWORD(v13->Multiplier);
          v20.Data = v13->pContainer;
          v21 = v14;
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v20);
          v11->States &= 0xF7u;
        }
        v11->States &= 0xFEu;
      }
      v15 = (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v11->Shapes.pObject->vfptr;
      v11->mLineStyle.Miter = miterLimit;
      v11->mLineStyle.Color = v9;
      v11->mLineStyle.Units = 0.050000001;
      v11->mLineStyle.Width = v10;
      v11->mLineStyle.Flags = joins | caps | scaling | (v8 != 0);
      v16 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
              v15,
              &v11->mLineStyle);
      v11->States |= 2u;
      v11->StrokeStyle = v16;
    }
  }
  else if ( ((unsigned int (*)(void))this->Shapes.pObject->vfptr[3].__vecDelDtor)() && v11->StrokeStyle )
  {
    v17 = v11->Shapes.pObject;
    if ( v17 && !((unsigned __int8 (*)(void))v17->vfptr[1].__vecDelDtor)() )
    {
      v11->States |= 0x80u;
      if ( v11->States & 8 )
      {
        v18 = v11->Shapes.pObject;
        v19 = LODWORD(v18->Multiplier);
        v20.Data = v18->pContainer;
        v21 = v19;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v20);
        v11->States &= 0xF7u;
      }
      v11->States &= 0xFEu;
    }
    v11->States &= 0xFDu;
    v11->StrokeStyle = 0;
  }
}

// File Line: 125
// RVA: 0x904720
bool __fastcall Scaleform::GFx::DrawingContext::SameLineStyle(Scaleform::GFx::DrawingContext *this, float lineWidth, unsigned int rgba, bool hinting, unsigned int scaling, unsigned int caps, unsigned int joins, float miterLimit)
{
  bool v8; // bp
  unsigned int v9; // esi
  Scaleform::GFx::DrawingContext *v10; // rdi
  int v12; // ebx
  bool v13; // bl
  float v14; // [rsp+28h] [rbp-40h]
  int v15; // [rsp+30h] [rbp-38h]
  float v16; // [rsp+34h] [rbp-34h]
  int v17; // [rsp+38h] [rbp-30h]
  __int128 v18; // [rsp+40h] [rbp-28h]

  v8 = hinting;
  v9 = rgba;
  v10 = this;
  if ( !((unsigned int (__cdecl *)(Scaleform::GFx::DrawingContext::PackedShape *))this->Shapes.pObject->vfptr[3].__vecDelDtor)(this->Shapes.pObject)
    || !v10->StrokeStyle )
  {
    return 0;
  }
  v12 = 0;
  v18 = 0ui64;
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, float *))v10->Shapes.pObject->vfptr[5].__vecDelDtor)(
    v10->Shapes.pObject,
    v10->StrokeStyle,
    &v14);
  v13 = 0;
  if ( !(_QWORD)v18 && v17 == v9 && COERCE_SIGNED_INT(v14 * 20.0) == COERCE_SIGNED_INT(lineWidth * 20.0) )
  {
    LOBYTE(v12) = v8 != 0;
    if ( v15 == (joins | caps | scaling | v12) && COERCE_SIGNED_INT(v16 * 20.0) == COERCE_SIGNED_INT(miterLimit * 20.0) )
      v13 = 1;
  }
  if ( *((_QWORD *)&v18 + 1) )
    Scaleform::RefCountImpl::Release(*((Scaleform::Render::RenderBuffer **)&v18 + 1));
  if ( (_QWORD)v18 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
  return v13;
}

// File Line: 145
// RVA: 0x8EBE20
bool __fastcall Scaleform::GFx::DrawingContext::NoLine(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rbx

  v1 = this;
  return !((unsigned int (*)(void))this->Shapes.pObject->vfptr[3].__vecDelDtor)() || !v1->StrokeStyle;
}

// File Line: 162
// RVA: 0x8C2560
Scaleform::Render::ComplexFill *__fastcall Scaleform::GFx::DrawingContext::CreateNewComplexFill(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rdi
  Scaleform::Render::RenderBuffer *v2; // rcx
  unsigned int v3; // esi
  __int64 v4; // rcx
  __int64 v5; // rbx
  signed __int64 v6; // rdi
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  int v10; // [rsp+28h] [rbp-30h]
  Scaleform::Render::RenderBuffer *v11; // [rsp+30h] [rbp-28h]

  v1 = this;
  this->mFillStyle.Color = 0;
  v2 = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v1->mFillStyle.pFill.pObject = 0i64;
  v3 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
         (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v1->Shapes.pObject->vfptr,
         &v1->mFillStyle);
  v1->FillStyle0 = v3;
  v1->FillStyle1 = 0;
  v5 = ((__int64 (__fastcall *)(__int64, signed __int64))v1->RenContext->pHeap->vfptr->Alloc)(v4, 80i64);
  if ( v5 )
  {
    *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v5 + 8) = 1;
    *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v5 = &Scaleform::Render::ComplexFill::`vftable;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 24) = 0i64;
    *(_QWORD *)(v5 + 32) = 1065353216i64;
    *(_QWORD *)(v5 + 40) = 0i64;
    *(_DWORD *)(v5 + 48) = 0;
    *(_QWORD *)(v5 + 52) = 1065353216i64;
    *(_DWORD *)(v5 + 60) = 0;
    *(_BYTE *)(v5 + 64) = 0;
    *(_DWORD *)(v5 + 68) = -1;
  }
  else
  {
    v5 = 0i64;
  }
  v11 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, int *))v1->Shapes.pObject->vfptr[4].__vecDelDtor)(
    v1->Shapes.pObject,
    v3,
    &v10);
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v11 = (Scaleform::Render::RenderBuffer *)v5;
  v6 = (signed __int64)&v1->Shapes.pObject->FillStyles.Data.Data[v3 - 1];
  *(_DWORD *)v6 = v10;
  v7 = v11;
  if ( v11 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v11);
    v7 = v11;
  }
  v8 = *(Scaleform::Render::RenderBuffer **)(v6 + 8);
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    v7 = v11;
  }
  *(_QWORD *)(v6 + 8) = v7;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  return (Scaleform::Render::ComplexFill *)v5;
}

// File Line: 173
// RVA: 0x8C08F0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::DrawingContext::CreateLineComplexFill(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rdi
  __int64 v2; // rax
  Scaleform::GFx::Resource *v3; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v4; // rdx
  signed __int64 v5; // rdi
  Scaleform::Render::StrokeStyleType *v6; // rsi
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::Resource *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rcx
  float v12; // [rsp+28h] [rbp-40h]
  float v13; // [rsp+2Ch] [rbp-3Ch]
  unsigned int v14; // [rsp+30h] [rbp-38h]
  float v15; // [rsp+34h] [rbp-34h]
  unsigned int v16; // [rsp+38h] [rbp-30h]
  Scaleform::Render::RenderBuffer *v17; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::Resource *v18; // [rsp+48h] [rbp-20h]

  v1 = this;
  if ( !(this->States & 2) )
    this->StrokeStyle = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
                          (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&this->Shapes.pObject->vfptr,
                          &this->mLineStyle);
  v2 = ((__int64 (__fastcall *)(Scaleform::GFx::DrawingContext *, signed __int64))v1->RenContext->pHeap->vfptr->Alloc)(
         this,
         80i64);
  v3 = (Scaleform::GFx::Resource *)v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Scaleform::RefCountImplCore::`vftable;
    *(_DWORD *)(v2 + 8) = 1;
    *(_QWORD *)v2 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v2 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
    *(_QWORD *)v2 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
    *(_QWORD *)v2 = &Scaleform::Render::ComplexFill::`vftable;
    *(_QWORD *)(v2 + 16) = 0i64;
    *(_QWORD *)(v2 + 24) = 0i64;
    *(_QWORD *)(v2 + 32) = 1065353216i64;
    *(_QWORD *)(v2 + 40) = 0i64;
    *(_DWORD *)(v2 + 48) = 0;
    *(_QWORD *)(v2 + 52) = 1065353216i64;
    *(_DWORD *)(v2 + 60) = 0;
    *(_BYTE *)(v2 + 64) = 0;
    *(_DWORD *)(v2 + 68) = -1;
  }
  else
  {
    v3 = 0i64;
  }
  v17 = 0i64;
  v18 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, float *))v1->Shapes.pObject->vfptr[5].__vecDelDtor)(
    v1->Shapes.pObject,
    v1->StrokeStyle,
    &v12);
  if ( v3 )
    Scaleform::Render::RenderBuffer::AddRef(v3);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  v17 = (Scaleform::Render::RenderBuffer *)v3;
  v4 = v1->Shapes.pObject;
  v5 = v1->StrokeStyle - 1;
  v6 = v4->StrokeStyles.Data.Data;
  v6[v5].Width = v12;
  v6[v5].Units = v13;
  v6[v5].Flags = v14;
  v6[v5].Miter = v15;
  v6[v5].Color = v16;
  v7 = v17;
  if ( v17 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v17);
    v7 = v17;
  }
  v8 = (Scaleform::Render::RenderBuffer *)v6[v5].pFill.pObject;
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    v7 = v17;
  }
  v6[v5].pFill.pObject = (Scaleform::Render::ComplexFill *)v7;
  v9 = v18;
  if ( v18 )
  {
    Scaleform::Render::RenderBuffer::AddRef(v18);
    v9 = v18;
  }
  v10 = (Scaleform::Render::RenderBuffer *)v6[v5].pDashes.pObject;
  if ( v10 )
  {
    Scaleform::RefCountImpl::Release(v10);
    v9 = v18;
  }
  v6[v5].pDashes.pObject = (Scaleform::Render::DashArray *)v9;
  if ( v18 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
  return v3;
}

// File Line: 193
// RVA: 0x8B6F70
void __fastcall Scaleform::GFx::DrawingContext::BeginFill(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rbx

  v1 = this;
  if ( this->States & 0x10 )
  {
    Scaleform::GFx::DrawingContext::EndFill(this);
    v1->States |= 0x14u;
  }
  else
  {
    this->States |= 0x14u;
  }
}

// File Line: 200
// RVA: 0x8B7040
void __fastcall Scaleform::GFx::DrawingContext::BeginSolidFill(Scaleform::GFx::DrawingContext *this, unsigned int rgba)
{
  Scaleform::GFx::DrawingContext *v2; // rbx
  Scaleform::Render::RenderBuffer *v3; // rcx
  unsigned int v4; // eax
  bool v5; // zf

  v2 = this;
  this->mFillStyle.Color = rgba;
  v3 = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v2->mFillStyle.pFill.pObject = 0i64;
  v4 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
         (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v2->Shapes.pObject->vfptr,
         &v2->mFillStyle);
  v5 = (v2->States & 0x10) == 0;
  v2->FillStyle1 = 0;
  v2->FillStyle0 = v4;
  if ( !v5 )
    Scaleform::GFx::DrawingContext::EndFill(v2);
  v2->States |= 0x14u;
}

// File Line: 216
// RVA: 0x8B6B80
void __fastcall Scaleform::GFx::DrawingContext::BeginBitmapFill(Scaleform::GFx::DrawingContext *this, Scaleform::GFx::FillType fillType, Scaleform::GFx::ImageResource *pimageRes, Scaleform::Render::Matrix2x4<float> *mtx)
{
  Scaleform::Render::Matrix2x4<float> *v4; // r12
  Scaleform::GFx::ImageResource *v5; // r13
  Scaleform::GFx::FillType v6; // er14
  Scaleform::GFx::DrawingContext *v7; // rsi
  Scaleform::Render::RenderBuffer *v8; // rbx
  Scaleform::Render::RenderBuffer *v9; // rcx
  unsigned int v10; // eax
  unsigned int v11; // er15
  __int64 v12; // rcx
  __int64 v13; // rdi
  float v14; // xmm1_4
  __int128 v15; // xmm2
  __int128 v16; // xmm3
  __int128 v17; // xmm4
  __int128 v18; // xmm5
  float v19; // xmm7_4
  float v20; // xmm8_4
  Scaleform::MemoryHeap *v21; // rax
  Scaleform::Render::RenderBuffer *v22; // rdi
  __int64 v23; // rcx
  int v24; // er14
  int v25; // er14
  int v26; // er14
  signed __int64 v27; // rdi
  Scaleform::Render::RenderBuffer *v28; // rax
  Scaleform::Render::RenderBuffer *v29; // rcx
  int v30; // [rsp+20h] [rbp-81h]
  int v31; // [rsp+24h] [rbp-7Dh]
  Scaleform::Render::RenderBuffer *v32[2]; // [rsp+28h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+38h] [rbp-69h]
  int v34; // [rsp+58h] [rbp-49h]
  Scaleform::MemoryHeap *v35; // [rsp+60h] [rbp-41h]
  int v36; // [rsp+68h] [rbp-39h]
  int v37; // [rsp+6Ch] [rbp-35h]
  __int64 v38; // [rsp+70h] [rbp-31h]
  __int64 v39; // [rsp+78h] [rbp-29h]
  __int64 v40; // [rsp+80h] [rbp-21h]
  __int64 v41; // [rsp+88h] [rbp-19h]
  __int64 v42; // [rsp+90h] [rbp-11h]
  Scaleform::MemoryHeap *v43; // [rsp+98h] [rbp-9h]
  __int64 v44; // [rsp+A0h] [rbp-1h]
  Scaleform::LogMessageId id; // [rsp+108h] [rbp+67h]

  v44 = -2i64;
  v4 = mtx;
  v5 = pimageRes;
  v6 = fillType;
  v7 = this;
  v8 = 0i64;
  this->mFillStyle.Color = 0;
  v9 = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v7->mFillStyle.pFill.pObject = 0i64;
  v10 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
          (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v7->Shapes.pObject->vfptr,
          &v7->mFillStyle);
  v11 = v10;
  v7->FillStyle0 = v10;
  v7->FillStyle1 = 0;
  if ( v10 )
  {
    v32[0] = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, int *))v7->Shapes.pObject->vfptr[4].__vecDelDtor)(
      v7->Shapes.pObject,
      v10,
      &v30);
    v43 = v7->RenContext->pHeap;
    v13 = ((__int64 (__fastcall *)(__int64, signed __int64))v43->vfptr->Alloc)(v12, 80i64);
    v42 = v13;
    if ( v13 )
    {
      *(_QWORD *)v13 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v13 + 8) = 1;
      *(_QWORD *)v13 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v13 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
      *(_QWORD *)v13 = &Scaleform::RefCountBase<Scaleform::Render::ComplexFill,71>::`vftable;
      *(_QWORD *)v13 = &Scaleform::Render::ComplexFill::`vftable;
      *(_QWORD *)(v13 + 16) = 0i64;
      *(_QWORD *)(v13 + 24) = 0i64;
      *(_QWORD *)(v13 + 32) = 1065353216i64;
      *(_QWORD *)(v13 + 40) = 0i64;
      *(_DWORD *)(v13 + 48) = 0;
      *(_QWORD *)(v13 + 52) = 1065353216i64;
      *(_DWORD *)(v13 + 60) = 0;
      *(_BYTE *)(v13 + 64) = 0;
      *(_DWORD *)(v13 + 68) = -1;
    }
    else
    {
      v13 = 0i64;
    }
    if ( v32[0] )
      Scaleform::RefCountImpl::Release(v32[0]);
    v32[0] = (Scaleform::Render::RenderBuffer *)v13;
    v14 = v4->M[0][1];
    v15 = LODWORD(v4->M[0][2]);
    v16 = LODWORD(v4->M[0][3]);
    v17 = LODWORD(v4->M[1][0]);
    v18 = LODWORD(v4->M[1][1]);
    v19 = v4->M[1][2];
    v20 = v4->M[1][3];
    m.M[0][0] = v4->M[0][0] * 20.0;
    m.M[0][1] = v14 * 20.0;
    m.M[1][2] = v19 * 20.0;
    m.M[1][3] = v20 * 20.0;
    *(_OWORD *)&m.M[0][2] = _xmm;
    *(__m128 *)v32 = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)((char *)&m + 8), &m);
    *(_QWORD *)(v13 + 32) = *(_QWORD *)&m.M[0][2];
    *(float *)(v13 + 40) = m.M[1][0];
    *(_DWORD *)(v13 + 44) = v31;
    *(Scaleform::Render::RenderBuffer **)(v13 + 48) = v32[0];
    *(Scaleform::Render::RenderBuffer **)(v13 + 56) = v32[1];
    v32[1] = 0i64;
    if ( ((unsigned int (*)(void))v5->pImage->vfptr[3].__vecDelDtor)() )
    {
      v8 = (Scaleform::Render::RenderBuffer *)v5->pImage;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))v8->vfptr[1].__vecDelDtor)(v5->pImage);
      v32[1] = v8;
    }
    else if ( v7->ImgCreator.pObject )
    {
      v21 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v7);
      v34 = 3;
      v35 = v21;
      v36 = 1;
      v37 = 1;
      v38 = 0i64;
      v39 = 0i64;
      v40 = 0i64;
      v41 = 0i64;
      v8 = (Scaleform::Render::RenderBuffer *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v7->ImgCreator.pObject->vfptr[4].__vecDelDtor)(
                                                v7->ImgCreator.pObject,
                                                &v34,
                                                v5->pImage);
      v32[1] = v8;
    }
    else
    {
      id.Id = 135168;
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in BeginBitmapFill");
    }
    v22 = v32[0];
    if ( v8 )
      ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v8->vfptr[1].__vecDelDtor)(v8);
    v23 = *(_QWORD *)&v22->Type;
    if ( v23 )
      (*(void (**)(void))(*(_QWORD *)v23 + 16i64))();
    *(_QWORD *)&v22->Type = v8;
    v24 = v6 - 64;
    if ( v24 )
    {
      v25 = v24 - 1;
      if ( v25 )
      {
        v26 = v25 - 1;
        if ( v26 )
        {
          if ( v26 == 1 )
            LOBYTE(v32[0][1].Type) = 1;
        }
        else
        {
          LOBYTE(v32[0][1].Type) = 0;
        }
      }
      else
      {
        LOBYTE(v32[0][1].Type) = 3;
      }
    }
    else
    {
      LOBYTE(v32[0][1].Type) = 2;
    }
    v27 = (signed __int64)&v7->Shapes.pObject->FillStyles.Data.Data[v11 - 1];
    *(_DWORD *)v27 = v30;
    v28 = v32[0];
    if ( v32[0] )
    {
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v32[0]);
      v28 = v32[0];
    }
    v29 = *(Scaleform::Render::RenderBuffer **)(v27 + 8);
    if ( v29 )
    {
      Scaleform::RefCountImpl::Release(v29);
      v28 = v32[0];
    }
    *(_QWORD *)(v27 + 8) = v28;
    if ( v7->States & 0x10 )
      Scaleform::GFx::DrawingContext::EndFill(v7);
    v7->States |= 0x14u;
    if ( v8 )
      ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))v8->vfptr[2].__vecDelDtor)(v8);
    if ( v32[0] )
      Scaleform::RefCountImpl::Release(v32[0]);
  }
}

// File Line: 256
// RVA: 0x8C8800
void __fastcall Scaleform::GFx::DrawingContext::EndFill(Scaleform::GFx::DrawingContext *this)
{
  char v1; // al
  Scaleform::GFx::DrawingContext *v2; // rbx
  float v3; // xmm1_4
  bool v4; // zf

  v1 = this->States;
  v2 = this;
  if ( v1 & 0x10 )
  {
    v3 = this->StX;
    v4 = v3 == this->Ex;
    this->States = v1 & 0xEF;
    if ( !v4 || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, v3, this->StY);
  }
  v2->StY = 1.1754944e-38;
  v2->StX = 1.1754944e-38;
  *(_QWORD *)&v2->FillStyle0 = 0i64;
}

// File Line: 263
// RVA: 0x8EBBB0
void __fastcall Scaleform::GFx::DrawingContext::MoveTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  float v3; // xmm7_4
  char v4; // al
  Scaleform::GFx::DrawingContext *v5; // rbx
  float v6; // xmm1_4
  int v7; // [rsp+54h] [rbp-2Ch]

  this->PosInfo.Pos = 0;
  v3 = x;
  this->PosInfo.StartX = 0;
  this->PosInfo.StartY = 0;
  LOBYTE(v7) = 0;
  v4 = this->States;
  v5 = this;
  this->PosInfo.LastX = 0;
  this->PosInfo.LastY = 0;
  this->PosInfo.FillBase = 0;
  this->PosInfo.StrokeBase = 0;
  this->PosInfo.NumFillBits = 0;
  this->PosInfo.NumStrokeBits = 0;
  this->PosInfo.Fill0 = 0;
  this->PosInfo.Fill1 = 0;
  this->PosInfo.Stroke = 0;
  LODWORD(this->PosInfo.Sfactor) = (_DWORD)FLOAT_1_0;
  *(_DWORD *)&this->PosInfo.Initialized = v7;
  if ( !(v4 & 4) )
  {
    if ( v4 & 0x10 )
    {
      v6 = this->StX;
      if ( v6 != this->Ex || this->StY != this->Ey )
        Scaleform::GFx::DrawingContext::LineTo(this, v6, this->StY);
    }
  }
  Scaleform::GFx::DrawingContext::NewPath(v5, v3, y);
  v5->States &= 0xFBu;
  v5->StX = v3;
  v5->StY = y;
}

// File Line: 279
// RVA: 0x8E8200
void __fastcall Scaleform::GFx::DrawingContext::LineTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v3; // rbx

  v3 = this;
  if ( !(this->States & 8) )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v3->Shapes.pObject->vfptr,
    &v3->PosInfo,
    x,
    y);
  v3->States &= 0xFDu;
  v3->Ex = x;
  v3->Ey = y;
  v3->States |= 0x80u;
}

// File Line: 292
// RVA: 0x8C44B0
void __fastcall Scaleform::GFx::DrawingContext::CurveTo(Scaleform::GFx::DrawingContext *this, float cx, float cy, float ax, float ay)
{
  Scaleform::GFx::DrawingContext *v5; // rbx

  v5 = this;
  if ( !(this->States & 8) )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
    (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v5->Shapes.pObject->vfptr,
    &v5->PosInfo,
    cx,
    cy,
    ax,
    ay);
  v5->States &= 0xFDu;
  v5->Ex = ax;
  v5->Ey = ay;
  v5->States |= 0x80u;
}

// File Line: 305
// RVA: 0x8EBD80
void __fastcall Scaleform::GFx::DrawingContext::NewPath(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  Scaleform::GFx::DrawingContext *v3; // rbx
  Scaleform::Render::ShapePathType v4; // er8

  v3 = this;
  Scaleform::GFx::DrawingContext::AcquirePath(this, this->States & 1);
  v4 = 2;
  if ( !(v3->States & 1) )
    v4 = 1;
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
    (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v3->Shapes.pObject->vfptr,
    &v3->PosInfo,
    v4,
    v3->FillStyle0,
    v3->FillStyle1,
    v3->StrokeStyle,
    x,
    y);
  v3->States &= 0xFEu;
  v3->States |= 0x88u;
  v3->Ex = x;
  v3->Ey = y;
}

// File Line: 319
// RVA: 0x8CD6F0
void __fastcall Scaleform::GFx::DrawingContext::FinishPath(Scaleform::GFx::DrawingContext *this)
{
  char v1; // al
  float v2; // xmm1_4
  bool v3; // zf

  v1 = this->States;
  if ( v1 & 0x10 )
  {
    v2 = this->StX;
    v3 = v2 == this->Ex;
    this->States = v1 & 0xEF;
    if ( !v3 || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, v2, this->StY);
  }
}

// File Line: 331
// RVA: 0x8B0030
char __fastcall Scaleform::GFx::DrawingContext::AcquirePath(Scaleform::GFx::DrawingContext *this, bool newShapeFlag)
{
  Scaleform::GFx::DrawingContext *v2; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v3; // rcx
  bool v4; // di
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rcx
  int v6; // xmm0_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v8; // [rsp+20h] [rbp-18h]
  int v9; // [rsp+28h] [rbp-10h]

  v2 = this;
  v3 = this->Shapes.pObject;
  v4 = newShapeFlag;
  if ( !v3 || ((unsigned __int8 (*)(void))v3->vfptr[1].__vecDelDtor)() )
    return 0;
  v2->States |= 0x80u;
  if ( v4 && v2->States & 0x10 )
    Scaleform::GFx::DrawingContext::FinishPath(v2);
  if ( v2->States & 8 )
  {
    v5 = v2->Shapes.pObject;
    v6 = LODWORD(v5->Multiplier);
    v8.Data = v5->pContainer;
    v9 = v6;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v8);
    v2->States &= 0xF7u;
  }
  if ( v4 )
    v2->States |= 1u;
  else
    v2->States &= 0xFEu;
  return 1;
}

// File Line: 352
// RVA: 0x8BD720
void __fastcall Scaleform::GFx::DrawingContext::ComputeBound(Scaleform::GFx::DrawingContext *this, Scaleform::Render::Rect<float> *pRect)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::DrawingContext *v3; // rbp
  unsigned __int64 v4; // rdi
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  __int64 v7; // rsi
  unsigned __int64 v8; // rsi
  _QWORD *v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // [rsp+20h] [rbp-18h]
  float v20; // [rsp+24h] [rbp-14h]
  float v21; // [rsp+28h] [rbp-10h]
  float v22; // [rsp+2Ch] [rbp-Ch]

  v2 = pRect;
  v3 = this;
  Scaleform::GFx::DrawingContext::UpdateRenderNode(this);
  v4 = 0i64;
  v5 = *(_QWORD *)(((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v6 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pTreeContainer.pObject[-1]
                                                                          - ((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pTreeContainer.pObject[-1]
                                                              - ((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63);
  v7 = *(_QWORD *)(*(_QWORD *)(v5 + 8 * v6 + 40) + 144i64);
  if ( v7 )
  {
    v8 = v7 & 1 ? *(_QWORD *)((v7 & 0xFFFFFFFFFFFFFFFEui64) + 8) : (*(_QWORD *)(*(_QWORD *)(v5 + 8 * v6 + 40) + 152i64) != 0i64)
                                                                 + 1i64;
    if ( v8 )
    {
      do
      {
        v9 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                  + 8
                                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pTreeContainer.pObject[-1] - ((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pTreeContainer.pObject[-1]
                                                                                            - ((_QWORD)v3->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                  + 40)
                      + 144i64);
        if ( *(_BYTE *)v9 & 1 )
          v9 = (_QWORD *)((*v9 & 0xFFFFFFFFFFFFFFFEui64) + 16);
        v10 = v9[v4];
        v11 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)((v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8
                                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v10 - (v10 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                     + ((unsigned __int64)((unsigned __int128)((signed __int64)(v10
                                                                                              - (v10 & 0xFFFFFFFFFFFFF000ui64)
                                                                                              - 56)
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                    + 40)
                        + 144i64);
        (*(void (__fastcall **)(__int64, float *))(*(_QWORD *)(v11 + 16) + 40i64))(v11 + 16, &v19);
        if ( v4 )
        {
          v15 = v19;
          if ( v2->x1 <= v19 )
            v15 = v2->x1;
          v16 = v2->x2;
          if ( v16 <= v21 )
            v16 = v21;
          v17 = v20;
          if ( v2->y1 <= v20 )
            v17 = v2->y1;
          v18 = v2->y2;
          if ( v18 <= v22 )
            v18 = v22;
          v2->x1 = v15;
          v2->y1 = v17;
          v2->x2 = v16;
          v2->y2 = v18;
        }
        else
        {
          v12 = v20;
          v2->x1 = v19;
          v13 = v21;
          v2->y1 = v12;
          v14 = v22;
          v2->x2 = v13;
          v2->y2 = v14;
        }
        ++v4;
      }
      while ( v4 < v8 );
    }
  }
}

// File Line: 369
// RVA: 0x8C4C20
char __fastcall Scaleform::GFx::DrawingContext::DefPointTestLocal(Scaleform::GFx::DrawingContext *this, Scaleform::Render::Point<float> *pt, bool testShape, Scaleform::GFx::DisplayObjectBase *pinst)
{
  bool v4; // r15
  Scaleform::Render::Point<float> *v5; // rsi
  Scaleform::GFx::DrawingContext *v6; // r14
  __int64 v7; // rbx
  signed __int64 v8; // r9
  __int64 v9; // rax
  unsigned __int64 v10; // rcx
  __int64 v11; // rdi
  unsigned __int64 v12; // rdi
  _QWORD *v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rbp
  float v16; // xmm0_4
  char result; // al
  float v18; // [rsp+20h] [rbp-28h]
  float v19; // [rsp+24h] [rbp-24h]
  float v20; // [rsp+28h] [rbp-20h]
  float v21; // [rsp+2Ch] [rbp-1Ch]

  v4 = testShape;
  v5 = pt;
  v6 = this;
  Scaleform::GFx::DrawingContext::UpdateRenderNode(this);
  v7 = 0i64;
  v8 = (signed __int64)&v6->pTreeContainer.pObject[-1] - ((_QWORD)v6->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64);
  v9 = *(_QWORD *)(((_QWORD)v6->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v10 = (unsigned int)((signed __int64)((unsigned __int128)(v8 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
      + ((unsigned __int64)((unsigned __int128)(v8 * (signed __int128)5270498306774157605i64) >> 64) >> 63);
  v11 = *(_QWORD *)(*(_QWORD *)(v9 + 8 * v10 + 40) + 144i64);
  if ( !v11 )
    return 0;
  v12 = v11 & 1 ? *(_QWORD *)((v11 & 0xFFFFFFFFFFFFFFFEui64) + 8) : (*(_QWORD *)(*(_QWORD *)(v9 + 8 * v10 + 40) + 152i64) != 0i64)
                                                                  + 1i64;
  if ( !v12 )
    return 0;
  while ( 1 )
  {
    v13 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v6->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6->pTreeContainer.pObject[-1] - ((_QWORD)v6->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6->pTreeContainer.pObject[-1]
                                                                                         - ((_QWORD)v6->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 144i64);
    if ( *(_BYTE *)v13 & 1 )
      v13 = (_QWORD *)((*v13 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    v14 = v13[v7];
    v15 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)((v14 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                + 8
                                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v14 - (v14 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                 + ((unsigned __int64)((unsigned __int128)((signed __int64)(v14
                                                                                          - (v14 & 0xFFFFFFFFFFFFF000ui64)
                                                                                          - 56)
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                + 40)
                    + 144i64);
    (*(void (__fastcall **)(__int64, float *))(*(_QWORD *)(v15 + 16) + 40i64))(v15 + 16, &v18);
    if ( v5->x <= v20 && v5->x >= v18 )
    {
      v16 = v5->y;
      if ( v16 <= v21 && v16 >= v19 )
        break;
    }
    if ( ++v7 >= v12 )
      return 0;
  }
  if ( v4 )
    result = Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
               *(Scaleform::Render::ShapeDataInterface **)(v15 + 88),
               &Scaleform::Render::Matrix2x4<float>::Identity,
               v5->x,
               v16);
  else
    result = 1;
  return result;
}

// File Line: 397
// RVA: 0x917540
void __fastcall Scaleform::GFx::DrawingContext::UpdateRenderNode(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext *v1; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v2; // rcx
  unsigned int v3; // er15
  unsigned int v4; // er14
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v6; // rax
  int v7; // xmm0_4
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::Render::ShapeMeshProvider *v9; // rax
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v10; // rbp
  Scaleform::Render::ShapeMeshProvider *v11; // rax
  Scaleform::Render::ShapeMeshProvider *v12; // rsi
  Scaleform::Render::TreeShape *v13; // rdi
  Scaleform::MemoryHeap *v14; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v15; // rax
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  bool v18; // zf
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v19; // [rsp+28h] [rbp-50h]
  int v20; // [rsp+30h] [rbp-48h]

  v1 = this;
  this->States &= 0x7Fu;
  v2 = this->Shapes.pObject;
  if ( v2
    && !((unsigned __int8 (__cdecl *)(Scaleform::GFx::DrawingContext::PackedShape *))v2->vfptr[1].__vecDelDtor)(v2) )
  {
    v3 = v1->StrokeStyle;
    v4 = v1->FillStyle0;
    v5 = v1->Shapes.pObject;
    if ( v5
      && !((unsigned __int8 (__cdecl *)(Scaleform::GFx::DrawingContext::PackedShape *))v5->vfptr[1].__vecDelDtor)(v5) )
    {
      v1->States |= 0x80u;
      if ( v1->States & 0x10 )
        Scaleform::GFx::DrawingContext::FinishPath(v1);
      if ( v1->States & 8 )
      {
        v6 = v1->Shapes.pObject;
        v7 = LODWORD(v6->Multiplier);
        v19.Data = v6->pContainer;
        v20 = v7;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v19);
        v1->States &= 0xF7u;
      }
      v1->States |= 1u;
    }
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v1->Shapes.pObject->vfptr);
    v9 = (Scaleform::Render::ShapeMeshProvider *)v1->RenContext->pHeap->vfptr->Alloc(v8, 144ui64, 0i64);
    v10 = 0i64;
    if ( v9 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
        v9,
        (Scaleform::Render::ShapeDataInterface *)&v1->Shapes.pObject->vfptr,
        0i64);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = (Scaleform::Render::TreeShape *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(v1->RenContext);
    Scaleform::Render::TreeShape::SetShape(v13, v12);
    Scaleform::Render::TreeContainer::Add(v1->pTreeContainer.pObject, (Scaleform::Render::TreeNode *)&v13->0);
    v15 = (Scaleform::GFx::DrawingContext::PackedShape *)v1->RenContext->pHeap->vfptr->Alloc(v14, 128ui64, 0i64);
    if ( v15 )
    {
      Scaleform::GFx::DrawingContext::PackedShape::PackedShape(v15, v1->RenContext->pHeap);
      v10 = v16;
    }
    v17 = (Scaleform::Render::RenderBuffer *)v1->Shapes.pObject;
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
    v1->Shapes.pObject = (Scaleform::GFx::DrawingContext::PackedShape *)v10;
    if ( v4 )
    {
      v1->FillStyle0 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
                         v10,
                         &v1->mFillStyle);
      if ( v1->States & 0x10 )
        Scaleform::GFx::DrawingContext::EndFill(v1);
      v1->States |= 0x14u;
    }
    if ( v3 )
    {
      v1->StrokeStyle = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
                          (Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v1->Shapes.pObject->vfptr,
                          &v1->mLineStyle);
      v1->States |= 2u;
    }
    if ( v13 )
    {
      v18 = v13->RefCount-- == 1;
      if ( v18 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v13->0);
    }
    if ( v12 )
      ((void (__cdecl *)(Scaleform::Render::MeshProviderVtbl **))v12->vfptr->Release)(&v12->vfptr);
  }
}

