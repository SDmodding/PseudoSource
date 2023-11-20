// File Line: 101
// RVA: 0xA276F0
void __fastcall UFG::UIDictionary::LoadDictionary(UFG::UIDictionary *this, const char *filename)
{
  const char *v2; // rdi
  UFG::UIDictionary *v3; // rsi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  int v6; // eax
  UFG::qString *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  int v10; // edx
  unsigned int v11; // ebx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qString v14; // [rsp+38h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-38h]

  v2 = filename;
  v3 = this;
  v4 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mDatabaseHandle.mPrev, v4);
  UFG::StreamResourceLoader::UnloadResourceFile(v3->mFilename);
  v3->mFilename[0] = 0;
  v6 = UFG::qStringLength(v2);
  UFG::qStringCopy(v3->mFilename, 256, v2, v6);
  UFG::qString::qString(&v14, v3->mFilename);
  v7 = UFG::qString::GetFilenameWithoutExtension(&v14, &result);
  UFG::qString::Set(&v14, v7->mData, v7->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v8 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v3->mDatabaseHandle.mPrev, v8);
  v11 = v14.mStringHashUpper32;
  if ( v14.mStringHashUpper32 == -1 )
  {
    v11 = UFG::qStringHashUpper32(v14.mData, v14.mStringHashUpper32 | v10);
    v14.mStringHashUpper32 = v11;
  }
  v12 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mDatabaseHandle.mPrev, 0x90CE6B7A, v11, v12);
  if ( UFG::StreamFileWrapper::FileExists(v2) )
    UFG::StreamResourceLoader::LoadResourceFile(v2, &gScaleformMemoryPool, 1u, 0i64, 0i64, 0i64);
  UFG::UIDictionary::PrintDictionary(v3);
  UFG::qString::~qString(&v14);
}

// File Line: 209
// RVA: 0xA28670
void __fastcall UFG::UIDictionary::UnloadDictionary(UFG::UIDictionary *this)
{
  UFG::qResourceInventory *v1; // rax
  UFG::UIDictionary *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax

  v1 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result;
  v2 = this;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v3, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>'::`2'::result = v1;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mDatabaseHandle.mPrev, v1);
  UFG::StreamResourceLoader::UnloadResourceFile(v2->mFilename);
  v2->mFilename[0] = 0;
}

// File Line: 288
// RVA: 0xA27FC0
void __fastcall UFG::UIDictionary::PrintDictionary(UFG::UIDictionary *this)
{
  UFG::UIDictionary *v1; // rdi
  UFG::qBaseTreeRB *i; // rbx

  v1 = this;
  UFG::qPrintf("=== Dictionary %s ===\n", this->mSectionName);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mStringMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v1->mStringMap.mTree, &i->mRoot) )
  {
    UFG::qPrintf("0x%8X\t%s\n", i->mRoot.mUID, i->mNULL.mParent);
  }
}

// File Line: 310
// RVA: 0xA2FD10
void __fastcall UFG::UIGfxTranslator::init(UFG::UIGfxTranslator *this, UFG::UIScreenFactory *screenFactory, Scaleform::GFx::Loader *gfxLoader)
{
  Scaleform::GFx::Loader *v3; // rdi
  UFG::UIGfxTranslator *v4; // rbx

  this->mScreenFactory = screenFactory;
  v3 = gfxLoader;
  v4 = this;
  gfxLoader->vfptr->SetState((Scaleform::GFx::StateBag *)gfxLoader, State_BlendMode, (Scaleform::GFx::State *)this);
  v4->mGfxLoader = v3;
}

// File Line: 333
// RVA: 0xA30570
void __fastcall UFG::UIGfxTranslator::loadDictionary(UFG::UIGfxTranslator *this, const char *sectionName)
{
  const char *v2; // rsi
  UFG::UIGfxTranslator *v3; // rdi
  UFG::allocator::free_link *v4; // rax
  UFG::UIDictionary *v5; // rax
  UFG::UIDictionary *v6; // rbx
  const char *v7; // rax
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v8; // rax
  char dest; // [rsp+40h] [rbp-208h]

  v2 = sectionName;
  v3 = this;
  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x348ui64, "UIGfxTranslator::loadDictionary", 0i64, 1u);
  if ( v4 )
  {
    UFG::UIDictionary::UIDictionary((UFG::UIDictionary *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !UFG::gUIShowIconsInBlankLoc || v3->mLanguage )
    v7 = UFG::UILanguages::getLanguageStringShort(v3->mLanguage);
  else
    v7 = "EN";
  UFG::qSPrintf(&dest, 512, "Data\\UI\\Localization\\%s_%s.bin", v7, v2);
  UFG::UIDictionary::LoadDictionary(v6, &dest);
  v8 = v3->mDictionaries.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v6->mPrev;
  v6->mPrev = v8;
  v6->mNext = &v3->mDictionaries.mNode;
  v3->mDictionaries.mNode.mPrev = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v6->mPrev;
}

// File Line: 345
// RVA: 0xA324B0
void __fastcall UFG::UIGfxTranslator::unloadDictionary(UFG::UIGfxTranslator *this, const char *sectionName)
{
  UFG::UIGfxTranslator *v2; // rdi
  int v3; // eax
  UFG::UIDictionary *v4; // rbx
  signed __int64 v5; // rdi
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v6; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v7; // rax

  v2 = this;
  v3 = UFG::qStringHashUpper32(sectionName, 0xFFFFFFFF);
  v4 = (UFG::UIDictionary *)v2->mDictionaries.mNode.mNext;
  v5 = (signed __int64)&v2->mDictionaries;
  if ( v4 != (UFG::UIDictionary *)v5 )
  {
    while ( v4->mUID != v3 )
    {
      v4 = (UFG::UIDictionary *)v4->mNext;
      if ( v4 == (UFG::UIDictionary *)v5 )
        return;
    }
    if ( v4->mIsLoaded )
    {
      v6 = v4->mPrev;
      v7 = v4->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v4->mPrev = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v4->mPrev;
      v4->mNext = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v4->mPrev;
      UFG::UIDictionary::~UIDictionary(v4);
      UFG::qMemoryPool::Free(&gScaleformMemoryPool, v4);
    }
    else
    {
      v4->mMarkedForDeleteOnLoad = 1;
    }
  }
}

// File Line: 376
// RVA: 0xA31900
void __fastcall UFG::UIGfxTranslator::reloadDictionary(UFG::UIGfxTranslator *this, const char *sectionName)
{
  UFG::UIDictionary *v2; // rbx
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v3; // r14
  const char *v4; // rsi
  UFG::UIGfxTranslator *v5; // rbp
  const char *v6; // rax
  const char *v7; // rax
  char dest; // [rsp+30h] [rbp-208h]

  v2 = (UFG::UIDictionary *)this->mDictionaries.mNode.mNext;
  v3 = &this->mDictionaries;
  v4 = sectionName;
  v5 = this;
  if ( v2 != (UFG::UIDictionary *)&this->mDictionaries )
  {
    while ( v4 )
    {
      v7 = UFG::UIGfxTranslator::getLanguageStringShort(v5);
      UFG::qSPrintf(&dest, 512, "Data\\UI\\Localization\\%s_%s.bin", v7, v4);
      if ( !(unsigned int)UFG::qStringCompare(v4, &dest, -1) )
        goto LABEL_5;
LABEL_6:
      v2 = (UFG::UIDictionary *)v2->mNext;
      if ( v2 == (UFG::UIDictionary *)v3 )
        return;
    }
    v6 = UFG::UIGfxTranslator::getLanguageStringShort(v5);
    UFG::qSPrintf(&dest, 512, "Data\\UI\\Localization\\%s_%s.bin", v6, v2->mSectionName);
LABEL_5:
    UFG::UIDictionary::LoadDictionary(v2, &dest);
    goto LABEL_6;
  }
}

// File Line: 435
// RVA: 0xA28340
char *__fastcall UFG::UIGfxTranslator::Translate(UFG::UIGfxTranslator *this, unsigned int hash)
{
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v2; // r13
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v3; // rax
  UFG::UILocalizationChunk *v4; // r15
  __int64 v5; // rax
  unsigned int *v6; // rcx
  unsigned int v7; // ebp
  int *v8; // r14
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  int v12; // esi
  __int64 v13; // rdi
  char *v14; // r12
  char *v15; // rax
  int v16; // eax
  int v18; // [rsp+60h] [rbp+8h]
  unsigned int v19; // [rsp+68h] [rbp+10h]
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v20; // [rsp+70h] [rbp+18h]

  v19 = hash;
  v2 = this->mDictionaries.mNode.mNext;
  v20 = &this->mDictionaries;
  if ( v2 == (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&this->mDictionaries )
    return 0i64;
  v3 = &this->mDictionaries;
  while ( 1 )
  {
    v4 = (UFG::UILocalizationChunk *)v2[51].mNext;
    if ( v4 )
      break;
LABEL_16:
    v2 = v2->mNext;
    if ( v2 == (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)v3 )
      return 0i64;
  }
  v5 = v4->mChunkData.mOffset;
  if ( v5 )
    v6 = (unsigned int *)((char *)&v4->mChunkData + v5);
  else
    v6 = 0i64;
  v7 = *v6;
  if ( v5 )
    v8 = (int *)((char *)&v4[1] + v5);
  else
    v8 = 0i64;
  v9 = 0;
  v10 = v7 >> 2;
  v11 = 0;
  v18 = 0;
  if ( !v10 )
    goto LABEL_15;
  while ( 1 )
  {
    v12 = *v8;
    v13 = v9;
    v14 = &UFG::UILocalizationChunk::getStringData(v4)[v9];
    v15 = UFG::UILocalizationChunk::getStringData(v4);
    v16 = UFG::qStringLength(&v15[v13]);
    v9 = v16 + v18 + 1;
    v18 += v16 + 1;
    if ( v12 == v19 )
      break;
    ++v11;
    ++v8;
    if ( v11 >= v10 )
      goto LABEL_15;
  }
  if ( !v14 )
  {
LABEL_15:
    v3 = v20;
    goto LABEL_16;
  }
  return v14;
}

// File Line: 465
// RVA: 0xA28450
void __fastcall UFG::UIGfxTranslator::Translate(UFG::UIGfxTranslator *this, Scaleform::GFx::Translator::TranslateInfo *ptranslateInfo)
{
  const wchar_t *v2; // rsi
  UFG::UIGfxTranslator *v3; // r14
  Scaleform::GFx::Translator::TranslateInfo *v4; // rbx
  int v5; // eax
  int v6; // edi
  char *v7; // rax
  char *v8; // rbp
  int v9; // edi
  unsigned int v10; // eax
  char *v11; // rax
  const char *v12; // rsi
  bool v13; // di
  unsigned int v14; // eax
  unsigned __int64 v15; // r14
  unsigned int v16; // er15
  UFG::allocator::free_link *v17; // rax
  wchar_t *v18; // rdi
  void *v19; // rcx

  if ( ptranslateInfo )
  {
    v2 = ptranslateInfo->pKey;
    v3 = this;
    v4 = ptranslateInfo;
    v5 = UFG::qStringLength(ptranslateInfo->pKey);
    v6 = v5;
    if ( v5 )
    {
      if ( v3->mLanguage )
      {
        if ( *v2 != 36 || v5 == 1 )
          return;
      }
      else if ( UFG::gUIShowIconsInBlankLoc && ((unsigned __int16)(*v2 - 48) <= 9u || *v2 == 45) )
      {
        if ( v4->Flags & 4 )
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(v4, v2, v5);
          v4->Flags |= 2u;
        }
        else
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(v4, v2, v5);
        }
        return;
      }
      v7 = (char *)UFG::qMalloc(v5, &customWorldMapCaption, 0i64);
      v8 = v7;
      if ( v7 )
      {
        v9 = v6 - 1;
        UFG::qWideStringCopy(v7, v2 + 1);
        if ( v8[v9 - 1] == 13 )
          v8[v9 - 1] = 0;
        v10 = UFG::qStringHashUpper32(v8, 0xFFFFFFFF);
        v11 = UFG::UIGfxTranslator::Translate(v3, v10);
        v12 = v11;
        v13 = v11 != 0i64;
        if ( v3->mLanguage
          || UFG::gUIShowIconsInBlankLoc && v11 && !(unsigned int)UFG::qStringCompareInsensitive(v11, "<img", 4) )
        {
          if ( v13 )
          {
            v14 = UFG::qStringLength(v12);
            v15 = v14;
            v16 = 2 * v14 + 2;
            v17 = UFG::qMalloc(v16, &customWorldMapCaption, 0i64);
            v18 = (wchar_t *)v17;
            if ( v17 )
            {
              UFG::qMemSet(v17, 0, v16);
              Scaleform::UTF8Util::DecodeString(v18, v12, v15);
              if ( v4->Flags & 4 )
              {
                Scaleform::GFx::Translator::TranslateInfo::SetResult(v4, v18, v15);
                v4->Flags |= 2u;
              }
              else
              {
                Scaleform::GFx::Translator::TranslateInfo::SetResult(v4, v18, v15);
              }
              operator delete[](v8);
              v19 = v18;
            }
            else
            {
              v19 = v8;
            }
            operator delete[](v19);
          }
          else
          {
            operator delete[](v8);
          }
        }
        else
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(v4, &customWorldMapCaption, 0i64);
          operator delete[](v8);
        }
      }
    }
  }
}

// File Line: 570
// RVA: 0xA2B1E0
const char *__fastcall UFG::UIGfxTranslator::getLanguageString(UFG::UIGfxTranslator *this)
{
  const char *result; // rax

  if ( !UFG::gUIShowIconsInBlankLoc || this->mLanguage )
    result = UFG::UILanguages::getLanguageString(this->mLanguage);
  else
    result = "English";
  return result;
}

// File Line: 588
// RVA: 0xA2B350
const char *__fastcall UFG::UIGfxTranslator::getLanguageStringShort(UFG::UIGfxTranslator *this)
{
  const char *result; // rax

  if ( !UFG::gUIShowIconsInBlankLoc || this->mLanguage )
    result = UFG::UILanguages::getLanguageStringShort(this->mLanguage);
  else
    result = "EN";
  return result;
}

// File Line: 608
// RVA: 0xA2B4C0
UFG::qString *__fastcall UFG::UIGfxTranslator::getLocalizedTime(UFG::UIGfxTranslator *this, UFG::qString *result, float time, UFG::UIGfxTranslator::eTimeScale timeScale)
{
  UFG::UIGfxTranslator::eTimeScale v4; // ebx
  UFG::qString *v5; // rdi
  UFG::UIGfxTranslator *v6; // rsi
  Scaleform::RefCountImplCoreVtbl *v7; // rbx
  unsigned int v8; // eax
  const char *v9; // rax
  float v10; // xmm4_4
  __int64 v11; // r8
  float v12; // xmm4_4
  unsigned int v13; // edx
  float v14; // xmm4_4
  signed int v15; // er9
  float v16; // xmm4_4
  unsigned int v17; // er10
  float v18; // xmm4_4
  double v19; // xmm2_8
  const char *v20; // rdx
  __int64 v22[2]; // [rsp+20h] [rbp-60h]
  UFG::qString text; // [rsp+40h] [rbp-40h]

  v4 = timeScale;
  v5 = result;
  v6 = this;
  UFG::qString::qString(&text, &customWorldMapCaption);
  if ( time >= 0.0 )
  {
    v10 = time;
    switch ( v4 )
    {
      case 0:
        v10 = time + 0.5;
        break;
      case 1:
        v10 = time + 5.0;
        break;
      case 2:
      case 3:
        v10 = time + 500.0;
        break;
      case 4:
        v10 = time + 30000.0;
        break;
      case 6:
        v10 = time + 1800000.0;
        break;
      default:
        break;
    }
    v11 = (unsigned int)(signed int)(float)(v10 * 0.000000011574074);
    v12 = v10 - (float)(86400000 * (signed int)(float)(v10 * 0.000000011574074));
    v13 = (signed int)(float)(v12 * 0.00000027777779);
    v14 = v12 + (float)(signed int)(-3600000 * v13);
    v15 = (signed int)(float)(v14 * 0.000016666667);
    v16 = v14 + (float)(-60000 * v15);
    v17 = (signed int)(float)(v16 * 0.001);
    v18 = v16 + (float)(signed int)(-1000 * v17);
    switch ( v6->mLanguage )
    {
      case 5u:
      case 6u:
      case 9u:
      case 0xAu:
      case 0x11u:
      case 0x12u:
      case 0x13u:
      case 0x14u:
        switch ( v4 )
        {
          case 0:
            LODWORD(v22[0]) = (signed int)v18;
            UFG::qString::Format(&text, "%01d.%02d,%03d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            goto LABEL_28;
          case 1:
            LODWORD(v22[0]) = (signed int)(float)(v18 * 0.1);
            UFG::qString::Format(&text, "%01d.%02d,%02d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            goto LABEL_28;
          case 2:
            UFG::qString::Format(&text, "%d.%02d.%02d", v13 + 24 * (_DWORD)v11);
            goto LABEL_28;
          case 3:
            UFG::qString::Format(&text, "%d.%02d", v15 + 60 * v13, v17);
            goto LABEL_28;
          case 4:
            goto $LN5_115;
          case 5:
            goto $LN28_40;
          case 6:
            goto $LN3_110;
          case 7:
            goto $LN2_113;
          default:
            goto LABEL_28;
        }
      case 0xCu:
      case 0x10u:
      case 0x17u:
        switch ( v4 )
        {
          case 0:
            LODWORD(v22[0]) = (signed int)v18;
            UFG::qString::Format(&text, "%01d:%02d,%03d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            goto LABEL_28;
          case 1:
            LODWORD(v22[0]) = (signed int)(float)(v18 * 0.1);
            UFG::qString::Format(&text, "%01d:%02d,%02d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            goto LABEL_28;
          case 2:
            goto $LN7_126;
          case 3:
            goto $LN6_132;
          case 4:
            goto $LN5_115;
          case 5:
            goto $LN28_40;
          case 6:
            goto $LN3_110;
          case 7:
            goto $LN2_113;
          default:
            goto LABEL_28;
        }
      default:
        switch ( v4 )
        {
          case 0:
            LODWORD(v22[0]) = (signed int)v18;
            UFG::qString::Format(&text, "%01d:%02d.%03d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            break;
          case 1:
            LODWORD(v22[0]) = (signed int)(float)(v18 * 0.1);
            UFG::qString::Format(&text, "%01d:%02d.%02d", v15 + 60 * (v13 + 24 * (_DWORD)v11), v17, v22[0]);
            break;
          case 2:
$LN7_126:
            UFG::qString::Format(&text, "%d:%02d:%02d", v13 + 24 * (_DWORD)v11);
            break;
          case 3:
$LN6_132:
            UFG::qString::Format(&text, "%d:%02d", v15 + 60 * v13, v17);
            break;
          case 4:
$LN5_115:
            UFG::qString::Format(&text, "%02dh%02dm", v13 + 24 * (_DWORD)v11);
            break;
          case 5:
$LN28_40:
            v19 = (float)(time * 0.00000027777779);
            v20 = "%.1f hours";
            goto LABEL_27;
          case 6:
$LN3_110:
            UFG::qString::Format(&text, "%dd, %dh", v11, v13);
            break;
          case 7:
$LN2_113:
            v19 = (float)(time * 0.000000011574074);
            v20 = "%.1f days";
LABEL_27:
            UFG::qString::Format(&text, v20, v19);
            break;
          default:
            goto LABEL_28;
        }
        break;
    }
LABEL_28:
    UFG::qString::qString(v5, &text);
  }
  else
  {
    v7 = v6->vfptr;
    v8 = UFG::qStringHashUpper32("INVALID_TIME_MS", 0xFFFFFFFF);
    v9 = (const char *)v7[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v8);
    UFG::qString::qString(v5, v9);
  }
  UFG::qString::~qString(&text);
  return v5;
}

// File Line: 1002
// RVA: 0xA31F40
void __fastcall UFG::UIGfxTranslator::setLanguage(UFG::UIGfxTranslator *this, UFG::UILanguages::eLanguage language, bool load_fonts)
{
  bool v3; // bp
  UFG::UIGfxTranslator *v4; // rdi
  char **v5; // rsi
  UFG::UIDictionary *v6; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v7; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v8; // rax
  UFG::qString *v9; // rax
  __int64 *v10; // rax
  __int64 *v11; // rcx
  __int64 *v12; // rax
  UFG::qString *i; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v14; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v15; // rax
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v17; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v18; // rax
  __int64 *v19; // rcx
  UFG::qString *v20; // rax
  __int64 *v21; // [rsp+28h] [rbp-20h]
  UFG::qString *v22; // [rsp+30h] [rbp-18h]

  v3 = load_fonts;
  v4 = this;
  this->mLanguage = language;
  UFG::gLanguageOverride = language;
  v21 = (__int64 *)&v21;
  v22 = (UFG::qString *)&v21;
  v5 = (char **)&this->mDictionaries;
  if ( (UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *)this->mDictionaries.mNode.mNext != &this->mDictionaries )
  {
    do
    {
      v6 = (UFG::UIDictionary *)v4->mDictionaries.mNode.mNext;
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&v6->mPrev;
      v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v9 )
      {
        UFG::qString::qString(v9, v6->mSectionName);
        v11 = v10;
      }
      else
      {
        v11 = 0i64;
      }
      v12 = v21;
      v21[1] = (__int64)v11;
      *v11 = (__int64)v12;
      v11[1] = (__int64)&v21;
      v21 = v11;
      UFG::UIDictionary::~UIDictionary(v6);
      UFG::qMemoryPool::Free(&gScaleformMemoryPool, v6);
    }
    while ( v5[1] != (char *)v5 );
  }
  for ( i = v22; v22 != (UFG::qString *)&v21; i = v22 )
  {
    v14 = i->mPrev;
    v15 = i->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    i->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&i->mPrev;
    UFG::UIGfxTranslator::loadDictionary(v4, i->mData);
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  if ( v3 )
    UFG::UIGfxTranslator::createFontMap(v4);
  for ( j = v22; v22 != (UFG::qString *)&v21; j = v22 )
  {
    v17 = j->mPrev;
    v18 = j->mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
    UFG::qString::~qString(j);
    operator delete[](j);
  }
  v19 = v21;
  v20 = v22;
  v21[1] = (__int64)v22;
  v20->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)v19;
}

// File Line: 1031
// RVA: 0xA2BBE0
signed __int64 __fastcall UFG::UIGfxTranslator::getSystemLanguage(__int64 a1)
{
  __int64 v2; // rax
  const char *v3; // rax
  const char *v4; // rbx
  int v5; // eax
  UFG::UILanguages::eLanguage v6; // ecx

  if ( !(unsigned __int8)SteamAPI_IsSteamRunning(a1) )
    return eLang_English;
  v2 = SteamApps();
  if ( !v2 )
    return eLang_English;
  v3 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 32i64))(v2);
  v4 = v3;
  if ( !v3 || !(unsigned int)UFG::qStringCompareInsensitive(v3, &customWorldMapCaption, -1) )
    return eLang_English;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "tchinese", -1) )
    return eLang_Cantonese;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "danish", -1) )
    return eLang_Danish;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "dutch", -1) )
    return eLang_Dutch;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "english", -1) )
    return eLang_English;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "finnish", -1) )
    return eLang_Finnish;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "french", -1) )
    return eLang_French;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "german", -1) )
    return eLang_German;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "italian", -1) )
    return eLang_Italian;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "japanese", -1) )
    return eLang_Japanese;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "koreana", -1)
    || !(unsigned int)UFG::qStringCompareInsensitive(v4, "korean", -1) )
  {
    return eLang_Korean;
  }
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "norwegian", -1) )
    return eLang_Norwegian;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "polish", -1) )
    return eLang_Polish;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "portuguese", -1) )
    return eLang_Portuguese;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "brazilian", -1) )
    return eLang_Portuguese_BR;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "russian", -1) )
    return eLang_Russian;
  if ( !(unsigned int)UFG::qStringCompareInsensitive(v4, "spanish", -1) )
    return eLang_Spanish;
  v5 = UFG::qStringCompareInsensitive(v4, "swedish", -1);
  v6 = eLang_English;
  if ( !v5 )
    v6 = eLang_Swedish;
  return v6;
}

// File Line: 1271
// RVA: 0xA2A390
void __fastcall UFG::UIGfxTranslator::createFontMap(UFG::UIGfxTranslator *this)
{
  UFG::UIGfxTranslator *v1; // r13
  Scaleform::GFx::FontMap *v2; // rax
  Scaleform::GFx::FontLib *v3; // r12
  Scaleform::GFx::FontMap *v4; // rax
  Scaleform::GFx::FontMap *v5; // r15
  Scaleform::GFx::FontLib *v6; // rax
  Scaleform::GFx::FontLib *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  SimpleXML::XMLDocument *v10; // rax
  SimpleXML::XMLDocument *v11; // rbp
  SimpleXML::XMLNode *v12; // rax
  SimpleXML::XMLNode *v13; // rsi
  char *v14; // rbx
  const char *v15; // rax
  SimpleXML::XMLNode *i; // r14
  char *v17; // rdi
  char *v18; // rbx
  Scaleform::GFx::FontMap::MapFontFlags v19; // eax
  char *v20; // rax
  Scaleform::GFx::MovieDefImpl *v21; // rbx
  UFG::qString v22; // [rsp+38h] [rbp-1E0h]
  UFG::qString v23; // [rsp+60h] [rbp-1B8h]
  UFG::qString result; // [rsp+88h] [rbp-190h]
  UFG::qString v25; // [rsp+B0h] [rbp-168h]
  char dest; // [rsp+E0h] [rbp-138h]

  v1 = this;
  v2 = (Scaleform::GFx::FontMap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    32i64);
  v3 = 0i64;
  if ( v2 )
  {
    Scaleform::GFx::FontMap::FontMap(v2);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v1->mGfxLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->mGfxLoader->vfptr,
    State_UserData|0x10,
    (Scaleform::GFx::State *)&v5->vfptr);
  v6 = (Scaleform::GFx::FontLib *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    32i64);
  if ( v6 )
  {
    Scaleform::GFx::FontLib::FontLib(v6);
    v3 = v7;
  }
  v1->mGfxLoader->vfptr->SetState(
    (Scaleform::GFx::StateBag *)&v1->mGfxLoader->vfptr,
    (Scaleform::GFx::State::StateType)20i64,
    (Scaleform::GFx::State *)&v3->vfptr);
  UFG::qString::qString(&v22);
  UFG::qString::qString(&v23);
  UFG::qString::Format(&v23, "%s", v1->mScreenFactory->m_rootDir);
  v8 = UFG::qString::GetFilePath(&v23, &result);
  v9 = UFG::qString::GetFilePath(v8, &v25);
  UFG::qString::Format(&v22, "%s/Config/FontDefinition.xml", v9->mData);
  UFG::qString::~qString(&v25);
  UFG::qString::~qString(&result);
  UFG::qString::ReplaceCharInPlace(&v22, 47, 92);
  v10 = SimpleXML::XMLDocument::Open(v22.mData, 1ui64, 0i64);
  v11 = v10;
  if ( v10 )
  {
    v12 = SimpleXML::XMLDocument::GetNode(v10, "FontDefinition", 0i64);
    v13 = SimpleXML::XMLDocument::GetChildNode(v11, "Language", v12);
    if ( v13 )
    {
      while ( 1 )
      {
        v14 = SimpleXML::XMLNode::GetAttribute(v13, "name");
        v15 = UFG::UIGfxTranslator::getLanguageString(v1);
        if ( !(unsigned int)UFG::qStringCompareInsensitive(v14, v15, -1) )
          break;
        v13 = SimpleXML::XMLDocument::GetNode(v11, "Language", v13);
        if ( !v13 )
          goto LABEL_15;
      }
      for ( i = SimpleXML::XMLDocument::GetChildNode(v11, "FontMap", v13);
            i;
            i = SimpleXML::XMLDocument::GetNode(v11, "FontMap", i) )
      {
        v17 = SimpleXML::XMLNode::GetAttribute(i, "name");
        v18 = SimpleXML::XMLNode::GetAttribute(i, "font");
        v19 = SimpleXML::XMLNode::GetAttribute(i, "style", 0);
        Scaleform::GFx::FontMap::MapFont(v5, v17, v18, v19, v1->mFontScale);
      }
      v20 = SimpleXML::XMLNode::GetAttribute(v13, "filename");
      UFG::qSPrintf(&dest, "%s", v20);
      UFG::qPrintf("Loading fonts from: %s\n", &dest);
      v21 = Scaleform::GFx::Loader::CreateMovie(v1->mGfxLoader, &dest, 0, 0i64);
      Scaleform::GFx::FontLib::AddFontsFrom(v3, (Scaleform::GFx::MovieDef *)&v21->vfptr, 1);
      if ( v21 )
        Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)&v21->vfptr);
    }
LABEL_15:
    SimpleXML::XMLDocument::~XMLDocument(v11);
    operator delete[](v11);
  }
  UFG::qString::~qString(&v23);
  UFG::qString::~qString(&v22);
  if ( v3 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v3);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
}

