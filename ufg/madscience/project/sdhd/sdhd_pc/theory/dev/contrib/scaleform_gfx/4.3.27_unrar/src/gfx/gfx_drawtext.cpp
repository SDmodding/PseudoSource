// File Line: 50
// RVA: 0x895ED0
void __fastcall Scaleform::GFx::DrawTextManagerImpl::DrawTextManagerImpl(Scaleform::GFx::DrawTextManagerImpl *this)
{
  Scaleform::GFx::DrawTextManagerImpl *v1; // rbx

  v1 = this;
  this->pRootNode.pObject = 0i64;
  this->pStateBag.pObject = 0i64;
  this->pMovieDef.pObject = 0i64;
  this->pTextAllocator.pObject = 0i64;
  this->pFontManager.pObject = 0i64;
  this->pFontStates.pObject = 0i64;
  this->pWeakLib.pObject = 0i64;
  Scaleform::GFx::DrawTextManager::TextParams::TextParams(&this->DefaultTextParams);
  v1->pLoaderImpl.pObject = 0i64;
  v1->RTFlags = 0;
  Scaleform::Render::ContextImpl::Context::Context(&v1->RenderContext, Scaleform::Memory::pGlobalHeap);
  v1->DispHandle.pData.pObject = 0i64;
}

// File Line: 53
// RVA: 0x8A4050
void __fastcall Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(Scaleform::GFx::DrawTextManagerImpl *this)
{
  Scaleform::GFx::DrawTextManagerImpl *v1; // rdi
  Scaleform::Render::ContextImpl::RTHandle *v2; // rsi
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::ContextImpl::Entry *v4; // rcx
  bool v5; // zf
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::MovieDef *v11; // rsi
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::Render::ContextImpl::Entry *v14; // rcx

  v1 = this;
  v2 = (Scaleform::Render::ContextImpl::RTHandle *)&this->DispHandle.pData;
  v3 = (Scaleform::Render::RenderBuffer *)this->DispHandle.pData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v2->pData.pObject = 0i64;
  v4 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRootNode.pObject->0;
  if ( v1->pRootNode.pObject )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  v1->pRootNode.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Shutdown(&v1->RenderContext, 1);
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(v2);
  Scaleform::Render::ContextImpl::Context::~Context(&v1->RenderContext);
  v6 = (Scaleform::Render::RenderBuffer *)v1->pLoaderImpl.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->DefaultTextParams.FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v7 = (Scaleform::Render::RenderBuffer *)v1->pWeakLib.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = (Scaleform::RefCountNTSImpl *)&v1->pFontStates.pObject->vfptr;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v9 = (Scaleform::Render::RenderBuffer *)v1->pFontManager.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = (Scaleform::RefCountNTSImpl *)&v1->pTextAllocator.pObject->vfptr;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v11 = v1->pMovieDef.pObject;
  if ( v11 && !_InterlockedDecrement(&v11->RefCount.Value) )
  {
    v12 = v11->pLib;
    if ( v12 )
    {
      v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)v11);
      v11->pLib = 0i64;
    }
    v11->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v11->vfptr, 1u);
  }
  v13 = (Scaleform::Render::RenderBuffer *)v1->pStateBag.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v14 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRootNode.pObject->0;
  if ( v1->pRootNode.pObject )
  {
    v5 = v14->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v14);
  }
}

// File Line: 92
// RVA: 0x90C980
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, const char *putf8Str, unsigned __int64 lengthInBytes)
{
  Scaleform::GFx::DrawTextImpl *v3; // rsi
  unsigned __int64 v4; // rbx
  const char *v5; // rdi

  v3 = this;
  v4 = lengthInBytes;
  v5 = putf8Str;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(v3->pTextNode.pObject, v5, v4);
}

// File Line: 97
// RVA: 0x90C9C0
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, const wchar_t *pstr, unsigned __int64 lengthInChars)
{
  Scaleform::GFx::DrawTextImpl *v3; // rsi
  unsigned __int64 v4; // rbx
  const wchar_t *v5; // rdi

  v3 = this;
  v4 = lengthInChars;
  v5 = pstr;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(v3->pTextNode.pObject, v5, v4);
}

// File Line: 102
// RVA: 0x90C930
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *str)
{
  Scaleform::GFx::DrawTextImpl *v2; // rdi
  Scaleform::String *v3; // rbx

  v2 = this;
  v3 = str;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(
    v2->pTextNode.pObject,
    (const char *)((v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
}

// File Line: 107
// RVA: 0x8DE820
Scaleform::String *__fastcall Scaleform::GFx::DrawTextImpl::GetText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  Scaleform::Render::TreeText::GetText(this->pTextNode.pObject, result);
  return v2;
}

// File Line: 112
// RVA: 0x907EC0
void __fastcall Scaleform::GFx::DrawTextImpl::SetHtmlText(Scaleform::GFx::DrawTextImpl *this, const char *putf8Str, unsigned __int64 lengthInBytes)
{
  unsigned __int64 v3; // rbx
  const char *v4; // rdi
  Scaleform::GFx::DrawTextImpl *v5; // rsi
  Scaleform::MemoryHeap *v6; // r9
  Scaleform::GFx::DrawTextManager *v7; // rbx
  Scaleform::Render::Text::DocView *v8; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h]

  v3 = lengthInBytes;
  v4 = putf8Str;
  v5 = this;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  v6 = v5->pDrawTextCtxt.pObject->pHeap;
  pimgInfoArr.Data.Data = 0i64;
  *(_OWORD *)&pimgInfoArr.Data.Size = 0ui64;
  pimgInfoArr.Data.pHeap = v6;
  Scaleform::Render::TreeText::SetHtmlText(v5->pTextNode.pObject, v4, v3, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v7 = v5->pDrawTextCtxt.pObject;
    v8 = Scaleform::Render::TreeText::GetDocView(v5->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(v8, v7, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}

// File Line: 122
// RVA: 0x907F90
void __fastcall Scaleform::GFx::DrawTextImpl::SetHtmlText(Scaleform::GFx::DrawTextImpl *this, const wchar_t *pstr, unsigned __int64 lengthInChars)
{
  unsigned __int64 v3; // rbx
  const wchar_t *v4; // rdi
  Scaleform::GFx::DrawTextImpl *v5; // rsi
  Scaleform::MemoryHeap *v6; // r9
  Scaleform::GFx::DrawTextManager *v7; // rbx
  Scaleform::Render::Text::DocView *v8; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h]

  v3 = lengthInChars;
  v4 = pstr;
  v5 = this;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  v6 = v5->pDrawTextCtxt.pObject->pHeap;
  pimgInfoArr.Data.Data = 0i64;
  *(_OWORD *)&pimgInfoArr.Data.Size = 0ui64;
  pimgInfoArr.Data.pHeap = v6;
  Scaleform::Render::TreeText::SetHtmlText(v5->pTextNode.pObject, v4, v3, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v7 = v5->pDrawTextCtxt.pObject;
    v8 = Scaleform::Render::TreeText::GetDocView(v5->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(v8, v7, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}

// File Line: 132
// RVA: 0x907DD0
void __fastcall Scaleform::GFx::DrawTextImpl::SetHtmlText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *str)
{
  Scaleform::String *v2; // rsi
  Scaleform::GFx::DrawTextImpl *v3; // rbp
  Scaleform::MemoryHeap *v4; // r8
  unsigned __int64 v5; // rbx
  Scaleform::Render::TreeText *v6; // rdi
  unsigned __int64 v7; // rax
  Scaleform::GFx::DrawTextManager *v8; // rbx
  Scaleform::Render::Text::DocView *v9; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h]

  v2 = str;
  v3 = this;
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  v4 = v3->pDrawTextCtxt.pObject->pHeap;
  pimgInfoArr.Data.Data = 0i64;
  *(_OWORD *)&pimgInfoArr.Data.Size = 0ui64;
  pimgInfoArr.Data.pHeap = v4;
  v5 = v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v6 = v3->pTextNode.pObject;
  v7 = Scaleform::String::GetLength(v2);
  Scaleform::Render::TreeText::SetHtmlText(v6, (const char *)(v5 + 12), v7, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v8 = v3->pDrawTextCtxt.pObject;
    v9 = Scaleform::Render::TreeText::GetDocView(v3->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(v9, v8, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}

// File Line: 142
// RVA: 0x8D9C10
Scaleform::String *__fastcall Scaleform::GFx::DrawTextImpl::GetHtmlText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rbx

  v2 = result;
  Scaleform::Render::TreeText::GetHtmlText(this->pTextNode.pObject, result);
  return v2;
}

// File Line: 147
// RVA: 0x90AD10
void __fastcall Scaleform::GFx::DrawTextImpl::SetRect(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Rect<float> *viewRect)
{
  Scaleform::Render::TreeText *v2; // rcx
  float v3; // xmm1_4
  float v4; // xmm0_4
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-18h]

  v2 = this->pTextNode.pObject;
  v3 = viewRect->x2 * 20.0;
  r.x1 = viewRect->x1 * 20.0;
  v4 = viewRect->y1;
  r.x2 = v3;
  r.y1 = v4 * 20.0;
  r.y2 = viewRect->y2 * 20.0;
  Scaleform::Render::TreeText::SetBounds(v2, &r);
}

// File Line: 151
// RVA: 0x8DCEA0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DrawTextImpl::GetRect(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::Render::Rect<float> *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4
  Scaleform::Render::Rect<float> *v7; // rax
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = Scaleform::Render::TreeText::GetBounds(this->pTextNode.pObject, &resulta);
  v4 = v3->x2 * 0.050000001;
  v2->x1 = v3->x1 * 0.050000001;
  v5 = v3->y1;
  v2->x2 = v4;
  v2->y1 = v5 * 0.050000001;
  v6 = v3->y2;
  v7 = v2;
  v2->y2 = v6 * 0.050000001;
  return v7;
}

// File Line: 156
// RVA: 0x909610
void __fastcall Scaleform::GFx::DrawTextImpl::SetMatrix(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Matrix2x4<float> *matrix)
{
  float v2; // xmm1_4
  Scaleform::Render::TreeText *v3; // rcx
  float v4; // xmm3_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // [rsp+20h] [rbp-28h]
  float v11; // [rsp+24h] [rbp-24h]
  float v12; // [rsp+28h] [rbp-20h]
  float v13; // [rsp+2Ch] [rbp-1Ch]
  float v14; // [rsp+30h] [rbp-18h]
  float v15; // [rsp+34h] [rbp-14h]
  float v16; // [rsp+38h] [rbp-10h]
  float v17; // [rsp+3Ch] [rbp-Ch]

  v2 = matrix->M[0][1];
  v3 = this->pTextNode.pObject;
  v4 = matrix->M[0][3] * 20.0;
  v5 = matrix->M[1][3];
  v10 = matrix->M[0][0];
  v6 = matrix->M[0][2];
  v11 = v2;
  v7 = matrix->M[1][0];
  v12 = v6;
  v8 = matrix->M[1][1];
  v14 = v7;
  v9 = matrix->M[1][2];
  v15 = v8;
  v16 = v9;
  v13 = v4;
  v17 = v5 * 20.0;
  Scaleform::Render::TreeNode::SetMatrix(
    (Scaleform::Render::TreeNode *)&v3->0,
    (Scaleform::Render::Matrix2x4<float> *)&v10);
}

// File Line: 163
// RVA: 0x8DAF20
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DrawTextImpl::GetMatrix(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Matrix2x4<float> *result)
{
  Scaleform::Render::Matrix2x4<float> *v2; // r10
  signed __int64 v3; // r8
  float *v4; // rdx
  float v5; // xmm0_4
  float v6; // eax
  float v7; // xmm0_4
  float v8; // eax

  v2 = result;
  v3 = (signed __int64)&this->pTextNode.pObject[-1] - ((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64);
  v4 = *(float **)(*(_QWORD *)(((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)(v3 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v5 = v4[7];
  v2->M[0][0] = v4[4];
  v2->M[0][1] = v4[5];
  v6 = v4[6];
  v2->M[0][3] = v5 * 0.050000001;
  v7 = v4[11];
  v2->M[0][2] = v6;
  v8 = v4[8];
  v2->M[1][3] = v7 * 0.050000001;
  v2->M[1][0] = v8;
  v2->M[1][1] = v4[9];
  v2->M[1][2] = v4[10];
  return v2;
}

// File Line: 171
// RVA: 0x906C50
void __fastcall Scaleform::GFx::DrawTextImpl::SetCxform(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::Cxform *v2; // rbx
  Scaleform::Render::ContextImpl::EntryData *v3; // rax

  v2 = cx;
  v3 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->pTextNode.pObject->0,
         2u);
  v3[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v2->M[0][0];
  v3[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v2->M[1][0];
}

// File Line: 175
// RVA: 0x8D6790
Scaleform::Render::Cxform *__fastcall Scaleform::GFx::DrawTextImpl::GetCxform(Scaleform::GFx::DrawTextImpl *this)
{
  return (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64)
                                                             + 0x20)
                                                 + 8
                                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pTextNode.pObject[-1] - ((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pTextNode.pObject[-1] - ((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                 + 40)
                                     + 80i64);
}

// File Line: 180
// RVA: 0x906A40
void __fastcall Scaleform::GFx::DrawTextImpl::SetColor(Scaleform::GFx::DrawTextImpl *this, __int64 c, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText *v4; // rcx
  Scaleform::Render::Color ca; // [rsp+30h] [rbp+8h]

  v4 = this->pTextNode.pObject;
  ca = *(Scaleform::Render::Color *)c;
  Scaleform::Render::TreeText::SetColor(v4, (Scaleform::Render::Color)&ca, startPos, endPos);
}

// File Line: 184
// RVA: 0x907620
void __fastcall Scaleform::GFx::DrawTextImpl::SetFont(Scaleform::GFx::DrawTextImpl *this, const char *pfontName, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFont(this->pTextNode.pObject, pfontName, startPos, endPos);
}

// File Line: 188
// RVA: 0x907630
void __fastcall Scaleform::GFx::DrawTextImpl::SetFontSize(Scaleform::GFx::DrawTextImpl *this, float fontSize, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFontSize(this->pTextNode.pObject, fontSize, startPos, endPos);
}

// File Line: 192
// RVA: 0x908620
void __fastcall Scaleform::GFx::DrawTextImpl::SetLetterSpacing(Scaleform::GFx::DrawTextImpl *this, float letterSpacing, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetLetterSpacing(this->pTextNode.pObject, letterSpacing, startPos, endPos);
}

// File Line: 197
// RVA: 0x907640
void __fastcall Scaleform::GFx::DrawTextImpl::SetFontStyle(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawText::FontStyle fontStyle, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFontStyle(this->pTextNode.pObject, fontStyle, startPos, endPos);
}

// File Line: 201
// RVA: 0x90E7D0
void __fastcall Scaleform::GFx::DrawTextImpl::SetUnderline(Scaleform::GFx::DrawTextImpl *this, bool underline, unsigned __int64 startPos, unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetUnderline(this->pTextNode.pObject, underline, startPos, endPos);
}

// File Line: 205
// RVA: 0x909A00
void __fastcall Scaleform::GFx::DrawTextImpl::SetMultiline(Scaleform::GFx::DrawTextImpl *this, bool multiline)
{
  Scaleform::Render::TreeText::SetMultiline(this->pTextNode.pObject, multiline);
}

// File Line: 209
// RVA: 0x8E7450
bool __fastcall Scaleform::GFx::DrawTextImpl::IsMultiline(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::IsMultiline(this->pTextNode.pObject);
}

// File Line: 215
// RVA: 0x90F750
void __fastcall Scaleform::GFx::DrawTextImpl::SetWordWrap(Scaleform::GFx::DrawTextImpl *this, bool wordWrap)
{
  Scaleform::Render::TreeText::SetWordWrap(this->pTextNode.pObject, wordWrap);
}

// File Line: 220
// RVA: 0x8E7EC0
bool __fastcall Scaleform::GFx::DrawTextImpl::IsWordWrap(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::IsWordWrap(this->pTextNode.pObject);
}

// File Line: 225
// RVA: 0x9061B0
void __fastcall Scaleform::GFx::DrawTextImpl::SetAlignment(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawText::Alignment a)
{
  Scaleform::Render::TreeText::SetAlignment(this->pTextNode.pObject, a);
}

// File Line: 229
// RVA: 0x8D4CC0
Scaleform::GFx::DrawText::Alignment __fastcall Scaleform::GFx::DrawTextImpl::GetAlignment(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetAlignment(this->pTextNode.pObject);
}

// File Line: 234
// RVA: 0x90E8A0
void __fastcall Scaleform::GFx::DrawTextImpl::SetVAlignment(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawText::VAlignment a)
{
  Scaleform::Render::TreeText::SetVAlignment(this->pTextNode.pObject, a);
}

// File Line: 238
// RVA: 0x8E12B0
Scaleform::GFx::DrawText::VAlignment __fastcall Scaleform::GFx::DrawTextImpl::GetVAlignment(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetVAlignment(this->pTextNode.pObject);
}

// File Line: 243
// RVA: 0x9067B0
void __fastcall Scaleform::GFx::DrawTextImpl::SetBorderColor(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Color *borderColor)
{
  Scaleform::Render::TreeText::SetBorderColor(this->pTextNode.pObject, borderColor);
}

// File Line: 246
// RVA: 0x8D4E20
Scaleform::Render::Color *__fastcall Scaleform::GFx::DrawTextImpl::GetBorderColor(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rbx

  v2 = result;
  Scaleform::Render::TreeText::GetBorderColor(this->pTextNode.pObject, result);
  return v2;
}

// File Line: 249
// RVA: 0x906350
void __fastcall Scaleform::GFx::DrawTextImpl::SetBackgroundColor(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this->pTextNode.pObject, bkgColor);
}

// File Line: 252
// RVA: 0x8D4D60
Scaleform::Render::Color *__fastcall Scaleform::GFx::DrawTextImpl::GetBackgroundColor(Scaleform::GFx::DrawTextImpl *this, Scaleform::Render::Color *result)
{
  Scaleform::Render::Color *v2; // rbx

  v2 = result;
  Scaleform::Render::TreeText::GetBackgroundColor(this->pTextNode.pObject, result);
  return v2;
}

// File Line: 296
// RVA: 0x906000
void __fastcall Scaleform::GFx::DrawTextImpl::SetAAMode(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawText::AAMode aa)
{
  Scaleform::Render::TreeText::SetAAMode(this->pTextNode.pObject, aa);
}

// File Line: 301
// RVA: 0x8D4920
Scaleform::GFx::DrawText::AAMode __fastcall Scaleform::GFx::DrawTextImpl::GetAAMode(Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetAAMode(this->pTextNode.pObject);
}

// File Line: 308
// RVA: 0x907180
void __fastcall Scaleform::GFx::DrawTextImpl::SetFilters(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawText::Filter *filters, unsigned __int64 filtersCnt)
{
  Scaleform::Render::TreeText::SetFilters(
    this->pTextNode.pObject,
    (Scaleform::Render::TreeText::Filter *)&filters->Type,
    filtersCnt);
}

// File Line: 314
// RVA: 0x8BC360
void __fastcall Scaleform::GFx::DrawTextImpl::ClearFilters(Scaleform::GFx::DrawTextImpl *this)
{
  Scaleform::Render::TreeText::ClearFilters(this->pTextNode.pObject);
}

// File Line: 319
// RVA: 0x906DF0
void __fastcall Scaleform::GFx::DrawTextImpl::SetDepth(Scaleform::GFx::DrawTextImpl *this, unsigned int newDepth)
{
  unsigned __int64 v2; // rbx
  Scaleform::GFx::DrawTextImpl *v3; // rsi
  unsigned __int64 v4; // rbp
  Scaleform::Render::TreeRoot *v5; // rdi
  __int64 v6; // rdx
  unsigned __int64 v7; // rcx

  v2 = newDepth;
  v3 = this;
  v4 = ((unsigned int (*)(void))this->vfptr[38].__vecDelDtor)();
  v5 = v3->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  v6 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                                                                                       - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                                                                           - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v7 = *(_QWORD *)(v6 + 144);
  if ( v7 )
  {
    if ( v7 & 1 )
      v7 = *(_QWORD *)((v7 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      v7 = (*(_QWORD *)(v6 + 152) != 0i64) + 1i64;
  }
  if ( v2 > v7 )
    LODWORD(v2) = Scaleform::Render::TreeContainer::GetSize((Scaleform::Render::TreeContainer *)v3->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject);
  Scaleform::Render::TreeContainer::Remove((Scaleform::Render::TreeContainer *)&v5->0, v4, 1ui64);
  Scaleform::Render::TreeContainer::Insert(
    (Scaleform::Render::TreeContainer *)v3->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject,
    (unsigned int)v2,
    (Scaleform::Render::TreeNode *)&v3->pTextNode.pObject->0);
}

// File Line: 328
// RVA: 0x8D6900
signed __int64 __fastcall Scaleform::GFx::DrawTextImpl::GetDepth(Scaleform::GFx::DrawTextImpl *this)
{
  Scaleform::GFx::DrawTextImpl *v1; // r11
  Scaleform::Render::TreeRoot *v2; // r10
  __int64 v3; // rax
  __int64 v4; // r8
  unsigned __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // r9
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rdx
  __int64 v10; // r10
  unsigned __int64 v11; // rdx
  _QWORD *v12; // rax

  v1 = this;
  v2 = this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  v3 = *(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v4 = 0i64;
  v5 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                                                                          - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                                                              - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63);
  v6 = *(_QWORD *)(v3 + 8 * v5 + 40);
  v7 = *(_QWORD *)(v6 + 144);
  if ( v7 )
  {
    if ( *(_BYTE *)(v6 + 144) & 1 )
      v8 = *(_QWORD *)((v7 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      v8 = (*(_QWORD *)(*(_QWORD *)(v3 + 8 * v5 + 40) + 152i64) != 0i64) + 1i64;
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 )
    return 0xFFFFFFFFi64;
  v9 = (unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                         * (signed __int128)5270498306774157605i64) >> 64;
  v10 = *(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v11 = (v9 >> 63) + ((signed __int64)v9 >> 4);
  while ( 1 )
  {
    v12 = (_QWORD *)(*(_QWORD *)(v10 + 8i64 * (unsigned int)v11 + 40) + 144i64);
    if ( *(_BYTE *)v12 & 1 )
      v12 = (_QWORD *)((*v12 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    if ( (Scaleform::Render::TreeText *)v12[v4] == v1->pTextNode.pObject )
      break;
    if ( ++v4 >= v8 )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v4;
}

// File Line: 341
// RVA: 0x90F140
void __fastcall Scaleform::GFx::DrawTextImpl::SetVisible(Scaleform::GFx::DrawTextImpl *this, bool visible)
{
  Scaleform::Render::TreeNode::SetVisible((Scaleform::Render::TreeNode *)&this->pTextNode.pObject->0, visible);
}

// File Line: 346
// RVA: 0x8E7E30
__int64 __fastcall Scaleform::GFx::DrawTextImpl::IsVisible(Scaleform::GFx::DrawTextImpl *this)
{
  return *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pTextNode.pObject[-1] - ((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this->pTextNode.pObject[-1]
                                                                                        - ((_QWORD)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40)
                  + 10i64) & 1;
}

// File Line: 360
// RVA: 0x895740
void __fastcall Scaleform::GFx::DrawTextImpl::DrawTextImpl(Scaleform::GFx::DrawTextImpl *this, Scaleform::GFx::DrawTextManager *pdtMgr)
{
  Scaleform::GFx::DrawTextManager *v2; // rdi
  Scaleform::GFx::DrawTextImpl *v3; // rbx
  Scaleform::GFx::DrawTextManagerImpl *v4; // rsi
  Scaleform::Log *v5; // rax
  Scaleform::Render::ContextImpl::EntryData *v6; // rdi
  Scaleform::Render::ContextImpl::Entry *v7; // rdi
  Scaleform::Render::ContextImpl::Entry *v8; // rcx
  bool v9; // zf
  Scaleform::Ptr<Scaleform::Log> *v10; // rax
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+58h] [rbp+10h]
  Scaleform::Log *v12; // [rsp+60h] [rbp+18h]

  v2 = pdtMgr;
  v3 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,325>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawText,325>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawText::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextImpl::`vftable;
  if ( pdtMgr )
    ++pdtMgr->RefCount;
  this->pDrawTextCtxt.pObject = pdtMgr;
  this->pTextNode.pObject = 0i64;
  this->pHeap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v4 = v2->pImpl;
  v5 = (Scaleform::Log *)v4->RenderContext.pHeap->vfptr->Alloc(v4->RenderContext.pHeap, 176ui64, 0i64);
  v6 = (Scaleform::Render::ContextImpl::EntryData *)v5;
  result.pObject = v5;
  v12 = v5;
  if ( v5 )
    Scaleform::Render::TreeText::NodeData::NodeData((Scaleform::Render::TreeText::NodeData *)v5);
  v7 = Scaleform::Render::ContextImpl::Context::createEntryHelper(&v4->RenderContext, v6);
  v8 = (Scaleform::Render::ContextImpl::Entry *)&v3->pTextNode.pObject->0;
  if ( v8 )
  {
    v9 = v8->RefCount-- == 1;
    if ( v9 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
  }
  v3->pTextNode.pObject = (Scaleform::Render::TreeText *)v7;
  v10 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v3->pDrawTextCtxt.pObject->vfptr, &result);
  Scaleform::Render::TreeText::Init(
    v3->pTextNode.pObject,
    v3->pDrawTextCtxt.pObject->pImpl->pTextAllocator.pObject,
    (Scaleform::Render::Text::FontManagerBase *)&v3->pDrawTextCtxt.pObject->pImpl->pFontManager.pObject->vfptr,
    v10->pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 368
// RVA: 0x8A3F50
void __fastcall Scaleform::GFx::DrawTextImpl::~DrawTextImpl(Scaleform::GFx::DrawTextImpl *this)
{
  Scaleform::GFx::DrawTextImpl *v1; // rbx
  unsigned int v2; // eax
  Scaleform::Render::ContextImpl::Entry *v3; // rcx
  bool v4; // zf
  Scaleform::RefCountNTSImpl *v5; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextImpl::`vftable;
  v2 = Scaleform::GFx::DrawTextImpl::GetDepth(this);
  if ( v2 != -1 )
    Scaleform::Render::TreeContainer::Remove(
      (Scaleform::Render::TreeContainer *)v1->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject,
      v2,
      1ui64);
  v3 = (Scaleform::Render::ContextImpl::Entry *)&v1->pTextNode.pObject->0;
  if ( v3 )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
  v5 = (Scaleform::RefCountNTSImpl *)&v1->pDrawTextCtxt.pObject->vfptr;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  v1->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawText::`vftable;
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->vfptr);
}

// File Line: 378
// RVA: 0x8F20E0
void __fastcall Scaleform::GFx::DrawTextImpl::ProcessImageTags(Scaleform::Render::Text::DocView *ptextDocView, Scaleform::GFx::DrawTextManager *pmgr, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v3; // r14
  unsigned __int64 v4; // rdi
  Scaleform::GFx::FileOpenerBase *v5; // rax
  Scaleform::GFx::StateBag *v6; // r15
  Scaleform::GFx::ImageCreator *v7; // rbx
  Scaleform::GFx::Resource **v8; // rbx
  unsigned __int64 v9; // rsi
  __int64 v10; // r13
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v11; // r12
  Scaleform::String *v12; // r14
  char v13; // al
  __int64 v14; // rbx
  Scaleform::Log *v15; // rbx
  Scaleform::Ptr<Scaleform::Log> *v16; // rax
  Scaleform::GFx::Resource *v17; // rbx
  Scaleform::GFx::ResourceLibBase *v18; // rcx
  Scaleform::Log *v19; // rbx
  Scaleform::Ptr<Scaleform::Log> *v20; // rax
  Scaleform::GFx::Resource *v21; // rbx
  Scaleform::GFx::ResourceLibBase *v22; // rcx
  Scaleform::GFx::Resource *v23; // rbx
  Scaleform::Log *v24; // rbx
  Scaleform::Ptr<Scaleform::Log> *v25; // rax
  Scaleform::GFx::Resource *v26; // rbx
  Scaleform::GFx::ResourceLibBase *v27; // rcx
  Scaleform::GFx::ResourceVtbl *v28; // rsi
  __int64 v29; // rax
  Scaleform::GFx::ResourceLibBase *v30; // rcx
  __int64 v31; // rax
  Scaleform::GFx::StateBag *v32; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *v33; // rsi
  Scaleform::GFx::StateBag *v34; // rax
  __int64 *v35; // rbx
  Scaleform::Ptr<Scaleform::Log> *v36; // rax
  __int64 v37; // rdx
  __int64 v38; // rax
  unsigned __int64 v39; // r8
  Scaleform::GFx::Resource *v40; // rbx
  Scaleform::GFx::ResourceLibBase *v41; // rcx
  Scaleform::Render::Text::ImageDesc *v42; // rsi
  Scaleform::Render::Image *v43; // rcx
  float v44; // xmm5_4
  float v45; // xmm4_4
  int v46; // eax
  float v47; // xmm3_4
  int v48; // eax
  float v49; // xmm2_4
  float v50; // xmm0_4
  float *v51; // rax
  float v52; // xmm2_4
  float v53; // xmm3_4
  Scaleform::GFx::Resource *v54; // rbx
  Scaleform::GFx::ResourceLibBase *v55; // rcx
  Scaleform::GFx::ResourceLibBase *v56; // rcx
  Scaleform::GFx::Resource *v57; // rbx
  Scaleform::GFx::ResourceLibBase *v58; // rcx
  unsigned __int64 v59; // [rsp+20h] [rbp-A0h]
  __int64 v60; // [rsp+28h] [rbp-98h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+30h] [rbp-90h]
  Scaleform::Render::RenderBuffer *v62; // [rsp+40h] [rbp-80h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+48h] [rbp-78h]
  Scaleform::Ptr<Scaleform::Log> v64; // [rsp+50h] [rbp-70h]
  Scaleform::Ptr<Scaleform::Log> v65; // [rsp+58h] [rbp-68h]
  Scaleform::Ptr<Scaleform::Log> v66; // [rsp+60h] [rbp-60h]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v67; // [rsp+68h] [rbp-58h]
  Scaleform::Ptr<Scaleform::Log> v68; // [rsp+70h] [rbp-50h]
  Scaleform::Ptr<Scaleform::Log> v69; // [rsp+78h] [rbp-48h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v70; // [rsp+80h] [rbp-40h]
  int v71; // [rsp+88h] [rbp-38h]
  __int64 v72; // [rsp+90h] [rbp-30h]
  int v73; // [rsp+98h] [rbp-28h]
  int v74; // [rsp+9Ch] [rbp-24h]
  __int64 v75; // [rsp+A0h] [rbp-20h]
  __int64 v76; // [rsp+A8h] [rbp-18h]
  __int64 v77; // [rsp+B0h] [rbp-10h]
  __int64 v78; // [rsp+B8h] [rbp-8h]
  int v79; // [rsp+C0h] [rbp+0h]
  __int64 v80; // [rsp+C8h] [rbp+8h]
  int v81; // [rsp+D0h] [rbp+10h]
  int v82; // [rsp+D4h] [rbp+14h]
  __int64 v83; // [rsp+D8h] [rbp+18h]
  __int64 v84; // [rsp+E0h] [rbp+20h]
  __int64 v85; // [rsp+E8h] [rbp+28h]
  __int64 v86; // [rsp+F0h] [rbp+30h]
  __int64 v87; // [rsp+F8h] [rbp+38h]
  Scaleform::GFx::Resource *v88; // [rsp+100h] [rbp+40h]
  __int64 v89; // [rsp+190h] [rbp+D0h]
  __int64 v90; // [rsp+198h] [rbp+D8h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v91; // [rsp+1A0h] [rbp+E0h]
  Scaleform::LogMessageId id; // [rsp+1A8h] [rbp+E8h]

  v87 = -2i64;
  v3 = imageInfoArray;
  v4 = imageInfoArray->Data.Size;
  v62 = 0i64;
  v5 = 0i64;
  if ( pmgr->pImpl->pMovieDef.pObject )
    v5 = (Scaleform::GFx::FileOpenerBase *)pmgr->pImpl->pMovieDef.pObject;
  v67.pObject = v5;
  v6 = (Scaleform::GFx::StateBag *)&pmgr->vfptr;
  v7 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&pmgr->vfptr, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v7 )
  {
    v8 = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetImageCreator(v6, &v70);
    if ( *v8 )
      Scaleform::Render::RenderBuffer::AddRef(*v8);
    v62 = (Scaleform::Render::RenderBuffer *)*v8;
    if ( v70.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v70.pObject);
  }
  v9 = 0i64;
  v59 = 0i64;
  if ( !v4 )
    goto LABEL_101;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v3->Data.Data;
    v12 = (Scaleform::String *)&v3->Data.Data[v10].Url.0;
    v13 = Scaleform::GFx::LoaderImpl::IsProtocolImage(v12, 0i64, 0i64);
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    v14 = 0i64;
    if ( v13 )
    {
      v31 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v90 + 24) + 48i64) + 72i64);
      v71 = 1;
      v72 = v31;
      v73 = 0;
      v74 = 1;
      v75 = 0i64;
      v76 = 0i64;
      v77 = 0i64;
      v78 = 0i64;
      v32 = (Scaleform::GFx::StateBag *)v6->vfptr->GetStateBagImpl(v6);
      v33 = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(
              v32,
              (Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *)&v68);
      v34 = (Scaleform::GFx::StateBag *)v6->vfptr->GetStateBagImpl(v6);
      v35 = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener(v34, &v67);
      v36 = Scaleform::GFx::StateBag::GetLog(v6, &v65);
      v37 = (__int64)v33->pObject;
      v38 = (__int64)v36->pObject;
      v76 = *v35;
      v75 = v38;
      v77 = v37;
      if ( v65.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v65.pObject);
      if ( v67.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v67.pObject);
      if ( v68.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v68.pObject);
      if ( !v62 )
      {
        LODWORD(result.pObject) = 135168;
        Scaleform::LogDebugMessage(
          (Scaleform::LogMessageId)&result,
          "Image resource creation failed - ImageCreator not installed");
        goto LABEL_96;
      }
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *, int *, Scaleform::String *))v62->vfptr[1].__vecDelDtor)(
              v62,
              &v71,
              v12);
      goto LABEL_68;
    }
    if ( !v67.pObject )
    {
      v15 = Scaleform::GFx::StateBag::GetLog(v6, &v66)->pObject;
      if ( v66.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pObject);
      if ( v15 )
      {
        v16 = Scaleform::GFx::StateBag::GetLog(v6, &v69);
        Scaleform::Log::LogWarning(
          v16->pObject,
          "DrawText::ProcessImageTags: cant find a resource since there is no moviedef\n");
        if ( v69.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v69.pObject);
      }
      v17 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v18 = v17->pLib;
        if ( v18 )
        {
          v18->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, (unsigned int)v17);
          v17->pLib = 0i64;
        }
        v17->vfptr->__vecDelDtor(v17, 1u);
      }
      goto LABEL_89;
    }
    if ( !(unsigned __int8)Scaleform::GFx::MovieDefImpl::GetExportedResource(
                             (Scaleform::GFx::MovieDefImpl *)v67.pObject,
                             &pdata,
                             v12,
                             0i64) )
    {
      v19 = Scaleform::GFx::StateBag::GetLog(v6, &v69)->pObject;
      if ( v69.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v69.pObject);
      if ( v19 )
      {
        v20 = Scaleform::GFx::StateBag::GetLog(v6, &v66);
        Scaleform::Log::LogWarning(
          v20->pObject,
          "DrawText::ProcessImageTags: cant find a resource for export name %s\n",
          (v12->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        if ( v66.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pObject);
      }
      v21 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v22 = v21->pLib;
        if ( v22 )
        {
          v22->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, (unsigned int)v21);
          v21->pLib = 0i64;
        }
        v21->vfptr->__vecDelDtor(v21, 1u);
      }
      goto LABEL_89;
    }
    if ( (((__int64 (*)(void))pdata.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) != 256 )
      goto LABEL_81;
    v23 = pdata.pResource.pObject;
    if ( pdata.pResource.pObject )
      _InterlockedExchangeAdd(&pdata.pResource.pObject->RefCount.Value, 1u);
    v88 = v23;
    if ( !v23 )
    {
      v24 = Scaleform::GFx::StateBag::GetLog(v6, &v64)->pObject;
      if ( v64.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v64.pObject);
      if ( v24 )
      {
        v25 = Scaleform::GFx::StateBag::GetLog(v6, &v68);
        Scaleform::Log::LogWarning(
          v25->pObject,
          "DrawText::ProcessImageTags: cant load the image %s\n",
          (v12->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        if ( v68.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v68.pObject);
      }
      v26 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v27 = v26->pLib;
        if ( v27 )
        {
          v27->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, (unsigned int)v26);
          v26->pLib = 0i64;
        }
        v26->vfptr->__vecDelDtor(v26, 1u);
      }
      goto LABEL_89;
    }
    if ( (*((unsigned int (**)(void))v23[1].vfptr->__vecDelDtor + 3))() )
    {
      v28 = v23[1].vfptr;
      if ( v28 )
        (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v28->__vecDelDtor + 1))(v23[1].vfptr);
      v60 = (__int64)v28;
      goto LABEL_55;
    }
    if ( !v62 )
      break;
    v29 = *(_QWORD *)(v90 + 32);
    v79 = 3;
    v80 = v29;
    v81 = 1;
    v82 = 1;
    v83 = 0i64;
    v84 = 0i64;
    v85 = 0i64;
    v86 = 0i64;
    v60 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *, int *, Scaleform::GFx::ResourceVtbl *))v62->vfptr[4].__vecDelDtor)(
            v62,
            &v79,
            v23[1].vfptr);
LABEL_55:
    if ( !_InterlockedDecrement(&v23->RefCount.Value) )
    {
      v30 = v23->pLib;
      if ( v30 )
      {
        v30->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v30->vfptr, (unsigned int)v23);
        v23->pLib = 0i64;
      }
      v23->vfptr->__vecDelDtor(v23, 1u);
    }
    v14 = v60;
LABEL_68:
    if ( !v14 )
    {
      v39 = v12->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      id.Id = 135168;
      Scaleform::LogDebugMessage(
        (Scaleform::LogMessageId)&id,
        "Image %s wasnt created in ProcessImageTags",
        v39 + 12);
      v40 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v41 = v40->pLib;
        if ( v41 )
        {
          v41->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v41->vfptr, (unsigned int)v40);
          v40->pLib = 0i64;
        }
        v40->vfptr->__vecDelDtor(v40, 1u);
      }
      v9 = v59;
      goto LABEL_89;
    }
    (*(void (__fastcall **)(__int64, Scaleform::Ptr<Scaleform::Log> *))(*(_QWORD *)v14 + 48i64))(v14, &v64);
    v42 = v11[v10].pTextImageDesc.pObject;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
    v43 = v42->pImage.pObject;
    if ( v43 )
      ((void (*)(void))v43->vfptr[2].__vecDelDtor)();
    v42->pImage.pObject = (Scaleform::Render::Image *)v14;
    v44 = (float)(LODWORD(v65.pObject) - LODWORD(v64.pObject));
    v45 = (float)(HIDWORD(v65.pObject) - HIDWORD(v64.pObject));
    v46 = v11[v10].Width;
    if ( !v46 )
      v46 = 20 * (LODWORD(v65.pObject) - LODWORD(v64.pObject));
    v47 = (float)v46;
    v48 = v11[v10].Height;
    if ( !v48 )
      v48 = 20 * (HIDWORD(v65.pObject) - HIDWORD(v64.pObject));
    v49 = (float)v48;
    v50 = (float)v11[v10].VSpace;
    v11[v10].pTextImageDesc.pObject->ScreenWidth = v47;
    v11[v10].pTextImageDesc.pObject->ScreenHeight = (float)v48;
    v11[v10].pTextImageDesc.pObject->BaseLineY = (float)((float)(v45 * 20.0) + v50) * 0.050000001;
    v11[v10].pTextImageDesc.pObject->Matrix.M[1][3] = COERCE_FLOAT(LODWORD(v11[v10].pTextImageDesc.pObject->BaseLineY) ^ _xmm[0])
                                                    + v11[v10].pTextImageDesc.pObject->Matrix.M[1][3];
    v51 = (float *)v11[v10].pTextImageDesc.pObject;
    v52 = v49 / v45;
    v53 = v47 / v44;
    v51[12] = v53 * v51[12];
    v51[13] = v53 * v51[13];
    v51[14] = v53 * v51[14];
    v51[15] = v53 * v51[15];
    v51[16] = v52 * v51[16];
    v51[17] = v52 * v51[17];
    v51[18] = v52 * v51[18];
    v51[19] = v52 * v51[19];
    *(_BYTE *)(v89 + 347) |= 2u;
    v9 = v59;
LABEL_81:
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
    v54 = pdata.pResource.pObject;
    if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
    {
      v55 = v54->pLib;
      if ( v55 )
      {
        v55->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v55->vfptr, (unsigned int)v54);
        v54->pLib = 0i64;
      }
      v54->vfptr->__vecDelDtor(v54, 1u);
    }
LABEL_89:
    v59 = ++v9;
    ++v10;
    if ( v9 >= (unsigned __int64)v62 )
      goto LABEL_101;
    v3 = v91;
  }
  HIDWORD(result.pObject) = 135168;
  Scaleform::LogDebugMessage(
    (Scaleform::LogMessageId)((char *)&result.pObject + 4),
    "ImageCreator is null in DrawText::ProcessImageTags");
  if ( !_InterlockedDecrement(&v23->RefCount.Value) )
  {
    v56 = v23->pLib;
    if ( v56 )
    {
      v56->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v56->vfptr, (unsigned int)v23);
      v23->pLib = 0i64;
    }
    v23->vfptr->__vecDelDtor(v23, 1u);
  }
LABEL_96:
  v57 = pdata.pResource.pObject;
  if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
  {
    v58 = v57->pLib;
    if ( v58 )
    {
      v58->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v58->vfptr, (unsigned int)v57);
      v57->pLib = 0i64;
    }
    v57->vfptr->__vecDelDtor(v57, 1u);
  }
LABEL_101:
  if ( v62 )
    Scaleform::RefCountImpl::Release(v62);
}

// File Line: 559
// RVA: 0x895870
void __fastcall Scaleform::GFx::DrawTextManager::DrawTextManager(Scaleform::GFx::DrawTextManager *this, Scaleform::GFx::Loader *ploader)
{
  Scaleform::GFx::Loader *v2; // rsi
  Scaleform::GFx::DrawTextManager *v3; // rbx
  __int64 v4; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v5; // rax
  Scaleform::GFx::DrawTextManagerImpl *v6; // rax
  Scaleform::GFx::DrawTextManagerImpl *v7; // r14
  Scaleform::GFx::MovieDef *v8; // rdi
  Scaleform::GFx::ResourceLibBase *v9; // rcx
  Scaleform::GFx::StateBagImpl *v10; // rax
  Scaleform::GFx::StateBagImpl *v11; // rax
  Scaleform::GFx::StateBagImpl *v12; // r14
  Scaleform::GFx::DrawTextManagerImpl *v13; // rdi
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::Log *v15; // rdi
  Scaleform::Ptr<Scaleform::Log> *v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::Log *v18; // rdi
  Scaleform::Log *v19; // rax
  Scaleform::Render::Text::Allocator *v20; // rax
  Scaleform::Render::Text::Allocator *v21; // r14
  Scaleform::GFx::DrawTextManagerImpl *v22; // rdi
  Scaleform::RefCountNTSImpl *v23; // rcx
  __int64 v24; // rdi
  Scaleform::GFx::StateBagImpl *v25; // rax
  signed __int64 v26; // rax
  Scaleform::GFx::DrawTextManagerImpl *v27; // r14
  Scaleform::RefCountNTSImpl *v28; // rcx
  Scaleform::GFx::FontLib *v29; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontLib> *v30; // rax
  signed __int64 v31; // rcx
  Scaleform::GFx::FontMap *v32; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontMap> *v33; // rax
  signed __int64 v34; // rcx
  Scaleform::GFx::FontProvider *v35; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *v36; // rax
  signed __int64 v37; // rcx
  __int64 v38; // rdi
  Scaleform::GFx::ResourceWeakLib *v39; // r14
  Scaleform::GFx::DrawTextManagerImpl *v40; // rsi
  Scaleform::Log *v41; // rax
  Scaleform::GFx::ResourceWeakLib *v42; // rax
  Scaleform::Render::RenderBuffer *v43; // rcx
  Scaleform::Log *v44; // rax
  Scaleform::GFx::FontManager *v45; // rax
  Scaleform::GFx::FontManager *v46; // r14
  Scaleform::GFx::DrawTextManagerImpl *v47; // rsi
  Scaleform::Render::RenderBuffer *v48; // rcx
  Scaleform::GFx::DrawTextManagerImpl *v49; // r14
  Scaleform::Log *v50; // rax
  Scaleform::Render::ContextImpl::EntryData *v51; // rsi
  Scaleform::Render::ContextImpl::Entry *v52; // r14
  Scaleform::Render::ContextImpl::Entry **v53; // rsi
  Scaleform::Render::ContextImpl::Entry *v54; // rcx
  bool v55; // zf
  signed __int64 v56; // rcx
  Scaleform::GFx::DrawTextManagerImpl *v57; // rsi
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v58; // rax
  Scaleform::Render::RenderBuffer *v59; // rcx
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v60; // [rsp+20h] [rbp-89h]
  Scaleform::Ptr<Scaleform::GFx::FontLib> v61; // [rsp+28h] [rbp-81h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v62; // [rsp+30h] [rbp-79h]
  Scaleform::Ptr<Scaleform::GFx::FontLib> v63; // [rsp+38h] [rbp-71h]
  Scaleform::Ptr<Scaleform::GFx::FontMap> v64; // [rsp+40h] [rbp-69h]
  Scaleform::Ptr<Scaleform::GFx::FontMap> v65; // [rsp+48h] [rbp-61h]
  void *v66; // [rsp+50h] [rbp-59h]
  int v67; // [rsp+60h] [rbp-49h]
  __int64 v68; // [rsp+68h] [rbp-41h]
  __int64 v69; // [rsp+70h] [rbp-39h]
  __int64 v70; // [rsp+78h] [rbp-31h]
  __int64 v71; // [rsp+80h] [rbp-29h]
  __int64 v72; // [rsp+88h] [rbp-21h]
  __int64 v73; // [rsp+90h] [rbp-19h]
  __int64 v74; // [rsp+98h] [rbp-11h]
  __int64 v75; // [rsp+A0h] [rbp-9h]
  __int64 v76; // [rsp+A8h] [rbp-1h]
  Scaleform::Log *v77; // [rsp+B0h] [rbp+7h]
  Scaleform::Render::ContextImpl::RTHandle v78; // [rsp+118h] [rbp+6Fh]
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+120h] [rbp+77h]
  Scaleform::Ptr<Scaleform::Log> v80; // [rsp+128h] [rbp+7Fh]

  v75 = -2i64;
  v2 = ploader;
  v3 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::GFx::StateBag};
  v67 = *(_DWORD *)((__int64)Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this)
                  + 56) & 0x1000;
  v68 = 16i64;
  v69 = 0x4000i64;
  v70 = 0x4000i64;
  v71 = -1i64;
  v72 = 0i64;
  v73 = 0i64;
  v74 = 0i64;
  v4 = (*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
         Scaleform::Memory::pGlobalHeap,
         "DrawText Manager",
         &v67);
  v3->pHeap = (Scaleform::MemoryHeap *)v4;
  v5 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)(*(__int64 (__fastcall **)(__int64, signed __int64, _QWORD))(*(_QWORD *)v4 + 80i64))(
                                                                 v4,
                                                                 392i64,
                                                                 0i64);
  v78.pData.pObject = v5;
  if ( v5 )
  {
    Scaleform::GFx::DrawTextManagerImpl::DrawTextManagerImpl((Scaleform::GFx::DrawTextManagerImpl *)v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v3->pImpl = v7;
  v8 = v7->pMovieDef.pObject;
  if ( v8 && _InterlockedExchangeAdd(&v8->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v9 = v8->pLib;
    if ( v9 )
    {
      v9->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v8->vfptr, 1u);
  }
  v7->pMovieDef.pObject = 0i64;
  v10 = (Scaleform::GFx::StateBagImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          88i64);
  v66 = v10;
  if ( v10 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl(v10, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = v3->pImpl;
  v14 = (Scaleform::Render::RenderBuffer *)v13->pStateBag.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  v13->pStateBag.pObject = v12;
  v15 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v2->vfptr, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v15 )
  {
    v16 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v2->vfptr, &v80);
    Scaleform::GFx::StateBag::SetLog((Scaleform::GFx::StateBag *)&v3->pImpl->pStateBag.pObject->vfptr, v16->pObject);
    v17 = (Scaleform::Render::RenderBuffer *)v80.pObject;
    if ( !v80.pObject )
      goto LABEL_25;
    goto LABEL_24;
  }
  v18 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            16i64);
  v66 = v18;
  if ( v18 )
  {
    v18->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
    v18->RefCount = 1;
    v18->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
    v18->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    v18->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Log,2>::`vftable;
    v18->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Log::`vftable;
  }
  else
  {
    v18 = 0i64;
  }
  v77 = v18;
  Scaleform::GFx::StateBag::SetLog((Scaleform::GFx::StateBag *)&v3->pImpl->pStateBag.pObject->vfptr, v18);
  if ( v18 )
  {
    v17 = (Scaleform::Render::RenderBuffer *)v18;
LABEL_24:
    Scaleform::RefCountImpl::Release(v17);
  }
LABEL_25:
  v19 = (Scaleform::Log *)v3->pHeap->vfptr->Alloc(v3->pHeap, 144ui64, 0i64);
  result.pObject = v19;
  if ( v19 )
  {
    Scaleform::Render::Text::Allocator::Allocator((Scaleform::Render::Text::Allocator *)v19, v3->pHeap, 0);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = v3->pImpl;
  v23 = (Scaleform::RefCountNTSImpl *)&v22->pTextAllocator.pObject->vfptr;
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
  v22->pTextAllocator.pObject = v21;
  v24 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          64i64);
  result.pObject = (Scaleform::Log *)v24;
  if ( v24 )
  {
    v25 = v3->pImpl->pStateBag.pObject;
    if ( v25 )
      v26 = (signed __int64)&v25->vfptr;
    else
      v26 = 0i64;
    *(_QWORD *)v24 = &Scaleform::RefCountNTSImplCore::`vftable;
    *(_DWORD *)(v24 + 8) = 1;
    *(_QWORD *)v24 = &Scaleform::RefCountNTSImpl::`vftable;
    *(_QWORD *)v24 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,327>::`vftable;
    *(_QWORD *)v24 = &Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>::`vftable;
    *(_QWORD *)(v24 + 16) = &Scaleform::GFx::StateBag::`vftable;
    *(_QWORD *)v24 = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::FontManagerStates,327>};
    *(_QWORD *)(v24 + 16) = &Scaleform::GFx::FontManagerStates::`vftable{for `Scaleform::GFx::StateBag};
    *(_QWORD *)(v24 + 24) = 0i64;
    *(_QWORD *)(v24 + 32) = 0i64;
    *(_QWORD *)(v24 + 40) = 0i64;
    *(_QWORD *)(v24 + 48) = 0i64;
    *(_QWORD *)(v24 + 56) = v26;
  }
  else
  {
    v24 = 0i64;
  }
  v27 = v3->pImpl;
  v28 = (Scaleform::RefCountNTSImpl *)&v27->pFontStates.pObject->vfptr;
  if ( v28 )
    Scaleform::RefCountNTSImpl::Release(v28);
  v27->pFontStates.pObject = (Scaleform::GFx::FontManagerStates *)v24;
  v29 = Scaleform::GFx::StateBag::GetFontLib((Scaleform::GFx::StateBag *)&v2->vfptr, &v61)->pObject;
  if ( v61.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v61.pObject);
  if ( v29 )
  {
    v30 = Scaleform::GFx::StateBag::GetFontLib((Scaleform::GFx::StateBag *)&v2->vfptr, &v63);
    v31 = (signed __int64)&v3->pImpl->pStateBag.pObject->vfptr;
    (*(void (__fastcall **)(signed __int64, signed __int64, Scaleform::GFx::FontLib *))(*(_QWORD *)v31 + 16i64))(
      v31,
      20i64,
      v30->pObject);
    if ( v63.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v63.pObject);
  }
  v32 = Scaleform::GFx::StateBag::GetFontMap((Scaleform::GFx::StateBag *)&v2->vfptr, &v65)->pObject;
  if ( v65.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v65.pObject);
  if ( v32 )
  {
    v33 = Scaleform::GFx::StateBag::GetFontMap((Scaleform::GFx::StateBag *)&v2->vfptr, &v64);
    v34 = (signed __int64)&v3->pImpl->pStateBag.pObject->vfptr;
    (*(void (__fastcall **)(signed __int64, signed __int64, Scaleform::GFx::FontMap *))(*(_QWORD *)v34 + 16i64))(
      v34,
      23i64,
      v33->pObject);
    if ( v64.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v64.pObject);
  }
  v35 = Scaleform::GFx::StateBag::GetFontProvider((Scaleform::GFx::StateBag *)&v2->vfptr, &v62)->pObject;
  if ( v62.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v62.pObject);
  if ( v35 )
  {
    v36 = Scaleform::GFx::StateBag::GetFontProvider((Scaleform::GFx::StateBag *)&v2->vfptr, &v60);
    v37 = (signed __int64)&v3->pImpl->pStateBag.pObject->vfptr;
    (*(void (__fastcall **)(signed __int64, signed __int64, Scaleform::GFx::FontProvider *))(*(_QWORD *)v37 + 16i64))(
      v37,
      22i64,
      v36->pObject);
    if ( v60.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v60.pObject);
  }
  v38 = (__int64)v2->pStrongResourceLib;
  if ( v38 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v2->pStrongResourceLib);
  v76 = v38;
  if ( v38 )
  {
    v39 = *(Scaleform::GFx::ResourceWeakLib **)(v38 + 16);
    v40 = v3->pImpl;
    if ( v39 )
      Scaleform::Render::RenderBuffer::AddRef(*(Scaleform::GFx::Resource **)(v38 + 16));
  }
  else
  {
    v41 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                              Scaleform::Memory::pGlobalHeap,
                              80i64);
    result.pObject = v41;
    if ( v41 )
    {
      Scaleform::GFx::ResourceWeakLib::ResourceWeakLib((Scaleform::GFx::ResourceWeakLib *)v41, 0i64);
      v39 = v42;
    }
    else
    {
      v39 = 0i64;
    }
    v40 = v3->pImpl;
  }
  v43 = (Scaleform::Render::RenderBuffer *)v40->pWeakLib.pObject;
  if ( v43 )
    Scaleform::RefCountImpl::Release(v43);
  v40->pWeakLib.pObject = v39;
  v44 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                            v3->pHeap,
                            104i64);
  result.pObject = v44;
  if ( v44 )
  {
    Scaleform::GFx::FontManager::FontManager(
      (Scaleform::GFx::FontManager *)v44,
      v3->pImpl->pWeakLib.pObject,
      v3->pImpl->pFontStates.pObject);
    v46 = v45;
  }
  else
  {
    v46 = 0i64;
  }
  v47 = v3->pImpl;
  v48 = (Scaleform::Render::RenderBuffer *)v47->pFontManager.pObject;
  if ( v48 )
    Scaleform::RefCountImpl::Release(v48);
  v47->pFontManager.pObject = v46;
  v49 = v3->pImpl;
  v50 = (Scaleform::Log *)v49->RenderContext.pHeap->vfptr->Alloc(v49->RenderContext.pHeap, 208ui64, 0i64);
  v51 = (Scaleform::Render::ContextImpl::EntryData *)v50;
  result.pObject = v50;
  v80.pObject = v50;
  if ( v50 )
    Scaleform::Render::TreeRoot::NodeData::NodeData((Scaleform::Render::TreeRoot::NodeData *)v50);
  v52 = Scaleform::Render::ContextImpl::Context::createEntryHelper(&v49->RenderContext, v51);
  v53 = (Scaleform::Render::ContextImpl::Entry **)v3->pImpl;
  v54 = *v53;
  if ( *v53 )
  {
    v55 = v54->RefCount-- == 1;
    if ( v55 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v54);
  }
  *v53 = v52;
  v56 = (signed __int64)&v3->pImpl->pRootNode.pObject[-1]
      - ((_QWORD)v3->pImpl->pRootNode.pObject & 0xFFFFFFFFFFFFF000ui64);
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v3->pImpl->pRootNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)(v56
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)(v56 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 204i64) )
    *(_DWORD *)(&Scaleform::Render::ContextImpl::Entry::getWritableData(
                   (Scaleform::Render::ContextImpl::Entry *)v3->pImpl->pRootNode.pObject,
                   0x1000u)[12].Flags
              + 1) = 0;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(
    &v78,
    (Scaleform::Render::ContextImpl::Entry *)v3->pImpl->pRootNode.pObject);
  v57 = v3->pImpl;
  v58 = v78.pData.pObject;
  if ( v78.pData.pObject )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v78.pData.pObject);
    v58 = v78.pData.pObject;
  }
  v59 = (Scaleform::Render::RenderBuffer *)v57->DispHandle.pData.pObject;
  if ( v59 )
  {
    Scaleform::RefCountImpl::Release(v59);
    v58 = v78.pData.pObject;
  }
  v57->DispHandle.pData.pObject = v58;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v78);
  if ( v38 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v38);
}.pObject;
  }
  v59 = (Scaleform::Render::RenderBuffer *)v57->DispHandle.pData.pObject;
  if ( v59 )
  {
    Scaleform::RefCountImpl::Release(v59);
    v58 = v78.pData.pObject;
  }
  v57->DispHandle.pData.pObject = v58;
  

// File Line: 608
// RVA: 0x8A3FD0
void __fastcall Scaleform::GFx::DrawTextManager::~DrawTextManager(Scaleform::GFx::DrawTextManager *this)
{
  Scaleform::GFx::DrawTextManager *v1; // rbx
  Scaleform::GFx::DrawTextManagerImpl *v2; // rdi

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>};
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::GFx::StateBag};
  v2 = this->pImpl;
  if ( v2 )
  {
    Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(this->pImpl);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  ((void (__cdecl *)(Scaleform::MemoryHeap *))v1->pHeap->vfptr->Release)(v1->pHeap);
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->vfptr);
}

// File Line: 629
// RVA: 0x89EC10
void __fastcall Scaleform::GFx::DrawTextManager::TextParams::TextParams(Scaleform::GFx::DrawTextManager::TextParams *this)
{
  Scaleform::GFx::DrawTextManager::TextParams *v1; // rdi
  unsigned int v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  Scaleform::String::String(&this->FontName);
  *(_WORD *)((char *)&v2 + 1) = 0;
  LOBYTE(v2) = 0;
  HIBYTE(v2) = -1;
  v1->TextColor.Raw = v2;
  *(_QWORD *)&v1->HAlignment = 0i64;
  v1->FontStyle = 0;
  v1->FontSize = 12.0;
  Scaleform::String::operator=(&v1->FontName, "Times New Roman");
  *(_WORD *)&v1->Underline = 256;
  v1->WordWrap = 1;
}

// File Line: 642
// RVA: 0x906D90
void __fastcall Scaleform::GFx::DrawTextManager::SetDefaultTextParams(Scaleform::GFx::DrawTextManager *this, Scaleform::GFx::DrawTextManager::TextParams *params)
{
  Scaleform::GFx::DrawTextManagerImpl *v2; // rbx
  Scaleform::GFx::DrawTextManager::TextParams *v3; // rdi
  Scaleform::GFx::DrawText::VAlignment v4; // eax
  Scaleform::String *v5; // rdx

  v2 = this->pImpl;
  v3 = params;
  v2->DefaultTextParams.TextColor.Raw = params->TextColor.Raw;
  v2->DefaultTextParams.HAlignment = params->HAlignment;
  v4 = params->VAlignment;
  v5 = &params->FontName;
  v2->DefaultTextParams.VAlignment = v4;
  v2->DefaultTextParams.FontStyle = HIDWORD(v5[-2].HeapTypeBits);
  v2->DefaultTextParams.FontSize = *(float *)&v5[-1].pData;
  Scaleform::String::operator=(&v2->DefaultTextParams.FontName, v5);
  v2->DefaultTextParams.Underline = v3->Underline;
  v2->DefaultTextParams.Multiline = v3->Multiline;
  v2->DefaultTextParams.WordWrap = v3->WordWrap;
}

// File Line: 648
// RVA: 0x8D6820
Scaleform::GFx::DrawTextManager::TextParams *__fastcall Scaleform::GFx::DrawTextManager::GetDefaultTextParams(Scaleform::GFx::DrawTextManager *this)
{
  return &this->pImpl->DefaultTextParams;
}

// File Line: 654
// RVA: 0x90DC20
void __fastcall Scaleform::GFx::DrawTextManager::SetTextParams(Scaleform::GFx::DrawTextManager *this, Scaleform::Render::Text::DocView *pdoc, Scaleform::GFx::DrawTextManager::TextParams *txtParams, Scaleform::Render::Text::TextFormat *tfmt)
{
  Scaleform::Render::Text::TextFormat *v4; // r15
  Scaleform::GFx::DrawTextManager::TextParams *v5; // rdi
  Scaleform::Render::Text::DocView *v6; // rbx
  signed __int16 v7; // si
  char v8; // r14
  Scaleform::GFx::DrawText::FontStyle v9; // ecx
  int v10; // ecx
  int v11; // ecx
  bool v12; // dl
  bool v13; // dl
  float v14; // xmm0_4
  signed int v15; // eax
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [rsp+8h] [rbp-51h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+38h] [rbp-21h]
  __int64 v18; // [rsp+88h] [rbp+2Fh]
  Scaleform::Render::Text::ParagraphFormat *src; // [rsp+D8h] [rbp+7Fh]

  v18 = -2i64;
  v4 = tfmt;
  v5 = txtParams;
  v6 = pdoc;
  Scaleform::Render::Text::TextFormat::TextFormat(
    (Scaleform::Render::Text::TextFormat *)((char *)&fmt + 24),
    this->pHeap);
  v7 = 0;
  defaultParagraphFmt.pAllocator = 0i64;
  v8 = 1;
  defaultParagraphFmt.RefCount = 1;
  defaultParagraphFmt.pTabStops = 0i64;
  *(_QWORD *)&defaultParagraphFmt.BlockIndent = 0i64;
  *(_DWORD *)&defaultParagraphFmt.RightMargin = 0;
  if ( v4 )
    Scaleform::Render::Text::TextFormat::operator=(&fmt, v4);
  if ( src )
    Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, src);
  fmt.ColorV = v5->TextColor.Raw;
  fmt.PresentMask |= 1u;
  v9 = v5->FontStyle;
  if ( v9 == 0 )
  {
    v13 = 0;
    goto LABEL_13;
  }
  v10 = v9 - 1;
  if ( !v10 )
  {
    v13 = 1;
LABEL_13:
    Scaleform::Render::Text::TextFormat::SetBold(&fmt, v13);
    v12 = 0;
    goto LABEL_14;
  }
  v11 = v10 - 1;
  if ( v11 )
  {
    if ( v11 != 1 )
      goto LABEL_15;
    Scaleform::Render::Text::TextFormat::SetBold(&fmt, 1);
    v12 = 1;
  }
  else
  {
    Scaleform::Render::Text::TextFormat::SetBold(&fmt, 0);
    v12 = 1;
  }
LABEL_14:
  Scaleform::Render::Text::TextFormat::SetItalic(&fmt, v12);
LABEL_15:
  Scaleform::Render::Text::TextFormat::SetFontName(&fmt, &v5->FontName);
  v14 = v5->FontSize;
  if ( v14 >= 3276.8 )
    LOWORD(v15) = -1;
  else
    v15 = (signed int)(float)(v14 * 20.0);
  fmt.FontSize = v15;
  fmt.PresentMask |= 8u;
  Scaleform::Render::Text::TextFormat::SetUnderline(&fmt, v5->Underline);
  switch ( v5->HAlignment )
  {
    case 1:
      v7 = 1;
      break;
    case 2:
      v7 = 3;
      break;
    case 3:
      v7 = 2;
      break;
  }
  defaultParagraphFmt.PresentMask = defaultParagraphFmt.PresentMask ^ (defaultParagraphFmt.PresentMask ^ (v7 << 9)) & 0x600 | 1;
  if ( v5->VAlignment == 1 )
  {
    v8 = 3;
  }
  else if ( v5->VAlignment == 2 )
  {
    v8 = 2;
  }
  v6->AlignProps &= 0xF3u;
  v6->AlignProps |= 4 * (v8 & 3);
  v6->RTFlags |= 1u;
  if ( v5->Multiline )
  {
    v6->Flags |= 4u;
    if ( v5->WordWrap )
      Scaleform::Render::Text::DocView::SetWordWrap(v6);
  }
  Scaleform::Render::Text::DocView::SetTextFormat(v6, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::DocView::SetParagraphFormat(v6, &defaultParagraphFmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
    (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->vfptr,
    &fmt);
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
    (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->vfptr,
    &defaultParagraphFmt);
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&defaultParagraphFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 761
// RVA: 0x8BFDE0
Scaleform::Render::TreeNode **__fastcall Scaleform::GFx::DrawTextManager::CreateHtmlText(Scaleform::GFx::DrawTextManager *this, const char *putf8Str, Scaleform::Render::Rect<float> *viewRect, Scaleform::GFx::DrawTextManager::TextParams *ptxtParams, unsigned int depth)
{
  Scaleform::GFx::DrawTextManager::TextParams *v5; // rsi
  Scaleform::Render::Rect<float> *v6; // rbp
  const char *v7; // r14
  Scaleform::GFx::DrawTextManager *v8; // rdi
  Scaleform::GFx::DrawTextImpl *v9; // rax
  Scaleform::Render::TreeNode **v10; // rax
  Scaleform::Render::TreeNode **v11; // rbx
  Scaleform::Render::Text::DocView *v12; // rax
  Scaleform::Render::TreeContainer *v13; // rcx

  v5 = ptxtParams;
  v6 = viewRect;
  v7 = putf8Str;
  v8 = this;
  v9 = (Scaleform::GFx::DrawTextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))this->pHeap->vfptr->Alloc)(
                                         this->pHeap,
                                         40i64);
  if ( v9 )
  {
    Scaleform::GFx::DrawTextImpl::DrawTextImpl(v9, v8);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  ((void (__fastcall *)(Scaleform::Render::TreeNode **, Scaleform::Render::Rect<float> *))(*v11)[2].PNode.pPrev)(
    v11,
    v6);
  if ( !v5 )
    v5 = &v8->pImpl->DefaultTextParams;
  v12 = Scaleform::Render::TreeText::GetDocView((Scaleform::Render::TreeText *)v11[3]);
  Scaleform::GFx::DrawTextManager::SetTextParams(v8, v12, v5, 0i64, 0i64);
  ((void (__fastcall *)(Scaleform::Render::TreeNode **, const char *, signed __int64))(*v11)[1].pPrev)(v11, v7, -1i64);
  v13 = (Scaleform::Render::TreeContainer *)v8->pImpl->pRootNode.pObject;
  if ( depth == -1 )
    Scaleform::Render::TreeContainer::Add(v13, v11[3]);
  else
    Scaleform::Render::TreeContainer::Insert(v13, depth, v11[3]);
  return v11;
}

// File Line: 935
// RVA: 0x8DE3F0
Scaleform::GFx::StateBag *__fastcall Scaleform::GFx::DrawTextManager::GetStateBagImpl(Scaleform::GFx::DrawTextManager *this)
{
  Scaleform::GFx::StateBag *result; // rax

  result = *(Scaleform::GFx::StateBag **)(*(_QWORD *)&this->RefCount + 8i64);
  if ( result )
    result += 2;
  return result;
}

// File Line: 955
// RVA: 0x8BAEE0
void __fastcall Scaleform::GFx::DrawTextManager::CheckFontStatesChange(Scaleform::GFx::DrawTextManager *this)
{
  Scaleform::GFx::DrawTextManager *v1; // rbp
  Scaleform::Ptr<Scaleform::GFx::Translator> *v2; // r14
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontMap> *v4; // rbx
  Scaleform::Ptr<Scaleform::GFx::FontLib> *v5; // rax
  Scaleform::Ptr<Scaleform::GFx::FontLib> v6; // [rsp+70h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::FontMap> v7; // [rsp+78h] [rbp+10h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v8; // [rsp+80h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+88h] [rbp+20h]

  v1 = this;
  v2 = Scaleform::GFx::StateBag::GetTranslator((Scaleform::GFx::StateBag *)&this->vfptr, &result);
  v3 = Scaleform::GFx::StateBag::GetFontProvider((Scaleform::GFx::StateBag *)&v1->vfptr, &v8);
  v4 = Scaleform::GFx::StateBag::GetFontMap((Scaleform::GFx::StateBag *)&v1->vfptr, &v7);
  v5 = Scaleform::GFx::StateBag::GetFontLib((Scaleform::GFx::StateBag *)&v1->vfptr, &v6);
  Scaleform::GFx::FontManagerStates::CheckStateChange(
    v1->pImpl->pFontStates.pObject,
    v5->pObject,
    v4->pObject,
    v3->pObject,
    v2->pObject);
  if ( v6.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6.pObject);
  if ( v7.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7.pObject);
  if ( v8.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8.pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 968
// RVA: 0x90EDE0
void __fastcall Scaleform::GFx::DrawTextManager::SetViewport(Scaleform::GFx::DrawTextManager *this, Scaleform::Render::Viewport *vp)
{
  Scaleform::GFx::DrawTextManager *v2; // rbx
  Scaleform::Render::TreeNode **v3; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-28h]

  v2 = this;
  Scaleform::Render::TreeRoot::SetViewport(this->pImpl->pRootNode.pObject, vp);
  v3 = (Scaleform::Render::TreeNode **)v2->pImpl;
  *(_OWORD *)&m.M[0][0] = 0x3D4CCCCDui64;
  m.M[1][0] = 0.0;
  *(_QWORD *)&m.M[1][1] = 1028443341i64;
  m.M[1][3] = 0.0;
  Scaleform::Render::TreeNode::SetMatrix(*v3, &m);
}

// File Line: 977
// RVA: 0x8B98A0
void __fastcall Scaleform::GFx::DrawTextManager::Capture(Scaleform::GFx::DrawTextManager *this, bool onChangeOnly)
{
  Scaleform::GFx::DrawTextManager *v2; // rbx

  v2 = this;
  if ( !onChangeOnly || Scaleform::Render::ContextImpl::Context::HasChanges(&this->pImpl->RenderContext) )
    Scaleform::Render::ContextImpl::Context::Capture(&v2->pImpl->RenderContext);
}

// File Line: 988
// RVA: 0x8D6CC0
Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot> *__fastcall Scaleform::GFx::DrawTextManager::GetDisplayHandle(Scaleform::GFx::DrawTextManager *this)
{
  return &this->pImpl->DispHandle;
}

