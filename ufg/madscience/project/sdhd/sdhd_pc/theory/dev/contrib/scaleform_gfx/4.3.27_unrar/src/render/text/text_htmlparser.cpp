// File Line: 103
// RVA: 0x92BE70
Scaleform::Render::Text::SGMLElementDesc *__fastcall Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(Scaleform::Render::Text::SGMLElementDesc *this, const wchar_t *lookForElemName, unsigned __int64 nameSize, Scaleform::Render::Text::SGMLElementDesc *ptable, unsigned __int64 tableSize)
{
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r15
  Scaleform::Render::Text::SGMLElementDesc *v7; // r14
  const wchar_t *v8; // r12
  Scaleform::Render::Text::SGMLElementDesc *v9; // r13
  signed __int64 v10; // rbx
  signed __int64 v11; // rsi
  Scaleform::Render::Text::SGMLElementDesc *result; // rax

  v5 = 0i64;
  v6 = nameSize;
  v7 = ptable;
  v8 = lookForElemName;
  v9 = this;
  v10 = (signed __int64)ptable;
  while ( v10 > 0 )
  {
    if ( -Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
            (const wchar_t *)v9,
            *(const char **)(v6 + 16 * ((v10 >> 1) + v5)),
            (unsigned __int64)v8) >= 0 )
    {
      v10 >>= 1;
    }
    else
    {
      v5 += (v10 >> 1) + 1;
      v10 += -1 - (v10 >> 1);
    }
  }
  if ( v5 >= (unsigned __int64)v7
    || (v11 = 2 * v5,
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
          (const wchar_t *)v9,
          *(const char **)(v6 + 8 * v11),
          (unsigned __int64)v8)) )
  {
    result = 0i64;
  }
  else
  {
    result = (Scaleform::Render::Text::SGMLElementDesc *)(v6 + 8 * v11);
  }
  return result;
}

// File Line: 142
// RVA: 0x92DBE0
char __fastcall Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(Scaleform::Render::Text::StyledText *this, const wchar_t *phtml, unsigned __int64 htmlSize, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  unsigned __int64 v5; // rdi
  const wchar_t *v6; // rbx
  Scaleform::Render::Text::StyledText *v7; // r15
  bool v9; // al
  __int64 v10; // r13
  Scaleform::Render::Text::TextFormat *v11; // rdx
  Scaleform::Render::Text::ParagraphFormat *v12; // rcx
  unsigned int *v13; // rdi
  Scaleform::MemoryHeapVtbl *v14; // rax
  unsigned int v15; // ebx
  Scaleform::Render::Text::HTMLImageTagDesc *v16; // rax
  Scaleform::Render::Text::FontHandle *v17; // rcx
  int v18; // er12
  char v19; // bl
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v20; // rsi
  unsigned __int64 v21; // rbx
  const wchar_t *v22; // rdi
  Scaleform::Render::Text::SGMLElementDesc *v23; // r14
  Scaleform::Render::Text::SGMLElementDesc *v24; // rax
  Scaleform::Render::Text::SGMLElementDesc *v25; // rsi
  __int64 v26; // rdx
  unsigned int v27; // edi
  char v28; // r14
  int v29; // edi
  unsigned __int64 v30; // r15
  const char *v31; // rdx
  int v32; // edi
  Scaleform::Render::Text::StyledText *v33; // rdi
  unsigned __int64 v34; // rbx
  const char *v35; // rdx
  unsigned __int64 v36; // r8
  unsigned __int64 v37; // rdx
  unsigned __int64 v38; // rdi
  Scaleform::Render::Text::Paragraph *v39; // rax
  unsigned __int64 v40; // rax
  Scaleform::Render::Text::TextFormat *v41; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v42; // rax
  int v43; // er14
  Scaleform::Render::Text::HTMLElementsEnum v44; // ecx
  unsigned __int64 v45; // rdi
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v46; // rsi
  Scaleform::Render::Text::Paragraph *v47; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v48; // rbx
  signed __int64 v49; // rcx
  Scaleform::Render::Text::SGMLElementDesc *v50; // rax
  int v51; // eax
  int v52; // eax
  Scaleform::Render::Text::HTMLImageTagDesc *v53; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v54; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v55; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v56; // rcx
  __int64 v57; // rcx
  bool v58; // zf
  __int64 v59; // rcx
  Scaleform::Render::Text::TextFormat *v60; // rdi
  Scaleform::Render::Text::ParagraphFormat *v61; // rsi
  Scaleform::Render::Text::HTMLImageTagDesc *v62; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v63; // rcx
  const char *v64; // rdx
  unsigned __int64 v65; // rbx
  unsigned __int64 v66; // rdi
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v67; // rsi
  Scaleform::Render::Text::TextFormat *v68; // r12
  Scaleform::Render::Text::TextFormat *v69; // rcx
  __int64 v70; // rbx
  signed __int64 v71; // r13
  Scaleform::Render::Text::SGMLElementDesc *v72; // rbx
  Scaleform::Render::Text::Paragraph *v73; // rax
  Scaleform::Render::Text::Paragraph *v74; // rbx
  const char *v75; // rdx
  Scaleform::Render::Text::Allocator *v76; // rax
  Scaleform::Render::Text::Paragraph *v77; // rdi
  Scaleform::Render::Text::Paragraph *v78; // rax
  int v79; // esi
  const char *v80; // rdx
  Scaleform::Render::Text::SGMLElementDesc *v81; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v82; // rax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  Scaleform::Render::Text::Allocator *v86; // rax
  Scaleform::Render::Text::SGMLElementDesc *v87; // rbx
  Scaleform::Render::Text::SGMLElementDesc *v88; // rbx
  unsigned __int64 v89; // rbx
  unsigned __int64 v90; // rdi
  unsigned __int64 v91; // rsi
  unsigned int v92; // edx
  unsigned __int64 i; // rax
  __int16 v94; // cx
  unsigned int v95; // er15
  int v96; // er14
  __int16 v97; // cx
  unsigned __int64 v98; // rax
  int v99; // er8
  int v100; // eax
  unsigned int *v101; // rdx
  unsigned __int64 v102; // rdi
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v103; // rbx
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v104; // rsi
  Scaleform::Render::Text::Allocator *v105; // rax
  Scaleform::Render::Text::ParagraphFormat *v106; // rdi
  Scaleform::Render::Text::ParagraphFormat *v107; // rbx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v108; // rcx
  Scaleform::Render::Text::Allocator *v109; // rax
  Scaleform::Render::Text::ParagraphFormat *v110; // rdi
  Scaleform::Render::Text::ParagraphFormat *v111; // rbx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v112; // rcx
  unsigned __int64 v113; // rax
  signed __int64 v114; // rcx
  Scaleform::Render::Text::Paragraph *v115; // rcx
  unsigned __int64 v116; // rax
  unsigned __int64 v117; // rdx
  wchar_t *v118; // rcx
  signed __int64 v119; // rbx
  Scaleform::Render::Text::Paragraph *v120; // rdi
  unsigned __int64 v121; // rax
  unsigned __int64 v122; // rcx
  bool v123; // cf
  wchar_t *v124; // rcx
  Scaleform::Render::Text::Allocator *v125; // rax
  Scaleform::Render::Text::FontHandle *v126; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v127; // rcx
  Scaleform::Render::Text::FontHandle *v128; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v129; // rcx
  Scaleform::Render::Text::TextFormat *pdefTextFmt; // [rsp+20h] [rbp-A8h]
  Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy> v131; // [rsp+30h] [rbp-98h]
  void *pheapAddr; // [rsp+48h] [rbp-80h]
  wchar_t *ppattrValue; // [rsp+50h] [rbp-78h]
  unsigned __int64 pattrValueSz; // [rsp+58h] [rbp-70h]
  wchar_t *pfontList; // [rsp+60h] [rbp-68h]
  unsigned __int64 fontListSz; // [rsp+68h] [rbp-60h]
  unsigned __int64 len; // [rsp+70h] [rbp-58h]
  Scaleform::Render::Text::SGMLParser<wchar_t> pdefParaFmt; // [rsp+78h] [rbp-50h]
  Scaleform::StringDH *v139; // [rsp+C8h] [rbp+0h]
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v140; // [rsp+D0h] [rbp+8h]
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *v141; // [rsp+D8h] [rbp+10h]
  int v142; // [rsp+E0h] [rbp+18h]
  wchar_t *ppname; // [rsp+E8h] [rbp+20h]
  Scaleform::Render::Text::SGMLElementDesc *v144; // [rsp+F0h] [rbp+28h]
  int v145; // [rsp+F8h] [rbp+30h]
  float v146; // [rsp+FCh] [rbp+34h]
  int v147; // [rsp+100h] [rbp+38h]
  unsigned int v148; // [rsp+104h] [rbp+3Ch]
  int v149; // [rsp+108h] [rbp+40h]
  unsigned int v150; // [rsp+10Ch] [rbp+44h]
  int v151; // [rsp+110h] [rbp+48h]
  int pdestVal; // [rsp+114h] [rbp+4Ch]
  int v153; // [rsp+118h] [rbp+50h]
  int v154; // [rsp+11Ch] [rbp+54h]
  int v155; // [rsp+120h] [rbp+58h]
  Scaleform::Render::Text::TextFormat *v156; // [rsp+128h] [rbp+60h]
  int v157; // [rsp+130h] [rbp+68h]
  int v158; // [rsp+134h] [rbp+6Ch]
  unsigned __int64 plen; // [rsp+138h] [rbp+70h]
  int v160; // [rsp+140h] [rbp+78h]
  Scaleform::Render::Text::TextFormat fmt; // [rsp+148h] [rbp+80h]
  Scaleform::Render::Text::TextFormat __that; // [rsp+198h] [rbp+D0h]
  wchar_t *v163; // [rsp+1E8h] [rbp+120h]
  wchar_t *v164; // [rsp+1F0h] [rbp+128h]
  wchar_t *lookForElemName; // [rsp+1F8h] [rbp+130h]
  Scaleform::Render::Text::SGMLElementDesc *v166; // [rsp+200h] [rbp+138h]
  Scaleform::MemoryHeap *pheap; // [rsp+208h] [rbp+140h]
  Scaleform::Render::Text::SGMLElementDesc *v168; // [rsp+210h] [rbp+148h]
  unsigned __int64 pattrNameSz; // [rsp+218h] [rbp+150h]
  Scaleform::Render::Text::SGMLElementDesc *v170; // [rsp+220h] [rbp+158h]
  wchar_t *v171; // [rsp+228h] [rbp+160h]
  wchar_t *ppattrName; // [rsp+230h] [rbp+168h]
  wchar_t *v173; // [rsp+238h] [rbp+170h]
  Scaleform::Render::Text::SGMLElementDesc *v174; // [rsp+240h] [rbp+178h]
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo val; // [rsp+248h] [rbp+180h]
  Scaleform::Render::Text::ParagraphFormat *v176; // [rsp+288h] [rbp+1C0h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+290h] [rbp+1C8h]
  unsigned __int64 urlSz; // [rsp+298h] [rbp+1D0h]
  Scaleform::Render::Text::TextFormat *v179; // [rsp+2A0h] [rbp+1D8h]
  wchar_t *purl; // [rsp+2A8h] [rbp+1E0h]
  wchar_t *ppContent; // [rsp+2B0h] [rbp+1E8h]
  wchar_t *v182; // [rsp+2B8h] [rbp+1F0h]
  unsigned __int64 pcontentSize; // [rsp+2C0h] [rbp+1F8h]
  Scaleform::Render::Text::ParagraphFormat *v184; // [rsp+2C8h] [rbp+200h]
  Scaleform::Render::Text::ParagraphFormat *v185; // [rsp+2D0h] [rbp+208h]
  Scaleform::Render::Text::SGMLElementDesc *v186; // [rsp+2D8h] [rbp+210h]
  Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> v187; // [rsp+2E0h] [rbp+218h]
  Scaleform::Render::Text::HTMLImageTagDesc *v188; // [rsp+378h] [rbp+2B0h]
  Scaleform::Render::Text::TextFormat v189; // [rsp+388h] [rbp+2C0h]
  __int64 v190; // [rsp+3D8h] [rbp+310h]
  Scaleform::Render::Text::StyledText *v191; // [rsp+438h] [rbp+370h]
  void *v192; // [rsp+448h] [rbp+380h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v193; // [rsp+450h] [rbp+388h]
  char v194; // [rsp+458h] [rbp+390h]
  char vars0; // [rsp+460h] [rbp+398h]
  void *retaddr; // [rsp+468h] [rbp+3A0h]
  Scaleform::Render::Text::StyledText *v197; // [rsp+470h] [rbp+3A8h]
  Scaleform::Render::Text::ParagraphFormat *v198; // [rsp+478h] [rbp+3B0h]

  v197 = this;
  v190 = -2i64;
  v4 = pimgInfoArr;
  v5 = htmlSize;
  v6 = phtml;
  v7 = this;
  if ( !htmlSize )
  {
    Scaleform::Render::Text::StyledText::EnsureTermNull(this);
    return 0;
  }
  pheap = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v192 = &v131;
  v131.Data = 0i64;
  v131.Size = 0i64;
  v131.Policy.Capacity = 0i64;
  pheapAddr = pheap;
  pdefParaFmt.pHeap = pheap;
  pdefParaFmt.CurState = 0;
  pdefParaFmt.Iter.pNextChar = v6;
  pdefParaFmt.Iter.pEnd = &v6[v5];
  pdefParaFmt.Iter.CurChar = 0;
  pdefParaFmt.Iter.DoContentParsing = 0;
  pdefParaFmt.Iter.pCurChar = v6;
  if ( v6 < pdefParaFmt.Iter.pEnd )
  {
    pdefParaFmt.Iter.CurChar = *v6;
    pdefParaFmt.Iter.pNextChar = v6 + 1;
  }
  pdefParaFmt.pBuffer = 0i64;
  pdefParaFmt.BufSize = 0i64;
  pdefParaFmt.BufPos = 0i64;
  pdefParaFmt.CondenseWhite = 0;
  v9 = 0;
  if ( vars0 )
    v9 = 1;
  pdefParaFmt.CondenseWhite = v9;
  v10 = 0i64;
  LODWORD(v192) = 0;
  v11 = (Scaleform::Render::Text::TextFormat *)v197;
  if ( !v197 )
    v11 = v7->pDefaultTextFormat.pObject;
  Scaleform::Render::Text::TextFormat::TextFormat(&__that, v11, 0i64);
  v12 = v198;
  if ( !v198 )
    v12 = v7->pDefaultParagraphFormat.pObject;
  pdefParaFmt.pHeap = 0i64;
  LODWORD(pheapAddr) = 1;
  ppattrValue = 0i64;
  pattrValueSz = *(_QWORD *)&v12->BlockIndent;
  LODWORD(pfontList) = *(_DWORD *)&v12->RightMargin;
  v13 = v12->pTabStops;
  v14 = Scaleform::Memory::pGlobalHeap->vfptr;
  if ( v13 )
  {
    v15 = *v13;
    v14->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    ppattrValue = 0i64;
    ppattrValue = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                               Scaleform::Memory::pGlobalHeap,
                               4i64 * (v15 + 1),
                               0i64);
    *(_DWORD *)ppattrValue = v15;
    memmove(ppattrValue + 2, v13 + 1, 4i64 * v15);
  }
  else
  {
    v14->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    ppattrValue = 0i64;
  }
  fmt.pAllocator = 0i64;
  fmt.RefCount = 1;
  v156 = (Scaleform::Render::Text::TextFormat *)((char *)&fmt + 16);
  Scaleform::StringDH::CopyConstructHelper(
    &fmt.FontList,
    (Scaleform::String *)&__that.FontList.0,
    __that.FontList.pHeap);
  v156 = (Scaleform::Render::Text::TextFormat *)((char *)&fmt + 32);
  Scaleform::StringDH::CopyConstructHelper(&fmt.Url, (Scaleform::String *)&__that.Url.0, __that.FontList.pHeap);
  v16 = __that.pImageDesc.pObject;
  if ( __that.pImageDesc.pObject )
  {
    ++__that.pImageDesc.pObject->RefCount;
    v16 = __that.pImageDesc.pObject;
  }
  fmt.pImageDesc.pObject = v16;
  v17 = __that.pFontHandle.pObject;
  if ( __that.pFontHandle.pObject )
  {
    _InterlockedExchangeAdd(&__that.pFontHandle.pObject->RefCount, 1u);
    v17 = __that.pFontHandle.pObject;
  }
  fmt.pFontHandle.pObject = v17;
  fmt.ColorV = __that.ColorV;
  fmt.LetterSpacing = __that.LetterSpacing;
  fmt.FontSize = __that.FontSize;
  fmt.FormatFlags = __that.FormatFlags;
  fmt.PresentMask = __that.PresentMask;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((__that.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  __that.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)__that.Url.pData & 3;
  Scaleform::String::AppendString((Scaleform::String *)&__that.Url.0, &customWorldMapCaption, 0i64);
  __that.PresentMask |= 0x100u;
  v18 = Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(&pdefParaFmt);
  if ( v18 != 0x8000 )
  {
    v19 = v194;
    while ( 1 )
    {
      if ( v18 == 1 )
        goto LABEL_294;
      if ( v18 == 2 )
        break;
      if ( v18 == 3 )
      {
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseContent(
               &pdefParaFmt,
               (const wchar_t **)&ppContent,
               &pcontentSize) )
        {
          v38 = pcontentSize;
          if ( pcontentSize )
          {
            v39 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
            v40 = v39 ? Scaleform::Render::Text::Paragraph::GetLength(v39) : 0i64;
            if ( !vars0 || v38 > 1 || *ppContent != 32 || v40 )
            {
              if ( v131.Size )
              {
                v41 = &v131.Data[v131.Size - 1].TextFmt;
                Scaleform::Render::Text::StyledText::AppendString(
                  v7,
                  ppContent,
                  v38,
                  NLP_ReplaceCRLF,
                  v41,
                  &v131.Data[v131.Size - 1].ParaFmt);
                Scaleform::Render::Text::TextFormat::operator=(&fmt, v41);
                v19 = v194;
              }
              else
              {
                Scaleform::Render::Text::StyledText::AppendString(
                  v7,
                  ppContent,
                  v38,
                  NLP_ReplaceCRLF,
                  &__that,
                  (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                Scaleform::Render::Text::TextFormat::operator=(&fmt, &__that);
              }
            }
          }
        }
        goto LABEL_293;
      }
      if ( v18 == 4 || v18 == 32773 )
      {
        ppname = 0i64;
        plen = 0i64;
        v20 = 0i64;
        if ( v18 == 4 )
        {
          v21 = v131.Size;
          if ( v131.Size )
            v20 = &v131.Data[v131.Size - 1];
          if ( pdefParaFmt.CurState != 4 )
            goto LABEL_43;
          Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(&pdefParaFmt, (const wchar_t **)&ppname, &plen);
          if ( pdefParaFmt.Iter.CurChar == 62 )
          {
            pdefParaFmt.CurState = 32772;
            pdefParaFmt.Iter.pCurChar = pdefParaFmt.Iter.pNextChar;
            if ( pdefParaFmt.Iter.DoContentParsing && *pdefParaFmt.Iter.pNextChar == 38 )
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&pdefParaFmt.Iter);
              v21 = v131.Size;
LABEL_43:
              if ( v20 )
              {
                v22 = (const wchar_t *)plen;
                v23 = (Scaleform::Render::Text::SGMLElementDesc *)ppname;
                if ( Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
                       ppname,
                       plen,
                       v20->pElemName,
                       v20->ElemNameSize) )
                {
                  v24 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                          v23,
                          v22,
                          (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::elementsTable,
                          (Scaleform::Render::Text::SGMLElementDesc *)0xD,
                          (unsigned __int64)pdefTextFmt);
                  v25 = v24;
                  if ( v24 && (_DWORD)v192 && (unsigned int)(v24->ElemId - 6) <= 1 )
                  {
                    while ( v21 )
                    {
                      v26 = *((_QWORD *)&v131.Data[v21] - 17);
                      if ( v26 && v25->ElemId == *(_DWORD *)(v26 + 8) )
                      {
                        if ( !v21 )
                          break;
                        v20 = &v131.Data[v21 - 1];
                        goto LABEL_56;
                      }
                      Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                        &v131,
                        pheapAddr,
                        v21 - 1);
                      if ( v21 - 1 > v21 )
                        Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::ConstructArray(
                          &v131.Data[v21],
                          0xFFFFFFFFFFFFFFFFui64);
                      v21 = v131.Size;
                    }
                  }
LABEL_291:
                  v19 = v194;
LABEL_292:
                  v4 = v193;
                  goto LABEL_293;
                }
LABEL_56:
                v27 = v20->ParaFmt.PresentMask;
                v28 = BYTE1(v27) & 1;
                v29 = (v27 >> 11) & 3;
                v10 = (__int64)v20->pElemDesc;
                v30 = v20->StartPos;
                Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  &v131,
                  pheapAddr,
                  v21 - 1);
                if ( v21 - 1 > v21 )
                  Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::ConstructArray(
                    &v131.Data[v21],
                    0xFFFFFFFFFFFFFFFFui64);
                if ( v10 )
                {
                  if ( *(_DWORD *)(v10 + 8) == 6
                    || *(_DWORD *)(v10 + 8) == 7 && (LODWORD(v192) = (_DWORD)v192 - 1, v18 != 32773) )
                  {
LABEL_62:
                    v19 = v194;
                    v7 = v191;
                    if ( v194 )
                    {
                      v31 = "\n";
                      if ( v191->RTFlags & 2 )
                        v31 = "\r";
                      Scaleform::Render::Text::StyledText::AppendString(
                        v191,
                        v31,
                        1ui64,
                        NLP_ReplaceCRLF,
                        &fmt,
                        (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                    }
                    goto LABEL_292;
                  }
                }
                else if ( retaddr && v28 )
                {
                  v32 = v29 - 1;
                  if ( !v32 )
                    goto LABEL_62;
                  if ( v32 == 1 )
                  {
                    v33 = v191;
                    v34 = Scaleform::Render::Text::StyledText::GetLength(v191);
                    if ( v194 )
                    {
                      v35 = "\n";
                      if ( v33->RTFlags & 2 )
                        v35 = "\r";
                      Scaleform::Render::Text::StyledText::AppendString(
                        v33,
                        v35,
                        1ui64,
                        NLP_ReplaceCRLF,
                        &fmt,
                        (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
                    }
                    v36 = v34 - v30;
                    v37 = v30;
                    v7 = v191;
                    Scaleform::Render::Text::StyledText::Remove(v191, v37, v36);
                    goto LABEL_291;
                  }
                }
                v7 = v191;
                goto LABEL_291;
              }
LABEL_289:
              v19 = v194;
              goto LABEL_290;
            }
            if ( pdefParaFmt.Iter.pNextChar < pdefParaFmt.Iter.pEnd )
            {
              pdefParaFmt.Iter.CurChar = *pdefParaFmt.Iter.pNextChar;
              ++pdefParaFmt.Iter.pNextChar;
              v21 = v131.Size;
              goto LABEL_43;
            }
          }
          else
          {
            pdefParaFmt.CurState = 1;
          }
          v21 = v131.Size;
          goto LABEL_43;
        }
        if ( !v10 || !*(_BYTE *)(v10 + 13) )
        {
          v21 = v131.Size;
          if ( v131.Size )
          {
            v20 = &v131.Data[v131.Size - 1];
            ppname = (wchar_t *)v20->pElemName;
            plen = v20->ElemNameSize;
            goto LABEL_43;
          }
          goto LABEL_289;
        }
LABEL_290:
        v4 = v193;
      }
LABEL_293:
      v18 = Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(&pdefParaFmt);
      if ( v18 == 0x8000 )
        goto LABEL_294;
    }
    v144 = 0i64;
    if ( pdefParaFmt.CurState == 2 )
    {
      Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(
        &pdefParaFmt,
        (const wchar_t **)&v144,
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
          pdefParaFmt.Iter.CurChar = *pdefParaFmt.Iter.pNextChar;
          ++pdefParaFmt.Iter.pNextChar;
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
    v42 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
            v144,
            lookForElemName,
            (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::elementsTable,
            (Scaleform::Render::Text::SGMLElementDesc *)0xD,
            (unsigned __int64)pdefTextFmt);
    v10 = (__int64)v42;
    v139 = (Scaleform::StringDH *)v42;
    v43 = LODWORD(v131.Size) - 1;
    if ( v42 && v42->EmptyElement )
    {
      v44 = v42->ElemId;
      if ( v44 == 2 )
      {
        if ( v19 )
        {
          v64 = "\n";
          if ( v7->RTFlags & 2 )
            v64 = "\r";
          Scaleform::Render::Text::StyledText::AppendString(
            v7,
            v64,
            1ui64,
            NLP_ReplaceCRLF,
            &fmt,
            (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
        }
        goto LABEL_293;
      }
      if ( v44 != 5 )
      {
        if ( v44 == 9 )
          Scaleform::Render::Text::StyledText::AppendString(
            v7,
            "\t",
            1ui64,
            NLP_ReplaceCRLF,
            v7->pDefaultTextFormat.pObject,
            v7->pDefaultParagraphFormat.pObject);
        goto LABEL_293;
      }
      if ( v4 )
      {
        val.pTextImageDesc.pObject = 0i64;
        val.Url.pHeap = pheap;
        _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
        val.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
        v139 = &val.Id;
        val.Id.pHeap = pheap;
        _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
        val.Id.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
        *(_QWORD *)&val.Width = 0i64;
        *(_QWORD *)&val.VSpace = 0i64;
        val.ParaId = -1;
        val.Alignment = 0;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,Scaleform::AllocatorDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,Scaleform::AllocatorDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->Data,
          &val);
        Scaleform::Render::Text::StyledText::HTMLImageTagInfo::~HTMLImageTagInfo(&val);
        v45 = v4->Data.Size << 6;
        v46 = v4->Data.Data;
        v47 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        if ( !v47 )
          v47 = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                  v7,
                  (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
        Scaleform::Render::Text::TextFormat::TextFormat(&v189, &__that, 0i64);
        *(_DWORD *)((char *)v46 + v45 - 8) = v47->UniqueId;
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&ppattrName,
               &pattrNameSz) )
        {
          do
          {
            v48 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    (Scaleform::Render::Text::SGMLElementDesc *)ppattrName,
                    (const wchar_t *)pattrNameSz,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v48
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&ppattrValue,
                   &pattrValueSz) )
            {
              switch ( v48->ElemId )
              {
                case 0xC:
                  v50 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                          (Scaleform::Render::Text::SGMLElementDesc *)ppattrValue,
                          (const wchar_t *)pattrValueSz,
                          (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                          (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                          (unsigned __int64)pdefTextFmt);
                  if ( v50 )
                  {
                    v51 = v50->ElemId - 14;
                    if ( v51 )
                    {
                      v52 = v51 - 21;
                      if ( v52 )
                      {
                        if ( v52 == 1 )
                          *((_BYTE *)v46 + v45 - 4) = 1;
                      }
                      else
                      {
                        *((_BYTE *)v46 + v45 - 4) = 2;
                      }
                    }
                    else
                    {
                      *((_BYTE *)v46 + v45 - 4) = 0;
                    }
                  }
                  break;
                case 0x13:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v158, ppattrValue, pattrValueSz)
                    && v158 >= 0 )
                  {
                    *(_DWORD *)((char *)v46 + v45 - 20) = 20 * v158;
                  }
                  break;
                case 0x15:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v157, ppattrValue, pattrValueSz) )
                    *(_DWORD *)((char *)v46 + v45 - 12) = 20 * v157;
                  break;
                case 0x16:
                  v49 = (signed __int64)&v46[-1].Id;
                  goto LABEL_112;
                case 0x1D:
                  v49 = (signed __int64)&v46[-1].Url;
LABEL_112:
                  Scaleform::String::AppendString((Scaleform::String *)(v45 + v49), ppattrValue, pattrValueSz);
                  break;
                case 0x21:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v147, ppattrValue, pattrValueSz) )
                    *(_DWORD *)((char *)v46 + v45 - 16) = 20 * v147;
                  break;
                case 0x22:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&pdestVal, ppattrValue, pattrValueSz)
                    && pdestVal >= 0 )
                  {
                    *(_DWORD *)((char *)v46 + v45 - 24) = 20 * pdestVal;
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
          v7 = v191;
        }
        v142 = 74;
        v53 = (Scaleform::Render::Text::HTMLImageTagDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             v7,
                                                             112ui64,
                                                             (Scaleform::AllocInfo *)&v142);
        v139 = (Scaleform::StringDH *)v53;
        if ( v53 )
        {
          Scaleform::Render::Text::HTMLImageTagDesc::HTMLImageTagDesc(v53);
          v55 = v54;
        }
        else
        {
          v55 = 0i64;
        }
        v188 = v55;
        if ( v55 )
          ++v55->RefCount;
        v56 = v189.pImageDesc.pObject;
        if ( v189.pImageDesc.pObject )
        {
          --v189.pImageDesc.pObject->RefCount;
          if ( !v56->RefCount )
            v56->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v56->vfptr, 1u);
        }
        v189.pImageDesc.pObject = v55;
        v189.PresentMask |= 0x200u;
        v55->ScreenWidth = (float)*(signed int *)((char *)v46 + v45 - 24);
        v55->ScreenHeight = (float)*(signed int *)((char *)v46 + v45 - 20);
        v55->VSpace = *(_DWORD *)((char *)v46 + v45 - 16);
        v55->HSpace = *(_DWORD *)((char *)v46 + v45 - 12);
        Scaleform::String::operator=(
          (Scaleform::String *)&v55->Url.0,
          (Scaleform::String *)((char *)&v46[-1].Url.0 + v45));
        Scaleform::String::operator=(
          (Scaleform::String *)&v55->Id.0,
          (Scaleform::String *)((char *)&v46[-1].Id.0 + v45));
        v55->Alignment = *((_BYTE *)v46 + v45 - 4);
        ++v55->RefCount;
        v57 = *(__int64 *)((char *)&v46[-1].pTextImageDesc.pObject + v45);
        if ( v57 )
        {
          v58 = (*(_DWORD *)(v57 + 8))-- == 1;
          if ( v58 )
            (**(void (__fastcall ***)(__int64, signed __int64))v57)(v57, 1i64);
        }
        *(Scaleform::Render::Text::ImageDesc **)((char *)&v46[-1].pTextImageDesc.pObject + v45) = (Scaleform::Render::Text::ImageDesc *)&v55->vfptr;
        if ( v43 < 0 )
        {
          v60 = &__that;
          v61 = (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt;
        }
        else
        {
          v59 = v43;
          v60 = &v131.Data[v59].TextFmt;
          v61 = &v131.Data[v59].ParaFmt;
        }
        if ( Scaleform::Render::Text::TextFormat::IsUrlSet(v60) )
        {
          Scaleform::String::operator=((Scaleform::String *)&v189.Url.0, (Scaleform::String *)&v60->Url.0);
          v189.PresentMask |= 0x100u;
        }
        Scaleform::Render::Text::StyledText::AppendString(v7, " ", 1ui64, NLP_ReplaceCRLF, &v189, v61);
        v62 = v60->pImageDesc.pObject;
        if ( v62 )
        {
          v58 = v62->RefCount-- == 1;
          if ( v58 )
            v62->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v62->vfptr, 1u);
        }
        v60->pImageDesc.pObject = 0i64;
        v60->PresentMask |= 0x200u;
        v63 = fmt.pImageDesc.pObject;
        if ( fmt.pImageDesc.pObject )
        {
          --fmt.pImageDesc.pObject->RefCount;
          if ( !v63->RefCount )
            v63->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v63->vfptr, 1u);
        }
        fmt.pImageDesc.pObject = 0i64;
        fmt.PresentMask |= 0x200u;
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, v60);
        Scaleform::Render::Text::TextFormat::operator=(&__that, v60);
        v58 = v55->RefCount-- == 1;
        if ( v58 )
          v55->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v55->vfptr, 1u);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v189);
        goto LABEL_291;
      }
      goto LABEL_293;
    }
    v65 = Scaleform::Render::Text::StyledText::GetLength(v7);
    v187.pElemName = (const wchar_t *)v144;
    v187.ElemNameSize = (unsigned __int64)lookForElemName;
    v187.pElemDesc = (Scaleform::Render::Text::SGMLElementDesc *)v10;
    v187.StartPos = 0i64;
    Scaleform::Render::Text::TextFormat::TextFormat(&v187.TextFmt, pheap);
    v187.ParaFmt.pAllocator = 0i64;
    v187.ParaFmt.RefCount = 1;
    v187.ParaFmt.pTabStops = 0i64;
    *(_QWORD *)&v187.ParaFmt.BlockIndent = 0i64;
    *(_DWORD *)&v187.ParaFmt.RightMargin = 0;
    Scaleform::ArrayDataBase<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,Scaleform::AllocatorDH<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v131,
      pheapAddr,
      v131.Size + 1);
    v141 = &v131.Data[v131.Size - 1];
    v140 = &v131.Data[v131.Size - 1];
    if ( v141 )
      Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>::SGMLStackElemDesc<wchar_t>(&v131.Data[v131.Size - 1], &v187);
    if ( v187.ParaFmt.pAllocator )
    {
      key = &v187.ParaFmt;
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v187.ParaFmt.pAllocator->ParagraphFormatStorage.pTable,
        &key);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v187.ParaFmt.pTabStops);
    v187.ParaFmt.pTabStops = 0i64;
    Scaleform::Render::Text::TextFormat::~TextFormat(&v187.TextFmt);
    v66 = v131.Size;
    v67 = v131.Data;
    *((_QWORD *)&v131.Data[v66] - 16) = v65;
    v68 = &v67[v66 - 1].TextFmt;
    v141 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)((char *)&v67[v66 - 1] + 32);
    v69 = &v67[v66 - 1].TextFmt;
    if ( v43 < 0 )
    {
      Scaleform::Render::Text::TextFormat::operator=(v69, &__that);
      v71 = (signed __int64)&v67[v66 - 1].ParaFmt;
      *(_QWORD *)(v71 + 24) = pattrValueSz;
      *(_DWORD *)(v71 + 32) = (_DWORD)pfontList;
      Scaleform::Render::Text::ParagraphFormat::CopyTabStops(&v67[v66 - 1].ParaFmt, (const unsigned int *)ppattrValue);
    }
    else
    {
      v70 = v43;
      Scaleform::Render::Text::TextFormat::operator=(v69, &v131.Data[v70].TextFmt);
      v71 = (signed __int64)&v67[v66 - 1].ParaFmt;
      Scaleform::Render::Text::ParagraphFormat::operator=(&v67[v66 - 1].ParaFmt, &v131.Data[v70].ParaFmt);
    }
    if ( !v139 )
    {
LABEL_287:
      Scaleform::Render::Text::TextFormat::operator=(&fmt, v68);
      v10 = (__int64)v139;
      goto LABEL_291;
    }
    switch ( LODWORD(v139->pHeap) )
    {
      case 0:
        while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                  &pdefParaFmt,
                  (const wchar_t **)&v174,
                  (unsigned __int64 *)&v163) )
        {
          v72 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                  v174,
                  v163,
                  (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                  (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                  (unsigned __int64)pdefTextFmt);
          if ( v72
            && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                 &pdefParaFmt,
                 (const wchar_t **)&purl,
                 &urlSz)
            && v72->ElemId == 20 )
          {
            Scaleform::Render::Text::TextFormat::SetUrl(v68, purl, urlSz);
            v7->RTFlags |= 1u;
          }
        }
        goto LABEL_287;
      case 1:
        Scaleform::Render::Text::TextFormat::SetBold(v68, 1);
        goto LABEL_287;
      case 3:
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&v166,
               (unsigned __int64 *)&v164) )
        {
          do
          {
            v87 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    v166,
                    v164,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v87
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&pfontList,
                   &fontListSz) )
            {
              switch ( v87->ElemId )
              {
                case 0xD:
                  if ( *pfontList == 35
                    && Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(&v150, pfontList + 1, fontListSz - 1) )
                  {
                    v68->ColorV &= 0xFFFFFFu;
                    v68->ColorV |= (unsigned __int8)v150 << 24;
                    v68->PresentMask |= 0x400u;
                  }
                  break;
                case 0x11:
                  if ( *pfontList == 35
                    && Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(&v148, pfontList + 1, fontListSz - 1) )
                  {
                    v68->ColorV &= 0xFF000000;
                    v68->ColorV |= v148 & 0xFFFFFF;
                    v68->PresentMask |= 1u;
                  }
                  break;
                case 0x12:
                  Scaleform::Render::Text::TextFormat::SetFontList(v68, pfontList, fontListSz);
                  break;
                case 0x18:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v151, pfontList, fontListSz) && v151 >= 0 )
                  {
                    if ( v151 )
                    {
                      v68->FormatFlags |= 8u;
                      v68->PresentMask |= 0x80u;
                    }
                    else
                    {
                      v68->FormatFlags &= 0xF7u;
                      v68->PresentMask &= 0xFF7Fu;
                    }
                  }
                  break;
                case 0x1B:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseFloat(&v146, pfontList, fontListSz) )
                  {
                    v68->PresentMask |= 2u;
                    v68->LetterSpacing = v146 * 20.0;
                  }
                  break;
                case 0x1E:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v155, pfontList, fontListSz) && v155 >= 0 )
                    Scaleform::Render::Text::TextFormat::SetFontSize(v68, (float)v155);
                  break;
                default:
                  break;
              }
            }
          }
          while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                    &pdefParaFmt,
                    (const wchar_t **)&v166,
                    (unsigned __int64 *)&v164) );
          v7 = v191;
        }
        Scaleform::Render::Text::TextFormat::operator=(&fmt, v68);
        goto LABEL_287;
      case 4:
        Scaleform::Render::Text::TextFormat::SetItalic(v68, 1);
        goto LABEL_287;
      case 6:
        *(_WORD *)(v71 + 34) |= 0x8080u;
        v73 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        v74 = v73;
        if ( v73 )
        {
          if ( Scaleform::Render::Text::Paragraph::GetLength(v73) )
          {
            if ( v194 )
            {
              v75 = "\n";
              if ( v7->RTFlags & 2 )
                v75 = "\r";
              Scaleform::Render::Text::StyledText::AppendString(
                v7,
                v75,
                1ui64,
                NLP_ReplaceCRLF,
                &fmt,
                (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
            }
            v74 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
          }
          v76 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
          Scaleform::Render::Text::Paragraph::SetFormat(v74, v76, (Scaleform::Render::Text::ParagraphFormat *)v71);
        }
        else
        {
          Scaleform::Render::Text::StyledText::AppendNewParagraph(v7, (Scaleform::Render::Text::ParagraphFormat *)v71);
        }
        goto LABEL_287;
      case 7:
        v77 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        v140 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v77;
        if ( v77 )
        {
          v79 = (signed int)v192;
          if ( !(_DWORD)v192 )
          {
LABEL_195:
            if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                   &pdefParaFmt,
                   (const wchar_t **)&v170,
                   (unsigned __int64 *)&v173) )
            {
              do
              {
                v81 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                        v170,
                        v173,
                        (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                        (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                        (unsigned __int64)pdefTextFmt);
                if ( v81 )
                {
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                         &pdefParaFmt,
                         (const wchar_t **)&v186,
                         (unsigned __int64 *)&v182)
                    && v81->ElemId == 12 )
                  {
                    v82 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                            v186,
                            v182,
                            (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                            (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                            (unsigned __int64)pdefTextFmt);
                    if ( v82 )
                    {
                      v83 = v82->ElemId - 35;
                      if ( v83 )
                      {
                        v84 = v83 - 1;
                        if ( v84 )
                        {
                          v85 = v84 - 1;
                          if ( v85 )
                          {
                            if ( v85 == 1 )
                            {
                              *(_WORD *)(v71 + 34) &= 0xFDFFu;
                              *(_WORD *)(v71 + 34) |= 0x401u;
                            }
                          }
                          else
                          {
                            *(_WORD *)(v71 + 34) |= 0x601u;
                          }
                        }
                        else
                        {
                          *(_WORD *)(v71 + 34) &= 0xFBFFu;
                          *(_WORD *)(v71 + 34) |= 0x201u;
                        }
                      }
                      else
                      {
                        *(_WORD *)(v71 + 34) &= 0xF9FFu;
                        *(_WORD *)(v71 + 34) |= 1u;
                      }
                    }
                  }
                }
              }
              while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                        &pdefParaFmt,
                        (const wchar_t **)&v170,
                        (unsigned __int64 *)&v173) );
              v77 = (Scaleform::Render::Text::Paragraph *)v140;
              v68 = (Scaleform::Render::Text::TextFormat *)v141;
              v7 = v191;
              v79 = (signed int)v192;
            }
            if ( !Scaleform::Render::Text::Paragraph::GetLength(v77) )
            {
              v86 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
              Scaleform::Render::Text::Paragraph::SetFormat(v77, v86, (Scaleform::Render::Text::ParagraphFormat *)v71);
            }
            LODWORD(v192) = v79 + 1;
            goto LABEL_287;
          }
          if ( v194 )
          {
            v80 = "\n";
            if ( v7->RTFlags & 2 )
              v80 = "\r";
            Scaleform::Render::Text::StyledText::AppendString(
              v7,
              v80,
              1ui64,
              NLP_ReplaceCRLF,
              &fmt,
              (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
          }
          v78 = Scaleform::Render::Text::StyledText::GetLastParagraph(v7);
        }
        else
        {
          v78 = Scaleform::Render::Text::StyledText::AppendNewParagraph(
                  v7,
                  (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
          v79 = (signed int)v192;
        }
        v140 = (Scaleform::Render::Text::SGMLStackElemDesc<wchar_t> *)v78;
        v77 = v78;
        goto LABEL_195;
      case 0xA:
        if ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
               &pdefParaFmt,
               (const wchar_t **)&v168,
               (unsigned __int64 *)&v171) )
        {
          do
          {
            v88 = Scaleform::Render::Text::SGMLElementDesc::FindElem<wchar_t>(
                    v168,
                    v171,
                    (unsigned __int64)`Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>::`2::attributesTable,
                    (Scaleform::Render::Text::SGMLElementDesc *)0x1B,
                    (unsigned __int64)pdefTextFmt);
            if ( v88
              && Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
                   &pdefParaFmt,
                   (const wchar_t **)&fontListSz,
                   &len) )
            {
              switch ( v88->ElemId )
              {
                case 0xF:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v160, (const wchar_t *)fontListSz, len)
                    && v160 >= 0 )
                  {
                    *(_WORD *)(v71 + 24) = v160;
                    *(_WORD *)(v71 + 34) |= 2u;
                  }
                  break;
                case 0x17:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v154, (const wchar_t *)fontListSz, len) )
                  {
                    *(_WORD *)(v71 + 26) = v154;
                    *(_WORD *)(v71 + 34) |= 4u;
                  }
                  break;
                case 0x19:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v149, (const wchar_t *)fontListSz, len) )
                  {
                    *(_WORD *)(v71 + 28) = v149;
                    *(_WORD *)(v71 + 34) |= 8u;
                  }
                  break;
                case 0x1A:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v153, (const wchar_t *)fontListSz, len)
                    && v153 >= 0 )
                  {
                    *(_WORD *)(v71 + 30) = v153;
                    *(_WORD *)(v71 + 34) |= 0x10u;
                  }
                  break;
                case 0x1C:
                  if ( Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(&v145, (const wchar_t *)fontListSz, len)
                    && v145 >= 0 )
                  {
                    *(_WORD *)(v71 + 32) = v145;
                    *(_WORD *)(v71 + 34) |= 0x20u;
                  }
                  break;
                case 0x20:
                  v89 = 0i64;
                  v90 = fontListSz;
                  v91 = len;
                  if ( len )
                  {
                    do
                    {
                      if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(*(unsigned __int16 *)(v90 + 2 * v89)) )
                        break;
                      ++v89;
                    }
                    while ( v89 < v91 );
                  }
                  if ( *(_WORD *)(v90 + 2 * v89) == 91 )
                    ++v89;
                  v92 = 1;
                  for ( i = v89; i < v91; ++i )
                  {
                    v94 = *(_WORD *)(v90 + 2 * i);
                    if ( v94 == 93 )
                      break;
                    if ( v94 == 44 )
                      ++v92;
                  }
                  Scaleform::Render::Text::ParagraphFormat::SetTabStopsNum(
                    (Scaleform::Render::Text::ParagraphFormat *)v71,
                    v92);
                  v95 = 0;
                  if ( v89 < v91 )
                  {
                    while ( *(_WORD *)(v90 + 2 * v89) != 93 )
                    {
                      v96 = 0;
                      while ( isdigit(*(unsigned __int16 *)(v90 + 2 * v89)) )
                      {
                        v96 = *(unsigned __int16 *)(v90 + 2 * v89++) + 2 * (5 * v96 - 24);
                        if ( v89 >= v91 )
                          goto LABEL_278;
                      }
                      for ( ; v89 < v91; ++v89 )
                      {
                        v97 = *(_WORD *)(v90 + 2 * v89);
                        v98 = (unsigned __int64)*(unsigned __int16 *)(v90 + 2 * v89) >> 8;
                        v99 = Scaleform::UnicodeSpaceBits[v98];
                        if ( !Scaleform::UnicodeSpaceBits[v98] )
                          break;
                        if ( v99 != 1 )
                        {
                          v100 = Scaleform::UnicodeSpaceBits[v99 + ((unsigned __int8)v97 >> 4)];
                          if ( !_bittest(&v100, v97 & 0xF) )
                            break;
                        }
                      }
LABEL_278:
                      v101 = *(unsigned int **)(v71 + 16);
                      if ( v101 && v95 < *v101 )
                        v101[v95 + 1] = v96;
                      ++v95;
                      if ( *(_WORD *)(v90 + 2 * v89) == 44 )
                      {
                        while ( ++v89 < v91 )
                        {
                          if ( !Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(*(unsigned __int16 *)(v90 + 2 * v89)) )
                            goto LABEL_284;
                        }
                        goto LABEL_285;
                      }
LABEL_284:
                      if ( v89 >= v91 )
                        goto LABEL_285;
                    }
                  }
                  break;
                default:
                  break;
              }
            }
LABEL_285:
            ;
          }
          while ( Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
                    &pdefParaFmt,
                    (const wchar_t **)&v168,
                    (unsigned __int64 *)&v171) );
          v68 = (Scaleform::Render::Text::TextFormat *)v141;
          v7 = v191;
        }
        goto LABEL_287;
      case 0xB:
        v68->FormatFlags |= 4u;
        v68->PresentMask |= 0x40u;
        goto LABEL_287;
      default:
        goto LABEL_287;
    }
  }
LABEL_294:
  if ( v131.Size )
  {
    v102 = v131.Size;
    v103 = v131.Data;
    v104 = &v131.Data[v131.Size];
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, &v104[-1].TextFmt);
    v105 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
    v106 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(v105, &v103[v102 - 1].ParaFmt);
    v107 = v7->pDefaultParagraphFormat.pObject;
    if ( v107 )
    {
      v58 = v107->RefCount-- == 1;
      if ( v58 )
      {
        v108 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v107->pAllocator;
        if ( v107->pAllocator )
        {
          v185 = v107;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            v108 + 3,
            &v185);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v107->pTabStops);
        v107->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v107);
      }
    }
    v7->pDefaultParagraphFormat.pObject = v106;
    Scaleform::Render::Text::TextFormat::operator=(&fmt, &v104[-1].TextFmt);
  }
  else
  {
    Scaleform::Render::Text::StyledText::SetDefaultTextFormat(v7, &__that);
    v109 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
    v110 = Scaleform::Render::Text::Allocator::AllocateParagraphFormat(
             v109,
             (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt);
    v111 = v7->pDefaultParagraphFormat.pObject;
    if ( v111 )
    {
      v58 = v111->RefCount-- == 1;
      if ( v58 )
      {
        v112 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)v111->pAllocator;
        if ( v111->pAllocator )
        {
          v176 = v111;
          Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
            v112 + 3,
            &v176);
        }
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v111->pTabStops);
        v111->pTabStops = 0i64;
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v111);
      }
    }
    v7->pDefaultParagraphFormat.pObject = v110;
  }
  Scaleform::Render::Text::StyledText::EnsureTermNull(v7);
  v113 = v7->Paragraphs.Data.Size;
  v114 = v113 - 1;
  if ( (signed __int64)(v113 - 1) >= 0 && v114 < (signed int)v113 )
  {
    v115 = v7->Paragraphs.Data.Data[v114].pPara;
    if ( v115 )
    {
      v116 = v115->Text.Size;
      if ( !v116 )
        goto LABEL_359;
      v117 = v116 - 1;
      if ( !v115->Text.pText || (v118 = &v115->Text.pText[v117], v117 >= v116) )
        v118 = 0i64;
      if ( !*v118 )
        --v116;
      if ( !v116 )
      {
LABEL_359:
        v119 = v7->Paragraphs.Data.Size;
        while ( --v119 >= 0 && v119 < SLODWORD(v7->Paragraphs.Data.Size) )
        {
          v120 = v7->Paragraphs.Data.Data[v119].pPara;
          v121 = v120->Text.Size;
          if ( v121 )
          {
            v122 = v121 - 1;
            if ( !v120->Text.pText || (v123 = v122 < v121, v124 = &v120->Text.pText[v122], !v123) )
              v124 = 0i64;
            if ( !*v124 )
              --v121;
          }
          if ( v121 > 1 )
            break;
          v125 = Scaleform::Render::Text::StyledText::GetAllocator(v7);
          Scaleform::Render::Text::Paragraph::SetTextFormat(v120, v125, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
        }
      }
    }
  }
  if ( fmt.pAllocator )
  {
    v179 = &fmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&fmt.pAllocator->TextFormatStorage.pTable,
      &v179);
  }
  v126 = fmt.pFontHandle.pObject;
  if ( fmt.pFontHandle.pObject && _InterlockedExchangeAdd(&fmt.pFontHandle.pObject->RefCount, 0xFFFFFFFF) == 1 && v126 )
    v126->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v126->vfptr, 1u);
  v127 = fmt.pImageDesc.pObject;
  if ( fmt.pImageDesc.pObject )
  {
    --fmt.pImageDesc.pObject->RefCount;
    if ( !v127->RefCount )
      v127->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v127->vfptr, 1u);
  }
  v192 = &fmt.Url;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((fmt.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v192 = &fmt.FontList;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((fmt.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( pdefParaFmt.pHeap )
  {
    v184 = (Scaleform::Render::Text::ParagraphFormat *)&pdefParaFmt;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&pdefParaFmt.pHeap->SelfSize,
      &v184);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ppattrValue);
  ppattrValue = 0i64;
  if ( __that.pAllocator )
  {
    v156 = &__that;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&__that.pAllocator->TextFormatStorage.pTable,
      &v156);
  }
  v128 = __that.pFontHandle.pObject;
  if ( __that.pFontHandle.pObject
    && _InterlockedExchangeAdd(&__that.pFontHandle.pObject->RefCount, 0xFFFFFFFF) == 1
    && v128 )
  {
    v128->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v128->vfptr, 1u);
  }
  v129 = __that.pImageDesc.pObject;
  if ( __that.pImageDesc.pObject )
  {
    --__that.pImageDesc.pObject->RefCount;
    if ( !v129->RefCount )
      v129->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v129->vfptr, 1u);
  }
  v192 = &__that.Url;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((__that.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v192 = &__that.FontList;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((__that.FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pdefParaFmt.pBuffer);
  v192 = &v131;
  Scaleform::ConstructorMov<Scaleform::Render::Text::SGMLStackElemDesc<wchar_t>>::DestructArray(v131.Data, v131.Size);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v131.Data);
  return 1;
}::TextFormat::HashFunctor> > *)&__that.pAllocator->TextFormatStorage.pTable,
      &v156);
  }
  v128 = __that.pFontHandle.pObject;
  if ( __that.pFontHandle.pObject
    && _InterlockedExchangeAdd(&__that.pFontHandle.pObject->RefCount, 0xFFFFFFFF) == 1
    && v128 )
  {
    v128->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v128->vfptr, 1u);
  }
  v129 = __that.pImageDesc.pObject;
  if ( __that.pImageDesc.pObject )
  {
    --__that.pImageDesc.pObject->RefCount;
    if ( !v129->RefCount )
      v129->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v129->vfptr, 1u);
  }
  v192 = &__that.Url;
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((__that.Url.Heap

// File Line: 1032
// RVA: 0x99E710
__int64 __fastcall Scaleform::Render::Text::StyledText::ParseHtml(Scaleform::Render::Text::StyledText *this, const char *phtml, unsigned __int64 htmlSize, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *pimgInfoArr)
{
  Scaleform::Render::Text::StyledText *v4; // r14
  const char *v5; // rdi
  __int64 v6; // rbx
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v7; // rbp
  wchar_t *v8; // rax
  wchar_t *v9; // rsi
  signed __int64 v10; // rax

  v4 = this;
  v5 = phtml;
  v6 = htmlSize;
  v7 = pimgInfoArr;
  v8 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * htmlSize + 2, 0i64);
  v9 = v8;
  v10 = Scaleform::UTF8Util::DecodeStringSafe(v8, v6 + 1, v5, v6);
  LOBYTE(v6) = Scaleform::Render::Text::StyledText::ParseHtmlImpl<wchar_t>(v4, v9, v10, v7);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  return (unsigned __int8)v6;
}

