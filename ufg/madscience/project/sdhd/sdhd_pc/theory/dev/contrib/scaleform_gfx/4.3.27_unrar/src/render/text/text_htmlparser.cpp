// File Line: 103
// RVA: 0x92BE70
Scaleform::Render::Text::SGMLElementDesc *__fastcall Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
        Scaleform::Render::Text::SGMLElementDesc *this,
        const wchar_t *lookForElemName,
        unsigned __int64 nameSize,
        Scaleform::Render::Text::SGMLElementDesc *ptable,
        unsigned __int64 tableSize)
{
  unsigned __int64 v5; // rsi
  __int64 v10; // rbx
  __int64 v11; // rsi

  v5 = 0i64;
  v10 = (__int64)ptable;
  while ( v10 > 0 )
  {
    if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
           (const wchar_t *)this,
           *(const char **)(nameSize + 16 * ((v10 >> 1) + v5)),
           (unsigned __int64)lookForElemName) <= 0 )
    {
      v10 >>= 1;
    }
    else
    {
      v5 += (v10 >> 1) + 1;
      v10 += -1 - (v10 >> 1);
    }
  }
  if ( v5 >= (unsigned __int64)ptable )
    return 0i64;
  v11 = 2 * v5;
  if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
         (const wchar_t *)this,
         *(const char **)(nameSize + 8 * v11),
         (unsigned __int64)lookForElemName) )
  {
    return 0i64;
  }
  else
  {
    return (Scaleform::Render::Text::SGMLElementDesc *)(nameSize + 8 * v11);
  }
}

// File Line: 142
// RVA: 0x92DBE0
char __fastcall Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(
        Scaleform::Render::Text::StyledText *this,
        const wchar_t *phtml,
        unsigned __int64 htmlSize,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::Text::StyledText *v7; // r15
  __int64 v9; // r13
  Scaleform::Render::Text::TextFormat *pObject; // rdx
  Scaleform::Render::Text::ParagraphFormat *v11; // rcx
  unsigned int *pTabStops; // rdi
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  unsigned int v14; // ebx
  Scaleform::Render::Text::HTMLImageTagDesc *v15; // rax
  Scaleform::Render::Text::FontHandle *v16; // rcx
  int Next; // r12d
  char v18; // bl
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v19; // rsi
  unsigned __int64 Size; // rbx
  const wchar_t *v21; // rdi
  Scaleform::Render::Text::SGMLElementDesc *v22; // r14
  Scaleform::Render::Text::SGMLElementDesc *v23; // rax
  Scaleform::Render::Text::SGMLElementDesc *v24; // rsi
  Scaleform::Render::Text::SGMLElementDesc *pElemDesc; // rdx
  unsigned int PresentMask; // edi
  char v27; // r14
  int v28; // edi
  unsigned __int64 StartPos; // r15
  const char *v30; // rdx
  int v31; // edi
  Scaleform::Render::Text::StyledText *v32; // rdi
  unsigned __int64 Length; // rbx
  const char *v34; // rdx
  unsigned __int64 v35; // r8
  unsigned __int64 v36; // rdx
  unsigned __int64 v37; // rdi
  Scaleform::Render::Text::Paragraph *LastParagraph; // rax
  unsigned __int64 v39; // rax
  Scaleform::Render::Text::TextFormat *p_TextFmt; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v41; // rax
  int v42; // r14d
  Scaleform::Render::Text::HTMLElementsEnum ElemId; // ecx
  unsigned __int64 v44; // rdi
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *Data; // rsi
  Scaleform::Render::Text::Paragraph *appended; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v47; // rbx
  Scaleform::StringDH *p_Url; // rcx
  Scaleform::Render::Text::SGMLElementDesc *v49; // rax
  int v50; // eax
  int v51; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *v52; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v53; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v54; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v55; // rcx
  __int64 v56; // rcx
  bool v57; // zf
  __int64 v58; // rcx
  Scaleform::Render::Text::TextFormat *p_that; // rdi
  Scaleform::Render::Text::ParagraphFormat *p_pdefParaFmt; // rsi
  Scaleform::Render::Text::HTMLImageTagDesc *v61; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v62; // rcx
  const char *v63; // rdx
  unsigned __int64 v64; // rbx
  unsigned __int64 v65; // rdi
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v66; // rsi
  Scaleform::Render::Text::TextFormat *v67; // r12
  __int64 v68; // rbx
  Scaleform::Render::Text::ParagraphFormat *p_ParaFmt; // r13
  Scaleform::Render::Text::SGMLElementDesc *v70; // rbx
  Scaleform::Render::Text::Paragraph *v71; // rax
  Scaleform::Render::Text::Paragraph *v72; // rbx
  const char *v73; // rdx
  Scaleform::Render::Text::Allocator *Allocator; // rax
  Scaleform::Render::Text::Paragraph *v75; // rdi
  Scaleform::Render::Text::Paragraph *v76; // rax
  int v77; // esi
  const char *v78; // rdx
  Scaleform::Render::Text::SGMLElementDesc *v79; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v80; // rax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  Scaleform::Render::Text::Allocator *v84; // rax
  Scaleform::Render::Text::SGMLElementDesc *v85; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v86; // rbx
  unsigned __int64 v87; // rbx
  unsigned __int64 v88; // rdi
  unsigned __int64 i; // rsi
  unsigned int v90; // edx
  unsigned __int64 j; // rax
  __int16 v92; // cx
  unsigned int v93; // r15d
  int v94; // r14d
  unsigned __int16 v95; // cx
  unsigned __int64 v96; // rax
  int v97; // r8d
  int v98; // eax
  unsigned int *v99; // rdx
  unsigned __int64 v100; // rdi
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v101; // rbx
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v102; // rsi
  Scaleform::Render::Text::Allocator *v103; // rax
  Scaleform::Render::Text::ParagraphFormat *ParagraphFormat; // rdi
  Scaleform::Render::Text::ParagraphFormat *v105; // rbx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *pAllocator; // rcx
  Scaleform::Render::Text::Allocator *v107; // rax
  Scaleform::Render::Text::ParagraphFormat *v108; // rdi
  Scaleform::Render::Text::ParagraphFormat *v109; // rbx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v110; // rcx
  unsigned __int64 v111; // rax
  signed __int64 v112; // rcx
  Scaleform::Render::Text::Paragraph *pPara; // rcx
  unsigned __int64 v114; // rax
  unsigned __int64 v115; // rdx
  wchar_t *v116; // rcx
  signed __int64 v117; // rbx
  Scaleform::Render::Text::Paragraph *v118; // rdi
  unsigned __int64 v119; // rax
  unsigned __int64 v120; // rcx
  bool v121; // cf
  wchar_t *v122; // rcx
  Scaleform::Render::Text::Allocator *v123; // rax
  Scaleform::Render::Text::FontHandle *v124; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v125; // rcx
  Scaleform::Render::Text::FontHandle *v126; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v127; // rcx
  Scaleform::Render::Text::TextFormat *pdefTextFmt; // [rsp+20h] [rbp-A8h]
  Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> v129; // [rsp+30h] [rbp-98h] BYREF
  void *pheapAddr; // [rsp+48h] [rbp-80h]
  wchar_t *ppattrValue; // [rsp+50h] [rbp-78h] BYREF
  unsigned __int64 pattrValueSz; // [rsp+58h] [rbp-70h] BYREF
  wchar_t *pfontList; // [rsp+60h] [rbp-68h] BYREF
  unsigned __int64 fontListSz; // [rsp+68h] [rbp-60h] BYREF
  unsigned __int64 len; // [rsp+70h] [rbp-58h] BYREF
  Scaleform::Render::Text::SGMLParser<wchar_t> pdefParaFmt; // [rsp+78h] [rbp-50h] BYREF
  Scaleform::StringDH *p_Id; // [rsp+C8h] [rbp+0h]
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v138; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v139; // [rsp+D8h] [rbp+10h]
  int v140; // [rsp+E0h] [rbp+18h] BYREF
  wchar_t *ppname; // [rsp+E8h] [rbp+20h] BYREF
  Scaleform::Render::Text::SGMLElementDesc *v142; // [rsp+F0h] [rbp+28h] BYREF
  int v143; // [rsp+F8h] [rbp+30h] BYREF
  float v144; // [rsp+FCh] [rbp+34h] BYREF
  int v145; // [rsp+100h] [rbp+38h] BYREF
  unsigned int v146; // [rsp+104h] [rbp+3Ch] BYREF
  int v147; // [rsp+108h] [rbp+40h] BYREF
  unsigned int v148; // [rsp+10Ch] [rbp+44h] BYREF
  int v149; // [rsp+110h] [rbp+48h] BYREF
  int pdestVal; // [rsp+114h] [rbp+4Ch] BYREF
  int v151; // [rsp+118h] [rbp+50h] BYREF
  int v152; // [rsp+11Ch] [rbp+54h] BYREF
  int v153; // [rsp+120h] [rbp+58h] BYREF
  Scaleform::Render::Text::TextFormat *p_FontList; // [rsp+128h] [rbp+60h] BYREF
  int v155; // [rsp+130h] [rbp+68h] BYREF
  int v156; // [rsp+134h] [rbp+6Ch] BYREF
  unsigned __int64 plen; // [rsp+138h] [rbp+70h] BYREF
  int v158; // [rsp+140h] [rbp+78h] BYREF
  Scaleform::Render::Text::TextFormat fmt; // [rsp+148h] [rbp+80h] BYREF
  Scaleform::Render::Text::TextFormat __that; // [rsp+198h] [rbp+D0h] BYREF
  wchar_t *v161; // [rsp+1E8h] [rbp+120h] BYREF
  wchar_t *v162; // [rsp+1F0h] [rbp+128h] BYREF
  wchar_t *lookForElemName; // [rsp+1F8h] [rbp+130h] BYREF
  Scaleform::Render::Text::SGMLElementDesc *v164; // [rsp+200h] [rbp+138h] BYREF
  Scaleform::MemoryHeap *pheap; // [rsp+208h] [rbp+140h]
  Scaleform::Render::Text::SGMLElementDesc *v166; // [rsp+210h] [rbp+148h] BYREF
  unsigned __int64 pattrNameSz; // [rsp+218h] [rbp+150h] BYREF
  Scaleform::Render::Text::SGMLElementDesc *v168; // [rsp+220h] [rbp+158h] BYREF
  wchar_t *v169; // [rsp+228h] [rbp+160h] BYREF
  wchar_t *ppattrName; // [rsp+230h] [rbp+168h] BYREF
  wchar_t *v171; // [rsp+238h] [rbp+170h] BYREF
  Scaleform::Render::Text::SGMLElementDesc *v172; // [rsp+240h] [rbp+178h] BYREF
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo val; // [rsp+248h] [rbp+180h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v174; // [rsp+288h] [rbp+1C0h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+290h] [rbp+1C8h] BYREF
  unsigned __int64 urlSz; // [rsp+298h] [rbp+1D0h] BYREF
  Scaleform::Render::Text::TextFormat *p_fmt; // [rsp+2A0h] [rbp+1D8h] BYREF
  wchar_t *purl; // [rsp+2A8h] [rbp+1E0h] BYREF
  wchar_t *ppContent; // [rsp+2B0h] [rbp+1E8h] BYREF
  wchar_t *v180; // [rsp+2B8h] [rbp+1F0h] BYREF
  unsigned __int64 pcontentSize; // [rsp+2C0h] [rbp+1F8h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v182; // [rsp+2C8h] [rbp+200h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v183; // [rsp+2D0h] [rbp+208h] BYREF
  Scaleform::Render::Text::SGMLElementDesc *v184; // [rsp+2D8h] [rbp+210h] BYREF
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> v185; // [rsp+2E0h] [rbp+218h] BYREF
  Scaleform::Render::Text::HTMLImageTagDesc *v186; // [rsp+378h] [rbp+2B0h]
  Scaleform::Render::Text::TextFormat v187; // [rsp+388h] [rbp+2C0h] BYREF
  __int64 v188; // [rsp+3D8h] [rbp+310h]
  Scaleform::Render::Text::StyledText *v189; // [rsp+438h] [rbp+370h]
  void *v190; // [rsp+448h] [rbp+380h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v191; // [rsp+450h] [rbp+388h]
  char v192; // [rsp+458h] [rbp+390h]
  char vars0; // [rsp+460h] [rbp+398h]
  void *retaddr; // [rsp+468h] [rbp+3A0h]
  Scaleform::Render::Text::ParagraphFormat *v196; // [rsp+478h] [rbp+3B0h]

  v188 = -2i64;
  v7 = this;
  if ( !htmlSize )
  {
    Scaleform::Render::Text::StyledText::EnsureTermNull(this);
    return 0;
  }
  pheap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v190 = &v129;
  memset(&v129, 0, sizeof(v129));
  pheapAddr = pheap;
  pdefParaFmt.pHeap = pheap;
  pdefParaFmt.CurState = 0;
  pdefParaFmt.Iter.pNextChar = phtml;
  pdefParaFmt.Iter.pEnd = &phtml[htmlSize];
  pdefParaFmt.Iter.CurChar = 0;
  pdefParaFmt.Iter.DoContentParsing = 0;
  pdefParaFmt.Iter.pCurChar = phtml;
  if ( phtml < pdefParaFmt.Iter.pEnd )
  {
    pdefParaFmt.Iter.CurChar = *phtml;
    pdefParaFmt.Iter.pNextChar = phtml + 1;
  }
  memset(&pdefParaFmt.pBuffer, 0, 24);
  pdefParaFmt.CondenseWhite = vars0 != 0;
  v9 = 0i64;
  LODWORD(v190) = 0;
  pObject = (Scaleform::Render::Text::TextFormat *)this;
  if ( !this )
    pObject = v7->pDefaultTextFormat.pObject;
  Scaleform::Render::Text::TextFormat::TextFormat(&__that, pObject, 0i64);
  v11 = v196;
  if ( !v196 )
    v11 = v7->pDefaultParagraphFormat.pObject;
  pdefParaFmt.pHeap = 0i64;
  LODWORD(pheapAddr) = 1;
  ppattrValue = 0i64;
  pattrValueSz = *(_QWORD *)&v11->BlockIndent;
  LODWORD(pfontList) = *(_DWORD *)&v11->RightMargin;
  pTabStops = v11->pTabStops;
  vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
  if ( pTabStops )
  {
    v14 = *pTabStops;
    vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    ppattrValue = 0i64;
    ppattrValue = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                               Scaleform::Memory::pGlobalHeap,
                               4i64 * (v14 + 1),
                               0i64);
    *(_DWORD *)ppattrValue = v14;
    memmove(ppattrValue + 2, pTabStops + 1, 4i64 * v14);
  }
  else
  {
    vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    ppattrValue = 0i64;
  }
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  p_FontList = (Scaleform::Render::Text::TextFormat *)&fmt.FontList;
  Scaleform::StringDH::CopyConstructHelper(&fmt.FontList, &__that.FontList, __that.FontList.pHeap);
  p_FontList = (Scaleform::Render::Text::TextFormat *)&fmt.Url;
  Scaleform::StringDH::CopyConstructHelper(&fmt.Url, &__that.Url, __that.FontList.pHeap);
  v15 = __that.pImageDesc.pObject;
  if ( __that.pImageDesc.pObject )
  {
    ++__that.pImageDesc.pObject->RefCount;
    v15 = __that.pImageDesc.pObject;
  }
  fmt.pImageDesc.pObject = v15;
  v16 = __that.pFontHandle.pObject;
  if ( __that.pFontHandle.pObject )
  {
    _InterlockedExchangeAdd(&__that.pFontHandle.pObject->RefCount, 1u);
    v16 = __that.pFontHandle.pObject;
  }
  fmt.pFontHandle.pObject = v16;
  fmt.ColorV = __that.ColorV;
  fmt.LetterSpacing = __that.LetterSpacing;
  fmt.FontSize = __that.FontSize;
  fmt.FormatFlags = __that.FormatFlags;
  fmt.PresentMask = __that.PresentMask;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((__that.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  __that.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)__that.Url.pData & 3;
  Scaleform::String::AppendString(&__that.Url, &customCaption, 0i64);
  __that.PresentMask |= 0x100u;
  Next = Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(&pdefParaFmt);
  if ( Next != 0x8000 )
  {
    v18 = v192;
    while ( 1 )
    {
      if ( Next == 1 )
        goto LABEL_291;
      if ( Next == 2 )
        break;
      if ( Next == 3 )
      {
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseContent(
               &pdefParaFmt,
               (const wchar_t **)&ppContent,
               &pcontentSize) )
        {
          v37 = pcontentSize;
          if ( pcontentSize )
          {
            LastParagraph = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
            v39 = LastParagraph ? Scaleform::Render::Text::Paragraph::GetLength(LastParagraph) : 0i64;
            if ( !vars0 || v37 > 1 || *ppContent != 32 || v39 )
            {
              if ( v129.Size )
              {
                p_TextFmt = &v129.Data[v129.Size - 1].TextFmt;
                Scaleform::Render::Text::StyledText::AppendString(
                  v7,
                  ppContent,
                  v37,
                  NLP_ReplaceCRLF,
                  p_TextFmt,
                  &v129.Data[v129.Size - 1].ParaFmt);
                Scaleform::Render::Text::TextFormat::operator=(&fmt, p_TextFmt);
                v18 = v192;
              }
              else
              {
                Scaleform::Render::Text::StyledText::AppendString(
                  v7,
                  ppContent,
                  v37,
                  NLP_ReplaceCRLF,
                  &__that,
                  (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                Scaleform::Render::Text::TextFormat::operator=(&fmt, &__that);
              }
            }
          }
        }
        goto LABEL_290;
      }
      if ( Next == 4 || Next == 32773 )
      {
        ppname = 0i64;
        plen = 0i64;
        v19 = 0i64;
        if ( Next == 4 )
        {
          Size = v129.Size;
          if ( v129.Size )
            v19 = &v129.Data[v129.Size - 1];
          if ( pdefParaFmt.CurState != 4 )
            goto LABEL_41;
          Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(&pdefParaFmt, (const wchar_t **)&ppname, &plen);
          if ( pdefParaFmt.Iter.CurChar == 62 )
          {
            pdefParaFmt.CurState = 32772;
            pdefParaFmt.Iter.pCurChar = pdefParaFmt.Iter.pNextChar;
            if ( pdefParaFmt.Iter.DoContentParsing && *pdefParaFmt.Iter.pNextChar == 38 )
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&pdefParaFmt.Iter);
              Size = v129.Size;
LABEL_41:
              if ( v19 )
              {
                v21 = (const wchar_t *)plen;
                v22 = (Scaleform::Render::Text::SGMLElementDesc *)ppname;
                if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
                       ppname,
                       plen,
                       v19->pElemName,
                       v19->ElemNameSize) )
                {
                  v23 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                          v22,
                          v21,
                          (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::elementsTable,
                          (Scaleform::Render::Text::SGMLElementDesc *)0xD,
                          (unsigned __int64)pdefTextFmt);
                  v24 = v23;
                  if ( v23 && (_DWORD)v190 && (unsigned int)(v23->ElemId - 6) <= 1 )
                  {
                    while ( Size )
                    {
                      pElemDesc = v129.Data[Size - 1].pElemDesc;
                      if ( pElemDesc && v24->ElemId == pElemDesc->ElemId )
                      {
                        v19 = &v129.Data[Size - 1];
                        goto LABEL_53;
                      }
                      Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                        &v129,
                        pheapAddr,
                        Size - 1);
                      if ( Size - 1 > Size )
                        Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::ConstructArray(
                          &v129.Data[Size],
                          0xFFFFFFFFFFFFFFFFui64);
                      Size = v129.Size;
                    }
                  }
LABEL_288:
                  v18 = v192;
LABEL_289:
                  pimgInfoArr = v191;
                  goto LABEL_290;
                }
LABEL_53:
                PresentMask = v19->ParaFmt.PresentMask;
                v27 = BYTE1(PresentMask) & 1;
                v28 = (PresentMask >> 11) & 3;
                v9 = (__int64)v19->pElemDesc;
                StartPos = v19->StartPos;
                Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  &v129,
                  pheapAddr,
                  Size - 1);
                if ( Size - 1 > Size )
                  Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::ConstructArray(
                    &v129.Data[Size],
                    0xFFFFFFFFFFFFFFFFui64);
                if ( v9 )
                {
                  if ( *(_DWORD *)(v9 + 8) == 6
                    || *(_DWORD *)(v9 + 8) == 7 && (LODWORD(v190) = (_DWORD)v190 - 1, Next != 32773) )
                  {
LABEL_59:
                    v18 = v192;
                    v7 = v189;
                    if ( v192 )
                    {
                      v30 = "\n";
                      if ( (v189->RTFlags & 2) != 0 )
                        v30 = "\r";
                      Scaleform::Render::Text::StyledText::AppendString(
                        v189,
                        v30,
                        1ui64,
                        NLP_ReplaceCRLF,
                        &fmt,
                        (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                    }
                    goto LABEL_289;
                  }
                }
                else if ( retaddr && v27 )
                {
                  v31 = v28 - 1;
                  if ( !v31 )
                    goto LABEL_59;
                  if ( v31 == 1 )
                  {
                    v32 = v189;
                    Length = Scaleform::Render::Text::StyledText::GetLength(v189);
                    if ( v192 )
                    {
                      v34 = "\n";
                      if ( (v32->RTFlags & 2) != 0 )
                        v34 = "\r";
                      Scaleform::Render::Text::StyledText::AppendString(
                        v32,
                        v34,
                        1ui64,
                        NLP_ReplaceCRLF,
                        &fmt,
                        (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                    }
                    v35 = Length - StartPos;
                    v36 = StartPos;
                    v7 = v189;
                    Scaleform::Render::Text::StyledText::Remove(v189, v36, v35);
                    goto LABEL_288;
                  }
                }
                v7 = v189;
                goto LABEL_288;
              }
LABEL_286:
              v18 = v192;
              goto LABEL_287;
            }
            if ( pdefParaFmt.Iter.pNextChar < pdefParaFmt.Iter.pEnd )
            {
              pdefParaFmt.Iter.CurChar = *pdefParaFmt.Iter.pNextChar++;
              Size = v129.Size;
              goto LABEL_41;
            }
          }
          else
          {
            pdefParaFmt.CurState = 1;
          }
          Size = v129.Size;
          goto LABEL_41;
        }
        if ( !v9 || !*(_BYTE *)(v9 + 13) )
        {
          Size = v129.Size;
          if ( v129.Size )
          {
            v19 = &v129.Data[v129.Size - 1];
            ppname = (wchar_t *)v19->pElemName;
            plen = v19->ElemNameSize;
            goto LABEL_41;
          }
          goto LABEL_286;
        }
LABEL_287:
        pimgInfoArr = v191;
      }
LABEL_290:
      Next = Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(&pdefParaFmt);
      if ( Next == 0x8000 )
        goto LABEL_291;
    }
    v142 = 0i64;
    if ( pdefParaFmt.CurState == 2 )
    {
      Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(
        &pdefParaFmt,
        (const wchar_t **)&v142,
        (unsigned __int64 *)&lookForElemName);
      if ( pdefParaFmt.Iter.CurChar == 62 )
      {
        pdefParaFmt.CurState = 32770;
        pdefParaFmt.Iter.pCurChar = pdefParaFmt.Iter.pNextChar;
        if ( pdefParaFmt.Iter.DoContentParsing && *pdefParaFmt.Iter.pNextChar == 38 )
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&pdefParaFmt.Iter);
        }
        else if ( pdefParaFmt.Iter.pNextChar < pdefParaFmt.Iter.pEnd )
        {
          pdefParaFmt.Iter.CurChar = *pdefParaFmt.Iter.pNextChar++;
        }
      }
      else if ( pdefParaFmt.Iter.CurChar == 47 )
      {
        pdefParaFmt.CurState = 6;
      }
      else
      {
        pdefParaFmt.CurState = 7;
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(&pdefParaFmt);
      }
    }
    v41 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
            v142,
            lookForElemName,
            (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::elementsTable,
            (Scaleform::Render::Text::SGMLElementDesc *)0xD,
            (unsigned __int64)pdefTextFmt);
    v9 = (__int64)v41;
    p_Id = (Scaleform::StringDH *)v41;
    v42 = LODWORD(v129.Size) - 1;
    if ( v41 && v41->EmptyElement )
    {
      ElemId = v41->ElemId;
      if ( ElemId == GFxHTML_BR )
      {
        if ( v18 )
        {
          v63 = "\n";
          if ( (v7->RTFlags & 2) != 0 )
            v63 = "\r";
          Scaleform::Render::Text::StyledText::AppendString(
            v7,
            v63,
            1ui64,
            NLP_ReplaceCRLF,
            &fmt,
            (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
        }
        goto LABEL_290;
      }
      if ( ElemId != GFxHTML_IMG )
      {
        if ( ElemId == GFxHTML_TAB )
          Scaleform::Render::Text::StyledText::AppendString(
            v7,
            "\t",
            1ui64,
            NLP_ReplaceCRLF,
            v7->pDefaultTextFormat.pObject,
            v7->pDefaultParagraphFormat.pObject);
        goto LABEL_290;
      }
      if ( pimgInfoArr )
      {
        val.pTextImageDesc.pObject = 0i64;
        val.Url.pHeap = pheap;
        _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
        val.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
        p_Id = &val.Id;
        val.Id.pHeap = pheap;
        _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
        val.Id.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
        *(_QWORD *)&val.Width = 0i64;
        *(_QWORD *)&val.VSpace = 0i64;
        val.ParaId = -1;
        val.Alignment = 0;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,Scaleform::AllocatorDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          pimgInfoArr,
          &val);
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo::~HTMLImageTagInfo(&val);
        v44 = pimgInfoArr->Data.Size << 6;
        Data = pimgInfoArr->Data.Data;
        appended = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        if ( !appended )
          appended = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                       v7,
                       (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
        Scaleform::Render::Text::TextFormat::TextFormat(&v187, &__that, 0i64);
        *(_DWORD *)((char *)Data + v44 - 8) = appended->UniqueId;
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&ppattrName,
               &pattrNameSz) )
        {
          do
          {
            v47 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    (Scaleform::Render::Text::SGMLElementDesc *)ppattrName,
                    (const wchar_t *)pattrNameSz,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v47
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&ppattrValue,
                   &pattrValueSz) )
            {
              switch ( v47->ElemId )
              {
                case GFxHTML_ALIGN:
                  v49 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                          (Scaleform::Render::Text::SGMLElementDesc *)ppattrValue,
                          (const wchar_t *)pattrValueSz,
                          (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                          (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                          (unsigned __int64)pdefTextFmt);
                  if ( v49 )
                  {
                    v50 = v49->ElemId - 14;
                    if ( v50 )
                    {
                      v51 = v50 - 21;
                      if ( v51 )
                      {
                        if ( v51 == 1 )
                          *((_BYTE *)Data + v44 - 4) = 1;
                      }
                      else
                      {
                        *((_BYTE *)Data + v44 - 4) = 2;
                      }
                    }
                    else
                    {
                      *((_BYTE *)Data + v44 - 4) = 0;
                    }
                  }
                  break;
                case GFxHTML_HEIGHT:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v156, ppattrValue, pattrValueSz)
                    && v156 >= 0 )
                  {
                    *(_DWORD *)((char *)Data + v44 - 20) = 20 * v156;
                  }
                  break;
                case GFxHTML_HSPACE:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v155, ppattrValue, pattrValueSz) )
                    *(_DWORD *)((char *)Data + v44 - 12) = 20 * v155;
                  break;
                case GFxHTML_ID:
                  p_Url = &Data[-1].Id;
                  goto LABEL_109;
                case GFxHTML_SRC:
                  p_Url = &Data[-1].Url;
LABEL_109:
                  Scaleform::String::AppendString(
                    (Scaleform::StringDH *)((char *)p_Url + v44),
                    ppattrValue,
                    pattrValueSz);
                  break;
                case GFxHTML_VSPACE:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v145, ppattrValue, pattrValueSz) )
                    *(_DWORD *)((char *)Data + v44 - 16) = 20 * v145;
                  break;
                case GFxHTML_WIDTH:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&pdestVal, ppattrValue, pattrValueSz)
                    && pdestVal >= 0 )
                  {
                    *(_DWORD *)((char *)Data + v44 - 24) = 20 * pdestVal;
                  }
                  break;
                default:
                  break;
              }
            }
          }
          while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                    &pdefParaFmt,
                    (const wchar_t **)&ppattrName,
                    &pattrNameSz) );
          v7 = v189;
        }
        v140 = 74;
        v52 = (Scaleform::Render::Text::HTMLImageTagDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             v7,
                                                             112i64,
                                                             &v140);
        p_Id = (Scaleform::StringDH *)v52;
        if ( v52 )
        {
          Scaleform::Render::Text::HTMLImageTagDesc::HTMLImageTagDesc(v52);
          v54 = v53;
        }
        else
        {
          v54 = 0i64;
        }
        v186 = v54;
        if ( v54 )
          ++v54->RefCount;
        v55 = v187.pImageDesc.pObject;
        if ( v187.pImageDesc.pObject )
        {
          --v187.pImageDesc.pObject->RefCount;
          if ( !v55->RefCount )
            v55->vfptr->__vecDelDtor(v55, 1u);
        }
        v187.pImageDesc.pObject = v54;
        v187.PresentMask |= 0x200u;
        v54->ScreenWidth = (float)*(int *)((char *)Data + v44 - 24);
        v54->ScreenHeight = (float)*(int *)((char *)Data + v44 - 20);
        v54->VSpace = *(_DWORD *)((char *)Data + v44 - 16);
        v54->HSpace = *(_DWORD *)((char *)Data + v44 - 12);
        Scaleform::String::operator=(&v54->Url, (Scaleform::String *)((char *)&Data[-1].Url + v44));
        Scaleform::String::operator=(&v54->Id, (Scaleform::String *)((char *)&Data[-1].Id + v44));
        v54->Alignment = *((_BYTE *)Data + v44 - 4);
        ++v54->RefCount;
        v56 = *(__int64 *)((char *)&Data[-1].pTextImageDesc.pObject + v44);
        if ( v56 )
        {
          v57 = (*(_DWORD *)(v56 + 8))-- == 1;
          if ( v57 )
            (**(void (__fastcall ***)(__int64, __int64))v56)(v56, 1i64);
        }
        *(Scaleform::Render::Text::ImageDesc **)((char *)&Data[-1].pTextImageDesc.pObject + v44) = v54;
        if ( v42 < 0 )
        {
          p_that = &__that;
          p_pdefParaFmt = (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt;
        }
        else
        {
          v58 = v42;
          p_that = &v129.Data[v58].TextFmt;
          p_pdefParaFmt = &v129.Data[v58].ParaFmt;
        }
        if ( Scaleform::Render::Text::TextFormat::IsUrlSet(p_that) )
        {
          Scaleform::String::operator=(&v187.Url, &p_that->Url);
          v187.PresentMask |= 0x100u;
        }
        Scaleform::Render::Text::StyledText::AppendString(v7, " ", 1ui64, NLP_ReplaceCRLF, &v187, p_pdefParaFmt);
        v61 = p_that->pImageDesc.pObject;
        if ( v61 )
        {
          v57 = v61->RefCount-- == 1;
          if ( v57 )
            v61->vfptr->__vecDelDtor(v61, 1u);
        }
        p_that->pImageDesc.pObject = 0i64;
        p_that->PresentMask |= 0x200u;
        v62 = fmt.pImageDesc.pObject;
        if ( fmt.pImageDesc.pObject )
        {
          --fmt.pImageDesc.pObject->RefCount;
          if ( !v62->RefCount )
            v62->vfptr->__vecDelDtor(v62, 1u);
        }
        fmt.pImageDesc.pObject = 0i64;
        fmt.PresentMask |= 0x200u;
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, p_that);
        Scaleform::Render::Text::TextFormat::operator=(&__that, p_that);
        v57 = v54->RefCount-- == 1;
        if ( v57 )
          v54->vfptr->__vecDelDtor(v54, 1u);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v187);
        goto LABEL_288;
      }
      goto LABEL_290;
    }
    v64 = Scaleform::Render::Text::StyledText::GetLength(v7);
    v185.pElemName = (const wchar_t *)v142;
    v185.ElemNameSize = (unsigned __int64)lookForElemName;
    v185.pElemDesc = (Scaleform::Render::Text::SGMLElementDesc *)v9;
    v185.StartPos = 0i64;
    Scaleform::Render::Text::TextFormat::TextFormat(&v185.TextFmt, pheap);
    v185.ParaFmt.pAllocator = 0i64;
    v185.ParaFmt.RefCount = 1;
    memset(&v185.ParaFmt.pTabStops, 0, 20);
    Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v129,
      pheapAddr,
      v129.Size + 1);
    v139 = &v129.Data[v129.Size - 1];
    v138 = v139;
    if ( v139 )
      Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(&v129.Data[v129.Size - 1], &v185);
    if ( v185.ParaFmt.pAllocator )
    {
      key = &v185.ParaFmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        &v185.ParaFmt.pAllocator->ParagraphFormatStorage,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v185.ParaFmt.pTabStops);
    v185.ParaFmt.pTabStops = 0i64;
    Scaleform::Render::Text::TextFormat::~TextFormat(&v185.TextFmt);
    v65 = v129.Size;
    v66 = v129.Data;
    v129.Data[v65 - 1].StartPos = v64;
    v67 = &v66[v65 - 1].TextFmt;
    v139 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v67;
    if ( v42 < 0 )
    {
      Scaleform::Render::Text::TextFormat::operator=(v67, &__that);
      p_ParaFmt = &v66[v65 - 1].ParaFmt;
      *(_QWORD *)&p_ParaFmt->BlockIndent = pattrValueSz;
      *(_DWORD *)&p_ParaFmt->RightMargin = (_DWORD)pfontList;
      Scaleform::Render::Text::ParagraphFormat::CopyTabStops(p_ParaFmt, (const unsigned int *)ppattrValue);
    }
    else
    {
      v68 = v42;
      Scaleform::Render::Text::TextFormat::operator=(v67, &v129.Data[v68].TextFmt);
      p_ParaFmt = &v66[v65 - 1].ParaFmt;
      Scaleform::Render::Text::ParagraphFormat::operator=(p_ParaFmt, &v129.Data[v68].ParaFmt);
    }
    if ( !p_Id )
    {
LABEL_284:
      Scaleform::Render::Text::TextFormat::operator=(&fmt, v67);
      v9 = (__int64)p_Id;
      goto LABEL_288;
    }
    switch ( LODWORD(p_Id->pHeap) )
    {
      case 0:
        while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                  &pdefParaFmt,
                  (const wchar_t **)&v172,
                  (unsigned __int64 *)&v161) )
        {
          v70 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                  v172,
                  v161,
                  (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                  (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                  (unsigned __int64)pdefTextFmt);
          if ( v70
            && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                 &pdefParaFmt,
                 (const wchar_t **)&purl,
                 &urlSz)
            && v70->ElemId == GFxHTML_HREF )
          {
            Scaleform::Render::Text::TextFormat::SetUrl(v67, purl, urlSz);
            v7->RTFlags |= 1u;
          }
        }
        goto LABEL_284;
      case 1:
        Scaleform::Render::Text::TextFormat::SetBold(v67, 1);
        goto LABEL_284;
      case 3:
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&v164,
               (unsigned __int64 *)&v162) )
        {
          do
          {
            v85 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    v164,
                    v162,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v85
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&pfontList,
                   &fontListSz) )
            {
              switch ( v85->ElemId )
              {
                case GFxHTML_ALPHA:
                  if ( *pfontList == 35
                    && Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(&v148, pfontList + 1, fontListSz - 1) )
                  {
                    v67->ColorV &= 0xFFFFFFu;
                    v67->ColorV |= (unsigned __int8)v148 << 24;
                    v67->PresentMask |= 0x400u;
                  }
                  break;
                case GFxHTML_COLOR:
                  if ( *pfontList == 35
                    && Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(&v146, pfontList + 1, fontListSz - 1) )
                  {
                    v67->ColorV &= 0xFF000000;
                    v67->ColorV |= v146 & 0xFFFFFF;
                    v67->PresentMask |= 1u;
                  }
                  break;
                case GFxHTML_FACE:
                  Scaleform::Render::Text::TextFormat::SetFontList(v67, pfontList, fontListSz);
                  break;
                case GFxHTML_KERNING:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v149, pfontList, fontListSz) && v149 >= 0 )
                  {
                    if ( v149 )
                    {
                      v67->FormatFlags |= 8u;
                      v67->PresentMask |= 0x80u;
                    }
                    else
                    {
                      v67->FormatFlags &= ~8u;
                      v67->PresentMask &= ~0x80u;
                    }
                  }
                  break;
                case GFxHTML_LETTERSPACING:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseFloat(&v144, pfontList, fontListSz) )
                  {
                    v67->PresentMask |= 2u;
                    v67->LetterSpacing = v144 * 20.0;
                  }
                  break;
                case GFxHTML_SIZE:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v153, pfontList, fontListSz) && v153 >= 0 )
                    Scaleform::Render::Text::TextFormat::SetFontSize(v67, (float)v153);
                  break;
                default:
                  break;
              }
            }
          }
          while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                    &pdefParaFmt,
                    (const wchar_t **)&v164,
                    (unsigned __int64 *)&v162) );
          v7 = v189;
        }
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v67);
        goto LABEL_284;
      case 4:
        Scaleform::Render::Text::TextFormat::SetItalic(v67, 1);
        goto LABEL_284;
      case 6:
        p_ParaFmt->PresentMask |= 0x8080u;
        v71 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        v72 = v71;
        if ( v71 )
        {
          if ( Scaleform::Render::Text::Paragraph::GetLength(v71) )
          {
            if ( v192 )
            {
              v73 = "\n";
              if ( (v7->RTFlags & 2) != 0 )
                v73 = "\r";
              Scaleform::Render::Text::StyledText::AppendString(
                v7,
                v73,
                1ui64,
                NLP_ReplaceCRLF,
                &fmt,
                (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
            }
            v72 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
          }
          Allocator = Scaleform::Render::Text::StyledText::GetAllocator(v7);
          Scaleform::Render::Text::Paragraph::SetFormat(v72, Allocator, p_ParaFmt);
        }
        else
        {
          Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, p_ParaFmt);
        }
        goto LABEL_284;
      case 7:
        v75 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        v138 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v75;
        if ( v75 )
        {
          v77 = (int)v190;
          if ( !(_DWORD)v190 )
          {
LABEL_192:
            if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                   &pdefParaFmt,
                   (const wchar_t **)&v168,
                   (unsigned __int64 *)&v171) )
            {
              do
              {
                v79 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                        v168,
                        v171,
                        (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                        (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                        (unsigned __int64)pdefTextFmt);
                if ( v79 )
                {
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                         &pdefParaFmt,
                         (const wchar_t **)&v184,
                         (unsigned __int64 *)&v180)
                    && v79->ElemId == GFxHTML_ALIGN )
                  {
                    v80 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                            v184,
                            v180,
                            (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                            (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                            (unsigned __int64)pdefTextFmt);
                    if ( v80 )
                    {
                      v81 = v80->ElemId - 35;
                      if ( v81 )
                      {
                        v82 = v81 - 1;
                        if ( v82 )
                        {
                          v83 = v82 - 1;
                          if ( v83 )
                          {
                            if ( v83 == 1 )
                            {
                              p_ParaFmt->PresentMask &= ~0x200u;
                              p_ParaFmt->PresentMask |= 0x401u;
                            }
                          }
                          else
                          {
                            p_ParaFmt->PresentMask |= 0x601u;
                          }
                        }
                        else
                        {
                          p_ParaFmt->PresentMask &= ~0x400u;
                          p_ParaFmt->PresentMask |= 0x201u;
                        }
                      }
                      else
                      {
                        p_ParaFmt->PresentMask &= 0xF9FFu;
                        p_ParaFmt->PresentMask |= 1u;
                      }
                    }
                  }
                }
              }
              while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                        &pdefParaFmt,
                        (const wchar_t **)&v168,
                        (unsigned __int64 *)&v171) );
              v75 = (Scaleform::Render::Text::Paragraph *)v138;
              v67 = (Scaleform::Render::Text::TextFormat *)v139;
              v7 = v189;
              v77 = (int)v190;
            }
            if ( !Scaleform::Render::Text::Paragraph::GetLength(v75) )
            {
              v84 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
              Scaleform::Render::Text::Paragraph::SetFormat(v75, v84, p_ParaFmt);
            }
            LODWORD(v190) = v77 + 1;
            goto LABEL_284;
          }
          if ( v192 )
          {
            v78 = "\n";
            if ( (v7->RTFlags & 2) != 0 )
              v78 = "\r";
            Scaleform::Render::Text::StyledText::AppendString(
              v7,
              v78,
              1ui64,
              NLP_ReplaceCRLF,
              &fmt,
              (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
          }
          v76 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        }
        else
        {
          v76 = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                  v7,
                  (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
          v77 = (int)v190;
        }
        v138 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v76;
        v75 = v76;
        goto LABEL_192;
      case 0xA:
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&v166,
               (unsigned __int64 *)&v169) )
        {
          do
          {
            v86 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    v166,
                    v169,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v86
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&fontListSz,
                   &len) )
            {
              switch ( v86->ElemId )
              {
                case GFxHTML_BLOCKINDENT:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v158, (const wchar_t *)fontListSz, len)
                    && v158 >= 0 )
                  {
                    p_ParaFmt->BlockIndent = v158;
                    p_ParaFmt->PresentMask |= 2u;
                  }
                  break;
                case GFxHTML_INDENT:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v152, (const wchar_t *)fontListSz, len) )
                  {
                    p_ParaFmt->Indent = v152;
                    p_ParaFmt->PresentMask |= 4u;
                  }
                  break;
                case GFxHTML_LEADING:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v147, (const wchar_t *)fontListSz, len) )
                  {
                    p_ParaFmt->Leading = v147;
                    p_ParaFmt->PresentMask |= 8u;
                  }
                  break;
                case GFxHTML_LEFTMARGIN:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v151, (const wchar_t *)fontListSz, len)
                    && v151 >= 0 )
                  {
                    p_ParaFmt->LeftMargin = v151;
                    p_ParaFmt->PresentMask |= 0x10u;
                  }
                  break;
                case GFxHTML_RIGHTMARGIN:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v143, (const wchar_t *)fontListSz, len)
                    && v143 >= 0 )
                  {
                    p_ParaFmt->RightMargin = v143;
                    p_ParaFmt->PresentMask |= 0x20u;
                  }
                  break;
                case GFxHTML_TABSTOPS:
                  v87 = 0i64;
                  v88 = fontListSz;
                  for ( i = len; v87 < i; ++v87 )
                  {
                    if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(*(unsigned __int16 *)(v88 + 2 * v87)) )
                      break;
                  }
                  if ( *(_WORD *)(v88 + 2 * v87) == 91 )
                    ++v87;
                  v90 = 1;
                  for ( j = v87; j < i; ++j )
                  {
                    v92 = *(_WORD *)(v88 + 2 * j);
                    if ( v92 == 93 )
                      break;
                    if ( v92 == 44 )
                      ++v90;
                  }
                  Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(p_ParaFmt, v90);
                  v93 = 0;
                  if ( v87 < i )
                  {
                    while ( *(_WORD *)(v88 + 2 * v87) != 93 )
                    {
                      v94 = 0;
                      while ( isdigit(*(unsigned __int16 *)(v88 + 2 * v87)) )
                      {
                        v94 = *(unsigned __int16 *)(v88 + 2 * v87++) + 2 * (5 * v94 - 24);
                        if ( v87 >= i )
                          goto LABEL_275;
                      }
                      for ( ; v87 < i; ++v87 )
                      {
                        v95 = *(_WORD *)(v88 + 2 * v87);
                        v96 = (unsigned __int64)v95 >> 8;
                        v97 = Scaleform::UnicodeSpaceBits[v96];
                        if ( !Scaleform::UnicodeSpaceBits[v96] )
                          break;
                        if ( v97 != 1 )
                        {
                          v98 = Scaleform::UnicodeSpaceBits[v97 + ((unsigned __int8)v95 >> 4)];
                          if ( !_bittest(&v98, v95 & 0xF) )
                            break;
                        }
                      }
LABEL_275:
                      v99 = p_ParaFmt->pTabStops;
                      if ( v99 && v93 < *v99 )
                        v99[v93 + 1] = v94;
                      ++v93;
                      if ( *(_WORD *)(v88 + 2 * v87) == 44 )
                      {
                        while ( ++v87 < i )
                        {
                          if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(*(unsigned __int16 *)(v88 + 2 * v87)) )
                            goto LABEL_281;
                        }
                        goto LABEL_282;
                      }
LABEL_281:
                      if ( v87 >= i )
                        goto LABEL_282;
                    }
                  }
                  break;
                default:
                  break;
              }
            }
LABEL_282:
            ;
          }
          while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                    &pdefParaFmt,
                    (const wchar_t **)&v166,
                    (unsigned __int64 *)&v169) );
          v67 = (Scaleform::Render::Text::TextFormat *)v139;
          v7 = v189;
        }
        goto LABEL_284;
      case 0xB:
        v67->FormatFlags |= 4u;
        v67->PresentMask |= 0x40u;
        goto LABEL_284;
      default:
        goto LABEL_284;
    }
  }
LABEL_291:
  if ( v129.Size )
  {
    v100 = v129.Size;
    v101 = v129.Data;
    v102 = &v129.Data[v129.Size];
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, &v102[-1].TextFmt);
    v103 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
    ParagraphFormat = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v103, &v101[v100 - 1].ParaFmt);
    v105 = v7->pDefaultParagraphFormat.pObject;
    if ( v105 )
    {
      v57 = v105->RefCount-- == 1;
      if ( v57 )
      {
        pAllocator = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v105->pAllocator;
        if ( v105->pAllocator )
        {
          v183 = v105;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            pAllocator + 3,
            &v183);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v105->pTabStops);
        v105->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v105);
      }
    }
    v7->pDefaultParagraphFormat.pObject = ParagraphFormat;
    Scaleform::Render::Text::TextFormat::operator=(&fmt, &v102[-1].TextFmt);
  }
  else
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, &__that);
    v107 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
    v108 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(
             v107,
             (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
    v109 = v7->pDefaultParagraphFormat.pObject;
    if ( v109 )
    {
      v57 = v109->RefCount-- == 1;
      if ( v57 )
      {
        v110 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v109->pAllocator;
        if ( v109->pAllocator )
        {
          v174 = v109;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            v110 + 3,
            &v174);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v109->pTabStops);
        v109->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v109);
      }
    }
    v7->pDefaultParagraphFormat.pObject = v108;
  }
  Scaleform::Render::Text::StyledText::EnsureTermNull(v7);
  v111 = v7->Paragraphs.Data.Size;
  v112 = v111 - 1;
  if ( (__int64)(v111 - 1) >= 0 && v112 < (int)v111 )
  {
    pPara = v7->Paragraphs.Data.Data[v112].pPara;
    if ( pPara )
    {
      v114 = pPara->Text.Size;
      if ( !v114 )
        goto LABEL_314;
      v115 = v114 - 1;
      if ( !pPara->Text.pText || (v116 = &pPara->Text.pText[v115], v115 >= v114) )
        v116 = 0i64;
      if ( !*v116 )
        --v114;
      if ( !v114 )
      {
LABEL_314:
        v117 = v7->Paragraphs.Data.Size;
        while ( --v117 >= 0 && v117 < SLODWORD(v7->Paragraphs.Data.Size) )
        {
          v118 = v7->Paragraphs.Data.Data[v117].pPara;
          v119 = v118->Text.Size;
          if ( v119 )
          {
            v120 = v119 - 1;
            if ( !v118->Text.pText || (v121 = v120 < v119, v122 = &v118->Text.pText[v120], !v121) )
              v122 = 0i64;
            if ( !*v122 )
              --v119;
          }
          if ( v119 > 1 )
            break;
          v123 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
          Scaleform::Render::Text::Paragraph::SetTextFormat(v118, v123, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
        }
      }
    }
  }
  if ( fmt.pAllocator )
  {
    p_fmt = &fmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      &fmt.pAllocator->TextFormatStorage,
      &p_fmt);
  }
  v124 = fmt.pFontHandle.pObject;
  if ( fmt.pFontHandle.pObject && !_InterlockedDecrement(&fmt.pFontHandle.pObject->RefCount) && v124 )
    v124->vfptr->__vecDelDtor(v124, 1u);
  v125 = fmt.pImageDesc.pObject;
  if ( fmt.pImageDesc.pObject )
  {
    --fmt.pImageDesc.pObject->RefCount;
    if ( !v125->RefCount )
      v125->vfptr->__vecDelDtor(v125, 1u);
  }
  v190 = &fmt.Url;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((fmt.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v190 = &fmt.FontList;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((fmt.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( pdefParaFmt.pHeap )
  {
    v182 = (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&pdefParaFmt.pHeap->SelfSize,
      &v182);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ppattrValue);
  ppattrValue = 0i64;
  if ( __that.pAllocator )
  {
    p_FontList = &__that;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      &__that.pAllocator->TextFormatStorage,
      &p_FontList);
  }
  v126 = __that.pFontHandle.pObject;
  if ( __that.pFontHandle.pObject && !_InterlockedDecrement(&__that.pFontHandle.pObject->RefCount) && v126 )
    v126->vfptr->__vecDelDtor(v126, 1u);
  v127 = __that.pImageDesc.pObject;
  if ( __that.pImageDesc.pObject )
  {
    --__that.pImageDesc.pObject->RefCount;
    if ( !v127->RefCount )
      v127->vfptr->__vecDelDtor(v127, 1u);
  }
  v190 = &__that.Url;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((__that.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v190 = &__that.FontList;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((__that.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pdefParaFmt.pBuffer);
  v190 = &v129;
  Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::DestructArray(v129.Data, v129.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v129.Data);
  return 1;
}

// File Line: 1032
// RVA: 0x99E710
__int64 __fastcall Scaleform::Render::Text::StyledText::ParseHtml(
        Scaleform::Render::Text::StyledText *this,
        char *phtml,
        __int64 htmlSize,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  __int64 v6; // rbx
  wchar_t *v8; // rsi
  __int64 v9; // rax

  v6 = htmlSize;
  v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * htmlSize + 2, 0i64);
  v9 = Scaleform::UTF8Util::DecodeStringSafe(v8, v6 + 1, phtml, v6);
  LOBYTE(v6) = Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(this, v8, v9, pimgInfoArr);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
  return (unsigned __int8)v6;
}

