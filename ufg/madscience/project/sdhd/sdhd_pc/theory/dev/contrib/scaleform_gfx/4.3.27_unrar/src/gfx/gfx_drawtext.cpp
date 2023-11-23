// File Line: 50
// RVA: 0x895ED0
void __fastcall Scaleform::GFx::DrawTextManagerImpl::DrawTextManagerImpl(Scaleform::GFx::DrawTextManagerImpl *this)
{
  this->pRootNode.pObject = 0i64;
  this->pStateBag.pObject = 0i64;
  this->pMovieDef.pObject = 0i64;
  this->pTextAllocator.pObject = 0i64;
  this->pFontManager.pObject = 0i64;
  this->pFontStates.pObject = 0i64;
  this->pWeakLib.pObject = 0i64;
  Scaleform::GFx::DrawTextManager::TextParams::TextParams(&this->DefaultTextParams);
  this->pLoaderImpl.pObject = 0i64;
  this->RTFlags = 0;
  Scaleform::Render::ContextImpl::Context::Context(&this->RenderContext, Scaleform::Memory::pGlobalHeap);
  this->DispHandle.pData.pObject = 0i64;
}

// File Line: 53
// RVA: 0x8A4050
void __fastcall Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(Scaleform::GFx::DrawTextManagerImpl *this)
{
  Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot> *p_DispHandle; // rsi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::TreeRoot *v4; // rcx
  bool v5; // zf
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::GFx::FontManagerStates *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::Text::Allocator *v10; // rcx
  Scaleform::GFx::MovieDef *v11; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::Render::TreeRoot *v14; // rcx

  p_DispHandle = &this->DispHandle;
  pObject = (Scaleform::Render::RenderBuffer *)this->DispHandle.pData.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  p_DispHandle->pData.pObject = 0i64;
  v4 = this->pRootNode.pObject;
  if ( this->pRootNode.pObject )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  this->pRootNode.pObject = 0i64;
  Scaleform::Render::ContextImpl::Context::Shutdown(&this->RenderContext, 1);
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(p_DispHandle);
  Scaleform::Render::ContextImpl::Context::~Context(&this->RenderContext);
  v6 = (Scaleform::Render::RenderBuffer *)this->pLoaderImpl.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->DefaultTextParams.FontName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v7 = (Scaleform::Render::RenderBuffer *)this->pWeakLib.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v8 = this->pFontStates.pObject;
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
  v9 = (Scaleform::Render::RenderBuffer *)this->pFontManager.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v10 = this->pTextAllocator.pObject;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v11 = this->pMovieDef.pObject;
  if ( v11 && !_InterlockedDecrement(&v11->RefCount.Value) )
  {
    pLib = v11->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v11);
      v11->pLib = 0i64;
    }
    v11->Scaleform::GFx::Resource::vfptr->__vecDelDtor(v11, 1u);
  }
  v13 = (Scaleform::Render::RenderBuffer *)this->pStateBag.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v14 = this->pRootNode.pObject;
  if ( this->pRootNode.pObject )
  {
    v5 = v14->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v14);
  }
}

// File Line: 92
// RVA: 0x90C980
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        const char *putf8Str,
        unsigned __int64 lengthInBytes)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, putf8Str, lengthInBytes);
}

// File Line: 97
// RVA: 0x90C9C0
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(
        Scaleform::GFx::DrawTextImpl *this,
        const wchar_t *pstr,
        unsigned __int64 lengthInChars)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(this->pTextNode.pObject, pstr, lengthInChars);
}

// File Line: 102
// RVA: 0x90C930
void __fastcall Scaleform::GFx::DrawTextImpl::SetText(Scaleform::GFx::DrawTextImpl *this, Scaleform::String *str)
{
  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  Scaleform::Render::TreeText::SetText(
    this->pTextNode.pObject,
    (const char *)((str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
    *(_QWORD *)(str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
}

// File Line: 107
// RVA: 0x8DE820
Scaleform::String *__fastcall Scaleform::GFx::DrawTextImpl::GetText(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::String *result)
{
  Scaleform::Render::TreeText::GetText(this->pTextNode.pObject, result);
  return result;
}

// File Line: 112
// RVA: 0x907EC0
void __fastcall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        const char *putf8Str,
        unsigned __int64 lengthInBytes)
{
  Scaleform::MemoryHeap *pHeap; // r9
  Scaleform::GFx::DrawTextManager *pObject; // rbx
  Scaleform::Render::Text::DocView *DocView; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&pimgInfoArr, 0, 24);
  pimgInfoArr.Data.pHeap = pHeap;
  Scaleform::Render::TreeText::SetHtmlText(this->pTextNode.pObject, putf8Str, lengthInBytes, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    pObject = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, pObject, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}

// File Line: 122
// RVA: 0x907F90
void __fastcall Scaleform::GFx::DrawTextImpl::SetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        const wchar_t *pstr,
        unsigned __int64 lengthInChars)
{
  Scaleform::MemoryHeap *pHeap; // r9
  Scaleform::GFx::DrawTextManager *pObject; // rbx
  Scaleform::Render::Text::DocView *DocView; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&pimgInfoArr, 0, 24);
  pimgInfoArr.Data.pHeap = pHeap;
  Scaleform::Render::TreeText::SetHtmlText(this->pTextNode.pObject, pstr, lengthInChars, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    pObject = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, pObject, &pimgInfoArr);
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
  Scaleform::MemoryHeap *pHeap; // r8
  unsigned __int64 v5; // rbx
  Scaleform::Render::TreeText *pObject; // rdi
  unsigned __int64 Length; // rax
  Scaleform::GFx::DrawTextManager *v8; // rbx
  Scaleform::Render::Text::DocView *DocView; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> pimgInfoArr; // [rsp+28h] [rbp-30h] BYREF

  Scaleform::GFx::DrawTextManager::CheckFontStatesChange(this->pDrawTextCtxt.pObject);
  pHeap = this->pDrawTextCtxt.pObject->pHeap;
  memset(&pimgInfoArr, 0, 24);
  pimgInfoArr.Data.pHeap = pHeap;
  v5 = str->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  pObject = this->pTextNode.pObject;
  Length = Scaleform::String::GetLength(str);
  Scaleform::Render::TreeText::SetHtmlText(pObject, (const char *)(v5 + 12), Length, &pimgInfoArr);
  if ( pimgInfoArr.Data.Size )
  {
    v8 = this->pDrawTextCtxt.pObject;
    DocView = Scaleform::Render::TreeText::GetDocView(this->pTextNode.pObject);
    Scaleform::GFx::DrawTextImpl::ProcessImageTags(DocView, v8, &pimgInfoArr);
  }
  Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
    pimgInfoArr.Data.Data,
    pimgInfoArr.Data.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pimgInfoArr.Data.Data);
}

// File Line: 142
// RVA: 0x8D9C10
Scaleform::String *__fastcall Scaleform::GFx::DrawTextImpl::GetHtmlText(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::String *result)
{
  Scaleform::Render::TreeText::GetHtmlText(this->pTextNode.pObject, result);
  return result;
}

// File Line: 147
// RVA: 0x90AD10
void __fastcall Scaleform::GFx::DrawTextImpl::SetRect(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Rect<float> *viewRect)
{
  Scaleform::Render::TreeText *pObject; // rcx
  float v3; // xmm1_4
  float y1; // xmm0_4
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pTextNode.pObject;
  v3 = viewRect->x2 * 20.0;
  r.x1 = viewRect->x1 * 20.0;
  y1 = viewRect->y1;
  r.x2 = v3;
  r.y1 = y1 * 20.0;
  r.y2 = viewRect->y2 * 20.0;
  Scaleform::Render::TreeText::SetBounds(pObject, &r);
}

// File Line: 151
// RVA: 0x8DCEA0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DrawTextImpl::GetRect(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *Bounds; // rax
  float v4; // xmm1_4
  float y1; // xmm0_4
  float y2; // xmm0_4
  Scaleform::Render::Rect<float> *v7; // rax
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-18h] BYREF

  Bounds = Scaleform::Render::TreeText::GetBounds(this->pTextNode.pObject, &resulta);
  v4 = Bounds->x2 * 0.050000001;
  result->x1 = Bounds->x1 * 0.050000001;
  y1 = Bounds->y1;
  result->x2 = v4;
  result->y1 = y1 * 0.050000001;
  y2 = Bounds->y2;
  v7 = result;
  result->y2 = y2 * 0.050000001;
  return v7;
}

// File Line: 156
// RVA: 0x909610
void __fastcall Scaleform::GFx::DrawTextImpl::SetMatrix(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Matrix2x4<float> *matrix)
{
  float v2; // xmm1_4
  Scaleform::Render::TreeText *pObject; // rcx
  float v4; // xmm3_4
  float v5; // xmm2_4
  Scaleform::Render::Matrix2x4<float> v6; // [rsp+20h] [rbp-28h] BYREF

  v2 = matrix->M[0][1];
  pObject = this->pTextNode.pObject;
  v4 = matrix->M[0][3] * 20.0;
  v5 = matrix->M[1][3];
  v6.M[0][0] = matrix->M[0][0];
  *(_QWORD *)&v6.M[0][1] = __PAIR64__(LODWORD(matrix->M[0][2]), LODWORD(v2));
  *(_QWORD *)&v6.M[1][0] = *(_QWORD *)&matrix->M[1][0];
  v6.M[1][2] = matrix->M[1][2];
  v6.M[0][3] = v4;
  v6.M[1][3] = v5 * 20.0;
  Scaleform::Render::TreeNode::SetMatrix(pObject, &v6);
}

// File Line: 163
// RVA: 0x8DAF20
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DrawTextImpl::GetMatrix(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Matrix2x4<float> *result)
{
  float *v3; // rdx
  float v4; // xmm0_4
  float v5; // eax
  float v6; // xmm0_4
  float v7; // eax

  v3 = *(float **)(*(_QWORD *)(((unsigned __int64)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64
                 * (unsigned int)((int)(LODWORD(this->pTextNode.pObject)
                                      - ((__int64)this->pTextNode.pObject & 0xFFFFF000)
                                      - 56)
                                / 56)
                 + 40);
  v4 = v3[7];
  result->M[0][0] = v3[4];
  result->M[0][1] = v3[5];
  v5 = v3[6];
  result->M[0][3] = v4 * 0.050000001;
  v6 = v3[11];
  result->M[0][2] = v5;
  v7 = v3[8];
  result->M[1][3] = v6 * 0.050000001;
  result->M[1][0] = v7;
  result->M[1][1] = v3[9];
  result->M[1][2] = v3[10];
  return result;
}

// File Line: 171
// RVA: 0x906C50
void __fastcall Scaleform::GFx::DrawTextImpl::SetCxform(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this->pTextNode.pObject, 2u);
  WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&cx->M[0][0];
  WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&cx->M[1][0];
}

// File Line: 175
// RVA: 0x8D6790
Scaleform::Render::Cxform *__fastcall Scaleform::GFx::DrawTextImpl::GetCxform(Scaleform::GFx::DrawTextImpl *this)
{
  return (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64)
                                                             + 0x20)
                                                 + 8i64
                                                 * (unsigned int)((int)(LODWORD(this->pTextNode.pObject)
                                                                      - ((__int64)this->pTextNode.pObject & 0xFFFFF000)
                                                                      - 56)
                                                                / 56)
                                                 + 40)
                                     + 80i64);
}

// File Line: 180
// RVA: 0x906A40
void __fastcall Scaleform::GFx::DrawTextImpl::SetColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *c,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::TreeText *pObject; // rcx
  Scaleform::Render::Color ca; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pTextNode.pObject;
  ca = (Scaleform::Render::Color)c->Raw;
  Scaleform::Render::TreeText::SetColor(pObject, (Scaleform::Render::Color)&ca, startPos, endPos);
}

// File Line: 184
// RVA: 0x907620
void __fastcall Scaleform::GFx::DrawTextImpl::SetFont(
        Scaleform::GFx::DrawTextImpl *this,
        const char *pfontName,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFont(this->pTextNode.pObject, pfontName, startPos, endPos);
}

// File Line: 188
// RVA: 0x907630
void __fastcall Scaleform::GFx::DrawTextImpl::SetFontSize(
        Scaleform::GFx::DrawTextImpl *this,
        float fontSize,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFontSize(this->pTextNode.pObject, fontSize, startPos, endPos);
}

// File Line: 192
// RVA: 0x908620
void __fastcall Scaleform::GFx::DrawTextImpl::SetLetterSpacing(
        Scaleform::GFx::DrawTextImpl *this,
        float letterSpacing,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetLetterSpacing(this->pTextNode.pObject, letterSpacing, startPos, endPos);
}

// File Line: 197
// RVA: 0x907640
void __fastcall Scaleform::GFx::DrawTextImpl::SetFontStyle(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::FontStyle fontStyle,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
{
  Scaleform::Render::TreeText::SetFontStyle(this->pTextNode.pObject, fontStyle, startPos, endPos);
}

// File Line: 201
// RVA: 0x90E7D0
void __fastcall Scaleform::GFx::DrawTextImpl::SetUnderline(
        Scaleform::GFx::DrawTextImpl *this,
        bool underline,
        unsigned __int64 startPos,
        unsigned __int64 endPos)
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
void __fastcall Scaleform::GFx::DrawTextImpl::SetAlignment(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::Alignment a)
{
  Scaleform::Render::TreeText::SetAlignment(this->pTextNode.pObject, a);
}

// File Line: 229
// RVA: 0x8D4CC0
Scaleform::GFx::DrawText::Alignment __fastcall Scaleform::GFx::DrawTextImpl::GetAlignment(
        Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetAlignment(this->pTextNode.pObject);
}

// File Line: 234
// RVA: 0x90E8A0
void __fastcall Scaleform::GFx::DrawTextImpl::SetVAlignment(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::VAlignment a)
{
  Scaleform::Render::TreeText::SetVAlignment(this->pTextNode.pObject, a);
}

// File Line: 238
// RVA: 0x8E12B0
Scaleform::GFx::DrawText::VAlignment __fastcall Scaleform::GFx::DrawTextImpl::GetVAlignment(
        Scaleform::GFx::DrawTextImpl *this)
{
  return Scaleform::Render::TreeText::GetVAlignment(this->pTextNode.pObject);
}

// File Line: 243
// RVA: 0x9067B0
void __fastcall Scaleform::GFx::DrawTextImpl::SetBorderColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *borderColor)
{
  Scaleform::Render::TreeText::SetBorderColor(this->pTextNode.pObject, borderColor);
}

// File Line: 246
// RVA: 0x8D4E20
Scaleform::Render::Color *__fastcall Scaleform::GFx::DrawTextImpl::GetBorderColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::TreeText::GetBorderColor(this->pTextNode.pObject, result);
  return result;
}

// File Line: 249
// RVA: 0x906350
void __fastcall Scaleform::GFx::DrawTextImpl::SetBackgroundColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *bkgColor)
{
  Scaleform::Render::TreeText::SetBackgroundColor(this->pTextNode.pObject, bkgColor);
}

// File Line: 252
// RVA: 0x8D4D60
Scaleform::Render::Color *__fastcall Scaleform::GFx::DrawTextImpl::GetBackgroundColor(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::Render::Color *result)
{
  Scaleform::Render::TreeText::GetBackgroundColor(this->pTextNode.pObject, result);
  return result;
}

// File Line: 296
// RVA: 0x906000
void __fastcall Scaleform::GFx::DrawTextImpl::SetAAMode(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::AAMode aa)
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
void __fastcall Scaleform::GFx::DrawTextImpl::SetFilters(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawText::Filter *filters,
        unsigned __int64 filtersCnt)
{
  Scaleform::Render::TreeText::SetFilters(this->pTextNode.pObject, filters, filtersCnt);
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
  unsigned __int64 v4; // rbp
  Scaleform::Render::TreeRoot *pObject; // rdi
  __int64 v6; // rdx
  unsigned __int64 v7; // rcx

  v2 = newDepth;
  v4 = ((unsigned int (__fastcall *)(Scaleform::GFx::DrawTextImpl *))this->vfptr[38].__vecDelDtor)(this);
  pObject = this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  v6 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64
                 * (unsigned int)((int)((int)&this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                                      - ((unsigned int)pObject & 0xFFFFF000))
                                / 56)
                 + 40);
  v7 = *(_QWORD *)(v6 + 144);
  if ( v7 )
  {
    if ( (v7 & 1) != 0 )
      v7 = *(_QWORD *)((v7 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      v7 = (*(_QWORD *)(v6 + 152) != 0i64) + 1i64;
  }
  if ( v2 > v7 )
    LODWORD(v2) = Scaleform::Render::TreeContainer::GetSize(this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject);
  Scaleform::Render::TreeContainer::Remove(pObject, v4, 1ui64);
  Scaleform::Render::TreeContainer::Insert(
    this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject,
    (unsigned int)v2,
    this->pTextNode.pObject);
}

// File Line: 328
// RVA: 0x8D6900
__int64 __fastcall Scaleform::GFx::DrawTextImpl::GetDepth(Scaleform::GFx::DrawTextImpl *this)
{
  Scaleform::Render::TreeRoot *pObject; // r10
  __int64 v3; // rax
  __int64 v4; // r8
  __int64 v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // r9
  unsigned __int64 v8; // r9
  __int64 v9; // rdx
  __int64 v10; // r10
  __int64 v11; // rdx
  _QWORD *v12; // rax

  pObject = this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject;
  v3 = *(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v4 = 0i64;
  v5 = (unsigned int)((int)((int)&this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject[-1]
                          - ((unsigned int)pObject & 0xFFFFF000))
                    / 56);
  v6 = *(_QWORD *)(v3 + 8 * v5 + 40);
  v7 = *(_QWORD *)(v6 + 144);
  if ( v7 )
  {
    if ( (*(_BYTE *)(v6 + 144) & 1) != 0 )
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
  v9 = (unsigned __int128)((__int64)((__int64)&pObject[-1] - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                         * (__int128)0x4924924924924925i64) >> 64;
  v10 = *(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v11 = ((unsigned __int64)v9 >> 63) + (v9 >> 4);
  while ( 1 )
  {
    v12 = (_QWORD *)(*(_QWORD *)(v10 + 8i64 * (unsigned int)v11 + 40) + 144i64);
    if ( (*(_BYTE *)v12 & 1) != 0 )
      v12 = (_QWORD *)((*v12 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    if ( (Scaleform::Render::TreeText *)v12[v4] == this->pTextNode.pObject )
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
  Scaleform::Render::TreeNode::SetVisible(this->pTextNode.pObject, visible);
}

// File Line: 346
// RVA: 0x8E7E30
__int64 __fastcall Scaleform::GFx::DrawTextImpl::IsVisible(Scaleform::GFx::DrawTextImpl *this)
{
  return *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pTextNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8i64
                              * (unsigned int)((int)(LODWORD(this->pTextNode.pObject)
                                                   - ((__int64)this->pTextNode.pObject & 0xFFFFF000)
                                                   - 56)
                                             / 56)
                              + 40)
                  + 10i64) & 1;
}

// File Line: 360
// RVA: 0x895740
void __fastcall Scaleform::GFx::DrawTextImpl::DrawTextImpl(
        Scaleform::GFx::DrawTextImpl *this,
        Scaleform::GFx::DrawTextManager *pdtMgr)
{
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // rsi
  Scaleform::Log *v5; // rax
  Scaleform::Render::ContextImpl::EntryData *v6; // rdi
  Scaleform::Render::TreeText *EntryHelper; // rdi
  Scaleform::Render::TreeText *pObject; // rcx
  Scaleform::Ptr<Scaleform::Log> *Log; // rax
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Log *v12; // [rsp+60h] [rbp+18h]

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
  pImpl = pdtMgr->pImpl;
  v5 = (Scaleform::Log *)pImpl->RenderContext.pHeap->vfptr->Alloc(pImpl->RenderContext.pHeap, 176ui64, 0i64);
  v6 = (Scaleform::Render::ContextImpl::EntryData *)v5;
  result.pObject = v5;
  v12 = v5;
  if ( v5 )
    Scaleform::Render::TreeText::NodeData::NodeData((Scaleform::Render::TreeText::NodeData *)v5);
  EntryHelper = (Scaleform::Render::TreeText *)Scaleform::Render::ContextImpl::Context::createEntryHelper(
                                                 &pImpl->RenderContext,
                                                 v6);
  pObject = this->pTextNode.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pTextNode.pObject = EntryHelper;
  Log = Scaleform::GFx::StateBag::GetLog(&this->pDrawTextCtxt.pObject->Scaleform::GFx::StateBag, &result);
  Scaleform::Render::TreeText::Init(
    this->pTextNode.pObject,
    this->pDrawTextCtxt.pObject->pImpl->pTextAllocator.pObject,
    this->pDrawTextCtxt.pObject->pImpl->pFontManager.pObject,
    Log->pObject);
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 368
// RVA: 0x8A3F50
void __fastcall Scaleform::GFx::DrawTextImpl::~DrawTextImpl(Scaleform::GFx::DrawTextImpl *this)
{
  unsigned int Depth; // eax
  Scaleform::Render::TreeText *pObject; // rcx
  Scaleform::GFx::DrawTextManager *v5; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextImpl::`vftable;
  Depth = Scaleform::GFx::DrawTextImpl::GetDepth(this);
  if ( Depth != -1 )
    Scaleform::Render::TreeContainer::Remove(this->pDrawTextCtxt.pObject->pImpl->pRootNode.pObject, Depth, 1ui64);
  pObject = this->pTextNode.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  v5 = this->pDrawTextCtxt.pObject;
  if ( v5 )
    Scaleform::RefCountNTSImpl::Release(v5);
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawText::`vftable;
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

// File Line: 378
// RVA: 0x8F20E0
void __fastcall Scaleform::GFx::DrawTextImpl::ProcessImageTags(
        Scaleform::Render::Text::DocView *ptextDocView,
        Scaleform::GFx::DrawTextManager *pmgr,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v3; // r14
  unsigned __int64 Size; // rdi
  Scaleform::GFx::FileOpenerBase *pObject; // rax
  Scaleform::GFx::StateBag *v6; // r15
  Scaleform::GFx::ImageCreator *v7; // rbx
  Scaleform::GFx::Resource **ImageCreator; // rbx
  unsigned __int64 v9; // rsi
  __int64 v10; // r13
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *Data; // r12
  Scaleform::String *p_Url; // r14
  char IsProtocolImage; // al
  __int64 v14; // rbx
  Scaleform::Log *v15; // rbx
  Scaleform::Ptr<Scaleform::Log> *v16; // rax
  Scaleform::GFx::Resource *v17; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::Log *v19; // rbx
  Scaleform::Ptr<Scaleform::Log> *v20; // rax
  Scaleform::GFx::ResourceLibBase *v21; // rcx
  Scaleform::GFx::Resource *v22; // rbx
  Scaleform::Log *v23; // rbx
  Scaleform::Ptr<Scaleform::Log> *v24; // rax
  Scaleform::GFx::ResourceLibBase *v25; // rcx
  Scaleform::GFx::ResourceVtbl *vfptr; // rsi
  __int64 v27; // rax
  Scaleform::GFx::ResourceLibBase *v28; // rcx
  __int64 v29; // rax
  Scaleform::GFx::StateBag *v30; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *ImageFileHandlerRegistry; // rsi
  Scaleform::GFx::StateBag *v32; // rax
  __int64 *FileOpener; // rbx
  Scaleform::Ptr<Scaleform::Log> *Log; // rax
  __int64 v35; // rdx
  __int64 v36; // rax
  unsigned __int64 v37; // r8
  Scaleform::GFx::Resource *v38; // rbx
  Scaleform::GFx::ResourceLibBase *v39; // rcx
  Scaleform::Render::Text::ImageDesc *v40; // rsi
  Scaleform::Render::Image *v41; // rcx
  float v42; // xmm5_4
  float v43; // xmm4_4
  int Width; // eax
  float v45; // xmm3_4
  int Height; // eax
  float v47; // xmm2_4
  float VSpace; // xmm0_4
  float *v49; // rax
  float v50; // xmm2_4
  float v51; // xmm3_4
  Scaleform::GFx::ResourceLibBase *v52; // rcx
  Scaleform::GFx::ResourceLibBase *v53; // rcx
  Scaleform::GFx::Resource *v54; // rbx
  Scaleform::GFx::ResourceLibBase *v55; // rcx
  unsigned __int64 v56; // [rsp+20h] [rbp-A0h]
  __int64 v57; // [rsp+28h] [rbp-98h]
  Scaleform::GFx::ResourceBindData pdata; // [rsp+30h] [rbp-90h] BYREF
  Scaleform::Render::RenderBuffer *v59; // [rsp+40h] [rbp-80h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> result; // [rsp+48h] [rbp-78h] BYREF
  Scaleform::Ptr<Scaleform::Log> v61; // [rsp+50h] [rbp-70h] BYREF
  Scaleform::Ptr<Scaleform::Log> v62; // [rsp+58h] [rbp-68h] BYREF
  Scaleform::Ptr<Scaleform::Log> v63; // [rsp+60h] [rbp-60h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v64; // [rsp+68h] [rbp-58h] BYREF
  Scaleform::Ptr<Scaleform::Log> v65; // [rsp+70h] [rbp-50h] BYREF
  Scaleform::Ptr<Scaleform::Log> v66; // [rsp+78h] [rbp-48h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v67; // [rsp+80h] [rbp-40h] BYREF
  int v68; // [rsp+88h] [rbp-38h] BYREF
  __int64 v69; // [rsp+90h] [rbp-30h]
  int v70; // [rsp+98h] [rbp-28h]
  int v71; // [rsp+9Ch] [rbp-24h]
  __int64 v72; // [rsp+A0h] [rbp-20h]
  __int64 v73; // [rsp+A8h] [rbp-18h]
  __int64 v74; // [rsp+B0h] [rbp-10h]
  __int64 v75; // [rsp+B8h] [rbp-8h]
  int v76; // [rsp+C0h] [rbp+0h] BYREF
  __int64 v77; // [rsp+C8h] [rbp+8h]
  int v78; // [rsp+D0h] [rbp+10h]
  int v79; // [rsp+D4h] [rbp+14h]
  __int64 v80; // [rsp+D8h] [rbp+18h]
  __int64 v81; // [rsp+E0h] [rbp+20h]
  __int64 v82; // [rsp+E8h] [rbp+28h]
  __int64 v83; // [rsp+F0h] [rbp+30h]
  __int64 v84; // [rsp+F8h] [rbp+38h]
  Scaleform::GFx::Resource *v85; // [rsp+100h] [rbp+40h]
  __int64 v86; // [rsp+190h] [rbp+D0h]
  __int64 v87; // [rsp+198h] [rbp+D8h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v88; // [rsp+1A0h] [rbp+E0h]
  Scaleform::LogMessageId id; // [rsp+1A8h] [rbp+E8h] BYREF

  v84 = -2i64;
  v3 = imageInfoArray;
  Size = imageInfoArray->Data.Size;
  v59 = 0i64;
  pObject = 0i64;
  if ( pmgr->pImpl->pMovieDef.pObject )
    pObject = (Scaleform::GFx::FileOpenerBase *)pmgr->pImpl->pMovieDef.pObject;
  v64.pObject = pObject;
  v6 = &pmgr->Scaleform::GFx::StateBag;
  v7 = Scaleform::GFx::StateBag::GetImageCreator(&pmgr->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v7 )
  {
    ImageCreator = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetImageCreator(v6, &v67);
    if ( *ImageCreator )
      Scaleform::Render::RenderBuffer::AddRef(*ImageCreator);
    v59 = (Scaleform::Render::RenderBuffer *)*ImageCreator;
    if ( v67.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v67.pObject);
  }
  v9 = 0i64;
  v56 = 0i64;
  if ( !Size )
    goto LABEL_101;
  v10 = 0i64;
  while ( 1 )
  {
    Data = v3->Data.Data;
    p_Url = &v3->Data.Data[v10].Url;
    IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(p_Url, 0i64, 0i64);
    pdata.pResource.pObject = 0i64;
    pdata.pBinding = 0i64;
    v14 = 0i64;
    if ( IsProtocolImage )
    {
      v29 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v87 + 24) + 48i64) + 72i64);
      v68 = 1;
      v69 = v29;
      v70 = 0;
      v71 = 1;
      v72 = 0i64;
      v73 = 0i64;
      v74 = 0i64;
      v75 = 0i64;
      v30 = (Scaleform::GFx::StateBag *)v6->vfptr->GetStateBagImpl(v6);
      ImageFileHandlerRegistry = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(
                                   v30,
                                   (Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *)&v65);
      v32 = (Scaleform::GFx::StateBag *)v6->vfptr->GetStateBagImpl(v6);
      FileOpener = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener(v32, &v64);
      Log = Scaleform::GFx::StateBag::GetLog(v6, &v62);
      v35 = (__int64)ImageFileHandlerRegistry->pObject;
      v36 = (__int64)Log->pObject;
      v73 = *FileOpener;
      v72 = v36;
      v74 = v35;
      if ( v62.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v62.pObject);
      if ( v64.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v64.pObject);
      if ( v65.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v65.pObject);
      if ( !v59 )
      {
        LODWORD(result.pObject) = 135168;
        Scaleform::LogDebugMessage(
          (Scaleform::LogMessageId)&result,
          "Image resource creation failed - ImageCreator not installed");
        goto LABEL_96;
      }
      v14 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *, int *, Scaleform::String *))v59->vfptr[1].__vecDelDtor)(
              v59,
              &v68,
              p_Url);
      goto LABEL_68;
    }
    if ( !v64.pObject )
    {
      v15 = Scaleform::GFx::StateBag::GetLog(v6, &v63)->pObject;
      if ( v63.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v63.pObject);
      if ( v15 )
      {
        v16 = Scaleform::GFx::StateBag::GetLog(v6, &v66);
        Scaleform::Log::LogWarning(
          v16->pObject,
          "DrawText::ProcessImageTags: cant find a resource since there is no moviedef\n");
        if ( v66.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pObject);
      }
      v17 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        pLib = v17->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v17);
          v17->pLib = 0i64;
        }
LABEL_87:
        v17->vfptr->__vecDelDtor(v17, 1u);
        goto LABEL_89;
      }
      goto LABEL_89;
    }
    if ( Scaleform::GFx::MovieDefImpl::GetExportedResource(
           (Scaleform::GFx::MovieDefImpl *)v64.pObject,
           &pdata,
           p_Url,
           0i64) )
    {
      break;
    }
    v19 = Scaleform::GFx::StateBag::GetLog(v6, &v66)->pObject;
    if ( v66.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pObject);
    if ( v19 )
    {
      v20 = Scaleform::GFx::StateBag::GetLog(v6, &v63);
      Scaleform::Log::LogWarning(
        v20->pObject,
        "DrawText::ProcessImageTags: cant find a resource for export name %s\n",
        (const char *)((p_Url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( v63.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v63.pObject);
    }
    v17 = pdata.pResource.pObject;
    if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
    {
      v21 = v17->pLib;
      if ( v21 )
      {
        v21->vfptr[1].__vecDelDtor(v21, (unsigned int)v17);
        v17->pLib = 0i64;
      }
      goto LABEL_87;
    }
LABEL_89:
    v56 = ++v9;
    ++v10;
    if ( v9 >= (unsigned __int64)v59 )
      goto LABEL_101;
    v3 = v88;
  }
  if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))pdata.pResource.pObject->vfptr->GetResourceTypeCode)(pdata.pResource.pObject) & 0xFF00) != 256 )
    goto LABEL_81;
  v22 = pdata.pResource.pObject;
  if ( pdata.pResource.pObject )
    _InterlockedExchangeAdd(&pdata.pResource.pObject->RefCount.Value, 1u);
  v85 = v22;
  if ( !v22 )
  {
    v23 = Scaleform::GFx::StateBag::GetLog(v6, &v61)->pObject;
    if ( v61.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v61.pObject);
    if ( v23 )
    {
      v24 = Scaleform::GFx::StateBag::GetLog(v6, &v65);
      Scaleform::Log::LogWarning(
        v24->pObject,
        "DrawText::ProcessImageTags: cant load the image %s\n",
        (const char *)((p_Url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( v65.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v65.pObject);
    }
    v17 = pdata.pResource.pObject;
    if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
    {
      v25 = v17->pLib;
      if ( v25 )
      {
        v25->vfptr[1].__vecDelDtor(v25, (unsigned int)v17);
        v17->pLib = 0i64;
      }
      goto LABEL_87;
    }
    goto LABEL_89;
  }
  if ( (*((unsigned int (__fastcall **)(Scaleform::GFx::ResourceVtbl *))v22[1].vfptr->__vecDelDtor + 3))(v22[1].vfptr) )
  {
    vfptr = v22[1].vfptr;
    if ( vfptr )
      (*((void (__fastcall **)(Scaleform::GFx::ResourceVtbl *))vfptr->__vecDelDtor + 1))(v22[1].vfptr);
    v57 = (__int64)vfptr;
LABEL_55:
    if ( !_InterlockedDecrement(&v22->RefCount.Value) )
    {
      v28 = v22->pLib;
      if ( v28 )
      {
        v28->vfptr[1].__vecDelDtor(v28, (unsigned int)v22);
        v22->pLib = 0i64;
      }
      v22->vfptr->__vecDelDtor(v22, 1u);
    }
    v14 = v57;
LABEL_68:
    if ( !v14 )
    {
      v37 = p_Url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      id.Id = 135168;
      Scaleform::LogDebugMessage(
        (Scaleform::LogMessageId)&id,
        "Image %s wasnt created in ProcessImageTags",
        (const char *)(v37 + 12));
      v38 = pdata.pResource.pObject;
      if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
      {
        v39 = v38->pLib;
        if ( v39 )
        {
          v39->vfptr[1].__vecDelDtor(v39, (unsigned int)v38);
          v38->pLib = 0i64;
        }
        v38->vfptr->__vecDelDtor(v38, 1u);
      }
      v9 = v56;
      goto LABEL_89;
    }
    (*(void (__fastcall **)(__int64, Scaleform::Ptr<Scaleform::Log> *))(*(_QWORD *)v14 + 48i64))(v14, &v61);
    v40 = Data[v10].pTextImageDesc.pObject;
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
    v41 = v40->pImage.pObject;
    if ( v41 )
      ((void (__fastcall *)(Scaleform::Render::Image *))v41->vfptr[2].__vecDelDtor)(v41);
    v40->pImage.pObject = (Scaleform::Render::Image *)v14;
    v42 = (float)(LODWORD(v62.pObject) - LODWORD(v61.pObject));
    v43 = (float)(HIDWORD(v62.pObject) - HIDWORD(v61.pObject));
    Width = Data[v10].Width;
    if ( !Width )
      Width = 20 * (LODWORD(v62.pObject) - LODWORD(v61.pObject));
    v45 = (float)Width;
    Height = Data[v10].Height;
    if ( !Height )
      Height = 20 * (HIDWORD(v62.pObject) - HIDWORD(v61.pObject));
    v47 = (float)Height;
    VSpace = (float)Data[v10].VSpace;
    Data[v10].pTextImageDesc.pObject->ScreenWidth = v45;
    Data[v10].pTextImageDesc.pObject->ScreenHeight = (float)Height;
    Data[v10].pTextImageDesc.pObject->BaseLineY = (float)((float)(v43 * 20.0) + VSpace) * 0.050000001;
    Data[v10].pTextImageDesc.pObject->Matrix.M[1][3] = COERCE_FLOAT(LODWORD(Data[v10].pTextImageDesc.pObject->BaseLineY) ^ _xmm[0])
                                                     + Data[v10].pTextImageDesc.pObject->Matrix.M[1][3];
    v49 = (float *)Data[v10].pTextImageDesc.pObject;
    v50 = v47 / v43;
    v51 = v45 / v42;
    v49[12] = v51 * v49[12];
    v49[13] = v51 * v49[13];
    v49[14] = v51 * v49[14];
    v49[15] = v51 * v49[15];
    v49[16] = v50 * v49[16];
    v49[17] = v50 * v49[17];
    v49[18] = v50 * v49[18];
    v49[19] = v50 * v49[19];
    *(_BYTE *)(v86 + 347) |= 2u;
    v9 = v56;
LABEL_81:
    if ( v14 )
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
    v17 = pdata.pResource.pObject;
    if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
    {
      v52 = v17->pLib;
      if ( v52 )
      {
        v52->vfptr[1].__vecDelDtor(v52, (unsigned int)v17);
        v17->pLib = 0i64;
      }
      goto LABEL_87;
    }
    goto LABEL_89;
  }
  if ( v59 )
  {
    v27 = *(_QWORD *)(v87 + 32);
    v76 = 3;
    v77 = v27;
    v78 = 1;
    v79 = 1;
    v80 = 0i64;
    v81 = 0i64;
    v82 = 0i64;
    v83 = 0i64;
    v57 = ((__int64 (__fastcall *)(Scaleform::Render::RenderBuffer *, int *, Scaleform::GFx::ResourceVtbl *))v59->vfptr[4].__vecDelDtor)(
            v59,
            &v76,
            v22[1].vfptr);
    goto LABEL_55;
  }
  HIDWORD(result.pObject) = 135168;
  Scaleform::LogDebugMessage(
    (Scaleform::LogMessageId)((char *)&result.pObject + 4),
    "ImageCreator is null in DrawText::ProcessImageTags");
  if ( !_InterlockedDecrement(&v22->RefCount.Value) )
  {
    v53 = v22->pLib;
    if ( v53 )
    {
      v53->vfptr[1].__vecDelDtor(v53, (unsigned int)v22);
      v22->pLib = 0i64;
    }
    v22->vfptr->__vecDelDtor(v22, 1u);
  }
LABEL_96:
  v54 = pdata.pResource.pObject;
  if ( pdata.pResource.pObject && !_InterlockedDecrement(&pdata.pResource.pObject->RefCount.Value) )
  {
    v55 = v54->pLib;
    if ( v55 )
    {
      v55->vfptr[1].__vecDelDtor(v55, (unsigned int)v54);
      v54->pLib = 0i64;
    }
    v54->vfptr->__vecDelDtor(v54, 1u);
  }
LABEL_101:
  if ( v59 )
    Scaleform::RefCountImpl::Release(v59);
}

// File Line: 559
// RVA: 0x895870
void __fastcall Scaleform::GFx::DrawTextManager::DrawTextManager(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::GFx::Loader *ploader)
{
  Scaleform::MemoryHeap *v4; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v5; // rax
  Scaleform::GFx::DrawTextManagerImpl *v6; // rax
  Scaleform::GFx::DrawTextManagerImpl *v7; // r14
  Scaleform::GFx::MovieDef *pObject; // rdi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::StateBagImpl *v10; // rax
  Scaleform::GFx::StateBagImpl *v11; // rax
  Scaleform::GFx::StateBagImpl *v12; // r14
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // rdi
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::Log *v15; // rdi
  Scaleform::Ptr<Scaleform::Log> *Log; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  Scaleform::Log *v18; // rdi
  Scaleform::Log *v19; // rax
  Scaleform::Render::Text::Allocator *v20; // rax
  Scaleform::Render::Text::Allocator *v21; // r14
  Scaleform::GFx::DrawTextManagerImpl *v22; // rdi
  Scaleform::RefCountNTSImpl *v23; // rcx
  __int64 v24; // rdi
  Scaleform::GFx::StateBagImpl *v25; // rax
  Scaleform::GFx::StateBag *v26; // rax
  Scaleform::GFx::DrawTextManagerImpl *v27; // r14
  Scaleform::RefCountNTSImpl *v28; // rcx
  Scaleform::GFx::FontLib *v29; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontLib> *FontLib; // rax
  Scaleform::GFx::StateBag *v31; // rcx
  Scaleform::GFx::FontMap *v32; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontMap> *FontMap; // rax
  Scaleform::GFx::StateBag *v34; // rcx
  Scaleform::GFx::FontProvider *v35; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *FontProvider; // rax
  Scaleform::GFx::StateBag *v37; // rcx
  Scaleform::GFx::ResourceLib *pStrongResourceLib; // rdi
  Scaleform::GFx::ResourceWeakLib *pWeakLib; // r14
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
  Scaleform::Render::ContextImpl::Entry *EntryHelper; // r14
  Scaleform::GFx::DrawTextManagerImpl *v53; // rsi
  Scaleform::Render::ContextImpl::Entry *v54; // rcx
  Scaleform::GFx::DrawTextManagerImpl *v56; // rsi
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v57; // rax
  Scaleform::Render::RenderBuffer *v58; // rcx
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v59; // [rsp+20h] [rbp-89h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontLib> v60; // [rsp+28h] [rbp-81h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v61; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontLib> v62; // [rsp+38h] [rbp-71h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontMap> v63; // [rsp+40h] [rbp-69h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontMap> v64; // [rsp+48h] [rbp-61h] BYREF
  void *v65; // [rsp+50h] [rbp-59h]
  unsigned int v66; // [rsp+60h] [rbp-49h] BYREF
  __int64 v67; // [rsp+68h] [rbp-41h]
  __int64 v68; // [rsp+70h] [rbp-39h]
  __int64 v69; // [rsp+78h] [rbp-31h]
  __int64 v70; // [rsp+80h] [rbp-29h]
  __int64 v71; // [rsp+88h] [rbp-21h]
  __int64 v72; // [rsp+90h] [rbp-19h]
  __int64 v73; // [rsp+98h] [rbp-11h]
  __int64 v74; // [rsp+A0h] [rbp-9h]
  Scaleform::GFx::ResourceLib *v75; // [rsp+A8h] [rbp-1h]
  Scaleform::Log *v76; // [rsp+B0h] [rbp+7h]
  Scaleform::Render::ContextImpl::RTHandle v77; // [rsp+118h] [rbp+6Fh] BYREF
  Scaleform::Ptr<Scaleform::Log> result; // [rsp+120h] [rbp+77h] BYREF
  Scaleform::Ptr<Scaleform::Log> v79; // [rsp+128h] [rbp+7Fh] BYREF

  v74 = -2i64;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::`vftable;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::`vftable;
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::GFx::StateBag};
  v66 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this)->Info.Desc.Flags & 0x1000;
  v67 = 16i64;
  v68 = 0x4000i64;
  v69 = 0x4000i64;
  v70 = -1i64;
  v71 = 0i64;
  v72 = 0i64;
  v73 = 0i64;
  v4 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, unsigned int *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  "DrawText Manager",
                                  &v66);
  this->pHeap = v4;
  v5 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v4->vfptr->Alloc(v4, 392ui64, 0i64);
  v77.pData.pObject = v5;
  if ( v5 )
  {
    Scaleform::GFx::DrawTextManagerImpl::DrawTextManagerImpl((Scaleform::GFx::DrawTextManagerImpl *)v5);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  this->pImpl = v7;
  pObject = v7->pMovieDef.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    pLib = pObject->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
      pObject->pLib = 0i64;
    }
    pObject->Scaleform::GFx::Resource::vfptr->__vecDelDtor(pObject, 1u);
  }
  v7->pMovieDef.pObject = 0i64;
  v10 = (Scaleform::GFx::StateBagImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          88i64);
  v65 = v10;
  if ( v10 )
  {
    Scaleform::GFx::StateBagImpl::StateBagImpl(v10, 0i64);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pImpl = this->pImpl;
  v14 = (Scaleform::Render::RenderBuffer *)pImpl->pStateBag.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  pImpl->pStateBag.pObject = v12;
  v15 = Scaleform::GFx::StateBag::GetLog(ploader, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v15 )
  {
    Log = Scaleform::GFx::StateBag::GetLog(ploader, &v79);
    Scaleform::GFx::StateBag::SetLog(&this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag, Log->pObject);
    v17 = (Scaleform::Render::RenderBuffer *)v79.pObject;
    if ( !v79.pObject )
      goto LABEL_25;
    goto LABEL_24;
  }
  v18 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                            Scaleform::Memory::pGlobalHeap,
                            16i64);
  v65 = v18;
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
  v76 = v18;
  Scaleform::GFx::StateBag::SetLog(&this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag, v18);
  if ( v18 )
  {
    v17 = (Scaleform::Render::RenderBuffer *)v18;
LABEL_24:
    Scaleform::RefCountImpl::Release(v17);
  }
LABEL_25:
  v19 = (Scaleform::Log *)this->pHeap->vfptr->Alloc(this->pHeap, 144i64, 0i64);
  result.pObject = v19;
  if ( v19 )
  {
    Scaleform::Render::Text::Allocator::Allocator((Scaleform::Render::Text::Allocator *)v19, this->pHeap, 0);
    v21 = v20;
  }
  else
  {
    v21 = 0i64;
  }
  v22 = this->pImpl;
  v23 = v22->pTextAllocator.pObject;
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
  v22->pTextAllocator.pObject = v21;
  v24 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
          Scaleform::Memory::pGlobalHeap,
          64i64);
  result.pObject = (Scaleform::Log *)v24;
  if ( v24 )
  {
    v25 = this->pImpl->pStateBag.pObject;
    if ( v25 )
      v26 = &v25->Scaleform::GFx::StateBag;
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
  v27 = this->pImpl;
  v28 = v27->pFontStates.pObject;
  if ( v28 )
    Scaleform::RefCountNTSImpl::Release(v28);
  v27->pFontStates.pObject = (Scaleform::GFx::FontManagerStates *)v24;
  v29 = Scaleform::GFx::StateBag::GetFontLib(ploader, &v60)->pObject;
  if ( v60.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v60.pObject);
  if ( v29 )
  {
    FontLib = Scaleform::GFx::StateBag::GetFontLib(ploader, &v62);
    v31 = &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag;
    v31->vfptr->SetState(v31, (Scaleform::GFx::State::StateType)20i64, FontLib->pObject);
    if ( v62.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v62.pObject);
  }
  v32 = Scaleform::GFx::StateBag::GetFontMap(ploader, &v64)->pObject;
  if ( v64.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v64.pObject);
  if ( v32 )
  {
    FontMap = Scaleform::GFx::StateBag::GetFontMap(ploader, &v63);
    v34 = &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag;
    v34->vfptr->SetState(v34, State_UserData|0x10, FontMap->pObject);
    if ( v63.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v63.pObject);
  }
  v35 = Scaleform::GFx::StateBag::GetFontProvider(ploader, &v61)->pObject;
  if ( v61.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v61.pObject);
  if ( v35 )
  {
    FontProvider = Scaleform::GFx::StateBag::GetFontProvider(ploader, &v59);
    v37 = &this->pImpl->pStateBag.pObject->Scaleform::GFx::StateBag;
    v37->vfptr->SetState(v37, State_ProjectionMatrix3D|0x10, FontProvider->pObject);
    if ( v59.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v59.pObject);
  }
  pStrongResourceLib = ploader->pStrongResourceLib;
  if ( pStrongResourceLib )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)ploader->pStrongResourceLib);
  v75 = pStrongResourceLib;
  if ( pStrongResourceLib )
  {
    pWeakLib = pStrongResourceLib->pWeakLib;
    v40 = this->pImpl;
    if ( pWeakLib )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pStrongResourceLib->pWeakLib);
  }
  else
  {
    v41 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                              Scaleform::Memory::pGlobalHeap,
                              80i64);
    result.pObject = v41;
    if ( v41 )
    {
      Scaleform::GFx::ResourceWeakLib::ResourceWeakLib((Scaleform::GFx::ResourceWeakLib *)v41, 0i64);
      pWeakLib = v42;
    }
    else
    {
      pWeakLib = 0i64;
    }
    v40 = this->pImpl;
  }
  v43 = (Scaleform::Render::RenderBuffer *)v40->pWeakLib.pObject;
  if ( v43 )
    Scaleform::RefCountImpl::Release(v43);
  v40->pWeakLib.pObject = pWeakLib;
  v44 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                            this->pHeap,
                            104i64);
  result.pObject = v44;
  if ( v44 )
  {
    Scaleform::GFx::FontManager::FontManager(
      (Scaleform::GFx::FontManager *)v44,
      this->pImpl->pWeakLib.pObject,
      this->pImpl->pFontStates.pObject);
    v46 = v45;
  }
  else
  {
    v46 = 0i64;
  }
  v47 = this->pImpl;
  v48 = (Scaleform::Render::RenderBuffer *)v47->pFontManager.pObject;
  if ( v48 )
    Scaleform::RefCountImpl::Release(v48);
  v47->pFontManager.pObject = v46;
  v49 = this->pImpl;
  v50 = (Scaleform::Log *)v49->RenderContext.pHeap->vfptr->Alloc(v49->RenderContext.pHeap, 208ui64, 0i64);
  v51 = (Scaleform::Render::ContextImpl::EntryData *)v50;
  result.pObject = v50;
  v79.pObject = v50;
  if ( v50 )
    Scaleform::Render::TreeRoot::NodeData::NodeData((Scaleform::Render::TreeRoot::NodeData *)v50);
  EntryHelper = Scaleform::Render::ContextImpl::Context::createEntryHelper(&v49->RenderContext, v51);
  v53 = this->pImpl;
  v54 = v53->pRootNode.pObject;
  if ( v53->pRootNode.pObject )
  {
    if ( v54->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v54);
  }
  v53->pRootNode.pObject = (Scaleform::Render::TreeRoot *)EntryHelper;
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this->pImpl->pRootNode.pObject & 0xFFFFFFFFFFFFF000ui64)
                                         + 0x20)
                             + 8i64
                             * (unsigned int)((int)((int)&this->pImpl->pRootNode.pObject[-1]
                                                  - ((__int64)this->pImpl->pRootNode.pObject & 0xFFFFF000))
                                            / 56)
                             + 40)
                 + 204i64) )
    *(_DWORD *)(&Scaleform::Render::ContextImpl::Entry::getWritableData(this->pImpl->pRootNode.pObject, 0x1000u)[12].Flags
              + 1) = 0;
  Scaleform::Render::ContextImpl::RTHandle::RTHandle(&v77, this->pImpl->pRootNode.pObject);
  v56 = this->pImpl;
  v57 = v77.pData.pObject;
  if ( v77.pData.pObject )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v77.pData.pObject);
    v57 = v77.pData.pObject;
  }
  v58 = (Scaleform::Render::RenderBuffer *)v56->DispHandle.pData.pObject;
  if ( v58 )
  {
    Scaleform::RefCountImpl::Release(v58);
    v57 = v77.pData.pObject;
  }
  v56->DispHandle.pData.pObject = v57;
  Scaleform::Render::ContextImpl::RTHandle::~RTHandle(&v77);
  if ( pStrongResourceLib )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pStrongResourceLib);
}fer *)v56->DispHandle.pData.pObject;
  if ( v58 )
  {
    Sc

// File Line: 608
// RVA: 0x8A3FD0
void __fastcall Scaleform::GFx::DrawTextManager::~DrawTextManager(Scaleform::GFx::DrawTextManager *this)
{
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // rdi

  this->Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,2>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::RefCountBaseNTS<Scaleform::GFx::DrawTextManager,2>};
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::DrawTextManager::`vftable{for `Scaleform::GFx::StateBag};
  pImpl = this->pImpl;
  if ( pImpl )
  {
    Scaleform::GFx::DrawTextManagerImpl::~DrawTextManagerImpl(this->pImpl);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImpl);
  }
  this->pHeap->vfptr->Release(this->pHeap);
  this->Scaleform::GFx::StateBag::vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
}

// File Line: 629
// RVA: 0x89EC10
void __fastcall Scaleform::GFx::DrawTextManager::TextParams::TextParams(
        Scaleform::GFx::DrawTextManager::TextParams *this)
{
  Scaleform::String::String(&this->FontName);
  this->TextColor.Raw = -16777216;
  *(_QWORD *)&this->HAlignment = 0i64;
  this->FontStyle = 0;
  this->FontSize = 12.0;
  Scaleform::String::operator=(&this->FontName, "Times New Roman");
  *(_WORD *)&this->Underline = 256;
  this->WordWrap = 1;
}

// File Line: 642
// RVA: 0x906D90
void __fastcall Scaleform::GFx::DrawTextManager::SetDefaultTextParams(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::GFx::DrawTextManager::TextParams *params)
{
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // rbx
  Scaleform::GFx::DrawText::VAlignment VAlignment; // eax
  Scaleform::String *p_FontName; // rdx

  pImpl = this->pImpl;
  pImpl->DefaultTextParams.TextColor.Raw = params->TextColor.Raw;
  pImpl->DefaultTextParams.HAlignment = params->HAlignment;
  VAlignment = params->VAlignment;
  p_FontName = &params->FontName;
  pImpl->DefaultTextParams.VAlignment = VAlignment;
  pImpl->DefaultTextParams.FontStyle = HIDWORD(p_FontName[-2].HeapTypeBits);
  pImpl->DefaultTextParams.FontSize = *(float *)&p_FontName[-1].pData;
  Scaleform::String::operator=(&pImpl->DefaultTextParams.FontName, p_FontName);
  pImpl->DefaultTextParams.Underline = params->Underline;
  pImpl->DefaultTextParams.Multiline = params->Multiline;
  pImpl->DefaultTextParams.WordWrap = params->WordWrap;
}

// File Line: 648
// RVA: 0x8D6820
Scaleform::GFx::DrawTextManager::TextParams *__fastcall Scaleform::GFx::DrawTextManager::GetDefaultTextParams(
        Scaleform::GFx::DrawTextManager *this)
{
  return &this->pImpl->DefaultTextParams;
}

// File Line: 654
// RVA: 0x90DC20
void __fastcall Scaleform::GFx::DrawTextManager::SetTextParams(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Text::DocView *pdoc,
        Scaleform::GFx::DrawTextManager::TextParams *txtParams,
        Scaleform::Render::Text::TextFormat *tfmt)
{
  __int16 v7; // si
  char v8; // r14
  Scaleform::GFx::DrawText::FontStyle FontStyle; // ecx
  __int32 v10; // ecx
  __int32 v11; // ecx
  bool v12; // dl
  bool v13; // dl
  float FontSize; // xmm0_4
  int v15; // eax
  Scaleform::Render::Text::ParagraphFormat defaultParagraphFmt; // [rsp+8h] [rbp-51h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [rsp+38h] [rbp-21h] BYREF
  __int64 v18; // [rsp+88h] [rbp+2Fh]
  Scaleform::Render::Text::ParagraphFormat *src; // [rsp+D8h] [rbp+7Fh]

  v18 = -2i64;
  Scaleform::Render::Text::TextFormat::TextFormat(
    (Scaleform::Render::Text::TextFormat *)&fmt.FontList.pHeap,
    this->pHeap);
  v7 = 0;
  defaultParagraphFmt.pAllocator = 0i64;
  v8 = 1;
  defaultParagraphFmt.RefCount = 1;
  memset(&defaultParagraphFmt.pTabStops, 0, 20);
  if ( tfmt )
    Scaleform::Render::Text::TextFormat::operator=(&fmt, tfmt);
  if ( src )
    Scaleform::Render::Text::ParagraphFormat::operator=(&defaultParagraphFmt, src);
  fmt.ColorV = txtParams->TextColor.Raw;
  fmt.PresentMask |= 1u;
  FontStyle = txtParams->FontStyle;
  if ( !FontStyle )
  {
    v13 = 0;
    goto LABEL_13;
  }
  v10 = FontStyle - 1;
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
  Scaleform::Render::Text::TextFormat::SetFontName(&fmt, &txtParams->FontName);
  FontSize = txtParams->FontSize;
  if ( FontSize >= 3276.8 )
    LOWORD(v15) = -1;
  else
    v15 = (int)(float)(FontSize * 20.0);
  fmt.FontSize = v15;
  fmt.PresentMask |= 8u;
  Scaleform::Render::Text::TextFormat::SetUnderline(&fmt, txtParams->Underline);
  switch ( txtParams->HAlignment )
  {
    case Align_TopCenter:
      v7 = 1;
      break;
    case Align_BottomCenter:
      v7 = 3;
      break;
    case Align_CenterLeft:
      v7 = 2;
      break;
  }
  defaultParagraphFmt.PresentMask = defaultParagraphFmt.PresentMask ^ (defaultParagraphFmt.PresentMask ^ (v7 << 9)) & 0x600 | 1;
  if ( txtParams->VAlignment == VAlign_Top )
  {
    v8 = 3;
  }
  else if ( txtParams->VAlignment == VAlign_Bottom )
  {
    v8 = 2;
  }
  pdoc->AlignProps &= 0xF3u;
  pdoc->AlignProps |= 4 * (v8 & 3);
  pdoc->RTFlags |= 1u;
  if ( txtParams->Multiline )
  {
    pdoc->Flags |= 4u;
    if ( txtParams->WordWrap )
      Scaleform::Render::Text::DocView::SetWordWrap(pdoc);
  }
  Scaleform::Render::Text::DocView::SetTextFormat(pdoc, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::DocView::SetParagraphFormat(pdoc, &defaultParagraphFmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(pdoc->pDocument.pObject, &fmt);
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(pdoc->pDocument.pObject, &defaultParagraphFmt);
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&defaultParagraphFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 761
// RVA: 0x8BFDE0
Scaleform::Render::TreeNode **__fastcall Scaleform::GFx::DrawTextManager::CreateHtmlText(
        Scaleform::GFx::DrawTextManager *this,
        const char *putf8Str,
        Scaleform::Render::Rect<float> *viewRect,
        Scaleform::GFx::DrawTextManager::TextParams *ptxtParams,
        unsigned int depth)
{
  Scaleform::GFx::DrawTextImpl *v9; // rax
  Scaleform::Render::TreeNode **v10; // rax
  Scaleform::Render::TreeNode **v11; // rbx
  Scaleform::Render::Text::DocView *DocView; // rax
  Scaleform::Render::TreeRoot *pObject; // rcx

  v9 = (Scaleform::GFx::DrawTextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                         this->pHeap,
                                         40i64);
  if ( v9 )
  {
    Scaleform::GFx::DrawTextImpl::DrawTextImpl(v9, this);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  ((void (__fastcall *)(Scaleform::Render::TreeNode **, Scaleform::Render::Rect<float> *))(*v11)[2].PNode.Scaleform::Render::ContextImpl::Entry::pPrev)(
    v11,
    viewRect);
  if ( !ptxtParams )
    ptxtParams = &this->pImpl->DefaultTextParams;
  DocView = Scaleform::Render::TreeText::GetDocView((Scaleform::Render::TreeText *)v11[3]);
  Scaleform::GFx::DrawTextManager::SetTextParams(this, DocView, ptxtParams, 0i64, 0i64);
  ((void (__fastcall *)(Scaleform::Render::TreeNode **, const char *, __int64))(*v11)[1].pPrev)(v11, putf8Str, -1i64);
  pObject = this->pImpl->pRootNode.pObject;
  if ( depth == -1 )
    Scaleform::Render::TreeContainer::Add(pObject, v11[3]);
  else
    Scaleform::Render::TreeContainer::Insert(pObject, depth, v11[3]);
  return v11;
}

// File Line: 935
// RVA: 0x8DE3F0
Scaleform::GFx::StateBag *__fastcall Scaleform::GFx::DrawTextManager::GetStateBagImpl(
        Scaleform::GFx::DrawTextManager *this)
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
  Scaleform::Ptr<Scaleform::GFx::Translator> *Translator; // r14
  Scaleform::Ptr<Scaleform::GFx::FontProvider> *FontProvider; // rdi
  Scaleform::Ptr<Scaleform::GFx::FontMap> *FontMap; // rbx
  Scaleform::Ptr<Scaleform::GFx::FontLib> *FontLib; // rax
  Scaleform::Ptr<Scaleform::GFx::FontLib> v6; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontMap> v7; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v8; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+88h] [rbp+20h] BYREF

  Translator = Scaleform::GFx::StateBag::GetTranslator(&this->Scaleform::GFx::StateBag, &result);
  FontProvider = Scaleform::GFx::StateBag::GetFontProvider(&this->Scaleform::GFx::StateBag, &v8);
  FontMap = Scaleform::GFx::StateBag::GetFontMap(&this->Scaleform::GFx::StateBag, &v7);
  FontLib = Scaleform::GFx::StateBag::GetFontLib(&this->Scaleform::GFx::StateBag, &v6);
  Scaleform::GFx::FontManagerStates::CheckStateChange(
    this->pImpl->pFontStates.pObject,
    FontLib->pObject,
    FontMap->pObject,
    FontProvider->pObject,
    Translator->pObject);
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
void __fastcall Scaleform::GFx::DrawTextManager::SetViewport(
        Scaleform::GFx::DrawTextManager *this,
        Scaleform::Render::Viewport *vp)
{
  Scaleform::GFx::DrawTextManagerImpl *pImpl; // rcx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-28h] BYREF

  Scaleform::Render::TreeRoot::SetViewport(this->pImpl->pRootNode.pObject, vp);
  pImpl = this->pImpl;
  *(_OWORD *)&m.M[0][0] = 0x3D4CCCCDui64;
  m.M[1][0] = 0.0;
  *(_QWORD *)&m.M[1][1] = 1028443341i64;
  m.M[1][3] = 0.0;
  Scaleform::Render::TreeNode::SetMatrix(pImpl->pRootNode.pObject, &m);
}

// File Line: 977
// RVA: 0x8B98A0
void __fastcall Scaleform::GFx::DrawTextManager::Capture(Scaleform::GFx::DrawTextManager *this, bool onChangeOnly)
{
  if ( !onChangeOnly || Scaleform::Render::ContextImpl::Context::HasChanges(&this->pImpl->RenderContext) )
    Scaleform::Render::ContextImpl::Context::Capture(&this->pImpl->RenderContext);
}

// File Line: 988
// RVA: 0x8D6CC0
Scaleform::Render::ContextImpl::DisplayHandle<Scaleform::Render::TreeRoot> *__fastcall Scaleform::GFx::DrawTextManager::GetDisplayHandle(
        Scaleform::GFx::DrawTextManager *this)
{
  return &this->pImpl->DispHandle;
}

