// File Line: 48
// RVA: 0x946070
void __fastcall Scaleform::Render::TextLayout::TextLayout(
        Scaleform::Render::TextLayout *this,
        Scaleform::Render::TextLayout::Builder *builder)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::TextLayout,74>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::TextLayout::`vftable;
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
  this->Data.Data.Data = 0i64;
  this->Data.Data.Size = 0i64;
  this->Data.Data.Policy.Capacity = 0i64;
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
  unsigned __int64 i; // rdi
  Scaleform::Render::Font *v3; // rcx
  unsigned __int64 j; // rdi
  Scaleform::Render::Image *v5; // rcx
  unsigned __int64 k; // rdi
  Scaleform::RefCountImpl *v7; // rcx

  for ( i = 0i64; i < this->FontCount; ++i )
  {
    v3 = this->pFonts[i];
    if ( !_InterlockedDecrement(&v3->RefCount) && v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  for ( j = 0i64; j < this->ImageCount; ++j )
  {
    v5 = this->pImages[j];
    ((void (__fastcall *)(Scaleform::Render::Image *))v5->vfptr[2].__vecDelDtor)(v5);
  }
  for ( k = 0i64; k < this->RefCntCount; ++k )
  {
    v7 = this->pRefCntData[k];
    if ( !_InterlockedDecrement(&v7->RefCount) && v7 )
      v7->vfptr->__vecDelDtor(v7, 1u);
  }
  if ( this->Data.Data.Size && (this->Data.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    if ( this->Data.Data.Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->Data.Data.Data = 0i64;
    }
    this->Data.Data.Policy.Capacity = 0i64;
  }
  this->Data.Data.Size = 0i64;
}

// File Line: 71
// RVA: 0x965B90
void __fastcall Scaleform::Render::TextLayout::Create(
        Scaleform::Render::TextLayout *this,
        Scaleform::Render::TextLayout::Builder *builder)
{
  unsigned __int64 v2; // rdi
  float y2; // xmm2_4
  float x2; // xmm1_4
  float x1; // eax
  Scaleform::ArrayLH_POD<unsigned char,74,Scaleform::ArrayDefaultPolicy> *p_Data; // rcx
  float v9; // xmm2_4
  float v10; // xmm1_4
  float y1; // xmm0_4
  unsigned __int64 Size; // rax
  unsigned __int64 v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rax
  Scaleform::Render::Font **pFonts; // rcx
  Scaleform::Render::Image **pImages; // rcx
  Scaleform::RefCountImpl **pRefCntData; // rcx
  unsigned __int64 i; // rdx
  unsigned __int64 j; // rsi
  Scaleform::Render::Image *v21; // rcx

  v2 = 0i64;
  this->pFonts = 0i64;
  this->FontCount = 0i64;
  this->pImages = 0i64;
  this->ImageCount = 0i64;
  this->pRefCntData = 0i64;
  this->RefCntCount = 0i64;
  y2 = builder->Bounds.y2;
  x2 = builder->Bounds.x2;
  x1 = builder->Bounds.x1;
  p_Data = &this->Data;
  HIDWORD(p_Data[-2].Data.Policy.Capacity) = LODWORD(builder->Bounds.y1);
  *(float *)&p_Data[-1].Data.Data = x2;
  *((float *)&p_Data[-1].Data.Data + 1) = y2;
  *(float *)&p_Data[-2].Data.Policy.Capacity = x1;
  v9 = builder->ClipBox.y2;
  v10 = builder->ClipBox.x2;
  y1 = builder->ClipBox.y1;
  *(float *)&p_Data[-1].Data.Size = builder->ClipBox.x1;
  *((float *)&p_Data[-1].Data.Size + 1) = y1;
  *(float *)&p_Data[-1].Data.Policy.Capacity = v10;
  *((float *)&p_Data[-1].Data.Policy.Capacity + 1) = v9;
  *(Scaleform::Render::TextFieldParam *)&p_Data[-4].Data.Data = builder->Param;
  Size = builder->Data.Size;
  p_Data[1].Data.Data = (char *)Size;
  v13 = (Size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,74>,Scaleform::ArrayDefaultPolicy>::Resize(
    &p_Data->Data,
    v13 + 8 * (builder->RefCntData.Size + builder->Images.Size + builder->Fonts.Size));
  if ( builder->Fonts.Size )
  {
    this->pFonts = (Scaleform::Render::Font **)&this->Data.Data.Data[v13];
    v14 = builder->Fonts.Size;
    v13 += 8 * v14;
    this->FontCount = v14;
  }
  if ( builder->Images.Size )
  {
    this->pImages = (Scaleform::Render::Image **)&this->Data.Data.Data[v13];
    v15 = builder->Images.Size;
    v13 += 8 * v15;
    this->ImageCount = v15;
  }
  if ( builder->RefCntData.Size )
  {
    this->pRefCntData = (Scaleform::RefCountImpl **)&this->Data.Data.Data[v13];
    this->RefCntCount = builder->RefCntData.Size;
  }
  if ( builder->Data.Size )
    memmove(this->Data.Data.Data, builder->Data.Data, this->DataSize);
  pFonts = this->pFonts;
  if ( pFonts )
    memmove(pFonts, builder->Fonts.Data, 8 * this->FontCount);
  pImages = this->pImages;
  if ( pImages )
    memmove(pImages, builder->Images.Data, 8 * this->ImageCount);
  pRefCntData = this->pRefCntData;
  if ( pRefCntData )
    memmove(pRefCntData, builder->RefCntData.Data, 8 * this->RefCntCount);
  for ( i = 0i64; i < this->FontCount; ++i )
    _InterlockedExchangeAdd(&this->pFonts[i]->RefCount, 1u);
  for ( j = 0i64; j < this->ImageCount; ++j )
  {
    v21 = this->pImages[j];
    ((void (__fastcall *)(Scaleform::Render::Image *))v21->vfptr[1].__vecDelDtor)(v21);
  }
  if ( this->RefCntCount )
  {
    do
      _InterlockedExchangeAdd(&this->pRefCntData[v2++]->RefCount, 1u);
    while ( v2 < this->RefCntCount );
  }
}

// File Line: 145
// RVA: 0x939360
void __fastcall Scaleform::Render::TextLayout::Builder::Builder(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::MemoryHeap *heap)
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
void __fastcall Scaleform::Render::TextLayout::Builder::ChangeFont(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Font *f,
        float size)
{
  unsigned __int64 v3; // rbx
  const char *v6; // rdi
  int v7; // esi
  float v8; // xmm0_4
  unsigned __int64 v9; // rcx
  Scaleform::Render::Font **Data; // rax
  _DWORD v11[2]; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Render::Font *v12; // [rsp+28h] [rbp-30h]
  Scaleform::RefCountImpl *val; // [rsp+68h] [rbp+10h] BYREF

  val = f;
  v3 = 0i64;
  v11[0] = 4;
  v12 = f;
  v6 = (const char *)v11;
  v7 = 16;
  *(float *)&v11[1] = size;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, v6++);
    --v7;
  }
  while ( v7 );
  this->LastFont = f;
  v8 = ((float (__fastcall *)(Scaleform::Render::Font *))f->vfptr[22].__vecDelDtor)(f);
  v9 = this->Fonts.Size;
  this->LastScale = size / v8;
  if ( v9 )
  {
    Data = this->Fonts.Data;
    while ( f != *Data )
    {
      ++v3;
      ++Data;
      if ( v3 >= v9 )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&this->Fonts,
      &val);
  }
}

// File Line: 221
// RVA: 0x9549C0
void __fastcall Scaleform::Render::TextLayout::Builder::AddRefCntData(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::RefCountImpl *p)
{
  char *v4; // rbx
  int v5; // edi
  unsigned __int64 Size; // rdx
  unsigned __int64 v7; // rcx
  Scaleform::RefCountImpl **Data; // rax
  char val[2]; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::RefCountImpl *v10; // [rsp+28h] [rbp-20h]
  Scaleform::RefCountImpl *v11; // [rsp+58h] [rbp+10h] BYREF

  v11 = p;
  strcpy(val, "\t");
  v10 = p;
  v4 = val;
  v5 = 16;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, v4++);
    --v5;
  }
  while ( v5 );
  Size = this->RefCntData.Size;
  v7 = 0i64;
  if ( Size )
  {
    Data = this->RefCntData.Data;
    while ( p != *Data )
    {
      ++v7;
      ++Data;
      if ( v7 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(&this->RefCntData, &v11);
  }
}

// File Line: 255
// RVA: 0x954080
void __fastcall Scaleform::Render::TextLayout::Builder::AddCursor(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::Render::Rect<float> *r,
        unsigned int color)
{
  float x1; // xmm0_4
  float y1; // xmm1_4
  const char *v5; // rbx
  int v6; // edi
  float x2; // xmm0_4
  Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2> *p_Data; // rsi
  float y2; // xmm1_4
  _DWORD v10[10]; // [rsp+20h] [rbp-28h] BYREF

  x1 = r->x1;
  y1 = r->y1;
  v10[0] = 7;
  v10[1] = color;
  v5 = (const char *)v10;
  v6 = 24;
  *(float *)&v10[2] = x1;
  x2 = r->x2;
  *(float *)&v10[3] = y1;
  p_Data = &this->Data;
  y2 = r->y2;
  *(float *)&v10[4] = x2;
  *(float *)&v10[5] = y2;
  do
  {
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(p_Data, v5++);
    --v6;
  }
  while ( v6 );
}

// File Line: 262
// RVA: 0x954360
void __fastcall Scaleform::Render::TextLayout::Builder::AddImage(
        Scaleform::Render::TextLayout::Builder *this,
        Scaleform::RefCountImpl *img,
        float scaleX,
        float scaleY,
        float baseLine,
        float advance)
{
  unsigned __int64 v6; // rbx
  const char *v9; // rdi
  int v10; // esi
  unsigned __int64 Size; // rcx
  Scaleform::Render::Image **Data; // rax
  int v13; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::RefCountImpl *v14; // [rsp+28h] [rbp-30h]
  float v15; // [rsp+30h] [rbp-28h]
  float v16; // [rsp+34h] [rbp-24h]
  float v17; // [rsp+38h] [rbp-20h]
  float v18; // [rsp+3Ch] [rbp-1Ch]
  Scaleform::RefCountImpl *val; // [rsp+68h] [rbp+10h] BYREF

  val = img;
  v6 = 0i64;
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
    Scaleform::ArrayStaticBuffPOD<unsigned char,1024,2>::PushBack(&this->Data, v9++);
    --v10;
  }
  while ( v10 );
  Size = this->Images.Size;
  if ( Size )
  {
    Data = this->Images.Data;
    while ( img != (Scaleform::RefCountImpl *)*Data )
    {
      ++v6;
      ++Data;
      if ( v6 >= Size )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Font *,32,2>::PushBack(
      (Scaleform::ArrayStaticBuffPOD<Scaleform::RefCountImpl *,32,2> *)&this->Images,
      &val);
  }
}

