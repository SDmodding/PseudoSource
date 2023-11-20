// File Line: 48
// RVA: 0x946070
void __fastcall Scaleform::Render::TextLayout::TextLayout(Scaleform::Render::TextLayout *this, Scaleform::Render::TextLayout::Builder *builder)
{
  Scaleform::ArrayLH_POD<unsigned char,74,Scaleform::ArrayDefaultPolicy> *v2; // [rsp+50h] [rbp+18h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextLayout,74>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextLayout::`vftable';
  this->Param.TextParam.pFont = 0i64;
  *(_QWORD *)&this->Param.TextParam.GlyphIndex = 0i64;
  *(_DWORD *)&this->Param.TextParam.BlurY = 0x100000;
  this->Param.ShadowParam.pFont = 0i64;
  *(_QWORD *)&this->Param.ShadowParam.GlyphIndex = 0i64;
  *(_DWORD *)&this->Param.ShadowParam.BlurY = 0x100000;
  *(_QWORD *)&this->Param.ShadowColor = 0i64;
  this->Param.ShadowOffsetY = 0.0;
  *(_QWORD *)&this->Bounds.x1 = 0i64;
  *(_QWORD *)&this->Bounds.x2 = 0i64;
  *(_QWORD *)&this->ClipBox.x1 = 0i64;
  *(_QWORD *)&this->ClipBox.x2 = 0i64;
  v2 = &this->Data;
  *(_OWORD *)&v2->Data.Data = 0ui64;
  v2->Data.Policy.Capacity = 0i64;
  this->pFonts = 0i64;
  this->FontCount = 0i64;
  this->pImages = 0i64;
  this->ImageCount = 0i64;
  this->pRefCntData = 0i64;
  this->RefCntCount = 0i64;
  Scaleform::Render::TextLayout::Create(this, builder);
}

// File Line: 58
// RVA: 0x95FF20
void __fastcall Scaleform::Render::TextLayout::Clear(Scaleform::Render::TextLayout *this)
{
  Scaleform::Render::TextLayout *v1; // rbx
  unsigned __int64 v2; // rdi
  Scaleform::Render::Font *v3; // rcx
  unsigned __int64 i; // rdi
  unsigned __int64 j; // rdi
  Scaleform::RefCountImpl *v6; // rcx

  v1 = this;
  v2 = 0i64;
  if ( this->FontCount )
  {
    do
    {
      v3 = v1->pFonts[v2];
      if ( !_InterlockedDecrement(&v3->RefCount) && v3 )
        v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
      ++v2;
    }
    while ( v2 < v1->FontCount );
  }
  for ( i = 0i64; i < v1->ImageCount; ++i )
    ((void (*)(void))v1->pImages[i]->vfptr[2].__vecDelDtor)();
  for ( j = 0i64; j < v1->RefCntCount; ++j )
  {
    v6 = v1->pRefCntData[j];
    if ( !_InterlockedDecrement(&v6->RefCount) && v6 )
      v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
  }
  if ( v1->Data.Data.Size > 0 && v1->Data.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
  {
    if ( v1->Data.Data.Data )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1->Data.Data.Data = 0i64;
    }
    v1->Data.Data.Policy.Capacity = 0i64;
  }
  v1->Data.Data.Size = 0i64;
}

// File Line: 71
// RVA: 0x965B90
void __fastcall Scaleform::Render::TextLayout::Create(Scaleform::Render::TextLayout *this, Scaleform::Render::TextLayout::Builder *builder)
{
  unsigned __int64 v2; // rdi
  Scaleform::Render::TextLayout::Builder *v3; // rsi
  Scaleform::Render::TextLayout *v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // eax
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,74>,Scaleform::ArrayDefaultPolicy> *v8; // rcx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  Scaleform::Render::Font **v16; // rcx
  Scaleform::Render::Image **v17; // rcx
  Scaleform::RefCountImpl **v18; // rcx
  unsigned __int64 i; // rdx
  unsigned __int64 j; // rsi

  v2 = 0i64;
  v3 = builder;
  v4 = this;
  this->pFonts = 0i64;
  this->FontCount = 0i64;
  this->pImages = 0i64;
  this->ImageCount = 0i64;
  this->pRefCntData = 0i64;
  this->RefCntCount = 0i64;
  v5 = builder->Bounds.y2;
  v6 = builder->Bounds.x2;
  v7 = builder->Bounds.x1;
  v8 = &this->Data.Data;
  HIDWORD(v8[-2].Policy.Capacity) = LODWORD(builder->Bounds.y1);
  *(float *)&v8[-1].Data = v6;
  *((float *)&v8[-1].Data + 1) = v5;
  *(float *)&v8[-2].Policy.Capacity = v7;
  v9 = builder->ClipBox.y2;
  v10 = builder->ClipBox.x2;
  v11 = builder->ClipBox.y1;
  *(float *)&v8[-1].Size = builder->ClipBox.x1;
  *((float *)&v8[-1].Size + 1) = v11;
  *(float *)&v8[-1].Policy.Capacity = v10;
  *((float *)&v8[-1].Policy.Capacity + 1) = v9;
  v8[-4].Data = (char *)builder->Param.TextParam.pFont;
  v8[-4].Size = *(_QWORD *)&builder->Param.TextParam.GlyphIndex;
  v8[-4].Policy.Capacity = *(_QWORD *)&builder->Param.TextParam.BlurY;
  v8[-3].Data = (char *)builder->Param.ShadowParam.pFont;
  v8[-3].Size = *(_QWORD *)&builder->Param.ShadowParam.GlyphIndex;
  v8[-3].Policy.Capacity = *(_QWORD *)&builder->Param.ShadowParam.BlurY;
  v8[-2].Data = *(char **)&builder->Param.ShadowColor;
  v8[-2].Size = *(_QWORD *)&builder->Param.ShadowOffsetY;
  v12 = builder->Data.Size;
  v8[1].Data = (char *)v12;
  v13 = (v12 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,74>,Scaleform::ArrayDefaultPolicy>::Resize(
    v8,
    v13 + 8 * (builder->RefCntData.Size + builder->Images.Size + builder->Fonts.Size));
  if ( v3->Fonts.Size )
  {
    v4->pFonts = (Scaleform::Render::Font **)&v4->Data.Data.Data[v13];
    v14 = v3->Fonts.Size;
    v13 += 8 * v14;
    v4->FontCount = v14;
  }
  if ( v3->Images.Size )
  {
    v4->pImages = (Scaleform::Render::Image **)&v4->Data.Data.Data[v13];
    v15 = v3->Images.Size;
    v13 += 8 * v15;
    v4->ImageCount = v15;
  }
  if ( v3->RefCntData.Size )
  {
    v4->pRefCntData = (Scaleform::RefCountImpl **)&v4->Data.Data.Data[v13];
    v4->RefCntCount = v3->RefCntData.Size;
  }
  if ( v3->Data.Size )
    memmove(v4->Data.Data.Data, v3->Data.Data, v4->DataSize);
  v16 = v4->pFonts;
  if ( v16 )
    memmove(v16, v3->Fonts.Data, 8 * v4->FontCount);
  v17 = v4->pImages;
  if ( v17 )
    memmove(v17, v3->Images.Data, 8 * v4->ImageCount);
  v18 = v4->pRefCntData;
  if ( v18 )
    memmove(v18, v3->RefCntData.Data, 8 * v4->RefCntCount);
  for ( i = 0i64; i < v4->FontCount; ++i )
    _InterlockedExchangeAdd(&v4->pFonts[i]->RefCount, 1u);
  for ( j = 0i64; j < v4->ImageCount; ++j )
    ((void (*)(void))v4->pImages[j]->vfptr[1].__vecDelDtor)();
  if ( v4->RefCntCount > 0 )
  {
    do
      _InterlockedExchangeAdd(&v4->pRefCntData[v2++]->RefCount, 1u);
    while ( v2 < v4->RefCntCount );
  }
}

// File Line: 145
// RVA: 0x939360
void __fastcall Scaleform::Render::TextLayout::Builder::Builder(Scaleform::Render::TextLayout::Builder *this, Scaleform::MemoryHeap *heap)
{
  this->Param.TextParam.pFont = 0i64;
  *(_QWORD *)&this->Param.TextParam.GlyphIndex = 0i64;
  *(_DWORD *)&this->Param.TextParam.BlurY = 0x100000;
  this->Param.ShadowParam.pFont = 0i64;
  *(_QWORD *)&this->Param.ShadowParam.GlyphIndex = 0i64;
  *(_DWORD *)&this->Param.ShadowParam.BlurY = 0x100000;
  *(_QWORD *)&this->Param.ShadowColor = 0i64;
  this->Param.ShadowOffsetY = 0.0;
  *(_QWORD *)&this->Bounds.x1 = 0i64;
  *(_QWORD *)&this->Bounds.x2 = 0i64;
  *(_QWORD *)&this->ClipBox.x1 = 0i64;
  *(_QWORD *)&this->ClipBox.x2 = 0i64;
  this->Data.pHeap = heap;
  this->Data.Size = 0i64;
  this->Data.Reserved = 1024i64;
  this->Data.Data = this->Data.Static;
  this->Fonts.pHeap = heap;
  this->Fonts.Size = 0i64;
  this->Fonts.Reserved = 32i64;
  this->Fonts.Data = this->Fonts.Static;
  this->Images.pHeap = heap;
  this->Images.Size = 0i64;
  this->Images.Reserved = 32i64;
  this->Images.Data = this->Images.Static;
  this->RefCntData.pHeap = heap;
  this->RefCntData.Size = 0i64;
  this->RefCntData.Reserved = 32i64;
  this->RefCntData.Data = this->RefCntData.Static;
  this->LastFont = 0i64;
  this->LastScale = 1.0;
}

// File Line: 206
// RVA: 0x95E1A0
void __usercall Scaleform::Render::TextLayout::Builder::ChangeFont(Scaleform::Render::TextLayout::Builder *this@<rcx>, Scaleform::Render::Font *f@<rdx>, float size@<xmm2>, float a4@<xmm0>)
{
  unsigned __int64 v4; // rbx
  Scaleform::Render::Font *v5; // r14
  Scaleform::Render::TextLayout::Builder *v6; // rbp
  const char *v7; // rdi
  signed int v8; // esi
  unsigned __int64 v9; // rcx
  Scaleform::Render::Font **v10; // rax
  int v11; // [rsp+20h] [rbp-38h]
  float v12; // [rsp+24h] [rbp-34h]
  Scaleform::Render::Font *v13; // [rsp+28h] [rbp-30h]
  Scaleform::RefCountImpl *val; // [rsp+68h] [rbp+10h]

  val = (Scaleform::RefCountImpl *)&f->vfptr;
  v4 = 0i64;
  v5 = f;
  v6 = this;
  v11 = 4;
  v13 = f;
  v7 = (const char *)&v11;
  v8 = 16;
  v12 = size;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v6->Data, v7++);
    --v8;
  }
  while ( v8 );
  v6->LastFont = v5;
  ((void (__fastcall *)(Scaleform::Render::Font *))v5->vfptr[22].__vecDelDtor)(v5);
  v9 = v6->Fonts.Size;
  v6->LastScale = size / a4;
  if ( v9 )
  {
    v10 = v6->Fonts.Data;
    while ( v5 != *v10 )
    {
      ++v4;
      ++v10;
      if ( v4 >= v9 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&v6->Fonts,
      &val);
  }
}

// File Line: 221
// RVA: 0x9549C0
void __fastcall Scaleform::Render::TextLayout::Builder::AddRefCntData(Scaleform::Render::TextLayout::Builder *this, Scaleform::RefCountImpl *p)
{
  Scaleform::RefCountImpl *v2; // rsi
  Scaleform::Render::TextLayout::Builder *v3; // rbp
  char *v4; // rbx
  signed int v5; // edi
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  Scaleform::RefCountImpl **v8; // rax
  char val[2]; // [rsp+20h] [rbp-28h]
  Scaleform::RefCountImpl *v10; // [rsp+28h] [rbp-20h]
  Scaleform::RefCountImpl *v11; // [rsp+58h] [rbp+10h]

  v11 = p;
  v2 = p;
  v3 = this;
  strcpy(val, "\t");
  v10 = p;
  v4 = val;
  v5 = 16;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v3->Data, v4++);
    --v5;
  }
  while ( v5 );
  v6 = v3->RefCntData.Size;
  v7 = 0i64;
  if ( v6 )
  {
    v8 = v3->RefCntData.Data;
    while ( v2 != *v8 )
    {
      ++v7;
      ++v8;
      if ( v7 >= v6 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(&v3->RefCntData, &v11);
  }
}

// File Line: 255
// RVA: 0x954080
void __fastcall Scaleform::Render::TextLayout::Builder::AddCursor(Scaleform::Render::TextLayout::Builder *this, Scaleform::Render::Rect<float> *r, unsigned int color)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  const char *v5; // rbx
  signed int v6; // edi
  float v7; // xmm0_4
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *v8; // rsi
  float v9; // xmm1_4
  int v10; // [rsp+20h] [rbp-28h]
  unsigned int v11; // [rsp+24h] [rbp-24h]
  float v12; // [rsp+28h] [rbp-20h]
  float v13; // [rsp+2Ch] [rbp-1Ch]
  float v14; // [rsp+30h] [rbp-18h]
  float v15; // [rsp+34h] [rbp-14h]

  v3 = r->x1;
  v4 = r->y1;
  v10 = 7;
  v11 = color;
  v5 = (const char *)&v10;
  v6 = 24;
  v12 = v3;
  v7 = r->x2;
  v13 = v4;
  v8 = &this->Data;
  v9 = r->y2;
  v14 = v7;
  v15 = v9;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(v8, v5++);
    --v6;
  }
  while ( v6 );
}

// File Line: 262
// RVA: 0x954360
void __fastcall Scaleform::Render::TextLayout::Builder::AddImage(Scaleform::Render::TextLayout::Builder *this, Scaleform::Render::Image *img, float scaleX, float scaleY, float baseLine, float advance)
{
  unsigned __int64 v6; // rbx
  Scaleform::Render::Image *v7; // rbp
  Scaleform::Render::TextLayout::Builder *v8; // r15
  const char *v9; // rdi
  signed int v10; // esi
  unsigned __int64 v11; // rcx
  Scaleform::Render::Image **v12; // rax
  int v13; // [rsp+20h] [rbp-38h]
  Scaleform::Render::Image *v14; // [rsp+28h] [rbp-30h]
  float v15; // [rsp+30h] [rbp-28h]
  float v16; // [rsp+34h] [rbp-24h]
  float v17; // [rsp+38h] [rbp-20h]
  float v18; // [rsp+3Ch] [rbp-1Ch]
  Scaleform::RefCountImpl *val; // [rsp+68h] [rbp+10h]

  val = (Scaleform::RefCountImpl *)img;
  v6 = 0i64;
  v7 = img;
  v8 = this;
  v13 = 8;
  v14 = img;
  v9 = (const char *)&v13;
  v10 = 32;
  v17 = baseLine;
  v18 = advance;
  v15 = scaleX;
  v16 = scaleY;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&v8->Data, v9++);
    --v10;
  }
  while ( v10 );
  v11 = v8->Images.Size;
  if ( v11 )
  {
    v12 = v8->Images.Data;
    while ( v7 != *v12 )
    {
      ++v6;
      ++v12;
      if ( v6 >= v11 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&v8->Images,
      &val);
  }
}

