// File Line: 33
// RVA: 0x895F50
void __fastcall Scaleform::GFx::DrawingContext::DrawingContext(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::Render::ContextImpl::Context *renCtxt,
        Scaleform::GFx::Resource *imgCreator)
{
  Scaleform::Render::TreeContainer *v5; // rdi
  Scaleform::Render::TreeContainer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,322>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawingContext,322>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawingContext::`vftable;
  this->pTreeContainer.pObject = 0i64;
  this->RenContext = renCtxt;
  if ( imgCreator )
    Scaleform::Render::RenderBuffer::AddRef(imgCreator);
  this->ImgCreator.pObject = (Scaleform::GFx::ImageCreator *)imgCreator;
  this->Shapes.pObject = 0i64;
  this->mFillStyle.pFill.pObject = 0i64;
  this->mLineStyle.pFill.pObject = 0i64;
  this->mLineStyle.pDashes.pObject = 0i64;
  *(_QWORD *)&this->PosInfo.Pos = 0i64;
  *(_QWORD *)&this->PosInfo.StartY = 0i64;
  *(_QWORD *)&this->PosInfo.LastY = 0i64;
  *(_QWORD *)&this->PosInfo.StrokeBase = 0i64;
  *(_QWORD *)&this->PosInfo.NumStrokeBits = 0i64;
  *(_QWORD *)&this->PosInfo.Fill1 = 0i64;
  this->PosInfo.Sfactor = 1.0;
  this->PosInfo.Initialized = 0;
  this->States = 1;
  this->pPrev = 0i64;
  this->pNext = 0i64;
  v5 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(this->RenContext);
  pObject = this->pTreeContainer.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pTreeContainer.pObject = v5;
  Scaleform::GFx::DrawingContext::Clear(this);
}

// File Line: 41
// RVA: 0x8A41B0
void __fastcall Scaleform::GFx::DrawingContext::~DrawingContext(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::TreeContainer *v7; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawingContext::`vftable;
  if ( this->pPrev && this->pNext )
  {
    this->pPrev->pNext = this->pNext;
    this->pNext->pPrev = this->pPrev;
    this->pPrev = (Scaleform::GFx::DrawingContext *)-1i64;
    this->pNext = (Scaleform::GFx::DrawingContext *)-1i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->mLineStyle.pDashes.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->mLineStyle.pFill.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::Render::RenderBuffer *)this->Shapes.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::Render::RenderBuffer *)this->ImgCreator.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v7 = this->pTreeContainer.pObject;
  if ( v7 )
  {
    if ( v7->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

// File Line: 47
// RVA: 0x8BC050
void __fastcall Scaleform::GFx::DrawingContext::Clear(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext::PackedShape *v2; // rax
  unsigned __int64 v3; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *v4; // rax
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rsi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  __int64 v7; // rdx
  __int64 v8; // rax

  v2 = (Scaleform::GFx::DrawingContext::PackedShape *)this->RenContext->pHeap->vfptr->Alloc(this, 128i64, 0i64);
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::DrawingContext::PackedShape::PackedShape(v2, this->RenContext->pHeap);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  pObject = (Scaleform::Render::RenderBuffer *)this->Shapes.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->Shapes.pObject = v5;
  this->States = 1;
  *(_QWORD *)&this->Ex = 0i64;
  this->StY = 1.1754944e-38;
  this->StX = 1.1754944e-38;
  *(_QWORD *)&this->StrokeStyle = 0i64;
  this->FillStyle1 = 0;
  v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64
                 * (unsigned int)((int)(LODWORD(this->pTreeContainer.pObject)
                                      - ((__int64)this->pTreeContainer.pObject & 0xFFFFF000)
                                      - 56)
                                / 56)
                 + 40);
  v8 = *(_QWORD *)(v7 + 144);
  if ( v8 )
  {
    if ( (v8 & 1) != 0 )
    {
      v3 = *(_QWORD *)((v8 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    }
    else
    {
      LOBYTE(v3) = *(_QWORD *)(v7 + 152) != 0i64;
      ++v3;
    }
  }
  Scaleform::Render::TreeContainer::Remove(this->pTreeContainer.pObject, 0i64, v3);
  this->States |= 0x80u;
}

// File Line: 59
// RVA: 0x909B40
void __fastcall Scaleform::GFx::DrawingContext::SetNoLine(Scaleform::GFx::DrawingContext *this)
{
  this->States &= ~2u;
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
void __fastcall Scaleform::GFx::DrawingContext::ChangeLineStyle(
        Scaleform::GFx::DrawingContext *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  float v10; // xmm6_4
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v13; // rcx
  int Multiplier_low; // xmm0_4
  Scaleform::GFx::DrawingContext::PackedShape *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v17; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v18; // rcx
  int v19; // xmm0_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v20; // [rsp+40h] [rbp-48h] BYREF
  int v21; // [rsp+48h] [rbp-40h]

  v10 = lineWidth;
  if ( (rgba & 0xFF000000) != 0 )
  {
    if ( lineWidth <= 0.0 )
      v10 = FLOAT_0_050000001;
    if ( !Scaleform::GFx::DrawingContext::SameLineStyle(this, v10, rgba, hinting, scaling, caps, joins, miterLimit) )
    {
      pObject = this->Shapes.pObject;
      if ( pObject
        && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))pObject->vfptr[1].__vecDelDtor)(pObject) )
      {
        this->States |= 0x80u;
        if ( (this->States & 8) != 0 )
        {
          v13 = this->Shapes.pObject;
          Multiplier_low = LODWORD(v13->Multiplier);
          v20.Data = v13->pContainer;
          v21 = Multiplier_low;
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v20);
          this->States &= ~8u;
        }
        this->States &= ~1u;
      }
      v15 = this->Shapes.pObject;
      this->mLineStyle.Miter = miterLimit;
      this->mLineStyle.Color = rgba;
      this->mLineStyle.Units = 0.050000001;
      this->mLineStyle.Width = v10;
      this->mLineStyle.Flags = joins | caps | scaling | hinting;
      v16 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
              v15,
              &this->mLineStyle);
      this->States |= 2u;
      this->StrokeStyle = v16;
    }
  }
  else if ( ((unsigned int (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))this->Shapes.pObject->vfptr[3].__vecDelDtor)(this->Shapes.pObject)
         && this->StrokeStyle )
  {
    v17 = this->Shapes.pObject;
    if ( v17
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))v17->vfptr[1].__vecDelDtor)(v17) )
    {
      this->States |= 0x80u;
      if ( (this->States & 8) != 0 )
      {
        v18 = this->Shapes.pObject;
        v19 = LODWORD(v18->Multiplier);
        v20.Data = v18->pContainer;
        v21 = v19;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v20);
        this->States &= ~8u;
      }
      this->States &= ~1u;
    }
    this->States &= ~2u;
    this->StrokeStyle = 0;
  }
}

// File Line: 125
// RVA: 0x904720
bool __fastcall Scaleform::GFx::DrawingContext::SameLineStyle(
        Scaleform::GFx::DrawingContext *this,
        float lineWidth,
        unsigned int rgba,
        bool hinting,
        unsigned int scaling,
        unsigned int caps,
        unsigned int joins,
        float miterLimit)
{
  int v12; // ebx
  bool v13; // bl
  int v14[6]; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::RenderBuffer *v15; // [rsp+40h] [rbp-28h]
  Scaleform::Render::RenderBuffer *v16; // [rsp+48h] [rbp-20h]

  if ( !((unsigned int (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))this->Shapes.pObject->vfptr[3].__vecDelDtor)(this->Shapes.pObject)
    || !this->StrokeStyle )
  {
    return 0;
  }
  v12 = 0;
  v15 = 0i64;
  v16 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, int *))this->Shapes.pObject->vfptr[5].__vecDelDtor)(
    this->Shapes.pObject,
    this->StrokeStyle,
    v14);
  v13 = 0;
  if ( !v15 && v14[4] == rgba && COERCE_INT(*(float *)v14 * 20.0) == COERCE_INT(lineWidth * 20.0) )
  {
    LOBYTE(v12) = hinting;
    if ( v14[2] == (joins | caps | scaling | v12)
      && COERCE_INT(*(float *)&v14[3] * 20.0) == COERCE_INT(miterLimit * 20.0) )
    {
      v13 = 1;
    }
  }
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  return v13;
}

// File Line: 145
// RVA: 0x8EBE20
bool __fastcall Scaleform::GFx::DrawingContext::NoLine(Scaleform::GFx::DrawingContext *this)
{
  return !((unsigned int (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))this->Shapes.pObject->vfptr[3].__vecDelDtor)(this->Shapes.pObject)
      || !this->StrokeStyle;
}

// File Line: 162
// RVA: 0x8C2560
Scaleform::Render::ComplexFill *__fastcall Scaleform::GFx::DrawingContext::CreateNewComplexFill(
        Scaleform::GFx::DrawingContext *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int v3; // esi
  __int64 v4; // rcx
  __int64 v5; // rbx
  Scaleform::Render::FillStyleType *v6; // rdi
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  unsigned int v10; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::Render::RenderBuffer *v11; // [rsp+30h] [rbp-28h]

  this->mFillStyle.Color = 0;
  pObject = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mFillStyle.pFill.pObject = 0i64;
  v3 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
         this->Shapes.pObject,
         &this->mFillStyle);
  this->FillStyle0 = v3;
  this->FillStyle1 = 0;
  v5 = ((__int64 (__fastcall *)(__int64, __int64))this->RenContext->pHeap->vfptr->Alloc)(v4, 80i64);
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
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, unsigned int *))this->Shapes.pObject->vfptr[4].__vecDelDtor)(
    this->Shapes.pObject,
    v3,
    &v10);
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5);
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v11 = (Scaleform::Render::RenderBuffer *)v5;
  v6 = &this->Shapes.pObject->FillStyles.Data.Data[v3 - 1];
  v6->Color = v10;
  v7 = v11;
  if ( v11 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v11);
    v7 = v11;
  }
  v8 = (Scaleform::Render::RenderBuffer *)v6->pFill.pObject;
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    v7 = v11;
  }
  v6->pFill.pObject = (Scaleform::Render::ComplexFill *)v7;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  return (Scaleform::Render::ComplexFill *)v5;
}

// File Line: 173
// RVA: 0x8C08F0
Scaleform::GFx::Resource *__fastcall Scaleform::GFx::DrawingContext::CreateLineComplexFill(
        Scaleform::GFx::DrawingContext *this)
{
  __int64 v2; // rax
  Scaleform::GFx::Resource *v3; // rbx
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // rdx
  __int64 v5; // rdi
  Scaleform::Render::StrokeStyleType *Data; // rsi
  Scaleform::Render::RenderBuffer *v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::Resource *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rcx
  int v12[6]; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::Render::RenderBuffer *v13; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::Resource *v14; // [rsp+48h] [rbp-20h]

  if ( (this->States & 2) == 0 )
    this->StrokeStyle = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
                          this->Shapes.pObject,
                          &this->mLineStyle);
  v2 = ((__int64 (__fastcall *)(Scaleform::GFx::DrawingContext *, __int64))this->RenContext->pHeap->vfptr->Alloc)(
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
  v13 = 0i64;
  v14 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, int *))this->Shapes.pObject->vfptr[5].__vecDelDtor)(
    this->Shapes.pObject,
    this->StrokeStyle,
    v12);
  if ( v3 )
    Scaleform::Render::RenderBuffer::AddRef(v3);
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v13 = (Scaleform::Render::RenderBuffer *)v3;
  pObject = this->Shapes.pObject;
  v5 = this->StrokeStyle - 1;
  Data = pObject->StrokeStyles.Data.Data;
  LODWORD(Data[v5].Width) = v12[0];
  LODWORD(Data[v5].Units) = v12[1];
  Data[v5].Flags = v12[2];
  LODWORD(Data[v5].Miter) = v12[3];
  Data[v5].Color = v12[4];
  v7 = v13;
  if ( v13 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v13);
    v7 = v13;
  }
  v8 = (Scaleform::Render::RenderBuffer *)Data[v5].pFill.pObject;
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    v7 = v13;
  }
  Data[v5].pFill.pObject = (Scaleform::Render::ComplexFill *)v7;
  v9 = v14;
  if ( v14 )
  {
    Scaleform::Render::RenderBuffer::AddRef(v14);
    v9 = v14;
  }
  v10 = (Scaleform::Render::RenderBuffer *)Data[v5].pDashes.pObject;
  if ( v10 )
  {
    Scaleform::RefCountImpl::Release(v10);
    v9 = v14;
  }
  Data[v5].pDashes.pObject = (Scaleform::Render::DashArray *)v9;
  if ( v14 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
  return v3;
}

// File Line: 193
// RVA: 0x8B6F70
void __fastcall Scaleform::GFx::DrawingContext::BeginFill(Scaleform::GFx::DrawingContext *this)
{
  if ( (this->States & 0x10) != 0 )
  {
    Scaleform::GFx::DrawingContext::EndFill(this);
    this->States |= 0x14u;
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
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int v4; // eax
  bool v5; // zf

  this->mFillStyle.Color = rgba;
  pObject = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mFillStyle.pFill.pObject = 0i64;
  v4 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
         this->Shapes.pObject,
         &this->mFillStyle);
  v5 = (this->States & 0x10) == 0;
  *(_QWORD *)&this->FillStyle0 = v4;
  if ( !v5 )
    Scaleform::GFx::DrawingContext::EndFill(this);
  this->States |= 0x14u;
}

// File Line: 216
// RVA: 0x8B6B80
void __fastcall Scaleform::GFx::DrawingContext::BeginBitmapFill(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::GFx::FillType fillType,
        Scaleform::GFx::ImageResource *pimageRes,
        Scaleform::Render::Matrix2x4<float> *mtx)
{
  Scaleform::Render::RenderBuffer *pImage; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int v10; // eax
  unsigned int v11; // r15d
  __int64 v12; // rcx
  __int64 v13; // rdi
  float v14; // xmm1_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  Scaleform::MemoryHeap *v17; // rax
  Scaleform::Render::RenderBuffer *v18; // rdi
  __int64 v19; // rcx
  int v20; // r14d
  int v21; // r14d
  int v22; // r14d
  Scaleform::Render::FillStyleType *v23; // rdi
  Scaleform::Render::RenderBuffer *v24; // rax
  Scaleform::Render::RenderBuffer *v25; // rcx
  int v26[2]; // [rsp+20h] [rbp-81h] BYREF
  Scaleform::Render::RenderBuffer *v27[2]; // [rsp+28h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+38h] [rbp-69h] BYREF
  int v29; // [rsp+58h] [rbp-49h] BYREF
  Scaleform::MemoryHeap *v30; // [rsp+60h] [rbp-41h]
  int v31; // [rsp+68h] [rbp-39h]
  int v32; // [rsp+6Ch] [rbp-35h]
  __int64 v33; // [rsp+70h] [rbp-31h]
  __int64 v34; // [rsp+78h] [rbp-29h]
  __int64 v35; // [rsp+80h] [rbp-21h]
  __int64 v36; // [rsp+88h] [rbp-19h]
  __int64 v37; // [rsp+90h] [rbp-11h]
  Scaleform::MemoryHeap *pHeap; // [rsp+98h] [rbp-9h]
  __int64 v39; // [rsp+A0h] [rbp-1h]
  Scaleform::LogMessageId id; // [rsp+108h] [rbp+67h] BYREF

  v39 = -2i64;
  pImage = 0i64;
  this->mFillStyle.Color = 0;
  pObject = (Scaleform::Render::RenderBuffer *)this->mFillStyle.pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mFillStyle.pFill.pObject = 0i64;
  v10 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
          this->Shapes.pObject,
          &this->mFillStyle);
  v11 = v10;
  *(_QWORD *)&this->FillStyle0 = v10;
  if ( v10 )
  {
    v27[0] = 0i64;
    ((void (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *, _QWORD, int *))this->Shapes.pObject->vfptr[4].__vecDelDtor)(
      this->Shapes.pObject,
      v10,
      v26);
    pHeap = this->RenContext->pHeap;
    v13 = ((__int64 (__fastcall *)(__int64, __int64))pHeap->vfptr->Alloc)(v12, 80i64);
    v37 = v13;
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
    if ( v27[0] )
      Scaleform::RefCountImpl::Release(v27[0]);
    v27[0] = (Scaleform::Render::RenderBuffer *)v13;
    v14 = mtx->M[0][1];
    v15 = mtx->M[1][2];
    v16 = mtx->M[1][3];
    m.M[0][0] = mtx->M[0][0] * 20.0;
    m.M[0][1] = v14 * 20.0;
    m.M[1][2] = v15 * 20.0;
    m.M[1][3] = v16 * 20.0;
    *(_OWORD *)&m.M[0][2] = _xmm;
    *(__m128 *)v27 = _xmm;
    Scaleform::Render::Matrix2x4<float>::SetInverse((Scaleform::Render::Matrix2x4<float> *)&m.M[0][2], &m);
    *(_QWORD *)(v13 + 32) = *(_QWORD *)&m.M[0][2];
    *(float *)(v13 + 40) = m.M[1][0];
    *(_DWORD *)(v13 + 44) = v26[1];
    *(Scaleform::Render::RenderBuffer **)(v13 + 48) = v27[0];
    *(Scaleform::Render::RenderBuffer **)(v13 + 56) = v27[1];
    v27[1] = 0i64;
    if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))pimageRes->pImage->vfptr[3].__vecDelDtor)(pimageRes->pImage) )
    {
      pImage = (Scaleform::Render::RenderBuffer *)pimageRes->pImage;
      if ( pImage )
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(pimageRes->pImage);
      v27[1] = pImage;
    }
    else if ( this->ImgCreator.pObject )
    {
      v17 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v29 = 3;
      v30 = v17;
      v31 = 1;
      v32 = 1;
      v33 = 0i64;
      v34 = 0i64;
      v35 = 0i64;
      v36 = 0i64;
      pImage = (Scaleform::Render::RenderBuffer *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))this->ImgCreator.pObject->vfptr[4].__vecDelDtor)(
                                                    this->ImgCreator.pObject,
                                                    &v29,
                                                    pimageRes->pImage);
      v27[1] = pImage;
    }
    else
    {
      id.Id = 135168;
      Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in BeginBitmapFill");
    }
    v18 = v27[0];
    if ( pImage )
      ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pImage->vfptr[1].__vecDelDtor)(pImage);
    v19 = *(_QWORD *)&v18->Type;
    if ( v19 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19);
    *(_QWORD *)&v18->Type = pImage;
    v20 = fillType - 64;
    if ( v20 )
    {
      v21 = v20 - 1;
      if ( v21 )
      {
        v22 = v21 - 1;
        if ( v22 )
        {
          if ( v22 == 1 )
            LOBYTE(v27[0][1].Type) = 1;
        }
        else
        {
          LOBYTE(v27[0][1].Type) = 0;
        }
      }
      else
      {
        LOBYTE(v27[0][1].Type) = 3;
      }
    }
    else
    {
      LOBYTE(v27[0][1].Type) = 2;
    }
    v23 = &this->Shapes.pObject->FillStyles.Data.Data[v11 - 1];
    v23->Color = v26[0];
    v24 = v27[0];
    if ( v27[0] )
    {
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v27[0]);
      v24 = v27[0];
    }
    v25 = (Scaleform::Render::RenderBuffer *)v23->pFill.pObject;
    if ( v25 )
    {
      Scaleform::RefCountImpl::Release(v25);
      v24 = v27[0];
    }
    v23->pFill.pObject = (Scaleform::Render::ComplexFill *)v24;
    if ( (this->States & 0x10) != 0 )
      Scaleform::GFx::DrawingContext::EndFill(this);
    this->States |= 0x14u;
    if ( pImage )
      ((void (__fastcall *)(Scaleform::Render::RenderBuffer *))pImage->vfptr[2].__vecDelDtor)(pImage);
    if ( v27[0] )
      Scaleform::RefCountImpl::Release(v27[0]);
  }
}

// File Line: 256
// RVA: 0x8C8800
void __fastcall Scaleform::GFx::DrawingContext::EndFill(Scaleform::GFx::DrawingContext *this)
{
  char States; // al
  float StX; // xmm1_4
  bool v4; // zf

  States = this->States;
  if ( (States & 0x10) != 0 )
  {
    StX = this->StX;
    v4 = StX == this->Ex;
    this->States = States & 0xEF;
    if ( !v4 || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, StX, this->StY);
  }
  this->StY = 1.1754944e-38;
  this->StX = 1.1754944e-38;
  *(_QWORD *)&this->FillStyle0 = 0i64;
}

// File Line: 263
// RVA: 0x8EBBB0
void __fastcall Scaleform::GFx::DrawingContext::MoveTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  char States; // al
  float StX; // xmm1_4
  int v7; // [rsp+54h] [rbp-2Ch]

  this->PosInfo.Pos = 0;
  this->PosInfo.StartX = 0;
  this->PosInfo.StartY = 0;
  LOBYTE(v7) = 0;
  States = this->States;
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
  if ( (States & 4) == 0 && (States & 0x10) != 0 )
  {
    StX = this->StX;
    if ( StX != this->Ex || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, StX, this->StY);
  }
  Scaleform::GFx::DrawingContext::NewPath(this, x, y);
  this->States &= ~4u;
  this->StX = x;
  this->StY = y;
}

// File Line: 279
// RVA: 0x8E8200
void __fastcall Scaleform::GFx::DrawingContext::LineTo(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  if ( (this->States & 8) == 0 )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
    this->Shapes.pObject,
    &this->PosInfo,
    x,
    y);
  this->States &= ~2u;
  this->Ex = x;
  this->Ey = y;
  this->States |= 0x80u;
}

// File Line: 292
// RVA: 0x8C44B0
void __fastcall Scaleform::GFx::DrawingContext::CurveTo(
        Scaleform::GFx::DrawingContext *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  if ( (this->States & 8) == 0 )
    Scaleform::GFx::DrawingContext::NewPath(this, this->Ex, this->Ey);
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
    this->Shapes.pObject,
    &this->PosInfo,
    cx,
    cy,
    ax,
    ay);
  this->States &= ~2u;
  this->Ex = ax;
  this->Ey = ay;
  this->States |= 0x80u;
}

// File Line: 305
// RVA: 0x8EBD80
void __fastcall Scaleform::GFx::DrawingContext::NewPath(Scaleform::GFx::DrawingContext *this, float x, float y)
{
  Scaleform::Render::ShapePathType v4; // r8d

  Scaleform::GFx::DrawingContext::AcquirePath(this, this->States & 1);
  v4 = Shape_NewLayer;
  if ( (this->States & 1) == 0 )
    v4 = Shape_NewPath;
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
    this->Shapes.pObject,
    &this->PosInfo,
    v4,
    this->FillStyle0,
    this->FillStyle1,
    this->StrokeStyle,
    x,
    y);
  this->States &= ~1u;
  this->States |= 0x88u;
  this->Ex = x;
  this->Ey = y;
}

// File Line: 319
// RVA: 0x8CD6F0
void __fastcall Scaleform::GFx::DrawingContext::FinishPath(Scaleform::GFx::DrawingContext *this)
{
  char States; // al
  float StX; // xmm1_4
  bool v3; // zf

  States = this->States;
  if ( (States & 0x10) != 0 )
  {
    StX = this->StX;
    v3 = StX == this->Ex;
    this->States = States & 0xEF;
    if ( !v3 || this->StY != this->Ey )
      Scaleform::GFx::DrawingContext::LineTo(this, StX, this->StY);
  }
}

// File Line: 331
// RVA: 0x8B0030
char __fastcall Scaleform::GFx::DrawingContext::AcquirePath(Scaleform::GFx::DrawingContext *this, bool newShapeFlag)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rcx
  int Multiplier_low; // xmm0_4
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v8; // [rsp+20h] [rbp-18h] BYREF
  int v9; // [rsp+28h] [rbp-10h]

  pObject = this->Shapes.pObject;
  if ( !pObject
    || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))pObject->vfptr[1].__vecDelDtor)(pObject) )
  {
    return 0;
  }
  this->States |= 0x80u;
  if ( newShapeFlag && (this->States & 0x10) != 0 )
    Scaleform::GFx::DrawingContext::FinishPath(this);
  if ( (this->States & 8) != 0 )
  {
    v5 = this->Shapes.pObject;
    Multiplier_low = LODWORD(v5->Multiplier);
    v8.Data = v5->pContainer;
    v9 = Multiplier_low;
    Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v8);
    this->States &= ~8u;
  }
  if ( newShapeFlag )
    this->States |= 1u;
  else
    this->States &= ~1u;
  return 1;
}

// File Line: 352
// RVA: 0x8BD720
void __fastcall Scaleform::GFx::DrawingContext::ComputeBound(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::Render::Rect<float> *pRect)
{
  unsigned __int64 v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // rsi
  unsigned __int64 v8; // rsi
  _QWORD *v9; // rcx
  __int64 v10; // rcx
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float x1; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  float y2; // xmm0_4
  float v18; // [rsp+20h] [rbp-18h] BYREF
  float v19; // [rsp+24h] [rbp-14h]
  float v20; // [rsp+28h] [rbp-10h]
  float v21; // [rsp+2Ch] [rbp-Ch]

  Scaleform::GFx::DrawingContext::UpdateRenderNode(this);
  v4 = 0i64;
  v5 = *(_QWORD *)(((unsigned __int64)this->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v6 = (unsigned int)((int)(LODWORD(this->pTreeContainer.pObject)
                          - ((__int64)this->pTreeContainer.pObject & 0xFFFFF000)
                          - 56)
                    / 56);
  v7 = *(_QWORD *)(*(_QWORD *)(v5 + 8 * v6 + 40) + 144i64);
  if ( v7 )
  {
    v8 = (v7 & 1) != 0
       ? *(_QWORD *)((v7 & 0xFFFFFFFFFFFFFFFEui64) + 8)
       : (*(_QWORD *)(*(_QWORD *)(v5 + 8 * v6 + 40) + 152i64) != 0i64) + 1i64;
    if ( v8 )
    {
      do
      {
        v9 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64)
                                              + 0x20)
                                  + 8i64
                                  * (unsigned int)((int)(LODWORD(this->pTreeContainer.pObject)
                                                       - ((__int64)this->pTreeContainer.pObject & 0xFFFFF000)
                                                       - 56)
                                                 / 56)
                                  + 40)
                      + 144i64);
        if ( (*(_BYTE *)v9 & 1) != 0 )
          v9 = (_QWORD *)((*v9 & 0xFFFFFFFFFFFFFFFEui64) + 16);
        v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)((v9[v4] & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8i64 * (unsigned int)((int)(v9[v4] - (v9[v4] & 0xFFFFF000) - 56) / 56)
                                    + 40)
                        + 144i64);
        (*(void (__fastcall **)(__int64, float *))(*(_QWORD *)(v10 + 16) + 40i64))(v10 + 16, &v18);
        if ( v4 )
        {
          x1 = v18;
          if ( pRect->x1 <= v18 )
            x1 = pRect->x1;
          x2 = pRect->x2;
          if ( x2 <= v20 )
            x2 = v20;
          y1 = v19;
          if ( pRect->y1 <= v19 )
            y1 = pRect->y1;
          y2 = pRect->y2;
          if ( y2 <= v21 )
            y2 = v21;
          pRect->x1 = x1;
          pRect->y1 = y1;
          pRect->x2 = x2;
          pRect->y2 = y2;
        }
        else
        {
          v11 = v19;
          pRect->x1 = v18;
          v12 = v20;
          pRect->y1 = v11;
          v13 = v21;
          pRect->x2 = v12;
          pRect->y2 = v13;
        }
        ++v4;
      }
      while ( v4 < v8 );
    }
  }
}

// File Line: 369
// RVA: 0x8C4C20
char __fastcall Scaleform::GFx::DrawingContext::DefPointTestLocal(
        Scaleform::GFx::DrawingContext *this,
        Scaleform::Render::Point<float> *pt,
        bool testShape,
        Scaleform::GFx::DisplayObjectBase *pinst)
{
  __int64 v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 v10; // rdi
  unsigned __int64 v11; // rdi
  _QWORD *v12; // rcx
  __int64 v13; // rbp
  float y; // xmm0_4
  int v16[10]; // [rsp+20h] [rbp-28h] BYREF

  Scaleform::GFx::DrawingContext::UpdateRenderNode(this);
  v7 = 0i64;
  v8 = *(_QWORD *)(((unsigned __int64)this->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v9 = (unsigned int)((int)(LODWORD(this->pTreeContainer.pObject)
                          - ((__int64)this->pTreeContainer.pObject & 0xFFFFF000)
                          - 56)
                    / 56);
  v10 = *(_QWORD *)(*(_QWORD *)(v8 + 8 * v9 + 40) + 144i64);
  if ( !v10 )
    return 0;
  v11 = (v10 & 1) != 0
      ? *(_QWORD *)((v10 & 0xFFFFFFFFFFFFFFFEui64) + 8)
      : (*(_QWORD *)(*(_QWORD *)(v8 + 8 * v9 + 40) + 152i64) != 0i64) + 1i64;
  if ( !v11 )
    return 0;
  while ( 1 )
  {
    v12 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pTreeContainer.pObject & 0xFFFFFFFFFFFFF000ui64)
                                           + 0x20)
                               + 8i64
                               * (unsigned int)((int)(LODWORD(this->pTreeContainer.pObject)
                                                    - ((__int64)this->pTreeContainer.pObject & 0xFFFFF000)
                                                    - 56)
                                              / 56)
                               + 40)
                   + 144i64);
    if ( (*(_BYTE *)v12 & 1) != 0 )
      v12 = (_QWORD *)((*v12 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    v13 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)((v12[v7] & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                + 8i64 * (unsigned int)((int)(v12[v7] - (v12[v7] & 0xFFFFF000) - 56) / 56)
                                + 40)
                    + 144i64);
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)(v13 + 16) + 40i64))(v13 + 16, v16);
    if ( pt->x <= *(float *)&v16[2] && pt->x >= *(float *)v16 )
    {
      y = pt->y;
      if ( y <= *(float *)&v16[3] && y >= *(float *)&v16[1] )
        break;
    }
    if ( ++v7 >= v11 )
      return 0;
  }
  if ( testShape )
    return Scaleform::Render::HitTestFill<Scaleform::Render::Matrix2x4<float>>(
             *(Scaleform::Render::ShapeDataInterface **)(v13 + 88),
             &Scaleform::Render::Matrix2x4<float>::Identity,
             pt->x,
             y);
  else
    return 1;
}

// File Line: 397
// RVA: 0x917540
void __fastcall Scaleform::GFx::DrawingContext::UpdateRenderNode(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // rcx
  unsigned int StrokeStyle; // r15d
  unsigned int FillStyle0; // r14d
  Scaleform::GFx::DrawingContext::PackedShape *v5; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v6; // rax
  int Multiplier_low; // xmm0_4
  Scaleform::MemoryHeap *v8; // rcx
  Scaleform::Render::ShapeMeshProvider *v9; // rax
  Scaleform::GFx::DrawingContext::PackedShape *v10; // rbp
  Scaleform::Render::ContextImpl::EntryDataVtbl *v11; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v12; // rsi
  Scaleform::Render::TreeShape *v13; // rdi
  Scaleform::MemoryHeap *v14; // rcx
  Scaleform::GFx::DrawingContext::PackedShape *v15; // rax
  Scaleform::GFx::DrawingContext::PackedShape *v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v19; // [rsp+28h] [rbp-50h] BYREF
  int v20; // [rsp+30h] [rbp-48h]

  this->States &= ~0x80u;
  pObject = this->Shapes.pObject;
  if ( pObject
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))pObject->vfptr[1].__vecDelDtor)(pObject) )
  {
    StrokeStyle = this->StrokeStyle;
    FillStyle0 = this->FillStyle0;
    v5 = this->Shapes.pObject;
    if ( v5
      && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DrawingContext::PackedShape *))v5->vfptr[1].__vecDelDtor)(v5) )
    {
      this->States |= 0x80u;
      if ( (this->States & 0x10) != 0 )
        Scaleform::GFx::DrawingContext::FinishPath(this);
      if ( (this->States & 8) != 0 )
      {
        v6 = this->Shapes.pObject;
        Multiplier_low = LODWORD(v6->Multiplier);
        v19.Data = v6->pContainer;
        v20 = Multiplier_low;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteEndPath(&v19);
        this->States &= ~8u;
      }
      this->States |= 1u;
    }
    Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(this->Shapes.pObject);
    v9 = (Scaleform::Render::ShapeMeshProvider *)this->RenContext->pHeap->vfptr->Alloc(v8, 144i64, 0i64);
    v10 = 0i64;
    if ( v9 )
    {
      Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(v9, this->Shapes.pObject, 0i64);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    v13 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeShape>(this->RenContext);
    Scaleform::Render::TreeShape::SetShape(v13, v12);
    Scaleform::Render::TreeContainer::Add(this->pTreeContainer.pObject, v13);
    v15 = (Scaleform::GFx::DrawingContext::PackedShape *)this->RenContext->pHeap->vfptr->Alloc(v14, 128i64, 0i64);
    if ( v15 )
    {
      Scaleform::GFx::DrawingContext::PackedShape::PackedShape(v15, this->RenContext->pHeap);
      v10 = v16;
    }
    v17 = (Scaleform::Render::RenderBuffer *)this->Shapes.pObject;
    if ( v17 )
      Scaleform::RefCountImpl::Release(v17);
    this->Shapes.pObject = v10;
    if ( FillStyle0 )
    {
      this->FillStyle0 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
                           v10,
                           &this->mFillStyle);
      if ( (this->States & 0x10) != 0 )
        Scaleform::GFx::DrawingContext::EndFill(this);
      this->States |= 0x14u;
    }
    if ( StrokeStyle )
    {
      this->StrokeStyle = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddStrokeStyle(
                            this->Shapes.pObject,
                            &this->mLineStyle);
      this->States |= 2u;
    }
    if ( v13 )
    {
      if ( v13->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
    }
    if ( v12 )
      (*((void (__fastcall **)(void (__fastcall **)(Scaleform::Render::ContextImpl::EntryData *, void *)))v12->CopyTo + 2))(&v12->CopyTo);
  }
}

