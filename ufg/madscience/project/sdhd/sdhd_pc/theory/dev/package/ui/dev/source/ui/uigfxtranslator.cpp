// File Line: 101
// RVA: 0xA276F0
void __fastcall UFG::UIDictionary::LoadDictionary(UFG::UIDictionary *this, const char *filename)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  int v6; // eax
  UFG::qString *FilenameWithoutExtension; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  unsigned int mStringHashUpper32; // ebx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  UFG::qString v13; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-38h] BYREF

  Inventory = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mDatabaseHandle, Inventory);
  UFG::StreamResourceLoader::UnloadResourceFile(this->mFilename);
  this->mFilename[0] = 0;
  v6 = UFG::qStringLength(filename);
  UFG::qStringCopy(this->mFilename, 256, filename, v6);
  UFG::qString::qString(&v13, this->mFilename);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v13, &result);
  UFG::qString::Set(&v13, FilenameWithoutExtension->mData, FilenameWithoutExtension->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v8 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = v8;
  }
  UFG::qResourceHandle::Close(&this->mDatabaseHandle, v8);
  mStringHashUpper32 = v13.mStringHashUpper32;
  if ( v13.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(v13.mData, 0xFFFFFFFF);
    v13.mStringHashUpper32 = mStringHashUpper32;
  }
  v11 = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = v11;
  }
  UFG::qResourceHandle::Init(&this->mDatabaseHandle, 0x90CE6B7A, mStringHashUpper32, v11);
  if ( UFG::StreamFileWrapper::FileExists(filename) )
    UFG::StreamResourceLoader::LoadResourceFile(filename, &gScaleformMemoryPool, 1u, 0i64, 0i64, 0i64);
  UFG::UIDictionary::PrintDictionary(this);
  UFG::qString::~qString(&v13);
}

// File Line: 209
// RVA: 0xA28670
void __fastcall UFG::UIDictionary::UnloadDictionary(UFG::UIDictionary *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax

  Inventory = `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x90CE6B7A);
    `UFG::qGetResourceInventory<UFG::UILocalizationChunk>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mDatabaseHandle, Inventory);
  UFG::StreamResourceLoader::UnloadResourceFile(this->mFilename);
  this->mFilename[0] = 0;
}

// File Line: 288
// RVA: 0xA27FC0
void __fastcall UFG::UIDictionary::PrintDictionary(UFG::UIDictionary *this)
{
  UFG::qBaseTreeRB *i; // rbx

  UFG::qPrintf("=== Dictionary %s ===\n", this->mSectionName);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mStringMap);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mStringMap.mTree, &i->mRoot) )
  {
    UFG::qPrintf("0x%8X\t%s\n", i->mRoot.mUID, (const char *)i->mNULL.mParent);
  }
}

// File Line: 310
// RVA: 0xA2FD10
void __fastcall UFG::UIGfxTranslator::init(
        UFG::UIGfxTranslator *this,
        UFG::UIScreenFactory *screenFactory,
        Scaleform::GFx::Loader *gfxLoader)
{
  this->mScreenFactory = screenFactory;
  gfxLoader->vfptr->SetState(gfxLoader, State_BlendMode, this);
  this->mGfxLoader = gfxLoader;
}

// File Line: 333
// RVA: 0xA30570
void __fastcall UFG::UIGfxTranslator::loadDictionary(UFG::UIGfxTranslator *this, char *sectionName)
{
  UFG::allocator::free_link *v4; // rax
  UFG::UIDictionary *v5; // rax
  UFG::UIDictionary *v6; // rbx
  const char *LanguageStringShort; // rax
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mPrev; // rax
  char dest[512]; // [rsp+40h] [rbp-208h] BYREF

  v4 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x348ui64, "UIGfxTranslator::loadDictionary", 0i64, 1u);
  if ( v4 )
  {
    UFG::UIDictionary::UIDictionary((UFG::UIDictionary *)v4, sectionName);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( !UFG::gUIShowIconsInBlankLoc || this->mLanguage )
    LanguageStringShort = UFG::UILanguages::getLanguageStringShort(this->mLanguage);
  else
    LanguageStringShort = "EN";
  UFG::qSPrintf(dest, 512, "Data\\UI\\Localization\\%s_%s.bin", LanguageStringShort, sectionName);
  UFG::UIDictionary::LoadDictionary(v6, dest);
  mPrev = this->mDictionaries.mNode.mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = &this->mDictionaries.mNode;
  this->mDictionaries.mNode.mPrev = v6;
}

// File Line: 345
// RVA: 0xA324B0
void __fastcall UFG::UIGfxTranslator::unloadDictionary(UFG::UIGfxTranslator *this, const char *sectionName)
{
  int v3; // eax
  UFG::UIDictionary *mNext; // rbx
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *p_mDictionaries; // rdi
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mPrev; // rcx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *v7; // rax

  v3 = UFG::qStringHashUpper32(sectionName, -1);
  mNext = (UFG::UIDictionary *)this->mDictionaries.mNode.mNext;
  p_mDictionaries = &this->mDictionaries;
  if ( mNext != (UFG::UIDictionary *)p_mDictionaries )
  {
    while ( mNext->mUID != v3 )
    {
      mNext = (UFG::UIDictionary *)mNext->mNext;
      if ( mNext == (UFG::UIDictionary *)p_mDictionaries )
        return;
    }
    if ( mNext->mIsLoaded )
    {
      mPrev = mNext->mPrev;
      v7 = mNext->mNext;
      mPrev->mNext = v7;
      v7->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::UIDictionary::~UIDictionary(mNext);
      UFG::qMemoryPool::Free(&gScaleformMemoryPool, (char *)mNext);
    }
    else
    {
      mNext->mMarkedForDeleteOnLoad = 1;
    }
  }
}

// File Line: 376
// RVA: 0xA31900
void __fastcall UFG::UIGfxTranslator::reloadDictionary(UFG::UIGfxTranslator *this, const char *sectionName)
{
  UFG::UIDictionary *mNext; // rbx
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *p_mDictionaries; // r14
  const char *v6; // rax
  const char *LanguageStringShort; // rax
  char dest[512]; // [rsp+30h] [rbp-208h] BYREF

  mNext = (UFG::UIDictionary *)this->mDictionaries.mNode.mNext;
  p_mDictionaries = &this->mDictionaries;
  if ( mNext != (UFG::UIDictionary *)&this->mDictionaries )
  {
    while ( sectionName )
    {
      LanguageStringShort = UFG::UIGfxTranslator::getLanguageStringShort(this);
      UFG::qSPrintf(dest, 512, "Data\\UI\\Localization\\%s_%s.bin", LanguageStringShort, sectionName);
      if ( !(unsigned int)UFG::qStringCompare(sectionName, dest, -1) )
        goto LABEL_5;
LABEL_6:
      mNext = (UFG::UIDictionary *)mNext->mNext;
      if ( mNext == (UFG::UIDictionary *)p_mDictionaries )
        return;
    }
    v6 = UFG::UIGfxTranslator::getLanguageStringShort(this);
    UFG::qSPrintf(dest, 512, "Data\\UI\\Localization\\%s_%s.bin", v6, mNext->mSectionName);
LABEL_5:
    UFG::UIDictionary::LoadDictionary(mNext, dest);
    goto LABEL_6;
  }
}

// File Line: 435
// RVA: 0xA28340
char *__fastcall UFG::UIGfxTranslator::Translate(UFG::UIGfxTranslator *this, unsigned int hash)
{
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mNext; // r13
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *v3; // rax
  UFG::UILocalizationChunk *v4; // r15
  __int64 mOffset; // rax
  unsigned int *v6; // rcx
  unsigned int v7; // ebp
  int *v8; // r14
  unsigned int v9; // ecx
  unsigned int v10; // ebp
  unsigned int v11; // ebx
  int v12; // esi
  __int64 v13; // rdi
  char *v14; // r12
  char *StringData; // rax
  unsigned int v17; // [rsp+60h] [rbp+8h]
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *p_mDictionaries; // [rsp+70h] [rbp+18h]

  mNext = this->mDictionaries.mNode.mNext;
  p_mDictionaries = &this->mDictionaries;
  if ( mNext == (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)&this->mDictionaries )
    return 0i64;
  v3 = &this->mDictionaries;
  while ( 1 )
  {
    v4 = (UFG::UILocalizationChunk *)mNext[51].mNext;
    if ( v4 )
      break;
LABEL_16:
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *)v3 )
      return 0i64;
  }
  mOffset = v4->mChunkData.mOffset;
  if ( mOffset )
    v6 = (unsigned int *)((char *)&v4->mChunkData + mOffset);
  else
    v6 = 0i64;
  v7 = *v6;
  if ( mOffset )
    v8 = (int *)((char *)&v4[1] + mOffset);
  else
    v8 = 0i64;
  v9 = 0;
  v10 = v7 >> 2;
  v11 = 0;
  v17 = 0;
  if ( !v10 )
    goto LABEL_15;
  while ( 1 )
  {
    v12 = *v8;
    v13 = v9;
    v14 = &UFG::UILocalizationChunk::getStringData(v4)[v9];
    StringData = UFG::UILocalizationChunk::getStringData(v4);
    v9 = UFG::qStringLength(&StringData[v13]) + v17 + 1;
    v17 = v9;
    if ( v12 == hash )
      break;
    ++v11;
    ++v8;
    if ( v11 >= v10 )
      goto LABEL_15;
  }
  if ( !v14 )
  {
LABEL_15:
    v3 = p_mDictionaries;
    goto LABEL_16;
  }
  return v14;
}

// File Line: 465
// RVA: 0xA28450
void __fastcall UFG::UIGfxTranslator::Translate(
        UFG::UIGfxTranslator *this,
        Scaleform::GFx::Translator::TranslateInfo *ptranslateInfo)
{
  const wchar_t *pKey; // rsi
  int v5; // eax
  int v6; // edi
  char *v7; // rax
  char *v8; // rbp
  int v9; // edi
  unsigned int v10; // eax
  char *v11; // rax
  char *v12; // rsi
  bool v13; // di
  unsigned int v14; // eax
  unsigned __int64 v15; // r14
  unsigned int v16; // r15d
  UFG::allocator::free_link *v17; // rax
  wchar_t *v18; // rdi
  void *v19; // rcx

  if ( ptranslateInfo )
  {
    pKey = ptranslateInfo->pKey;
    v5 = UFG::qStringLength(ptranslateInfo->pKey);
    v6 = v5;
    if ( v5 )
    {
      if ( this->mLanguage )
      {
        if ( *pKey != 36 || v5 == 1 )
          return;
      }
      else if ( UFG::gUIShowIconsInBlankLoc && ((unsigned __int16)(*pKey - 48) <= 9u || *pKey == 45) )
      {
        if ( (ptranslateInfo->Flags & 4) != 0 )
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, pKey, v5);
          ptranslateInfo->Flags |= 2u;
        }
        else
        {
          Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, pKey, v5);
        }
        return;
      }
      v7 = (char *)UFG::qMalloc(v5, &customCaption, 0i64);
      v8 = v7;
      if ( v7 )
      {
        v9 = v6 - 1;
        UFG::qWideStringCopy(v7, pKey + 1);
        if ( v8[v9 - 1] == 13 )
          v8[v9 - 1] = 0;
        v10 = UFG::qStringHashUpper32(v8, -1);
        v11 = UFG::UIGfxTranslator::Translate(this, v10);
        v12 = v11;
        v13 = v11 != 0i64;
        if ( this->mLanguage
          || UFG::gUIShowIconsInBlankLoc && v11 && !(unsigned int)UFG::qStringCompareInsensitive(v11, "<img", 4) )
        {
          if ( v13 )
          {
            v14 = UFG::qStringLength(v12);
            v15 = v14;
            v16 = 2 * v14 + 2;
            v17 = UFG::qMalloc(v16, &customCaption, 0i64);
            v18 = (wchar_t *)v17;
            if ( v17 )
            {
              UFG::qMemSet(v17, 0, v16);
              Scaleform::UTF8Util::DecodeString(v18, v12, v15);
              if ( (ptranslateInfo->Flags & 4) != 0 )
              {
                Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, v18, v15);
                ptranslateInfo->Flags |= 2u;
              }
              else
              {
                Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, v18, v15);
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
          Scaleform::GFx::Translator::TranslateInfo::SetResult(ptranslateInfo, &customCaption, 0i64);
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
  if ( !UFG::gUIShowIconsInBlankLoc || this->mLanguage )
    return UFG::UILanguages::getLanguageString(this->mLanguage);
  else
    return "English";
}

// File Line: 588
// RVA: 0xA2B350
const char *__fastcall UFG::UIGfxTranslator::getLanguageStringShort(UFG::UIGfxTranslator *this)
{
  if ( !UFG::gUIShowIconsInBlankLoc || this->mLanguage )
    return UFG::UILanguages::getLanguageStringShort(this->mLanguage);
  else
    return "EN";
}

// File Line: 608
// RVA: 0xA2B4C0
UFG::qString *__fastcall UFG::UIGfxTranslator::getLocalizedTime(
        UFG::UIGfxTranslator *this,
        UFG::qString *result,
        float time,
        UFG::UIGfxTranslator::eTimeScale timeScale)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rbx
  unsigned int v8; // eax
  const char *v9; // rax
  float v10; // xmm4_4
  __int64 v11; // r8
  float v12; // xmm4_4
  unsigned int v13; // edx
  float v14; // xmm4_4
  __int64 v15; // r9
  float v16; // xmm4_4
  unsigned int v17; // r10d
  float v18; // xmm4_4
  UFG::qString text; // [rsp+40h] [rbp-40h] BYREF

  UFG::qString::qString(&text, &customCaption);
  if ( time >= 0.0 )
  {
    v10 = time;
    switch ( timeScale )
    {
      case eTS_MILLISECONDS:
        v10 = time + 0.5;
        break;
      case eTS_CENTISECONDS:
        v10 = time + 5.0;
        break;
      case eTS_SECONDS:
      case eTS_SECONDS_SHORT:
        v10 = time + 500.0;
        break;
      case eTS_MINUTES:
        v10 = time + 30000.0;
        break;
      case eTS_DAYS_HOURS:
        v10 = time + 1800000.0;
        break;
      default:
        break;
    }
    v11 = (unsigned int)(int)(float)(v10 * 0.000000011574074);
    v12 = v10 - (float)(86400000 * (int)(float)(v10 * 0.000000011574074));
    v13 = (int)(float)(v12 * 0.00000027777779);
    v14 = v12 + (float)(int)(-3600000 * v13);
    v15 = (unsigned int)(int)(float)(v14 * 0.000016666667);
    v16 = v14 + (float)(-60000 * (int)(float)(v14 * 0.000016666667));
    v17 = (int)(float)(v16 * 0.001);
    v18 = v16 + (float)(int)(-1000 * v17);
    switch ( this->mLanguage )
    {
      case eLang_Danish:
      case eLang_Dutch:
      case eLang_Finnish:
      case eLang_French:
      case eLang_Polish:
      case eLang_Portuguese:
      case eLang_Portuguese_BR:
      case eLang_Russian:
        switch ( timeScale )
        {
          case eTS_MILLISECONDS:
            UFG::qString::Format(
              &text,
              "%01d.%02d,%03d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)v18);
            break;
          case eTS_CENTISECONDS:
            UFG::qString::Format(
              &text,
              "%01d.%02d,%02d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)(float)(v18 * 0.1));
            break;
          case eTS_SECONDS:
            UFG::qString::Format(&text, "%d.%02d.%02d", v13 + 24 * (_DWORD)v11, v15, v17);
            break;
          case eTS_SECONDS_SHORT:
            UFG::qString::Format(&text, "%d.%02d", (unsigned int)v15 + 60 * v13, v17);
            break;
          case eTS_MINUTES:
            goto $LN5_115;
          case eTS_HOURS:
            goto $LN28_40;
          case eTS_DAYS_HOURS:
            goto $LN3_110;
          case eTS_DAYS:
            goto $LN2_113;
          default:
            goto LABEL_27;
        }
        break;
      case eLang_German:
      case eLang_Norwegian:
      case eLang_Swedish:
        switch ( timeScale )
        {
          case eTS_MILLISECONDS:
            UFG::qString::Format(
              &text,
              "%01d:%02d,%03d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)v18);
            break;
          case eTS_CENTISECONDS:
            UFG::qString::Format(
              &text,
              "%01d:%02d,%02d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)(float)(v18 * 0.1));
            break;
          case eTS_SECONDS:
            goto $LN7_126;
          case eTS_SECONDS_SHORT:
            goto $LN6_132;
          case eTS_MINUTES:
            goto $LN5_115;
          case eTS_HOURS:
            goto $LN28_40;
          case eTS_DAYS_HOURS:
            goto $LN3_110;
          case eTS_DAYS:
            goto $LN2_113;
          default:
            goto LABEL_27;
        }
        break;
      default:
        switch ( timeScale )
        {
          case eTS_MILLISECONDS:
            UFG::qString::Format(
              &text,
              "%01d:%02d.%03d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)v18);
            break;
          case eTS_CENTISECONDS:
            UFG::qString::Format(
              &text,
              "%01d:%02d.%02d",
              (unsigned int)v15 + 60 * (v13 + 24 * (_DWORD)v11),
              v17,
              (int)(float)(v18 * 0.1));
            break;
          case eTS_SECONDS:
$LN7_126:
            UFG::qString::Format(&text, "%d:%02d:%02d", v13 + 24 * (_DWORD)v11, v15, v17);
            break;
          case eTS_SECONDS_SHORT:
$LN6_132:
            UFG::qString::Format(&text, "%d:%02d", (unsigned int)v15 + 60 * v13, v17);
            break;
          case eTS_MINUTES:
$LN5_115:
            UFG::qString::Format(&text, "%02dh%02dm", v13 + 24 * (_DWORD)v11, v15);
            break;
          case eTS_HOURS:
$LN28_40:
            UFG::qString::Format(&text, "%.1f hours", (float)(time * 0.00000027777779));
            break;
          case eTS_DAYS_HOURS:
$LN3_110:
            UFG::qString::Format(&text, "%dd, %dh", v11, v13);
            break;
          case eTS_DAYS:
$LN2_113:
            UFG::qString::Format(&text, "%.1f days", (float)(time * 0.000000011574074));
            break;
          default:
            goto LABEL_27;
        }
        break;
    }
LABEL_27:
    UFG::qString::qString(result, &text);
  }
  else
  {
    vfptr = this->vfptr;
    v8 = UFG::qStringHashUpper32("INVALID_TIME_MS", -1);
    v9 = (const char *)vfptr[5].__vecDelDtor(this, v8);
    UFG::qString::qString(result, v9);
  }
  UFG::qString::~qString(&text);
  return result;
}

// File Line: 1002
// RVA: 0xA31F40
void __fastcall UFG::UIGfxTranslator::setLanguage(
        UFG::UIGfxTranslator *this,
        UFG::UILanguages::eLanguage language,
        bool load_fonts)
{
  UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *p_mDictionaries; // rsi
  UFG::UIDictionary *mNext; // rbx
  UFG::qNode<UFG::UIDictionary,UFG::UIDictionary> *mPrev; // rcx
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
  __int64 *v21; // [rsp+28h] [rbp-20h] BYREF
  UFG::qString *v22; // [rsp+30h] [rbp-18h]

  this->mLanguage = language;
  UFG::gLanguageOverride = language;
  v21 = (__int64 *)&v21;
  v22 = (UFG::qString *)&v21;
  p_mDictionaries = &this->mDictionaries;
  if ( (UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *)this->mDictionaries.mNode.mNext != &this->mDictionaries )
  {
    do
    {
      mNext = (UFG::UIDictionary *)this->mDictionaries.mNode.mNext;
      mPrev = mNext->mPrev;
      v8 = mNext->mNext;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v9 = (UFG::qString *)UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
      if ( v9 )
      {
        UFG::qString::qString(v9, mNext->mSectionName);
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
      UFG::UIDictionary::~UIDictionary(mNext);
      UFG::qMemoryPool::Free(&gScaleformMemoryPool, (char *)mNext);
    }
    while ( (UFG::qList<UFG::UIDictionary,UFG::UIDictionary,1,0> *)p_mDictionaries->mNode.mNext != p_mDictionaries );
  }
  for ( i = v22; v22 != (UFG::qString *)&v21; i = v22 )
  {
    v14 = i->mPrev;
    v15 = i->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    i->mPrev = i;
    i->mNext = i;
    UFG::UIGfxTranslator::loadDictionary(this, i->mData);
    UFG::qString::~qString(i);
    operator delete[](i);
  }
  if ( load_fonts )
    UFG::UIGfxTranslator::createFontMap(this);
  for ( j = v22; v22 != (UFG::qString *)&v21; j = v22 )
  {
    v17 = j->mPrev;
    v18 = j->mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    j->mPrev = j;
    j->mNext = j;
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
  if ( !v3 || !(unsigned int)UFG::qStringCompareInsensitive(v3, &customCaption, -1) )
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
    return eLang_Swedish;
  return (unsigned int)v6;
}

// File Line: 1271
// RVA: 0xA2A390
void __fastcall UFG::UIGfxTranslator::createFontMap(UFG::UIGfxTranslator *this)
{
  Scaleform::GFx::FontMap *v2; // rax
  Scaleform::GFx::FontLib *v3; // r12
  Scaleform::GFx::FontMap *v4; // rax
  Scaleform::GFx::FontMap *v5; // r15
  Scaleform::GFx::FontLib *v6; // rax
  Scaleform::GFx::FontLib *v7; // rax
  UFG::qString *FilePath; // rax
  UFG::qString *v9; // rax
  SimpleXML::XMLDocument *v10; // rax
  SimpleXML::XMLDocument *v11; // rbp
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // rsi
  char *Attribute; // rbx
  const char *LanguageString; // rax
  SimpleXML::XMLNode *i; // r14
  char *v17; // rdi
  char *v18; // rbx
  Scaleform::GFx::FontMap::MapFontFlags v19; // eax
  char *v20; // rax
  Scaleform::GFx::MovieDefImpl *Movie; // rbx
  UFG::qString v22; // [rsp+38h] [rbp-1E0h] BYREF
  UFG::qString v23; // [rsp+60h] [rbp-1B8h] BYREF
  UFG::qString result; // [rsp+88h] [rbp-190h] BYREF
  UFG::qString v25; // [rsp+B0h] [rbp-168h] BYREF
  char dest[312]; // [rsp+E0h] [rbp-138h] BYREF

  v2 = (Scaleform::GFx::FontMap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
  this->mGfxLoader->vfptr->SetState(this->mGfxLoader, State_UserData|0x10, v5);
  v6 = (Scaleform::GFx::FontLib *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    32i64);
  if ( v6 )
  {
    Scaleform::GFx::FontLib::FontLib(v6);
    v3 = v7;
  }
  this->mGfxLoader->vfptr->SetState(this->mGfxLoader, (Scaleform::GFx::State::StateType)20i64, v3);
  UFG::qString::qString(&v22);
  UFG::qString::qString(&v23);
  UFG::qString::Format(&v23, "%s", this->mScreenFactory->m_rootDir);
  FilePath = UFG::qString::GetFilePath(&v23, &result);
  v9 = UFG::qString::GetFilePath(FilePath, &v25);
  UFG::qString::Format(&v22, "%s/Config/FontDefinition.xml", v9->mData);
  UFG::qString::~qString(&v25);
  UFG::qString::~qString(&result);
  UFG::qString::ReplaceCharInPlace(&v22, 47, 92);
  v10 = SimpleXML::XMLDocument::Open(v22.mData, 1ui64, 0i64);
  v11 = v10;
  if ( v10 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v10, "FontDefinition", 0i64);
    ChildNode = SimpleXML::XMLDocument::GetChildNode(v11, "Language", Node);
    if ( ChildNode )
    {
      while ( 1 )
      {
        Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "name");
        LanguageString = UFG::UIGfxTranslator::getLanguageString(this);
        if ( !(unsigned int)UFG::qStringCompareInsensitive(Attribute, LanguageString, -1) )
          break;
        ChildNode = SimpleXML::XMLDocument::GetNode(v11, "Language", ChildNode);
        if ( !ChildNode )
          goto LABEL_15;
      }
      for ( i = SimpleXML::XMLDocument::GetChildNode(v11, "FontMap", ChildNode);
            i;
            i = SimpleXML::XMLDocument::GetNode(v11, "FontMap", i) )
      {
        v17 = SimpleXML::XMLNode::GetAttribute(i, "name");
        v18 = SimpleXML::XMLNode::GetAttribute(i, "font");
        v19 = SimpleXML::XMLNode::GetAttribute(i, "style", 0);
        Scaleform::GFx::FontMap::MapFont(v5, v17, v18, v19, this->mFontScale);
      }
      v20 = SimpleXML::XMLNode::GetAttribute(ChildNode, "filename");
      UFG::qSPrintf(dest, "%s", v20);
      UFG::qPrintf("Loading fonts from: %s\n", dest);
      Movie = Scaleform::GFx::Loader::CreateMovie(this->mGfxLoader, dest, 0, 0i64);
      Scaleform::GFx::FontLib::AddFontsFrom(v3, Movie, 1);
      if ( Movie )
        Scaleform::GFx::Resource::Release(Movie);
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

